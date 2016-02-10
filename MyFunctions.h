/***************************************************************
 * Name:      MyFunctions.h
 * Purpose:   My functions definition
 * Author:    Gaspare Faraci (g.faraci@fidia.it)
 * Created:   2008-05-19
 * Copyright: Gaspare Faraci ()
 * License:
 **************************************************************/

#ifndef __MYFUNCTIONS_H__
#define __MYFUNCTIONS_H__

#include <wx/wx.h>
#include <wx/tokenzr.h>

//==============================================================================================
//
//==============================================================================================
template<class T> 
class VariableRestorer
{
public:
    VariableRestorer( T* pT )
    { 
        m_pT = pT; 
        m_oldTValue = *pT; 
    }

    ~VariableRestorer()
    { 
        *m_pT = m_oldTValue; 
    }

private:
    T* m_pT;
    T  m_oldTValue;
};

//==============================================================================================
//
//==============================================================================================
class cAge
{
public:
    cAge();
    ~cAge();

    enum eAgeType
    {
        Undefined,
        Years,
        Months,
        Days
    };

    bool Compute( const wxDateTime& dt );
    wxString Get();
    eAgeType GetType(); 

    static wxString GetType( eAgeType type );

private:
    wxString    m_szAge;
    eAgeType    m_eType;

    void Init();
};

//==============================================================================================
// Macro definitions                    	
//==============================================================================================
#define CHAR_LIST_SIZE(x)					(sizeof(x)/sizeof(const char*))
#define ENUM_SIZE(x,y)						(sizeof(x)/sizeof(y))
#define INT_TO_STR(x)						(wxString::Format( _("%d"), x))
#define STR_TO_INT(x)						(atoi(x.c_str()))
#define GET_PERC(x,y)						(((float)x*(float)y)/100.)
#define FORMAT_TIME                        _T("%H:%M")
#define FORMAT_DATE                        _T("%d/%m/%Y")
#define FORMAT_DATE_TIME                   _T("%d/%m/%Y %H:%M")
#define FORMAT_DATE_EXTENDED               _T("%A %d %B %Y")
#define FORMAT_DATE_TIME_EXTENDED          _T("%A %d %B %Y %H:%M")

//==============================================================================================
//
//==============================================================================================
static const wxDateTime EmptyDate( 21, wxDateTime::Jul, 1977, 15, 59 );

//==============================================================================================
//
//==============================================================================================
void ERROR_MESSAGE( const char* format, ... );
void WARNING_MESSAGE( const char* format, ... );
void INFO_MESSAGE( const char* format, ... );
int  QUESTION_MESSAGE( const char* format, ... );
wxString SQLStringFormat( const wxString& s );
wxString SQLQueryFormat( const wxString& s );
bool FormatTime( wxString& s );
bool FormatDate( wxString& s );
bool GetHourMin( const wxString& s, int* h, int* m );
int GetHourDiff( const wxString& a, const wxString& b );
wxDateTime StrToDateTime( const wxString& value );
wxDateTime StrToDate( const wxString& value );
wxDateTime ConcatDateTime( const wxDateTime& date, const wxString& time );
void ComboBoxChangeWithSearch( wxComboBox* cb );
bool ValidateTextCtrlFormatTime( wxTextCtrl* txt );
bool ValidateTextCtrlFormatDate( wxTextCtrl* txt );
bool ValidateTextCtrlFormatNumber( wxTextCtrl* txt, const wxString& format = _T("%d") );
bool ValidateTextCtrlFormatCurrency( wxTextCtrl* txt );
bool ValidateTextCtrlFormatPlate( wxTextCtrl* txt );
bool ValidateTextCtrlFormatLetterCod( wxTextCtrl* txt, const wxArrayString& codlist );
bool ValidateTextCtrlFormatNumberCod( wxTextCtrl* txt, const wxString& format, const wxArrayString& codlist );
bool ValidateTextCtrlSpecialFormat( wxTextCtrl* txt, const wxString& format );
wxString GetAge( const wxDateTime& dt );

#endif // MYFUNCTIONS_H_INCLUDED
