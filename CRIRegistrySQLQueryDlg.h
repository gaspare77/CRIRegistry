#ifndef __CRIRegistrySQLQueryDlg__
#define __CRIRegistrySQLQueryDlg__

/**
@file
Subclass of SQLQueryDlg, which is generated by wxFormBuilder.
*/

#include "CRIRegistryGUIs.h"
#include "CRIRegistryConstant.h"
#include "db/dbSingleton.h"
#include "db/dbClass.h"

/** Implementing SQLQueryDlg */
class CRIRegistrySQLQueryDlg : public SQLQueryDlg
{
protected:
    // Handlers for SQLQueryDlg events.
    void OnOpenQuery( wxCommandEvent& event );
	void OnQueryAdd( wxCommandEvent& event );
	void OnQueryDel( wxCommandEvent& event );
	void OnQueryExecute( wxCommandEvent& event );
	void OnExport( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );
    void OnWrite( wxKeyEvent& event );

public:
    /** Constructor */
    CRIRegistrySQLQueryDlg( wxWindow* parent );	

private:
	std::map<wxString,dbClass>	m_mQueries;
	bool SelectQueries();
    bool UpdateLocal();
	bool AddQuery( const wxString& name, const wxString& query );
	bool DelQuery( const wxString& name );
	wxArrayString GetQueriesList();
};

#endif // __CRIRegistrySQLQueryDlg__