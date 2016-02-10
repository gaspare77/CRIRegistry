//---------------------------------------------------------------------------
// Name:        CServiceCrew.cpp
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#ifndef __CSERVICECREW_H_INCL__
#define __CSERVICECREW_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CServiceCrew : public dbClass
{
public:
    // Constructor
    CServiceCrew();
    CServiceCrew( const dbRow& r );
	CServiceCrew( const CServiceCrew& s );

    // Get Fields Value

    // Set Fields Value

};
#endif // __CSERVICECREW_H_INCL__
