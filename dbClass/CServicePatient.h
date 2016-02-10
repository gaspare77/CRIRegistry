//---------------------------------------------------------------------------
// Name:        CServicePatient.h
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#ifndef __CSERVICEPATIENT_H_INCL__
#define __CSERVICEPATIENT_H_INCL__

#include "../CRIRegistryConstant.h"
#include "../db/dbClass.h"
#include "CDinamic.h"
#include "CTreatment.h"

class CServicePatient : public dbClass
{
public:
    // Constructor
    CServicePatient();
    CServicePatient( const dbRow& r );
	CServicePatient( const CServicePatient& p );

	// Add Treatment
    bool AddTreatment( const CTreatment& treatment );
	// Add Dinamic
    bool AddDinamic( const CDinamic& dinamic );

	// Del Treatment
    bool DelTreatment( const CTreatment& treatment );
    // Del Dinamic
    bool DelDinamic( const CDinamic& dinamic );

	// Get Treatment
	const std::vector<CTreatment>& GetTreatment() const { return m_vTreatment; }
	std::vector<CTreatment>& GetTreatment() { return m_vTreatment; }
	// Get Dinamic
	const std::vector<CDinamic>& GetDinamic() const { return m_vDinamic; }
	std::vector<CDinamic>& GetDinamic() { return m_vDinamic; }

	// Clear All Treatments
	void ClearAllTreatment() { m_vTreatment.clear(); }
	// Clear All Dinamics
	void ClearAllDinamic() { m_vDinamic.clear(); }

	// Insert the dbRow into the DataBase
    bool InsertIntoDb();
    // Select the dbRow from the DataBase
    bool SelectFromDb();
    // Update the dbRow into the DataBase
    bool UpdateIntoDb();
    // Remove the dbRow into the DataBase
    bool RemoveFromDb();

	wxString GetDinamica( int i );
	wxString GetTrattamento( int i );

	void SetDinamica( int i, const wxString s );
	void SetTrattamento( int i, const wxString s );

private:
	void Init();

	wxString			    m_szForeIgnKey1;
	wxString			    m_szForeIgnKey2;
	std::vector<CTreatment>	m_vTreatment;
	std::vector<CDinamic>	m_vDinamic;
};

const CServicePatient DummyPatient;

#endif // __CSERVICEPATIENT_H_INCL__
