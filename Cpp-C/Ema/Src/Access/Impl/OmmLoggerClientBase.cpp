/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright (C) 2019-2022 Refinitiv. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#include "OmmLoggerClientBase.h"


using namespace refinitiv::ema::access;

Mutex OmmLoggerClientBase::_printLock;

OmmLoggerClientBase::~OmmLoggerClientBase() {}
