#include "UsersManagerSetUsersPwdDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
UsersManagerSetUsersPwdDlg::UsersManagerSetUsersPwdDlg( wxWindow* parent ):
SetUsersPwdDlg( parent )
{
   SetIcon( wxICON(UsersIcon) );

   m_szPwd = wxEmptyString;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void UsersManagerSetUsersPwdDlg::OnOk( wxCommandEvent& event )
{
	if ( m_NuovaPassword->GetValue().IsEmpty() )
	{
		ERROR_MESSAGE(_("Nessuna password definita"));
		m_NuovaPassword->SetFocus();
		return;
	}

	if ( m_NuovaPassword->GetValue() != m_ConfermaPassword->GetValue() )
	{
		ERROR_MESSAGE(_("La password di conferma non e' corretta"));
		m_ConfermaPassword->SetFocus();
		return;
	}

	m_szPwd = m_NuovaPassword->GetValue();

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void UsersManagerSetUsersPwdDlg::OnCancel( wxCommandEvent& event )
{
	EndModal( wxID_CANCEL );
}
