#include "WizardPagesOspedale.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesOspedale::WizardPagesOspedale( wxWindow* parent, CService* service ):
Ospedale( (wxWindow*)parent ), m_pService( service )
{
    m_pPage = new WizardPagesLuogoIntervento( parent, service );
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );

	wxString query = wxString::Format( _T("SELECT %s FROM %s ORDER BY %s"), FIELD_NOME, TABLE_OSPEDALI, FIELD_NOME );
    wxArrayString azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Ospedale->Append( _T("") );
    m_Ospedale->Append( azsList );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesOspedale::OnChoice( wxCommandEvent& event )
{
    if ( m_Ospedale->GetStringSelection().IsEmpty() )
    {
        m_Societa->Clear();
        m_Hospital.Clear();
        return;
    }

    if ( !m_Hospital.LoadFromDb( m_Ospedale->GetStringSelection() ) )
    {
        m_Ospedale->SetSelection( -1 );
        m_Societa->Clear();
        return;
    }

    m_Societa->SetValue( m_Hospital.GetSocieta() );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesOspedale::OnEnter()
{
	m_Ospedale->SetStringSelection( m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO).GetStringValue() );
	m_Ospedale->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesOspedale::OnExit()
{
    m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO) = wxString::Format( _T("%s%s"), szServicePlace[SERVICEPLACE_HOSPITAL], m_Hospital.GetNome().c_str() );
    m_pService->GetField(FIELD_RICHIESTO_CF_PIVA) = m_Hospital.GetSocieta();
    m_pService->GetField(FIELD_RICHIESTO_INDIRIZZO) = m_Hospital.GetIndirizzo();
    m_pService->GetField(FIELD_RICHIESTO_CIVICO) = m_Hospital.GetCivico();
    m_pService->GetField(FIELD_RICHIESTO_CAP) = m_Hospital.GetCAP();
    m_pService->GetField(FIELD_RICHIESTO_CITTA) = m_Hospital.GetCitta();
    m_pService->GetField(FIELD_RICHIESTO_PROVINCIA) = m_Hospital.GetProvincia();
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesOspedale::GoNext()
{
	if ( m_Hospital.GetNome().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato selezionato l'ospedale") );
		m_Ospedale->SetFocus();
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesOspedale::GoPrev()
{
	return true;
}
