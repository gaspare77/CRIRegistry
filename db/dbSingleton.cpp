//---------------------------------------------------------------------------
// Name:        dbSingleton.cpp
// Author:      Gaspare Faraci
// Created:     29/6/2009
//---------------------------------------------------------------------------

#include "dbSingleton.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
dbSingleton::dbSingleton() :
    m_dbFieldDummy()
{
    m_OdbcWConId = (OdbcWConnectionId*)NULL;
    m_OdbcW = (OdbcW*)NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Destructor implementation
// 
dbSingleton::~dbSingleton()
{
    if ( m_OdbcW )
    {
        delete m_OdbcW;
        m_OdbcW = (OdbcW*)NULL;
    }
    if ( m_OdbcWConId )
    {
        delete m_OdbcWConId;
        m_OdbcWConId = (OdbcWConnectionId*)NULL;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool dbSingleton::Connect( const wxString& filename, const wxString& user, const wxString& pwd )
{
	wxString dnsFileName( wxGetCwd() + _T("\\") + filename );
    
	if ( !wxFileExists( dnsFileName ) )
    {
        ERROR_MESSAGE( _("Il file %s non e' stato trovato"), dnsFileName.c_str() );
        return false;
    }

    wxString dnsinfo;
//    dnsinfo << _T("FILEDSN=") << dnsFileName << _T(";UID=") << user << _T(";PWD=") << pwd;
//    dnsinfo << _T("DSN=") << dsnname << _T(";UID=") << user << _T(";PWD=") << pwd;
    dnsinfo = wxString::Format( _T("FILEDSN=%s"), dnsFileName.c_str() );
    m_OdbcWConId = new OdbcWConnectionId( dnsinfo.c_str(), "", "" );

    if ( !m_OdbcWConId )
    {
        ERROR_MESSAGE( _("m_OdbcWConId is NULL") );
        return false;
    }

    m_OdbcW = new OdbcW( *m_OdbcWConId );
    if ( !m_OdbcW )
    {
        ERROR_MESSAGE( _("m_OdbcW is NULL") );
        return false;
    }

    return m_OdbcW->Connect();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool dbSingleton::IsConnected()
{
    if ( !m_OdbcWConId || !m_OdbcW )
    {
        ERROR_MESSAGE( _("m_OdbcWConId or m_OdbcW are NULL") );
        return false;
    }

    if ( m_OdbcW->IsConnected() )
        return true;

    if ( m_OdbcW->Connect() )
        return true;

    ERROR_MESSAGE( _("Non e' stato possibile connettersi al DataBase") );
    return false;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool dbSingleton::SQLQuery( const wxString& query, dbResultSet* ResultSet )
{
    // Check the connection
    if ( !IsConnected() )
    {
        return false;
    }

    //INFO_MESSAGE(query);
    // If ResultSet is NULL execute only a SQL query without result
    if ( !ResultSet )
    {
        return m_OdbcW->ExecuteQuery( query.c_str(), NULL );
    }
    else
    {
        ResultSet->Clear();
    }

    // Execute the SQL query
    OdbcW_QueryResultSet res;
    if ( !m_OdbcW->ExecuteQuery( query.c_str(), &res ) )
    {
        return false;
    }

    // Store the result set
    std::vector<std::string> Fields( res.GetFields() );
    std::vector<OdbcW_QueryResultSet::ColumnDescriptor> Columns( res.GetColumns() );
    dbRow row;

    for ( unsigned int i = 0, a = 0; i < Fields.size(); i++ )
    {
        // Add the Field into the Row
        row.Add( Columns[a].GetName(), Fields[i], Columns[a].GetType() );
        
        // Increment the position of column name into the vector or return at the begin
        if ( a < Columns.size() - 1 )
        {
            a++;
        }
        else
        {
            a = 0;
            ResultSet->Add( row );
            row.Clear();
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool dbSingleton::SQLUpdate( const wxString& table, const dbRow& row, const wxString& condition )
{
    // Check the connection
    if ( !IsConnected() )
    {
        return false;
    }

    if ( row.GetSQLSet().IsEmpty() )
	{
		return true;
	}

    wxString query;
    query = wxString::Format( _T("UPDATE %s SET %s WHERE %s"), table.c_str(), row.GetSQLSet().c_str(), condition.c_str()  );
//    INFO_MESSAGE(query);

    return m_OdbcW->ExecuteQuery( query.c_str(), NULL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool dbSingleton::SQLInsert( const wxString& table, const dbRow& row )
{
    // Check the connection
    if ( !IsConnected() )
    {
        return false;
    }

    wxString query;
    query = wxString::Format( _T("INSERT INTO %s (%s) VALUES (%s)"), table.c_str(), row.GetFields().c_str(), row.GetValues().c_str() );
//    INFO_MESSAGE(query);

    return m_OdbcW->ExecuteQuery( query.c_str(), NULL );
}


/////////////////////////////////////////////////////////////////////////////
// 
// 
bool dbSingleton::SQLDelete( const wxString& table, const wxString& condition )
{
    // Check the connection
    if ( !IsConnected() )
    {
        return false;
    }

    wxString query;
    OdbcW_QueryResultSet res;

    query = wxString::Format( _T("SELECT * FROM %s WHERE %s"), table.c_str(), condition.c_str() );
    //   INFO_MESSAGE(query);

    m_OdbcW->ExecuteQuery( query.c_str(), &res );
    if ( res.GetFieldsFound() == 0 )
    {
        return true;
    }

    query = wxString::Format( _T("DELETE FROM %s WHERE %s"), table.c_str(), condition.c_str() );
 //   INFO_MESSAGE(query);

    return m_OdbcW->ExecuteQuery( query.c_str(), NULL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
int dbSingleton::SQLCount( const wxString& table, const wxString& field, const wxString& condition )
{
    // Check the connection
    if ( !IsConnected() )
    {
        return -1;
    }

    dbResultSet res;
    wxString szFieldAs( _T("CountValue") );
    wxString query;

    if ( condition.IsEmpty() )
    {
        query = wxString::Format( _T("SELECT COUNT(%s) AS \'%s\' FROM %s"), field.c_str(), szFieldAs.c_str(), table.c_str() );
    }
    else
    {
        query = wxString::Format( _T("SELECT COUNT(%s) AS \'%s\' FROM %s WHERE %s"), field.c_str(), szFieldAs.c_str(), table.c_str(), condition.c_str() );
    }
    
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return -1;
    }

    return res[szFieldAs].GetIntValue();
}
/////////////////////////////////////////////////////////////////////////////
// 
// 
int dbSingleton::SQLGetMax( const wxString& table, const wxString& field, const wxString& condition )
{
    // Check the connection
    if ( !IsConnected() )
    {
        return -1;
    }

    dbResultSet res;
    wxString szFieldAs( _T("MaxValue") );
    wxString query;

    if ( condition.IsEmpty() )
    {
        query = wxString::Format( _T("SELECT MAX(%s) AS \'%s\' FROM %s"), field.c_str(), szFieldAs.c_str(), table.c_str() );
    }
    else
    {
        query = wxString::Format( _T("SELECT MAX(%s) AS \'%s\' FROM %s WHERE %s"), field.c_str(), szFieldAs.c_str(), table.c_str(), condition.c_str() );
    }

    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return -1;
    }

    return res[szFieldAs].GetIntValue();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
wxDateTime dbSingleton::SQLGetLastDate( const wxString& table, const wxString& field, const wxString& condition )
{
    // Check the connection
    if ( !IsConnected() )
    {
        return wxDateTime::Now();
    }

    dbResultSet res;
    wxString szFieldAs( _T("MaxValue") );
    wxString query;

    if ( condition.IsEmpty() )
    {
        query = wxString::Format( _T("SELECT MAX(%s) AS \'%s\' FROM %s"), field.c_str(), szFieldAs.c_str(), table.c_str() );
    }
    else
    {
        query = wxString::Format( _T("SELECT MAX(%s) AS \'%s\' FROM %s WHERE %s"), field.c_str(), szFieldAs.c_str(), table.c_str(), condition.c_str() );
    }

    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return wxDateTime::Now();
    }

    return res[szFieldAs].GetDateTimeValue();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool dbSingleton::CreateTables()
{
    // Check the connection
    if ( !IsConnected() )
    {
        return false;
    }

    wxString filename = wxFileSelector();
    if ( filename.IsEmpty() )
    {
        return true;
    }

    wxFFile file( filename );
    wxString query;
    if ( !file.Open(filename) || !file.ReadAll(&query) || !file.Close() )
    {
        return false;
    }
    
    //    INFO_MESSAGE(query);
        return m_OdbcW->ExecuteQuery( query.c_str(), NULL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
wxArrayString dbSingleton::SQLGetColArray( const wxString& query, int col )
{
    wxArrayString asz;
    asz.Clear();

    // Check the connection
    if ( IsConnected() )
    {
        // Append into the array all row field for the column requested
        dbResultSet res;
        if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
        {
            for ( unsigned int i = 0; i < res.GetSize(); i++ )
            {
                asz.Add( res.Row(i).Col(col).GetStringValue() );
            }
        }
    }

    return asz;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
wxArrayString dbSingleton::SQLGetColArray( const wxString& query, const wxString& col )
{
    wxArrayString asz;
    asz.Clear();

    // Check the connection
    if ( IsConnected() )
    {
        // Append into the array all row field for the column requested
        dbResultSet res;
        if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
        {
            for ( unsigned int i = 0; i < res.GetSize(); i++ )
            {
                asz.Add( res.Row(i).Col(col).GetStringValue() );
            }
        }
    }

    return asz;
}
