#include "WizardPagesPaziente.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesPaziente::WizardPagesPaziente( wxWindow* parent, CService* service  ):
Paziente( (wxWindow*)parent ), m_pService( service )
{
    m_pPage = new WizardPagesLuogoIntervento( parent, service );
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );

	m_Stato->Append( wxArrayString( CHAR_LIST_SIZE(szStates), szStates ) );
	m_TipologiaPagamento->Append( wxArrayString(CHAR_LIST_SIZE(szPaymentType), szPaymentType) );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPaziente::OnExitCtrl( wxFocusEvent& event )
{
    cAge age;
	switch( event.GetId() )
	{
    case ID_COGNOME:
        m_Cognome->SetValue( m_Cognome->GetValue().MakeUpper() );
        break;
    case ID_NOME:
        m_Nome->SetValue( m_Nome->GetValue().MakeUpper() );
        break;
    case ID_CODICE_FISCALE:
        m_CodFiscale->SetValue( m_CodFiscale->GetValue().MakeUpper() );
        break;
    case ID_DATA_NASCITA:
        ::ValidateTextCtrlFormatDate( m_DataNascita );
/*
        if ( age.Compute( ::StrToDate( m_DataNascita->GetValue() ) ) )
		{
			m_Eta->SetValue( age.Get() );
            m_Anni->SetValue( age.GetType() == cAge::Years );
            m_Mesi->SetValue( age.GetType() == cAge::Months );
            m_Giorni->SetValue( age.GetType() == cAge::Days );
            m_Sesso->SetFocus();
		}
*/
        break;
    case ID_ETA:
        ::ValidateTextCtrlFormatNumber( m_Eta );
        break;
	case ID_INDIRIZZO:
		m_Indirizzo->SetValue( m_Indirizzo->GetValue().MakeUpper() );
		break;
	case ID_CIVICO:
		m_Civico->SetValue( m_Civico->GetValue().MakeUpper() );
		break;
	case ID_CAP:
		::ValidateTextCtrlFormatNumber( m_CAP );
		break;
	case ID_CITTA:
		m_Citta->SetValue( m_Citta->GetValue().MakeUpper() );
		break;
	case ID_PROVINCIA:
		m_Provincia->SetValue( m_Provincia->GetValue().MakeUpper() );
		break;
    case ID_MOTIVOTRASPORTO:
        m_MotivoTrasporto->SetValue( m_MotivoTrasporto->GetValue().MakeUpper() );
        break;
	case ID_IMPORTO:
		::ValidateTextCtrlFormatCurrency( m_Importo );
		break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPaziente::OnEnter()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesPaziente::OnExit()
{
	m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO) = m_Cognome->GetValue() + _T(" ") + m_Nome->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CF_PIVA) = m_CodFiscale->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_INDIRIZZO) = m_Indirizzo->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CIVICO) = m_Civico->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CAP) = m_CAP->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CITTA) = m_Citta->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_PROVINCIA) = m_Provincia->GetValue();
	m_pService->GetField(FIELD_DATIPAGAMENTO) = m_TipologiaPagamento->GetStringSelection();
	m_pService->GetField(FIELD_IMPORTO) = m_Importo->GetValue();

    m_pService->ClearAllPatient();

    CServicePatient p;
    p[FIELD_COGNOME] = m_Cognome->GetValue();
    p[FIELD_NOME] = m_Nome->GetValue();
	p[FIELD_COD_FISCALE] = m_CodFiscale->GetValue();
    p[FIELD_DATA_NASCITA] = ::StrToDate( m_DataNascita->GetValue() );
    p[FIELD_ETA] = m_Eta->GetValue();
    if ( !m_Eta->GetValue().IsEmpty() && m_Anni->GetValue() )
    {
        p[FIELD_ETA_TIPO] = cAge::GetType( cAge::Years );
    }
    else if ( !m_Eta->GetValue().IsEmpty() && m_Mesi->GetValue() )
    {
        p[FIELD_ETA_TIPO] = cAge::GetType( cAge::Months );
    }
    else if ( !m_Eta->GetValue().IsEmpty() && m_Giorni->GetValue() )
    {
        p[FIELD_ETA_TIPO] = cAge::GetType( cAge::Days );
    }
    else
    {
        p[FIELD_ETA_TIPO] = wxEmptyString;
    }
    p[FIELD_SESSO] = m_Sesso->GetStringSelection();
    p[FIELD_INDIRIZZO] =  m_Indirizzo->GetValue();
    p[FIELD_CIVICO] = m_Civico->GetValue();
    p[FIELD_CAP] = m_CAP->GetValue();
    p[FIELD_CITTA] = m_Citta->GetValue();
    p[FIELD_PROVINCIA] = m_Provincia->GetValue();
    p[FIELD_MOTIVOTRASPORTO] = m_MotivoTrasporto->GetValue();
    p[FIELD_FIRMA_SCHEDA_CRI] = false;
    p[FIELD_FIRMA_SCHEDA_118] = false;
	p[FIELD_NUM_TEAM] = wxEmptyString;
    p[FIELD_COD_PATOLOGIA] = wxEmptyString;
    p[FIELD_COD_EVE_GRAVITA] = wxEmptyString;
    p[FIELD_COD_EVE_PATOLOGIA] = wxEmptyString;
    p[FIELD_COD_EVE_LUOGO] = wxEmptyString;
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
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesPaziente::GoNext()
{
	if ( m_Cognome->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il nominativo del paziente") );
        m_Cognome->SetFocus();
        return false;
    }

	if ( m_TipologiaPagamento->GetStringSelection().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stata inserita la tipologia di pagamento") );
        m_TipologiaPagamento->SetFocus();
        return false;
    }

    if ( m_MotivoTrasporto->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il motivo del trasporto") );
        m_MotivoTrasporto->SetFocus();
        return false;
    }

    if ( m_TipologiaPagamento->GetStringSelection() == szPaymentType[PAYMENT_TYPE_PAYED] && ( m_pService->GetField(FIELD_IMPORTO).GetFloatValue() <= 0.0 ) )
    {
        WARNING_MESSAGE( _("Non e' stato inserito l'importo pagato") );
        m_Importo->SetFocus();
        return false;
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesPaziente::GoPrev()
{
	return true;
}
