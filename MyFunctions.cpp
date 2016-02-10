/***************************************************************
 * Name:      MyFunctions.cpp
 * Purpose:   My functions code
 * Author:    Gaspare Faraci (g.faraci@fidia.it)
 * Created:   2008-05-19
 * Copyright: Gaspare Faraci ()
 * License:
 **************************************************************/

#include "MyFunctions.h"


//==============================================================================================
// Class cAge
//==============================================================================================
cAge::cAge()
{
    Init();
}

cAge::~cAge()
{
}

bool cAge::Compute( const wxDateTime& dt )
{
    Init();

    if ( dt == EmptyDate )
	{
		return false;
	}
	
	wxDateTime dtNow = wxDateTime::Now();
	wxDateSpan dtBd;
	dtBd.SetDays( dt.GetDay() );
	dtBd.SetMonths( dt.GetMonth() );
	dtBd.SetYears( dt.GetYear() );

	if ( dt.IsLaterThan( dtNow ) )
	{
		return false;
	}

	wxDateTime dtDiff = dtNow - dtBd;
	int iYear = dtDiff.GetYear();
	int iMonth = dtDiff.GetMonth();
	int iDay = dtDiff.GetDay();

	if ( iYear > 0 )
    {
		m_szAge = wxString::Format( _T("%d"), iYear );
        m_eType = Years;
    }
	else if ( iMonth > 0 )
    {
		m_szAge = wxString::Format( _T("%d"), iMonth+1 );
        m_eType = Months;
    }
    else
    {
		m_szAge = wxString::Format( _T("%d"), iDay+1 );
        m_eType = Days;
    }

    return true;
}

wxString cAge::Get() 
{ 
    return m_szAge; 
}

cAge::eAgeType cAge::GetType() 
{ 
    return m_eType; 
}

wxString cAge::GetType( eAgeType type )
{
    wxString s(wxEmptyString);
    switch ( type )
    {
    case Years:
        s = _T("aa");
        break;

    case Months:
        s = _T("mm");
        break;

    case Days:
        s = _T("gg");
        break;
    }

    return s;
}

void cAge::Init()
{ 
    m_szAge = wxEmptyString; 
    m_eType = Undefined; 
}


//==============================================================================================
//  Show the Error Message
//==============================================================================================
void ERROR_MESSAGE( const char* format, ... )
{
	char formattedMessage[2048];
	va_list va_cursor;

	va_start( va_cursor, format);
	vsprintf( formattedMessage, format, va_cursor );
	va_end( va_cursor );

	wxMessageBox( formattedMessage, _("Error"), wxICON_ERROR );
}

//==============================================================================================
//  Show the Warning Message
//==============================================================================================
void WARNING_MESSAGE( const char* format, ... )
{
    char formattedMessage[2048];
    va_list va_cursor;

    va_start( va_cursor, format );
    vsprintf( formattedMessage, format, va_cursor );
    va_end( va_cursor );

    wxMessageBox( formattedMessage, _("Warning"), wxICON_WARNING );
}

//==============================================================================================
//  Show the Info Message
//==============================================================================================
void INFO_MESSAGE( const char* format, ... )
{
    char formattedMessage[2048];
    va_list va_cursor;

    va_start( va_cursor, format );
    vsprintf( formattedMessage, format, va_cursor );
    va_end( va_cursor );

    wxMessageBox( formattedMessage, _("Info"), wxICON_INFORMATION );
}

//==============================================================================================
//  Show the Question Message
//==============================================================================================
int QUESTION_MESSAGE( const char* format, ... )
{
    char formattedMessage[2048];
    va_list va_cursor;

    va_start( va_cursor, format );
    vsprintf( formattedMessage, format, va_cursor );
    va_end( va_cursor );

    return wxMessageBox( formattedMessage, _("Confirm"), wxYES_NO | wxICON_QUESTION | wxNO_DEFAULT );
}

//==============================================================================================
//  Convert into SQL String, used for parse the special characts
//==============================================================================================
wxString SQLStringFormat( const wxString& s )
{
    wxString _s(s);

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

    return _s;
}

//==============================================================================================
//
//==============================================================================================
wxString SQLQueryFormat( const wxString& s )
{
    wxString _s(s);

    for ( unsigned int i = 0; i < _s.Len(); i++ )
    {
        switch ( (int)_s[i] )
        {
            case 37:
                _s.insert(++i, "%");
                break;

            default:
                break;
        }
    }

    return _s;
}

//==============================================================================================
//
//==============================================================================================
bool FormatTime( wxString& s )
{
    if ( s.IsEmpty() )
    {
        return true;
    }

    wxStringTokenizer tkz( s, _T(".:") );
    wxString hours = tkz.GetNextToken();
    wxString minutes = tkz.GetNextToken();

    if ( !hours.IsNumber() || !minutes.IsNumber() )
    {
        return false;
    }

    int h = atoi ( hours.c_str() );
    int m = atoi ( minutes.c_str() );
    if ( h < 0 || h > 23 || m < 0 || m > 59 )
    {
        return false;
    }

    s.Printf( _T("%02d:%02d"), h, m );
    return true;
}

//==============================================================================================
//
//==============================================================================================
bool FormatDate( wxString& s )
{
    if ( s.IsEmpty() )
    {
        return true;
    }

    wxStringTokenizer tkz( s, _T("-/.") );
    wxString day = tkz.GetNextToken();
    wxString month = tkz.GetNextToken();
    wxString year = tkz.GetNextToken();

    if ( !day.IsNumber() || !month.IsNumber() || !year.IsNumber() )
    {
        return false;
    }

    int d = atoi ( day.c_str() );
    int m = atoi ( month.c_str() );
    int y = atoi ( year.c_str() );
    if ( d < 1 || m < 1 || m > 12 || y < 1900 )
    {
        return false;
    }

	wxDateTime dt;
	if ( d > dt.GetLastMonthDay((wxDateTime::Month)(m-1), y ).GetDay() )
	{
		return false;
	}

    s.Printf( _T("%02d/%02d/%d"), d, m, y );
    return true;
}

//==============================================================================================
//
//==============================================================================================
bool GetHourMin( const wxString& s, int* h, int* m )
{
    wxStringTokenizer tkz( s, _T(":") );
    if ( tkz.CountTokens() != 2 )
    {
        *h = 0;
        *m = 0;
        return false;
    }

    *h = atoi( tkz.GetNextToken().c_str() );
    *m = atoi( tkz.GetNextToken().c_str() );
    return true;
}

//==============================================================================================
//
//==============================================================================================
int GetHourDiff( const wxString& a, const wxString& b )
{
    wxStringTokenizer tkz;
    wxString hours;

    tkz.SetString( a, _T(".:") );
    hours = tkz.GetNextToken();
    int start = atoi ( hours.c_str() );

    tkz.SetString( b, _T(".:") );
    hours = tkz.GetNextToken();
    int end = atoi ( hours.c_str() );

    return end - start;
}

//==============================================================================================
//
//==============================================================================================
wxDateTime StrToDateTime( const wxString& value )
{
    wxDateTime d = EmptyDate;
    int year, month, day, hours, minutes;

    wxStringTokenizer tkz( value, _T("-: "));
    if ( tkz.HasMoreTokens() )
    {
        year = atoi( tkz.GetNextToken().c_str() );
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the year in StrToDateTime()") );
        return d;
    }

    if ( tkz.HasMoreTokens() )
    {
        month = atoi( tkz.GetNextToken().c_str() ) - 1;
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the month in StrToDateTime()") );
        return d;
    }

    if ( tkz.HasMoreTokens() )
    {
        day = atoi( tkz.GetNextToken().c_str() );
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the day in StrToDateTime()") );
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

//==============================================================================================
//
//==============================================================================================
wxDateTime StrToDate( const wxString& value )
{
    wxDateTime d = EmptyDate;
    int year, month, day;

    if ( value.IsEmpty() )
	{
		return d;
	}
	
	wxStringTokenizer tkz( value, _T("/"));
    if ( tkz.HasMoreTokens() )
    {
        day = atoi( tkz.GetNextToken().c_str() );
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the day in StrToDate()") );
        return d;
    }

    if ( tkz.HasMoreTokens() )
    {
        month = atoi( tkz.GetNextToken().c_str() ) - 1;
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the month in StrToDate()") );
        return d;
    }

    if ( tkz.HasMoreTokens() )
    {
        year = atoi( tkz.GetNextToken().c_str() );
    }
    else
    {
        ERROR_MESSAGE( _("No more token for get the year in StrToDate()") );
        return d;
    }

	d.Set( day, (wxDateTime::Month)month, year, 0, 0 );

    return d;
}

//==============================================================================================
//
//==============================================================================================
wxDateTime ConcatDateTime( const wxDateTime& date, const wxString& time )
{
	wxDateTime dt = EmptyDate;
	int h, m;

	if ( GetHourMin( time, &h, &m ) )
	{
		dt = date;
		dt.SetHour( h ).SetMinute( m );
	}

	return dt;
}

//==============================================================================================
//
//==============================================================================================
void ComboBoxChangeWithSearch( wxComboBox* cb )
{
	wxString s = cb->GetValue();
    for ( unsigned int i = 0; i <= cb->GetCount(); i++ )
    {
        wxString a = cb->GetString(i);
        if ( a.Upper().StartsWith(s.Upper().c_str()) )
        {
            cb->Select(i);
            cb->SetSelection( s.Len(), a.Len() );            
            return;
        }
    }
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlFormatTime( wxTextCtrl* txt )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() )
    {
		wxString s = txt->GetValue();
		if ( FormatTime( s ) )
		{
			txt->SetValue( s );
		}
		else
		{
			txt->SetBackgroundColour( wxColor(255,0,0) );
			txt->SetSelection( 0, txt->GetValue().Len() );
			txt->SetFocus();
			return false;
		}
	}

	return true;
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlFormatDate( wxTextCtrl* txt )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() )
    {
		wxString s = txt->GetValue();
		if ( FormatDate( s ) )
		{
			txt->SetValue( s );
		}
		else
		{
			txt->SetBackgroundColour( wxColor(255,0,0) );
			txt->SetSelection( 0, txt->GetValue().Len() );
			txt->SetFocus();
			return false;
		}
	}

	return true;
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlFormatNumber( wxTextCtrl* txt, const wxString& format )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() )
    {
		wxString s = txt->GetValue();
		long l; 
		if ( s.ToLong( &l ) )
		{
			txt->SetValue( wxString::Format( format, l ) );
		}
		else
		{
			txt->SetFocus();
			txt->SetSelection( 0, txt->GetValue().Len() );
			txt->SetBackgroundColour( wxColor(255,0,0) );
			return false;
		}
	}

	return true;
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlFormatLetterCod( wxTextCtrl* txt, const wxArrayString& codlist )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() )
    {
		wxString s = txt->GetValue().MakeUpper();
		for ( size_t i = 0; i < codlist.GetCount(); i++ )
		{
			if ( s == codlist[i] )
			{
				txt->SetValue( s );
				return true;
			}
		}
		txt->SetFocus();
		txt->SetSelection( 0, txt->GetValue().Len() );
		txt->SetBackgroundColour( wxColor(255,0,0) );
		return false;
	}

	return true;
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlFormatNumberCod( wxTextCtrl* txt, const wxString& format, const wxArrayString& codlist )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() )
    {
		wxString s = txt->GetValue();
		wxStringTokenizer tkz( s, _T(".") );
		wxString s1 = tkz.GetNextToken();
		wxString s2 = tkz.GetNextToken();
		long l1,l2; 
		if ( s1.ToLong( &l1 ) && ( s2.IsEmpty() || s2.ToLong( &l2 ) ) )
		{
			if ( s2.IsEmpty() )
				s = wxString::Format( format, l1 );
			else
				s = wxString::Format( format, l1 ) + _T(".") + wxString::Format( _T("%d"), l2 );
				
			for ( size_t i = 0; i < codlist.GetCount(); i++ )
			{
				if ( s == codlist[i] )
				{
					txt->SetValue( s );
					return true;
				}
			}
		}
		txt->SetFocus();
		txt->SetSelection( 0, txt->GetValue().Len() );
		txt->SetBackgroundColour( wxColor(255,0,0) );
		return false;
	}

	return true;
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlFormatCurrency( wxTextCtrl* txt )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() )
    {
		wxString s = txt->GetValue();
		s.Replace( _T("."), _T(",") );
		double f; 
		if ( s.ToDouble( &f ) )
		{
			txt->SetValue( wxString::Format("%.2f", f ) );
		}
		else
		{
			txt->SetFocus();
			txt->SetSelection( 0, txt->GetValue().Len() );
			txt->SetBackgroundColour( wxColor(255,0,0) );
			return false;
		}
	}

	return true;
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlFormatPlate( wxTextCtrl* txt )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() )
    {
        wxString plate = txt->GetValue().Upper();

        if ( plate.Len() < 4 || plate[0] != _T('C') || plate[1] != _T('R') || plate[2] != _T('I') )
        {
			txt->SetFocus();
			txt->SetSelection( 0, txt->GetValue().Len() );
			txt->SetBackgroundColour( wxColor(255,0,0) );
			return false;
		}
		else
		{
			txt->SetValue( plate );
		}
    }

	return true;
}

//==============================================================================================
//
//==============================================================================================
bool ValidateTextCtrlSpecialFormat( wxTextCtrl* txt, const wxString& format )
{
	txt->SetBackgroundColour( *wxWHITE );

	if ( txt && !txt->GetValue().IsEmpty() && !format.IsEmpty() )
    {
        wxString s = txt->GetValue().Upper();
        if ( !s.Matches( format ) )
        {
			txt->SetFocus();
			txt->SetSelection( 0, txt->GetValue().Len() );
			txt->SetBackgroundColour( wxColor(255,0,0) );
			return false;
		}
		else
		{
			txt->SetValue( s );
		}
    }

	return true;
}

//==============================================================================================
//
//==============================================================================================
wxString GetAge( const wxDateTime& dt )
{
    cAge age;
    wxString s(wxEmptyString);

    if ( age.Compute( dt ) )
    {
        switch ( age.GetType() )
        {
        case cAge::Years:
            s = wxString::Format( _T("%d aa"), age.Get() );
            break;

        case cAge::Months:
            s = wxString::Format( _T("%d mm"), age.Get() );
            break;

        case cAge::Days:
            s = wxString::Format( _T("%d dd"), age.Get() );
            break;
        }
    }
    
    return s;
}
