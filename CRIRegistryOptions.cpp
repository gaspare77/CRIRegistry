//---------------------------------------------------------------------------
// Name:        CRIRegistryOptions.cpp
// Author:      Gaspare Faraci
// Created:     29/6/2009
//---------------------------------------------------------------------------

#include "CRIRegistryOptions.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CRIRegistryOptions::CRIRegistryOptions()
{
    wxString szConfigPath = wxString::Format( _T("%s"), PRODUCTNAME );

    m_szGruppo = new TSetting<wxString>( szConfigPath,          _T("DefaultGruppo"),    wxEmptyString );     
    m_bIncrementNumServ = new TSetting<bool>( szConfigPath,     _T("IncrNumServ"),      false );
    m_bIncrementNumServSup = new TSetting<bool>( szConfigPath,  _T("IncrNumServSup"),   false );
	m_iAutoLogOutTime = new TSetting<int>( szConfigPath,        _T("AutoLogOutTime"),   5 );			
    m_szLastUser = new TSetting<wxString>( szConfigPath,        _T("LastUser"),         wxEmptyString );     
}

/////////////////////////////////////////////////////////////////////////////
// Destructor implementation
// 
CRIRegistryOptions::~CRIRegistryOptions()
{
}

/////////////////////////////////////////////////////////////////////////////
// Show
// 
bool CRIRegistryOptions::Show()
{
	CRIRegistryOptionsDlg dlg( 0l );
	dlg.ShowModal();
	return true;
}
