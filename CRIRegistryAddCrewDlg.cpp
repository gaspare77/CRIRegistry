#include "CRIRegistryAddCrewDlg.h"

/////////////////////////////////////////////////////////////////////////////
//
//
CRIRegistryAddCrewDlg::CRIRegistryAddCrewDlg( wxWindow* parent ):
AddCrewDlg( parent )
{
    SetIcon( wxICON(CrewIcon) );

    wxString query, s;
	wxArrayString azsList;

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_GRUPPO, TABLE_GRUPPI );
	azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Gruppo->Append( azsList );
    m_Gruppo->SetStringSelection( CRIRegistryOptions::Instance()->GetDefaultGruppo() );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLOGIATURNI );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_TipoServizio->Append( _T("") );
    m_TipoServizio->Append( azsList );
    m_TipoServizio->Append( OTHER_SELECTION );
	
	query = wxString::Format( _T("SELECT %s FROM %s WHERE %s = 0"), FIELD_CODMEZZO, TABLE_PARCOMACCHINE, FIELD_NONOPERATIVA );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Mezzo->Append( _T("") );
    m_Mezzo->Append( azsList );

	m_Equipaggio->InsertColumn( 0, _("Cognome"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 1, _("Nome"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 2, _("Qualifica"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 3, _("Qualifica Stato"), wxLIST_FORMAT_CENTER );

	int w = m_Equipaggio->GetSize().GetWidth() - 30;
    m_Equipaggio->SetColumnWidth( 0, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 1, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 2, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 3, GET_PERC(25., w) );	
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::OnExitCtrl( wxFocusEvent& event )
{
    switch ( event.GetId() )
    {
    case ID_DATA:
        break;

    case ID_ORA_INIZIO:
		::ValidateTextCtrlFormatTime( m_OraInizio );
        break;

    case ID_ORA_FINE:
		::ValidateTextCtrlFormatTime( m_OraFine );
        break;
    }

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::OnChoice( wxCommandEvent& event )
{
    switch ( event.GetId() )
    {
    case ID_GRUPPO:
        break;

    case ID_MEZZO:
        break;

    case ID_TIPO_SERVIZIO:
        break;
    }

    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::OnAddCrew( wxCommandEvent& event )
{
	CRIRegistryCrewDlg dlg( this );
	if ( dlg.ShowModal() == wxID_OK )
	{
        CShift s;
        s[FIELD_GRUPPO] = m_Gruppo->GetStringSelection();
        s[FIELD_COGNOME] = dlg.GetCrew().GetField(FIELD_COGNOME).GetStringValue();
        s[FIELD_NOME] = dlg.GetCrew().GetField(FIELD_NOME).GetStringValue();
        s[FIELD_QUALIFICA] = dlg.GetCrew().GetField(FIELD_QUALIFICA).GetStringValue();
        s[FIELD_QUALIFICASTATO] = dlg.GetCrew().GetField(FIELD_QUALIFICASTATO).GetStringValue();
        s.SetId( m_vCrew.size() + 1 );
		m_vCrew.push_back( s );
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::OnModifyCrew( wxCommandEvent& event )
{
	std::vector<CShift>::iterator it = GetCrewSelected();
	if ( it == m_vCrew.end() )
	{
		return;
	}

    CServiceCrew crew;
    crew[FIELD_COGNOME] = it->GetField(FIELD_COGNOME).GetStringValue();
    crew[FIELD_NOME] = it->GetField(FIELD_NOME).GetStringValue();
    crew[FIELD_QUALIFICA] = it->GetField(FIELD_QUALIFICA).GetStringValue();
    crew[FIELD_QUALIFICASTATO] = it->GetField(FIELD_QUALIFICASTATO).GetStringValue();
	CRIRegistryCrewDlg dlg( this, crew );
	if ( dlg.ShowModal() == wxID_OK )
	{
		it->GetField(FIELD_COGNOME) = dlg.GetCrew().GetField(FIELD_COGNOME).GetStringValue();
		it->GetField(FIELD_NOME) = dlg.GetCrew().GetField(FIELD_NOME).GetStringValue();
		it->GetField(FIELD_QUALIFICA) = dlg.GetCrew().GetField(FIELD_QUALIFICA).GetStringValue();
		it->GetField(FIELD_QUALIFICASTATO) = dlg.GetCrew().GetField(FIELD_QUALIFICASTATO).GetStringValue();
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::OnDelCrew( wxCommandEvent& event )
{
	std::vector<CShift>::iterator it = GetCrewSelected();
	if ( it == m_vCrew.end() )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare %s %s?"), 
		it->GetField(FIELD_COGNOME).GetCharValue(), 
		it->GetField(FIELD_NOME).GetCharValue() ) == wxYES )
	{
		m_vCrew.erase( it );
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::OnOk( wxCommandEvent& event )
{
    int hours = 0, minutes = 0;
    wxDateTime dtStart, dtEnd;
    wxString szGruppo, szType, szMezzo;

	// Gruppo
	if ( m_Gruppo->GetSelection() >= 0 )
	{
		szGruppo = m_Gruppo->GetStringSelection();
	}
	else
	{
        ERROR_MESSAGE( _("Il gruppo non e' stato inserito") );
		m_Gruppo->SetFocus();
		return;
	}

    // Ora Inizio turno
	if ( GetHourMin( m_OraInizio->GetValue(), &hours, &minutes ) )
    {
        dtStart = m_Data->GetValue().SetHour( hours ).SetMinute( minutes );
    }
    else
    {
        ERROR_MESSAGE( _("L'ora di inizio turno non e' stata inserita") );
        m_OraInizio->SetFocus();
        return;
    }

	// Ora Fine turno
    if ( GetHourMin( m_OraFine->GetValue(), &hours, &minutes ) )
    {
        dtEnd = m_Data->GetValue().SetHour( hours ).SetMinute( minutes );
        if ( dtStart >= dtEnd )
        {
            dtEnd += wxDateSpan::Day();
        }
    }
    else
    {
        ERROR_MESSAGE( _("L'ora di fine turno non e' stata inserita") );
        m_OraFine->SetFocus();
        return;
    }

	// Tipo di Servizio
	if ( m_TipoServizio->GetSelection() > 0 )
	{
		szType = m_TipoServizio->GetStringSelection();
	}
	else
	{
        ERROR_MESSAGE( _("Il tipo di servizio non e' stato inserito") );
		m_TipoServizio->SetFocus();
		return;
	}
	
	// Mezzo
	if ( m_Mezzo->GetSelection() > 0 )
	{
		szMezzo = m_Mezzo->GetStringSelection();
	}
	else
	{
        ERROR_MESSAGE( _("Il mezzo non e' stato inserito") );
		m_Mezzo->SetFocus();
		return;
	}

    for ( std::vector<CShift>::iterator it = m_vCrew.begin(); it != m_vCrew.end(); ++it )
    {
        it->GetField(FIELD_GRUPPO) = szGruppo;
        it->GetField(FIELD_DATAORAINIZIO) = dtStart;
        it->GetField(FIELD_DATAORAFINE) = dtEnd;	
        it->GetField(FIELD_TIPO) = szType;
        it->GetField(FIELD_CODMEZZO) = szMezzo;
    }
    
    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::UpdateCrewsListCtrl()
{
	m_Equipaggio->DeleteAllItems();

	std::vector<CShift>::iterator it;
	for ( it = m_vCrew.begin(); it != m_vCrew.end(); ++it )
	{
        long i = m_Equipaggio->GetItemCount();
        m_Equipaggio->InsertItem( i, it->GetField(FIELD_COGNOME).GetStringValue() );
        m_Equipaggio->SetItem( i, 1, it->GetField(FIELD_NOME).GetStringValue() );
        m_Equipaggio->SetItem( i, 2, it->GetField(FIELD_QUALIFICA).GetStringValue() );
		m_Equipaggio->SetItem( i, 3, it->GetField(FIELD_QUALIFICASTATO).GetStringValue() );
		m_Equipaggio->SetItemPtrData( i, it->GetId() );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
long CRIRegistryAddCrewDlg::GetCrewItemSelected()
{
    for ( long i = 0; i < m_Equipaggio->GetItemCount(); i++ )
    {
		if ( m_Equipaggio->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
			return i;
        }
    }

	return -1;
}

/////////////////////////////////////////////////////////////////////////////
//
//
std::vector<CShift>::iterator CRIRegistryAddCrewDlg::GetCrewSelected()
{
	std::vector<CShift>::iterator it = m_vCrew.end();
	long item = GetCrewItemSelected();
	if ( item < 0 )
	{
	    return it;
	}

	for ( it = m_vCrew.begin(); it != m_vCrew.end(); ++it )
	{
		if ( m_Equipaggio->GetItemData( item ) == it->GetId() )
		{
			break;
		}
	}

    return it;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddCrewDlg::SetCrew( std::vector<CShift> crew ) 
{ 
    m_vCrew = crew;         
    UpdateCrewsListCtrl(); 
}
