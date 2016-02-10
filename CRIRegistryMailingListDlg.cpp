#include "CRIRegistryMailingListDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryMailingListDlg::CRIRegistryMailingListDlg( wxWindow* parent ):
MailingListDlg( parent )
{
    SetIcon( wxICON(EditIcon) ); 

	m_Fields.clear();

	m_FieldsList->InsertColumn( 0, _("Nominativo"), wxLIST_FORMAT_LEFT );
	m_FieldsList->InsertColumn( 1, _("EMail"), wxLIST_FORMAT_LEFT );

    m_FieldsList->SetColumnWidth( 0, 245 );
    m_FieldsList->SetColumnWidth( 1, 315 );

    // Lock the Table
    UsersManager::Instance()->LockTable( TABLE_MAILING_LIST );

    wxString query = wxString::Format( _T("SELECT * FROM %s ORDER BY %s"), TABLE_MAILING_LIST, FIELD_NOME );
	dbResultSet res;
	if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		for ( size_t i = 0; i < res.GetSize(); i++ )
		{
			dbClass f( res.Row(i), TABLE_MAILING_LIST, FIELD_ID );
			m_Fields.push_back(f);
		}
	}

    UpdateList();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryMailingListDlg::~CRIRegistryMailingListDlg()
{
    // Unlock the Table
    UsersManager::Instance()->UnlockTable( TABLE_MAILING_LIST );
}
    
/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryMailingListDlg::OnAdd( wxCommandEvent& event )
{
    CRIRegistryMailAddressDlg dlg( this );
    if ( dlg.ShowModal() == wxID_OK )
    {
	    dbClass f( TABLE_MAILING_LIST, FIELD_ID );
	    f.Add( FIELD_NOME,  dlg.GetName() );
	    f.Add( FIELD_EMAIL, dlg.GetEMail() );
		if ( !f.InsertIntoDb() )
		{
			WARNING_MESSAGE(_("Non e' stato possibile inserire l'indirizzo email nel database"));
			return;
		}
		m_Fields.push_back( f );
        UpdateList();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryMailingListDlg::OnModify( wxCommandEvent& event )
{
	std::vector<dbClass>::iterator it = GetFieldSelected();
    if ( it != m_Fields.end() )
    {
        CRIRegistryMailAddressDlg dlg( this, it->GetField(FIELD_NOME).GetStringValue(), it->GetField(FIELD_EMAIL).GetStringValue() );
        if ( dlg.ShowModal() == wxID_OK )
        {
            it->GetField(FIELD_NOME) = dlg.GetName();
            it->GetField(FIELD_EMAIL) = dlg.GetEMail();
		    if ( !it->UpdateIntoDb() )
		    {
			    WARNING_MESSAGE(_("Non e' stato possibile modificare l'indirizzo email nel database"));
			    return;
		    }
            UpdateList();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryMailingListDlg::OnDel( wxCommandEvent& event )
{
	std::vector<dbClass>::iterator it = GetFieldSelected();
    if ( it != m_Fields.end() )
    {
        if ( QUESTION_MESSAGE( _("Sei sicuro di voler cancellare %s?"), it->GetField(FIELD_NOME).GetCharValue() ) == wxYES )
        {
		    if ( !it->RemoveFromDb() )
		    {
			    WARNING_MESSAGE(_("Non e' stato possibile eliminare l'indirizzo email dal database"));
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
void CRIRegistryMailingListDlg::OnOk( wxCommandEvent& event )
{
//    INFO_MESSAGE( "%d, %d", m_FieldsList->GetColumnWidth(0), m_FieldsList->GetColumnWidth(1) );

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryMailingListDlg::UpdateList()
{
	m_FieldsList->DeleteAllItems();
    long i = 0;
    for ( std::vector<dbClass>::iterator it = m_Fields.begin(); it != m_Fields.end(); ++it )
    {
        dbClass f(*it);

        m_FieldsList->InsertItem( i, f[FIELD_NOME].GetStringValue() );
        m_FieldsList->SetItem( i, 1, f[FIELD_EMAIL].GetStringValue() );
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
long CRIRegistryMailingListDlg::GetItemSelected()
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
std::vector<dbClass>::iterator CRIRegistryMailingListDlg::GetFieldSelected()
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
