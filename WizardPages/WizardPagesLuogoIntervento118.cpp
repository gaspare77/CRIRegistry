#include "WizardPagesLuogoIntervento118.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesLuogoIntervento118::WizardPagesLuogoIntervento118( wxWindow* parent, CService* service ):
LuogoIntervento118( parent ), m_pService( service )
{
	m_pPage1 = new WizardPagesInfoServizio118( parent, service );
	m_pPage1->SetPrevPage( this );

    SetNextPage( m_pPage1 );

	wxString query = wxString::Format( _T("SELECT %s FROM %s ORDER BY %s"), FIELD_NOME, TABLE_OSPEDALI, FIELD_NOME );
    m_Ospedale->Append( dbSingleton::Instance()->SQLGetColArray( query ) );

	m_Ospedale_Checked->SetValue( false );
	m_AltroLuogo_Checked->SetValue( false );

	m_Ospedale->Enable( false );
	m_Luogo->Enable( false );
	m_CAP->Enable( false );
	m_Citta->Enable( false );
	m_Provincia->Enable( false );
	m_AltroMezzo_Codice->Enable( false );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoIntervento118::OnCheck( wxCommandEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_OSPEDALE_CHECKED:
	case ID_ALTRO_LUOGO_CHECKED:
        if ( m_Ospedale_Checked->GetValue() && event.GetId() == ID_OSPEDALE_CHECKED )
		{
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
void WizardPagesLuogoIntervento118::OnExitCtrl( wxFocusEvent& event )
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
        case ID_ALTRO_MEZZO_CODICE:
            m_AltroMezzo_Codice->SetValue( m_AltroMezzo_Codice->GetValue().MakeUpper() );
            break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoIntervento118::OnEnter()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoIntervento118::OnExit()
{
    m_pService->GetField(FIELD_CARABINIERI) = m_Carabinieri_Checked->GetValue();
    m_pService->GetField(FIELD_POLIZIA) = m_Polizia_Checked->GetValue();
    m_pService->GetField(FIELD_POLIZIA_MUNICIPALE) = m_Polizia_Municipale_Checked->GetValue();
    m_pService->GetField(FIELD_VVFF) = m_Vigili_del_Fuoco_Checked->GetValue();
    m_pService->GetField(FIELD_GUARDIA_MEDICA) = m_Guardia_Medica_Checked->GetValue();
    m_pService->GetField(FIELD_ALTRI_MEZZI) = m_Altro_Mezzo_Checked->GetValue();
    m_pService->GetField(FIELD_ALTRI_MEZZI_COD) = m_AltroMezzo_Codice->GetValue();
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesLuogoIntervento118::GoNext()
{
    if ( m_Ospedale_Checked->GetValue() )
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
		if ( m_Citta->GetValue().IsEmpty() )
		{
			WARNING_MESSAGE( _("Non e' stata inserita la citta' d'intervento") );
			m_Citta->SetFocus();
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
bool WizardPagesLuogoIntervento118::GoPrev()
{
	return true;
}