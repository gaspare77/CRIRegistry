//---------------------------------------------------------------------------
// Name:        CServiceCrew.cpp
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#include "CServiceCrew.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CServiceCrew::CServiceCrew() :
dbClass( TABLE_REGISTROSERVIZI_EQUIPAGGI, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_COGNOME       , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NOME          , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_QUALIFICA     , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_QUALIFICASTATO, wxEmptyString );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CServiceCrew::CServiceCrew( const dbRow& r ) : 
dbClass( r, TABLE_REGISTROSERVIZI_EQUIPAGGI, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CServiceCrew::CServiceCrew( const CServiceCrew& s ) : 
dbClass( s.m_dbRow, TABLE_REGISTROSERVIZI_EQUIPAGGI, FIELD_ID )
{    
}
