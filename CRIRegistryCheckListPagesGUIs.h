///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CRIREGISTRYCHECKLISTPAGESGUIS_H__
#define __CRIREGISTRYCHECKLISTPAGESGUIS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/checklst.h>
#include <wx/treectrl.h>
#include <wx/scrolwin.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class CheckListTimeIntervalDlg
///////////////////////////////////////////////////////////////////////////////
class CheckListTimeIntervalDlg : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_Orari;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Edit;
		wxBitmapButton* m_bpButton_Del;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CheckListTimeIntervalDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Intervallo Orari Check List"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 340,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CheckListTimeIntervalDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CheckListTimeDlg
///////////////////////////////////////////////////////////////////////////////
class CheckListTimeDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_TURNO = 1000,
			ID_INIZIO,
			ID_FINE
		};
		
		wxStaticText* m_staticText4;
		wxTextCtrl* m_Turno;
		wxStaticText* m_staticText41;
		wxTextCtrl* m_Inizio;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_Fine;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CheckListTimeDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Intervallo Orari Turno"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 357,213 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CheckListTimeDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CheckListAddItemDlg
///////////////////////////////////////////////////////////////////////////////
class CheckListAddItemDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_TESTO = 1000
		};
		
		wxStaticText* m_staticText10;
		wxTextCtrl* m_Testo;
		wxStaticText* m_staticText91;
		wxChoice* m_Posizione;
		wxBitmapButton* m_bpButton_EditPosition;
		wxStaticText* m_staticText13;
		wxCheckListBox* m_ListaOrari;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditPosition( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CheckListAddItemDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit voce inserita nella Check List"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 503,357 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CheckListAddItemDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CheckListEditDlg
///////////////////////////////////////////////////////////////////////////////
class CheckListEditDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_GRUPPO = 1000
		};
		
		wxStaticText* m_staticText14;
		wxChoice* m_Gruppo;
		wxTreeCtrl* m_Voci;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Edit;
		wxBitmapButton* m_bpButton_Del;
		wxBitmapButton* m_bpButton_EditHours;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnItemActivate( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditHours( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CheckListEditDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Modifica Check List"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,550 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CheckListEditDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CheckListDlg
///////////////////////////////////////////////////////////////////////////////
class CheckListDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText15;
		wxTextCtrl* m_Data;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_Turno;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_Gruppo;
		wxScrolledWindow* m_ScrolledWindow;
		wxBoxSizer* m_Container;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton_Ok;
		wxBitmapButton* m_bpButton_Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CheckListDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Check List"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~CheckListDlg();
	
};

#endif //__CRIREGISTRYCHECKLISTPAGESGUIS_H__
