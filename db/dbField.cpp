//---------------------------------------------------------------------------
// Name:        dbField.cpp
// Author:      Gaspare Faraci
// Created:     11/7/2008
//---------------------------------------------------------------------------

#include "dbField.h"

///////////////////////////////////////////////////////////////////////////////
// 
//  Class dbField
//
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
dbField::dbField()
{
    Initialize();
}

/////////////////////////////////////////////////////////////////////////////
// Destructor implementation
// 
dbField::~dbField()
{
}

/////////////////////////////////////////////////////////////////////////////
// Set values
// 
void dbField::Set( const wxString& name, const wxString& value, OdbcW_DataType type )
{
    m_szName = name;
    m_szValue = value;
    m_eDataType = type;
}

/////////////////////////////////////////////////////////////////////////////
// Set values
// 
void dbField::Set( const wxString& name, const char* value )
{
    m_szName = name;
    m_eDataType = WDT_STRING;
    SetValue( value );
}

/////////////////////////////////////////////////////////////////////////////
// Set values
// 
void dbField::Set( const wxString& name, const wxDateTime& value )
{
    m_szName = name;
    m_eDataType = WDT_STRING;
    SetValue( value );
}

/////////////////////////////////////////////////////////////////////////////
// Set values
// 
void dbField::Set( const wxString& name, const double& value )
{
    m_szName = name;
    m_eDataType = WDT_REAL;
    SetValue( value );
}

/////////////////////////////////////////////////////////////////////////////
// Set values
// 
void dbField::Set( const wxString& name, const int& value )
{
    m_szName = name;
    m_eDataType = WDT_INTEGER;
    SetValue( value );
}

/////////////////////////////////////////////////////////////////////////////
// Set values
// 
void dbField::Set( const wxString& name, const bool& value )
{
    m_szName = name;
    m_eDataType = WDT_INTEGER;
    SetValue( value );
}

/////////////////////////////////////////////////////////////////////////////
// Assignment operator for another dbField
// 
dbField& dbField::operator=( const dbField& f )
{
    m_szName = f.m_szName;
    m_szValue = f.m_szValue;
    m_eDataType = f.m_eDataType;

    return *this;
}

/////////////////////////////////////////////////////////////////////////////
// Set a wxString value
// 
void dbField::SetValue( const wxString& value )
{
    wxString s = value;
    s.Trim(true).Trim(false);

	switch ( m_eDataType )
	{
	case WDT_INTEGER:
		SetValue( atoi( s.c_str() ) );
		break;

    case WDT_REAL:
        s.Replace( _T("."), _T(",") );
		SetValue( atof( s.c_str() ) );
		break;

	case WDT_STRING:
		m_szValue = s;
		// If is a email address
		if ( m_szValue.Contains( _T("@") ))
		{
			m_szValue.MakeLower();
		}
		break;

	default:
		ERROR_MESSAGE( _("Unknow DataType for field:\nName: %s\nType: %d\nValue: %s"), 
			m_szName.c_str(),
			(int)m_eDataType,
			m_szValue.c_str() );
		m_szValue = wxEmptyString;
	}
}

/////////////////////////////////////////////////////////////////////////////
// Set a char* value
// 
void dbField::SetValue( const char* value )
{
	m_szValue = value;
}

/////////////////////////////////////////////////////////////////////////////
// Set a int value
// 
void dbField::SetValue( const int& value )
{
	if ( value == 0 )
	{
		m_szValue = wxEmptyString;
		return;
	}
	
    m_szValue = wxString::Format( _T("%d"), value );
}

/////////////////////////////////////////////////////////////////////////////
// Set a bool value
// 
void dbField::SetValue( const bool& value )
{
    m_szValue = value ? _T("1") : _T("0");
}

/////////////////////////////////////////////////////////////////////////////
// Set a float value
// 
void dbField::SetValue( const double& value )
{
    if ( value == 0.0 )
	{
		m_szValue = wxEmptyString;
		return;
	}
	
    m_szValue = wxString::Format( _T("%.3f"), value );
	m_szValue.Replace( _T(","), _T(".") );
}

/////////////////////////////////////////////////////////////////////////////
// Set a wxDateTime value
// 
void dbField::SetValue( const wxDateTime& value )
{
	if ( value == EmptyDate )
	{
		m_szValue = wxEmptyString;
		return;
	}
	
	m_szValue = value.Format( _T("%Y-%m-%d %H:%M:00") );
}

/////////////////////////////////////////////////////////////////////////////
// Comparison operator
// 
bool dbField::operator==( const dbField& f ) const
{
    return m_szName == f.m_szName && m_eDataType == f.m_eDataType && m_szValue == f.m_szValue;
}

/////////////////////////////////////////////////////////////////////////////
// Comparison operator
// 
bool dbField::operator!=( const dbField& f ) const
{
    return m_szName != f.m_szName || m_eDataType != f.m_eDataType || m_szValue != f.m_szValue;
}

/////////////////////////////////////////////////////////////////////////////
// Clear values
// 
void dbField::Clear()
{
    m_szName = wxEmptyString;
    m_szValue = wxEmptyString;
}

/////////////////////////////////////////////////////////////////////////////
// Initialize values
// 
void dbField::Initialize()
{
    m_szName = wxEmptyString;
    m_szValue = wxEmptyString;
    m_eDataType = WDT_UNDEFINED;
}

/////////////////////////////////////////////////////////////////////////////
// Get the value converted in wxString
// 
const wxString& dbField::GetStringValue() const
{ 
    return m_szValue;
}

/////////////////////////////////////////////////////////////////////////////
// Get the value converted in const char*
// 
const char* dbField::GetCharValue() const 
{ 
    return GetStringValue().c_str(); 
}

/////////////////////////////////////////////////////////////////////////////
// Get the value converted in float
// 
float dbField::GetFloatValue() const
{ 
    wxString s = m_szValue;
    s.Replace( _T("."), _T(",") );

    return atof( s.c_str() );
}

/////////////////////////////////////////////////////////////////////////////
// Get the value converted in int
// 
int dbField::GetIntValue() const
{
    return atoi( m_szValue.c_str() ); 
}

/////////////////////////////////////////////////////////////////////////////
// Get the value converted in bool
// 
bool dbField::GetBoolValue() const
{
    return atoi( m_szValue.c_str() ) == 0 ? false : true; 
}

/////////////////////////////////////////////////////////////////////////////
// Get the value converted in wxDateTime
// 
wxDateTime dbField::GetDateTimeValue() const
{
    wxDateTime d = EmptyDate;
    if ( m_szValue == wxEmptyString )
    {
        return d;
    }

    int year, month, day, hours, minutes;
    wxStringTokenizer tkz( m_szValue, _T("-: "));
    if ( tkz.HasMoreTokens() )
    {
        year = atoi( tkz.GetNextToken().c_str() );
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the year in dbResultSet::GetDateTimeValue()") );
        return d;
    }

    if ( tkz.HasMoreTokens() )
    {
        month = atoi( tkz.GetNextToken().c_str() ) - 1;
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the month in dbResultSet::GetDateTimeValue()") );
        return d;
    }

    if ( tkz.HasMoreTokens() )
    {
        day = atoi( tkz.GetNextToken().c_str() );
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the day in dbResultSet::GetDateTimeValue()") );
        return d;
    }

	if ( tkz.HasMoreTokens() )
	{
		hours = atoi( tkz.GetNextToken().c_str() );
	}
	else
	{
		hours = 0;
	}

	if ( tkz.HasMoreTokens() )
	{
		minutes = atoi( tkz.GetNextToken().c_str() );
	}
	else
	{
		minutes = 0;
	}

	d.Set( day, (wxDateTime::Month)month, year, hours, minutes );

    return d;
}

///////////////////////////////////////////////////////////////////////////////
// 
//
wxString dbField::GetSQLFormatValue() const 
{ 
	wxString _s;
	switch ( m_eDataType )
	{
	case WDT_INTEGER:
		_s = m_szValue.IsEmpty() ? _T("0") : m_szValue;
		break;

	case WDT_REAL:
    case WDT_STRING:
        _s = SQLStringFormat( m_szValue );
/*
        for ( unsigned int i = 0; i < _s.Len(); i++ ) 
        {
            switch ( _s[i] ) 
            {
            case '\0':		// Must be escaped for "mysql"
                _s[i] = '\\';
                _s.insert(++i, "0");
                break;
            case '\n':		// Must be escaped for logs
                _s[i] = '\\';
                _s.insert(++i, "n");
                break;
            case '\r':
                _s[i] = '\\';
                _s.insert(++i, "r");
                break;
            case '\\':
                _s[i] = '\\';
                _s.insert(++i, "\\");
                break;
            case '\"':
                _s[i] = '\\';
                _s.insert(++i, "\"");
                break;
            case '\'':		// Better safe than sorry
                _s[i] = '\\';
                _s.insert(++i, "\'");
                break;
            case '\032':	// This gives problems on Win32
                _s[i] = '\\';
                _s.insert(++i, "Z");
                break;
            default:
                break;
            }
        }

        if ( _s.IsEmpty() )
        {
            _s = _T("NULL");
        }
        else
        {
            _s.insert( 0, "\'");
            _s.insert( _s.Len(), "\'");
        }
*/
		break;
	}
    return _s;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Class dbRow
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 
// 
dbRow::dbRow() : 
m_dbFieldDummy(), m_szLastFieldUnserialized()
{
}

///////////////////////////////////////////////////////////////////////////////
// 
dbRow::dbRow( const dbRow& r )
{
    CopyData( r );
}

///////////////////////////////////////////////////////////////////////////////
// 
const dbRow& dbRow::operator=( const dbRow& r )
{
    CopyData( r );
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// 
dbRow::~dbRow()
{
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Clear()
{
    m_dbFields.clear();
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Add( const wxString& name, const wxString& value, OdbcW_DataType type )
{
    dbField field;

    field.Set( name, value, type );
    Add( field );
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Add( const wxString& name, const char* value )
{
    dbField field;

    field.Set( name, value );
    Add( field );
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Add( const wxString& name, int value )
{
    dbField field;

    field.Set( name, value );
    Add( field );
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Add( const wxString& name, bool value )
{
    dbField field;

    field.Set( name, value );
    Add( field );
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Add( const wxString& name, double value )
{
    dbField field;

    field.Set( name, value );
    Add( field );
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Add( const wxString& name, const wxDateTime& value )
{
    dbField field;

    field.Set( name, value );
    Add( field );
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Add( const dbField& field )
{
    // Check that the field have a name
    if ( field.GetName() == wxEmptyString )
    {
        ERROR_MESSAGE( _("dbRow::Add called with empty field name") );
        return;
    }

    m_dbFields.push_back( field );
}

///////////////////////////////////////////////////////////////////////////////
// 
std::vector<dbField>::iterator dbRow::Get( const wxString& name )
{
	std::vector<dbField>::iterator it;
	for ( it = m_dbFields.begin(); it != m_dbFields.end(); ++it )
	{
		if ( it->GetName().Upper() == name.Upper() )
		{
			break;
		}
	}

	return it;
}

///////////////////////////////////////////////////////////////////////////////
// 
std::vector<dbField>::const_iterator dbRow::Get( const wxString& name ) const
{
	std::vector<dbField>::const_iterator it;
	for ( it = m_dbFields.begin(); it != m_dbFields.end(); ++it )
	{
		if ( it->GetName().Upper() == name.Upper() )
		{
			break;
		}
	}

	return it;
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::Del( const wxString& name )
{
    std::vector<dbField>::iterator it = Get( name );

    if ( it != m_dbFields.end() )
    {
        m_dbFields.erase( it );
    }
}

///////////////////////////////////////////////////////////////////////////////
// 
dbField& dbRow::Col( const wxString& name )
{
    std::vector<dbField>::iterator it = Get( name );

    if ( it != m_dbFields.end() )
    {
        return *it;
    }

    return m_dbFieldDummy;
}

///////////////////////////////////////////////////////////////////////////////
// 
const dbField& dbRow::Col( const wxString& name ) const
{
    std::vector<dbField>::const_iterator it = Get( name );

    if ( it != m_dbFields.end() )
    {
        return *it;
    }

    return m_dbFieldDummy;
}

///////////////////////////////////////////////////////////////////////////////
// 
dbField& dbRow::Col( unsigned int i )
{
    if ( i < m_dbFields.size() )
    {
        return m_dbFields[i];
    }

    return m_dbFieldDummy;
}

///////////////////////////////////////////////////////////////////////////////
// 
const dbField& dbRow::Col( unsigned int i ) const
{
    if ( i < m_dbFields.size() )
    {
        return m_dbFields[i];
    }

    return m_dbFieldDummy;
}

///////////////////////////////////////////////////////////////////////////////
// 
wxString dbRow::GetFields() const
{
    wxString szFields;

    for ( std::vector<dbField>::const_iterator it = m_dbFields.begin(); it != m_dbFields.end(); ++it )
    {
        if ( szFields.IsEmpty() )
        {
            szFields += it->GetName();
        }
        else
        {
            szFields += _T(",") + it->GetName();
        }
    }

    return szFields;
}

///////////////////////////////////////////////////////////////////////////////
// 
wxString dbRow::GetValues() const
{
     wxString szValues;

    for ( std::vector<dbField>::const_iterator it = m_dbFields.begin(); it != m_dbFields.end(); ++it )
    {
        if ( szValues.IsEmpty() )
        {
            szValues += it->GetSQLFormatValue();
        }
        else
        {
            szValues += _T(",") + it->GetSQLFormatValue();
        }
    }

    return szValues;
}

///////////////////////////////////////////////////////////////////////////////
// 
wxString dbRow::GetSQLSet() const
{
    wxString szSQLSet;

    for ( std::vector<dbField>::const_iterator it = m_dbFields.begin(); it != m_dbFields.end(); ++it )
    {
        if ( szSQLSet.IsEmpty() )
        {
            szSQLSet += it->GetName() + _T("=") + it->GetSQLFormatValue();
        }
        else
        {
            szSQLSet += _T(",") + it->GetName() + _T("=") + it->GetSQLFormatValue();
        }
    }

    return szSQLSet;
}

///////////////////////////////////////////////////////////////////////////////
// 
size_t dbRow::GetSize() const
{
    return m_dbFields.size();
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbRow::CopyData( const dbRow& r )
{
    m_dbFields = r.m_dbFields;
    m_dbFieldDummy = r.m_dbFieldDummy;
}

///////////////////////////////////////////////////////////////////////////////
// 
bool dbRow::operator==( const dbRow& r ) const
{
    if ( GetSize() != r.GetSize() )
    {
        return false;
    }

    if ( GetSQLSet() != r.GetSQLSet() )
    {
        return false;
    }

    return true;
}

///////////////////////////////////////////////////////////////////////////////
// 
bool dbRow::operator!=( const dbRow& r ) const
{
    if ( GetSize() != r.GetSize() )
    {
        return true;
    }

    if ( GetSQLSet() != r.GetSQLSet() )
    {
        return true;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////
// 
wxString dbRow::Serialize()
{
    wxString s = wxEmptyString;

    for ( std::vector<dbField>::const_iterator it = m_dbFields.begin(); it != m_dbFields.end(); ++it )
    {
        s += it->GetName() + _T("=") + it->GetStringValue() + _T("\n");
    }
    return s;
}

bool dbRow::Unserialize( const wxString& s )
{
    int pos = s.Find( _T("=") );
    wxString field, value;

    if (( pos == wxNOT_FOUND ) && m_szLastFieldUnserialized.IsEmpty() )
    {
        return false;
    }
    else if ( pos == wxNOT_FOUND )
    {
        field = m_szLastFieldUnserialized;
        value = Col(field).GetStringValue() + _T("\n") + s;
        Col(field).SetValue( value );
    }
    else
    {
        field = s.SubString( 0, pos-1 );
        value = s.SubString( pos+1, s.Len()-1 );
        Col(field).SetValue( value );
    }
    
    m_szLastFieldUnserialized = field;
    return true;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Class dbResultSet
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// 
dbResultSet::dbResultSet() : 
m_RowDummy(), m_FieldDummy()
{
}

///////////////////////////////////////////////////////////////////////////////
// 
dbResultSet::~dbResultSet()
{
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbResultSet::Clear()
{
    m_ResultSet.clear();
}

///////////////////////////////////////////////////////////////////////////////
// 
void dbResultSet::Add( const dbRow& row )
{
    m_ResultSet.push_back( row );
}

///////////////////////////////////////////////////////////////////////////////
// 
dbRow& dbResultSet::Row( unsigned int row ) 
{
    if ( row < m_ResultSet.size() )
    {
        return m_ResultSet[row];
    }

    return m_RowDummy;
}

///////////////////////////////////////////////////////////////////////////////
// 
const dbRow& dbResultSet::Row( unsigned int row ) const
{
    if ( row < m_ResultSet.size() )
    {
        return m_ResultSet[row];
    }

    return m_RowDummy;
}

///////////////////////////////////////////////////////////////////////////////
// 
dbField& dbResultSet::operator[]( const wxString& name ) 
{
    if ( m_ResultSet.empty() )
    {
        return m_FieldDummy;
    }

    return m_ResultSet[0][name];
}

///////////////////////////////////////////////////////////////////////////////
// 
const dbField& dbResultSet::operator[]( const wxString& name ) const
{
	if ( m_ResultSet.empty() )
	{
		return m_FieldDummy;
	}

	return m_ResultSet[0][name];
}

///////////////////////////////////////////////////////////////////////////////
// 
size_t dbResultSet::GetSize() const
{
    return m_ResultSet.size();
}

