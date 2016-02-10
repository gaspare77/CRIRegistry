#ifndef __WizardPagesOspedale__
#define __WizardPagesOspedale__

/**
@file
Subclass of Ospedale, which is generated by wxFormBuilder.
*/

#include "../CRIRegistryWizardPagesGUIs.h"
#include "../dbClass/CService.h"
#include "../dbClass/CHospital.h"
#include "WizardPagesLuogoIntervento.h"

/** Implementing Ospedale */
class WizardPagesOspedale : public Ospedale
{
    // Handlers for Ospedale events.
    void OnChoice( wxCommandEvent& event );

public:
	/** Constructor */
	WizardPagesOspedale( wxWindow* parent, CService* service  );
	~WizardPagesOspedale() { }
	
protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual bool GoNext();
	virtual bool GoPrev();

private:
	CService*				    m_pService;
    WizardPagesLuogoIntervento*	m_pPage;
    CHospital                   m_Hospital;
};

#endif // __WizardPagesOspedale__
