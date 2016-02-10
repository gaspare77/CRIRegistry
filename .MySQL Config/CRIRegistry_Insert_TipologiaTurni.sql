-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `TipologiaTurni`
-- -----------------------------------------------------
INSERT INTO `TipologiaTurni` (`Tipo`) VALUES ('ASSISTENZA');
INSERT INTO `TipologiaTurni` (`Tipo`) VALUES ('BASE');
INSERT INTO `TipologiaTurni` (`Tipo`) VALUES ('CENTRALINO');
INSERT INTO `TipologiaTurni` (`Tipo`) VALUES ('INDIA');
INSERT INTO `TipologiaTurni` (`Tipo`) VALUES ('MANIFESTAZIONE');
INSERT INTO `TipologiaTurni` (`Tipo`) VALUES ('PULIZIA SEDE');
INSERT INTO `TipologiaTurni` (`Tipo`) VALUES ('PULIZIA MEZZO');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
