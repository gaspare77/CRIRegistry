#ifndef __CRIRegistryPresenceDlg__
#define __CRIRegistryPresenceDlg__

/**
@file
Subclass of PresenceDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "dbClass/CPresence.h"
#include "UsersManager.h"

const CPresence DummyPresence;

/** Implementing PresenceDlg */
class CRIRegistryPresenceDlg : public PresenceDlg
{
protected:
	// Handlers for PresenceDlg events.
	void OnClose( wxCloseEvent& event );
	void OnWrite( wxKeyEvent& event );
	void OnExitCtrl( wxFocusEvent& event );
	void OnOk( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );

public:
	/** Constructor */
	CRIRegistryPresenceDlg( wxWindow* parent, const CPresence& presence = DummyPresence, eMode mode = ADD );

	const CPresence& GetPresence() { return m_Presence; }
    void SetPresence( const CPresence& p ) { m_Presence = p; }

private:
	CPresence	m_Presence;
	eMode		m_Mode;

    void UpdateCtrl();
    bool UpdateData();
};

#endif // __CRIRegistryPresenceDlg__
