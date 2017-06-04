#include "UsersManagerDlg.h"

/////////////////////////////////////////////////////////////////////////////
//
// 
UsersManagerDlg::UsersManagerDlg( wxWindow* parent ):
UsersDlg( parent ), m_bUserAdded( false ), m_bWaitConfirm( false ), m_DummyPwd( _T("abcdf") )
{
	SetIcon( wxICON(UsersIcon) );

    // Lock the Table
    UsersManager::Instance()->LockTable( TABLE_USERS );
	
	m_Privilegi->Append( wxArrayString( CHAR_LIST_SIZE(szUserPrivilege)-1, szUserPrivilege ) );

	UpdateUsersList();
	ClearData();
	EnableCtrl( false );
    m_bpButton_Ok->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
// 
UsersManagerDlg::~UsersManagerDlg()
{
    // Unlock the Table
    UsersManager::Instance()->UnlockTable( TABLE_USERS );
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::UpdateUsersList()
{
	wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE %s <> \'%s\' ORDER BY %s,%s"), FIELD_USER, TABLE_USERS, FIELD_USER, szUserPrivilege[ADMINISTRATOR], FIELD_COGNOME, FIELD_NOME );
	m_listBox_Utenti->Clear();
	m_listBox_Utenti->Append( dbSingleton::Instance()->SQLGetColArray( query ) );
	ClearData();
}

/////////////////////////////////////////////////////////////////////////////
//
// 
bool UsersManagerDlg::UpdateUserData()
{
	if ( m_listBox_Utenti->GetSelection() < 0 )
	{
		return false;
	}

	if ( !m_CurrentUser.LoadFromDb( m_listBox_Utenti->GetStringSelection() ) )
	{
		return false;
	}

	m_Utente->SetValue( m_CurrentUser.GetName() );
	m_Nome->SetValue( m_CurrentUser.GetNome() );
	m_Cognome->SetValue( m_CurrentUser.GetCognome() );
	m_Password->SetValue( m_DummyPwd );
	m_ConfermaPassword->SetValue( m_DummyPwd );
	m_Privilegi->SetSelection( m_CurrentUser.GetPrivileges() );
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::ClearData()
{
	m_Utente->Clear();
	m_Nome->Clear();
	m_Cognome->Clear();
	m_Password->Clear();
	m_ConfermaPassword->Clear();
	m_Privilegi->SetSelection( 0 );
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::EnableCtrl( bool enable )
{
	m_Utente->Enable( enable );
	m_Nome->Enable( enable );
	m_Cognome->Enable( enable );
	m_Password->Enable( enable );
	m_ConfermaPassword->Enable( enable );
	m_Privilegi->Enable( enable );
	m_bpButton_Confirm->Enable( enable );
	m_bpButton_Cancel->Enable( enable );

	m_listBox_Utenti->Enable( !enable );
	m_bpButton_Add->Enable( !enable );
	m_bpButton_Del->Enable( !enable );
	m_bpButton_Modify->Enable( !enable );

	m_bWaitConfirm = enable;
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::OnConfirm( wxCommandEvent& event )
{
	if ( m_Utente->GetValue().IsEmpty() )
	{
		ERROR_MESSAGE( _("Non e' stato inserito il nome utente") );
		m_Utente->SetFocus();
		return;
	}

	if ( m_bUserAdded && m_listBox_Utenti->FindString( m_Utente->GetValue() ) != wxNOT_FOUND )
	{
		WARNING_MESSAGE( _("L'utente %s esiste gia'"), m_Utente->GetValue().c_str() );
		return;
	}

	if ( m_Password->GetValue() != m_ConfermaPassword->GetValue() )
	{
		ERROR_MESSAGE( _("La password di conferma non e' corretta") );
		return;
	}

	if ( m_Nome->GetValue().IsEmpty() )
	{
		ERROR_MESSAGE( _("Non e' stato inserito il nome dell'utente") );
		return;
	}

	if ( m_Cognome->GetValue().IsEmpty() )
	{
		ERROR_MESSAGE( _("Non e' stato inserito il cognome dell'utente") );
		return;
	}

	m_CurrentUser.SetName( m_Utente->GetValue() );
	m_CurrentUser.SetNome( m_Nome->GetValue() );
	m_CurrentUser.SetCognome( m_Cognome->GetValue() );
	if ( m_Password->GetValue() != m_DummyPwd )
	{
		m_CurrentUser.SetPwd( m_Password->GetValue() );
	}
	m_CurrentUser.SetPrivileges( m_Privilegi->GetSelection() );
	
	if ( m_bUserAdded ) 
	{
		m_CurrentUser.SetLastLogIn( EmptyDate );
		if ( m_CurrentUser.InsertIntoDb() )
		{
			INFO_MESSAGE( _("L'utente %s e' stato inserito"), m_CurrentUser.GetName().c_str() );
		}
	}
	else
	{
		if ( m_CurrentUser.UpdateIntoDb() )
		{
			INFO_MESSAGE( _("L'utente %s e' stato cambiato"), m_CurrentUser.GetName().c_str() );
		}
	}

	UpdateUsersList();
	m_listBox_Utenti->SetStringSelection( m_CurrentUser.GetName() );
	UpdateUserData();
	m_bUserAdded = false;
	EnableCtrl( false );
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::OnCancel( wxCommandEvent& event )
{
	m_bUserAdded = false;
	ClearData();
	UpdateUserData();
	EnableCtrl( false );
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_UTENTE:
		m_Utente->SetValue( m_Utente->GetValue().Lower() );
		break;
	case ID_NOME:
		m_Nome->SetValue( m_Nome->GetValue().Upper() );
		break;
	case ID_COGNOME:
		m_Cognome->SetValue( m_Cognome->GetValue().Upper() );
		break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::OnAdd( wxCommandEvent& event )
{
	m_listBox_Utenti->SetSelection( -1 );
	ClearData();
	m_bUserAdded = true;
	EnableCtrl( true );
	m_Utente->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::OnModify( wxCommandEvent& event )
{
	if ( UpdateUserData() )
	{
		EnableCtrl( true );
		m_Utente->SetFocus();
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void UsersManagerDlg::OnSelect( wxCommandEvent& event )
{
	UpdateUserData();
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::OnDel( wxCommandEvent& event )
{
	if ( m_listBox_Utenti->GetSelection() < 0 )
	{
		return;
	}

	if ( !m_CurrentUser.LoadFromDb( m_listBox_Utenti->GetStringSelection() ) )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare l'utente %s?"), m_CurrentUser.GetName().c_str() ) != wxYES )
	{
		return;
	}

	if ( m_CurrentUser.RemoveFromDb() )
	{
		ClearData();
		UpdateUsersList();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void UsersManagerDlg::OnOk( wxCommandEvent& event )
{
	if ( m_bWaitConfirm && QUESTION_MESSAGE( _("Non sono stati confermati i cambiamenti apportati.\nLi vuoi confermare ora?") ) == wxYES )
	{
		OnConfirm( event );
	}
	Close();
}
