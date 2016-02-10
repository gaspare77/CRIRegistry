-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Data for table `Users`
-- -----------------------------------------------------
INSERT INTO `users` (`Nome`, `Cognome`, `User`, `Pwd`, `Privileges`) VALUES ('FRANCO', 'TURCO', 'franco.turco', md5('alfa159'), 5);

-- -----------------------------------------------------
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
