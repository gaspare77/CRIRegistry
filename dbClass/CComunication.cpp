//---------------------------------------------------------------------------
// Name:        CComunication.cpp
// Author:      Gaspare Faraci
// Created:     11/6/2014
//---------------------------------------------------------------------------

#include "CComunication.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CComunication::CComunication() :
dbClass( TABLE_COMUNICAZIONI, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_GRUPPO          , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_INSERITA        , EmptyDate );
    dbClass::m_dbRow.Add( FIELD_MITTENTE        , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_DESTINATARIO    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_OGGETTO         , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_TESTO           , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_LETTA           , false );
    dbClass::m_dbRow.Add( FIELD_PRIVATA         , false );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CComunication::CComunication( const dbRow& r ) : 
dbClass( r, TABLE_COMUNICAZIONI, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CComunication::CComunication( const CComunication& c) : 
dbClass( c.m_dbRow, TABLE_COMUNICAZIONI, FIELD_ID )
{    
}

