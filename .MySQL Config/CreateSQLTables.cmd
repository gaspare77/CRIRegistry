@echo off

@set user=root
@set pwd=gfrgfr77
@set db=cri

@echo *****************************************************
@echo            CONFIGURAZIONE DATABASE MYSQL
@echo *****************************************************
@echo.

@echo Creazione tabelle in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% < CRIRegistry_Create.sql
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

@echo Inserimento dati Generali in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < CRIRegistry_Insert.sql
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert000
@set table=Comunicazioni
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert001 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert001
@set table=Gruppi
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert002 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert002
@set table=MotivazioniRifiutaTrasporto
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert003 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert003
@set table=Ospedali
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert004 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert004
@set table=ParcoMacchine
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert005 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert005
@set table=QueryList
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert006 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert006
@set table=RegistroPresenze
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert007 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert007
@set table=RegistroServizi
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert008 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert008
@set table=RegistroServizi_Equipaggi
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert009 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert009
@set table=RegistroServizi_Pazienti
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert010 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert010
@set table=RegistroServizi_Pazienti_Prestazioni
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert011 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert011
@set table=RegistroServizi_Pazienti_Dinamiche
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert012 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert012
@set table=RegistroTurni
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert013 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert013
@set table=TipologiaMezzi
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert014 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert014
@set table=TipologiaServizi118
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert015 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert015
@set table=TipologiaServiziInterni
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert016 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert016
@set table=TipologiaServiziOrdinari
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert017 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert017
@set table=TipologiaTurni
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert018 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert018
@set table=Users
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert019 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert019
@set table=Mailing_List
@set filename=CRIRegistry_Insert_%table%.sql
@if not exist %filename% goto Insert019 
@echo Inserimento dati nella tabella %table% in corso ...
@mysql.exe -h localhost -u%user% -p%pwd% -D%db% < %filename%
@if ERRORLEVEL 1 pause & exit 1
@echo Ok

:Insert020


:Exit
@echo.
@echo *****************************************************
@echo                OPERAZIONE COMPLETATA
@echo *****************************************************
@echo.
@pause
@exit 0