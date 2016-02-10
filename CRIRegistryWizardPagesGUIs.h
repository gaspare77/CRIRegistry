///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CRIREGISTRYWIZARDPAGESGUIS_H__
#define __CRIREGISTRYWIZARDPAGESGUIS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class MyWizardPage;
class TxtCtrl118Code;

#include "MyWizardPage.h"
#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/calctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Gruppo
///////////////////////////////////////////////////////////////////////////////
class Gruppo : public MyWizardPage
{
	private:
	
	protected:
		wxChoice* m_Gruppo;
	
	public:
		
		Gruppo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~Gruppo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Data
///////////////////////////////////////////////////////////////////////////////
class Data : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_ORA_INIZIO = 1000,
			ID_ORA_PARTENZA,
			ID_ORA_ARRIVO_TARGET,
			ID_ORA_PARTENZA_TARGET,
			ID_ORA_ARRIVO,
			ID_ORA_FINE
		};
		
		wxCalendarCtrl* m_Data;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_OraInizio;
		wxStaticText* m_staticText221;
		wxTextCtrl* m_OraPartenza;
		wxStaticText* m_staticText2211;
		wxTextCtrl* m_OraArrivoTarget;
		wxStaticText* m_staticText2212;
		wxTextCtrl* m_OraPartenzaTarget;
		wxStaticText* m_staticText2213;
		wxTextCtrl* m_OraArrivo;
		wxStaticText* m_staticText22141;
		wxTextCtrl* m_OraFine;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		Data( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~Data();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Equipaggio
///////////////////////////////////////////////////////////////////////////////
class Equipaggio : public MyWizardPage
{
	private:
	
	protected:
		wxChoice* m_Mezzo;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_Targa;
		wxStaticText* m_staticText311;
		wxTextCtrl* m_Tipo;
		wxListCtrl* m_Equipaggio;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Modify;
		wxBitmapButton* m_bpButton_Del;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Equipaggio( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~Equipaggio();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Richiesto
///////////////////////////////////////////////////////////////////////////////
class Richiesto : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_118 = 1000,
			ID_PARENTI,
			ID_OSPEDALI,
			ID_ALTRI,
			ID_SERVIZIO_INTERNO,
			ID_TIPO,
			ID_ALTRA_TIPOLOGIA
		};
		
		wxRadioButton* m_radio_118;
		wxRadioButton* m_radio_Parenti;
		wxRadioButton* m_radio_Ospedali;
		wxChoice* m_Ospedale;
		wxRadioButton* m_radio_Altri;
		wxRadioButton* m_radio_ServizioInterno;
		wxChoice* m_Tipo;
		wxTextCtrl* m_AltraTipologia;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		Richiesto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~Richiesto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Paziente
///////////////////////////////////////////////////////////////////////////////
class Paziente : public MyWizardPage
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
			ID_IMPORTO
		};
		
		wxStaticText* m_staticText4;
		wxTextCtrl* m_Cognome;
		wxStaticText* m_staticText46;
		wxTextCtrl* m_Nome;
		wxStaticText* m_staticText45;
		wxTextCtrl* m_CodFiscale;
		wxStaticText* m_staticText44;
		wxTextCtrl* m_DataNascita;
		wxStaticText* m_staticText47;
		wxTextCtrl* m_Eta;
		wxRadioButton* m_Anni;
		wxRadioButton* m_Mesi;
		wxRadioButton* m_Giorni;
		wxStaticText* m_staticText43;
		wxChoice* m_Sesso;
		wxStaticText* m_staticText41;
		wxTextCtrl* m_Indirizzo;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_Civico;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_CAP;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_Citta;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_Provincia;
		wxStaticText* m_staticText161;
		wxChoice* m_Stato;
		wxStaticText* m_staticText171;
		wxTextCtrl* m_Cittadinanza;
		wxStaticText* m_staticText451;
		wxTextCtrl* m_MotivoTrasporto;
		wxStaticText* m_staticText78;
		wxChoice* m_TipologiaPagamento;
		wxStaticText* m_staticText79;
		wxTextCtrl* m_Importo;
		wxStaticText* m_staticText80;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		Paziente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~Paziente();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Richiedente
///////////////////////////////////////////////////////////////////////////////
class Richiedente : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_NOMINATIVO = 1000,
			ID_CF_PIVA,
			ID_INDIRIZZO,
			ID_CIVICO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA,
			ID_IMPORTO
		};
		
		wxStaticText* m_staticText4;
		wxTextCtrl* m_Nominativo;
		wxStaticText* m_staticText45;
		wxTextCtrl* m_CodFiscale_Piva;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_Indirizzo;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_Civico;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_CAP;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_Citta;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_Provincia;
		wxStaticText* m_staticText78;
		wxChoice* m_TipologiaPagamento;
		wxStaticText* m_staticText79;
		wxTextCtrl* m_Importo;
		wxStaticText* m_staticText80;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		Richiedente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~Richiedente();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LuogoIntervento
///////////////////////////////////////////////////////////////////////////////
class LuogoIntervento : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_ABITAZIONE_CHECKED = 1000,
			ID_OSPEDALE_CHECKED,
			ID_ALTRO_LUOGO_CHECKED,
			ID_LUOGO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA
		};
		
		wxCheckBox* m_Abitazione_Checked;
		wxCheckBox* m_Ospedale_Checked;
		wxChoice* m_Ospedale;
		wxCheckBox* m_AltroLuogo_Checked;
		wxTextCtrl* m_Luogo;
		wxStaticText* m_CAP_Label;
		wxTextCtrl* m_CAP;
		wxStaticText* m_Citta_Label;
		wxTextCtrl* m_Citta;
		wxStaticText* m_Provincia_Label;
		wxTextCtrl* m_Provincia;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		LuogoIntervento( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~LuogoIntervento();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LuogoIntervento118
///////////////////////////////////////////////////////////////////////////////
class LuogoIntervento118 : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_ALTRO_LUOGO_CHECKED = 1000,
			ID_LUOGO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA,
			ID_OSPEDALE_CHECKED,
			ID_ALTRO_MEZZO_CHECKED,
			ID_ALTRO_MEZZO_CODICE
		};
		
		wxCheckBox* m_AltroLuogo_Checked;
		wxTextCtrl* m_Luogo;
		wxStaticText* m_CAP_Label;
		wxTextCtrl* m_CAP;
		wxStaticText* m_Citta_Label;
		wxTextCtrl* m_Citta;
		wxStaticText* m_Provincia_Label;
		wxTextCtrl* m_Provincia;
		wxCheckBox* m_Ospedale_Checked;
		wxChoice* m_Ospedale;
		wxCheckBox* m_Carabinieri_Checked;
		wxCheckBox* m_Polizia_Checked;
		wxCheckBox* m_Polizia_Municipale_Checked;
		wxCheckBox* m_Vigili_del_Fuoco_Checked;
		wxCheckBox* m_Guardia_Medica_Checked;
		wxCheckBox* m_Altro_Mezzo_Checked;
		wxTextCtrl* m_AltroMezzo_Codice;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		LuogoIntervento118( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~LuogoIntervento118();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class InfoServizio118
///////////////////////////////////////////////////////////////////////////////
class InfoServizio118 : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_COD_RADIO_118 = 1000,
			ID_SCHEDA_118,
			ID_COD_GRAVITA,
			ID_COD_PATOLOGIA,
			ID_COD_LUOGO,
			ID_NOMINATIVO_PAZIENTE,
			ID_AVARIA_MEZZO,
			ID_PAZIENTE_NONTROVATO,
			ID_PAZIENTE_GIATRASPORTATO,
			ID_GIA_TRASPORTATO_MEZZO,
			ID_SERVIZIO_NON_COMPLETATO,
			ID_NON_COMPLETATO,
			ID_SERVIZIO_ANNULLATO,
			ID_ANNULLATO_ORA,
			ID_ANNULLATO_LUOGO
		};
		
		wxStaticText* m_staticText3311;
		wxTextCtrl* m_CodRadio118;
		wxStaticText* m_NumScheda118;
		wxTextCtrl* m_Scheda118;
		wxStaticText* m_staticText331;
		TxtCtrl118Code* m_CodGravita;
		TxtCtrl118Code* m_CodPatologia;
		TxtCtrl118Code* m_CodLuogo;
		wxStaticText* m_staticText3312;
		wxTextCtrl* m_NominativoPaziente;
		wxCheckBox* m_AvariaMezzo;
		wxCheckBox* m_PazienteNonTrovato;
		wxCheckBox* m_PazienteGiaTrasportato;
		wxTextCtrl* m_GiaTrasportatoMezzo;
		wxCheckBox* m_ServizioNonCompletato;
		wxTextCtrl* m_NonCompletato;
		wxCheckBox* m_ServizioAnnullato;
		wxStaticText* m_label_AnnullatoOra;
		wxTextCtrl* m_AnnullatoOra;
		wxStaticText* m_label_AnnullatoLuogo;
		wxTextCtrl* m_AnnullatoLuogo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnCheck( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		InfoServizio118( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~InfoServizio118();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PazientiTrasportati
///////////////////////////////////////////////////////////////////////////////
class PazientiTrasportati : public MyWizardPage
{
	private:
	
	protected:
		wxListCtrl* m_Pazienti;
		wxBitmapButton* m_bpButton_Add;
		wxBitmapButton* m_bpButton_Modify;
		wxBitmapButton* m_bpButton_Del;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PazientiTrasportati( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~PazientiTrasportati();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LuogoTrasportato
///////////////////////////////////////////////////////////////////////////////
class LuogoTrasportato : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_ABITAZIONE_CHECKED = 1000,
			ID_OSPEDALE_CHECKED,
			ID_ALTRO_LUOGO_CHECKED,
			ID_LUOGO,
			ID_CAP,
			ID_CITTA,
			ID_PROVINCIA
		};
		
		wxCheckBox* m_Abitazione_Checked;
		wxCheckBox* m_Ospedale_Checked;
		wxChoice* m_Ospedale;
		wxCheckBox* m_AltroLuogo_Checked;
		wxTextCtrl* m_Luogo;
		wxStaticText* m_CAP_Label;
		wxTextCtrl* m_CAP;
		wxStaticText* m_Citta_Label;
		wxTextCtrl* m_Citta;
		wxStaticText* m_Provincia_Label;
		wxTextCtrl* m_Provincia;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		LuogoTrasportato( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~LuogoTrasportato();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class UtilizzoMezzo
///////////////////////////////////////////////////////////////////////////////
class UtilizzoMezzo : public MyWizardPage
{
	private:
	
	protected:
		enum
		{
			ID_KM_INIZIALI = 1000,
			ID_KM_FINALI,
			ID_KM_PERCORSI,
			ID_ORE_FERMO_MACCHINA
		};
		
		wxStaticText* m_staticText21;
		wxTextCtrl* m_KmIniziali;
		wxStaticText* m_staticText211;
		wxTextCtrl* m_KmFinali;
		wxStaticText* m_staticText2111;
		wxTextCtrl* m_KmPercorsi;
		wxStaticText* m_staticText21111;
		wxTextCtrl* m_OreFermoMacchina;
		wxStaticText* m_staticText28;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitCtrl( wxFocusEvent& event ) { event.Skip(); }
		
	
	public:
		
		UtilizzoMezzo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~UtilizzoMezzo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Fine
///////////////////////////////////////////////////////////////////////////////
class Fine : public MyWizardPage
{
	private:
	
	protected:
		wxTextCtrl* m_Note;
	
	public:
		
		Fine( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxTAB_TRAVERSAL ); 
		~Fine();
	
};

#endif //__CRIREGISTRYWIZARDPAGESGUIS_H__
