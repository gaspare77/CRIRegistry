/////////////////////////////////////////////////////////////////////////////
// 
//
/////////////////////////////////////////////////////////////////////////////
#include "CRIRegistryCheckListAddItemDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCheckListAddItemDlg::CRIRegistryCheckListAddItemDlg( wxWindow* parent, const wxString& gruppo, const wxString& type, const wxString& item, const wxString& position ):
CheckListAddItemDlg( parent ), m_Gruppo(gruppo)
{
    SetIcon( wxICON(EditIcon) );
    
    SelectHours();
    SelectPositions();

    wxString query;
    dbResultSet res;

    query = wxString::Format(_T("SELECT %s FROM %s WHERE %s=%s"), 
        FIELD_ID,
        TABLE_CHECK_LIST_TYPE,
        FIELD_TIPO, ::SQLStringFormat(type));

    dbSingleton::Instance()->SQLQuery(query, &res);
    m_TypeId = res.Row(0).Col(0).GetIntValue();

    if ( item.IsEmpty() )
    {
        for ( int i = 0; i < m_ListaOrari->GetCount(); i++ )
        {
            m_ListaOrari->Check(i);
        }
        m_Posizione->SetStringSelection( position );
        m_Testo->SetFocus();
    }
    else
    {
	    query = wxString::Format( _T("SELECT * FROM %s WHERE %s=%s AND %s=%s AND %s_%s=%d"), 
            TABLE_CHECK_LIST_ITEM,
            FIELD_NOME, ::SQLStringFormat(item).c_str(),
            FIELD_GRUPPO, ::SQLStringFormat(m_Gruppo).c_str(),
            TABLE_CHECK_LIST_TYPE, FIELD_ID, m_TypeId 
            );	
        dbSingleton::Instance()->SQLQuery( query, &res );

        m_Testo->SetValue( item );
        std::vector<dbRow>::iterator it;
        // Select the Position
        it = GetPositionById( res.Row(0).Col(wxString::Format(_T("%s_%s"), TABLE_CHECK_LIST_POSITION, FIELD_ID)).GetIntValue() );
        if ( it != m_Positions.end() )
        {
            m_Posizione->SetStringSelection( it->Col(FIELD_POSIZIONE).GetStringValue() );
        }
        // Select the Hours
        for ( int i = 0; i < res.GetSize(); i++ )
        {
            it = GetHourById( res.Row(i).Col(wxString::Format(_T("%s_%s"), TABLE_CHECK_LIST_TIME, FIELD_ID)).GetIntValue() );
            if ( it != m_Hours.end() )
            {
                for ( int i = 0; i < m_ListaOrari->GetCount(); i++ )
                {
                    if ( m_ListaOrari->GetString(i) == it->Col(FIELD_NOME).GetStringValue() )
                    {
                        m_ListaOrari->Check(i);
                    }
                }
            }
            m_Items.push_back( res.Row(i) );
        }
        m_bpButton_Ok->SetFocus();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListAddItemDlg::OnChoice( wxCommandEvent& event )
{
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListAddItemDlg::OnEditPosition( wxCommandEvent& event )
{
    wxString condition = wxString::Format(_T("%s=%s"), FIELD_GRUPPO, SQLStringFormat(m_Gruppo));
    CRIRegistryAddFieldsDlg dlg(this, TABLE_CHECK_LIST_POSITION, FIELD_ID, FIELD_POSIZIONE, condition);
    dlg.SetTitle(_("Posizioni Check List"));
    dlg.FieldToAdd()->Add(FIELD_GRUPPO, m_Gruppo);
    dlg.ShowModal();

    wxString PositionSelected = m_Posizione->GetStringSelection();
    SelectPositions();
    if ( !PositionSelected.IsEmpty() )
    {
        m_Posizione->SetStringSelection(PositionSelected);
    }

}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListAddItemDlg::OnExitCtrl( wxFocusEvent& event )
{
    switch (event.GetId())
    {
    case ID_TESTO:
        m_Testo->SetValue(m_Testo->GetValue().Upper());
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListAddItemDlg::OnOk( wxCommandEvent& event )
{
    if ( m_Testo->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE(_("Non e' stato inserito nessun testo") );
        m_Testo->SetFocus();
        return;
    }

    // Check if the same text already exist into the db
    if ( m_Items.size() == 0 )
    {
        dbResultSet res;
        wxString query;
        query = wxString::Format(_T("SELECT %s FROM %s WHERE %s=%s AND %s=%s AND %s_%s=%d"), 
            FIELD_ID,
            TABLE_CHECK_LIST_ITEM,
            FIELD_NOME, ::SQLStringFormat(m_Testo->GetValue()),
            FIELD_GRUPPO, ::SQLStringFormat(m_Gruppo),
            TABLE_CHECK_LIST_TYPE, FIELD_ID, m_TypeId
            );
        dbSingleton::Instance()->SQLQuery(query, &res);    
        if ( res.GetSize() > 0 )
        {
            WARNING_MESSAGE(_("Il testo inserito esiste gia' nel database") );
            m_Testo->SetFocus();
            return;
        }
    }

    if ( m_Posizione->GetStringSelection().IsEmpty() )
    {
        WARNING_MESSAGE(_("Non e' stata inserita nessuna posizione") );
        m_Posizione->SetFocus();
        return;
    }
    
    bool bAnyHourSelected = true;
    for ( int i = 0; i < m_ListaOrari->GetCount(); i++ )
    {
        if ( m_ListaOrari->IsChecked(i) )
        {
            bAnyHourSelected = false;
        }
    }
    if ( bAnyHourSelected )
    {
        WARNING_MESSAGE(_("Non e' stato selezionato nessun orario") );
        m_ListaOrari->SetFocus();
        return;
    }
    
    EndModal(wxID_OK);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListAddItemDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
bool CRIRegistryCheckListAddItemDlg::InsertIntoDb()
{
    std::vector<dbRow>::iterator p = GetPositionSelect(m_Posizione->GetStringSelection());
    if ( p == m_Positions.end() )
    {
        ERROR_MESSAGE(wxString::Format(_("Non e' stato possile trovare la posizione %s nel database"), m_Posizione->GetStringSelection().c_str()));
        return false;
    }

    for ( int i = 0; i < m_ListaOrari->GetCount(); i++ )
    {
        if ( m_ListaOrari->IsChecked(i) )
        {
            std::vector<dbRow>::iterator h = GetHourSelect(m_ListaOrari->GetString(i));
            if ( h == m_Hours.end() )
            {
                ERROR_MESSAGE(wxString::Format(_("Non e' stato possile trovare l'orario %s nel database"), m_ListaOrari->GetString(i).c_str()));
                return false;
            }
            wxString query = wxString::Format(_T("INSERT INTO %s(%s,%s,%s_%s,%s_%s,%s_%s) VALUES(%s,%s,%d,%d,%d)"), 
                TABLE_CHECK_LIST_ITEM,
                FIELD_NOME, 
                FIELD_GRUPPO,
                TABLE_CHECK_LIST_POSITION, FIELD_ID,
                TABLE_CHECK_LIST_TIME, FIELD_ID,
                TABLE_CHECK_LIST_TYPE, FIELD_ID,
                ::SQLStringFormat(m_Testo->GetValue()),
                ::SQLStringFormat(m_Gruppo),
                p->Col(FIELD_ID).GetIntValue(),
                h->Col(FIELD_ID).GetIntValue(),
                m_TypeId
                );
            if ( !dbSingleton::Instance()->SQLQuery(query) )
            {
                ERROR_MESSAGE(wxString::Format(_("Non e' stato possile inserire la voce:\n%s\n%s\n%s"), m_Testo->GetValue().c_str(), m_ListaOrari->GetString(i).c_str(), m_Posizione->GetStringSelection().c_str()));
                return false;
            }
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
//
bool CRIRegistryCheckListAddItemDlg::UpdateDb()
{
    std::vector<dbRow>::iterator p = GetPositionSelect(m_Posizione->GetStringSelection());
    if ( p == m_Positions.end() )
    {
        ERROR_MESSAGE(wxString::Format(_("Non e' stato possile trovare la posizione %s nel database"), m_Posizione->GetStringSelection().c_str()));
        return false;
    }

    for ( int i = 0; i < m_ListaOrari->GetCount(); i++ )
    {
        wxString query = wxEmptyString;
        std::vector<dbRow>::iterator item = GetItemByHour(m_ListaOrari->GetString(i));
        if ( m_ListaOrari->IsChecked(i) )
        {
            if ( item == m_Items.end() )
            {
                // Insert item
                std::vector<dbRow>::iterator h = GetHourSelect(m_ListaOrari->GetString(i));
                if ( h == m_Hours.end() )
                {
                    ERROR_MESSAGE(wxString::Format(_("Non e' stato possile trovare l'orario %s nel database"), m_ListaOrari->GetString(i).c_str()));
                    return false;
                }
                query = wxString::Format(_T("INSERT INTO %s(%s,%s,%s_%s,%s_%s,%s_%s) VALUES(%s,%s,%d,%d,%d)"), 
                    TABLE_CHECK_LIST_ITEM,
                    FIELD_NOME, 
                    FIELD_GRUPPO,
                    TABLE_CHECK_LIST_POSITION, FIELD_ID,
                    TABLE_CHECK_LIST_TIME, FIELD_ID,
                    TABLE_CHECK_LIST_TYPE, FIELD_ID,
                    ::SQLStringFormat(m_Testo->GetValue()),
                    ::SQLStringFormat(m_Gruppo),
                    p->Col(FIELD_ID).GetIntValue(),
                    h->Col(FIELD_ID).GetIntValue(),
                    m_TypeId
                    );
            }
            else
            {
                // Update item
                item->Col(FIELD_NOME) = m_Testo->GetValue();
                item->Col(wxString::Format(_T("%s_%s"), TABLE_CHECK_LIST_POSITION, FIELD_ID)) = p->Col(FIELD_ID).GetIntValue();
                query = wxString::Format(_T("UPDATE %s SET %s WHERE %s=%d"),
                    TABLE_CHECK_LIST_ITEM,
                    item->GetSQLSet().c_str(),
                    FIELD_ID, item->Col(FIELD_ID).GetIntValue()
                    );
            }
        }
        else if ( item != m_Items.end() )
        {
            // Delete item
            query = wxString::Format(_T("DELETE FROM %s WHERE %s=%d"),
                TABLE_CHECK_LIST_ITEM,
                FIELD_ID,
                item->Col(FIELD_ID).GetIntValue()
                );
        }

        if ( !query.IsEmpty() )
        {
            if ( !dbSingleton::Instance()->SQLQuery(query) )
            {
                ERROR_MESSAGE(wxString::Format(_("Non e' stato possile modificare la voce:\n%s\n%s\n%s"), m_Testo->GetValue().c_str(), m_ListaOrari->GetString(i).c_str(), m_Posizione->GetStringSelection().c_str()));
                return false;
            }
        }
    }
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListAddItemDlg::SelectPositions()
{
    m_Posizione->Clear();
    m_Positions.clear();

	wxString query = wxString::Format( _T("SELECT * FROM %s WHERE %s=%s"), 
                                        TABLE_CHECK_LIST_POSITION,
                                        FIELD_GRUPPO, ::SQLStringFormat(m_Gruppo).c_str() 
                                        );	
    dbResultSet res;
    dbSingleton::Instance()->SQLQuery( query, &res );
    for ( int i = 0; i < res.GetSize(); i++ )
    {
        m_Positions.push_back( res.Row(i) );
    }
    m_Posizione->Append( GetPositions() );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListAddItemDlg::SelectHours()
{
    m_ListaOrari->Clear();
    m_Hours.clear();

	wxString query = wxString::Format( _T("SELECT * FROM %s WHERE %s=%s"), 
                                        TABLE_CHECK_LIST_TIME,
                                        FIELD_GRUPPO, ::SQLStringFormat(m_Gruppo).c_str() 
                                        );
    dbResultSet res;
    dbSingleton::Instance()->SQLQuery( query, &res );
    for ( int i = 0; i < res.GetSize(); i++ )
    {
        m_Hours.push_back( res.Row(i) );
    }
    m_ListaOrari->Append( GetHours() );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
wxArrayString CRIRegistryCheckListAddItemDlg::GetHours()
{
    wxArrayString ar;
    for ( std::vector<dbRow>::iterator it = m_Hours.begin(); it != m_Hours.end(); it++ )
    {
        ar.Add( it->Col(FIELD_NOME).GetStringValue() );
    }
    return ar;
}

/////////////////////////////////////////////////////////////////////////////
// 
//
wxArrayString CRIRegistryCheckListAddItemDlg::GetPositions()
{
    wxArrayString ar;
    for ( std::vector<dbRow>::iterator it = m_Positions.begin(); it != m_Positions.end(); it++ )
    {
        ar.Add( it->Col(FIELD_POSIZIONE).GetStringValue() );
    }
    return ar;
}

/////////////////////////////////////////////////////////////////////////////
// 
//
std::vector<dbRow>::iterator CRIRegistryCheckListAddItemDlg::GetHourSelect( const wxString& name )
{
    for ( std::vector<dbRow>::iterator it = m_Hours.begin(); it != m_Hours.end(); it++ )
    {
        if ( it->Col(FIELD_NOME).GetStringValue() == name )
        {
            return it;
        }
    }

    return m_Hours.end();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
std::vector<dbRow>::iterator CRIRegistryCheckListAddItemDlg::GetHourById( int id )
{
    for ( std::vector<dbRow>::iterator it = m_Hours.begin(); it != m_Hours.end(); it++ )
    {
        if ( it->Col(FIELD_ID).GetIntValue() == id )
        {
            return it;
        }
    }

    return m_Hours.end();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
std::vector<dbRow>::iterator CRIRegistryCheckListAddItemDlg::GetPositionSelect( const wxString& name )
{
    for ( std::vector<dbRow>::iterator it = m_Positions.begin(); it != m_Positions.end(); it++ )
    {
        if ( it->Col(FIELD_POSIZIONE).GetStringValue() == name )
        {
            return it;
        }
    }

    return m_Positions.end();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
std::vector<dbRow>::iterator CRIRegistryCheckListAddItemDlg::GetPositionById( int id )
{
    for ( std::vector<dbRow>::iterator it = m_Positions.begin(); it != m_Positions.end(); it++ )
    {
        if ( it->Col(FIELD_ID).GetIntValue() == id )
        {
            return it;
        }
    }

    return m_Positions.end();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
std::vector<dbRow>::iterator CRIRegistryCheckListAddItemDlg::GetItemByHour( const wxString& hour )
{
    std::vector<dbRow>::iterator h = GetHourSelect(hour);
    if ( h != m_Hours.end() )
    {
        for ( std::vector<dbRow>::iterator it = m_Items.begin(); it != m_Items.end(); it++ )
        {
            if ( it->Col(wxString::Format(_T("%s_%s"), TABLE_CHECK_LIST_TIME, FIELD_ID)).GetIntValue() == h->Col(FIELD_ID).GetIntValue() )
            {
                return it;
            }
        }
    }

    return m_Items.end();
}
