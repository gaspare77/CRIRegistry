#include "CRIRegistryWizardDlg.h"

/////////////////////////////////////////////////////////////////////////////
// Event Table 
// 
BEGIN_EVENT_TABLE( CRIRegistryWizardDlg, wxWizard)
    EVT_WIZARD_CANCEL(wxID_ANY, CRIRegistryWizardDlg::OnWizardCancel)
    EVT_WIZARD_FINISHED(wxID_ANY, CRIRegistryWizardDlg::OnWizardFinished)
END_EVENT_TABLE()

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CRIRegistryWizardDlg::CRIRegistryWizardDlg( wxWindow* parent, const CService& s ) :
m_Service( s )
{	
	// Set the wizzard title
	wxString title = wxString::Format( _("Registrazione guidata servizi a cura di %s"), s[FIELD_CENTRALINO].GetCharValue());

	// Create the wizard
	wxWizard::Create( parent, wxID_ANY, title, wxBitmap( wxT("Res/bp_Call.png"), wxBITMAP_TYPE_ANY ) );

    // Set Icon
    SetIcon( wxICON(CRIRegistryIcon) );

	// Create the first pages
	m_pPage = new WizardPagesGruppo( (wxWizard*)this, &m_Service );

	// Set Sizer
	SetPageSize( wxSize( 600,350 )/*m_page->GetSize()*/ );
}

/////////////////////////////////////////////////////////////////////////////
// Wizard Execute
// 
bool CRIRegistryWizardDlg::Execute()
{
	return wxWizard::RunWizard( m_pPage );
}

/////////////////////////////////////////////////////////////////////////////
// Wizard events
// 
void CRIRegistryWizardDlg::OnWizardCancel( wxWizardEvent& event )
{
	if ( QUESTION_MESSAGE("Sei sicuro di voler annullare la registrazione del servizio?") == wxYES )
	{
		event.Skip();
	}
	event.Veto();
}

/////////////////////////////////////////////////////////////////////////////
// Wizard events
// 
void CRIRegistryWizardDlg::OnWizardFinished( wxWizardEvent& event )
{
}
