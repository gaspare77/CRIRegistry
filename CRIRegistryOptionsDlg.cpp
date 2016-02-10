#include "CRIRegistryOptionsDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistryOptionsDlg::CRIRegistryOptionsDlg( wxWindow* parent ):
OptionsDlg( parent )
{
    SetIcon( wxICON(OptionsIcon) );
    
	wxString query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_GRUPPO, TABLE_GRUPPI );
	wxArrayString aszGruppi = dbSingleton::Instance()->SQLGetColArray( query );

    m_Gruppo->Append( _T("") );
    m_Gruppo->Append( aszGruppi );

    m_Gruppo->SetStringSelection( CRIRegistryOptions::Instance()->GetDefaultGruppo() );
    m_IncNumServizi->SetValue( CRIRegistryOptions::Instance()->IncrementNumServ() );
    m_IncNumServiziSup->SetValue( CRIRegistryOptions::Instance()->IncrementNumServSup() );
	m_AutoLogOutTime->SetValue( CRIRegistryOptions::Instance()->GetAutoLogOutTime() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryOptionsDlg::OnOk( wxCommandEvent& event )
{
    bool bSettingsChanged = ( m_Gruppo->GetStringSelection() != CRIRegistryOptions::Instance()->GetDefaultGruppo() ) ||
                            (  m_IncNumServizi->GetValue() != CRIRegistryOptions::Instance()->IncrementNumServ() ) ||
                            (  m_IncNumServiziSup->GetValue() != CRIRegistryOptions::Instance()->IncrementNumServSup() ) ||
                            (  m_AutoLogOutTime->GetValue() != CRIRegistryOptions::Instance()->GetAutoLogOutTime() );

    if ( bSettingsChanged && ( QUESTION_MESSAGE( _("Salvare le modifiche apportate?") ) == wxYES ) )
    {
        CRIRegistryOptions::Instance()->SetDefaultGruppo( m_Gruppo->GetStringSelection() );
        CRIRegistryOptions::Instance()->SetIncrementNumServ( m_IncNumServizi->GetValue() );
        CRIRegistryOptions::Instance()->SetIncrementNumServSup( m_IncNumServiziSup->GetValue() );
		CRIRegistryOptions::Instance()->SetAutoLogOutTime( m_AutoLogOutTime->GetValue() );
    }

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryOptionsDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}
