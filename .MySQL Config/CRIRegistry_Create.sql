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
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

DELIMITER $$
CREATE TRIGGER Insert_NumServizio
  BEFORE INSERT ON registroservizi
  FOR EACH ROW
  BEGIN
    DECLARE LastNumServizio INT(10) UNSIGNED;
    DECLARE LastNumServizioSup INT(10) UNSIGNED;

    SELECT max(NumServizio) INTO LastNumServizio FROM registroservizi WHERE year(Data)=year(NEW.Data);
    IF LastNumServizio IS NULL THEN
        SET LastNumServizio = 0;
    END IF;
    
    SELECT max(NumServizioSup) INTO LastNumServizioSup FROM registroservizi WHERE year(Data)=year(NEW.Data);
    IF LastNumServizioSup IS NULL THEN
        SET LastNumServizioSup = 0;
    END IF;

    IF NEW.NumServizio < 0 THEN
        SET NEW.NumServizio = LastNumServizio + 1;
    END IF;
    
    IF NEW.NumServizioSup < 0 THEN
        SET NEW.NumServizioSup = LastNumServizioSup + 1;
    END IF;
  END
$$
DELIMITER ;

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
  PRIMARY KEY (`Id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
