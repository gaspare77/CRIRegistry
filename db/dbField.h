//---------------------------------------------------------------------------
// Name:        dbField.cpp
// Author:      Gaspare Faraci
// Created:     11/7/2008
//---------------------------------------------------------------------------

#ifndef __DBFIELD_H_INCL__
#define __DBFIELD_H_INCL__

#include <wx/wx.h>
#include <wx/tokenzr.h>
#include <map>
#include <vector>

#include "../OdbcW/OdbcW.h"
#include "../MyFunctions.h"


///////////////////////////////////////////////////////////////////////////////
// 
//  Class dbField
//
///////////////////////////////////////////////////////////////////////////////
class dbField
{
public:
    dbField();
    virtual ~dbField();
    void Set( const wxString& name, const wxString& value, OdbcW_DataType type = WDT_STRING );
    void Set( const wxString& name, const char* value );
    void Set( const wxString& name, const wxDateTime& value );
    void Set( const wxString& name, const double& value );
    void Set( const wxString& name, const int& value );
    void Set( const wxString& name, const bool& value );
    void Clear();

    const wxString& GetName() const { return m_szName; }
    const OdbcW_DataType& GetType() const { return m_eDataType; } 

    const wxString& GetStringValue() const;
    const char* GetCharValue() const;
    float GetFloatValue() const;
    int GetIntValue() const;
    bool GetBoolValue() const;
    wxDateTime GetDateTimeValue() const;
	wxString GetSQLFormatValue() const;
    
	void SetValue( const wxString& value );
    void SetValue( const char* value );
    void SetValue( const int& value );
    void SetValue( const bool& value );
    void SetValue( const double& value );
    void SetValue( const wxDateTime& value );
    
    dbField& operator= ( const dbField& f );

    void operator= ( const wxString& value){ SetValue( value ); }
    void operator= ( const wxDateTime& value){ SetValue( value ); }
    void operator= ( const char* value){ SetValue( value ); }
    void operator= ( const int& value){ SetValue( value ); }
    void operator= ( const double& value){ SetValue( value ); }
    void operator= ( const bool& value){ SetValue( value ); }

    bool operator==( const dbField& f ) const;
    bool operator!=( const dbField& f ) const;

    bool IsEmpty() { return GetStringValue().IsEmpty() || GetDateTimeValue() == EmptyDate; }

private:
    wxString        m_szName;
    wxString        m_szValue;
    OdbcW_DataType  m_eDataType;

    void Initialize();
};

///////////////////////////////////////////////////////////////////////////////
// 
//  Class dbRow
//
///////////////////////////////////////////////////////////////////////////////
class dbRow
{
public:
    dbRow();
    dbRow( const dbRow& r );
    virtual const dbRow& operator=( const dbRow& r );
    virtual ~dbRow();
    void Clear();
    void Add( const wxString& name, const wxString& value, OdbcW_DataType type = WDT_STRING );
    void Add( const wxString& name, const char* value );
    void Add( const wxString& name, int value );
    void Add( const wxString& name, bool value );
    void Add( const wxString& name, double value );
    void Add( const wxString& name, const wxDateTime& value );
    void Add( const dbField& field );
	void Del( const wxString& name );
    dbField& Col( const wxString& name );
    dbField& Col( unsigned int i = 0 );
    dbField& operator[]( const wxString& name ){ return Col(name); };
    dbField& operator()( unsigned int i ){ return Col(i); };
    const dbField& Col( const wxString& name ) const;
    const dbField& Col( unsigned int i = 0 ) const;
    const dbField& operator[]( const wxString& name ) const { return Col(name); };
    const dbField& operator()( unsigned int i ) const { return Col(i); };
	wxString GetFields() const;
    wxString GetValues() const;
    wxString GetSQLSet() const;
    size_t GetSize() const;
    bool operator==( const dbRow& r ) const;
    bool operator!=( const dbRow& r ) const;
    
    wxString Serialize();
    bool Unserialize( const wxString& s );

private:
    void CopyData( const dbRow& r );
	std::vector<dbField>::iterator Get( const wxString& name );
	std::vector<dbField>::const_iterator Get( const wxString& name ) const;
    std::vector<dbField>	m_dbFields;
    dbField                 m_dbFieldDummy;
    wxString                m_szLastFieldUnserialized;
};

///////////////////////////////////////////////////////////////////////////////
// 
//  Class dbResultSet
//
///////////////////////////////////////////////////////////////////////////////
class dbResultSet
{
public:
    dbResultSet();
    virtual ~dbResultSet();
    void Clear();
    void Add( const dbRow& row );
    dbRow& Row( unsigned int row = 0 );
	const dbRow& Row( unsigned int row = 0 ) const;
	dbField& operator[]( const wxString& name ) ;
	const dbField& operator[]( const wxString& name ) const;
	size_t GetSize() const;

private:
    std::vector<dbRow>  m_ResultSet;
    dbRow               m_RowDummy;
    dbField             m_FieldDummy;
};
#endif
