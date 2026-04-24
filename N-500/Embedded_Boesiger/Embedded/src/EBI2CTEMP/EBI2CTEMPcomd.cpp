//## begin module%3FD73DA90138.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FD73DA90138.cm

//## begin module%3FD73DA90138.cp preserve=no
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
//## end module%3FD73DA90138.cp

//## Module: EBI2CTEMPcomd%3FD73DA90138; Package body
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FD73DA90138.additionalIncludes preserve=no
//## end module%3FD73DA90138.additionalIncludes

//## begin module%3FD73DA90138.includes preserve=yes
//## end module%3FD73DA90138.includes

// EBPItype
#include "EBPItype.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBI2CTEMPcomd
#include "EBI2CTEMPcomd.h"
// EBI2CTEMPexcp
#include "EBI2CTEMPexcp.h"
// EBI2CTEMPident
#include "EBI2CTEMPident.h"
// EBHITrsm
#include "EBHITrsm.h"


//## begin module%3FD73DA90138.declarations preserve=no
//## end module%3FD73DA90138.declarations

//## begin module%3FD73DA90138.additionalDeclarations preserve=yes
//## end module%3FD73DA90138.additionalDeclarations


// Class CI2CTempSensor1631ZCommand 




CI2CTempSensor1631ZCommand::CI2CTempSensor1631ZCommand (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed)
  //## begin CI2CTempSensor1631ZCommand::CI2CTempSensor1631ZCommand%1071063016.hasinit preserve=no
      : m_dwI2CBusNumber(p_dwI2CBusNumber), m_dwI2CTransferSpeed(p_dwI2CTransferSpeed)
  //## end CI2CTempSensor1631ZCommand::CI2CTempSensor1631ZCommand%1071063016.hasinit
  //## begin CI2CTempSensor1631ZCommand::CI2CTempSensor1631ZCommand%1071063016.initialization preserve=yes
  ,CHII2CCommand()
  //## end CI2CTempSensor1631ZCommand::CI2CTempSensor1631ZCommand%1071063016.initialization
{
  //## begin CI2CTempSensor1631ZCommand::CI2CTempSensor1631ZCommand%1071063016.body preserve=yes
  m_pI2CDataStream = new CPII2CDataStream(p_pcI2CStream, p_nLength);
  //## end CI2CTempSensor1631ZCommand::CI2CTempSensor1631ZCommand%1071063016.body
}


CI2CTempSensor1631ZCommand::~CI2CTempSensor1631ZCommand()
{
  //## begin CI2CTempSensor1631ZCommand::~CI2CTempSensor1631ZCommand%.body preserve=yes
  m_pI2CDataStream->ReleaseRef();
  //## end CI2CTempSensor1631ZCommand::~CI2CTempSensor1631ZCommand%.body
}



//## Other Operations (implementation)
bool CI2CTempSensor1631ZCommand::Execute ()
{
  //## begin CI2CTempSensor1631ZCommand::Execute%1071063017.body preserve=yes
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
      throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_WRONG_DATA_SIZE, __FILE__, __LINE__, 0);
    }

    // signal I2C event
    l_pSyncObjI2C = IHIInterface::GetInstance()->OpenEvent(CHII2CParameter::GetcdwI2CEventID(),eHIUndefined);

    // set I2C parameter in the I2C Ctrl Register
    IHIInterface::GetInstance()->SetDWord(CHII2CParameter::GetcdwI2CTransferSpeedID(),m_dwI2CTransferSpeed);
    IHIInterface::GetInstance()->SetDWord(CHII2CParameter::GetcdwI2CBusNumberID(),m_dwI2CBusNumber);

    // zero memory
    ZeroMemory((PBYTE)l_pdwWriteAdr, l_dwMaxDataSize);
    ZeroMemory((PBYTE)l_pdwReadAdr, l_dwMaxDataSize);

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
    if (l_pI2CAnswerDataStream)
      delete [] l_pI2CAnswerDataStream;
    l_pI2CAnswerDataStream = NULL;

    m_pSyncObj->AttachException(p_pException);
  }
  return true;
  //## end CI2CTempSensor1631ZCommand::Execute%1071063017.body
}

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CI2CTempSensor1631ZCommand::GetdwI2CBusNumber () const
{
  //## begin CI2CTempSensor1631ZCommand::GetdwI2CBusNumber%3FFD6125004E.get preserve=no
  return m_dwI2CBusNumber;
  //## end CI2CTempSensor1631ZCommand::GetdwI2CBusNumber%3FFD6125004E.get
}

const DWORD CI2CTempSensor1631ZCommand::GetdwI2CTransferSpeed () const
{
  //## begin CI2CTempSensor1631ZCommand::GetdwI2CTransferSpeed%3FFD6125007D.get preserve=no
  return m_dwI2CTransferSpeed;
  //## end CI2CTempSensor1631ZCommand::GetdwI2CTransferSpeed%3FFD6125007D.get
}

// Additional Declarations
  //## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.declarations preserve=yes
  //## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.declarations

//## begin module%3FD73DA90138.epilog preserve=yes
//## end module%3FD73DA90138.epilog
