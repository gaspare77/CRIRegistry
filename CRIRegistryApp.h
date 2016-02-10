/////////////////////////////////////////////////////////////////////////////
// Name:        CRIRegistryApp.h
// 
// Author:      Gaspare Faraci
// 
/////////////////////////////////////////////////////////////////////////////

#ifndef CRIRegistryApp_H
#define CRIRegistryApp_H

#define WIN32_LEAN_AND_MEAN
#include <wx/wx.h>
#include <wx/fs_inet.h>

#include "CRIRegistryMainFrame.h"
#include "CRIRegistryConstant.h"
#include "CRIRegistryOptions.h"
#include "db/dbSingleton.h"
#include "UsersManager.h"

class CRIRegistryApp : public wxApp
{
public:
    CRIRegistryApp(){};
    ~CRIRegistryApp(){};
    bool OnInit();
    int OnExit();

private:
	wxLocale m_locale;
};

DECLARE_APP(CRIRegistryApp)

#endif
