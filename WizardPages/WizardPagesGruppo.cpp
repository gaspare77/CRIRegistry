#include "WizardPagesGruppo.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesGruppo::WizardPagesGruppo( wxWizard* parent, CService* service ):
Gruppo( (wxWindow*)parent ), m_pService( service )
{
    m_pPage = new WizardPagesData( parent, service );
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );

	wxString query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_GRUPPO, TABLE_GRUPPI );
    wxArrayString azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Gruppo->Append( _T("") );
    m_Gruppo->Append( azsList );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesGruppo::OnEnter()
{
	m_Gruppo->SetStringSelection( m_pService->GetField(FIELD_GRUPPO).GetStringValue() );
	m_Gruppo->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesGruppo::OnExit()
{
	m_pService->GetField(FIELD_GRUPPO) = m_Gruppo->GetStringSelection();
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesGruppo::GoNext()
{
	if ( m_pService->GetField(FIELD_GRUPPO).GetStringValue().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato selezionato il gruppo") );
		m_Gruppo->SetFocus();
		return false;
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesGruppo::GoPrev()
{
	return true;
}
