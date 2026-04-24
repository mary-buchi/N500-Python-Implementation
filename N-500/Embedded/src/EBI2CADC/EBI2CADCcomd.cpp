//## begin module%3FFC0DFC034B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FFC0DFC034B.cm

//## begin module%3FFC0DFC034B.cp preserve=no
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
//## end module%3FFC0DFC034B.cp

//## Module: EBI2CADCcomd%3FFC0DFC034B; Package body
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FFC0DFC034B.additionalIncludes preserve=no
//## end module%3FFC0DFC034B.additionalIncludes

//## begin module%3FFC0DFC034B.includes preserve=yes
//## end module%3FFC0DFC034B.includes

// EBPItype
#include "EBPItype.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBI2CADCexcp
#include "EBI2CADCexcp.h"
// EBI2CADCident
#include "EBI2CADCident.h"
// EBI2CADCcomd
#include "EBI2CADCcomd.h"


//## begin module%3FFC0DFC034B.declarations preserve=no
//## end module%3FFC0DFC034B.declarations

//## begin module%3FFC0DFC034B.additionalDeclarations preserve=yes
//## end module%3FFC0DFC034B.additionalDeclarations


// Class CI2CADCMAX1037Command 




CI2CADCMAX1037Command::CI2CADCMAX1037Command (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed)
  //## begin CI2CADCMAX1037Command::CI2CADCMAX1037Command%1073465618.hasinit preserve=no
      : m_dwI2CBusNumber(p_dwI2CBusNumber), m_dwI2CTransferSpeed(p_dwI2CTransferSpeed)
  //## end CI2CADCMAX1037Command::CI2CADCMAX1037Command%1073465618.hasinit
  //## begin CI2CADCMAX1037Command::CI2CADCMAX1037Command%1073465618.initialization preserve=yes
  ,CHII2CCommand()
  //## end CI2CADCMAX1037Command::CI2CADCMAX1037Command%1073465618.initialization
{
  //## begin CI2CADCMAX1037Command::CI2CADCMAX1037Command%1073465618.body preserve=yes
  m_pI2CDataStream = new CPII2CDataStream(p_pcI2CStream, p_nLength);
  //## end CI2CADCMAX1037Command::CI2CADCMAX1037Command%1073465618.body
}


CI2CADCMAX1037Command::~CI2CADCMAX1037Command()
{
  //## begin CI2CADCMAX1037Command::~CI2CADCMAX1037Command%.body preserve=yes
  m_pI2CDataStream->ReleaseRef();
  //## end CI2CADCMAX1037Command::~CI2CADCMAX1037Command%.body
}



//## Other Operations (implementation)
bool CI2CADCMAX1037Command::Execute ()
{
  //## begin CI2CADCMAX1037Command::Execute%1073465619.body preserve=yes
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
      throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_WRONG_DATA_SIZE, __FILE__, __LINE__, 0);
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
  //## end CI2CADCMAX1037Command::Execute%1073465619.body
}

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CI2CADCMAX1037Command::GetdwI2CBusNumber () const
{
  //## begin CI2CADCMAX1037Command::GetdwI2CBusNumber%3FFD5F5D004E.get preserve=no
  return m_dwI2CBusNumber;
  //## end CI2CADCMAX1037Command::GetdwI2CBusNumber%3FFD5F5D004E.get
}

const DWORD CI2CADCMAX1037Command::GetdwI2CTransferSpeed () const
{
  //## begin CI2CADCMAX1037Command::GetdwI2CTransferSpeed%3FFD5F5D007D.get preserve=no
  return m_dwI2CTransferSpeed;
  //## end CI2CADCMAX1037Command::GetdwI2CTransferSpeed%3FFD5F5D007D.get
}

// Additional Declarations
  //## begin CI2CADCMAX1037Command%3FFC0E700261.declarations preserve=yes
  //## end CI2CADCMAX1037Command%3FFC0E700261.declarations

//## begin module%3FFC0DFC034B.epilog preserve=yes
//## end module%3FFC0DFC034B.epilog
