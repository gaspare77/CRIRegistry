#include "CRIRegistryAddFieldsDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryAddFieldsDlg::CRIRegistryAddFieldsDlg( wxWindow* parent, const wxString& table, const wxString& id, const wxString& field, const wxString& condition ):
AddFieldsDlg( parent ), m_ItemToAdd( table, id )
{
    SetIcon( wxICON(EditIcon) ); 

	m_szTable = table;
	m_szIdFieldName = id;
	m_szFieldName = field;
	m_Fields.clear();
	m_FieldsList->Clear();

	m_ItemToAdd.Add( m_szFieldName, WDT_STRING );

    // Lock the Table
    UsersManager::Instance()->LockTable( m_szTable );
	
	wxString query;
    if (condition.IsEmpty())
    {
        query = _T("SELECT * FROM ") + m_szTable;
    }
    else
    {
        query = _T("SELECT * FROM ") + m_szTable + _T(" WHERE ") + condition;
    }
	dbResultSet res;
	if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		for ( size_t i = 0; i < res.GetSize(); i++ )
		{
			dbClass f( res.Row(i), m_szTable, m_szIdFieldName );
			m_Fields.push_back(f);
			m_FieldsList->Append( f[m_szFieldName].GetStringValue() );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryAddFieldsDlg::~CRIRegistryAddFieldsDlg()
{
    // Unlock the Table
    UsersManager::Instance()->UnlockTable( m_szTable );
}
    
/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryAddFieldsDlg::OnAdd( wxCommandEvent& event )
{
    dbClass f(m_ItemToAdd);
	wxTextEntryDialog dlg( this, _("Inserire il valore del campo da aggiungere"), GetTitle() );
	dlg.SetValue( wxEmptyString );
	if ( dlg.ShowModal() == wxID_OK )
	{
		f[m_szFieldName] = dlg.GetValue().MakeUpper();
		if ( !f.InsertIntoDb() )
		{
			WARNING_MESSAGE(_("Non e' stato possibile inserire il campo nel database"));
			return;
		}
		m_Fields.push_back( f );
		m_FieldsList->Append( dlg.GetValue().MakeUpper() );
		m_FieldsList->SetSelection( m_FieldsList->GetCount()-1 );
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryAddFieldsDlg::OnModify( wxCommandEvent& event )
{
	int i = m_FieldsList->GetSelection();
	std::vector<dbClass>::iterator it = GetFieldSelected();
	if ( i >= 0 && it != m_Fields.end() )
	{
		dbClass f(*it);
		wxTextEntryDialog dlg( this, wxString::Format( _("Modificare il campo %s in"), f[m_szFieldName].GetCharValue() ), GetTitle() );
		dlg.SetValue( f[m_szFieldName].GetStringValue() );
		if ( dlg.ShowModal() == wxID_OK )
		{
			f[m_szFieldName] = dlg.GetValue().MakeUpper();
			if ( !f.UpdateIntoDb() )
			{
				WARNING_MESSAGE(_("Non e' stato possibile modificare il campo nel database"));
				return;
			}
			*it = f;
			m_FieldsList->SetString( i, dlg.GetValue().MakeUpper() );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryAddFieldsDlg::OnDel( wxCommandEvent& event )
{
	int i = m_FieldsList->GetSelection();
	std::vector<dbClass>::iterator it = GetFieldSelected();
	if ( i >= 0 && it != m_Fields.end() && QUESTION_MESSAGE( _("Sei sicuro di voler cancellare il campo selezionato?") ) == wxYES )
	{
		if ( !it->RemoveFromDb() )
		{
			WARNING_MESSAGE(_("Non e' stato possibile cancellare il campo dal database"));
			return;
		}
		m_Fields.erase( it );
		m_FieldsList->Delete( i );
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryAddFieldsDlg::OnOk( wxCommandEvent& event )
{
    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
std::vector<dbClass>::iterator CRIRegistryAddFieldsDlg::GetFieldSelected()
{
	std::vector<dbClass>::iterator it;
	for ( it = m_Fields.begin(); it != m_Fields.end(); ++it )
	{
		dbClass f(*it);
		if ( f[m_szFieldName].GetStringValue() == m_FieldsList->GetStringSelection() )
		{
			break;
		}
	}

	return it;
}

