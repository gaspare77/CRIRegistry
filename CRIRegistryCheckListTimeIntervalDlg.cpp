#include "CRIRegistryCheckListTimeIntervalDlg.h"

CRIRegistryCheckListTimeIntervalDlg::CRIRegistryCheckListTimeIntervalDlg( wxWindow* parent ):
CheckListTimeIntervalDlg( parent )
{
    SetIcon( wxICON(EditIcon) );
}

void CRIRegistryCheckListTimeIntervalDlg::OnAdd( wxCommandEvent& event )
{
// TODO: Implement OnAdd
}

void CRIRegistryCheckListTimeIntervalDlg::OnEdit( wxCommandEvent& event )
{
// TODO: Implement OnEdit
}

void CRIRegistryCheckListTimeIntervalDlg::OnDel( wxCommandEvent& event )
{
// TODO: Implement OnDel
}

void CRIRegistryCheckListTimeIntervalDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

void CRIRegistryCheckListTimeIntervalDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}
