#include "CRIRegistryCAPDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCAPDlg::CRIRegistryCAPDlg( wxWindow* parent, const wxString& cap, const wxString& comune, const wxString& provincia ):
CAPDlg( parent ), m_Cap(cap), m_Comune(comune), m_Provincia(provincia)
{
    SetIcon( wxICON(EditIcon) ); 
    m_txtCAP->SetValue( m_Cap );
    m_txtComune->SetValue( m_Comune );
    m_txtProvincia->SetValue( m_Provincia );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPDlg::OnExitCtrl( wxFocusEvent& event )
{
    switch( event.GetId() )
    {
    case ID_CAP:
        ::ValidateTextCtrlFormatNumber(m_txtCAP, _T("%05d"));
        break;
        
    case ID_COMUNE:
        m_txtComune->SetValue( m_txtComune->GetValue().MakeUpper() );
        break;

    case ID_PROVINCIA:
        m_txtProvincia->SetValue( m_txtProvincia->GetValue().MakeUpper() );
        break;
    }
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPDlg::OnOk( wxCommandEvent& event )
{
    if ( m_txtCAP->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il CAP") );
        m_txtCAP->SetFocus();
        return;
    }

    if ( m_txtComune->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il Comune") );
        m_txtComune->SetFocus();
        return;
    }

    if ( m_txtProvincia->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stata inserita la provincia") );
        m_txtProvincia->SetFocus();
        return;
    }

    m_Cap = m_txtCAP->GetValue();
    m_Comune = m_txtComune->GetValue();
    m_Provincia = m_txtProvincia->GetValue();

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}
