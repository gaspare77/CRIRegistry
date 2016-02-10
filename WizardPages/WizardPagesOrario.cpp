#include "WizardPagesOrario.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesOrario::WizardPagesOrario( wxWizard* parent, CService* service ):
Orario( (wxWindow*)parent ), m_pService( service )
{
	m_pPage = new WizardPagesEquipaggio( parent, service );
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesOrario::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
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
void WizardPagesOrario::OnEnter()
{
	if ( m_pService->GetField(FIELD_ORAINIZIO).GetDateTimeValue() != EmptyDate )
	{
		m_OraInizio->SetValue( m_pService->GetField(FIELD_ORAINIZIO).GetDateTimeValue().Format(FORMAT_TIME) );
	}
	else
	{
		m_OraInizio->Clear();
	}

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
void WizardPagesOrario::OnExit()
{
	int h, m;
	wxDateTime dtStart, dtEnd;

	if ( !m_OraInizio->GetValue().IsEmpty() && ::ValidateTextCtrlFormatTime( m_OraInizio ) && ::GetHourMin( m_OraInizio->GetValue(), &h, &m ) )
	{
		dtStart = m_pService->GetField(FIELD_DATA).GetDateTimeValue();
		dtStart.SetHour( h ).SetMinute( m );
	}
	else
	{
		dtStart = EmptyDate;
	}

	if ( !m_OraFine->GetValue().IsEmpty() && ::ValidateTextCtrlFormatTime( m_OraFine ) && ::GetHourMin( m_OraFine->GetValue(), &h, &m ) )
	{
		dtEnd = m_pService->GetField(FIELD_DATA).GetDateTimeValue();
		dtEnd.SetHour( h ).SetMinute( m );
		if ( dtStart >= dtEnd )
		{
			dtEnd += wxDateSpan::Day();
		}
	}
	else
	{
		dtEnd = EmptyDate;
	}

	m_pService->GetField(FIELD_ORAINIZIO) = dtStart;
	m_pService->GetField(FIELD_ORAFINE) = dtEnd;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesOrario::GoNext()
{
	if ( m_pService->GetField(FIELD_ORAINIZIO).GetDateTimeValue() == EmptyDate )
	{
		WARNING_MESSAGE( _("Non e' stata inserita l'ora di inizio") );
		m_OraInizio->SetFocus();
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesOrario::GoPrev()
{
	return true;
}
