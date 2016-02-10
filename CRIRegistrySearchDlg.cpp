#include "CRIRegistrySearchDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistrySearchDlg::CRIRegistrySearchDlg( wxWindow* parent ):
SearchDlg( parent )
{
    SetIcon( wxICON(SearchIcon) );
	m_Field->Append( wxArrayString( CHAR_LIST_SIZE(szSearchBy), szSearchBy ) );
    
    wxDateTime dt( wxDateTime::Now() );

    dt.SetDay( 1 );
    dt.SetMonth( wxDateTime::Jan );
    m_date_Start->SetValue( dt );

    dt.SetMonth( wxDateTime::Dec );
    m_date_End->SetValue( dt );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySearchDlg::OnExitCtrl( wxFocusEvent& event )
{
	switch ( event.GetId() )
	{
	case ID_VALUE:
		m_Value->SetValue( m_Value->GetValue().Upper() );
		break;
	}

	event.Skip();
}
/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySearchDlg::OnOk( wxCommandEvent& event )
{
	if ( m_Field->GetSelection() > 0 )
	{
		m_iField = m_Field->GetSelection();
		m_szValue = m_Value->GetValue();
		m_szValue.Replace( _T("*"), _T("%%"), true );
        m_szDateStart = m_date_Start->GetValue().FormatISODate();
        m_szDateEnd = m_date_End->GetValue().FormatISODate();
		EndModal( wxID_OK );
	}
	else
	{
	    EndModal( wxID_CANCEL );
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySearchDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}

