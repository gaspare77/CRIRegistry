#ifndef _CRIREGISTRYCONSTANTS_
#define _CRIREGISTRYCONSTANTS_

#include "wx/intl.h"

// ================================================================================
// DataBase Tables
#define TABLE_REGISTROPRESENZE              _T("RegistroPresenze")
#define TABLE_REGISTROTURNI                 _T("RegistroTurni")
#define TABLE_REGISTROSERVIZI               _T("RegistroServizi")
#define TABLE_REGISTROSERVIZI_EQUIPAGGI     _T("RegistroServizi_Equipaggi")
#define TABLE_REGISTROSERVIZI_PAZIENTI      _T("RegistroServizi_Pazienti")
#define TABLE_REGISTROSERVIZI_PRESTAZIONI   _T("RegistroServizi_Pazienti_Prestazioni")
#define TABLE_REGISTROSERVIZI_DINAMICHE     _T("RegistroServizi_Pazienti_Dinamiche")
#define TABLE_CODICI_GRAVITA                _T("CodiciGravita")
#define TABLE_CODICI_PATOLOGIA_PRESUNTA     _T("CodiciPatologiaPresunta")
#define TABLE_CODICI_PATOLOGIA_RISCONTRATA  _T("CodiciPatologiaRiscontrata")
#define TABLE_CODICI_LUOGO                  _T("CodiciLuogo")
#define TABLE_CODICI_DINAMICA_RISCONTRATA   _T("CodiciDinamicaRiscontrata")
#define TABLE_CODICI_PRESTAZIONE            _T("CodiciPrestazione")
#define TABLE_PARCOMACCHINE                 _T("ParcoMacchine")
#define TABLE_OSPEDALI                      _T("Ospedali")
#define TABLE_GRUPPI                        _T("Gruppi")
#define TABLE_TIPOLIGIASERVIZI_118          _T("TipologiaServizi118")
#define TABLE_TIPOLIGIASERVIZI_ORDINARI     _T("TipologiaServiziOrdinari")
#define TABLE_TIPOLIGIASERVIZI_INTERNI      _T("TipologiaServiziInterni")
#define TABLE_TIPOLOGIATURNI                _T("TipologiaTurni")
#define TABLE_TIPOLOGIAMEZZI                _T("TipologiaMezzi")
#define TABLE_MOTIVIRIFIUTATRASPORTO        _T("MotivazioniRifiutaTrasporto")
#define TABLE_USERS                         _T("Users")
#define TABLE_QUERY_LIST                    _T("QueryList")
#define TABLE_LOCK                          _T("Table_Lock")
#define TABLE_COMUNICAZIONI                 _T("Comunicazioni")
#define TABLE_MAILING_LIST                  _T("Mailing_List")

// ================================================================================
// DataBase Fields 
#define FIELD_ID                            _T("Id")
#define FIELD_GRUPPO                        _T("Gruppo")
#define FIELD_MODELLO                       _T("Modello")
#define FIELD_TIPO                          _T("Tipo")
#define FIELD_ALTRO_TIPO                    _T("Altro_Tipo")
#define FIELD_TARGA                         _T("Targa")
#define FIELD_KM                            _T("Km")
#define FIELD_NONOPERATIVA                  _T("NonOperativa")
#define FIELD_SOCIETA                       _T("Societa")
#define FIELD_NUM_TEL                       _T("NumTelefono")
#define FIELD_NUM_FAX                       _T("NumFax")
#define FIELD_DATAORAINIZIO                 _T("DataOraInizio")
#define FIELD_DATAORAFINE                   _T("DataOraFine")
#define FIELD_COGNOME                       _T("Cognome")
#define FIELD_NOME                          _T("Nome")
#define FIELD_QUALIFICA                     _T("Qualifica")
#define FIELD_QUALIFICASTATO                _T("QualificaStato")                   
#define FIELD_NUMSERVIZIO                   _T("NumServizio")               
#define FIELD_NUMSERVIZIOSUP                _T("NumServizioSup")               
#define FIELD_CODMEZZO                      _T("CodiceMezzo")
#define FIELD_TARGAMEZZO                    _T("TargaMezzo")
#define FIELD_TIPOMEZZO                     _T("TipologiaMezzo")
#define FIELD_CODRADIO118                   _T("CodiceRadio118")             
#define FIELD_DATA                          _T("Data")                      
#define FIELD_ORAINIZIO                     _T("OraInizio") 
#define FIELD_ORAPARTENZA                   _T("OraPartenza")
#define FIELD_ORAARRIVOTARGET               _T("OraArrivoTarget")
#define FIELD_ORAPARTENZATARGET             _T("OraPartenzaTarget")
#define FIELD_ORAARRIVO                     _T("OraArrivo")
#define FIELD_ORAFINE                       _T("OraFine")                   
#define FIELD_RICHIESTO                     _T("Richiesto")         
#define FIELD_SCHEDA118                     _T("Scheda118")                 
#define FIELD_RICHIESTO_NOMINATIVO          _T("Richiesto_Nominativo")         
#define FIELD_RICHIESTO_CF_PIVA             _T("Richiesto_CF_PIVA")         
#define FIELD_RICHIESTO_INDIRIZZO           _T("Richiesto_Indirizzo")         
#define FIELD_RICHIESTO_CIVICO              _T("Richiesto_Civico") 
#define FIELD_RICHIESTO_CAP                 _T("Richiesto_CAP")         
#define FIELD_RICHIESTO_CITTA               _T("Richiesto_Citta")         
#define FIELD_RICHIESTO_PROVINCIA           _T("Richiesto_Provincia")         
#define FIELD_DATIPAGAMENTO                 _T("DatiPagamento")     
#define FIELD_IMPORTO                       _T("Importo")           
#define FIELD_KM_PERCORSI                   _T("KmPercorsi")                
#define FIELD_ORE_FERMO_MACCHINA            _T("Ore_Fermo_Macchina")
#define FIELD_INTERVENTO_LUOGO              _T("LuogoIntervento")      
#define FIELD_INTERVENTO_CAP                _T("LuogoIntervento_CAP")
#define FIELD_INTERVENTO_CITTA              _T("LuogoIntervento_Citta")      
#define FIELD_INTERVENTO_PROVINCIA          _T("LuogoIntervento_Provincia")  
#define FIELD_TRASPORTATO_LUOGO             _T("Trasportato")        
#define FIELD_TRASPORTATO_CAP               _T("Trasportato_CAP")        
#define FIELD_TRASPORTATO_CITTA             _T("Trasportato_Citta")        
#define FIELD_TRASPORTATO_PROVINCIA         _T("Trasportato_Provincia")    
#define FIELD_NOTE                          _T("Note")                      
#define FIELD_CENTRALINO                    _T("Centralino")                
#define FIELD_CHIUSO                        _T("Chiuso")                    
#define FIELD_SESSO                         _T("Sesso")
#define FIELD_INDIRIZZO                     _T("Indirizzo")   
#define FIELD_CIVICO                        _T("Civico")
#define FIELD_CAP                           _T("CAP")
#define FIELD_CITTA                         _T("Citta")             
#define FIELD_PROVINCIA                     _T("Provincia")         
#define FIELD_STATO                         _T("Stato")
#define FIELD_CITTADINANZA                  _T("Cittadinanza")
#define FIELD_MOTIVOTRASPORTO               _T("MotivoDelTrasporto")    
#define FIELD_USER                          _T("User")
#define FIELD_PWD                           _T("Pwd")
#define FIELD_PRIVILEGES                    _T("Privileges")
#define FIELD_LAST_LOGIN                    _T("LastLogIn")
#define FIELD_LAST_LOGOUT                   _T("LastLogOut")
#define FIELD_QUERY                         _T("Query")
#define FIELD_FIRMA_SCHEDA_CRI              _T("Firma_Scheda_CRI")
#define FIELD_FIRMA_SCHEDA_118              _T("Firma_Scheda_118")
#define FIELD_CARABINIERI                   _T("Carabinieri")
#define FIELD_POLIZIA                       _T("Polizia")
#define FIELD_POLIZIA_MUNICIPALE            _T("Polizia_Municipale")
#define FIELD_VVFF                          _T("VVFF")
#define FIELD_GUARDIA_MEDICA                _T("Guardia_Medica")
#define FIELD_ALTRI_MEZZI                   _T("Altri_Mezzi")
#define FIELD_ALTRI_MEZZI_COD               _T("Altri_Mezzi_Codice")
#define FIELD_MOTIVO                        _T("Motivo")
#define FIELD_SETTING                       _T("Setting")
#define FIELD_VALUE                         _T("Value")
#define FIELD_CODICE                        _T("Codice")
#define FIELD_DESCRIZIONE                   _T("Descrizione")
#define FIELD_COD_FISCALE                   _T("CodiceFiscale")
#define FIELD_DATA_NASCITA                  _T("DataDiNascita") 
#define FIELD_ETA                           _T("Eta")
#define FIELD_ETA_TIPO                      _T("Eta_Tipo")
#define FIELD_NUM_TEAM                      _T("NumeroTeam")
#define FIELD_COD_PATOLOGIA                 _T("CodicePatologiaSpecifica")
#define FIELD_COD_EVE_GRAVITA               _T("Codice_Evento_Gravita")
#define FIELD_COD_EVE_PATOLOGIA             _T("Codice_Evento_Patologia")
#define FIELD_COD_EVE_LUOGO                 _T("Codice_Evento_Luogo")
#define FIELD_COD_ARR_GRAVITA               _T("Codice_Arrivo_Gravita")
#define FIELD_COD_ARR_PATOLOGIA             _T("Codice_Arrivo_Patologia")
#define FIELD_COD_ARR_LUOGO                 _T("Codice_Arrivo_Luogo")
#define FIELD_COD_PAR_GRAVITA               _T("Codice_Partenza_Gravita")
#define FIELD_COD_PAR_PATOLOGIA             _T("Codice_Partenza_Patologia")
#define FIELD_COD_PAR_PATOLOGIA2            _T("Codice_Partenza_Patologia2")
#define FIELD_COD_PAR_LUOGO                 _T("Codice_Partenza_Luogo")
#define FIELD_COD_RIL_GRAVITA               _T("Codice_Rilascio_Gravita")
#define FIELD_COD_RIL_PATOLOGIA             _T("Codice_Rilascio_Patologia")
#define FIELD_COD_RIL_LUOGO                 _T("Codice_Rilascio_Luogo")
#define FIELD_TRIAGE                        _T("Triage")
#define FIELD_ANNULLATO                     _T("Annullato")
#define FIELD_TABLE_NAME                    _T("Table_Name")
#define FIELD_TABLE_ID                      _T("Table_Id")
#define FIELD_INSERITA                      _T("Inserita")
#define FIELD_MITTENTE                      _T("Mittente")
#define FIELD_DESTINATARIO                  _T("Destinatario")
#define FIELD_OGGETTO                       _T("Oggetto")
#define FIELD_TESTO                         _T("Testo")
#define FIELD_LETTA                         _T("Letta")
#define FIELD_EMAIL                         _T("eMail")
#define FIELD_PRIVATA                       _T("Privata")

// ================================================================================
//
#define OTHER_SELECTION                     _T("ALTRO")

// ================================================================================
//
static const char* szRequestedBy[]=
{
    _(""),
    _("118"),
    _("ASL"),
    _("PARENTI"),
    _("OSPEDALI"),
    _("ALTRI"),
    _("SERVIZIO INTERNO")
};

enum eRequestedBy
{
    UNKNOW_REQUESTED_BY,
    REQUESTED_BY_118,
    REQUESTED_BY_ASL,
    REQUESTED_BY_PARENT,
    REQUESTED_BY_HOSPITAL,
    REQUESTED_BY_OTHER,
    REQUESTED_BY_INTERNAL,
    REQUESTED_BY_END
};

// ================================================================================
//
static const char* szPaymentType[]=
{
    _(""),
    _("PAGATO"),
    _("FATTURARE"),
    _("INESEGIBILE")
};

enum ePaymentType
{
    UNKNOW_PAYMENT_TYPE,
    PAYMENT_TYPE_PAYED,
    PAYMENT_TYPE_BILL,
    PAYMENT_TYPE_FREE,
    PAYMENT_TYPE_END
};

// ================================================================================
//
static const char* szQualification[] =
{
    _(""),
    _("AUTISTA"),
    _("BARELLIERE"),
    _("CENTRALINO"),
    _("INFERMIERE"),
    _("MEDICO"),
    _("VOLONTARIO")
};

enum eQualification
{
    UNKNOW_QUALIFICATION,
    QUALIFICATION_AUTISTA,
    QUALIFICATION_BARELLIERE,
    QUALIFICATION_CENTRALINO,
    QUALIFICATION_INFERMIERE,
    QUALIFICATION_MEDICO,
    QUALIFICATION_VOLONTARIO,
    QUALIFICATION_END
};

// ================================================================================
//
static const char* szQualificationStatus[] =
{
    _(""),
    _("EFFETTIVO"),
    _("T.P.P."),
    _("1^ STEP"),
    _("2^ STEP")
};

enum eQualificationStatus
{
    UNKNOW_QUALIFICATION_STATUS,
    QUALIFICATION_STATUS_EFFETTIVO,
    QUALIFICATION_STATUS_TTP,
    QUALIFICATION_STATUS_1_STEP,
    QUALIFICATION_STATUS_2_STEP,
    QUALIFICATION_STATUS_END
};

// ================================================================================
//
enum eUserPrivilege
{
    NONE,
    USER,
    CENTRALINO,
    RESP_MEZZI,
    RESP_TURNI,
    RESP_CENTR,
    ADMINISTRATOR,
    USER_END
};

static const char* szUserPrivilege[] =
{
    _(""),
    _("V.d.S"),
    _("CENTRALINO"),
    _("RESPONSABILE MEZZI"),
    _("RESPONSABILE TURNI"),
    _("RESPONSABILE CENTRALINO"),
    _("ADMINISTRATOR"),
};

// ================================================================================
//
enum eMode
{
    ADD,
    MODIFY,
    READ_ONLY
};

// ================================================================================
//
static const char* szSearchBy[] =
{
    _(""),
    _("NUMERO DI SERVIZIO"),
    _("NUMERO DI SERVIZIO (SECONDARIO)"),
    _("NUMERO DI SCHEDA 118"),
    _("NOMINATIVO RICHIEDENTE"),
    _("NOMINATIVO PAZIENTE"),
    _("SERVIZI CON NOTE"),
    _("QUERY SQL")
};

enum eSearchBy
{
    SEARCH_UNKNOW,
    NUM_SERVIZIO,
    NUM_SERVIZIO_SUP,
    NUM_SCHEDA_118,
    NOMINATIVO_RICHIEDENTE,
    NOMINATIVO_PAZIENTE,
    NOTE_SERVIZIO,
    SQL_QUERY,
    SEARCH_END
};

// ================================================================================
//
static const char* szServicePlace[] =
{
    _(""),
    _("H "),
    _("ABITAZIONE")
};

enum eServicePlace
{
    SERVICEPLACE_UNKNOW,
    SERVICEPLACE_HOSPITAL,
    SERVICEPLACE_HOME
};

// ================================================================================
//
static const char* szServiceResult[] =
{
    _(""),
    _("RIF. TRASP."),
    _("TRASP. DALLA"),
    _("NON TROVATO"),
    _("NON COMPLETATO"),
    _("ANNULATO DALLA C.O. 118"),
    _("H "),
    _("DECEDUTO"),
    _("ABITAZIONE"),
    _("AVARIA MEZZO")
};

enum eServiceResult
{
    SERVICERESULT_UNKNOW,
    SERVICERESULT_REFUSES_TRANSPORT,
    SERVICERESULT_TRANSPORT_BY,
    SERVICERESULT_NOT_FOUND,
    SERVICERESULT_NOT_COMPLETED,
    SERVICERESULT_ANNULLED_BY_118,
    SERVICERESULT_HOSPITAL,
    SERVICERESULT_DEAD,
    SERVICERESULT_HOME,
    SERVICERESULT_VEHICLE_DAMAGE
};

// ================================================================================
//
enum e118CodeType
{
    TYPE_CODE_UNKNOW,
    TYPE_CODE_GRAVITY,
    TYPE_CODE_EVENT,
    TYPE_CODE_ARRIVAL,
    TYPE_CODE_DEPARTURE,
    TYPE_CODE_DEPARTURE_2,
    TYPE_CODE_RELEASE,
    TYPE_CODE_PLACE,
    TYPE_CODE_DINAMIC,
    TYPE_CODE_TREATMENT
};

// ================================================================================
//
static const char* szStates[] =
{
    _(""),
    _("AFGHANISTAN"),
    _("ALBANIA"),
    _("ALGERIA"),
    _("ANDORRA"),
    _("ANGOLA"),
    _("ANTIGUA E BARBUDA"),
    _("ARABIA SAUDITA"),
    _("ARGENTINA"),
    _("ARMENIA"),
    _("AUSTRALIA"),
    _("AUSTRIA"),
    _("AZERBAIGIAN"),
    _("BAHAMAS"),
    _("BAHREIN"),
    _("BANGLADESH"),
    _("BARBADOS"),
    _("BELGIO"),
    _("BELIZE"),
    _("BENIN"),
    _("BHUTAN"),
    _("BIELORUSSIA"),
    _("BOLIVIA"),
    _("BOSNIA E ERZEGOVIA"),
    _("BOTSWANA"),
    _("BRASILE"),
    _("BRUNEI"),
    _("BULGARIA"),
    _("BURKINA FASO"),
    _("BURUNDI"),
    _("CAMBOGIA"),
    _("CAMERUN"),
    _("CANADA"),
    _("CAPO VERDE"),
    _("CECOSLOVACCHIA"),
    _("CENTRAFRICANA, REPUBBLICA"),
    _("CIAD"),
    _("CILE"),
    _("CINA"),
    _("CIPRO"),
    _("COLOMBIA"),
    _("COMORE"),
    _("CONGO, REPUBBLICA DEL"),
    _("CONGO, REPUBBLICA DEMOCRATICA DEL"),
    _("COREA DEL SUD"),
    _("COREA DEL NORD"),
    _("COSTA D'AVORIO"),
    _("COSTA RICA"),
    _("CROAZIA"),
    _("CUBA"),
    _("DANIMARCA"),
    _("DOMINICA"),
    _("DOMINICANA, REPUBBLICA"),
    _("ECUADOR"),
    _("EGITTO"),
    _("EL SALVADOR"),
    _("EMIRATI ARABI UNITI"),
    _("ERITREA"),
    _("ESTONIA"),
    _("ETIOPIA"),
    _("FIGI"),
    _("FILIPPINE"),
    _("FINLANDIA"),
    _("FRANCIA"),
    _("GABON"),
    _("GAMBIA"),
    _("GEORGIA"),
    _("GERMANIA"),
    _("GHANA"),
    _("GIAMAICA"),
    _("GIAPPONE"),
    _("GIBUTI"),
    _("GIORDANIA"),
    _("GRECIA"),
    _("GRENADA"),
    _("GUATEMALA"),
    _("GUINEA"),
    _("GUINEA BISSAU"),
    _("GUINEA EQUATORIALE"),
    _("GUYANA"),
    _("HAITI"),
    _("HONDURAS"),
    _("INDIA"),
    _("INDONESIA"),
    _("IRAN"),
    _("IRAQ"),
    _("IRLANDA"),
    _("ISLANDA"),
    _("ISRAELE"),
    _("ITALIA"),
    _("KAZAKHSTAN"),
    _("KENYA"),
    _("KIRGHIZISTAN"),
    _("KIRIBATI"),
    _("KUWAIT"),
    _("LAOS"),
    _("LESOTHO"),
    _("LETTONIA"),
    _("LIBANO"),
    _("LIBERIA"),
    _("LIBIA"),
    _("LIECHTENSTEIN"),
    _("LITUANIA"),
    _("LUSSEMBURGO"),
    _("MACEDONIA"),
    _("MADAGASCAR"),
    _("MALAWI"),
    _("MALAYSIA"),
    _("MALDIVE"),
    _("MALI"),
    _("MALTA"),
    _("MAROCCO"),
    _("MARSHALL, ISOLE"),
    _("MAURITANIA"),
    _("MAURITIUS"),
    _("MESSICO"),
    _("MICRONESIA, STATI FEDERATI"),
    _("MOLDOVA"),
    _("MONACO"),
    _("MONGOLIA"),
    _("MOZAMBICO"),
    _("MYANMAR"),
    _("NAMIBIA"),
    _("NAURU"),
    _("NEPAL"),
    _("NICARAGUA"),
    _("NIGER"),
    _("NIGERIA"),
    _("NORVEGIA"),
    _("NUOVA ZELANDA"),
    _("OMAN"),
    _("PAESI BASSI"),
    _("PAKISTAN"),
    _("PALAU"),
    _("PANAMA"),
    _("PAPUA NUOVA GUINEA"),
    _("PARAGUAY"),
    _("PERU'"),
    _("POLONIA"),
    _("PORTOGALLO"),
    _("QATAR"),
    _("REGNO UNITO"),
    _("ROMANIA"),
    _("RUANDA"),
    _("RUSSIA"),
    _("SAINT KITTS E NEVIS"),
    _("SAINT LUCIA"),
    _("SAINT VINCENT E GRENADINE"),
    _("SALOMONE, ISOLE"),
    _("SAMOA"),
    _("SAN MARINO"),
    _("SANTA SEDE"),
    _("SENEGAL"),
    _("SERBIA E MONTENEGRO"),
    _("SEYCHELLES"),
    _("SIERRA LEONE"),
    _("SINGAPORE"),
    _("SIRIA"),
    _("SLOVACCHIA"),
    _("SLOVENIA"),
    _("SOMALIA"),
    _("SPAGNA"),
    _("SRI LANKA"),
    _("STATI UNITI D'AMERICA"),
    _("SUD AFRICA"),
    _("SUDAN"),
    _("SURINAME"),
    _("SVEZIA"),
    _("SVIZZERA"),
    _("SWAZILAND"),
    _("TAGIKISTAN"),
    _("TAIWAN"),
    _("TANZANIA"),
    _("TERRITORI DELL'AUTONOMIA PALESTINESE"),
    _("THAILANDIA"),
    _("TIMOR ORIENTALE"),
    _("TOGO"),
    _("TONGA"),
    _("TRINIDAD E TOBAGO"),
    _("TUNISIA"),
    _("TURCHIA"),
    _("TURKMENISTAN"),
    _("TUVALU"),
    _("UCRAINA"),
    _("UGANDA"),
    _("UNGHERIA"),
    _("URUGUAY"),
    _("UZBEKISTAN"),
    _("VANUATU"),
    _("VENEZUELA"),
    _("VIETNAM"),
    _("YEMEN"),
    _("ZAMBIA"),
    _("ZIMBABWE")
};

#endif
