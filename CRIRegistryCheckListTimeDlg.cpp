#include "CRIRegistryCheckListTimeDlg.h"

CRIRegistryCheckListTimeDlg::CRIRegistryCheckListTimeDlg( wxWindow* parent ):
CheckListTimeDlg( parent )
{
    SetIcon( wxICON(EditIcon) );
}

void CRIRegistryCheckListTimeDlg::OnExitCtrl( wxFocusEvent& event )
{
// TODO: Implement OnExitCtrl
}

void CRIRegistryCheckListTimeDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

void CRIRegistryCheckListTimeDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}
