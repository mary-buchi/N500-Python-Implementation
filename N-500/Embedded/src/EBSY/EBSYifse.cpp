//## begin module%3EF98CC801C3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF98CC801C3.cm

//## begin module%3EF98CC801C3.cp preserve=no
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
//## end module%3EF98CC801C3.cp

//## Module: EBSYifse%3EF98CC801C3; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYifse.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF98CC801C3.additionalIncludes preserve=no
//## end module%3EF98CC801C3.additionalIncludes

//## begin module%3EF98CC801C3.includes preserve=yes
#include <atlbase.h>
//## end module%3EF98CC801C3.includes

// EBPItype
#include "EBPItype.h"
// EBSYifse
#include "EBSYifse.h"
//## begin module%3EF98CC801C3.declarations preserve=no
//## end module%3EF98CC801C3.declarations

//## begin module%3EF98CC801C3.additionalDeclarations preserve=yes
static const long  lBuffSize = 511;

#ifdef _WIN32_WCE
//static const WCHAR sIpAddrSetupKey[] = _T("Comm\\PCI\\VT30651\\Parms\\TCPIP"); // WinCE 4.2.NET
static const WCHAR sIpAddrSetupKey[] = _T("Comm\\PCI\\FETCE5B1\\Parms\\TCPIP");
#else
//static const WCHAR sIpAddrSetupKey[] = _T("SOFTWARE\\GeminiII\\Comm\\PCI\\VT30651\\Parms\\TCPIP"); // WinCE 4.2.NET
static const WCHAR sIpAddrSetupKey[] = _T("SOFTWARE\\GeminiII\\Comm\\PCI\\FETCE5B1\\Parms\\TCPIP");
#endif

static const WCHAR sIpAddrName[]     = _T("IpAddress");
static const WCHAR sIpMaskName[]     = _T("SubnetMask");
static const WCHAR sIpGatewayName[]  = _T("DefaultGateway");
static const WCHAR sIpAutoCfg[]      = _T("AutoCfg");
static const WCHAR sIpAutoDHCP[]     = _T("EnableDHCP");

static const WCHAR sEmpty[]          = _T("");

//## end module%3EF98CC801C3.additionalDeclarations


// Class CSYInterfaceSettings 


//## Other Operations (implementation)
CString CSYInterfaceSettings::ReadValue (const CString& p_sKeyName, const CString& p_sValueName)
{
  //## begin CSYInterfaceSettings::ReadValue%1056542787.body preserve=yes

    CRegKey  RegKey;
    WCHAR    p_sValue[64];
    ULONG    ulSize     = 128;
    CString  sRetVal    = sEmpty;

    p_sValue[64] = 0; // Set last byte to zero (prevent overflow of buffer

    // Open key
    if (RegKey.Open(HKEY_LOCAL_MACHINE, p_sKeyName) == ERROR_SUCCESS)
    {
        // Read value
#ifdef _WIN32_WCE
            if(RegKey.QueryValue(p_sValue, p_sValueName, &ulSize) == ERROR_SUCCESS)
#else
            if(RegKey.QueryStringValue(p_sValueName, p_sValue, &ulSize) == ERROR_SUCCESS)
#endif
        {
            sRetVal = p_sValue;
        }

        ASSERT (RegKey.Close() == ERROR_SUCCESS);

    }

    return sRetVal;

  //## end CSYInterfaceSettings::ReadValue%1056542787.body
}

bool CSYInterfaceSettings::WriteValue (const CString& p_sKeyName, const CString& p_sValueName, const CString& p_sValue)
{
  //## begin CSYInterfaceSettings::WriteValue%1056542788.body preserve=yes

    CRegKey  RegKey;
    bool     bRetVal    = false;

    // Open key
    if (RegKey.Open(HKEY_LOCAL_MACHINE, p_sKeyName) == ERROR_SUCCESS)
    {
        // Write value
#ifdef _WIN32_WCE
        if(RegKey.SetValue(p_sValue, p_sValueName) == ERROR_SUCCESS)
#else
        if (RegKey.SetStringValue(p_sValueName, p_sValue) == ERROR_SUCCESS)
#endif
        {
            bRetVal = true;
        }

        ASSERT (RegKey.Close() == ERROR_SUCCESS);
    }

    return bRetVal;

  //## end CSYInterfaceSettings::WriteValue%1056542788.body
}

bool CSYInterfaceSettings::WriteValue (const CString& p_sKeyName, const CString& p_sValueName, const DWORD& p_dwValue)
{
  //## begin CSYInterfaceSettings::WriteValue%1091609204.body preserve=yes
    CRegKey  RegKey;
    bool     bRetVal    = false;

    // Open key
    if (RegKey.Open(HKEY_LOCAL_MACHINE, p_sKeyName) == ERROR_SUCCESS)
    {
        // Write value
#ifdef _WIN32_WCE
        if(RegKey.SetValue(p_dwValue, p_sValueName) == ERROR_SUCCESS)
#else
        if (RegKey.SetDWORDValue(p_sValueName, p_dwValue) == ERROR_SUCCESS)
#endif
        {
            bRetVal = true;
        }

        ASSERT (RegKey.Close() == ERROR_SUCCESS);
    }

    return bRetVal;
  //## end CSYInterfaceSettings::WriteValue%1091609204.body
}

bool CSYInterfaceSettings::SetIPAddress (CPIInterfaceConfig* p_pInterfaceConfig)
{
  //## begin CSYInterfaceSettings::SetIPAddress%1056543512.body preserve=yes

    in_addr inAddr;
    CString sInetAddr;
    CString sInetMask;
    CString sInetGateWay;

    inAddr.S_un.S_addr = p_pInterfaceConfig->GetdwAddress();
    sInetAddr  = inet_ntoa(inAddr);

    inAddr.S_un.S_addr = p_pInterfaceConfig->GetdwMask();
    sInetMask  = inet_ntoa(inAddr);

    inAddr.S_un.S_addr = p_pInterfaceConfig->GetdwGateway();
    sInetGateWay  = inet_ntoa(inAddr);

    WriteValue(sIpAddrSetupKey, sIpAddrName,    sInetAddr);
    WriteValue(sIpAddrSetupKey, sIpMaskName,    sInetMask);
    WriteValue(sIpAddrSetupKey, sIpGatewayName, sInetGateWay);

    WriteValue(sIpAddrSetupKey, sIpAutoCfg, (DWORD)p_pInterfaceConfig->GetbUseDHCP());
    WriteValue(sIpAddrSetupKey, sIpAutoDHCP,(DWORD)p_pInterfaceConfig->GetbUseDHCP());

    // persist settings
    CRegKey  RegKey;
    if (RegKey.Open(HKEY_LOCAL_MACHINE, sIpAddrSetupKey) == ERROR_SUCCESS)
    {
        ::RegFlushKey((HKEY)RegKey);
    }
    RegKey.Close();

    return true;

  //## end CSYInterfaceSettings::SetIPAddress%1056543512.body
}

// Additional Declarations
  //## begin CSYInterfaceSettings%3EF98D7302DC.declarations preserve=yes
  //## end CSYInterfaceSettings%3EF98D7302DC.declarations

//## begin module%3EF98CC801C3.epilog preserve=yes
//## end module%3EF98CC801C3.epilog
