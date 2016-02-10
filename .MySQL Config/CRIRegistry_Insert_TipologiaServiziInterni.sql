-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `TipologiaServiziInterni`
-- -----------------------------------------------------
INSERT INTO `TipologiaServiziInterni` (`Tipo`) VALUES ('CAMBIO MEZZO');
INSERT INTO `TipologiaServiziInterni` (`Tipo`) VALUES ('RACCOLTA FONDI');
INSERT INTO `TipologiaServiziInterni` (`Tipo`) VALUES ('RIFORNIMENTO CARBURANTE');
INSERT INTO `TipologiaServiziInterni` (`Tipo`) VALUES ('SCUOLA GUIDA');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
