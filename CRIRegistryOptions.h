//---------------------------------------------------------------------------
// Name:        CRIRegistryOptions.h
// Author:      Gaspare Faraci
// Created:     29/6/2009
//---------------------------------------------------------------------------
#ifndef __CRIREGISTRYOPTIONS_H_INCL__
#define __CRIREGISTRYOPTIONS_H_INCL__

#include "Singleton.h"
#include "Setting.h"
#include "CRIRegistryVersion.h"
#include "CRIRegistryOptionsDlg.h"
#include "MyFunctions.h"

class CRIRegistryOptions : public Singleton<CRIRegistryOptions, CRIRegistryOptions>
{
public:
	virtual ~CRIRegistryOptions();
	bool Show();

    bool IncrementNumServ() { return m_bIncrementNumServ->GetValue(); }
    bool IncrementNumServSup() { return m_bIncrementNumServSup->GetValue(); }
    wxString GetDefaultGruppo() { return m_szGruppo->GetValue(); }
	wxString GetAutoLogOutTime() { return wxString::Format( _T("%d"), m_iAutoLogOutTime->GetValue() ); }
	int AutoLogOutTime() { return m_iAutoLogOutTime->GetValue(); }
    wxString GetLastUser() { return m_szLastUser->GetValue(); }

    void SetIncrementNumServ( bool value ) { m_bIncrementNumServ->SetValue( value ); }
    void SetIncrementNumServSup( bool value ) { m_bIncrementNumServSup->SetValue( value ); }
    void SetDefaultGruppo( const wxString& gruppo ) { m_szGruppo->SetValue( gruppo ); }
	void SetAutoLogOutTime( const wxString& time ) { m_iAutoLogOutTime->SetValue( atoi( time.c_str() ) ); }
    void SetLastUsert( const wxString& user ) { m_szLastUser->SetValue( user ); }

protected:
	CRIRegistryOptions();

private:
    friend Singleton<CRIRegistryOptions, CRIRegistryOptions>;

    TSetting<bool>*         m_bIncrementNumServ;
    TSetting<bool>*         m_bIncrementNumServSup;
    TSetting<wxString>*     m_szGruppo;
	TSetting<int>*			m_iAutoLogOutTime;
    TSetting<wxString>*     m_szLastUser;
};
#endif;