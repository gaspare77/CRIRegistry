#include "WizardPagesRichiesto.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesRichiesto::WizardPagesRichiesto( wxWizard* parent, CService* service ):
Richiesto( (wxWindow*)parent ), m_pService( service ) 
{
	m_pPage0 = new WizardPagesLuogoIntervento118( parent, service );
	m_pPage0->SetPrevPage( this );

    m_pPage1 = new WizardPagesLuogoIntervento( parent, service );
	m_pPage1->SetPrevPage( this );

	m_pPage2 = new WizardPagesPaziente( parent, service );
	m_pPage2->SetPrevPage( this );

	m_pPage3 = new WizardPagesRichiedente( parent, service );
	m_pPage3->SetPrevPage( this );

	m_pPage4 = new WizardPagesUtilizzoMezzo( parent, service );
	m_pPage4->SetPrevPage( this );

	SetNextPage( m_pPage0 );

	wxString query;
	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLIGIASERVIZI_ORDINARI );
	m_aszTypeOrdinary = dbSingleton::Instance()->SQLGetColArray( query );
	m_aszTypeOrdinary.Add( OTHER_SELECTION );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLIGIASERVIZI_118 );
	m_aszType118 = dbSingleton::Instance()->SQLGetColArray( query );
	m_aszType118.Add( OTHER_SELECTION );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLIGIASERVIZI_INTERNI );
	m_aszTypeInternal = dbSingleton::Instance()->SQLGetColArray( query );	
	m_aszTypeInternal.Add( OTHER_SELECTION );

	query = wxString::Format( _T("SELECT %s FROM %s ORDER BY %s"), FIELD_NOME, TABLE_OSPEDALI, FIELD_NOME );
    m_Ospedale->Append( dbSingleton::Instance()->SQLGetColArray( query ) );

    m_AltraTipologia->Enable( false );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiesto::OnCheck( wxCommandEvent& event )
{
	m_Tipo->Clear();

	switch( event.GetId() )
	{
	case ID_OSPEDALI:
		m_Tipo->Append( m_aszTypeOrdinary );
		break;

	case ID_118:
		m_Tipo->Append( m_aszType118 );
		m_Ospedale->SetSelection( -1 );
		break;

	case ID_PARENTI:
		m_Tipo->Append( m_aszTypeOrdinary );
		m_Ospedale->SetSelection( -1 );
		break;

	case ID_ALTRI:
		m_Tipo->Append( m_aszTypeOrdinary );
		m_Ospedale->SetSelection( -1 );
		break;

	case ID_SERVIZIO_INTERNO:
		m_Tipo->Append( m_aszTypeInternal );
		m_Ospedale->SetSelection( -1 );
		break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiesto::OnChoice( wxCommandEvent& event )
{
    switch ( event.GetId() )
    {
    case ID_TIPO:
        m_AltraTipologia->Enable( m_Tipo->GetStringSelection() == OTHER_SELECTION );
        if ( m_Tipo->GetStringSelection() != OTHER_SELECTION )
        {
            m_AltraTipologia->Clear();
        }
        break;
    }
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiesto::OnExitCtrl( wxFocusEvent& event )
{
    switch ( event.GetId() )
    {
    case ID_ALTRA_TIPOLOGIA:
        m_AltraTipologia->SetValue( m_AltraTipologia->GetValue().MakeUpper() );
        break;
    }
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiesto::OnEnter()
{
	wxString s=  m_pService->GetField(FIELD_RICHIESTO).GetStringValue();
	m_radio_118->SetValue( s == szRequestedBy[REQUESTED_BY_118] );
	m_radio_Parenti->SetValue( s == szRequestedBy[REQUESTED_BY_PARENT] );
	m_radio_Ospedali->SetValue( s == szRequestedBy[REQUESTED_BY_HOSPITAL] );
	m_radio_Altri->SetValue( s == szRequestedBy[REQUESTED_BY_OTHER] );
	m_radio_ServizioInterno->SetValue( s == szRequestedBy[REQUESTED_BY_INTERNAL] );
	m_Tipo->SetStringSelection( m_pService->GetField(FIELD_TIPO).GetStringValue() );
	m_Ospedale->SetStringSelection( m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO).GetStringValue() );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesRichiesto::OnExit()
{
	eRequestedBy eRequest = UNKNOW_REQUESTED_BY;
	if ( m_radio_118->GetValue() )
	{
		eRequest = REQUESTED_BY_118;
		SetNextPage( m_pPage0 );
	}
	else if ( m_radio_Parenti->GetValue() )
	{
		eRequest = REQUESTED_BY_PARENT;
		SetNextPage( m_pPage2 );
	}
	else if ( m_radio_Ospedali->GetValue() )
	{
		eRequest = REQUESTED_BY_HOSPITAL;
		SetNextPage( m_pPage1 );
	}
	else if ( m_radio_Altri->GetValue() )
	{
		eRequest = REQUESTED_BY_OTHER;
		SetNextPage( m_pPage3 );
	}
	else if ( m_radio_ServizioInterno->GetValue() )
	{
		eRequest = REQUESTED_BY_INTERNAL;
		SetNextPage( m_pPage4 );
	}

	m_pService->GetField(FIELD_RICHIESTO) = szRequestedBy[eRequest];

	if ( m_LastRequestedBy != szRequestedBy[eRequest] )
	{
		m_pService->GetField(FIELD_TIPO) = wxEmptyString;
		m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO) = wxEmptyString;
		m_pService->GetField(FIELD_RICHIESTO_CF_PIVA) = wxEmptyString;
		m_pService->GetField(FIELD_RICHIESTO_INDIRIZZO) = wxEmptyString;
		m_pService->GetField(FIELD_RICHIESTO_CIVICO) = wxEmptyString;
		m_pService->GetField(FIELD_RICHIESTO_CAP) = wxEmptyString;
		m_pService->GetField(FIELD_RICHIESTO_CITTA) = wxEmptyString;
		m_pService->GetField(FIELD_RICHIESTO_PROVINCIA) = wxEmptyString;
		m_pService->GetField(FIELD_DATIPAGAMENTO) = wxEmptyString;
		m_pService->GetField(FIELD_IMPORTO) = wxEmptyString;
		m_pService->ClearAllPatient();
        m_LastRequestedBy = szRequestedBy[eRequest];
	}

	m_pService->GetField(FIELD_TIPO) = m_Tipo->GetStringSelection();
    m_pService->GetField(FIELD_ALTRO_TIPO) = m_AltraTipologia->GetValue();
	m_pService->GetField(FIELD_RICHIESTO_NOMINATIVO) = m_Ospedale->GetStringSelection();
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesRichiesto::GoNext()
{
	if ( m_pService->GetField(FIELD_RICHIESTO).GetStringValue().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato selezionato chi richiede il servizio") );
		return false;
	}

	if ( m_pService->GetField(FIELD_RICHIESTO).GetStringValue() == szRequestedBy[REQUESTED_BY_HOSPITAL] &&
		 m_Ospedale->GetSelection() < 0 )
	{
		WARNING_MESSAGE( _("Non e' stato selezionato l'ospedale") );
		m_Ospedale->SetFocus();
		return false;
	}

	if ( m_pService->GetField(FIELD_TIPO).GetStringValue().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato selezionato il tipo di servizio") );
		m_Tipo->SetFocus();
		return false;
	}

    if ( m_AltraTipologia->IsEnabled() && m_AltraTipologia->GetValue().IsEmpty() )
    {
		WARNING_MESSAGE( _("Non e' stata insertita l'altra tipologia") );
		m_AltraTipologia->SetFocus();
		return false;
    }

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesRichiesto::GoPrev()
{
	return true;
}
