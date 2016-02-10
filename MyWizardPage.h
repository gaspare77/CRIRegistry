#ifndef __MyWizardPage__
#define __MyWizardPage__

#include "MyFunctions.h"
#include <wx/wizard.h>

/////////////////////////////////////////////////////////////////////////////
// MyWizardPage
//
class MyWizardPage : public wxWizardPage
{
public:
    MyWizardPage( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL );
	virtual wxWizardPage* GetNext() const { return m_pNextPage; };
	virtual wxWizardPage* GetPrev() const { return m_pPrevPage; };
	virtual void SetNextPage( wxWizardPage* page ) { m_pNextPage = page; }
	virtual void SetPrevPage( wxWizardPage* page ) { m_pPrevPage = page; }

protected:
	virtual void OnEnter() {}
	virtual void OnExit() {}
	virtual bool GoNext() { return true; }
	virtual bool GoPrev() { return true; }
    virtual bool TransferDataToWindow();
    virtual bool TransferDataFromWindow();

private:
    void OnPageChange(wxWizardEvent& event);

	wxWizardPage* m_pNextPage;
	wxWizardPage* m_pPrevPage;

    DECLARE_EVENT_TABLE();
};

#endif // __MyWizardPage__
