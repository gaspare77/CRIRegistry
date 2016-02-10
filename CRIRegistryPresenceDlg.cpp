#include "CRIRegistryPresenceDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistryPresenceDlg::CRIRegistryPresenceDlg( wxWindow* parent, const CPresence& presence, eMode mode ):
PresenceDlg( parent ), m_Presence( presence ), m_Mode( mode )
{
    SetIcon( wxICON(PresenceIcon) );

    wxString query;
	wxArrayString azsList;

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_GRUPPO, TABLE_GRUPPI );
	azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Gruppo->Append( azsList );
    m_Gruppo->SetStringSelection( CRIRegistryOptions::Instance()->GetDefaultGruppo() );

    query = wxString::Format( _T("SELECT DISTINCT(%s) FROM %s ORDER BY %s"), FIELD_COGNOME, TABLE_REGISTROPRESENZE, FIELD_COGNOME );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Cognome->Append( azsList );

	query = wxString::Format( _T("SELECT DISTINCT(%s) FROM %s ORDER BY %s"), FIELD_NOME, TABLE_REGISTROPRESENZE, FIELD_NOME );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Nome->Append( azsList );

    UpdateCtrl();

    m_Gruppo->Enable( m_Mode != READ_ONLY );
	m_Data->Enable( m_Mode != READ_ONLY );
    m_OraIngresso->Enable( m_Mode != READ_ONLY );
    m_OraUscita->Enable( m_Mode == MODIFY );
    m_Cognome->Enable( m_Mode != READ_ONLY );
    m_Nome->Enable( m_Mode != READ_ONLY );
    m_Note->Enable( m_Mode != READ_ONLY );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryPresenceDlg::OnClose( wxCloseEvent& event )
{
	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryPresenceDlg::OnWrite( wxKeyEvent& event )
{
	int k = event.GetKeyCode();
    if ( k == 8 || k == 9 || k == 13 || k == 27 || k == 127 || k >= 300 )
	{
		event.Skip();
        return;
	}

    switch ( event.GetId() )
	{
    case ID_COGNOME:
		ComboBoxChangeWithSearch( m_Cognome );
        break;

    case ID_NOME:
		ComboBoxChangeWithSearch( m_Nome );
        break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryPresenceDlg::OnExitCtrl( wxFocusEvent& event )
{
    wxString s;

    switch ( event.GetId() )
    {
    case ID_GRUPPO:
        break;

    case ID_DATA:
        break;

    case ID_ORA_INGRESSO:
		ValidateTextCtrlFormatTime( m_OraIngresso );
        break;

    case ID_ORA_USCITA:
		ValidateTextCtrlFormatTime( m_OraUscita );
        break;

	case ID_COGNOME:
		m_Cognome->SetValue( m_Cognome->GetValue().Upper() );
        break;

	case ID_NOME:
		m_Nome->SetValue( m_Nome->GetValue().Upper() );
        break;

	case ID_NOTE:
		m_Note->SetValue( m_Note->GetValue().Upper() );
        break;
    }

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryPresenceDlg::OnOk( wxCommandEvent& event )
{
    if ( !UpdateData() )
    {
        return;
    }

	EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryPresenceDlg::OnCancel( wxCommandEvent& event )
{
	EndModal( wxID_CANCEL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryPresenceDlg::UpdateCtrl()
{
    m_Gruppo->SetStringSelection( m_Presence[FIELD_GRUPPO].GetStringValue() );
    m_Cognome->SetValue( m_Presence[FIELD_COGNOME].GetStringValue() );
    m_Nome->SetValue( m_Presence[FIELD_NOME].GetStringValue() );

	if ( m_Presence[FIELD_DATAORAINIZIO].GetDateTimeValue() == EmptyDate )
    {
        m_Data->SetValue( wxDateTime::Now() );
        m_OraIngresso->SetValue( _T("") );
    }
    else
    {
        m_Data->SetValue( m_Presence[FIELD_DATAORAINIZIO].GetDateTimeValue() );
        m_OraIngresso->SetValue( m_Presence[FIELD_DATAORAINIZIO].GetDateTimeValue().Format(FORMAT_TIME) );
    }

    if ( m_Presence[FIELD_DATAORAFINE].GetDateTimeValue() == EmptyDate )
    {
        m_OraUscita->SetValue( _T("") );
    }
    else
    {
        m_OraUscita->SetValue( m_Presence[FIELD_DATAORAFINE].GetDateTimeValue().Format(FORMAT_TIME) );
    }

    m_Note->SetValue( m_Presence[FIELD_NOTE].GetStringValue() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryPresenceDlg::UpdateData()
{
	// Gruppo
	if ( m_Gruppo->GetSelection() >= 0 )
	{
        m_Presence[FIELD_GRUPPO] = m_Gruppo->GetStringSelection();
	}
	else
	{
        ERROR_MESSAGE( _("Il gruppo non e' stato inserito") );
		m_Gruppo->SetFocus();
		return false;
	}

    // Cognome
	if ( m_Cognome->GetValue().Len() > 0 )
	{
		m_Presence[FIELD_COGNOME] = m_Cognome->GetValue();
	}
	else
	{
        ERROR_MESSAGE( _("Il cognome non e' stato inserito") );
		m_Cognome->SetFocus();
		return false;
	}

	// Nome
	if ( m_Nome->GetValue().Len() > 0 )
	{
		m_Presence[FIELD_NOME] = m_Nome->GetValue();
	}
	else
	{
        ERROR_MESSAGE( _("Il nome non e' stato inserito") );
		m_Nome->SetFocus();
		return false;
	}

    wxDateTime start,end;
    int hours = 0, minutes = 0;

	// Ora Ingresso
	if ( GetHourMin( m_OraIngresso->GetValue(), &hours, &minutes ) )
    {
        start = m_Data->GetValue().SetHour( hours ).SetMinute( minutes );
	    m_Presence[FIELD_DATAORAINIZIO] = start;
    }
    else
    {
	    m_Presence[FIELD_DATAORAINIZIO] = EmptyDate;
    }

	// Ora Uscita
	if ( GetHourMin( m_OraUscita->GetValue(), &hours, &minutes ) )
	{
		end = m_Data->GetValue().SetHour( hours ).SetMinute( minutes );
		if ( start >= end )
		{
			end += wxDateSpan::Day();
		}
		m_Presence[FIELD_DATAORAFINE] = end;
	}
	else
	{
		m_Presence[FIELD_DATAORAFINE] = EmptyDate;
	}

    // Note
    m_Presence[FIELD_NOTE] = m_Note->GetValue();
	return true;
}
