#ifndef __WizardPagesOrario__
#define __WizardPagesOrario__

/**
@file
Subclass of Orario, which is generated by wxFormBuilder.
*/

#include "../CRIRegistryWizardPagesGUIs.h"
#include "../dbClass/CService.h"
#include "WizardPagesEquipaggio.h"

/** Implementing Orario */
class WizardPagesOrario : public Orario
{
protected:
	// Handlers for Orario events.
	void OnExitCtrl( wxFocusEvent& event );

public:
	/** Constructor */
	WizardPagesOrario( wxWizard* parent, CService* service );
	~WizardPagesOrario(){ }

protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual bool GoNext();
	virtual bool GoPrev();

private:
	CService*				m_pService;
	WizardPagesEquipaggio*	m_pPage;
};

#endif // __WizardPagesOrario__
