// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifndef _WIN32_WCE
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
// #include <afxsock.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxmt.h>			// MFC mutli thread stuff.
#include <afxtempl.h>       // MFC mutli thread stuff. 
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#define _INC_WINDOWS
#include <winsock2.h>
//#include "afx.h"
#else

#include <windows.h>

#endif
//#include "dllie.h"


// TODO: reference additional headers your program requires here
