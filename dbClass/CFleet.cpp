//---------------------------------------------------------------------------
// Name:        CFleet.cpp
// Author:      Gaspare Faraci
// Created:     1/28/2010
//---------------------------------------------------------------------------

#include "CFleet.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CFleet::CFleet() : 
dbClass( TABLE_PARCOMACCHINE, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_CODMEZZO	, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_GRUPPO		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_MODELLO		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_TIPO		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CODRADIO118	, 0 );
    dbClass::m_dbRow.Add( FIELD_TARGA		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_KM			, 0 );
    dbClass::m_dbRow.Add( FIELD_NOTE		, wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_NONOPERATIVA, false );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CFleet::CFleet( const dbRow& r ) : 
dbClass( r, TABLE_PARCOMACCHINE, FIELD_ID )
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool CFleet::LoadFromDb( const wxString& cod )
{
	Clear();

	if ( cod.IsEmpty() )
	{
		ERROR_MESSAGE( _("Il codice mezzo non e' stato definito") );
		return false;
	}

	wxString query = wxString::Format( _T("SELECT * FROM %s WHERE %s = \'%s\'"), TABLE_PARCOMACCHINE, FIELD_CODMEZZO, cod.c_str() );
	dbResultSet res;
	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		return false;
	}

	if ( res.GetSize() == 0 )
	{
		ERROR_MESSAGE( _("Il mezzo %s non esiste nel database"), cod.c_str() );
		return false;
	}

	m_dbRow = res.Row();
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CFleet::Clear()
{
	for ( unsigned int i = 0; i < m_dbRow.GetSize(); i++ )
	{
		m_dbRow.Col(i).Clear();
	}
}
