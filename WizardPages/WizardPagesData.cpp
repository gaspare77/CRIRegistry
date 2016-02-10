#include "WizardPagesData.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesData::WizardPagesData( wxWizard* parent, CService* service ):
Data( (wxWindow*)parent ), m_pService( service )
{
	m_pPage = new WizardPagesEquipaggio( parent, service );
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesData::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_ORA_INIZIO:
		::ValidateTextCtrlFormatTime( m_OraInizio );
		break;

	case ID_ORA_PARTENZA:
		::ValidateTextCtrlFormatTime( m_OraPartenza );
		break;

	case ID_ORA_ARRIVO_TARGET:
		::ValidateTextCtrlFormatTime( m_OraArrivoTarget );
		break;

	case ID_ORA_PARTENZA_TARGET:
		::ValidateTextCtrlFormatTime( m_OraPartenzaTarget );
		break;

	case ID_ORA_ARRIVO:
		::ValidateTextCtrlFormatTime( m_OraArrivo );
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
void WizardPagesData::OnEnter()
{
	// Data
	if ( m_pService->GetField(FIELD_DATA).GetDateTimeValue() == EmptyDate )
	{
		m_Data->SetDate( wxDateTime::Now() );
	}
	else
	{
		m_Data->SetDate( m_pService->GetField(FIELD_DATA).GetDateTimeValue() );
	}

	// Ora Inizio
	if ( m_pService->GetField(FIELD_ORAINIZIO).GetDateTimeValue() != EmptyDate )
	{
		m_OraInizio->SetValue( m_pService->GetField(FIELD_ORAINIZIO).GetDateTimeValue().Format(FORMAT_TIME) );
	}
	else
	{
		m_OraInizio->Clear();
	}

	// Ora Partenza
	if ( m_pService->GetField(FIELD_ORAPARTENZA).GetDateTimeValue() != EmptyDate )
	{
		m_OraPartenza->SetValue( m_pService->GetField(FIELD_ORAPARTENZA).GetDateTimeValue().Format(FORMAT_TIME) );
	}
	else
	{
		m_OraPartenza->Clear();
	}
	
	// Ora Arrivo Target
	if ( m_pService->GetField(FIELD_ORAARRIVOTARGET).GetDateTimeValue() != EmptyDate )
	{
		m_OraArrivoTarget->SetValue( m_pService->GetField(FIELD_ORAARRIVOTARGET).GetDateTimeValue().Format(FORMAT_TIME) );
	}
	else
	{
		m_OraArrivoTarget->Clear();
	}

	// Ora Partenza Target
	if ( m_pService->GetField(FIELD_ORAPARTENZATARGET).GetDateTimeValue() != EmptyDate )
	{
		m_OraPartenzaTarget->SetValue( m_pService->GetField(FIELD_ORAPARTENZATARGET).GetDateTimeValue().Format(FORMAT_TIME) );
	}
	else
	{
		m_OraPartenzaTarget->Clear();
	}

	// Ora Arrivo
	if ( m_pService->GetField(FIELD_ORAARRIVO).GetDateTimeValue() != EmptyDate )
	{
		m_OraArrivo->SetValue( m_pService->GetField(FIELD_ORAARRIVO).GetDateTimeValue().Format(FORMAT_TIME) );
	}
	else
	{
		m_OraArrivo->Clear();
	}

	// Ora Fine
	if ( m_pService->GetField(FIELD_ORAFINE).GetDateTimeValue() != EmptyDate )
	{
		m_OraFine->SetValue( m_pService->GetField(FIELD_ORAFINE).GetDateTimeValue().Format(FORMAT_TIME) );
	}
	else
	{
		m_OraFine->Clear();
	}

	m_OraInizio->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesData::OnExit()
{
	wxDateTime dtStart = ::ConcatDateTime( m_Data->GetDate(), m_OraInizio->GetValue() ); 
	wxDateTime dtDeparture = ::ConcatDateTime( m_Data->GetDate(), m_OraPartenza->GetValue() );
	wxDateTime dtTagertArrival = ::ConcatDateTime( m_Data->GetDate(), m_OraArrivoTarget->GetValue() );
	wxDateTime dtTargetDeparture = ::ConcatDateTime( m_Data->GetDate(), m_OraPartenzaTarget->GetValue() );
	wxDateTime dtArrival = ::ConcatDateTime( m_Data->GetDate(), m_OraArrivo->GetValue() );
    wxDateTime dtEnd = ::ConcatDateTime( m_Data->GetDate(), m_OraFine->GetValue() );

	if ( dtStart > dtDeparture && dtDeparture != EmptyDate )
	{
		dtDeparture += wxDateSpan::Day();
	}
	if ( dtStart > dtTagertArrival && dtTagertArrival != EmptyDate )
	{
		dtTagertArrival += wxDateSpan::Day();
	}
	if ( dtStart > dtTargetDeparture && dtTargetDeparture != EmptyDate )
	{
		dtTargetDeparture += wxDateSpan::Day();
	}
	if ( dtStart > dtArrival && dtArrival != EmptyDate )
	{
		dtArrival += wxDateSpan::Day();
	}
	if ( dtStart > dtEnd && dtEnd != EmptyDate )
	{
		dtEnd += wxDateSpan::Day();
	}

	m_pService->GetField(FIELD_DATA) = m_Data->GetDate();
	m_pService->GetField(FIELD_ORAINIZIO) = dtStart;
	m_pService->GetField(FIELD_ORAPARTENZA) = dtDeparture;
	m_pService->GetField(FIELD_ORAARRIVOTARGET) = dtTagertArrival;
	m_pService->GetField(FIELD_ORAPARTENZATARGET) = dtTargetDeparture;
	m_pService->GetField(FIELD_ORAARRIVO) = dtArrival;
	m_pService->GetField(FIELD_ORAFINE) = dtEnd;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesData::GoNext()
{
	wxDateTime dtStart = m_pService->GetField(FIELD_ORAINIZIO).GetDateTimeValue(); 
	wxDateTime dtDeparture = m_pService->GetField(FIELD_ORAPARTENZA).GetDateTimeValue();
	wxDateTime dtTagertArrival = m_pService->GetField(FIELD_ORAARRIVOTARGET).GetDateTimeValue();
	wxDateTime dtTargetDeparture = m_pService->GetField(FIELD_ORAPARTENZATARGET).GetDateTimeValue();
	wxDateTime dtArrival = m_pService->GetField(FIELD_ORAARRIVO).GetDateTimeValue();
    wxDateTime dtEnd = m_pService->GetField(FIELD_ORAFINE).GetDateTimeValue();

    if (dtStart == EmptyDate )
	{
		WARNING_MESSAGE( _("Non e' stata inserita l'ora di inizio") );
		m_OraInizio->SetFocus();
		return false;
	}

    if ( dtStart > wxDateTime::Now() )
    {
		WARNING_MESSAGE( _("La data selezionata non e' corretta") );
		m_Data->SetFocus();
		return false;
    }

    bool  bcond1 = ( dtDeparture == EmptyDate ) && ( dtTagertArrival == EmptyDate ) && ( dtTargetDeparture == EmptyDate ) && ( dtArrival == EmptyDate );
    bool  bcond2 = ( dtDeparture != EmptyDate ) && ( dtTagertArrival == EmptyDate ) && ( dtTargetDeparture == EmptyDate ) && ( dtArrival == EmptyDate );
    bool  bcond3 = ( dtDeparture != EmptyDate ) && ( dtTagertArrival != EmptyDate ) && ( dtTargetDeparture == EmptyDate ) && ( dtArrival == EmptyDate );
    bool  bcond4 = ( dtDeparture != EmptyDate ) && ( dtTagertArrival != EmptyDate ) && ( dtTargetDeparture != EmptyDate ) && ( dtArrival != EmptyDate );
    if ( !( bcond1 || bcond2 || bcond3 || bcond4 ) )
	{
		WARNING_MESSAGE( _("Non sono stati inseriti tutti gli orari") );
		if ( dtDeparture == EmptyDate )
        {
            m_OraPartenza->SetFocus();
        }
        else if ( dtTagertArrival == EmptyDate )
        {
            m_OraArrivoTarget->SetFocus();
        }
        else if ( dtTargetDeparture == EmptyDate )
        {
            m_OraPartenzaTarget->SetFocus();
        }
        else if ( dtArrival == EmptyDate )
        {
            m_OraArrivo->SetFocus();
        }
		return false;
	}

    if (( dtDeparture != EmptyDate ) && (( dtDeparture - dtStart ) > wxTimeSpan::Hours(12) ))
    {
		WARNING_MESSAGE( _("L'ora di partenza non e' corretta") );
		m_OraPartenza->SetFocus();
		return false;
    }

    if (( dtTagertArrival != EmptyDate ) && ( dtTagertArrival < dtDeparture ))
    {
		WARNING_MESSAGE( _("L'ora di arrivo al target non e' corretta") );
		m_OraArrivoTarget->SetFocus();
		return false;
    }

    if (( dtTargetDeparture != EmptyDate ) && ( dtTargetDeparture < dtTagertArrival ))
    {
		WARNING_MESSAGE( _("L'ora di partenza dal target non e' corretta") );
		m_OraPartenzaTarget->SetFocus();
		return false;
    }

    if (( dtArrival != EmptyDate ) && ( dtArrival < dtTargetDeparture ))
    {
		WARNING_MESSAGE( _("L'ora di arrivo non e' corretta") );
		m_OraArrivo->SetFocus();
		return false;
    }

    if (( dtEnd != EmptyDate ) && ( dtArrival != EmptyDate ) && ( dtEnd < dtArrival ))
    {
		WARNING_MESSAGE( _("L'ora di fine servizio non e' corretta") );
		m_OraFine->SetFocus();
		return false;
    }
    
    return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesData::GoPrev()
{
	return true;
}
