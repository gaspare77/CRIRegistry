-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `CodiciPatologiaPresunta`
-- -----------------------------------------------------
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('01', 'TRAUMATICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('02', 'CARDIOCIRCOLATORIA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('03', 'RESPIRATORIA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('04', 'NEUROLOGICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('05', 'PSICHIATRICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('06', 'NEOPLASTICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('07', 'INTOSSICAZIONE');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('08', 'METABOLICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('09', 'GASTROENTEROLOGICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('10', 'UROLOGICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('11', 'OCULISTICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('12', 'OTORINOLARINGOIATRICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('13', 'DERMATOLOGICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('14', 'OSTETRICO-GINECOLOGICA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('15', 'INFETTIVA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('19', 'ALTRA PATOLOGIA');
INSERT INTO `CodiciPatologiaPresunta` (`Codice`, `Descrizione`) VALUES ('20', 'PATOLOGIA NON IDENTIFICATA');

-- -----------------------------------------------------
-- Data for table `CodiciPatologiaRiscontrata`
-- -----------------------------------------------------
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '001', 'ADDOME');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '002', 'AMPUTAZIONE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '003', 'ARTI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '004', 'CONTUSIONE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '005', 'CRANIO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '006', 'EMORRAGIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '007', 'FERITA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '008', 'FOLGORAZIONE/ELETTROCUZIONE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '009', 'FRATTURA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '010', 'FRATTURA DI FEMORE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '011', 'LESIONE AGLI OCCHI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '012', 'LESIONE DA FREDDO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '013', 'POLITRAUMATISMO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '014', 'RACHIDE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '015', 'TORACE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '016', 'USTIONE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('01', '017', 'ALTRA TRAUMATICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '021', 'ARRESTO CARDIOCIRCOLATORI0');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '022', 'CARDIOPALMO/ARITMIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '023', 'CRISI IPERTENSIVA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '024', 'DOLORE TORACICO < 2 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '024.1', 'DOLORE TORACICO 2 - 12 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '024.2', 'DOLORE TORACICO 12 - 24 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '024.3', 'DOLORE TORACICO > 24 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '025', 'SCOMPENSO CARDIOCIRCOLATORI0');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '026', 'SINDROME CORONARICA ACUTA < 2 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '026.1', 'SINDROME CORONARICA ACUTA 2 - 12 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '026.2', 'SINDROME CORONARICA ACUTA 12 - 24 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '026.3', 'SINDROME CORONARICA ACUTA > 24 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('02', '027', 'ALTRA CARDIOCIRCOLATORIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('03', '031', 'CORPO ESTRANEO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('03', '032', 'CRISI ASMATICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('03', '033', 'DISTRESS RESPIRATORIO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('03', '034', 'IMMERSIONE/SOMMERSIONE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('03', '035', 'INSUFFICIENZA RESPIRATORIA CRONICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('03', '036', 'ALTRA RESPIRATORIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '041', 'CEFALEA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '042', 'COMA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '043', 'CONVULSIONI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '044', 'DECADIMENTO PSICHICO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '045', 'ICTUS < 3 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '046', 'ICTUS > 3 H');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '047', 'PERDITA DI COSCIENZA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('04', '048', 'ALTRA NEUROLOGICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('05', '051', 'AGITAZIONE PSICOMOTORIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('05', '052', 'TENTATO SUICIDIO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('05', '053', 'ALTRA PSICHIATRICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('06', '061', 'NEOPLASTICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('07', '071', 'ALIMENTI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('07', '072', 'FARMACI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('07', '073', 'INTOSSICAZIONE ETILICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('07', '074', 'OSSIDO DI CARBONIO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('07', '075', 'OVERDOSE/STUPEFACENTI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('07', '076', 'SOSTANZE CHIMICHE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('07', '077', 'ALTRA INTOSSICAZIONE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('08', '081', 'IPERGLICEMIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('08', '082', 'IPOGLICEMIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('08', '083', 'ALTRA METABOLICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('09', '091', 'DOLORE ADDOMINALE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('09', '092', 'EMORRAGIA DIGESTIVA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('09', '093', 'ALTRA GASTROENTEROLOGICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('10', '101', 'COLICO RENALE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('10', '102', 'RITENZIONE URINARIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('10', '103', 'ALTRA UROLOGICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('11', '111', 'FERITA PENETRANTE OCCHIO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('11', '112', 'ALTRA OCULISTICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('12', '121', 'CORPO ESTRANEO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('12', '122', 'EPISTASSI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('12', '123', 'ALTRA OTORINOLARINGOIATRICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('13', '131', 'PARASSITOSI');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('13', '132', 'ALLERGIA REAZIONE ORTICALOIDE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('13', '133', 'ALTRA DERMATOLOGICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('14', '141', 'METRORAGGIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('14', '142', 'MINACCIA ABORTO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('14', '143', 'PARTO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('14', '144', 'ALTRA OSTETRICO-GINECOLOGICA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('15', '151', 'STATO FEBBRILE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('15', '152', 'ALTRA INFETTIVA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('19', '191', 'CATASTROFE O EMERGENZA NBCR');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('19', '192', 'STATO FEBBRILE');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('19', '193', 'ALLERGIA-LARINGOSPASMO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('19', '194', 'ALLERGIA-SHOCK ANAFILATTICO');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('19', '195', 'ALTRA PATOLOGIA');
INSERT INTO `CodiciPatologiaRiscontrata` (`CodicePresunto`, `Codice`, `Descrizione`) VALUES ('20', '201', 'PATOLOGIA NON IDENTIFICATA');

-- -----------------------------------------------------
-- Data for table `CodiciDinamicaRiscontrata`
-- -----------------------------------------------------
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('01', 'AGRESSIONE');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('02', 'ARMA BIANCA');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('03', 'ARMA DA FUOCO');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('04', 'ESPLOSIONE');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('05', 'INCASTRATO');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('06', 'INCIDENTE AUTO');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('07', 'INCIDENTE BICICLETTA');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('08', 'INCIDENTE MEZZO PESANTE');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('09', 'INCIDENTE MOTO');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('10', 'INCIDENTE PEDONE');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('11', 'INCENDIO');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('12', 'MORSO DI ANIMALE');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('13', 'PRECIPITATO < 3 M');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('14', 'PRECIPITATO > 3 M');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('15', 'PROIETTATO');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('16', 'SOCCORSO PERSONA');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('17', 'TUFFO/IMMERSIONE');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('18', 'VIOLENZA SESSUALE');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('19', 'ALTRA DINAMICA');
INSERT INTO `CodiciDinamicaRiscontrata` (`Codice`, `Descrizione`) VALUES ('20', 'NON DEFINITA');

-- -----------------------------------------------------
-- Data for table `CodiciPrestazione`
-- -----------------------------------------------------
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('01', 'ACCESSO VENOSO CENTRALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('02', 'ACCESSO VENOSO PERIFERICO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('03', 'ASPIRAZIONE SECRETI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('04', 'BENDAGGIO ARTI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('05', 'CAPNOMETRIA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('06', 'CATETERISMO VESCICALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('07', 'CLAMPAGGIO E TAGLIO CORDONE OMBELLICALE DOPO IL PARTO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('08', 'CRICOTIROIDOTOMIA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('09', 'CONTROLLO SATURAZIONE 02');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('10', 'CONTROLLO EMORRAGIA ESTERNA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('11', 'CONTROLLO PNEUMOTORACE (PNX) APERTO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('12', 'DECOMPRESSIONE PNEUMOTORACE (PNX)');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('13', 'DECONTAMINAZIONE SINGOLA (IN CASO DI NBCR)');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('14', 'DEFIBRILLAZIONE SEMIAUTOMATICA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('15', 'DETERMINAZIONE CO AMBIENTALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('16', 'DISOSTRUZIONE VIE AEREE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('17', 'DRENAGGIO TORACICO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('18', 'ECOGRAFIA ADDOME COMPLETO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('19', 'ECOGRAFIA ADDOME INFERIORE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('20', 'ECOGRAFIA RENO-VESCICALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('21', 'ECOGRAFIA VASI ADDOMINALI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('22', 'ECOGRAFIA TORACE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('23', 'ELETTROCARDIOGRAMMA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('24', 'EMATOCRITO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('25', 'EMOCROMO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('26', 'EMOGASANALISI ARTERIOSA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('27', 'ESTRICAZIONE DI INCASTRATI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('28', 'FASCIOTOMIA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('29', 'GASTROLUSI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('30', 'GESTIONE DI PAZIENTI IN AGITAZIONE PSICOMOTORIA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('31', 'GESTIONE DI PAZIENTI IN AGITAZIONE PSICOMOTORIA (IN CRISI)');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('32', 'GLICEMIA SU SANGUE CAPILLARE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('33', 'INIEZIONE DI ANESTETICO IN NERVO PERIFERICO PER ANALGESIA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('34', 'INIEZIONE O INFUSIONE DI FARMACI E LIQUIDI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('35', 'INIEZIONE O INFUSIONE DI SOSTANZE ANALGESICHE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('36', 'INFUSIONE INTRAOSSEA PER LIQUIDI E FARMACI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('37', 'IMMOBILIZZAZIONE ARTI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('38', 'IMMOBILIZZAZIONE COLONNA CON COLLARE CERVICALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('39', 'IMMOBILIZZAZIONE COLONNA CON ESTRICATORE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('40', 'IMMOBILIZZAZIONE COLONNA CON MATERASSINO A DEPRESSIONE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('41', 'IMMOBILIZZAZIONE COLONNA CON TAVOLA SPINALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('42', 'INSERZIONE DI TUBO ENDOTRACHEALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('43', 'INSERZIONE TUBO NASOTRACHEALE O NASOFARINGEO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('44', 'INSERZIONE TUBO OROTRACHEALE (O ALTRO PRESIDIO SOVRA O SOTTO GLOTTICO)');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('45', 'MASSAGGIO CARDIACO ESTERNO A TORACE CHIUSO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('46', 'MEDICAZIONE USTIONI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('47', 'MEDICAZIONI VARIE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('48', 'MONITORAGGIO DELLA PRESSIONE ARTERIOSA SISTEMICA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('49', 'PERICARDIOCENTESI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('50', 'POSIZIONAMENTO SONDINO NASOGASTRICO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('51', 'PREVENZIONE IPOTERMICA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('52', 'PRELIEVO DI SANGUE ARTERIOSO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('53', 'PRELIEVO DI SANGUE VENOSO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('54', 'PRELIEVO DI SANGUE VENOSO PER DETERMINAZIONE CO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('55', 'RIANIMAZIONE CARDIOPOLMONARE DI BASE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('56', 'RICERCA SOSTANZE DI ABUSO (DROGHE) SU LIQUIDI BIOLOGICI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('57', 'RICERCA SOSTANZE DI ABUSO (ETANOLO) SU LIQUIDI BIOLOGICI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('58', 'RIDUZIONE CHIUSA DI LUSSAZIONE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('59', 'RIDUZIONE MANUALE DI ERNIA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('60', 'RIDUZIONE MANUALE PROLASSO RETTALE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('61', 'RIMOZIONE CORPO ESTRANEO LARINGE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('62', 'RIMOZIONE CORPO ESTRANEO TRACHEA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('63', 'SPIROMETRIA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('64', 'SOMMINISTRAZIONE FARMACI CON AEROSOL');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('65', 'SOMMINISTRAZIONE OSSIGENO');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('66', 'SUPPORTO PSICOLOGICO AL PAZIENTE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('67', 'SUTURA FERITE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('68', 'TAMPONAMENTO ANTERIORE PER EPISTASSI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('69', 'TERAPIE CARDIACHE ELETTRICHE (CARDIOVERSIONE,PACING,DEFRIBILLAZIONE MANUALE)');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('70', 'TRASFUSIONE E SOMMINISTRAZIONE EMODERIVATI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('71', 'TROMBALISI');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('72', 'TROPONINA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('73', 'VENTILAZIONE CON PALLONE AUTOESPANSIBILE');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('74', 'VENTILAZIONE MECCANICA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('75', 'VENTILAZIONE MECCANICA NON INVASIVA');
INSERT INTO `CodiciPrestazione` (`Codice`, `Descrizione`) VALUES ('76', 'VISITA GENERALE');

-- -----------------------------------------------------
-- Data for table `CodiciLuogo`
-- -----------------------------------------------------
INSERT INTO `CodiciLuogo` (`Codice`, `Descrizione`) VALUES ('S', 'STRADA');
INSERT INTO `CodiciLuogo` (`Codice`, `Descrizione`) VALUES ('P', 'LUOGO/ESERCIZIO PUBBLICO');
INSERT INTO `CodiciLuogo` (`Codice`, `Descrizione`) VALUES ('Y', 'IMPIANTO SPORTIVO');
INSERT INTO `CodiciLuogo` (`Codice`, `Descrizione`) VALUES ('K', 'CASA');
INSERT INTO `CodiciLuogo` (`Codice`, `Descrizione`) VALUES ('L', 'LAVORO');
INSERT INTO `CodiciLuogo` (`Codice`, `Descrizione`) VALUES ('Q', 'SCUOLA');
INSERT INTO `CodiciLuogo` (`Codice`, `Descrizione`) VALUES ('Z', 'ALTRO LUOGO');

-- -----------------------------------------------------
-- Data for table `CodiciGravita`
-- -----------------------------------------------------
INSERT INTO `CodiciGravita` (`CodiceNum`, `Codice`, `Descrizione`) VALUES (0, 'B', 'BIANCO');
INSERT INTO `CodiciGravita` (`CodiceNum`, `Codice`, `Descrizione`) VALUES (1, 'V', 'VERDE');
INSERT INTO `CodiciGravita` (`CodiceNum`, `Codice`, `Descrizione`) VALUES (2, 'G', 'GIALLO');
INSERT INTO `CodiciGravita` (`CodiceNum`, `Codice`, `Descrizione`) VALUES (3, 'R', 'ROSSO');
INSERT INTO `CodiciGravita` (`CodiceNum`, `Codice`, `Descrizione`) VALUES (4, 'N', 'NERO');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
