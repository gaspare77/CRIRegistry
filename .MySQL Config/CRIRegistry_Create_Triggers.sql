-- -----------------------------------------------------
-- Data for database `cri`
-- -----------------------------------------------------
USE `cri`;
START TRANSACTION;

-- -----------------------------------------------------
-- Triggers for database `cri`
-- -----------------------------------------------------
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
-- Commit all Data into database `cri`
-- -----------------------------------------------------
COMMIT;
