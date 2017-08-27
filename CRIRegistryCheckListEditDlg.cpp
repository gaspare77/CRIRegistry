#include "CRIRegistryCheckListEditDlg.h"

CRIRegistryCheckListEditDlg::CRIRegistryCheckListEditDlg( wxWindow* parent ):
CheckListEditDlg( parent )
{
    SetIcon( wxICON(CheckListIcon) );
}

void CRIRegistryCheckListEditDlg::OnChoice( wxCommandEvent& event )
{
// TODO: Implement OnChoice
}

void CRIRegistryCheckListEditDlg::OnAdd( wxCommandEvent& event )
{
    CRIRegistryCheckListAddItemDlg dlg(this);
    if ( dlg.ShowModal() == wxID_OK )
    {
    }
}

void CRIRegistryCheckListEditDlg::OnEdit( wxCommandEvent& event )
{
// TODO: Implement OnEdit
}

void CRIRegistryCheckListEditDlg::OnDel( wxCommandEvent& event )
{
// TODO: Implement OnDel
}

void CRIRegistryCheckListEditDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

void CRIRegistryCheckListEditDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}
