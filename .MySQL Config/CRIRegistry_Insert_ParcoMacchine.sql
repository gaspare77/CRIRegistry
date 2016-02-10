-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `ParcoMacchine`
-- -----------------------------------------------------
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101081', 'RIVOLI', 'TRASPORTI', 'CRI 15803');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101082', 'RIVOLI', 'TRASPORTI', 'CRI 15214');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101083', 'RIVOLI', 'TRASPORTI', 'CRI 15804');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101084', 'RIVOLI', 'BASE', 'CRI 816 AA');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101085', 'RIVOLI', 'TRASPORTI', 'CRI 14404');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101086', 'RIVOLI', 'TRASPORTI', 'CRI 15080');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101087', 'RIVOLI', 'BASE', 'CRI 370 AC');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101088', 'RIVOLI', 'BASE', 'CRI 304 AB');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('101581', 'GRUGLIASCO', 'BASE', 'CRI 369 AC');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('102081', 'RIVOLI', 'CAMION', 'CRI A 3052');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('102084', 'RIVOLI', 'AUTOVETTURA', 'CRI A 2244');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('102086', 'RIVOLI', 'PULMINO', 'CRI A 292');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('102087', 'RIVOLI', 'PULMINO', 'CRI A 883');
INSERT INTO `parcomacchine` (`CodiceMezzo`, `Gruppo`, `Tipo`, `Targa`) VALUES ('102581', 'GRUGLIASCO','AUTOVETTURA','CRI 917 AC');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
