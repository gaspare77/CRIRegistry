#include "CRIRegistryServiceDlg.h"

/////////////////////////////////////////////////////////////////////////////
//
//
CRIRegistryServiceDlg::CRIRegistryServiceDlg( wxWindow* parent, const CService& service ):
ServiceRegistryDlg( parent ), m_Service( service ), m_aszPaymentType( CHAR_LIST_SIZE(szPaymentType), szPaymentType )
{
	SetIcon( wxICON(ServiceIcon));

	wxString query;
	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLIGIASERVIZI_ORDINARI );
	m_aszServiceType = dbSingleton::Instance()->SQLGetColArray( query );
	m_aszServiceType.Add( OTHER_SELECTION );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLIGIASERVIZI_118 );
	m_asz118ServiceType = dbSingleton::Instance()->SQLGetColArray( query );
	m_asz118ServiceType.Add( OTHER_SELECTION );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_TIPO, TABLE_TIPOLIGIASERVIZI_INTERNI );
	m_aszInternalServiceType = dbSingleton::Instance()->SQLGetColArray( query );	
	m_aszInternalServiceType.Add( OTHER_SELECTION );

	m_bUserIsTheOwner   = UsersManager::Instance()->GetUserLogged().GetFullName() == m_Service[FIELD_CENTRALINO].GetStringValue();
	m_bUserCanChangeAll = UsersManager::Instance()->GetUserLogged().GetPrivileges() >= RESP_CENTR;
	m_bUserCanAdd       = UsersManager::Instance()->GetUserLogged().GetPrivileges() >= CENTRALINO;;

	m_notebook->SetSelection( 0 );
	m_Dati_Pagamento->Append( m_aszPaymentType );

	m_Equipaggio->InsertColumn( 0, _("Cognome"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 1, _("Nome"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 2, _("Qualifica"), wxLIST_FORMAT_LEFT );
	m_Equipaggio->InsertColumn( 3, _("Qualifica Stato"), wxLIST_FORMAT_CENTER );

	m_Pazienti->InsertColumn( 0, _("Nominativo"),wxLIST_FORMAT_LEFT );
	m_Pazienti->InsertColumn( 1, _("Sesso"),wxLIST_FORMAT_CENTER );
	m_Pazienti->InsertColumn( 2, _("Eta'"),wxLIST_FORMAT_CENTER );

	int w;
	w= m_Equipaggio->GetSize().GetWidth() - 30;
    m_Equipaggio->SetColumnWidth( 0, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 1, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 2, GET_PERC(25., w) );
    m_Equipaggio->SetColumnWidth( 3, GET_PERC(25., w) );

	w= m_Pazienti->GetSize().GetWidth() - 30;
    m_Pazienti->SetColumnWidth( 0, GET_PERC(80., w) );
    m_Pazienti->SetColumnWidth( 1, GET_PERC(10., w) );
    m_Pazienti->SetColumnWidth( 2, GET_PERC(10., w) );
	
    UpdateCtrl();
	UpdateRequestedCtrl();
	UpdatePatientsListCtrl();
	UpdatePatientsCtrl();
	UpdateCrewsListCtrl();
	UpdateCtrlStatusByUser();

	SetPatientSelected( 0 );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_NUM_SCHEDA:
		::ValidateTextCtrlFormatNumber( m_NumeroScheda, _T("%06d") );
		break;
	case ID_NUM_SCHEDA_SUP:
		::ValidateTextCtrlFormatNumber( m_NumeroSchedaSup, _T("%06d") );
		break;
	case ID_GRUPPO:
		m_Gruppo->SetValue( m_Gruppo->GetValue().MakeUpper() );
		break;
	case ID_COD_AMBULANZA:
		::ValidateTextCtrlFormatNumber( m_CodAmbulanza );
		break;
	case ID_COD_AMBULANZA_118:
		::ValidateTextCtrlFormatNumber( m_CodAmbulanza118, _T("%03d") );
		break;
	case ID_TARGA_AMBULANZA:
		::ValidateTextCtrlFormatPlate( m_TargaAmbulanza );
		break;
	case ID_ORA_INIZIO:
		::ValidateTextCtrlFormatTime( m_OraInizio );
		break;
	case ID_ORA_PARTENZA:
		::ValidateTextCtrlFormatTime( m_OraPartenza );
		break;
	case ID_ORA_ARRIVO_TARGET:
		::ValidateTextCtrlFormatTime( m_OraArrivoTarget );
		break;
	case ID_ORA_PARTENZA_TARGET:
		::ValidateTextCtrlFormatTime( m_OraPartenzaTarget );
		break;
	case ID_ORA_ARRIVO:
		::ValidateTextCtrlFormatTime( m_OraArrivo );
		break;
	case ID_ORA_FINE:
		::ValidateTextCtrlFormatTime( m_OraFine );
		break;
	case ID_SCHEDA_118:
		m_NumScheda118->SetValue( m_NumScheda118->GetValue().MakeUpper() );
		break;
    case ID_ALTRA_TIPOLOGIA:
        m_AltraTipologia->SetValue( m_AltraTipologia->GetValue().MakeUpper() );
        break;
	case ID_RICHIESTO_NOMINATIVO:
		m_Richiesto_Nominativo->SetValue( m_Richiesto_Nominativo->GetValue().MakeUpper() );
		break;
	case ID_RICHIESTO_CF_PIVA:
		m_Richiesto_CF_PIVA->SetValue( m_Richiesto_CF_PIVA->GetValue().MakeUpper() );
		break;
	case ID_RICHIESTO_INDIRIZZO:
		m_Richiesto_Indirizzo->SetValue( m_Richiesto_Indirizzo->GetValue().MakeUpper() );
		break;
	case ID_RICHIESTO_CIVICO:
		m_Richiesto_Civico->SetValue( m_Richiesto_Civico->GetValue().MakeUpper() );
		break;
	case ID_RICHIESTO_CAP:
		::ValidateTextCtrlFormatNumber( m_Richiesto_CAP );
		break;
	case ID_RICHIESTO_CITTA:
		m_Richiesto_Citta->SetValue( m_Richiesto_Citta->GetValue().MakeUpper() );
		break;
	case ID_RICHIESTO_PROVINCIA:
		m_Richiesto_Provincia->SetValue( m_Richiesto_Provincia->GetValue().MakeUpper() );
		break;
	case ID_LUOGOINTERVENTO:
		m_LuogoIntervento->SetValue( m_LuogoIntervento->GetValue().MakeUpper() );
		break;
	case ID_LUOGOINTERVENTO_CAP:
		::ValidateTextCtrlFormatNumber( m_LuogoIntervento_CAP );
		break;
	case ID_LUOGOINTERVENTO_CITTA:
		m_LuogoIntervento_Citta->SetValue( m_LuogoIntervento_Citta->GetValue().MakeUpper() );
		break;
	case ID_LUOGOINTERVENTO_PROVINCIA:
		m_LuogoIntervento_Provincia->SetValue( m_LuogoIntervento_Provincia->GetValue().MakeUpper() );
		break;
	case ID_ALTRO_MEZZO:
		m_Altro_Mezzo->SetValue( m_Altro_Mezzo->GetValue().MakeUpper() );
		break;
	case ID_IMPORTO:
		::ValidateTextCtrlFormatCurrency( m_Importo );
		break;
	case ID_KM_PERCORSI:
		::ValidateTextCtrlFormatNumber( m_KmPercorsi );
		break;
	case ID_ORE_FERMO_MACCHINA:
		::ValidateTextCtrlFormatCurrency( m_Ore_Fermo_Macchina );
		break;
	case ID_NOTE:
		m_Note->SetValue( m_Note->GetValue().MakeUpper() );
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnCheck( wxCommandEvent& event )
{
	UpdateRequestedCtrl();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnCheckClose( wxCommandEvent& event )
{	
	if ( !CanBeClosed() )
	{
		WARNING_MESSAGE( _("Il Servizio non puo' essere chiuso") );
		m_Chiuso->SetValue( false );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnPatientSelected( wxListEvent& event )
{
	UpdatePatientsCtrl();
	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnModifyCrew( wxCommandEvent& event )
{
	std::vector<CServiceCrew>::iterator it = GetCrewSelected();
	if ( it == m_Service.GetCrew().end() )
	{
		return;
	}

	CRIRegistryCrewDlg dlg( this, *it );
	if ( dlg.ShowModal() == wxID_OK )
	{
		*it = dlg.GetCrew();
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnAddCrew( wxCommandEvent& event )
{
	CRIRegistryCrewDlg dlg( this );
	if ( dlg.ShowModal() == wxID_OK )
	{
		m_Service.AddCrew( dlg.GetCrew() );
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnDelCrew( wxCommandEvent& event )
{
	std::vector<CServiceCrew>::iterator it = GetCrewSelected();
	if ( it == m_Service.GetCrew().end() )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare %s %s?"), 
		it->GetField(FIELD_COGNOME).GetCharValue(), 
		it->GetField(FIELD_NOME).GetCharValue() ) == wxYES )
	{
		m_Service.DelCrew( *it );
		UpdateCrewsListCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnModifyPatient( wxCommandEvent& event )
{
	std::vector<CServicePatient>::iterator it = GetPatientSelected();
	int i = GetPatientItemSelected();
	if ( it == m_Service.GetPatient().end() )
	{
		return;
	}

	CRIRegistryPatientDlg dlg( this, *it );
	if ( dlg.ShowModal() == wxID_OK )
	{
		*it = dlg.GetPatient();
		UpdatePatientsListCtrl();
		SetPatientSelected( i );
		UpdatePatientsCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnAddPatient( wxCommandEvent& event )
{
	CRIRegistryPatientDlg dlg( this );
	if ( dlg.ShowModal() == wxID_OK )
	{
		m_Service.AddPatient( dlg.GetPatient() );
		UpdatePatientsListCtrl();
		SetPatientSelected( m_Pazienti->GetItemCount() - 1 );
		UpdatePatientsCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnDelPatient( wxCommandEvent& event )
{
	std::vector<CServicePatient>::iterator it = GetPatientSelected();
	if ( it == m_Service.GetPatient().end() )
	{
		return;
	}

	if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare %s %s?"), 
		it->GetField(FIELD_COGNOME).GetCharValue(),
		it->GetField(FIELD_NOME).GetCharValue()) == wxYES )
	{
		m_Service.DelPatient( *it );
		UpdatePatientsListCtrl();
		SetPatientSelected( 0 );
		UpdatePatientsCtrl();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnCancel( wxCommandEvent& event )
{
	EndModal( wxID_CANCEL );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::OnOk( wxCommandEvent& event )
{
	if ( CanBeClosed() && !m_Chiuso->GetValue() && QUESTION_MESSAGE( _("Il servizio non e' stato chiuso.\nLo vuoi chiudere ora?") ) == wxYES )
	{
		m_Chiuso->SetValue( true );
	}
	if ( m_Chiuso->GetValue() && !CanBeClosed() )
	{
		WARNING_MESSAGE( _("Il servizio e' stato riaperto.") );
		m_Chiuso->SetValue( false );
	}

	UpdateData();
	EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::UpdateCtrl()
{
	m_NumeroScheda->SetValue( m_Service[FIELD_NUMSERVIZIO].GetIntValue() > 0 ? wxString::Format( _T("%06d"), m_Service[FIELD_NUMSERVIZIO].GetIntValue() ) : wxEmptyString );
	m_NumeroSchedaSup->SetValue( m_Service[FIELD_NUMSERVIZIOSUP].GetIntValue() > 0 ? wxString::Format( _T("%06d"), m_Service[FIELD_NUMSERVIZIOSUP].GetIntValue() ) : wxEmptyString );
	m_Gruppo->SetValue( m_Service[FIELD_GRUPPO].GetStringValue() );
	m_CodAmbulanza->SetValue( m_Service[FIELD_CODMEZZO].GetStringValue() );
	m_CodAmbulanza118->SetValue( m_Service[FIELD_CODRADIO118].GetStringValue() );
	m_TargaAmbulanza->SetValue( m_Service[FIELD_TARGAMEZZO].GetStringValue() );
	m_Data->SetValue( m_Service[FIELD_DATA].GetDateTimeValue() );
	m_OraInizio->SetValue( m_Service[FIELD_ORAINIZIO].GetDateTimeValue() == EmptyDate ? wxEmptyString : m_Service[FIELD_ORAINIZIO].GetDateTimeValue().Format(FORMAT_TIME) );
	m_OraPartenza->SetValue( m_Service[FIELD_ORAPARTENZA].GetDateTimeValue() == EmptyDate ? wxEmptyString : m_Service[FIELD_ORAPARTENZA].GetDateTimeValue().Format(FORMAT_TIME) );
	m_OraArrivoTarget->SetValue( m_Service[FIELD_ORAARRIVOTARGET].GetDateTimeValue() == EmptyDate ? wxEmptyString : m_Service[FIELD_ORAARRIVOTARGET].GetDateTimeValue().Format(FORMAT_TIME) );
	m_OraPartenzaTarget->SetValue( m_Service[FIELD_ORAPARTENZATARGET].GetDateTimeValue() == EmptyDate ? wxEmptyString : m_Service[FIELD_ORAPARTENZATARGET].GetDateTimeValue().Format(FORMAT_TIME) );
	m_OraArrivo->SetValue( m_Service[FIELD_ORAARRIVO].GetDateTimeValue() == EmptyDate ? wxEmptyString : m_Service[FIELD_ORAARRIVO].GetDateTimeValue().Format(FORMAT_TIME) );
    m_OraFine->SetValue( m_Service[FIELD_ORAFINE].GetDateTimeValue() == EmptyDate ? wxEmptyString : m_Service[FIELD_ORAFINE].GetDateTimeValue().Format(FORMAT_TIME) );
	m_Richiesto_118->SetValue( m_Service[FIELD_RICHIESTO].GetStringValue() == szRequestedBy[REQUESTED_BY_118] );
	m_Richiesto_Ospedali->SetValue( m_Service[FIELD_RICHIESTO].GetStringValue() == szRequestedBy[REQUESTED_BY_HOSPITAL] );
	m_Servizio_Interno->SetValue( m_Service[FIELD_RICHIESTO].GetStringValue() == szRequestedBy[REQUESTED_BY_INTERNAL] );
	m_Richiesto_Parenti->SetValue( m_Service[FIELD_RICHIESTO].GetStringValue() == szRequestedBy[REQUESTED_BY_PARENT] );
	m_Richiesto_Altri->SetValue( m_Service[FIELD_RICHIESTO].GetStringValue() == szRequestedBy[REQUESTED_BY_OTHER] );
	m_NumScheda118->SetValue( m_Service[FIELD_SCHEDA118].GetStringValue() );
	m_Richiesto_Nominativo->SetValue( m_Service[FIELD_RICHIESTO_NOMINATIVO].GetStringValue() );
	m_Richiesto_CF_PIVA->SetValue( m_Service[FIELD_RICHIESTO_CF_PIVA].GetStringValue() );
	m_Richiesto_Indirizzo->SetValue( m_Service[FIELD_RICHIESTO_INDIRIZZO].GetStringValue() );
	m_Richiesto_Civico->SetValue( m_Service[FIELD_RICHIESTO_CIVICO].GetStringValue() );
	m_Richiesto_CAP->SetValue( m_Service[FIELD_RICHIESTO_CAP].GetIntValue() > 0 ? m_Service[FIELD_RICHIESTO_CAP].GetStringValue() : wxEmptyString );
	m_Richiesto_Citta->SetValue( m_Service[FIELD_RICHIESTO_CITTA].GetStringValue() );
	m_Richiesto_Provincia->SetValue( m_Service[FIELD_RICHIESTO_PROVINCIA].GetStringValue() );
	m_LuogoIntervento->SetValue( m_Service[FIELD_INTERVENTO_LUOGO].GetStringValue() );
	m_LuogoIntervento_CAP->SetValue( m_Service[FIELD_INTERVENTO_CAP].GetIntValue() > 0 ? m_Service[FIELD_INTERVENTO_CAP].GetStringValue() : wxEmptyString );
	m_LuogoIntervento_Citta->SetValue( m_Service[FIELD_INTERVENTO_CITTA].GetStringValue() );
	m_LuogoIntervento_Provincia->SetValue( m_Service[FIELD_INTERVENTO_PROVINCIA].GetStringValue() );
	m_Carabinieri_Checked->SetValue( m_Service[FIELD_CARABINIERI].GetBoolValue() );
	m_Polizia_Checked->SetValue( m_Service[FIELD_POLIZIA].GetBoolValue() );
	m_Polizia_Municipale_Checked->SetValue( m_Service[FIELD_POLIZIA_MUNICIPALE].GetBoolValue() );
	m_Vigili_del_Fuoco_Checked->SetValue( m_Service[FIELD_VVFF].GetBoolValue() );
	m_Guardia_Medica_Checked->SetValue( m_Service[FIELD_GUARDIA_MEDICA].GetBoolValue() );
	m_Altro_Mezzo_Checked->SetValue( m_Service[FIELD_ALTRI_MEZZI].GetBoolValue() );
	m_Altro_Mezzo->SetValue( m_Service[FIELD_ALTRI_MEZZI_COD].GetStringValue() );
	m_Dati_Pagamento->SetStringSelection( m_Service[FIELD_DATIPAGAMENTO].GetStringValue() );
	m_Importo->SetValue( m_Service[FIELD_IMPORTO].GetFloatValue() > 0.0 ? wxString::Format( _T("%.2f"), m_Service[FIELD_IMPORTO].GetFloatValue() ) : wxEmptyString );
	m_KmPercorsi->SetValue(  m_Service[FIELD_KM_PERCORSI].GetIntValue() > 0 ? m_Service[FIELD_KM_PERCORSI].GetStringValue() : wxEmptyString );
	m_Ore_Fermo_Macchina->SetValue( m_Service[FIELD_ORE_FERMO_MACCHINA].GetFloatValue() > 0.0 ? wxString::Format( _T("%.2f"), m_Service[FIELD_ORE_FERMO_MACCHINA].GetFloatValue() ) : wxEmptyString );
	m_Note->SetValue( m_Service[FIELD_NOTE].GetStringValue() );
	m_Centralino->SetValue( m_Service[FIELD_CENTRALINO].GetStringValue() );
	m_Chiuso->SetValue( m_Service[FIELD_CHIUSO].GetBoolValue() );
	m_Annullato->SetValue( m_Service[FIELD_ANNULLATO].GetBoolValue() );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::UpdatePatientsListCtrl()
{
	m_Pazienti->DeleteAllItems();

	std::vector<CServicePatient>::iterator it;
	for ( it = m_Service.GetPatient().begin(); it != m_Service.GetPatient().end(); ++it )
	{
        long i = m_Pazienti->GetItemCount();
        m_Pazienti->InsertItem( i, it->GetField(FIELD_COGNOME).GetStringValue() + _T(" ") + it->GetField(FIELD_NOME).GetStringValue() );
        m_Pazienti->SetItem( i, 1, it->GetField(FIELD_SESSO).GetStringValue() );
		m_Pazienti->SetItem( i, 2, it->GetField(FIELD_ETA).GetStringValue().IsEmpty() ? _T("-") : it->GetField(FIELD_ETA).GetStringValue() + it->GetField(FIELD_ETA_TIPO).GetStringValue() );
		m_Pazienti->SetItemPtrData( i, it->GetId() );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::UpdatePatientsCtrl()
{
	std::vector<CServicePatient>::iterator it = GetPatientSelected();
	if ( it == m_Service.GetPatient().end() )
	{
		m_CodFiscale->Clear();
		m_NumTeam->Clear();
		m_Indirizzo->Clear();
		m_Civico->Clear();
		m_CAP->Clear();
		m_Citta->Clear();
		m_Provincia->Clear();
		m_Stato->Clear();
		m_Cittadinanza->Clear();
		m_MotivoDelTrasporto->Clear();
		m_Trasportato->Clear();
		m_Trasportato_CAP->Clear();
		m_Trasportato_Citta->Clear();
		m_Trasportato_Provincia->Clear();
		m_CodEvento_Gravita->Clear();
		m_CodEvento_Patologia->Clear();
		m_CodEvento_Luogo->Clear();
		m_CodArrivo_Gravita->Clear();
		m_CodArrivo_Patologia->Clear();
		m_CodArrivo_Luogo->Clear();
		m_CodPartenza_Gravita->Clear();
		m_CodPartenza_Patologia->Clear();
		m_CodPartenza_Luogo->Clear();
		m_CodPartenza_Patologia2->Clear();
		m_CodRilascio_Gravita->Clear();
		m_CodRilascio_Patologia->Clear();
		m_CodRilascio_Luogo->Clear();
		m_PatologiaSpecifica->Clear();
		m_Prestazione->Clear();
		m_Prestazione2->Clear();
		m_Prestazione3->Clear();
		m_Prestazione4->Clear();
		m_Prestazione5->Clear();
		m_DinamicaRiscontrata->Clear();
		m_DinamicaRiscontrata2->Clear();
		m_Triage->Clear();
		m_FirmaSC_CRI->SetValue( false );
		m_FirmaSC_118->SetValue( false );

		return;
	}
	
	m_CodFiscale->SetValue( it->GetField(FIELD_COD_FISCALE).GetStringValue() );
	m_NumTeam->SetValue( it->GetField(FIELD_NUM_TEAM).GetStringValue() );
	m_Indirizzo->SetValue( it->GetField(FIELD_INDIRIZZO).GetStringValue() );
	m_Civico->SetValue( it->GetField(FIELD_CIVICO).GetStringValue() );
	m_CAP->SetValue( it->GetField(FIELD_CAP).GetIntValue() > 0 ? it->GetField(FIELD_CAP).GetStringValue() : wxEmptyString );
	m_Citta->SetValue( it->GetField(FIELD_CITTA).GetStringValue() );
	m_Provincia->SetValue( it->GetField(FIELD_PROVINCIA).GetStringValue() );
	m_Stato->SetValue( it->GetField(FIELD_STATO).GetStringValue() );
	m_Cittadinanza->SetValue( it->GetField(FIELD_CITTADINANZA).GetStringValue() );
	m_MotivoDelTrasporto->SetValue( it->GetField(FIELD_MOTIVOTRASPORTO).GetStringValue() );
	m_Trasportato->SetValue( it->GetField(FIELD_TRASPORTATO_LUOGO).GetStringValue() );
	m_Trasportato_CAP->SetValue( it->GetField(FIELD_TRASPORTATO_CAP).GetIntValue() > 0 ? it->GetField(FIELD_TRASPORTATO_CAP).GetStringValue() : wxEmptyString );
	m_Trasportato_Citta->SetValue( it->GetField(FIELD_TRASPORTATO_CITTA).GetStringValue() );
	m_Trasportato_Provincia->SetValue( it->GetField(FIELD_TRASPORTATO_PROVINCIA).GetStringValue() );
	m_CodEvento_Gravita->SetValue( it->GetField(FIELD_COD_EVE_GRAVITA).GetStringValue() );
	m_CodEvento_Patologia->SetValue( it->GetField(FIELD_COD_EVE_PATOLOGIA).GetStringValue() );
	m_CodEvento_Luogo->SetValue( it->GetField(FIELD_COD_EVE_LUOGO).GetStringValue() );
	m_CodArrivo_Gravita->SetValue( it->GetField(FIELD_COD_ARR_GRAVITA).GetStringValue() );
	m_CodArrivo_Patologia->SetValue( it->GetField(FIELD_COD_ARR_PATOLOGIA).GetStringValue() );
	m_CodArrivo_Luogo->SetValue( it->GetField(FIELD_COD_ARR_LUOGO).GetStringValue() );
	m_CodPartenza_Gravita->SetValue( it->GetField(FIELD_COD_PAR_GRAVITA).GetStringValue() );
	m_CodPartenza_Patologia->SetValue( it->GetField(FIELD_COD_PAR_PATOLOGIA).GetStringValue() );
	m_CodPartenza_Patologia2->SetValue( it->GetField(FIELD_COD_PAR_PATOLOGIA2).GetStringValue() );
	m_CodPartenza_Luogo->SetValue( it->GetField(FIELD_COD_PAR_LUOGO).GetStringValue() );
	m_CodRilascio_Gravita->SetValue( it->GetField(FIELD_COD_RIL_GRAVITA).GetStringValue() );
	m_CodRilascio_Patologia->SetValue( it->GetField(FIELD_COD_RIL_PATOLOGIA).GetStringValue() );
	m_CodRilascio_Luogo->SetValue( it->GetField(FIELD_COD_RIL_LUOGO).GetStringValue() );
	m_PatologiaSpecifica->SetValue( it->GetField(FIELD_COD_PATOLOGIA).GetStringValue() );
	m_Triage->SetValue( it->GetField(FIELD_TRIAGE).GetStringValue() );
	m_Prestazione->SetValue( it->GetTrattamento(0) );
	m_Prestazione2->SetValue( it->GetTrattamento(1) );
	m_Prestazione3->SetValue( it->GetTrattamento(2) );
	m_Prestazione4->SetValue( it->GetTrattamento(3) );
	m_Prestazione5->SetValue( it->GetTrattamento(4) );
	m_DinamicaRiscontrata->SetValue( it->GetDinamica(0) );
	m_DinamicaRiscontrata2->SetValue( it->GetDinamica(1) );
	m_FirmaSC_CRI->SetValue( it->GetField(FIELD_FIRMA_SCHEDA_CRI).GetBoolValue() );
	m_FirmaSC_118->SetValue( it->GetField(FIELD_FIRMA_SCHEDA_118).GetBoolValue() );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::UpdateCrewsListCtrl()
{
	m_Equipaggio->DeleteAllItems();

	std::vector<CServiceCrew>::iterator it;
	for ( it = m_Service.GetCrew().begin(); it != m_Service.GetCrew().end(); ++it )
	{
        long i = m_Equipaggio->GetItemCount();
        m_Equipaggio->InsertItem( i, it->GetField(FIELD_COGNOME).GetStringValue() );
        m_Equipaggio->SetItem( i, 1, it->GetField(FIELD_NOME).GetStringValue() );
        m_Equipaggio->SetItem( i, 2, it->GetField(FIELD_QUALIFICA).GetStringValue() );
		m_Equipaggio->SetItem( i, 3, it->GetField(FIELD_QUALIFICASTATO).GetStringValue() );
		m_Equipaggio->SetItemPtrData( i, it->GetId() );
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::UpdateRequestedCtrl()
{
	m_Tipo->Clear();
	m_Tipo->Append( _T("") );
	if ( m_Servizio_Interno->GetValue() )
	{
		m_Tipo->Append( m_aszInternalServiceType );
	}
	else if ( m_Richiesto_118->GetValue() )
	{
		m_Tipo->Append( m_asz118ServiceType );
	}
	else
	{
		m_Tipo->Append( m_aszServiceType );
	}	

	wxString s = m_Service[FIELD_TIPO].GetStringValue();
	if ( !s.IsEmpty() && m_Tipo->FindString( s ) == wxNOT_FOUND )
	{
		m_Tipo->Append( s );
	}
	m_Tipo->SetStringSelection( s );
    m_AltraTipologia->SetValue( m_Service[FIELD_ALTRO_TIPO].GetStringValue() );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::UpdateData()
{
	m_Service[FIELD_NUMSERVIZIO] = m_NumeroScheda->GetValue();
	m_Service[FIELD_NUMSERVIZIOSUP] = m_NumeroSchedaSup->GetValue();
	m_Service[FIELD_GRUPPO] = m_Gruppo->GetValue();
	m_Service[FIELD_CODMEZZO] = m_CodAmbulanza->GetValue();
	m_Service[FIELD_CODRADIO118] = m_CodAmbulanza118->GetValue();
	m_Service[FIELD_TARGAMEZZO] = m_TargaAmbulanza->GetValue();
	m_Service[FIELD_DATA] = m_Data->GetValue();

	wxDateTime dtStart = ::ConcatDateTime( m_Data->GetValue(), m_OraInizio->GetValue() ); 
	wxDateTime dtDeparture = ::ConcatDateTime( m_Data->GetValue(), m_OraPartenza->GetValue() );
	wxDateTime dtTagertArrival = ::ConcatDateTime( m_Data->GetValue(), m_OraArrivoTarget->GetValue() );
	wxDateTime dtTargetDeparture = ::ConcatDateTime( m_Data->GetValue(), m_OraPartenzaTarget->GetValue() );
	wxDateTime dtArrival = ::ConcatDateTime( m_Data->GetValue(), m_OraArrivo->GetValue() );
    wxDateTime dtEnd = ::ConcatDateTime( m_Data->GetValue(), m_OraFine->GetValue() );

	if ( dtStart >= dtDeparture && dtDeparture != EmptyDate )
	{
		dtDeparture += wxDateSpan::Day();
	}
	if ( dtStart >= dtTagertArrival && dtTagertArrival != EmptyDate )
	{
		dtTagertArrival += wxDateSpan::Day();
	}
	if ( dtStart >= dtTargetDeparture && dtTargetDeparture != EmptyDate )
	{
		dtTargetDeparture += wxDateSpan::Day();
	}
	if ( dtStart >= dtArrival && dtArrival != EmptyDate )
	{
		dtArrival += wxDateSpan::Day();
	}
	if ( dtStart >= dtEnd && dtEnd != EmptyDate )
	{
		dtEnd += wxDateSpan::Day();
	}

	m_Service[FIELD_ORAINIZIO] = dtStart;
	m_Service[FIELD_ORAPARTENZA] = dtDeparture;
	m_Service[FIELD_ORAARRIVOTARGET] = dtTagertArrival;
	m_Service[FIELD_ORAPARTENZATARGET] = dtTargetDeparture;
	m_Service[FIELD_ORAARRIVO] = dtArrival;
	m_Service[FIELD_ORAFINE] = dtEnd;

	if ( m_Richiesto_118->GetValue() )
	{
		m_Service[FIELD_RICHIESTO] = szRequestedBy[REQUESTED_BY_118];
	}
	else if ( m_Richiesto_Ospedali->GetValue() )
	{
		m_Service[FIELD_RICHIESTO] = szRequestedBy[REQUESTED_BY_HOSPITAL];
	}
	else if ( m_Servizio_Interno->GetValue() )
	{
		m_Service[FIELD_RICHIESTO] = szRequestedBy[REQUESTED_BY_INTERNAL];
	}
	else if ( m_Richiesto_Parenti->GetValue() )
	{
		m_Service[FIELD_RICHIESTO] = szRequestedBy[REQUESTED_BY_PARENT];
	}
	else if ( m_Richiesto_Altri->GetValue() )
	{
		m_Service[FIELD_RICHIESTO] = szRequestedBy[REQUESTED_BY_OTHER];
	}
	m_Service[FIELD_SCHEDA118] = m_NumScheda118->GetValue();
	m_Service[FIELD_TIPO] = m_Tipo->GetStringSelection();
    m_Service[FIELD_ALTRO_TIPO] = m_AltraTipologia->GetValue();
	m_Service[FIELD_RICHIESTO_NOMINATIVO] = m_Richiesto_Nominativo->GetValue();
	m_Service[FIELD_RICHIESTO_CF_PIVA] = m_Richiesto_CF_PIVA->GetValue();
	m_Service[FIELD_RICHIESTO_INDIRIZZO] = m_Richiesto_Indirizzo->GetValue();
	m_Service[FIELD_RICHIESTO_CIVICO] = m_Richiesto_Civico->GetValue();
	m_Service[FIELD_RICHIESTO_CAP] = m_Richiesto_CAP->GetValue();
	m_Service[FIELD_RICHIESTO_CITTA] = m_Richiesto_Citta->GetValue();
	m_Service[FIELD_RICHIESTO_PROVINCIA] = m_Richiesto_Provincia->GetValue();
	m_Service[FIELD_INTERVENTO_LUOGO] = m_LuogoIntervento->GetValue();
	m_Service[FIELD_INTERVENTO_CAP] = m_LuogoIntervento_CAP->GetValue();
	m_Service[FIELD_INTERVENTO_CITTA] = m_LuogoIntervento_Citta->GetValue();
	m_Service[FIELD_INTERVENTO_PROVINCIA] = m_LuogoIntervento_Provincia->GetValue();
	m_Service[FIELD_CARABINIERI] = m_Carabinieri_Checked->GetValue(); 			 
	m_Service[FIELD_POLIZIA] = m_Polizia_Checked->GetValue();				 
	m_Service[FIELD_POLIZIA_MUNICIPALE] = m_Polizia_Municipale_Checked->GetValue();	 
	m_Service[FIELD_VVFF] = m_Vigili_del_Fuoco_Checked->GetValue();		 
	m_Service[FIELD_GUARDIA_MEDICA] = m_Guardia_Medica_Checked->GetValue();		 
	m_Service[FIELD_ALTRI_MEZZI] = m_Altro_Mezzo_Checked->GetValue();			 
	m_Service[FIELD_ALTRI_MEZZI_COD] = m_Altro_Mezzo->GetValue();			 
	m_Service[FIELD_DATIPAGAMENTO] = m_Dati_Pagamento->GetStringSelection();
	m_Service[FIELD_IMPORTO] = m_Importo->GetValue();
	m_Service[FIELD_KM_PERCORSI] = m_KmPercorsi->GetValue();
	m_Service[FIELD_ORE_FERMO_MACCHINA] = m_Ore_Fermo_Macchina->GetValue();
	m_Service[FIELD_NOTE] = m_Note->GetValue();
	m_Service[FIELD_CENTRALINO] = m_Centralino->GetValue();
	m_Service[FIELD_CHIUSO] = m_Chiuso->GetValue();
	m_Service[FIELD_ANNULLATO] = m_Annullato->GetValue();
}

/////////////////////////////////////////////////////////////////////////////
//
//
long CRIRegistryServiceDlg::GetPatientItemSelected()
{
    for ( long i = 0; i < m_Pazienti->GetItemCount(); i++ )
    {
		if ( m_Pazienti->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
			return i;
        }
    }

	return -1;
}

/////////////////////////////////////////////////////////////////////////////
//
//
long CRIRegistryServiceDlg::GetCrewItemSelected()
{
    for ( long i = 0; i < m_Equipaggio->GetItemCount(); i++ )
    {
		if ( m_Equipaggio->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
			return i;
        }
    }

	return -1;
}

/////////////////////////////////////////////////////////////////////////////
//
//
std::vector<CServicePatient>::iterator CRIRegistryServiceDlg::GetPatientSelected()
{
	std::vector<CServicePatient>::iterator it = m_Service.GetPatient().end();
	long item = GetPatientItemSelected();
	if ( item < 0 )
	{
	    return it;
	}
	for ( it = m_Service.GetPatient().begin(); it != m_Service.GetPatient().end(); ++it )
	{
		if ( m_Pazienti->GetItemData( item ) == it->GetId() )
		{
			break;
		}
	}

	return it;
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::SetPatientSelected( long i )
{
	m_Pazienti->SetFocus();
	m_Pazienti->SetItemState( i, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED );
	m_Pazienti->SetItemState( i, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED );
	m_Pazienti->EnsureVisible( i );
}

/////////////////////////////////////////////////////////////////////////////
//
//
std::vector<CServiceCrew>::iterator CRIRegistryServiceDlg::GetCrewSelected()
{
	std::vector<CServiceCrew>::iterator it = m_Service.GetCrew().end();
	long item = GetCrewItemSelected();
	if ( item < 0 )
	{
	    return it;
	}

	for ( it = m_Service.GetCrew().begin(); it != m_Service.GetCrew().end(); ++it )
	{
		if ( m_Equipaggio->GetItemData( item ) == it->GetId() )
		{
			break;
		}
	}

    return it;
}

/////////////////////////////////////////////////////////////////////////////
//
//
bool CRIRegistryServiceDlg::CanBeClosed()
{
	return m_Annullato->GetValue() || !(m_NumeroScheda->GetValue().IsEmpty() || m_OraFine->GetValue().IsEmpty() );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryServiceDlg::UpdateCtrlStatusByUser()
{
	if ( !m_bUserIsTheOwner && !m_bUserCanChangeAll )
	{
		WARNING_MESSAGE( _("Il servizio e' stato registrato da %s.\nTu potrai solo inserire eventuali note oppure inserire l'orario di chiusura."), m_Service[FIELD_CENTRALINO].GetCharValue() );
	}
	
	m_NumeroScheda->Enable( m_bUserCanChangeAll || ( m_NumeroScheda->GetValue().IsEmpty() && m_bUserCanAdd ) );
	m_NumeroSchedaSup->Enable( m_bUserCanChangeAll );
	m_Gruppo->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_CodAmbulanza->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_CodAmbulanza118->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_TargaAmbulanza->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Data->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_OraInizio->Enable( m_bUserCanChangeAll || m_bUserIsTheOwner );
	m_OraPartenza->Enable( m_bUserCanChangeAll || m_bUserIsTheOwner );
	m_OraArrivoTarget->Enable( m_bUserCanChangeAll || m_bUserIsTheOwner );
	m_OraPartenzaTarget->Enable( m_bUserCanChangeAll || m_bUserIsTheOwner );
	m_OraArrivo->Enable( m_bUserCanChangeAll || m_bUserIsTheOwner );
	m_OraFine->Enable( m_bUserCanChangeAll || m_bUserIsTheOwner || ( m_OraFine->GetValue().IsEmpty() && m_bUserCanAdd ) );

	m_Richiesto_118->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_Ospedali->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Servizio_Interno->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_Parenti->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_Altri->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Tipo->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_NumScheda118->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_LuogoIntervento->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_LuogoIntervento_CAP->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_LuogoIntervento_Citta->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_LuogoIntervento_Provincia->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Carabinieri_Checked->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Polizia_Checked->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Polizia_Municipale_Checked->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Vigili_del_Fuoco_Checked->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Guardia_Medica_Checked->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Altro_Mezzo_Checked->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Altro_Mezzo->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );

	m_Richiesto_Nominativo->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_CF_PIVA->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_Indirizzo->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_Civico->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_CAP->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_Citta->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Richiesto_Provincia->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Dati_Pagamento->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Importo->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_KmPercorsi->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_Ore_Fermo_Macchina->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );

	m_bpButton_Add_Patient->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_bpButton_Del_Patient->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_bpButton_Modify_Patient->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );

	m_bpButton_Add_Crew->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_bpButton_Del_Crew->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );
	m_bpButton_Modify_Crew->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll );

	m_Note->Enable( true );

	m_Chiuso->Enable( m_bUserIsTheOwner || m_bUserCanChangeAll || !m_Chiuso->GetValue() );
	m_Annullato->Enable( m_bUserCanChangeAll );
}
