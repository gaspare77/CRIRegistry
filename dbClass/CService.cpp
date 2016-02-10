//---------------------------------------------------------------------------
// Name:        CService.cpp
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#include "CService.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CService::CService() :
dbClass( TABLE_REGISTROSERVIZI, FIELD_ID )
{
	Init();

	dbClass::m_dbRow.Add( FIELD_NUMSERVIZIO             , 0 );
    dbClass::m_dbRow.Add( FIELD_NUMSERVIZIOSUP          , 0 );
    dbClass::m_dbRow.Add( FIELD_DATA                    , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_ORAINIZIO               , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_ORAPARTENZA             , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_ORAARRIVOTARGET         , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_ORAPARTENZATARGET       , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_ORAARRIVO               , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_ORAFINE                 , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_GRUPPO                  , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CODMEZZO                , wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_TARGAMEZZO				, wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_TIPOMEZZO				, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CODRADIO118	            , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO				, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO_NOMINATIVO	, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO_CF_PIVA		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO_INDIRIZZO		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO_CIVICO		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO_CAP			, 0 );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO_CITTA			, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_RICHIESTO_PROVINCIA		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_SCHEDA118               , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_TIPO					, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_ALTRO_TIPO			    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_DATIPAGAMENTO		    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_IMPORTO			        , 0.0 );
    dbClass::m_dbRow.Add( FIELD_ORE_FERMO_MACCHINA      , 0.0 );
    dbClass::m_dbRow.Add( FIELD_KM_PERCORSI             , 0 );
    dbClass::m_dbRow.Add( FIELD_INTERVENTO_LUOGO	    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_INTERVENTO_CAP			, 0 );
    dbClass::m_dbRow.Add( FIELD_INTERVENTO_CITTA		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_INTERVENTO_PROVINCIA	, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CENTRALINO              , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NOTE                    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CARABINIERI				, false );
    dbClass::m_dbRow.Add( FIELD_POLIZIA					, false );
    dbClass::m_dbRow.Add( FIELD_POLIZIA_MUNICIPALE		, false );
    dbClass::m_dbRow.Add( FIELD_VVFF					, false );
    dbClass::m_dbRow.Add( FIELD_GUARDIA_MEDICA			, false );
	dbClass::m_dbRow.Add( FIELD_ALTRI_MEZZI				, false );
	dbClass::m_dbRow.Add( FIELD_ALTRI_MEZZI_COD			, wxEmptyString );
	dbClass::m_dbRow.Add( FIELD_CHIUSO                  , false );
	dbClass::m_dbRow.Add( FIELD_ANNULLATO               , false );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CService::CService( const dbRow& r ) : 
dbClass( r, TABLE_REGISTROSERVIZI, FIELD_ID )
{    
	Init();
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CService::CService( const CService& s ) : 
dbClass( s.m_dbRow, TABLE_REGISTROSERVIZI, FIELD_ID )
{
	Init();

	m_vCrew = s.m_vCrew;
	m_vPatient = s.m_vPatient;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CService::Init()
{
	m_szForeIgnKey = wxString::Format( _T("%s_%s"), TABLE_REGISTROSERVIZI, FIELD_ID );
}

/////////////////////////////////////////////////////////////////////////////
// Add Crew
// 
bool CService::AddCrew( const CServiceCrew& crew )
{
    CServiceCrew c( crew );
	if ( GetId() > 0 )
	{
		c.Add( m_szForeIgnKey, GetId() );
		if ( !c.InsertIntoDb() )
		{
			return false;
		}
	}
    else
    {
        c.SetId( m_vCrew.size() + 1 );
    }
    m_vCrew.push_back( c );
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// Del Crew
// 
bool CService::DelCrew( const CServiceCrew& crew )
{
    std::vector<CServiceCrew>::iterator it;
    for ( it = m_vCrew.begin(); it != m_vCrew.end(); ++it )
    {
        if ( *it == crew )
        {
			if ( GetId() > 0 )
			{
				if ( !it->RemoveFromDb() )
				{
					return false;
				}
			}
            m_vCrew.erase( it );
			break;
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
wxString CService::GetDriverName()
{
    wxString s;
	std::vector<CServiceCrew>::iterator it;
	for ( it = m_vCrew.begin(); it != m_vCrew.end(); ++it )
	{
        if ( it->GetField(FIELD_QUALIFICA).GetStringValue() == szQualification[QUALIFICATION_AUTISTA] )
        {
            s = it->GetField(FIELD_COGNOME).GetStringValue();
            break;
        }
    }
    return s;
}

/////////////////////////////////////////////////////////////////////////////
// Add Patient
// 
bool CService::AddPatient( const CServicePatient& patient )
{
    CServicePatient p( patient );
	if ( GetId() > 0 )
	{
		p.Add( m_szForeIgnKey, GetId() );
		if ( !p.InsertIntoDb() )
		{
			return false;
		}
	}
    else
    {
        p.SetId( m_vPatient.size() + 1 );
    }
    m_vPatient.push_back( p );
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// Del Patient
// 
bool CService::DelPatient( const CServicePatient& patient )
{
    std::vector<CServicePatient>::iterator it;
    for ( it = m_vPatient.begin(); it != m_vPatient.end(); ++it )
    {
        if ( *it == patient )
        {
			if ( GetId() > 0 )
			{
				if ( !it->RemoveFromDb() )
				{
					return false;
				}
			}
			m_vPatient.erase( it );
			break;
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Insert the dbRow into the DataBase
// 
bool CService::InsertIntoDb()
{
	if ( !dbClass::InsertIntoDb() )
	{
		return false;
	}

	std::vector<CServiceCrew>::iterator c;
	for ( c = m_vCrew.begin(); c != m_vCrew.end(); ++c )
	{
		c->Add( m_szForeIgnKey, GetId() );
		if ( !c->InsertIntoDb() )
		{
			return false;
		}
	}

	std::vector<CServicePatient>::iterator p;
	for ( p = m_vPatient.begin(); p != m_vPatient.end(); ++p )
	{
		p->Add( m_szForeIgnKey, GetId() );
		if ( !p->InsertIntoDb() )
		{
			return false;
		}
	}

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Select the dbRow from the DataBase
// 
bool CService::SelectFromDb()
{
	if ( !dbClass::SelectFromDb() )
	{
	   return false;
	}

	wxString query;
	dbResultSet res;
	size_t i;

	// Select the Crews
	query = wxString::Format( _T("SELECT %s FROM %s WHERE %s=%d ORDER BY %s"), 
								FIELD_ID,
								TABLE_REGISTROSERVIZI_EQUIPAGGI,
								m_szForeIgnKey.c_str(),
								GetId(),
								FIELD_QUALIFICA);

	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
	   return false;
	}

    m_vCrew.clear();
	for ( i = 0; i < res.GetSize(); i++ )
	{
	   CServiceCrew c;
	   c[FIELD_ID] = res.Row(i).Col(0).GetIntValue();
	   if ( !c.SelectFromDb() )
	   {
		   return false;
	   }
	   m_vCrew.push_back( c );
	}
	
	// Select the Patients
	query = wxString::Format( _T("SELECT %s FROM %s WHERE %s=%d"), 
								FIELD_ID,
								TABLE_REGISTROSERVIZI_PAZIENTI,
								m_szForeIgnKey.c_str(),
								GetId() );

	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
	   return false;
	}

    m_vPatient.clear();
	for ( i = 0; i < res.GetSize(); i++ )
	{
	   CServicePatient p;
	   p[FIELD_ID] = res.Row(i).Col(0).GetIntValue();
	   if ( !p.SelectFromDb() )
	   {
		   return false;
	   }
	   m_vPatient.push_back( p );
	}
	
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// Update the dbRow into the DataBase
// 
bool CService::UpdateIntoDb()
{
    if ( !dbClass::UpdateIntoDb() )
	{
		return false;
	}

	std::vector<CServiceCrew>::iterator c;
	for ( c = m_vCrew.begin(); c != m_vCrew.end(); ++c )
	{
		if ( !c->UpdateIntoDb() )
		{
			return false;
		}
	}

	std::vector<CServicePatient>::iterator p;
	for ( p = m_vPatient.begin(); p != m_vPatient.end(); ++p )
	{
		if ( !p->UpdateIntoDb() )
		{
			return false;
		}
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
// Remove the dbRow into the DataBase
// 
bool CService::RemoveFromDb()
{
    return dbClass::RemoveFromDb();
}
