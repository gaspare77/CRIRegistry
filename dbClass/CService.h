//---------------------------------------------------------------------------
// Name:        CService.h
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#ifndef __CSERVICE_H_INCL__
#define __CSERVICE_H_INCL__

#include "../CRIRegistryConstant.h"
#include "../db/dbClass.h"
#include "CServiceCrew.h"
#include "CServicePatient.h"
#include "CHospital.h"
#include "CFleet.h"

class C118Code
{
public:
	C118Code() 
	{
		Clear();
	}
	C118Code( const wxString& g, const wxString& p, const wxString& l )
	{
		Set( g, p, l );
	}

	C118Code& operator= (const C118Code& c )
	{
		m_szGravita = c.m_szGravita;
		m_szPatologia = c.m_szPatologia;
		m_szLuogo = c.m_szLuogo;
		m_szValue = c.m_szValue;

		return *this;
	}

	virtual ~C118Code() 
	{
	}

	void Set( const wxString& g, const wxString& p, const wxString& l )
	{
		m_szGravita = g;
		m_szPatologia = p;
		m_szLuogo = l;
		if ( g.IsEmpty() || p.IsEmpty() || l.IsEmpty() )
		{
			m_szValue = wxEmptyString;
		}
		else
		{
			m_szValue = g + _T(" - ") + p + _T(" - ") + l;
		}
	}

	void Clear()
	{
		m_szGravita = wxEmptyString;
		m_szPatologia = wxEmptyString;
		m_szLuogo = wxEmptyString;
		m_szValue = wxEmptyString;
	}

	const wxString& GetGravita() const { return m_szGravita; };
	const wxString& GetPatologia() const { return m_szPatologia; };
	const wxString& GetLuogo() const { return m_szLuogo; };
	const wxString& GetValue() const { return m_szValue; };

private:
	wxString m_szGravita;
	wxString m_szPatologia;
	wxString m_szLuogo;
	wxString m_szValue;
};

class CService : public dbClass
{
public:
    // Constructor
    CService();
    CService( const dbRow& r );
	CService( const CService& s);

	// Add Crew
    virtual bool AddCrew( const CServiceCrew& crew );
    // Del Crew
    virtual bool DelCrew( const CServiceCrew& crew );
	// Get Crew
	const std::vector<CServiceCrew>& GetCrew() const { return m_vCrew; }
	std::vector<CServiceCrew>& GetCrew() { return m_vCrew; }
	// Clear All Crew
	void ClearAllCrew() { m_vCrew.clear(); }
    // Return the Name of the Driver
    wxString GetDriverName();

    // Add Patient
    virtual bool AddPatient( const CServicePatient& patient );
    // Del Patient
    virtual bool DelPatient( const CServicePatient& patient );
	// Get Patient
	const std::vector<CServicePatient>& GetPatient() const { return m_vPatient; }
	std::vector<CServicePatient>& GetPatient() { return m_vPatient; }
	// Clear All Patien
	void ClearAllPatient() { m_vPatient.clear(); }

	void SetVehicle( const CFleet& v ) { m_Vehicle = v; }
	CFleet& GetVehicle() { return m_Vehicle; }

	void SetHospital( const CHospital& h ) { m_Hospital = h; }
	CHospital& GetHospital() { return m_Hospital; }

	void Set118CodeEvent(  const C118Code& code ) { m_118CodeEvent = code; }
	C118Code& Get118CodeEvent() { return m_118CodeEvent; }

	// Insert the dbRow into the DataBase
    bool InsertIntoDb();
    // Select the dbRow from the DataBase
    bool SelectFromDb();
    // Update the dbRow into the DataBase
    bool UpdateIntoDb();
    // Remove the dbRow into the DataBase
    bool RemoveFromDb();

private:
	void Init();

	wxString						m_szForeIgnKey;
    std::vector<CServiceCrew>		m_vCrew;
    std::vector<CServicePatient>	m_vPatient;
	CFleet							m_Vehicle;
	CHospital						m_Hospital;
	C118Code						m_118CodeEvent;
};
#endif // __CSERVICE_H_INCL__
