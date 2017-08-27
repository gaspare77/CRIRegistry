#ifndef __CRIRegistryMainFrame__
#define __CRIRegistryMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/
#define WIN32_LEAN_AND_MEAN

#include "CRIRegistryGUIs.h"
#include "CRIRegistryFleetDlg.h"
#include "CRIRegistryHospitalDlg.h"
#include "CRIRegistryPresenceDlg.h"
#include "CRIRegistryAddCrewDlg.h"
#include "CRIRegistryShiftDlg.h"
#include "CRIRegistryServiceDlg.h"
#include "CRIRegistrySelectDateRangeDlg.h"
#include "CRIRegistrySelectUserDisponibilityDlg.h"
#include "CRIRegistryHtmlFrame.h"
#include "CRIRegistrySearchDlg.h"
#include "CRIRegistrySQLQueryDlg.h"
#include "CRIRegistryAddFieldsDlg.h"
#include "CRIRegistryWizardDlg.h"
#include "CRIRegistryComunicationDlg.h"
#include "CRIRegistryOptions.h"
#include "CRIRegistryConstant.h"
#include "CRIRegistryVersion.h"
#include "CRIRegistryProgressDlg.h"
#include "CRIRegistryMailingListDlg.h"
#include "dbClass/CPresence.h"
#include "dbClass/CService.h"
#include "dbClass/CShift.h"
#include "dbClass/CComunication.h"
#include "UsersManager.h"
#include "CRIRegistryCheckListDlg.h"
#include "CRIRegistryCheckListEditDlg.h"

#include <wx/aboutdlg.h>

/** Implementing MainFrame */
class CRIRegistryMainFrame : public MainFrame
{
protected:
	// Handlers for MainFrame events.
	void OnClose( wxCloseEvent& event );
	void OnSQLQuery( wxCommandEvent& event );
	void OnQuit( wxCommandEvent& event );
	void OnLogIn( wxCommandEvent& event );
	void OnLogOut( wxCommandEvent& event );
	void OnChangeUser( wxCommandEvent& event );
	void OnChangeUsersPwd( wxCommandEvent& event );
	void OnUsersManager( wxCommandEvent& event );
	void OnOpenGroup( wxCommandEvent& event );
	void OnOpenFleet( wxCommandEvent& event );
	void OnOpenHospital( wxCommandEvent& event );
	void OnOpenServiceType( wxCommandEvent& event );
	void OnOpen118ServiceType( wxCommandEvent& event );
	void OnOpenInternalServiceType( wxCommandEvent& event );
	void OnOpenShiftType( wxCommandEvent& event );
	void OnOpenVehicleType( wxCommandEvent& event );
    void OnOpenReasonsRefusingTransport( wxCommandEvent& event );
    void OnOpenMailingList( wxCommandEvent& event );
    void OnEditCheckList( wxCommandEvent& event );
    void OnOptions( wxCommandEvent& event );
    void OnAddCrew( wxCommandEvent& event );
	void OnAddShift( wxCommandEvent& event );
	void OnModifyShift( wxCommandEvent& event );
	void OnDelShift( wxCommandEvent& event );
	void OnViewCurrentShift( wxCommandEvent& event );
	void OnViewAllShift( wxCommandEvent& event );
	void OnAddService( wxCommandEvent& event );
	void OnModifyService( wxCommandEvent& event );
	void OnDelService( wxCommandEvent& event );
	void OnViewCurrentService( wxCommandEvent& event );
	void OnViewAllService( wxCommandEvent& event );
	void OnViewSearchedService( wxCommandEvent& event );
	void OnAbout( wxCommandEvent& event );
	void OnNotebookPageChanged( wxNotebookEvent& event );
	void OnPresencesListDbClick( wxMouseEvent& event );
	void OnSize( wxSizeEvent& event );
	void OnPresenceIn( wxCommandEvent& event );
	void OnPresenceOut( wxCommandEvent& event );
	void OnModifyPresence( wxCommandEvent& event );
	void OnDelPresence( wxCommandEvent& event );
	void OnViewCurrentPresence( wxCommandEvent& event );
	void OnViewAllPresence( wxCommandEvent& event );
	void OnShifsListDbClick( wxMouseEvent& event );
	void OnServicesListDbClick( wxMouseEvent& event );
	void OnSelectPresence( wxCommandEvent& event );
	void OnSelectShift( wxCommandEvent& event );
	void OnSelectService( wxCommandEvent& event );
	void OnTimer( wxTimerEvent& event );
	void OnKeyPressed( wxKeyEvent& event );
    void OnExportService( wxCommandEvent& event ); 
    void OnImportService( wxCommandEvent& event ); 
    void OnExportShift( wxCommandEvent& event ); 
    void OnImportShift( wxCommandEvent& event ); 
	void OnAddComunication( wxCommandEvent& event );
	void OnModifyComunication( wxCommandEvent& event );
	void OnDelComunication( wxCommandEvent& event );
	void OnViewCurrentComunication( wxCommandEvent& event );
	void OnViewAllComunication( wxCommandEvent& event );
	void OnComunicationListDbClick( wxMouseEvent& event );
	void OnSelectComunication( wxCommandEvent& event );
    void OnSelectFindUsers( wxCommandEvent& event );
    void OnShowCheckList( wxCommandEvent& event );

	DECLARE_EVENT_TABLE();
	enum
	{
		TIMER_ID = 1000,
	};

public:
	/** Constructor */
	CRIRegistryMainFrame( wxWindow* parent );

private:
    bool ShowCurrentPresence();
    bool ShowAllPresence();
    bool ShowCurrentShift();
    bool ShowAllShift();
    bool ShowCurrentService();
    bool ShowAllService();
	bool ShowSearchedService();
    bool ShowCurrentComunication();
    bool ShowAllComunication();
	long GetPresenceItemSelected();
	long GetShiftItemSelected();
	long GetServiceItemSelected();
	long GetComunicationItemSelected();
    int GetComunicationsToRead();
	std::vector<CPresence>::iterator GetPresenceSelected();
	std::vector<CService>::iterator GetServiceSelected();
	std::vector<CShift>::iterator GetShiftSelected();
	std::vector<CComunication>::iterator GetComunicationSelected();

    std::vector<CPresence>      m_vPresences;
    std::vector<CService>       m_vServices;
    std::vector<CShift>         m_vShifts;
    std::vector<CComunication>  m_vComunications;
	wxTimer					    m_Timer;
	volatile bool			    m_bStopTimer;
    volatile bool               m_bOnTimer;
	int						    m_iRefresLists;
	int						    m_iRefreshListsTime;	//min.
	int						    m_iMinInactivity;		//min.
    CRIRegistryProgressDlg      m_ProgressDlg;

public:
	void UpdatePresenceList();
	void UpdateShiftList();
    void UpdateServiceList();
    void UpdateComunicationList();
	void SetPresenceSelected( const CPresence& s );
	void SetServiceSelected( const CService& s );
	void SetShiftSelected( const CShift& s );
	void SetComunicationSelected( const CComunication& c );
    void LogInUser();
	void AuthenticateUser();
};

#endif // __CRIRegistryMainFrame__
