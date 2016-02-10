//---------------------------------------------------------------------------
// Name:        CDinamic.h
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#ifndef __CDINAMIC_H_INCL__
#define __CDINAMIC_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CDinamic : public dbClass
{
public:
    // Constructor
    CDinamic();
    CDinamic( const dbRow& r );
	CDinamic( const CDinamic& p );
};

#endif // __CSERVICEPATIENT_H_INCL__
