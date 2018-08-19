#include "CRIRegistryCheckListTimeIntervalDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCheckListTimeIntervalDlg::CRIRegistryCheckListTimeIntervalDlg( wxWindow* parent, const wxString& gruppo ):
CheckListTimeIntervalDlg( parent ), m_Gruppo(gruppo)
{
    SetIcon( wxICON(EditIcon) );

    UpdateList();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeIntervalDlg::OnAdd( wxCommandEvent& event )
{
    CRIRegistryCheckListTimeDlg dlg(this);
    if (dlg.ShowModal() == wxID_OK)
    {
        dbRow row;
        row.Add(FIELD_GRUPPO,   m_Gruppo);
        row.Add(FIELD_NOME,     dlg.GetTurno());
        row.Add(FIELD_INIZIO,   dlg.GetInizio());
        row.Add(FIELD_FINE,     dlg.GetFine());
        dbSingleton::Instance()->SQLInsert(TABLE_CHECK_LIST_TIME, row);
        UpdateList();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeIntervalDlg::OnEdit( wxCommandEvent& event )
{
    if (m_Orari->GetSelection() >= 0)
    {
        for (std::vector<dbRow>::iterator it = m_Items.begin(); it != m_Items.end(); it++ )
        {
            if ( it->Col(FIELD_NOME).GetStringValue() == m_Orari->GetStringSelection() )
            {
                CRIRegistryCheckListTimeDlg dlg(this, it->Col(FIELD_NOME).GetStringValue(), it->Col(FIELD_INIZIO).GetStringValue(), it->Col(FIELD_FINE).GetStringValue());
                if (dlg.ShowModal() == wxID_OK)
                {
                    it->Col(FIELD_GRUPPO).SetValue(m_Gruppo);
                    it->Col(FIELD_NOME).SetValue(dlg.GetTurno());
                    it->Col(FIELD_INIZIO).SetValue(dlg.GetInizio());
                    it->Col(FIELD_FINE).SetValue(dlg.GetFine());
                    dbSingleton::Instance()->SQLUpdate(TABLE_CHECK_LIST_TIME, *it, wxString::Format(_T("%s=%d"), FIELD_ID, it->Col(FIELD_ID).GetIntValue()));
                    UpdateList();
                }
                return;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeIntervalDlg::OnDel( wxCommandEvent& event )
{
    if ((m_Orari->GetSelection() > 0 ) && (::QUESTION_MESSAGE(_("Sei sicuro di vole cancellare la voce:\n%s\ndall\'elenco?"), m_Orari->GetStringSelection().c_str()) == wxYES))
    {
        wxString condition = wxString::Format(_T("%s=%s AND %s=%s"), 
                                FIELD_NOME, SQLStringFormat(m_Orari->GetStringSelection()).c_str(),
                                FIELD_GRUPPO, SQLStringFormat(m_Gruppo).c_str());
        dbSingleton::Instance()->SQLDelete(TABLE_CHECK_LIST_TIME, condition);
        UpdateList();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeIntervalDlg::OnOk( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeIntervalDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListTimeIntervalDlg::UpdateList()
{
    m_Items.clear();
    m_Orari->Clear();

    dbResultSet res;
    dbSingleton::Instance()->SQLQuery(wxString::Format( _T("SELECT * FROM %s WHERE %s=%s"), TABLE_CHECK_LIST_TIME, FIELD_GRUPPO, ::SQLStringFormat(m_Gruppo).c_str() ), &res);

    for ( int i = 0; i < res.GetSize(); i++ )
    {
        m_Items.push_back(res.Row(i));
        m_Orari->Append( res.Row(i).Col(FIELD_NOME).GetStringValue() );
    }
}
