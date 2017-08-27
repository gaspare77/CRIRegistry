#include "CRIRegistryCheckListAddItemDlg.h"

CRIRegistryCheckListAddItemDlg::CRIRegistryCheckListAddItemDlg( wxWindow* parent ):
CheckListAddItemDlg( parent )
{
    SetIcon( wxICON(EditIcon) );
}

void CRIRegistryCheckListAddItemDlg::OnEditPosition( wxCommandEvent& event )
{
    CRIRegistryAddFieldsDlg dlg(this, TABLE_CHECK_LIST_POSITION, FIELD_ID, FIELD_POSIZIONE);
    dlg.SetTitle(_("Posizioni Check List"));
    dlg.ShowModal();
}

void CRIRegistryCheckListAddItemDlg::OnExitCtrl( wxFocusEvent& event )
{
// TODO: Implement OnExitCtrl
}

void CRIRegistryCheckListAddItemDlg::OnEditHours( wxCommandEvent& event )
{
    CRIRegistryCheckListTimeIntervalDlg dlg(this);
    dlg.ShowModal();
}

void CRIRegistryCheckListAddItemDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

void CRIRegistryCheckListAddItemDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}
