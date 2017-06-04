///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CRIREGISTRYGUIS_H__
#define __CRIREGISTRYGUIS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class TxtCtrl118Code;

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/combobox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/scrolwin.h>
#include <wx/gauge.h>
#include <wx/statusbr.h>
#include <wx/html/htmlwin.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			ID_SQL_QUERY = 1000,
			ID_OPTIONS,
			ID_USER_LOGIN,
			ID_USER_LOGOUT,
			ID_CHANGE_USER_PWD,
			ID_USERS_MANAGER,
			ID_OPEN_GROUP,
			ID_OPEN_FLEET,
			ID_OPEN_HOSPITAL,
			ID_OPEN_SERVICE_TYPE,
			ID_OPEN_118_SERVICE_TYPE,
			ID_OPEN_INTERNAL_SERVICE_TYPE,
			ID_OPEN_SHIFT_TYPE,
			ID_OPEN_VEHICLE_TYPE,
			ID_OPEN_REASONS_REFUSING_TRANSPORT,
			ID_OPEN_MAILING_LIST,
			ID_PRESENCE_IN,
			ID_PRESENCE_OUT,
			ID_MODIFY_PRESENCE,
			ID_DEL_PRESENCE,
			ID_VIEW_CURRENT_PRESENCE,
			ID_VIEW_ALL_PRESENCE,
			ID_ADD_CREW,
			ID_ADD_SHIFT,
			ID_MODIFY_SHIFT,
			ID_DEL_SHIFT,
			ID_VIEW_CURRENT_SHIFT,
			ID_VIEW_ALL_SHIFT,
			ID_EXPORT_SHIFT,
			ID_IMPORT_SHIFT,
			ID_ADD_SERVICE,
			ID_MODIFY_SERVICE,
			ID_DEL_SERVICE,
			ID_VIEW_CURRENT_SERVICE,
			ID_VIEW_SEARCHED_SERVICE,
			ID_VIEW_ALL_SERVICE,
			ID_EXPORT_SERVICE,
			ID_IMPORT_SERVICE,
			ID_ADD_COMUNICATION,
			ID_MODIFY_COMUNICATION,
			ID_DEL_COMUNICATION,
			ID_VIEW_CURRENT_COMUNICATION,
			ID_VIEW_ALL_COMUNICATION,
			ID_LIST_PRESENCE,
			ID_LIST_SHIFT,
			ID_LIST_SERVICE,
			ID_LIST_COMUNICATION,
			ID_BP_CLOSE
		};
		
		wxMenuBar* m_menubar;
		wxMenu* m_menu_File;
		wxMenu* m_menu_Config;
		wxMenu* m_menu_Users;
		wxMenu* m_menu_Data;
		wxMenu* m_menu_Presence;
		wxMenu* m_menu_Shift;
		wxMenu* m_menu_Service;
		wxMenu* m_menu_Comunication;
		wxMenu* m_menu_Help;
		wxNotebook* m_notebook;
		wxPanel* m_panel_Presence;
		wxListCtrl* m_list_Presence;
		wxBitmapButton* m_bpButton_PresenceIn;
		wxBitmapButton* m_bpButton_PresenceOut;
		wxBitmapButton* m_bpButton_ModifyPresence;
		wxBitmapButton* m_bpButton_DelPresence;
		wxStaticBitmap* m_bitmap_PresenceShowed;
		wxPanel* m_panel_Shift;
		wxListCtrl* m_list_Shift;
		wxBitmapButton* m_bpButton_AddCrew;
		wxBitmapButton* m_bpButton_AddShift;
		wxBitmapButton* m_bpButton_ModifyShift;
		wxBitmapButton* m_bpButton_DelShift;
		wxStaticBitmap* m_bitmap_ShiftShowed;
		wxPanel* m_panel_Service;
		wxListCtrl* m_list_Service;
		wxBitmapButton* m_bpButton_AddService;
		wxBitmapButton* m_bpButton_ModifyService;
		wxBitmapButton* m_bpButton_DelService;
		wxStaticBitmap* m_bitmap_ServiceShowed;
		wxPanel* m_panel_Comunication;
		wxListCtrl* m_list_Comunication;
		wxBitmapButton* m_bpButton_AddComunication;
		wxBitmapButton* m_bpButton_ModifyComunication;
		wxBitmapButton* m_bpButton_DelComunication;
		wxStaticBitmap* m_bitmap_ComunicationShowed;
		wxBitmapButton* m_bpButton_SelectUser;
		wxBitmapButton* m_bpButton_SelectPresence;
		wxBitmapButton* m_bpButton_SelectShift;
		wxBitmapButton* m_bpButton_SelectService;
		wxBitmapButton* m_bpButton_SelectComunication;
		wxBitmapButton* m_bpButton_FindUsers;
		wxStaticText* m_Calendar;
		wxBitmapButton* m_bpButton_Close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnSQLQuery( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOptions( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLogIn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLogOut( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeUsersPwd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsersManager( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenGroup( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenFleet( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenHospital( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenServiceType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpen118ServiceType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenInternalServiceType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenShiftType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenVehicleType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenReasonsRefusingTransport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenMailingList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPresenceIn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPresenceOut( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyPresence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPresenceDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewCurrentPresence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewAllPresence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddCrew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewCurrentShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewAllShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewCurrentService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewSearchedService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewAllService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddComunication( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyComunication( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelComunication( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewCurrentComunication( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewAllComunication( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNotebookPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnKeyPressed( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnPresencesListDbClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnDelPresence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShifsListDbClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnServicesListDbClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnComunicationListDbClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnChangeUser( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPresence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectShift( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectComunication( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectFindUsers( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Registro Servizi"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~MainFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SQLQueryDlg
///////////////////////////////////////////////////////////////////////////////
class SQLQueryDlg : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* m_SQLQuery;
		wxBitmapButton* m_bpButton_QueryAdd;
		wxBitmapButton* m_bpButton_QueryDel;
		wxBitmapButton* m_bpButton_Execute;
		wxBitmapButton* m_bp_OpenQuery;
		wxGrid* m_Grid;
		wxBitmapButton* m_bpButton_Export;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnWrite( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnQueryAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQueryDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQueryExecute( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenQuery( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SQLQueryDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SQL Query"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER ); 
		~SQLQueryDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FleetDlg
///////////////////////////////////////////////////////////////////////////////
class FleetDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_COD_MEZZO = 1000,
			ID_GRUPPO,
			ID_TIPO,
			ID_MODELLO,
			ID_RADIO_118,
			ID_TARGA,
			ID_KM,
			ID_NOTE,
			ID_NON_OPERATIVA
		};
		
		wxListBox* m_listBox_ParcoMacchine;
		wxBitmapButton* m_bpButton_Modify;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Del;
		wxStaticText* m_staticText98;
		wxTextCtrl* m_CodMezzo;
		wxStaticText* m_staticText37;
		wxChoice* m_Gruppo;
		wxStaticText* m_staticText371;
		wxChoice* m_Tipo;
		wxStaticText* m_staticText372;
		wxTextCtrl* m_Modello;
		wxStaticText* m_staticText37312;
		wxTextCtrl* m_Radio118;
		wxStaticText* m_staticText373;
		wxTextCtrl* m_Targa;
		wxStaticText* m_staticText3731;
		wxTextCtrl* m_Km;
		wxStaticText* m_staticText37311;
		wxTextCtrl* m_Note;
		wxCheckBox* m_NonOperativa;
		wxStaticText* m_staticText61;
		wxBitmapButton* m_bpButton_Confirm;
		wxBitmapButton* m_bpButton_Cancel;
		wxStaticLine* m_staticline8;
		wxBitmapButton* m_bpButton_Ok;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnConfirm( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FleetDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Parco Macchine"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 656,486 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~FleetDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class HospitalDlg
///////////////////////////////////////////////////////////////////////////////
class HospitalDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_OSPEDALE = 1000,
			ID_SOCIETA,
			ID_INDIRIZZO,
			ID_CIVICO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA,
			ID_NUM_TEL,
			ID_NUM_FAX,
			ID_NOTE
		};
		
		wxListBox* m_listBox_Ospedali;
		wxBitmapButton* m_bpButton_Modify;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Del;
		wxStaticText* m_staticText706;
		wxTextCtrl* m_Ospedale;
		wxStaticText* m_staticText70;
		wxTextCtrl* m_Societa;
		wxStaticText* m_staticText701;
		wxTextCtrl* m_Indirizzo;
		wxStaticText* m_staticText64;
		wxTextCtrl* m_Civico;
		wxStaticText* m_staticText7031;
		wxTextCtrl* m_CAP;
		wxStaticText* m_staticText702;
		wxTextCtrl* m_Citta;
		wxTextCtrl* m_Provincia;
		wxStaticText* m_staticText703;
		wxTextCtrl* m_NumTel;
		wxStaticText* m_staticText704;
		wxTextCtrl* m_NumFax;
		wxStaticText* m_staticText705;
		wxTextCtrl* m_Note;
		wxStaticText* m_staticText61;
		wxBitmapButton* m_bpButton_Confirm;
		wxBitmapButton* m_bpButton_Cancel;
		wxStaticLine* m_staticline8;
		wxBitmapButton* m_bpButton_Ok;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnConfirm( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		HospitalDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Lista Ospedali"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 656,486 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~HospitalDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class UsersDlg
///////////////////////////////////////////////////////////////////////////////
class UsersDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_UTENTE = 1000,
			ID_COGNOME,
			ID_NOME
		};
		
		wxListBox* m_listBox_Utenti;
		wxStaticText* m_staticText50;
		wxTextCtrl* m_Utente;
		wxStaticText* m_staticText501;
		wxTextCtrl* m_Cognome;
		wxStaticText* m_staticText502;
		wxTextCtrl* m_Nome;
		wxStaticText* m_staticText503;
		wxTextCtrl* m_Password;
		wxStaticText* m_staticText505;
		wxTextCtrl* m_ConfermaPassword;
		wxStaticText* m_staticText504;
		wxChoice* m_Privilegi;
		wxStaticText* m_staticText61;
		wxBitmapButton* m_bpButton_Confirm;
		wxBitmapButton* m_bpButton_Cancel;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Del;
		wxBitmapButton* m_bpButton_Modify;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnConfirm( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		UsersDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Gestione Utenti"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 656,486 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~UsersDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LogInDlg
///////////////////////////////////////////////////////////////////////////////
class LogInDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText46;
		wxTextCtrl* m_Utente;
		wxStaticText* m_staticText47;
		wxTextCtrl* m_Password;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LogInDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Inserire Utente e Password"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 306,158 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~LogInDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChangeUsersPwdDlg
///////////////////////////////////////////////////////////////////////////////
class ChangeUsersPwdDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText4711;
		wxTextCtrl* m_Password;
		wxStaticText* m_staticText471;
		wxTextCtrl* m_NuovaPassword;
		wxStaticText* m_staticText472;
		wxTextCtrl* m_ConfermaPassword;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ChangeUsersPwdDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Cambia Password"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 306,196 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ChangeUsersPwdDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SetUsersPwdDlg
///////////////////////////////////////////////////////////////////////////////
class SetUsersPwdDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText471;
		wxTextCtrl* m_NuovaPassword;
		wxStaticText* m_staticText472;
		wxTextCtrl* m_ConfermaPassword;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SetUsersPwdDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Imposta Password"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 306,158 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SetUsersPwdDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddFieldsDlg
///////////////////////////////////////////////////////////////////////////////
class AddFieldsDlg : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_FieldsList;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Modify;
		wxBitmapButton* m_bpButton_Del;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AddFieldsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 306,406 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddFieldsDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MailingListDlg
///////////////////////////////////////////////////////////////////////////////
class MailingListDlg : public wxDialog 
{
	private:
	
	protected:
		wxListCtrl* m_FieldsList;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Modify;
		wxBitmapButton* m_bpButton_Del;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MailingListDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Indirizzi eMail per le Comunicazioni"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 606,406 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MailingListDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MailAddressDlg
///////////////////////////////////////////////////////////////////////////////
class MailAddressDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_NOME = 1000,
			ID_EMAIL
		};
		
		wxStaticText* m_staticText31;
		wxTextCtrl* m_Nome;
		wxStaticText* m_staticText311;
		wxTextCtrl* m_eMail;
		wxStaticText* m_staticText32;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MailAddressDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Indirizzo eMail"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 506,229 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MailAddressDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PresenceDlg
///////////////////////////////////////////////////////////////////////////////
class PresenceDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_GRUPPO = 1000,
			ID_COGNOME,
			ID_NOME,
			ID_DATA,
			ID_ORA_INGRESSO,
			ID_ORA_USCITA,
			ID_NOTE
		};
		
		wxStaticText* m_staticText37;
		wxChoice* m_Gruppo;
		wxStaticText* m_staticText31;
		wxComboBox* m_Cognome;
		wxStaticText* m_staticText311;
		wxComboBox* m_Nome;
		wxStaticText* m_staticText221111;
		wxDatePickerCtrl* m_Data;
		wxStaticText* m_staticText221112;
		wxTextCtrl* m_OraIngresso;
		wxStaticText* m_staticText58;
		wxTextCtrl* m_OraUscita;
		wxStaticText* m_staticText581;
		wxTextCtrl* m_Note;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnWrite( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PresenceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Registrazione Presenze"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 406,426 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PresenceDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ShiftDlg
///////////////////////////////////////////////////////////////////////////////
class ShiftDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_GRUPPO = 1000,
			ID_DATA,
			ID_COGNOME,
			ID_NOME,
			ID_QUALIFICA,
			ID_QUALIFICA_STATO,
			ID_TIPO_SERVIZIO,
			ID_MEZZO,
			ID_ORA_INIZIO,
			ID_ORA_FINE
		};
		
		wxStaticText* m_staticText37;
		wxChoice* m_Gruppo;
		wxStaticText* m_staticText221111;
		wxDatePickerCtrl* m_Data;
		wxStaticText* m_staticText31;
		wxComboBox* m_Cognome;
		wxStaticText* m_staticText311;
		wxComboBox* m_Nome;
		wxStaticText* m_staticText32;
		wxChoice* m_Qualifica;
		wxChoice* m_QualificaStato;
		wxStaticText* m_staticText51;
		wxChoice* m_TipoServizio;
		wxStaticText* m_staticText5111;
		wxChoice* m_Mezzo;
		wxStaticText* m_staticText221112;
		wxTextCtrl* m_OraInizio;
		wxStaticText* m_staticText58;
		wxTextCtrl* m_OraFine;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnWrite( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ShiftDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Registrazione Turni"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 406,426 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ShiftDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ServiceRegistryDlg
///////////////////////////////////////////////////////////////////////////////
class ServiceRegistryDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_NUM_SCHEDA = 1000,
			ID_NUM_SCHEDA_SUP,
			ID_GRUPPO,
			ID_COD_AMBULANZA,
			ID_COD_AMBULANZA_118,
			ID_TARGA_AMBULANZA,
			ID_DATA,
			ID_ORA_INIZIO,
			ID_ORA_FINE,
			ID_RICHIESTO_118,
			ID_RICHIESTO_ASL,
			ID_RICHIESTO_OSPEDALI,
			ID_RICHIESTO_PARENTI,
			ID_RICHIESTO_ALTRI,
			ID_SERVIZIO_INTERNO,
			ID_SCHEDA_118,
			ID_ALTRA_TIPOLOGIA,
			ID_LUOGOINTERVENTO,
			ID_LUOGOINTERVENTO_CAP,
			ID_LUOGOINTERVENTO_CITTA,
			ID_LUOGOINTERVENTO_PROVINCIA,
			ID_ALTRO_MEZZO,
			ID_RICHIESTO_NOMINATIVO,
			ID_RICHIESTO_CF_PIVA,
			ID_RICHIESTO_INDIRIZZO,
			ID_RICHIESTO_CIVICO,
			ID_RICHIESTO_CAP,
			ID_RICHIESTO_CITTA,
			ID_RICHIESTO_PROVINCIA,
			ID_DATI_PAGAMENTO,
			ID_IMPORTO,
			ID_ORA_PARTENZA,
			ID_ORA_ARRIVO_TARGET,
			ID_ORA_PARTENZA_TARGET,
			ID_ORA_ARRIVO,
			ID_KM_PERCORSI,
			ID_ORE_FERMO_MACCHINA,
			ID_NOTE,
			ID_CENTRALINO
		};
		
		wxStaticText* m_staticText56;
		wxTextCtrl* m_NumeroScheda;
		wxStaticText* m_staticText68;
		wxTextCtrl* m_NumeroSchedaSup;
		wxStaticText* m_staticText62;
		wxTextCtrl* m_Gruppo;
		wxStaticText* m_staticText621;
		wxTextCtrl* m_CodAmbulanza;
		wxStaticText* m_staticText69;
		wxTextCtrl* m_CodAmbulanza118;
		wxStaticText* m_staticText92;
		wxTextCtrl* m_TargaAmbulanza;
		wxStaticText* m_staticText57;
		wxDatePickerCtrl* m_Data;
		wxStaticText* m_staticText160;
		wxTextCtrl* m_OraInizio;
		wxStaticText* m_staticText16021;
		wxTextCtrl* m_OraFine;
		wxNotebook* m_notebook;
		wxPanel* m_panel1;
		wxRadioButton* m_Richiesto_118;
		wxRadioButton* m_Richiesto_Asl;
		wxRadioButton* m_Richiesto_Ospedali;
		wxRadioButton* m_Richiesto_Parenti;
		wxRadioButton* m_Richiesto_Altri;
		wxRadioButton* m_Servizio_Interno;
		wxStaticText* m_NumScheda118_Label;
		wxTextCtrl* m_NumScheda118;
		wxStaticText* m_Tipo_Label;
		wxChoice* m_Tipo;
		wxTextCtrl* m_AltraTipologia;
		wxTextCtrl* m_LuogoIntervento;
		wxStaticText* m_staticText102;
		wxTextCtrl* m_LuogoIntervento_CAP;
		wxStaticText* m_staticText103;
		wxTextCtrl* m_LuogoIntervento_Citta;
		wxStaticText* m_staticText104;
		wxTextCtrl* m_LuogoIntervento_Provincia;
		wxCheckBox* m_Carabinieri_Checked;
		wxCheckBox* m_Polizia_Checked;
		wxCheckBox* m_Polizia_Municipale_Checked;
		wxCheckBox* m_Vigili_del_Fuoco_Checked;
		wxCheckBox* m_Guardia_Medica_Checked;
		wxCheckBox* m_Altro_Mezzo_Checked;
		wxTextCtrl* m_Altro_Mezzo;
		wxPanel* m_panel2;
		wxStaticText* m_Richiesto_Nominativo_Label;
		wxTextCtrl* m_Richiesto_Nominativo;
		wxStaticText* m_Richiesto_CF_PIVA_Label;
		wxTextCtrl* m_Richiesto_CF_PIVA;
		wxStaticText* m_Richiesto_Indirizzo_Label;
		wxTextCtrl* m_Richiesto_Indirizzo;
		wxStaticText* m_Richiesto_Civico_Label;
		wxTextCtrl* m_Richiesto_Civico;
		wxStaticText* m_Richiesto_CAP_Label;
		wxTextCtrl* m_Richiesto_CAP;
		wxStaticText* m_Richiesto_Citta_Label;
		wxTextCtrl* m_Richiesto_Citta;
		wxStaticText* m_Richiesto_Provincia_Label;
		wxTextCtrl* m_Richiesto_Provincia;
		wxStaticText* m_Dati_Pagamento_Label;
		wxChoice* m_Dati_Pagamento;
		wxStaticText* m_Importo_Label;
		wxTextCtrl* m_Importo;
		wxStaticText* m_staticText1601;
		wxTextCtrl* m_OraPartenza;
		wxStaticText* m_staticText1602;
		wxTextCtrl* m_OraArrivoTarget;
		wxStaticText* m_staticText1603;
		wxTextCtrl* m_OraPartenzaTarget;
		wxStaticText* m_staticText16011;
		wxTextCtrl* m_OraArrivo;
		wxStaticText* m_staticText101;
		wxTextCtrl* m_KmPercorsi;
		wxStaticText* m_staticText106;
		wxTextCtrl* m_Ore_Fermo_Macchina;
		wxStaticText* m_staticText107;
		wxPanel* m_panel3;
		wxListCtrl* m_Pazienti;
		wxBitmapButton* m_bpButton_Add_Patient;
		wxBitmapButton* m_bpButton_Modify_Patient;
		wxBitmapButton* m_bpButton_Del_Patient;
		wxScrolledWindow* m_scrolledWindow1;
		wxStaticText* m_staticText1112;
		wxTextCtrl* m_CodFiscale;
		wxStaticText* m_staticText152;
		wxTextCtrl* m_NumTeam;
		wxStaticText* m_staticText111;
		wxTextCtrl* m_Indirizzo;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_Civico;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_CAP;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_Citta;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_Provincia;
		wxStaticText* m_staticText1111;
		wxTextCtrl* m_Stato;
		wxStaticText* m_staticText151;
		wxTextCtrl* m_Cittadinanza;
		wxStaticText* m_staticText21;
		wxStaticText* m_staticText211;
		wxTextCtrl* m_MotivoDelTrasporto;
		wxStaticText* m_staticText1042;
		wxTextCtrl* m_Trasportato;
		wxStaticText* m_staticText1021;
		wxTextCtrl* m_Trasportato_CAP;
		wxStaticText* m_staticText1031;
		wxTextCtrl* m_Trasportato_Citta;
		wxStaticText* m_staticText1041;
		wxTextCtrl* m_Trasportato_Provincia;
		wxStaticText* m_staticText19;
		wxTextCtrl* m_CodEvento_Gravita;
		wxTextCtrl* m_CodEvento_Patologia;
		wxTextCtrl* m_CodEvento_Luogo;
		wxStaticText* m_staticText20;
		wxTextCtrl* m_CodArrivo_Gravita;
		wxTextCtrl* m_CodArrivo_Patologia;
		wxTextCtrl* m_CodArrivo_Luogo;
		wxStaticText* m_staticText191;
		wxTextCtrl* m_CodPartenza_Gravita;
		wxTextCtrl* m_CodPartenza_Patologia;
		wxTextCtrl* m_CodPartenza_Luogo;
		wxStaticText* m_staticText201;
		wxTextCtrl* m_CodPartenza_Patologia2;
		wxStaticText* m_staticText2011;
		wxTextCtrl* m_CodRilascio_Gravita;
		wxTextCtrl* m_CodRilascio_Patologia;
		wxTextCtrl* m_CodRilascio_Luogo;
		wxStaticText* m_staticText167111;
		wxTextCtrl* m_PatologiaSpecifica;
		wxStaticText* m_staticText167;
		wxTextCtrl* m_Prestazione;
		wxStaticText* m_staticText174;
		wxTextCtrl* m_Prestazione2;
		wxTextCtrl* m_Prestazione3;
		wxTextCtrl* m_Prestazione4;
		wxTextCtrl* m_Prestazione5;
		wxStaticText* m_staticText1671;
		wxTextCtrl* m_DinamicaRiscontrata;
		wxTextCtrl* m_DinamicaRiscontrata2;
		wxStaticText* m_staticText16711;
		wxTextCtrl* m_Triage;
		wxCheckBox* m_FirmaSC_CRI;
		wxCheckBox* m_FirmaSC_118;
		wxPanel* m_panel4;
		wxListCtrl* m_Equipaggio;
		wxBitmapButton* m_bpButton_Add_Crew;
		wxBitmapButton* m_bpButton_Modify_Crew;
		wxBitmapButton* m_bpButton_Del_Crew;
		wxPanel* m_panel5;
		wxTextCtrl* m_Note;
		wxStaticText* m_staticText93;
		wxTextCtrl* m_Centralino;
		wxCheckBox* m_Chiuso;
		wxCheckBox* m_Annullato;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPatientSelected( wxListEvent& event ) { event.Skip(); }
		virtual void OnAddPatient( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyPatient( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelPatient( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddCrew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyCrew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelCrew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ServiceRegistryDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Servizi Registrati"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1006,748 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ServiceRegistryDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddCrewDlg
///////////////////////////////////////////////////////////////////////////////
class AddCrewDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_GRUPPO = 1000,
			ID_DATA,
			ID_ORA_INIZIO,
			ID_ORA_FINE,
			ID_MEZZO,
			ID_TIPO_SERVIZIO
		};
		
		wxStaticText* m_staticText37;
		wxChoice* m_Gruppo;
		wxStaticText* m_staticText221111;
		wxDatePickerCtrl* m_Data;
		wxStaticText* m_staticText221112;
		wxTextCtrl* m_OraInizio;
		wxStaticText* m_staticText58;
		wxTextCtrl* m_OraFine;
		wxStaticText* m_staticText5111;
		wxChoice* m_Mezzo;
		wxStaticText* m_staticText51111;
		wxChoice* m_TipoServizio;
		wxListCtrl* m_Equipaggio;
		wxBitmapButton* m_bpButton_Add_Crew;
		wxBitmapButton* m_bpButton_Modify_Crew;
		wxBitmapButton* m_bpButton_Del_Crew;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddCrew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyCrew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelCrew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AddCrewDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Inserisci Equipaggio"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 646,486 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddCrewDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CrewDlg
///////////////////////////////////////////////////////////////////////////////
class CrewDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_COGNOME = 1000,
			ID_NOME,
			ID_QUALIFICA,
			ID_QUALIFICA_STATO
		};
		
		wxStaticText* m_staticText31;
		wxComboBox* m_Cognome;
		wxStaticText* m_staticText311;
		wxComboBox* m_Nome;
		wxStaticText* m_staticText32;
		wxChoice* m_Qualifica;
		wxChoice* m_QualificaStato;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnWrite( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CrewDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("V.d.S."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 486,196 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CrewDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PatientDlg
///////////////////////////////////////////////////////////////////////////////
class PatientDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_COGNOME = 1000,
			ID_NOME,
			ID_CODICE_FISCALE,
			ID_NUMERO_TEAM,
			ID_DATA_NASCITA,
			ID_ETA,
			ID_SESSO,
			ID_INDIRIZZO,
			ID_CIVICO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA,
			ID_STATO,
			ID_CITTADINANZA,
			ID_MOTIVOTRASPORTO,
			ID_TRASPORTATO,
			ID_TRASPORTATO_CAP,
			ID_TRASPORTATO_CITTA,
			ID_TRASPORTATO_PROVINCIA,
			ID_COD_EVENTO_G,
			ID_COD_EVENTO_P,
			ID_COD_EVENTO_L,
			ID_COD_ARRIVO_G,
			ID_COD_ARRIVO_P,
			ID_COD_ARRIVO_L,
			ID_COD_PARTENZA_G,
			ID_COD_PARTENZA_P,
			ID_COD_PARTENZA_L,
			ID_COD_PARTENZA_P2,
			ID_COD_RILASCIO_G,
			ID_COD_RILASCIO_P,
			ID_COD_RILASCIO_L,
			ID_PATOLOGIA_SPECIFICA,
			ID_PRESTAZIONE1,
			ID_PRESTAZIONE2,
			ID_PRESTAZIONE3,
			ID_PRESTAZIONE4,
			ID_PRESTAZIONE5,
			ID_DINAMICA1,
			ID_DINAMICA2,
			ID_TRIAGE
		};
		
		wxStaticText* m_staticText4;
		wxTextCtrl* m_Cognome;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_Nome;
		wxStaticText* m_staticText138;
		wxTextCtrl* m_CodFiscale;
		wxStaticText* m_staticText155;
		wxTextCtrl* m_Numero_Team;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_DataNascita;
		wxStaticText* m_staticText135;
		wxTextCtrl* m_Eta;
		wxRadioButton* m_Anni;
		wxRadioButton* m_Mesi;
		wxRadioButton* m_Giorni;
		wxStaticText* m_staticText41;
		wxChoice* m_Sesso;
		wxStaticText* m_staticText110;
		wxTextCtrl* m_Indirizzo;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_Civico;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_CAP;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_Citta;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_Provincia;
		wxStaticText* m_staticText136;
		wxChoice* m_Stato;
		wxStaticText* m_staticText137;
		wxTextCtrl* m_Cittadinanza;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_MotivoDelTrasporto;
		wxStaticText* m_staticText143;
		wxTextCtrl* m_Trasportato;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_Trasportato_CAP;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_Trasportato_Citta;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_Trasportato_Provincia;
		wxStaticText* m_staticText19;
		TxtCtrl118Code* m_CodEvento_Gravita;
		TxtCtrl118Code* m_CodEvento_Patologia;
		TxtCtrl118Code* m_CodEvento_Luogo;
		wxStaticText* m_staticText20;
		TxtCtrl118Code* m_CodArrivo_Gravita;
		TxtCtrl118Code* m_CodArrivo_Patologia;
		TxtCtrl118Code* m_CodArrivo_Luogo;
		wxStaticText* m_staticText191;
		TxtCtrl118Code* m_CodPartenza_Gravita;
		TxtCtrl118Code* m_CodPartenza_Patologia;
		TxtCtrl118Code* m_CodPartenza_Luogo;
		wxStaticText* m_staticText201;
		TxtCtrl118Code* m_CodPartenza_Patologia2;
		wxStaticText* m_staticText2011;
		TxtCtrl118Code* m_CodRilascio_Gravita;
		TxtCtrl118Code* m_CodRilascio_Patologia;
		TxtCtrl118Code* m_CodRilascio_Luogo;
		wxStaticText* m_staticText167111;
		wxTextCtrl* m_PatologiaSpecifica;
		wxStaticText* m_staticText167;
		TxtCtrl118Code* m_Prestazione;
		wxStaticText* m_staticText174;
		TxtCtrl118Code* m_Prestazione2;
		TxtCtrl118Code* m_Prestazione3;
		TxtCtrl118Code* m_Prestazione4;
		TxtCtrl118Code* m_Prestazione5;
		wxStaticText* m_staticText1671;
		TxtCtrl118Code* m_DinamicaRiscontrata;
		TxtCtrl118Code* m_DinamicaRiscontrata2;
		wxStaticText* m_staticText16711;
		wxTextCtrl* m_Triage;
		wxCheckBox* m_FirmaSC_CRI;
		wxCheckBox* m_FirmaSC_118;
		wxStaticLine* m_staticline12;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PatientDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Paziente"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 906,706 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PatientDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddPatient118Dlg
///////////////////////////////////////////////////////////////////////////////
class AddPatient118Dlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_COGNOME = 1000,
			ID_NOME,
			ID_CODICE_FISCALE,
			ID_NUMERO_TEAM,
			ID_DATA_NASCITA,
			ID_ETA,
			ID_SESSO,
			ID_INDIRIZZO,
			ID_CIVICO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA,
			ID_STATO,
			ID_CITTADINANZA,
			ID_MOTIVOTRASPORTO,
			ID_COD_EVENTO_G,
			ID_COD_EVENTO_P,
			ID_COD_EVENTO_L,
			ID_COD_ARRIVO_G,
			ID_COD_ARRIVO_P,
			ID_COD_ARRIVO_L,
			ID_COD_PARTENZA_G,
			ID_COD_PARTENZA_P,
			ID_COD_PARTENZA_L,
			ID_COD_PARTENZA_P2,
			ID_COD_RILASCIO_G,
			ID_COD_RILASCIO_P,
			ID_COD_RILASCIO_L,
			ID_PATOLOGIA_SPECIFICA,
			ID_PRESTAZIONE1,
			ID_PRESTAZIONE2,
			ID_PRESTAZIONE3,
			ID_PRESTAZIONE4,
			ID_PRESTAZIONE5,
			ID_DINAMICA1,
			ID_DINAMICA2,
			ID_TRIAGE,
			ID_RICOVERATO,
			ID_RIFIUTA_TRASPORTO,
			ID_TRASPORTATO_ALTRO_MEZZO,
			ID_ALTRA_AMBULANZA,
			ID_DECEDUTO
		};
		
		wxStaticText* m_staticText4;
		wxTextCtrl* m_Cognome;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_Nome;
		wxStaticText* m_staticText138;
		wxTextCtrl* m_CodFiscale;
		wxStaticText* m_staticText154;
		wxTextCtrl* m_Numero_Team;
		wxStaticText* m_staticText141;
		wxTextCtrl* m_DataNascita;
		wxStaticText* m_staticText1351;
		wxTextCtrl* m_Eta;
		wxRadioButton* m_Anni;
		wxRadioButton* m_Mesi;
		wxRadioButton* m_Giorni;
		wxStaticText* m_staticText411;
		wxChoice* m_Sesso;
		wxStaticText* m_staticText110;
		wxTextCtrl* m_Indirizzo;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_Civico;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_CAP;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_Citta;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_Provincia;
		wxStaticText* m_staticText136;
		wxChoice* m_Stato;
		wxStaticText* m_staticText137;
		wxTextCtrl* m_Cittadinanza;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_MotivoDelTrasporto;
		wxNotebook* m_notebook;
		wxPanel* m_panel1;
		wxStaticText* m_staticText19;
		TxtCtrl118Code* m_CodEvento_Gravita;
		TxtCtrl118Code* m_CodEvento_Patologia;
		TxtCtrl118Code* m_CodEvento_Luogo;
		wxStaticText* m_staticText20;
		TxtCtrl118Code* m_CodArrivo_Gravita;
		TxtCtrl118Code* m_CodArrivo_Patologia;
		TxtCtrl118Code* m_CodArrivo_Luogo;
		wxStaticText* m_staticText191;
		TxtCtrl118Code* m_CodPartenza_Gravita;
		TxtCtrl118Code* m_CodPartenza_Patologia;
		TxtCtrl118Code* m_CodPartenza_Luogo;
		wxStaticText* m_staticText201;
		TxtCtrl118Code* m_CodPartenza_Patologia2;
		wxStaticText* m_staticText2011;
		TxtCtrl118Code* m_CodRilascio_Gravita;
		TxtCtrl118Code* m_CodRilascio_Patologia;
		TxtCtrl118Code* m_CodRilascio_Luogo;
		wxStaticText* m_staticText167111;
		wxTextCtrl* m_PatologiaSpecifica;
		wxStaticText* m_staticText167;
		TxtCtrl118Code* m_Prestazione;
		wxStaticText* m_staticText174;
		TxtCtrl118Code* m_Prestazione2;
		TxtCtrl118Code* m_Prestazione3;
		TxtCtrl118Code* m_Prestazione4;
		TxtCtrl118Code* m_Prestazione5;
		wxStaticText* m_staticText1671;
		TxtCtrl118Code* m_DinamicaRiscontrata;
		TxtCtrl118Code* m_DinamicaRiscontrata2;
		wxStaticText* m_staticText16711;
		wxTextCtrl* m_Triage;
		wxPanel* m_panel2;
		wxCheckBox* m_Trasportato;
		wxChoice* m_Ospedale;
		wxCheckBox* m_RifiutaTrasporto;
		wxChoice* m_RifiutaTrasportoMotivo;
		wxStaticText* m_FirmaSC_Label;
		wxCheckBox* m_FirmaSC_118;
		wxCheckBox* m_FirmaSC_CRI;
		wxCheckBox* m_TrasportatoDaAltraAbulanza;
		wxTextCtrl* m_AltraAmbulanza;
		wxCheckBox* m_Deceduto;
		wxStaticLine* m_staticline12;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AddPatient118Dlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Paziente"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 906,706 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddPatient118Dlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddPatientDlg
///////////////////////////////////////////////////////////////////////////////
class AddPatientDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_COGNOME = 1000,
			ID_NOME,
			ID_CODICE_FISCALE,
			ID_DATA_NASCITA,
			ID_ETA,
			ID_SESSO,
			ID_INDIRIZZO,
			ID_CIVICO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA,
			ID_STATO,
			ID_CITTADINANZA,
			ID_MOTIVOTRASPORTO,
			ID_ABITAZIONE_CHECKED,
			ID_OSPEDALE_CHECKED,
			ID_ALTRO_LUOGO_CHECKED,
			ID_TRASPORTATO_LUOGO,
			ID_TRASPORTATO_CAP,
			ID_TRASPORTATO_CITTA,
			ID_TRASPORTATO_PROVINCIA
		};
		
		wxStaticText* m_staticText4;
		wxTextCtrl* m_Cognome;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_Nome;
		wxStaticText* m_staticText138;
		wxTextCtrl* m_CodFiscale;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_DataNascita;
		wxStaticText* m_staticText135;
		wxTextCtrl* m_Eta;
		wxRadioButton* m_Anni;
		wxRadioButton* m_Mesi;
		wxRadioButton* m_Giorni;
		wxStaticText* m_staticText41;
		wxChoice* m_Sesso;
		wxStaticText* m_staticText110;
		wxTextCtrl* m_Indirizzo;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_Civico;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_CAP;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_Citta;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_Provincia;
		wxStaticText* m_staticText136;
		wxChoice* m_Stato;
		wxStaticText* m_staticText137;
		wxTextCtrl* m_Cittadinanza;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_MotivoDelTrasporto;
		wxCheckBox* m_Abitazione_Checked;
		wxCheckBox* m_Ospedale_Checked;
		wxChoice* m_Ospedale;
		wxCheckBox* m_Altro_Luogo_Checked;
		wxTextCtrl* m_Trasportato_Luogo;
		wxStaticText* m_Trasportato_CAP_Label;
		wxTextCtrl* m_Trasportato_CAP;
		wxStaticText* m_Trasportato_Citta_Label;
		wxTextCtrl* m_Trasportato_Citta;
		wxStaticText* m_Trasportato_Provincia_Label;
		wxTextCtrl* m_Trasportato_Provincia;
		wxStaticLine* m_staticline12;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AddPatientDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Paziente"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 906,706 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddPatientDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SelectDateRangeDlg
///////////////////////////////////////////////////////////////////////////////
class SelectDateRangeDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_Text;
		wxStaticText* m_staticText51;
		wxDatePickerCtrl* m_date_Start;
		wxStaticText* m_staticText52;
		wxDatePickerCtrl* m_date_End;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SelectDateRangeDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Selezionare l'intervallo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 406,186 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SelectDateRangeDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SearchDlg
///////////////////////////////////////////////////////////////////////////////
class SearchDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_VALUE = 1000
		};
		
		wxStaticText* m_staticText51;
		wxDatePickerCtrl* m_date_Start;
		wxStaticText* m_staticText52;
		wxDatePickerCtrl* m_date_End;
		wxChoice* m_Field;
		wxTextCtrl* m_Value;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SearchDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Ricerca Servizi"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 406,196 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SearchDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class OptionsDlg
///////////////////////////////////////////////////////////////////////////////
class OptionsDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText139;
		wxChoice* m_Gruppo;
		wxStaticText* m_staticText141;
		wxCheckBox* m_IncNumServizi;
		wxStaticText* m_staticText1411;
		wxCheckBox* m_IncNumServiziSup;
		wxStaticText* m_staticText156;
		wxTextCtrl* m_AutoLogOutTime;
		wxStaticText* m_staticText157;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		OptionsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Opzioni Programma"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 496,256 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~OptionsDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ProgressDlg
///////////////////////////////////////////////////////////////////////////////
class ProgressDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_Text;
		wxGauge* m_gauge;
	
	public:
		
		ProgressDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 406,89 ), long style = wxSTAY_ON_TOP ); 
		~ProgressDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ComunicationDlg
///////////////////////////////////////////////////////////////////////////////
class ComunicationDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_COMUNICAZIONE_TO = 1000,
			ID_OGGETTO,
			ID_COMUNICAZIONE
		};
		
		wxStaticText* m_staticText312;
		wxChoice* m_Gruppo;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_ComunicazioneDa;
		wxStaticText* m_staticText311;
		wxChoice* m_ComunicazioneTo;
		wxStaticText* m_staticText313;
		wxTextCtrl* m_Oggetto;
		wxStaticText* m_staticText581;
		wxTextCtrl* m_Note;
		wxCheckBox* m_Letta;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ComunicationDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Comunicazioni di Servizio"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 426,506 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ComunicationDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SelectUserDisponibilityDlg
///////////////////////////////////////////////////////////////////////////////
class SelectUserDisponibilityDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_NAME = 1000
		};
		
		wxStaticText* m_staticText212;
		wxTextCtrl* m_Name;
		wxStaticText* m_staticText2223;
		wxChoice* m_Group;
		wxStaticText* m_staticText51;
		wxCheckBox* m_checkBox_Date;
		wxDatePickerCtrl* m_Date;
		wxStaticText* m_staticText2221;
		wxChoice* m_Qualification;
		wxStaticText* m_staticText222;
		wxChoice* m_Qualification_Type;
		wxStaticText* m_staticText2222;
		wxChoice* m_Qualification_Status;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Find;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnCheckDate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SelectUserDisponibilityDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Ricerca Volontari"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 406,310 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SelectUserDisponibilityDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class HtmlFrame
///////////////////////////////////////////////////////////////////////////////
class HtmlFrame : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* m_statusBar;
		wxHtmlWindow* m_html;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnIconize( wxIconizeEvent& event ) { event.Skip(); }
		
	
	public:
		
		HtmlFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxFRAME_FLOAT_ON_PARENT|wxSTAY_ON_TOP|wxTAB_TRAVERSAL );
		
		~HtmlFrame();
	
};

#endif //__CRIREGISTRYGUIS_H__
