#ifndef __CRIRegistryPatientDlg__
#define __CRIRegistryPatientDlg__

/**
@file
Subclass of PatientDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "dbClass/CServicePatient.h"
#include "UsersManager.h"
#include "TxtCtrl118Code.h"
#include "CRIRegistryCAPListDlg.h"

/** Implementing PatientDlg */
class CRIRegistryPatientDlg : public PatientDlg
{
protected:
	// Handlers for PatientDlg events.
	void OnExitCtrl( wxFocusEvent& event );
	void OnOk( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );
    void OnKeyUp( wxKeyEvent& event );

public:
	/** Constructor */
	CRIRegistryPatientDlg( wxWindow* parent, const CServicePatient& patient = DummyPatient );

	const CServicePatient& GetPatient() { return m_Patient; }

private:
	CServicePatient m_Patient;
	wxArrayString	m_CodeGravityList;
	wxArrayString	m_CodePatology1List;
	wxArrayString	m_CodePatology2List;
	wxArrayString	m_CodePlaceList;
	wxArrayString	m_CodeTreatmentList;
	wxArrayString	m_CodeDinamicList;
};

#endif // __CRIRegistryPatientDlg__
