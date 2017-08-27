#include "CRIRegistryCheckListDlg.h"

CRIRegistryCheckListDlg::CRIRegistryCheckListDlg( wxWindow* parent ):
CheckListDlg( parent )
{
    SetIcon( wxICON(CheckListIcon) );
}

void CRIRegistryCheckListDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

void CRIRegistryCheckListDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}
