#ifndef __WizardPagesLuogoTrasportato__
#define __WizardPagesLuogoTrasportato__

/**
@file
Subclass of LuogoTrasportato, which is generated by wxFormBuilder.
*/

#include "../CRIRegistryWizardPagesGUIs.h"
#include "../dbClass/CService.h"
#include "WizardPagesUtilizzoMezzo.h"

/** Implementing LuogoTrasportato */
class WizardPagesLuogoTrasportato : public LuogoTrasportato
{
protected:
	// Handlers for LuogoTrasportato events.
	void OnCheck( wxCommandEvent& event );
	void OnExitCtrl( wxFocusEvent& event );

public:
	/** Constructor */
	WizardPagesLuogoTrasportato( wxWindow* parent, CService* service );
    ~WizardPagesLuogoTrasportato(){ }

protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual bool GoNext();
	virtual bool GoPrev();

    CService*					    m_pService;
    WizardPagesUtilizzoMezzo*       m_pPage1;
};

#endif // __WizardPagesLuogoTrasportato__