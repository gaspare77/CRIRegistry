//---------------------------------------------------------------------------
// Name:        dbClass.cpp
// Author:      Gaspare Faraci
// Created:     2/10/2010
//---------------------------------------------------------------------------

#include "dbClass.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
dbClass::dbClass( const wxString& TableName, const wxString& IdFieldName )
{    
	m_szTableName = TableName;
	m_szIdFieldName = IdFieldName;
    m_dbRow.Add( IdFieldName, 0 );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
dbClass::dbClass( const dbClass& f )
{
    CopyData( f );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
dbClass::dbClass( const dbRow& r, const wxString& TableName, const wxString& IdFieldName )
{
	m_szTableName = TableName;
	m_szIdFieldName = IdFieldName;
	m_dbRow = r;
}

/////////////////////////////////////////////////////////////////////////////
// Destructor implementation
// 
dbClass::~dbClass()
{
}

/////////////////////////////////////////////////////////////////////////////
// Assignement operator
// 
const dbClass& dbClass::operator=( const dbClass& f )
{
    if ( this != &f )
    {
        CopyData( f );
    }

    return *this;
}

/////////////////////////////////////////////////////////////////////////////
// Copy all members
// 
void dbClass::CopyData( const dbClass& src )
{
    m_dbRow = src.m_dbRow;
    m_szIdFieldName = src.m_szIdFieldName;
    m_szTableName = src.m_szTableName;
}

/////////////////////////////////////////////////////////////////////////////
// Insert the dbRow into the DataBase
// 
bool dbClass::InsertIntoDb()
{
	int Id = dbSingleton::Instance()->SQLGetMax( m_szTableName, m_szIdFieldName );
	if ( ++Id < 1 )
	{
		ERROR_MESSAGE( _("dbClass::InsertIntoDb() Id < 1 into table: %s"), m_szTableName.c_str() );
		return false;
	}
	m_dbRow[m_szIdFieldName] = Id;

	return dbSingleton::Instance()->SQLInsert( m_szTableName, m_dbRow );
}

/////////////////////////////////////////////////////////////////////////////
// Select the dbRow from the DataBase
// 
bool dbClass::SelectFromDb()
{
	if ( m_dbRow[m_szIdFieldName].GetType() != WDT_INTEGER )
	{
		ERROR_MESSAGE( _("dbClass()::SelectFromDb() Invalid Id Field (%s) Type (%d) into table (%s)"), m_szIdFieldName.c_str(), m_dbRow[m_szIdFieldName].GetType(), m_szTableName.c_str() );
		return false;
	}

    dbResultSet res;
	wxString query = wxString::Format( _T("SELECT * FROM %s WHERE %s=%d"), m_szTableName.c_str(), m_szIdFieldName.c_str(), GetId() );
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_dbRow = res.Row();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Update the dbRow into the DataBase
// 
bool dbClass::UpdateIntoDb()
{
	if ( m_dbRow[m_szIdFieldName].GetType() != WDT_INTEGER )
	{
		ERROR_MESSAGE( _("dbClass()::UpdateIntoDb() Invalid Id Field (%s) Type (%d) into table (%s)"), m_szIdFieldName.c_str(), m_dbRow[m_szIdFieldName].GetType(), m_szTableName.c_str() );
		return false;
	}
    
    wxString condition = wxString::Format( _T("%s=%d"), m_szIdFieldName.c_str(), GetId() );
	return dbSingleton::Instance()->SQLUpdate( m_szTableName, m_dbRow, condition );
}

/////////////////////////////////////////////////////////////////////////////
// Remove the dbRow into the DataBase
// 
bool dbClass::RemoveFromDb()
{
	if ( m_dbRow[m_szIdFieldName].GetType() != WDT_INTEGER )
	{
		ERROR_MESSAGE( _("dbClass()::RemoveFromDb() Invalid Id Field (%s) Type (%d) into table (%s)"), m_szIdFieldName.c_str(), m_dbRow[m_szIdFieldName].GetType(), m_szTableName.c_str() );
		return false;
	}
    
    wxString condition = wxString::Format( _T("%s=%d"), m_szIdFieldName.c_str(), GetId() );
    return dbSingleton::Instance()->SQLDelete( m_szTableName, condition );
}
