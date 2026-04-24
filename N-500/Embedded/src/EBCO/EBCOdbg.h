/*****************************************************************

FILENAME:	crtdbg.h

AUTHOR:		Ciprian Miclaus (Ciprian_Miclaus@yahoo.com)

DESCRIPTION:
Detects memory leaks in eVC++ almost the same way crtdbg does in VC++.
At the end of program execution it will display in the debug window if
there were any memory leaks and how the memory looks so you can identify
where your memory leak occurred. It will display in the debug window a
message saying no memory leaks detected if there are no memory leaks.
Similar to what crtdbg does in VC++.
It will fail to display the line same as crtdbg does.
There are 3 simple steps in order to enable memory leak detection:
1. Define _DEBUG
#define _DEBUG
2. Include "crtdbg.h"
#include "crtdbg.h"
3. Let your first line in the code be:
_CrtSetDbgFlag (ON);

Tips on debugging:
Tip 1:
Altho it doesn't display the line where the memory leak occurred (read
Tip 2), the utility display the address in hexa, and you can add a small
code to the operator new function, just after the first malloc:
	if (retPtr == (void*)0x76DA0)
		dumb instruction; <- place a breakpoint on this one
so you can detect easily which line of your code called the operator new
to allocate memory at the specified address and wasn't freed.
Tip 2:
Here's a trick that allow you to get the correct line and filename where
the memory leak occurred. Define the following line in every file, or define
it in a .h and include it in every file where you want accurate line and
filename:

#define new new(_T(__FILE__), __LINE__)

Happy debugging!

LICENSE: Public domain

COMMENTS:
Please report any bugs to Ciprian_Miclaus@yahoo.com.
You can use and distribute this code freely, but please keep these
few lines.
If you make any improvements, or have any ideas about how this code
could be improved or just you feel you need to comment this code in
any way, please send your comments, idea, imporvements to me to my 
email above.
The code doesn't detect memory leaks generated with C functions:
malloc, calloc, free, but that can be done in the future. Let me know
and I will program it.

********************************************************************/

#ifndef _CRTDBG_HEADER
#define _CRTDBG_HEADER

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//#include <tchar.h>

#ifdef _WIN_CE
	#include <windows.h>
#else
	#include <afxwin.h>         // MFC core and standard components
#endif

EBCO_DLL_DECL int GetNumberOfAllocatedBlocks();
EBCO_DLL_DECL void GetAllocatedBlockInfo(WCHAR* p_pBuffer, const DWORD p_dwBufferSize);

#if defined(DEBUG) && defined(CO_DEBUG_NEW)

extern "C" void WINAPIV NKDbgPrintfW(LPCWSTR lpszFmt, ...);


struct EBCO_DLL_DECL _CrtFileName {
	unsigned short*	_CrtName;
	_CrtFileName*	_CrtNext;
};

struct EBCO_DLL_DECL _CrtMem {
	_CrtFileName*	_CrtFileName;
	int				_CrtLine;
	unsigned int	_CrtMemLen;
	void*			_CrtMemAddr;
	_CrtMem*		_CrtNext;
	int             _CrtAllocCnt;
};

EBCO_DLL_DECL void* operator new(
        unsigned int s,
        unsigned short* name,
        int line
        );

EBCO_DLL_DECL void operator delete(
        void *pvMem,
        unsigned short* name,
        int line);

inline void* __cdecl operator new(unsigned int s)
        { return ::operator new(s, _T(__FILE__), __LINE__); }

inline void __cdecl operator delete(void *pvMem)
		{ ::operator delete(pvMem,_T(__FILE__),__LINE__); }

class EBCO_DLL_DECL garbageCollector {
public:
	garbageCollector (unsigned short* p_sInstance)
		: m_sInstance(p_sInstance) {}
	~garbageCollector ();

private:
	unsigned short* m_sInstance;
};

#define _CrtSetDbgFlag(ignore) \
		garbageCollector	gb;




#else

#define _CrtSetDbgFlag(ignore)

#endif //DEBUG

#endif //HEADER