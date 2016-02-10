//---------------------------------------------------------------------------
// Name:        CDinamic.cpp
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#include "CDinamic.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CDinamic::CDinamic() :
dbClass( TABLE_REGISTROSERVIZI_DINAMICHE, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_CODICE, wxEmptyString );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CDinamic::CDinamic( const dbRow& r ) : 
dbClass( r, TABLE_REGISTROSERVIZI_DINAMICHE, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CDinamic::CDinamic( const CDinamic& p ) : 
dbClass( p.m_dbRow, TABLE_REGISTROSERVIZI_DINAMICHE, FIELD_ID )
{    
}
