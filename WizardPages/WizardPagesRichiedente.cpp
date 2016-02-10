#include "WizardPagesRichiedente.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesRichiedente::WizardPagesRichiedente( wxWindow* parent, CService* service ):
Richiedente( (wxWindow*)parent ), m_pService( service )
{
    m_pPage = new WizardPagesLuogoIntervento( parent, service );
	m_pPage->SetPrevPage( this );
	SetNextPage( m_pPage );

	m_TipologiaPagamento->Append( wxArrayString(CHAR_LIST_SIZE(szPaymentType), szPaymentType) );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiedente::OnExitCtrl( wxFocusEvent& event )
{
	switch( event.GetId() )
	{
	case ID_NOMINATIVO:
		m_Nominativo->SetValue( m_Nominativo->GetValue().MakeUpper() );
		break;
	case ID_CF_PIVA:
		m_CodFiscale_Piva->SetValue( m_CodFiscale_Piva->GetValue().MakeUpper() );
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
	case ID_IMPORTO:
		::ValidateTextCtrlFormatCurrency( m_Importo );
		break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiedente::OnEnter()
{
	m_Nominativo->SetValue( m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO).GetStringValue() );
	m_CodFiscale_Piva->SetValue( m_pService->GetField(FIELD_RICHIESTO_CF_PIVA).GetStringValue() );
	m_Indirizzo->SetValue( m_pService->GetField(FIELD_RICHIESTO_INDIRIZZO).GetStringValue() );
	m_Civico->SetValue( m_pService->GetField(FIELD_RICHIESTO_CIVICO).GetStringValue() );
	m_CAP->SetValue( m_pService->GetField(FIELD_RICHIESTO_CAP).GetStringValue() );
	m_Citta->SetValue( m_pService->GetField(FIELD_RICHIESTO_CITTA).GetStringValue() );
	m_Provincia->SetValue( m_pService->GetField(FIELD_RICHIESTO_PROVINCIA).GetStringValue() );
	m_TipologiaPagamento->SetStringSelection( m_pService->GetField(FIELD_DATIPAGAMENTO).GetStringValue() );
	m_Importo->SetValue( m_pService->GetField(FIELD_IMPORTO).GetFloatValue() > 0.0 ? wxString::Format( _T("%.2f"), m_pService->GetField(FIELD_IMPORTO).GetFloatValue() ) : wxEmptyString );
	m_Nominativo->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiedente::OnExit()
{
	m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO) = m_Nominativo->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CF_PIVA) = m_CodFiscale_Piva->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_INDIRIZZO) = m_Indirizzo->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CIVICO) = m_Civico->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CAP) = m_CAP->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_CITTA) = m_Citta->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_PROVINCIA) = m_Provincia->GetValue();
	m_pService->GetField(FIELD_DATIPAGAMENTO) = m_TipologiaPagamento->GetStringSelection();
	m_pService->GetField(FIELD_IMPORTO) = m_Importo->GetValue();
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesRichiedente::GoNext()
{
	if ( m_Nominativo->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il nominativo di chi richiede il servizio") );
        m_Nominativo->SetFocus();
        return false;
    }

	if ( m_TipologiaPagamento->GetStringSelection().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stata inserita la tipologia di pagamento") );
        m_TipologiaPagamento->SetFocus();
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
bool WizardPagesRichiedente::GoPrev()
{
	return true;
}