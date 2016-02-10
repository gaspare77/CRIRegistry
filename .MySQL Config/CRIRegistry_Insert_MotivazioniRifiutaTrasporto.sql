-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `MotivazioniRifiutaTrasporto`
-- -----------------------------------------------------
INSERT INTO `MotivazioniRifiutaTrasporto` (`Motivo`) VALUES ('DICE DI STARE MEGLIO');
INSERT INTO `MotivazioniRifiutaTrasporto` (`Motivo`) VALUES ('OSPEDALE NON GRADITO');
INSERT INTO `MotivazioniRifiutaTrasporto` (`Motivo`) VALUES ('SI RECA CON MEZZI PROPRI');
INSERT INTO `MotivazioniRifiutaTrasporto` (`Motivo`) VALUES ('CONTATTA LA GUARDIA MEDICA');

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
