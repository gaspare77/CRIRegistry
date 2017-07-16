#include "WizardPagesLuogoTrasportato.h"

/////////////////////////////////////////////////////////////////////////////
//
//
WizardPagesLuogoTrasportato::WizardPagesLuogoTrasportato( wxWindow* parent, CService* service ):
LuogoTrasportato( (wxWindow*)parent ), m_pService( service )
{
    m_pPage1 = new WizardPagesUtilizzoMezzo( parent, service );
    m_pPage1->SetPrevPage( this );

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
void WizardPagesLuogoTrasportato::OnCheck( wxCommandEvent& event )
{
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
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoTrasportato::OnExitCtrl( wxFocusEvent& event )
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
void WizardPagesLuogoTrasportato::OnKeyUp( wxKeyEvent& event )
{
	switch ( event.GetId() )
	{
		case ID_CAP:
            if ( event.GetKeyCode() == WXK_F1 )
            {
                CRIRegistryCAPListDlg dlg(this);
                if ( dlg.ShowModal() == wxID_OK )
                {
                    m_CAP->SetValue( dlg.FieldSelect()->GetField(FIELD_CAP).GetStringValue() );
                    m_Citta->SetValue( dlg.FieldSelect()->GetField(FIELD_COMUNE).GetStringValue() );
                    m_Provincia->SetValue( dlg.FieldSelect()->GetField(FIELD_PROVINCIA).GetStringValue() );
                    m_Provincia->SetFocus();
                    return;
                }
            }
            break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoTrasportato::OnEnter()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
void WizardPagesLuogoTrasportato::OnExit()
{
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool WizardPagesLuogoTrasportato::GoNext()
{
	std::vector<CServicePatient>::iterator it = m_pService->GetPatient().begin();
	if ( it == m_pService->GetPatient().end() )
	{
		ERROR_MESSAGE( _("Non e' stato inserito nessun paziente") );
		return false;
	}

	if ( m_Abitazione_Checked->GetValue() )
	{
		it->GetField(FIELD_TRASPORTATO_LUOGO) = szServicePlace[SERVICEPLACE_HOME];
		it->GetField(FIELD_TRASPORTATO_CAP) = m_pService->GetField(FIELD_RICHIESTO_CAP).GetStringValue();
		it->GetField(FIELD_TRASPORTATO_CITTA) = m_pService->GetField(FIELD_RICHIESTO_CITTA).GetStringValue();
		it->GetField(FIELD_TRASPORTATO_PROVINCIA) = m_pService->GetField(FIELD_RICHIESTO_PROVINCIA).GetStringValue();
	}
	else if ( m_Ospedale_Checked->GetValue() )
	{
		CHospital h;
		if ( !h.LoadFromDb( m_Ospedale->GetStringSelection() ) )
		{
			m_Ospedale->SetFocus();
			return false;
		}

		it->GetField(FIELD_TRASPORTATO_LUOGO) = wxString::Format( _T("%s%s"), szServicePlace[SERVICEPLACE_HOSPITAL], h.GetNome().c_str() );
		it->GetField(FIELD_TRASPORTATO_CAP) = h.GetCAP();
		it->GetField(FIELD_TRASPORTATO_CITTA) = h.GetCitta();
		it->GetField(FIELD_TRASPORTATO_PROVINCIA) = h.GetProvincia();
	}
	else if ( m_AltroLuogo_Checked->GetValue() )
	{
		if ( m_Luogo->GetValue().IsEmpty() )
		{
			WARNING_MESSAGE( _("Non e' stato inserito il luogo dove il paziente e' stato trasportato") );
			m_Luogo->SetFocus();
			return false;
		}
		it->GetField(FIELD_TRASPORTATO_LUOGO) = m_Luogo->GetValue();
		it->GetField(FIELD_TRASPORTATO_CAP) = m_CAP->GetValue();
		it->GetField(FIELD_TRASPORTATO_CITTA) = m_Citta->GetValue();
		it->GetField(FIELD_TRASPORTATO_PROVINCIA) = m_Provincia->GetValue();
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
bool WizardPagesLuogoTrasportato::GoPrev()
{
	return true;
}
