//---------------------------------------------------------------------------
// Name:        CServicePatient.cpp
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#include "CServicePatient.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CServicePatient::CServicePatient() :
dbClass( TABLE_REGISTROSERVIZI_PAZIENTI, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_COGNOME                 , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NOME                    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_FISCALE             , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_DATA_NASCITA            , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_ETA                     , 0 );
    dbClass::m_dbRow.Add( FIELD_ETA_TIPO                , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_SESSO                   , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_INDIRIZZO               , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CIVICO                  , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CAP                     , 0 );
    dbClass::m_dbRow.Add( FIELD_CITTA                   , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_PROVINCIA               , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_STATO                   , _T("ITALIA") );
    dbClass::m_dbRow.Add( FIELD_CITTADINANZA            , _T("ITALIANA") );
    dbClass::m_dbRow.Add( FIELD_MOTIVOTRASPORTO         , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_TRASPORTATO_LUOGO       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_TRASPORTATO_CAP         , 0 );
    dbClass::m_dbRow.Add( FIELD_TRASPORTATO_CITTA       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_TRASPORTATO_PROVINCIA   , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_FIRMA_SCHEDA_CRI        , false );
    dbClass::m_dbRow.Add( FIELD_FIRMA_SCHEDA_118        , false );
    dbClass::m_dbRow.Add( FIELD_NUM_TEAM                , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_PATOLOGIA           , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_EVE_GRAVITA         , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_EVE_PATOLOGIA       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_EVE_LUOGO           , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_ARR_GRAVITA         , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_ARR_PATOLOGIA       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_ARR_LUOGO           , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_PAR_GRAVITA         , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_PAR_PATOLOGIA       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_PAR_PATOLOGIA2      , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_PAR_LUOGO           , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_RIL_GRAVITA         , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_RIL_PATOLOGIA       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COD_RIL_LUOGO           , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_TRIAGE                  , wxEmptyString );

    Init();

    CDinamic d;
    d[FIELD_CODICE] = wxEmptyString;
    AddDinamic( d );
    AddDinamic( d );

    CTreatment t;
    t[FIELD_CODICE] = wxEmptyString;
    AddTreatment( t );
    AddTreatment( t );
    AddTreatment( t );
    AddTreatment( t );
    AddTreatment( t );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CServicePatient::CServicePatient( const dbRow& r ) : 
dbClass( r, TABLE_REGISTROSERVIZI_PAZIENTI, FIELD_ID )
{    
    Init();
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CServicePatient::CServicePatient( const CServicePatient& p ) : 
dbClass( p.m_dbRow, TABLE_REGISTROSERVIZI_PAZIENTI, FIELD_ID )
{    
    Init();
    m_vTreatment = p.m_vTreatment;
    m_vDinamic = p.m_vDinamic;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CServicePatient::Init()
{
    m_szForeIgnKey1 = wxString::Format( _T("%s_%s"), TABLE_REGISTROSERVIZI, FIELD_ID );
    m_szForeIgnKey2 = wxString::Format( _T("%s_%s"), TABLE_REGISTROSERVIZI_PAZIENTI, FIELD_ID );
}

/////////////////////////////////////////////////////////////////////////////
// Insert the dbRow into the DataBase
// 
bool CServicePatient::InsertIntoDb()
{
    // Insert this
    if ( !dbClass::InsertIntoDb() )
    {
        return false;
    }

    // Insert the Dinamic
    std::vector<CDinamic>::iterator d;
    for ( d = m_vDinamic.begin(); d != m_vDinamic.end(); ++d )
    {
        d->Add( m_szForeIgnKey1, GetField(m_szForeIgnKey1).GetIntValue() );
        d->Add( m_szForeIgnKey2, GetId() );
        if ( !d->InsertIntoDb() )
        {
            return false;
        }
    }

    // Insert the Tratment
    std::vector<CTreatment>::iterator t;
    for ( t = m_vTreatment.begin(); t != m_vTreatment.end(); ++t )
    {
        t->Add( m_szForeIgnKey1, GetField(m_szForeIgnKey1).GetIntValue() );
        t->Add( m_szForeIgnKey2, GetId() );
        if ( !t->InsertIntoDb() )
        {
            return false;
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Select the dbRow from the DataBase
// 
bool CServicePatient::SelectFromDb()
{
    // Select this
    if ( !dbClass::SelectFromDb() )
    {
        return false;
    }

    wxString query;
    dbResultSet res;
    size_t i;

    // Select the Dinamic
    query = wxString::Format( _T("SELECT %s FROM %s WHERE %s=%d"), 
                                FIELD_ID,
                                TABLE_REGISTROSERVIZI_DINAMICHE,
                                m_szForeIgnKey2.c_str(),
                                GetId());

    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
       return false;
    }

    m_vDinamic.clear();
    for ( i = 0; i < res.GetSize(); i++ )
    {
       CDinamic d;
       d[FIELD_ID] = res.Row(i).Col(0).GetIntValue();
       if ( !d.SelectFromDb() )
       {
           return false;
       }
       m_vDinamic.push_back( d );
    }

    // Select the Treatment
    query = wxString::Format( _T("SELECT %s FROM %s WHERE %s=%d"), 
                                FIELD_ID,
                                TABLE_REGISTROSERVIZI_PRESTAZIONI,
                                m_szForeIgnKey2.c_str(),
                                GetId());

    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
       return false;
    }

    m_vTreatment.clear();
    for ( i = 0; i < res.GetSize(); i++ )
    {
       CTreatment t;
       t[FIELD_ID] = res.Row(i).Col(0).GetIntValue();
       if ( !t.SelectFromDb() )
       {
           return false;
       }
       m_vTreatment.push_back( t );
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Update the dbRow into the DataBase
// 
bool CServicePatient::UpdateIntoDb()
{
    // Update this
    if ( !dbClass::UpdateIntoDb() )
    {
        return false;
    }

    // Update Dinamic
    std::vector<CDinamic>::iterator d;
    for ( d = m_vDinamic.begin(); d != m_vDinamic.end(); ++d )
    {
        if ( !d->UpdateIntoDb() )
        {
            return false;
        }
    }

    // Update Treatment
    std::vector<CTreatment>::iterator t;
    for ( t = m_vTreatment.begin(); t != m_vTreatment.end(); ++t )
    {
        if ( !t->UpdateIntoDb() )
        {
            return false;
        }
    }
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Remove the dbRow into the DataBase
// 
bool CServicePatient::RemoveFromDb()
{
    return dbClass::RemoveFromDb();
}

/////////////////////////////////////////////////////////////////////////////
// Add Treatment
// 
bool CServicePatient::AddTreatment( const CTreatment& treatment )
{
    CTreatment t( treatment );
    if ( GetId() > 0 )
    {
        t.Add( m_szForeIgnKey1, GetField(m_szForeIgnKey1).GetIntValue() );
        t.Add( m_szForeIgnKey2, GetId() );
        if ( !t.InsertIntoDb() )
        {
            return false;
        }
    }
    else
    {
        t.SetId( m_vTreatment.size() + 1 );
    }
    m_vTreatment.push_back( t );
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Add Dinamic
// 
bool CServicePatient::AddDinamic( const CDinamic& dinamic )
{
    CDinamic d( dinamic );
    if ( GetId() > 0 )
    {
        d.Add( m_szForeIgnKey1, GetField(m_szForeIgnKey1).GetIntValue() );
        d.Add( m_szForeIgnKey2, GetId() );
        if ( !d.InsertIntoDb() )
        {
            return false;
        }
    }
    else
    {
        d.SetId( m_vDinamic.size() + 1 );
    }
    m_vDinamic.push_back( d );
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Del Treatment
// 
bool CServicePatient::DelTreatment( const CTreatment& treatment )
{
    std::vector<CTreatment>::iterator it;
    for ( it = m_vTreatment.begin(); it != m_vTreatment.end(); ++it )
    {
        if ( *it == treatment )
        {
            if ( GetId() > 0 )
            {
                if ( !it->RemoveFromDb() )
                {
                    return false;
                }
            }
            m_vTreatment.erase( it );
            break;
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Del Dinamic
// 
bool CServicePatient::DelDinamic( const CDinamic& dinamic )
{
    std::vector<CDinamic>::iterator it;
    for ( it = m_vDinamic.begin(); it != m_vDinamic.end(); ++it )
    {
        if ( *it == dinamic )
        {
            if ( GetId() > 0 )
            {
                if ( !it->RemoveFromDb() )
                {
                    return false;
                }
            }
            m_vDinamic.erase( it );
            break;
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
wxString CServicePatient::GetDinamica( int i )
{
    if ( i < (int)m_vDinamic.size() )
    {
        return m_vDinamic[i].GetField(FIELD_CODICE).GetStringValue();
    }

    return wxEmptyString;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
wxString CServicePatient::GetTrattamento( int i )
{
    if ( i < (int)m_vTreatment.size() )
    {
        return m_vTreatment[i].GetField(FIELD_CODICE).GetStringValue();
    }

    return wxEmptyString;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CServicePatient::SetDinamica( int i, const wxString s )
{
    if ( i < (int)m_vDinamic.size() )
    {
        m_vDinamic[i].GetField(FIELD_CODICE) = s;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CServicePatient::SetTrattamento( int i, const wxString s )
{
    if ( i < (int)m_vTreatment.size() )
    {
        m_vTreatment[i].GetField(FIELD_CODICE) = s;
    }
}

