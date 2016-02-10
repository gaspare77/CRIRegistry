#include "MyWizardPage.h"

/////////////////////////////////////////////////////////////////////////////
// Event Table 
// 
BEGIN_EVENT_TABLE( MyWizardPage, wxWizardPage )
    EVT_WIZARD_PAGE_CHANGING( wxID_ANY, MyWizardPage::OnPageChange )
END_EVENT_TABLE()

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
MyWizardPage::MyWizardPage( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) :
wxWizardPage( (wxWizard*)parent )
{
	m_pNextPage = (wxWizardPage*)NULL;
	m_pPrevPage = (wxWizardPage*)NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Wizard Page events
// 
void MyWizardPage::OnPageChange(wxWizardEvent& event)
{
    if ( event.GetDirection() )
    {
        if ( GoNext() )
        {
            event.Skip(); 
            return;
        }
        else
        {
            event.Veto();
            return;
        }
    }
    else
    {
        if ( GoPrev() )
        {
            event.Skip(); 
            return;
        }
        else
        {
            event.Veto();
            return;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool MyWizardPage::TransferDataToWindow()
{ 
    OnEnter(); 
    return true; 
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool MyWizardPage::TransferDataFromWindow()
{ 
    OnExit(); 
    return true; 
}
