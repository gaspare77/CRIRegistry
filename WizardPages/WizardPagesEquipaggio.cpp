#include "WizardPagesEquipaggio.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesEquipaggio::WizardPagesEquipaggio( wxWizard* parent, CService* service ):
Equipaggio( (wxWindow*)parent ), m_pService( service )
{
	m_pPage = new WizardPagesRichiesto( parent, service );
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );

	m_Equipaggio->InsertColumn( 0, _("Cognome"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 1, _("Nome"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 2, _("Qualifica"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 3, _("Qualifica Stato"), wxLIST_FORMAT_CENTER );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::OnChoice( wxCommandEvent& event )
{
	if ( m_Mezzo->GetStringSelection().IsEmpty() || !m_Ambulance.LoadFromDb( m_Mezzo->GetStringSelection() ) )
	{
		m_Mezzo->SetSelection( -1 );
		m_Targa->Clear();
		m_Tipo->Clear();
		m_Ambulance.Clear();
		m_pService->ClearAllCrew();
		UpdateCrewsListCtrl();
		return;
	}

	m_pService->GetField(FIELD_CODMEZZO) = m_Ambulance.GetCodice();
	m_pService->GetField(FIELD_TARGAMEZZO) = m_Ambulance.GetTarga();
//use the crew type=> m_pService->GetField(FIELD_TIPOMEZZO) = m_Ambulance.GetTipo();
	m_pService->SetVehicle( m_Ambulance );
	SelectCrew();

	m_Targa->SetValue( m_Ambulance.GetTarga() );
//use the crew type=> m_Tipo->SetValue( m_Ambulance.GetTipo() );
	m_Tipo->SetValue( m_pService->GetField(FIELD_TIPOMEZZO).GetStringValue() );
    UpdateCrewsListCtrl();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::OnAdd( wxCommandEvent& event )
{
	if ( m_Mezzo->GetStringSelection().IsEmpty() )
    {
        return;
    }

    CRIRegistryCrewDlg dlg( this );
	if ( dlg.ShowModal() == wxID_OK )
	{
		m_pService->AddCrew( dlg.GetCrew() );
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::OnModify( wxCommandEvent& event )
{
	std::vector<CServiceCrew>::iterator it = GetCrewSelected();
	if ( it == m_pService->GetCrew().end() )
	{
		return;
	}

	CRIRegistryCrewDlg dlg( this, *it );
	if ( dlg.ShowModal() == wxID_OK )
	{
		*it = dlg.GetCrew();
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::OnDel( wxCommandEvent& event )
{
	std::vector<CServiceCrew>::iterator it = GetCrewSelected();
	if ( it == m_pService->GetCrew().end() )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare %s %s?"), 
		it->GetField(FIELD_COGNOME).GetCharValue(), 
		it->GetField(FIELD_NOME).GetCharValue() ) == wxYES )
	{
		m_pService->DelCrew( *it );
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::OnSize( wxSizeEvent& event )
{
	int w = m_Equipaggio->GetSize().GetWidth() - 30;
    m_Equipaggio->SetColumnWidth( 0, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 1, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 2, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 3, GET_PERC(25., w) );	

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::OnEnter()
{
	wxString query = wxString::Format( _T("SELECT DISTINCT(%s) FROM %s WHERE \'%s\' >= %s AND \'%s\' <= %s AND %s IS NOT NULL ORDER BY %s"), 
		FIELD_CODMEZZO, 
		TABLE_REGISTROTURNI, 
		m_pService->GetField(FIELD_ORAINIZIO).GetCharValue(),
		FIELD_DATAORAINIZIO, 
		m_pService->GetField(FIELD_ORAINIZIO).GetCharValue(),
		FIELD_DATAORAFINE, 
        FIELD_CODMEZZO,
        FIELD_CODMEZZO
		);

	wxArrayString azsList = dbSingleton::Instance()->SQLGetColArray( query );
	m_Mezzo->Clear();
    m_Mezzo->Append( _T("") );
    m_Mezzo->Append( azsList );
	m_Mezzo->SetStringSelection( m_pService->GetField(FIELD_CODMEZZO).GetStringValue() );
	m_Mezzo->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::OnExit()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesEquipaggio::GoNext()
{
	if ( m_Mezzo->GetStringSelection().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato selezionato il mezzo") );
		m_Mezzo->SetFocus();
		return false;
	}

	if ( m_Equipaggio->GetItemCount() == 0 )
	{
		WARNING_MESSAGE( _("Non e' stato inserito nessun equipaggio") );
		m_bpButton_Add->SetFocus();
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesEquipaggio::GoPrev()
{
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::UpdateCrewsListCtrl()
{
	m_Equipaggio->DeleteAllItems();

	std::vector<CServiceCrew>::iterator it;
	for ( it = m_pService->GetCrew().begin(); it != m_pService->GetCrew().end(); ++it )
	{
        long i = m_Equipaggio->GetItemCount();
        m_Equipaggio->InsertItem( i, it->GetField(FIELD_COGNOME).GetStringValue() );
        m_Equipaggio->SetItem( i, 1, it->GetField(FIELD_NOME).GetStringValue() );
        m_Equipaggio->SetItem( i, 2, it->GetField(FIELD_QUALIFICA).GetStringValue() );
		m_Equipaggio->SetItem( i, 3, it->GetField(FIELD_QUALIFICASTATO).GetStringValue() );
		m_Equipaggio->SetItemPtrData( i, it->GetId() );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
long WizardPagesEquipaggio::GetCrewItemSelected()
{
    for ( long i = 0; i < m_Equipaggio->GetItemCount(); i++ )
    {
		if ( m_Equipaggio->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
			return i;
        }
    }

	return -1;
}

/////////////////////////////////////////////////////////////////////////////
//
//
std::vector<CServiceCrew>::iterator WizardPagesEquipaggio::GetCrewSelected()
{
	std::vector<CServiceCrew>::iterator it = m_pService->GetCrew().end();
	long item = GetCrewItemSelected();
	if ( item < 0 )
	{
	    return it;
	}

	for ( it = m_pService->GetCrew().begin(); it != m_pService->GetCrew().end(); ++it )
	{
		if ( m_Equipaggio->GetItemData( item ) == it->GetId() )
		{
			break;
		}
	}

    return it;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesEquipaggio::SelectCrew()
{
	m_pService->ClearAllCrew();

	wxString query = wxString::Format( _T("SELECT %s,%s,%s,%s,%s FROM %s WHERE %s=%s AND \'%s\' >= %s AND \'%s\' < %s ORDER BY %s"),
										  FIELD_COGNOME,
										  FIELD_NOME,
										  FIELD_QUALIFICA,
										  FIELD_QUALIFICASTATO,
                                          FIELD_TIPO,
										  TABLE_REGISTROTURNI,
										  FIELD_CODMEZZO,
										  m_Ambulance.GetCodice().c_str(),
										  m_pService->GetField(FIELD_ORAINIZIO).GetCharValue(),
										  FIELD_DATAORAINIZIO,
										  m_pService->GetField(FIELD_ORAINIZIO).GetCharValue(),
										  FIELD_DATAORAFINE,
										  FIELD_QUALIFICA);

	dbResultSet res;
	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		return;
	}

	m_pService->GetField(FIELD_TIPOMEZZO) = res.Row().Col(FIELD_TIPO).GetStringValue();

    for ( int i = 0; i < (int)res.GetSize(); i++ )
    {
        CServiceCrew crew;
        crew[FIELD_COGNOME] = res.Row(i).Col(FIELD_COGNOME).GetStringValue();
        crew[FIELD_NOME] = res.Row(i).Col(FIELD_NOME).GetStringValue();
        crew[FIELD_QUALIFICA] = res.Row(i).Col(FIELD_QUALIFICA).GetStringValue();
        crew[FIELD_QUALIFICASTATO] = res.Row(i).Col(FIELD_QUALIFICASTATO).GetStringValue();
        m_pService->AddCrew( crew );
    }
}
