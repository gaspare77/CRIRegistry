#ifndef __CRIRegistryAddPatientDlg__
#define __CRIRegistryAddPatientDlg__

/**
@file
Subclass of AddPatientDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "dbClass/CServicePatient.h"
#include "dbClass/CHospital.h"
#include "UsersManager.h"

/** Implementing AddPatientDlg */
class CRIRegistryAddPatientDlg : public AddPatientDlg
{
protected:
	// Handlers for AddPatientDlg events.
	void OnExitCtrl( wxFocusEvent& event );
	void OnOk( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );
	void OnCheckBox( wxCommandEvent& event );

public:
	/** Constructor */
	CRIRegistryAddPatientDlg( wxWindow* parent, const CServicePatient& patient = DummyPatient );
	const CServicePatient& GetPatient() { return m_Patient; }

private:
	CServicePatient         m_Patient;
	CHospital               m_HospitalSelected;
};

#endif // __CRIRegistryAddPatientDlg__
