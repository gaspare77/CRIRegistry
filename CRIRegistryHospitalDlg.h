#ifndef __CRIRegistryHospitalDlg__
#define __CRIRegistryHospitalDlg__

/**
@file
Subclass of HospitalDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "dbClass/CHospital.h"
#include "UsersManager.h"

/** Implementing HospitalDlg */
class CRIRegistryHospitalDlg : public HospitalDlg
{
protected:
	// Handlers for HospitalDlg events.
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
	CRIRegistryHospitalDlg( wxWindow* parent );
    ~CRIRegistryHospitalDlg();

private:
	void EnableCtrl( bool enable );
	void ClearData(); 
    void UpdateHospitalList();
    bool UpdateHospitalData();
	CHospital m_CurrentHospital;
	bool m_bHospitalAdded;
	bool m_bWaitConfirm;
};

#endif // __CRIRegistryHospitalDlg__
