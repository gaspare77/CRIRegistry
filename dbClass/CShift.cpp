//---------------------------------------------------------------------------
// Name:        CShift.cpp
// Author:      Gaspare Faraci
// Created:     2/9/2010
//---------------------------------------------------------------------------

#include "CShift.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CShift::CShift() :
dbClass( TABLE_REGISTROTURNI, FIELD_ID )
{
    dbClass::m_dbRow.Add( FIELD_GRUPPO		    , wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_DATAORAINIZIO	, EmptyDate );
    dbClass::m_dbRow.Add( FIELD_DATAORAFINE		, EmptyDate );
    dbClass::m_dbRow.Add( FIELD_TIPO			, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_CODMEZZO		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_COGNOME			, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_NOME			, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_QUALIFICA		, wxEmptyString );
    dbClass::m_dbRow.Add( FIELD_QUALIFICASTATO	, wxEmptyString );
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CShift::CShift( const dbRow& r ) : 
dbClass( r, TABLE_REGISTROTURNI, FIELD_ID )
{    
}

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CShift::CShift( const CShift& s) : 
dbClass( s.m_dbRow, TABLE_REGISTROTURNI, FIELD_ID )
{    
}

