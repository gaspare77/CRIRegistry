#ifndef __CRIRegistryCodeSelectionDlg__
#define __CRIRegistryCodeSelectionDlg__

/**
@file
Subclass of CodeSelectionDlg, which is generated by wxFormBuilder.
*/

#include <wx/bmpbuttn.h>
#include <wx/statline.h>
#include <wx/listbox.h>
#include <wx/dialog.h>
#include <wx/event.h>

#include "CRIRegistryConstant.h"
#include "db/dbClass.h"
#include "MyFunctions.h"

/** Implementing CodeSelectionDlg */
class CRIRegistryCodeSelectionDlg : public wxDialog
{
protected:
	wxListBox* m_CodeList;
	wxStaticLine* m_staticline1;
	wxBitmapButton* m_bpButton_Ok;
	wxBitmapButton* m_bpButton_Cancel;

    // Handlers for CodeSelectionDlg events.
	void OnOk( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );

public:
	/** Constructor */
	CRIRegistryCodeSelectionDlg( wxWindow* parent, e118CodeType type, const wxString& code = wxEmptyString );
	~CRIRegistryCodeSelectionDlg();

    const wxString& GetCode() { return m_szCode; }
    void SelectCode( const wxString& code );

private:
    wxString m_szCode;
};

#endif // __CRIRegistryCodeSelectionDlg__
