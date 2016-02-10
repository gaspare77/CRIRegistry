//
// OdbcW.cpp
//
#pragma warning (disable : 4786)

#include <stdlib.h>
#include <stdio.h>
#include <map>
#include "OdbcW.h"
#include "OdbcWSetup.h"
#include "OdbcWInternal.h"

//
// class OdbcW_QueryResultSet method
//
OdbcW_QueryResultSet::OdbcW_QueryResultSet(const unsigned int maxFieldBufferSize, const unsigned int fieldsToSkip):
	m_columns(),
	m_fields(),
	m_fieldBufferSize(maxFieldBufferSize),
	m_fieldsToSkip(fieldsToSkip),
	m_fieldsFound(0){
}

OdbcW_QueryResultSet::~OdbcW_QueryResultSet(){
}

void OdbcW_QueryResultSet::Reset()
{
	m_columns.clear();
	m_fields.clear();
	m_fieldsFound=0;

	if(0!=m_fieldBufferSize)
		m_fields.reserve(m_fieldBufferSize);
}

void OdbcW_QueryResultSet::AppendColumn(const char* columnName, OdbcW_DataType columnType)
{
	m_columns.push_back(ColumnDescriptor(columnName, columnType));
}

void OdbcW_QueryResultSet::AppendField(const char* fieldValue)
{
	m_fields.push_back(fieldValue);
}

const std::vector<OdbcW_QueryResultSet::ColumnDescriptor>& OdbcW_QueryResultSet::GetColumns() const
{
	return m_columns;
}

const std::vector<std::string>& OdbcW_QueryResultSet::GetFields() const
{
	return m_fields;
}

unsigned int OdbcW_QueryResultSet::GetFieldBufferSize() const
{
	return m_fieldBufferSize;
}

unsigned int OdbcW_QueryResultSet::GetFieldsToSkip() const
{
	return m_fieldsToSkip;
}

unsigned int OdbcW_QueryResultSet::GetFieldsFound() const
{
	return m_fieldsFound;
}

void OdbcW_QueryResultSet::SetFieldBufferSize(unsigned int fieldBufferSize)
{
	m_fieldBufferSize=fieldBufferSize;
	Reset();
}

void OdbcW_QueryResultSet::SetFieldsToSkip(unsigned int fieldsToSkip)
{
	m_fieldsToSkip=fieldsToSkip;
}

void OdbcW_QueryResultSet::SetFieldsFound(unsigned int fieldsFound)
{
	m_fieldsFound=fieldsFound;
}

//
// OdbcWConnectionId methods
//
OdbcWConnectionId::OdbcWConnectionId(const char* dataSourceName, const char* login, const char* password):
	m_dataSourceName(dataSourceName),
	m_login(login),
	m_password(password){}
OdbcWConnectionId::~OdbcWConnectionId(){}

std::string OdbcWConnectionId::GetDataSourceName() const{return m_dataSourceName;}
std::string OdbcWConnectionId::GetLogin() const {return m_login;}
std::string OdbcWConnectionId::GetPassword() const {return m_password;}

bool operator < (const OdbcWConnectionId& first, const OdbcWConnectionId& second)
{
	return first.GetDataSourceName() < second.GetDataSourceName();
}

//
// class ReferenceCounter
//
class ReferenceCounter
{
public:
	ReferenceCounter():m_counter(0){}
	virtual ~ReferenceCounter(){}

	operator int(){return m_counter;}	
	void operator ++(){++m_counter;}
 	void operator --(){--m_counter;}
protected:
private:
	int m_counter;
};

//
// class OdbcW methods
//
static int s_odbcWinstancesCounter=0;
static std::map<OdbcWConnectionId, ReferenceCounter> s_connectionReferenceCounters;

OdbcW::OdbcW(const OdbcWConnectionId& connectionId):
	m_connectionId(connectionId)
{
	_SYNCRONIZE_

	if(0==s_odbcWinstancesCounter)
		OdbcW_SqlInitEnvironment();
	++s_odbcWinstancesCounter;
}

OdbcW::~OdbcW()
{
	_SYNCRONIZE_

	--s_connectionReferenceCounters[m_connectionId];
	if(0==s_connectionReferenceCounters[m_connectionId])
		OdbcW_SqlFreeConnection(m_connectionId);

	--s_odbcWinstancesCounter;
	if(0==s_odbcWinstancesCounter)
		OdbcW_SqlFreeEnvironment();
}

bool OdbcW::Connect()
{
	_SYNCRONIZE_

	if(0==s_connectionReferenceCounters[m_connectionId])
	{
		if(true==OdbcW_SqlConnect(m_connectionId))
		{
			++s_connectionReferenceCounters[m_connectionId];
			return true;
		} else
			return false;
	} else
		++s_connectionReferenceCounters[m_connectionId];

	return true;
}

bool OdbcW::IsConnected() const
{
	return OdbcW_SqlConnectionReady(m_connectionId);
}

bool OdbcW::ExecuteQuery(const char* queryString, OdbcW_QueryResultSet* resultSet) const
{
	_SYNCRONIZE_

	const bool queryResult(OdbcW_SqlExecuteQuery(m_connectionId, queryString, resultSet));
	if(queryResult==false)
	{
		_LOGERROR_("Unable to execute query:");
		_LOGERROR_("%s", queryString);
		_LOGERROR_("Error executing query");
	}
	else
	{
		_LOGMESSAGE_("Executed query:");
		_LOGMESSAGE_("%s", queryString);

	}

	return queryResult;
}
