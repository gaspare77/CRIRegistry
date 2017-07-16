#include "CRIRegistryCAPListDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCAPListDlg::CRIRegistryCAPListDlg( wxWindow* parent ):
CAPListDlg( parent )
{
    SetIcon( wxICON(EditIcon) ); 

	m_Fields.clear();

	m_FieldsList->InsertColumn( 0, _("CAP"), wxLIST_FORMAT_CENTER );
	m_FieldsList->InsertColumn( 1, _("Comune"), wxLIST_FORMAT_LEFT );
	m_FieldsList->InsertColumn( 2, _("Provincia"), wxLIST_FORMAT_CENTER );

    m_FieldsList->SetColumnWidth( 0, 65 );
    m_FieldsList->SetColumnWidth( 1, 320 );
    m_FieldsList->SetColumnWidth( 2, 65 );

    // Lock the Table
    UsersManager::Instance()->LockTable( TABLE_CAP_LIST );

    wxString query = wxString::Format( _T("SELECT * FROM %s ORDER BY %s"), TABLE_CAP_LIST, FIELD_COMUNE );
	dbResultSet res;
	if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		for ( size_t i = 0; i < res.GetSize(); i++ )
		{
			dbClass f( res.Row(i), TABLE_CAP_LIST, FIELD_ID );
			m_Fields.push_back(f);
		}
	}

    UpdateList();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCAPListDlg::~CRIRegistryCAPListDlg()
{
    // Unlock the Table
    UsersManager::Instance()->UnlockTable( TABLE_CAP_LIST );
}
    
/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPListDlg::OnAdd( wxCommandEvent& event )
{
    CRIRegistryCAPDlg dlg( this );
    if ( dlg.ShowModal() == wxID_OK )
    {
	    dbClass f( TABLE_CAP_LIST, FIELD_ID );
	    f.Add( FIELD_CAP,  dlg.GetCap() );
	    f.Add( FIELD_COMUNE, dlg.GetComune() );
	    f.Add( FIELD_PROVINCIA, dlg.GetProvincia() );
		if ( !f.InsertIntoDb() )
		{
			WARNING_MESSAGE(_("Non e' stato possibile inserire il CAP nel database"));
			return;
		}
		m_Fields.push_back( f );
        UpdateList();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPListDlg::OnModify( wxCommandEvent& event )
{
	std::vector<dbClass>::iterator it = GetFieldSelected();
    if ( it != m_Fields.end() )
    {
        CRIRegistryCAPDlg dlg( this, it->GetField(FIELD_CAP).GetStringValue(), it->GetField(FIELD_COMUNE).GetStringValue(), it->GetField(FIELD_PROVINCIA).GetStringValue() );
        if ( dlg.ShowModal() == wxID_OK )
        {
            it->GetField(FIELD_CAP) = dlg.GetCap();
            it->GetField(FIELD_COMUNE) = dlg.GetComune();
            it->GetField(FIELD_PROVINCIA) = dlg.GetProvincia();
		    if ( !it->UpdateIntoDb() )
		    {
			    WARNING_MESSAGE(_("Non e' stato possibile modificare il CAP nel database"));
			    return;
		    }
            UpdateList();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPListDlg::OnDel( wxCommandEvent& event )
{
	std::vector<dbClass>::iterator it = GetFieldSelected();
    if ( it != m_Fields.end() )
    {
        if ( QUESTION_MESSAGE( _("Sei sicuro di voler cancellare il CAP:\n %s - %s (%s)?"), it->GetField(FIELD_CAP).GetCharValue(), it->GetField(FIELD_COMUNE).GetCharValue(), it->GetField(FIELD_PROVINCIA).GetCharValue() ) == wxYES )
        {
		    if ( !it->RemoveFromDb() )
		    {
			    WARNING_MESSAGE(_("Non e' stato possibile eliminare il CAP dal database"));
			    return;
		    }
            m_Fields.erase( it );
            UpdateList();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPListDlg::OnOk( wxCommandEvent& event )
{
    m_FieldSelect = GetFieldSelected();
    if ( m_FieldSelect == m_Fields.end() )
    {
        ERROR_MESSAGE(_("Non e' stato selezionato nessun CAP"));
        return;
    }

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPListDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCAPListDlg::UpdateList()
{
	m_FieldsList->DeleteAllItems();
    long i = 0;
    for ( std::vector<dbClass>::iterator it = m_Fields.begin(); it != m_Fields.end(); ++it )
    {
        dbClass f(*it);

        m_FieldsList->InsertItem( i, f[FIELD_CAP].GetStringValue() );
        m_FieldsList->SetItem( i, 1, f[FIELD_COMUNE].GetStringValue() );
        m_FieldsList->SetItem( i, 2, f[FIELD_PROVINCIA].GetStringValue() );
        m_FieldsList->SetItemPtrData( i, f.GetId() );

        if ( i % 2 )
        {
            m_FieldsList->SetItemBackgroundColour( i, wxColor(240,240,240) );
        }

        i++;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
long CRIRegistryCAPListDlg::GetItemSelected()
{
    for ( long i = 0; i < m_FieldsList->GetItemCount(); i++ )
    {
		if ( m_FieldsList->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
			return i;
        }
    }

	return -1;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
std::vector<dbClass>::iterator CRIRegistryCAPListDlg::GetFieldSelected()
{
	std::vector<dbClass>::iterator it = m_Fields.end();
	long item = GetItemSelected();
	if ( item < 0 )
	{
		return it;
	}

	for ( it = m_Fields.begin(); it != m_Fields.end(); ++it )
	{
		if ( m_FieldsList->GetItemData( item ) == it->GetId() )
		{
			break;
		}
	}

    return it;
}
