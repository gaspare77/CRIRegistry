//---------------------------------------------------------------------------
// Name:        CComunication.cpp
// Author:      Gaspare Faraci
// Created:     11/6/2014
//---------------------------------------------------------------------------

#ifndef __CCOMUNICATION_H_INCL__
#define __CCOMUNICATION_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CComunication : public dbClass
{
public:
    // Constructor
    CComunication();    
    CComunication( const dbRow& r );
    CComunication( const CComunication& c);
};
#endif // __CCOMUNICATION_H_INCL__
