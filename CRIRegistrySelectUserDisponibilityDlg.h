#ifndef __CRIRegistrySelectUserDisponibilityDlg__
#define __CRIRegistrySelectUserDisponibilityDlg__

#include "CRIRegistryGUIs.h"
#include "MyFunctions.h"

//// end generated include

/** Implementing SelectUserDisponibility */
class CRIRegistrySelectUserDisponibilityDlg : public SelectUserDisponibilityDlg
{
protected:
    // Handlers for SelectUserDisponibility events.
    void OnOk( wxCommandEvent& event );
    void OnCancel( wxCommandEvent& event );
    void OnCheckDate( wxCommandEvent& event );
	void OnExitCtrl( wxFocusEvent& event );

public:
    /** Constructor */
    CRIRegistrySelectUserDisponibilityDlg( wxWindow* parent );
    const wxString& GetUrl(){ return m_szUrl; }

private:
    wxString m_szUrl;
};

#endif // __CRIRegistrySelectUserDisponibilityDlg__
