#include "CRIRegistryCheckListDlg.h"

// ============================================================================
// CItem
// ============================================================================
/////////////////////////////////////////////////////////////////////////////
// 
//
CItem::CItem( wxWindow* parent, int id, const wxString& name ) : wxBoxSizer( wxHORIZONTAL )
{
    m_Id = id;
    m_Name = new wxCheckBox( parent, wxID_ANY, name, wxDefaultPosition, wxDefaultSize, 0 );
    this->Add( m_Name, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 ); 
    m_txtNote = new wxTextCtrl( parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 )/*, wxTE_MULTILINE*/ );
	this->Add( m_txtNote, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
}   

/////////////////////////////////////////////////////////////////////////////
// 
//
void CItem::Set( bool checked, const wxString& note )
{
    m_Name->SetValue(checked);
    m_txtNote->SetValue(note);

    m_Checked = checked;
    m_Note = note;
}

/////////////////////////////////////////////////////////////////////////////
// 
//
bool CItem::IsChanged()
{
    if ( m_Name->IsChecked() != m_Checked )
    {
        return true;
    }
    if ( m_txtNote->GetValue() != m_Note)
    {
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////
// 
//
bool CItem::IsChecked()
{
    return m_Name->IsChecked();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CItem::Update()
{
    if ( IsChanged() )
    {
        wxString query = wxString::Format(_T("UPDATE %s SET %s=%d, %s=%s, %s=%s WHERE %s=%d"), 
            TABLE_CHECK_LIST,
            FIELD_VERIFICATO, m_Name->IsChecked() ? 1 : 0,
            FIELD_NOTE, ::SQLStringFormat(m_txtNote->GetValue()).c_str(),
            FIELD_VOLONTARIO, ::SQLStringFormat(UsersManager::Instance()->GetUserLogged().GetFullName()).c_str(),
            FIELD_ID, m_Id
        );
        dbSingleton::Instance()->SQLQuery(query);
    }
}

// ============================================================================
// CPosition
// ============================================================================
/////////////////////////////////////////////////////////////////////////////
// 
//
CPosition::CPosition( wxWindow* parent, const wxString& name ) : wxStaticBoxSizer(new wxStaticBox( parent, wxID_ANY, name ), wxVERTICAL )
{
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CPosition::AddItem( CItem* item )
{
    this->Add( (wxBoxSizer*)item, 0, wxEXPAND, 5 );
    m_Items.push_back(item);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CPosition::UpdateItems()
{
    for ( int i = 0; i < m_Items.size(); i++ )
    {
        m_Items[i]->Update();
    }
}

/////////////////////////////////////////////////////////////////////////////
// 
//
bool CPosition::IsChecked()
{
    for ( int i = 0; i < m_Items.size(); i++ )
    {
        if ( !m_Items[i]->IsChecked() )
        {
            return false;
        }
    }
    return true;
}

// ============================================================================
// CheckListDlg
// ============================================================================
/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryCheckListDlg::CRIRegistryCheckListDlg( wxWindow* parent, const wxString& type ):
CheckListDlg( parent )
{
    SetIcon( wxICON(CheckListIcon) );
    
    wxString query;
    dbResultSet res;

    query = wxString::Format(_T("SELECT * FROM %s WHERE %s=%s AND %s='%s' AND DATE(Now())=DATE(%s) AND TIME(Now())>=%s AND TIME(Now())<=%s ORDER BY %s, %s"),
        TABLE_CHECK_LIST,
        FIELD_GRUPPO, ::SQLStringFormat(CRIRegistryOptions::Instance()->GetDefaultGruppo()).c_str(),
        FIELD_TIPO, type.c_str(),
        FIELD_DATA,
        FIELD_INIZIO,
        FIELD_FINE,
        FIELD_POSIZIONE,
        FIELD_NOME
        );
    dbSingleton::Instance()->SQLQuery(query, &res);

    m_Data->SetValue(res.Row(0).Col(FIELD_DATA).GetDateTimeValue().Format(FORMAT_DATE));
    m_Turno->SetValue(res.Row(0).Col(FIELD_TURNO).GetStringValue());
    m_Gruppo->SetValue(res.Row(0).Col(FIELD_GRUPPO).GetStringValue());

    wxString lastPosition = wxEmptyString;
	CPosition* position = 0;
    for (int i = 0; i < res.GetSize(); i++)
    {        
        if ( !position || ( lastPosition != res.Row(i).Col(FIELD_POSIZIONE).GetStringValue() ))
        {
	        position = new CPosition( m_ScrolledWindow, res.Row(i).Col(FIELD_POSIZIONE).GetStringValue() );
            m_Container->Add( position, 0, wxEXPAND|wxALL, 10 );
            m_Positions.push_back(position);
        }
        lastPosition = res.Row(i).Col(FIELD_POSIZIONE).GetStringValue();
        CItem* item = new CItem( m_ScrolledWindow, res.Row(i).Col(FIELD_ID).GetIntValue(), res.Row(i).Col(FIELD_NOME).GetStringValue());
        item->Set(res.Row(i).Col(FIELD_VERIFICATO).GetBoolValue(), res.Row(i).Col(FIELD_NOTE).GetStringValue());
	    position->AddItem( item );
    }
	m_ScrolledWindow->SetSizer( m_Container );
	m_ScrolledWindow->Layout();
	m_Container->Fit( m_ScrolledWindow );

    this->Layout();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListDlg::OnOk( wxCommandEvent& event )
{    
    for (int i = 0; i < m_Positions.size(); i++)
    {
        if (m_Positions[i]->IsChecked())
        {
            m_Positions[i]->UpdateItems();
        }
        else
        {
            WARNING_MESSAGE(_("Non hai completato la check-list"));
            return;
        }
    }
    EndModal(wxID_OK);
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryCheckListDlg::OnCancel( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}
