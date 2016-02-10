#include "WizardPagesPazientiTrasportati.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesPazientiTrasportati::WizardPagesPazientiTrasportati( wxWindow* parent , CService* service ):
PazientiTrasportati( (wxWindow*)parent ), m_pService( service )
{
	m_pPage = new WizardPagesUtilizzoMezzo( parent, service ); 
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );

    m_Pazienti->InsertColumn( 0, _("Nominativo"), wxLIST_FORMAT_LEFT );
    m_Pazienti->InsertColumn( 1, _("Eta'"), wxLIST_FORMAT_CENTER );
    m_Pazienti->InsertColumn( 2, _("Trasportato"), wxLIST_FORMAT_LEFT );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati::OnAdd( wxCommandEvent& event )
{
	CServicePatient p;
	CRIRegistryAddPatientDlg dlg( this, p );
	if ( dlg.ShowModal() == wxID_OK )
	{
		m_pService->AddPatient( dlg.GetPatient() );
		UpdatePatientsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati::OnModify( wxCommandEvent& event )
{
	std::vector<CServicePatient>::iterator it = GetPatientSelected();
	if ( it == m_pService->GetPatient().end() )
	{
		return;
	}

	CRIRegistryAddPatientDlg dlg( this, *it );
	if ( dlg.ShowModal() == wxID_OK )
	{
		*it = dlg.GetPatient();
		UpdatePatientsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati::OnDel( wxCommandEvent& event )
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
void WizardPagesPazientiTrasportati::OnSize( wxSizeEvent& event )
{
	int w = m_Pazienti->GetSize().GetWidth() - 30;
    m_Pazienti->SetColumnWidth( 0, GET_PERC(40., w) );
    m_Pazienti->SetColumnWidth( 1, GET_PERC(10., w) );
    m_Pazienti->SetColumnWidth( 2, GET_PERC(50., w) );
	
	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati::OnEnter()
{
	UpdatePatientsListCtrl();
	m_bpButton_Add->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati::OnExit()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesPazientiTrasportati::GoNext()
{
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesPazientiTrasportati::GoPrev()
{
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPazientiTrasportati::UpdatePatientsListCtrl()
{
	m_Pazienti->DeleteAllItems();

	std::vector<CServicePatient>::iterator it;
	for ( it = m_pService->GetPatient().begin(); it != m_pService->GetPatient().end(); ++it )
	{
        long i = m_Pazienti->GetItemCount();
        m_Pazienti->InsertItem( i, it->GetField(FIELD_COGNOME).GetStringValue() + _T(" ") + it->GetField(FIELD_NOME).GetStringValue() );
		m_Pazienti->SetItem( i, 1, it->GetField(FIELD_ETA).GetStringValue().IsEmpty() ? _T("-") : it->GetField(FIELD_ETA).GetStringValue() + it->GetField(FIELD_ETA_TIPO).GetStringValue() );
		m_Pazienti->SetItem( i, 2, it->GetField(FIELD_TRASPORTATO_LUOGO).GetStringValue() );
		m_Pazienti->SetItemPtrData( i, it->GetId() );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
long WizardPagesPazientiTrasportati::GetPatientItemSelected()
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
std::vector<CServicePatient>::iterator WizardPagesPazientiTrasportati::GetPatientSelected()
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