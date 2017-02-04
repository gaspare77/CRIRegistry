///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TxtCtrl118Code.h"

#include "CRIRegistryWizardPagesGUIs.h"

///////////////////////////////////////////////////////////////////////////

Gruppo::Gruppo( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Selezionare il Gruppo *") ), wxVERTICAL );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	sbSizer2->Add( m_Gruppo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
}

Gruppo::~Gruppo()
{
}

Data::Data( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Selezionare il giorno *") ), wxVERTICAL );
	
	m_Data = new wxCalendarCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_MONDAY_FIRST|wxCAL_SEQUENTIAL_MONTH_SELECTION|wxCAL_SHOW_HOLIDAYS|wxCAL_SHOW_SURROUNDING_WEEKS );
	sbSizer4->Add( m_Data, 0, wxALL, 5 );
	
	
	bSizer73->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Inserire gli orari del Servizio") ), wxVERTICAL );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Inizio Servizio/Allarme *"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	m_staticText22->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer25->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraInizio = new wxTextCtrl( this, ID_ORA_INIZIO, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraInizio->SetMaxLength( 0 ); 
	bSizer25->Add( m_OraInizio, 0, wxALL, 5 );
	
	
	sbSizer41->Add( bSizer25, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221 = new wxStaticText( this, wxID_ANY, _("Partenza"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText221->Wrap( -1 );
	m_staticText221->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer62->Add( m_staticText221, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraPartenza = new wxTextCtrl( this, ID_ORA_PARTENZA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraPartenza->SetMaxLength( 0 ); 
	bSizer62->Add( m_OraPartenza, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer41->Add( bSizer62, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer621;
	bSizer621 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2211 = new wxStaticText( this, wxID_ANY, _("Arrivo Target/R.V."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2211->Wrap( -1 );
	m_staticText2211->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer621->Add( m_staticText2211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraArrivoTarget = new wxTextCtrl( this, ID_ORA_ARRIVO_TARGET, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraArrivoTarget->SetMaxLength( 0 ); 
	bSizer621->Add( m_OraArrivoTarget, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer41->Add( bSizer621, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer622;
	bSizer622 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2212 = new wxStaticText( this, wxID_ANY, _("Partenza Target/R.V."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2212->Wrap( -1 );
	m_staticText2212->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer622->Add( m_staticText2212, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraPartenzaTarget = new wxTextCtrl( this, ID_ORA_PARTENZA_TARGET, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraPartenzaTarget->SetMaxLength( 0 ); 
	bSizer622->Add( m_OraPartenzaTarget, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer41->Add( bSizer622, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer623;
	bSizer623 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2213 = new wxStaticText( this, wxID_ANY, _("Arrivo H/Altro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2213->Wrap( -1 );
	m_staticText2213->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer623->Add( m_staticText2213, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraArrivo = new wxTextCtrl( this, ID_ORA_ARRIVO, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraArrivo->SetMaxLength( 0 ); 
	bSizer623->Add( m_OraArrivo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer41->Add( bSizer623, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6241;
	bSizer6241 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22141 = new wxStaticText( this, wxID_ANY, _("Operativo/Fine Servizio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22141->Wrap( -1 );
	m_staticText22141->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer6241->Add( m_staticText22141, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraFine = new wxTextCtrl( this, ID_ORA_FINE, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraFine->SetMaxLength( 0 ); 
	bSizer6241->Add( m_OraFine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer41->Add( bSizer6241, 1, wxEXPAND, 5 );
	
	
	bSizer73->Add( sbSizer41, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer73, 1, 0, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_OraInizio->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraPartenza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraArrivoTarget->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraPartenzaTarget->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraArrivo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraFine->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
}

Data::~Data()
{
	// Disconnect Events
	m_OraInizio->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraPartenza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraArrivoTarget->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraPartenzaTarget->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraArrivo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	m_OraFine->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Data::OnExitCtrl ), NULL, this );
	
}

Equipaggio::Equipaggio( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Selezionare il Mezzo *") ), wxVERTICAL );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString m_MezzoChoices;
	m_Mezzo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_MezzoChoices, 0 );
	m_Mezzo->SetSelection( 0 );
	bSizer48->Add( m_Mezzo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Targa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer48->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Targa = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Targa->SetMaxLength( 0 ); 
	bSizer48->Add( m_Targa, 0, wxALL, 5 );
	
	m_staticText311 = new wxStaticText( this, wxID_ANY, _("Tipo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText311->Wrap( -1 );
	bSizer48->Add( m_staticText311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Tipo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Tipo->SetMaxLength( 0 ); 
	bSizer48->Add( m_Tipo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer3->Add( bSizer48, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer1->Add( sbSizer3, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Equipaggio di Servizio *") ), wxVERTICAL );
	
	m_Equipaggio = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	sbSizer2->Add( m_Equipaggio, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer12->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Modify = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer12->Add( m_bpButton_Modify, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer12->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer12, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_Mezzo->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Equipaggio::OnChoice ), NULL, this );
	m_Equipaggio->Connect( wxEVT_SIZE, wxSizeEventHandler( Equipaggio::OnSize ), NULL, this );
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Equipaggio::OnAdd ), NULL, this );
	m_bpButton_Modify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Equipaggio::OnModify ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Equipaggio::OnDel ), NULL, this );
}

Equipaggio::~Equipaggio()
{
	// Disconnect Events
	m_Mezzo->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Equipaggio::OnChoice ), NULL, this );
	m_Equipaggio->Disconnect( wxEVT_SIZE, wxSizeEventHandler( Equipaggio::OnSize ), NULL, this );
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Equipaggio::OnAdd ), NULL, this );
	m_bpButton_Modify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Equipaggio::OnModify ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Equipaggio::OnDel ), NULL, this );
	
}

Richiesto::Richiesto( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Servizio Richiesto da *") ), wxVERTICAL );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer61->SetMinSize( wxSize( -1,30 ) ); 
	m_radio_118 = new wxRadioButton( this, ID_118, _("118"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizer61->Add( m_radio_118, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( bSizer61, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer611->SetMinSize( wxSize( -1,30 ) ); 
	m_radio_Asl = new wxRadioButton( this, ID_ASL, _("ASL"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizer611->Add( m_radio_Asl, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( bSizer611, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer62->SetMinSize( wxSize( -1,30 ) ); 
	m_radio_Parenti = new wxRadioButton( this, ID_PARENTI, _("Parenti"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizer62->Add( m_radio_Parenti, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( bSizer62, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer63->SetMinSize( wxSize( -1,30 ) ); 
	m_radio_Ospedali = new wxRadioButton( this, ID_OSPEDALI, _("Ospedali"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizer63->Add( m_radio_Ospedali, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer63a;
	bSizer63a = new wxBoxSizer( wxVERTICAL );
	
	wxArrayString m_OspedaleChoices;
	m_Ospedale = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_OspedaleChoices, 0 );
	m_Ospedale->SetSelection( 0 );
	bSizer63a->Add( m_Ospedale, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer63->Add( bSizer63a, 1, wxEXPAND, 5 );
	
	
	sbSizer1->Add( bSizer63, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer64->SetMinSize( wxSize( -1,30 ) ); 
	m_radio_Altri = new wxRadioButton( this, ID_ALTRI, _("Altri"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizer64->Add( m_radio_Altri, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( bSizer64, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer65->SetMinSize( wxSize( -1,30 ) ); 
	m_radio_ServizioInterno = new wxRadioButton( this, ID_SERVIZIO_INTERNO, _("Servizio Interno"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizer65->Add( m_radio_ServizioInterno, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( bSizer65, 0, wxEXPAND, 5 );
	
	
	bSizer17->Add( sbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Selezionare la tipologia di servizio *") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString m_TipoChoices;
	m_Tipo = new wxChoice( this, ID_TIPO, wxDefaultPosition, wxSize( 200,-1 ), m_TipoChoices, 0 );
	m_Tipo->SetSelection( 0 );
	bSizer25->Add( m_Tipo, 0, wxALL, 5 );
	
	m_AltraTipologia = new wxTextCtrl( this, ID_ALTRA_TIPOLOGIA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_AltraTipologia, 1, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer25, 1, 0, 5 );
	
	
	bSizer17->Add( sbSizer2, 0, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizer17 );
	this->Layout();
	
	// Connect Events
	m_radio_118->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_Asl->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_Parenti->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_Ospedali->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_Ospedale->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Richiesto::OnChoice ), NULL, this );
	m_radio_Altri->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_ServizioInterno->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_Tipo->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Richiesto::OnChoice ), NULL, this );
	m_AltraTipologia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiesto::OnExitCtrl ), NULL, this );
}

Richiesto::~Richiesto()
{
	// Disconnect Events
	m_radio_118->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_Asl->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_Parenti->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_Ospedali->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_Ospedale->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Richiesto::OnChoice ), NULL, this );
	m_radio_Altri->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_radio_ServizioInterno->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Richiesto::OnCheck ), NULL, this );
	m_Tipo->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Richiesto::OnChoice ), NULL, this );
	m_AltraTipologia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiesto::OnExitCtrl ), NULL, this );
	
}

Paziente::Paziente( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Dati del paziente trasportato") ), wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Cognome *"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	m_staticText4->Wrap( -1 );
	bSizer18->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxTextCtrl( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cognome->SetMaxLength( 0 ); 
	bSizer18->Add( m_Cognome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText46 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	bSizer18->Add( m_staticText46, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxTextCtrl( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Nome->SetMaxLength( 0 ); 
	bSizer18->Add( m_Nome, 1, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText45 = new wxStaticText( this, wxID_ANY, _("Codice Fiscale"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	m_staticText45->Wrap( -1 );
	bSizer181->Add( m_staticText45, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodFiscale = new wxTextCtrl( this, ID_CODICE_FISCALE, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_CodFiscale->SetMaxLength( 0 ); 
	bSizer181->Add( m_CodFiscale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer181, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText44 = new wxStaticText( this, wxID_ANY, _("Data Nascita"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	m_staticText44->Wrap( -1 );
	bSizer55->Add( m_staticText44, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DataNascita = new wxTextCtrl( this, ID_DATA_NASCITA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_DataNascita->SetMaxLength( 0 ); 
	bSizer55->Add( m_DataNascita, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText47 = new wxStaticText( this, wxID_ANY, _("Eta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText47->Wrap( -1 );
	bSizer55->Add( m_staticText47, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Eta = new wxTextCtrl( this, ID_ETA, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_RIGHT );
	m_Eta->SetMaxLength( 0 ); 
	bSizer55->Add( m_Eta, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Anni = new wxRadioButton( this, wxID_ANY, _("Anni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_Anni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Mesi = new wxRadioButton( this, wxID_ANY, _("Mesi"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_Mesi, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Giorni = new wxRadioButton( this, wxID_ANY, _("Giorni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_Giorni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer55->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText43 = new wxStaticText( this, wxID_ANY, _("Sesso"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText43->Wrap( -1 );
	bSizer55->Add( m_staticText43, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_SessoChoices[] = { _(" -"), _("M"), _("F") };
	int m_SessoNChoices = sizeof( m_SessoChoices ) / sizeof( wxString );
	m_Sesso = new wxChoice( this, ID_SESSO, wxDefaultPosition, wxSize( 60,-1 ), m_SessoNChoices, m_SessoChoices, 0 );
	m_Sesso->SetSelection( 0 );
	bSizer55->Add( m_Sesso, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer55, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	m_staticText41->Wrap( -1 );
	bSizer17->Add( m_staticText41, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Indirizzo = new wxTextCtrl( this, ID_INDIRIZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Indirizzo->SetMaxLength( 0 ); 
	bSizer17->Add( m_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer17->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Civico = new wxTextCtrl( this, ID_CIVICO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Civico->SetMaxLength( 0 ); 
	bSizer17->Add( m_Civico, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer17, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	m_staticText16->Wrap( -1 );
	bSizer171->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer171->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer171->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer171->Add( m_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer171->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer171->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer171, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1711;
	bSizer1711 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText161 = new wxStaticText( this, wxID_ANY, _("Stato"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	m_staticText161->Wrap( -1 );
	bSizer1711->Add( m_staticText161, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_StatoChoices;
	m_Stato = new wxChoice( this, ID_STATO, wxDefaultPosition, wxDefaultSize, m_StatoChoices, 0 );
	m_Stato->SetSelection( 0 );
	bSizer1711->Add( m_Stato, 1, wxALL, 5 );
	
	m_staticText171 = new wxStaticText( this, wxID_ANY, _("Cittadinanza"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText171->Wrap( -1 );
	bSizer1711->Add( m_staticText171, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cittadinanza = new wxTextCtrl( this, ID_CITTADINANZA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cittadinanza->SetMaxLength( 0 ); 
	bSizer1711->Add( m_Cittadinanza, 1, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer1711, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText451 = new wxStaticText( this, wxID_ANY, _("Motivo del Trasporto *"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	m_staticText451->Wrap( -1 );
	bSizer56->Add( m_staticText451, 0, wxALL|wxEXPAND, 5 );
	
	m_MotivoTrasporto = new wxTextCtrl( this, ID_MOTIVOTRASPORTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_MotivoTrasporto->SetMaxLength( 0 ); 
	bSizer56->Add( m_MotivoTrasporto, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizer2->Add( bSizer56, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText78 = new wxStaticText( this, wxID_ANY, _("Tipologia pagamento *"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText78->Wrap( -1 );
	bSizer75->Add( m_staticText78, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_TipologiaPagamentoChoices;
	m_TipologiaPagamento = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_TipologiaPagamentoChoices, 0 );
	m_TipologiaPagamento->SetSelection( 0 );
	bSizer75->Add( m_TipologiaPagamento, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText79 = new wxStaticText( this, wxID_ANY, _("Importo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText79->Wrap( -1 );
	bSizer75->Add( m_staticText79, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Importo = new wxTextCtrl( this, ID_IMPORTO, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxTE_RIGHT );
	m_Importo->SetMaxLength( 0 ); 
	bSizer75->Add( m_Importo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText80 = new wxStaticText( this, wxID_ANY, _("Euro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText80->Wrap( -1 );
	bSizer75->Add( m_staticText80, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer75, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_CodFiscale->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_DataNascita->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Eta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Civico->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_MotivoTrasporto->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Importo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
}

Paziente::~Paziente()
{
	// Disconnect Events
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_CodFiscale->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_DataNascita->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Eta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Civico->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_MotivoTrasporto->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	m_Importo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Paziente::OnExitCtrl ), NULL, this );
	
}

Richiedente::Richiedente( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Dati di chi richiede il servizio") ), wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Nominativo *"), wxDefaultPosition, wxSize( 65,-1 ), 0 );
	m_staticText4->Wrap( -1 );
	bSizer18->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nominativo = new wxTextCtrl( this, ID_NOMINATIVO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Nominativo->SetMaxLength( 0 ); 
	bSizer18->Add( m_Nominativo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText45 = new wxStaticText( this, wxID_ANY, _("C.F./P.IVA"), wxDefaultPosition, wxSize( 65,-1 ), 0 );
	m_staticText45->Wrap( -1 );
	bSizer181->Add( m_staticText45, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodFiscale_Piva = new wxTextCtrl( this, ID_CF_PIVA, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_CodFiscale_Piva->SetMaxLength( 0 ); 
	bSizer181->Add( m_CodFiscale_Piva, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer181, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 65,-1 ), 0 );
	m_staticText42->Wrap( -1 );
	bSizer17->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Indirizzo = new wxTextCtrl( this, ID_INDIRIZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Indirizzo->SetMaxLength( 0 ); 
	bSizer17->Add( m_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer17->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Civico = new wxTextCtrl( this, ID_CIVICO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Civico->SetMaxLength( 0 ); 
	bSizer17->Add( m_Civico, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer17, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 65,-1 ), 0 );
	m_staticText16->Wrap( -1 );
	bSizer171->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer171->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer171->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer171->Add( m_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer171->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer171->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer171, 0, wxEXPAND, 5 );
	
	
	sbSizer2->Add( 0, 30, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText78 = new wxStaticText( this, wxID_ANY, _("Tipologia pagamento *"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText78->Wrap( -1 );
	bSizer75->Add( m_staticText78, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_TipologiaPagamentoChoices;
	m_TipologiaPagamento = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_TipologiaPagamentoChoices, 0 );
	m_TipologiaPagamento->SetSelection( 0 );
	bSizer75->Add( m_TipologiaPagamento, 1, wxALL, 5 );
	
	m_staticText79 = new wxStaticText( this, wxID_ANY, _("Importo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText79->Wrap( -1 );
	bSizer75->Add( m_staticText79, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Importo = new wxTextCtrl( this, ID_IMPORTO, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxTE_RIGHT );
	m_Importo->SetMaxLength( 0 ); 
	bSizer75->Add( m_Importo, 0, wxALL, 5 );
	
	m_staticText80 = new wxStaticText( this, wxID_ANY, _("Euro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText80->Wrap( -1 );
	bSizer75->Add( m_staticText80, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer2->Add( bSizer75, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_Nominativo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_CodFiscale_Piva->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Civico->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Importo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
}

Richiedente::~Richiedente()
{
	// Disconnect Events
	m_Nominativo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_CodFiscale_Piva->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Civico->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	m_Importo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Richiedente::OnExitCtrl ), NULL, this );
	
}

LuogoIntervento::LuogoIntervento( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Selezionare il luogo di intervento *") ), wxVERTICAL );
	
	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Abitazione_Checked = new wxCheckBox( this, ID_ABITAZIONE_CHECKED, _("Abitazione del Paziente"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer82->Add( m_Abitazione_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer82, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Ospedale_Checked = new wxCheckBox( this, ID_OSPEDALE_CHECKED, _("Ospedale"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer83->Add( m_Ospedale_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_OspedaleChoices;
	m_Ospedale = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_OspedaleChoices, 0 );
	m_Ospedale->SetSelection( 0 );
	bSizer83->Add( m_Ospedale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer83, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_AltroLuogo_Checked = new wxCheckBox( this, ID_ALTRO_LUOGO_CHECKED, _("Altro Luogo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer84->Add( m_AltroLuogo_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Luogo = new wxTextCtrl( this, ID_LUOGO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Luogo->SetMaxLength( 0 ); 
	bSizer84->Add( m_Luogo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer84, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer85;
	bSizer85 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer85->Add( 90, 0, 0, wxEXPAND, 5 );
	
	m_CAP_Label = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_CAP_Label->Wrap( -1 );
	bSizer85->Add( m_CAP_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer85->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta_Label = new wxStaticText( this, wxID_ANY, _("Citta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta_Label->Wrap( -1 );
	bSizer85->Add( m_Citta_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer85->Add( m_Citta, 1, wxALL, 5 );
	
	m_Provincia_Label = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Provincia_Label->Wrap( -1 );
	bSizer85->Add( m_Provincia_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer85->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer85, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer4, 1, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_Abitazione_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento::OnCheck ), NULL, this );
	m_Ospedale_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento::OnCheck ), NULL, this );
	m_AltroLuogo_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento::OnCheck ), NULL, this );
	m_Luogo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
}

LuogoIntervento::~LuogoIntervento()
{
	// Disconnect Events
	m_Abitazione_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento::OnCheck ), NULL, this );
	m_Ospedale_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento::OnCheck ), NULL, this );
	m_AltroLuogo_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento::OnCheck ), NULL, this );
	m_Luogo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento::OnExitCtrl ), NULL, this );
	
}

LuogoIntervento118::LuogoIntervento118( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Selezionare il luogo di intervento *") ), wxVERTICAL );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_AltroLuogo_Checked = new wxCheckBox( this, ID_ALTRO_LUOGO_CHECKED, _("Target"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	bSizer84->Add( m_AltroLuogo_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Luogo = new wxTextCtrl( this, ID_LUOGO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Luogo->SetMaxLength( 0 ); 
	bSizer84->Add( m_Luogo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer84, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer85;
	bSizer85 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer85->Add( 80, 0, 0, wxEXPAND, 5 );
	
	m_CAP_Label = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_CAP_Label->Wrap( -1 );
	bSizer85->Add( m_CAP_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer85->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta_Label = new wxStaticText( this, wxID_ANY, _("Citta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta_Label->Wrap( -1 );
	bSizer85->Add( m_Citta_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer85->Add( m_Citta, 1, wxALL, 5 );
	
	m_Provincia_Label = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Provincia_Label->Wrap( -1 );
	bSizer85->Add( m_Provincia_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer85->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer85, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Ospedale_Checked = new wxCheckBox( this, ID_OSPEDALE_CHECKED, _("Ospedale"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	bSizer83->Add( m_Ospedale_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_OspedaleChoices;
	m_Ospedale = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_OspedaleChoices, 0 );
	m_Ospedale->SetSelection( 0 );
	bSizer83->Add( m_Ospedale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer83, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer4, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer15;
	sbSizer15 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Presenti sul posto") ), wxVERTICAL );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	m_Carabinieri_Checked = new wxCheckBox( this, wxID_ANY, _("Carabinieri"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( m_Carabinieri_Checked, 0, wxALL, 5 );
	
	m_Polizia_Checked = new wxCheckBox( this, wxID_ANY, _("Polizia"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( m_Polizia_Checked, 0, wxALL, 5 );
	
	m_Polizia_Municipale_Checked = new wxCheckBox( this, wxID_ANY, _("Polizia Municipale"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( m_Polizia_Municipale_Checked, 0, wxALL, 5 );
	
	m_Vigili_del_Fuoco_Checked = new wxCheckBox( this, wxID_ANY, _("Vigili del Fuoco"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( m_Vigili_del_Fuoco_Checked, 0, wxALL, 5 );
	
	m_Guardia_Medica_Checked = new wxCheckBox( this, wxID_ANY, _("Guardia Medica"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( m_Guardia_Medica_Checked, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Altro_Mezzo_Checked = new wxCheckBox( this, ID_ALTRO_MEZZO_CHECKED, _("Altro Mezzo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( m_Altro_Mezzo_Checked, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_AltroMezzo_Codice = new wxTextCtrl( this, ID_ALTRO_MEZZO_CODICE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_AltroMezzo_Codice->SetMaxLength( 0 ); 
	bSizer53->Add( m_AltroMezzo_Codice, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer46->Add( bSizer53, 0, wxEXPAND, 5 );
	
	
	sbSizer15->Add( bSizer46, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer15, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_AltroLuogo_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento118::OnCheck ), NULL, this );
	m_Luogo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_Ospedale_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento118::OnCheck ), NULL, this );
	m_Altro_Mezzo_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento118::OnCheck ), NULL, this );
	m_AltroMezzo_Codice->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
}

LuogoIntervento118::~LuogoIntervento118()
{
	// Disconnect Events
	m_AltroLuogo_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento118::OnCheck ), NULL, this );
	m_Luogo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	m_Ospedale_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento118::OnCheck ), NULL, this );
	m_Altro_Mezzo_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoIntervento118::OnCheck ), NULL, this );
	m_AltroMezzo_Codice->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoIntervento118::OnExitCtrl ), NULL, this );
	
}

InfoServizio118::InfoServizio118( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer13;
	sbSizer13 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Informazioni sul servizio 118") ), wxVERTICAL );
	
	wxBoxSizer* bSizer4511;
	bSizer4511 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer4511->SetMinSize( wxSize( -1,30 ) ); 
	m_staticText3311 = new wxStaticText( this, wxID_ANY, _("Codice radio 118 *"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText3311->Wrap( -1 );
	bSizer4511->Add( m_staticText3311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodRadio118 = new wxTextCtrl( this, ID_COD_RADIO_118, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_CodRadio118->SetMaxLength( 0 ); 
	bSizer4511->Add( m_CodRadio118, 0, wxALL, 5 );
	
	
	sbSizer13->Add( bSizer4511, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer45->SetMinSize( wxSize( -1,30 ) ); 
	m_NumScheda118 = new wxStaticText( this, wxID_ANY, _("Numero di scheda 118 *"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_NumScheda118->Wrap( -1 );
	bSizer45->Add( m_NumScheda118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Scheda118 = new wxTextCtrl( this, ID_SCHEDA_118, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_RIGHT );
	m_Scheda118->SetMaxLength( 0 ); 
	bSizer45->Add( m_Scheda118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer45, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer451;
	bSizer451 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer451->SetMinSize( wxSize( -1,30 ) ); 
	m_staticText331 = new wxStaticText( this, wxID_ANY, _("Codice di uscita *"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText331->Wrap( -1 );
	bSizer451->Add( m_staticText331, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodGravita = new TxtCtrl118Code( this, ID_COD_GRAVITA, wxEmptyString, wxDefaultPosition, wxSize( 20,-1 ), wxTE_CENTRE );
	m_CodGravita->SetMaxLength( 1 ); 
	bSizer451->Add( m_CodGravita, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodPatologia = new TxtCtrl118Code( this, ID_COD_PATOLOGIA, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CENTRE );
	m_CodPatologia->SetMaxLength( 2 ); 
	bSizer451->Add( m_CodPatologia, 0, wxALL, 5 );
	
	m_CodLuogo = new TxtCtrl118Code( this, ID_COD_LUOGO, wxEmptyString, wxDefaultPosition, wxSize( 20,-1 ), wxTE_CENTRE );
	m_CodLuogo->SetMaxLength( 1 ); 
	bSizer451->Add( m_CodLuogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizer13->Add( bSizer451, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4512;
	bSizer4512 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer4512->SetMinSize( wxSize( -1,30 ) ); 
	m_staticText3312 = new wxStaticText( this, wxID_ANY, _("Nominativo fornito dalla CO"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_staticText3312->Wrap( -1 );
	bSizer4512->Add( m_staticText3312, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NominativoPaziente = new wxTextCtrl( this, ID_NOMINATIVO_PAZIENTE, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_NominativoPaziente->SetMaxLength( 0 ); 
	bSizer4512->Add( m_NominativoPaziente, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer4512, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4612;
	bSizer4612 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer4612->SetMinSize( wxSize( -1,30 ) ); 
	m_AvariaMezzo = new wxCheckBox( this, ID_AVARIA_MEZZO, _("Avaria Mezzo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4612->Add( m_AvariaMezzo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer4612, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer461;
	bSizer461 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer461->SetMinSize( wxSize( -1,30 ) ); 
	m_PazienteNonTrovato = new wxCheckBox( this, ID_PAZIENTE_NONTROVATO, _("Il Paziente non e' stato trovato"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer461->Add( m_PazienteNonTrovato, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer461, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4611;
	bSizer4611 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer4611->SetMinSize( wxSize( -1,30 ) ); 
	m_PazienteGiaTrasportato = new wxCheckBox( this, ID_PAZIENTE_GIATRASPORTATO, _("Il Paziente e' stato gia' trasportato"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4611->Add( m_PazienteGiaTrasportato, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GiaTrasportatoMezzo = new wxTextCtrl( this, ID_GIA_TRASPORTATO_MEZZO, wxEmptyString, wxDefaultPosition, wxSize( 360,-1 ), 0 );
	m_GiaTrasportatoMezzo->SetMaxLength( 0 ); 
	bSizer4611->Add( m_GiaTrasportatoMezzo, 0, wxALL, 5 );
	
	
	sbSizer13->Add( bSizer4611, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer462;
	bSizer462 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer462->SetMinSize( wxSize( -1,30 ) ); 
	m_ServizioNonCompletato = new wxCheckBox( this, ID_SERVIZIO_NON_COMPLETATO, _("Il Servizio non e' stato completato"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer462->Add( m_ServizioNonCompletato, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NonCompletato = new wxTextCtrl( this, ID_NON_COMPLETATO, wxEmptyString, wxDefaultPosition, wxSize( 360,-1 ), 0 );
	m_NonCompletato->SetMaxLength( 0 ); 
	bSizer462->Add( m_NonCompletato, 0, wxALL, 5 );
	
	
	sbSizer13->Add( bSizer462, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer46->SetMinSize( wxSize( -1,30 ) ); 
	m_ServizioAnnullato = new wxCheckBox( this, ID_SERVIZIO_ANNULLATO, _("Il Servizio e' stato annullato dalla centrale"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( m_ServizioAnnullato, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer46, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );
	
	m_label_AnnullatoOra = new wxStaticText( this, wxID_ANY, _("Ora *"), wxDefaultPosition, wxDefaultSize, 0 );
	m_label_AnnullatoOra->Wrap( -1 );
	bSizer53->Add( m_label_AnnullatoOra, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_AnnullatoOra = new wxTextCtrl( this, ID_ANNULLATO_ORA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_AnnullatoOra->SetMaxLength( 0 ); 
	bSizer53->Add( m_AnnullatoOra, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_label_AnnullatoLuogo = new wxStaticText( this, wxID_ANY, _("Luogo *"), wxDefaultPosition, wxDefaultSize, 0 );
	m_label_AnnullatoLuogo->Wrap( -1 );
	bSizer53->Add( m_label_AnnullatoLuogo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_AnnullatoLuogo = new wxTextCtrl( this, ID_ANNULLATO_LUOGO, wxEmptyString, wxDefaultPosition, wxSize( 414,-1 ), 0 );
	m_AnnullatoLuogo->SetMaxLength( 0 ); 
	bSizer53->Add( m_AnnullatoLuogo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer53, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer13, 1, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_CodRadio118->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_Scheda118->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_CodGravita->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_CodPatologia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_CodLuogo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_NominativoPaziente->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_AvariaMezzo->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_PazienteNonTrovato->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_PazienteGiaTrasportato->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_GiaTrasportatoMezzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_ServizioNonCompletato->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_NonCompletato->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_ServizioAnnullato->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_AnnullatoOra->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_AnnullatoLuogo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
}

InfoServizio118::~InfoServizio118()
{
	// Disconnect Events
	m_CodRadio118->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_Scheda118->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_CodGravita->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_CodPatologia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_CodLuogo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_NominativoPaziente->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_AvariaMezzo->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_PazienteNonTrovato->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_PazienteGiaTrasportato->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_GiaTrasportatoMezzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_ServizioNonCompletato->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_NonCompletato->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_ServizioAnnullato->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InfoServizio118::OnCheck ), NULL, this );
	m_AnnullatoOra->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	m_AnnullatoLuogo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( InfoServizio118::OnExitCtrl ), NULL, this );
	
}

PazientiTrasportati::PazientiTrasportati( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Pazienti Trasportati *") ), wxVERTICAL );
	
	m_Pazienti = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	sbSizer2->Add( m_Pazienti, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer12->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Modify = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer12->Add( m_bpButton_Modify, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer12->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer12, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer2, 1, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_Pazienti->Connect( wxEVT_SIZE, wxSizeEventHandler( PazientiTrasportati::OnSize ), NULL, this );
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PazientiTrasportati::OnAdd ), NULL, this );
	m_bpButton_Modify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PazientiTrasportati::OnModify ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PazientiTrasportati::OnDel ), NULL, this );
}

PazientiTrasportati::~PazientiTrasportati()
{
	// Disconnect Events
	m_Pazienti->Disconnect( wxEVT_SIZE, wxSizeEventHandler( PazientiTrasportati::OnSize ), NULL, this );
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PazientiTrasportati::OnAdd ), NULL, this );
	m_bpButton_Modify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PazientiTrasportati::OnModify ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PazientiTrasportati::OnDel ), NULL, this );
	
}

LuogoTrasportato::LuogoTrasportato( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Selezionare il luogo dove il paziente e' stato trasportato *") ), wxVERTICAL );
	
	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Abitazione_Checked = new wxCheckBox( this, ID_ABITAZIONE_CHECKED, _("Abitazione del Paziente"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer82->Add( m_Abitazione_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer82, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Ospedale_Checked = new wxCheckBox( this, ID_OSPEDALE_CHECKED, _("Ospedale"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer83->Add( m_Ospedale_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_OspedaleChoices;
	m_Ospedale = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_OspedaleChoices, 0 );
	m_Ospedale->SetSelection( 0 );
	bSizer83->Add( m_Ospedale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer83, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_AltroLuogo_Checked = new wxCheckBox( this, ID_ALTRO_LUOGO_CHECKED, _("Altro Luogo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer84->Add( m_AltroLuogo_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Luogo = new wxTextCtrl( this, ID_LUOGO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Luogo->SetMaxLength( 0 ); 
	bSizer84->Add( m_Luogo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer84, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer85;
	bSizer85 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer85->Add( 90, 0, 0, wxEXPAND, 5 );
	
	m_CAP_Label = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_CAP_Label->Wrap( -1 );
	bSizer85->Add( m_CAP_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer85->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta_Label = new wxStaticText( this, wxID_ANY, _("Citta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta_Label->Wrap( -1 );
	bSizer85->Add( m_Citta_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer85->Add( m_Citta, 1, wxALL, 5 );
	
	m_Provincia_Label = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Provincia_Label->Wrap( -1 );
	bSizer85->Add( m_Provincia_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer85->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( bSizer85, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer4, 1, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_Abitazione_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoTrasportato::OnCheck ), NULL, this );
	m_Ospedale_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoTrasportato::OnCheck ), NULL, this );
	m_AltroLuogo_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoTrasportato::OnCheck ), NULL, this );
	m_Luogo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
}

LuogoTrasportato::~LuogoTrasportato()
{
	// Disconnect Events
	m_Abitazione_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoTrasportato::OnCheck ), NULL, this );
	m_Ospedale_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoTrasportato::OnCheck ), NULL, this );
	m_AltroLuogo_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LuogoTrasportato::OnCheck ), NULL, this );
	m_Luogo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( LuogoTrasportato::OnExitCtrl ), NULL, this );
	
}

UtilizzoMezzo::UtilizzoMezzo( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer14;
	sbSizer14 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Mezzo") ), wxVERTICAL );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Km Iniziali *"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText21->Wrap( -1 );
	bSizer40->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_KmIniziali = new wxTextCtrl( this, ID_KM_INIZIALI, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	m_KmIniziali->SetMaxLength( 0 ); 
	bSizer40->Add( m_KmIniziali, 0, wxALL, 5 );
	
	
	sbSizer14->Add( bSizer40, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer401;
	bSizer401 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText211 = new wxStaticText( this, wxID_ANY, _("Km Finali *"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText211->Wrap( -1 );
	bSizer401->Add( m_staticText211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_KmFinali = new wxTextCtrl( this, ID_KM_FINALI, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	m_KmFinali->SetMaxLength( 0 ); 
	bSizer401->Add( m_KmFinali, 0, wxALL, 5 );
	
	
	sbSizer14->Add( bSizer401, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4011;
	bSizer4011 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2111 = new wxStaticText( this, wxID_ANY, _("Km Percorsi"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText2111->Wrap( -1 );
	bSizer4011->Add( m_staticText2111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_KmPercorsi = new wxTextCtrl( this, ID_KM_PERCORSI, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RIGHT );
	m_KmPercorsi->SetMaxLength( 0 ); 
	bSizer4011->Add( m_KmPercorsi, 0, wxALL, 5 );
	
	
	sbSizer14->Add( bSizer4011, 0, wxEXPAND, 5 );
	
	
	sbSizer14->Add( 0, 30, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer40111;
	bSizer40111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21111 = new wxStaticText( this, wxID_ANY, _("Fermo Macchina"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText21111->Wrap( -1 );
	bSizer40111->Add( m_staticText21111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OreFermoMacchina = new wxTextCtrl( this, ID_ORE_FERMO_MACCHINA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OreFermoMacchina->SetMaxLength( 0 ); 
	bSizer40111->Add( m_OreFermoMacchina, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("ore"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer40111->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer14->Add( bSizer40111, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer14, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_KmIniziali->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UtilizzoMezzo::OnExitCtrl ), NULL, this );
	m_KmFinali->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UtilizzoMezzo::OnExitCtrl ), NULL, this );
	m_OreFermoMacchina->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UtilizzoMezzo::OnExitCtrl ), NULL, this );
}

UtilizzoMezzo::~UtilizzoMezzo()
{
	// Disconnect Events
	m_KmIniziali->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UtilizzoMezzo::OnExitCtrl ), NULL, this );
	m_KmFinali->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UtilizzoMezzo::OnExitCtrl ), NULL, this );
	m_OreFermoMacchina->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UtilizzoMezzo::OnExitCtrl ), NULL, this );
	
}

Fine::Fine( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : MyWizardPage( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer16;
	sbSizer16 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Note sul Servizio") ), wxVERTICAL );
	
	m_Note = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	sbSizer16->Add( m_Note, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer16, 1, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
}

Fine::~Fine()
{
}
