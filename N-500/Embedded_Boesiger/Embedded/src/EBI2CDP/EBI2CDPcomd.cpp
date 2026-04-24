//## begin module%3FFBC9D902CE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FFBC9D902CE.cm

//## begin module%3FFBC9D902CE.cp preserve=no
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
//## end module%3FFBC9D902CE.cp

//## Module: EBI2CDPcomd%3FFBC9D902CE; Package body
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FFBC9D902CE.additionalIncludes preserve=no
//## end module%3FFBC9D902CE.additionalIncludes

//## begin module%3FFBC9D902CE.includes preserve=yes
//## end module%3FFBC9D902CE.includes

// EBPItype
#include "EBPItype.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBI2CDPcomd
#include "EBI2CDPcomd.h"
// EBI2CDPexcp
#include "EBI2CDPexcp.h"
// EBI2CDPident
#include "EBI2CDPident.h"


//## begin module%3FFBC9D902CE.declarations preserve=no
//## end module%3FFBC9D902CE.declarations

//## begin module%3FFBC9D902CE.additionalDeclarations preserve=yes
//## end module%3FFBC9D902CE.additionalDeclarations


// Class CI2CDigitalPotiAD5245Command 




CI2CDigitalPotiAD5245Command::CI2CDigitalPotiAD5245Command (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed)
  //## begin CI2CDigitalPotiAD5245Command::CI2CDigitalPotiAD5245Command%1073465616.hasinit preserve=no
      : m_dwI2CBusNumber(p_dwI2CBusNumber), m_dwI2CTransferSpeed(p_dwI2CTransferSpeed)
  //## end CI2CDigitalPotiAD5245Command::CI2CDigitalPotiAD5245Command%1073465616.hasinit
  //## begin CI2CDigitalPotiAD5245Command::CI2CDigitalPotiAD5245Command%1073465616.initialization preserve=yes
  ,CHII2CCommand()
  //## end CI2CDigitalPotiAD5245Command::CI2CDigitalPotiAD5245Command%1073465616.initialization
{
  //## begin CI2CDigitalPotiAD5245Command::CI2CDigitalPotiAD5245Command%1073465616.body preserve=yes
  m_pI2CDataStream = new CPII2CDataStream(p_pcI2CStream, p_nLength);
  //## end CI2CDigitalPotiAD5245Command::CI2CDigitalPotiAD5245Command%1073465616.body
}


CI2CDigitalPotiAD5245Command::~CI2CDigitalPotiAD5245Command()
{
  //## begin CI2CDigitalPotiAD5245Command::~CI2CDigitalPotiAD5245Command%.body preserve=yes
  m_pI2CDataStream->ReleaseRef();
  //## end CI2CDigitalPotiAD5245Command::~CI2CDigitalPotiAD5245Command%.body
}



//## Other Operations (implementation)
bool CI2CDigitalPotiAD5245Command::Execute ()
{
  //## begin CI2CDigitalPotiAD5245Command::Execute%1073465617.body preserve=yes
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
      throw new XI2CDPExceptionError(I2CDP_ID, IDE_I2C_INTF_AD5245_WRONG_DATA_SIZE, __FILE__, __LINE__, 0);
    }

    // signal I2C event
    l_pSyncObjI2C = IHIInterface::GetInstance()->OpenEvent(CHII2CParameter::GetcdwI2CEventID(),eHIUndefined);

    // set I2C parameter in the I2C Ctrl Register
    IHIInterface::GetInstance()->SetDWord(CHII2CParameter::GetcdwI2CTransferSpeedID(),m_dwI2CTransferSpeed);
    IHIInterface::GetInstance()->SetDWord(CHII2CParameter::GetcdwI2CBusNumberID(),m_dwI2CBusNumber);

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
  //## end CI2CDigitalPotiAD5245Command::Execute%1073465617.body
}

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CI2CDigitalPotiAD5245Command::GetdwI2CBusNumber () const
{
  //## begin CI2CDigitalPotiAD5245Command::GetdwI2CBusNumber%3FFD60EA0222.get preserve=no
  return m_dwI2CBusNumber;
  //## end CI2CDigitalPotiAD5245Command::GetdwI2CBusNumber%3FFD60EA0222.get
}

const DWORD CI2CDigitalPotiAD5245Command::GetdwI2CTransferSpeed () const
{
  //## begin CI2CDigitalPotiAD5245Command::GetdwI2CTransferSpeed%3FFD60EA0242.get preserve=no
  return m_dwI2CTransferSpeed;
  //## end CI2CDigitalPotiAD5245Command::GetdwI2CTransferSpeed%3FFD60EA0242.get
}

// Additional Declarations
  //## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.declarations preserve=yes
  //## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.declarations

//## begin module%3FFBC9D902CE.epilog preserve=yes
//## end module%3FFBC9D902CE.epilog


