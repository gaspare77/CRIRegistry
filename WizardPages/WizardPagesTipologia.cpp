#include "WizardPagesTipologia.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesTipologia::WizardPagesTipologia( wxWindow* parent, CService* service ):
Tipologia( (wxWindow*)parent ), m_pService( service )
{
	m_pPage1 = new WizardPagesLuogoIntervento( parent, service );
	m_pPage1->SetPrevPage( this );

	m_pPage2 = new WizardPagesPaziente( parent, service );
	m_pPage2->SetPrevPage( this );

	m_pPage3 = new WizardPagesOspedale( parent, service );
	m_pPage3->SetPrevPage( this );

	m_pPage4 = new WizardPagesRichiedente( parent, service );
	m_pPage4->SetPrevPage( this );

	SetNextPage( m_pPage1 );

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
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesTipologia::OnEnter()
{
	m_Tipo->Clear();

	wxString s =  m_pService->GetField(FIELD_RICHIESTO).GetStringValue();
	if ( s == szRequestedBy[REQUESTED_BY_118] )
	{
		m_Tipo->Append( m_aszType118 );
	}
	else if ( s == szRequestedBy[REQUESTED_BY_PARENT] )
	{
		m_Tipo->Append( m_aszTypeOrdinary );
	}
	else if ( s == szRequestedBy[REQUESTED_BY_HOSPITAL] )
	{
		m_Tipo->Append( m_aszTypeOrdinary );
	}
	else if ( s == szRequestedBy[REQUESTED_BY_OTHER] )
	{
		m_Tipo->Append( m_aszTypeOrdinary );
	}
	else if ( s == szRequestedBy[REQUESTED_BY_INTERNAL] )
	{
		m_Tipo->Append( m_aszTypeInternal );
	}

	m_Tipo->SetStringSelection( m_pService->GetField(FIELD_TIPO).GetStringValue() );
	m_Tipo->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesTipologia::OnExit()
{
	m_pService->GetField(FIELD_TIPO) = m_Tipo->GetStringSelection();
	if ( m_pService->GetField(FIELD_RICHIESTO).GetStringValue() == szRequestedBy[REQUESTED_BY_PARENT] )
	{
		SetNextPage( m_pPage2 );
	}
	else if ( m_pService->GetField(FIELD_RICHIESTO).GetStringValue() == szRequestedBy[REQUESTED_BY_HOSPITAL] )
	{
		SetNextPage( m_pPage3 );
	}
	else if ( m_pService->GetField(FIELD_RICHIESTO).GetStringValue() == szRequestedBy[REQUESTED_BY_OTHER] )
	{
		SetNextPage( m_pPage4 );
	}
	else
	{
		SetNextPage( m_pPage1 );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesTipologia::GoNext()
{
	if ( m_pService->GetField(FIELD_TIPO).GetStringValue().IsEmpty() )
	{
		WARNING_MESSAGE( _("Non e' stato selezionato il tipo di servizio") );
		m_Tipo->SetFocus();
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesTipologia::GoPrev()
{
	return true;
}
