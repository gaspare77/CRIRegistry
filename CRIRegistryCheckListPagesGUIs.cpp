///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CRIRegistryCheckListPagesGUIs.h"

///////////////////////////////////////////////////////////////////////////

CheckListTimeIntervalDlg::CheckListTimeIntervalDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer0;
	bSizer0 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_Orari = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer1->Add( m_Orari, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Edit = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton_Edit, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer8, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	bSizer0->Add( bSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer6->Add( m_staticline1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer0->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer0->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer0 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnAdd ), NULL, this );
	m_bpButton_Edit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnEdit ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnDel ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnCancel ), NULL, this );
}

CheckListTimeIntervalDlg::~CheckListTimeIntervalDlg()
{
	// Disconnect Events
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnAdd ), NULL, this );
	m_bpButton_Edit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnEdit ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnDel ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeIntervalDlg::OnCancel ), NULL, this );
	
}

CheckListTimeDlg::CheckListTimeDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Turno"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	m_staticText4->Wrap( -1 );
	bSizer14->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Turno = new wxTextCtrl( this, ID_TURNO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_Turno, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer13->Add( bSizer14, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, _("Inizo"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	m_staticText41->Wrap( -1 );
	bSizer141->Add( m_staticText41, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Inizio = new wxTextCtrl( this, ID_INIZIO, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxTE_CENTRE );
	bSizer141->Add( m_Inizio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer13->Add( bSizer141, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, _("Fine"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	m_staticText42->Wrap( -1 );
	bSizer142->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Fine = new wxTextCtrl( this, ID_FINE, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxTE_CENTRE );
	bSizer142->Add( m_Fine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer13->Add( bSizer142, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer6->Add( m_staticline1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer13->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer13->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer13 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Turno->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListTimeDlg::OnExitCtrl ), NULL, this );
	m_Inizio->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListTimeDlg::OnExitCtrl ), NULL, this );
	m_Fine->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListTimeDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeDlg::OnCancel ), NULL, this );
}

CheckListTimeDlg::~CheckListTimeDlg()
{
	// Disconnect Events
	m_Turno->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListTimeDlg::OnExitCtrl ), NULL, this );
	m_Inizio->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListTimeDlg::OnExitCtrl ), NULL, this );
	m_Fine->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListTimeDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListTimeDlg::OnCancel ), NULL, this );
	
}

CheckListAddItemDlg::CheckListAddItemDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, _("Testo"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText10->Wrap( -1 );
	bSizer30->Add( m_staticText10, 0, wxALL, 5 );
	
	m_Testo = new wxTextCtrl( this, ID_TESTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_Testo->SetMaxLength( 255 ); 
	bSizer30->Add( m_Testo, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer27->Add( bSizer30, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer291;
	bSizer291 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, _("Posizione"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText91->Wrap( -1 );
	bSizer291->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_PosizioneChoices;
	m_Posizione = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_PosizioneChoices, 0 );
	m_Posizione->SetSelection( 0 );
	bSizer291->Add( m_Posizione, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_EditPosition = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_EditPosition->SetToolTip( _("Edit Posizioni") );
	
	bSizer291->Add( m_bpButton_EditPosition, 0, wxALL, 5 );
	
	
	bSizer27->Add( bSizer291, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("Orari"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText13->Wrap( -1 );
	bSizer46->Add( m_staticText13, 0, wxALL, 5 );
	
	wxArrayString m_ListaOrariChoices;
	m_ListaOrari = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_ListaOrariChoices, wxLB_EXTENDED|wxLB_MULTIPLE|wxLB_NEEDED_SB );
	bSizer46->Add( m_ListaOrari, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer27->Add( bSizer46, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer6->Add( m_staticline1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer27->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer27->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer27 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Testo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListAddItemDlg::OnExitCtrl ), NULL, this );
	m_Posizione->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CheckListAddItemDlg::OnChoice ), NULL, this );
	m_bpButton_EditPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListAddItemDlg::OnEditPosition ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListAddItemDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListAddItemDlg::OnCancel ), NULL, this );
}

CheckListAddItemDlg::~CheckListAddItemDlg()
{
	// Disconnect Events
	m_Testo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CheckListAddItemDlg::OnExitCtrl ), NULL, this );
	m_Posizione->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CheckListAddItemDlg::OnChoice ), NULL, this );
	m_bpButton_EditPosition->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListAddItemDlg::OnEditPosition ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListAddItemDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListAddItemDlg::OnCancel ), NULL, this );
	
}

CheckListEditDlg::CheckListEditDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText14->Wrap( -1 );
	bSizer48->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, ID_GRUPPO, wxDefaultPosition, wxDefaultSize, m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	bSizer48->Add( m_Gruppo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer47->Add( bSizer48, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxVERTICAL );
	
	m_Voci = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_HIDE_ROOT|wxTR_LINES_AT_ROOT );
	bSizer49->Add( m_Voci, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Edit = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton_Edit, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpButton_EditHours = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Clock.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer8->Add( m_bpButton_EditHours, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer49->Add( bSizer8, 0, wxEXPAND, 5 );
	
	
	bSizer47->Add( bSizer49, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer6->Add( m_staticline1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer47->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer47->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer47 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Gruppo->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CheckListEditDlg::OnChoice ), NULL, this );
	m_Voci->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( CheckListEditDlg::OnItemActivate ), NULL, this );
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnAdd ), NULL, this );
	m_bpButton_Edit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnEdit ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnDel ), NULL, this );
	m_bpButton_EditHours->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnEditHours ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnCancel ), NULL, this );
}

CheckListEditDlg::~CheckListEditDlg()
{
	// Disconnect Events
	m_Gruppo->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CheckListEditDlg::OnChoice ), NULL, this );
	m_Voci->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( CheckListEditDlg::OnItemActivate ), NULL, this );
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnAdd ), NULL, this );
	m_bpButton_Edit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnEdit ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnDel ), NULL, this );
	m_bpButton_EditHours->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnEditHours ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListEditDlg::OnCancel ), NULL, this );
	
}

CheckListDlg::CheckListDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,600 ), wxDefaultSize );
	
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer60->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Data = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	bSizer60->Add( m_Data, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, _("Turno"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer60->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Turno = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	bSizer60->Add( m_Turno, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer60->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Gruppo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	bSizer60->Add( m_Gruppo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer59->Add( bSizer60, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	m_ScrolledWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_ScrolledWindow->SetScrollRate( 5, 5 );
	m_Container = new wxBoxSizer( wxVERTICAL );
	
	
	m_ScrolledWindow->SetSizer( m_Container );
	m_ScrolledWindow->Layout();
	m_Container->Fit( m_ScrolledWindow );
	bSizer61->Add( m_ScrolledWindow, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer59->Add( bSizer61, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer6->Add( m_staticline1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer59->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer59->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer59 );
	this->Layout();
	bSizer59->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListDlg::OnCancel ), NULL, this );
}

CheckListDlg::~CheckListDlg()
{
	// Disconnect Events
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CheckListDlg::OnCancel ), NULL, this );
	
}
