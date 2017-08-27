SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

DROP SCHEMA IF EXISTS `cri` ;
CREATE SCHEMA IF NOT EXISTS `cri` DEFAULT CHARACTER SET utf8 ;
USE `cri` ;

-- -----------------------------------------------------
-- Table `codicidinamicariscontrata`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `codicidinamicariscontrata` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `Codice` VARCHAR(2) NULL DEFAULT NULL ,
  `Descrizione` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `codicigravita`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `codicigravita` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `CodiceNum` INT(10) UNSIGNED NULL DEFAULT '0' ,
  `Codice` VARCHAR(2) NULL DEFAULT NULL ,
  `Descrizione` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `codiciluogo`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `codiciluogo` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `Codice` VARCHAR(2) NULL DEFAULT NULL ,
  `Descrizione` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `codicipatologiapresunta`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `codicipatologiapresunta` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `Codice` VARCHAR(2) NULL DEFAULT NULL ,
  `Descrizione` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `codicipatologiariscontrata`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `codicipatologiariscontrata` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `CodicePresunto` VARCHAR(2) NULL DEFAULT NULL ,
  `Codice` VARCHAR(5) NULL DEFAULT NULL ,
  `Descrizione` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `codiciprestazione`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `codiciprestazione` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `Codice` VARCHAR(2) NULL DEFAULT NULL ,
  `Descrizione` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `gruppi`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `gruppi` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Gruppo` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `motivazionirifiutatrasporto`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `motivazionirifiutatrasporto` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Motivo` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `ospedali`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `ospedali` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Nome` VARCHAR(100) NULL DEFAULT NULL ,
  `Societa` VARCHAR(100) NULL DEFAULT NULL ,
  `Indirizzo` VARCHAR(100) NULL DEFAULT NULL ,
  `Civico` VARCHAR(45) NULL DEFAULT NULL ,
  `CAP` INT(10) UNSIGNED NULL DEFAULT NULL ,
  `Citta` VARCHAR(45) NULL DEFAULT NULL ,
  `Provincia` VARCHAR(2) NULL DEFAULT NULL ,
  `NumTelefono` VARCHAR(100) NULL DEFAULT NULL ,
  `NumFax` VARCHAR(100) NULL DEFAULT NULL ,
  `Note` TEXT NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `parcomacchine`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `parcomacchine` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `CodiceMezzo` VARCHAR(10) NULL DEFAULT NULL ,
  `Gruppo` VARCHAR(100) NULL DEFAULT NULL ,
  `Modello` VARCHAR(100) NULL DEFAULT NULL ,
  `Tipo` VARCHAR(100) NULL DEFAULT NULL ,
  `CodiceRadio118` VARCHAR(100) NULL DEFAULT NULL ,
  `Targa` VARCHAR(100) NULL DEFAULT NULL ,
  `Km` INT(10) UNSIGNED NULL DEFAULT NULL ,
  `Note` TEXT NULL DEFAULT NULL ,
  `NonOperativa` TINYINT(1) NULL DEFAULT '0' ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `querylist`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `querylist` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Nome` VARCHAR(45) NULL DEFAULT NULL ,
  `Query` TEXT NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `registropresenze`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `registropresenze` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `DataOraInizio` DATETIME NULL DEFAULT NULL ,
  `DataOraFine` DATETIME NULL DEFAULT NULL ,
  `Gruppo` VARCHAR(45) NULL DEFAULT NULL ,
  `Cognome` VARCHAR(100) NULL DEFAULT NULL ,
  `Nome` VARCHAR(100) NULL DEFAULT NULL ,
  `Note` TEXT NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `registroservizi`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `registroservizi` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `NumServizio` INT(10) NULL DEFAULT '0' ,
  `NumServizioSup` INT(10) NULL DEFAULT '0' ,
  `Data` DATE NULL DEFAULT NULL ,
  `OraInizio` DATETIME NULL DEFAULT NULL ,
  `OraPartenza` DATETIME NULL DEFAULT NULL ,
  `OraArrivoTarget` DATETIME NULL DEFAULT NULL ,
  `OraPartenzaTarget` DATETIME NULL DEFAULT NULL ,
  `OraArrivo` DATETIME NULL DEFAULT NULL ,
  `OraFine` DATETIME NULL DEFAULT NULL ,
  `Gruppo` VARCHAR(100) NULL DEFAULT NULL ,
  `CodiceMezzo` VARCHAR(10) NULL DEFAULT NULL ,
  `TargaMezzo` VARCHAR(100) NULL DEFAULT NULL ,
  `TipologiaMezzo` VARCHAR(100) NULL DEFAULT NULL ,
  `CodiceRadio118` VARCHAR(10) NULL DEFAULT NULL ,
  `Richiesto` VARCHAR(100) NULL DEFAULT NULL ,
  `Richiesto_Nominativo` VARCHAR(100) NULL DEFAULT NULL ,
  `Richiesto_CF_PIVA` VARCHAR(45) NULL DEFAULT NULL ,
  `Richiesto_Indirizzo` VARCHAR(100) NULL DEFAULT NULL ,
  `Richiesto_Civico` VARCHAR(45) NULL DEFAULT NULL ,
  `Richiesto_CAP` INT(10) UNSIGNED NULL DEFAULT NULL ,
  `Richiesto_Citta` VARCHAR(45) NULL DEFAULT NULL ,
  `Richiesto_Provincia` VARCHAR(2) NULL DEFAULT NULL ,
  `Scheda118` VARCHAR(45) NULL DEFAULT NULL ,
  `Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  `Altro_Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  `DatiPagamento` VARCHAR(100) NULL DEFAULT NULL ,
  `Importo` FLOAT UNSIGNED NULL DEFAULT '0' ,
  `Ore_Fermo_Macchina` FLOAT UNSIGNED NULL DEFAULT '0' ,
  `KmPercorsi` INT(10) UNSIGNED NULL DEFAULT '0' ,
  `LuogoIntervento` VARCHAR(100) NULL DEFAULT NULL ,
  `LuogoIntervento_CAP` INT(10) UNSIGNED NULL DEFAULT '0' ,
  `LuogoIntervento_Citta` VARCHAR(45) NULL DEFAULT NULL ,
  `LuogoIntervento_Provincia` VARCHAR(2) NULL DEFAULT NULL ,
  `Centralino` VARCHAR(100) NULL DEFAULT NULL ,
  `Note` TEXT NULL DEFAULT NULL ,
  `Carabinieri` TINYINT(1) NULL DEFAULT '0' ,
  `Polizia` TINYINT(1) NULL DEFAULT '0' ,
  `Polizia_Municipale` TINYINT(1) NULL DEFAULT '0' ,
  `VVFF` TINYINT(1) NULL DEFAULT '0' ,
  `Guardia_Medica` TINYINT(1) NULL DEFAULT '0' ,
  `Altri_Mezzi` TINYINT(1) NULL DEFAULT '0' ,
  `Altri_Mezzi_Codice` VARCHAR(100) NULL DEFAULT NULL ,
  `Chiuso` TINYINT(1) NULL DEFAULT '0' ,
  `Annullato` TINYINT(1) NULL DEFAULT '0' ,
  `Registrato` TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `registroservizi_pazienti`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `registroservizi_pazienti` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `RegistroServizi_Id` INT(10) UNSIGNED NOT NULL ,
  `Cognome` VARCHAR(45) NULL DEFAULT NULL ,
  `Nome` VARCHAR(45) NULL DEFAULT NULL ,
  `Sesso` VARCHAR(4) NULL DEFAULT NULL ,
  `DataDiNascita` DATE NULL DEFAULT NULL ,
  `Eta` INT UNSIGNED NULL DEFAULT NULL ,
  `Eta_Tipo` VARCHAR(5) NULL DEFAULT NULL ,
  `CodiceFiscale` VARCHAR(45) NULL DEFAULT NULL ,
  `Indirizzo` VARCHAR(100) NULL DEFAULT NULL ,
  `Civico` VARCHAR(45) NULL DEFAULT NULL ,
  `CAP` INT(10) UNSIGNED NULL DEFAULT NULL ,
  `Citta` VARCHAR(45) NULL DEFAULT NULL ,
  `Provincia` VARCHAR(2) NULL DEFAULT NULL ,
  `Stato` VARCHAR(45) NULL DEFAULT NULL ,
  `Cittadinanza` VARCHAR(45) NULL DEFAULT NULL ,
  `MotivoDelTrasporto` TEXT NULL DEFAULT NULL ,
  `Trasportato` VARCHAR(100) NULL DEFAULT NULL ,
  `Trasportato_CAP` INT(10) UNSIGNED NULL DEFAULT '0' ,
  `Trasportato_Citta` VARCHAR(45) NULL DEFAULT NULL ,
  `Trasportato_Provincia` VARCHAR(2) NULL DEFAULT NULL ,
  `Firma_Scheda_CRI` TINYINT(1) NULL DEFAULT '0' ,
  `Firma_Scheda_118` TINYINT(1) NULL DEFAULT '0' ,
  `NumeroTeam` VARCHAR(45) NULL DEFAULT NULL ,
  `CodicePatologiaSpecifica` VARCHAR(45) NULL DEFAULT NULL ,
  `Codice_Evento_Gravita` VARCHAR(1) NULL DEFAULT NULL ,
  `Codice_Evento_Patologia` VARCHAR(5) NULL DEFAULT NULL ,
  `Codice_Evento_Luogo` VARCHAR(1) NULL DEFAULT NULL ,
  `Codice_Arrivo_Gravita` VARCHAR(1) NULL DEFAULT NULL ,
  `Codice_Arrivo_Patologia` VARCHAR(5) NULL DEFAULT NULL ,
  `Codice_Arrivo_Luogo` VARCHAR(1) NULL DEFAULT NULL ,
  `Codice_Partenza_Gravita` VARCHAR(1) NULL DEFAULT NULL ,
  `Codice_Partenza_Patologia` VARCHAR(5) NULL DEFAULT NULL ,
  `Codice_Partenza_Patologia2` VARCHAR(5) NULL DEFAULT NULL ,
  `Codice_Partenza_Luogo` VARCHAR(1) NULL DEFAULT NULL ,
  `Codice_Rilascio_Gravita` VARCHAR(1) NULL DEFAULT NULL ,
  `Codice_Rilascio_Patologia` VARCHAR(5) NULL DEFAULT NULL ,
  `Codice_Rilascio_Luogo` VARCHAR(1) NULL DEFAULT NULL ,
  `Triage` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`, `RegistroServizi_Id`) ,
  INDEX `fk_RegistroServizi_Pazienti_idx` (`RegistroServizi_Id` ASC) ,
  CONSTRAINT `fk_RegistroServizi_Pazienti`
    FOREIGN KEY (`RegistroServizi_Id` )
    REFERENCES `registroservizi` (`Id` )
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `registroservizi_pazienti_dinamiche`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `registroservizi_pazienti_dinamiche` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `RegistroServizi_Id` INT(10) UNSIGNED NOT NULL ,
  `RegistroServizi_Pazienti_Id` INT(10) UNSIGNED NOT NULL ,
  `Codice` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`, `RegistroServizi_Id`, `RegistroServizi_Pazienti_Id`) ,
  INDEX `fk_RegistroServizi_Dinamiche_idx` (`RegistroServizi_Pazienti_Id` ASC, `RegistroServizi_Id` ASC) ,
  CONSTRAINT `fk_RegistroServizi_Pazienti_Dinamiche`
    FOREIGN KEY (`RegistroServizi_Pazienti_Id` , `RegistroServizi_Id` )
    REFERENCES `registroservizi_pazienti` (`Id` , `RegistroServizi_Id` )
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `registroservizi_equipaggi`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `registroservizi_equipaggi` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `RegistroServizi_Id` INT(10) UNSIGNED NOT NULL ,
  `Cognome` VARCHAR(100) NULL DEFAULT NULL ,
  `Nome` VARCHAR(100) NULL DEFAULT NULL ,
  `Qualifica` VARCHAR(100) NULL DEFAULT NULL ,
  `QualificaStato` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`, `RegistroServizi_Id`) ,
  INDEX `fk_RegistroServizi_Equipaggi_idx` (`RegistroServizi_Id` ASC) ,
  CONSTRAINT `fk_RegistroServizi_Equipaggi`
    FOREIGN KEY (`RegistroServizi_Id` )
    REFERENCES `registroservizi` (`Id` )
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `registroservizi_pazienti_prestazioni`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `registroservizi_pazienti_prestazioni` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `RegistroServizi_Id` INT(10) UNSIGNED NOT NULL ,
  `RegistroServizi_Pazienti_Id` INT(10) UNSIGNED NOT NULL ,
  `Codice` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`, `RegistroServizi_Id`, `RegistroServizi_Pazienti_Id`) ,
  INDEX `fk_RegistroServizi_Prestazioni_idx` (`RegistroServizi_Id` ASC, `RegistroServizi_Pazienti_Id` ASC) ,
  CONSTRAINT `fk_RegistroServizi_Pazienti_Prestazioni`
    FOREIGN KEY (`RegistroServizi_Id` , `RegistroServizi_Pazienti_Id` )
    REFERENCES `registroservizi_pazienti` (`RegistroServizi_Id` , `Id` )
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `registroturni`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `registroturni` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `DataOraInizio` DATETIME NULL DEFAULT NULL ,
  `DataOraFine` DATETIME NULL DEFAULT NULL ,
  `Gruppo` VARCHAR(45) NULL DEFAULT NULL ,
  `Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  `CodiceMezzo` VARCHAR(10) NULL DEFAULT NULL ,
  `Cognome` VARCHAR(100) NULL DEFAULT NULL ,
  `Nome` VARCHAR(100) NULL DEFAULT NULL ,
  `Qualifica` VARCHAR(100) NULL DEFAULT NULL ,
  `QualificaStato` VARCHAR(100) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `tipologiamezzi`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `tipologiamezzi` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `tipologiaservizi118`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `tipologiaservizi118` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `tipologiaserviziinterni`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `tipologiaserviziinterni` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `tipologiaserviziordinari`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `tipologiaserviziordinari` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `tipologiaturni`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `tipologiaturni` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT ,
  `Tipo` VARCHAR(45) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `users`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `users` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `User` VARCHAR(45) NOT NULL ,
  `Nome` VARCHAR(45) NULL DEFAULT NULL ,
  `Cognome` VARCHAR(45) NULL DEFAULT NULL ,
  `Privileges` INT(10) UNSIGNED NULL DEFAULT NULL ,
  `Pwd` VARCHAR(45) NOT NULL ,
  `LastLogIn` DATETIME NULL DEFAULT NULL ,
  `LastLogOut` DATETIME NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `table_lock`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `table_lock` (
  `Table_Name` VARCHAR(45) NULL DEFAULT NULL ,
  `Table_Id` INT(11) NULL DEFAULT NULL ,
  `User` VARCHAR(45) NULL DEFAULT NULL )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mailing_list`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `mailing_list` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `Nome` VARCHAR(45) NULL DEFAULT NULL ,
  `eMail` VARCHAR(255) NULL DEFAULT NULL ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `comunicazioni`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `comunicazioni` (
  `Id` INT(11) NOT NULL AUTO_INCREMENT ,
  `Gruppo` VARCHAR(45) NULL DEFAULT NULL ,
  `Inserita` DATETIME NULL DEFAULT NULL ,
  `Mittente` VARCHAR(45) NULL DEFAULT NULL ,
  `Destinatario` VARCHAR(45) NULL DEFAULT NULL ,
  `Oggetto` VARCHAR(255) NULL DEFAULT NULL ,
  `Testo` TEXT NULL DEFAULT NULL ,
  `Letta` TINYINT(1) UNSIGNED NULL DEFAULT '0' ,
  `Privata` TINYINT(1) UNSIGNED NULL DEFAULT '0' ,
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `cri`.`CAP_List`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `CAP_List` (
  `Id` INT(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `CAP` INT(10) UNSIGNED NOT NULL,
  `Comune` VARCHAR(45) NOT NULL,
  `Provincia` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;
-- -----------------------------------------------------
-- Table `cri`.`check_list_time`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `cri`.`check_list_time` (
  `Id` INT(10) NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NOT NULL,
  `Inizio` TIME NOT NULL,
  `Fine` TIME NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `cri`.`check_list_position`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `cri`.`check_list_position` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `Posizione` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `cri`.`check_list_type`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `cri`.`check_list_type` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `Tipo` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `cri`.`check_list_item`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `cri`.`check_list_item` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NOT NULL,
  `Gruppo` VARCHAR(45) NOT NULL,
  `check_list_position_Id` INT(10) UNSIGNED NOT NULL,
  `check_list_time_Id` INT(10) NOT NULL,
  `check_list_type_Id` INT(10) UNSIGNED NOT NULL,
  PRIMARY KEY (`Id`, `check_list_position_Id`, `check_list_time_Id`, `check_list_type_Id`),
  INDEX `fk_check_list_item_check_list_position1_idx` (`check_list_position_Id` ASC),
  INDEX `fk_check_list_item_check_list_time1_idx` (`check_list_time_Id` ASC),
  INDEX `fk_check_list_item_check_list_type1_idx` (`check_list_type_Id` ASC),
  CONSTRAINT `fk_check_list_item_check_list_position1`
    FOREIGN KEY (`check_list_position_Id`)
    REFERENCES `cri`.`check_list_position` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_check_list_item_check_list_time1`
    FOREIGN KEY (`check_list_time_Id`)
    REFERENCES `cri`.`check_list_time` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_check_list_item_check_list_type1`
    FOREIGN KEY (`check_list_type_Id`)
    REFERENCES `cri`.`check_list_type` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `cri`.`check_list`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `cri`.`check_list` (
  `Id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `Data` DATETIME NOT NULL,
  `Volontario` VARCHAR(45) NOT NULL,
  `check_list_item_Id` INT(10) UNSIGNED NOT NULL,
  `Verificato` TINYINT(1) NULL DEFAULT 0,
  `Valore` VARCHAR(45) NULL,
  PRIMARY KEY (`Id`, `check_list_item_Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC),
  INDEX `fk_check_list_check_list_item1_idx` (`check_list_item_Id` ASC),
  CONSTRAINT `fk_check_list_check_list_item`
    FOREIGN KEY (`check_list_item_Id`)
    REFERENCES `cri`.`check_list_item` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
