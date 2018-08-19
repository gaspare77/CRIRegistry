#include "CheckListManager.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor implementation
// 
CheckListManager::CheckListManager(void)
{
}

/////////////////////////////////////////////////////////////////////////////
// Destructor implementation
// 
CheckListManager::~CheckListManager(void)
{
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CheckListManager::Show(const wxString& type)
{
    CRIRegistryCheckListDlg dlg(0l, type);
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CheckListManager::Control(const wxString& type)
{
    wxString query;
    dbResultSet res;

    query = wxString::Format(_T("SELECT %s FROM %s WHERE %s=%s AND %s='%s' AND DATE(Now())=DATE(%s) AND TIME(Now())>=%s AND TIME(Now())<=%s ORDER BY %s, %s"),
        FIELD_VERIFICATO,
        TABLE_CHECK_LIST,
        FIELD_GRUPPO, ::SQLStringFormat(CRIRegistryOptions::Instance()->GetDefaultGruppo()).c_str(),
        FIELD_TIPO, type.c_str(),
        FIELD_DATA,
        FIELD_INIZIO,
        FIELD_FINE,
        FIELD_POSIZIONE,
        FIELD_NOME
        );
    if ( !dbSingleton::Instance()->SQLQuery(query, &res) )
    {
        return;
    }

    bool showWarning = false;
    if ( res.GetSize() == 0 )
    {
        Create(type);
        showWarning = true;
    }
    else
    {
        for (int i = 0; i < res.GetSize(); i++)
        {
            if ( !res.Row(i).Col(FIELD_VERIFICATO).GetBoolValue() )
            {
                showWarning = true;
                break;
            }
        }
    }

    if (showWarning)
    {
        WARNING_MESSAGE("Ricordati che devi fare la check-list %s", type.c_str());
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CheckListManager::Create(const wxString& type)
{
    wxString query;
    dbResultSet res;

    // Select fields to add
    query = wxString::Format(_T("SELECT t1.%s, t4.%s, t3.%s, t3.%s, t3.%s, t2.%s, t1.%s FROM %s AS t1 JOIN %s AS t2 ON t1.%s_%s=t2.%s JOIN %s AS t3 ON t1.%s_%s=t3.%s JOIN %s AS t4 ON t1.%s_%s=t4.%s WHERE t1.%s=%s AND t4.%s='%s' AND TIME(Now())>=t3.%s AND TIME(Now())<=t3.%s ORDER BY t2.%s, t1.%s"),
        FIELD_GRUPPO,
        FIELD_TIPO,
        FIELD_NOME,
        FIELD_INIZIO,
        FIELD_FINE,
        FIELD_POSIZIONE,
        FIELD_NOME,
        TABLE_CHECK_LIST_ITEM,
        TABLE_CHECK_LIST_POSITION,
        TABLE_CHECK_LIST_POSITION, FIELD_ID, 
        FIELD_ID,
        TABLE_CHECK_LIST_TIME, 
        TABLE_CHECK_LIST_TIME, FIELD_ID, 
        FIELD_ID,
        TABLE_CHECK_LIST_TYPE, 
        TABLE_CHECK_LIST_TYPE, FIELD_ID, 
        FIELD_ID,
        FIELD_GRUPPO, ::SQLStringFormat(CRIRegistryOptions::Instance()->GetDefaultGruppo()).c_str(),
        FIELD_TIPO, type.c_str(),
        FIELD_INIZIO,
        FIELD_FINE,
        FIELD_POSIZIONE,
        FIELD_NOME
    );
    if (!dbSingleton::Instance()->SQLQuery(query, &res))
    {
        return false;
    }

    // Insert the fields into the table
    for (int i = 0; i < res.GetSize(); i++)
    {
        query = wxString::Format(_T("INSERT INTO %s (%s,%s,%s,%s,%s,%s,%s,%s) VALUES(%s,%s,Now(),%s,%s,%s,%s,%s)"), 
            TABLE_CHECK_LIST,
            FIELD_GRUPPO,
            FIELD_TIPO,
            FIELD_DATA,
            FIELD_TURNO,
            FIELD_INIZIO,
            FIELD_FINE,
            FIELD_POSIZIONE,
            FIELD_NOME,
            res.Row(i).Col(0).GetSQLFormatValue().c_str(),
            res.Row(i).Col(1).GetSQLFormatValue().c_str(),
            res.Row(i).Col(2).GetSQLFormatValue().c_str(),
            res.Row(i).Col(3).GetSQLFormatValue().c_str(),
            res.Row(i).Col(4).GetSQLFormatValue().c_str(),
            res.Row(i).Col(5).GetSQLFormatValue().c_str(),
            res.Row(i).Col(6).GetSQLFormatValue().c_str(),
            res.Row(i).Col(7).GetSQLFormatValue().c_str()
        );
        if (!dbSingleton::Instance()->SQLQuery(query))
        {
            return false;
        }
    }

    return true;
}
