//---------------------------------------------------------------------------
// Name:        dbClass.cpp
// Author:      Gaspare Faraci
// Created:     2/10/2010
//---------------------------------------------------------------------------

#ifndef __DBCLASS_H_INCL__
#define __DBCLASS_H_INCL__

#include "dbSingleton.h"

class dbClass
{
public:
    // Constructor
	dbClass() {};
    dbClass( const wxString& TableName, const wxString& IdFieldName );
    dbClass( const dbClass& f );
    dbClass( const dbRow& r, const wxString& TableName, const wxString& IdFieldName );
    // Destructor
    virtual ~dbClass();
    // Assignement operator
    virtual const dbClass& operator=( const dbClass& f );
    // Compare operator
    virtual bool operator==( const dbClass& f ) const { return m_dbRow == f.m_dbRow;}
    virtual bool operator!=( const dbClass& f ) const { return m_dbRow != f.m_dbRow;}
    // Get the Field
    virtual dbField& operator[]( const wxString& name ) { return m_dbRow[name]; }
    virtual const dbField& operator[]( const wxString& name ) const { return m_dbRow[name]; }
    virtual dbField& GetField( const wxString& name ) { return m_dbRow[name]; }
    virtual const dbField& GetField( const wxString& name ) const { return m_dbRow[name]; }
	// Add a Field
	virtual void Add( const wxString& name, OdbcW_DataType type ){ m_dbRow.Add( name, wxEmptyString, type ); }
	virtual void Add( const wxString& name, const wxString& value ){ m_dbRow.Add( name, value, WDT_STRING ); }
	virtual void Add( const wxString& name, int value ){ m_dbRow.Add( name, value ); }

    // Insert the dbRow into the DataBase
    virtual bool InsertIntoDb();
    // Select the dbRow from the DataBase
    virtual bool SelectFromDb();
    // Update the dbRow into the DataBase
    virtual bool UpdateIntoDb();
    // Remove the dbRow into the DataBase
    virtual bool RemoveFromDb();

    // Get Table Name
    virtual const wxString& GetTableName() const { return m_szTableName; }
    // Get Field Id Name
    virtual const wxString& GetIdFieldName() const { return m_szIdFieldName; }
    // Get Id Fields Value
    virtual int GetId() const { return m_dbRow[m_szIdFieldName].GetIntValue(); }
    // Set Id Fields Value
    virtual void SetId( int n ) { m_dbRow[m_szIdFieldName] = n; }

    wxString Serialize() { return m_dbRow.Serialize(); }
    bool Unserialize( const wxString& s ) { return m_dbRow.Unserialize( s ); }

protected:
    dbRow       m_dbRow;

private:
    void CopyData( const dbClass& src );

    wxString    m_szIdFieldName;
    wxString    m_szTableName;
};
#endif // __DBCLASS_H_INCL__
