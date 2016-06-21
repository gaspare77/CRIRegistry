#ifndef __WizardPagesInfoServizio118__
#define __WizardPagesInfoServizio118__

/**
@file
Subclass of InfoServizio118, which is generated by wxFormBuilder.
*/

#include "../CRIRegistryWizardPagesGUIs.h"
#include "../dbClass/CService.h"
#include "../CRIRegistryCodeSelectionDlg.h"
#include "WizardPagesPazientiTrasportati118.h"
#include "WizardPagesUtilizzoMezzo.h"

/** Implementing InfoServizio118 */
class WizardPagesInfoServizio118 : public InfoServizio118
{
protected:
    // Handlers for InfoServizio118 events.
    void OnExitCtrl( wxFocusEvent& event );
    void OnCheck( wxCommandEvent& event );

public:
    /** Constructor */
    WizardPagesInfoServizio118( wxWindow* parent, CService* service  );
    ~WizardPagesInfoServizio118(){ }
	
protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual bool GoNext();
	virtual bool GoPrev();

private:
	WizardPagesPazientiTrasportati118*	m_pPage1;
    WizardPagesUtilizzoMezzo*		    m_pPage2;
	CService*							m_pService;
	wxArrayString						m_CodeGravityList;
	wxArrayString						m_CodePatology1List;
	wxArrayString						m_CodePlaceList;
};

#endif // __WizardPagesInfoServizio118__