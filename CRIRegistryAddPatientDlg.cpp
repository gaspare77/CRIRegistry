#include "CRIRegistryAddPatientDlg.h"

/////////////////////////////////////////////////////////////////////////////
//
//
CRIRegistryAddPatientDlg::CRIRegistryAddPatientDlg( wxWindow* parent, const CServicePatient& patient ):
AddPatientDlg( parent ), m_Patient( patient )
{
    SetIcon( wxICON(PatientIcon) );
    
    m_Ospedale->Clear();

    wxString query = wxString::Format( _T("SELECT %s FROM %s ORDER BY %s"), FIELD_NOME, TABLE_OSPEDALI, FIELD_NOME );
    m_Ospedale->Append( dbSingleton::Instance()->SQLGetColArray( query ) );

	m_Stato->Append( wxArrayString( CHAR_LIST_SIZE(szStates), szStates ) );
    
    m_Cognome->SetValue( m_Patient[FIELD_COGNOME].GetStringValue() );
    m_Nome->SetValue( m_Patient[FIELD_NOME].GetStringValue() );
	m_CodFiscale->SetValue( m_Patient[FIELD_COD_FISCALE].GetStringValue() );
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

    wxString szHospital;
    if ( m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue() == szServiceResult[SERVICERESULT_HOME] )
    {
        m_Abitazione_Checked->SetValue( true );
    }
    else if ( m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue().StartsWith( szServiceResult[SERVICERESULT_HOSPITAL], &szHospital ) )
    {
        m_Ospedale_Checked->SetValue( true );
        m_Ospedale->SetStringSelection( szHospital );
    }
    else if ( !m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue().IsEmpty() )
    {
        m_Altro_Luogo_Checked->SetValue( true );
        m_Trasportato_Luogo->SetValue( m_Patient[FIELD_TRASPORTATO_LUOGO].GetStringValue() );
        m_Trasportato_CAP->SetValue( m_Patient[FIELD_TRASPORTATO_CAP].GetStringValue() );
        m_Trasportato_Citta->SetValue( m_Patient[FIELD_TRASPORTATO_CITTA].GetStringValue() );
        m_Trasportato_Provincia->SetValue( m_Patient[FIELD_TRASPORTATO_PROVINCIA].GetStringValue() );
    }
    else
    {
        m_Abitazione_Checked->SetValue( false );

        m_Ospedale_Checked->SetValue( false );
        m_Ospedale->Enable( false );
        m_Ospedale->SetSelection( -1 );

        m_Altro_Luogo_Checked->SetValue( false );
        m_Trasportato_Luogo->Enable( false );
        m_Trasportato_Luogo->Clear();
        m_Trasportato_CAP->Enable( false );
        m_Trasportato_CAP->Clear();
        m_Trasportato_Citta->Enable( false );
        m_Trasportato_Citta->Clear();
        m_Trasportato_Provincia->Enable( false );
        m_Trasportato_Provincia->Clear();        
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatientDlg::OnExitCtrl( wxFocusEvent& event )
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
    case ID_TRASPORTATO_LUOGO:
        m_Trasportato_Luogo->SetValue( m_Trasportato_Luogo->GetValue().MakeUpper() );
        break;
    case ID_TRASPORTATO_CAP:
        m_Trasportato_CAP->SetValue( m_Trasportato_CAP->GetValue().MakeUpper() );
        break;
    case ID_TRASPORTATO_CITTA:
        m_Trasportato_Citta->SetValue( m_Trasportato_Citta->GetValue().MakeUpper() );
        break;
    case ID_TRASPORTATO_PROVINCIA:
        m_Trasportato_Provincia->SetValue( m_Trasportato_Provincia->GetValue().MakeUpper() );
        break;
    }
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatientDlg::OnOk( wxCommandEvent& event )
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
    m_Patient[FIELD_FIRMA_SCHEDA_CRI] = wxEmptyString;
    m_Patient[FIELD_FIRMA_SCHEDA_118] = wxEmptyString;

    if ( m_Ospedale_Checked->GetValue() )
    {
        if ( !m_HospitalSelected.LoadFromDb( m_Ospedale->GetStringSelection() ) )
        {
			m_Ospedale->SetFocus();
            return;
        }
        m_Patient[FIELD_TRASPORTATO_LUOGO] = wxString::Format( _T("%s%s"), szServiceResult[SERVICERESULT_HOSPITAL], m_HospitalSelected.GetNome() );
        m_Patient[FIELD_TRASPORTATO_CAP] = m_HospitalSelected.GetCAP();
        m_Patient[FIELD_TRASPORTATO_CITTA] = m_HospitalSelected.GetCitta();
        m_Patient[FIELD_TRASPORTATO_PROVINCIA] = m_HospitalSelected.GetProvincia();
    }
    else if ( m_Abitazione_Checked->GetValue() )
    {
		m_Patient[FIELD_TRASPORTATO_LUOGO] =  szServiceResult[SERVICERESULT_HOME];
        m_Patient[FIELD_TRASPORTATO_CAP] = m_CAP->GetValue();
        m_Patient[FIELD_TRASPORTATO_CITTA] = m_Citta->GetValue();
        m_Patient[FIELD_TRASPORTATO_PROVINCIA] = m_Provincia->GetValue();
    }
    else if ( m_Altro_Luogo_Checked->GetValue() )
    {
		if ( m_Trasportato_Luogo->GetValue().IsEmpty())
		{
	        WARNING_MESSAGE( _("Non e' stato inserito il luogo dove e' stato trasportato il paziente") );
		    m_Trasportato_Luogo->SetFocus();
			return;
		}
		m_Patient[FIELD_TRASPORTATO_LUOGO] = m_Trasportato_Luogo->GetValue();
        m_Patient[FIELD_TRASPORTATO_CAP] = m_Trasportato_CAP->GetValue();
        m_Patient[FIELD_TRASPORTATO_CITTA] = m_Trasportato_Citta->GetValue();
        m_Patient[FIELD_TRASPORTATO_PROVINCIA] = m_Trasportato_Provincia->GetValue();
    }
    else
    {
        WARNING_MESSAGE( _("Non e' stato inserito dove e' stato trasportato il paziente") );
        return;
    }

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatientDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryAddPatientDlg::OnCheckBox( wxCommandEvent& event )
{
    if ( m_Abitazione_Checked->GetValue() && event.GetId() == ID_ABITAZIONE_CHECKED )
    {
//        m_Abitazione_Checked->SetValue( false );

        m_Ospedale_Checked->SetValue( false );
        m_Ospedale->Enable( false );
        m_Ospedale->SetSelection( -1 );

        m_Altro_Luogo_Checked->SetValue( false );
        m_Trasportato_Luogo->Enable( false );
        m_Trasportato_Luogo->Clear();
        m_Trasportato_CAP->Enable( false );
        m_Trasportato_CAP->Clear();
        m_Trasportato_Citta->Enable( false );
        m_Trasportato_Citta->Clear();
        m_Trasportato_Provincia->Enable( false );
        m_Trasportato_Provincia->Clear();        
    }
    else if ( m_Ospedale_Checked->GetValue() && event.GetId() == ID_OSPEDALE_CHECKED )
    {
        m_Abitazione_Checked->SetValue( false );

//        m_Ospedale_Checked->SetValue( false );
        m_Ospedale->Enable( true );
//        m_Ospedale->SetSelection( -1 );

        m_Altro_Luogo_Checked->SetValue( false );
        m_Trasportato_Luogo->Enable( false );
        m_Trasportato_Luogo->Clear();
        m_Trasportato_CAP->Enable( false );
        m_Trasportato_CAP->Clear();
        m_Trasportato_Citta->Enable( false );
        m_Trasportato_Citta->Clear();
        m_Trasportato_Provincia->Enable( false );
        m_Trasportato_Provincia->Clear();        
    }
    else if ( m_Altro_Luogo_Checked->GetValue() && event.GetId() == ID_ALTRO_LUOGO_CHECKED )
    {
        m_Abitazione_Checked->SetValue( false );

        m_Ospedale_Checked->SetValue( false );
        m_Ospedale->Enable( false );
        m_Ospedale->SetSelection( -1 );

//        m_Altro_Luogo_Checked->SetValue( false );
        m_Trasportato_Luogo->Enable( true );
//        m_Trasportato_Luogo->Clear()
        m_Trasportato_CAP->Enable( true );
//        m_Trasportato_CAP->Clear();
        m_Trasportato_Citta->Enable( true );
//        m_Trasportato_Citta->Clear();
        m_Trasportato_Provincia->Enable( true );
//        m_Trasportato_Provincia->Clear();        
    }
    else
    {
        m_Abitazione_Checked->SetValue( false );

        m_Ospedale_Checked->SetValue( false );
        m_Ospedale->Enable( false );
        m_Ospedale->SetSelection( -1 );

        m_Altro_Luogo_Checked->SetValue( false );
        m_Trasportato_Luogo->Enable( false );
        m_Trasportato_Luogo->Clear();
        m_Trasportato_CAP->Enable( false );
        m_Trasportato_CAP->Clear();
        m_Trasportato_Citta->Enable( false );
        m_Trasportato_Citta->Clear();
        m_Trasportato_Provincia->Enable( false );
        m_Trasportato_Provincia->Clear();        
    }
}
