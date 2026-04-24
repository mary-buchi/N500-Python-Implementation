#include "stdafx.h"

#ifdef _DEBUG
	#include "EBCOdbg.h"

#if defined(DEBUG) && defined(CO_DEBUG_NEW)
	static garbageCollector gc(_T("EBCO"));

	_CrtMem*			_CrtMemRoot = 0;
	_CrtFileName*		_CrtFileNameRoot = 0;
	CCriticalSection    _CrtCriticalSection;
	int _CrtAllocCnt = 0;
#endif


int GetNumberOfAllocatedBlocks()
{
#if defined(DEBUG) && defined(CO_DEBUG_NEW)
	if (!_CrtMemRoot)
		return 0;
	else
	{
		_CrtMem*	_tmpMem;
		int l_iCnt=0;
		for (_tmpMem = _CrtMemRoot; _tmpMem; _tmpMem = _tmpMem->_CrtNext) {
			l_iCnt++;
		}

		return l_iCnt;
	}
#else
	return 0;
#endif
}

void GetAllocatedBlockInfo(WCHAR* p_pBuffer, const DWORD p_dwBufferSize)
{
#if defined(DEBUG) && defined(CO_DEBUG_NEW)
	WCHAR* l_pInfo = p_pBuffer;
	CSingleLock l_Lock(&_CrtCriticalSection, TRUE);
	if (!_CrtMemRoot)
		return;
	else
	{
		_CrtMem*	_tmpMem;
		int l_iCnt=0;
		for (_tmpMem = _CrtMemRoot; _tmpMem; _tmpMem = _tmpMem->_CrtNext)
		{
			if (l_pInfo-p_pBuffer > (int)(p_dwBufferSize - 100))
				l_pInfo += wsprintf(l_pInfo, _T("BlockAdr=0x%x, Length=%d, File=%s, Line=%d\n"), _tmpMem->_CrtMemAddr, _tmpMem->_CrtMemLen, _tmpMem->_CrtFileName->_CrtName, _tmpMem->_CrtLine);

			l_iCnt++;
		}
		wsprintf(l_pInfo, _T("NumberOfAllocatedBlocks=%d\n"), l_iCnt);
	}
#else
		wsprintf(p_pBuffer, _T("Not available in release mode or without CO_DEBUG_NEW"));
#endif
}

#if defined(DEBUG) && defined(CO_DEBUG_NEW)
void* operator new(
        unsigned int s,
        unsigned short* name,
        int line
        )
{
	CSingleLock l_Lock(&_CrtCriticalSection, TRUE);
	void*	retPtr = malloc (s);
	if (retPtr) {
		_CrtMem*	_crtMemCell = (struct _CrtMem*)malloc (sizeof(_CrtMem));
		_crtMemCell->_CrtLine		= line;
		_crtMemCell->_CrtMemLen		= s;
		_crtMemCell->_CrtMemAddr	= retPtr;
		_crtMemCell->_CrtNext		= 0;
		_crtMemCell->_CrtAllocCnt   = _CrtAllocCnt++;

		if (_CrtAllocCnt == -1)
		{
			int a=0;
		}
		
		_CrtFileName*	_tmpCrtFileName;
		for (_tmpCrtFileName = _CrtFileNameRoot; _tmpCrtFileName && wcscmp(name, _tmpCrtFileName->_CrtName); _tmpCrtFileName = _tmpCrtFileName->_CrtNext);
		if (!_tmpCrtFileName) {
			unsigned short*	_crtName = (unsigned short*)malloc ((wcslen (name) + 1) * sizeof(unsigned short));
			wcscpy (_crtName, name);
			_CrtFileName*	_crtFileName = (struct _CrtFileName*)malloc (sizeof (_CrtFileName));
			_crtFileName->_CrtName = _crtName;
			_crtFileName->_CrtNext = 0;
			if (!_CrtFileNameRoot)
				_CrtFileNameRoot = _crtFileName;
			else {
				for (_tmpCrtFileName = _CrtFileNameRoot; _tmpCrtFileName->_CrtNext; _tmpCrtFileName = _tmpCrtFileName->_CrtNext);
				_tmpCrtFileName->_CrtNext = _crtFileName;
			}
			_tmpCrtFileName = _crtFileName;
		}
		_crtMemCell->_CrtFileName = _tmpCrtFileName;

		if (!_CrtMemRoot) {
			_CrtMemRoot		= _crtMemCell;
		}
		else {
			_CrtMem*	_tmpMemPtr;
			for (_tmpMemPtr = _CrtMemRoot; _tmpMemPtr->_CrtNext; _tmpMemPtr = _tmpMemPtr->_CrtNext);
			_tmpMemPtr->_CrtNext = _crtMemCell;
		}
	}

	return retPtr;

}

void __cdecl operator delete(void *pvMem, unsigned short* name, int line)
{
	CSingleLock l_Lock(&_CrtCriticalSection, TRUE);
	if (pvMem) {
		_CrtMem*	_tmpMem;
		if (pvMem == _CrtMemRoot->_CrtMemAddr) {
			_tmpMem			= _CrtMemRoot;
			_CrtMemRoot		= _CrtMemRoot->_CrtNext;
			free (_tmpMem);
		}
		else {
			for (_tmpMem = _CrtMemRoot; _tmpMem->_CrtNext && (_tmpMem->_CrtNext->_CrtMemAddr != pvMem); _tmpMem = _tmpMem->_CrtNext);
			if (_tmpMem->_CrtNext) {
				_CrtMem*	_tmpMem2;
				_tmpMem2	= _tmpMem->_CrtNext;
				_tmpMem->_CrtNext = _tmpMem2->_CrtNext;
				free (_tmpMem2);
			}
			else
				NKDbgPrintfW (_T("%s(%i) : Warning : deletes memory pointer not allocated with new!\n"), _T(__FILE__), __LINE__);
		}
		free (pvMem);
	}
}

garbageCollector::~garbageCollector ()
{
	if (!_CrtMemRoot)
		NKDbgPrintfW (_T("'%s', No memory leaks detected!\n"), m_sInstance);
	else {
		_CrtMem*	_tmpMem;
		NKDbgPrintfW (_T("'%s', Detected memory leaks!\nDumping objects ->\n"), m_sInstance);
		for (_tmpMem = _CrtMemRoot; _tmpMem; _tmpMem = _tmpMem->_CrtNext) {
			NKDbgPrintfW (_T("%s(%i) : normal block at 0x%08X, Cnt=%d, %i bytes long\n Data <"), _tmpMem->_CrtFileName->_CrtName, _tmpMem->_CrtLine, _tmpMem->_CrtMemAddr, _tmpMem->_CrtAllocCnt, _tmpMem->_CrtMemLen);
			/*for (unsigned int i = 0; i < _tmpMem->_CrtMemLen; i++)
				NKDbgPrintfW (_T("%c"), *(((char*)_tmpMem->_CrtMemAddr)+i));
			NKDbgPrintfW (_T(">\n"));*/
		}
	}
	_CrtFileName*	_tmpName = _CrtFileNameRoot;
	for (;_tmpName;) {
		_CrtFileNameRoot	= _tmpName->_CrtNext;
		free(_tmpName->_CrtName);
		free(_tmpName);
		_tmpName			= _CrtFileNameRoot;
	}

}

#endif


#endif
