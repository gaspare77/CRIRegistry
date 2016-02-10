#include "CRIRegistryMailAddressDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryMailAddressDlg::CRIRegistryMailAddressDlg( wxWindow* parent, const wxString& name, const wxString& email ):
MailAddressDlg( parent ), m_Name( name ), m_EMail( email )
{
    SetIcon( wxICON(AddressBookIcon) );
    m_Nome->SetValue( m_Name );
    m_eMail->SetValue( m_EMail );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryMailAddressDlg::~CRIRegistryMailAddressDlg()
{
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryMailAddressDlg::OnExitCtrl( wxFocusEvent& event )
{
    switch( event.GetId() )
    {
    case ID_NOME:
        m_Nome->SetValue( m_Nome->GetValue().MakeUpper() );
        break;
        
    case ID_EMAIL:
        m_eMail->SetValue( m_eMail->GetValue().MakeLower() );
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryMailAddressDlg::OnOk( wxCommandEvent& event )
{
    if ( m_Nome->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il nome") );
        m_Nome->SetFocus();
        return;
    }

    if ( m_eMail->GetValue().IsEmpty() ) //<gfr> add check mail address
    {
        WARNING_MESSAGE( _("Non e' stato inserito l'indirizzo email") );
        m_eMail->SetFocus();
        return;
    }

    m_Name = m_Nome->GetValue();
    m_EMail = m_eMail->GetValue();

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryMailAddressDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}
