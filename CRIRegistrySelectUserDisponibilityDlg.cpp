/////////////////////////////////////////////////////////////////////////////
// 
// 
#include "CRIRegistrySelectUserDisponibilityDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistrySelectUserDisponibilityDlg::CRIRegistrySelectUserDisponibilityDlg( wxWindow* parent ):
SelectUserDisponibilityDlg( parent )
{
    SetIcon( wxICON(SearchIcon) );

    m_Group->Append( _("") );
    m_Group->Append( _("GRUGLIASCO") );
    m_Group->Append( _("RIVOLI") );

    m_Qualification->Append( _("") );
    m_Qualification->Append( _("AUTISTA") );
    m_Qualification->Append( _("BARELLIERE") );
    m_Qualification->Append( _("CENTRALINO") );

    m_Qualification_Type->Append( _("") );
    m_Qualification_Type->Append( _("BASE") );
    m_Qualification_Type->Append( _("INDIA") );

    m_Qualification_Status->Append( _("") );
    m_Qualification_Status->Append( _("EFFETTIVO") );
    m_Qualification_Status->Append( _("T.P.P.") );

    m_Date->Enable( m_checkBox_Date->GetValue() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySelectUserDisponibilityDlg::OnCheckDate( wxCommandEvent& event )
{
    m_Date->Enable( event.IsChecked() );
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySelectUserDisponibilityDlg::OnExitCtrl( wxFocusEvent& event )
{
    switch ( event.GetId() )
    {
    case ID_NAME:
        m_Name->SetValue( m_Name->GetValue().Upper() );
        if ( m_Name->GetValue().IsEmpty() )
        {
            m_Group->Enable( true );
            m_Qualification->Enable( true );
            m_Qualification_Type->Enable( true );
            m_Qualification_Status->Enable( true );
            m_checkBox_Date->Enable( true );
        }
        else
        {
            m_Group->Enable( false );
            m_Group->SetSelection( 0 );
            m_Qualification->Enable( false );
            m_Qualification->SetSelection( 0 );
            m_Qualification_Type->Enable( false );
            m_Qualification_Type->SetSelection( 0 );
            m_Qualification_Status->Enable( false );
            m_Qualification_Status->SetSelection( 0 );
            m_checkBox_Date->Enable( false );
            m_checkBox_Date->SetValue( false );
        }
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySelectUserDisponibilityDlg::OnOk( wxCommandEvent& event )
{
    m_szUrl  = _T("http://gfr.altervista.org/cri/get_users_available.php");
    
    bool bFirst = false;

    if (  !m_Name->GetValue().IsEmpty() )
    {
        m_szUrl +=  wxString::Format( _T("%sname=%s"), bFirst ? _T("&") : _T("?"), m_Name->GetValue().c_str() );
        bFirst = true;
    }

    if (  m_checkBox_Date->GetValue() )
    {
        m_szUrl +=  wxString::Format( _T("%sdate=%s"), bFirst ? _T("&") : _T("?"), m_Date->GetValue().Format( _T("%d-%m-%Y") ).c_str() );
        bFirst = true;
    }
    
    if ( m_Group->GetSelection() > 0 )
    {
        m_szUrl +=  wxString::Format( _T("%sgroup=%s"), bFirst ? _T("&") : _T("?"), m_Group->GetStringSelection().c_str() );
        bFirst = true;
    }

    if ( m_Qualification->GetSelection() > 0 )
    {
        m_szUrl +=  wxString::Format( _T("%squalification=%s"), bFirst ? _T("&") : _T("?"), m_Qualification->GetStringSelection().c_str() );
        bFirst = true;
    }

    if ( m_Qualification_Type->GetSelection() > 0 )
    {
        m_szUrl +=  wxString::Format( _T("%squalification_type=%s"), bFirst ? _T("&") : _T("?"), m_Qualification_Type->GetStringSelection().c_str() );
        bFirst = true;
    }

    if ( m_Qualification_Status->GetSelection() > 0 )
    {
        m_szUrl +=  wxString::Format( _T("%squalification_status=%s"), bFirst ? _T("&") : _T("?"), m_Qualification_Status->GetStringSelection().c_str() );
        bFirst = true;
    }

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySelectUserDisponibilityDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}
