#include "CRIRegistryAddPatient118Dlg.h"

/////////////////////////////////////////////////////////////////////////////
//
//
CRIRegistryAddPatient118Dlg::CRIRegistryAddPatient118Dlg( wxWindow* parent, const CServicePatient& patient ):
AddPatient118Dlg( parent ), m_Patient( patient )
{
    SetIcon( wxICON(PatientIcon) );
    
    m_Ospedale->Clear();
    m_AltraAmbulanza->Clear();
	m_RifiutaTrasportoMotivo->Clear();

    wxString query;
	query = wxString::Format( _T("SELECT %s FROM %s ORDER BY %s"), FIELD_NOME, TABLE_OSPEDALI, FIELD_NOME );
    m_Ospedale->Append( dbSingleton::Instance()->SQLGetColArray( query ) );
    
	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_MOTIVO, TABLE_MOTIVIRIFIUTATRASPORTO );
	m_RifiutaTrasportoMotivo->Append( dbSingleton::Instance()->SQLGetColArray( query ) );
	m_RifiutaTrasportoMotivo->Append( OTHER_SELECTION );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_GRAVITA );
	m_CodeGravityList = dbSingleton::Instance()->SQLGetColArray( query );
	m_CodEvento_Gravita->SetProperty( TYPE_CODE_GRAVITY, m_CodeGravityList );
	m_CodArrivo_Gravita->SetProperty( TYPE_CODE_GRAVITY, m_CodeGravityList );
	m_CodPartenza_Gravita->SetProperty( TYPE_CODE_GRAVITY, m_CodeGravityList );
	m_CodRilascio_Gravita->SetProperty( TYPE_CODE_GRAVITY, m_CodeGravityList );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_PATOLOGIA_PRESUNTA );
	m_CodePatology1List = dbSingleton::Instance()->SQLGetColArray( query );
	m_CodEvento_Patologia->SetProperty( TYPE_CODE_EVENT, m_CodePatology1List );
	m_CodArrivo_Patologia->SetProperty( TYPE_CODE_ARRIVAL, m_CodePatology1List );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_PATOLOGIA_RISCONTRATA );
	m_CodePatology2List = dbSingleton::Instance()->SQLGetColArray( query );
	m_CodPartenza_Patologia->SetProperty( TYPE_CODE_DEPARTURE, m_CodePatology2List );
	m_CodPartenza_Patologia2->SetProperty( TYPE_CODE_DEPARTURE, m_CodePatology2List );
	m_CodRilascio_Patologia->SetProperty( TYPE_CODE_RELEASE, m_CodePatology2List );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_LUOGO );
	m_CodePlaceList = dbSingleton::Instance()->SQLGetColArray( query );
	m_CodEvento_Luogo->SetProperty( TYPE_CODE_PLACE, m_CodePlaceList );
	m_CodArrivo_Luogo->SetProperty( TYPE_CODE_PLACE, m_CodePlaceList );
	m_CodPartenza_Luogo->SetProperty( TYPE_CODE_PLACE, m_CodePlaceList );
	m_CodRilascio_Luogo->SetProperty( TYPE_CODE_PLACE, m_CodePlaceList );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_PRESTAZIONE );
	m_CodeTreatmentList = dbSingleton::Instance()->SQLGetColArray( query );
	m_Prestazione->SetProperty( TYPE_CODE_TREATMENT, m_CodeTreatmentList );
	m_Prestazione2->SetProperty( TYPE_CODE_TREATMENT, m_CodeTreatmentList );
	m_Prestazione3->SetProperty( TYPE_CODE_TREATMENT, m_CodeTreatmentList );
	m_Prestazione4->SetProperty( TYPE_CODE_TREATMENT, m_CodeTreatmentList );
	m_Prestazione5->SetProperty( TYPE_CODE_TREATMENT, m_CodeTreatmentList );

	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_CODICE, TABLE_CODICI_DINAMICA_RISCONTRATA );
	m_CodeDinamicList = dbSingleton::Instance()->SQLGetColArray( query );
	m_DinamicaRiscontrata->SetProperty( TYPE_CODE_DINAMIC, m_CodeDinamicList );
	m_DinamicaRiscontrata2->SetProperty( TYPE_CODE_DINAMIC, m_CodeDinamicList );

	m_Stato->Append( wxArrayString( CHAR_LIST_SIZE(szStates), szStates ) );

	m_Cognome->SetValue( m_Patient[FIELD_COGNOME].GetStringValue() );
	m_Nome->SetValue( m_Patient[FIELD_NOME].GetStringValue() );
	m_CodFiscale->SetValue( m_Patient[FIELD_COD_FISCALE].GetStringValue() );
	m_Numero_Team->SetValue( m_Patient[FIELD_NUM_TEAM].GetStringValue() );
	m_DataNascita->SetValue( m_Patient[FIELD_DATA_NASCITA].GetDateTimeValue() == EmptyDate ? wxEmptyString : m_Patient[FIELD_DATA_NASCITA].GetDateTimeValue().Format(FORMAT_DATE) );
    m_Eta->SetValue( m_Patient[FIELD_ETA].GetStringValue() );
    m_Anni->SetValue( m_Patient[FIELD_ETA_TIPO].GetStringValue() == cAge::GetType( cAge::Years ) );
    m_Mesi->SetValue( m_Patient[FIELD_ETA_TIPO].GetStringValue() == cAge::GetType( cAge::Months ) );
    m_Giorni->SetValue( m_Patient[FIELD_ETA_TIPO].GetStringValue() == cAge::GetType( cAge::Days ) );
	m_Sesso->SetStringSelection( m_Patient[FIELD_SESSO].GetStringValue() );
    m_Indirizzo->SetValue( m_Patient[FIELD_INDIRIZZO].GetStringValue() );
    m_Civico->SetValue( m_Patient[FIELD_CIVICO].GetStringValue() );
    m_CAP->SetValue( m_Patient[FIELD_CAP].GetIntValue() > 0 ? m_Patient[FIELD_CAP].GetStringValue() : wxEmptyString );
    m_Citta->SetValue( m_Patient[FIELD_CITTA].GetStringValue() );
    m_Provincia->SetValue( m_Patient[FIELD_PROVINCIA].GetStringValue() );
	m_Stato->SetStringSelection( m_Patient[FIELD_STATO].GetStringValue() );  
	m_Cittadinanza->SetValue( m_Patient[FIELD_CITTADINANZA].GetStringValue() );   
	m_MotivoDelTrasporto->SetValue( m_Patient[FIELD_MOTIVOTRASPORTO].GetStringValue() );
	m_CodEvento_Gravita->SetValue( m_Patient[FIELD_COD_EVE_GRAVITA].GetStringValue() );
	m_CodEvento_Patologia->SetValue( m_Patient[FIELD_COD_EVE_PATOLOGIA].GetStringValue() );
	m_CodEvento_Luogo->SetValue( m_Patient[FIELD_COD_EVE_LUOGO].GetStringValue() );
	m_CodArrivo_Gravita->SetValue( m_Patient[FIELD_COD_ARR_GRAVITA].GetStringValue() );
	m_CodArrivo_Patologia->SetValue( m_Patient[FIELD_COD_ARR_PATOLOGIA].GetStringValue() );
	m_CodArrivo_Luogo->SetValue( m_Patient[FIELD_COD_ARR_LUOGO].GetStringValue() );
	m_CodPartenza_Gravita->SetValue( m_Patient[FIELD_COD_PAR_GRAVITA].GetStringValue() );
	m_CodPartenza_Patologia->SetValue( m_Patient[FIELD_COD_PAR_PATOLOGIA].GetStringValue() );
	m_CodPartenza_Patologia2->SetValue( m_Patient[FIELD_COD_PAR_PATOLOGIA2].GetStringValue() );
	m_CodPartenza_Luogo->SetValue( m_Patient[FIELD_COD_PAR_LUOGO].GetStringValue() );
	m_CodRilascio_Gravita->SetValue( m_Patient[FIELD_COD_RIL_GRAVITA].GetStringValue() );
	m_CodRilascio_Patologia->SetValue( m_Patient[FIELD_COD_RIL_PATOLOGIA].GetStringValue() );
	m_CodRilascio_Luogo->SetValue( m_Patient[FIELD_COD_RIL_LUOGO].GetStringValue() );
	m_PatologiaSpecifica->SetValue( m_Patient[FIELD_COD_PATOLOGIA].GetStringValue() );
	m_Triage->SetValue( m_Patient[FIELD_TRIAGE].GetStringValue() );
	m_Prestazione->SetValue( m_Patient.GetTrattamento(0) );
	m_Prestazione2->SetValue( m_Patient.GetTrattamento(1) );
	m_Prestazione3->SetValue( m_Patient.GetTrattamento(2) );
	m_Prestazione4->SetValue( m_Patient.GetTrattamento(3) );
	m_Prestazione5->SetValue( m_Patient.GetTrattamento(4) );
	m_DinamicaRiscontrata->SetValue( m_Patient.GetDinamica(0) );
	m_DinamicaRiscontrata2->SetValue( m_Patient.GetDinamica(1) );
	m_FirmaSC_CRI->SetValue( m_Patient[FIELD_FIRMA_SCHEDA_CRI].GetBoolValue() );
    m_FirmaSC_118->SetValue( m_Patient[FIELD_FIRMA_SCHEDA_118].GetBoolValue() );

	wxString szReason;
	wxString szHospital;
	wxString szOtherAmbulance;
    if ( m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue().StartsWith( szServiceResult[SERVICERESULT_REFUSES_TRANSPORT], &szReason ) )
    {
		m_RifiutaTrasporto->SetValue( true );
		m_RifiutaTrasportoMotivo->SetStringSelection( szReason );
    }
    else if ( m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue().StartsWith( szServiceResult[SERVICERESULT_TRANSPORT_BY], &szOtherAmbulance ) )
    {
		m_TrasportatoDaAltraAbulanza->SetValue( true );
        m_AltraAmbulanza->SetValue( szOtherAmbulance );
    }
    else if ( m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue().StartsWith( szServiceResult[SERVICERESULT_HOSPITAL], &szHospital ) )
    {
		m_Trasportato->SetValue( true );
        m_Ospedale->SetStringSelection( szHospital );
    }
	else if ( m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue() == szServiceResult[SERVICERESULT_DEAD] )
	{
		m_Deceduto->SetValue( true );
	}
	else
	{
		m_Trasportato->SetValue( false );
		m_Ospedale->Enable( false );
		m_Ospedale->SetSelection( -1 );
		m_Deceduto->SetValue( false );

		m_RifiutaTrasporto->SetValue( false );
		m_RifiutaTrasportoMotivo->Enable( false );
		m_RifiutaTrasportoMotivo->SetSelection( -1 );
		m_FirmaSC_118->Enable( false );
		m_FirmaSC_118->SetValue( false );
		m_FirmaSC_CRI->Enable( false );
		m_FirmaSC_CRI->SetValue( false );

		m_TrasportatoDaAltraAbulanza->SetValue( false );
		m_AltraAmbulanza->Enable( false );
		m_AltraAmbulanza->Clear();
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatient118Dlg::OnExitCtrl( wxFocusEvent& event )
{
    cAge age;
    switch ( event.GetId() )
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
    case ID_NUMERO_TEAM:
        m_Numero_Team->SetValue( m_Numero_Team->GetValue().MakeUpper() );
        break;
    case ID_DATA_NASCITA:
        ::ValidateTextCtrlFormatDate( m_DataNascita );
        if ( age.Compute( ::StrToDate( m_DataNascita->GetValue() ) ) )
		{
			m_Eta->SetValue( age.Get() );
            m_Anni->SetValue( age.GetType() == cAge::Years );
            m_Mesi->SetValue( age.GetType() == cAge::Months );
            m_Giorni->SetValue( age.GetType() == cAge::Days );
            m_Sesso->SetFocus();
		}
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
	case ID_CITTADINANZA:
		m_Cittadinanza->SetValue( m_Cittadinanza->GetValue().MakeUpper() );
		break;
    case ID_MOTIVOTRASPORTO:
        m_MotivoDelTrasporto->SetValue( m_MotivoDelTrasporto->GetValue().MakeUpper() );
        break;
    case ID_ALTRA_AMBULANZA:
        m_AltraAmbulanza->SetValue( m_AltraAmbulanza->GetValue().MakeUpper() );
        break;
	case ID_PATOLOGIA_SPECIFICA:
		m_PatologiaSpecifica->SetValue( m_PatologiaSpecifica->GetValue().MakeUpper() );
        break;
	case ID_TRIAGE:
		m_Triage->SetValue( m_Triage->GetValue().MakeUpper() );
        break;
	}
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatient118Dlg::OnKeyUp( wxKeyEvent& event )
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
void CRIRegistryAddPatient118Dlg::OnCheckBox( wxCommandEvent& event )
{
	if ( m_Trasportato->GetValue() && event.GetId() == ID_RICOVERATO )
	{
//		m_Trasportato->SetValue( false );
		m_Ospedale->Enable( true );
//		m_Ospedale->SetSelection( -1 );
		m_Deceduto->SetValue( false );

		m_RifiutaTrasporto->SetValue( false );
		m_RifiutaTrasportoMotivo->Enable( false );
		m_RifiutaTrasportoMotivo->SetSelection( -1 );
		m_FirmaSC_118->Enable( false );
		m_FirmaSC_118->SetValue( false );
		m_FirmaSC_CRI->Enable( false );
		m_FirmaSC_CRI->SetValue( false );

		m_TrasportatoDaAltraAbulanza->SetValue( false );
		m_AltraAmbulanza->Enable( false );
		m_AltraAmbulanza->Clear();
	}
	else if ( m_Deceduto->GetValue() && event.GetId() == ID_DECEDUTO )
	{
		m_Trasportato->SetValue( false );
		m_Ospedale->Enable( false );
		m_Ospedale->SetSelection( -1 );

		m_RifiutaTrasporto->SetValue( false );
		m_RifiutaTrasportoMotivo->Enable( false );
		m_RifiutaTrasportoMotivo->SetSelection( -1 );
		m_FirmaSC_118->Enable( false );
		m_FirmaSC_118->SetValue( false );
		m_FirmaSC_CRI->Enable( false );
		m_FirmaSC_CRI->SetValue( false );

		m_TrasportatoDaAltraAbulanza->SetValue( false );
		m_AltraAmbulanza->Enable( false );
		m_AltraAmbulanza->Clear();
	}
	else if ( m_RifiutaTrasporto->GetValue() && event.GetId() == ID_RIFIUTA_TRASPORTO )
	{
		m_Trasportato->SetValue( false );
		m_Ospedale->Enable( false );
		m_Ospedale->SetSelection( -1 );
		m_Deceduto->SetValue( false );

//		m_RifiutaTrasporto->SetValue( false );
		m_RifiutaTrasportoMotivo->Enable( true );
//		m_RifiutaTrasportoMotivo->SetSelection( -1 );
		m_FirmaSC_118->Enable( true );
//		m_FirmaSC_118->SetValue( false );
		m_FirmaSC_CRI->Enable( true );
//		m_FirmaSC_CRI->SetValue( false );

		m_TrasportatoDaAltraAbulanza->SetValue( false );
		m_AltraAmbulanza->Enable( false );
		m_AltraAmbulanza->Clear();
	}
	else if ( m_TrasportatoDaAltraAbulanza->GetValue() && event.GetId() == ID_TRASPORTATO_ALTRO_MEZZO )
	{
		m_Trasportato->SetValue( false );
		m_Ospedale->Enable( false );
		m_Ospedale->SetSelection( -1 );
		m_Deceduto->SetValue( false );

		m_RifiutaTrasporto->SetValue( false );
		m_RifiutaTrasportoMotivo->Enable( false );
		m_RifiutaTrasportoMotivo->SetSelection( -1 );
		m_FirmaSC_118->Enable( false );
		m_FirmaSC_118->SetValue( false );
		m_FirmaSC_CRI->Enable( false );
		m_FirmaSC_CRI->SetValue( false );

//		m_TrasportatoDaAltraAbulanza->SetValue( false );
		m_AltraAmbulanza->Enable( true );
//		m_AltraAmbulanza->Clear();
	}
	else
	{
		m_Trasportato->SetValue( false );
		m_Ospedale->Enable( false );
		m_Ospedale->SetSelection( -1 );
		m_Deceduto->SetValue( false );

		m_RifiutaTrasporto->SetValue( false );
		m_RifiutaTrasportoMotivo->Enable( false );
		m_RifiutaTrasportoMotivo->SetSelection( -1 );
		m_FirmaSC_118->Enable( false );
		m_FirmaSC_118->SetValue( false );
		m_FirmaSC_CRI->Enable( false );
		m_FirmaSC_CRI->SetValue( false );

		m_TrasportatoDaAltraAbulanza->SetValue( false );
		m_AltraAmbulanza->Enable( false );
		m_AltraAmbulanza->Clear();
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatient118Dlg::OnOk( wxCommandEvent& event )
{
    if ( m_Cognome->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il Nominativo del paziente") );
        m_Cognome->SetFocus();
        return;
    }

    m_Patient[FIELD_COGNOME] = m_Cognome->GetValue();
    m_Patient[FIELD_NOME] = m_Nome->GetValue();
	m_Patient[FIELD_COD_FISCALE] = m_CodFiscale->GetValue();
	m_Patient[FIELD_NUM_TEAM] = m_Numero_Team->GetValue();
    m_Patient[FIELD_DATA_NASCITA] = ::StrToDate( m_DataNascita->GetValue() );
    m_Patient[FIELD_ETA] = m_Eta->GetValue();
    if ( !m_Eta->GetValue().IsEmpty() && m_Anni->GetValue() )
    {
        m_Patient[FIELD_ETA_TIPO] = cAge::GetType( cAge::Years );
    }
    else if ( !m_Eta->GetValue().IsEmpty() && m_Mesi->GetValue() )
    {
        m_Patient[FIELD_ETA_TIPO] = cAge::GetType( cAge::Months );
    }
    else if ( !m_Eta->GetValue().IsEmpty() && m_Giorni->GetValue() )
    {
        m_Patient[FIELD_ETA_TIPO] = cAge::GetType( cAge::Days );
    }
    else
    {
        m_Patient[FIELD_ETA_TIPO] = wxEmptyString;
    }
	m_Patient[FIELD_SESSO] = m_Sesso->GetStringSelection();
    m_Patient[FIELD_INDIRIZZO] = m_Indirizzo->GetValue();
    m_Patient[FIELD_CIVICO] = m_Civico->GetValue();
    m_Patient[FIELD_CAP] = m_CAP->GetValue();
    m_Patient[FIELD_CITTA] = m_Citta->GetValue();
    m_Patient[FIELD_PROVINCIA] = m_Provincia->GetValue();
	m_Patient[FIELD_STATO] = m_Stato->GetStringSelection();
	m_Patient[FIELD_CITTADINANZA] = m_Cittadinanza->GetValue();
	m_Patient[FIELD_MOTIVOTRASPORTO] = m_MotivoDelTrasporto->GetValue();
	m_Patient[FIELD_FIRMA_SCHEDA_CRI] = m_FirmaSC_CRI->GetValue();
    m_Patient[FIELD_FIRMA_SCHEDA_118] = m_FirmaSC_118->GetValue();
	
    if ( m_CodEvento_Gravita->GetValue().IsEmpty() || m_CodEvento_Patologia->GetValue().IsEmpty() || m_CodEvento_Luogo->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il Codice Evento") );
        m_CodEvento_Gravita->SetFocus();
        return;
    }
    m_Patient[FIELD_COD_EVE_GRAVITA] = m_CodEvento_Gravita->GetValue();		
	m_Patient[FIELD_COD_EVE_PATOLOGIA] = m_CodEvento_Patologia->GetValue();		
	m_Patient[FIELD_COD_EVE_LUOGO] = m_CodEvento_Luogo->GetValue();			
	
    if ( m_CodArrivo_Gravita->GetValue().IsEmpty() || m_CodArrivo_Patologia->GetValue().IsEmpty() || m_CodArrivo_Luogo->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il Codice d'Arrivo") );
        m_CodArrivo_Gravita->SetFocus();
        return;
    }
    m_Patient[FIELD_COD_ARR_GRAVITA] = m_CodArrivo_Gravita->GetValue();		
	m_Patient[FIELD_COD_ARR_PATOLOGIA] = m_CodArrivo_Patologia->GetValue();		
	m_Patient[FIELD_COD_ARR_LUOGO] = m_CodArrivo_Luogo->GetValue();			
	
    if ( m_CodPartenza_Gravita->GetValue().IsEmpty() || m_CodPartenza_Patologia->GetValue().IsEmpty() || m_CodPartenza_Luogo->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il Codice di Partenza") );
        m_CodPartenza_Gravita->SetFocus();
        return;
    }
    m_Patient[FIELD_COD_PAR_GRAVITA] = m_CodPartenza_Gravita->GetValue();		
	m_Patient[FIELD_COD_PAR_PATOLOGIA] = m_CodPartenza_Patologia->GetValue();	
	m_Patient[FIELD_COD_PAR_PATOLOGIA2] = m_CodPartenza_Patologia2->GetValue();		
	m_Patient[FIELD_COD_PAR_LUOGO] = m_CodPartenza_Luogo->GetValue();	
	
    if ( m_CodRilascio_Gravita->GetValue().IsEmpty() || m_CodRilascio_Patologia->GetValue().IsEmpty() || m_CodRilascio_Luogo->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il Codice di Rilascio") );
        m_CodRilascio_Gravita->SetFocus();
        return;
    }
    m_Patient[FIELD_COD_RIL_GRAVITA] = m_CodRilascio_Gravita->GetValue();		
	m_Patient[FIELD_COD_RIL_PATOLOGIA] = m_CodRilascio_Patologia->GetValue();	
	m_Patient[FIELD_COD_RIL_LUOGO] = m_CodRilascio_Luogo->GetValue();		
	
    m_Patient[FIELD_COD_PATOLOGIA] = m_PatologiaSpecifica->GetValue();		
	
    if ( m_Prestazione->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stata inserita la Prestazione Principale") );
        m_Prestazione->SetFocus();
        return;
    }
    m_Patient.SetTrattamento( 0, m_Prestazione->GetValue() );				
	m_Patient.SetTrattamento( 1, m_Prestazione2->GetValue() );				
	m_Patient.SetTrattamento( 2, m_Prestazione3->GetValue() );				
	m_Patient.SetTrattamento( 3, m_Prestazione4->GetValue() );				
	m_Patient.SetTrattamento( 4, m_Prestazione5->GetValue() );				

    if ( m_DinamicaRiscontrata->GetValue().IsEmpty() && m_CodEvento_Patologia->GetValue() == _T("01") )
    {
        WARNING_MESSAGE( _("Non e' stata inserita la dinamica riscontrata") );
        m_DinamicaRiscontrata->SetFocus();
        return;
    }
    m_Patient.SetDinamica( 0, m_DinamicaRiscontrata->GetValue() );		
	m_Patient.SetDinamica( 1, m_DinamicaRiscontrata2->GetValue() );		

	if ( m_Trasportato->GetValue() )
    {
        if ( !m_HospitalSelected.LoadFromDb( m_Ospedale->GetStringSelection() ) )
        {
			m_Ospedale->SetFocus();
            return;
        }
        m_Patient[FIELD_TRASPORTATO_LUOGO] = wxString::Format( _T("%s%s"), szServiceResult[SERVICERESULT_HOSPITAL], m_HospitalSelected.GetNome() .c_str() );
        m_Patient[FIELD_TRASPORTATO_CAP] = m_HospitalSelected.GetCAP();
        m_Patient[FIELD_TRASPORTATO_CITTA] = m_HospitalSelected.GetCitta();
        m_Patient[FIELD_TRASPORTATO_PROVINCIA] = m_HospitalSelected.GetProvincia();
        m_Patient[FIELD_TRIAGE] = m_Triage->GetValue();
    }
	else if ( m_Deceduto->GetValue() )
	{
		m_Patient[FIELD_TRASPORTATO_LUOGO] = szServiceResult[SERVICERESULT_DEAD];
		m_Patient[FIELD_TRASPORTATO_CAP] = wxEmptyString;
		m_Patient[FIELD_TRASPORTATO_CITTA] = wxEmptyString;
		m_Patient[FIELD_TRASPORTATO_PROVINCIA] = wxEmptyString;
	}
	else if ( m_RifiutaTrasporto->GetValue() )
    {
		if ( m_RifiutaTrasportoMotivo->GetStringSelection().Len() < 2 )
		{
	        WARNING_MESSAGE( _("Non e' stato inserito il perche' rifiuta il trasporto") );
		    m_RifiutaTrasportoMotivo->SetFocus();
			return;
		}
		m_Patient[FIELD_TRASPORTATO_LUOGO] = wxString::Format( _T("%s%s"), szServiceResult[SERVICERESULT_REFUSES_TRANSPORT], m_RifiutaTrasportoMotivo->GetStringSelection().c_str() );
        m_Patient[FIELD_TRASPORTATO_CAP] = wxEmptyString;
        m_Patient[FIELD_TRASPORTATO_CITTA] = wxEmptyString;
        m_Patient[FIELD_TRASPORTATO_PROVINCIA] = wxEmptyString;
    }
    else if ( m_TrasportatoDaAltraAbulanza->GetValue() )
    {
		if ( m_AltraAmbulanza->GetValue().IsEmpty())
		{
	        WARNING_MESSAGE( _("Non e' stato inserito l'altro mezzo che trasporta il paziente") );
		    m_AltraAmbulanza->SetFocus();
			return;
		}
		m_Patient[FIELD_TRASPORTATO_LUOGO] = wxString::Format( _T("%s%s"), szServiceResult[SERVICERESULT_TRANSPORT_BY], m_AltraAmbulanza->GetValue().c_str() );
        m_Patient[FIELD_TRASPORTATO_CAP] = wxEmptyString;
        m_Patient[FIELD_TRASPORTATO_CITTA] = wxEmptyString;
        m_Patient[FIELD_TRASPORTATO_PROVINCIA] = wxEmptyString;
    }
    else
    {
        WARNING_MESSAGE( _("Non e' stato inserito l'esito del servizio") );
        return;
    }

//	if ( m_Trasportato->GetValue() )
//    {
//        if ( m_Triage->GetValue().IsEmpty() )
//        {
//            WARNING_MESSAGE( _("Non e' stato inserito il Codice Triage") );
//            m_Triage->SetFocus();
//            return;
//        }
//        m_Patient[FIELD_TRIAGE] = m_Triage->GetValue();					
//    }

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatient118Dlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}
