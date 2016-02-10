//---------------------------------------------------------------------------
// Name:        CUser.cpp
// Author:      Gaspare Faraci
// Created:     2/9/2010
//---------------------------------------------------------------------------

#include "CUser.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CUser::CUser() :
dbClass( TABLE_USERS, FIELD_ID )
{
	dbClass::m_dbRow.Add( FIELD_USER,		wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_COGNOME,	wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_NOME,		wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_PWD,		wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_PRIVILEGES,	0 );
	dbClass::m_dbRow.Add( FIELD_LAST_LOGIN,	EmptyDate );
	dbClass::m_dbRow.Add( FIELD_LAST_LOGOUT,EmptyDate );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CUser::CUser( const dbRow& r ) : 
dbClass( r, TABLE_USERS, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CUser::CUser( const CUser& s) : 
dbClass( s.m_dbRow, TABLE_USERS, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool CUser::LoadFromDb( const wxString& username )
{
	if ( username.IsEmpty() )
	{
		ERROR_MESSAGE( _("Il Nome utente non e' stato definito") );
		return false;
	}

	if ( username.Lower() == _T("administrator") )
	{
		m_dbRow[FIELD_USER] = _T("administrator");
		m_dbRow[FIELD_COGNOME] = _T("FARACI");
		m_dbRow[FIELD_NOME] = _T("GASPARE");
		m_dbRow[FIELD_PWD] = my_md5("gfrgfr77");
		m_dbRow[FIELD_PRIVILEGES] = ADMINISTRATOR;
		m_dbRow[FIELD_LAST_LOGIN] = wxDateTime::Now();
		m_dbRow[FIELD_LAST_LOGOUT] = wxDateTime::Now();
		return true;
	}

	wxString query = wxString::Format( _T("SELECT * FROM %s WHERE %s = \'%s\'"), TABLE_USERS, FIELD_USER, username.c_str() );
	dbResultSet res;
	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		return false;
	}

	if ( res.GetSize() == 0 )
	{
		ERROR_MESSAGE( _("L'utente %s non esiste nel database"), username.c_str() );
		return false;
	}

	m_dbRow = res.Row();
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool CUser::CheckPwd( const wxString& pwd ) const 
{ 
	if( GetPwd() != my_md5(pwd) )
	{
		ERROR_MESSAGE( _("La password inserita non e' corretta") );
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool CUser::IsAlreadyLoggedIn() const
{
    if ( m_dbRow[FIELD_LAST_LOGOUT].GetDateTimeValue() >= m_dbRow[FIELD_LAST_LOGIN].GetDateTimeValue()  )
    {
        return false;
    }

	return QUESTION_MESSAGE( _("L'utente %s e' gia' connesso\nVuoi connetterti lo stesso?"), GetName().c_str() ) == wxNO;
}