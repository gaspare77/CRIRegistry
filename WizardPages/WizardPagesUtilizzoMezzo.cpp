#include "WizardPagesUtilizzoMezzo.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesUtilizzoMezzo::WizardPagesUtilizzoMezzo( wxWindow* parent, CService* service  ):
UtilizzoMezzo( (wxWindow*)parent ), m_pService( service )
{
	m_pPage = new WizardPagesFine( parent, service );
    m_pPage->SetPrevPage( this );
    SetNextPage( m_pPage );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesUtilizzoMezzo::OnExitCtrl( wxFocusEvent& event )
{
    switch ( event.GetId() )
    {
        case ID_KM_INIZIALI:
            if ( ::ValidateTextCtrlFormatNumber( m_KmIniziali ) )
            {
                ComputeKm();
            }
            break;

        case ID_KM_FINALI:
            if ( ::ValidateTextCtrlFormatNumber( m_KmFinali ) )
            {
                ComputeKm();
            }
            break;

        case ID_ORE_FERMO_MACCHINA:
            ::ValidateTextCtrlFormatCurrency( m_OreFermoMacchina );

            break;
    }

    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesUtilizzoMezzo::OnEnter()
{
    if ( m_pService->GetField(FIELD_KM_PERCORSI).GetIntValue() <= 0 )
    {
        m_KmIniziali->SetValue( m_pService->GetVehicle().GetKm() );
        m_KmFinali->Clear();
    }
    ComputeKm();

    if ( m_pService->GetField(FIELD_ORE_FERMO_MACCHINA).GetFloatValue() > 0.0 )
    {
        m_OreFermoMacchina->SetValue( wxString::Format( _T("%.2f"), m_pService->GetField(FIELD_ORE_FERMO_MACCHINA).GetFloatValue() ) );
    }
    else
    {
        m_OreFermoMacchina->Clear();
    }
    m_KmFinali->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesUtilizzoMezzo::OnExit()
{
    ComputeKm();
    m_pService->GetField(FIELD_KM_PERCORSI) = m_KmPercorsi->GetValue();
    m_pService->GetField(FIELD_ORE_FERMO_MACCHINA) = m_OreFermoMacchina->GetValue();
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesUtilizzoMezzo::GoNext()
{
	if ( m_pService->GetField(FIELD_KM_PERCORSI).GetStringValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non sono stati inseriti i km finali") );
        m_KmFinali->SetFocus();
        return false;
    }

    if ( m_pService->GetField(FIELD_KM_PERCORSI).GetIntValue() < 0 )
    {
        WARNING_MESSAGE( _("I km finali inseriti non sono corretti") );
        m_KmFinali->SetFocus();
        return false;
    }

    m_pService->GetVehicle().SetKm( m_KmFinali->GetValue() );

    return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesUtilizzoMezzo::GoPrev()
{
	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesUtilizzoMezzo::ComputeKm()
{
    if ( m_KmIniziali->GetValue().IsEmpty() || m_KmFinali->GetValue().IsEmpty() )
    {
        m_KmPercorsi->Clear();
        return;
    }

    long start, end;
    m_KmIniziali->GetValue().ToLong( &start );
    m_KmFinali->GetValue().ToLong( &end );
    m_KmPercorsi->SetValue( wxString::Format( _T("%d"), (int)( end - start ) ) );
}

