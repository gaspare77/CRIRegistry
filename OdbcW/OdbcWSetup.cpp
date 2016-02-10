#include "OdbcWSetup.h"

wxCriticalSection s_odbcWCriticalSection;

void _LOGMESSAGE_(const char* format, ...)
{
	char formattedMessage[2048];
	va_list va_cursor;

	va_start(va_cursor, format);
	vsprintf(formattedMessage, format, va_cursor);
	va_end(va_cursor);

	wxLogInfo( formattedMessage );
}

void _LOGERROR_(const char* format, ...)
{
	char formattedMessage[2048];
	va_list va_cursor;

	va_start(va_cursor, format);
	vsprintf(formattedMessage, format, va_cursor);
	va_end(va_cursor);

	wxLogError( formattedMessage );    
}

void _LOGWARNING_(const char* format, ...)
{
	char formattedMessage[2048];
	va_list va_cursor;

	va_start(va_cursor, format);
	vsprintf(formattedMessage, format, va_cursor);
	va_end(va_cursor);

	wxLogWarning( formattedMessage );    
}

void _LOGINFO_(const char* format, ...)
{
	char formattedMessage[2048];
	va_list va_cursor;

	va_start(va_cursor, format);
	vsprintf(formattedMessage, format, va_cursor);
	va_end(va_cursor);

	wxLogInfo( formattedMessage );
}
