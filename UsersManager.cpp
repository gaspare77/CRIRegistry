//---------------------------------------------------------------------------
// Name:        UsersManager.cpp
// Author:      Gaspare Faraci
// Created:     29/6/2009
//---------------------------------------------------------------------------

#include "UsersManager.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
UsersManager::UsersManager()
{
    m_LastUser = CRIRegistryOptions::Instance()->GetLastUser();
}

/////////////////////////////////////////////////////////////////////////////
// Destructor implementation
// 
UsersManager::~UsersManager()
{
    LogOut();
}

/////////////////////////////////////////////////////////////////////////////
//
// 
bool UsersManager::LogIn()
{
    UsersManagerLogInDlg dlg( 0l, m_LastUser );
    if ( dlg.ShowModal() == wxID_OK )
    {
        CUser user;
        if ( user.LoadFromDb( dlg.GetUser() ) && user.CheckPwd( dlg.GetPassword() ) && !user.IsAlreadyLoggedIn() )
        {
            m_User = user;

            // If the user has not psw defined he must set it
            if ( m_User.GetPwd() == my_md5( _T("") ) && !SetPassword() )
            {
                return false;
            }

            // Show user info
            INFO_MESSAGE( _("Utente: %s\nPrivilegi: %s\nUltimo accesso: %s"), 
                m_User.GetName().c_str(),
                szUserPrivilege[m_User.GetPrivileges()],
                m_User.GetLastLogIn() == EmptyDate ? 
                _("Primo accesso") : 
            m_User.GetLastLogIn().Format(FORMAT_DATE_TIME_EXTENDED).c_str()
                );

            // Update the last login time
            m_User.SetLastLogIn( wxDateTime::Now() );
            m_User.UpdateIntoDb();

            // Unlock all table and row opened by it
            UnlockAll();

            m_LastUser = m_User.GetName();
            CRIRegistryOptions::Instance()->SetLastUsert( m_LastUser );
            return true;
        }
    }

    return false;
}

/////////////////////////////////////////////////////////////////////////////
//
// 
bool UsersManager::LogOut( bool ask )
{
    if ( ask && QUESTION_MESSAGE( _("Disconnettere l'utente %s"), m_User.GetName().c_str() ) == wxNO )
    {
        return false;
    }

    // Update the last logout time
    if ( !m_User.GetName().IsEmpty() )
    {
        m_User.SetLastLogOut( wxDateTime::Now() );
        m_User.UpdateIntoDb();

        // Unlock all table and row opened by it
        UnlockAll();
    }

    m_User.SetName( wxEmptyString );
    m_User.SetNome( wxEmptyString );
    m_User.SetCognome( wxEmptyString );
    m_User.SetPwd( wxEmptyString );
    m_User.SetPrivileges( NONE );
    m_User.SetLastLogIn( EmptyDate );
    m_User.SetLastLogOut( EmptyDate );

    return true;
}

/////////////////////////////////////////////////////////////////////////////
//
// 
bool UsersManager::ChangePassword()
{
    UsersManagerChangeUsersPwdDlg dlg( 0l );
    if ( dlg.ShowModal() == wxID_OK )
    {
        m_User.SetPwd( dlg.GetNewPassword() );
        if ( !m_User.UpdateIntoDb() )
        {
            return false;
        }

        INFO_MESSAGE( _("La password per l'utente %s e' stata cambiata"), m_User.GetName().c_str() );
        return true;
    }

    return false;
}

/////////////////////////////////////////////////////////////////////////////
//
// 
bool UsersManager::SetPassword()
{
    UsersManagerSetUsersPwdDlg dlg( 0l );
    if ( dlg.ShowModal() == wxID_OK )
    {
        m_User.SetPwd( dlg.GetNewPassword() );
        if ( !m_User.UpdateIntoDb() )
        {
            return false;
        }

        INFO_MESSAGE( _("La password per l'utente %s e' impostata"), m_User.GetName().c_str() );
        return true;
    }

    return false;
}

/////////////////////////////////////////////////////////////////////////////
//
// 
bool UsersManager::Show()
{
    UsersManagerDlg dlg( 0l );
    dlg.ShowModal();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool UsersManager::LockTable( const wxString& table )
{
    wxString query = wxString::Format( _T("INSERT INTO %s(%s,%s) VALUES(\'%s\',\'%s\')"), 
        TABLE_LOCK, 
        FIELD_TABLE_NAME, FIELD_USER, 
        table.c_str(), m_User.GetName().c_str() );

    return dbSingleton::Instance()->SQLQuery( query, NULL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool UsersManager::UnlockTable( const wxString& table )
{
    wxString query = wxString::Format( _T("DELETE FROM %s WHERE %s=\'%s\' AND %s=\'%s\'"), 
        TABLE_LOCK, 
        FIELD_TABLE_NAME, table.c_str(), 
        FIELD_USER, m_User.GetName().c_str() );

    return dbSingleton::Instance()->SQLQuery( query, NULL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool UsersManager::IsTableLocked( const wxString& table, const wxString& msg )
{
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE (%s=\'%s\') AND (%s<>\'%s\')"), 
        FIELD_USER, 
        TABLE_LOCK, 
        FIELD_TABLE_NAME, table.c_str(), 
        FIELD_USER, m_User.GetName().c_str() );
    dbResultSet res;

    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) || res.GetSize() != 0 )
    {
        WARNING_MESSAGE( _("%s\n%s"), msg.c_str(), res.Row().Col().GetCharValue() );
        return true;
    }

    return false;
}

/////////////////////////////////////////////////////////////////////////////
// Lock the dbRow into the DataBase
// 
bool UsersManager::LockRow( const wxString& table, int id )
{
    wxString query = wxString::Format( _T("INSERT INTO %s(%s,%s,%s) VALUES(\'%s\',%d,\'%s\')"), 
        TABLE_LOCK, 
        FIELD_TABLE_NAME, FIELD_TABLE_ID, FIELD_USER, 
        table.c_str(), id, m_User.GetName().c_str() );

    return dbSingleton::Instance()->SQLQuery( query, NULL );
}

/////////////////////////////////////////////////////////////////////////////
// Unlock the dbRow into the DataBase
// 
bool UsersManager::UnlockRow( const wxString& table, int id )
{
    wxString query = wxString::Format( _T("DELETE FROM %s WHERE %s=\'%s\' AND %s=%d AND %s=\'%s\'"), 
        TABLE_LOCK, 
        FIELD_TABLE_NAME, table.c_str(),
        FIELD_TABLE_ID, id,
        FIELD_USER, m_User.GetName().c_str() );

    return dbSingleton::Instance()->SQLQuery( query, NULL );
}

/////////////////////////////////////////////////////////////////////////////
// Check if is locked the dbRow into the DataBase
// 
bool UsersManager::IsRowLocked( const wxString& table, int id, const wxString& msg )
{
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE (%s=\'%s\') AND (%s=%d) AND (%s<>\'%s\')"), 
        FIELD_USER, 
        TABLE_LOCK, 
        FIELD_TABLE_NAME, table.c_str(), 
        FIELD_TABLE_ID, id,
        FIELD_USER, m_User.GetName().c_str() );

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) || res.GetSize() != 0 )
    {
        WARNING_MESSAGE( _("%s\n%s"), msg.c_str(), res.Row().Col().GetCharValue() );
        return true;
    }

    return false;
}

/////////////////////////////////////////////////////////////////////////////
// Unlock all for the current user
// 
bool UsersManager::UnlockAll()
{
    wxString query = wxString::Format( _T("DELETE FROM %s WHERE %s=\'%s\'"), 
        TABLE_LOCK, 
        FIELD_USER, m_User.GetName().c_str() );

    return dbSingleton::Instance()->SQLQuery( query, NULL );
}

