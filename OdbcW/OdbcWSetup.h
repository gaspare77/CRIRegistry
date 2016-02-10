//
// OdbcWSetup.h
//
#ifndef _ODBCWSETUP_H_FILE_
#define  _ODBCWSETUP_H_FILE_

//
// Application dependent definitions
//
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string>
#include <wx/thread.h>
#include <wx/intl.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <windows.h>

extern wxCriticalSection s_odbcWCriticalSection;
#define _SYNCRONIZE_ wxCriticalSectionLocker __criticalSectionLocker__(s_odbcWCriticalSection);

void _LOGMESSAGE_(const char* format, ...);
void _LOGERROR_(const char* format, ...);
void _LOGWARNING_(const char* format, ...);
void _LOGINFO_(const char* format, ...);

#endif
