//
// OdbcW_Win32.cpp
//

#pragma warning (disable : 4786)

#include "OdbcW.h"
#include "OdbcWInternal.h"
#include "OdbcWSetup.h"

#include <windows.h>
#include <sqlext.h>
#include <map>
//
// Platform dependent definitions and data
//
#define MAX_COL             150
#define MAXDATALEN          4096	//2048
#define MAXBUFLEN           1024
#define MAXDISPLAYSIZE      2048
#define COLTRUNC_WARNG      _("Number of columns in display truncated to %u")
#define ROWTRUNC_WARNG      _("Number of rows in display truncated to %u")
#define SQLERR_FORMAT       _("SQL Error State: %s Native Error Code: %lX")
#define NULLDATASTRING      _T("")
#define ODBC_MSG_TAG        _T("[MySQL][ODBC 5.1 Driver][mysqld-5.5.25a]")

static SQLHENV s_sqlENVHandle=SQL_NULL_HENV;
static std::map<OdbcWConnectionId, SQLHDBC> s_sqlDBCHandle;

//
// OdbcW_GetSqlConnectionHDBC
//
static SQLHDBC OdbcW_GetSqlConnectionHDBC(const OdbcWConnectionId& connectionId)
{
	std::map<OdbcWConnectionId, SQLHDBC>::iterator dbcIterator(s_sqlDBCHandle.find(connectionId));
	if(s_sqlDBCHandle.end()!=dbcIterator)
		return dbcIterator->second;

	return SQL_NULL_HDBC;
}

//
// OdbcW_ConvertSqlTypeToOdbcType
//
static OdbcW_DataType OdbcW_ConvertSqlTypeToWOdbcType(int sqlType)
{
	OdbcW_DataType wType(WDT_UNDEFINED);

	switch(sqlType)
	{
		case SQL_DECIMAL:
		case SQL_NUMERIC:
		case SQL_REAL:
		case SQL_FLOAT:
		case SQL_DOUBLE:
			wType=WDT_REAL;
			break;
		case SQL_SMALLINT:
		case SQL_INTEGER:
		case SQL_BIT:
		case SQL_TINYINT:
		case SQL_BIGINT:
			wType=WDT_INTEGER;
			break;
		default:
			wType=WDT_STRING;

	};

	return wType;
};

//
// OdbcW_DisplaySQLError
//
static void OdbcW_DisplaySQLError(SQLRETURN nResult, SWORD fHandleType, SQLHANDLE handle)
{
	char    szDispBuffer[MAXDISPLAYSIZE+1]; // Display Buffer
	UCHAR   szErrState[SQL_SQLSTATE_SIZE+1];    // SQL Error State string
	UCHAR   szErrText[SQL_MAX_MESSAGE_LENGTH+1];    // SQL Error Text string
	char    szBuffer[SQL_SQLSTATE_SIZE+SQL_MAX_MESSAGE_LENGTH+MAXBUFLEN+1];
	// formatted Error text Buffer
	SWORD    wErrMsgLen;             // Error message length
	UDWORD   dwErrCode;              // Native Error code
	int  iSize;                      // Display Error Text size
	SQLRETURN  nErrResult;             // Return Code from SQLGetDiagRec
	SWORD sMsgNum = 1;
	SWORD fFirstRun = TRUE;

	szBuffer[0] = '\0';

	do
	{
		// continue to bring messageboxes till all errors are displayed.
		// more than one message box may be reqd. as err text has fixed
		// string size.

		// initialize display buffer with the string in error text buffer
		strcpy(szDispBuffer, szBuffer);

		// call SQLGetDiagRec function with proper ODBC handles, repeatedly until
		// function returns SQL_NO_DATA. Concatenate all error strings
		// in the display buffer and display all results.
		while ((nErrResult = SQLGetDiagRec(fHandleType, handle, sMsgNum++,
			szErrState, (long*)(&dwErrCode), szErrText,
			SQL_MAX_MESSAGE_LENGTH-1, &wErrMsgLen))
			!= SQL_NO_DATA)
		{
			if(nErrResult == SQL_ERROR || nErrResult == SQL_INVALID_HANDLE)
				break;

			wsprintf(szBuffer, SQLERR_FORMAT, (LPSTR)szErrState, dwErrCode);
			iSize = strlen(szDispBuffer);
			if (iSize && (iSize+strlen(szBuffer)+1) >= MAXDISPLAYSIZE)
			   break;
			if (iSize)
			   strcat(szDispBuffer, "\n");
			strcat(szDispBuffer, szBuffer);
		}

        // display proper ERROR or WARNING message with proper title
		if('\0'!=*szDispBuffer){
			if (nResult==SQL_SUCCESS_WITH_INFO){
                wxMessageBox( LPSTR(szErrText), szDispBuffer, wxICON_WARNING );
				_LOGMESSAGE_( "%s %s", szDispBuffer, LPSTR(szErrText) );
            }
			else{
                wxMessageBox( LPSTR(szErrText), szDispBuffer, wxICON_ERROR );
				_LOGMESSAGE_( "%s %s", szDispBuffer, LPSTR(szErrText) );
            }
		}

		if (fFirstRun)
			fFirstRun = FALSE;
	}
	while (!(nErrResult == SQL_NO_DATA || nErrResult == SQL_ERROR || nErrResult == SQL_INVALID_HANDLE));
}

//
// Interface functions
//

//
// OdbcW_InitSqlEnvironment()
//
bool OdbcW_SqlInitEnvironment()
{
	// Allocate an Environment Handle
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &s_sqlENVHandle)!=SQL_SUCCESS)
	{
		_LOGMESSAGE_( _("Unable to allocate SQL handle") );
		return false;
	}

	if (SQLSetEnvAttr(s_sqlENVHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, SQL_IS_INTEGER)!=SQL_SUCCESS)
	{
		_LOGMESSAGE_( _("Unable to set SQL environment") );
		return false;
	}

	_LOGMESSAGE_( _("SQL environment initialized") );

	return true;
}

//
// OdbcW_FreeSqlEnvironment
//
bool OdbcW_SqlFreeEnvironment()
{
	if(SQLFreeHandle(SQL_HANDLE_ENV, s_sqlENVHandle)!=SQL_SUCCESS)
	{
		_LOGMESSAGE_( _("Unable to free SQL environment") );
		return false;
	}

	_LOGMESSAGE_( _("SQL environment freed") );

	return true;
}

//
// OdbcW_SqlConnect
//
bool OdbcW_SqlConnect(const OdbcWConnectionId& connectionId)
{
	if(SQL_NULL_HDBC!=OdbcW_GetSqlConnectionHDBC(connectionId))
		return true;

	// Allocate a new SQLHDBC. If successful then call SQLConnect using the
	// allocated hdbc and supplied connection information.
	SQLHDBC hdbc;
	int nResult(SQLAllocHandle(SQL_HANDLE_DBC, s_sqlENVHandle, (SQLHDBC FAR *)&hdbc)!=SQL_SUCCESS);
	if (nResult)
	{
		_LOGMESSAGE_( _("Unable to allocate DBC handle") );
		OdbcW_DisplaySQLError(nResult, SQL_HANDLE_ENV, s_sqlENVHandle);
		return false;
	}

	// if failed to connect, free the allocated hdbc before return
	SQLCHAR OutConnectString[MAXBUFLEN];
	SQLSMALLINT StringLength;
	nResult=SQLDriverConnect(hdbc,
                            NULL,
                            (SQLCHAR*)(connectionId.GetDataSourceName().c_str()),
							SQL_NTS,
                            (SQLCHAR*)OutConnectString,
                            sizeof(OutConnectString),
                            &StringLength,
                            SQL_DRIVER_NOPROMPT);
	if (SQL_SUCCESS!=nResult && SQL_SUCCESS_WITH_INFO!=nResult)
	{
		_LOGMESSAGE_( _("Unable to connect DBC handle") );
		OdbcW_DisplaySQLError(nResult, SQL_HANDLE_DBC, hdbc);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		return false;
	}

	// display any connection information if driver returns SQL_SUCCESS_WITH_INFO
	if (nResult == SQL_SUCCESS_WITH_INFO)
		OdbcW_DisplaySQLError(nResult, SQL_HANDLE_DBC, hdbc);

	s_sqlDBCHandle[connectionId]=hdbc;
	_LOGMESSAGE_( _("Successfully connected to %s"), connectionId.GetDataSourceName().c_str());

	return true;
}

//
// OdbcW_SqlFreeConnection
//
bool OdbcW_SqlFreeConnection(const OdbcWConnectionId& connectionId)
{
	SQLHDBC hdbc(OdbcW_GetSqlConnectionHDBC(connectionId));
	if(SQL_NULL_HDBC==hdbc)
	{
		_LOGERROR_( _("Unable to free connection to dsn %s"), connectionId.GetDataSourceName().c_str());
		return false;
	}

	s_sqlDBCHandle.erase(s_sqlDBCHandle.find(connectionId));
	SQLDisconnect(hdbc);
	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	_LOGMESSAGE_( _("Freed connection to %s"), connectionId.GetDataSourceName().c_str());

	return true;
}

//
// OdbcW_SqlConnectionReady
//
bool OdbcW_SqlConnectionReady(const OdbcWConnectionId& connectionId)
{
	return SQL_NULL_HDBC!=OdbcW_GetSqlConnectionHDBC(connectionId);
}

//
// OdbcW_SqlExecuteQuery
//
bool OdbcW_SqlExecuteQuery(const OdbcWConnectionId& connectionId, const char* sqlQueryString, OdbcW_QueryResultSet* resultSet)
{
	SQLHDBC hdbc(OdbcW_GetSqlConnectionHDBC(connectionId));
	if(SQL_NULL_HDBC==hdbc)
	{
		_LOGERROR_( _("Connection to dsn %s is not ready"), connectionId.GetDataSourceName().c_str());
		return false;
	}

	// Allocate a new Statement Handle on the scanned hdbc
	SQLHSTMT hstmt;
	int nResult(SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt));
	if(SQL_SUCCESS!=nResult){
		OdbcW_DisplaySQLError(nResult, SQL_HANDLE_DBC, hdbc);
		return false;
	}

    int nReturn(SQLExecDirect(hstmt, (unsigned char*)(sqlQueryString), SQL_NTS));
	if(SQL_SUCCESS!=nReturn)
	{
		OdbcW_DisplaySQLError(nReturn, SQL_HANDLE_STMT, hstmt);

		// if the return value was just information, carry on
		if(SQL_SUCCESS_WITH_INFO!=nReturn)
		{
			// Close the open result set.
			SQLCloseCursor(hstmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
			return false;
		}
	}

	if(NULL==resultSet)
	{
		SQLCloseCursor(hstmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return true;
	}
	resultSet->Reset();

	// call SQLNumResultCols to calculate the number of columns in
	// the result set, if more than the MAX_COL (the array boundary)
	// limit the number to MAX_COL and display truncation warning.
	// if it is 0, the statement probably was a non-SELECT simply return
	short nCols;
	nReturn=SQLNumResultCols(hstmt, &nCols);
	if (nCols>MAX_COL)
	{
		nCols = MAX_COL;
		char szDispBuffer[MAXDISPLAYSIZE];
		wsprintf(szDispBuffer, COLTRUNC_WARNG, MAX_COL);
		_LOGMESSAGE_(szDispBuffer);
	}
	else
		if (nCols==0)
		{
			// Close the open result set.
			SQLCloseCursor(hstmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
			return true;
		}

	// Before bind scroll the cursor
	const int firstRow(resultSet->GetFieldsToSkip()/nCols);
	for(int k0(0); k0<firstRow; ++k0){
		const int fetchResult(SQLFetch(hstmt));
		switch(fetchResult){
			case SQL_SUCCESS:
				break;
			case SQL_SUCCESS_WITH_INFO:
				OdbcW_DisplaySQLError(fetchResult, SQL_HANDLE_STMT, hstmt);
				break;
			default:
				_LOGERROR_( _("Unable to seek first row") );
				OdbcW_DisplaySQLError(fetchResult, SQL_HANDLE_STMT, hstmt);

				SQLCloseCursor(hstmt);
				SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
				return false;
				break;
		}
	}

	// call SQLBindCol to bind column data array and column data length
	// array to the result set
	UCHAR  rgbData[MAX_COL][MAXDATALEN]; // Results Data Array
	SDWORD dwDataLen[MAX_COL]; // Results Data Length Array
	UCHAR szBuffer[MAXBUFLEN+1];      // display buffer
	int nCount;
	for(nCount=0; nCount<nCols; nCount++)
		SQLBindCol(hstmt, (UWORD)(nCount+1), SQL_C_CHAR, rgbData[nCount], MAXDATALEN, &dwDataLen[nCount]);

	SWORD     swColType;                  // column data type
	SWORD     swColScale;                 // column scale
	SWORD     swColNull;                  // nullable column ?
	SWORD     swColLength = MAXDATALEN;   // column data length
	UDWORD    udwColDef;                  // precision on the column
	for(nCount=1; nCount<=nCols; nCount++){
		SQLDescribeCol(hstmt, nCount, szBuffer, MAXDATALEN, &swColLength, &swColType, &udwColDef, &swColScale, &swColNull);
		resultSet->AppendColumn((const char*)(szBuffer), OdbcW_ConvertSqlTypeToWOdbcType(swColType));
	}

	// call SQLFetch to fetch each row of the result set. Extract data
	// value and store it in the display buffer, separated by tabs.
	// continue until SQLFetch fails.
	const int firstField(firstRow*nCols);
	const int lastField(resultSet->GetFieldBufferSize());

	int kFields(0);
	while(((nReturn=SQLFetch(hstmt))==SQL_SUCCESS || nReturn==SQL_SUCCESS_WITH_INFO))
	{
		for(nCount=0; nCount<nCols; nCount++)
		{
			if ( lastField==0 || kFields<lastField )
			{
				// check if the column is a null value?
				resultSet->AppendField((dwDataLen[nCount]==SQL_NULL_DATA)?NULLDATASTRING:(char*)(rgbData[nCount]));
			}
		}
		kFields+=nCols;
	}
	resultSet->SetFieldsFound(kFields);
	SQLFreeStmt(hstmt, SQL_UNBIND);

	if(SQL_NO_DATA!=nReturn)
		OdbcW_DisplaySQLError(nReturn, SQL_HANDLE_STMT, hstmt);

	// if there was any error returned by SQLFetch, display it
	if (SQL_ERROR!=nReturn)
		OdbcW_DisplaySQLError(nReturn, SQL_HANDLE_STMT, hstmt);

	// Close the open result set.
	// Unbind all bound columns.
	SQLCloseCursor(hstmt);
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);

	return true;
}
