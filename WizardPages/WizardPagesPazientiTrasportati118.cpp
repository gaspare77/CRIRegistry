#include "WizardPagesPazientiTrasportati118.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesPazientiTrasportati118::WizardPagesPazientiTrasportati118( wxWindow* parent , CService* service ):
PazientiTrasportati( (wxWindow*)parent ), m_pService( service )
{
	m_pPage = new WizardPagesUtilizzoMezzo( parent, service ); 
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );

    m_Pazienti->InsertColumn( 0, _("Nominativo"), wxLIST_FORMAT_LEFT );
    m_Pazienti->InsertColumn( 1, _("Eta'"), wxLIST_FORMAT_CENTER );
    m_Pazienti->InsertColumn( 2, _("Cod.U"), wxLIST_FORMAT_CENTER );
    m_Pazienti->InsertColumn( 3, _("Cod.R"), wxLIST_FORMAT_CENTER );
    m_Pazienti->InsertColumn( 4, _("Esito"), wxLIST_FORMAT_LEFT );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati118::OnAdd( wxCommandEvent& event )
{
	CServicePatient p;
	p[FIELD_COD_EVE_GRAVITA] = m_pService->Get118CodeEvent().GetGravita();
	p[FIELD_COD_EVE_PATOLOGIA] = m_pService->Get118CodeEvent().GetPatologia();	
	p[FIELD_COD_EVE_LUOGO] = m_pService->Get118CodeEvent().GetLuogo();
	CRIRegistryAddPatient118Dlg dlg( this, p );
	if ( dlg.ShowModal() == wxID_OK )
	{
		m_pService->AddPatient( dlg.GetPatient() );
		UpdatePatientsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati118::OnModify( wxCommandEvent& event )
{
	std::vector<CServicePatient>::iterator it = GetPatientSelected();
	if ( it == m_pService->GetPatient().end() )
	{
		return;
	}

	CRIRegistryAddPatient118Dlg dlg( this, *it );
	if ( dlg.ShowModal() == wxID_OK )
	{
		*it = dlg.GetPatient();
		UpdatePatientsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati118::OnDel( wxCommandEvent& event )
{
	std::vector<CServicePatient>::iterator it = GetPatientSelected();
	if ( it == m_pService->GetPatient().end() )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare il paziente %s %s?"), it->GetField(FIELD_COGNOME).GetCharValue(), it->GetField(FIELD_NOME).GetCharValue() ) == wxYES )
	{
		m_pService->DelPatient( *it );
		UpdatePatientsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati118::OnSize( wxSizeEvent& event )
{
	int w = m_Pazienti->GetSize().GetWidth() - 30;
    m_Pazienti->SetColumnWidth( 0, GET_PERC(35., w) );
    m_Pazienti->SetColumnWidth( 1, GET_PERC(10., w) );
    m_Pazienti->SetColumnWidth( 2, GET_PERC(10., w) );
    m_Pazienti->SetColumnWidth( 3, GET_PERC(10., w) );	
	m_Pazienti->SetColumnWidth( 4, GET_PERC(35., w) );	
	
	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati118::OnEnter()
{
	UpdatePatientsListCtrl();
	m_bpButton_Add->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati118::OnExit()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesPazientiTrasportati118::GoNext()
{
	if (( m_Pazienti->GetItemCount() == 0 ) && ( m_pService->GetField(FIELD_TIPO).GetStringValue() == _("URGENZE") ))
	{
		WARNING_MESSAGE( _("Non e' stato inserito nessun paziente") );
		m_bpButton_Add->SetFocus();
		return false;
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesPazientiTrasportati118::GoPrev()
{
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati118::UpdatePatientsListCtrl()
{
	m_Pazienti->DeleteAllItems();

	std::vector<CServicePatient>::iterator it;
	for ( it = m_pService->GetPatient().begin(); it != m_pService->GetPatient().end(); ++it )
	{
        long i = m_Pazienti->GetItemCount();
		wxString szNominativo = it->GetField(FIELD_COGNOME).GetStringValue() + _T(" ") + it->GetField(FIELD_NOME).GetStringValue();
		wxString szEta = it->GetField(FIELD_ETA).GetStringValue().IsEmpty() ? _T("-") : it->GetField(FIELD_ETA).GetStringValue() + it->GetField(FIELD_ETA_TIPO).GetStringValue();
		wxString szCodUscita = it->GetField(FIELD_COD_EVE_GRAVITA).GetStringValue() + it->GetField(FIELD_COD_EVE_PATOLOGIA).GetStringValue() + it->GetField(FIELD_COD_EVE_LUOGO).GetStringValue();
		wxString szCodRientro = it->GetField(FIELD_COD_RIL_GRAVITA).GetStringValue() + it->GetField(FIELD_COD_RIL_PATOLOGIA).GetStringValue() + it->GetField(FIELD_COD_RIL_LUOGO).GetStringValue();

        m_Pazienti->InsertItem( i, szNominativo );
		m_Pazienti->SetItem( i, 1, szEta );
        m_Pazienti->SetItem( i, 2, szCodUscita );
		m_Pazienti->SetItem( i, 3, szCodRientro );
		m_Pazienti->SetItem( i, 4, it->GetField(FIELD_TRASPORTATO_LUOGO).GetStringValue() );
		m_Pazienti->SetItemPtrData( i, it->GetId() );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
long WizardPagesPazientiTrasportati118::GetPatientItemSelected()
{
    for ( long i = 0; i < m_Pazienti->GetItemCount(); i++ )
    {
		if ( m_Pazienti->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
			return i;
        }
    }

	return -1;
}

/////////////////////////////////////////////////////////////////////////////
//
//
std::vector<CServicePatient>::iterator WizardPagesPazientiTrasportati118::GetPatientSelected()
{
	std::vector<CServicePatient>::iterator it = m_pService->GetPatient().end();
	long item = GetPatientItemSelected();
	if ( item < 0 )
	{
	    return it;
	}

	for ( it = m_pService->GetPatient().begin(); it != m_pService->GetPatient().end(); ++it )
	{
		if ( m_Pazienti->GetItemData( item ) == it->GetId() )
		{
			break;
		}
	}

    return it;
}