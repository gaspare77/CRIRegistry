//---------------------------------------------------------------------------
// Name:        CPresence.cpp
// Author:      Gaspare Faraci
// Created:     2/9/2010
//---------------------------------------------------------------------------

#include "CPresence.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CPresence::CPresence() :
dbClass( TABLE_REGISTROPRESENZE, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_GRUPPO		    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COGNOME			, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NOME			, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_DATAORAINIZIO	, EmptyDate );
    dbClass::m_dbRow.Add( FIELD_DATAORAFINE		, EmptyDate );
    dbClass::m_dbRow.Add( FIELD_NOTE			, wxEmptyString );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CPresence::CPresence( const dbRow& r ) : 
dbClass( r, TABLE_REGISTROPRESENZE, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CPresence::CPresence( const CPresence& s) : 
dbClass( s.m_dbRow, TABLE_REGISTROPRESENZE, FIELD_ID )
{    
}

