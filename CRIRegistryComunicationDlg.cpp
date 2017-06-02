#include "CRIRegistryComunicationDlg.h"

/////////////////////////////////////////////////////////////////////////////
// 
//
CRIRegistryComunicationDlg::CRIRegistryComunicationDlg( wxWindow* parent, const CComunication& c, eMode mode ):
ComunicationDlg( parent ), m_Comunication( c ), m_Mode( mode )
{
    SetIcon( wxICON(ComunicationIcon) );

    wxString query;
	dbResultSet res;

    m_Gruppo->Clear();
    m_Gruppo->Append( _T("") );
	query = wxString::Format( _T("SELECT %s FROM %s"), FIELD_GRUPPO, TABLE_GRUPPI );
	wxArrayString aszGruppi = dbSingleton::Instance()->SQLGetColArray( query );
    m_Gruppo->Append( aszGruppi );

    m_ComunicazioneTo->Clear();
    m_ComunicazioneTo->AppendString( _T("CENTRALINO") );
    query = wxString::Format( _T("SELECT * FROM %s ORDER BY %s"), TABLE_MAILING_LIST, FIELD_NOME );
	if ( dbSingleton::Instance()->SQLQuery( query, &res ) )
	{
		for ( size_t i = 0; i < res.GetSize(); i++ )
		{
			dbClass f( res.Row(i), TABLE_MAILING_LIST, FIELD_ID );
			m_MailingList.push_back(f);
            m_ComunicazioneTo->AppendString( f.GetField(FIELD_NOME).GetStringValue() );
		}
	}

    UpdateCtrl();

    m_Gruppo->Enable( m_Mode != READ_ONLY );
    m_ComunicazioneDa->Enable( m_Mode != READ_ONLY );
	m_ComunicazioneTo->Enable( m_Mode != READ_ONLY );
    m_Oggetto->Enable( m_Mode != READ_ONLY );
    m_Note->Enable( m_Mode != READ_ONLY );

    m_ComunicazioneTo->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryComunicationDlg::OnClose( wxCloseEvent& event )
{
    event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryComunicationDlg::OnExitCtrl( wxFocusEvent& event )
{
    switch ( event.GetId() )
    {
	case ID_OGGETTO:
		m_Oggetto->SetValue( m_Oggetto->GetValue().Upper() );
        break;

	case ID_COMUNICAZIONE:
		m_Note->SetValue( m_Note->GetValue().Upper() );
        break;
    }

	event.Skip();
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryComunicationDlg::OnOk( wxCommandEvent& event )
{
    if ( !UpdateData() )
    {
        return;
    }

    if ( NeedToSendEmail() && !m_Letta->GetValue() )
    {
        m_Comunication[FIELD_LETTA] = SendMail();
    }

    EndModal( wxID_OK );
}

/////////////////////////////////////////////////////////////////////////////
// 
//
void CRIRegistryComunicationDlg::OnCancel( wxCommandEvent& event )
{
    EndModal( wxID_CANCEL );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
void CRIRegistryComunicationDlg::UpdateCtrl()
{
    m_Gruppo->SetStringSelection( m_Comunication[FIELD_GRUPPO].GetStringValue() );
    m_ComunicazioneDa->SetValue( m_Comunication[FIELD_MITTENTE].GetStringValue() );
    m_ComunicazioneTo->SetStringSelection( m_Comunication[FIELD_DESTINATARIO].GetStringValue() );
    m_Oggetto->SetValue( m_Comunication[FIELD_OGGETTO].GetStringValue() );
    m_Note->SetValue( m_Comunication[FIELD_TESTO].GetStringValue() );
    m_Letta->SetValue( m_Comunication[FIELD_LETTA].GetBoolValue() );
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryComunicationDlg::UpdateData()
{
    if ( m_Mode == READ_ONLY )
    {
        return true;
    }

    if ( m_Gruppo->GetStringSelection().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il gruppo") );
        m_Gruppo->SetFocus();
        return false;
    }

    if ( m_ComunicazioneTo->GetStringSelection().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito il destinatario") );
        m_ComunicazioneTo->SetFocus();
        return false;
    }

    if ( m_Oggetto->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stato inserito l'oggetto della comunicazione") );
        m_Oggetto->SetFocus();
        return false;
    }

    if ( m_Note->GetValue().IsEmpty() )
    {
        WARNING_MESSAGE( _("Non e' stata inserita la comunicazione") );
        m_Note->SetFocus();
        return false;
    }

    m_Comunication[FIELD_GRUPPO] = m_Gruppo->GetStringSelection();
    m_Comunication[FIELD_OGGETTO] = m_Oggetto->GetValue();
    m_Comunication[FIELD_DESTINATARIO] = m_ComunicazioneTo->GetStringSelection();
    m_Comunication[FIELD_TESTO] = m_Note->GetValue();
    m_Comunication[FIELD_LETTA] = m_Letta->GetValue();
    m_Comunication[FIELD_PRIVATA] = NeedToSendEmail();
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryComunicationDlg::NeedToSendEmail()
{
    for ( std::vector<dbClass>::iterator it = m_MailingList.begin(); it != m_MailingList.end(); ++it )
    {
        if ( m_ComunicazioneTo->GetStringSelection() == it->GetField(FIELD_NOME).GetStringValue() )
        {
            return true;
        }
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
wxArrayString CRIRegistryComunicationDlg::GetMailAddress()
{
    wxArrayString a;
    wxString addr;

    for ( std::vector<dbClass>::iterator it = m_MailingList.begin(); it != m_MailingList.end(); ++it )
    {
        if ( m_ComunicazioneTo->GetStringSelection() == it->GetField(FIELD_NOME).GetStringValue() )
        {
            addr = it->GetField(FIELD_EMAIL).GetStringValue();
        }
    }

    wxStringTokenizer tkz( addr, _T(";") );
    while ( tkz.HasMoreTokens() )
    {
        addr = tkz.GetNextToken();
        a.Add( addr );
    }

    return a;
}

/////////////////////////////////////////////////////////////////////////////
// 
// 
bool CRIRegistryComunicationDlg::SendMail()
{
	bool bError = false;
    wxArrayString to = GetMailAddress();
	try
	{
		CSmtp mail;

        mail.SetCharSet( _T("iso-8859-1") );
        mail.SetSMTPServer( _T("smtps.aruba.it"), 465 );
        mail.SetSecurityType( USE_SSL );
        mail.SetLogin( _T("gaspare.faraci@cririvoli.it") );
        mail.SetPassword( _T("gfrgfr77") );
        mail.SetSenderName( _("Centralino C.R.I.") );
        mail.SetSenderMail( _T("noreply@cririvoli.it") );
        mail.SetSubject( m_Comunication[FIELD_OGGETTO].GetCharValue() );
        for ( size_t i = 0; i < to.Count(); i++ )
        {
            mail.AddRecipient( to[i].c_str() );
        }
        mail.SetXPriority( XPRIORITY_HIGH );
        mail.SetXMailer( PRODUCTNAME );
        mail.AddMsgLine( m_Comunication[FIELD_TESTO].GetCharValue() );
        mail.AddMsgLine( m_Comunication[FIELD_MITTENTE].GetCharValue() );
        mail.AddMsgLine( _("") );
        mail.AddMsgLine( _("") );
        mail.AddMsgLine( _("NB:") );
        mail.AddMsgLine( _("Questo messaggio e’ stato creato con un sistema automatico,") );
        mail.AddMsgLine( _("non rispondere a questo indirizzo e-mail.") );
        wxBusyInfo busy( _("Invio messaggio email in corso ..."), this );
		mail.Send();
        INFO_MESSAGE( _("Il messaggio e' stato inviato") );
	}
	catch(ECSmtp e)
	{
		ERROR_MESSAGE( _T("%s"), e.GetErrorText().c_str() );
		bError = true;
	}

    return !bError;
}
