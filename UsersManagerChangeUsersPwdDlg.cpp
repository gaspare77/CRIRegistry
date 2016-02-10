#include "UsersManagerChangeUsersPwdDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
UsersManagerChangeUsersPwdDlg::UsersManagerChangeUsersPwdDlg( wxWindow* parent ) :
ChangeUsersPwdDlg( parent )
{
   SetIcon( wxICON(UsersIcon) );

   m_szPwd = wxEmptyString;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void UsersManagerChangeUsersPwdDlg::OnOk( wxCommandEvent& event )
{
	if ( UsersManager::Instance()->GetUserLogged().GetPwd() != my_md5(m_Password->GetValue()) )
	{
		ERROR_MESSAGE(_("La vecchia password non e' corretta"));
		m_Password->SetFocus();
		return;
	}

	if ( m_NuovaPassword->GetValue() != m_ConfermaPassword->GetValue() )
	{
		ERROR_MESSAGE(_("La password di conferma non e' corretta"));
		m_ConfermaPassword->SetFocus();
		return;
	}

	if ( m_NuovaPassword->GetValue().IsEmpty() && QUESTION_MESSAGE(_("La password dell'utente verra' cancellata.\nVuoi Continuare?")) != wxYES )
	{		
		m_NuovaPassword->SetFocus();
		return;
	}

	m_szPwd = m_NuovaPassword->GetValue();

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void UsersManagerChangeUsersPwdDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}
