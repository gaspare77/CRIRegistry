-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `Mailing_List`
-- -----------------------------------------------------
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE AREA 1 RIVOLI', 'area1.rivoli@cririvoli.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE AREA 1 GRUGLIASCO', 'area1.grugliasco@cririvoli.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE AREA 3 RIVOLI', 'area3.rivoli@cririvoli.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE AREA 3 GRUGLIASCO', 'area3.grugliasco@cririvoli.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE CENTRALINO', 'turcofranco1@tin.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE MEZZI', 'giovanni.tribastone@cririvoli.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE MATERIALI', 'renato.gri@cririvoli.it;roberto.fasano@cririvoli.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE PROGRAMMA CENTRALINO', 'gaspare.faraci@cririvoli.it');
INSERT INTO `Mailing_List` (`Nome`,`eMail`) VALUES ('RESPONSABILE RAPPORTI 118', 'resp118@cririvoli.it');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
