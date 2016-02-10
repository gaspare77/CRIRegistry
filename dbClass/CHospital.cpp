//---------------------------------------------------------------------------
// Name:        CHospital.cpp
// Author:      Gaspare Faraci
// Created:     1/28/2010
//---------------------------------------------------------------------------

#include "CHospital.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CHospital::CHospital() :
dbClass( TABLE_OSPEDALI, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_NOME		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_SOCIETA     , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_INDIRIZZO   , wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_CIVICO		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CAP			, 0 );
    dbClass::m_dbRow.Add( FIELD_CITTA       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_PROVINCIA   , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NUM_TEL     , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NUM_FAX     , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NOTE        , wxEmptyString );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CHospital::CHospital( const dbRow& r ) : 
dbClass( r, TABLE_OSPEDALI, FIELD_ID )
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool CHospital::LoadFromDb( const wxString& name )
{
	Clear();

	if ( name.IsEmpty() )
	{
		ERROR_MESSAGE( _("L'ospedale non e' stato definito") );
		return false;
	}

	wxString query = wxString::Format( _T("SELECT * FROM %s WHERE %s = %s"), TABLE_OSPEDALI, FIELD_NOME, SQLStringFormat(name.c_str()) );
	dbResultSet res;
	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		return false;
	}

	if ( res.GetSize() == 0 )
	{
		ERROR_MESSAGE( _("L'ospedale %s non esiste nel database"), name.c_str() );
		return false;
	}

	m_dbRow = res.Row();
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CHospital::Clear()
{
	for ( size_t i = 0; i <= m_dbRow.GetSize(); i++ )
	{
		m_dbRow.Col(i).Clear();
	}
}

