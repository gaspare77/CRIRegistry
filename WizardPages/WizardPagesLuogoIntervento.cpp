#include "WizardPagesLuogoIntervento.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesLuogoIntervento::WizardPagesLuogoIntervento( wxWindow* parent, CService* service ):
LuogoIntervento( (wxWindow*)parent ), m_pService( service )
{
	m_pPage1 = new WizardPagesPazientiTrasportati( parent, service );
	m_pPage1->SetPrevPage( this );

	m_pPage2 = new WizardPagesLuogoTrasportato( parent, service );
	m_pPage2->SetPrevPage( this );

	SetNextPage( m_pPage1 );

	wxString query = wxString::Format( _T("SELECT %s FROM %s ORDER BY %s"), FIELD_NOME, TABLE_OSPEDALI, FIELD_NOME );
    m_Ospedale->Append( dbSingleton::Instance()->SQLGetColArray( query ) );

	m_Abitazione_Checked->SetValue( false );
	m_Ospedale_Checked->SetValue( false );
	m_AltroLuogo_Checked->SetValue( false );

	m_Ospedale->Enable( false );
	m_Luogo->Enable( false );
	m_CAP->Enable( false );
	m_Citta->Enable( false );
	m_Provincia->Enable( false );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoIntervento::OnCheck( wxCommandEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_ABITAZIONE_CHECKED:
	case ID_OSPEDALE_CHECKED:
	case ID_ALTRO_LUOGO_CHECKED:
		if ( m_Abitazione_Checked->GetValue() && event.GetId() == ID_ABITAZIONE_CHECKED )
		{
			m_Ospedale_Checked->SetValue( false );
			m_Ospedale->Enable( false );
			m_Ospedale->SetSelection( -1 );
			m_AltroLuogo_Checked->SetValue( false );
			m_Luogo->Enable( false );
			m_Luogo->Clear();
			m_CAP->Enable( false );
			m_CAP->Clear();
			m_Citta->Enable( false );
			m_Citta->Clear();
			m_Provincia->Enable( false );
			m_Provincia->Clear();
		}
		else if ( m_Ospedale_Checked->GetValue() && event.GetId() == ID_OSPEDALE_CHECKED )
		{
			m_Abitazione_Checked->SetValue( false );
			m_Ospedale->Enable( true );
			m_AltroLuogo_Checked->SetValue( false );
			m_Luogo->Enable( false );
			m_Luogo->Clear();
			m_CAP->Enable( false );
			m_CAP->Clear();
			m_Citta->Enable( false );
			m_Citta->Clear();
			m_Provincia->Enable( false );
			m_Provincia->Clear();
		}
		else if ( m_AltroLuogo_Checked->GetValue() && event.GetId() == ID_ALTRO_LUOGO_CHECKED )
		{
			m_Abitazione_Checked->SetValue( false );
			m_Ospedale_Checked->SetValue( false );
			m_Ospedale->Enable( false );
			m_Ospedale->SetSelection( -1 );
			m_Luogo->Enable( true );
			m_CAP->Enable( true );
			m_Citta->Enable( true );
			m_Provincia->Enable( true );
		}
		else
		{
			m_Abitazione_Checked->SetValue( false );
			m_Ospedale_Checked->SetValue( false );
			m_Ospedale->Enable( false );
			m_Ospedale->SetSelection( -1 );
			m_AltroLuogo_Checked->SetValue( false );
			m_Luogo->Enable( false );
			m_Luogo->Clear();
			m_CAP->Enable( false );
			m_CAP->Clear();
			m_Citta->Enable( false );
			m_Citta->Clear();
			m_Provincia->Enable( false );
			m_Provincia->Clear();
		}
		break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoIntervento::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
		case ID_LUOGO:
			m_Luogo->SetValue( m_Luogo->GetValue().MakeUpper() );
			break;
		case ID_CAP:
			m_CAP->SetValue( m_CAP->GetValue().MakeUpper() );
			break;
		case ID_CITTA:
			m_Citta->SetValue( m_Citta->GetValue().MakeUpper() );
			break;
		case ID_PROVINCIA:
			m_Provincia->SetValue( m_Provincia->GetValue().MakeUpper() );
			break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoIntervento::OnEnter()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoIntervento::OnExit()
{
    if ( m_pService->GetField(FIELD_RICHIESTO).GetStringValue() == szRequestedBy[REQUESTED_BY_PARENT] )
	{
		SetNextPage( m_pPage2 );
	}
	else
	{
		SetNextPage( m_pPage1 );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesLuogoIntervento::GoNext()
{
	if ( m_Abitazione_Checked->GetValue() )
	{
		m_pService->GetField(FIELD_INTERVENTO_LUOGO) = szServicePlace[SERVICEPLACE_HOME];
		m_pService->GetField(FIELD_INTERVENTO_CAP) = m_pService->GetField(FIELD_RICHIESTO_CAP).GetStringValue();
		m_pService->GetField(FIELD_INTERVENTO_CITTA) = m_pService->GetField(FIELD_RICHIESTO_CITTA).GetStringValue();
		m_pService->GetField(FIELD_INTERVENTO_PROVINCIA) = m_pService->GetField(FIELD_RICHIESTO_PROVINCIA).GetStringValue();
	}
	else if ( m_Ospedale_Checked->GetValue() )
	{
		CHospital h;
		if ( !h.LoadFromDb( m_Ospedale->GetStringSelection() ) )
		{
			m_Ospedale->SetFocus();
			return false;
		}

		m_pService->GetField(FIELD_INTERVENTO_LUOGO) = wxString::Format( _T("%s%s"), szServicePlace[SERVICEPLACE_HOSPITAL], h.GetNome().c_str() );
		m_pService->GetField(FIELD_INTERVENTO_CAP) = h.GetCAP();
		m_pService->GetField(FIELD_INTERVENTO_CITTA) = h.GetCitta();
		m_pService->GetField(FIELD_INTERVENTO_PROVINCIA) = h.GetProvincia();
	}
	else if ( m_AltroLuogo_Checked->GetValue() )
	{
		if ( m_Luogo->GetValue().IsEmpty() )
		{
			WARNING_MESSAGE( _("Non e' stato inserito il luogo d'intervento") );
			m_Luogo->SetFocus();
			return false;
		}
		m_pService->GetField(FIELD_INTERVENTO_LUOGO) = m_Luogo->GetValue();
		m_pService->GetField(FIELD_INTERVENTO_CAP) = m_CAP->GetValue();
		m_pService->GetField(FIELD_INTERVENTO_CITTA) = m_Citta->GetValue();
		m_pService->GetField(FIELD_INTERVENTO_PROVINCIA) = m_Provincia->GetValue();
	}
	else
	{
		WARNING_MESSAGE( _("Non e' stato selezionato nessun luogo d'intervento") );
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesLuogoIntervento::GoPrev()
{
	return true;
}