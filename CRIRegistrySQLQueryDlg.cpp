#include "CRIRegistrySQLQueryDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistrySQLQueryDlg::CRIRegistrySQLQueryDlg( wxWindow* parent ):
SQLQueryDlg( parent )
{
	SetIcon(wxICON(SQLQueryIcon));

    m_Grid->DeleteCols( 0,  m_Grid->GetNumberCols() );
    m_Grid->DeleteRows( 0,  m_Grid->GetNumberRows() );
	m_Grid->SetRowLabelSize( 0 );

    // Update the Db Language
    UpdateLocal();
    
	SelectQueries();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistrySQLQueryDlg::SelectQueries()
{
	dbResultSet res;
	wxString query = wxString::Format( _T("SELECT * FROM %s"), TABLE_QUERY_LIST );
	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		return false;
	}

	m_mQueries.clear();
	for ( size_t i = 0; i < res.GetSize(); i++ )
	{
		dbClass d( res.Row(i), TABLE_QUERY_LIST, FIELD_ID );
		m_mQueries[res.Row(i).Col(FIELD_NOME).GetStringValue()] = d;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistrySQLQueryDlg::UpdateLocal()
{
	dbResultSet res;
	wxString query = wxString::Format( _T("set lc_time_names = 'it_it'") );
	if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistrySQLQueryDlg::AddQuery( const wxString& name, const wxString& query )
{
	dbClass d( TABLE_QUERY_LIST, FIELD_ID );
	d.Add( FIELD_NOME, name );
	d.Add( FIELD_QUERY, query );

    if ( !d.InsertIntoDb() )
	{
		return false;
	}

	m_mQueries[name] = d;

	return true;	
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistrySQLQueryDlg::DelQuery( const wxString& name )
{
	std::map<wxString,dbClass>::iterator it = m_mQueries.find( name );
	if ( it == m_mQueries.end() )
	{
		return false;
	}

	if ( !it->second.RemoveFromDb() )
	{
		return false;
	}

	m_mQueries.erase( it );
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
wxArrayString CRIRegistrySQLQueryDlg::GetQueriesList()
{
	std::map<wxString,dbClass>::iterator it;
	wxArrayString a;
	for ( it = m_mQueries.begin(); it != m_mQueries.end(); ++it )
	{
		a.Add( it->first );
	}

	return a;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySQLQueryDlg::OnExport( wxCommandEvent& event )
{
	if ( m_Grid->GetNumberRows() == 0 )
	{
		return;
	}

	wxString szFileName = ::wxSaveFileSelector( _T(""), _T("csv"), _T(""), this );
	if ( szFileName.IsEmpty() )
	{
		return;
	}

	if ( ::wxFileExists( szFileName ) && QUESTION_MESSAGE( _("Il file %s esiste gia'.\nLo vuoi sovrascrivere?"), szFileName.c_str() ) != wxYES )
	{
		return;
	}

	wxFFile file( szFileName, "w" );
	if ( !file.IsOpened() )
	{
		return;
	}

	int row, col;

	for ( col = 0; col < m_Grid->GetNumberCols(); col++ )
	{
		file.Write( m_Grid->GetColLabelValue( col ) );
		if ( col < m_Grid->GetNumberCols() - 1 )
		{
			file.Write( _T(";") );
		}
	}
	file.Write( _T("\n") );
	
	for ( row = 0; row < m_Grid->GetNumberRows(); row++ )
	{
		for ( col = 0; col < m_Grid->GetNumberCols(); col++ )
		{
            wxString s =  m_Grid->GetCellValue( row, col );
            s.Replace( _T("\n"), _T(". ") );
			file.Write( s );
			if ( col < m_Grid->GetNumberCols() - 1 )
			{
				file.Write( _T(";") );
			}
		}

		file.Write( _T("\n") );
	}

	file.Close();

	INFO_MESSAGE( _("Il file %s e' stato esportato"), szFileName.c_str() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySQLQueryDlg::OnQueryAdd( wxCommandEvent& event )
{
	if ( m_SQLQuery->GetValue().IsEmpty() )
	{
		return;
	}

	wxString name = ::wxGetTextFromUser( _("Inserire il nome da assegnare alla query"), GetTitle(), wxEmptyString, this );
	if ( name.IsEmpty() )
	{
		return;
	}

	std::map<wxString,dbClass>::iterator it = m_mQueries.find( name );
	if (( it != m_mQueries.end() ) && ( QUESTION_MESSAGE( _("Esiste gia' una query salvata con lo stesso nome.\nLa vuoi sovrascrivere?") ) != wxYES ))
	{
		return;
	}
	
	AddQuery( name, ::SQLQueryFormat( m_SQLQuery->GetValue().Trim(false).Trim(true) ) );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySQLQueryDlg::OnQueryDel( wxCommandEvent& event )
{
	if ( m_mQueries.empty() )
	{
		return;
	}

	wxString name = ::wxGetSingleChoice( _("Selezionare la query da rimuovere"), GetTitle(), GetQueriesList(), this );
	if ( name.IsEmpty() || ( QUESTION_MESSAGE( _("Sei sicuro di voler rimuovere la query %s?"), name.c_str() ) != wxYES ))
	{
		return;
	}

	DelQuery( name );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySQLQueryDlg::OnOpenQuery( wxCommandEvent& event )
{
	if ( m_mQueries.empty() )
	{
		return;
	}

	wxString name = ::wxGetSingleChoice( _("Selezionare la query da eseguire"), GetTitle(), GetQueriesList(), this );
	if ( name.IsEmpty() )
	{
		return;
	}

	m_SQLQuery->Clear();
	m_SQLQuery->AppendText( m_mQueries[name][FIELD_QUERY].GetStringValue() );
	m_SQLQuery->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySQLQueryDlg::OnQueryExecute( wxCommandEvent& event )
{
	if ( m_SQLQuery->GetValue().IsEmpty() )
	{
        m_Grid->DeleteCols( 0,  m_Grid->GetNumberCols() );
        m_Grid->DeleteRows( 0,  m_Grid->GetNumberRows() );
		return;
	}

    dbResultSet res;   
    wxString query = ::SQLQueryFormat( m_SQLQuery->GetValue() );
    //INFO_MESSAGE( "%s", query.c_str() );
    if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        m_Grid->DeleteCols( 0,  m_Grid->GetNumberCols() );
        m_Grid->DeleteRows( 0,  m_Grid->GetNumberRows() );

        m_Grid->AppendRows( res.GetSize() );
		m_Grid->AppendCols( res.Row().GetSize() );
    
		for ( unsigned int row = 0; row < res.GetSize(); row++ )
        {
            for ( unsigned col = 0; col < res.Row(row).GetSize(); col++ )
            {
				if ( row == 0 )
				{
					m_Grid->SetColLabelValue( col, res.Row(row).Col(col).GetName() );
				}
                m_Grid->SetCellValue( row, col, res.Row(row).Col(col).GetStringValue() );
				m_Grid->SetReadOnly( row, col );
            }
        }

		m_Grid->AutoSizeColumns();
		m_Grid->Refresh();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySQLQueryDlg::OnCancel( wxCommandEvent& event )
{
	Close();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySQLQueryDlg::OnWrite( wxKeyEvent& event )
{
	event.Skip();
}

