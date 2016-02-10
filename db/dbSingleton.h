//---------------------------------------------------------------------------
// Name:        dbSingleton.h
// Author:      Gaspare Faraci
// Created:     29/6/2009
//---------------------------------------------------------------------------

#ifndef __DBSINGLETON_H_INCL__
#define __DBSINGLETON_H_INCL__

#include <wx/wx.h>
#include <wx/ffile.h>

#include "dbField.h"
#include "../Singleton.h"
#include "../OdbcW/OdbcW.h"
#include "../MyFunctions.h"

class dbSingleton : public Singleton<dbSingleton, dbSingleton>
{
public:
    // Destructor
    virtual ~dbSingleton();
    bool Connect( const wxString& filename, const wxString& user = wxEmptyString, const wxString& pwd = wxEmptyString );
    bool IsConnected();
    bool SQLQuery( const wxString& query, dbResultSet* ResultSet = NULL );
    bool SQLUpdate( const wxString& table, const dbRow& res, const wxString& condition );
    bool SQLInsert( const wxString& table, const dbRow& res );
    bool SQLDelete( const wxString& table, const wxString& condition );
	int SQLGetMax( const wxString& table, const wxString& field, const wxString& condition = wxEmptyString );
	int SQLCount( const wxString& table, const wxString& field, const wxString& condition = wxEmptyString );
    wxDateTime SQLGetLastDate( const wxString& table, const wxString& field, const wxString& condition = wxEmptyString );
    wxArrayString SQLGetColArray( const wxString& query, int col = 0 );
    wxArrayString SQLGetColArray( const wxString& query, const wxString& col );
    bool CreateTables();

protected:
    // Constructor - protected so users cannot call it.
    dbSingleton();

private: 
	friend Singleton<dbSingleton, dbSingleton>;

	OdbcWConnectionId*              m_OdbcWConId;
    OdbcW*                          m_OdbcW;
    wxString                        m_szDnsFileName;
    wxString                        m_szdbUser;
    wxString                        m_szdbPwd;
    bool							m_bOk;
    dbField                         m_dbFieldDummy;
};
#endif
