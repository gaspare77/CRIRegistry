//---------------------------------------------------------------------------
// Name:        CTreatment.cpp
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#include "CTreatment.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CTreatment::CTreatment() :
dbClass( TABLE_REGISTROSERVIZI_PRESTAZIONI, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_CODICE, wxEmptyString );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CTreatment::CTreatment( const dbRow& r ) : 
dbClass( r, TABLE_REGISTROSERVIZI_PRESTAZIONI, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CTreatment::CTreatment( const CTreatment& p ) : 
dbClass( p.m_dbRow, TABLE_REGISTROSERVIZI_PRESTAZIONI, FIELD_ID )
{    
}
