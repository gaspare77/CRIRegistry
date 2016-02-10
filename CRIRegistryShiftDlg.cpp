#include "CRIRegistryShiftDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistryShiftDlg::CRIRegistryShiftDlg( wxWindow* parent, const CShift& shift, eMode mode ) :
ShiftDlg( parent ), m_Shift( shift ), m_Mode( mode )
{
    SetIcon( wxICON(ShiftIcon) );

    wxArrayString aszQualification( CHAR_LIST_SIZE(szQualification), szQualification );
    m_Qualifica->Append( aszQualification );

    wxArrayString aszQualificationStatus( CHAR_LIST_SIZE(szQualificationStatus), szQualificationStatus );
    m_QualificaStato->Append( aszQualificationStatus );

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
	s = m_Shift[FIELD_TIPO].GetStringValue();
	if ( !s.IsEmpty() && m_TipoServizio->FindString( s ) == wxNOT_FOUND )
	{
		m_TipoServizio->Append( s );
	}
	
	query = wxString::Format( _T("SELECT %s FROM %s WHERE %s = 0"), FIELD_CODMEZZO, TABLE_PARCOMACCHINE, FIELD_NONOPERATIVA );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Mezzo->Append( _T("") );
    m_Mezzo->Append( azsList );
	s = m_Shift[FIELD_CODMEZZO].GetStringValue();
	if ( !s.IsEmpty() && m_Mezzo->FindString( s ) == wxNOT_FOUND )
	{
		m_Mezzo->Append( s );
	}

	query = wxString::Format( _T("SELECT DISTINCT(%s) FROM %s ORDER BY %s"), FIELD_COGNOME, TABLE_REGISTROTURNI, FIELD_COGNOME );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Cognome->Append( azsList );

	query = wxString::Format( _T("SELECT DISTINCT(%s) FROM %s ORDER BY %s"), FIELD_NOME, TABLE_REGISTROTURNI, FIELD_NOME );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Nome->Append( azsList );

    UpdateCtrl();

    m_Gruppo->Enable( m_Mode != READ_ONLY );
	m_Data->Enable( m_Mode != READ_ONLY );
    m_OraInizio->Enable( m_Mode != READ_ONLY );
    m_OraFine->Enable( m_Mode != READ_ONLY );
    m_TipoServizio->Enable( m_Mode != READ_ONLY );
    m_Mezzo->Enable( m_Mode != READ_ONLY );
    m_Cognome->Enable( m_Mode != READ_ONLY );
    m_Nome->Enable( m_Mode != READ_ONLY );
    m_Qualifica->Enable( m_Mode != READ_ONLY );
    m_QualificaStato->Enable( m_Mode != READ_ONLY );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryShiftDlg::OnClose( wxCloseEvent& event )
{
	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryShiftDlg::OnChoice( wxCommandEvent& event )
{
    switch ( event.GetId() )
    {
    case ID_MEZZO:
        break;

    case ID_TIPO_SERVIZIO:
        break;

    case ID_QUALIFICA:
        break;

    case ID_QUALIFICA_STATO:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryShiftDlg::OnWrite( wxKeyEvent& event )
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
		::ComboBoxChangeWithSearch( m_Cognome );
        break;

    case ID_NOME:
		::ComboBoxChangeWithSearch( m_Nome );
        break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryShiftDlg::OnExitCtrl( wxFocusEvent& event )
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

	case ID_COGNOME:
		m_Cognome->SetValue( m_Cognome->GetValue().Upper() );
        break;

	case ID_NOME:
		m_Nome->SetValue( m_Nome->GetValue().Upper() );
        break;
    }

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryShiftDlg::OnOk( wxCommandEvent& event )
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
void CRIRegistryShiftDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryShiftDlg::UpdateCtrl()
{
    m_Gruppo->SetStringSelection( m_Shift[FIELD_GRUPPO].GetStringValue() );
    
    if ( m_Shift[FIELD_DATAORAINIZIO].GetDateTimeValue() == EmptyDate )
    {
        m_Data->SetValue( wxDateTime::Now() );
        m_OraInizio->SetValue( _T("") );
    }
    else
    {
        m_Data->SetValue( m_Shift[FIELD_DATAORAINIZIO].GetDateTimeValue() );
        m_OraInizio->SetValue( m_Shift[FIELD_DATAORAINIZIO].GetDateTimeValue().Format(FORMAT_TIME) );
    }

    if ( m_Shift[FIELD_DATAORAFINE].GetDateTimeValue() == EmptyDate )
    {
        m_OraFine->SetValue( _T("") );
    }
    else
    {
        m_OraFine->SetValue( m_Shift[FIELD_DATAORAFINE].GetDateTimeValue().Format(FORMAT_TIME) );
    }

    m_TipoServizio->SetStringSelection( m_Shift[FIELD_TIPO].GetStringValue() );
    m_Mezzo->SetStringSelection( m_Shift[FIELD_CODMEZZO].GetStringValue() );
    m_Cognome->SetValue( m_Shift[FIELD_COGNOME].GetStringValue() );
    m_Nome->SetValue( m_Shift[FIELD_NOME].GetStringValue() );
    m_Qualifica->SetStringSelection( m_Shift[FIELD_QUALIFICA].GetStringValue() );
    m_QualificaStato->SetStringSelection( m_Shift[FIELD_QUALIFICASTATO].GetStringValue() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryShiftDlg::UpdateData()
{
    wxDateTime start,end;
    int hours = 0, minutes = 0;

	// Gruppo
	if ( m_Gruppo->GetSelection() >= 0 )
	{
		m_Shift[FIELD_GRUPPO] = m_Gruppo->GetStringSelection();
	}
	else
	{
        ERROR_MESSAGE( _("Il gruppo non e' stato inserito") );
		m_Gruppo->SetFocus();
		return false;
	}

	// Ora Inizio turno
	if ( GetHourMin( m_OraInizio->GetValue(), &hours, &minutes ) )
    {
        start = m_Data->GetValue().SetHour( hours ).SetMinute( minutes );
	    m_Shift[FIELD_DATAORAINIZIO] = start;
    }
    else
    {
        ERROR_MESSAGE( _("L'ora di inizio turno non e' stata inserita") );
        m_OraInizio->SetFocus();
        return false;
    }

	// Ora Fine turno
    if ( GetHourMin( m_OraFine->GetValue(), &hours, &minutes ) )
    {
        end = m_Data->GetValue().SetHour( hours ).SetMinute( minutes );
        if ( start >= end )
        {
            end += wxDateSpan::Day();
        }
	    m_Shift[FIELD_DATAORAFINE] = end;
    }
    else
    {
        ERROR_MESSAGE( _("L'ora di fine turno non e' stata inserita") );
        m_OraFine->SetFocus();
        return false;
    }

	// Tipo di Servizio
	if ( m_TipoServizio->GetSelection() > 0 )
	{
		m_Shift[FIELD_TIPO] = m_TipoServizio->GetStringSelection();
	}
	else
	{
        ERROR_MESSAGE( _("Il tipo di servizio non e' stato inserito") );
		m_TipoServizio->SetFocus();
		return false;
	}
	
	// Mezzo
	m_Shift[FIELD_CODMEZZO] = m_Mezzo->GetStringSelection();

	// Cognome
	if ( m_Cognome->GetValue().Len() > 0 )
	{
		m_Shift[FIELD_COGNOME] = m_Cognome->GetValue();
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
		m_Shift[FIELD_NOME] = m_Nome->GetValue();
	}
	else
	{
        ERROR_MESSAGE( _("Il nome non e' stato inserito") );
		m_Nome->SetFocus();
		return false;
	}

	// Qualifica
	if ( m_Qualifica->GetSelection() > 0 && m_QualificaStato->GetSelection() > 0 )
	{
		m_Shift[FIELD_QUALIFICA] = m_Qualifica->GetStringSelection();
	    m_Shift[FIELD_QUALIFICASTATO] = m_QualificaStato->GetStringSelection();
	}
	else
	{
        ERROR_MESSAGE( _("La qualifica non e' stata inserita") );
		if ( m_Qualifica->GetSelection() > 0 )
		{
			m_QualificaStato->SetFocus();
		}
		else
		{
			m_Qualifica->SetFocus();
		}
		return false;
	}

    return true;
}
