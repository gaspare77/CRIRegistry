#include "CRIRegistryCrewDlg.h"

/////////////////////////////////////////////////////////////////////////////
//
//
CRIRegistryCrewDlg::CRIRegistryCrewDlg( wxWindow* parent, const CServiceCrew& crew ):
CrewDlg( parent ), m_Crew( crew )
{
    SetIcon( wxICON(CrewIcon) );

    wxArrayString aszQualification( CHAR_LIST_SIZE(szQualification), szQualification );
    m_Qualifica->Append( aszQualification );

    wxArrayString aszQualificationStatus( CHAR_LIST_SIZE(szQualificationStatus), szQualificationStatus );
    m_QualificaStato->Append( aszQualificationStatus );

	wxString query;
	wxArrayString azsList;

    query = wxString::Format( _T("SELECT DISTINCT(%s) FROM %s ORDER BY %s"), FIELD_COGNOME, TABLE_REGISTROSERVIZI_EQUIPAGGI, FIELD_COGNOME );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Cognome->Append( azsList );

    query = wxString::Format( _T("SELECT DISTINCT(%s) FROM %s ORDER BY %s"), FIELD_NOME, TABLE_REGISTROSERVIZI_EQUIPAGGI, FIELD_NOME );
    azsList = dbSingleton::Instance()->SQLGetColArray( query );
    m_Nome->Append( azsList );

	m_Cognome->SetValue( m_Crew[FIELD_COGNOME].GetStringValue() );
    m_Nome->SetValue( m_Crew[FIELD_NOME].GetStringValue() );
    m_Qualifica->SetStringSelection( m_Crew[FIELD_QUALIFICA].GetStringValue() );
    m_QualificaStato->SetStringSelection( m_Crew[FIELD_QUALIFICASTATO].GetStringValue() );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryCrewDlg::OnWrite( wxKeyEvent& event )
{
	int k = event.GetKeyCode();
    if ( k == 8 || k == 9 || k == 13 || k == 27 || k == 127 || k >= 300 )
	{
		event.Skip();
        return;
	}

    switch ( event.GetId() )
	{
    case ID_COGNOME:
		::ComboBoxChangeWithSearch( m_Cognome );
        break;

    case ID_NOME:
		::ComboBoxChangeWithSearch( m_Nome );
        break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryCrewDlg::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_COGNOME:
		m_Cognome->SetValue( m_Cognome->GetValue().Upper() );
        break;

	case ID_NOME:
		m_Nome->SetValue( m_Nome->GetValue().Upper() );
        break;
	}

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryCrewDlg::OnOk( wxCommandEvent& event )
{
    m_Crew[FIELD_COGNOME] = m_Cognome->GetValue();
    m_Crew[FIELD_NOME] = m_Nome->GetValue();
    m_Crew[FIELD_QUALIFICA] = m_Qualifica->GetStringSelection();
    m_Crew[FIELD_QUALIFICASTATO] = m_QualificaStato->GetStringSelection();

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryCrewDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}
