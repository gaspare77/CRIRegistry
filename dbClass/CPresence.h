//---------------------------------------------------------------------------
// Name:        CPresence.cpp
// Author:      Gaspare Faraci
// Created:     2/9/2010
//---------------------------------------------------------------------------

#ifndef __CPRESENCE_H_INCL__
#define __CPRESENCE_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CPresence : public dbClass
{
public:
    // Constructor
    CPresence();    
    CPresence( const dbRow& r );
    CPresence( const CPresence& s);
};
#endif // __CPRESENCE_H_INCL__
