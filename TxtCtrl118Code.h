#ifndef _TxtCtrl118Code_
#define _TxtCtrl118Code_

#include <wx/textctrl.h>
#include "CRIRegistryCodeSelectionDlg.h"

class TxtCtrl118Code : public wxTextCtrl
{
public:
    TxtCtrl118Code(); 
    TxtCtrl118Code(wxWindow *parent, 
               wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTextCtrlNameStr);

    void SetProperty( e118CodeType type, const wxArrayString& list );

protected:
	void OnExitCtrl( wxFocusEvent& event );
    void OnKeyUp( wxKeyEvent& event );

private:
    e118CodeType    m_Type;
    wxArrayString   m_CodeList;

    DECLARE_EVENT_TABLE();
};

#endif