-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `TipologiaServiziOrdinari`
-- -----------------------------------------------------
INSERT INTO `TipologiaServiziOrdinari` (`Tipo`) VALUES ('ASSISTENZA');
INSERT INTO `TipologiaServiziOrdinari` (`Tipo`) VALUES ('DIALISI');
INSERT INTO `TipologiaServiziOrdinari` (`Tipo`) VALUES ('MANIFESTAZIONE');
INSERT INTO `TipologiaServiziOrdinari` (`Tipo`) VALUES ('TRASPORTO');
INSERT INTO `tipologiaserviziordinari` (`Tipo`) VALUES ('GRUVILLAGE ASSISTENZA');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
