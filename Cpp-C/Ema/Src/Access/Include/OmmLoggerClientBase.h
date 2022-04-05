/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright (C) 2019-2022 Refinitiv. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#ifndef __refinitiv_ema_access_OmmLoggerClientBase_h
#define __refinitiv_ema_access_OmmLoggerClientBase_h

#include "EmaString.h"
#include "Access/Impl/Mutex.h"
#include <cstdio>

namespace refinitiv::ema::access {

class OmmLoggerClientBase
{
public :

    enum Severity {
        VerboseEnum = 0,	// output all log messages including information
        SuccessEnum,		// indicates successful completion of a task / step
        WarningEnum,		// indicates completion of a task / step; may require attention and correction
        ErrorEnum,			// indicates failure while performing task / step; requires correction to proceed
        NoLogMsgEnum		// do not print any log messages
    };

    virtual void log( const EmaString& instanceName, Severity , const EmaString& text ) = 0;

    virtual void log( const EmaString& instanceName, Severity , const char* text ) = 0;

    virtual ~OmmLoggerClientBase() = 0;

protected:

    static Mutex			_printLock;

};

}

#endif // __refinitiv_ema_access_OmmLoggerClientBase_h
