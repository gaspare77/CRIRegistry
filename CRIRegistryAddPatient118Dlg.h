#ifndef __CRIRegistryAddPatient118Dlg__
#define __CRIRegistryAddPatient118Dlg__

/**
@file
Subclass of AddPatient118Dlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "dbClass/CServicePatient.h"
#include "dbClass/CHospital.h"
#include "UsersManager.h"
#include "TxtCtrl118Code.h"
#include "CRIRegistryCAPListDlg.h"

/** Implementing AddPatientDlg */
class CRIRegistryAddPatient118Dlg : public AddPatient118Dlg
{
protected:
	// Handlers for PatientDlg events.
	void OnExitCtrl( wxFocusEvent& event );
	void OnOk( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );
	void OnCheckBox( wxCommandEvent& event );
    void OnKeyUp( wxKeyEvent& event );

public:
	/** Constructor */
	CRIRegistryAddPatient118Dlg( wxWindow* parent, const CServicePatient& patient = DummyPatient );
	const CServicePatient& GetPatient() { return m_Patient; }

private:
	CServicePatient     m_Patient;
	CHospital           m_HospitalSelected;
	wxArrayString		m_CodeGravityList;
	wxArrayString		m_CodePatology1List;
	wxArrayString		m_CodePatology2List;
	wxArrayString		m_CodePlaceList;
	wxArrayString		m_CodeTreatmentList;
	wxArrayString		m_CodeDinamicList;
};

#endif // __CRIRegistryAddPatient118Dlg__
