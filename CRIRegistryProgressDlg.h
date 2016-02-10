/////////////////////////////////////////////////////////////////////////////
// Name:        CRIRegistryProgressDlg.h
// 
// Author:      Gaspare Faraci
// 
/////////////////////////////////////////////////////////////////////////////

#ifndef __CRIRegistryProgressDlg__
#define __CRIRegistryProgressDlg__

#include "CRIRegistryGUIs.h"

/** Implementing ProgressDlg */
class CRIRegistryProgressDlg : public ProgressDlg
{
public:
	/** Constructor */
	CRIRegistryProgressDlg( wxWindow* parent );

    void SetText( const wxString& txt );
    void SetMax( int max );
    void Update( int val );
};

#endif // __CRIRegistryProgressDlg__
