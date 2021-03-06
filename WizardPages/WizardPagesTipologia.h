#ifndef __WizardPagesTipologia__
#define __WizardPagesTipologia__

/**
@file
Subclass of Tipologia, which is generated by wxFormBuilder.
*/

#include "../CRIRegistryWizardPagesGUIs.h"
#include "../dbClass/CService.h"
#include "WizardPagesPaziente.h"
#include "WizardPagesOspedale.h"
#include "WizardPagesRichiedente.h"
#include "WizardPagesLuogoIntervento.h"

/** Implementing Tipologia */
class WizardPagesTipologia : public Tipologia
{
public:
	/** Constructor */
	WizardPagesTipologia( wxWindow* parent, CService* service );	
	~WizardPagesTipologia(){ }
	
protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual bool GoNext();
	virtual bool GoPrev();

private:
	CService*					m_pService;
    WizardPagesLuogoIntervento*	m_pPage1;
    WizardPagesPaziente*	    m_pPage2;
    WizardPagesOspedale*	    m_pPage3;
    WizardPagesRichiedente*	    m_pPage4;
	wxArrayString				m_aszType118;
	wxArrayString				m_aszTypeOrdinary;
	wxArrayString				m_aszTypeInternal;
};

#endif // __WizardPagesTipologia__
