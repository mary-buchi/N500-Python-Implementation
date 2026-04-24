//## begin module%3E19820B0114.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E19820B0114.cm

//## begin module%3E19820B0114.cp preserve=no
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
//## end module%3E19820B0114.cp

//## Module: EBDIintf%3E19820B0114; Package body
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDIintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E19820B0114.additionalIncludes preserve=no
//## end module%3E19820B0114.additionalIncludes

//## begin module%3E19820B0114.includes preserve=yes
//## end module%3E19820B0114.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPIfact
#include "EBPIfact.h"
// EBHIintf
#include "EBHIintf.h"
// EBDIintf
#include "EBDIintf.h"
// EBDIident
#include "EBDIident.h"


//## begin module%3E19820B0114.declarations preserve=no
//## end module%3E19820B0114.declarations

//## begin module%3E19820B0114.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}
//## end module%3E19820B0114.additionalDeclarations


// Class CDIDiagnosticInterface 



CDIDiagnosticInterface::CDIDiagnosticInterface (UINT p_uiID)
  //## begin CDIDiagnosticInterface::CDIDiagnosticInterface%1041861676.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CDIDiagnosticInterface::CDIDiagnosticInterface%1041861676.hasinit
  //## begin CDIDiagnosticInterface::CDIDiagnosticInterface%1041861676.initialization preserve=yes
  ,IPIDiagnosticInterface(DI_ID)
  //## end CDIDiagnosticInterface::CDIDiagnosticInterface%1041861676.initialization
{
  //## begin CDIDiagnosticInterface::CDIDiagnosticInterface%1041861676.body preserve=yes
	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(DI_ID);
	CString l_sTrace(_T(""));
	m_bHardwarePresent ? l_sTrace= _T("Yes") : l_sTrace= _T("No");
	CO_TRACE(DI_ID, (LPCTSTR)(_T("DiagnosticInterface HardwarePresent: ") +l_sTrace));
  //## end CDIDiagnosticInterface::CDIDiagnosticInterface%1041861676.body
}


CDIDiagnosticInterface::~CDIDiagnosticInterface()
{
  //## begin CDIDiagnosticInterface::~CDIDiagnosticInterface%.body preserve=yes
  //## end CDIDiagnosticInterface::~CDIDiagnosticInterface%.body
}



//## Other Operations (implementation)
CCOSyncObject* CDIDiagnosticInterface::Startup ()
{
  //## begin CDIDiagnosticInterface::Startup%1041861679.body preserve=yes
  DUMMY_RETURN
  //## end CDIDiagnosticInterface::Startup%1041861679.body
}

CCOSyncObject* CDIDiagnosticInterface::Shutdown ()
{
  //## begin CDIDiagnosticInterface::Shutdown%1041861680.body preserve=yes
  DUMMY_RETURN
  //## end CDIDiagnosticInterface::Shutdown%1041861680.body
}

CCOSyncObject* CDIDiagnosticInterface::ConnectionEstablished ()
{
  //## begin CDIDiagnosticInterface::ConnectionEstablished%1055770102.body preserve=yes
  DUMMY_RETURN
  //## end CDIDiagnosticInterface::ConnectionEstablished%1055770102.body
}

CCOSyncObject* CDIDiagnosticInterface::ConnectionLost ()
{
  //## begin CDIDiagnosticInterface::ConnectionLost%1055770103.body preserve=yes
  DUMMY_RETURN
  //## end CDIDiagnosticInterface::ConnectionLost%1055770103.body
}

UINT CDIDiagnosticInterface::GetuiID ()
{
  //## begin CDIDiagnosticInterface::GetuiID%1041922647.body preserve=yes
  return m_uiID;
  //## end CDIDiagnosticInterface::GetuiID%1041922647.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::ReadDWord (UINT p_uiAddress, EPIRegisterType p_eRegisterType)
{
  //## begin CDIDiagnosticInterface::ReadDWord%1041861677.body preserve=yes
	int l_iValue = 0;

	if (m_bHardwarePresent)													
		l_iValue = int(CHIInterface::GetInstance()->DIReadDWord((DWORD)p_uiAddress, p_eRegisterType));	

	CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_iValue);		
    l_pSyncObjInt->SignalCompletion();			
	CO_TRACE1(DI_ID, _T("DiagnosticInterface ReadDWord Address from: %d"), p_uiAddress);
	return l_pSyncObjInt;													 
  //## end CDIDiagnosticInterface::ReadDWord%1041861677.body
}

CCOSyncObject* CDIDiagnosticInterface::WriteDWord (UINT p_uiAddress, UINT p_uiValue, EPIRegisterType p_eRegisterType)
{
  //## begin CDIDiagnosticInterface::WriteDWord%1041861678.body preserve=yes
	CO_TRACE1(DI_ID, _T("DiagnosticInterface WriteDWord Address: %d"),p_uiAddress);
	if (m_bHardwarePresent)														
		CHIInterface::GetInstance()->DIWriteDWord((DWORD)p_uiAddress,(DWORD)p_uiValue, p_eRegisterType);

	DUMMY_RETURN
  //## end CDIDiagnosticInterface::WriteDWord%1041861678.body
}

CCOSyncObject* CDIDiagnosticInterface::EnableEventSignalisation ()
{
  //## begin CDIDiagnosticInterface::EnableEventSignalisation%1066028230.body preserve=yes
	CO_TRACE(DI_ID, _T("DiagnosticInterface EnableEventSignalisation"));
	CCOSyncObject* l_pSyncObj = NULL;
	if (m_bHardwarePresent)														
		l_pSyncObj = CHIInterface::GetInstance()->EnableEventSignalisation();

  return l_pSyncObj;
  //## end CDIDiagnosticInterface::EnableEventSignalisation%1066028230.body
}

CCOSyncObject* CDIDiagnosticInterface::DisableEventSignalisation ()
{
  //## begin CDIDiagnosticInterface::DisableEventSignalisation%1066028231.body preserve=yes
	CO_TRACE(DI_ID, _T("DiagnosticInterface DisableEventSignalisation"));
	CCOSyncObject* l_pSyncObj = NULL;
  if (m_bHardwarePresent)														
		l_pSyncObj = CHIInterface::GetInstance()->DisableEventSignalisation();

  return l_pSyncObj;
  //## end CDIDiagnosticInterface::DisableEventSignalisation%1066028231.body
}

CCOSyncObject* CDIDiagnosticInterface::PCSetNomVoltage (DWORD p_dwDACValue)
{
  //## begin CDIDiagnosticInterface::PCSetNomVoltage%1094803150.body preserve=yes
  CHIInterface::GetInstance()->PCSetNomVoltage(p_dwDACValue);

	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
  l_pSyncObj->SignalCompletion();
  return l_pSyncObj;
  //## end CDIDiagnosticInterface::PCSetNomVoltage%1094803150.body
}

CCOSyncObject* CDIDiagnosticInterface::PCLampSelection (EPILamp p_eSelection)
{
  //## begin CDIDiagnosticInterface::PCLampSelection%1094803151.body preserve=yes
  CHIInterface::GetInstance()->PCLampSelection(p_eSelection);
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
  l_pSyncObj->SignalCompletion();
  return l_pSyncObj;
  //## end CDIDiagnosticInterface::PCLampSelection%1094803151.body
}

CCOSyncObject* CDIDiagnosticInterface::PCLampOnOff (bool p_bSelection)
{
  //## begin CDIDiagnosticInterface::PCLampOnOff%1094803152.body preserve=yes
  CHIInterface::GetInstance()->PCLampOnOff(p_bSelection);
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
  l_pSyncObj->SignalCompletion();
  return l_pSyncObj;
  //## end CDIDiagnosticInterface::PCLampOnOff%1094803152.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::PCGetActCurrent ()
{
  //## begin CDIDiagnosticInterface::PCGetActCurrent%1094803153.body preserve=yes

  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  l_pSyncObjInt = CHIInterface::GetInstance()->PCGetActCurrent();

  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::PCGetActCurrent%1094803153.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::PCGetActVoltage (EPILamp p_eSelection)
{
  //## begin CDIDiagnosticInterface::PCGetActVoltage%1094803154.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  l_pSyncObjInt = CHIInterface::GetInstance()->PCGetActVoltage(p_eSelection);

  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::PCGetActVoltage%1094803154.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::PCGetLampIdentification (EPILamp p_eSelection)
{
  //## begin CDIDiagnosticInterface::PCGetLampIdentification%1094803155.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  l_pSyncObjInt = CHIInterface::GetInstance()->PCGetLampIdentification(p_eSelection);

  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::PCGetLampIdentification%1094803155.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::WCGetActVelocityCounts ()
{
  //## begin CDIDiagnosticInterface::WCGetActVelocityCounts%1094803156.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  l_pSyncObjInt = CHIInterface::GetInstance()->WCGetActVelocityCounts();

  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::WCGetActVelocityCounts%1094803156.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::WCGetLastVelocityCounts ()
{
  //## begin CDIDiagnosticInterface::WCGetLastVelocityCounts%1094803157.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  l_pSyncObjInt = CHIInterface::GetInstance()->WCGetLastVelocityCounts();

  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::WCGetLastVelocityCounts%1094803157.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::WCGetPosition ()
{
  //## begin CDIDiagnosticInterface::WCGetPosition%1094803158.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  l_pSyncObjInt = CHIInterface::GetInstance()->WCGetPosition();

  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::WCGetPosition%1094803158.body
}

CCOSyncObject* CDIDiagnosticInterface::WCInitializeDAC ()
{
  //## begin CDIDiagnosticInterface::WCInitializeDAC%1094803159.body preserve=yes
  CCOSyncObject* l_pSyncObj = NULL;
  l_pSyncObj = CHIInterface::GetInstance()->WCInitializeDAC();

  return l_pSyncObj;
  //## end CDIDiagnosticInterface::WCInitializeDAC%1094803159.body
}

CCOSyncObject* CDIDiagnosticInterface::WCSetDACValue (DWORD p_dwDACValue)
{
  //## begin CDIDiagnosticInterface::WCSetDACValue%1094803160.body preserve=yes
  CHIInterface::GetInstance()->WCSetDACValue(p_dwDACValue);
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
  l_pSyncObj->SignalCompletion();
  return l_pSyncObj;
  //## end CDIDiagnosticInterface::WCSetDACValue%1094803160.body
}

CCOSyncObjectCString* CDIDiagnosticInterface::ReadFpgaArtNr ()
{
  //## begin CDIDiagnosticInterface::ReadFpgaArtNr%1094803162.body preserve=yes
  CCOSyncObjectCString* l_pSyncObjStr = NULL;
  l_pSyncObjStr = CHIInterface::GetInstance()->ReadFpgaArtNr();

  return l_pSyncObjStr;
  //## end CDIDiagnosticInterface::ReadFpgaArtNr%1094803162.body
}

CCOSyncObjectCString* CDIDiagnosticInterface::ReadFpgaSwVersion ()
{
  //## begin CDIDiagnosticInterface::ReadFpgaSwVersion%1094803163.body preserve=yes
  CCOSyncObjectCString* l_pSyncObjStr = NULL;
  l_pSyncObjStr = CHIInterface::GetInstance()->ReadFpgaSwVersion();

  return l_pSyncObjStr;
  //## end CDIDiagnosticInterface::ReadFpgaSwVersion%1094803163.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::I2CEpromByteRead (DWORD p_uiObjID, WORD p_uiAddress)
{
  //## begin CDIDiagnosticInterface::I2CEpromByteRead%1094803164.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  
  IPII2CEprom24LC515* l_pI2CIntf = CPIObjectFactory::GetInstance()->CreateEprom24LC515(p_uiObjID, _T(""));
  l_pSyncObjInt = l_pI2CIntf->ByteRead(p_uiAddress);

  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::I2CEpromByteRead%1094803164.body
}

CCOSyncObject* CDIDiagnosticInterface::I2CEpromByteWrite (DWORD p_uiObjID, WORD p_uiAddress, BYTE p_cValue)
{
  //## begin CDIDiagnosticInterface::I2CEpromByteWrite%1094803166.body preserve=yes
  CCOSyncObject* l_pSyncObj = NULL;
  try
  {
  
    IPII2CEprom24LC515* l_pI2CIntf = CPIObjectFactory::GetInstance()->CreateEprom24LC515(p_uiObjID, _T(""));
    l_pSyncObj = l_pI2CIntf->ByteWrite(p_uiAddress, p_cValue);
  }
  catch(XCOExceptionError *l_pException)
  {
    l_pSyncObj->AttachException(l_pException);
  }
  return l_pSyncObj;
  //## end CDIDiagnosticInterface::I2CEpromByteWrite%1094803166.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::GetDigitsLaserLevelDetection ()
{
  //## begin CDIDiagnosticInterface::GetDigitsLaserLevelDetection%1097650515.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = NULL;
  l_pSyncObjInt = CHIInterface::GetInstance()->GetDigitsLaserLevelDetection();
  return l_pSyncObjInt;
  //## end CDIDiagnosticInterface::GetDigitsLaserLevelDetection%1097650515.body
}

CCOSyncObject* CDIDiagnosticInterface::ReleaseHWReset ()
{
  //## begin CDIDiagnosticInterface::ReleaseHWReset%1097650516.body preserve=yes
  CHIInterface::GetInstance()->EnableWatchdog(eHIWd10s);
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
  l_pSyncObj->SignalCompletion();
  return l_pSyncObj;
  //## end CDIDiagnosticInterface::ReleaseHWReset%1097650516.body
}

CCOSyncObject* CDIDiagnosticInterface::DisableWatchdog ()
{
  //## begin CDIDiagnosticInterface::DisableWatchdog%1097650517.body preserve=yes
  CHIInterface::GetInstance()->DisableWatchdog();
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
  l_pSyncObj->SignalCompletion();
  return l_pSyncObj;
  //## end CDIDiagnosticInterface::DisableWatchdog%1097650517.body
}

CCOSyncObjectCString* CDIDiagnosticInterface::GetOsVersion ()
{
  //## begin CDIDiagnosticInterface::GetOsVersion%1108365888.body preserve=yes
    CCOSyncObjectCString* l_pSyncObjStr = NULL;
    l_pSyncObjStr = CHIInterface::GetInstance()->GetOsVersion();

    return l_pSyncObjStr;
  //## end CDIDiagnosticInterface::GetOsVersion%1108365888.body
}

CCOSyncObjectInt* CDIDiagnosticInterface::GetUsedMemory ()
{
  //## begin CDIDiagnosticInterface::GetUsedMemory%1174554258.body preserve=yes
	MEMORYSTATUS l_MemState;
	GlobalMemoryStatus(&l_MemState);

	int l_iInUse = (int)((l_MemState.dwTotalPhys - l_MemState.dwAvailPhys) / 1024);

    CCOSyncObjectInt* l_pSyncObj = new CCOSyncObjectInt(l_iInUse);
    l_pSyncObj->SignalCompletion();
    return l_pSyncObj;
  //## end CDIDiagnosticInterface::GetUsedMemory%1174554258.body
}

CCOSyncObjectCString* CDIDiagnosticInterface::GetMemoryAllocInfo ()
{
  //## begin CDIDiagnosticInterface::GetMemoryAllocInfo%1174997741.body preserve=yes
#if defined(DEBUG) && defined(_WIN32_WCE)
	WCHAR* l_pBuffer = new WCHAR[32000];
	CString l_sInfo1 = ICORefCounting::GetLivingObjectInfo();

	::GetAllocatedBlockInfo(l_pBuffer, 32000);
	CString l_sInfo2 = l_pBuffer;

	CCOSyncObjectCString* l_pSyncObj = new CCOSyncObjectCString(l_sInfo1 + l_sInfo2);
	l_pSyncObj->SignalCompletion();

	delete[] l_pBuffer;
	return l_pSyncObj;
#else
	CCOSyncObjectCString* l_pSyncObj = new CCOSyncObjectCString(_T("Release Build does not contain any info"));
	l_pSyncObj->SignalCompletion();
	return l_pSyncObj;
#endif
  //## end CDIDiagnosticInterface::GetMemoryAllocInfo%1174997741.body
}

// Additional Declarations
  //## begin CDIDiagnosticInterface%3E198CAE029B.declarations preserve=yes
  //## end CDIDiagnosticInterface%3E198CAE029B.declarations

//## begin module%3E19820B0114.epilog preserve=yes
//## end module%3E19820B0114.epilog
