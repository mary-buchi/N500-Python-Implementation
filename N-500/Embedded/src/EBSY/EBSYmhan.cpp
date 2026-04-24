//## begin module%3ED367E3023F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ED367E3023F.cm

//## begin module%3ED367E3023F.cp preserve=no
//	/*====================================================*
//	  * Copyright  : Büchi Labortechnik AG, Meierseggstr. 40,
//	  *                   9230 Flawil, Switzerland.
//	  *
//	  * Filename   : $Workfile:$
//	  * System     :
//	  * Function   :
//	  * Author     :
//	  * References :
//	  * Contents   :
//	  *
//	  * $History:$
//	  *=====================================================*
//	  */
//## end module%3ED367E3023F.cp

//## Module: EBSYmhan%3ED367E3023F; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYmhan.cpp

// stdafx
#include "stdafx.h"
//## begin module%3ED367E3023F.additionalIncludes preserve=no
//## end module%3ED367E3023F.additionalIncludes

//## begin module%3ED367E3023F.includes preserve=yes
//## end module%3ED367E3023F.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBSYdlld
#include "EBSYdlld.h"
// EBSYidnt
#include "EBSYidnt.h"
// EBSYmhan
#include "EBSYmhan.h"


//## begin module%3ED367E3023F.declarations preserve=no
//## end module%3ED367E3023F.declarations

//## begin module%3ED367E3023F.additionalDeclarations preserve=yes
//## end module%3ED367E3023F.additionalDeclarations


// Class CSYModuleHandling 

//## begin CSYModuleHandling::aLoadedDLLs%3EEED3620315.role preserve=no  public: static CMapStringToPtr { -> VFHN}
CMapStringToPtr CSYModuleHandling::m_aLoadedDLLs;
//## end CSYModuleHandling::aLoadedDLLs%3EEED3620315.role

//## begin CSYModuleHandling::RegisteredDLLs%4099084F0154.role preserve=no  public: static bool { -> VFHN}
CMap<HMODULE, HMODULE&, bool, bool&> CSYModuleHandling::m_RegisteredDLLs;
//## end CSYModuleHandling::RegisteredDLLs%4099084F0154.role

CSYModuleHandling::CSYModuleHandling()
  //## begin CSYModuleHandling::CSYModuleHandling%.hasinit preserve=no
  //## end CSYModuleHandling::CSYModuleHandling%.hasinit
  //## begin CSYModuleHandling::CSYModuleHandling%.initialization preserve=yes
  //## end CSYModuleHandling::CSYModuleHandling%.initialization
{
  //## begin CSYModuleHandling::CSYModuleHandling%.body preserve=yes
  //## end CSYModuleHandling::CSYModuleHandling%.body
}


CSYModuleHandling::~CSYModuleHandling()
{
  //## begin CSYModuleHandling::~CSYModuleHandling%.body preserve=yes
  //## end CSYModuleHandling::~CSYModuleHandling%.body
}



//## Other Operations (implementation)
bool CSYModuleHandling::LoadAllDLLs (bool p_bLoadAtStart)
{
  //## begin CSYModuleHandling::LoadAllDLLs%1054039295.body preserve=yes

    bool bRetVal = true;
    int i = 0;

    while (asDLLToLoadDirectory[i].m_sDllName)
    {
		if (p_bLoadAtStart)
		{
			if (asDLLToLoadDirectory[i].m_bLoadAtStart)
			{
				CO_TRACE1(SY_ID, _T("Loading Assembly '%s' ..."), (LPCTSTR)asDLLToLoadDirectory[i].m_sDllName);
				if (!LoadDLL(asDLLToLoadDirectory[i].m_sDllName))
				{
					bRetVal = false;
				}
			}
		}
		else
		{
			if (!asDLLToLoadDirectory[i].m_bLoadAtStart)
			{
				CO_TRACE1(SY_ID, _T("Loading Assembly '%s' ..."), (LPCTSTR)asDLLToLoadDirectory[i].m_sDllName);
				if (!LoadDLL(asDLLToLoadDirectory[i].m_sDllName))
				{
					bRetVal = false;
				}
			}
		}
		i++;
	}

    return bRetVal;

  //## end CSYModuleHandling::LoadAllDLLs%1054039295.body
}

bool CSYModuleHandling::UnloadAllDLLs ()
{
  //## begin CSYModuleHandling::UnloadAllDLLs%1054039296.body preserve=yes

    POSITION pos;
    bool     bRetVal = true;
    CString sDLLName = GetFirstDLLName(pos);

    while (sDLLName != "")
    {
        CO_TRACE1(SY_ID, _T("Unloading Assembly '%s' ..."), (LPCTSTR)sDLLName);
        if (!UnLoadDLL(sDLLName))
        {
            bRetVal = false;
        }
        sDLLName = GetNextDLLName(pos);
    }

    return bRetVal;

  //## end CSYModuleHandling::UnloadAllDLLs%1054039296.body
}

bool CSYModuleHandling::RegisterAllInterfaces (bool p_bLoadAtStart)
{
  //## begin CSYModuleHandling::RegisterAllInterfaces%1054039297.body preserve=yes

    POSITION pos;
    bool     bRetVal = true;
    CString sDLLName = GetFirstDLLName(pos);

    while (sDLLName != _T(""))
    {
		if (p_bLoadAtStart)
		{
			// register at start
			if (LoadAtStart(sDLLName))
			{
				if (!RegisterInterface(sDLLName))
				{
					bRetVal = false;
				}
			}
		}
		else
		{
			// register at start
			if (!LoadAtStart(sDLLName))
			{
				if (!RegisterInterface(sDLLName))
				{
					bRetVal = false;
				}
			}
		}
		sDLLName = GetNextDLLName(pos);
    }

	return bRetVal;

  //## end CSYModuleHandling::RegisterAllInterfaces%1054039297.body
}

bool CSYModuleHandling::DeRegisterAllInterfaces ()
{
  //## begin CSYModuleHandling::DeRegisterAllInterfaces%1054039298.body preserve=yes

    POSITION pos;
    bool     bRetVal = true;
    CString sDLLName = GetFirstDLLName(pos);

    while (sDLLName != _T(""))
    {
        if (!DeRegisterInterface(sDLLName))
        {
            bRetVal = false;
        }
        sDLLName = GetNextDLLName(pos);
    }

    m_RegisteredDLLs.RemoveAll();

    return bRetVal;

  //## end CSYModuleHandling::DeRegisterAllInterfaces%1054039298.body
}

bool CSYModuleHandling::ReadAllDLLVersions (CMapStringToString& p_rDLLVersionList)
{
  //## begin CSYModuleHandling::ReadAllDLLVersions%1056436737.body preserve=yes

    CString  sDLLName;
    CString  sDLLVersion;
    bool     bRetVal = true;
    int      i = 0;

    // Read Versions of Core-Component DLLS
    i=0;
    while (asCoreDLLDirectory[i].m_sDllName)
    {
        sDLLName = asCoreDLLDirectory[i].m_sDllName;
        sDLLVersion = CSYModuleHandling::GetDLLVersion(sDLLName);
        p_rDLLVersionList.SetAt(sDLLName, sDLLVersion);
        i++;
    }

    // Read Versions of ToLoad-Component DLLS
    i=0;
    while (asDLLToLoadDirectory[i].m_sDllName)
    {
        sDLLName = asDLLToLoadDirectory[i].m_sDllName;
        sDLLVersion = CSYModuleHandling::GetDLLVersion(sDLLName);
        p_rDLLVersionList.SetAt(sDLLName, sDLLVersion);
        i++;
    }

    return bRetVal;

  //## end CSYModuleHandling::ReadAllDLLVersions%1056436737.body
}

CString CSYModuleHandling::GetDLLVersion (const CString& p_sDLLName)
{
  //## begin CSYModuleHandling::GetDLLVersion%1055830876.body preserve=yes

   VS_FIXEDFILEINFO sVSFixed;
   BYTE*            pVersionInfo;
   CString          sVersion;
   DWORD            dwLen         = 0;
   DWORD            dwDummyHandle = 1;      // dummy handle needed by ::GetFileVersionInfoSize
   bool             bRetval        = FALSE; // return value
   LPTSTR           szFilename = const_cast<LPTSTR> ((LPCTSTR)p_sDLLName);

   dwLen = ::GetFileVersionInfoSize (szFilename, &dwDummyHandle);
   if (dwLen > 0)
   {
      ::ZeroMemory (&sVSFixed, sizeof (VS_FIXEDFILEINFO));
      pVersionInfo = new BYTE [dwLen]; // allocate version info
      if (::GetFileVersionInfo (szFilename, 0, dwLen, pVersionInfo) == TRUE)
      {
         UINT iLen = 0;
         LPVOID pVoid = NULL;
         if (::VerQueryValue (pVersionInfo, _T ("\\"), &pVoid, &iLen))
         {
            // copy VS_FIXED structure
            sVSFixed = *((VS_FIXEDFILEINFO*)pVoid);
            sVersion.Format(_T("%02d.%02d.%02d.%02d"), 
                            (sVSFixed.dwFileVersionMS >> 16),
                            (sVSFixed.dwFileVersionMS & 0x0000FFFF),
                            (sVSFixed.dwFileVersionLS >> 16),
                            (sVSFixed.dwFileVersionLS & 0x0000FFFF));
         }
      }

      delete [] pVersionInfo;
   }

   return sVersion;

  //## end CSYModuleHandling::GetDLLVersion%1055830876.body
}

HMODULE CSYModuleHandling::LoadDLL (const CString& p_sDLLName)
{
  //## begin CSYModuleHandling::LoadDLL%1055830870.body preserve=yes

  HMODULE hDLL = GetDLLHandle(p_sDLLName);

  // Load library only, if not already loaded (Do not increase reference cont of DLL)
  if (!hDLL)
  {
    hDLL = LoadLibrary(p_sDLLName);
    if (hDLL)
    {
        SetDLLHandle(p_sDLLName, hDLL);
    }
  }

  return hDLL;

  //## end CSYModuleHandling::LoadDLL%1055830870.body
}

bool CSYModuleHandling::UnLoadDLL (const CString& p_sDLLName)
{
  //## begin CSYModuleHandling::UnLoadDLL%1055830871.body preserve=yes

    bool bRetVal = false;
    HMODULE hDLL = GetDLLHandle(p_sDLLName); // Handle to DLL

    if (hDLL)
    {
      bRetVal = (FreeLibrary(hDLL) != 0);
    }

    // Remove key from lost of loaded modules
    m_aLoadedDLLs.RemoveKey(p_sDLLName);

    return (bRetVal);

  //## end CSYModuleHandling::UnLoadDLL%1055830871.body
}

void CSYModuleHandling::UnLoadDynamicDLLs ()
{
  //## begin CSYModuleHandling::UnLoadDynamicDLLs%1159966958.body preserve=yes
    int i = 0;

    while (asDLLToLoadDirectory[i].m_sDllName)
    {
		if (!asDLLToLoadDirectory[i].m_bLoadAtStart)
		{
			CO_TRACE1(SY_ID, _T("Unloading Assembly '%s' ..."), (LPCTSTR)asDLLToLoadDirectory[i].m_sDllName);
			DeRegisterInterface(asDLLToLoadDirectory[i].m_sDllName);
			UnLoadDLL(asDLLToLoadDirectory[i].m_sDllName);
		}

		i++;
	}
  //## end CSYModuleHandling::UnLoadDynamicDLLs%1159966958.body
}

bool CSYModuleHandling::RegisterInterface (const CString& p_sDLLName)
{
  //## begin CSYModuleHandling::RegisterInterface%1055830873.body preserve=yes

    HMODULE hDLL = GetDLLHandle(p_sDLLName);

    if (hDLL)
    {
        bool l_bIsRegistered = false;
        m_RegisteredDLLs.Lookup(hDLL, l_bIsRegistered);

        if (!l_bIsRegistered)
        {
#ifdef _WIN32_WCE
            FARPROC fnRegisterMethode = ::GetProcAddress(hDLL, _T("InitInstance"));
            if (fnRegisterMethode)
            {
                l_bIsRegistered = true;
                m_RegisteredDLLs.SetAt(hDLL, l_bIsRegistered);
                fnRegisterMethode();
            }
            else
            {
                hDLL = 0;
            }
#else
            // from function "GetProcAddress" only the ANSI version is available under Win NT/2000
            FARPROC fnRegisterMethode  = ::GetProcAddress(hDLL, "InitInstance");
            if (fnRegisterMethode)
            {
                l_bIsRegistered = true;
                m_RegisteredDLLs.SetAt(hDLL, l_bIsRegistered);
                fnRegisterMethode();
            }
            else
            {
                hDLL = 0;
            }
#endif
        }
    }

    return (hDLL != 0);    
  //## end CSYModuleHandling::RegisterInterface%1055830873.body
}

bool CSYModuleHandling::DeRegisterInterface (const CString& p_sDLLName)
{
  //## begin CSYModuleHandling::DeRegisterInterface%1055830874.body preserve=yes

    HMODULE hDLL = GetDLLHandle(p_sDLLName);

    if (hDLL)
    {
		m_RegisteredDLLs.RemoveKey(hDLL);
#ifdef _WIN32_WCE
        FARPROC fnDeRegisterMethode = ::GetProcAddress(hDLL, _T("ExitInstance"));
        if (fnDeRegisterMethode)
        {
            fnDeRegisterMethode();
        }
        else
        {
            hDLL = 0;
        }
#else
        // from function "GetProcAddress" only the ANSI version is available under Win NT/2000
        FARPROC fnDeRegisterMethode  = ::GetProcAddress(hDLL, "ExitInstance");
        if (fnDeRegisterMethode)
        {
            fnDeRegisterMethode();
        }
        else
        {
            hDLL = 0;
        }
#endif
    }

    return (hDLL != 0);

  //## end CSYModuleHandling::DeRegisterInterface%1055830874.body
}

CString CSYModuleHandling::GetFirstDLLName (POSITION& p_pPosition)
{
  //## begin CSYModuleHandling::GetFirstDLLName%1055830877.body preserve=yes

    CString  sDLLName;
    void*    pDummy;

    p_pPosition = m_aLoadedDLLs.GetStartPosition();
    if (p_pPosition)
    {
        m_aLoadedDLLs.GetNextAssoc(p_pPosition, sDLLName, pDummy);
    }
    else
    {
        sDLLName = "";
    }

    return sDLLName;

  //## end CSYModuleHandling::GetFirstDLLName%1055830877.body
}

CString CSYModuleHandling::GetNextDLLName (POSITION& p_pPosition)
{
  //## begin CSYModuleHandling::GetNextDLLName%1055830878.body preserve=yes

    CString  sDLLName;
    void*    pDummy;

    if (p_pPosition)
    {
        m_aLoadedDLLs.GetNextAssoc(p_pPosition, sDLLName, pDummy);
    }
    else
    {
        sDLLName = _T("");
    }

    return sDLLName;

  //## end CSYModuleHandling::GetNextDLLName%1055830878.body
}

HMODULE CSYModuleHandling::GetDLLHandle (const CString& p_sDLLName)
{
  //## begin CSYModuleHandling::GetDLLHandle%1055830872.body preserve=yes

    void *pTmp;
    if (m_aLoadedDLLs.Lookup(p_sDLLName, pTmp))
	{
		return (HMODULE)pTmp;
	}

    return NULL;

  //## end CSYModuleHandling::GetDLLHandle%1055830872.body
}

void CSYModuleHandling::SetDLLHandle (const CString& p_sDLLName, const HMODULE p_hDLL)
{
  //## begin CSYModuleHandling::SetDLLHandle%1055830875.body preserve=yes

    // Register DLL with name and handle
    // Use CMapToPointer to store the value of the HANDLE
    void *pTmp = p_hDLL;
    m_aLoadedDLLs.SetAt(p_sDLLName, pTmp);

  //## end CSYModuleHandling::SetDLLHandle%1055830875.body
}

void CSYModuleHandling::CleanupBackupDLLs ()
{
  //## begin CSYModuleHandling::CleanupBackupDLLs%1057322344.body preserve=yes

    try
    {
        BOOL                        bSuccess = TRUE;
        CString                     sDLLName = _T("");
        CString                     sDLLPath = _T("");
        HANDLE                      hFile;                    
        WIN32_FIND_DATA             fileData;
        
        CString sOldLocation = sOldDLLLocation;
        hFile = FindFirstFile(sOldLocation+_T("\\*.*"), &fileData);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            BOOL bWorking = TRUE;
            while (bWorking)
            {
                if (!(fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                {
                    sDLLName = fileData.cFileName;
                    sDLLPath = sOldLocation + _T("\\") + sDLLName;

	                // remove read only attribute
	                CFileStatus l_FileStatus;
	                if ( CFile::GetStatus( (LPCTSTR) sDLLPath, l_FileStatus ) )
	                {
		                // file exists
		                // remove readOnly attribute
		                l_FileStatus.m_attribute = 0;
		                CFile::SetStatus( (LPCTSTR) sDLLPath, l_FileStatus );
	                }

                    CO_TRACE1(SY_ID, _T("Delete DLL %s"), sDLLPath);
                    DeleteFile(sDLLPath);
                }
                bWorking = FindNextFile(hFile, &fileData);
            }
            FindClose(hFile);
		    RemoveDirectory(sOldDLLLocation);
        }
    }
    catch(CFileException* p_pException)
    {
        p_pException->Delete();
        throw new XCOExceptionCleanupInitialize(SY_ID, IDE_UPDATE_COMPONENT, __FILE__, __LINE__);
    }
  //## end CSYModuleHandling::CleanupBackupDLLs%1057322344.body
}

bool CSYModuleHandling::LoadAtStart (const CString& p_sDLLName)
{
  //## begin CSYModuleHandling::LoadAtStart%1074156378.body preserve=yes
	int i = 0;
    while (asDLLToLoadDirectory[i].m_sDllName)
    {
		if (p_sDLLName == asDLLToLoadDirectory[i].m_sDllName)
		{
			return asDLLToLoadDirectory[i].m_bLoadAtStart;
		}
		i++;
	}
	ASSERT(false);
	return false;
  //## end CSYModuleHandling::LoadAtStart%1074156378.body
}

// Additional Declarations
  //## begin CSYModuleHandling%3ED32C79029C.declarations preserve=yes
  //## end CSYModuleHandling%3ED32C79029C.declarations

//## begin module%3ED367E3023F.epilog preserve=yes
//## end module%3ED367E3023F.epilog
