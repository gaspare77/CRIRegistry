//---------------------------------------------------------------------------
// Name:        CShift.cpp
// Author:      Gaspare Faraci
// Created:     2/9/2010
//---------------------------------------------------------------------------

#ifndef __CSHIFT_H_INCL__
#define __CSHIFT_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CShift : public dbClass
{
public:
    // Constructor
    CShift();    
    CShift( const dbRow& r );
    CShift( const CShift& s);
};
#endif // __CSHIFT_H_INCL__
