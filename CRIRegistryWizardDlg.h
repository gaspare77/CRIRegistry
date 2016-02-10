#ifndef __CRIRegistryWizardDlg__
#define __CRIRegistryWizardDlg__

#include <wx/wizard.h>

#include "dbClass/CService.h"
#include "WizardPages/WizardPagesGruppo.h"
#include "WizardPages/WizardPagesPazientiTrasportati.h" 

/////////////////////////////////////////////////////////////////////////////
// CRIRegistryWizardDlg
//
class CRIRegistryWizardDlg : public wxWizard
{
public:
	CRIRegistryWizardDlg( wxWindow* parent, const CService& s  );
	const CService& GetService() { return m_Service; }
	bool Execute();

protected:
    void OnWizardCancel( wxWizardEvent& event );
    void OnWizardFinished( wxWizardEvent& event );

private:
	CService				m_Service;	
	WizardPagesGruppo*		m_pPage;

    DECLARE_EVENT_TABLE();
};

#endif // __CRIRegistryWizardDlg__
