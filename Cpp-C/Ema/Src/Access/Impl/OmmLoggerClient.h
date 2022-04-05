/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright (C) 2019-2021 Refinitiv. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#ifndef __refinitiv_ema_access_OmmLoggerClient_h
#define __refinitiv_ema_access_OmmLoggerClient_h

#include "EmaString.h"
#include "Mutex.h"
#include "OmmLoggerClientBase.h"
#include <stdio.h>

namespace refinitiv::ema::access {

static EmaString CR( "\n\t" );

struct LoggerFile {
	int			clientCount;
	FILE*		ptr;
	EmaString	*fileName;
	UInt32			fileNumber;
	UInt32			maxFileSize;
	UInt32			maxFileNumber;
};

struct LoggerClientFiles {
	int					fileCount;
	int					openFilesSize;
	struct LoggerFile*	openFiles;
};

class OmmLoggerClient : public OmmLoggerClientBase
{
public :

    using OmmLoggerClientBase::Severity;
    using OmmLoggerClientBase::VerboseEnum;
    using OmmLoggerClientBase::SuccessEnum;
    using OmmLoggerClientBase::WarningEnum;
    using OmmLoggerClientBase::ErrorEnum;
    using OmmLoggerClientBase::NoLogMsgEnum;

    EmaString				_logLine;

    bool					_includeDateInLoggerOutput;

    Severity				_severity;

	enum LoggerType {
		FileEnum = 0,
		StdoutEnum
	};

	static OmmLoggerClient* create( LoggerType loggerType, bool includeDate, Severity severity, const EmaString& fileName, UInt32 maxFileSize, UInt32 maxFileNumber );

	void log( const EmaString& instanceName, Severity , const EmaString& text );

	void log( const EmaString& instanceName, Severity , const char* text );

	static const char* loggerSeverityString( Severity );

	static char* timeString( bool includeDate = false );

    ~OmmLoggerClient();
private :

	OmmLoggerClient( LoggerType loggerType, bool includeDate, Severity severity, const EmaString& fileName, UInt32 maxFileSize, UInt32 maxFileNumber );

	void openLogFile( const EmaString&, UInt32 maxFileSize, UInt32 maxFileNumber );

	void closeLogFile();

	FILE*					_pOutput;

	int						_clientFileIndex;

	OmmLoggerClient();
	OmmLoggerClient( const OmmLoggerClient& );
	OmmLoggerClient& operator=( const OmmLoggerClient& );

	static LoggerClientFiles clientFiles;

	void addLogLine( const EmaString& callbackClientName, Severity severity, const char* text );
};

}

#endif // __refinitiv_ema_access_OmmLoggerClient_h
