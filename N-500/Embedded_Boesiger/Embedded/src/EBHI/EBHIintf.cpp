//## begin module%3E2279BE0161.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E2279BE0161.cm

//## begin module%3E2279BE0161.cp preserve=no
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
//## end module%3E2279BE0161.cp

//## Module: EBHIintf%3E2279BE0161; Package body
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E2279BE0161.additionalIncludes preserve=no
//## end module%3E2279BE0161.additionalIncludes

//## begin module%3E2279BE0161.includes preserve=yes
#include <atlbase.h>
//## end module%3E2279BE0161.includes

// EBCOmark
#include "EBCOmark.h"
// EBCOsync
#include "EBCOsync.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBHIifid
#include "EBHIifid.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBHIrsm
#include "EBHIrsm.h"
// EBHIexcp
#include "EBHIexcp.h"
// EBHIthrd
#include "EBHIthrd.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIident
#include "EBHIident.h"
// EBHITrsm
#include "EBHITrsm.h"
// EBHITtype
#include "EBHITtype.h"


//## begin module%3E2279BE0161.declarations preserve=no
//## end module%3E2279BE0161.declarations

//## begin module%3E2279BE0161.additionalDeclarations preserve=yes
#ifdef _WIN32_WCE
  #include "pkfuncs.h"
#endif

#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}

//## end module%3E2279BE0161.additionalDeclarations


// Class IHIInterface 



IHIInterface::IHIInterface (const CString& p_sSubsystemID)
  //## begin IHIInterface::IHIInterface%1042447542.hasinit preserve=no
      : m_dwWCIrqNumber(0)
  //## end IHIInterface::IHIInterface%1042447542.hasinit
  //## begin IHIInterface::IHIInterface%1042447542.initialization preserve=yes
  //## end IHIInterface::IHIInterface%1042447542.initialization
{
  //## begin IHIInterface::IHIInterface%1042447542.body preserve=yes
  //## end IHIInterface::IHIInterface%1042447542.body
}


IHIInterface::~IHIInterface()
{
  //## begin IHIInterface::~IHIInterface%.body preserve=yes
  //## end IHIInterface::~IHIInterface%.body
}



//## Other Operations (implementation)
IHIInterface* IHIInterface::GetInstance ()
{
  //## begin IHIInterface::GetInstance%1043393618.body preserve=yes
  return CHIInterface::GetInstance();
  //## end IHIInterface::GetInstance%1043393618.body
}

//## Get and Set Operations for Class Attributes (implementation)

const DWORD IHIInterface::GetdwWCIrqNumber () const
{
  //## begin IHIInterface::GetdwWCIrqNumber%3E63337002CE.get preserve=no
  return m_dwWCIrqNumber;
  //## end IHIInterface::GetdwWCIrqNumber%3E63337002CE.get
}

void IHIInterface::SetdwWCIrqNumber (DWORD value)
{
  //## begin IHIInterface::SetdwWCIrqNumber%3E63337002CE.set preserve=no
  m_dwWCIrqNumber = value;
  //## end IHIInterface::SetdwWCIrqNumber%3E63337002CE.set
}

// Additional Declarations
  //## begin IHIInterface%3E2271C40106.declarations preserve=yes
  //## end IHIInterface%3E2271C40106.declarations

// Class CHIInterface 


//## begin CHIInterface::pInstance%3E22856A0182.role preserve=no  public: static CHIInterface {1..1 -> 1..1RFHN}
CHIInterface *CHIInterface::m_pInstance = NULL;
//## end CHIInterface::pInstance%3E22856A0182.role
















//## begin CHIInterface::pEventMask%3FCDD1010186.role preserve=no  public: static CHIIOCEventMasks {1..1 -> 1..1RFHN}
CHIIOCEventMasks *CHIInterface::m_pEventMask = NULL;
//## end CHIInterface::pEventMask%3FCDD1010186.role


CHIInterface::CHIInterface (UINT p_uiID)
  //## begin CHIInterface::CHIInterface%1042447564.hasinit preserve=no
      : m_uiID(p_uiID), m_pVa(NULL), m_pPa(NULL), m_dwPageSize(0), m_dwNumberOfPages(0), m_hPCIDevice(NULL), m_hPCIFile(NULL)
  //## end CHIInterface::CHIInterface%1042447564.hasinit
  //## begin CHIInterface::CHIInterface%1042447564.initialization preserve=yes
  ,IHIInterface(HI_ID)
  //## end CHIInterface::CHIInterface%1042447564.initialization
{
  //## begin CHIInterface::CHIInterface%1042447564.body preserve=yes
  m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(HI_ID);
  //## end CHIInterface::CHIInterface%1042447564.body
}


CHIInterface::~CHIInterface()
{
  //## begin CHIInterface::~CHIInterface%.body preserve=yes
	CO_TRACE(HI_ID, _T("EBHI - CHIInterface::~CHIInterface() completed"));

	for (POSITION l_Pos = m_NodeMap.GetStartPosition(); l_Pos != NULL;)
	{
		DWORD l_dwKey = 0;
		CHIProcessNodeConfig* l_pNodeCfg = NULL;
		m_NodeMap.GetNextAssoc(l_Pos, l_dwKey, l_pNodeCfg);
		delete l_pNodeCfg;
	}
	m_NodeMap.RemoveAll();

  m_IdMap.RemoveAll();
  m_TestProcImMap.RemoveAll();
  
  //## end CHIInterface::~CHIInterface%.body
}



//## Other Operations (implementation)
void CHIInterface::Create ()
{
  //## begin CHIInterface::Create%1042447561.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CHIInterface(1);
    m_pInstance->Initialize();

    CO_TRACE(HI_ID, _T("EBHI - CHIInterface::Create () completed"));
  //## end CHIInterface::Create%1042447561.body
}

void CHIInterface::Delete ()
{
  //## begin CHIInterface::Delete%1042447562.body preserve=yes
  if (m_pEventMask)
  {
    delete m_pEventMask;
  }
  m_pEventMask = NULL;

  if (m_pInstance)
  {
    m_pInstance->DeInitialize();
    delete m_pInstance;
  }
  m_pInstance = NULL;
  
  CO_TRACE(HI_ID, _T("EBHI - CHIInterface::Delete () completed"));
  //## end CHIInterface::Delete%1042447562.body
}

IHIInterface* CHIInterface::GetInstance ()
{
  //## begin CHIInterface::GetInstance%1043393617.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CHIInterface::GetInstance%1043393617.body
}

void CHIInterface::Initialize ()
{
  //## begin CHIInterface::Initialize%1042447565.body preserve=yes
  CHIIOCSetRSMAddress* l_pRSM = NULL;
  DWORD* l_pdwWCEventMask = NULL;
  DWORD* l_pdwHWEventMask = NULL;
  DWORD l_dwWCEventMaskSize = 0;
  DWORD l_dwHWEventMaskSize = 0;
  
  CCOVersion l_ConfigVersion = LoadConfig();

  try
  {
#ifdef _WIN32_WCE
    
    DWORD l_dwError = 0;
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwErrorLen = 0;




	//////////////////////////////////////////////////////
    // load driver with its information from 
    // [HKEY_LOCAL_MACHINE\Software\Buchi\NIRWare\Drivers\PCI]
    m_hPCIDevice = ActivateDeviceEx(_T("Software\\Buchi\\NIRWare\\Drivers\\PCI"),
                                    NULL,
                                    0,
                                    NULL);
    if (!m_hPCIDevice)
    {
      CString l_strErr = _T("");
      l_strErr.Format(_T("Initialize() - ActivateDeviceEx() return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

  ////////////////////////////////////////////////////////////////////////
    // load PCI stream device driver
    m_hPCIFile = CreateFile( _T("PCI1:"),                   // resource name
					                  GENERIC_WRITE | GENERIC_READ,  // access
					                  0,                             // share mode
					                  NULL,                          // security attributes must be NULL
					                  OPEN_EXISTING,                 // open file if exist
					                  FILE_ATTRIBUTE_NORMAL,         // attributes
					                  NULL);                         // template file
    
    if (m_hPCIFile == INVALID_HANDLE_VALUE)
    {
      l_dwError = GetLastError();
      CString l_strErr = _T("");
      l_strErr.Format(_T("Initialize() - CreateFile(PCI1:)) return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

    CCOSyncObjectCString* l_pSyncObjVersion = NULL;
    l_pSyncObjVersion = ReadFpgaSwVersion();
    l_pSyncObjVersion->Synchronize(2000);
  
    CCOVersion l_ActFPGAVersion = l_pSyncObjVersion->GetValue();
    l_pSyncObjVersion->ReleaseRef();

    // Compare actual FPGA Version with Config XML file
    if (l_ActFPGAVersion > l_ConfigVersion)
    {
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_FPGA_VERSION_MISMATCH, _T(__FILE__), __LINE__, 0);
    }
    
    // sets the WC IRQ number
    SetdwWCIrqNumber(ReadWCIrqNumber());

    /////////////////////////// 
    // allocate reserved shared memory for IFM-, laser data and process image
    CHIReservedSharedMemory::AllocRSMStreamBuffer();
    CHIReservedSharedMemory::AllocRSMProcessImage();


    // initialize shared memory instances
    CHITReservedSharedMemory::InitInstance(CHIReservedSharedMemory::GetpVAdrStreamBuffer(),
                                          CHIReservedSharedMemory::GetpVAdrProcessImage());

    ///////////////////////////////////////////////////////
    // create Hardware Worker Threads
    CHII2CWorkerThread::CreateInstance();
    
    CHIEventWorkerThread::CreateInstance(m_bHardwarePresent);
    CCOSyncObjectPtr l_pSyncObj = CHIEventWorkerThread::GetInstance()->GetpSyncObj();
    l_pSyncObj->Synchronize(10000);

    CHIDatapackageWorkerThread::CreateInstance(m_bHardwarePresent);


    l_pRSM = new CHIIOCSetRSMAddress(CHITReservedSharedMemory::GetclpPhysAdrStreamBuffer(),
                                     CHITReservedSharedMemory::GetclpPhysAdrProcessImage());
    
    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_SET_RSM_ADDRESS,            // control code for the operation  
                                  l_pRSM,
                                  sizeof(CHIIOCSetRSMAddress),
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    
    if (!l_dwRetVal)
    {
        l_dwError = 0;
        CString l_strErr = _T("");
        l_strErr.Format(_T("Initialize() - DeviceIoControl(IOCTL_HAL_PCI_SET_RSM_ADDRESS) return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

    ///////////////////////////////////////////////////////
    // set EventMask to default value -> all events masked
    m_pEventMask = new CHIIOCEventMasks();
    ASSERT(m_pEventMask);
    for (DWORD ii = 0; ii < CHITReservedSharedMemory::GetcdwNumbersOfWCEventReg(); ii++)
    {
      m_pEventMask->m_dwWCEventMask[ii] = 0xFFFFFFFF; // all WC events active
    }
    for (DWORD jj = 0; jj < CHITReservedSharedMemory::GetcdwNumbersOfEventReg(); jj++)
    {
      m_pEventMask->m_dwHWEventMask[jj] = 0xFFFFFFFF; // all HW events active
    }

    DWORD l_dwSize = sizeof(CHIIOCEventMasks);
    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_MASK_EVENT_REG,     // control code for the operation  
                                  m_pEventMask,
                                  l_dwSize,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);


    if (!l_dwRetVal)
    {
        CString l_strErr = _T("");
        l_strErr.Format(_T("Initialize() - DeviceIoControl(IOCTL_HAL_PCI_WC_MASK_EVENT_REG) return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
    //
    ////////////////////////////////////////////////////////

    CO_TRACE(HI_ID,_T("EBHI - CHIInterface::Initialize () completed"));




#else
    ///////////////////////////////////////////////////////
    // create Hardware Worker Threads (Send and Receive)
    CHII2CWorkerThread::CreateInstance();
    CHIEventWorkerThread::CreateInstance(m_bHardwarePresent);
    CHIDatapackageWorkerThread::CreateInstance(m_bHardwarePresent);
#endif
    if (l_pRSM)
    {
      delete l_pRSM;
    }
    l_pRSM = NULL;
  }
  catch(...)
  {
    if (l_pRSM)
    {
      delete l_pRSM;
    }
    l_pRSM = NULL;

    if (m_pEventMask)
    {
      delete m_pEventMask;
    }
    m_pEventMask = NULL;

    CO_TRACE(HI_ID,_T("EBHI - CHIInterface::Initialize () Exception occured!\r\n"));
    
    throw;
  }
  //## end CHIInterface::Initialize%1042447565.body
}

void CHIInterface::DeInitialize ()
{
  //## begin CHIInterface::DeInitialize%1042645876.body preserve=yes
#ifdef _WIN32_WCE
  BOOL l_bRetVal = 0;
  DWORD l_dwError = 0;

  ///////////////////////////////////////////////////////////
  // Destroy Hardware  Worker Threads
  CHIDatapackageWorkerThread::DeleteInstance();
  CHIEventWorkerThread::DeleteInstance();
  CHII2CWorkerThread::DeleteInstance();
  
  ///////////////////////////////////////////////////////////
  // close PCI stream device driver  
  if(m_hPCIFile)
  {
    l_bRetVal = CloseHandle(m_hPCIFile);
    if (!l_bRetVal)
    {
      l_dwError = GetLastError();
      CString l_strErr = _T("");
      l_strErr.Format(_T("DeInitialize() - CloseHandle() return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }

  ///////////////////////////////////////////////////////////
  // deactivate PCI device


  if (m_hPCIDevice)
  { 
  	l_bRetVal = DeactivateDevice(m_hPCIDevice);
    if (!l_bRetVal)
    {
      l_dwError = GetLastError();
      CString l_strErr = _T("");
      l_strErr.Format(_T("DeInitialize() - DeactivateDevice() return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }


  ///////////////////////////////////////////////////////////
  // delete shared memory instance
  CHITReservedSharedMemory::DeleteInstance();

  ///////////////////////////////////////////////////////////
  // deallocate shared memory (IFM-, laser data and process image)
  CHIReservedSharedMemory::DeAllocRSMStreamBuffer();
  CHIReservedSharedMemory::DeAllocRSMProcessImage();  

  CO_TRACE(HI_ID, _T("EBHI - CHIInterface::DeInitialize () completed"));
#else
  ///////////////////////////////////////////////////////////
  // Destroy Hardware  Worker Threads
  CHIDatapackageWorkerThread::DeleteInstance();
  CHIEventWorkerThread::DeleteInstance();
  CHII2CWorkerThread::DeleteInstance();
#endif
  //## end CHIInterface::DeInitialize%1042645876.body
}

DWORD CHIInterface::ReadWCIrqNumber ()
{
  //## begin CHIInterface::ReadWCIrqNumber%1046687700.body preserve=yes
  DWORD l_dwValue = 0;
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  
#ifdef _WIN32_WCE

  l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                IOCTL_HAL_PCI_DRIVER_READY,            // control code for the operation  
                                NULL,
                                0,
                                &l_dwValue,
                                l_dwErrorLen,
                                &l_dwReadBytes,
                                NULL);

  if (!l_dwRetVal)
  {
    CString l_strErr = _T("");
    l_strErr.Format(_T("ReadWCIrqNumber() return error %d\r\n"), l_dwError);
    CO_TRACE(HI_ID, l_strErr);
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
  }
#endif
  return l_dwValue;
  
  //## end CHIInterface::ReadWCIrqNumber%1046687700.body
}

DWORD CHIInterface::MCDataAcquisitionStart ()
{
  //## begin CHIInterface::MCDataAcquisitionStart%1049118884.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_DATA_ON,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        CString l_strErr = _T("");
        l_strErr.Format(_T("MCDataAcquisitionStart() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }
  else
  {
    CO_TRACE(HI_ID, _T("simulation mode - no hardware"));
    l_dwRetVal = TRUE;
  }
#endif
  return l_dwRetVal;
  //## end CHIInterface::MCDataAcquisitionStart%1049118884.body
}

DWORD CHIInterface::MCDataAcquisitionStop ()
{
  //## begin CHIInterface::MCDataAcquisitionStop%1049118885.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;

  // stop transfer mc data packages
  CCOSyncObjectPtr l_pSyncObj = CHIDatapackageWorkerThread::GetInstance()->Stop();
  l_pSyncObj->Synchronize();

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_DATA_OFF,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        CString l_strErr = _T("");
        l_strErr.Format(_T("MCDataAcquisitionStop() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }
  else
  {
    CO_TRACE(HI_ID, _T("simulation mode - no hardware\r\n"));
    l_dwRetVal = TRUE;
  }

#endif
  return l_dwRetVal;
  //## end CHIInterface::MCDataAcquisitionStop%1049118885.body
}

CPISyncObjDataPackage* CHIInterface::MCGetDataPackage ()
{
  //## begin CHIInterface::MCGetDataPackage%1042447549.body preserve=yes
  CO_TRACE(HI_ID, _T("CHIInterface::MCGetDataPackage () - Begin"));
  
  CPISyncObjDataPackage* l_pSyncObj = CHIDatapackageWorkerThread::GetInstance()->GetDataPackage();

  CO_TRACE(HI_ID, _T("CHIInterface::MCGetDataPackage () - End"));

  return l_pSyncObj;
  //## end CHIInterface::MCGetDataPackage%1042447549.body
}

DWORD CHIInterface::DIReadDWord (DWORD p_dwAddress, EPIRegisterType p_eRegisterType)
{
  //## begin CHIInterface::DIReadDWord%1042447559.body preserve=yes
#ifdef _WIN32_WCE
    CSingleLock l_Lock(&m_AccessLock, TRUE);
    // start address process image (write)
    PDWORD l_pdwAdr;
    if (p_eRegisterType == eWrite)
        l_pdwAdr = (PDWORD)(CHITReservedSharedMemory::GetUserProcImWriteBaseAdr());
    else
        l_pdwAdr = (PDWORD)(CHITReservedSharedMemory::GetUserProcImReadBaseAdr());

    // add offset address
    l_pdwAdr+= (p_dwAddress / sizeof(DWORD));

    return *l_pdwAdr;
#else
    return 0;
#endif
  //## end CHIInterface::DIReadDWord%1042447559.body
}

void CHIInterface::DIWriteDWord (DWORD p_dwAddress, DWORD p_dwValue, EPIRegisterType p_eRegisterType)
{
  //## begin CHIInterface::DIWriteDWord%1042447560.body preserve=yes
#ifdef _WIN32_WCE
    CSingleLock l_Lock(&m_AccessLock, TRUE);
    // start address process image (write)
    PDWORD l_pdwAdr;
    if (p_eRegisterType == eWrite)
        l_pdwAdr = (PDWORD)(CHITReservedSharedMemory::GetUserProcImWriteBaseAdr());
    else
        l_pdwAdr = (PDWORD)(CHITReservedSharedMemory::GetUserProcImReadBaseAdr());

    // add offset address
    l_pdwAdr+= (p_dwAddress / sizeof(DWORD));

    *l_pdwAdr = p_dwValue;
#endif
  //## end CHIInterface::DIWriteDWord%1042447560.body
}

void CHIInterface::WCReset ()
{
  //## begin CHIInterface::WCReset%1088517551.body preserve=yes
  if (m_bHardwarePresent)
  {
#ifdef _WIN32_WCE
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwError = 0;
    DWORD l_dwErrorLen = 0;

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_RESET,           // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCReset() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
#endif
  }
  else
  {
    CO_TRACE(HI_ID, _T("simulation mode - no hardware\r\n"));
  }
  //## end CHIInterface::WCReset%1088517551.body
}

void CHIInterface::WCStart ()
{
  //## begin CHIInterface::WCStart%1042527953.body preserve=yes
  if (m_bHardwarePresent)
  {
#ifdef _WIN32_WCE
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwError = 0;
    DWORD l_dwErrorLen = 0;

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_START,           // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCStart() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
#endif
  }
  else
  {
    CO_TRACE(HI_ID, _T("simulation mode - no hardware\r\n"));
  }
  //## end CHIInterface::WCStart%1042527953.body
}

CCOSyncObject* CHIInterface::WCStop (DWORD p_dwStoppedEvent)
{
  //## begin CHIInterface::WCStop%1042527954.body preserve=yes
  CCOSyncObject* l_pSyncObj = NULL;
  EHIOpenEventRegistration l_eType = eHIHigh;
#ifdef _WIN32_WCE
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

  if (m_bHardwarePresent)
  {
    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_STOP,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCStop() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
    l_pSyncObj = OpenEvent(p_dwStoppedEvent, l_eType);
  }
  else
  {
    CO_TRACE(HI_ID, _T("simulation mode - no hardware\r\n"));
    l_pSyncObj = new CCOSyncObject();
    l_pSyncObj->SignalCompletion();                  
  }
#else
    l_pSyncObj = new CCOSyncObject();
    l_pSyncObj->SignalCompletion();                  
#endif
  return l_pSyncObj;
  //## end CHIInterface::WCStop%1042527954.body
}

void CHIInterface::WCSetProfile (CHIIOCSetWCProfile* p_pProfile)
{
  //## begin CHIInterface::WCSetProfile%1042527955.body preserve=yes
#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwError = 0;
    DWORD l_dwErrorLen = 0;


    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_SETPROFILE,       // control code for the operation  
                                  p_pProfile,
                                  sizeof(CHIIOCSetWCProfile),
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCSetProfile() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
  else
  {
    CO_TRACE(HI_ID, _T("simulation mode - no hardware\r\n"));
  }
#endif
  //## end CHIInterface::WCSetProfile%1042527955.body
}

void CHIInterface::WCSetConfiguration (CHIIOCSetWCConfiguration* p_pConfig)
{
  //## begin CHIInterface::WCSetConfiguration%1042527956.body preserve=yes
#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwError = 0;
    DWORD l_dwErrorLen = 0;


    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_SETCONFIG,       // control code for the operation  
                                  p_pConfig,
                                  sizeof(CHIIOCSetWCConfiguration),
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCSetConfiguration() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
  else
  {
    CO_TRACE(HI_ID, _T("simulation mode - no hardware\r\n"));
  }
#endif
  //## end CHIInterface::WCSetConfiguration%1042527956.body
}

CCOSyncObject* CHIInterface::WCReferencing (DWORD p_dwReferencedEvent)
{
  //## begin CHIInterface::WCReferencing%1042527958.body preserve=yes
  CCOSyncObject* l_pSyncObj = NULL;
#ifdef _WIN32_WCE
  EHIOpenEventRegistration l_eType = eHIHigh;

  if (m_bHardwarePresent)
  {
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwError = 0;
    DWORD l_dwErrorLen = 0;

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_REFERENCING,     // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCReferencing() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
    l_pSyncObj = OpenEvent(p_dwReferencedEvent, l_eType);
  }
  else
  {
    l_pSyncObj = new CCOSyncObject;
    l_pSyncObj->SignalCompletion();
  }
#else
    l_pSyncObj = new CCOSyncObject();
    l_pSyncObj->SignalCompletion();
#endif

  return l_pSyncObj;
  //## end CHIInterface::WCReferencing%1042527958.body
}

DWORD CHIInterface::WCEmergencyStop ()
{
  //## begin CHIInterface::WCEmergencyStop%1068453037.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  DWORD l_dwRetVal = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_EMERGENCY_STOP,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);

    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCEmergencyStop() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
  else
  {
    l_dwRetVal = TRUE;
  }
#endif
  return l_dwRetVal;
  //## end CHIInterface::WCEmergencyStop%1068453037.body
}

DWORD CHIInterface::EnableWCIrq ()
{
  //## begin CHIInterface::EnableWCIrq%1046761789.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WCISR_ENABLE,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);

    if (!l_dwRetVal)
    {
        CString l_strErr = _T("");
        l_strErr.Format(_T("EnableWCIrq() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }
  else
  {
    l_dwRetVal = TRUE;
  }
#endif
  return l_dwRetVal;
  //## end CHIInterface::EnableWCIrq%1046761789.body
}

DWORD CHIInterface::DisableWCIrq ()
{
  //## begin CHIInterface::DisableWCIrq%1046761790.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

#ifdef _WIN32_WCE

  if (m_bHardwarePresent)
  {
    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WCISR_DISABLE,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
 
    if (!l_dwRetVal)
    {
      CString l_strErr = _T("");
      l_strErr.Format(_T("DisableWCIrq() return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }
  else
  {
    l_dwRetVal = TRUE;
  }
#endif
  return l_dwRetVal;
  //## end CHIInterface::DisableWCIrq%1046761790.body
}

void CHIInterface::TEST (DWORD p_Test)
{
  //## begin CHIInterface::TEST%1046940012.body preserve=yes
  DWORD *l_pAdr = CHITReservedSharedMemory::GetWedgePositionAdr ();
  l_pAdr = CHITReservedSharedMemory::GetWedgeActVelocityAdr();
  l_pAdr = CHITReservedSharedMemory::GetWedgeLastVelocityAdr();
  l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
  
  /*
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwError = 0;
    DWORD l_dwErrorLen = 0;
#ifdef _WIN32_WCE

    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_DATA_ON,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
 
    if (!l_dwRetVal)
    {
        CString l_strErr.Format(_T("TEST() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
#endif
    */

  //## end CHIInterface::TEST%1046940012.body
}

CCOSyncObject* CHIInterface::WCInitialize (DWORD p_dwInitializedEvent)
{
  //## begin CHIInterface::WCInitialize%1042527959.body preserve=yes
  CCOSyncObject* l_pSyncObj = NULL;
#ifdef _WIN32_WCE
  EHIOpenEventRegistration l_eType = eHIHigh;
  if (m_bHardwarePresent)
  {
    DWORD l_dwReadBytes = 0;
    DWORD l_dwRetVal = 0;
    DWORD l_dwError = 0;
    DWORD l_dwErrorLen = 0;

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_INI,             // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCInitialize() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
    l_pSyncObj = OpenEvent(p_dwInitializedEvent, l_eType);
  }
  else
  {
    l_pSyncObj = new CCOSyncObject;
    l_pSyncObj->SignalCompletion();
  }
#else
    l_pSyncObj = new CCOSyncObject;
    l_pSyncObj->SignalCompletion();
#endif
  return l_pSyncObj;
  //## end CHIInterface::WCInitialize%1042527959.body
}

DWORD CHIInterface::GetDWord (DWORD p_dwObjID)
{
  //## begin CHIInterface::GetDWord%1048077957.body preserve=yes
  // p_dwObjID = logical number of the data point
  // logical number layout:
  //
  //  MSB                                                                                          LSB
  //  31                   24 23                   16 15                   8  7                    0
  //  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
  //  |        |  |                                            |  |              |  |              |
  //  |        |  |                                            |  |              |  - - - - - - - - - - Bit Position; Values: 0..31
  //  |        |  |                                            |  |              |
  //  |        |  |                                            |  - - - - - - - - - - Data Width; Values: 1..32
  //  |        |  |                                            |
  //  |        |  - - - - - - - - - - - - - - - - - - - - - - - - - - Data Base Address Offset (DWORD); Value: 0x0 .. 0xFFFF FFFF
  //  |        |
  //  - - - - - - - - - - - - - - - - - - - - Data Control Bits; Values 0x0..0xF
  //                                          0x8:  1 = Write Log ID / 0 = Read Log ID
  //                                          0x4:  Reserve
  //                                          0x2:  1 = delete register content
  //                                          0x1:  1 = I2C Device
  //
  //  E.G.: 
  //  - digital input 2 (Bit Index)
  //  - Data Base Address Offset (Process Image): 0x1 (DWORD)
  //  - data width -> 1 (digital input!)
  //  - read bit = 0
  //
  //  -> Logical Number (l_dwID)
  //  MSB                                                                                          LSB
  //  31                   24 23                   16 15                   8  7                    0
  //  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  1  0  0  0  0  1  0  =>  0x1042
  //
  //
  //
  //  - digital value (e.g. 10 bit DAC) -> write value
  //  - value position in process image ex bit position 5
  //  - Data Base Address Offset (Process Image): 0x20 (DWORD)
  //  - data width -> 10 (bit)
  //  - write bit = 1
  //
  //  -> Logical Number (l_dwID)
  //  MSB                                                                                          LSB
  //  31                   24 23                   16 15                   8  7                    0
  //  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  1  0  1  0  0  0  0  1  0  1  =>  0x80020285
  //

  DWORD l_dwProcImOffsetAdr = 0;      // process image offset address
  DWORD l_dwProcImBitPos = 0;         // process image bit position
  DWORD l_dwProcImDataWidth = 0;      // process image data width
  DWORD l_dwProcImDataControlReg = 0; // process image data control register

  bool l_bDeleteRegisterContent = false;

  bool l_bProcImWriteReg = false;

  DWORD l_dwProcImBitMask = 0x1;
  DWORD l_dwProcImMask = 0;
  
  DWORD* l_pdwAdr = NULL;
  
  DWORD l_dwRetVal = 0;

#ifdef _WIN32_WCE
  // convert Object ID -> HW Log ID
  DWORD l_dwID = GetLogicalID(p_dwObjID);

  // determin process image offset address
  l_dwProcImOffsetAdr = (l_dwID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr();
  l_dwProcImBitPos = (l_dwID & CHIProcessImageParameter::GetcdwMaskBitPosition()) >> CHIProcessImageParameter::GetcdwShiftCountsBitPosition();
  l_dwProcImDataWidth = (l_dwID & CHIProcessImageParameter::GetcdwMaskDataWidth()) >> CHIProcessImageParameter::GetcdwShiftCountsDataWidth();
  l_dwProcImDataControlReg = (l_dwID & CHIProcessImageParameter::GetcdwMaskControlStates()) >> CHIProcessImageParameter::GetcdwShiftCountsControlStates();
  
  if (l_dwID & CHIProcessImageParameter::GetcdwMaskDeleteRegister())
  {
    l_bDeleteRegisterContent = true;
  }

  if ((l_dwProcImDataWidth > 32) || (l_dwProcImBitPos >= 32) || ((l_dwProcImBitPos + l_dwProcImDataWidth) > 32))
  {
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_WRONG_LOG_ID, _T(__FILE__), __LINE__, 0);
    return l_dwRetVal;
  }
  
  if (!(l_dwID && CHIProcessImageParameter::GetcdwMaskWriteBit()))
  { 
    l_bProcImWriteReg = true;
  }

  CSingleLock l_Lock(&m_AccessLock, TRUE);
  
  // determine Get Address -> Write or Read Process Image
  if (l_bProcImWriteReg)
  {
    // read from WRITE Process Image
    l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImWriteBaseAdr() + (l_dwProcImOffsetAdr / sizeof(DWORD));
  }
  else
  {
    // read from READ Process Image
    l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImReadBaseAdr() + (l_dwProcImOffsetAdr / sizeof(DWORD));
  }
  
  if (l_dwProcImDataWidth == 1)
  {
    // bit mask
    l_dwProcImBitMask = l_dwProcImBitMask << l_dwProcImBitPos;

    // read bit value
    *l_pdwAdr & l_dwProcImBitMask ? l_dwRetVal = TRUE : l_dwRetVal = FALSE;
  }
  else if (l_dwProcImDataWidth > 1)
  {
    // data mask
    for (DWORD ii = 0; ii < l_dwProcImDataWidth; ii++)
    {
      l_dwProcImMask = l_dwProcImMask | (l_dwProcImBitMask << ii);
      
    }
    
    // read value
    l_dwRetVal = (*l_pdwAdr >> l_dwProcImBitPos) & l_dwProcImMask;
  }
  else
  {
    // should never happen !!!
    ASSERT(FALSE);
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_WRONG_LOG_ID, _T(__FILE__), __LINE__, 0);
  }

  if (l_bDeleteRegisterContent)
  {
    // delete register content
    *l_pdwAdr = 0;
  }

#else
  l_dwRetVal = m_TestProcImMap[p_dwObjID];
#endif

  return l_dwRetVal;
  //## end CHIInterface::GetDWord%1048077957.body
}

DWORD CHIInterface::SetDWord (DWORD p_dwObjID, DWORD p_dwValue)
{
  //## begin CHIInterface::SetDWord%1048077958.body preserve=yes


  // p_dwObjID = logical number of the data point
  // logical number layout:
  //
  //  MSB                                                                                          LSB
  //  31                   24 23                   16 15                   8  7                    0
  //  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
  //  |        |  |                                            |  |              |  |              |
  //  |        |  |                                            |  |              |  - - - - - - - - - - Bit Position; Values: 0..31
  //  |        |  |                                            |  |              |
  //  |        |  |                                            |  - - - - - - - - - - Data Width; Values: 1..32
  //  |        |  |                                            |
  //  |        |  - - - - - - - - - - - - - - - - - - - - - - - - - - Data Base Address Offset (DWORD); Value: 0x0 .. 0xFFFF FFFF
  //  |        |
  //  - - - - - - - - - - - - - - - - - - - - Data Control Bits; Values 0x0..0xF
  //                                          0x8:  1 = Write Log ID / 0 = Read Log ID
  //                                          0x4:  Reserve
  //                                          0x2:  1 = delete register content
  //                                          0x1:  1 = I2C Device
  //
  //  E.G.: 
  //  - digital input 2 (Bit Index)
  //  - Data Base Address Offset (Process Image): 0x1 (DWORD)
  //  - data width -> 1 (digital input!)
  //  - read bit = 0
  //
  //  -> Logical Number (l_dwID)
  //  MSB                                                                                          LSB
  //  31                   24 23                   16 15                   8  7                    0
  //  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  1  0  0  0  0  1  0  =>  0x1042
  //
  //
  //
  //  - digital value (e.g. 10 bit DAC) -> write value
  //  - value position in process image ex bit position 5
  //  - Data Base Address Offset (Process Image): 0x20 (DWORD)
  //  - data width -> 10 (bit)
  //  - write bit = 1
  //
  //  -> Logical Number (l_dwID)
  //  MSB                                                                                          LSB
  //  31                   24 23                   16 15                   8  7                    0
  //  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  1  0  1  0  0  0  0  1  0  1  =>  0x80020285
  //
#ifdef _WIN32_WCE
  DWORD l_dwProcImOffsetAdr = 0;      // process image offset address
  DWORD l_dwProcImBitPos = 0;         // process image bit position
  DWORD l_dwProcImDataWidth = 0;      // process image data width
  DWORD l_dwProcImDataControlReg = 0; // process image data control register
  
  DWORD l_dwProcImBitMask = 0x1;
  DWORD l_dwProcImMask = 0;
  
  DWORD* l_pdwWriteAdr = NULL;

  // convert Object ID -> HW Log ID
  DWORD l_dwID = GetLogicalID(p_dwObjID);

  // determin process image offset address
  l_dwProcImOffsetAdr = (l_dwID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr();
  l_dwProcImBitPos = (l_dwID & CHIProcessImageParameter::GetcdwMaskBitPosition()) >> CHIProcessImageParameter::GetcdwShiftCountsBitPosition();
  l_dwProcImDataWidth = (l_dwID & CHIProcessImageParameter::GetcdwMaskDataWidth()) >> CHIProcessImageParameter::GetcdwShiftCountsDataWidth();
  l_dwProcImDataControlReg = (l_dwID & CHIProcessImageParameter::GetcdwMaskControlStates()) >> CHIProcessImageParameter::GetcdwShiftCountsControlStates();
  
  if (!(l_dwID && CHIProcessImageParameter::GetcdwMaskWriteBit()))
  { 
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_NO_WRITE_ACCESS, _T(__FILE__), __LINE__, 0);
    return 0;
  }
  
  if ((l_dwProcImDataWidth > 32) || (l_dwProcImBitPos >= 32) || ((l_dwProcImBitPos + l_dwProcImDataWidth) > 32))
  {
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_WRONG_LOG_ID, _T(__FILE__), __LINE__, 0);
    return 0;
  }
  
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  // start address process image (write)
  l_pdwWriteAdr = (PDWORD)(CHITReservedSharedMemory::GetUserProcImWriteBaseAdr());
  if (l_dwProcImDataWidth == 1)
  {
    // add offset address
	  l_pdwWriteAdr+= (l_dwProcImOffsetAdr / sizeof(DWORD));
	
    if (p_dwValue >= 1)
    { // set bit
      // bit mask
      l_dwProcImBitMask = l_dwProcImBitMask << l_dwProcImBitPos;
      // write bit value
      *l_pdwWriteAdr = *l_pdwWriteAdr | l_dwProcImBitMask;
    }
    else
    { // clear bit
      // bit mask
      l_dwProcImBitMask = ~(l_dwProcImBitMask << l_dwProcImBitPos);
      // write bit value
      *l_pdwWriteAdr = *l_pdwWriteAdr & l_dwProcImBitMask;
    }
  }
  else if (l_dwProcImDataWidth > 1)
  {
    // add offset address
	  l_pdwWriteAdr+= (l_dwProcImOffsetAdr / sizeof(DWORD));

    // data mask
    for (DWORD ii = 0; ii < l_dwProcImDataWidth; ii++)
    {
      l_dwProcImMask = l_dwProcImMask | (l_dwProcImBitMask << ii);
      
    }

    // set bit mask
    p_dwValue = (p_dwValue << l_dwProcImBitPos);
    
    // write value
    *l_pdwWriteAdr = (*l_pdwWriteAdr & ~(l_dwProcImMask << l_dwProcImBitPos)) | p_dwValue;
  }
  else
  {
    // should never happen !!!
    ASSERT(FALSE);
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_WRONG_LOG_ID, _T(__FILE__), __LINE__, 0);
    return 0;
  }

  return 1;

#else
  m_TestProcImMap[p_dwObjID] = p_dwValue;
  return 1;
#endif
  //## end CHIInterface::SetDWord%1048077958.body
}

BOOL CHIInterface::SetDataValid (DWORD p_dwObjID)
{
  //## begin CHIInterface::SetDataValid%1060343696.body preserve=yes
  DWORD *l_dwAdr = NULL;
  DWORD l_dwProcImOffsetAdr = 0;      // process image offset address
  DWORD l_dwProcImBitPos = 0;         // process image bit position
  DWORD l_dwProcImDataWidth = 0;      // process image data width
  DWORD l_dwProcImDataControlReg = 0; // process image data control register
  
  DWORD l_dwProcImBitMask = 0x1;
  DWORD l_dwProcImDataMask = 0;

  // convert Object ID -> HW Log ID
  DWORD l_dwID = GetLogicalID(p_dwObjID);

  // determin process image offset address
  l_dwProcImOffsetAdr = (l_dwID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr();
  l_dwProcImBitPos = (l_dwID & CHIProcessImageParameter::GetcdwMaskBitPosition()) >> CHIProcessImageParameter::GetcdwShiftCountsBitPosition();
  l_dwProcImDataWidth = (l_dwID & CHIProcessImageParameter::GetcdwMaskDataWidth()) >> CHIProcessImageParameter::GetcdwShiftCountsDataWidth();
  l_dwProcImDataControlReg = (l_dwID & CHIProcessImageParameter::GetcdwMaskControlStates()) >> CHIProcessImageParameter::GetcdwShiftCountsControlStates();
  
  if (!(l_dwID && CHIProcessImageParameter::GetcdwMaskWriteBit()))
  { 
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_NO_WRITE_ACCESS, _T(__FILE__), __LINE__, 0);
    return 0;
  }
  
  if ((l_dwProcImDataWidth > 32) || (l_dwProcImBitPos >= 32) || ((l_dwProcImBitPos + l_dwProcImDataWidth) > 32))
  {
    throw new XHIExceptionError(HI_ID, IDE_HW_INTF_WRONG_LOG_ID, _T(__FILE__), __LINE__, 0);
    return 0;
  }

  if (m_bHardwarePresent)
  {
     if (l_dwProcImDataWidth >= 1)
     {
    
        // start address process image (write)
        l_dwAdr = (PDWORD)(CHITReservedSharedMemory::GetUserProcImWriteBaseAdr());

        l_dwAdr+= (l_dwProcImOffsetAdr / sizeof(DWORD));

        l_dwProcImBitMask = l_dwProcImBitMask << l_dwProcImBitPos;
        // bit mask
        for (DWORD ii = 0; ii < l_dwProcImDataWidth; ii++)
        {
          l_dwProcImDataMask = l_dwProcImDataMask | (l_dwProcImBitMask << ii);
    
        }
    
        CSingleLock l_Lock(&m_AccessLock, TRUE);
        // write bit value
        *l_dwAdr = *l_dwAdr | l_dwProcImDataMask;

        return 1;
     }
     else
     {
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_VALID_DATA_ERROR, _T(__FILE__), __LINE__, 0);
        return 0;
     }
  }
  else
  {
    return 1;
  }
  //## end CHIInterface::SetDataValid%1060343696.body
}

CCOSyncObject* CHIInterface::OpenEvent (DWORD p_dwObjID, EHIOpenEventRegistration p_eRegistration)
{
  //## begin CHIInterface::OpenEvent%1048077961.body preserve=yes
    // convert Object ID -> HW Log ID
	DWORD l_dwID = GetLogicalID(p_dwObjID);
    CCOSyncObject* l_pSyncObj = CHIEventWorkerThread::GetInstance()->OpenEvent(l_dwID, p_eRegistration);
    l_pSyncObj->AddRef();

	CString l_sName;
	l_sName.Format(_T("HI:OpenEvent for EventID=%d"), p_dwObjID);
	l_pSyncObj->SetsName(l_sName);

    return(l_pSyncObj);
  //## end CHIInterface::OpenEvent%1048077961.body
}

void CHIInterface::CloseEvent (DWORD p_dwObjID, CCOSyncObject* p_pSyncObj)
{
  //## begin CHIInterface::CloseEvent%1048077962.body preserve=yes
    // convert Object ID -> HW Log ID
	DWORD l_dwID = GetLogicalID(p_dwObjID);

	CHIEventWorkerThread::GetInstance()->CloseEvent(l_dwID, p_pSyncObj);

  //## end CHIInterface::CloseEvent%1048077962.body
}

CCOSyncObjectArray* CHIInterface::DebugGetEvents (DWORD p_dwID)
{
  //## begin CHIInterface::DebugGetEvents%1051517665.body preserve=yes
    return CHIEventWorkerThread::GetInstance()->DebugGetEvents(p_dwID);

  //## end CHIInterface::DebugGetEvents%1051517665.body
}

void CHIInterface::DebugSetEvents (DWORD p_dwObjID)
{
  //## begin CHIInterface::DebugSetEvents%1056608819.body preserve=yes
    CHIEventWorkerThread::GetInstance()->DebugSetEvents(p_dwObjID);

  //## end CHIInterface::DebugSetEvents%1056608819.body
}

void CHIInterface::SetNodeConfig (DWORD p_dwLogID, DWORD p_dwAdrOffset, DWORD p_dwIndex)
{
  //## begin CHIInterface::SetNodeConfig%1050303226.body preserve=yes

  CHIProcessNodeConfig* l_pConfig = new CHIProcessNodeConfig(p_dwAdrOffset,p_dwIndex);

  m_NodeMap.SetAt(p_dwLogID, l_pConfig);
  //## end CHIInterface::SetNodeConfig%1050303226.body
}

CHIProcessNodeConfig* CHIInterface::GetNodeConfig (DWORD p_dwLogID)
{
  //## begin CHIInterface::GetNodeConfig%1050303227.body preserve=yes
  if (p_dwLogID < m_NodeMap.GetHashTableSize())
  {
    return m_NodeMap[p_dwLogID];
  }
  else
  {
    return NULL;
  }
  //## end CHIInterface::GetNodeConfig%1050303227.body
}

void CHIInterface::TESTSetData (DWORD p_Test)
{
  //## begin CHIInterface::TESTSetData%1052718392.body preserve=yes
  //TEST GetDataPackage
  DWORD l_IFMData[8] = {0,1,2,3,4,5,6,7};
  DWORD l_LaserData[8] = {8,9,10,11,12,13,14,15};
  DWORD Index = p_Test;
  bool l_bDirection = false; //FOREWARD
  for (DWORD ii = 0; ii < Index; ii++)
  {
    //if(ii >= 262140)
      //int qq = Index;

    // set direction bit
    if (ii & 0x1)
      l_bDirection = true;
    else
      l_bDirection = false;

    CHITReservedSharedMemory::SetDirectionBit(l_IFMData,
                                              l_LaserData,
                                              l_bDirection);

    ////////////////////////////////////////
    // check the hardware error flags and set the appropriate HW error bit
    CHITReservedSharedMemory::CheckHardwareError(l_IFMData,
                                                 l_LaserData);
    
    ////////////////////////////////////////
    // check the IFM data buffer overflow
    if (CHITReservedSharedMemory::GetbBufferOverflow())
      CHITReservedSharedMemory::SetOverflowBit(l_IFMData);

    ////////////////////////////////////////
    // check the Laser data buffer overflow
    if (CHITReservedSharedMemory::GetbBufferOverflow())
      CHITReservedSharedMemory::SetOverflowBit(l_LaserData);

    CHITReservedSharedMemory::SetStreamData(l_IFMData, l_LaserData);

    for (int ii = 0;ii < 8; ii++)
    {
      l_IFMData[ii] &= 0x00FFFFFF;
      l_LaserData[ii] &= 0x00FFFFFF;
    }
  }


  CHIMCParameter::SetdwMaxTransferDataSize(0x100000);
  CHIMCParameter::SetdwMinTransferDataSize(0x400);

  //## end CHIInterface::TESTSetData%1052718392.body
}

CCOSyncObject* CHIInterface::EnableEventSignalisation ()
{
  //## begin CHIInterface::EnableEventSignalisation%1066028223.body preserve=yes
  if (m_bHardwarePresent)
  {
#ifdef _WIN32_WCE
    CCOSyncObject* l_pSyncObj = CHIEventWorkerThread::GetInstance()->EnableEventSignalisation();
    l_pSyncObj->AddRef();
    return(l_pSyncObj);
#else
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();
    return l_pSyncObj;
#endif
  }
  else
  {
	  CCOSyncObject* l_pSyncObj = new CCOSyncObject();
	  l_pSyncObj->AddRef();
	  return l_pSyncObj;
  }
  //## end CHIInterface::EnableEventSignalisation%1066028223.body
}

CCOSyncObject* CHIInterface::DisableEventSignalisation ()
{
  //## begin CHIInterface::DisableEventSignalisation%1066028225.body preserve=yes
  if (m_bHardwarePresent)
  {
#ifdef _WIN32_WCE
    CCOSyncObject* l_pSyncObj = CHIEventWorkerThread::GetInstance()->DisableEventSignalisation();
    l_pSyncObj->AddRef();
    return(l_pSyncObj);
#else
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();
    return l_pSyncObj;
#endif
  }
  else
  {
	  CCOSyncObject* l_pSyncObj = new CCOSyncObject();
	  l_pSyncObj->AddRef();
	  return l_pSyncObj;
  }
  //## end CHIInterface::DisableEventSignalisation%1066028225.body
}

DWORD CHIInterface::ClearWCIrq ()
{
  //## begin CHIInterface::ClearWCIrq%1070368615.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

#ifdef _WIN32_WCE

  if (m_bHardwarePresent)
  {
    l_dwRetVal = DeviceIoControl( m_hPCIFile,   // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WCISR_CLEAR,            // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
 
    if (!l_dwRetVal)
    {
      CString l_strErr = _T("");
      l_strErr.Format(_T("ClearWCIrq() return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }
  else
  {
    l_dwRetVal = TRUE;
  }
#endif
  return l_dwRetVal;
  //## end CHIInterface::ClearWCIrq%1070368615.body
}

DWORD CHIInterface::GetStaticObjID (EHIStaticObjID p_eStaticObjID)
{
  //## begin CHIInterface::GetStaticObjID%1067255365.body preserve=yes
    DWORD l_dwRetValue = 0;

    switch(p_eStaticObjID)
    {
	    	// Led
        case eHILedGreen:
            l_dwRetValue = IU_IDLED6Green;
            break;
        case eHILedRed:
            l_dwRetValue = IU_IDLED2Red;
            break;

	    	// Lamp
	    	case eHIIDLmpActCurrent:
			      l_dwRetValue = IU_IDLmpActCurrent;
            break;
        case eHIIDLmpActVoltagePri:
      			l_dwRetValue = IU_IDLmpActVoltagePri;
            break;
        case eHIIDLmpActVoltageSec:
      			l_dwRetValue = IU_IDLmpActVoltageSec;
            break;
        case eHIIDLmpNomVoltage:
      			l_dwRetValue = IU_IDLmpNomVoltage;
            break;
        case eHIIDLmpSelection:
            l_dwRetValue = IU_IDLmpSelection;
            break;
        case eHIIDLmpOnOff:
      			l_dwRetValue = IU_IDLmpOnOff;
            break;
		    case eHILmpNomVoltageLLimit:
			      l_dwRetValue = 3540; // [mV]
			      break;
		    case eHILmpStandByVoltage:
      			l_dwRetValue = 4500; // [mV]
            break;
		    case eHILmpActCurrLLimit:
  			    l_dwRetValue = 1529;// [mA]
            break;

		    // Laser
        case eHIIDIOLaser:
            l_dwRetValue = IU_IDIOLaser;
            break;

        // docking event
        case eHIIDDockingState:
            l_dwRetValue = MC_IDDockingState;
            break;

        // start / stop buttons
        case eHIIDButtonStart:
            l_dwRetValue = MC_IDButtonStart;
            break;
        case eHIIDButtonStop:
            l_dwRetValue = MC_IDButtonStop;
            break;
        
        // Hardware Exceptions
        case eHIIDHwExceptions:
            l_dwRetValue = IU_IDHwWarningErrorState;
            break;
        default:
            ASSERT(FALSE);
			break;
    }

    return l_dwRetValue;
  //## end CHIInterface::GetStaticObjID%1067255365.body
}

CCOSyncObjectInt* CHIInterface::WCGetActVelocityCounts ()
{
  //## begin CHIInterface::WCGetActVelocityCounts%1068453039.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  DWORD l_dwOut = 0;
  DWORD l_dwReadOutput = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_GET_ACT_VELOCITY,     // control code for the operation  
                                  NULL,
                                  0,
                                  &l_dwOut,
                                  l_dwReadOutput,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCGetActVelocityCounts() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
#endif

  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_dwOut);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::WCGetActVelocityCounts%1068453039.body
}

CCOSyncObjectInt* CHIInterface::WCGetLastVelocityCounts ()
{
  //## begin CHIInterface::WCGetLastVelocityCounts%1068453040.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  DWORD l_dwOut = 0;
  DWORD l_dwReadOutput = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_GET_LAST_VELOCITY,     // control code for the operation  
                                  NULL,
                                  0,
                                  &l_dwOut,
                                  l_dwReadOutput,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCGetLastVelocityCounts() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
#endif

  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_dwOut);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::WCGetLastVelocityCounts%1068453040.body
}

CCOSyncObjectInt* CHIInterface::WCGetPosition ()
{
  //## begin CHIInterface::WCGetPosition%1068453041.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  DWORD l_dwOut = 0;
  DWORD l_dwReadOutput = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_GET_POSITION,     // control code for the operation  
                                  NULL,
                                  0,
                                  &l_dwOut,
                                  l_dwReadOutput,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCGetPosition() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
#endif

  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_dwOut);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::WCGetPosition%1068453041.body
}

CCOSyncObject* CHIInterface::WCInitializeDAC ()
{
  //## begin CHIInterface::WCInitializeDAC%1068530376.body preserve=yes
  CCOSyncObject* l_pSyncObj = NULL;
  
  PDWORD l_pAdr = NULL;
  DWORD  l_dwValue = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    // get wedge controll write register
    l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
    
    // clear wedge write register
    *l_pAdr = 0;

    // WC DAC wake up   
    l_dwValue = *l_pAdr & (~CHITReservedSharedMemory::GetcdwBitMaskWCDACWakeUp());
    l_dwValue|= ((CHITDACMAX5712::GetcdwWakeUpValue() << CHITReservedSharedMemory::GetcdwWCDACValueLeftShiftCounts()) & CHITReservedSharedMemory::GetcdwBitMaskWCDACWakeUp());
    *l_pAdr|= (CHITDACMAX5712::GetcdwWakeUpValue() << CHITReservedSharedMemory::GetcdwWCDACValueLeftShiftCounts());

    // wait
    Sleep(1);

    // set DAC offset value
    l_dwValue = *l_pAdr & (~CHITReservedSharedMemory::GetcdwBitMaskWCDACWakeUp()); // clear wake up value
    l_dwValue|= ((CHITDACMAX5712::GetcdwDefaultOffsetValue() << CHITReservedSharedMemory::GetcdwWCDACValueLeftShiftCounts()) & CHITReservedSharedMemory::GetcdwBitMaskWCDACValue());
    *l_pAdr = l_dwValue;

    //wait
    Sleep(1);

    // set WC DAC enable
    *l_pAdr |= CHITReservedSharedMemory::GetcdwBitMaskWCEnable();
  }
#endif

  l_pSyncObj = new CCOSyncObject();
  l_pSyncObj->SignalCompletion();                  

  return l_pSyncObj;
  //## end CHIInterface::WCInitializeDAC%1068530376.body
}

void CHIInterface::WCSetDACValue (DWORD p_dwDACValue)
{
  //## begin CHIInterface::WCSetDACValue%1068453042.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;


#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_SET_DAC,     // control code for the operation  
                                  &p_dwDACValue,
                                  sizeof(DWORD),
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCSetDACValue() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
#endif
  //## end CHIInterface::WCSetDACValue%1068453042.body
}

CCOSyncObject* CHIInterface::WCControllerON (DWORD p_dwFlag)
{
  //## begin CHIInterface::WCControllerON%1068453043.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_CONTROLLER,     // control code for the operation  
                                  &p_dwFlag,
                                  sizeof(DWORD),
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCControllerON() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
#endif
  CCOSyncObject* l_pSyncObj = new CCOSyncObject();		
  l_pSyncObj->SignalCompletion();				

  return l_pSyncObj;

  //## end CHIInterface::WCControllerON%1068453043.body
}

CCOSyncObjectInt* CHIInterface::WCGetLightBarrierState ()
{
  //## begin CHIInterface::WCGetLightBarrierState%1068453049.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  DWORD l_dwOut = 0;
  DWORD l_dwReadOutput = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_LB_STATE,     // control code for the operation  
                                  NULL,
                                  0,
                                  &l_dwOut,
                                  l_dwReadOutput,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("WCGetLightBarrierState() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }
  }
#endif

  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_dwOut);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::WCGetLightBarrierState%1068453049.body
}

CCOVersion CHIInterface::LoadConfig (const CString& p_sXmlDocStream)
{
  //## begin CHIInterface::LoadConfig%1068729290.body preserve=yes
#ifdef _WIN32_WCE
    const CString l_sFileName = _T("\\Hard Disk\\NIRFlex\\HIConfig.xml");
#else
    const CString l_sFileName = _T("R:\\Embedded\\Bin\\Debug\\HIConfig.xml");
#endif

    CCOMarkup l_XML;
    if (&p_sXmlDocStream == NULL)
    {
        // try to load default
        CFile l_File;
        if (l_File.Open(l_sFileName, CFile::modeRead))
        {
            int l_iLength = (int)l_File.GetLength();
            BYTE* l_pBuffer = new BYTE[l_iLength];
            l_File.Read(l_pBuffer, l_iLength);
            l_File.Close();

            CString l_sDoc(l_pBuffer);
            delete [] l_pBuffer;

            l_XML.SetDoc(l_sDoc);
        }
        else
        {
            // load of default failed
            ASSERT(FALSE);
        }
    }
    else
    {
        l_XML.SetDoc(p_sXmlDocStream);
    }

    // reset previous map
    m_IdMap.RemoveAll();
    
    CString l_strConfigVersion;
    if (!l_XML.FindChildElem(_T("VersionInfo")))
    {
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_FPGA_VERSION_MISMATCH, _T(__FILE__), __LINE__, 0);
    }
    l_XML.IntoElem();
    l_XML.FindChildElem( _T("File") );
    m_sXMLVersion = l_XML.GetChildData();
    l_XML.FindChildElem(_T("FPGA"));
    l_strConfigVersion = l_XML.GetChildData();
    l_XML.OutOfElem();

    // read config
    while ( l_XML.FindChildElem(_T("HIConfig")) )
    {
        WCHAR*  l_pError;
        CString l_sName, l_sID, l_sAddress;
        l_XML.IntoElem();
        l_XML.FindChildElem( _T("Name") );
        l_sName = l_XML.GetChildData();
        l_XML.FindChildElem( _T("ID") );
        l_sID = l_XML.GetChildData();
        l_XML.FindChildElem( _T("Address") );
        l_sAddress = l_XML.GetChildData();
        l_XML.OutOfElem();

        DWORD l_dwID = wcstoul((LPCTSTR)l_sID, &l_pError, 10);
        DWORD l_dwAddress = wcstoul((LPCTSTR)l_sAddress, &l_pError,16);
        m_IdMap.SetAt(l_dwID, l_dwAddress);
    }

    return CCOVersion(l_strConfigVersion);
  //## end CHIInterface::LoadConfig%1068729290.body
}

CCOSyncObjectInt* CHIInterface::WCCalibrateDAC ()
{
  //## begin CHIInterface::WCCalibrateDAC%1069249956.body preserve=yes
  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(0);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::WCCalibrateDAC%1069249956.body
}

DWORD CHIInterface::MaskHWEvent (DWORD p_dwLogEventID, EHIEventMaskType p_eType)
{
  //## begin CHIInterface::MaskHWEvent%1069662407.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  
  DWORD l_dwOffset = 0;
  DWORD l_dwBitPos = 0;
  DWORD l_dwDataWidth = 0;
  DWORD l_dwBitMask = 0x1;

#ifdef _WIN32_WCE
  try
  {
    // convert Object ID -> HW Log ID
    DWORD l_dwID = GetLogicalID(p_dwLogEventID);
    // determin offset address
    l_dwBitPos = (l_dwID & CHIProcessImageParameter::GetcdwMaskBitPosition()) >> CHIProcessImageParameter::GetcdwShiftCountsBitPosition();
    l_dwDataWidth = (l_dwID & CHIProcessImageParameter::GetcdwMaskDataWidth()) >> CHIProcessImageParameter::GetcdwShiftCountsDataWidth();

    if ((l_dwDataWidth > 1) || (l_dwBitPos >= 32) || ((l_dwBitPos + l_dwDataWidth) > 32))
    {
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_WRONG_LOG_ID, _T(__FILE__), __LINE__, 0);
      return l_dwRetVal;
    }

    switch (p_eType)
    {
      case eHIHardwareEvent: // HW event (dig. Input, Stepper etc.)
        l_dwOffset = (((l_dwID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr()) - CHITReservedSharedMemory::GetcdwAdrOffsetEventReg()) / sizeof(DWORD);
        ASSERT(l_dwOffset < CHITReservedSharedMemory::GetcdwNumbersOfEventReg());
        m_pEventMask->m_dwHWEventMask[l_dwOffset]&= ~(l_dwBitMask << l_dwBitPos);
        break;
      
      case eHIWedgeControlEvent: // WC event
        l_dwOffset = (((l_dwID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr()) - CHITReservedSharedMemory::GetcdwAdrOffsetWCEventReg()) / sizeof(DWORD);
        ASSERT(l_dwOffset < CHITReservedSharedMemory::GetcdwNumbersOfWCEventReg());
        m_pEventMask->m_dwWCEventMask[l_dwOffset]&= ~(l_dwBitMask << l_dwBitPos);
        break;
      
      default:
        ASSERT(FALSE);  
        break;

    }
      
    if (m_bHardwarePresent)
    {

      l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                    IOCTL_HAL_PCI_WC_MASK_EVENT_REG,     // control code for the operation  
                                    m_pEventMask,
                                    sizeof(CHIIOCEventMasks),
                                    NULL,
                                    0,
                                    &l_dwReadBytes,
                                    NULL);
      if (!l_dwRetVal)
      {
        CString l_strErr = _T("");
        l_strErr.Format(_T("MaskHWEvent() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
      }
    }
  }
  catch(...)
  {
    throw;
  }
  return l_dwRetVal;
#else
  return 1;
#endif
  //## end CHIInterface::MaskHWEvent%1069662407.body
}

DWORD CHIInterface::UnMaskHWEvent (DWORD p_dwLogEventID, EHIEventMaskType p_eType)
{
  //## begin CHIInterface::UnMaskHWEvent%1069662408.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  
  DWORD l_dwOffset = 0;
  DWORD l_dwBitPos = 0;
  DWORD l_dwDataWidth = 0;
  DWORD l_dwBitMask = 0x1;

#ifdef _WIN32_WCE
  try
  {
    // convert Object ID -> HW Log ID
    DWORD l_dwID = GetLogicalID(p_dwLogEventID);
    // determin offset address
    l_dwBitPos = (l_dwID & CHIProcessImageParameter::GetcdwMaskBitPosition()) >> CHIProcessImageParameter::GetcdwShiftCountsBitPosition();
    l_dwDataWidth = (l_dwID & CHIProcessImageParameter::GetcdwMaskDataWidth()) >> CHIProcessImageParameter::GetcdwShiftCountsDataWidth();

    if ((l_dwDataWidth > 1) || (l_dwBitPos >= 32) || ((l_dwBitPos + l_dwDataWidth) > 32))
    {
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_WRONG_LOG_ID, _T(__FILE__), __LINE__, 0);
      return l_dwRetVal;
    }

    switch (p_eType)
    {
      case eHIHardwareEvent: // HW event (dig. Input, Stepper etc.)
        l_dwOffset = (((l_dwID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr()) - CHITReservedSharedMemory::GetcdwAdrOffsetEventReg()) / sizeof(DWORD);
        ASSERT(l_dwOffset < CHITReservedSharedMemory::GetcdwNumbersOfEventReg());
        m_pEventMask->m_dwHWEventMask[l_dwOffset]|= (l_dwBitMask << l_dwBitPos);
        break;
      
      case eHIWedgeControlEvent: // WC event
        l_dwOffset = (((l_dwID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr()) - CHITReservedSharedMemory::GetcdwAdrOffsetWCEventReg()) / sizeof(DWORD);
        ASSERT(l_dwOffset < CHITReservedSharedMemory::GetcdwNumbersOfWCEventReg());
        m_pEventMask->m_dwWCEventMask[l_dwOffset]|= (l_dwBitMask << l_dwBitPos);
        break;
      
      default:
        ASSERT(FALSE);  
        break;

    }
    
    if (m_bHardwarePresent)
    {

      l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                    IOCTL_HAL_PCI_WC_MASK_EVENT_REG,     // control code for the operation  
                                    m_pEventMask,
                                    sizeof(CHIIOCEventMasks),
                                    NULL,
                                    0,
                                    &l_dwReadBytes,
                                    NULL);
      if (!l_dwRetVal)
      {
        CString l_strErr = _T("");
        l_strErr.Format(_T("UnMaskHWEvent() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
      }
    }
  }
  catch(...)
  {
    throw;
  }
  return l_dwRetVal;
#else
  return 1;
#endif
  //## end CHIInterface::UnMaskHWEvent%1069662408.body
}

DWORD CHIInterface::NotifyWCISRtoSendEvent ()
{
  //## begin CHIInterface::NotifyWCISRtoSendEvent%1070368617.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

  AcknowledgeEventSignalisation();

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WC_SEND_EVENT,     // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
      CString l_strErr = _T("");
      l_strErr.Format(_T("NotifyWCISRtoSendEvent() return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }
  else
  {
    l_dwRetVal = TRUE;
  }
#endif

  return l_dwRetVal;
  //## end CHIInterface::NotifyWCISRtoSendEvent%1070368617.body
}

DWORD* CHIInterface::GetI2CWriteStartAdr ()
{
  //## begin CHIInterface::GetI2CWriteStartAdr%1071824383.body preserve=yes
  return CHITReservedSharedMemory::GetI2CWriteStartAdr();
  //## end CHIInterface::GetI2CWriteStartAdr%1071824383.body
}

DWORD* CHIInterface::GetI2CReadStartAdr ()
{
  //## begin CHIInterface::GetI2CReadStartAdr%1071824384.body preserve=yes
  return CHITReservedSharedMemory::GetI2CReadStartAdr();
  //## end CHIInterface::GetI2CReadStartAdr%1071824384.body
}

CCOSyncObjectInt* CHIInterface::GetNumberOfWCScan ()
{
  //## begin CHIInterface::GetNumberOfWCScan%1073285404.body preserve=yes
  CCOSyncObjectInt* l_pSyncObj = new CCOSyncObjectInt(0);
  if (m_bHardwarePresent)
  {
    PDWORD l_pdwAdr = CHITReservedSharedMemory::GetNumberOfWCScanAdr();
  
    l_pSyncObj->SetValue(*l_pdwAdr);
    l_pSyncObj->SignalCompletion();
  
    // resret number of scan register
    *l_pdwAdr = 0;
  }
  else
  {
    l_pSyncObj->SetValue(1);
    l_pSyncObj->SignalCompletion();
  }
  return l_pSyncObj;
  //## end CHIInterface::GetNumberOfWCScan%1073285404.body
}

double CHIInterface::GetCurrentLaserLevelDetection ()
{
  //## begin CHIInterface::GetCurrentLaserLevelDetection%1073998353.body preserve=yes
  double l_dRetVal = 0;
  DWORD l_dwADCDigit = 0;
  CCOSyncObjectInt* l_pSyncObj = new CCOSyncObjectInt(0);
  PDWORD l_pdwAdr = CHITReservedSharedMemory::GetLaserDetectionAdr();
  DWORD l_dwTmp = *l_pdwAdr & CHITADCMAX1281::GetcdwBitMaskCurLaserDet();
  l_dwADCDigit = l_dwTmp >> CHITADCMAX1281::GetcdwShiftCountsCurLaserDet();
  
  // convertion -> digt to current
  double l_dVRef = CHITADCMAX1281::GetcdADCRefVoltage();
  double l_dCurGainResistor = (double)CHITADCMAX1281::GetcdwADCCurGainResistor();
  double l_dADCRange = (double)CHITADCMAX1281::GetcdwADCRange();

  l_dRetVal = (double)l_dwADCDigit * (l_dVRef / (l_dADCRange * l_dCurGainResistor));
  
  return l_dRetVal;

  //## end CHIInterface::GetCurrentLaserLevelDetection%1073998353.body
}

CCOSyncObjectInt* CHIInterface::GetDigitsLaserLevelDetection ()
{
  //## begin CHIInterface::GetDigitsLaserLevelDetection%1097650513.body preserve=yes
  DWORD l_dwADCDigit = 0;
  CCOSyncObjectInt* l_pSyncObj = new CCOSyncObjectInt(0);
  if (m_bHardwarePresent)
  {
    PDWORD l_pdwAdr = CHITReservedSharedMemory::GetLaserDetectionAdr();
    DWORD l_dwTmp = *l_pdwAdr & CHITADCMAX1281::GetcdwBitMaskCurLaserDet();
    l_dwADCDigit = l_dwTmp >> CHITADCMAX1281::GetcdwShiftCountsCurLaserDet();
  
    l_pSyncObj->SetValue((int)l_dwADCDigit);
    l_pSyncObj->SignalCompletion();
  }
  else
  {
    l_pSyncObj->SetValue(1);
    l_pSyncObj->SignalCompletion();
  }
  return l_pSyncObj;
  //## end CHIInterface::GetDigitsLaserLevelDetection%1097650513.body
}

DWORD CHIInterface::GetHWExceptionErrorCode ()
{
  //## begin CHIInterface::GetHWExceptionErrorCode%1074258760.body preserve=yes
  DWORD l_dwRetVal = 0;
  if (m_bHardwarePresent)
  {
    PDWORD l_pdwAdr = CHITReservedSharedMemory::GetHWExceptionRegStartAdr();
    l_dwRetVal = *l_pdwAdr;
    *l_pdwAdr = 0;
  }
  return l_dwRetVal;
  //## end CHIInterface::GetHWExceptionErrorCode%1074258760.body
}

void CHIInterface::SetHWExceptionEventNr (DWORD p_dwExceptionEventNr)
{
  //## begin CHIInterface::SetHWExceptionEventNr%1074582785.body preserve=yes
  DWORD l_dwLogID = GetLogicalID(p_dwExceptionEventNr);
  CHIEventWorkerThread::GetInstance()->SetdwHWExceptionEventNr(l_dwLogID);
  //## end CHIInterface::SetHWExceptionEventNr%1074582785.body
}

DWORD CHIInterface::GetLogicalID (DWORD p_dwID)
{
  //## begin CHIInterface::GetLogicalID%1075107935.body preserve=yes
	DWORD l_dwID = 0;
	BOOL l_bRes = m_IdMap.Lookup(p_dwID, l_dwID);
	
	if (l_bRes)
	{	
		// id found
		return l_dwID;
	}
	else
	{
		// id not found
		CString l_strErr;
		l_strErr.Format(_T("Exception in File: %s. Line: %d. Logical ID '%d' not defined in Buchi.HIConfig.xml"), _T(__FILE__), __LINE__, p_dwID);
		CO_TRACE(HI_ID, l_strErr);
		throw new XHIExceptionError(HI_ID, IDE_HW_INTF_INVALID_OBJ_ID, _T(__FILE__), __LINE__, 0);
	}
  //## end CHIInterface::GetLogicalID%1075107935.body
}

CCOSyncObjectCString* CHIInterface::ReadFpgaArtNr ()
{
  //## begin CHIInterface::ReadFpgaArtNr%1076322542.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

  DWORD l_dwAdrOffset = CHIIOCPCISettings::GetcdwAdrOffsetFpgaArtNr();
  DWORD l_dwArtNr = 0;
  DWORD l_dwArtNrLength = 0;
  PBYTE l_pData = new BYTE[sizeof(DWORD)];

  char l_cArtNr[100]; sprintf(l_cArtNr, "%c", 0);
  char l_cTmp[100]; sprintf(l_cTmp, "%c", 0);

  CString l_strArtNr = _T("");

  CCOSyncObjectCString* l_pSyncObj = new CCOSyncObjectCString(_T(""));
#ifdef _WIN32_WCE
  try
  {
    if (m_bHardwarePresent)
    {

      for (DWORD ii = 0; ii < CHIIOCPCISettings::GetcdwNumberOfDWordFpgaArtNr(); ii++)
      {
        l_dwAdrOffset+= ii;
        l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                      IOCTL_HAL_PCI_READ_REGISTER,     // control code for the operation  
                                      &l_dwAdrOffset,
                                      sizeof(DWORD),
                                      (PDWORD)l_pData,
                                      l_dwArtNrLength,
                                      &l_dwReadBytes,
                                      NULL);
        if (!l_dwRetVal)
        {
          CString l_strErr = _T("");
          l_strErr.Format(_T("ReadFpgaArtNr() return error %d\r\n"), l_dwError);
          CO_TRACE(HI_ID, l_strErr);
          throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
        }
      
        for (int jj = 0; jj < sizeof(DWORD); jj++)
        {
          strcat((char*)l_cTmp, "");
          sprintf(l_cTmp, "%c", l_pData[jj]);
          strcat((char*)l_cArtNr, l_cTmp);
          if (strcmp(l_cTmp,"") == 0)
            break;
        }

      }
      l_strArtNr = l_cArtNr;
    }
    l_pSyncObj->SetValue(l_strArtNr);
    l_pSyncObj->SignalCompletion();
    delete [] l_pData;
  }
  catch(XCOException* p_pException)
  {
    delete [] l_pData;
    l_pSyncObj->AttachException(p_pException);
  }
#else
  l_pSyncObj->SignalCompletion();
#endif

  return l_pSyncObj;
  //## end CHIInterface::ReadFpgaArtNr%1076322542.body
}

CCOSyncObjectCString* CHIInterface::ReadFpgaSwVersion ()
{
  //## begin CHIInterface::ReadFpgaSwVersion%1076322543.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  
  DWORD l_dwAdrOffset = CHIIOCPCISettings::GetcdwAdrOffsetFpgaSwVersion();
  DWORD l_dwVersion = 0;
  DWORD l_dwVersionLength = 0;
  PBYTE l_pData = new BYTE[sizeof(DWORD)];

  char l_cVersion[100]; sprintf(l_cVersion, "%c", 0);
  char l_cTmp[100]; sprintf(l_cTmp, "%c", 0);

  CString l_strVersion = _T("");

  CCOSyncObjectCString* l_pSyncObj = new CCOSyncObjectCString(_T("HI:ReadFPGAVersion"), _T(""));

#ifdef _WIN32_WCE
  try
  {
    if (m_bHardwarePresent)
    {

      for (DWORD ii = 0; ii < CHIIOCPCISettings::GetcdwNumberOfDWordFpgaSwVersion(); ii++)
      {
        l_dwAdrOffset+= ii;
        l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                      IOCTL_HAL_PCI_READ_REGISTER,     // control code for the operation  
                                      &l_dwAdrOffset,
                                      sizeof(DWORD),
                                      (PDWORD)l_pData,
                                      l_dwVersionLength,
                                      &l_dwReadBytes,
                                      NULL);
        if (!l_dwRetVal)
        {
          CString l_strErr = _T("");
          l_strErr.Format(_T("ReadFpgaSwVersion() return error %d\r\n"), l_dwError);
          CO_TRACE(HI_ID, l_strErr);
          throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
        }
      
        for (int jj = 0; jj < sizeof(DWORD); jj++)
        {
          strcat((char*)l_cTmp, "");
          sprintf(l_cTmp, "%c", l_pData[jj]);
          strcat((char*)l_cVersion, l_cTmp);
          if (strcmp(l_cTmp,"") == 0)
            break;
        }

      }
      l_strVersion = l_cVersion;
      
    }
    l_pSyncObj->SetValue(l_strVersion);
    l_pSyncObj->SignalCompletion();
    delete [] l_pData;
  }
  catch(XCOException* p_pException)
  {
    delete [] l_pData;
    l_pSyncObj->AttachException(p_pException);
  }
#else
  l_pSyncObj->SignalCompletion();
#endif

  return l_pSyncObj;
  //## end CHIInterface::ReadFpgaSwVersion%1076322543.body
}

CCOSyncObject* CHIInterface::SetNewStreamBufferSize (DWORD p_dwSize)
{
  //## begin CHIInterface::SetNewStreamBufferSize%1085576033.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;
  DWORD l_dwSize = p_dwSize;
  
  CCOSyncObject* l_pSyncObj = new CCOSyncObject(_T("HI:SetNewStreamBufferSize"));
  
  if (l_dwSize == 0)
  {
    // set default stream buffer size
    l_dwSize = CHITReservedSharedMemory::GetcdwStreamBufferSizeInByte();
  }

  CHITReservedSharedMemory::SetNewStreamBufferSize(l_dwSize);  // sets stream buffer size

  try
  {
#ifdef _WIN32_WCE
    if (m_bHardwarePresent)
    {

      l_dwRetVal = DeviceIoControl(m_hPCIFile,                       // Handle to the device that is to perform the operation
                                   IOCTL_HAL_PCI_SET_BUFFERSIZE,     // control code for the operation  
                                   &l_dwSize,
                                   sizeof(DWORD),
                                   NULL,
                                   0,
                                   &l_dwReadBytes,
                                   NULL);
      if (!l_dwRetVal)
      {
          l_dwError = GetHWExceptionErrorCode();
          CString l_strErr = _T("");
          l_strErr.Format(_T("SetNewStreamBufferSize() return error %d\r\n"), l_dwError);
          CO_TRACE(HI_ID, l_strErr);
          throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, l_dwError);
      }
    }
    else
    {
      l_dwRetVal = TRUE;
    }
#endif
  }
  catch(XCOExceptionError* l_pException)
  {
    l_pSyncObj->AttachException(l_pException);
  }
  		
  l_pSyncObj->SignalCompletion();				
  return l_pSyncObj;
  //## end CHIInterface::SetNewStreamBufferSize%1085576033.body
}

void CHIInterface::DisableWatchdog ()
{
  //## begin CHIInterface::DisableWatchdog%1085723664.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;
  DWORD l_dwError = 0;
  DWORD l_dwErrorLen = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WD_DISABLE,     // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
      CString l_strErr = _T("");
      l_strErr.Format(_T("DisableWatchdog() return error %d\r\n"), l_dwError);
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }
  else
  {
    l_dwRetVal = TRUE;
  }
#endif
  //## end CHIInterface::DisableWatchdog%1085723664.body
}

void CHIInterface::EnableWatchdog (EHIWatchDogTime p_eWatchDogTime)
{
  //## begin CHIInterface::EnableWatchdog%1085723665.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwRetVal = 0;

  DWORD l_dwWDResetTime = (DWORD)p_eWatchDogTime;  // Wachdog Time
#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_WD_REFRESH,     // control code for the operation  
                                  &l_dwWDResetTime,
                                  sizeof(DWORD),
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
      CString l_strErr = _T("");
      l_strErr.Format(_T("ReleaseHWReset() return error \r\n"));
      CO_TRACE(HI_ID, l_strErr);
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_PCI_DRIVER_ERROR, _T(__FILE__), __LINE__, 0);
    }
  }

#endif
  //## end CHIInterface::EnableWatchdog%1085723665.body
}

void CHIInterface::PCSetNomVoltage (DWORD p_dwDACValue)
{
  //## begin CHIInterface::PCSetNomVoltage%1094799192.body preserve=yes
  PDWORD l_pdwAdr = NULL;
  DWORD  l_dwValue = 0;
  DWORD  l_dwBitMask = 0;
  DWORD  l_dwActValue = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    // write adr Process Image WRITE
    l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImWriteBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampCtrl()/sizeof(DWORD));
    

    // prepare value  
    l_dwValue = p_dwDACValue << CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampNomVoltage();
    l_dwBitMask = CHITReservedSharedMemory::GetcdwBitMaskPCNomVoltage();
    l_dwValue&= l_dwBitMask;
    l_dwActValue = *l_pdwAdr;
    l_dwActValue = (l_dwActValue &~l_dwBitMask) | l_dwValue;
    *l_pdwAdr = l_dwActValue;
  }
#endif
  //## end CHIInterface::PCSetNomVoltage%1094799192.body
}

void CHIInterface::PCLampSelection (EPILamp p_eSelection)
{
  //## begin CHIInterface::PCLampSelection%1094799193.body preserve=yes
  PDWORD l_pdwAdr = NULL;
  DWORD  l_dwValue = 0;
  DWORD  l_dwBitMask = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    // write adr Process Image WRITE
    l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImWriteBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampCtrl()/sizeof(DWORD));
    
    // lamp selection
    if (p_eSelection == ePrimaryLamp)
    {
      // primary lamp
      l_dwValue = ~CHITReservedSharedMemory::GetcdwBitMaskPCLampSel();
      *l_pdwAdr&= l_dwValue;
    }
    else
    {
      // secondary lamp
      l_dwValue = CHITReservedSharedMemory::GetcdwBitMaskPCLampSel();
      *l_pdwAdr|= l_dwValue;
    }
  }
#endif
  //## end CHIInterface::PCLampSelection%1094799193.body
}

void CHIInterface::PCLampOnOff (bool p_bSelection)
{
  //## begin CHIInterface::PCLampOnOff%1094799194.body preserve=yes
  PDWORD l_pdwAdr = NULL;
  DWORD  l_dwValue = 0;
  DWORD  l_dwBitMask = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    // write adr Process Image WRITE
    l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImWriteBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampCtrl()/sizeof(DWORD));

    if (p_bSelection)
    {
      // lamp ON
      l_dwValue = CHITReservedSharedMemory::GetcdwBitMaskPCOnOff();
      *l_pdwAdr|= l_dwValue;
    }
    else
    {
      // lamp OFF
      l_dwValue = ~CHITReservedSharedMemory::GetcdwBitMaskPCOnOff();
      *l_pdwAdr&= l_dwValue;
    }
  }
#endif
  //## end CHIInterface::PCLampOnOff%1094799194.body
}

CCOSyncObjectInt* CHIInterface::PCGetActCurrent ()
{
  //## begin CHIInterface::PCGetActCurrent%1094799195.body preserve=yes
  DWORD l_dwRetVal = 0;
  PDWORD l_pdwAdr = NULL;
  DWORD  l_dwValue = 0;
  DWORD  l_dwBitShifts = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    // read adr Process Image READ
    l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImReadBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampCurr()/sizeof(DWORD));
    l_dwValue = *l_pdwAdr & CHITReservedSharedMemory::GetcdwBitMaskPCActCurr();
    l_dwBitShifts = CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActCurrent();
    l_dwRetVal = (l_dwValue >> l_dwBitShifts);

  }
#endif
  
  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_dwRetVal);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::PCGetActCurrent%1094799195.body
}

CCOSyncObjectInt* CHIInterface::PCGetActVoltage (EPILamp p_eSelection)
{
  //## begin CHIInterface::PCGetActVoltage%1094799196.body preserve=yes
  DWORD l_dwRetVal = 0;
  PDWORD l_pdwAdr = NULL;
  DWORD  l_dwValue = 0;
  DWORD  l_dwBitShifts = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    // read adr Process Image READ
    // lamp selection
    if (p_eSelection == ePrimaryLamp)
    {
      // primary lamp
      l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImReadBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampPrimary()/sizeof(DWORD));
    }
    else
    {
      // secondary lamp
      l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImReadBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampSecondary()/sizeof(DWORD));

    }

    l_dwValue = *l_pdwAdr & CHITReservedSharedMemory::GetcdwBitMaskPCActVolt();
    l_dwBitShifts = CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActVoltage();
    l_dwRetVal = (l_dwValue >> l_dwBitShifts);

  }
#endif
  
  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_dwRetVal);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::PCGetActVoltage%1094799196.body
}

CCOSyncObjectInt* CHIInterface::PCGetLampIdentification (EPILamp p_eSelection)
{
  //## begin CHIInterface::PCGetLampIdentification%1094799197.body preserve=yes
  DWORD l_dwRetVal = 0;
  PDWORD l_pdwAdr = NULL;
  DWORD  l_dwValue = 0;
  DWORD  l_dwBitShifts = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {
    // read adr Process Image READ
    // lamp selection
    if (p_eSelection == ePrimaryLamp)
    {
      // primary lamp
      l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImReadBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampPrimary()/sizeof(DWORD));
    }
    else
    {
      // secondary lamp
      l_pdwAdr = (PDWORD)CHITReservedSharedMemory::GetUserProcImReadBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetLampSecondary()/sizeof(DWORD));

    }

    l_dwValue = *l_pdwAdr & CHITReservedSharedMemory::GetcdwBitMaskPCLampIdent();
    l_dwBitShifts = CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampIdent();
    l_dwRetVal = (l_dwValue >> l_dwBitShifts);

  }
#endif
  
  CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_dwRetVal);		
  l_pSyncObjInt->SignalCompletion();				

  return l_pSyncObjInt;
  //## end CHIInterface::PCGetLampIdentification%1094799197.body
}

bool CHIInterface::AcknowledgeEventSignalisation ()
{
  //## begin CHIInterface::AcknowledgeEventSignalisation%1101976960.body preserve=yes
  DWORD l_dwReadBytes = 0;
  DWORD l_dwError = 0;
  DWORD l_dwRetVal = 0;

#ifdef _WIN32_WCE
  if (m_bHardwarePresent)
  {

    l_dwRetVal = DeviceIoControl( m_hPCIFile,                       // Handle to the device that is to perform the operation
                                  IOCTL_HAL_PCI_ACK_EVENT,          // control code for the operation  
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  &l_dwReadBytes,
                                  NULL);
    if (!l_dwRetVal)
    {
        l_dwError = GetHWExceptionErrorCode();
        CString l_strErr = _T("");
        l_strErr.Format(_T("AcknowledgeEventSignalisation() return error %d\r\n"), l_dwError);
        CO_TRACE(HI_ID, l_strErr);
        return false;
    }
  }
  return true;
#else
    return true;
#endif
  //## end CHIInterface::AcknowledgeEventSignalisation%1101976960.body
}

CCOSyncObjectCString* CHIInterface::GetOsVersion ()
{
  //## begin CHIInterface::GetOsVersion%1108550310.body preserve=yes
	CCOSyncObjectCString* l_pSyncObj = new CCOSyncObjectCString(_T("HI:GetOsVersion"), _T(""));
	CString l_sVersion = _T("");

	// try to read plattform version from registry
    CRegKey l_Key;
    if (l_Key.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Buchi\\PlattformVersion")) == ERROR_SUCCESS)
    {
        // Read value
#ifdef _WIN32_WCE
		DWORD l_dwValue;
		CString l_sValue;
        if(l_Key.QueryValue(l_dwValue, _T("Major")) == ERROR_SUCCESS)
		{
			l_sValue.Format(_T("%d."), l_dwValue);
			l_sVersion = l_sVersion + l_sValue;
		}
        if(l_Key.QueryValue(l_dwValue, _T("Minor")) == ERROR_SUCCESS)
		{
			l_sValue.Format(_T("%d."), l_dwValue);
			l_sVersion = l_sVersion + l_sValue;
		}
        if(l_Key.QueryValue(l_dwValue, _T("Build")) == ERROR_SUCCESS)
		{
			l_sValue.Format(_T("%d."), l_dwValue);
			l_sVersion = l_sVersion + l_sValue;
		}
        if(l_Key.QueryValue(l_dwValue, _T("Revision")) == ERROR_SUCCESS)
		{
			l_sValue.Format(_T("%d"), l_dwValue);
			l_sVersion = l_sVersion + l_sValue;
		}
#endif
        l_Key.Close();
    }
	else
	{

		OSVERSIONINFO stOsVersion;
		GetVersionEx(&stOsVersion);
		l_sVersion.Format(_T("%d.%d.%d.0"), stOsVersion.dwMajorVersion, stOsVersion.dwMinorVersion, stOsVersion.dwBuildNumber);
	}

	l_pSyncObj->SetValue(l_sVersion);
    l_pSyncObj->SignalCompletion();
	return l_pSyncObj;	  
  //## end CHIInterface::GetOsVersion%1108550310.body
}

//## Get and Set Operations for Class Attributes (implementation)

bool CHIInterface::GetbHardwarePresent ()
{
  //## begin CHIInterface::GetbHardwarePresent%3F448E380138.get preserve=no
  return m_bHardwarePresent;
  //## end CHIInterface::GetbHardwarePresent%3F448E380138.get
}

void CHIInterface::SetbHardwarePresent (bool value)
{
  //## begin CHIInterface::SetbHardwarePresent%3F448E380138.set preserve=no
  m_bHardwarePresent = value;
  //## end CHIInterface::SetbHardwarePresent%3F448E380138.set
}

//## Get and Set Operations for Associations (implementation)

CMap<DWORD, DWORD&, CHIProcessNodeConfig *, CHIProcessNodeConfig *&>& CHIInterface::GetNodeMap ()
{
  //## begin CHIInterface::GetNodeMap%3E96C0A3032C.get preserve=no
  return m_NodeMap;
  //## end CHIInterface::GetNodeMap%3E96C0A3032C.get
}

CArray<DWORD,DWORD>& CHIInterface::GetdwLogNrDigIOArray ()
{
  //## begin CHIInterface::GetdwLogNrDigIOArray%3EB669D3000F.get preserve=no
  return m_dwLogNrDigIOArray;
  //## end CHIInterface::GetdwLogNrDigIOArray%3EB669D3000F.get
}

CArray<DWORD,DWORD>& CHIInterface::GetdwLogNrWCEventArray ()
{
  //## begin CHIInterface::GetdwLogNrWCEventArray%3ECCC41A0148.get preserve=no
  return m_dwLogNrWCEventArray;
  //## end CHIInterface::GetdwLogNrWCEventArray%3ECCC41A0148.get
}

CArray<DWORD,DWORD>& CHIInterface::GetdwLogNrHWExceptionArray ()
{
  //## begin CHIInterface::GetdwLogNrHWExceptionArray%3ECCC5030157.get preserve=no
  return m_dwLogNrHWExceptionArray;
  //## end CHIInterface::GetdwLogNrHWExceptionArray%3ECCC5030157.get
}

CMap<DWORD, DWORD&, DWORD, DWORD&>& CHIInterface::GetIdMap ()
{
  //## begin CHIInterface::GetIdMap%3EF997440000.get preserve=no
  return m_IdMap;
  //## end CHIInterface::GetIdMap%3EF997440000.get
}

CString CHIInterface::GetsXMLVersion ()
{
  //## begin CHIInterface::GetsXMLVersion%41DD59F50365.get preserve=no
  return m_sXMLVersion;
  //## end CHIInterface::GetsXMLVersion%41DD59F50365.get
}

// Additional Declarations
  //## begin CHIInterface%3E2271DE02EA.declarations preserve=yes
  //## end CHIInterface%3E2271DE02EA.declarations

// Class CHIProcessNodeConfig 





CHIProcessNodeConfig::CHIProcessNodeConfig (DWORD p_dwAdrOffset, DWORD p_dwIndex)
  //## begin CHIProcessNodeConfig::CHIProcessNodeConfig%1050062593.hasinit preserve=no
      : m_dwAdrOffset(p_dwAdrOffset), m_dwIndex(p_dwIndex), m_eDataType(eHIDWORD)
  //## end CHIProcessNodeConfig::CHIProcessNodeConfig%1050062593.hasinit
  //## begin CHIProcessNodeConfig::CHIProcessNodeConfig%1050062593.initialization preserve=yes
  //## end CHIProcessNodeConfig::CHIProcessNodeConfig%1050062593.initialization
{
  //## begin CHIProcessNodeConfig::CHIProcessNodeConfig%1050062593.body preserve=yes
  //## end CHIProcessNodeConfig::CHIProcessNodeConfig%1050062593.body
}


CHIProcessNodeConfig::~CHIProcessNodeConfig()
{
  //## begin CHIProcessNodeConfig::~CHIProcessNodeConfig%.body preserve=yes
  //## end CHIProcessNodeConfig::~CHIProcessNodeConfig%.body
}



//## Other Operations (implementation)
DWORD* CHIProcessNodeConfig::GetAddress ()
{
  //## begin CHIProcessNodeConfig::GetAddress%1050062594.body preserve=yes
  return(CHITReservedSharedMemory::GetpVAdrProcessImage() + m_dwAdrOffset);
  //## end CHIProcessNodeConfig::GetAddress%1050062594.body
}

//## Get and Set Operations for Class Attributes (implementation)

DWORD CHIProcessNodeConfig::GetdwAdrOffset ()
{
  //## begin CHIProcessNodeConfig::GetdwAdrOffset%3E96C5CF0128.get preserve=no
  return m_dwAdrOffset;
  //## end CHIProcessNodeConfig::GetdwAdrOffset%3E96C5CF0128.get
}

DWORD CHIProcessNodeConfig::GetdwIndex ()
{
  //## begin CHIProcessNodeConfig::GetdwIndex%3E96C629034B.get preserve=no
  return m_dwIndex;
  //## end CHIProcessNodeConfig::GetdwIndex%3E96C629034B.get
}

// Additional Declarations
  //## begin CHIProcessNodeConfig%3E96C03C034B.declarations preserve=yes
  //## end CHIProcessNodeConfig%3E96C03C034B.declarations

//## begin module%3E2279BE0161.epilog preserve=yes
//## end module%3E2279BE0161.epilog
