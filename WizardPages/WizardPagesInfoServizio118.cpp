#include "WizardPagesInfoServizio118.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesInfoServizio118::WizardPagesInfoServizio118( wxWindow* parent, CService* service  ):
InfoServizio118( (wxWindow*)parent ), m_pService( service )
{
    m_pPage1 = new WizardPagesPazientiTrasportati118( parent, service ); 
    m_pPage1->SetPrevPage( this );

	m_pPage2 = new WizardPagesUtilizzoMezzo( parent, service ); 
	m_pPage2->SetPrevPage( this );

	SetNextPage( m_pPage1 );

	wxString query;
	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_GRAVITA );
	m_CodeGravityList = dbSingleton::Instance()->SQLGetColArray( query );
	m_CodGravita->SetProperty( TYPE_CODE_GRAVITY, m_CodeGravityList );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_PATOLOGIA_PRESUNTA );
	m_CodePatology1List = dbSingleton::Instance()->SQLGetColArray( query );
    m_CodPatologia->SetProperty( TYPE_CODE_ARRIVAL, m_CodePatology1List );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_LUOGO );
	m_CodePlaceList = dbSingleton::Instance()->SQLGetColArray( query );
    m_CodLuogo->SetProperty( TYPE_CODE_PLACE, m_CodePlaceList );

	m_GiaTrasportatoMezzo->Show( false );
	m_NonCompletato->Show( false );
    m_label_AnnullatoOra->Show( false );
    m_label_AnnullatoLuogo->Show( false );
    m_AnnullatoOra->Show( false );
    m_AnnullatoLuogo->Show( false );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesInfoServizio118::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
		case ID_COD_RADIO_118:
			::ValidateTextCtrlFormatNumber( m_CodRadio118, _T("%03d") );
			break;

		case ID_SCHEDA_118:
			ValidateTextCtrlSpecialFormat( m_Scheda118, _T("????????/??") );
			break;

		case ID_NOMINATIVO_PAZIENTE:
			m_NominativoPaziente->SetValue( m_NominativoPaziente->GetValue().MakeUpper() );
			break;

		case ID_GIA_TRASPORTATO_MEZZO:
			m_GiaTrasportatoMezzo->SetValue( m_GiaTrasportatoMezzo->GetValue().MakeUpper() );
			break;

		case ID_NON_COMPLETATO:
			m_NonCompletato->SetValue( m_NonCompletato->GetValue().MakeUpper() );
			break;

		case ID_ANNULLATO_ORA:
			::ValidateTextCtrlFormatTime( m_AnnullatoOra );
			break;

		case ID_ANNULLATO_LUOGO:
			m_AnnullatoLuogo->SetValue( m_AnnullatoLuogo->GetValue().MakeUpper() );
			break;
	}

    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesInfoServizio118::OnCheck( wxCommandEvent& event )
{
    switch ( event.GetId() )
    {
        case ID_AVARIA_MEZZO:
            m_AvariaMezzo->SetValue( event.IsChecked() );
            m_PazienteNonTrovato->SetValue( false );
            m_ServizioAnnullato->SetValue( false );
			m_ServizioNonCompletato->SetValue( false );
			m_PazienteGiaTrasportato->SetValue( false );
            break;

        case ID_PAZIENTE_NONTROVATO:
            m_AvariaMezzo->SetValue( false );
            m_PazienteNonTrovato->SetValue( event.IsChecked() );
            m_ServizioAnnullato->SetValue( false );
			m_ServizioNonCompletato->SetValue( false );
			m_PazienteGiaTrasportato->SetValue( false );
            break;

        case ID_SERVIZIO_ANNULLATO:
            m_AvariaMezzo->SetValue( false );
            m_ServizioAnnullato->SetValue( event.IsChecked() );
            m_PazienteNonTrovato->SetValue( false );
			m_ServizioNonCompletato->SetValue( false );
			m_PazienteGiaTrasportato->SetValue( false );
            break;

		case ID_SERVIZIO_NON_COMPLETATO:
            m_AvariaMezzo->SetValue( false );
			m_ServizioNonCompletato->SetValue( event.IsChecked() );
            m_PazienteNonTrovato->SetValue( false );
            m_ServizioAnnullato->SetValue( false );
			m_PazienteGiaTrasportato->SetValue( false );
			break;

		case ID_PAZIENTE_GIATRASPORTATO:
            m_AvariaMezzo->SetValue( false );
			m_PazienteGiaTrasportato->SetValue(  event.IsChecked()  );
			m_ServizioNonCompletato->SetValue( false );
            m_PazienteNonTrovato->SetValue( false );
            m_ServizioAnnullato->SetValue( false );
	}

	m_GiaTrasportatoMezzo->Show( m_PazienteGiaTrasportato->GetValue() );
	m_NonCompletato->Show( m_ServizioNonCompletato->GetValue() );
    m_label_AnnullatoOra->Show( m_ServizioAnnullato->GetValue() );
    m_label_AnnullatoLuogo->Show( m_ServizioAnnullato->GetValue() );
    m_AnnullatoOra->Show( m_ServizioAnnullato->GetValue() );
    m_AnnullatoLuogo->Show( m_ServizioAnnullato->GetValue() );

    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesInfoServizio118::OnEnter()
{
	if ( m_pService->GetField(FIELD_CODRADIO118).GetStringValue().IsEmpty() )
	{
		m_CodRadio118->SetValue( m_pService->GetVehicle().GetRadio118() );
	}
	else
	{
		m_CodRadio118->SetValue( m_pService->GetField(FIELD_CODRADIO118).GetStringValue() );
	}
	
	if ( !m_CodRadio118->GetValue().IsEmpty() )
	{
		m_Scheda118->SetFocus();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesInfoServizio118::OnExit()
{
	m_pService->GetField(FIELD_CODRADIO118) = m_CodRadio118->GetValue(); 
	m_pService->GetField(FIELD_SCHEDA118) = m_Scheda118->GetValue(); 

	m_pService->ClearAllPatient();

	if ( m_AvariaMezzo->GetValue() || m_PazienteNonTrovato->GetValue() || m_PazienteGiaTrasportato->GetValue() || m_ServizioAnnullato->GetValue() || m_ServizioNonCompletato->GetValue() )
	{
		CServicePatient p;
		p[FIELD_COGNOME] = m_NominativoPaziente->GetValue().IsEmpty() ? _("N.P.") : m_NominativoPaziente->GetValue();
		p[FIELD_NOME] = wxEmptyString;
		p[FIELD_DATA_NASCITA] = EmptyDate;
		p[FIELD_SESSO] = wxEmptyString;
		p[FIELD_INDIRIZZO] = wxEmptyString;
		p[FIELD_CIVICO] = wxEmptyString;
		p[FIELD_CAP] = wxEmptyString;
		p[FIELD_CITTA] = wxEmptyString;
		p[FIELD_PROVINCIA] = wxEmptyString;
		p[FIELD_MOTIVOTRASPORTO] = wxEmptyString;
        if ( m_AvariaMezzo->GetValue() )
        {
            p[FIELD_TRASPORTATO_LUOGO] = szServiceResult[SERVICERESULT_VEHICLE_DAMAGE];
        }
		else if ( m_PazienteNonTrovato->GetValue() )
		{
			p[FIELD_TRASPORTATO_LUOGO] = szServiceResult[SERVICERESULT_NOT_FOUND];
		}
		else if ( m_PazienteGiaTrasportato->GetValue() )
		{
			p[FIELD_TRASPORTATO_LUOGO] = wxString::Format( _T("%s %s"), szServiceResult[SERVICERESULT_TRANSPORT_BY], m_GiaTrasportatoMezzo->GetValue().c_str() );
		}
		else if ( m_ServizioNonCompletato->GetValue() )
		{
			p[FIELD_TRASPORTATO_LUOGO] = wxString::Format( _T("%s %s"), szServiceResult[SERVICERESULT_NOT_COMPLETED], m_NonCompletato->GetValue().c_str() );
		}
		else if ( m_ServizioAnnullato->GetValue() )
		{
			p[FIELD_TRASPORTATO_LUOGO] = wxString::Format( _T("%s, ORA %s, %s"), szServiceResult[SERVICERESULT_ANNULLED_BY_118], m_AnnullatoOra->GetValue().c_str(), m_AnnullatoLuogo->GetValue().c_str() );
		}
		p[FIELD_TRASPORTATO_CAP] = 0;
		p[FIELD_TRASPORTATO_CITTA] = wxEmptyString;
		p[FIELD_TRASPORTATO_PROVINCIA] = wxEmptyString;
		p[FIELD_FIRMA_SCHEDA_CRI] = false;
		p[FIELD_FIRMA_SCHEDA_118] = false;
		p[FIELD_NUM_TEAM] = wxEmptyString;
		p[FIELD_COD_PATOLOGIA] = wxEmptyString;
		p[FIELD_COD_EVE_GRAVITA] = m_CodGravita->GetValue();
		p[FIELD_COD_EVE_PATOLOGIA] = m_CodPatologia->GetValue();
		p[FIELD_COD_EVE_LUOGO] = m_CodLuogo->GetValue();
		p[FIELD_COD_ARR_GRAVITA] = wxEmptyString;
		p[FIELD_COD_ARR_PATOLOGIA] = wxEmptyString;
		p[FIELD_COD_ARR_LUOGO] = wxEmptyString;
		p[FIELD_COD_PAR_GRAVITA] = wxEmptyString;
		p[FIELD_COD_PAR_PATOLOGIA] = wxEmptyString;
		p[FIELD_COD_PAR_PATOLOGIA2] = wxEmptyString;
		p[FIELD_COD_PAR_LUOGO] = wxEmptyString;
		p[FIELD_COD_RIL_GRAVITA] = wxEmptyString;
		p[FIELD_COD_RIL_PATOLOGIA] = wxEmptyString;
		p[FIELD_COD_RIL_LUOGO] = wxEmptyString;
		p[FIELD_TRIAGE] = wxEmptyString;

		m_pService->AddPatient( p );
		SetNextPage( m_pPage2 );
	}
	else
	{
		m_pService->Set118CodeEvent( C118Code(m_CodGravita->GetValue(), m_CodPatologia->GetValue(), m_CodLuogo->GetValue() ) );
		SetNextPage( m_pPage1 );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesInfoServizio118::GoNext()
{
	if ( m_CodRadio118->GetValue().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato inserito il codice radio 118") );
		m_CodRadio118->SetFocus();
		return false;
	}

	if ( m_Scheda118->GetValue().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato inserito il numero di scheda 118") );
		m_Scheda118->SetFocus();
		return false;
	}

	if ( m_CodGravita->GetValue().IsEmpty() || m_CodPatologia->GetValue().IsEmpty() || m_CodLuogo->GetValue().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato inserito il codice di uscita") );
		if ( m_CodGravita->GetValue().IsEmpty() )
		{
			m_CodGravita->SetFocus();
		}
		else if ( m_CodPatologia->GetValue().IsEmpty() )
		{
			m_CodPatologia->SetFocus();
		}
		else
		{
			m_CodLuogo->SetFocus();
		}
		return false;
	}

    if ( m_PazienteGiaTrasportato->GetValue() )
    {
        if ( m_GiaTrasportatoMezzo->GetValue().IsEmpty() )
        {
			WARNING_MESSAGE( _("Non e' stato inserito chi ha trasportato il paziente") );
			m_GiaTrasportatoMezzo->SetFocus();
			return false;
        }
    }

    if ( m_ServizioNonCompletato->GetValue() )
    {
        if ( m_NonCompletato->GetValue().IsEmpty() )
        {
			WARNING_MESSAGE( _("Non e' stato inserito il perche' non e' stato completato") );
			m_NonCompletato->SetFocus();
			return false;
        }
    }

	if ( m_ServizioAnnullato->GetValue() )
	{
		if ( m_AnnullatoOra->GetValue().IsEmpty() )
		{
			WARNING_MESSAGE( _("Non e' stata inserita l'ora di quando e' stato annullato il servizio") );
			m_AnnullatoOra->SetFocus();
			return false;
		}

		if ( m_AnnullatoLuogo->GetValue().IsEmpty() )
		{
			WARNING_MESSAGE( _("Non e' stato inserito il luogo di quando e' stato annullato il servizio") );
			m_AnnullatoLuogo->SetFocus();
			return false;
		}
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesInfoServizio118::GoPrev()
{
	return true;
}
