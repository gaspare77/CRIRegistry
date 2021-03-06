#ifndef __CRIRegistryCheckListAddItemDlg__
#define __CRIRegistryCheckListAddItemDlg__

/**
@file
Subclass of CheckListAddItemDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryCheckListPagesGUIs.h"
#include "CRIRegistryCheckListTimeIntervalDlg.h"
#include "CRIRegistryAddFieldsDlg.h"
#include "CRIRegistryOptions.h"

/** Implementing CheckListAddItemDlg */
class CRIRegistryCheckListAddItemDlg : public CheckListAddItemDlg
{
protected:
    // Handlers for CheckListAddItemDlg events.
    void OnChoice( wxCommandEvent& event );
    void OnEditPosition( wxCommandEvent& event );
    void OnExitCtrl( wxFocusEvent& event );
    void OnOk( wxCommandEvent& event );
    void OnCancel( wxCommandEvent& event );

public:
    /** Constructor */
    CRIRegistryCheckListAddItemDlg( wxWindow* parent, const wxString& gruppo, const wxString& type, const wxString& item = wxEmptyString, const wxString& position = wxEmptyString );
    bool InsertIntoDb();
    bool UpdateDb();

private:
    wxString            m_Gruppo;
    std::vector<dbRow>  m_Hours;
    std::vector<dbRow>  m_Positions;
    std::vector<dbRow>  m_Items;

    int m_TypeId;

    wxArrayString GetHours();
    wxArrayString GetPositions();

    std::vector<dbRow>::iterator GetHourSelect( const wxString& name );
    std::vector<dbRow>::iterator GetHourById( int id );

    std::vector<dbRow>::iterator GetPositionSelect( const wxString& name );
    std::vector<dbRow>::iterator GetPositionById( int id );

    std::vector<dbRow>::iterator GetItemByHour( const wxString& hour );

    void SelectPositions();
    void SelectHours();

};

#endif // __CRIRegistryCheckListAddItemDlg__
