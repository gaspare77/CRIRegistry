///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TxtCtrl118Code.h"

#include "CRIRegistryGUIs.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 900,700 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	m_menubar = new wxMenuBar( 0 );
	m_menu_File = new wxMenu();
	wxMenuItem* m_menu_SQLQuery;
	m_menu_SQLQuery = new wxMenuItem( m_menu_File, ID_SQL_QUERY, wxString( _("SQL Query") ) , _("SQL Query"), wxITEM_NORMAL );
	m_menu_File->Append( m_menu_SQLQuery );
	
	m_menu_File->AppendSeparator();
	
	wxMenuItem* m_menu_Quit;
	m_menu_Quit = new wxMenuItem( m_menu_File, wxID_ANY, wxString( _("Esci") ) + wxT('\t') + wxT("ALT+F4"), _("Chiude il programma"), wxITEM_NORMAL );
	m_menu_File->Append( m_menu_Quit );
	
	m_menubar->Append( m_menu_File, _("&File") ); 
	
	m_menu_Config = new wxMenu();
	wxMenuItem* m_menu_Options;
	m_menu_Options = new wxMenuItem( m_menu_Config, ID_OPTIONS, wxString( _("Opzioni") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_Config->Append( m_menu_Options );
	
	m_menubar->Append( m_menu_Config, _("&Configurazione") ); 
	
	m_menu_Users = new wxMenu();
	wxMenuItem* m_menu_LogIn;
	m_menu_LogIn = new wxMenuItem( m_menu_Users, ID_USER_LOGIN, wxString( _("Accedi") ) + wxT('\t') + wxT("CTRL+A"), wxEmptyString, wxITEM_NORMAL );
	m_menu_Users->Append( m_menu_LogIn );
	
	wxMenuItem* m_menu_LogOut;
	m_menu_LogOut = new wxMenuItem( m_menu_Users, ID_USER_LOGOUT, wxString( _("Esci") ) + wxT('\t') + wxT("CTRL+E"), wxEmptyString, wxITEM_NORMAL );
	m_menu_Users->Append( m_menu_LogOut );
	
	wxMenuItem* m_menu_ChangePwd;
	m_menu_ChangePwd = new wxMenuItem( m_menu_Users, ID_CHANGE_USER_PWD, wxString( _("Modifica Password") ) , _("Cambia la password"), wxITEM_NORMAL );
	m_menu_Users->Append( m_menu_ChangePwd );
	
	m_menu_Users->AppendSeparator();
	
	wxMenuItem* m_menu_UsersManager;
	m_menu_UsersManager = new wxMenuItem( m_menu_Users, ID_USERS_MANAGER, wxString( _("Gestione Utenti") ) , _("Gestione Utenti"), wxITEM_NORMAL );
	m_menu_Users->Append( m_menu_UsersManager );
	
	m_menubar->Append( m_menu_Users, _("&Utenti") ); 
	
	m_menu_Data = new wxMenu();
	wxMenuItem* m_menu_OpenGroup;
	m_menu_OpenGroup = new wxMenuItem( m_menu_Data, ID_OPEN_GROUP, wxString( _("Lista Gruppi") ) , _("Visualizza/Modifica i Gruppi"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenGroup );
	
	wxMenuItem* m_menu_OpenFleet;
	m_menu_OpenFleet = new wxMenuItem( m_menu_Data, ID_OPEN_FLEET, wxString( _("Parco Macchine") ) , _("Visualizza/Modifica il parco macchine"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenFleet );
	
	wxMenuItem* m_menu_OpenHospital;
	m_menu_OpenHospital = new wxMenuItem( m_menu_Data, ID_OPEN_HOSPITAL, wxString( _("Lista Ospedali") ) , _("Visualizza/Modifica la lista degli ospedali"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenHospital );
	
	wxMenuItem* m_menu_OpenServiceType;
	m_menu_OpenServiceType = new wxMenuItem( m_menu_Data, ID_OPEN_SERVICE_TYPE, wxString( _("Tipologie Servizi Ordinari") ) , _("Visualizza/Modifica le tipologie dei servizi ordinari"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenServiceType );
	
	wxMenuItem* m_menu_Open118ServiceType;
	m_menu_Open118ServiceType = new wxMenuItem( m_menu_Data, ID_OPEN_118_SERVICE_TYPE, wxString( _("Tipologie Servizi 118") ) , _("Visualizza/Modifica le tipologie dei servizi 118"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_Open118ServiceType );
	
	wxMenuItem* m_menu_OpenInternalServiceType;
	m_menu_OpenInternalServiceType = new wxMenuItem( m_menu_Data, ID_OPEN_INTERNAL_SERVICE_TYPE, wxString( _("Tipologie Servizi Interni") ) , _("Visualizza/Modifica le tipologie dei servizi"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenInternalServiceType );
	
	wxMenuItem* m_menu_OpenShiftType;
	m_menu_OpenShiftType = new wxMenuItem( m_menu_Data, ID_OPEN_SHIFT_TYPE, wxString( _("Tipologie Turni") ) , _("Visualizza/Modifica le tipologie dei turni"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenShiftType );
	
	wxMenuItem* m_menu_OpenVehicleType;
	m_menu_OpenVehicleType = new wxMenuItem( m_menu_Data, ID_OPEN_VEHICLE_TYPE, wxString( _("Tipologie Mezzi") ) , _("Visualizza/Modifica le tipologie dei mezzi"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenVehicleType );
	
	wxMenuItem* m_menu_OpenReasonsRefusingTransport;
	m_menu_OpenReasonsRefusingTransport = new wxMenuItem( m_menu_Data, ID_OPEN_REASONS_REFUSING_TRANSPORT, wxString( _("Motivazioni Rifiuta Trasporto") ) , _("Visualizza/Modifica le motivazioni di rifiuta il trasporto"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenReasonsRefusingTransport );
	
	wxMenuItem* m_menu_OpenMailingList;
	m_menu_OpenMailingList = new wxMenuItem( m_menu_Data, ID_OPEN_MAILING_LIST, wxString( _("Mailing List Comunicazioni") ) , _("Visualizza/Modifica la mailing list per le comunicazioni di servizio"), wxITEM_NORMAL );
	m_menu_Data->Append( m_menu_OpenMailingList );
	
	m_menubar->Append( m_menu_Data, _("&Dati") ); 
	
	m_menu_Presence = new wxMenu();
	wxMenuItem* m_menu_PresenceIn;
	m_menu_PresenceIn = new wxMenuItem( m_menu_Presence, ID_PRESENCE_IN, wxString( _("Registra Ingresso") ) + wxT('\t') + wxT("CTRL+P"), _("Registra l'ingresso"), wxITEM_NORMAL );
	m_menu_Presence->Append( m_menu_PresenceIn );
	
	wxMenuItem* m_menu_PresenceOut;
	m_menu_PresenceOut = new wxMenuItem( m_menu_Presence, ID_PRESENCE_OUT, wxString( _("Registra Uscita") ) , _("Registra l'uscita"), wxITEM_NORMAL );
	m_menu_Presence->Append( m_menu_PresenceOut );
	
	wxMenuItem* m_menu_ModifyPresence;
	m_menu_ModifyPresence = new wxMenuItem( m_menu_Presence, ID_MODIFY_PRESENCE, wxString( _("Modifica Presenza") ) , _("Modifica la Presenza selezionata"), wxITEM_NORMAL );
	m_menu_Presence->Append( m_menu_ModifyPresence );
	
	wxMenuItem* m_menu_PresenceDel;
	m_menu_PresenceDel = new wxMenuItem( m_menu_Presence, ID_DEL_PRESENCE, wxString( _("Cancella Presenza") ) , _("Cancella la presenza selezionata"), wxITEM_NORMAL );
	m_menu_Presence->Append( m_menu_PresenceDel );
	
	m_menu_Presence->AppendSeparator();
	
	wxMenuItem* m_menu_ViewCurrentPresence;
	m_menu_ViewCurrentPresence = new wxMenuItem( m_menu_Presence, ID_VIEW_CURRENT_PRESENCE, wxString( _("Visualizza Presenze Correnti") ) , _("Visualizza le Presenze Correnti"), wxITEM_RADIO );
	m_menu_Presence->Append( m_menu_ViewCurrentPresence );
	
	wxMenuItem* m_menu_ViewAllPresence;
	m_menu_ViewAllPresence = new wxMenuItem( m_menu_Presence, ID_VIEW_ALL_PRESENCE, wxString( _("Visualizza tutte le Presenze") ) , _("Visualizza tutte le Presenze nell'intervallo richiesto"), wxITEM_RADIO );
	m_menu_Presence->Append( m_menu_ViewAllPresence );
	
	m_menubar->Append( m_menu_Presence, _("&Presenze") ); 
	
	m_menu_Shift = new wxMenu();
	wxMenuItem* m_menu_AddCrew;
	m_menu_AddCrew = new wxMenuItem( m_menu_Shift, ID_ADD_CREW, wxString( _("Aggiungi Equipaggio") ) , _("Aggiunge un nuovo Equipaggio"), wxITEM_NORMAL );
	m_menu_Shift->Append( m_menu_AddCrew );
	
	wxMenuItem* m_menu_AddShift;
	m_menu_AddShift = new wxMenuItem( m_menu_Shift, ID_ADD_SHIFT, wxString( _("Aggiungi Turno") ) + wxT('\t') + wxT("CTRL+T"), _("Aggiunge un nuovo Turno"), wxITEM_NORMAL );
	m_menu_Shift->Append( m_menu_AddShift );
	
	wxMenuItem* m_menu_ModifyShift;
	m_menu_ModifyShift = new wxMenuItem( m_menu_Shift, ID_MODIFY_SHIFT, wxString( _("Modifica Turno") ) , _("Modifica il Turno selezionato"), wxITEM_NORMAL );
	m_menu_Shift->Append( m_menu_ModifyShift );
	
	wxMenuItem* m_menu_DeShift;
	m_menu_DeShift = new wxMenuItem( m_menu_Shift, ID_DEL_SHIFT, wxString( _("Cancella Turno") ) , _("Cancella il Turno selezionato"), wxITEM_NORMAL );
	m_menu_Shift->Append( m_menu_DeShift );
	
	m_menu_Shift->AppendSeparator();
	
	wxMenuItem* m_menu_ViewCurrentShift;
	m_menu_ViewCurrentShift = new wxMenuItem( m_menu_Shift, ID_VIEW_CURRENT_SHIFT, wxString( _("Visualizza Turni Correnti") ) , _("Visualizza i Turni Correnti"), wxITEM_RADIO );
	m_menu_Shift->Append( m_menu_ViewCurrentShift );
	
	wxMenuItem* m_menu_ViewAllShift;
	m_menu_ViewAllShift = new wxMenuItem( m_menu_Shift, ID_VIEW_ALL_SHIFT, wxString( _("Visualizza tutti i Turni") ) , _("Visulizza tutti i Turni nell'intervallo richiesto"), wxITEM_RADIO );
	m_menu_Shift->Append( m_menu_ViewAllShift );
	
	m_menu_Shift->AppendSeparator();
	
	wxMenuItem* m_menu_ExportShift;
	m_menu_ExportShift = new wxMenuItem( m_menu_Shift, ID_EXPORT_SHIFT, wxString( _("Esporta i Turni Registrati") ) , _("Esporta i Turni Registrati"), wxITEM_NORMAL );
	m_menu_Shift->Append( m_menu_ExportShift );
	
	wxMenuItem* m_menu_ImportShift;
	m_menu_ImportShift = new wxMenuItem( m_menu_Shift, ID_IMPORT_SHIFT, wxString( _("Importa i Turni Registrati") ) , _("Importa i Turni Registrati"), wxITEM_NORMAL );
	m_menu_Shift->Append( m_menu_ImportShift );
	
	m_menubar->Append( m_menu_Shift, _("&Turni") ); 
	
	m_menu_Service = new wxMenu();
	wxMenuItem* m_menu_AddService;
	m_menu_AddService = new wxMenuItem( m_menu_Service, ID_ADD_SERVICE, wxString( _("Registra Servizio") ) + wxT('\t') + wxT("CTRL+S"), _("Registra un nuovo Servizio"), wxITEM_NORMAL );
	m_menu_Service->Append( m_menu_AddService );
	
	wxMenuItem* m_menu_ModifyService;
	m_menu_ModifyService = new wxMenuItem( m_menu_Service, ID_MODIFY_SERVICE, wxString( _("Modifica Servizio") ) , _("Modifica il Servizio selezionato"), wxITEM_NORMAL );
	m_menu_Service->Append( m_menu_ModifyService );
	
	wxMenuItem* m_menu_DelService;
	m_menu_DelService = new wxMenuItem( m_menu_Service, ID_DEL_SERVICE, wxString( _("Cancella Servizio") ) , _("Cancella il Servizio selezionato"), wxITEM_NORMAL );
	m_menu_Service->Append( m_menu_DelService );
	
	m_menu_Service->AppendSeparator();
	
	wxMenuItem* m_menu_ViewCurrentService;
	m_menu_ViewCurrentService = new wxMenuItem( m_menu_Service, ID_VIEW_CURRENT_SERVICE, wxString( _("Visualizza Servizi Aperti") ) , _("Visualizza i Servizi Aperti"), wxITEM_RADIO );
	m_menu_Service->Append( m_menu_ViewCurrentService );
	
	wxMenuItem* m_menu_ViewSearchedService;
	m_menu_ViewSearchedService = new wxMenuItem( m_menu_Service, ID_VIEW_SEARCHED_SERVICE, wxString( _("Visualizza Ricerca Servizi") ) , _("Visualizza i Servizi ricercati"), wxITEM_RADIO );
	m_menu_Service->Append( m_menu_ViewSearchedService );
	
	wxMenuItem* m_menu_ViewAllService;
	m_menu_ViewAllService = new wxMenuItem( m_menu_Service, ID_VIEW_ALL_SERVICE, wxString( _("Visualizza tutti i Servizi") ) , _("Visualizza tutti i Servizi registrati nell'intervallo richiesto"), wxITEM_RADIO );
	m_menu_Service->Append( m_menu_ViewAllService );
	
	m_menu_Service->AppendSeparator();
	
	wxMenuItem* m_menu_ExportService;
	m_menu_ExportService = new wxMenuItem( m_menu_Service, ID_EXPORT_SERVICE, wxString( _("Esporta i Servizi Registrati") ) , _("Esporta i Sevizi Registrati"), wxITEM_NORMAL );
	m_menu_Service->Append( m_menu_ExportService );
	
	wxMenuItem* m_menu_ImportService;
	m_menu_ImportService = new wxMenuItem( m_menu_Service, ID_IMPORT_SERVICE, wxString( _("Importa i Servizi Registrati") ) , _("Importa i Sevizi Registrati"), wxITEM_NORMAL );
	m_menu_Service->Append( m_menu_ImportService );
	
	m_menubar->Append( m_menu_Service, _("&Servizi") ); 
	
	m_menu_Comunication = new wxMenu();
	wxMenuItem* m_menu_AddComunication;
	m_menu_AddComunication = new wxMenuItem( m_menu_Comunication, ID_ADD_COMUNICATION, wxString( _("Aggiungi Comunicazione") ) + wxT('\t') + wxT("CTRL+M"), wxEmptyString, wxITEM_NORMAL );
	m_menu_Comunication->Append( m_menu_AddComunication );
	
	wxMenuItem* m_menu_ModifyComunication;
	m_menu_ModifyComunication = new wxMenuItem( m_menu_Comunication, ID_MODIFY_COMUNICATION, wxString( _("Modifica Comunicazione") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_Comunication->Append( m_menu_ModifyComunication );
	
	wxMenuItem* m_menu_DelComunication;
	m_menu_DelComunication = new wxMenuItem( m_menu_Comunication, ID_DEL_COMUNICATION, wxString( _("Cancella Comunicazione") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_Comunication->Append( m_menu_DelComunication );
	
	m_menu_Comunication->AppendSeparator();
	
	wxMenuItem* m_menu_ViewCurrentComunication;
	m_menu_ViewCurrentComunication = new wxMenuItem( m_menu_Comunication, ID_VIEW_CURRENT_COMUNICATION, wxString( _("Visualizza Comunicazione Correnti") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_Comunication->Append( m_menu_ViewCurrentComunication );
	
	wxMenuItem* m_menu_ViewAllComunication;
	m_menu_ViewAllComunication = new wxMenuItem( m_menu_Comunication, ID_VIEW_ALL_COMUNICATION, wxString( _("Visualizza tutte le Comunicazione") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_Comunication->Append( m_menu_ViewAllComunication );
	
	m_menubar->Append( m_menu_Comunication, _("C&omunicazioni") ); 
	
	m_menu_Help = new wxMenu();
	wxMenuItem* m_menu_About;
	m_menu_About = new wxMenuItem( m_menu_Help, wxID_ANY, wxString( _("&About") ) + wxT('\t') + wxT("F1"), _("Visualizza le informazione sul programma"), wxITEM_NORMAL );
	m_menu_Help->Append( m_menu_About );
	
	m_menubar->Append( m_menu_Help, _("&Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel_Presence = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer662;
	bSizer662 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer681;
	bSizer681 = new wxBoxSizer( wxVERTICAL );
	
	m_list_Presence = new wxListCtrl( m_panel_Presence, ID_LIST_PRESENCE, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer681->Add( m_list_Presence, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizer662->Add( bSizer681, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6711;
	bSizer6711 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_PresenceIn = new wxBitmapButton( m_panel_Presence, wxID_ANY, wxBitmap( wxT("Res/bp_DoorIn.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_PresenceIn->SetToolTip( _("Registra l'ingresso") );
	
	bSizer6711->Add( m_bpButton_PresenceIn, 0, wxALL, 5 );
	
	m_bpButton_PresenceOut = new wxBitmapButton( m_panel_Presence, wxID_ANY, wxBitmap( wxT("Res/bp_DoorOut.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_PresenceOut->SetToolTip( _("Registra l'uscita") );
	
	bSizer6711->Add( m_bpButton_PresenceOut, 0, wxALL, 5 );
	
	m_bpButton_ModifyPresence = new wxBitmapButton( m_panel_Presence, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_ModifyPresence->SetToolTip( _("Modifica la Presenza selezionato") );
	
	bSizer6711->Add( m_bpButton_ModifyPresence, 0, wxALL, 5 );
	
	m_bpButton_DelPresence = new wxBitmapButton( m_panel_Presence, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_DelPresence->SetToolTip( _("Cancella la Presenza selezionata") );
	
	bSizer6711->Add( m_bpButton_DelPresence, 0, wxALL, 5 );
	
	
	bSizer6711->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bitmap_PresenceShowed = new wxStaticBitmap( m_panel_Presence, wxID_ANY, wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6711->Add( m_bitmap_PresenceShowed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer662->Add( bSizer6711, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	
	m_panel_Presence->SetSizer( bSizer662 );
	m_panel_Presence->Layout();
	bSizer662->Fit( m_panel_Presence );
	m_notebook->AddPage( m_panel_Presence, _("Registro Presenze"), true );
	m_panel_Shift = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxVERTICAL );
	
	m_list_Shift = new wxListCtrl( m_panel_Shift, ID_LIST_SHIFT, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer68->Add( m_list_Shift, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizer66->Add( bSizer68, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer671;
	bSizer671 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_AddCrew = new wxBitmapButton( m_panel_Shift, wxID_ANY, wxBitmap( wxT("Res/bp_AddCrew.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_AddCrew->SetToolTip( _("Aggiunge un nuovo Turno") );
	
	bSizer671->Add( m_bpButton_AddCrew, 0, wxALL, 5 );
	
	m_bpButton_AddShift = new wxBitmapButton( m_panel_Shift, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_AddShift->SetToolTip( _("Aggiunge un nuovo Turno") );
	
	bSizer671->Add( m_bpButton_AddShift, 0, wxALL, 5 );
	
	m_bpButton_ModifyShift = new wxBitmapButton( m_panel_Shift, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_ModifyShift->SetToolTip( _("Modifica il Turno selezionato") );
	
	bSizer671->Add( m_bpButton_ModifyShift, 0, wxALL, 5 );
	
	m_bpButton_DelShift = new wxBitmapButton( m_panel_Shift, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_DelShift->SetToolTip( _("Cancella il Turno selezionato") );
	
	bSizer671->Add( m_bpButton_DelShift, 0, wxALL, 5 );
	
	
	bSizer671->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bitmap_ShiftShowed = new wxStaticBitmap( m_panel_Shift, wxID_ANY, wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer671->Add( m_bitmap_ShiftShowed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer66->Add( bSizer671, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	
	m_panel_Shift->SetSizer( bSizer66 );
	m_panel_Shift->Layout();
	bSizer66->Fit( m_panel_Shift );
	m_notebook->AddPage( m_panel_Shift, _("Registro Turni"), false );
	m_panel_Service = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxVERTICAL );
	
	m_list_Service = new wxListCtrl( m_panel_Service, ID_LIST_SERVICE, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer76->Add( m_list_Service, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizer67->Add( bSizer76, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer661;
	bSizer661 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_AddService = new wxBitmapButton( m_panel_Service, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_AddService->SetToolTip( _("Registra un nuovo Servizio") );
	
	bSizer661->Add( m_bpButton_AddService, 0, wxALL, 5 );
	
	m_bpButton_ModifyService = new wxBitmapButton( m_panel_Service, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_ModifyService->SetToolTip( _("Modifica il servizio Selezionato") );
	
	bSizer661->Add( m_bpButton_ModifyService, 0, wxALL, 5 );
	
	m_bpButton_DelService = new wxBitmapButton( m_panel_Service, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_DelService->SetToolTip( _("Cancella il Servizio selezionato") );
	
	bSizer661->Add( m_bpButton_DelService, 0, wxALL, 5 );
	
	
	bSizer661->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bitmap_ServiceShowed = new wxStaticBitmap( m_panel_Service, wxID_ANY, wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer661->Add( m_bitmap_ServiceShowed, 0, wxALL, 5 );
	
	
	bSizer67->Add( bSizer661, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	
	m_panel_Service->SetSizer( bSizer67 );
	m_panel_Service->Layout();
	bSizer67->Fit( m_panel_Service );
	m_notebook->AddPage( m_panel_Service, _("Registro Servizi"), false );
	m_panel_Comunication = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer672;
	bSizer672 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer761;
	bSizer761 = new wxBoxSizer( wxVERTICAL );
	
	m_list_Comunication = new wxListCtrl( m_panel_Comunication, ID_LIST_COMUNICATION, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer761->Add( m_list_Comunication, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizer672->Add( bSizer761, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6611;
	bSizer6611 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_AddComunication = new wxBitmapButton( m_panel_Comunication, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_AddComunication->SetToolTip( _("Registra un nuovo Servizio") );
	
	bSizer6611->Add( m_bpButton_AddComunication, 0, wxALL, 5 );
	
	m_bpButton_ModifyComunication = new wxBitmapButton( m_panel_Comunication, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_ModifyComunication->SetToolTip( _("Modifica il servizio Selezionato") );
	
	bSizer6611->Add( m_bpButton_ModifyComunication, 0, wxALL, 5 );
	
	m_bpButton_DelComunication = new wxBitmapButton( m_panel_Comunication, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton_DelComunication->SetToolTip( _("Cancella il Servizio selezionato") );
	
	bSizer6611->Add( m_bpButton_DelComunication, 0, wxALL, 5 );
	
	
	bSizer6611->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bitmap_ComunicationShowed = new wxStaticBitmap( m_panel_Comunication, wxID_ANY, wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6611->Add( m_bitmap_ComunicationShowed, 0, wxALL, 5 );
	
	
	bSizer672->Add( bSizer6611, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	
	m_panel_Comunication->SetSizer( bSizer672 );
	m_panel_Comunication->Layout();
	bSizer672->Fit( m_panel_Comunication );
	m_notebook->AddPage( m_panel_Comunication, _("Comunicazioni"), false );
	
	bSizer37->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_SelectUser = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Users.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW );
	m_bpButton_SelectUser->SetToolTip( _("Cambia utente") );
	
	bSizer44->Add( m_bpButton_SelectUser, 0, wxALL, 5 );
	
	
	bSizer44->Add( 20, 0, 0, 0, 5 );
	
	m_bpButton_SelectPresence = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_UsersPresence.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW );
	m_bpButton_SelectPresence->SetToolTip( _("Visualizza il Registro presenze") );
	
	bSizer44->Add( m_bpButton_SelectPresence, 0, wxALL, 5 );
	
	m_bpButton_SelectShift = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_AmbulanceUsers.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW );
	m_bpButton_SelectShift->SetToolTip( _("Visualizza i Turni Registrati") );
	
	bSizer44->Add( m_bpButton_SelectShift, 0, wxALL, 5 );
	
	m_bpButton_SelectService = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Call.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW );
	m_bpButton_SelectService->SetToolTip( _("Visualizza i Servizi Registrati") );
	
	bSizer44->Add( m_bpButton_SelectService, 0, wxALL, 5 );
	
	m_bpButton_SelectComunication = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Comunication.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW );
	m_bpButton_SelectComunication->SetToolTip( _("Visualizza le Comunicazioni di Servizio") );
	
	bSizer44->Add( m_bpButton_SelectComunication, 0, wxALL, 5 );
	
	m_bpButton_FindUsers = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Users_Search.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 72,72 ), wxBU_AUTODRAW );
	m_bpButton_FindUsers->SetToolTip( _("Ricerca Volontari Disponibili") );
	
	bSizer44->Add( m_bpButton_FindUsers, 0, wxALL, 5 );
	
	
	bSizer44->Add( 20, 0, 1, wxEXPAND, 5 );
	
	m_Calendar = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_Calendar->Wrap( -1 );
	m_Calendar->SetFont( wxFont( 18, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer44->Add( m_Calendar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Close = new wxBitmapButton( this, ID_BP_CLOSE, wxBitmap( wxT("Res/bp_Close.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW );
	m_bpButton_Close->SetToolTip( _("Chiude il programma") );
	
	bSizer44->Add( m_bpButton_Close, 0, wxALL, 5 );
	
	
	bSizer37->Add( bSizer44, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer37 );
	this->Layout();
	bSizer37->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnClose ) );
	this->Connect( m_menu_SQLQuery->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnSQLQuery ) );
	this->Connect( m_menu_Quit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnQuit ) );
	this->Connect( m_menu_Options->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOptions ) );
	this->Connect( m_menu_LogIn->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLogIn ) );
	this->Connect( m_menu_LogOut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLogOut ) );
	this->Connect( m_menu_ChangePwd->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnChangeUsersPwd ) );
	this->Connect( m_menu_UsersManager->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnUsersManager ) );
	this->Connect( m_menu_OpenGroup->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenGroup ) );
	this->Connect( m_menu_OpenFleet->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenFleet ) );
	this->Connect( m_menu_OpenHospital->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenHospital ) );
	this->Connect( m_menu_OpenServiceType->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenServiceType ) );
	this->Connect( m_menu_Open118ServiceType->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpen118ServiceType ) );
	this->Connect( m_menu_OpenInternalServiceType->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenInternalServiceType ) );
	this->Connect( m_menu_OpenShiftType->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenShiftType ) );
	this->Connect( m_menu_OpenVehicleType->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenVehicleType ) );
	this->Connect( m_menu_OpenReasonsRefusingTransport->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenReasonsRefusingTransport ) );
	this->Connect( m_menu_OpenMailingList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenMailingList ) );
	this->Connect( m_menu_PresenceIn->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPresenceIn ) );
	this->Connect( m_menu_PresenceOut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPresenceOut ) );
	this->Connect( m_menu_ModifyPresence->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyPresence ) );
	this->Connect( m_menu_PresenceDel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPresenceDel ) );
	this->Connect( m_menu_ViewCurrentPresence->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentPresence ) );
	this->Connect( m_menu_ViewAllPresence->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllPresence ) );
	this->Connect( m_menu_AddCrew->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddCrew ) );
	this->Connect( m_menu_AddShift->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddShift ) );
	this->Connect( m_menu_ModifyShift->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyShift ) );
	this->Connect( m_menu_DeShift->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDelShift ) );
	this->Connect( m_menu_ViewCurrentShift->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentShift ) );
	this->Connect( m_menu_ViewAllShift->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllShift ) );
	this->Connect( m_menu_ExportShift->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportShift ) );
	this->Connect( m_menu_ImportShift->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnImportShift ) );
	this->Connect( m_menu_AddService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddService ) );
	this->Connect( m_menu_ModifyService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyService ) );
	this->Connect( m_menu_DelService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDelService ) );
	this->Connect( m_menu_ViewCurrentService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentService ) );
	this->Connect( m_menu_ViewSearchedService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewSearchedService ) );
	this->Connect( m_menu_ViewAllService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllService ) );
	this->Connect( m_menu_ExportService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportService ) );
	this->Connect( m_menu_ImportService->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnImportService ) );
	this->Connect( m_menu_AddComunication->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddComunication ) );
	this->Connect( m_menu_ModifyComunication->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyComunication ) );
	this->Connect( m_menu_DelComunication->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDelComunication ) );
	this->Connect( m_menu_ViewCurrentComunication->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentComunication ) );
	this->Connect( m_menu_ViewAllComunication->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllComunication ) );
	this->Connect( m_menu_About->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAbout ) );
	m_notebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MainFrame::OnNotebookPageChanged ), NULL, this );
	m_list_Presence->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Presence->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnPresencesListDbClick ), NULL, this );
	m_list_Presence->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_PresenceIn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnPresenceIn ), NULL, this );
	m_bpButton_PresenceOut->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnPresenceOut ), NULL, this );
	m_bpButton_ModifyPresence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyPresence ), NULL, this );
	m_bpButton_DelPresence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelPresence ), NULL, this );
	m_list_Shift->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Shift->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnShifsListDbClick ), NULL, this );
	m_list_Shift->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_AddCrew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddCrew ), NULL, this );
	m_bpButton_AddShift->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddShift ), NULL, this );
	m_bpButton_ModifyShift->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyShift ), NULL, this );
	m_bpButton_DelShift->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelShift ), NULL, this );
	m_list_Service->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Service->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnServicesListDbClick ), NULL, this );
	m_list_Service->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_AddService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddService ), NULL, this );
	m_bpButton_ModifyService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyService ), NULL, this );
	m_bpButton_DelService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelService ), NULL, this );
	m_list_Comunication->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Comunication->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnComunicationListDbClick ), NULL, this );
	m_list_Comunication->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_AddComunication->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddComunication ), NULL, this );
	m_bpButton_ModifyComunication->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyComunication ), NULL, this );
	m_bpButton_DelComunication->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelComunication ), NULL, this );
	m_bpButton_SelectUser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnChangeUser ), NULL, this );
	m_bpButton_SelectPresence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectPresence ), NULL, this );
	m_bpButton_SelectShift->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectShift ), NULL, this );
	m_bpButton_SelectService->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectService ), NULL, this );
	m_bpButton_SelectComunication->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectComunication ), NULL, this );
	m_bpButton_FindUsers->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectFindUsers ), NULL, this );
	m_bpButton_Close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnQuit ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnClose ) );
	this->Disconnect( ID_SQL_QUERY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnSQLQuery ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnQuit ) );
	this->Disconnect( ID_OPTIONS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOptions ) );
	this->Disconnect( ID_USER_LOGIN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLogIn ) );
	this->Disconnect( ID_USER_LOGOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLogOut ) );
	this->Disconnect( ID_CHANGE_USER_PWD, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnChangeUsersPwd ) );
	this->Disconnect( ID_USERS_MANAGER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnUsersManager ) );
	this->Disconnect( ID_OPEN_GROUP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenGroup ) );
	this->Disconnect( ID_OPEN_FLEET, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenFleet ) );
	this->Disconnect( ID_OPEN_HOSPITAL, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenHospital ) );
	this->Disconnect( ID_OPEN_SERVICE_TYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenServiceType ) );
	this->Disconnect( ID_OPEN_118_SERVICE_TYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpen118ServiceType ) );
	this->Disconnect( ID_OPEN_INTERNAL_SERVICE_TYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenInternalServiceType ) );
	this->Disconnect( ID_OPEN_SHIFT_TYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenShiftType ) );
	this->Disconnect( ID_OPEN_VEHICLE_TYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenVehicleType ) );
	this->Disconnect( ID_OPEN_REASONS_REFUSING_TRANSPORT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenReasonsRefusingTransport ) );
	this->Disconnect( ID_OPEN_MAILING_LIST, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnOpenMailingList ) );
	this->Disconnect( ID_PRESENCE_IN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPresenceIn ) );
	this->Disconnect( ID_PRESENCE_OUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPresenceOut ) );
	this->Disconnect( ID_MODIFY_PRESENCE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyPresence ) );
	this->Disconnect( ID_DEL_PRESENCE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPresenceDel ) );
	this->Disconnect( ID_VIEW_CURRENT_PRESENCE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentPresence ) );
	this->Disconnect( ID_VIEW_ALL_PRESENCE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllPresence ) );
	this->Disconnect( ID_ADD_CREW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddCrew ) );
	this->Disconnect( ID_ADD_SHIFT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddShift ) );
	this->Disconnect( ID_MODIFY_SHIFT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyShift ) );
	this->Disconnect( ID_DEL_SHIFT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDelShift ) );
	this->Disconnect( ID_VIEW_CURRENT_SHIFT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentShift ) );
	this->Disconnect( ID_VIEW_ALL_SHIFT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllShift ) );
	this->Disconnect( ID_EXPORT_SHIFT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportShift ) );
	this->Disconnect( ID_IMPORT_SHIFT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnImportShift ) );
	this->Disconnect( ID_ADD_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddService ) );
	this->Disconnect( ID_MODIFY_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyService ) );
	this->Disconnect( ID_DEL_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDelService ) );
	this->Disconnect( ID_VIEW_CURRENT_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentService ) );
	this->Disconnect( ID_VIEW_SEARCHED_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewSearchedService ) );
	this->Disconnect( ID_VIEW_ALL_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllService ) );
	this->Disconnect( ID_EXPORT_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExportService ) );
	this->Disconnect( ID_IMPORT_SERVICE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnImportService ) );
	this->Disconnect( ID_ADD_COMUNICATION, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddComunication ) );
	this->Disconnect( ID_MODIFY_COMUNICATION, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnModifyComunication ) );
	this->Disconnect( ID_DEL_COMUNICATION, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDelComunication ) );
	this->Disconnect( ID_VIEW_CURRENT_COMUNICATION, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewCurrentComunication ) );
	this->Disconnect( ID_VIEW_ALL_COMUNICATION, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnViewAllComunication ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAbout ) );
	m_notebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MainFrame::OnNotebookPageChanged ), NULL, this );
	m_list_Presence->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Presence->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnPresencesListDbClick ), NULL, this );
	m_list_Presence->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_PresenceIn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnPresenceIn ), NULL, this );
	m_bpButton_PresenceOut->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnPresenceOut ), NULL, this );
	m_bpButton_ModifyPresence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyPresence ), NULL, this );
	m_bpButton_DelPresence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelPresence ), NULL, this );
	m_list_Shift->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Shift->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnShifsListDbClick ), NULL, this );
	m_list_Shift->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_AddCrew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddCrew ), NULL, this );
	m_bpButton_AddShift->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddShift ), NULL, this );
	m_bpButton_ModifyShift->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyShift ), NULL, this );
	m_bpButton_DelShift->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelShift ), NULL, this );
	m_list_Service->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Service->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnServicesListDbClick ), NULL, this );
	m_list_Service->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_AddService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddService ), NULL, this );
	m_bpButton_ModifyService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyService ), NULL, this );
	m_bpButton_DelService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelService ), NULL, this );
	m_list_Comunication->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::OnKeyPressed ), NULL, this );
	m_list_Comunication->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::OnComunicationListDbClick ), NULL, this );
	m_list_Comunication->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnSize ), NULL, this );
	m_bpButton_AddComunication->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnAddComunication ), NULL, this );
	m_bpButton_ModifyComunication->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnModifyComunication ), NULL, this );
	m_bpButton_DelComunication->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDelComunication ), NULL, this );
	m_bpButton_SelectUser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnChangeUser ), NULL, this );
	m_bpButton_SelectPresence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectPresence ), NULL, this );
	m_bpButton_SelectShift->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectShift ), NULL, this );
	m_bpButton_SelectService->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectService ), NULL, this );
	m_bpButton_SelectComunication->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectComunication ), NULL, this );
	m_bpButton_FindUsers->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnSelectFindUsers ), NULL, this );
	m_bpButton_Close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnQuit ), NULL, this );
	
}

SQLQueryDlg::SQLQueryDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 900,700 ), wxDefaultSize );
	
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxHORIZONTAL );
	
	m_SQLQuery = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_MULTILINE );
	m_SQLQuery->SetMaxLength( 0 ); 
	bSizer92->Add( m_SQLQuery, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer170;
	bSizer170 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer172;
	bSizer172 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_QueryAdd = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer172->Add( m_bpButton_QueryAdd, 0, wxALL, 5 );
	
	m_bpButton_QueryDel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer172->Add( m_bpButton_QueryDel, 0, wxALL, 5 );
	
	
	bSizer170->Add( bSizer172, 1, 0, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Execute = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Execute.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer171->Add( m_bpButton_Execute, 0, wxALL, 5 );
	
	m_bp_OpenQuery = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_OpenQuery.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer171->Add( m_bp_OpenQuery, 0, wxALL, 5 );
	
	
	bSizer170->Add( bSizer171, 1, 0, 5 );
	
	
	bSizer92->Add( bSizer170, 0, wxEXPAND, 5 );
	
	
	bSizer91->Add( bSizer92, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Grid = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_Grid->CreateGrid( 0, 0 );
	m_Grid->EnableEditing( true );
	m_Grid->EnableGridLines( true );
	m_Grid->EnableDragGridSize( false );
	m_Grid->SetMargins( 0, 0 );
	
	// Columns
	m_Grid->EnableDragColMove( false );
	m_Grid->EnableDragColSize( true );
	m_Grid->SetColLabelSize( 30 );
	m_Grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_Grid->EnableDragRowSize( true );
	m_Grid->SetRowLabelSize( 80 );
	m_Grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_Grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer93->Add( m_Grid, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer91->Add( bSizer93, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Export = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Export.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer94->Add( m_bpButton_Export, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer94->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer94, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer91 );
	this->Layout();
	bSizer91->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_SQLQuery->Connect( wxEVT_CHAR, wxKeyEventHandler( SQLQueryDlg::OnWrite ), NULL, this );
	m_bpButton_QueryAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnQueryAdd ), NULL, this );
	m_bpButton_QueryDel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnQueryDel ), NULL, this );
	m_bpButton_Execute->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnQueryExecute ), NULL, this );
	m_bp_OpenQuery->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnOpenQuery ), NULL, this );
	m_bpButton_Export->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnExport ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnCancel ), NULL, this );
}

SQLQueryDlg::~SQLQueryDlg()
{
	// Disconnect Events
	m_SQLQuery->Disconnect( wxEVT_CHAR, wxKeyEventHandler( SQLQueryDlg::OnWrite ), NULL, this );
	m_bpButton_QueryAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnQueryAdd ), NULL, this );
	m_bpButton_QueryDel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnQueryDel ), NULL, this );
	m_bpButton_Execute->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnQueryExecute ), NULL, this );
	m_bp_OpenQuery->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnOpenQuery ), NULL, this );
	m_bpButton_Export->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnExport ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SQLQueryDlg::OnCancel ), NULL, this );
	
}

FleetDlg::FleetDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 650,480 ), wxDefaultSize );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	m_listBox_ParcoMacchine = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), 0, NULL, 0 ); 
	bSizer40->Add( m_listBox_ParcoMacchine, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Modify = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer42->Add( m_bpButton_Modify, 0, wxALL, 5 );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer42->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer42->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	bSizer40->Add( bSizer42, 0, 0, 5 );
	
	
	bSizer77->Add( bSizer40, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText98 = new wxStaticText( this, wxID_ANY, _("Codice Mezzo"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText98->Wrap( -1 );
	bSizer156->Add( m_staticText98, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodMezzo = new wxTextCtrl( this, ID_COD_MEZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodMezzo->SetMaxLength( 0 ); 
	bSizer156->Add( m_CodMezzo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer41->Add( bSizer156, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText37->Wrap( -1 );
	bSizer43->Add( m_staticText37, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, ID_GRUPPO, wxDefaultPosition, wxDefaultSize, m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	m_Gruppo->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer43->Add( m_Gruppo, 0, wxALL, 5 );
	
	
	bSizer41->Add( bSizer43, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer431;
	bSizer431 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText371 = new wxStaticText( this, wxID_ANY, _("Tipo"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText371->Wrap( -1 );
	bSizer431->Add( m_staticText371, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_TipoChoices;
	m_Tipo = new wxChoice( this, ID_TIPO, wxDefaultPosition, wxDefaultSize, m_TipoChoices, 0 );
	m_Tipo->SetSelection( 0 );
	m_Tipo->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer431->Add( m_Tipo, 0, wxALL, 5 );
	
	
	bSizer41->Add( bSizer431, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer432;
	bSizer432 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText372 = new wxStaticText( this, wxID_ANY, _("Modello"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText372->Wrap( -1 );
	bSizer432->Add( m_staticText372, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Modello = new wxTextCtrl( this, ID_MODELLO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Modello->SetMaxLength( 0 ); 
	bSizer432->Add( m_Modello, 1, wxALL, 5 );
	
	
	bSizer41->Add( bSizer432, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer43312;
	bSizer43312 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText37312 = new wxStaticText( this, wxID_ANY, _("Radio 118"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText37312->Wrap( -1 );
	bSizer43312->Add( m_staticText37312, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Radio118 = new wxTextCtrl( this, ID_RADIO_118, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Radio118->SetMaxLength( 0 ); 
	bSizer43312->Add( m_Radio118, 0, wxALL, 5 );
	
	
	bSizer41->Add( bSizer43312, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer433;
	bSizer433 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText373 = new wxStaticText( this, wxID_ANY, _("Targa"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText373->Wrap( -1 );
	bSizer433->Add( m_staticText373, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Targa = new wxTextCtrl( this, ID_TARGA, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_Targa->SetMaxLength( 0 ); 
	bSizer433->Add( m_Targa, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer41->Add( bSizer433, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4331;
	bSizer4331 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3731 = new wxStaticText( this, wxID_ANY, _("Km"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText3731->Wrap( -1 );
	bSizer4331->Add( m_staticText3731, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Km = new wxTextCtrl( this, ID_KM, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Km->SetMaxLength( 0 ); 
	bSizer4331->Add( m_Km, 0, wxALL, 5 );
	
	
	bSizer41->Add( bSizer4331, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer43311;
	bSizer43311 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText37311 = new wxStaticText( this, wxID_ANY, _("Note"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText37311->Wrap( -1 );
	bSizer43311->Add( m_staticText37311, 0, wxALL, 5 );
	
	m_Note = new wxTextCtrl( this, ID_NOTE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_Note->SetMaxLength( 0 ); 
	bSizer43311->Add( m_Note, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer41->Add( bSizer43311, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer433111;
	bSizer433111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_NonOperativa = new wxCheckBox( this, ID_NON_OPERATIVA, _("Non Operativa"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer433111->Add( m_NonOperativa, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer41->Add( bSizer433111, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer134;
	bSizer134 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, _("Conferma cambiamenti"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	bSizer134->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer134->Add( 0, 0, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Confirm = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm16x16.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 40,-1 ), wxBU_AUTODRAW );
	bSizer134->Add( m_bpButton_Confirm, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel16x16.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 40,-1 ), wxBU_AUTODRAW );
	bSizer134->Add( m_bpButton_Cancel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer41->Add( bSizer134, 0, wxEXPAND, 5 );
	
	
	bSizer77->Add( bSizer41, 1, wxEXPAND, 5 );
	
	
	bSizer39->Add( bSizer77, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline8 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer111->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );
	
	
	bSizer39->Add( bSizer111, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer110;
	bSizer110 = new wxBoxSizer( wxVERTICAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer110->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	
	bSizer39->Add( bSizer110, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer39 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_listBox_ParcoMacchine->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FleetDlg::OnSelect ), NULL, this );
	m_bpButton_Modify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnModify ), NULL, this );
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnAdd ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnDel ), NULL, this );
	m_CodMezzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Modello->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Radio118->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Targa->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Km->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Note->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Confirm->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnConfirm ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnCancel ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnOk ), NULL, this );
}

FleetDlg::~FleetDlg()
{
	// Disconnect Events
	m_listBox_ParcoMacchine->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( FleetDlg::OnSelect ), NULL, this );
	m_bpButton_Modify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnModify ), NULL, this );
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnAdd ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnDel ), NULL, this );
	m_CodMezzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Modello->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Radio118->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Targa->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Km->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_Note->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FleetDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Confirm->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnConfirm ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnCancel ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FleetDlg::OnOk ), NULL, this );
	
}

HospitalDlg::HospitalDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 650,480 ), wxDefaultSize );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxVERTICAL );
	
	m_listBox_Ospedali = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 ); 
	m_listBox_Ospedali->SetMinSize( wxSize( 250,-1 ) );
	
	bSizer80->Add( m_listBox_Ospedali, 1, wxALL, 5 );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Modify = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer42->Add( m_bpButton_Modify, 0, wxALL, 5 );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer42->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer42->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	bSizer80->Add( bSizer42, 0, 0, 5 );
	
	
	bSizer79->Add( bSizer80, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer856;
	bSizer856 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText706 = new wxStaticText( this, wxID_ANY, _("Ospedale"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText706->Wrap( -1 );
	bSizer856->Add( m_staticText706, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Ospedale = new wxTextCtrl( this, ID_OSPEDALE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Ospedale->SetMaxLength( 0 ); 
	bSizer856->Add( m_Ospedale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer84->Add( bSizer856, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer85;
	bSizer85 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText70 = new wxStaticText( this, wxID_ANY, _("Societa'"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText70->Wrap( -1 );
	bSizer85->Add( m_staticText70, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Societa = new wxTextCtrl( this, ID_SOCIETA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Societa->SetMaxLength( 0 ); 
	bSizer85->Add( m_Societa, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer84->Add( bSizer85, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer851;
	bSizer851 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText701 = new wxStaticText( this, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText701->Wrap( -1 );
	bSizer851->Add( m_staticText701, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Indirizzo = new wxTextCtrl( this, ID_INDIRIZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Indirizzo->SetMaxLength( 0 ); 
	bSizer851->Add( m_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText64 = new wxStaticText( this, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	bSizer851->Add( m_staticText64, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Civico = new wxTextCtrl( this, ID_CIVICO, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), 0 );
	m_Civico->SetMaxLength( 0 ); 
	bSizer851->Add( m_Civico, 0, wxALL, 5 );
	
	
	bSizer84->Add( bSizer851, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8531;
	bSizer8531 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText7031 = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText7031->Wrap( -1 );
	bSizer8531->Add( m_staticText7031, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer8531->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer84->Add( bSizer8531, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer852;
	bSizer852 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText702 = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText702->Wrap( -1 );
	bSizer852->Add( m_staticText702, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer852->Add( m_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer852->Add( m_Provincia, 0, wxALL, 5 );
	
	
	bSizer84->Add( bSizer852, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer853;
	bSizer853 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText703 = new wxStaticText( this, wxID_ANY, _("Num. Telefono"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText703->Wrap( -1 );
	bSizer853->Add( m_staticText703, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NumTel = new wxTextCtrl( this, ID_NUM_TEL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_NumTel->SetMaxLength( 0 ); 
	bSizer853->Add( m_NumTel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer84->Add( bSizer853, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer854;
	bSizer854 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText704 = new wxStaticText( this, wxID_ANY, _("Num. Fax"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText704->Wrap( -1 );
	bSizer854->Add( m_staticText704, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NumFax = new wxTextCtrl( this, ID_NUM_FAX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_NumFax->SetMaxLength( 0 ); 
	bSizer854->Add( m_NumFax, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer84->Add( bSizer854, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer855;
	bSizer855 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText705 = new wxStaticText( this, wxID_ANY, _("Note"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText705->Wrap( -1 );
	bSizer855->Add( m_staticText705, 0, wxALL, 5 );
	
	m_Note = new wxTextCtrl( this, ID_NOTE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_Note->SetMaxLength( 0 ); 
	bSizer855->Add( m_Note, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer84->Add( bSizer855, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer134;
	bSizer134 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, _("Conferma cambiamenti"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	bSizer134->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer134->Add( 0, 0, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Confirm = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm16x16.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 40,-1 ), wxBU_AUTODRAW );
	bSizer134->Add( m_bpButton_Confirm, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel16x16.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 40,-1 ), wxBU_AUTODRAW );
	bSizer134->Add( m_bpButton_Cancel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer84->Add( bSizer134, 0, wxEXPAND, 5 );
	
	
	bSizer79->Add( bSizer84, 1, wxEXPAND, 5 );
	
	
	bSizer78->Add( bSizer79, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline8 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer111->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );
	
	
	bSizer78->Add( bSizer111, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer110;
	bSizer110 = new wxBoxSizer( wxVERTICAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer110->Add( m_bpButton_Ok, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	bSizer78->Add( bSizer110, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer78 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_listBox_Ospedali->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( HospitalDlg::OnSelect ), NULL, this );
	m_bpButton_Modify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnModify ), NULL, this );
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnAdd ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnDel ), NULL, this );
	m_Ospedale->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Societa->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Civico->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_NumTel->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_NumFax->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Note->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Confirm->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnConfirm ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnCancel ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnOk ), NULL, this );
}

HospitalDlg::~HospitalDlg()
{
	// Disconnect Events
	m_listBox_Ospedali->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( HospitalDlg::OnSelect ), NULL, this );
	m_bpButton_Modify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnModify ), NULL, this );
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnAdd ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnDel ), NULL, this );
	m_Ospedale->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Societa->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Civico->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_NumTel->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_NumFax->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_Note->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HospitalDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Confirm->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnConfirm ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnCancel ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HospitalDlg::OnOk ), NULL, this );
	
}

UsersDlg::UsersDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 650,480 ), wxDefaultSize );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer( wxVERTICAL );
	
	bSizer106->SetMinSize( wxSize( 200,-1 ) ); 
	m_listBox_Utenti = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 ); 
	m_listBox_Utenti->SetMinSize( wxSize( 250,-1 ) );
	
	bSizer106->Add( m_listBox_Utenti, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer105->Add( bSizer106, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer108;
	bSizer108 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText50 = new wxStaticText( this, wxID_ANY, _("Utente"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText50->Wrap( -1 );
	bSizer108->Add( m_staticText50, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Utente = new wxTextCtrl( this, ID_UTENTE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Utente->SetMaxLength( 0 ); 
	bSizer108->Add( m_Utente, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer107->Add( bSizer108, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1081;
	bSizer1081 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText501 = new wxStaticText( this, wxID_ANY, _("Cognome"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText501->Wrap( -1 );
	bSizer1081->Add( m_staticText501, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxTextCtrl( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cognome->SetMaxLength( 0 ); 
	bSizer1081->Add( m_Cognome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer107->Add( bSizer1081, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1082;
	bSizer1082 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText502 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText502->Wrap( -1 );
	bSizer1082->Add( m_staticText502, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxTextCtrl( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Nome->SetMaxLength( 0 ); 
	bSizer1082->Add( m_Nome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer107->Add( bSizer1082, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1083;
	bSizer1083 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText503 = new wxStaticText( this, wxID_ANY, _("Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText503->Wrap( -1 );
	bSizer1083->Add( m_staticText503, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Password = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_Password->SetMaxLength( 0 ); 
	bSizer1083->Add( m_Password, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer107->Add( bSizer1083, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1085;
	bSizer1085 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText505 = new wxStaticText( this, wxID_ANY, _("Conferma Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText505->Wrap( -1 );
	bSizer1085->Add( m_staticText505, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ConfermaPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_ConfermaPassword->SetMaxLength( 0 ); 
	bSizer1085->Add( m_ConfermaPassword, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer107->Add( bSizer1085, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1084;
	bSizer1084 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText504 = new wxStaticText( this, wxID_ANY, _("Privilegi"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText504->Wrap( -1 );
	bSizer1084->Add( m_staticText504, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_PrivilegiChoices;
	m_Privilegi = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_PrivilegiChoices, 0 );
	m_Privilegi->SetSelection( 0 );
	bSizer1084->Add( m_Privilegi, 1, wxALL, 5 );
	
	
	bSizer107->Add( bSizer1084, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer134;
	bSizer134 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, _("Conferma cambiamenti"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText61->Wrap( -1 );
	bSizer134->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer134->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpButton_Confirm = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm16x16.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 40,-1 ), wxBU_AUTODRAW );
	bSizer134->Add( m_bpButton_Confirm, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel16x16.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 40,-1 ), wxBU_AUTODRAW );
	bSizer134->Add( m_bpButton_Cancel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer107->Add( bSizer134, 0, wxEXPAND, 5 );
	
	
	bSizer105->Add( bSizer107, 1, wxEXPAND, 5 );
	
	
	bSizer75->Add( bSizer105, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer123->Add( m_bpButton_Add, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer123->Add( m_bpButton_Del, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Modify = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer123->Add( m_bpButton_Modify, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer75->Add( bSizer123, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer75->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	
	bSizer75->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer75 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_listBox_Utenti->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( UsersDlg::OnSelect ), NULL, this );
	m_Utente->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UsersDlg::OnExitCtrl ), NULL, this );
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UsersDlg::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UsersDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Confirm->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnConfirm ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnCancel ), NULL, this );
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnAdd ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnDel ), NULL, this );
	m_bpButton_Modify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnModify ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnOk ), NULL, this );
}

UsersDlg::~UsersDlg()
{
	// Disconnect Events
	m_listBox_Utenti->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( UsersDlg::OnSelect ), NULL, this );
	m_Utente->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UsersDlg::OnExitCtrl ), NULL, this );
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UsersDlg::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( UsersDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Confirm->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnConfirm ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnCancel ), NULL, this );
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnAdd ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnDel ), NULL, this );
	m_bpButton_Modify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnModify ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UsersDlg::OnOk ), NULL, this );
	
}

LogInDlg::LogInDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,150 ), wxDefaultSize );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText46 = new wxStaticText( this, wxID_ANY, _("Utente"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText46->Wrap( -1 );
	bSizer76->Add( m_staticText46, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Utente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Utente->SetMaxLength( 0 ); 
	bSizer76->Add( m_Utente, 1, wxALL, 5 );
	
	
	bSizer75->Add( bSizer76, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText47 = new wxStaticText( this, wxID_ANY, _("Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText47->Wrap( -1 );
	bSizer77->Add( m_staticText47, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Password = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD|wxTE_PROCESS_ENTER );
	m_Password->SetMaxLength( 0 ); 
	bSizer77->Add( m_Password, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer75->Add( bSizer77, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer75->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer75->Add( bSizer39, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer75 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Password->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( LogInDlg::OnOk ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogInDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogInDlg::OnCancel ), NULL, this );
}

LogInDlg::~LogInDlg()
{
	// Disconnect Events
	m_Password->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( LogInDlg::OnOk ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogInDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LogInDlg::OnCancel ), NULL, this );
	
}

ChangeUsersPwdDlg::ChangeUsersPwdDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,190 ), wxDefaultSize );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer7711;
	bSizer7711 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4711 = new wxStaticText( this, wxID_ANY, _("Vecchia Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText4711->Wrap( -1 );
	bSizer7711->Add( m_staticText4711, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Password = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_Password->SetMaxLength( 0 ); 
	bSizer7711->Add( m_Password, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer75->Add( bSizer7711, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer771;
	bSizer771 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText471 = new wxStaticText( this, wxID_ANY, _("Nuova Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText471->Wrap( -1 );
	bSizer771->Add( m_staticText471, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NuovaPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_NuovaPassword->SetMaxLength( 0 ); 
	bSizer771->Add( m_NuovaPassword, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer75->Add( bSizer771, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer772;
	bSizer772 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText472 = new wxStaticText( this, wxID_ANY, _("Conferma Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText472->Wrap( -1 );
	bSizer772->Add( m_staticText472, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ConfermaPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_ConfermaPassword->SetMaxLength( 0 ); 
	bSizer772->Add( m_ConfermaPassword, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer75->Add( bSizer772, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer75->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer75->Add( bSizer39, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer75 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChangeUsersPwdDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChangeUsersPwdDlg::OnCancel ), NULL, this );
}

ChangeUsersPwdDlg::~ChangeUsersPwdDlg()
{
	// Disconnect Events
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChangeUsersPwdDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChangeUsersPwdDlg::OnCancel ), NULL, this );
	
}

SetUsersPwdDlg::SetUsersPwdDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,150 ), wxDefaultSize );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer771;
	bSizer771 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText471 = new wxStaticText( this, wxID_ANY, _("Nuova Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText471->Wrap( -1 );
	bSizer771->Add( m_staticText471, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NuovaPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_NuovaPassword->SetMaxLength( 0 ); 
	bSizer771->Add( m_NuovaPassword, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer75->Add( bSizer771, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer772;
	bSizer772 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText472 = new wxStaticText( this, wxID_ANY, _("Conferma Password"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText472->Wrap( -1 );
	bSizer772->Add( m_staticText472, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ConfermaPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_ConfermaPassword->SetMaxLength( 0 ); 
	bSizer772->Add( m_ConfermaPassword, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer75->Add( bSizer772, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer75->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer75->Add( bSizer39, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer75 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetUsersPwdDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetUsersPwdDlg::OnCancel ), NULL, this );
}

SetUsersPwdDlg::~SetUsersPwdDlg()
{
	// Disconnect Events
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetUsersPwdDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetUsersPwdDlg::OnCancel ), NULL, this );
	
}

AddFieldsDlg::AddFieldsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxVERTICAL );
	
	m_FieldsList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	bSizer78->Add( m_FieldsList, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Modify = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpButton_Modify, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	bSizer78->Add( bSizer99, 0, wxEXPAND, 5 );
	
	
	bSizer65->Add( bSizer78, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer781;
	bSizer781 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer781->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer65->Add( bSizer781, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer67->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	
	bSizer65->Add( bSizer67, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer65 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnAdd ), NULL, this );
	m_bpButton_Modify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnModify ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnDel ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnOk ), NULL, this );
}

AddFieldsDlg::~AddFieldsDlg()
{
	// Disconnect Events
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnAdd ), NULL, this );
	m_bpButton_Modify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnModify ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnDel ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFieldsDlg::OnOk ), NULL, this );
	
}

MailingListDlg::MailingListDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 600,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxVERTICAL );
	
	m_FieldsList = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer78->Add( m_FieldsList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Add = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpButton_Add, 0, wxALL, 5 );
	
	m_bpButton_Modify = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpButton_Modify, 0, wxALL, 5 );
	
	m_bpButton_Del = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpButton_Del, 0, wxALL, 5 );
	
	
	bSizer78->Add( bSizer99, 0, wxEXPAND, 5 );
	
	
	bSizer65->Add( bSizer78, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer781;
	bSizer781 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer781->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer65->Add( bSizer781, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer67->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	
	bSizer65->Add( bSizer67, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer65 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnAdd ), NULL, this );
	m_bpButton_Modify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnModify ), NULL, this );
	m_bpButton_Del->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnDel ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnOk ), NULL, this );
}

MailingListDlg::~MailingListDlg()
{
	// Disconnect Events
	m_bpButton_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnAdd ), NULL, this );
	m_bpButton_Modify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnModify ), NULL, this );
	m_bpButton_Del->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnDel ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailingListDlg::OnOk ), NULL, this );
	
}

MailAddressDlg::MailAddressDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,220 ), wxDefaultSize );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText31->Wrap( -1 );
	bSizer37->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxTextCtrl( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( m_Nome, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer37, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText311 = new wxStaticText( this, wxID_ANY, _("Indirizzo email"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText311->Wrap( -1 );
	bSizer371->Add( m_staticText311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_eMail = new wxTextCtrl( this, ID_EMAIL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer371->Add( m_eMail, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer371, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, _("Separare gli indirizzi email con il carattere \";\"\nEsempio:\nnome1@dominio.it;nome2@dominio.it"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText32->Wrap( -1 );
	bSizer38->Add( m_staticText32, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer36->Add( bSizer38, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer39, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer36 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MailAddressDlg::OnExitCtrl ), NULL, this );
	m_eMail->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MailAddressDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailAddressDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailAddressDlg::OnCancel ), NULL, this );
}

MailAddressDlg::~MailAddressDlg()
{
	// Disconnect Events
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MailAddressDlg::OnExitCtrl ), NULL, this );
	m_eMail->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MailAddressDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailAddressDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MailAddressDlg::OnCancel ), NULL, this );
	
}

PresenceDlg::PresenceDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,420 ), wxDefaultSize );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText37->Wrap( -1 );
	bSizer43->Add( m_staticText37, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, ID_GRUPPO, wxDefaultPosition, wxDefaultSize, m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	m_Gruppo->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer43->Add( m_Gruppo, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer43, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Cognome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText31->Wrap( -1 );
	bSizer37->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxComboBox( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer37->Add( m_Cognome, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer37, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText311 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText311->Wrap( -1 );
	bSizer371->Add( m_staticText311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxComboBox( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer371->Add( m_Nome, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer371, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221111 = new wxStaticText( this, wxID_ANY, _("Data"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText221111->Wrap( -1 );
	bSizer48->Add( m_staticText221111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Data = new wxDatePickerCtrl( this, ID_DATA, wxDefaultDateTime, wxDefaultPosition, wxSize( 130,-1 ), wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer48->Add( m_Data, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer48, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221112 = new wxStaticText( this, wxID_ANY, _("Ora Ingresso"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText221112->Wrap( -1 );
	bSizer49->Add( m_staticText221112, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraIngresso = new wxTextCtrl( this, ID_ORA_INGRESSO, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraIngresso->SetMaxLength( 5 ); 
	bSizer49->Add( m_OraIngresso, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer49, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText58 = new wxStaticText( this, wxID_ANY, _("Ora Uscita"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText58->Wrap( -1 );
	bSizer84->Add( m_staticText58, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraUscita = new wxTextCtrl( this, ID_ORA_USCITA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraUscita->SetMaxLength( 5 ); 
	bSizer84->Add( m_OraUscita, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer84, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer841;
	bSizer841 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText581 = new wxStaticText( this, wxID_ANY, _("Note"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText581->Wrap( -1 );
	bSizer841->Add( m_staticText581, 0, wxALL, 5 );
	
	m_Note = new wxTextCtrl( this, ID_NOTE, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_MULTILINE );
	m_Note->SetMaxLength( 0 ); 
	bSizer841->Add( m_Note, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer36->Add( bSizer841, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer36 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( PresenceDlg::OnClose ) );
	m_Cognome->Connect( wxEVT_KEY_UP, wxKeyEventHandler( PresenceDlg::OnWrite ), NULL, this );
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KEY_UP, wxKeyEventHandler( PresenceDlg::OnWrite ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_OraIngresso->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_OraUscita->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_Note->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresenceDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresenceDlg::OnCancel ), NULL, this );
}

PresenceDlg::~PresenceDlg()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( PresenceDlg::OnClose ) );
	m_Cognome->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( PresenceDlg::OnWrite ), NULL, this );
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( PresenceDlg::OnWrite ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_OraIngresso->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_OraUscita->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_Note->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PresenceDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresenceDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresenceDlg::OnCancel ), NULL, this );
	
}

ShiftDlg::ShiftDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,420 ), wxDefaultSize );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText37->Wrap( -1 );
	bSizer43->Add( m_staticText37, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, ID_GRUPPO, wxDefaultPosition, wxDefaultSize, m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	m_Gruppo->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer43->Add( m_Gruppo, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer43, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221111 = new wxStaticText( this, wxID_ANY, _("Data"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText221111->Wrap( -1 );
	bSizer48->Add( m_staticText221111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Data = new wxDatePickerCtrl( this, ID_DATA, wxDefaultDateTime, wxDefaultPosition, wxSize( 130,-1 ), wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer48->Add( m_Data, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer48, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Cognome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText31->Wrap( -1 );
	bSizer37->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxComboBox( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer37->Add( m_Cognome, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer37, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText311 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText311->Wrap( -1 );
	bSizer371->Add( m_staticText311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxComboBox( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer371->Add( m_Nome, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer371, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, _("Qualifica"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText32->Wrap( -1 );
	bSizer38->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_QualificaChoices;
	m_Qualifica = new wxChoice( this, ID_QUALIFICA, wxDefaultPosition, wxDefaultSize, m_QualificaChoices, 0 );
	m_Qualifica->SetSelection( 0 );
	m_Qualifica->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer38->Add( m_Qualifica, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxArrayString m_QualificaStatoChoices;
	m_QualificaStato = new wxChoice( this, ID_QUALIFICA_STATO, wxDefaultPosition, wxDefaultSize, m_QualificaStatoChoices, 0 );
	m_QualificaStato->SetSelection( 0 );
	m_QualificaStato->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer38->Add( m_QualificaStato, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer38, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, _("Tipo di Servizio"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText51->Wrap( -1 );
	bSizer69->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_TipoServizioChoices;
	m_TipoServizio = new wxChoice( this, ID_TIPO_SERVIZIO, wxDefaultPosition, wxDefaultSize, m_TipoServizioChoices, 0 );
	m_TipoServizio->SetSelection( 0 );
	m_TipoServizio->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer69->Add( m_TipoServizio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer69, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6931;
	bSizer6931 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5111 = new wxStaticText( this, wxID_ANY, _("Mezzo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText5111->Wrap( -1 );
	bSizer6931->Add( m_staticText5111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_MezzoChoices;
	m_Mezzo = new wxChoice( this, ID_MEZZO, wxDefaultPosition, wxDefaultSize, m_MezzoChoices, 0 );
	m_Mezzo->SetSelection( 0 );
	m_Mezzo->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer6931->Add( m_Mezzo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer6931, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221112 = new wxStaticText( this, wxID_ANY, _("Ora Inizio Turno"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText221112->Wrap( -1 );
	bSizer49->Add( m_staticText221112, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraInizio = new wxTextCtrl( this, ID_ORA_INIZIO, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraInizio->SetMaxLength( 5 ); 
	bSizer49->Add( m_OraInizio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer49, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText58 = new wxStaticText( this, wxID_ANY, _("Ora Fine Turno"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText58->Wrap( -1 );
	bSizer84->Add( m_staticText58, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraFine = new wxTextCtrl( this, ID_ORA_FINE, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraFine->SetMaxLength( 5 ); 
	bSizer84->Add( m_OraFine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer84, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer36 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ShiftDlg::OnClose ) );
	m_Cognome->Connect( wxEVT_KEY_UP, wxKeyEventHandler( ShiftDlg::OnWrite ), NULL, this );
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KEY_UP, wxKeyEventHandler( ShiftDlg::OnWrite ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_Qualifica->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_QualificaStato->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_TipoServizio->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_Mezzo->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_OraInizio->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_OraFine->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShiftDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShiftDlg::OnCancel ), NULL, this );
}

ShiftDlg::~ShiftDlg()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ShiftDlg::OnClose ) );
	m_Cognome->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( ShiftDlg::OnWrite ), NULL, this );
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( ShiftDlg::OnWrite ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_Qualifica->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_QualificaStato->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_TipoServizio->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_Mezzo->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ShiftDlg::OnChoice ), NULL, this );
	m_OraInizio->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_OraFine->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ShiftDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShiftDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShiftDlg::OnCancel ), NULL, this );
	
}

ServiceRegistryDlg::ServiceRegistryDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1000,748 ), wxDefaultSize );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer192;
	bSizer192 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText56 = new wxStaticText( this, wxID_ANY, _("Servizio Num."), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText56->Wrap( -1 );
	m_staticText56->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer192->Add( m_staticText56, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NumeroScheda = new wxTextCtrl( this, ID_NUM_SCHEDA, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxTE_RIGHT );
	m_NumeroScheda->SetMaxLength( 0 ); 
	bSizer192->Add( m_NumeroScheda, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText68 = new wxStaticText( this, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText68->Wrap( -1 );
	m_staticText68->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer192->Add( m_staticText68, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NumeroSchedaSup = new wxTextCtrl( this, ID_NUM_SCHEDA_SUP, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxTE_LEFT );
	m_NumeroSchedaSup->SetMaxLength( 0 ); 
	bSizer192->Add( m_NumeroSchedaSup, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText62 = new wxStaticText( this, wxID_ANY, _("Gruppo di"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText62->Wrap( -1 );
	m_staticText62->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer192->Add( m_staticText62, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Gruppo = new wxTextCtrl( this, ID_GRUPPO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_Gruppo->SetMaxLength( 0 ); 
	bSizer192->Add( m_Gruppo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText621 = new wxStaticText( this, wxID_ANY, _("Mezzo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText621->Wrap( -1 );
	m_staticText621->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer192->Add( m_staticText621, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodAmbulanza = new wxTextCtrl( this, ID_COD_AMBULANZA, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxTE_RIGHT );
	m_CodAmbulanza->SetMaxLength( 0 ); 
	bSizer192->Add( m_CodAmbulanza, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText69 = new wxStaticText( this, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText69->Wrap( -1 );
	m_staticText69->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer192->Add( m_staticText69, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodAmbulanza118 = new wxTextCtrl( this, ID_COD_AMBULANZA_118, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_LEFT );
	m_CodAmbulanza118->SetMaxLength( 0 ); 
	bSizer192->Add( m_CodAmbulanza118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText92 = new wxStaticText( this, wxID_ANY, _("Targa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	bSizer192->Add( m_staticText92, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_TargaAmbulanza = new wxTextCtrl( this, ID_TARGA_AMBULANZA, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), wxTE_CENTRE );
	m_TargaAmbulanza->SetMaxLength( 0 ); 
	bSizer192->Add( m_TargaAmbulanza, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer78->Add( bSizer192, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText57 = new wxStaticText( this, wxID_ANY, _("Data"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText57->Wrap( -1 );
	bSizer79->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Data = new wxDatePickerCtrl( this, ID_DATA, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	bSizer79->Add( m_Data, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer79->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText160 = new wxStaticText( this, wxID_ANY, _("Inizio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText160->Wrap( -1 );
	bSizer79->Add( m_staticText160, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraInizio = new wxTextCtrl( this, ID_ORA_INIZIO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_OraInizio->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer79->Add( m_OraInizio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText16021 = new wxStaticText( this, wxID_ANY, _("Fine"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16021->Wrap( -1 );
	bSizer79->Add( m_staticText16021, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraFine = new wxTextCtrl( this, ID_ORA_FINE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_OraFine->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer79->Add( m_OraFine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer78->Add( bSizer79, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer186;
	bSizer186 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel1 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer187;
	bSizer187 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer1651;
	bSizer1651 = new wxBoxSizer( wxVERTICAL );
	
	m_Richiesto_118 = new wxRadioButton( m_panel1, ID_RICHIESTO_118, _("118"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer1651->Add( m_Richiesto_118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Asl = new wxRadioButton( m_panel1, ID_RICHIESTO_ASL, _("ASL"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer1651->Add( m_Richiesto_Asl, 0, wxALL, 5 );
	
	m_Richiesto_Ospedali = new wxRadioButton( m_panel1, ID_RICHIESTO_OSPEDALI, _("Ospedali"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer1651->Add( m_Richiesto_Ospedali, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Parenti = new wxRadioButton( m_panel1, ID_RICHIESTO_PARENTI, _("Parenti"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer1651->Add( m_Richiesto_Parenti, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Altri = new wxRadioButton( m_panel1, ID_RICHIESTO_ALTRI, _("Altri"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer1651->Add( m_Richiesto_Altri, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Servizio_Interno = new wxRadioButton( m_panel1, ID_SERVIZIO_INTERNO, _("Servizio Interno"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer1651->Add( m_Servizio_Interno, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer3->Add( bSizer1651, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer173;
	bSizer173 = new wxBoxSizer( wxHORIZONTAL );
	
	m_NumScheda118_Label = new wxStaticText( m_panel1, wxID_ANY, _("Numero di Scheda 118"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_NumScheda118_Label->Wrap( -1 );
	bSizer173->Add( m_NumScheda118_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NumScheda118 = new wxTextCtrl( m_panel1, ID_SCHEDA_118, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_NumScheda118->SetMaxLength( 0 ); 
	bSizer173->Add( m_NumScheda118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer162->Add( bSizer173, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Tipo_Label = new wxStaticText( m_panel1, wxID_ANY, _("Tipologia di servizio"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_Tipo_Label->Wrap( -1 );
	bSizer154->Add( m_Tipo_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxArrayString m_TipoChoices;
	m_Tipo = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_TipoChoices, 0 );
	m_Tipo->SetSelection( 0 );
	bSizer154->Add( m_Tipo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_AltraTipologia = new wxTextCtrl( m_panel1, ID_ALTRA_TIPOLOGIA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer154->Add( m_AltraTipologia, 1, wxALL, 5 );
	
	
	bSizer162->Add( bSizer154, 0, wxEXPAND, 5 );
	
	
	fgSizer3->Add( bSizer162, 1, wxEXPAND, 5 );
	
	
	bSizer187->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	
	bSizer187->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Luogo d'intervento") ), wxVERTICAL );
	
	wxBoxSizer* bSizer179;
	bSizer179 = new wxBoxSizer( wxHORIZONTAL );
	
	m_LuogoIntervento = new wxTextCtrl( m_panel1, ID_LUOGOINTERVENTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_LuogoIntervento->SetMaxLength( 0 ); 
	bSizer179->Add( m_LuogoIntervento, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer11->Add( bSizer179, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer180;
	bSizer180 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText102 = new wxStaticText( m_panel1, wxID_ANY, _("CAP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	bSizer180->Add( m_staticText102, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_LuogoIntervento_CAP = new wxTextCtrl( m_panel1, ID_LUOGOINTERVENTO_CAP, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_LuogoIntervento_CAP->SetMaxLength( 0 ); 
	bSizer180->Add( m_LuogoIntervento_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText103 = new wxStaticText( m_panel1, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText103->Wrap( -1 );
	bSizer180->Add( m_staticText103, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_LuogoIntervento_Citta = new wxTextCtrl( m_panel1, ID_LUOGOINTERVENTO_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_LuogoIntervento_Citta->SetMaxLength( 0 ); 
	bSizer180->Add( m_LuogoIntervento_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText104 = new wxStaticText( m_panel1, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText104->Wrap( -1 );
	bSizer180->Add( m_staticText104, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_LuogoIntervento_Provincia = new wxTextCtrl( m_panel1, ID_LUOGOINTERVENTO_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_LuogoIntervento_Provincia->SetMaxLength( 2 ); 
	bSizer180->Add( m_LuogoIntervento_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer11->Add( bSizer180, 0, wxEXPAND, 5 );
	
	
	bSizer187->Add( sbSizer11, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer51;
	sbSizer51 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Presenti sul posto") ), wxVERTICAL );
	
	sbSizer51->SetMinSize( wxSize( 200,-1 ) ); 
	m_Carabinieri_Checked = new wxCheckBox( m_panel1, wxID_ANY, _("Carabinieri"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer51->Add( m_Carabinieri_Checked, 0, wxALL, 5 );
	
	m_Polizia_Checked = new wxCheckBox( m_panel1, wxID_ANY, _("Polizia"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer51->Add( m_Polizia_Checked, 0, wxALL, 5 );
	
	m_Polizia_Municipale_Checked = new wxCheckBox( m_panel1, wxID_ANY, _("Polizia Municipale"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer51->Add( m_Polizia_Municipale_Checked, 0, wxALL, 5 );
	
	m_Vigili_del_Fuoco_Checked = new wxCheckBox( m_panel1, wxID_ANY, _("Vigili del fuoco"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer51->Add( m_Vigili_del_Fuoco_Checked, 0, wxALL, 5 );
	
	m_Guardia_Medica_Checked = new wxCheckBox( m_panel1, wxID_ANY, _("Guardia Medica"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer51->Add( m_Guardia_Medica_Checked, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Altro_Mezzo_Checked = new wxCheckBox( m_panel1, wxID_ANY, _("Altro"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer181->Add( m_Altro_Mezzo_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Altro_Mezzo = new wxTextCtrl( m_panel1, ID_ALTRO_MEZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Altro_Mezzo->SetMaxLength( 0 ); 
	bSizer181->Add( m_Altro_Mezzo, 1, wxALL, 5 );
	
	
	sbSizer51->Add( bSizer181, 0, wxEXPAND, 5 );
	
	
	bSizer187->Add( sbSizer51, 0, wxALL, 5 );
	
	
	m_panel1->SetSizer( bSizer187 );
	m_panel1->Layout();
	bSizer187->Fit( m_panel1 );
	m_notebook->AddPage( m_panel1, _("Richiesto"), false );
	m_panel2 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1652;
	bSizer1652 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1621;
	bSizer1621 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Richiesto_Nominativo_Label = new wxStaticText( m_panel2, wxID_ANY, _("Nominativo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_Richiesto_Nominativo_Label->Wrap( -1 );
	bSizer1621->Add( m_Richiesto_Nominativo_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Nominativo = new wxTextCtrl( m_panel2, ID_RICHIESTO_NOMINATIVO, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_Richiesto_Nominativo->SetMaxLength( 0 ); 
	bSizer1621->Add( m_Richiesto_Nominativo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1652->Add( bSizer1621, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1623;
	bSizer1623 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Richiesto_CF_PIVA_Label = new wxStaticText( m_panel2, wxID_ANY, _("C.F./P.IVA"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_Richiesto_CF_PIVA_Label->Wrap( -1 );
	bSizer1623->Add( m_Richiesto_CF_PIVA_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_CF_PIVA = new wxTextCtrl( m_panel2, ID_RICHIESTO_CF_PIVA, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_Richiesto_CF_PIVA->SetMaxLength( 0 ); 
	bSizer1623->Add( m_Richiesto_CF_PIVA, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1652->Add( bSizer1623, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1611;
	bSizer1611 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Richiesto_Indirizzo_Label = new wxStaticText( m_panel2, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_Richiesto_Indirizzo_Label->Wrap( -1 );
	bSizer1611->Add( m_Richiesto_Indirizzo_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Indirizzo = new wxTextCtrl( m_panel2, ID_RICHIESTO_INDIRIZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Richiesto_Indirizzo->SetMaxLength( 0 ); 
	bSizer1611->Add( m_Richiesto_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Civico_Label = new wxStaticText( m_panel2, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Richiesto_Civico_Label->Wrap( -1 );
	bSizer1611->Add( m_Richiesto_Civico_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Civico = new wxTextCtrl( m_panel2, ID_RICHIESTO_CIVICO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Richiesto_Civico->SetMaxLength( 0 ); 
	bSizer1611->Add( m_Richiesto_Civico, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1652->Add( bSizer1611, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer165;
	bSizer165 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Richiesto_CAP_Label = new wxStaticText( m_panel2, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_Richiesto_CAP_Label->Wrap( -1 );
	bSizer165->Add( m_Richiesto_CAP_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_CAP = new wxTextCtrl( m_panel2, ID_RICHIESTO_CAP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Richiesto_CAP->SetMaxLength( 0 ); 
	bSizer165->Add( m_Richiesto_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Citta_Label = new wxStaticText( m_panel2, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Richiesto_Citta_Label->Wrap( -1 );
	bSizer165->Add( m_Richiesto_Citta_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Citta = new wxTextCtrl( m_panel2, ID_RICHIESTO_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Richiesto_Citta->SetMaxLength( 0 ); 
	bSizer165->Add( m_Richiesto_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Provincia_Label = new wxStaticText( m_panel2, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Richiesto_Provincia_Label->Wrap( -1 );
	bSizer165->Add( m_Richiesto_Provincia_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Richiesto_Provincia = new wxTextCtrl( m_panel2, ID_RICHIESTO_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), 0 );
	m_Richiesto_Provincia->SetMaxLength( 2 ); 
	bSizer165->Add( m_Richiesto_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1652->Add( bSizer165, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1661;
	bSizer1661 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Dati_Pagamento_Label = new wxStaticText( m_panel2, wxID_ANY, _("Tipologia di pagamento"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_Dati_Pagamento_Label->Wrap( -1 );
	bSizer1661->Add( m_Dati_Pagamento_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_Dati_PagamentoChoices;
	m_Dati_Pagamento = new wxChoice( m_panel2, ID_DATI_PAGAMENTO, wxDefaultPosition, wxSize( 200,-1 ), m_Dati_PagamentoChoices, 0 );
	m_Dati_Pagamento->SetSelection( 0 );
	bSizer1661->Add( m_Dati_Pagamento, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Importo_Label = new wxStaticText( m_panel2, wxID_ANY, _("Importo in Euro"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_Importo_Label->Wrap( -1 );
	bSizer1661->Add( m_Importo_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Importo = new wxTextCtrl( m_panel2, ID_IMPORTO, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxTE_RIGHT );
	m_Importo->SetMaxLength( 0 ); 
	bSizer1661->Add( m_Importo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1652->Add( bSizer1661, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer13;
	sbSizer13 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Orari passaggi radio con il 118") ), wxVERTICAL );
	
	wxBoxSizer* bSizer2321;
	bSizer2321 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1601 = new wxStaticText( m_panel2, wxID_ANY, _("Partenza"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1601->Wrap( -1 );
	m_staticText1601->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer2321->Add( m_staticText1601, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraPartenza = new wxTextCtrl( m_panel2, ID_ORA_PARTENZA, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_OraPartenza->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer2321->Add( m_OraPartenza, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer2321, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2322;
	bSizer2322 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1602 = new wxStaticText( m_panel2, wxID_ANY, _("Arrivo Target/R.V."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1602->Wrap( -1 );
	m_staticText1602->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer2322->Add( m_staticText1602, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraArrivoTarget = new wxTextCtrl( m_panel2, ID_ORA_ARRIVO_TARGET, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_OraArrivoTarget->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer2322->Add( m_OraArrivoTarget, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer2322, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2323;
	bSizer2323 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1603 = new wxStaticText( m_panel2, wxID_ANY, _("Partenza Target/R.V."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1603->Wrap( -1 );
	m_staticText1603->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer2323->Add( m_staticText1603, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraPartenzaTarget = new wxTextCtrl( m_panel2, ID_ORA_PARTENZA_TARGET, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_OraPartenzaTarget->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer2323->Add( m_OraPartenzaTarget, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer2323, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer23211;
	bSizer23211 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16011 = new wxStaticText( m_panel2, wxID_ANY, _("Arrivo H/Altro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16011->Wrap( -1 );
	m_staticText16011->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer23211->Add( m_staticText16011, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraArrivo = new wxTextCtrl( m_panel2, ID_ORA_ARRIVO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_OraArrivo->SetMinSize( wxSize( 50,-1 ) );
	
	bSizer23211->Add( m_OraArrivo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer13->Add( bSizer23211, 0, wxEXPAND, 5 );
	
	
	bSizer1652->Add( sbSizer13, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Mezzo") ), wxVERTICAL );
	
	wxBoxSizer* bSizer1691;
	bSizer1691 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText101 = new wxStaticText( m_panel2, wxID_ANY, _("Km Percorsi"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText101->Wrap( -1 );
	bSizer1691->Add( m_staticText101, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_KmPercorsi = new wxTextCtrl( m_panel2, ID_KM_PERCORSI, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	m_KmPercorsi->SetMaxLength( 0 ); 
	bSizer1691->Add( m_KmPercorsi, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer3->Add( bSizer1691, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer170;
	bSizer170 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText106 = new wxStaticText( m_panel2, wxID_ANY, _("Fermo macchina"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText106->Wrap( -1 );
	bSizer170->Add( m_staticText106, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Ore_Fermo_Macchina = new wxTextCtrl( m_panel2, ID_ORE_FERMO_MACCHINA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_RIGHT );
	m_Ore_Fermo_Macchina->SetMaxLength( 0 ); 
	bSizer170->Add( m_Ore_Fermo_Macchina, 1, wxALL, 5 );
	
	m_staticText107 = new wxStaticText( m_panel2, wxID_ANY, _("Ore"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText107->Wrap( -1 );
	bSizer170->Add( m_staticText107, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer3->Add( bSizer170, 1, wxEXPAND, 5 );
	
	
	bSizer1652->Add( sbSizer3, 0, wxALL, 5 );
	
	
	m_panel2->SetSizer( bSizer1652 );
	m_panel2->Layout();
	bSizer1652->Fit( m_panel2 );
	m_notebook->AddPage( m_panel2, _("Fatturazione"), false );
	m_panel3 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer189;
	bSizer189 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1158;
	bSizer1158 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Pazienti = new wxListCtrl( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer1158->Add( m_Pazienti, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1321;
	bSizer1321 = new wxBoxSizer( wxVERTICAL );
	
	m_bpButton_Add_Patient = new wxBitmapButton( m_panel3, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer1321->Add( m_bpButton_Add_Patient, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_bpButton_Modify_Patient = new wxBitmapButton( m_panel3, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer1321->Add( m_bpButton_Modify_Patient, 0, wxRIGHT|wxLEFT, 5 );
	
	m_bpButton_Del_Patient = new wxBitmapButton( m_panel3, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer1321->Add( m_bpButton_Del_Patient, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer1158->Add( bSizer1321, 0, wxEXPAND, 5 );
	
	
	bSizer189->Add( bSizer1158, 0, wxEXPAND, 5 );
	
	m_scrolledWindow1 = new wxScrolledWindow( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer120;
	bSizer120 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1232;
	bSizer1232 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1112 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Cod. Fiscale"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText1112->Wrap( -1 );
	bSizer1232->Add( m_staticText1112, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodFiscale = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_CodFiscale->SetMaxLength( 0 ); 
	bSizer1232->Add( m_CodFiscale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText152 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Numero Team"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText152->Wrap( -1 );
	bSizer1232->Add( m_staticText152, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NumTeam = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_NumTeam->SetMaxLength( 0 ); 
	bSizer1232->Add( m_NumTeam, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer1232, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText111 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText111->Wrap( -1 );
	bSizer123->Add( m_staticText111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Indirizzo = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Indirizzo->SetMaxLength( 0 ); 
	bSizer123->Add( m_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText15 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer123->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Civico = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Civico->SetMaxLength( 0 ); 
	bSizer123->Add( m_Civico, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer123, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText16->Wrap( -1 );
	bSizer124->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_CAP->SetMaxLength( 0 ); 
	bSizer124->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText17 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer124->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Citta->SetMaxLength( 0 ); 
	bSizer124->Add( m_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText18 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer124->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer124->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer124, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1231;
	bSizer1231 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1111 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Stato"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText1111->Wrap( -1 );
	bSizer1231->Add( m_staticText1111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Stato = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Stato->SetMaxLength( 0 ); 
	bSizer1231->Add( m_Stato, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText151 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Cittadinanza"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	bSizer1231->Add( m_staticText151, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cittadinanza = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Cittadinanza->SetMaxLength( 0 ); 
	bSizer1231->Add( m_Cittadinanza, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer1231, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer126;
	bSizer126 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer1162;
	bSizer1162 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText21 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Motivo del"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText21->Wrap( -1 );
	bSizer1162->Add( m_staticText21, 0, wxALL, 5 );
	
	m_staticText211 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Trasporto"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText211->Wrap( -1 );
	bSizer1162->Add( m_staticText211, 0, wxALL, 5 );
	
	
	bSizer158->Add( bSizer1162, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_MotivoDelTrasporto = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,50 ), wxTE_MULTILINE|wxTE_READONLY );
	m_MotivoDelTrasporto->SetMaxLength( 0 ); 
	bSizer158->Add( m_MotivoDelTrasporto, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer126->Add( bSizer158, 1, wxEXPAND, 5 );
	
	
	bSizer120->Add( bSizer126, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1791;
	bSizer1791 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1042 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Trasportato"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText1042->Wrap( -1 );
	bSizer1791->Add( m_staticText1042, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Trasportato->SetMaxLength( 0 ); 
	bSizer1791->Add( m_Trasportato, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer1791, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1801;
	bSizer1801 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1021 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText1021->Wrap( -1 );
	bSizer1801->Add( m_staticText1021, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_CAP = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_READONLY );
	m_Trasportato_CAP->SetMaxLength( 0 ); 
	bSizer1801->Add( m_Trasportato_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText1031 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1031->Wrap( -1 );
	bSizer1801->Add( m_staticText1031, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Citta = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_Trasportato_Citta->SetMaxLength( 0 ); 
	bSizer1801->Add( m_Trasportato_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText1041 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1041->Wrap( -1 );
	bSizer1801->Add( m_staticText1041, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Provincia = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_Trasportato_Provincia->SetMaxLength( 2 ); 
	bSizer1801->Add( m_Trasportato_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer1801, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer188;
	bSizer188 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer42;
	sbSizer42 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow1, wxID_ANY, _("Codici Servizio 118") ), wxVERTICAL );
	
	wxBoxSizer* bSizer239;
	bSizer239 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer240;
	bSizer240 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer160;
	bSizer160 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Evento"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer160->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CodEvento_Gravita = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_CodEvento_Gravita->SetMaxLength( 0 ); 
	m_CodEvento_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer160->Add( m_CodEvento_Gravita, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodEvento_Patologia = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodEvento_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer160->Add( m_CodEvento_Patologia, 0, wxALL, 5 );
	
	m_CodEvento_Luogo = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodEvento_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer160->Add( m_CodEvento_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer160, 0, 0, 5 );
	
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Valutazione Arrivo"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText20->Wrap( -1 );
	bSizer161->Add( m_staticText20, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_CodArrivo_Gravita = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_CodArrivo_Gravita->SetMaxLength( 0 ); 
	m_CodArrivo_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodArrivo_Patologia = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodArrivo_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Patologia, 0, wxALL, 5 );
	
	m_CodArrivo_Luogo = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodArrivo_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer161, 0, 0, 5 );
	
	wxBoxSizer* bSizer1601;
	bSizer1601 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText191 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Valutazione Partenza"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText191->Wrap( -1 );
	bSizer1601->Add( m_staticText191, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CodPartenza_Gravita = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_CodPartenza_Gravita->SetMaxLength( 0 ); 
	m_CodPartenza_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodPartenza_Patologia = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodPartenza_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Patologia, 0, wxALL, 5 );
	
	m_CodPartenza_Luogo = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodPartenza_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer1601, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1612;
	bSizer1612 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText201 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Patologia Secondaria"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText201->Wrap( -1 );
	bSizer1612->Add( m_staticText201, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer1612->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_CodPartenza_Patologia2 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodPartenza_Patologia2->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1612->Add( m_CodPartenza_Patologia2, 0, wxALL, 5 );
	
	
	bSizer1612->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer240->Add( bSizer1612, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16121;
	bSizer16121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2011 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Rilascio"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText2011->Wrap( -1 );
	bSizer16121->Add( m_staticText2011, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_CodRilascio_Gravita = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE|wxTE_READONLY );
	m_CodRilascio_Gravita->SetMaxLength( 0 ); 
	m_CodRilascio_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodRilascio_Patologia = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodRilascio_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Patologia, 0, wxALL, 5 );
	
	m_CodRilascio_Luogo = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_CodRilascio_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer16121, 1, wxEXPAND, 5 );
	
	
	bSizer239->Add( bSizer240, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer244;
	bSizer244 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer245111;
	bSizer245111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText167111 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Patologia Specifica"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText167111->Wrap( -1 );
	bSizer245111->Add( m_staticText167111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_PatologiaSpecifica = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer245111->Add( m_PatologiaSpecifica, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer245111, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer245;
	bSizer245 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText167 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Prest. Principale"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText167->Wrap( -1 );
	bSizer245->Add( m_staticText167, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizer245->Add( m_Prestazione, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText174 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Prest. Secondarie"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText174->Wrap( -1 );
	bSizer245->Add( m_staticText174, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione2 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizer245->Add( m_Prestazione2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione3 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizer245->Add( m_Prestazione3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione4 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizer245->Add( m_Prestazione4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione5 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizer245->Add( m_Prestazione5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer245, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2451;
	bSizer2451 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1671 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Dinamica Riscont."), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText1671->Wrap( -1 );
	bSizer2451->Add( m_staticText1671, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DinamicaRiscontrata = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizer2451->Add( m_DinamicaRiscontrata, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DinamicaRiscontrata2 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE|wxTE_READONLY );
	bSizer2451->Add( m_DinamicaRiscontrata2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer2451, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24511;
	bSizer24511 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16711 = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Triage"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText16711->Wrap( -1 );
	bSizer24511->Add( m_staticText16711, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Triage = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer24511->Add( m_Triage, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer24511, 0, wxEXPAND, 5 );
	
	
	bSizer239->Add( bSizer244, 1, wxEXPAND, 5 );
	
	
	sbSizer42->Add( bSizer239, 1, wxEXPAND, 5 );
	
	
	bSizer188->Add( sbSizer42, 1, wxEXPAND|wxTOP|wxRIGHT, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow1, wxID_ANY, _("Firma") ), wxVERTICAL );
	
	m_FirmaSC_CRI = new wxCheckBox( m_scrolledWindow1, wxID_ANY, _("Scheda C.R.I."), wxDefaultPosition, wxDefaultSize, 0 );
	m_FirmaSC_CRI->Enable( false );
	
	sbSizer9->Add( m_FirmaSC_CRI, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_FirmaSC_118 = new wxCheckBox( m_scrolledWindow1, wxID_ANY, _("Scheda 118"), wxDefaultPosition, wxDefaultSize, 0 );
	m_FirmaSC_118->Enable( false );
	
	sbSizer9->Add( m_FirmaSC_118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer188->Add( sbSizer9, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer120->Add( bSizer188, 0, wxEXPAND, 5 );
	
	
	m_scrolledWindow1->SetSizer( bSizer120 );
	m_scrolledWindow1->Layout();
	bSizer120->Fit( m_scrolledWindow1 );
	bSizer189->Add( m_scrolledWindow1, 1, wxEXPAND|wxALL, 5 );
	
	
	m_panel3->SetSizer( bSizer189 );
	m_panel3->Layout();
	bSizer189->Fit( m_panel3 );
	m_notebook->AddPage( m_panel3, _("Pazienti"), true );
	m_panel4 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer191;
	bSizer191 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Equipaggio = new wxListCtrl( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer191->Add( m_Equipaggio, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxVERTICAL );
	
	m_bpButton_Add_Crew = new wxBitmapButton( m_panel4, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpButton_Add_Crew, 0, wxRIGHT|wxLEFT, 5 );
	
	m_bpButton_Modify_Crew = new wxBitmapButton( m_panel4, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpButton_Modify_Crew, 0, wxRIGHT|wxLEFT, 5 );
	
	m_bpButton_Del_Crew = new wxBitmapButton( m_panel4, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpButton_Del_Crew, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer191->Add( bSizer132, 0, wxALIGN_BOTTOM, 5 );
	
	
	m_panel4->SetSizer( bSizer191 );
	m_panel4->Layout();
	bSizer191->Fit( m_panel4 );
	m_notebook->AddPage( m_panel4, _("Equipaggio"), false );
	m_panel5 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer163;
	bSizer163 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer306;
	bSizer306 = new wxBoxSizer( wxVERTICAL );
	
	m_Note = new wxTextCtrl( m_panel5, ID_NOTE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_Note->SetMaxLength( 0 ); 
	bSizer306->Add( m_Note, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer163->Add( bSizer306, 1, wxEXPAND, 5 );
	
	
	m_panel5->SetSizer( bSizer163 );
	m_panel5->Layout();
	bSizer163->Fit( m_panel5 );
	m_notebook->AddPage( m_panel5, _("Note"), false );
	
	bSizer186->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer78->Add( bSizer186, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer178;
	bSizer178 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText93 = new wxStaticText( this, wxID_ANY, _("Scheda compilata da"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	bSizer178->Add( m_staticText93, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Centralino = new wxTextCtrl( this, ID_CENTRALINO, wxEmptyString, wxDefaultPosition, wxSize( 400,-1 ), wxTE_READONLY );
	m_Centralino->SetMaxLength( 0 ); 
	bSizer178->Add( m_Centralino, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer178->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_Chiuso = new wxCheckBox( this, wxID_ANY, _("Chiuso"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer178->Add( m_Chiuso, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Annullato = new wxCheckBox( this, wxID_ANY, _("Annullato"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer178->Add( m_Annullato, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer78->Add( bSizer178, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer84->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer84->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer84->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer78->Add( bSizer84, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer78 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_NumeroScheda->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_NumeroSchedaSup->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Gruppo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_CodAmbulanza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_CodAmbulanza118->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_TargaAmbulanza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraInizio->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraFine->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_118->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Asl->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Ospedali->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Parenti->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Altri->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Servizio_Interno->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_NumScheda118->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_AltraTipologia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Altro_Mezzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Nominativo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_CF_PIVA->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Civico->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Importo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraPartenza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraArrivoTarget->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraPartenzaTarget->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraArrivo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_KmPercorsi->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Ore_Fermo_Macchina->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Pazienti->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( ServiceRegistryDlg::OnPatientSelected ), NULL, this );
	m_bpButton_Add_Patient->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnAddPatient ), NULL, this );
	m_bpButton_Modify_Patient->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnModifyPatient ), NULL, this );
	m_bpButton_Del_Patient->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnDelPatient ), NULL, this );
	m_CodFiscale->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Stato->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Add_Crew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnAddCrew ), NULL, this );
	m_bpButton_Modify_Crew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnModifyCrew ), NULL, this );
	m_bpButton_Del_Crew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnDelCrew ), NULL, this );
	m_Note->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Centralino->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Chiuso->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnCheckClose ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnCancel ), NULL, this );
}

ServiceRegistryDlg::~ServiceRegistryDlg()
{
	// Disconnect Events
	m_NumeroScheda->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_NumeroSchedaSup->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Gruppo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_CodAmbulanza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_CodAmbulanza118->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_TargaAmbulanza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraInizio->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraFine->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_118->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Asl->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Ospedali->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Parenti->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Richiesto_Altri->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_Servizio_Interno->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ServiceRegistryDlg::OnCheck ), NULL, this );
	m_NumScheda118->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_AltraTipologia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_LuogoIntervento_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Altro_Mezzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Nominativo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_CF_PIVA->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Civico->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Richiesto_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Importo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraPartenza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraArrivoTarget->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraPartenzaTarget->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_OraArrivo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_KmPercorsi->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Ore_Fermo_Macchina->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Pazienti->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( ServiceRegistryDlg::OnPatientSelected ), NULL, this );
	m_bpButton_Add_Patient->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnAddPatient ), NULL, this );
	m_bpButton_Modify_Patient->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnModifyPatient ), NULL, this );
	m_bpButton_Del_Patient->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnDelPatient ), NULL, this );
	m_CodFiscale->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Stato->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Add_Crew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnAddCrew ), NULL, this );
	m_bpButton_Modify_Crew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnModifyCrew ), NULL, this );
	m_bpButton_Del_Crew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnDelCrew ), NULL, this );
	m_Note->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Centralino->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ServiceRegistryDlg::OnExitCtrl ), NULL, this );
	m_Chiuso->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnCheckClose ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ServiceRegistryDlg::OnCancel ), NULL, this );
	
}

AddCrewDlg::AddCrewDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 640,480 ), wxDefaultSize );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText37->Wrap( -1 );
	bSizer43->Add( m_staticText37, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, ID_GRUPPO, wxDefaultPosition, wxDefaultSize, m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	m_Gruppo->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer43->Add( m_Gruppo, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer43, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221111 = new wxStaticText( this, wxID_ANY, _("Data"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText221111->Wrap( -1 );
	bSizer48->Add( m_staticText221111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Data = new wxDatePickerCtrl( this, ID_DATA, wxDefaultDateTime, wxDefaultPosition, wxSize( 130,-1 ), wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer48->Add( m_Data, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText221112 = new wxStaticText( this, wxID_ANY, _("Ora Inizio Turno"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText221112->Wrap( -1 );
	bSizer48->Add( m_staticText221112, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraInizio = new wxTextCtrl( this, ID_ORA_INIZIO, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraInizio->SetMaxLength( 5 ); 
	bSizer48->Add( m_OraInizio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText58 = new wxStaticText( this, wxID_ANY, _("Ora Fine Turno"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText58->Wrap( -1 );
	bSizer48->Add( m_staticText58, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OraFine = new wxTextCtrl( this, ID_ORA_FINE, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_OraFine->SetMaxLength( 5 ); 
	bSizer48->Add( m_OraFine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer48, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5111 = new wxStaticText( this, wxID_ANY, _("Mezzo"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText5111->Wrap( -1 );
	bSizer69->Add( m_staticText5111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_MezzoChoices;
	m_Mezzo = new wxChoice( this, ID_MEZZO, wxDefaultPosition, wxDefaultSize, m_MezzoChoices, 0 );
	m_Mezzo->SetSelection( 0 );
	m_Mezzo->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer69->Add( m_Mezzo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText51111 = new wxStaticText( this, wxID_ANY, _("Tipo di Servizio"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_staticText51111->Wrap( -1 );
	bSizer69->Add( m_staticText51111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_TipoServizioChoices;
	m_TipoServizio = new wxChoice( this, ID_TIPO_SERVIZIO, wxDefaultPosition, wxDefaultSize, m_TipoServizioChoices, 0 );
	m_TipoServizio->SetSelection( 0 );
	m_TipoServizio->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer69->Add( m_TipoServizio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer69, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer191;
	bSizer191 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Equipaggio = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer191->Add( m_Equipaggio, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxVERTICAL );
	
	m_bpButton_Add_Crew = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Add.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpButton_Add_Crew, 0, wxRIGHT|wxLEFT, 5 );
	
	m_bpButton_Modify_Crew = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Modify.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpButton_Modify_Crew, 0, wxRIGHT|wxLEFT, 5 );
	
	m_bpButton_Del_Crew = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Del.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpButton_Del_Crew, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer191->Add( bSizer132, 0, wxALIGN_BOTTOM, 5 );
	
	
	bSizer36->Add( bSizer191, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer36 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_OraInizio->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddCrewDlg::OnExitCtrl ), NULL, this );
	m_OraFine->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddCrewDlg::OnExitCtrl ), NULL, this );
	m_Mezzo->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddCrewDlg::OnChoice ), NULL, this );
	m_TipoServizio->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddCrewDlg::OnChoice ), NULL, this );
	m_bpButton_Add_Crew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnAddCrew ), NULL, this );
	m_bpButton_Modify_Crew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnModifyCrew ), NULL, this );
	m_bpButton_Del_Crew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnDelCrew ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnCancel ), NULL, this );
}

AddCrewDlg::~AddCrewDlg()
{
	// Disconnect Events
	m_OraInizio->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddCrewDlg::OnExitCtrl ), NULL, this );
	m_OraFine->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddCrewDlg::OnExitCtrl ), NULL, this );
	m_Mezzo->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddCrewDlg::OnChoice ), NULL, this );
	m_TipoServizio->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( AddCrewDlg::OnChoice ), NULL, this );
	m_bpButton_Add_Crew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnAddCrew ), NULL, this );
	m_bpButton_Modify_Crew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnModifyCrew ), NULL, this );
	m_bpButton_Del_Crew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnDelCrew ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCrewDlg::OnCancel ), NULL, this );
	
}

CrewDlg::CrewDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 480,190 ), wxDefaultSize );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Cognome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText31->Wrap( -1 );
	bSizer37->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxComboBox( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer37->Add( m_Cognome, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer37, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText311 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText311->Wrap( -1 );
	bSizer371->Add( m_staticText311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxComboBox( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer371->Add( m_Nome, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer371, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, _("Qualifica"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText32->Wrap( -1 );
	bSizer38->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_QualificaChoices;
	m_Qualifica = new wxChoice( this, ID_QUALIFICA, wxDefaultPosition, wxDefaultSize, m_QualificaChoices, 0 );
	m_Qualifica->SetSelection( 0 );
	m_Qualifica->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer38->Add( m_Qualifica, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxArrayString m_QualificaStatoChoices;
	m_QualificaStato = new wxChoice( this, ID_QUALIFICA_STATO, wxDefaultPosition, wxDefaultSize, m_QualificaStatoChoices, 0 );
	m_QualificaStato->SetSelection( 0 );
	m_QualificaStato->SetMinSize( wxSize( 130,-1 ) );
	
	bSizer38->Add( m_QualificaStato, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer38, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer39, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer36 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Cognome->Connect( wxEVT_KEY_UP, wxKeyEventHandler( CrewDlg::OnWrite ), NULL, this );
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CrewDlg::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KEY_UP, wxKeyEventHandler( CrewDlg::OnWrite ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CrewDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CrewDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CrewDlg::OnCancel ), NULL, this );
}

CrewDlg::~CrewDlg()
{
	// Disconnect Events
	m_Cognome->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( CrewDlg::OnWrite ), NULL, this );
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CrewDlg::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( CrewDlg::OnWrite ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( CrewDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CrewDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CrewDlg::OnCancel ), NULL, this );
	
}

PatientDlg::PatientDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 900,700 ), wxDefaultSize );
	
	wxBoxSizer* bSizer120;
	bSizer120 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Cognome"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText4->Wrap( -1 );
	bSizer121->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxTextCtrl( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cognome->SetMaxLength( 0 ); 
	bSizer121->Add( m_Cognome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText42->Wrap( -1 );
	bSizer121->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxTextCtrl( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Nome->SetMaxLength( 0 ); 
	bSizer121->Add( m_Nome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer121, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer208;
	bSizer208 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText138 = new wxStaticText( this, wxID_ANY, _("Codice Fiscale"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText138->Wrap( -1 );
	bSizer208->Add( m_staticText138, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodFiscale = new wxTextCtrl( this, ID_CODICE_FISCALE, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_CodFiscale->SetMaxLength( 0 ); 
	bSizer208->Add( m_CodFiscale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText155 = new wxStaticText( this, wxID_ANY, _("Numero Team"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText155->Wrap( -1 );
	bSizer208->Add( m_staticText155, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Numero_Team = new wxTextCtrl( this, ID_NUMERO_TEAM, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Numero_Team->SetMaxLength( 0 ); 
	bSizer208->Add( m_Numero_Team, 1, wxALL, 5 );
	
	
	bSizer120->Add( bSizer208, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer122;
	bSizer122 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("Data di Nascita"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText14->Wrap( -1 );
	bSizer122->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DataNascita = new wxTextCtrl( this, ID_DATA_NASCITA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_DataNascita->SetMaxLength( 0 ); 
	bSizer122->Add( m_DataNascita, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText135 = new wxStaticText( this, wxID_ANY, _("Eta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText135->Wrap( -1 );
	bSizer122->Add( m_staticText135, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Eta = new wxTextCtrl( this, ID_ETA, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_RIGHT );
	m_Eta->SetMaxLength( 0 ); 
	bSizer122->Add( m_Eta, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Anni = new wxRadioButton( this, wxID_ANY, _("Anni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer122->Add( m_Anni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Mesi = new wxRadioButton( this, wxID_ANY, _("Mesi"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer122->Add( m_Mesi, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Giorni = new wxRadioButton( this, wxID_ANY, _("Giorni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer122->Add( m_Giorni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer122->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, _("Sesso"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText41->Wrap( -1 );
	bSizer122->Add( m_staticText41, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_SessoChoices[] = { _(" -"), _("M"), _("F") };
	int m_SessoNChoices = sizeof( m_SessoChoices ) / sizeof( wxString );
	m_Sesso = new wxChoice( this, ID_SESSO, wxDefaultPosition, wxSize( 60,-1 ), m_SessoNChoices, m_SessoChoices, 0 );
	m_Sesso->SetSelection( 0 );
	bSizer122->Add( m_Sesso, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer122, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText110 = new wxStaticText( this, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText110->Wrap( -1 );
	bSizer123->Add( m_staticText110, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Indirizzo = new wxTextCtrl( this, ID_INDIRIZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Indirizzo->SetMaxLength( 0 ); 
	bSizer123->Add( m_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer123->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Civico = new wxTextCtrl( this, ID_CIVICO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Civico->SetMaxLength( 0 ); 
	bSizer123->Add( m_Civico, 0, wxALL, 5 );
	
	
	bSizer120->Add( bSizer123, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText16->Wrap( -1 );
	bSizer124->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer124->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer124->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer124->Add( m_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer124->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer124->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer124, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer207;
	bSizer207 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText136 = new wxStaticText( this, wxID_ANY, _("Stato"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText136->Wrap( -1 );
	bSizer207->Add( m_staticText136, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_StatoChoices;
	m_Stato = new wxChoice( this, ID_STATO, wxDefaultPosition, wxDefaultSize, m_StatoChoices, 0 );
	m_Stato->SetSelection( 0 );
	bSizer207->Add( m_Stato, 1, wxALL, 5 );
	
	m_staticText137 = new wxStaticText( this, wxID_ANY, _("Cittadinanza"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText137->Wrap( -1 );
	bSizer207->Add( m_staticText137, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cittadinanza = new wxTextCtrl( this, ID_CITTADINANZA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cittadinanza->SetMaxLength( 0 ); 
	bSizer207->Add( m_Cittadinanza, 1, wxALL, 5 );
	
	
	bSizer120->Add( bSizer207, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer126;
	bSizer126 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Motivo del Trasporto"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText21->Wrap( -1 );
	bSizer126->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_MotivoDelTrasporto = new wxTextCtrl( this, ID_MOTIVOTRASPORTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_MotivoDelTrasporto->SetMaxLength( 0 ); 
	bSizer126->Add( m_MotivoDelTrasporto, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer120->Add( bSizer126, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1791;
	bSizer1791 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText143 = new wxStaticText( this, wxID_ANY, _("Trasportato"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText143->Wrap( -1 );
	bSizer1791->Add( m_staticText143, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato = new wxTextCtrl( this, ID_TRASPORTATO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Trasportato->SetMaxLength( 0 ); 
	bSizer1791->Add( m_Trasportato, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer1791, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1801;
	bSizer1801 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText23->Wrap( -1 );
	bSizer1801->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_CAP = new wxTextCtrl( this, ID_TRASPORTATO_CAP, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_Trasportato_CAP->SetMaxLength( 0 ); 
	bSizer1801->Add( m_Trasportato_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer1801->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Citta = new wxTextCtrl( this, ID_TRASPORTATO_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Trasportato_Citta->SetMaxLength( 0 ); 
	bSizer1801->Add( m_Trasportato_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer1801->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Provincia = new wxTextCtrl( this, ID_TRASPORTATO_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Trasportato_Provincia->SetMaxLength( 2 ); 
	bSizer1801->Add( m_Trasportato_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer1801, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer298;
	bSizer298 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer188;
	bSizer188 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer42;
	sbSizer42 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Codici Servizio 118") ), wxVERTICAL );
	
	wxBoxSizer* bSizer239;
	bSizer239 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer240;
	bSizer240 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1602;
	bSizer1602 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Evento"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer1602->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CodEvento_Gravita = new TxtCtrl118Code( this, ID_COD_EVENTO_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodEvento_Gravita->SetMaxLength( 1 ); 
	m_CodEvento_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1602->Add( m_CodEvento_Gravita, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodEvento_Patologia = new TxtCtrl118Code( this, ID_COD_EVENTO_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodEvento_Patologia->SetMaxLength( 2 ); 
	m_CodEvento_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1602->Add( m_CodEvento_Patologia, 0, wxALL, 5 );
	
	m_CodEvento_Luogo = new TxtCtrl118Code( this, ID_COD_EVENTO_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodEvento_Luogo->SetMaxLength( 1 ); 
	m_CodEvento_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1602->Add( m_CodEvento_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer1602, 0, 0, 5 );
	
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Valutazione Arrivo"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText20->Wrap( -1 );
	bSizer161->Add( m_staticText20, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_CodArrivo_Gravita = new TxtCtrl118Code( this, ID_COD_ARRIVO_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodArrivo_Gravita->SetMaxLength( 1 ); 
	m_CodArrivo_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodArrivo_Patologia = new TxtCtrl118Code( this, ID_COD_ARRIVO_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodArrivo_Patologia->SetMaxLength( 2 ); 
	m_CodArrivo_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Patologia, 0, wxALL, 5 );
	
	m_CodArrivo_Luogo = new TxtCtrl118Code( this, ID_COD_ARRIVO_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodArrivo_Luogo->SetMaxLength( 1 ); 
	m_CodArrivo_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer161, 0, 0, 5 );
	
	wxBoxSizer* bSizer1601;
	bSizer1601 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText191 = new wxStaticText( this, wxID_ANY, _("Valutazione Partenza"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText191->Wrap( -1 );
	bSizer1601->Add( m_staticText191, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CodPartenza_Gravita = new TxtCtrl118Code( this, ID_COD_PARTENZA_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodPartenza_Gravita->SetMaxLength( 1 ); 
	m_CodPartenza_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodPartenza_Patologia = new TxtCtrl118Code( this, ID_COD_PARTENZA_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodPartenza_Patologia->SetMaxLength( 5 ); 
	m_CodPartenza_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Patologia, 0, wxALL, 5 );
	
	m_CodPartenza_Luogo = new TxtCtrl118Code( this, ID_COD_PARTENZA_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodPartenza_Luogo->SetMaxLength( 1 ); 
	m_CodPartenza_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer1601, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1612;
	bSizer1612 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText201 = new wxStaticText( this, wxID_ANY, _("Patologia Secondaria"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText201->Wrap( -1 );
	bSizer1612->Add( m_staticText201, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer1612->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_CodPartenza_Patologia2 = new TxtCtrl118Code( this, ID_COD_PARTENZA_P2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodPartenza_Patologia2->SetMaxLength( 5 ); 
	m_CodPartenza_Patologia2->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1612->Add( m_CodPartenza_Patologia2, 0, wxALL, 5 );
	
	
	bSizer1612->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer240->Add( bSizer1612, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16121;
	bSizer16121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2011 = new wxStaticText( this, wxID_ANY, _("Rilascio"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	m_staticText2011->Wrap( -1 );
	bSizer16121->Add( m_staticText2011, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_CodRilascio_Gravita = new TxtCtrl118Code( this, ID_COD_RILASCIO_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodRilascio_Gravita->SetMaxLength( 1 ); 
	m_CodRilascio_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodRilascio_Patologia = new TxtCtrl118Code( this, ID_COD_RILASCIO_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodRilascio_Patologia->SetMaxLength( 5 ); 
	m_CodRilascio_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Patologia, 0, wxALL, 5 );
	
	m_CodRilascio_Luogo = new TxtCtrl118Code( this, ID_COD_RILASCIO_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodRilascio_Luogo->SetMaxLength( 1 ); 
	m_CodRilascio_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer16121, 1, wxEXPAND, 5 );
	
	
	bSizer239->Add( bSizer240, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer244;
	bSizer244 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer245111;
	bSizer245111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText167111 = new wxStaticText( this, wxID_ANY, _("Patologia Specifica"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText167111->Wrap( -1 );
	bSizer245111->Add( m_staticText167111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_PatologiaSpecifica = new wxTextCtrl( this, ID_PATOLOGIA_SPECIFICA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer245111->Add( m_PatologiaSpecifica, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer245111, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer245;
	bSizer245 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText167 = new wxStaticText( this, wxID_ANY, _("Prest. Principale"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText167->Wrap( -1 );
	bSizer245->Add( m_staticText167, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione = new TxtCtrl118Code( this, ID_PRESTAZIONE1, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer245->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText174 = new wxStaticText( this, wxID_ANY, _("Prest. Secondarie"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText174->Wrap( -1 );
	bSizer245->Add( m_staticText174, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione2 = new TxtCtrl118Code( this, ID_PRESTAZIONE2, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione2->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione3 = new TxtCtrl118Code( this, ID_PRESTAZIONE3, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione3->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione4 = new TxtCtrl118Code( this, ID_PRESTAZIONE4, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione4->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione5 = new TxtCtrl118Code( this, ID_PRESTAZIONE5, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione5->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer245, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2451;
	bSizer2451 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1671 = new wxStaticText( this, wxID_ANY, _("Dinamica Riscont."), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText1671->Wrap( -1 );
	bSizer2451->Add( m_staticText1671, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DinamicaRiscontrata = new TxtCtrl118Code( this, ID_DINAMICA1, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_DinamicaRiscontrata->SetMaxLength( 2 ); 
	bSizer2451->Add( m_DinamicaRiscontrata, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DinamicaRiscontrata2 = new TxtCtrl118Code( this, ID_DINAMICA2, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_DinamicaRiscontrata2->SetMaxLength( 2 ); 
	bSizer2451->Add( m_DinamicaRiscontrata2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer2451, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24511;
	bSizer24511 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16711 = new wxStaticText( this, wxID_ANY, _("Triage"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText16711->Wrap( -1 );
	bSizer24511->Add( m_staticText16711, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Triage = new wxTextCtrl( this, ID_TRIAGE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24511->Add( m_Triage, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer24511, 0, wxEXPAND, 5 );
	
	
	bSizer239->Add( bSizer244, 1, wxEXPAND, 5 );
	
	
	sbSizer42->Add( bSizer239, 1, wxEXPAND, 5 );
	
	
	bSizer188->Add( sbSizer42, 1, wxEXPAND|wxTOP|wxRIGHT, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Firma") ), wxVERTICAL );
	
	m_FirmaSC_CRI = new wxCheckBox( this, wxID_ANY, _("Scheda C.R.I."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( m_FirmaSC_CRI, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_FirmaSC_118 = new wxCheckBox( this, wxID_ANY, _("Scheda 118"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( m_FirmaSC_118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer188->Add( sbSizer9, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer298->Add( bSizer188, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizer120->Add( bSizer298, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer129;
	bSizer129 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline12 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer129->Add( m_staticline12, 0, wxEXPAND | wxALL, 5 );
	
	
	bSizer120->Add( bSizer129, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer120->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer120 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_CodFiscale->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Numero_Team->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_DataNascita->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Eta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Civico->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_MotivoDelTrasporto->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_PatologiaSpecifica->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Triage->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PatientDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PatientDlg::OnCancel ), NULL, this );
}

PatientDlg::~PatientDlg()
{
	// Disconnect Events
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_CodFiscale->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Numero_Team->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_DataNascita->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Eta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Civico->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_MotivoDelTrasporto->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_PatologiaSpecifica->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_Triage->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( PatientDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PatientDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PatientDlg::OnCancel ), NULL, this );
	
}

AddPatient118Dlg::AddPatient118Dlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 900,700 ), wxDefaultSize );
	
	wxBoxSizer* bSizer120;
	bSizer120 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Cognome *"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText4->Wrap( -1 );
	bSizer121->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxTextCtrl( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cognome->SetMaxLength( 0 ); 
	bSizer121->Add( m_Cognome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText42->Wrap( -1 );
	bSizer121->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxTextCtrl( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Nome->SetMaxLength( 0 ); 
	bSizer121->Add( m_Nome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer121, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer208;
	bSizer208 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText138 = new wxStaticText( this, wxID_ANY, _("Codice Fiscale"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText138->Wrap( -1 );
	bSizer208->Add( m_staticText138, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodFiscale = new wxTextCtrl( this, ID_CODICE_FISCALE, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_CodFiscale->SetMaxLength( 0 ); 
	bSizer208->Add( m_CodFiscale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText154 = new wxStaticText( this, wxID_ANY, _("Numero Team"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText154->Wrap( -1 );
	bSizer208->Add( m_staticText154, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Numero_Team = new wxTextCtrl( this, ID_NUMERO_TEAM, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Numero_Team->SetMaxLength( 0 ); 
	bSizer208->Add( m_Numero_Team, 1, wxALL, 5 );
	
	
	bSizer120->Add( bSizer208, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1221;
	bSizer1221 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText141 = new wxStaticText( this, wxID_ANY, _("Data di Nascita"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText141->Wrap( -1 );
	bSizer1221->Add( m_staticText141, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DataNascita = new wxTextCtrl( this, ID_DATA_NASCITA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_DataNascita->SetMaxLength( 0 ); 
	bSizer1221->Add( m_DataNascita, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText1351 = new wxStaticText( this, wxID_ANY, _("Eta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1351->Wrap( -1 );
	bSizer1221->Add( m_staticText1351, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Eta = new wxTextCtrl( this, ID_ETA, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_RIGHT );
	m_Eta->SetMaxLength( 0 ); 
	bSizer1221->Add( m_Eta, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Anni = new wxRadioButton( this, wxID_ANY, _("Anni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1221->Add( m_Anni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Mesi = new wxRadioButton( this, wxID_ANY, _("Mesi"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1221->Add( m_Mesi, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Giorni = new wxRadioButton( this, wxID_ANY, _("Giorni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1221->Add( m_Giorni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1221->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText411 = new wxStaticText( this, wxID_ANY, _("Sesso"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText411->Wrap( -1 );
	bSizer1221->Add( m_staticText411, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_SessoChoices[] = { _(" -"), _("M"), _("F") };
	int m_SessoNChoices = sizeof( m_SessoChoices ) / sizeof( wxString );
	m_Sesso = new wxChoice( this, ID_SESSO, wxDefaultPosition, wxSize( 60,-1 ), m_SessoNChoices, m_SessoChoices, 0 );
	m_Sesso->SetSelection( 0 );
	bSizer1221->Add( m_Sesso, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer1221, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText110 = new wxStaticText( this, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText110->Wrap( -1 );
	bSizer123->Add( m_staticText110, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Indirizzo = new wxTextCtrl( this, ID_INDIRIZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Indirizzo->SetMaxLength( 0 ); 
	bSizer123->Add( m_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer123->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Civico = new wxTextCtrl( this, ID_CIVICO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Civico->SetMaxLength( 0 ); 
	bSizer123->Add( m_Civico, 0, wxALL, 5 );
	
	
	bSizer120->Add( bSizer123, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText16->Wrap( -1 );
	bSizer124->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer124->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer124->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer124->Add( m_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer124->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer124->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer124, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer207;
	bSizer207 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText136 = new wxStaticText( this, wxID_ANY, _("Stato"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText136->Wrap( -1 );
	bSizer207->Add( m_staticText136, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_StatoChoices;
	m_Stato = new wxChoice( this, ID_STATO, wxDefaultPosition, wxDefaultSize, m_StatoChoices, 0 );
	m_Stato->SetSelection( 0 );
	bSizer207->Add( m_Stato, 1, wxALL, 5 );
	
	m_staticText137 = new wxStaticText( this, wxID_ANY, _("Cittadinanza"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText137->Wrap( -1 );
	bSizer207->Add( m_staticText137, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cittadinanza = new wxTextCtrl( this, ID_CITTADINANZA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cittadinanza->SetMaxLength( 0 ); 
	bSizer207->Add( m_Cittadinanza, 1, wxALL, 5 );
	
	
	bSizer120->Add( bSizer207, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer160;
	bSizer160 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer160->SetMinSize( wxSize( -1,55 ) ); 
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Motivo del Trasporto *"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText21->Wrap( -1 );
	bSizer160->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_MotivoDelTrasporto = new wxTextCtrl( this, ID_MOTIVOTRASPORTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_MotivoDelTrasporto->SetMaxLength( 0 ); 
	bSizer160->Add( m_MotivoDelTrasporto, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer120->Add( bSizer160, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer255;
	bSizer255 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel1 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer239;
	bSizer239 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer240;
	bSizer240 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1602;
	bSizer1602 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( m_panel1, wxID_ANY, _("Evento*"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer1602->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CodEvento_Gravita = new TxtCtrl118Code( m_panel1, ID_COD_EVENTO_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodEvento_Gravita->SetMaxLength( 1 ); 
	m_CodEvento_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1602->Add( m_CodEvento_Gravita, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodEvento_Patologia = new TxtCtrl118Code( m_panel1, ID_COD_EVENTO_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodEvento_Patologia->SetMaxLength( 2 ); 
	m_CodEvento_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1602->Add( m_CodEvento_Patologia, 0, wxALL, 5 );
	
	m_CodEvento_Luogo = new TxtCtrl118Code( m_panel1, ID_COD_EVENTO_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodEvento_Luogo->SetMaxLength( 1 ); 
	m_CodEvento_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1602->Add( m_CodEvento_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer1602, 0, 0, 5 );
	
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( m_panel1, wxID_ANY, _("Valutazione Arrivo*"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText20->Wrap( -1 );
	bSizer161->Add( m_staticText20, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_CodArrivo_Gravita = new TxtCtrl118Code( m_panel1, ID_COD_ARRIVO_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodArrivo_Gravita->SetMaxLength( 1 ); 
	m_CodArrivo_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodArrivo_Patologia = new TxtCtrl118Code( m_panel1, ID_COD_ARRIVO_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodArrivo_Patologia->SetMaxLength( 2 ); 
	m_CodArrivo_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Patologia, 0, wxALL, 5 );
	
	m_CodArrivo_Luogo = new TxtCtrl118Code( m_panel1, ID_COD_ARRIVO_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodArrivo_Luogo->SetMaxLength( 1 ); 
	m_CodArrivo_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer161->Add( m_CodArrivo_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer161, 0, 0, 5 );
	
	wxBoxSizer* bSizer1601;
	bSizer1601 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText191 = new wxStaticText( m_panel1, wxID_ANY, _("Valutazione Partenza*"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText191->Wrap( -1 );
	bSizer1601->Add( m_staticText191, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CodPartenza_Gravita = new TxtCtrl118Code( m_panel1, ID_COD_PARTENZA_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodPartenza_Gravita->SetMaxLength( 1 ); 
	m_CodPartenza_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodPartenza_Patologia = new TxtCtrl118Code( m_panel1, ID_COD_PARTENZA_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodPartenza_Patologia->SetMaxLength( 5 ); 
	m_CodPartenza_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Patologia, 0, wxALL, 5 );
	
	m_CodPartenza_Luogo = new TxtCtrl118Code( m_panel1, ID_COD_PARTENZA_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodPartenza_Luogo->SetMaxLength( 1 ); 
	m_CodPartenza_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer1601->Add( m_CodPartenza_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer1601, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1612;
	bSizer1612 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText201 = new wxStaticText( m_panel1, wxID_ANY, _("Patologia Secondaria"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText201->Wrap( -1 );
	bSizer1612->Add( m_staticText201, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer1612->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_CodPartenza_Patologia2 = new TxtCtrl118Code( m_panel1, ID_COD_PARTENZA_P2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodPartenza_Patologia2->SetMaxLength( 5 ); 
	m_CodPartenza_Patologia2->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer1612->Add( m_CodPartenza_Patologia2, 0, wxALL, 5 );
	
	
	bSizer1612->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer240->Add( bSizer1612, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16121;
	bSizer16121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2011 = new wxStaticText( m_panel1, wxID_ANY, _("Rilascio*"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText2011->Wrap( -1 );
	bSizer16121->Add( m_staticText2011, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_CodRilascio_Gravita = new TxtCtrl118Code( m_panel1, ID_COD_RILASCIO_G, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_CENTRE );
	m_CodRilascio_Gravita->SetMaxLength( 1 ); 
	m_CodRilascio_Gravita->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Gravita, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_CodRilascio_Patologia = new TxtCtrl118Code( m_panel1, ID_COD_RILASCIO_P, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodRilascio_Patologia->SetMaxLength( 5 ); 
	m_CodRilascio_Patologia->SetMinSize( wxSize( 40,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Patologia, 0, wxALL, 5 );
	
	m_CodRilascio_Luogo = new TxtCtrl118Code( m_panel1, ID_COD_RILASCIO_L, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_CodRilascio_Luogo->SetMaxLength( 1 ); 
	m_CodRilascio_Luogo->SetMinSize( wxSize( 20,-1 ) );
	
	bSizer16121->Add( m_CodRilascio_Luogo, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer240->Add( bSizer16121, 1, wxEXPAND, 5 );
	
	
	bSizer239->Add( bSizer240, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer244;
	bSizer244 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer245111;
	bSizer245111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText167111 = new wxStaticText( m_panel1, wxID_ANY, _("Patologia Specifica"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText167111->Wrap( -1 );
	bSizer245111->Add( m_staticText167111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_PatologiaSpecifica = new wxTextCtrl( m_panel1, ID_PATOLOGIA_SPECIFICA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer245111->Add( m_PatologiaSpecifica, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer245111, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer245;
	bSizer245 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText167 = new wxStaticText( m_panel1, wxID_ANY, _("Prest. Principale*"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText167->Wrap( -1 );
	bSizer245->Add( m_staticText167, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione = new TxtCtrl118Code( m_panel1, ID_PRESTAZIONE1, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer245->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText174 = new wxStaticText( m_panel1, wxID_ANY, _("Prest. Secondarie"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText174->Wrap( -1 );
	bSizer245->Add( m_staticText174, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione2 = new TxtCtrl118Code( m_panel1, ID_PRESTAZIONE2, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione2->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione3 = new TxtCtrl118Code( m_panel1, ID_PRESTAZIONE3, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione3->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione4 = new TxtCtrl118Code( m_panel1, ID_PRESTAZIONE4, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione4->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Prestazione5 = new TxtCtrl118Code( m_panel1, ID_PRESTAZIONE5, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_Prestazione5->SetMaxLength( 2 ); 
	bSizer245->Add( m_Prestazione5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer245, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2451;
	bSizer2451 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1671 = new wxStaticText( m_panel1, wxID_ANY, _("Dinamica Riscont."), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText1671->Wrap( -1 );
	bSizer2451->Add( m_staticText1671, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DinamicaRiscontrata = new TxtCtrl118Code( m_panel1, ID_DINAMICA1, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_DinamicaRiscontrata->SetMaxLength( 2 ); 
	bSizer2451->Add( m_DinamicaRiscontrata, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DinamicaRiscontrata2 = new TxtCtrl118Code( m_panel1, ID_DINAMICA2, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_DinamicaRiscontrata2->SetMaxLength( 2 ); 
	bSizer2451->Add( m_DinamicaRiscontrata2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer2451, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24511;
	bSizer24511 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16711 = new wxStaticText( m_panel1, wxID_ANY, _("Triage"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	m_staticText16711->Wrap( -1 );
	bSizer24511->Add( m_staticText16711, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Triage = new wxTextCtrl( m_panel1, ID_TRIAGE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24511->Add( m_Triage, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer244->Add( bSizer24511, 0, wxEXPAND, 5 );
	
	
	bSizer239->Add( bSizer244, 1, wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( bSizer239 );
	m_panel1->Layout();
	bSizer239->Fit( m_panel1 );
	m_notebook->AddPage( m_panel1, _("Codici 118"), true );
	m_panel2 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer256;
	bSizer256 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer194;
	bSizer194 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer194->SetMinSize( wxSize( -1,30 ) ); 
	m_Trasportato = new wxCheckBox( m_panel2, ID_RICOVERATO, _("Ricoverato all'ospedale"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer194->Add( m_Trasportato, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_OspedaleChoices;
	m_Ospedale = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_OspedaleChoices, 0 );
	m_Ospedale->SetSelection( 0 );
	bSizer194->Add( m_Ospedale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer256->Add( bSizer194, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17911;
	bSizer17911 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer17911->SetMinSize( wxSize( -1,30 ) ); 
	m_RifiutaTrasporto = new wxCheckBox( m_panel2, ID_RIFIUTA_TRASPORTO, _("Rifiuta il trasporto"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer17911->Add( m_RifiutaTrasporto, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_RifiutaTrasportoMotivoChoices;
	m_RifiutaTrasportoMotivo = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_RifiutaTrasportoMotivoChoices, 0 );
	m_RifiutaTrasportoMotivo->SetSelection( 0 );
	bSizer17911->Add( m_RifiutaTrasportoMotivo, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer315;
	bSizer315 = new wxBoxSizer( wxHORIZONTAL );
	
	m_FirmaSC_Label = new wxStaticText( m_panel2, wxID_ANY, _("Firma"), wxDefaultPosition, wxDefaultSize, 0 );
	m_FirmaSC_Label->Wrap( -1 );
	bSizer315->Add( m_FirmaSC_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_FirmaSC_118 = new wxCheckBox( m_panel2, wxID_ANY, _("Scheda 118"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer315->Add( m_FirmaSC_118, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_FirmaSC_CRI = new wxCheckBox( m_panel2, wxID_ANY, _("Scheda C.R.I."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer315->Add( m_FirmaSC_CRI, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer17911->Add( bSizer315, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer256->Add( bSizer17911, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer179111;
	bSizer179111 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer179111->SetMinSize( wxSize( -1,30 ) ); 
	m_TrasportatoDaAltraAbulanza = new wxCheckBox( m_panel2, ID_TRASPORTATO_ALTRO_MEZZO, _("Trasportato da altro mezzo"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer179111->Add( m_TrasportatoDaAltraAbulanza, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_AltraAmbulanza = new wxTextCtrl( m_panel2, ID_ALTRA_AMBULANZA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_AltraAmbulanza->SetMaxLength( 0 ); 
	bSizer179111->Add( m_AltraAmbulanza, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer256->Add( bSizer179111, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer195;
	bSizer195 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer195->SetMinSize( wxSize( -1,30 ) ); 
	m_Deceduto = new wxCheckBox( m_panel2, ID_DECEDUTO, _("Deceduto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer195->Add( m_Deceduto, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer256->Add( bSizer195, 0, wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer256 );
	m_panel2->Layout();
	bSizer256->Fit( m_panel2 );
	m_notebook->AddPage( m_panel2, _("Esito"), false );
	
	bSizer255->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer120->Add( bSizer255, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer129;
	bSizer129 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline12 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer129->Add( m_staticline12, 0, wxEXPAND | wxALL, 5 );
	
	
	bSizer120->Add( bSizer129, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer120->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer120 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_CodFiscale->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Numero_Team->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_DataNascita->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Eta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Civico->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_MotivoDelTrasporto->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_PatologiaSpecifica->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Triage->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Trasportato->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_RifiutaTrasporto->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_TrasportatoDaAltraAbulanza->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_AltraAmbulanza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Deceduto->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCancel ), NULL, this );
}

AddPatient118Dlg::~AddPatient118Dlg()
{
	// Disconnect Events
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_CodFiscale->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Numero_Team->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_DataNascita->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Eta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Civico->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_MotivoDelTrasporto->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_PatologiaSpecifica->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Triage->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Trasportato->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_RifiutaTrasporto->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_TrasportatoDaAltraAbulanza->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_AltraAmbulanza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatient118Dlg::OnExitCtrl ), NULL, this );
	m_Deceduto->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCheckBox ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatient118Dlg::OnCancel ), NULL, this );
	
}

AddPatientDlg::AddPatientDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 900,700 ), wxDefaultSize );
	
	wxBoxSizer* bSizer120;
	bSizer120 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Cognome *"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText4->Wrap( -1 );
	bSizer121->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cognome = new wxTextCtrl( this, ID_COGNOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cognome->SetMaxLength( 0 ); 
	bSizer121->Add( m_Cognome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, _("Nome"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText42->Wrap( -1 );
	bSizer121->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Nome = new wxTextCtrl( this, ID_NOME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Nome->SetMaxLength( 0 ); 
	bSizer121->Add( m_Nome, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer121, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer208;
	bSizer208 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText138 = new wxStaticText( this, wxID_ANY, _("Codice Fiscale"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText138->Wrap( -1 );
	bSizer208->Add( m_staticText138, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CodFiscale = new wxTextCtrl( this, ID_CODICE_FISCALE, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_CodFiscale->SetMaxLength( 0 ); 
	bSizer208->Add( m_CodFiscale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer208, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer122;
	bSizer122 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("Data di Nascita"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText14->Wrap( -1 );
	bSizer122->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DataNascita = new wxTextCtrl( this, ID_DATA_NASCITA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_DataNascita->SetMaxLength( 0 ); 
	bSizer122->Add( m_DataNascita, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText135 = new wxStaticText( this, wxID_ANY, _("Eta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText135->Wrap( -1 );
	bSizer122->Add( m_staticText135, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Eta = new wxTextCtrl( this, ID_ETA, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_RIGHT );
	m_Eta->SetMaxLength( 0 ); 
	bSizer122->Add( m_Eta, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Anni = new wxRadioButton( this, wxID_ANY, _("Anni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer122->Add( m_Anni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Mesi = new wxRadioButton( this, wxID_ANY, _("Mesi"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer122->Add( m_Mesi, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Giorni = new wxRadioButton( this, wxID_ANY, _("Giorni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer122->Add( m_Giorni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer122->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, _("Sesso"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText41->Wrap( -1 );
	bSizer122->Add( m_staticText41, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_SessoChoices[] = { _(" -"), _("M"), _("F") };
	int m_SessoNChoices = sizeof( m_SessoChoices ) / sizeof( wxString );
	m_Sesso = new wxChoice( this, ID_SESSO, wxDefaultPosition, wxSize( 60,-1 ), m_SessoNChoices, m_SessoChoices, 0 );
	m_Sesso->SetSelection( 0 );
	bSizer122->Add( m_Sesso, 0, wxALL, 5 );
	
	
	bSizer120->Add( bSizer122, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText110 = new wxStaticText( this, wxID_ANY, _("Indirizzo"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText110->Wrap( -1 );
	bSizer123->Add( m_staticText110, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Indirizzo = new wxTextCtrl( this, ID_INDIRIZZO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Indirizzo->SetMaxLength( 0 ); 
	bSizer123->Add( m_Indirizzo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Civico"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer123->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Civico = new wxTextCtrl( this, ID_CIVICO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Civico->SetMaxLength( 0 ); 
	bSizer123->Add( m_Civico, 0, wxALL, 5 );
	
	
	bSizer120->Add( bSizer123, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText16->Wrap( -1 );
	bSizer124->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CAP = new wxTextCtrl( this, ID_CAP, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_CAP->SetMaxLength( 0 ); 
	bSizer124->Add( m_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer124->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Citta = new wxTextCtrl( this, ID_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Citta->SetMaxLength( 0 ); 
	bSizer124->Add( m_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer124->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Provincia = new wxTextCtrl( this, ID_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Provincia->SetMaxLength( 2 ); 
	bSizer124->Add( m_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer120->Add( bSizer124, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer207;
	bSizer207 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText136 = new wxStaticText( this, wxID_ANY, _("Stato"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText136->Wrap( -1 );
	bSizer207->Add( m_staticText136, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_StatoChoices;
	m_Stato = new wxChoice( this, ID_STATO, wxDefaultPosition, wxDefaultSize, m_StatoChoices, 0 );
	m_Stato->SetSelection( 0 );
	bSizer207->Add( m_Stato, 1, wxALL, 5 );
	
	m_staticText137 = new wxStaticText( this, wxID_ANY, _("Cittadinanza"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText137->Wrap( -1 );
	bSizer207->Add( m_staticText137, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Cittadinanza = new wxTextCtrl( this, ID_CITTADINANZA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Cittadinanza->SetMaxLength( 0 ); 
	bSizer207->Add( m_Cittadinanza, 1, wxALL, 5 );
	
	
	bSizer120->Add( bSizer207, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer160;
	bSizer160 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Motivo del Trasporto *"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText21->Wrap( -1 );
	bSizer160->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_MotivoDelTrasporto = new wxTextCtrl( this, ID_MOTIVOTRASPORTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_MotivoDelTrasporto->SetMaxLength( 0 ); 
	bSizer160->Add( m_MotivoDelTrasporto, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer120->Add( bSizer160, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Trasportato *") ), wxVERTICAL );
	
	wxBoxSizer* bSizer209;
	bSizer209 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Abitazione_Checked = new wxCheckBox( this, ID_ABITAZIONE_CHECKED, _("Abitazione del Paziente"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer209->Add( m_Abitazione_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer10->Add( bSizer209, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2091;
	bSizer2091 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Ospedale_Checked = new wxCheckBox( this, ID_OSPEDALE_CHECKED, _("Ospedale"), wxDefaultPosition, wxSize( 130,-1 ), 0 );
	bSizer2091->Add( m_Ospedale_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_OspedaleChoices;
	m_Ospedale = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_OspedaleChoices, 0 );
	m_Ospedale->SetSelection( 0 );
	bSizer2091->Add( m_Ospedale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer10->Add( bSizer2091, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2092;
	bSizer2092 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Altro_Luogo_Checked = new wxCheckBox( this, ID_ALTRO_LUOGO_CHECKED, _("Altro Luogo"), wxDefaultPosition, wxSize( 130,-1 ), 0 );
	bSizer2092->Add( m_Altro_Luogo_Checked, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Luogo = new wxTextCtrl( this, ID_TRASPORTATO_LUOGO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Trasportato_Luogo->SetMaxLength( 0 ); 
	bSizer2092->Add( m_Trasportato_Luogo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer10->Add( bSizer2092, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1801;
	bSizer1801 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Trasportato_CAP_Label = new wxStaticText( this, wxID_ANY, _("CAP"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_Trasportato_CAP_Label->Wrap( -1 );
	bSizer1801->Add( m_Trasportato_CAP_Label, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_CAP = new wxTextCtrl( this, ID_TRASPORTATO_CAP, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), 0 );
	m_Trasportato_CAP->SetMaxLength( 0 ); 
	bSizer1801->Add( m_Trasportato_CAP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Citta_Label = new wxStaticText( this, wxID_ANY, _("Citta'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Trasportato_Citta_Label->Wrap( -1 );
	bSizer1801->Add( m_Trasportato_Citta_Label, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Citta = new wxTextCtrl( this, ID_TRASPORTATO_CITTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Trasportato_Citta->SetMaxLength( 0 ); 
	bSizer1801->Add( m_Trasportato_Citta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Provincia_Label = new wxStaticText( this, wxID_ANY, _("Provincia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Trasportato_Provincia_Label->Wrap( -1 );
	bSizer1801->Add( m_Trasportato_Provincia_Label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Trasportato_Provincia = new wxTextCtrl( this, ID_TRASPORTATO_PROVINCIA, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_CENTRE );
	m_Trasportato_Provincia->SetMaxLength( 2 ); 
	bSizer1801->Add( m_Trasportato_Provincia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer10->Add( bSizer1801, 1, wxEXPAND, 5 );
	
	
	bSizer120->Add( sbSizer10, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer129;
	bSizer129 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline12 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer129->Add( m_staticline12, 0, wxEXPAND | wxALL, 5 );
	
	
	bSizer120->Add( bSizer129, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer120->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer120 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Cognome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Nome->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_CodFiscale->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_DataNascita->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Eta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Civico->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_MotivoDelTrasporto->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Abitazione_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCheckBox ), NULL, this );
	m_Ospedale_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCheckBox ), NULL, this );
	m_Altro_Luogo_Checked->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCheckBox ), NULL, this );
	m_Trasportato_Luogo->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_CAP->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Citta->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Provincia->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatientDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCancel ), NULL, this );
}

AddPatientDlg::~AddPatientDlg()
{
	// Disconnect Events
	m_Cognome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Nome->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_CodFiscale->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_DataNascita->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Eta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Indirizzo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Civico->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Cittadinanza->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_MotivoDelTrasporto->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Abitazione_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCheckBox ), NULL, this );
	m_Ospedale_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCheckBox ), NULL, this );
	m_Altro_Luogo_Checked->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCheckBox ), NULL, this );
	m_Trasportato_Luogo->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_CAP->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Citta->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_Trasportato_Provincia->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( AddPatientDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatientDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddPatientDlg::OnCancel ), NULL, this );
	
}

SelectDateRangeDlg::SelectDateRangeDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,180 ), wxDefaultSize );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Text = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Text->Wrap( -1 );
	bSizer78->Add( m_Text, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer65->Add( bSizer78, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, _("Dal"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText51->Wrap( -1 );
	bSizer66->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_date_Start = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	bSizer66->Add( m_date_Start, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText52 = new wxStaticText( this, wxID_ANY, _("Al"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE );
	m_staticText52->Wrap( -1 );
	bSizer66->Add( m_staticText52, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_date_End = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	bSizer66->Add( m_date_End, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer65->Add( bSizer66, 1, wxEXPAND, 5 );
	
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
	
	// Connect Events
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDateRangeDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDateRangeDlg::OnCancel ), NULL, this );
}

SelectDateRangeDlg::~SelectDateRangeDlg()
{
	// Disconnect Events
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDateRangeDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDateRangeDlg::OnCancel ), NULL, this );
	
}

SearchDlg::SearchDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,180 ), wxDefaultSize );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer661;
	bSizer661 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, _("Dal"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText51->Wrap( -1 );
	bSizer661->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_date_Start = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	bSizer661->Add( m_date_Start, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText52 = new wxStaticText( this, wxID_ANY, _("Al"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE );
	m_staticText52->Wrap( -1 );
	bSizer661->Add( m_staticText52, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_date_End = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	bSizer661->Add( m_date_End, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer65->Add( bSizer661, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString m_FieldChoices;
	m_Field = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_FieldChoices, 0 );
	m_Field->SetSelection( 0 );
	bSizer68->Add( m_Field, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer66->Add( bSizer68, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer170;
	bSizer170 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Value = new wxTextCtrl( this, ID_VALUE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Value->SetMaxLength( 0 ); 
	bSizer170->Add( m_Value, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer66->Add( bSizer170, 1, wxEXPAND, 5 );
	
	
	bSizer65->Add( bSizer66, 0, wxEXPAND, 5 );
	
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
	
	// Connect Events
	m_Value->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( SearchDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDlg::OnCancel ), NULL, this );
}

SearchDlg::~SearchDlg()
{
	// Disconnect Events
	m_Value->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( SearchDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SearchDlg::OnCancel ), NULL, this );
	
}

OptionsDlg::OptionsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 490,250 ), wxDefaultSize );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer220;
	bSizer220 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer218;
	bSizer218 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText139 = new wxStaticText( this, wxID_ANY, _("Gruppo di Default"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText139->Wrap( -1 );
	bSizer218->Add( m_staticText139, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	bSizer218->Add( m_Gruppo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer220->Add( bSizer218, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer219;
	bSizer219 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText141 = new wxStaticText( this, wxID_ANY, _("Incrementa Numero Servizi"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	bSizer219->Add( m_staticText141, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_IncNumServizi = new wxCheckBox( this, wxID_ANY, _("Si"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer219->Add( m_IncNumServizi, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer220->Add( bSizer219, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer2191;
	bSizer2191 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1411 = new wxStaticText( this, wxID_ANY, _("Incrementa Numero Servizi Supplementare"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1411->Wrap( -1 );
	bSizer2191->Add( m_staticText1411, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_IncNumServiziSup = new wxCheckBox( this, wxID_ANY, _("Si"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2191->Add( m_IncNumServiziSup, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer220->Add( bSizer2191, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer225;
	bSizer225 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText156 = new wxStaticText( this, wxID_ANY, _("Disconnetti automaticamente l'utente dopo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText156->Wrap( -1 );
	bSizer225->Add( m_staticText156, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_AutoLogOutTime = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), wxTE_CENTRE );
	m_AutoLogOutTime->SetMaxLength( 0 ); 
	bSizer225->Add( m_AutoLogOutTime, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText157 = new wxStaticText( this, wxID_ANY, _("minuti di inattivita'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText157->Wrap( -1 );
	bSizer225->Add( m_staticText157, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer220->Add( bSizer225, 0, wxEXPAND|wxALL, 5 );
	
	
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
	
	// Connect Events
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OptionsDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OptionsDlg::OnCancel ), NULL, this );
}

OptionsDlg::~OptionsDlg()
{
	// Disconnect Events
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OptionsDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OptionsDlg::OnCancel ), NULL, this );
	
}

ProgressDlg::ProgressDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,75 ), wxDefaultSize );
	
	wxBoxSizer* bSizer260;
	bSizer260 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer261;
	bSizer261 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Text = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT|wxST_NO_AUTORESIZE );
	m_Text->Wrap( -1 );
	bSizer261->Add( m_Text, 1, wxALL, 5 );
	
	
	bSizer260->Add( bSizer261, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer262;
	bSizer262 = new wxBoxSizer( wxHORIZONTAL );
	
	m_gauge = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL|wxGA_SMOOTH );
	m_gauge->SetValue( 0 ); 
	bSizer262->Add( m_gauge, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer260->Add( bSizer262, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer260 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

ProgressDlg::~ProgressDlg()
{
}

ComunicationDlg::ComunicationDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 420,500 ), wxDefaultSize );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer372;
	bSizer372 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText312 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_staticText312->Wrap( -1 );
	bSizer372->Add( m_staticText312, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GruppoChoices;
	m_Gruppo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_GruppoChoices, 0 );
	m_Gruppo->SetSelection( 0 );
	bSizer372->Add( m_Gruppo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer372, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Da"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_staticText31->Wrap( -1 );
	bSizer37->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ComunicazioneDa = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer37->Add( m_ComunicazioneDa, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer37, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText311 = new wxStaticText( this, wxID_ANY, _("A"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_staticText311->Wrap( -1 );
	bSizer371->Add( m_staticText311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_ComunicazioneToChoices;
	m_ComunicazioneTo = new wxChoice( this, ID_COMUNICAZIONE_TO, wxDefaultPosition, wxDefaultSize, m_ComunicazioneToChoices, 0 );
	m_ComunicazioneTo->SetSelection( 0 );
	bSizer371->Add( m_ComunicazioneTo, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer371, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer373;
	bSizer373 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText313 = new wxStaticText( this, wxID_ANY, _("Oggetto"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_staticText313->Wrap( -1 );
	bSizer373->Add( m_staticText313, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Oggetto = new wxTextCtrl( this, ID_OGGETTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer373->Add( m_Oggetto, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer36->Add( bSizer373, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer841;
	bSizer841 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText581 = new wxStaticText( this, wxID_ANY, _("Comunicazione"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText581->Wrap( -1 );
	bSizer841->Add( m_staticText581, 0, wxALL, 5 );
	
	m_Note = new wxTextCtrl( this, ID_COMUNICAZIONE, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_MULTILINE );
	m_Note->SetMaxLength( 0 ); 
	bSizer841->Add( m_Note, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer36->Add( bSizer841, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer300;
	bSizer300 = new wxBoxSizer( wxVERTICAL );
	
	m_Letta = new wxCheckBox( this, wxID_ANY, _("Letta"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer300->Add( m_Letta, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	
	bSizer36->Add( bSizer300, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer78->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer36->Add( bSizer78, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Ok = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Confirm.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Ok, 0, wxALL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer39->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer39, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer36 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ComunicationDlg::OnClose ) );
	m_Oggetto->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ComunicationDlg::OnExitCtrl ), NULL, this );
	m_Note->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ComunicationDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComunicationDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComunicationDlg::OnCancel ), NULL, this );
}

ComunicationDlg::~ComunicationDlg()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ComunicationDlg::OnClose ) );
	m_Oggetto->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ComunicationDlg::OnExitCtrl ), NULL, this );
	m_Note->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( ComunicationDlg::OnExitCtrl ), NULL, this );
	m_bpButton_Ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComunicationDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComunicationDlg::OnCancel ), NULL, this );
	
}

SelectUserDisponibilityDlg::SelectUserDisponibilityDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,300 ), wxDefaultSize );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer307;
	bSizer307 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText212 = new wxStaticText( this, wxID_ANY, _("Nominativo"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText212->Wrap( -1 );
	bSizer307->Add( m_staticText212, 0, wxALL, 5 );
	
	m_Name = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer307->Add( m_Name, 1, wxALL, 5 );
	
	
	bSizer65->Add( bSizer307, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3273;
	bSizer3273 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2223 = new wxStaticText( this, wxID_ANY, _("Gruppo"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText2223->Wrap( -1 );
	bSizer3273->Add( m_staticText2223, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_GroupChoices;
	m_Group = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_GroupChoices, 0 );
	m_Group->SetSelection( 0 );
	bSizer3273->Add( m_Group, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer65->Add( bSizer3273, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer326;
	bSizer326 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, _("Disponibile il Giorno"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText51->Wrap( -1 );
	bSizer326->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBox_Date = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer326->Add( m_checkBox_Date, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Date = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN );
	bSizer326->Add( m_Date, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer65->Add( bSizer326, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3271;
	bSizer3271 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2221 = new wxStaticText( this, wxID_ANY, _("Qualifica"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText2221->Wrap( -1 );
	bSizer3271->Add( m_staticText2221, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_QualificationChoices;
	m_Qualification = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_QualificationChoices, 0 );
	m_Qualification->SetSelection( 0 );
	bSizer3271->Add( m_Qualification, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer65->Add( bSizer3271, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer327;
	bSizer327 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText222 = new wxStaticText( this, wxID_ANY, _("Tipo di Turno"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText222->Wrap( -1 );
	bSizer327->Add( m_staticText222, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_Qualification_TypeChoices;
	m_Qualification_Type = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Qualification_TypeChoices, 0 );
	m_Qualification_Type->SetSelection( 0 );
	bSizer327->Add( m_Qualification_Type, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer65->Add( bSizer327, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3272;
	bSizer3272 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2222 = new wxStaticText( this, wxID_ANY, _("Qualifica Stato"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_staticText2222->Wrap( -1 );
	bSizer3272->Add( m_staticText2222, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_Qualification_StatusChoices;
	m_Qualification_Status = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Qualification_StatusChoices, 0 );
	m_Qualification_Status->SetSelection( 0 );
	bSizer3272->Add( m_Qualification_Status, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer65->Add( bSizer3272, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer781;
	bSizer781 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer781->Add( m_staticline1, 1, wxALL, 5 );
	
	
	bSizer65->Add( bSizer781, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_Find = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Search.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer67->Add( m_bpButton_Find, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton_Cancel = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Res/bp_Cancel.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer67->Add( m_bpButton_Cancel, 0, wxALL, 5 );
	
	
	bSizer65->Add( bSizer67, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer65 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Name->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( SelectUserDisponibilityDlg::OnExitCtrl ), NULL, this );
	m_checkBox_Date->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SelectUserDisponibilityDlg::OnCheckDate ), NULL, this );
	m_bpButton_Find->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectUserDisponibilityDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectUserDisponibilityDlg::OnCancel ), NULL, this );
}

SelectUserDisponibilityDlg::~SelectUserDisponibilityDlg()
{
	// Disconnect Events
	m_Name->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( SelectUserDisponibilityDlg::OnExitCtrl ), NULL, this );
	m_checkBox_Date->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SelectUserDisponibilityDlg::OnCheckDate ), NULL, this );
	m_bpButton_Find->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectUserDisponibilityDlg::OnOk ), NULL, this );
	m_bpButton_Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectUserDisponibilityDlg::OnCancel ), NULL, this );
	
}

HtmlFrame::HtmlFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,600 ), wxDefaultSize );
	
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer308;
	bSizer308 = new wxBoxSizer( wxVERTICAL );
	
	m_html = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer308->Add( m_html, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer308 );
	this->Layout();
	bSizer308->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_ICONIZE, wxIconizeEventHandler( HtmlFrame::OnIconize ) );
}

HtmlFrame::~HtmlFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ICONIZE, wxIconizeEventHandler( HtmlFrame::OnIconize ) );
	
}
