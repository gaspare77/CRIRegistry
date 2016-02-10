//---------------------------------------------------------------------------
// Name:        CFleet.cpp
// Author:      Gaspare Faraci
// Created:     1/28/2010
//---------------------------------------------------------------------------

#ifndef __CFLEET_H_INCL__
#define __CFLEET_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CFleet : public dbClass
{
public:
    // Constructor
    CFleet();
    CFleet( const dbRow& r );

	bool LoadFromDb( const wxString& cod );
    void Clear();

    // Get Fields Value
    wxString GetCodice() const { return dbClass::m_dbRow[FIELD_CODMEZZO].GetStringValue(); }
    wxString GetRadio118() const { return dbClass::m_dbRow[FIELD_CODRADIO118].GetStringValue(); }
	wxString GetKm() const { return dbClass::m_dbRow[FIELD_KM].GetIntValue() != 0 ? dbClass::m_dbRow[FIELD_KM].GetStringValue() : _T(""); }
    wxString GetGruppo() const { return dbClass::m_dbRow[FIELD_GRUPPO].GetStringValue(); }
    wxString GetModello() const { return dbClass::m_dbRow[FIELD_MODELLO].GetStringValue(); }
    wxString GetTipo() const { return dbClass::m_dbRow[FIELD_TIPO].GetStringValue(); }
    wxString GetTarga() const { return dbClass::m_dbRow[FIELD_TARGA].GetStringValue(); }
    wxString GetNote() const { return dbClass::m_dbRow[FIELD_NOTE].GetStringValue(); }

    bool IsAvailable() const { return !dbClass::m_dbRow[FIELD_NONOPERATIVA].GetBoolValue(); }
    

    // Set Fields Value
	void SetCodice( const wxString& cod ) { dbClass::m_dbRow[FIELD_CODMEZZO] = cod; }
    void SetRadio118( const wxString& radio118 ) { dbClass::m_dbRow[FIELD_CODRADIO118] = radio118; }
    void SetKm( const wxString& km ) { dbClass::m_dbRow[FIELD_KM] = km; }
    void SetGruppo( const wxString& gruppo ) { dbClass::m_dbRow[FIELD_GRUPPO] = gruppo; }
    void SetModello( const wxString& modello ) { dbClass::m_dbRow[FIELD_MODELLO] = modello; }
    void SetTipo( const wxString& tipo ) { dbClass::m_dbRow[FIELD_TIPO] = tipo; }
    void SetTarga( const wxString& targa ) { dbClass::m_dbRow[FIELD_TARGA] = targa; }
    void SetNote( const wxString& note ) { dbClass::m_dbRow[FIELD_NOTE] = note; }
	void SetNotAvailable( bool b ) { dbClass::m_dbRow[FIELD_NONOPERATIVA] = b; }
};
#endif // __CFLEET_H_INCL__
