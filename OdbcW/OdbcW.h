//
// OdbcW.h
//
#ifndef _ODBCW_H_FILE_
#define _ODBCW_H_FILE_

#include <vector>
#include <string>

enum OdbcW_DataType
{
	WDT_INTEGER=0,
	WDT_REAL,
	WDT_STRING,
	WDT_UNDEFINED
};

//
// class OdbcW_QueryResultSet
//
class OdbcW_QueryResultSet
{
public:
	class ColumnDescriptor
	{
		public:
			ColumnDescriptor(const char* columnName, OdbcW_DataType columnType):
				m_columnName(columnName),
				m_columnType(columnType){}

			virtual ~ColumnDescriptor(){}
		
			std::string GetName() const {return m_columnName;}
			OdbcW_DataType GetType() const {return m_columnType;}
		protected:
		private:
			std::string m_columnName;
			OdbcW_DataType m_columnType;
	};
public:
	OdbcW_QueryResultSet(const unsigned int maxFieldBufferSize=0, const unsigned int fieldsToSkip=0);
	virtual ~OdbcW_QueryResultSet();

	void Reset();
	void AppendColumn(const char* columnName, OdbcW_DataType columnType);
	void AppendField(const char* fieldValue);

	const std::vector<ColumnDescriptor>& GetColumns() const;
	const std::vector<std::string>& GetFields() const;
	unsigned int GetFieldBufferSize() const;
	unsigned int GetFieldsToSkip() const;
	unsigned int GetFieldsFound() const;

	void SetFieldBufferSize(unsigned int fieldBufferSize);
	void SetFieldsToSkip(unsigned int fieldsToSkip);
	void SetFieldsFound(unsigned int totalFieldsFound);
protected:
private:
	std::vector<ColumnDescriptor> m_columns;
	std::vector<std::string> m_fields;
	unsigned int m_fieldBufferSize;
	unsigned int m_fieldsToSkip;
	unsigned int m_fieldsFound;
};

//
// class OdbcWConnectionId
//
class OdbcWConnectionId
{
public:
	OdbcWConnectionId(const char* dataSourceName, const char* login, const char* password);
	virtual ~OdbcWConnectionId();

	std::string GetDataSourceName() const;
	std::string GetLogin() const;
	std::string GetPassword() const;
protected:
private:
	std::string m_dataSourceName;
	std::string m_login;
	std::string m_password;
};
bool operator < (const OdbcWConnectionId& first, const OdbcWConnectionId& second);

//
// class Odbc
//
class OdbcW
{
public:
	OdbcW(const OdbcWConnectionId& connectionId);
	virtual ~OdbcW();

	bool Connect();
	bool IsConnected() const;
	bool ExecuteQuery(const char* query, OdbcW_QueryResultSet* resultSet) const;
protected:
private:
	const OdbcWConnectionId m_connectionId;
};

#endif
