/////////////////////////////////////////////////////////////////////////////
// 
//
/////////////////////////////////////////////////////////////////////////////
#include "CRIRegistryCheckListEditDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCheckListEditDlg::CRIRegistryCheckListEditDlg( wxWindow* parent, const wxString& type ):
CheckListEditDlg( parent ), m_Type(type)
{
    SetIcon( wxICON(CheckListIcon) );
    SetTitle(GetTitle() + _(" ") + m_Type );

    wxString query;
    wxArrayString azsList;

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_GRUPPO, TABLE_GRUPPI );
	azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Gruppo->Append( azsList );
    m_Gruppo->SetStringSelection( CRIRegistryOptions::Instance()->GetDefaultGruppo() );

    UpdateItemsList();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnChoice( wxCommandEvent& event )
{
    UpdateItemsList();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnItemActivate( wxTreeEvent& event )
{
     wxTreeItemId item = event.GetItem();
     if ( item && !m_Voci->HasChildren(item) )
     {
        EditItem( item );
     }
     event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnAdd( wxCommandEvent& event )
{
    wxString position = wxEmptyString;
    wxTreeItemId item = m_Voci->GetSelection();
    if ( item ) 
    {
        if ( m_Voci->HasChildren(item) )
        {
            position = m_Voci->GetItemText(item);
        }
        else
        {
            wxTreeItemId p = m_Voci->GetItemParent(item);
            if ( p )
            {
                position = m_Voci->GetItemText(p);
            }
        }
    }

    CRIRegistryCheckListAddItemDlg dlg(this, m_Gruppo->GetStringSelection(), m_Type, wxEmptyString, position);
    if ( dlg.ShowModal() == wxID_OK )
    {
        dlg.InsertIntoDb();
        UpdateItemsList();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnEdit( wxCommandEvent& event )
{
     wxTreeItemId item = m_Voci->GetSelection();
     if ( item && !m_Voci->HasChildren(item) )
     {
        EditItem( item );
     }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnDel( wxCommandEvent& event )
{
     wxTreeItemId item = m_Voci->GetSelection();
     if ( item && !m_Voci->HasChildren(item) && (::QUESTION_MESSAGE(_("Sei sicuro di vole cancellare la voce:\n%s\ndall\'elenco?"), m_Voci->GetItemText(item).c_str()) == wxYES))
     {
        wxString query = wxString::Format( _T("SELECT T1.%s FROM %s AS T1 JOIN %s AS T2 ON T1.%s_%s=T2.%s WHERE T1.%s=%s AND T1.%s=%s AND T2.%s=\'%s\'"), 
            FIELD_ID, 
            TABLE_CHECK_LIST_ITEM,
            TABLE_CHECK_LIST_TYPE,
            TABLE_CHECK_LIST_TYPE, FIELD_ID,
            FIELD_ID,
            FIELD_NOME, SQLStringFormat(m_Voci->GetItemText(item)).c_str(),
            FIELD_GRUPPO, SQLStringFormat(m_Gruppo->GetStringSelection()).c_str(),
            FIELD_TIPO, m_Type.c_str()
            );
        wxArrayString ids_to_delete = dbSingleton::Instance()->SQLGetColArray( query );
        for ( int i = 0; i < ids_to_delete.Count(); i++)
        {
            dbSingleton::Instance()->SQLDelete(TABLE_CHECK_LIST_ITEM, wxString::Format(_T("%s=%s"), FIELD_ID, ids_to_delete[i].c_str()));
        }
        UpdateItemsList();
     }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnEditHours( wxCommandEvent& event )
{
    CRIRegistryCheckListTimeIntervalDlg dlg(this, m_Gruppo->GetStringSelection());
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::UpdateItemsList()
{
    m_Voci->DeleteAllItems();

    wxTreeItemId rootId = m_Voci->AddRoot(_("root"));

	dbResultSet res;
    wxString query = wxString::Format( _T("SELECT DISTINCT(T1.%s), T3.%s FROM %s AS T1 JOIN %s AS T2 ON T1.%s_%s=T2.%s JOIN %s AS T3 ON T1.%s_%s=T3.%s WHERE T1.%s=\'%s\' AND T2.%s=\'%s\' ORDER BY T3.%s, T1.%s"), 
        FIELD_NOME, 
        FIELD_POSIZIONE,
        TABLE_CHECK_LIST_ITEM,
        TABLE_CHECK_LIST_TYPE,
        TABLE_CHECK_LIST_TYPE, FIELD_ID,
        FIELD_ID,
        TABLE_CHECK_LIST_POSITION,
        TABLE_CHECK_LIST_POSITION, FIELD_ID,
        FIELD_ID,
        FIELD_GRUPPO, m_Gruppo->GetStringSelection().c_str(),
        FIELD_TIPO, m_Type.c_str(),
        FIELD_POSIZIONE,
        FIELD_NOME
        );
    
    wxTreeItemId posId;
    wxString lastPosition = wxEmptyString;
    if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        for ( int row = 0; row < res.GetSize(); row++ )
        {
            if ( lastPosition != res.Row(row).Col(1).GetStringValue() )
            {
                posId = m_Voci->AppendItem(rootId, res.Row(row).Col(1).GetStringValue());
            }
            wxTreeItemId itemId = m_Voci->AppendItem(posId, res.Row(row).Col(0).GetStringValue());
            lastPosition = res.Row(row).Col(1).GetStringValue();
        }
        //m_Voci->ExpandAll();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListEditDlg::EditItem( const wxTreeItemId& item )
{
    CRIRegistryCheckListAddItemDlg dlg(this, m_Gruppo->GetStringSelection(), m_Type, m_Voci->GetItemText(item));
    if ( dlg.ShowModal() == wxID_OK )
    {
        dlg.UpdateDb();
        UpdateItemsList();
    }
}

