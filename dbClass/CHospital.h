//---------------------------------------------------------------------------
// Name:        CHospital.cpp
// Author:      Gaspare Faraci
// Created:     1/28/2010
//---------------------------------------------------------------------------

#ifndef __CHOSPITAL_H_INCL__
#define __CHOSPITAL_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CHospital : public dbClass
{
public:
    // Constructor
    CHospital();
    CHospital( const dbRow& r );

	bool LoadFromDb( const wxString& name );
    void Clear();

    // Get Fields Value
    wxString GetNome() const { return dbClass::m_dbRow[FIELD_NOME].GetStringValue(); }                                   
    wxString GetSocieta() const { return dbClass::m_dbRow[FIELD_SOCIETA].GetStringValue(); }                                   
    wxString GetIndirizzo() const { return dbClass::m_dbRow[FIELD_INDIRIZZO].GetStringValue(); }                        
    wxString GetCivico() const { return dbClass::m_dbRow[FIELD_CIVICO].GetStringValue(); }                               
	wxString GetCAP() const { return dbClass::m_dbRow[FIELD_CAP].GetIntValue() > 0 ? dbClass::m_dbRow[FIELD_CAP].GetStringValue() : _T(""); }
    wxString GetCitta() const { return dbClass::m_dbRow[FIELD_CITTA].GetStringValue(); }                               
    wxString GetProvincia() const { return dbClass::m_dbRow[FIELD_PROVINCIA].GetStringValue(); }                          
    wxString GetNumTel() const { return dbClass::m_dbRow[FIELD_NUM_TEL].GetStringValue(); }                              
    wxString GetNumFax() const { return dbClass::m_dbRow[FIELD_NUM_FAX].GetStringValue(); }                              
    wxString GetNote() const { return dbClass::m_dbRow[FIELD_NOTE].GetStringValue(); }                                    

    // Set Fields Value
    void SetNome( const wxString& s ) { dbClass::m_dbRow[FIELD_NOME] = s; }
    void SetSocieta( const wxString& s ) { dbClass::m_dbRow[FIELD_SOCIETA] = s; }
    void SetIndirizzo( const wxString& s ) { dbClass::m_dbRow[FIELD_INDIRIZZO] = s; }
	void SetCivico( const wxString& s ) { dbClass::m_dbRow[FIELD_CIVICO] = s; }
	void SetCAP( const wxString& s ) { dbClass::m_dbRow[FIELD_CAP] = s; }
    void SetCitta( const wxString& s ) { dbClass::m_dbRow[FIELD_CITTA] = s; }
    void SetProvincia( const wxString& s ) { dbClass::m_dbRow[FIELD_PROVINCIA] = s; }
    void SetNumTel( const wxString& s ) { dbClass::m_dbRow[FIELD_NUM_TEL] = s; }
    void SetNumFax( const wxString& s ) { dbClass::m_dbRow[FIELD_NUM_FAX] = s; }
    void SetNote( const wxString& s ) { dbClass::m_dbRow[FIELD_NOTE] = s; }
};
#endif // __CFLEET_H_INCL__
