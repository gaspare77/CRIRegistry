#ifndef __UsersManagerChangeUsersPwdDlg__
#define __UsersManagerChangeUsersPwdDlg__

/**
@file
Subclass of ChangeUsersPwdDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "UsersManager.h"
#include "MyFunctions.h"

/** Implementing ChangeUsersPwdDlg */
class UsersManagerChangeUsersPwdDlg : public ChangeUsersPwdDlg
{
protected:
	// Handlers for ChangeUsersPwdDlg events.
	void OnOk( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );

public:
	/** Constructor */
	UsersManagerChangeUsersPwdDlg( wxWindow* parent );
	wxString GetNewPassword(){ return m_szPwd; }
	
private:
	wxString m_szPwd;
};

#endif // __UsersManagerChangeUsersPwdDlg__