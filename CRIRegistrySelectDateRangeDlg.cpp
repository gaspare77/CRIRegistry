#include "CRIRegistrySelectDateRangeDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistrySelectDateRangeDlg::CRIRegistrySelectDateRangeDlg( wxWindow* parent, const wxString& text ) :
SelectDateRangeDlg( parent )
{
    SetIcon( wxICON(CalendarIcon) );

    wxDateTime start,end;

    start = wxDateTime::Now();
    start.SetDay( 1 );

    end = wxDateTime::Now();
    end.SetToLastMonthDay();

    m_date_Start->SetValue( start );
    m_date_End->SetValue( end );
    m_Text->SetLabel( text );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySelectDateRangeDlg::OnOk( wxCommandEvent& event )
{
    m_dtDateStart = m_date_Start->GetValue();
    m_dtDateEnd = m_date_End->GetValue();

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistrySelectDateRangeDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}

