#include "CRIRegistryFleetDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistryFleetDlg::CRIRegistryFleetDlg( wxWindow* parent ):
FleetDlg( parent ), m_bFleetAdded( false ), m_bWaitConfirm( false )
{
    SetIcon( wxICON(AmbulanceIcon) );

    // Lock the Table
    UsersManager::Instance()->LockTable( TABLE_PARCOMACCHINE );
	
	wxString query;
	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_GRUPPO, TABLE_GRUPPI );
	wxArrayString aszGroup( dbSingleton::Instance()->SQLGetColArray( query ) );
    m_Gruppo->Append( _T("") );
    m_Gruppo->Append( aszGroup );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLOGIAMEZZI );
    wxArrayString aszAmbulanceType( dbSingleton::Instance()->SQLGetColArray( query ) );
    m_Tipo->Append( _T("") );
    m_Tipo->Append( aszAmbulanceType );
	m_Tipo->Append( OTHER_SELECTION );

    UpdateFleetList();
	ClearData();
	EnableCtrl( false );
    m_bpButton_Ok->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistryFleetDlg::~CRIRegistryFleetDlg()
{
    // Unlock the Table
    UsersManager::Instance()->UnlockTable( TABLE_PARCOMACCHINE );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::UpdateFleetList()
{
	wxString query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODMEZZO, TABLE_PARCOMACCHINE );
	m_listBox_ParcoMacchine->Clear();
	m_listBox_ParcoMacchine->Append( dbSingleton::Instance()->SQLGetColArray( query ) );
	ClearData();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryFleetDlg::UpdateFleetData()
{
	if ( m_listBox_ParcoMacchine->GetSelection() < 0 )
	{
		return false;
	}

	if ( !m_CurrentFleet.LoadFromDb( m_listBox_ParcoMacchine->GetStringSelection() ) )
	{
		return false;
	}
	
	m_CodMezzo->SetValue( m_CurrentFleet.GetCodice() );
    m_Gruppo->SetStringSelection( m_CurrentFleet.GetGruppo() );
    m_Tipo->SetStringSelection( m_CurrentFleet.GetTipo() );
    m_Modello->SetValue( m_CurrentFleet.GetModello() );
    m_Targa->SetValue( m_CurrentFleet.GetTarga() );
    m_Radio118->SetValue( m_CurrentFleet.GetRadio118() );
    m_Km->SetValue( m_CurrentFleet.GetKm() );
    m_Note->SetValue( m_CurrentFleet.GetNote() );
	m_NonOperativa->SetValue( !m_CurrentFleet.IsAvailable() );
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::ClearData()
{
	m_CodMezzo->Clear();
    m_Gruppo->SetSelection( 0 );
    m_Tipo->SetSelection( 0 );
    m_Modello->Clear();
    m_Targa->Clear();
    m_Radio118->Clear();
    m_Km->Clear();
    m_Note->Clear();
	m_NonOperativa->SetValue( false );
}

/////////////////////////////////////////////////////////////////////////////
//
// 
void CRIRegistryFleetDlg::EnableCtrl( bool enable )
{
	m_CodMezzo->Enable( enable );
	m_Gruppo->Enable( enable );
	m_Tipo->Enable( enable );
	m_Modello->Enable( enable );
	m_Targa->Enable( enable );
	m_Radio118->Enable( enable );
	m_Km->Enable( enable );
	m_Note->Enable( enable );
	m_NonOperativa->Enable( enable );
	m_bpButton_Confirm->Enable( enable );
	m_bpButton_Cancel->Enable( enable );

	m_listBox_ParcoMacchine->Enable( !enable );
	m_bpButton_Add->Enable( !enable );
	m_bpButton_Del->Enable( !enable );
	m_bpButton_Modify->Enable( !enable );

	m_bWaitConfirm = enable;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_COD_MEZZO:
		::ValidateTextCtrlFormatNumber( m_CodMezzo );
		break;
	case ID_MODELLO:
		m_Modello->SetValue( m_Modello->GetValue().Upper() );
		break;
	case ID_TARGA:
		::ValidateTextCtrlFormatPlate( m_Targa );
		break;
	case ID_RADIO_118:
		::ValidateTextCtrlFormatNumber( m_Radio118 );
		break;
	case ID_KM:
		::ValidateTextCtrlFormatNumber( m_Km );
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
void CRIRegistryFleetDlg::OnConfirm( wxCommandEvent& event )
{
	if ( m_CodMezzo->GetValue().IsEmpty() )
	{
		ERROR_MESSAGE( _("Non e' stato inserito il codice mezzo") );
		m_CodMezzo->SetFocus();
		return;
	}

	if ( m_bFleetAdded && m_listBox_ParcoMacchine->FindString( m_CodMezzo->GetValue() ) >= 0 )
	{
		WARNING_MESSAGE( _("Il codice mezzo %s esiste gia'"), m_CodMezzo->GetValue().c_str() );
		m_CodMezzo->SetFocus();
		return;
	}

	m_CurrentFleet.SetCodice( m_CodMezzo->GetValue() );
	m_CurrentFleet.SetGruppo( m_Gruppo->GetStringSelection() );
	m_CurrentFleet.SetTipo( m_Tipo->GetStringSelection() );
	m_CurrentFleet.SetModello( m_Modello->GetValue() );
	m_CurrentFleet.SetTarga( m_Targa->GetValue() );
	m_CurrentFleet.SetRadio118( m_Radio118->GetValue() );
	m_CurrentFleet.SetKm( m_Km->GetValue() );
	m_CurrentFleet.SetNote( m_Note->GetValue() );
	m_CurrentFleet.SetNotAvailable( m_NonOperativa->GetValue() );

	if ( m_bFleetAdded ) 
	{
		if ( m_CurrentFleet.InsertIntoDb() )
		{
			INFO_MESSAGE( _("Il mezzo %s e' stato inserito"), m_CurrentFleet.GetCodice().c_str() );
		}
	}
	else
	{
		if ( m_CurrentFleet.UpdateIntoDb() )
		{
			INFO_MESSAGE( _("Il mezzo %s e' stato cambiato"), m_CurrentFleet.GetCodice().c_str() );
		}
	}

	UpdateFleetList();
	m_listBox_ParcoMacchine->SetStringSelection( m_CurrentFleet.GetCodice() );
	UpdateFleetData();
	m_bFleetAdded = false;
	EnableCtrl( false );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::OnCancel( wxCommandEvent& event )
{
	m_bFleetAdded = false;
	ClearData();
	UpdateFleetData();
	EnableCtrl( false );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::OnAdd( wxCommandEvent& event )
{
	m_listBox_ParcoMacchine->SetSelection( -1 );
	ClearData();
	EnableCtrl( true );
	m_bFleetAdded = true;
	m_CodMezzo->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::OnModify( wxCommandEvent& event )
{
	if ( UpdateFleetData() )
	{
		EnableCtrl( true );
		m_CodMezzo->SetFocus();
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::OnSelect( wxCommandEvent& event )
{
	UpdateFleetData();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::OnDel( wxCommandEvent& event )
{
	if ( m_listBox_ParcoMacchine->GetSelection() < 0 )
	{
		return;
	}

	if ( !m_CurrentFleet.LoadFromDb( m_listBox_ParcoMacchine->GetStringSelection() ) )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare il mezzo %s?"), m_CurrentFleet.GetCodice().c_str() ) != wxYES )
	{
		return;
	}

	if ( m_CurrentFleet.RemoveFromDb() )
	{
		ClearData();
		UpdateFleetList();
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryFleetDlg::OnOk( wxCommandEvent& event )
{
	if ( m_bWaitConfirm && QUESTION_MESSAGE( _("Non sono stati confermati i cambiamenti apportati.\nLi vuoi confermare ora?") ) == wxYES )
	{
		OnConfirm( event );
	}
	Close();
}
