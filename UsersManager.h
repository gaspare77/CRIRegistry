//---------------------------------------------------------------------------
// Name:        UsersManager.h
// Author:      Gaspare Faraci
// Created:     29/6/2009
//---------------------------------------------------------------------------
#ifndef __USERSMANAGER_H_INCL__
#define __USERSMANAGER_H_INCL__

#include "Singleton.h"
#include "CRIRegistryConstant.h"
#include "CRIRegistryOptions.h"
#include "db/dbSingleton.h"
#include "db/dbClass.h"
#include "dbClass/CUser.h"
#include "MyFunctions.h"
#include "UsersManagerDlg.h"
#include "UsersManagerLogInDlg.h"
#include "UsersManagerSetUsersPwdDlg.h"
#include "UsersManagerChangeUsersPwdDlg.h"
#include "MyMD5.h"

class UsersManager : public Singleton<UsersManager, UsersManager>
{
public:
	virtual ~UsersManager();
	const CUser& GetUserLogged() { return m_User; }
	bool IsUserLogged() { return !m_User.GetName().IsEmpty(); }

	bool LogIn();
	bool LogOut( bool ask = false );
	bool ChangePassword();
	bool SetPassword();
	bool Show();

    bool LockTable( const wxString& table );
    bool UnlockTable( const wxString& table );
    bool IsTableLocked( const wxString& table, const wxString& msg );
    bool LockRow( const wxString& table, int id );
    bool UnlockRow( const wxString& table, int id );
    bool IsRowLocked( const wxString& table, int id, const wxString& msg );
    bool UnlockAll();

protected:
	UsersManager();

private:
	friend Singleton<UsersManager, UsersManager>;
	wxString	m_LastUser;
	CUser		m_User;
};
#endif;