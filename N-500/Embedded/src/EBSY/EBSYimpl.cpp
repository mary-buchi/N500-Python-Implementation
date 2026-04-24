//## begin module%3EDC5B3C01E5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01E5.cm

//## begin module%3EDC5B3C01E5.cp preserve=no
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
//## end module%3EDC5B3C01E5.cp

//## Module: EBSYimpl%3EDC5B3C01E5; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C01E5.additionalIncludes preserve=no
//## end module%3EDC5B3C01E5.additionalIncludes

//## begin module%3EDC5B3C01E5.includes preserve=yes
//## end module%3EDC5B3C01E5.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"
// EBCOcomd
#include "EBCOcomd.h"
// EBSYsten
#include "EBSYsten.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYintf
#include "EBSYintf.h"
// EBSYmain
#include "EBSYmain.h"
// EBSYidnt
#include "EBSYidnt.h"
// EBSYexcp
#include "EBSYexcp.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3EDC5B3C01E5.declarations preserve=no
//## end module%3EDC5B3C01E5.declarations

//## begin module%3EDC5B3C01E5.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01E5.additionalDeclarations


// Class CSYSystemImplementation 




CSYSystemImplementation::CSYSystemImplementation (CSYSystemInterface* p_pInterface)
  //## begin CSYSystemImplementation::CSYSystemImplementation%1038899316.hasinit preserve=no
      : m_uiWarmupTimeout(30*60000), m_pSetInterfaceCfgSyncObj(NULL)
  //## end CSYSystemImplementation::CSYSystemImplementation%1038899316.hasinit
  //## begin CSYSystemImplementation::CSYSystemImplementation%1038899316.initialization preserve=yes
  , ICOAsyncImplementation(p_pInterface)
  //## end CSYSystemImplementation::CSYSystemImplementation%1038899316.initialization
{
  //## begin CSYSystemImplementation::CSYSystemImplementation%1038899316.body preserve=yes
  //## end CSYSystemImplementation::CSYSystemImplementation%1038899316.body
}


CSYSystemImplementation::~CSYSystemImplementation()
{
  //## begin CSYSystemImplementation::~CSYSystemImplementation%.body preserve=yes
    if (m_pSetInterfaceCfgSyncObj)
        m_pSetInterfaceCfgSyncObj->ReleaseRef();
    m_pSetInterfaceCfgSyncObj = NULL;
  //## end CSYSystemImplementation::~CSYSystemImplementation%.body
}



//## Other Operations (implementation)
void CSYSystemImplementation::InitInstance ()
{
  //## begin CSYSystemImplementation::InitInstance%1038899317.body preserve=yes
    m_pStateMachineEngine = new CSYStateMachineEngine(this);
    ICOAsyncImplementation::InitInstance();
  //## end CSYSystemImplementation::InitInstance%1038899317.body
}

EPIDeviceState CSYSystemImplementation::GetDeviceState ()
{
  //## begin CSYSystemImplementation::GetDeviceState%1056436743.body preserve=yes
    return dynamic_cast<CSYStateMachineEngine*>(m_pStateMachineEngine)->GetDeviceState();
  //## end CSYSystemImplementation::GetDeviceState%1056436743.body
}

void CSYSystemImplementation::RegisterClient (const CString& p_sClient)
{
  //## begin CSYSystemImplementation::RegisterClient%1096648856.body preserve=yes
    if (m_sCurrentClient == _T("") || m_sCurrentClient == p_sClient)
    {
        m_sCurrentClient = p_sClient;
    }
    else
    {
        // device is busy -> already connected
        throw new XSYExceptionErrorDeviceBusy(SY_ID, IDE_DEVICE_BUSY, __FILE__, __LINE__, m_sCurrentClient);
    }
  //## end CSYSystemImplementation::RegisterClient%1096648856.body
}

void CSYSystemImplementation::ResetClient ()
{
  //## begin CSYSystemImplementation::ResetClient%1096648861.body preserve=yes
    m_sCurrentClient = _T("");
  //## end CSYSystemImplementation::ResetClient%1096648861.body
}

CString CSYSystemImplementation::GetSoftwareVersion ()
{
  //## begin CSYSystemImplementation::GetSoftwareVersion%1096656418.body preserve=yes

#ifdef _WIN32_WCE
   VS_FIXEDFILEINFO sVSFixed;
   BYTE*            pVersionInfo;
   CString          sVersion;
   DWORD            dwLen         = 0;
   DWORD            dwDummyHandle = 1;      // dummy handle needed by ::GetFileVersionInfoSize
   bool             bRetval        = FALSE; // return value
   LPTSTR           szFilename = _T("NIRFlex.exe");

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
                            (sVSFixed.dwProductVersionMS >> 16),
                            (sVSFixed.dwProductVersionMS & 0x0000FFFF),
                            (sVSFixed.dwProductVersionLS >> 16),
                            (sVSFixed.dwProductVersionLS & 0x0000FFFF));
         }
      }

      delete [] pVersionInfo;
   }

   return sVersion;
#else
   return _T("2.4");
#endif
  //## end CSYSystemImplementation::GetSoftwareVersion%1096656418.body
}

bool CSYSystemImplementation::HandleErrorException (XCOExceptionError* p_pException)
{
  //## begin CSYSystemImplementation::HandleErrorException%1096648863.body preserve=yes
    if (dynamic_cast<XSYExceptionErrorDeviceBusy*>(p_pException) != NULL)
    {
        return true;
    }

    return ICOAsyncImplementation::HandleErrorException(p_pException);
  //## end CSYSystemImplementation::HandleErrorException%1096648863.body
}

CString CSYSystemImplementation::GetOsVersion ()
{
  //## begin CSYSystemImplementation::GetOsVersion%1108540800.body preserve=yes
	  CCOSyncObjectCString* l_pSyncObjStr = NULL;
	  l_pSyncObjStr = CHIInterface::GetInstance()->GetOsVersion();
	  l_pSyncObjStr->Synchronize();
	  CString sVersion = l_pSyncObjStr->GetValue();
	  l_pSyncObjStr->ReleaseRef();

	  return sVersion;
  //## end CSYSystemImplementation::GetOsVersion%1108540800.body
}

CString CSYSystemImplementation::GetFpgaVersion ()
{
  //## begin CSYSystemImplementation::GetFpgaVersion%1108540801.body preserve=yes
	CCOSyncObjectCString* l_pSyncObjStr = NULL;
	l_pSyncObjStr = CHIInterface::GetInstance()->ReadFpgaSwVersion();
	l_pSyncObjStr->Synchronize();
	CString sVersion = l_pSyncObjStr->GetValue();
	l_pSyncObjStr->ReleaseRef();

	return sVersion;
  //## end CSYSystemImplementation::GetFpgaVersion%1108540801.body
}

//## Get and Set Operations for Class Attributes (implementation)

UINT CSYSystemImplementation::GetuiWarmupTimeout ()
{
  //## begin CSYSystemImplementation::GetuiWarmupTimeout%4098868E0065.get preserve=no
  return m_uiWarmupTimeout;
  //## end CSYSystemImplementation::GetuiWarmupTimeout%4098868E0065.get
}

void CSYSystemImplementation::SetuiWarmupTimeout (UINT value)
{
  //## begin CSYSystemImplementation::SetuiWarmupTimeout%4098868E0065.set preserve=no
  m_uiWarmupTimeout = value;
  //## end CSYSystemImplementation::SetuiWarmupTimeout%4098868E0065.set
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObject * CSYSystemImplementation::GetpSetInterfaceCfgSyncObj ()
{
  //## begin CSYSystemImplementation::GetpSetInterfaceCfgSyncObj%4111F8B50150.get preserve=no
  return m_pSetInterfaceCfgSyncObj;
  //## end CSYSystemImplementation::GetpSetInterfaceCfgSyncObj%4111F8B50150.get
}

void CSYSystemImplementation::SetpSetInterfaceCfgSyncObj (CCOSyncObject * value)
{
  //## begin CSYSystemImplementation::SetpSetInterfaceCfgSyncObj%4111F8B50150.set preserve=yes
    if (m_pSetInterfaceCfgSyncObj)
        m_pSetInterfaceCfgSyncObj->ReleaseRef();

    m_pSetInterfaceCfgSyncObj = value;
    if (m_pSetInterfaceCfgSyncObj)
        m_pSetInterfaceCfgSyncObj->AddRef();
  //## end CSYSystemImplementation::SetpSetInterfaceCfgSyncObj%4111F8B50150.set
}

// Additional Declarations
  //## begin CSYSystemImplementation%3EDC5B9C009A.declarations preserve=yes
  //## end CSYSystemImplementation%3EDC5B9C009A.declarations

//## begin module%3EDC5B3C01E5.epilog preserve=yes
//## end module%3EDC5B3C01E5.epilog
