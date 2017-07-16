#include "CRIRegistryCodeSelectionDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCodeSelectionDlg::CRIRegistryCodeSelectionDlg( wxWindow* parent, e118CodeType type, const wxString& code ):
wxDialog( parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 500,380 ), wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER )
{
    wxString query, szItem;
	dbResultSet res;
	size_t i;

    SetIcon( wxICON(EditIcon) );

    switch ( type )
    {
    case TYPE_CODE_GRAVITY:
        SetTitle( _("Selezionare il codice gravita'") );
    	query = wxString::Format( _T("SELECT * FROM %s"), TABLE_CODICI_GRAVITA );
        break;

    case TYPE_CODE_EVENT:
	case TYPE_CODE_ARRIVAL:
        SetTitle( _("Selezionare il codice patologia presunta") );
		query = wxString::Format( _T("SELECT * FROM %s"), TABLE_CODICI_PATOLOGIA_PRESUNTA );
		break;

	case TYPE_CODE_DEPARTURE:
	case TYPE_CODE_DEPARTURE_2:
	case TYPE_CODE_RELEASE:
        SetTitle( _("Selezionare il codice patologia riscontrata") );
		query = wxString::Format( _T("SELECT * FROM %s"), TABLE_CODICI_PATOLOGIA_RISCONTRATA );
		break;

    case TYPE_CODE_DINAMIC:
        SetTitle( _("Selezionare il codice dinamica riscontrata") );
		query = wxString::Format( _T("SELECT * FROM %s"), TABLE_CODICI_DINAMICA_RISCONTRATA );
        break;
        
    case TYPE_CODE_TREATMENT:
        SetTitle( _("Selezionare il codice prestazione effettuate") );
		query = wxString::Format( _T("SELECT * FROM %s"), TABLE_CODICI_PRESTAZIONE );
        break;

    case TYPE_CODE_PLACE:
        SetTitle( _("Selezionare il codice luogo") );
       	query = wxString::Format( _T("SELECT * FROM %s"), TABLE_CODICI_LUOGO );
        break;
    }

	this->SetSizeHints( wxSize( 500,380 ), wxSize( 800,600 ) );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer220;
	bSizer220 = new wxBoxSizer( wxVERTICAL );
	
	m_CodeList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE ); 
	if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		for ( i = 0; i < res.GetSize(); i++ )
		{
			szItem = wxString::Format( _T("[%s] - %s"), res.Row(i).Col(FIELD_CODICE).GetCharValue(), res.Row(i).Col(FIELD_DESCRIZIONE).GetCharValue() );
			m_CodeList->Append( szItem );
		}
	}
	bSizer220->Add( m_CodeList, 1, wxALL|wxEXPAND, 5 );
	bSizer65->Add( bSizer220, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer781;
	bSizer781 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer781->Add( m_staticline1, 1, wxALL, 5 );
	bSizer65->Add( bSizer781, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer67->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer67->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	bSizer65->Add( bSizer67, 0, wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer65 );
	this->Layout();
	this->Centre( wxBOTH );

    SelectCode( code );

	// Connect Events
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CRIRegistryCodeSelectionDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CRIRegistryCodeSelectionDlg::OnCancel ), NULL, this );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCodeSelectionDlg::~CRIRegistryCodeSelectionDlg()
{
	// Disconnect Events
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CRIRegistryCodeSelectionDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CRIRegistryCodeSelectionDlg::OnCancel ), NULL, this );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCodeSelectionDlg::SelectCode( const wxString& code )
{
	for ( unsigned int i = 0; i < m_CodeList->GetCount(); i++ )
	{
		wxString s = m_CodeList->GetString(i);
		if ( code == s.SubString( s.Find( _T("[") )+1, s.Find( _T("]") )-1 ) )
		{
            m_CodeList->SetSelection( i );
            m_CodeList->EnsureVisible( i );
			return;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCodeSelectionDlg::OnOk( wxCommandEvent& event )
{
    wxString s = m_CodeList->GetStringSelection(); 
    m_szCode = s.SubString( s.Find( _T("[") )+1, s.Find( _T("]") )-1 );
    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCodeSelectionDlg::OnCancel( wxCommandEvent& event )
{
    m_szCode = wxEmptyString;
    EndModal( wxID_CANCEL );
}
