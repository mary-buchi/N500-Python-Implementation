//## begin module%3FDD891F0186.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD891F0186.cm

//## begin module%3FDD891F0186.cp preserve=no
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
//## end module%3FDD891F0186.cp

//## Module: EBI2CEPROMcomd%3FDD891F0186; Package body
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FDD891F0186.additionalIncludes preserve=no
//## end module%3FDD891F0186.additionalIncludes

//## begin module%3FDD891F0186.includes preserve=yes
//## end module%3FDD891F0186.includes

// EBPIcpst
#include "EBPIcpst.h"
// EBPItype
#include "EBPItype.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBHIintf
#include "EBHIintf.h"
// EBI2CEPROMexcp
#include "EBI2CEPROMexcp.h"
// EBI2CEPROMident
#include "EBI2CEPROMident.h"
// EBHITrsm
#include "EBHITrsm.h"
// EBI2CEPROMcomd
#include "EBI2CEPROMcomd.h"


//## begin module%3FDD891F0186.declarations preserve=no
//## end module%3FDD891F0186.declarations

//## begin module%3FDD891F0186.additionalDeclarations preserve=yes
//## end module%3FDD891F0186.additionalDeclarations


// Class CI2CEprom24LC515Command 




CI2CEprom24LC515Command::CI2CEprom24LC515Command (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed)
  //## begin CI2CEprom24LC515Command::CI2CEprom24LC515Command%1071483522.hasinit preserve=no
      : m_dwI2CBusNumber(p_dwI2CBusNumber), m_dwI2CTransferSpeed(p_dwI2CTransferSpeed)
  //## end CI2CEprom24LC515Command::CI2CEprom24LC515Command%1071483522.hasinit
  //## begin CI2CEprom24LC515Command::CI2CEprom24LC515Command%1071483522.initialization preserve=yes
  ,CHII2CCommand()
  //## end CI2CEprom24LC515Command::CI2CEprom24LC515Command%1071483522.initialization
{
  //## begin CI2CEprom24LC515Command::CI2CEprom24LC515Command%1071483522.body preserve=yes
 
  m_pI2CDataStream = new CPII2CDataStream(p_pcI2CStream, p_nLength);
  //## end CI2CEprom24LC515Command::CI2CEprom24LC515Command%1071483522.body
}


CI2CEprom24LC515Command::~CI2CEprom24LC515Command()
{
  //## begin CI2CEprom24LC515Command::~CI2CEprom24LC515Command%.body preserve=yes
  m_pI2CDataStream->ReleaseRef();
  //## end CI2CEprom24LC515Command::~CI2CEprom24LC515Command%.body
}



//## Other Operations (implementation)
bool CI2CEprom24LC515Command::Execute ()
{
  //## begin CI2CEprom24LC515Command::Execute%1071483523.body preserve=yes
  CCOSyncObjectPtr l_pSyncObjI2C = NULL;
  PDWORD l_pdwWriteAdr = IHIInterface::GetInstance()->GetI2CWriteStartAdr();
  PDWORD l_pdwReadAdr = IHIInterface::GetInstance()->GetI2CReadStartAdr();
  DWORD l_dwMaxDataSize = CHII2CParameter::GetcdwI2CMaxDataSize();
  PBYTE l_pcI2CAnswerData = NULL;
  CPII2CDataStream *l_pI2CAnswerDataStream = NULL;
 
  try
  {
#ifdef _WIN32_WCE  
    l_pcI2CAnswerData = new BYTE[m_pI2CDataStream->GetnSize()];

    // check data size vs. max. available buffer size
    if (m_pI2CDataStream->GetnSize() >= (int)l_dwMaxDataSize)
    {
      // actual buffer size >= than available buffer transfer size
      throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_WRONG_DATA_SIZE, __FILE__, __LINE__, 0);
    }
    

    // signal I2C event
    l_pSyncObjI2C = IHIInterface::GetInstance()->OpenEvent(CHII2CParameter::GetcdwI2CEventID(),eHIUndefined);

    // set I2C parameter in the I2C Ctrl Register
    IHIInterface::GetInstance()->SetDWord(CHII2CParameter::GetcdwI2CTransferSpeedID(),m_dwI2CTransferSpeed);
    
    IHIInterface::GetInstance()->SetDWord(CHII2CParameter::GetcdwI2CBusNumberID(),m_dwI2CBusNumber);

    // zero Memory
    ZeroMemory((PBYTE)l_pdwWriteAdr,l_dwMaxDataSize);
    // copy data TO the process image
    CopyMemory((PBYTE)l_pdwWriteAdr, // destination
              m_pI2CDataStream->GetpcI2CDataStream(), // source
              m_pI2CDataStream->GetnSize()); // size in BYTE
    
    // set I2C data valid 
    IHIInterface::GetInstance()->SetDWord(CHII2CParameter::GetcdwI2CValidID(),1);
    
    l_pSyncObjI2C->Synchronize(10000);

    // copy data FROM the process image
    CopyMemory(l_pcI2CAnswerData, // destination
              (PBYTE)l_pdwReadAdr, // source
              m_pI2CDataStream->GetnSize()); // size in BYTE


    IHIInterface::GetInstance()->CloseEvent(CHII2CParameter::GetcdwI2CEventID(),l_pSyncObjI2C);
    

    l_pI2CAnswerDataStream = new CPII2CDataStream(l_pcI2CAnswerData, m_pI2CDataStream->GetnSize());
    m_pSyncObj->SetValue(l_pI2CAnswerDataStream);
    m_pSyncObj->SignalCompletion();
#else

    m_pI2CDataStream->AddRef();
    m_pSyncObj->SetValue(m_pI2CDataStream);
    m_pSyncObj->SignalCompletion();
  
#endif

  }
  catch(XCOException* p_pException)
  {
    CCOSystemMonitorInterface::GetpMonitor()->FlushQueue();
    if (l_pI2CAnswerDataStream)
      delete [] l_pI2CAnswerDataStream;
    l_pI2CAnswerDataStream = NULL;

    m_pSyncObj->AttachException(p_pException);
  }
  return true;
  //## end CI2CEprom24LC515Command::Execute%1071483523.body
}

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CI2CEprom24LC515Command::GetdwI2CBusNumber () const
{
  //## begin CI2CEprom24LC515Command::GetdwI2CBusNumber%3FFD6127038A.get preserve=no
  return m_dwI2CBusNumber;
  //## end CI2CEprom24LC515Command::GetdwI2CBusNumber%3FFD6127038A.get
}

const DWORD CI2CEprom24LC515Command::GetdwI2CTransferSpeed () const
{
  //## begin CI2CEprom24LC515Command::GetdwI2CTransferSpeed%3FFD612703A9.get preserve=no
  return m_dwI2CTransferSpeed;
  //## end CI2CEprom24LC515Command::GetdwI2CTransferSpeed%3FFD612703A9.get
}

// Additional Declarations
  //## begin CI2CEprom24LC515Command%3FDD8FA5000F.declarations preserve=yes
  //## end CI2CEprom24LC515Command%3FDD8FA5000F.declarations

//## begin module%3FDD891F0186.epilog preserve=yes
//## end module%3FDD891F0186.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CI2CEprom24LC515Command::CI2CEprom24LC515Command%1078405493.body preserve=no
  m_pI2CDataStream = new CPII2CDataStream((PBYTE)p_pdwI2CStream, p_nLength);
//## end CI2CEprom24LC515Command::CI2CEprom24LC515Command%1078405493.body

#endif
