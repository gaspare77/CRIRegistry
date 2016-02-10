#include "UsersManagerLogInDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
UsersManagerLogInDlg::UsersManagerLogInDlg( wxWindow* parent, const wxString& user ) :
LogInDlg( parent )
{
	SetIcon( wxICON(UsersIcon) );

	m_Utente->SetValue( user );
	if ( user.IsEmpty() )
	{
		m_Utente->SetFocus();
	}
	else
	{
		m_Password->SetFocus();
	}

	m_szUser = wxEmptyString;
	m_szPwd = wxEmptyString;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void UsersManagerLogInDlg::OnOk( wxCommandEvent& event )
{
	m_szUser = m_Utente->GetValue().Lower();
	m_szPwd = m_Password->GetValue();
    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void UsersManagerLogInDlg::OnCancel( wxCommandEvent& event )
{
	EndModal( wxID_CANCEL );
}
