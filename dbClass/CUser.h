//---------------------------------------------------------------------------
// Name:        CUser.cpp
// Author:      Gaspare Faraci
// Created:     2/9/2010
//---------------------------------------------------------------------------

#ifndef __CUSER_H_INCL__
#define __CUSER_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"
#include "../MyMD5.h"

class CUser : public dbClass
{
public:
    // Constructor
    CUser();    
    CUser( const dbRow& r );
    CUser( const CUser& s);

	bool LoadFromDb( const wxString& username );
	bool CheckPwd( const wxString& pwd ) const ;
    bool IsAlreadyLoggedIn() const;

	wxString GetName() const { return m_dbRow[FIELD_USER].GetStringValue(); }
	wxString GetNome() const { return m_dbRow[FIELD_NOME].GetStringValue(); }
	wxString GetCognome() const { return m_dbRow[FIELD_COGNOME].GetStringValue(); }
	wxString GetFullName() const { return m_dbRow[FIELD_COGNOME].GetStringValue() + _T(" ") + m_dbRow[FIELD_NOME].GetStringValue(); }
	wxString GetPwd() const { return m_dbRow[FIELD_PWD].GetStringValue(); }
	int GetPrivileges() const { return m_dbRow[FIELD_PRIVILEGES].GetIntValue(); }
	wxDateTime GetLastLogIn() const { return m_dbRow[FIELD_LAST_LOGIN].GetDateTimeValue(); }
	wxDateTime GetLastLogOut() const { return m_dbRow[FIELD_LAST_LOGOUT].GetDateTimeValue(); }

	void SetName( const wxString& name ) { m_dbRow[FIELD_USER] = name; }
	void SetNome( const wxString& nome ) { m_dbRow[FIELD_NOME] = nome; }
	void SetCognome( const wxString& cognome ) { m_dbRow[FIELD_COGNOME] = cognome; }
	void SetPwd( const wxString& pwd ) { m_dbRow[FIELD_PWD] = my_md5(pwd); }
	void SetPrivileges( int privileges ) { m_dbRow[FIELD_PRIVILEGES] = privileges; }
	void SetLastLogIn( const wxDateTime& date ) { m_dbRow[FIELD_LAST_LOGIN] = date; }
	void SetLastLogOut( const wxDateTime& date ) { m_dbRow[FIELD_LAST_LOGOUT] = date; }
};
#endif // __CUSER_H_INCL__
