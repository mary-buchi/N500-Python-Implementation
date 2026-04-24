// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "dllie.h"
#ifdef DEBUG
#include "EBCOdbg.h"
#endif

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
// #include <afxsock.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxmt.h>			// MFC mutli thread stuff.
#include <afxtempl.h>       // MFC mutli thread stuff. */
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#define _INC_WINDOWS
#include <winsock2.h>

#ifndef _WIN32_WCE
#include <math.h>
#endif

#include "EBCOsmon.h"
#define CO_TRACE(u,m)	{ \
		if (CCOSystemMonitorInterface::GetpMonitor()) { \
			CCOSystemMonitorInterface::GetpMonitor()->AddMessage((u),(m)); \
		} \
	}
#define CO_TRACE1(u,m,p)	{ \
		if (CCOSystemMonitorInterface::GetpMonitor()) { \
			CString l_sStr; l_sStr.Format((m),(p)); \
			CCOSystemMonitorInterface::GetpMonitor()->AddMessage((u),l_sStr); \
		} \
	}

// TODO: reference additional headers your program requires here
