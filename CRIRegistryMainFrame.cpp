#include "CRIRegistryMainFrame.h"

#define __SHOW_DATE_TIME__  m_Calendar->SetLabel( wxDateTime::Now().Format( _("%H:%M\n%A %d %B %Y") ) );

#define __SINCRONIZE_TIMER__ \
    VariableRestorer<bool> TimerRestorer( &m_bStopTimer ); \
    if ( m_bOnTimer ) \
        return; \
    m_bStopTimer = true;

/////////////////////////////////////////////////////////////////////////////
// 
// 
BEGIN_EVENT_TABLE( CRIRegistryMainFrame, MainFrame )
    EVT_TIMER( TIMER_ID, CRIRegistryMainFrame::OnTimer)
END_EVENT_TABLE()

/////////////////////////////////////////////////////////////////////////////
// 
// 
CRIRegistryMainFrame::CRIRegistryMainFrame( wxWindow* parent ) :
MainFrame( parent ), 
m_Timer( this, TIMER_ID ), 
m_bStopTimer( false ),
m_bOnTimer( false ), 
m_iRefresLists( 0 ),
m_iMinInactivity( 0 ),
m_iRefreshListsTime( 1 ),
m_ProgressDlg( NULL )
{
    SetIcon( wxICON(ProgramIcon) ); 

//  int widths[] = { -1, 250 };
//  int style[] = { wxSB_NORMAL, wxSB_NORMAL };
//  m_statusBar->SetFieldsCount( 2, widths );
//  m_statusBar->SetStatusStyles( 2, style );
    __SHOW_DATE_TIME__

    // Presence list control
    m_list_Presence->InsertColumn( 0, _("Gruppo"), wxLIST_FORMAT_LEFT );
    m_list_Presence->InsertColumn( 1, _("Cognome"), wxLIST_FORMAT_LEFT );
    m_list_Presence->InsertColumn( 2, _("Nome"), wxLIST_FORMAT_LEFT );
    m_list_Presence->InsertColumn( 3, _("Ingresso"), wxLIST_FORMAT_CENTER );
    m_list_Presence->InsertColumn( 4, _("Uscita"), wxLIST_FORMAT_CENTER );
    m_list_Presence->InsertColumn( 5, _("Note"), wxLIST_FORMAT_LEFT );
        
    // Shifts list control
    wxImageList* ShiftStatusImageList = new wxImageList( 16, 16 );
    ShiftStatusImageList->Add( wxICON(ShiftStatusIcon000) );

    m_list_Shift->AssignImageList( ShiftStatusImageList, wxIMAGE_LIST_SMALL );
    m_list_Shift->InsertColumn( 0, _("Gruppo"), wxLIST_FORMAT_LEFT );
    m_list_Shift->InsertColumn( 1, _("Inizio"), wxLIST_FORMAT_CENTER );
    m_list_Shift->InsertColumn( 2, _("Fine"), wxLIST_FORMAT_CENTER );
    m_list_Shift->InsertColumn( 3, _("Tipo"), wxLIST_FORMAT_LEFT );
    m_list_Shift->InsertColumn( 4, _("Mezzo"), wxLIST_FORMAT_CENTER );
    m_list_Shift->InsertColumn( 5, _("Cognome"), wxLIST_FORMAT_LEFT );
    m_list_Shift->InsertColumn( 6, _("Nome"), wxLIST_FORMAT_LEFT );
    m_list_Shift->InsertColumn( 7, _("Qualifica"), wxLIST_FORMAT_LEFT );

    // Services list control
    wxImageList* ServiceStatusImageList = new wxImageList( 16, 16 );
    ServiceStatusImageList->Add( wxICON(ServiceStatusIcon000) );
    ServiceStatusImageList->Add( wxICON(ServiceStatusIcon001) );
    ServiceStatusImageList->Add( wxICON(ServiceStatusIcon002) );

    m_list_Service->AssignImageList( ServiceStatusImageList, wxIMAGE_LIST_SMALL );
    m_list_Service->InsertColumn( 0, _("Gruppo"), wxLIST_FORMAT_LEFT );
    m_list_Service->InsertColumn( 1, _("Servizio N."), wxLIST_FORMAT_CENTER );
    m_list_Service->InsertColumn( 2, _("Data"), wxLIST_FORMAT_LEFT );
    m_list_Service->InsertColumn( 3, _("Tipo di Servizio"), wxLIST_FORMAT_LEFT );
    m_list_Service->InsertColumn( 4, _("Ora Inizio"), wxLIST_FORMAT_CENTER );
    m_list_Service->InsertColumn( 5, _("Ora Fine"), wxLIST_FORMAT_CENTER );
    m_list_Service->InsertColumn( 6, _("Mezzo"), wxLIST_FORMAT_CENTER );
    m_list_Service->InsertColumn( 7, _("Stato"), wxLIST_FORMAT_RIGHT/*LEFT*/ );

    // Comunication list control
    wxImageList* ComunicationStatusImageList = new wxImageList( 16, 16 );
    ComunicationStatusImageList->Add( wxICON(ComunicationStatusIcon000) );

    m_list_Comunication->AssignImageList( ComunicationStatusImageList, wxIMAGE_LIST_SMALL );
    m_list_Comunication->InsertColumn( 0, _("Gruppo"), wxLIST_FORMAT_LEFT );
    m_list_Comunication->InsertColumn( 1, _("Data"), wxLIST_FORMAT_LEFT );
    m_list_Comunication->InsertColumn( 2, _("Da"), wxLIST_FORMAT_LEFT );
    m_list_Comunication->InsertColumn( 3, _("A"), wxLIST_FORMAT_LEFT );
    m_list_Comunication->InsertColumn( 4, _("Oggetto"), wxLIST_FORMAT_LEFT );

    m_notebook->SetSelection( 0 );
    
    AuthenticateUser();

    m_Timer.Start( 60000 ); // 1 min.
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnTimer( wxTimerEvent& event )
{
    __SHOW_DATE_TIME__

    if ( m_bStopTimer || m_bOnTimer )
    {
        m_iMinInactivity = 0;
        return;
    }

    m_bOnTimer = true;

    // Reselect the data from the database
    if ( ++m_iRefresLists >= m_iRefreshListsTime )
    {
        if ( m_menu_Presence->IsChecked( ID_VIEW_CURRENT_PRESENCE ) && m_notebook->GetSelection() == 0 )
        {       
            ShowCurrentPresence();
        }

        if ( m_menu_Shift->IsChecked( ID_VIEW_CURRENT_SHIFT ) && m_notebook->GetSelection() == 1 )
        {       
            ShowCurrentShift();
        }

        if ( m_menu_Service->IsChecked( ID_VIEW_CURRENT_SERVICE ) && m_notebook->GetSelection() == 2 )
        {
            ShowCurrentService();
        }

        if ( m_menu_Comunication->IsChecked( ID_VIEW_CURRENT_COMUNICATION ) && m_notebook->GetSelection() == 3 )
        {
            ShowCurrentComunication();
        }

        m_iRefresLists = 0;
    }

    // Auto set presence out after 12 h
    for ( std::vector<CPresence>::iterator it = m_vPresences.begin(); it != m_vPresences.end(); ++it )
    {
        wxDateTime dt = it->GetField(FIELD_DATAORAINIZIO).GetDateTimeValue();
        if ( wxDateTime::Now() >= dt + wxTimeSpan::Hours(12) )
        {
            it->GetField(FIELD_DATAORAFINE).SetValue( wxDateTime::Now() );
            it->UpdateIntoDb();
        }
    }

    // Auto LogOut User after a [AutoLogOutTime] min. of inactivity
    if ( UsersManager::Instance()->IsUserLogged() && ( CRIRegistryOptions::Instance()->AutoLogOutTime() > 0 ) )
    {
        if ( ++m_iMinInactivity >= ( CRIRegistryOptions::Instance()->AutoLogOutTime() ) )
        {
            UsersManager::Instance()->LogOut();
            AuthenticateUser();
            m_iMinInactivity = 0;
        }
    }

    m_bOnTimer = false;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnClose( wxCloseEvent& event )
{
    __SINCRONIZE_TIMER__

    Destroy();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnSize( wxSizeEvent& event )
{
    __SINCRONIZE_TIMER__

    m_list_Presence->SetColumnWidth( 0, 100 );
    m_list_Presence->SetColumnWidth( 1, 200 );
    m_list_Presence->SetColumnWidth( 2, 200 );
    m_list_Presence->SetColumnWidth( 3, 100 );
    m_list_Presence->SetColumnWidth( 4, 100 );
    m_list_Presence->SetColumnWidth( 5, 200 );

    m_list_Shift->SetColumnWidth( 0, 100 );
    m_list_Shift->SetColumnWidth( 1, 100 );
    m_list_Shift->SetColumnWidth( 2, 100 );
    m_list_Shift->SetColumnWidth( 3, 100 );
    m_list_Shift->SetColumnWidth( 4, 50 );
    m_list_Shift->SetColumnWidth( 5, 200 );
    m_list_Shift->SetColumnWidth( 6, 200 );
    m_list_Shift->SetColumnWidth( 7, 150 );

    m_list_Service->SetColumnWidth( 0, 100 );
    m_list_Service->SetColumnWidth( 1, 100 );
    m_list_Service->SetColumnWidth( 2, 160 );
    m_list_Service->SetColumnWidth( 3, 350 );
    m_list_Service->SetColumnWidth( 4, 65 );
    m_list_Service->SetColumnWidth( 5, 65 );
    m_list_Service->SetColumnWidth( 6, 50 );
    m_list_Service->SetColumnWidth( 7, 80 );

    m_list_Comunication->SetColumnWidth( 0, 100 );
    m_list_Comunication->SetColumnWidth( 1, 180 );
    m_list_Comunication->SetColumnWidth( 2, 180 );
    m_list_Comunication->SetColumnWidth( 3, 200 );
    m_list_Comunication->SetColumnWidth( 4, 350 );

    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnQuit( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    Close();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnSQLQuery( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    CRIRegistrySQLQueryDlg dlg( this );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnExportService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    wxString szFileName = wxString::Format( _("Backup_RegistroServizi") );
    szFileName = ::wxSaveFileSelector( _T(""), _T("gfr"), szFileName );
    if ( szFileName.IsEmpty() )
    {
        return;
    }
    if ( ::wxFileExists(szFileName) && QUESTION_MESSAGE(_("Il file %s esiste gia\'\nLo vuoi sovrascrivere?"), szFileName.c_str()) != wxYES )
    {
        return;
    }

    CRIRegistrySelectDateRangeDlg dlg( this, _("Selezionare l'intervallo dei servizi da esportare") );
    if ( dlg.ShowModal() != wxID_OK )
    {
        return;
    }
    
    wxString query;
    wxString start;
    wxString end;
    dbResultSet res;
    start =  dlg.GetDateStart().FormatISODate();
    end =  dlg.GetDateEnd().FormatISODate();
    query = wxString::Format( _T("SELECT %s FROM %s WHERE %s >= \'%s\' AND %s <= \'%s\' ORDER BY %s,%s,%s"), 
                                FIELD_ID,
                                TABLE_REGISTROSERVIZI,
                                FIELD_DATA,
                                start.c_str(),
                                FIELD_DATA,
                                end.c_str(),
                                FIELD_DATA,
                                FIELD_NUMSERVIZIOSUP,
                                FIELD_NUMSERVIZIO);

    m_ProgressDlg.Show();
    m_ProgressDlg.SetText( _("Esecuzione della query in corso ...") );
    m_ProgressDlg.Update( 0 );
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        m_ProgressDlg.Close();
        return;
    }
    m_ProgressDlg.Update( 100 );

    m_ProgressDlg.SetText( _("Caricamento dei dati ricevuti in corso ...") );
    m_ProgressDlg.Update( 0 );
    std::vector<CService> vServices;
    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CService service;
        service.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !service.SelectFromDb() )
        {
            m_ProgressDlg.Close();
            return;
        }
        vServices.push_back( service );
        m_ProgressDlg.Update( i * 100 / res.GetSize() );
    }

    wxFFile file( szFileName, "w" );
    if ( !file.IsOpened() )
    {
        m_ProgressDlg.Close();
        return;
    }

    m_ProgressDlg.SetText( wxString::Format( _("Esportazione dei servizi in corso ...") ) );
    int iProgress = 0;
    m_ProgressDlg.Update( iProgress );
    for ( std::vector<CService>::iterator s = vServices.begin(); s != vServices.end(); ++s )
    {
        file.Write( _T("<CService>\n") );
        file.Write( s->Serialize() );
        for ( std::vector<CServiceCrew>::iterator c = s->GetCrew().begin(); c != s->GetCrew().end(); ++c )
        {
            file.Write( _T("<CServiceCrew>\n") );
            file.Write( c->Serialize() );
            file.Write( _T("<CServiceCrewEnd>\n") );
        }
        for ( std::vector<CServicePatient>::iterator p = s->GetPatient().begin(); p != s->GetPatient().end(); ++p )
        {
            file.Write( _T("<CServicePatient>\n") );
            file.Write( p->Serialize() );
            for ( std::vector<CTreatment>::iterator t = p->GetTreatment().begin(); t != p->GetTreatment().end(); ++t )
            {
                file.Write( _T("<CTreatment>\n") );
                file.Write( t->Serialize() );
                file.Write( _T("<CTreatmentEnd>\n") );
            }
            for ( std::vector<CDinamic>::iterator d = p->GetDinamic().begin(); d != p->GetDinamic().end(); ++d )
            {
                file.Write( _T("<CDinamic>\n") );
                file.Write( d->Serialize() );
                file.Write( _T("<CDinamicEnd>\n") );
            }
            file.Write( _T("<CServicePatientEnd>\n") );
        }
        file.Write( _T("<CServiceEnd>\n") );
        m_ProgressDlg.Update( ++iProgress*100/vServices.size() );
    }

    file.Close();
    m_ProgressDlg.Close();
    INFO_MESSAGE( _("Il file %s e' stato esportato"), szFileName.c_str() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnImportService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    wxString szFileName = wxString::Format( _("") );
    szFileName = ::wxLoadFileSelector( _T(""), _T("gfr"), szFileName );
    if ( szFileName.IsEmpty() )
    {
        return;
    }

    m_ProgressDlg.Show();
    m_ProgressDlg.SetText( _("Importazione servizi in corso ...") );
    m_ProgressDlg.Update( 0 );

    wxFFile file( szFileName, "r" );
    if ( !file.IsOpened() )
    {
        ERROR_MESSAGE( _("Errore durante l\'apertura del file %s"), szFileName.c_str() );
        m_ProgressDlg.Close();
        return;
    }
    wxString lines;
    if ( !file.ReadAll( &lines ) )
    {
        ERROR_MESSAGE( _("Errore durante la lettura del file %s"), szFileName.c_str() );
        m_ProgressDlg.Close();
        return;
    }
    file.Close();

    if ( !lines.StartsWith( _T("<CService>") ) )
    {
        ERROR_MESSAGE( _("Il file %s non e\' valido"), szFileName.c_str() );
        m_ProgressDlg.Close();
        return;
    }

    wxStringTokenizer tk( lines, _T("\r\n") );
    int iSize = tk.CountTokens();
    int iProgress = 0;

    CService service;
    CServiceCrew crew;
    CServicePatient patient;
    CTreatment treatment;
    CDinamic dinamic;

    bool bIntoServiceSection = false;
    bool bIntoServiceCrewSection = false;
    bool bIntoServicePatientSection = false;
    bool bIntoTreatmentSection = false;
    bool bIntoDinamicSection = false;
    wxString txt;

    while( tk.HasMoreTokens() )
    {
        wxString line = tk.GetNextToken();
        m_ProgressDlg.Update( ++iProgress*100/iSize );
        
        // Skip Id field
        if ( line.StartsWith( FIELD_ID ) )
        {
            continue;
        }
        if ( line.StartsWith( wxString::Format( _T("%s_%s"), TABLE_REGISTROSERVIZI, FIELD_ID ) ) )
        {
            continue;
        }
        if ( line.StartsWith( wxString::Format( _T("%s_%s"), TABLE_REGISTROSERVIZI_PAZIENTI, FIELD_ID ) ) )
        {
            continue;
        }

        // Section CService
        if ( line == _T("<CService>") )
        {
            bIntoServiceSection = true;
            continue;
        }
        if ( line == _T("<CServiceEnd>") )
        {
            txt = wxString::Format( _("Importo il servizio numero %08d/%08d"), service.GetField(FIELD_NUMSERVIZIO).GetIntValue(), service.GetField(FIELD_NUMSERVIZIOSUP).GetIntValue() );
            m_ProgressDlg.SetText( txt );
            wxString szCondition = wxString::Format( _T("%s=\'%s\' AND %s=%d AND %s=%d"), 
                FIELD_DATA,
                service.GetField(FIELD_DATA).GetCharValue(), 
                FIELD_NUMSERVIZIO,
                service.GetField(FIELD_NUMSERVIZIO).GetIntValue(), 
                FIELD_NUMSERVIZIOSUP,
                service.GetField(FIELD_NUMSERVIZIOSUP).GetIntValue() );
            int isPresent = dbSingleton::Instance()->SQLCount( TABLE_REGISTROSERVIZI, FIELD_ID, szCondition );
            if ( isPresent == 0 )
            {
                ::wxSafeYield( &m_ProgressDlg, true );
                bool bResult = service.InsertIntoDb();
                if ( !bResult )
                {
                    ERROR_MESSAGE( _("Errore durante l\'importazione del Registro Servizi") );
                    m_ProgressDlg.Close();
                    return;
                }
            }
            else
            {
                if ( QUESTION_MESSAGE( _("Il servizio %06d/%06d\ndel %s e\' gia\' presente.\nVuoi continuare?"), 
                    service.GetField(FIELD_NUMSERVIZIO).GetIntValue(), 
                    service.GetField(FIELD_NUMSERVIZIOSUP).GetIntValue(),
                    service.GetField(FIELD_DATA).GetDateTimeValue().FormatDate().c_str()
                    ) == wxNO )
                {
                    m_ProgressDlg.Close();
                    return;
                }
            }
            service.SetId( 0 );
            service.ClearAllCrew();
            service.ClearAllPatient();
            bIntoServiceSection = false;
            continue;
        }
        // Section CServiceCrew
        if ( line == _T("<CServiceCrew>") )
        {
            bIntoServiceCrewSection = true;
            continue;
        }
        if ( line == _T("<CServiceCrewEnd>") )
        {
            service.AddCrew( crew );
            bIntoServiceCrewSection = false;
            continue;
        }

        // Section CServicePatient
        if ( line == _T("<CServicePatient>") )
        {
            patient.ClearAllTreatment();
            patient.ClearAllDinamic();
            bIntoServicePatientSection = true;
            continue;
        }
        if ( line == _T("<CServicePatientEnd>") )
        {
            service.AddPatient( patient );
            bIntoServicePatientSection = false;
            continue;
        }

        // Section CTreatment
        if ( line == _T("<CTreatment>") )
        {
            bIntoTreatmentSection = true;
            continue;
        }
        if ( line == _T("<CTreatmentEnd>") )
        {
            patient.AddTreatment( treatment );
            bIntoTreatmentSection = false;
            continue;
        }

        // Section CDinamic
        if ( line == _T("<CDinamic>") )
        {
            bIntoDinamicSection = true;
            continue;
        }
        if ( line == _T("<CDinamicEnd>") )
        {
            patient.AddDinamic( dinamic );
            bIntoDinamicSection = false;
            continue;
        }

        // Unserialize
        bool bUnserialized = false;
        if ( bIntoServiceSection && !bIntoServiceCrewSection && !bIntoServicePatientSection && !bIntoTreatmentSection && !bIntoDinamicSection )
        {
            bUnserialized = service.Unserialize( line );
        }
        else if ( bIntoServiceSection && bIntoServiceCrewSection && !bIntoServicePatientSection && !bIntoTreatmentSection && !bIntoDinamicSection )
        {
            bUnserialized = crew.Unserialize( line );
        }
        else if ( bIntoServiceSection && !bIntoServiceCrewSection && bIntoServicePatientSection && !bIntoTreatmentSection && !bIntoDinamicSection )
        {
            bUnserialized = patient.Unserialize( line );
        }
        else if ( bIntoServiceSection && !bIntoServiceCrewSection && bIntoServicePatientSection && bIntoTreatmentSection && !bIntoDinamicSection )
        {
            bUnserialized = treatment.Unserialize( line );
        }
        else if ( bIntoServiceSection && !bIntoServiceCrewSection && bIntoServicePatientSection && !bIntoTreatmentSection && bIntoDinamicSection )
        {
            bUnserialized = dinamic.Unserialize( line );
        }

        if ( !bUnserialized )
        {
            ERROR_MESSAGE( _("Error on line %d [%s]"), iProgress, line.c_str() );
            m_ProgressDlg.Close();
            return;
        }
    }
    
    m_ProgressDlg.Close();
    INFO_MESSAGE( _("Il file %s e' stato importato"), szFileName.c_str() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnExportShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    wxString szFileName = wxString::Format( _("Backup_RegistroTurni") );
    szFileName = ::wxSaveFileSelector( _T(""), _T("gfr"), szFileName );
    if ( szFileName.IsEmpty() )
    {
        return;
    }
    if ( ::wxFileExists(szFileName) && QUESTION_MESSAGE(_("Il file %s esiste gia\'\nLo vuoi sovrascrivere?"), szFileName.c_str()) != wxYES )
    {
        return;
    }

    CRIRegistrySelectDateRangeDlg dlg( this, _("Selezionare l'intervallo dei turni da esportare") );
    if ( dlg.ShowModal() != wxID_OK )
    {
        return;
    }
    
    wxString query;
    wxString start;
    wxString end;
    dbResultSet res;
    start =  dlg.GetDateStart().FormatISODate();
    end =  dlg.GetDateEnd().FormatISODate();

    query = wxString::Format( _T("SELECT %s FROM %s WHERE (%s>=\'%s %s\' AND %s<=\'%s %s\') OR (%s>=\'%s %s\' AND %s<=\'%s %s\') ORDER BY %s,%s,%s,%s,%s"), 
                                FIELD_ID,
                                TABLE_REGISTROTURNI,
                                FIELD_DATAORAINIZIO,
                                start.c_str(),
                                start.c_str(),
                                FIELD_DATAORAINIZIO,
                                end.c_str(),
                                end.c_str(),
                                FIELD_DATAORAFINE,
                                start.c_str(),
                                start.c_str(),
                                FIELD_DATAORAFINE,
                                end.c_str(),
                                end.c_str(),
                                FIELD_DATAORAINIZIO,
                                FIELD_DATAORAFINE,
                                FIELD_TIPO,
                                FIELD_CODMEZZO,
                                FIELD_QUALIFICA);

    m_ProgressDlg.Show();
    m_ProgressDlg.SetText( _("Esecuzione della query in corso ...") );
    m_ProgressDlg.Update( 0 );
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        m_ProgressDlg.Close();
        return;
    }
    m_ProgressDlg.Update( 100 );

    m_ProgressDlg.SetText( _("Caricamento dei dati ricevuti in corso ...") );
    m_ProgressDlg.Update( 0 );
    std::vector<CShift> vShift;
    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CShift shift;
        shift.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !shift.SelectFromDb() )
        {
            m_ProgressDlg.Close();
            return;
        }
        vShift.push_back( shift );
        m_ProgressDlg.Update( i * 100 / res.GetSize() );
    }

    wxFFile file( szFileName, "w" );
    if ( !file.IsOpened() )
    {
        m_ProgressDlg.Close();
        return;
    }

    m_ProgressDlg.SetText( wxString::Format( _("Esportazione dei servizi in corso ...") ) );
    int iProgress = 0;
    m_ProgressDlg.Update( iProgress );
    for ( std::vector<CShift>::iterator s = vShift.begin(); s != vShift.end(); ++s )
    {
        file.Write( _T("<CShift>\n") );
        file.Write( s->Serialize() );
        file.Write( _T("<CShiftEnd>\n") );
        m_ProgressDlg.Update( ++iProgress*100/vShift.size() );
    }

    file.Close();
    m_ProgressDlg.Close();
    INFO_MESSAGE( _("Il file %s e' stato esportato"), szFileName.c_str() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnImportShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    wxString szFileName = wxString::Format( _("") );
    szFileName = ::wxLoadFileSelector( _T(""), _T("gfr"), szFileName );
    if ( szFileName.IsEmpty() )
    {
        return;
    }

    m_ProgressDlg.Show();
    m_ProgressDlg.SetText( _("Importazione turni in corso ...") );
    m_ProgressDlg.Update( 0 );

    wxFFile file( szFileName, "r" );
    if ( !file.IsOpened() )
    {
        ERROR_MESSAGE( _("Errore durante l\'apertura del file %s"), szFileName.c_str() );
        m_ProgressDlg.Close();
        return;
    }
    wxString lines;
    if ( !file.ReadAll( &lines ) )
    {
        ERROR_MESSAGE( _("Errore durante la lettura del file %s"), szFileName.c_str() );
        m_ProgressDlg.Close();
        return;
    }
    file.Close();

    if ( !lines.StartsWith( _T("<CShift>") ) )
    {
        ERROR_MESSAGE( _("Il file %s non e\' valido"), szFileName.c_str() );
        m_ProgressDlg.Close();
        return;
    }

    wxStringTokenizer tk( lines, _T("\r\n") );
    int iSize = tk.CountTokens();
    int iProgress = 0;

    CShift shift;
    while( tk.HasMoreTokens() )
    {
        wxString line = tk.GetNextToken();
        m_ProgressDlg.Update( ++iProgress*100/iSize );
        
        // Skip Id field
        if ( line.StartsWith( FIELD_ID ) )
        {
            continue;
        }

        // Section CService
        if ( line == _T("<CShift>") )
        {
            continue;
        }

        if ( line == _T("<CShiftEnd>") )
        {
            wxString szCondition = wxString::Format( _T("%s=\'%s\' AND %s=\'%s\' AND %s=%s AND %s=%s"), 
                FIELD_DATAORAINIZIO,
                shift.GetField(FIELD_DATAORAINIZIO).GetCharValue(), 
                FIELD_DATAORAFINE,
                shift.GetField(FIELD_DATAORAFINE).GetCharValue(), 
                FIELD_COGNOME,
                shift.GetField(FIELD_COGNOME).GetSQLFormatValue().c_str(),
                FIELD_NOME,
                shift.GetField(FIELD_NOME).GetSQLFormatValue().c_str()
                );
            int isPresent = dbSingleton::Instance()->SQLCount( TABLE_REGISTROTURNI, FIELD_ID, szCondition );
            if ( isPresent == 0 )
            {
                ::wxSafeYield( &m_ProgressDlg, true );
                bool bResult = shift.InsertIntoDb();
                if ( !bResult )
                {
                    ERROR_MESSAGE( _("Errore durante l\'importazione del Registro Turni") );
                    m_ProgressDlg.Close();
                    return;
                }
            }
            else
            {
                if ( QUESTION_MESSAGE( _("Il turno di %s %s\ndel %s e\' gia\' presente.\nVuoi continuare?"), 
                    shift.GetField(FIELD_COGNOME).GetCharValue(),
                    shift.GetField(FIELD_NOME).GetCharValue(),
                    shift.GetField(FIELD_DATAORAINIZIO).GetDateTimeValue().FormatDate().c_str()
                    ) == wxNO )
                {
                    m_ProgressDlg.Close();
                    return;
                }
            }
            shift.SetId( 0 );
            continue;
        }

        // Unserialize
        if ( !shift.Unserialize( line ) )
        {
            ERROR_MESSAGE( _("Error on line %d [%s]"), iProgress, line.c_str() );
            m_ProgressDlg.Close();
            return;
        }
    }
    
    m_ProgressDlg.Close();
    INFO_MESSAGE( _("Il file %s e' stato importato"), szFileName.c_str() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnLogIn( wxCommandEvent& event )
{
    LogInUser();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnLogOut( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    UsersManager::Instance()->LogOut();
    AuthenticateUser();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnChangeUser( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    if ( UsersManager::Instance()->IsUserLogged() )
    {
        UsersManager::Instance()->LogOut();
        AuthenticateUser();
        return;
    }

    UsersManager::Instance()->LogIn();
    AuthenticateUser();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnChangeUsersPwd( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    UsersManager::Instance()->ChangePassword();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnUsersManager( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_USERS, _("Non e' possibile aprire la Gestione Utenti perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    UsersManager::Instance()->Show();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenFleet( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_PARCOMACCHINE, _("Non e' possibile aprire il Parco Macchine perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryFleetDlg dlg( this );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenHospital( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_OSPEDALI, _("Non e' possibile aprire la Lista Ospedali perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryHospitalDlg dlg( this );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenGroup( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_GRUPPI, _("Non e' possibile aprire la Lista Gruppi perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryAddFieldsDlg dlg( this, TABLE_GRUPPI, FIELD_ID, FIELD_GRUPPO );
    dlg.SetTitle( _("Lista Gruppi") );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenServiceType( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_TIPOLIGIASERVIZI_ORDINARI, _("Non e' possibile aprire le Tipologie di Servizi Ordinari perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryAddFieldsDlg dlg( this, TABLE_TIPOLIGIASERVIZI_ORDINARI, FIELD_ID, FIELD_TIPO );
    dlg.SetTitle( _("Tipologie di Servizi Ordinari") );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpen118ServiceType( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_TIPOLIGIASERVIZI_118, _("Non e' possibile aprire le Tipologie di Servizi 118 perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryAddFieldsDlg dlg( this, TABLE_TIPOLIGIASERVIZI_118, FIELD_ID, FIELD_TIPO );
    dlg.SetTitle( _("Tipologie di Servizi 118") );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenInternalServiceType( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_TIPOLIGIASERVIZI_INTERNI, _("Non e' possibile aprire le Tipologie di Servizi Interni perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryAddFieldsDlg dlg( this, TABLE_TIPOLIGIASERVIZI_INTERNI, FIELD_ID, FIELD_TIPO );
    dlg.SetTitle( _("Tipologie di Servizi Interni") );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenShiftType( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_TIPOLOGIATURNI, _("Non e' possibile aprire le Tipologie Turni perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryAddFieldsDlg dlg( this, TABLE_TIPOLOGIATURNI, FIELD_ID, FIELD_TIPO );
    dlg.SetTitle( _("Tipologie Turni") );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenVehicleType( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_TIPOLOGIAMEZZI, _("Non e' possibile aprire le Tipologie Mezzi perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryAddFieldsDlg dlg( this, TABLE_TIPOLOGIAMEZZI, FIELD_ID, FIELD_TIPO );
    dlg.SetTitle( _("Tipologie Mezzi") );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenReasonsRefusingTransport( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_MOTIVIRIFIUTATRASPORTO, _("Non e' possibile aprire le Motivazioni Rifiuta il Trasporto perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryAddFieldsDlg dlg( this, TABLE_MOTIVIRIFIUTATRASPORTO, FIELD_ID, FIELD_MOTIVO );
    dlg.SetTitle( _("Motivazioni Rifiuta il Trasporto") );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOpenMailingList( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    // Check if the table is locked
    if ( UsersManager::Instance()->IsTableLocked( TABLE_MAILING_LIST, _("Non e' possibile aprire la mailing list perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    CRIRegistryMailingListDlg dlg( this );
    dlg.ShowModal();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnOptions( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    CRIRegistryOptions::Instance()->Show();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewCurrentPresence( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 0 );
    ShowCurrentPresence();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewAllPresence( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 0 );
    if ( !ShowAllPresence() )
    {
        ShowCurrentPresence();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewCurrentShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 1 );
    ShowCurrentShift();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewAllShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 1 );
    if ( !ShowAllShift() )
    {
        ShowCurrentShift();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewCurrentService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 2 );
    ShowCurrentService();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewAllService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 2 );
    if ( !ShowAllService() )
    {
        ShowCurrentService();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewSearchedService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 2 );
    if ( !ShowSearchedService() )
    {
        ShowCurrentService();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewCurrentComunication( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 3 );
    ShowCurrentComunication();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnViewAllComunication( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 3 );
    if ( !ShowAllComunication() )
    {
        ShowCurrentComunication();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnAbout( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    wxAboutDialogInfo about;

    about.SetIcon( wxICON(ProgramIcon) );
    about.SetName( PRODUCTNAME );
    about.SetVersion( VERSION );
    about.SetDescription( DESCRIPTION );
    about.SetWebSite( EMAIL, AUTOR );

    wxAboutBox( about );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnNotebookPageChanged( wxNotebookEvent& event )
{
    __SINCRONIZE_TIMER__

    event.Skip();

    switch( event.GetSelection() )
    {
    case 0:
        ShowCurrentPresence();
        break;

    case 1:
        ShowCurrentShift();
        break;

    case 2:
        ShowCurrentService();
        break;

    case 3:
        ShowCurrentComunication();
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnSelectPresence( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 0 );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnSelectShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 1 );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnSelectService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 2 );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnSelectComunication( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    m_notebook->SetSelection( 3 );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnSelectFindUsers( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    CRIRegistrySelectUserDisponibilityDlg dlg( this );
    if ( dlg.ShowModal() == wxID_OK )
    {
        CRIRegistryHtmlFrame* frame = new CRIRegistryHtmlFrame( this );
        frame->Show( dlg.GetUrl() );
        frame->Maximize();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnPresencesListDbClick( wxMouseEvent& event )
{
    __SINCRONIZE_TIMER__

    if ( m_bpButton_ModifyPresence->IsEnabled() )
    {
        wxCommandEvent e;
        OnModifyPresence( e );
        event.Skip();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnShifsListDbClick( wxMouseEvent& event )
{
    __SINCRONIZE_TIMER__

    if ( m_bpButton_ModifyShift->IsEnabled() )
    {
        wxCommandEvent e;
        OnModifyShift( e );
        event.Skip();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnServicesListDbClick( wxMouseEvent& event )
{
    __SINCRONIZE_TIMER__

    if ( m_bpButton_ModifyService->IsEnabled() )
    {
        wxCommandEvent e;
        OnModifyService( e );
        event.Skip();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnComunicationListDbClick( wxMouseEvent& event )
{
    __SINCRONIZE_TIMER__

    if ( m_bpButton_ModifyComunication->IsEnabled() )
    {
        wxCommandEvent e;
        OnModifyComunication( e );
        event.Skip();
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryMainFrame::OnKeyPressed( wxKeyEvent& event )
{
    __SINCRONIZE_TIMER__

    switch ( event.GetKeyCode() )
    {
    case WXK_ESCAPE:
        if (( m_notebook->GetSelection() == 0 ) && ( m_menu_Presence->IsChecked( ID_VIEW_ALL_PRESENCE )))
        {
            ShowCurrentPresence();
        }
        else if (( m_notebook->GetSelection() == 1 ) && ( m_menu_Shift->IsChecked( ID_VIEW_ALL_SHIFT )))
        {
            ShowCurrentShift();
        }
        else if (( m_notebook->GetSelection() == 2 ) && ( m_menu_Service->IsChecked( ID_VIEW_ALL_SERVICE ) ||  m_menu_Service->IsChecked( ID_VIEW_SEARCHED_SERVICE )))
        {
            ShowCurrentService();
        }
        else if (( m_notebook->GetSelection() == 3 ) && ( m_menu_Comunication->IsChecked( ID_VIEW_ALL_COMUNICATION )))
        {
            ShowCurrentComunication();
        }
        break;

    case WXK_F3:
        if ( m_notebook->GetSelection() == 2 )
        {
            ShowSearchedService();
        }
        break;

    case WXK_F5:
        break;
    }
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnPresenceIn( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    CPresence p;
    p[FIELD_DATAORAINIZIO] = wxDateTime::Now();
    CRIRegistryPresenceDlg dlg( this, p );
    if ( dlg.ShowModal() == wxID_OK )
    {
        p = dlg.GetPresence();
        if ( p.InsertIntoDb() )
        {
            ShowCurrentPresence();
            SetPresenceSelected( p );
        }
        else
        {
            ERROR_MESSAGE( _("Non e' stato possibile inserire la presenza nel database") );
            return;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnPresenceOut( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CPresence>::iterator it = GetPresenceSelected();
    if ( it == m_vPresences.end() ) 
    {
        return;
    }

    if ( it->GetField( FIELD_DATAORAFINE ).GetDateTimeValue() != EmptyDate )
    {
        return;
    }

    if ( QUESTION_MESSAGE( _("Confermare l'uscita di %s %s?"), 
        it->GetField(FIELD_COGNOME).GetCharValue(), 
        it->GetField(FIELD_NOME).GetCharValue()) != wxYES )
    {
        SetPresenceSelected( *it );
        return;
    }

    it->GetField( FIELD_DATAORAFINE ) = wxDateTime::Now();
    if ( it->UpdateIntoDb() )
    {
        ShowCurrentPresence();
    }
    else
    {
        ERROR_MESSAGE( _("Non e' stato possibile aggiornare la presenza dal database") );
        SetPresenceSelected( *it );
        return;
    }   
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnModifyPresence( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CPresence>::iterator it = GetPresenceSelected();
    if ( it == m_vPresences.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_REGISTROPRESENZE, it->GetId(), _("Non e' possibile modificare la presenza perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_REGISTROPRESENZE, it->GetId() );

    // Reselect the data from the database
    if ( !it->SelectFromDb() )
    {
        return;
    }

    CRIRegistryPresenceDlg dlg( this, *it, MODIFY );
    if ( dlg.ShowModal() == wxID_OK )
    {
        CPresence p(dlg.GetPresence());
        if ( p.UpdateIntoDb() )
        {
            *it = p;
            UpdatePresenceList();
        }
        else
        {
            ERROR_MESSAGE( _("Non e' stato possibile modificare la presenza nel database") );
        }
    }

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_REGISTROPRESENZE, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnDelPresence( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CPresence>::iterator it = GetPresenceSelected();
    if ( it == m_vPresences.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_REGISTROPRESENZE, it->GetId(), _("Non e' possibile cancellare la presenza perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare il turno selezionanto?") ) != wxYES )
    {
        SetPresenceSelected( *it );
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_REGISTROPRESENZE, it->GetId() );

    if ( it->RemoveFromDb() )
    {
        m_vPresences.erase( it );
        if ( m_vPresences.size() > 0 )
        {
            if ( it == m_vPresences.end() )
            {
                SetPresenceSelected( *(--it) );
            }
            else
            {
                SetPresenceSelected( *it );
            }

        }
        UpdatePresenceList();
    }
    else
    {
        ERROR_MESSAGE( _("Non e' stato possibile eliminare la presenza dal database") );
        SetPresenceSelected( *it );
    }   

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_REGISTROPRESENZE, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnAddCrew( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    CRIRegistryAddCrewDlg dlg( this );
    if ( dlg.ShowModal() == wxID_OK )
    {
        std::vector<CShift> crew = dlg.GetCrew();
        for ( std::vector<CShift>::iterator it = crew.begin(); it != crew.end(); ++it )
        {        
            if ( it->InsertIntoDb() )
            {
                ShowCurrentShift();
            }
            else
            {
                ERROR_MESSAGE( _("Non e' stato possibile inserire l'equipaggio nel database") );
                return;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnAddShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    CRIRegistryShiftDlg dlg( this );
    if ( dlg.ShowModal() == wxID_OK )
    {
        CShift s = dlg.GetShift();
        if ( s.InsertIntoDb() )
        {
            ShowCurrentShift();
            SetShiftSelected( s );
        }
        else
        {
            ERROR_MESSAGE( _("Non e' stato possibile inserire il turno nel database") );
            return;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnModifyShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CShift>::iterator it = GetShiftSelected();
    if ( it == m_vShifts.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_REGISTROTURNI, it->GetId(), _("Non e' possibile modificare il turno perche' e' gia' aperto da:") ) )
    {        
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_REGISTROTURNI, it->GetId() );

    // Reselect the data from the database
    if ( !it->SelectFromDb() )
    {
        return;
    }

    CRIRegistryShiftDlg dlg( this, *it, MODIFY );
    if ( dlg.ShowModal() == wxID_OK )
    {
        CShift s(dlg.GetShift());
        if ( s.UpdateIntoDb() )
        {
            *it = s;
            UpdateShiftList();
        }
        else
        {
            ERROR_MESSAGE( _("Non e' stato possibile modificare il turno nel database") );
        }
    }

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_REGISTROTURNI, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnDelShift( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CShift>::iterator it = GetShiftSelected();
    if ( it == m_vShifts.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_REGISTROTURNI, it->GetId(), _("Non e' possibile cancellare il turno perche' e' gia' aperto da:") ) )
    {        
        return;
    }

    if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare il turno selezionanto?") ) != wxYES )
    {
        SetShiftSelected( *it );
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_REGISTROTURNI, it->GetId() );

    if ( it->RemoveFromDb() )
    {
        m_vShifts.erase( it );
        if ( m_vShifts.size() > 0 )
        {
            if ( it == m_vShifts.end() )
            {
                SetShiftSelected( *(--it) );
            }
            else
            {
                SetShiftSelected( *it );
            }

        }
        UpdateShiftList();
    }
    else
    {
        ERROR_MESSAGE( _("Non e' stato possibile eliminare il turno dal database") );
        SetShiftSelected( *it );
    }   

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_REGISTROTURNI, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnAddService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    int NumServ = -1;
    int NumServSup = -1;
    wxString StartWithNum;

    // If is the first one, ask to user with which value want to start
    int CountNumServ = dbSingleton::Instance()->SQLCount( TABLE_REGISTROSERVIZI, FIELD_NUMSERVIZIO );

    // Preset value for Numero Di Servizio
    if ( CRIRegistryOptions::Instance()->IncrementNumServ() && ( CountNumServ == 0 ))
    {
        wxTextEntryDialog dlg1( this, _("Inserire il numero di servizio dalla quale si vuole partire"), _("Numero di Servizio"), wxString::Format( _T("%d"), NumServ ) );
        if ( dlg1.ShowModal() == wxID_OK )
        {
            StartWithNum = dlg1.GetValue();
            if ( StartWithNum.IsEmpty() || !StartWithNum.IsNumber() || atoi( StartWithNum.c_str() ) <= 0 )
            {
                WARNING_MESSAGE( _("Il numero di servizio inserito non e' corretto") );
                return;
            }
            NumServ = atoi( StartWithNum.c_str() );
        }
        else
        {
            return;
        }
    }

    // Preset value for Numero Di Servizio Supplementare
    if ( CRIRegistryOptions::Instance()->IncrementNumServSup() && ( CountNumServ == 0 ))
    {
        wxTextEntryDialog dlg2( this, _("Inserire il numero di servizio supplementare dalla quale si vuole partire"), _("Numero di Servizio Supplementare"), wxString::Format( _T("%d"), NumServSup ) );
        if ( dlg2.ShowModal() == wxID_OK )
        {
            StartWithNum = dlg2.GetValue();
            if ( StartWithNum.IsEmpty() || !StartWithNum.IsNumber() || atoi( StartWithNum.c_str() ) <= 0 )
            {
                WARNING_MESSAGE( _("Il numero di servizio supplementare inserito non e' corretto") );
                return;
            }
            NumServSup = atoi( StartWithNum.c_str() );
        }
        else
        {
            return;
        }
    }

    // Create the service class and set the dafault fields
    CService s;
    s[FIELD_GRUPPO] = CRIRegistryOptions::Instance()->GetDefaultGruppo();
    s[FIELD_CENTRALINO] = UsersManager::Instance()->GetUserLogged().GetFullName();

    // Start the wizard
    CRIRegistryWizardDlg dlg( this, s );
    if ( !dlg.Execute() )
    {
        return;
    }
    s = dlg.GetService();

    s[FIELD_NUMSERVIZIO] = CRIRegistryOptions::Instance()->IncrementNumServ() ? NumServ : 0;
    s[FIELD_NUMSERVIZIOSUP] = CRIRegistryOptions::Instance()->IncrementNumServSup() ? NumServSup : 0;
    s[FIELD_CHIUSO] = CRIRegistryOptions::Instance()->IncrementNumServ() && ( s[FIELD_ORAFINE].GetDateTimeValue() != EmptyDate );

    // Insert the service into the database
    if ( s.InsertIntoDb() )
    {
        ShowCurrentService();
        SetServiceSelected( s );
        s.GetVehicle().UpdateIntoDb();  //Update the Km for the vehicle used

    }
    else
    {
        ERROR_MESSAGE( _("Non e' stato possibile inserire il servizio nel database") );
        return;
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnModifyService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CService>::iterator it = GetServiceSelected();
    if ( it == m_vServices.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_REGISTROSERVIZI, it->GetId(), _("Non e' possibile modificare il servizio perche' e' gia' aperto da:") ) )
    {        
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_REGISTROSERVIZI, it->GetId() );

    // Reselect the data from the database
    if ( !it->SelectFromDb() )
    {
        return;
    }

    CRIRegistryServiceDlg dlg( this, *it );
    if ( dlg.ShowModal() == wxID_OK )
    {
        CService s(dlg.GetService());
        if ( s.UpdateIntoDb() )
        {
            *it = s;
            UpdateServiceList();
        }
        else
        {
            ERROR_MESSAGE( _("Non e' stato possibile modificare il servizio nel database") );
        }
    }
    else
    {
        it->SelectFromDb();
    }

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_REGISTROSERVIZI, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnDelService( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CService>::iterator it = GetServiceSelected();
    if ( it == m_vServices.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_REGISTROSERVIZI, it->GetId(), _("Non e' possibile cancellare il servizio perche' e' gia' aperto da:") ) )
    {        
        return;
    }

    int lastService = dbSingleton::Instance()->SQLGetMax( TABLE_REGISTROSERVIZI, FIELD_ID );

    if ( it->GetId() != lastService )
    {
        WARNING_MESSAGE( _("E' possibile eliminare solo l'ultimo servizio registrato") );
        SetServiceSelected( *it );
        return;
    }

    if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare il servizio selezionanto?") ) != wxYES )
    {
        SetServiceSelected( *it );
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_REGISTROSERVIZI, it->GetId() );

    if ( it->RemoveFromDb() )
    {
        m_vServices.erase( it );
        if ( m_vServices.size() > 0 && it == m_vServices.end() )
        {
            SetServiceSelected( *(--it) );
        }
        UpdateServiceList();
    }
    else
    {
        ERROR_MESSAGE( _("Non e' stato possibile eliminare il servizio dal database") );
        SetServiceSelected( *it );
    }   

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_REGISTROSERVIZI, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnAddComunication( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    CComunication c;
    c[FIELD_INSERITA] = wxDateTime::Now();
    c[FIELD_GRUPPO] = CRIRegistryOptions::Instance()->GetDefaultGruppo();
    c[FIELD_MITTENTE] = UsersManager::Instance()->GetUserLogged().GetFullName();

    CRIRegistryComunicationDlg dlg( this, c );
    if ( dlg.ShowModal() == wxID_OK )
    {
        c = dlg.GetComunication();
        if ( c.InsertIntoDb() )
        {
            ShowCurrentComunication();
            SetComunicationSelected( c );
        }
        else
        {
            ERROR_MESSAGE( _("Non e' stato possibile inserire la comunicazione nel database") );
            return;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnModifyComunication( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CComunication>::iterator it = GetComunicationSelected();
    if ( it == m_vComunications.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_COMUNICAZIONI, it->GetId(), _("Non e' possibile modificare la comunicazione perche\' e\' gia\' aperta da:") ) )
    {        
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_COMUNICAZIONI, it->GetId() );

    // Reselect the data from the database
    if ( !it->SelectFromDb() )
    {
        return;
    }

    bool bCanModify = ( UsersManager::Instance()->GetUserLogged().GetFullName() == it->GetField(FIELD_MITTENTE).GetStringValue() ) ||
                      ( UsersManager::Instance()->GetUserLogged().GetPrivileges() >= RESP_CENTR );
    eMode mode = bCanModify ? MODIFY : READ_ONLY;
    CRIRegistryComunicationDlg dlg( this, *it, mode );
    if ( dlg.ShowModal() == wxID_OK )
    {
        CComunication c(dlg.GetComunication());
        if ( c.UpdateIntoDb() )
        {
            *it = c;
            UpdateComunicationList();
        }
        else
        {
            ERROR_MESSAGE( _("Non e' stato possibile modificare la comunicazione nel database") );
        }
    }

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_COMUNICAZIONI, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::OnDelComunication( wxCommandEvent& event )
{
    __SINCRONIZE_TIMER__

    std::vector<CComunication>::iterator it = GetComunicationSelected();
    if ( it == m_vComunications.end() ) 
    {
        return;
    }

    // Check if the row is locked
    if ( UsersManager::Instance()->IsRowLocked( TABLE_COMUNICAZIONI, it->GetId(), _("Non e' possibile cancellare la comunicazione perche' e' gia' aperta da:") ) )
    {        
        return;
    }

    if ( QUESTION_MESSAGE( _("Sei sicuro di voler eliminare la comunicazione selezionanta?") ) != wxYES )
    {
        SetComunicationSelected( *it );
        return;
    }

    // Lock the row
    UsersManager::Instance()->LockRow( TABLE_COMUNICAZIONI, it->GetId() );

    if ( it->RemoveFromDb() )
    {
        m_vComunications.erase( it );
        if ( m_vComunications.size() > 0 )
        {
            if ( it == m_vComunications.end() )
            {
                SetComunicationSelected( *(--it) );
            }
            else
            {
                SetComunicationSelected( *it );
            }

        }
        UpdateComunicationList();
    }
    else
    {
        ERROR_MESSAGE( _("Non e' stato possibile eliminare la comunicazione dal database") );
        SetComunicationSelected( *it );
    }   

    // Unlock the row
    UsersManager::Instance()->UnlockRow( TABLE_COMUNICAZIONI, it->GetId() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowCurrentPresence()
{
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE %s IS NULL ORDER BY %s,%s"), 
                                       FIELD_ID,
                                       TABLE_REGISTROPRESENZE,
                                       FIELD_DATAORAFINE,
                                       FIELD_DATAORAINIZIO,
                                       FIELD_DATAORAFINE );

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vPresences.clear();

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CPresence presence;
        presence.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !presence.SelectFromDb() )
        {
            return false;
        }
        m_vPresences.push_back( presence );
    }

    m_bitmap_PresenceShowed->SetBitmap( wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Presence->Check( ID_VIEW_CURRENT_PRESENCE, true );
    UpdatePresenceList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowAllPresence()
{
    CRIRegistrySelectDateRangeDlg dlg( this, _("Selezionare l'itervallo delle Presenze da Visualizzare") );
    if ( dlg.ShowModal() != wxID_OK )
    {
        return false;
    }

    wxDateTime start = dlg.GetDateStart();
    wxDateTime end = dlg.GetDateEnd();
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE (%s>=\'%s %s\' AND %s<=\'%s %s\') OR (%s>=\'%s %s\' AND %s<=\'%s %s\') ORDER BY %s,%s"), 
                                       FIELD_ID,
                                       TABLE_REGISTROPRESENZE,
                                       FIELD_DATAORAINIZIO,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_DATAORAINIZIO,
                                       end.FormatISODate().c_str(),
                                       end.FormatISOTime().c_str(),
                                       FIELD_DATAORAFINE,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_DATAORAFINE,
                                       end.FormatISODate().c_str(),
                                       end.FormatISOTime().c_str(),
                                       FIELD_DATAORAINIZIO,
                                       FIELD_DATAORAFINE );

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vPresences.clear();

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CPresence presence;
        presence.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !presence.SelectFromDb() )
        {
            return false;            
        }
        m_vPresences.push_back( presence );
    }

    m_bitmap_PresenceShowed->SetBitmap( wxBitmap( wxT("Res/img_Calendar32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Presence->Check( ID_VIEW_ALL_PRESENCE, true );
    UpdatePresenceList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowCurrentShift()
{
    wxDateTime start = wxDateTime::Now() - wxTimeSpan::Hours(12);
    wxDateTime end = wxDateTime::Now() + wxTimeSpan::Hours(12);
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE (%s>=\'%s %s\' AND %s<=\'%s %s\') OR (%s>=\'%s %s\' AND %s<=\'%s %s\') ORDER BY %s,%s,%s,%s,%s"), 
                                       FIELD_ID,
                                       TABLE_REGISTROTURNI,
                                       FIELD_DATAORAINIZIO,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_DATAORAINIZIO,
                                       end.FormatISODate().c_str(),
                                       end.FormatISOTime().c_str(),
                                       FIELD_DATAORAFINE,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_DATAORAFINE,
                                       end.FormatISODate().c_str(),
                                       end.FormatISOTime().c_str(),
                                       FIELD_DATAORAINIZIO,
                                       FIELD_DATAORAFINE,
                                       FIELD_TIPO,
                                       FIELD_CODMEZZO,
                                       FIELD_QUALIFICA);

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vShifts.clear();

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CShift shift;
        shift.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !shift.SelectFromDb() )
        {
            return false;
        }
        m_vShifts.push_back( shift );
    }

    m_bitmap_ShiftShowed->SetBitmap( wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Shift->Check( ID_VIEW_CURRENT_SHIFT, true );
    UpdateShiftList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowAllShift()
{
    CRIRegistrySelectDateRangeDlg dlg( this, _("Selezionare l'itervallo dei Turni da Visualizzare") );
    if ( dlg.ShowModal() != wxID_OK )
    {
        return false;
    }

    wxDateTime start = dlg.GetDateStart();
    wxDateTime end = dlg.GetDateEnd();
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE (%s>=\'%s %s\' AND %s<=\'%s %s\') OR (%s>=\'%s %s\' AND %s<=\'%s %s\') ORDER BY %s,%s,%s,%s,%s"), 
                                       FIELD_ID,
                                       TABLE_REGISTROTURNI,
                                       FIELD_DATAORAINIZIO,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_DATAORAINIZIO,
                                       end.FormatISODate().c_str(),
                                       end.FormatISOTime().c_str(),
                                       FIELD_DATAORAFINE,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_DATAORAFINE,
                                       end.FormatISODate().c_str(),
                                       end.FormatISOTime().c_str(),
                                       FIELD_DATAORAINIZIO,
                                       FIELD_DATAORAFINE,
                                       FIELD_TIPO,
                                       FIELD_CODMEZZO,
                                       FIELD_QUALIFICA);

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vShifts.clear();

    m_ProgressDlg.Show();
    m_ProgressDlg.SetText( _("Lettura Turni dal database in corso ...") );
    m_ProgressDlg.Update( 0 );
    m_ProgressDlg.SetMax( res.GetSize() ); 

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CShift shift;
        shift.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !shift.SelectFromDb() )
        {
            return false;            
        }
        m_vShifts.push_back( shift );
        m_ProgressDlg.Update( i );
    }
    m_ProgressDlg.Update( 100 );
    m_ProgressDlg.Close();

    m_bitmap_ShiftShowed->SetBitmap( wxBitmap( wxT("Res/img_Calendar32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Shift->Check( ID_VIEW_ALL_SHIFT, true );
    UpdateShiftList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowCurrentService()
{
    wxDateTime DateTime = wxDateTime::Now() - wxTimeSpan::Hours(24);
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE %s>=\'%s %s\' OR %s=0 ORDER BY YEAR(%s),%s,%s"), 
                                       FIELD_ID,
                                       TABLE_REGISTROSERVIZI,
                                       FIELD_ORAINIZIO,
                                       DateTime.FormatISODate().c_str(),
                                       DateTime.FormatISOTime().c_str(),
                                       FIELD_CHIUSO,
                                       FIELD_DATA,
                                       FIELD_NUMSERVIZIO,
                                       FIELD_NUMSERVIZIOSUP);

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vServices.clear();

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CService service;
        service.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !service.SelectFromDb() )
        {
            return false;
        }
        m_vServices.push_back( service );
    }

    m_bitmap_ServiceShowed->SetBitmap( wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Service->Check( ID_VIEW_CURRENT_SERVICE, true );
    UpdateServiceList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowSearchedService()
{
    CRIRegistrySearchDlg dlg( this );
    if ( dlg.ShowModal() != wxID_OK )
    {
        return false;
    }
    
    wxString query;
    switch ( dlg.GetField() )
    {
    case NUM_SERVIZIO:
        query = wxString::Format( _T("SELECT %s FROM %s WHERE %s = %s AND (DATA > \'%s\' AND DATA <= \'%s\')"), 
                                  FIELD_ID, 
                                  TABLE_REGISTROSERVIZI, 
                                  FIELD_NUMSERVIZIO, 
                                  dlg.GetValue().c_str(), 
                                  dlg.GetDateStart().c_str(),
                                  dlg.GetDateEnd().c_str() );
        break;

    case NUM_SERVIZIO_SUP:
        query = wxString::Format( _T("SELECT %s FROM %s WHERE %s = %s AND (DATA > \'%s\' AND DATA <= \'%s\')"), 
                                  FIELD_ID, 
                                  TABLE_REGISTROSERVIZI, 
                                  FIELD_NUMSERVIZIOSUP, 
                                  dlg.GetValue().c_str(), 
                                  dlg.GetDateStart().c_str(),
                                  dlg.GetDateEnd().c_str() );
        break;

    case NUM_SCHEDA_118:
        query = wxString::Format( _T("SELECT %s FROM %s WHERE %s = %s AND (DATA > \'%s\' AND DATA <= \'%s\')"), 
                                  FIELD_ID, 
                                  TABLE_REGISTROSERVIZI, 
                                  FIELD_SCHEDA118, 
                                  ::SQLStringFormat( dlg.GetValue() ).c_str(), 
                                  dlg.GetDateStart().c_str(),
                                  dlg.GetDateEnd().c_str() );
        break;
    
    case NOMINATIVO_RICHIEDENTE:
        query = wxString::Format( _T("SELECT %s FROM %s WHERE %s LIKE %s AND (DATA > \'%s\' AND DATA <= \'%s\')"), 
                                  FIELD_ID, 
                                  TABLE_REGISTROSERVIZI, 
                                  FIELD_RICHIESTO_NOMINATIVO, 
                                  ::SQLStringFormat( dlg.GetValue() ).c_str(), 
                                  dlg.GetDateStart().c_str(),
                                  dlg.GetDateEnd().c_str() );
        break;

    case NOMINATIVO_PAZIENTE:
        query = wxString::Format( _T("SELECT DISTINCT(%s.%s_%s) FROM %s,%s WHERE %s.%s LIKE %s AND (%s.DATA > \'%s\' AND %s.DATA <= \'%s\')"), 
                                  TABLE_REGISTROSERVIZI_PAZIENTI, 
                                  TABLE_REGISTROSERVIZI,
                                  FIELD_ID, 
                                  TABLE_REGISTROSERVIZI_PAZIENTI, 
                                  TABLE_REGISTROSERVIZI,
                                  TABLE_REGISTROSERVIZI_PAZIENTI,
                                  FIELD_COGNOME, 
                                  ::SQLStringFormat( dlg.GetValue() + _T("%%") ).c_str(), 
                                  TABLE_REGISTROSERVIZI,
                                  dlg.GetDateStart().c_str(),
                                  TABLE_REGISTROSERVIZI,
                                  dlg.GetDateEnd().c_str() );
        break;

    case NOTE_SERVIZIO:
        query = wxString::Format( _T("SELECT %s FROM %s WHERE LENGTH(%s)>0 AND (DATA > \'%s\' AND DATA <= \'%s\')"), 
                                  FIELD_ID, 
                                  TABLE_REGISTROSERVIZI,
                                  FIELD_NOTE, 
                                  dlg.GetDateStart().c_str(),
                                  dlg.GetDateEnd().c_str() );
        break;

    case SQL_QUERY:
        query = wxString::Format( _T("SELECT %s FROM %s WHERE (%s) AND (DATA > \'%s\' AND DATA <= \'%s\')"), 
                                  FIELD_ID, 
                                  TABLE_REGISTROSERVIZI,
                                  dlg.GetValue().c_str(), 
                                  dlg.GetDateStart().c_str(),
                                  dlg.GetDateEnd().c_str() );
        break;

    default:
        return false;
    }

    query += wxString::Format( _T(" ORDER BY YEAR(%s),%s,%s"), FIELD_DATA, FIELD_NUMSERVIZIO, FIELD_NUMSERVIZIOSUP );
//  INFO_MESSAGE(query.c_str());

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }
/*
    if ( res.GetSize() == 0 ) 
    {
        return false;
    }
*/
    m_vServices.clear();

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CService service;
        service.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !service.SelectFromDb() )
        {
            return false;
        }
        m_vServices.push_back( service );
    }

    m_bitmap_ServiceShowed->SetBitmap( wxBitmap( wxT("Res/img_Search32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Service->Check( ID_VIEW_SEARCHED_SERVICE, true );
    UpdateServiceList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowAllService()
{
    CRIRegistrySelectDateRangeDlg dlg( this, _("Selezionare l'itervallo dei Servizi da Visualizzare") );
    if ( dlg.ShowModal() != wxID_OK )
    {
        return false;
    }

    wxDateTime start = dlg.GetDateStart();
    wxDateTime end = dlg.GetDateEnd();
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE %s>=\'%s\' AND %s<=\'%s\' ORDER BY YEAR(%s),%s,%s"), 
                                       FIELD_ID,
                                       TABLE_REGISTROSERVIZI,
                                       FIELD_DATA,
                                       start.FormatISODate().c_str(),
                                       FIELD_DATA,
                                       end.FormatISODate().c_str(),
                                       FIELD_DATA,
                                       FIELD_NUMSERVIZIO,
                                       FIELD_NUMSERVIZIOSUP);

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vServices.clear();

    m_ProgressDlg.Show();
    m_ProgressDlg.SetText( _("Lettura Servizi dal database in corso ...") );
    m_ProgressDlg.Update( 0 );
    m_ProgressDlg.SetMax( res.GetSize() ); 
    
    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CService service;
        service.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !service.SelectFromDb() )
        {
            return false;
        }
        m_vServices.push_back( service );
        m_ProgressDlg.Update( i );
    }
    m_ProgressDlg.Update( 100 );
    m_ProgressDlg.Close();

    m_bitmap_ServiceShowed->SetBitmap( wxBitmap( wxT("Res/img_Calendar32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Service->Check( ID_VIEW_ALL_SERVICE, true );
    UpdateServiceList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowCurrentComunication()
{
    wxDateTime start = wxDateTime::Now() - wxTimeSpan::Hours(24);
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE %s>='%s %s' OR %s=0 ORDER BY %s"), 
                                       FIELD_ID,
                                       TABLE_COMUNICAZIONI,
                                       FIELD_INSERITA,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_LETTA,
                                       FIELD_INSERITA);

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vComunications.clear();

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CComunication comunication;
        comunication.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !comunication.SelectFromDb() )
        {
            return false;
        }
        m_vComunications.push_back( comunication );
    }

    m_bitmap_ComunicationShowed->SetBitmap( wxBitmap( wxT("Res/img_Alarm32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Comunication->Check( ID_VIEW_CURRENT_COMUNICATION, true );
    UpdateComunicationList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryMainFrame::ShowAllComunication()
{
    CRIRegistrySelectDateRangeDlg dlg( this, _("Selezionare l'itervallo delle Comunicazioni da Visualizzare") );
    if ( dlg.ShowModal() != wxID_OK )
    {
        return false;
    }

    wxDateTime start = dlg.GetDateStart();
    wxDateTime end = dlg.GetDateEnd();
    wxString query = wxString::Format( _T("SELECT %s FROM %s WHERE %s>=\'%s %s\' AND %s<=\'%s %s\' ORDER BY %s"), 
                                       FIELD_ID,
                                       TABLE_COMUNICAZIONI,
                                       FIELD_INSERITA,
                                       start.FormatISODate().c_str(),
                                       start.FormatISOTime().c_str(),
                                       FIELD_INSERITA,
                                       end.FormatISODate().c_str(),
                                       end.FormatISOTime().c_str(),
                                       FIELD_INSERITA );

    dbResultSet res;
    if ( !dbSingleton::Instance()->SQLQuery( query, &res ) )
    {
        return false;
    }

    m_vComunications.clear();

    for ( size_t i = 0; i < res.GetSize(); i++ )
    {
        CComunication comunication;
        comunication.SetId( res.Row(i).Col(0).GetIntValue() );
        if ( !comunication.SelectFromDb() )
        {
            return false;            
        }
        m_vComunications.push_back( comunication );
    }

    m_bitmap_ComunicationShowed->SetBitmap( wxBitmap( wxT("Res/img_Calendar32x32.png"), wxBITMAP_TYPE_ANY ) );
    m_menu_Comunication->Check( ID_VIEW_ALL_COMUNICATION, true );
    UpdateComunicationList();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::UpdatePresenceList()
{
    std::vector<CPresence>::const_iterator PresenceSelected = GetPresenceSelected();
    
    m_list_Presence->Freeze();
    m_list_Presence->DeleteAllItems();

    for ( std::vector<CPresence>::iterator it = m_vPresences.begin(); it != m_vPresences.end(); ++it )
    {
        CPresence p(*it);
        long i = m_list_Presence->GetItemCount();
        m_list_Presence->InsertItem( i, p[FIELD_GRUPPO].GetStringValue() );
        m_list_Presence->SetItem( i, 1, p[FIELD_COGNOME].GetStringValue() );
        m_list_Presence->SetItem( i, 2, p[FIELD_NOME].GetStringValue() );
        m_list_Presence->SetItem( i, 3, p[FIELD_DATAORAINIZIO].GetDateTimeValue() == EmptyDate ? _T("") : p[FIELD_DATAORAINIZIO].GetDateTimeValue().Format(FORMAT_DATE_TIME) );
        m_list_Presence->SetItem( i, 4, p[FIELD_DATAORAFINE].GetDateTimeValue() == EmptyDate ? _T("") : p[FIELD_DATAORAFINE].GetDateTimeValue().Format(FORMAT_DATE_TIME) );
        m_list_Presence->SetItem( i, 5, p[FIELD_NOTE].GetStringValue() );
        m_list_Presence->SetItemData( i, p.GetId() );
        
        if ( i % 2 )
        {
            m_list_Presence->SetItemBackgroundColour( i, wxColor(240,240,240) );
        }
    }

    if ( PresenceSelected != m_vPresences.end() )
    {
        SetPresenceSelected( *PresenceSelected );
    }

    m_list_Presence->Thaw();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::UpdateShiftList()
{
    std::vector<CShift>::const_iterator ShiftSelected = GetShiftSelected();
    
    m_list_Shift->Freeze();
    m_list_Shift->DeleteAllItems();

    long ItemToShow = -1;
    for ( std::vector<CShift>::iterator it = m_vShifts.begin(); it != m_vShifts.end(); ++it )
    {
        CShift s(*it);
        long i = m_list_Shift->GetItemCount();
        
        m_list_Shift->InsertItem( i, s[FIELD_GRUPPO].GetStringValue() );
        m_list_Shift->SetItemImage( i, s[FIELD_CODMEZZO].GetStringValue().IsEmpty() ? -1 : 0 );
        m_list_Shift->SetItem( i, 1, s[FIELD_DATAORAINIZIO].GetDateTimeValue().Format(FORMAT_DATE_TIME) );
        m_list_Shift->SetItem( i, 2, s[FIELD_DATAORAFINE].GetDateTimeValue().Format(FORMAT_DATE_TIME) );
        m_list_Shift->SetItem( i, 3, s[FIELD_TIPO].GetStringValue() );
        m_list_Shift->SetItem( i, 4, s[FIELD_CODMEZZO].GetStringValue() );
        m_list_Shift->SetItem( i, 5, s[FIELD_COGNOME].GetStringValue() );
        m_list_Shift->SetItem( i, 6, s[FIELD_NOME].GetStringValue() );
        m_list_Shift->SetItem( i, 7, s[FIELD_QUALIFICA].GetStringValue() + _T(" ") + s[FIELD_QUALIFICASTATO].GetStringValue() );
        m_list_Shift->SetItemData( i, s.GetId() );
        
        if ( i % 2 )
        {
            m_list_Shift->SetItemBackgroundColour( i, wxColor(240,240,240) );
        }

        // Plus color
        wxDateTime now(wxDateTime::Now());
        wxDateTime start(s[FIELD_DATAORAINIZIO].GetDateTimeValue());
        wxDateTime limit1(s[FIELD_DATAORAFINE].GetDateTimeValue() - wxTimeSpan::Hours(1));
        wxDateTime limit2(s[FIELD_DATAORAFINE].GetDateTimeValue() - wxTimeSpan::Minutes(30));
        wxDateTime end(s[FIELD_DATAORAFINE].GetDateTimeValue());
        if ( now >= start && now <= limit1 )
        {
            m_list_Shift->SetItemBackgroundColour( i, wxColor(37,252,37) );
            if ( ItemToShow < 0 )
            {
                ItemToShow = i;
            }
        }
        else if ( now >= start && now >= limit1 && now <= limit2 )
        {
            m_list_Shift->SetItemBackgroundColour( i, wxColor(252,187,37) );
            if ( ItemToShow < 0 )
            {
                ItemToShow = i;
            }
        }
        else if ( now >= start && now >= limit2 && now <= end )
        {
            m_list_Shift->SetItemBackgroundColour( i, wxColor(252,37,37) );
            if ( ItemToShow < 0 )
            {
                ItemToShow = i;
            }
        }
    }

    if ( ShiftSelected != m_vShifts.end() )
    {
        SetShiftSelected( *ShiftSelected );
    }
    else
    {
        m_list_Shift->EnsureVisible( ItemToShow );
    }

    m_list_Shift->Thaw();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::UpdateServiceList()
{
    std::vector<CService>::const_iterator ServiceSelected = GetServiceSelected();

    m_list_Service->Freeze();
    m_list_Service->DeleteAllItems();

    for ( std::vector<CService>::iterator it = m_vServices.begin(); it != m_vServices.end(); ++it )
    {
        CService s(*it);
        long i = m_list_Service->GetItemCount();        
        m_list_Service->InsertItem( i, s[FIELD_GRUPPO].GetStringValue() );
        m_list_Service->SetItem( i, 1, wxString::Format( _T("%06d/%06d"), s[FIELD_NUMSERVIZIO].GetIntValue(), s[FIELD_NUMSERVIZIOSUP].GetIntValue() ) );
        m_list_Service->SetItem( i, 2, s[FIELD_DATA].GetDateTimeValue().Format(FORMAT_DATE_EXTENDED) );

        if ( s[FIELD_RICHIESTO].GetStringValue() == szRequestedBy[REQUESTED_BY_118] )
        {
            m_list_Service->SetItem( i, 3, wxString::Format( _T("118-%s"), s[FIELD_SCHEDA118].GetCharValue() ));
        }
        else
        {
            if ( s[FIELD_TIPO].GetStringValue() == OTHER_SELECTION )
            {
                m_list_Service->SetItem( i, 3, wxString::Format( _T("%s - %s"), s[FIELD_RICHIESTO].GetCharValue(), (s[FIELD_ALTRO_TIPO].GetStringValue().IsEmpty() ? OTHER_SELECTION : s[FIELD_ALTRO_TIPO].GetCharValue()) ));
            }
            else
            {
                m_list_Service->SetItem( i, 3, wxString::Format( _T("%s - %s"), s[FIELD_RICHIESTO].GetCharValue(), s[FIELD_TIPO].GetCharValue() ));
            }
        }
        m_list_Service->SetItem( i, 4, s[FIELD_ORAINIZIO].GetDateTimeValue() == EmptyDate ? 
                                _T("") : 
                                s[FIELD_ORAINIZIO].GetDateTimeValue().Format(FORMAT_TIME) );
        m_list_Service->SetItem( i, 5, s[FIELD_ORAFINE].GetDateTimeValue() == EmptyDate ? 
                                _T("") : 
                                s[FIELD_ORAFINE].GetDateTimeValue().Format(FORMAT_TIME) );
        m_list_Service->SetItem( i, 6, s[FIELD_CODMEZZO].GetStringValue() );
        m_list_Service->SetItemPtrData( i, s.GetId() );

        wxListItem info;
        info.SetId( i );
        info.SetColumn( 7 );
        info.SetImage( s[FIELD_NOTE].GetStringValue().IsEmpty() ? -1 : 1 );
        if ( s[FIELD_ANNULLATO].GetBoolValue() )
        {
            info.SetText( _("ANNULATO") );
            m_list_Service->SetItemImage( i, 2 );
        }
        else
        {
            if  ( s[FIELD_CHIUSO].GetBoolValue() )
            {
                info.SetText( _("CHIUSO") );
                m_list_Service->SetItemImage( i, -1 );
            }
            else
            {
                info.SetText( _("APERTO") );
                m_list_Service->SetItemImage( i, 0 );
            }
        }
        m_list_Service->SetItem( info );

        if ( i % 2 )
        {
            m_list_Service->SetItemBackgroundColour( i, wxColor(240,240,240) );
        }       
    }

    if ( ServiceSelected != m_vServices.end() )
    {
        SetServiceSelected( *ServiceSelected );
    }
    else
    {
        m_list_Service->EnsureVisible( m_list_Service->GetItemCount() - 1 );
    }

    m_list_Service->Thaw();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::UpdateComunicationList()
{
    std::vector<CComunication>::const_iterator ComunicationSelected = GetComunicationSelected();

    m_list_Comunication->Freeze();
    m_list_Comunication->DeleteAllItems();

    for ( std::vector<CComunication>::iterator it = m_vComunications.begin(); it != m_vComunications.end(); ++it )
    {
        CComunication c(*it);
        long i = m_list_Comunication->GetItemCount();   
        m_list_Comunication->InsertItem( i, c[FIELD_GRUPPO].GetStringValue() );
        m_list_Comunication->SetItem( i, 1, c[FIELD_INSERITA].GetDateTimeValue().Format(FORMAT_DATE_TIME_EXTENDED) );
        m_list_Comunication->SetItem( i, 2, c[FIELD_MITTENTE].GetStringValue() );
        m_list_Comunication->SetItem( i, 3, c[FIELD_DESTINATARIO].GetStringValue() );
        m_list_Comunication->SetItem( i, 4, c[FIELD_OGGETTO].GetStringValue() );
        m_list_Comunication->SetItemPtrData( i, c.GetId() );
        m_list_Comunication->SetItemImage( i, c[FIELD_LETTA].GetBoolValue() ? -1 : 0 );

        if ( i % 2 )
        {
            m_list_Comunication->SetItemBackgroundColour( i, wxColor(240,240,240) );
        }       
    }

    if ( ComunicationSelected != m_vComunications.end() )
    {
        SetComunicationSelected( *ComunicationSelected );
    }
    else
    {
        m_list_Comunication->EnsureVisible( m_list_Comunication->GetItemCount() - 1 );
    }

    m_list_Comunication->Thaw();
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
long CRIRegistryMainFrame::GetPresenceItemSelected()
{
    for ( long i = 0; i < m_list_Presence->GetItemCount(); i++ )
    {
        if ( m_list_Presence->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
            return i;
        }
    }

    return -1;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
std::vector<CPresence>::iterator CRIRegistryMainFrame::GetPresenceSelected()
{
    std::vector<CPresence>::iterator it = m_vPresences.end();
    long item = GetPresenceItemSelected();
    if ( item < 0 )
    {
        return it;
    }

    for ( it = m_vPresences.begin(); it != m_vPresences.end(); ++it )
    {
        if ( m_list_Presence->GetItemData( item ) == it->GetId() )
        {
            break;
        }
    }

    return it;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::SetPresenceSelected( const CPresence& s )
{
    for ( long i = 0; i < m_list_Presence->GetItemCount(); i++ )
    {
        if ( m_list_Presence->GetItemData( i ) == s.GetId() )
        {
            m_list_Presence->SetFocus();
            m_list_Presence->SetItemState( i, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED );
            m_list_Presence->SetItemState( i, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED );
            m_list_Presence->EnsureVisible( i );
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
long CRIRegistryMainFrame::GetShiftItemSelected()
{
    for ( long i = 0; i < m_list_Shift->GetItemCount(); i++ )
    {
        if ( m_list_Shift->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
            return i;
        }
    }

    return -1;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
std::vector<CShift>::iterator CRIRegistryMainFrame::GetShiftSelected()
{
    std::vector<CShift>::iterator it = m_vShifts.end();
    long item = GetShiftItemSelected();
    if ( item < 0 )
    {
        return it;
    }

    for ( it = m_vShifts.begin(); it != m_vShifts.end(); ++it )
    {
        if ( m_list_Shift->GetItemData( item ) == it->GetId() )
        {
            break;
        }
    }

    return it;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::SetShiftSelected( const CShift& s )
{
    for ( long i = 0; i < m_list_Shift->GetItemCount(); i++ )
    {
        if ( m_list_Shift->GetItemData( i ) == s.GetId() )
        {
            m_list_Shift->SetFocus();
            m_list_Shift->SetItemState( i, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED );
            m_list_Shift->SetItemState( i, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED );
            m_list_Shift->EnsureVisible( i );
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
long CRIRegistryMainFrame::GetServiceItemSelected()
{
    for ( long i = 0; i < m_list_Service->GetItemCount(); i++ )
    {
        if ( m_list_Service->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
            return i;
        }
    }

    return -1;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
std::vector<CService>::iterator CRIRegistryMainFrame::GetServiceSelected()
{
    std::vector<CService>::iterator it = m_vServices.end();
    long item = GetServiceItemSelected();
    if ( item < 0 )
    {
        return it;
    }

    for ( it = m_vServices.begin(); it != m_vServices.end(); ++it )
    {
        if ( m_list_Service->GetItemData( item ) == it->GetId() )
        {
            break;
        }
    }

    return it;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::SetServiceSelected( const CService& s )
{
    for ( long i = 0; i < m_list_Service->GetItemCount(); i++ )
    {
        if ( m_list_Service->GetItemData( i ) == s.GetId() )
        {
            m_list_Service->SetFocus();
            m_list_Service->SetItemState( i, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED );
            m_list_Service->SetItemState( i, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED );
            m_list_Service->EnsureVisible( i );
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
long CRIRegistryMainFrame::GetComunicationItemSelected()
{
    for ( long i = 0; i < m_list_Comunication->GetItemCount(); i++ )
    {
        if ( m_list_Comunication->GetItemState( i, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
        {
            return i;
        }
    }

    return -1;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
std::vector<CComunication>::iterator CRIRegistryMainFrame::GetComunicationSelected()
{
    std::vector<CComunication>::iterator it = m_vComunications.end();
    long item = GetComunicationItemSelected();
    if ( item < 0 )
    {
        return it;
    }

    for ( it = m_vComunications.begin(); it != m_vComunications.end(); ++it )
    {
        if ( m_list_Comunication->GetItemData( item ) == it->GetId() )
        {
            break;
        }
    }

    return it;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryMainFrame::SetComunicationSelected( const CComunication& c )
{
    for ( long i = 0; i < m_list_Comunication->GetItemCount(); i++ )
    {
        if ( m_list_Comunication->GetItemData( i ) == c.GetId() )
        {
            m_list_Comunication->SetFocus();
            m_list_Comunication->SetItemState( i, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED );
            m_list_Comunication->SetItemState( i, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED );
            m_list_Comunication->EnsureVisible( i );
            break;
        }
    }
}


/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryMainFrame::AuthenticateUser()
{
    CUser user = UsersManager::Instance()->GetUserLogged();
    wxString title;
    if ( user.GetName().IsEmpty() )
    {
        title = wxString::Format( _("%s %s"), PRODUCTNAME, VERSION );
        m_bpButton_SelectUser->SetBitmapLabel( wxBitmap( wxT("Res/bp_Users_Disconnect.png"), wxBITMAP_TYPE_ANY ) );

    }
    else
    {
        title = wxString::Format( _("%s %s [Utente: %s]"), PRODUCTNAME, VERSION, user.GetName().c_str() );
        m_bpButton_SelectUser->SetBitmapLabel( wxBitmap( wxT("Res/bp_Users_Connect.png"), wxBITMAP_TYPE_ANY ) );
    }
    SetTitle( title );

    m_menu_File->Enable( ID_SQL_QUERY, user.GetPrivileges() >= RESP_CENTR );

    m_menu_Config->Enable( ID_OPTIONS, user.GetPrivileges() >= RESP_CENTR );
    
    m_menu_Presence->Enable( ID_PRESENCE_IN, user.GetPrivileges() >= USER );
    m_menu_Presence->Enable( ID_PRESENCE_OUT, user.GetPrivileges() >= USER );
    m_menu_Presence->Enable( ID_MODIFY_PRESENCE, user.GetPrivileges() >= RESP_CENTR );
    m_menu_Presence->Enable( ID_DEL_PRESENCE, user.GetPrivileges() >= RESP_CENTR );
    m_menu_Presence->Enable( ID_VIEW_CURRENT_PRESENCE, user.GetPrivileges() >= USER );
    m_menu_Presence->Enable( ID_VIEW_ALL_PRESENCE, user.GetPrivileges() >= USER );
    m_menu_Presence->Check( ID_VIEW_CURRENT_PRESENCE, true );

    m_menu_Shift->Enable( ID_ADD_CREW, user.GetPrivileges() >= USER );
    m_menu_Shift->Enable( ID_ADD_SHIFT, user.GetPrivileges() >= USER );
    m_menu_Shift->Enable( ID_DEL_SHIFT, user.GetPrivileges() >= USER );
    m_menu_Shift->Enable( ID_MODIFY_SHIFT, user.GetPrivileges() >= USER );
    m_menu_Shift->Enable( ID_VIEW_CURRENT_SHIFT, user.GetPrivileges() >= USER );
    m_menu_Shift->Enable( ID_VIEW_ALL_SHIFT, user.GetPrivileges() >= USER );
    m_menu_Shift->Check( ID_VIEW_CURRENT_SHIFT, true );
    m_menu_Shift->Enable( ID_IMPORT_SHIFT, user.GetPrivileges() == ADMINISTRATOR );
    m_menu_Shift->Enable( ID_EXPORT_SHIFT, user.GetPrivileges() == ADMINISTRATOR );

    m_menu_Service->Enable( ID_ADD_SERVICE, user.GetPrivileges() >= CENTRALINO );
    m_menu_Service->Enable( ID_DEL_SERVICE, user.GetPrivileges() >= CENTRALINO );
    m_menu_Service->Enable( ID_MODIFY_SERVICE, user.GetPrivileges() >= USER );
    m_menu_Service->Enable( ID_VIEW_CURRENT_SERVICE, user.GetPrivileges() >= USER );
    m_menu_Service->Enable( ID_VIEW_SEARCHED_SERVICE, user.GetPrivileges() >= USER );
    m_menu_Service->Enable( ID_VIEW_ALL_SERVICE, user.GetPrivileges() >= USER );
    m_menu_Service->Check( ID_VIEW_CURRENT_SERVICE, true );
    m_menu_Service->Enable( ID_IMPORT_SERVICE, user.GetPrivileges() == ADMINISTRATOR );
    m_menu_Service->Enable( ID_EXPORT_SERVICE, user.GetPrivileges() == ADMINISTRATOR );

    m_menu_Users->Enable( ID_USER_LOGOUT, UsersManager::Instance()->IsUserLogged() );
    m_menu_Users->Enable( ID_CHANGE_USER_PWD, user.GetPrivileges() >= USER );
    m_menu_Users->Enable( ID_USERS_MANAGER, user.GetPrivileges() >= RESP_CENTR );

    m_menu_Data->Enable( ID_OPEN_FLEET, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_GROUP, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_HOSPITAL, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_SERVICE_TYPE, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_118_SERVICE_TYPE, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_INTERNAL_SERVICE_TYPE, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_SHIFT_TYPE, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_VEHICLE_TYPE, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_REASONS_REFUSING_TRANSPORT, user.GetPrivileges() > CENTRALINO );
    m_menu_Data->Enable( ID_OPEN_MAILING_LIST, user.GetPrivileges() > CENTRALINO );

    m_menu_Comunication->Enable( ID_ADD_COMUNICATION, user.GetPrivileges() >= USER );
    m_menu_Comunication->Enable( ID_DEL_COMUNICATION, user.GetPrivileges() >= USER );
    m_menu_Comunication->Enable( ID_MODIFY_COMUNICATION, user.GetPrivileges() >= USER );
    m_menu_Comunication->Enable( ID_VIEW_CURRENT_COMUNICATION, user.GetPrivileges() >= USER );
    m_menu_Comunication->Enable( ID_VIEW_ALL_COMUNICATION, user.GetPrivileges() >= USER );
    m_menu_Comunication->Check( ID_VIEW_CURRENT_COMUNICATION, true );

    m_bpButton_PresenceIn->Enable( user.GetPrivileges() >= USER );
    m_bpButton_PresenceOut->Enable( user.GetPrivileges() >= USER );
    m_bpButton_ModifyPresence->Enable( user.GetPrivileges() >= RESP_CENTR );
    m_bpButton_DelPresence->Enable( user.GetPrivileges() >= RESP_CENTR );

    m_bpButton_AddCrew->Enable( user.GetPrivileges() >= USER );
    m_bpButton_AddShift->Enable( user.GetPrivileges() >= USER );
    m_bpButton_DelShift->Enable( user.GetPrivileges() >= USER );
    m_bpButton_ModifyShift->Enable( user.GetPrivileges() >= USER );

    m_bpButton_AddService->Enable( user.GetPrivileges() >= CENTRALINO );
    m_bpButton_DelService->Enable( user.GetPrivileges() >= CENTRALINO );
    m_bpButton_ModifyService->Enable( user.GetPrivileges() >= USER );

    m_bpButton_AddComunication->Enable( user.GetPrivileges() >= CENTRALINO );
    m_bpButton_DelComunication->Enable( user.GetPrivileges() >= CENTRALINO );
    m_bpButton_ModifyComunication->Enable( user.GetPrivileges() >= USER );

    ShowCurrentPresence();
    ShowCurrentShift();
    ShowCurrentService();
    ShowCurrentComunication();
}

/////////////////////////////////////////////////////////////////////////////
//
//
void CRIRegistryMainFrame::LogInUser()
{
    __SINCRONIZE_TIMER__

    UsersManager::Instance()->LogIn();
    AuthenticateUser();
}