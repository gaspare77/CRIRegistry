#include "TxtCtrl118Code.h"

/////////////////////////////////////////////////////////////////////////////
// Event Table 
// 
BEGIN_EVENT_TABLE( TxtCtrl118Code, wxTextCtrl )
    EVT_KEY_UP( TxtCtrl118Code::OnKeyUp )
    EVT_KILL_FOCUS( TxtCtrl118Code::OnExitCtrl )
END_EVENT_TABLE()

/////////////////////////////////////////////////////////////////////////////
//
//
TxtCtrl118Code::TxtCtrl118Code() : wxTextCtrl()
{ 
    m_Type = TYPE_CODE_UNKNOW;
    m_CodeList.Clear();
}

/////////////////////////////////////////////////////////////////////////////
//
//
TxtCtrl118Code::TxtCtrl118Code(wxWindow *parent, 
    wxWindowID id,
    const wxString& value,
    const wxPoint& pos, 
    const wxSize& size,
    long style,
    const wxValidator& validator,
    const wxString& name) : wxTextCtrl(parent, id, value, pos, size, style, validator, name)
{
    m_Type = TYPE_CODE_UNKNOW;
    m_CodeList.Clear();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void TxtCtrl118Code::SetProperty( e118CodeType type, const wxArrayString& list )
{
    m_Type = type;
    m_CodeList = list;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void TxtCtrl118Code::OnExitCtrl( wxFocusEvent& event )
{
    switch ( m_Type )
    {
    case TYPE_CODE_GRAVITY:
        ::ValidateTextCtrlFormatLetterCod( this, m_CodeList );
        break;
	case TYPE_CODE_EVENT:
		::ValidateTextCtrlFormatNumberCod( this, _T("%02d"), m_CodeList );
        break;
	case TYPE_CODE_ARRIVAL:
		::ValidateTextCtrlFormatNumberCod( this, _T("%02d"), m_CodeList );
        break;
	case TYPE_CODE_DEPARTURE:
		::ValidateTextCtrlFormatNumberCod( this, _T("%03d"), m_CodeList );
        break;
	case TYPE_CODE_RELEASE:
		::ValidateTextCtrlFormatNumberCod( this, _T("%03d"), m_CodeList );
        break;
	case TYPE_CODE_PLACE:
		::ValidateTextCtrlFormatLetterCod( this, m_CodeList );
        break;
	case TYPE_CODE_DINAMIC:
		::ValidateTextCtrlFormatNumberCod( this, _T("%02d"), m_CodeList );
        break;
	case TYPE_CODE_TREATMENT:
		::ValidateTextCtrlFormatNumberCod( this, _T("%02d"), m_CodeList );
        break;
    }

    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void TxtCtrl118Code::OnKeyUp( wxKeyEvent& event )
{
    if ( m_Type != TYPE_CODE_UNKNOW && event.GetKeyCode() == WXK_F1 )
    {
        CRIRegistryCodeSelectionDlg dlg( this, m_Type, GetValue() );
        if ( dlg.ShowModal() == wxID_OK )
        {
            SetValue( dlg.GetCode() );
            return;
        }
    }

    event.Skip();
}


