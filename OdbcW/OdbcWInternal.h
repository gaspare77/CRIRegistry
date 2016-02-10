//
// OdbcWInternal.h
//
#ifndef _ODBCWINTERNAL_H_HILE_
#define _ODBCWINTERNAL_H_HILE_

#include "OdbcW.h"

bool OdbcW_SqlInitEnvironment();
bool OdbcW_SqlFreeEnvironment();
bool OdbcW_SqlConnect(const OdbcWConnectionId& connectionId);
bool OdbcW_SqlFreeConnection(const OdbcWConnectionId& connectionId);
bool OdbcW_SqlConnectionReady(const OdbcWConnectionId& connectionId);
bool OdbcW_SqlExecuteQuery(const OdbcWConnectionId& connectionId, const char* sqlQueryString, OdbcW_QueryResultSet* resultSet);

#endif

