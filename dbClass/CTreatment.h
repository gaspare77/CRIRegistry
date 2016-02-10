//---------------------------------------------------------------------------
// Name:        CTreatment.h
// Author:      Gaspare Faraci
// Created:     2/15/2010
//---------------------------------------------------------------------------

#ifndef __CTREATMENT_H_INCL__
#define __CTREATMENT_H_INCL__

#include "../db/dbClass.h"
#include "../CRIRegistryConstant.h"

class CTreatment : public dbClass
{
public:
    // Constructor
    CTreatment();
    CTreatment( const dbRow& r );
	CTreatment( const CTreatment& p );
};

#endif // __CSERVICEPATIENT_H_INCL__
