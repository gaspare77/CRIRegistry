-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `TipologiaMezzi`
-- -----------------------------------------------------
INSERT INTO `TipologiaMezzi` (`Tipo`) VALUES ('AUTOVETTURA');
INSERT INTO `TipologiaMezzi` (`Tipo`) VALUES ('FURGONE');
INSERT INTO `TipologiaMezzi` (`Tipo`) VALUES ('BASE');
INSERT INTO `TipologiaMezzi` (`Tipo`) VALUES ('INDIA');
INSERT INTO `TipologiaMezzi` (`Tipo`) VALUES ('PULMINO');
INSERT INTO `TipologiaMezzi` (`Tipo`) VALUES ('TRASPORTI');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
