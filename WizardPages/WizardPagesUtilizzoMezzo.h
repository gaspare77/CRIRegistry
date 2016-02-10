#ifndef __WizardPagesUtilizzoMezzo__
#define __WizardPagesUtilizzoMezzo__

/**
@file
Subclass of UtilizzoMezzo, which is generated by wxFormBuilder.
*/

#include "../CRIRegistryWizardPagesGUIs.h"
#include "../dbClass/CService.h"
#include "WizardPagesFine.h"

/** Implementing UtilizzoMezzo */
class WizardPagesUtilizzoMezzo : public UtilizzoMezzo
{
protected:
    // Handlers for UtilizzoMezzo events.
    void OnExitCtrl( wxFocusEvent& event );

public:
    /** Constructor */
    WizardPagesUtilizzoMezzo( wxWindow* parent, CService* service  );
    ~WizardPagesUtilizzoMezzo(){ }
	
protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual bool GoNext();
	virtual bool GoPrev();

private:
	CService*			m_pService;
	WizardPagesFine*	m_pPage;
    void ComputeKm();
};

#endif // __WizardPagesUtilizzoMezzo__
