/////////////////////////////////////////////////////////////////////////////
// Name:        CRIRegistryApp.cpp
// 
// Author:      Gaspare Faraci
// 
/////////////////////////////////////////////////////////////////////////////

#include "CRIRegistryApp.h"

IMPLEMENT_APP(CRIRegistryApp)

/////////////////////////////////////////////////////////////////////////////
// 'Main program' equivalent: the program execution "starts" here
//
bool CRIRegistryApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;
    
    // Set locale language
    m_locale.Init(m_locale.GetSystemLanguage(), wxLOCALE_CONV_ENCODING);
    m_locale.AddCatalogLookupPathPrefix( _T("Locale") );
    m_locale.AddCatalog( _T("it") );

    // Set the Image handler
    wxImage::AddHandler( new wxPNGHandler );

    // Set the internet filesystem
    wxFileSystem::AddHandler( new wxInternetFSHandler );

    // Open the connection with the DataBase
    if ( !dbSingleton::Instance()->Connect( _T("DatabaseCRI.dsn") ) )
        return false;

    // Show the MainFrame
	CRIRegistryMainFrame *pFrame = new CRIRegistryMainFrame( NULL );
    SetTopWindow( pFrame );
    pFrame->Show();
	pFrame->Maximize();
    pFrame->LogInUser();

	return true;
}

/////////////////////////////////////////////////////////////////////////////
// Program exit
//
int CRIRegistryApp::OnExit()
{
	UsersManager::Destroy();
	dbSingleton::Destroy();
    return wxApp::OnExit();
}
