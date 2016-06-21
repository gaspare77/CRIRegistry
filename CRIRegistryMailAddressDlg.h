#ifndef __CRIRegistryMailAddressDlg__
#define __CRIRegistryMailAddressDlg__

/**
@file
Subclass of MailAddressDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "MyFunctions.h"


/** Implementing MailAddressDlg */
class CRIRegistryMailAddressDlg : public MailAddressDlg
{
protected:
    // Handlers for MailAddressDlg events.
    void OnExitCtrl( wxFocusEvent& event );
    void OnOk( wxCommandEvent& event );
    void OnCancel( wxCommandEvent& event );

public:
    /** Constructor */
    CRIRegistryMailAddressDlg( wxWindow* parent, const wxString& name = wxEmptyString, const wxString& email = wxEmptyString );
    ~CRIRegistryMailAddressDlg();
    const wxString& GetName() { return m_Name; }
    const wxString& GetEMail() { return m_EMail; }

private:
    wxString m_Name;
    wxString m_EMail;
};

#endif // __CRIRegistryMailAddressDlg__