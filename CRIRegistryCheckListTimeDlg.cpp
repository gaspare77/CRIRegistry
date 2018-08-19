#include "CRIRegistryCheckListTimeDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCheckListTimeDlg::CRIRegistryCheckListTimeDlg( wxWindow* parent, const wxString& turno, const wxString& inizio, const wxString& fine ):
CheckListTimeDlg( parent )
{
    SetIcon( wxICON(EditIcon) );

    m_Turno->SetValue( turno );
    m_Inizio->SetValue( inizio );
    ::ValidateTextCtrlFormatTime(m_Inizio);
    m_Fine->SetValue( fine );
    ::ValidateTextCtrlFormatTime(m_Fine);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeDlg::OnExitCtrl( wxFocusEvent& event )
{
    switch (event.GetId())
    {
    case ID_TURNO:
        m_Turno->SetValue(m_Turno->GetValue().Upper());
        break;

    case ID_INIZIO:
        ::ValidateTextCtrlFormatTime(m_Inizio);
        break;

    case ID_FINE:
        ::ValidateTextCtrlFormatTime(m_Fine);
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}
