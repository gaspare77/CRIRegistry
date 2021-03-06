#ifndef __CRIRegistryFleetDlg__
#define __CRIRegistryFleetDlg__

/**
@file
Subclass of FleetDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "dbClass/CFleet.h"
#include "UsersManager.h"

/** Implementing FleetDlg */
class CRIRegistryFleetDlg : public FleetDlg
{
protected:
	// Handlers for FleetDlg events.
	void OnConfirm( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );
	void OnExitCtrl( wxFocusEvent& event );
	void OnSelect( wxCommandEvent& event );
	void OnModify( wxCommandEvent& event );
    void OnAdd( wxCommandEvent& event );
    void OnDel( wxCommandEvent& event );
    void OnOk( wxCommandEvent& event );
	
public:
	/** Constructor */
	CRIRegistryFleetDlg( wxWindow* parent );
    ~CRIRegistryFleetDlg();

private:
	void EnableCtrl( bool enable );
	void ClearData();
    void UpdateFleetList();
    bool UpdateFleetData();

	CFleet m_CurrentFleet;
	bool m_bFleetAdded;
	bool m_bWaitConfirm;

};

#endif // __CRIRegistryFleetDlg__
