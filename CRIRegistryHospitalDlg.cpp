#include "CRIRegistryHospitalDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistryHospitalDlg::CRIRegistryHospitalDlg( wxWindow* parent ):
HospitalDlg( parent ), m_bHospitalAdded( false ), m_bWaitConfirm( false )
{
    SetIcon( wxICON(AddressBookIcon) );

    // Lock the Table
    UsersManager::Instance()->LockTable( TABLE_OSPEDALI );
	
    UpdateHospitalList();
	ClearData();
	EnableCtrl( false );
    m_bpButton_Ok->SetFocus();
}

CRIRegistryHospitalDlg::~CRIRegistryHospitalDlg()
{
    // Unlock the Table
    UsersManager::Instance()->UnlockTable( TABLE_OSPEDALI );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::UpdateHospitalList()
{
	wxString query = wxString::Format( _T("SELECT %s FROM %s ORDER BY %s"), FIELD_NOME, TABLE_OSPEDALI, FIELD_NOME );
	m_listBox_Ospedali->Clear();
	m_listBox_Ospedali->Append( dbSingleton::Instance()->SQLGetColArray( query ) );
	ClearData();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryHospitalDlg::UpdateHospitalData()
{
	if ( m_listBox_Ospedali->GetSelection() < 0 )
	{
		return false;
	}

	if ( !m_CurrentHospital.LoadFromDb( m_listBox_Ospedali->GetStringSelection() ) )
	{
		return false;
	}

	m_Ospedale->SetValue( m_CurrentHospital.GetNome() );
    m_Societa->SetValue( m_CurrentHospital.GetSocieta() );
    m_Indirizzo->SetValue( m_CurrentHospital.GetIndirizzo() );
	m_Civico->SetValue( m_CurrentHospital.GetCivico() );
	m_CAP->SetValue( m_CurrentHospital.GetCAP() );
    m_Citta->SetValue( m_CurrentHospital.GetCitta() );
    m_Provincia->SetValue( m_CurrentHospital.GetProvincia() );
    m_NumTel->SetValue( m_CurrentHospital.GetNumTel() );
    m_NumFax->SetValue( m_CurrentHospital.GetNumFax() );
    m_Note->SetValue( m_CurrentHospital.GetNote() );
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::ClearData()
{
	m_Ospedale->Clear();
    m_Societa->Clear();
    m_Indirizzo->Clear();
	m_Civico->Clear();
	m_CAP->Clear();
    m_Citta->Clear();
    m_Provincia->Clear();
    m_NumTel->Clear();
    m_NumFax->Clear();
    m_Note->Clear();
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void CRIRegistryHospitalDlg::EnableCtrl( bool enable )
{
	m_Ospedale->Enable( enable );
	m_Societa->Enable( enable );
	m_Indirizzo->Enable( enable );
	m_Civico->Enable( enable );
	m_CAP->Enable( enable );
	m_Citta->Enable( enable );
	m_Provincia->Enable( enable );
	m_NumTel->Enable( enable );
	m_NumFax->Enable( enable );
	m_Note->Enable( enable );
	m_bpButton_Confirm->Enable( enable );
	m_bpButton_Cancel->Enable( enable );

	m_listBox_Ospedali->Enable( !enable );
	m_bpButton_Add->Enable( !enable );
	m_bpButton_Del->Enable( !enable );
	m_bpButton_Modify->Enable( !enable );

	m_bWaitConfirm = enable;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::OnConfirm( wxCommandEvent& event )
{
	if ( m_Ospedale->GetValue().IsEmpty() )
	{
		ERROR_MESSAGE( _("Non e' stato inserito il nome dell'ospedale") );
		m_Ospedale->SetFocus();
		return;
	}

	if ( m_bHospitalAdded && m_listBox_Ospedali->FindString( m_Ospedale->GetValue() ) >= 0 )
	{
		WARNING_MESSAGE( _("L'ospedale %s esiste gia'"), m_Ospedale->GetValue().c_str() );
		m_Ospedale->SetFocus();
		return;
	}

	m_CurrentHospital.SetNome( m_Ospedale->GetValue().Upper() );
	m_CurrentHospital.SetSocieta( m_Societa->GetValue().Upper() );
	m_CurrentHospital.SetIndirizzo( m_Indirizzo->GetValue().Upper() );
	m_CurrentHospital.SetCivico( m_Civico->GetValue().Upper() );
	m_CurrentHospital.SetCAP( m_CAP->GetValue().Upper() );
	m_CurrentHospital.SetCitta( m_Citta->GetValue().Upper() );
	m_CurrentHospital.SetProvincia( m_Provincia->GetValue().Upper() );
	m_CurrentHospital.SetNumTel( m_NumTel->GetValue().Upper() );
	m_CurrentHospital.SetNumFax( m_NumFax->GetValue().Upper() );
	m_CurrentHospital.SetNote( m_Note->GetValue().Upper() );

	if ( m_bHospitalAdded ) 
	{
		if ( m_CurrentHospital.InsertIntoDb() )
		{
			INFO_MESSAGE( _("L'ospedale %s e' stato inserito"), m_CurrentHospital.GetNome().c_str() );
		}
	}
	else
	{
		if ( m_CurrentHospital.UpdateIntoDb() )
		{
			INFO_MESSAGE( _("L'ospedale %s e' stato cambiato"), m_CurrentHospital.GetNome().c_str() );
		}
	}

	UpdateHospitalList();
	m_listBox_Ospedali->SetStringSelection( m_CurrentHospital.GetNome() );
	UpdateHospitalData();
	m_bHospitalAdded = false;
	EnableCtrl( false );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::OnCancel( wxCommandEvent& event )
{
	m_bHospitalAdded = false;
	ClearData();
	UpdateHospitalData();
	EnableCtrl( false );
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void CRIRegistryHospitalDlg::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_OSPEDALE:
		m_Ospedale->SetValue( m_Ospedale->GetValue().Upper() );
		break;
	case ID_SOCIETA:
		m_Societa->SetValue( m_Societa->GetValue().Upper() );
		break;
	case ID_INDIRIZZO:
		m_Indirizzo->SetValue( m_Indirizzo->GetValue().Upper() );
		break;
	case ID_CIVICO:
		m_Civico->SetValue( m_Civico->GetValue().Upper() );
		break;
	case ID_CAP:
		::ValidateTextCtrlFormatNumber( m_CAP );
		break;
	case ID_CITTA:
		m_Citta->SetValue( m_Citta->GetValue().Upper() );
		break;
	case ID_PROVINCIA:
		m_Provincia->SetValue( m_Provincia->GetValue().Upper() );
		break;
	case ID_NUM_TEL:
		m_NumTel->SetValue( m_NumTel->GetValue().Upper() );
		break;
	case ID_NUM_FAX:
		m_NumFax->SetValue( m_NumFax->GetValue().Upper() );
		break;
	case ID_NOTE:
		m_Note->SetValue( m_Note->GetValue().Upper() );
		break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::OnAdd( wxCommandEvent& event )
{
	m_listBox_Ospedali->SetSelection( -1 );
	ClearData();
	m_bHospitalAdded = true;
	EnableCtrl( true );
	m_Ospedale->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::OnModify( wxCommandEvent& event )
{
	if ( UpdateHospitalData() )
	{
		EnableCtrl( true );
		m_Ospedale->SetFocus();
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::OnSelect( wxCommandEvent& event )
{
	UpdateHospitalData();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::OnDel( wxCommandEvent& event )
{
	if ( m_listBox_Ospedali->GetSelection() < 0 )
	{
		return;
	}

	if ( !m_CurrentHospital.LoadFromDb( m_listBox_Ospedali->GetStringSelection() ) )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare l'ospedale %s?"), m_CurrentHospital.GetNome().c_str() ) != wxYES )
	{
		return;
	}

	if ( m_CurrentHospital.RemoveFromDb() )
	{
		UpdateHospitalList();
		ClearData();
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryHospitalDlg::OnOk( wxCommandEvent& event )
{
	if ( m_bWaitConfirm && QUESTION_MESSAGE( _("Non sono stati confermati i cambiamenti apportati.\nLi vuoi confermare ora?") ) == wxYES )
	{
		OnConfirm( event );
	}
	Close();
}
