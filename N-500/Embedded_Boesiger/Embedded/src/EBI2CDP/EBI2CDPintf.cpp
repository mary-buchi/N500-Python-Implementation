//## begin module%3F4B4E7A036B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4E7A036B.cm

//## begin module%3F4B4E7A036B.cp preserve=no
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
//## end module%3F4B4E7A036B.cp

//## Module: EBI2CDPintf%3F4B4E7A036B; Package body
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F4B4E7A036B.additionalIncludes preserve=no
//## end module%3F4B4E7A036B.additionalIncludes

//## begin module%3F4B4E7A036B.includes preserve=yes
//## end module%3F4B4E7A036B.includes

// EBPIcpst
#include "EBPIcpst.h"
// EBPItype
#include "EBPItype.h"
// EBHIthrd
#include "EBHIthrd.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBI2CSTDLIBcomd
#include "EBI2CSTDLIBcomd.h"
// EBI2CSTDLIBconv
#include "EBI2CSTDLIBconv.h"
// EBI2CDPcomd
#include "EBI2CDPcomd.h"
// EBI2CDPexcp
#include "EBI2CDPexcp.h"
// EBI2CDPintf
#include "EBI2CDPintf.h"
// EBI2CDPident
#include "EBI2CDPident.h"


//## begin module%3F4B4E7A036B.declarations preserve=no
//## end module%3F4B4E7A036B.declarations

//## begin module%3F4B4E7A036B.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}
//## end module%3F4B4E7A036B.additionalDeclarations


// Class CI2CDigitalPotiAD5245 












CI2CDigitalPotiAD5245::CI2CDigitalPotiAD5245 (UINT p_uiID)
  //## begin CI2CDigitalPotiAD5245::CI2CDigitalPotiAD5245%1061902077.hasinit preserve=no
      : m_cInstruction(0x00), m_cMaskDPAD5245(0x1), m_cMaskWriteAccess(0xFE), m_cMaskReadAccess(0x01), m_uiID(p_uiID), m_bHWPresent(false)
  //## end CI2CDigitalPotiAD5245::CI2CDigitalPotiAD5245%1061902077.hasinit
  //## begin CI2CDigitalPotiAD5245::CI2CDigitalPotiAD5245%1061902077.initialization preserve=yes
   , IPII2CDigitalPotiAD5245(I2CDP_ID)
  //## end CI2CDigitalPotiAD5245::CI2CDigitalPotiAD5245%1061902077.initialization
{
  //## begin CI2CDigitalPotiAD5245::CI2CDigitalPotiAD5245%1061902077.body preserve=yes
  m_bHWPresent = CPIComponentsState::GetInstance()->GetComponentState(I2CDP_ID);

  // get log .object ID from map table
  CMap<DWORD, DWORD&, DWORD, DWORD&> &l_IdMap = IHIInterface::GetInstance()->GetIdMap(); 
  DWORD l_dwID = (DWORD)m_uiID;
  UINT l_uiID = l_IdMap[l_dwID];

  // determin process image offset address
  m_cI2CDeviceAdr = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr());
  m_cI2CBusNumber = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CBusNumber()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CBusNumber());
  m_cI2CTransferSpeed = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CTransferSpeed()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CTransferSpeed());
  m_cI2CDevice = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskControlStates()) >> CHIProcessImageParameter::GetcdwShiftCountsControlStates());

  CO_TRACE1(I2CDP_ID,_T("I2C Device %d DP AD5245 created"),m_uiID);
  CO_TRACE1(I2CDP_ID,_T("DP AD5245 - I2C Device Addresse: %#4x"), (DWORD)m_cI2CDeviceAdr);
  CO_TRACE1(I2CDP_ID,_T("DP AD5245 - I2C Bus Number: %d"), (DWORD)m_cI2CBusNumber);
  CO_TRACE1(I2CDP_ID,_T("DP AD5245 - I2C Transfer Speed: %d"), (DWORD)m_cI2CTransferSpeed);
  //## end CI2CDigitalPotiAD5245::CI2CDigitalPotiAD5245%1061902077.body
}


CI2CDigitalPotiAD5245::~CI2CDigitalPotiAD5245()
{
  //## begin CI2CDigitalPotiAD5245::~CI2CDigitalPotiAD5245%.body preserve=yes
  CO_TRACE1(I2CDP_ID,_T("I2C Device %d DP AD5245 deleted"),m_uiID);
  //## end CI2CDigitalPotiAD5245::~CI2CDigitalPotiAD5245%.body
}



//## Other Operations (implementation)
UINT CI2CDigitalPotiAD5245::GetuiID ()
{
  //## begin CI2CDigitalPotiAD5245::GetuiID%1061902078.body preserve=yes
  return m_uiID;
  //## end CI2CDigitalPotiAD5245::GetuiID%1061902078.body
}

CCOSyncObject* CI2CDigitalPotiAD5245::Startup ()
{
  //## begin CI2CDigitalPotiAD5245::Startup%1061902079.body preserve=yes
#ifdef _WIN32_WCE
#endif
  
  DUMMY_RETURN;
  //## end CI2CDigitalPotiAD5245::Startup%1061902079.body
}

CCOSyncObject* CI2CDigitalPotiAD5245::Shutdown ()
{
  //## begin CI2CDigitalPotiAD5245::Shutdown%1061902080.body preserve=yes
  DUMMY_RETURN;
  //## end CI2CDigitalPotiAD5245::Shutdown%1061902080.body
}

CCOSyncObject* CI2CDigitalPotiAD5245::ConnectionEstablished ()
{
  //## begin CI2CDigitalPotiAD5245::ConnectionEstablished%1061902081.body preserve=yes
  DUMMY_RETURN;
  //## end CI2CDigitalPotiAD5245::ConnectionEstablished%1061902081.body
}

CCOSyncObject* CI2CDigitalPotiAD5245::ConnectionLost ()
{
  //## begin CI2CDigitalPotiAD5245::ConnectionLost%1061902082.body preserve=yes
  DUMMY_RETURN;
  //## end CI2CDigitalPotiAD5245::ConnectionLost%1061902082.body
}

CCOSyncObject* CI2CDigitalPotiAD5245::WriteValue (BYTE p_cValue)
{
  //## begin CI2CDigitalPotiAD5245::WriteValue%1061902083.body preserve=yes
  CCOSyncObject *l_pSyncObj = new CCOSyncObject();
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  CI2CDigitalPotiAD5245Command *l_pCmd = NULL;

  if (!m_bHWPresent)
  {
      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
  }

  PDWORD l_pdwI2CStream = NULL;

  char l_cAdrByte = (m_cI2CDeviceAdr << 0x1);

  char l_cAdr[20], l_cInstruction[20], l_cData[20], l_cI2CStream[1000];
  strcpy(l_cAdr,""); strcpy(l_cInstruction,""); strcpy(l_cData,""); strcpy(l_cI2CStream,"");

  DWORD l_dwErrorCode = 0;
  DWORD l_dwBytesWritten = 0;

  // check device identification (last 12 bit)
  try
  {
    if (m_cI2CDevice && m_cMaskDPAD5245)
    {
      // I2C digital ponti DP AD5245
      // set control address byte
      l_cAdrByte&= m_cMaskWriteAccess;
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cAdrByte, l_cAdr);

      // instruction byte
      CI2CSTDLIBConvert::ByteToI2CCharStream(m_cInstruction, l_cInstruction);
      
      // data byte
      //CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cData);
      CI2CSTDLIBConvert::ByteToI2CCharStream((char)p_cValue, l_cData);

      // I2C stream string
      // START + Adr + ACK + Instruction + ACK + Data + NACK + STOP
      sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cAdr, CI2CSTDLIBCmd::m_cI2CAck,
                           //l_cInstruction,CI2CSTDLIBCmd::m_cI2CAck,l_cData,CI2CSTDLIBCmd::m_cI2CNack,
                           l_cInstruction,CI2CSTDLIBCmd::m_cI2CAck,l_cData,CI2CSTDLIBCmd::m_cI2CAck,
                           CI2CSTDLIBCmd::m_cI2CStop);

      // Write Value
      CO_TRACE(I2CDP_ID, _T("Send:"));
      CO_TRACE(I2CDP_ID, l_cI2CStream);
      CO_TRACE(I2CDP_ID, _T("/"));

      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

      // add command (WriteMode) to the I2C worker thread queue
      l_pCmd = new CI2CDigitalPotiAD5245Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
  
      l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
      l_pI2CSyncObj->Synchronize();
      l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
      l_pCmd->ReleaseRef();
      l_pCmd = NULL;
      
      // convert answer data byte stream data to I2C String
      l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
      l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);

      // convert byte stream data to I2C String
      strcpy(l_cI2CStream,"");
      CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;

      // Write Value
      CO_TRACE(I2CDP_ID, _T("Receive:"));
      CO_TRACE(I2CDP_ID, l_cI2CStream);
      CO_TRACE(I2CDP_ID, _T("/"));

      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
           !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 54))
      {
        // command failed
        throw new XI2CDPExceptionError(I2CDP_ID, IDE_I2C_INTF_AD5245_WRITE_ACK_ERROR, __FILE__, __LINE__, 0);
      }

      l_pSyncObj->SignalCompletion();
    }
    else
    {
      throw new XI2CDPExceptionError(I2CDP_ID, IDE_I2C_INTF_AD5245_WRONG_ID, __FILE__, __LINE__, 0);
    }
  }
  catch(XCOExceptionError* p_pException)
  {
    if (l_pCmd)
      l_pCmd->ReleaseRef();
    l_pCmd = NULL;

    if (l_pI2CSyncObj)
      l_pI2CSyncObj->ReleaseRef();
    l_pI2CSyncObj = NULL;

    if (l_pI2CAnswerDataStream)
      l_pI2CAnswerDataStream->ReleaseRef();
    l_pI2CAnswerDataStream = NULL;

    if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
    {
       p_pException->Delete();
       l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CDP_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
    }
    else
    {
	   l_pSyncObj->AttachException(p_pException);
    }    
  }
  return l_pSyncObj;
  //## end CI2CDigitalPotiAD5245::WriteValue%1061902083.body
}

CCOSyncObjectInt* CI2CDigitalPotiAD5245::ReadValue ()
{
  //## begin CI2CDigitalPotiAD5245::ReadValue%1061902084.body preserve=yes
  CCOSyncObjectInt *l_pSyncObj = new CCOSyncObjectInt(0);
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  CI2CDigitalPotiAD5245Command *l_pCmd = NULL;

  if (!m_bHWPresent)
  {
      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
  }

  PDWORD l_pdwI2CStream = NULL;
  BYTE l_cRetVal = 0;

  char l_cAdrByte = (m_cI2CDeviceAdr << 0x1);

  char l_cAdr[20], l_cInstruction[20], l_cData[20], l_cI2CStream[1000];
  strcpy(l_cAdr,""); strcpy(l_cInstruction,""); strcpy(l_cData,""); strcpy(l_cI2CStream,"");

  DWORD l_dwErrorCode = 0;
  DWORD l_dwBytesWritten = 0;

  // check device identification (last 12 bit)
  try
  {
    if (m_cI2CDevice && m_cMaskDPAD5245)
    {
      // I2C digital ponti DP AD5245
      // set control address byte
      l_cAdrByte|= m_cMaskReadAccess;
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cAdrByte, l_cAdr);

      // data byte
      CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cData);

      // I2C stream string
      // START + Adr + ACK + Data + NACK + STOP
      sprintf(l_cI2CStream,"%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cAdr, CI2CSTDLIBCmd::m_cI2CAck,
                           l_cData,CI2CSTDLIBCmd::m_cI2CAck,CI2CSTDLIBCmd::m_cI2CStop);

      // Read Value
      CO_TRACE(I2CDP_ID, _T("Send:"));
      CO_TRACE(I2CDP_ID, l_cI2CStream);
      CO_TRACE(I2CDP_ID, _T("/"));

      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

      // add command (WriteMode) to the I2C worker thread queue
      l_pCmd = new CI2CDigitalPotiAD5245Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
  
      l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
      l_pI2CSyncObj->Synchronize();
      l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
      l_pCmd->ReleaseRef();
      l_pCmd = NULL;
      
      // convert answer data byte stream data to I2C String
      l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
      l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);

      // convert byte stream data to I2C String
      strcpy(l_cI2CStream,"");
      CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;

      // Read Value
      CO_TRACE(I2CDP_ID, _T("Receive:"));
      CO_TRACE(I2CDP_ID, l_cI2CStream);
      CO_TRACE(I2CDP_ID, _T("/"));

      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckACK(l_cI2CStream, 36))
      {
        // command failed
        throw new XI2CDPExceptionError(I2CDP_ID, IDE_I2C_INTF_AD5245_WRITE_ACK_ERROR, __FILE__, __LINE__, 0);
      }
      
      // get data
      strcpy(l_cData, "");
      l_cRetVal = 0;
      strncat(l_cData, &l_cI2CStream[20],16);
      if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cData, l_cRetVal))
      {
        // no data found
        throw new XI2CDPExceptionError(I2CDP_ID, IDE_I2C_INTF_AD5245_READ_ERROR, __FILE__, __LINE__, 0);
      }
      l_pSyncObj->SetValue((int)l_cRetVal);
      l_pSyncObj->SignalCompletion();
    }
    else
    {
      throw new XI2CDPExceptionError(I2CDP_ID, IDE_I2C_INTF_AD5245_WRONG_ID, __FILE__, __LINE__, 0);
    }
  }
  catch(XCOExceptionError* p_pException)
  {
    if (l_pCmd)
      l_pCmd->ReleaseRef();
    l_pCmd = NULL;

    if (l_pI2CSyncObj)
      l_pI2CSyncObj->ReleaseRef();
    l_pI2CSyncObj = NULL;

    if (l_pI2CAnswerDataStream)
      l_pI2CAnswerDataStream->ReleaseRef();
    l_pI2CAnswerDataStream = NULL;
    
    if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
    {
       p_pException->Delete();
       l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CDP_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
    }
    else
    {
	   l_pSyncObj->AttachException(p_pException);
    }    
  }
  return l_pSyncObj;

  //## end CI2CDigitalPotiAD5245::ReadValue%1061902084.body
}

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CI2CDigitalPotiAD5245::GetdwI2CBaseAdr () const
{
  //## begin CI2CDigitalPotiAD5245::GetdwI2CBaseAdr%3FFBD7D2000F.get preserve=no
  return m_dwI2CBaseAdr;
  //## end CI2CDigitalPotiAD5245::GetdwI2CBaseAdr%3FFBD7D2000F.get
}

const BYTE CI2CDigitalPotiAD5245::GetcI2CDeviceAdr () const
{
  //## begin CI2CDigitalPotiAD5245::GetcI2CDeviceAdr%3F5D78C1007D.get preserve=no
  return m_cI2CDeviceAdr;
  //## end CI2CDigitalPotiAD5245::GetcI2CDeviceAdr%3F5D78C1007D.get
}

const BYTE CI2CDigitalPotiAD5245::GetcI2CBusNumber () const
{
  //## begin CI2CDigitalPotiAD5245::GetcI2CBusNumber%3F5D78C1009C.get preserve=no
  return m_cI2CBusNumber;
  //## end CI2CDigitalPotiAD5245::GetcI2CBusNumber%3F5D78C1009C.get
}

const BYTE CI2CDigitalPotiAD5245::GetcI2CTransferSpeed () const
{
  //## begin CI2CDigitalPotiAD5245::GetcI2CTransferSpeed%3F5D78C100AB.get preserve=no
  return m_cI2CTransferSpeed;
  //## end CI2CDigitalPotiAD5245::GetcI2CTransferSpeed%3F5D78C100AB.get
}

const BYTE CI2CDigitalPotiAD5245::GetcI2CDevice () const
{
  //## begin CI2CDigitalPotiAD5245::GetcI2CDevice%3F5D78C100BB.get preserve=no
  return m_cI2CDevice;
  //## end CI2CDigitalPotiAD5245::GetcI2CDevice%3F5D78C100BB.get
}

const BYTE CI2CDigitalPotiAD5245::GetcInstruction () const
{
  //## begin CI2CDigitalPotiAD5245::GetcInstruction%3FFBD32801F4.get preserve=no
  return m_cInstruction;
  //## end CI2CDigitalPotiAD5245::GetcInstruction%3FFBD32801F4.get
}

// Additional Declarations
  //## begin CI2CDigitalPotiAD5245%3F4B6249005D.declarations preserve=yes
  //## end CI2CDigitalPotiAD5245%3F4B6249005D.declarations

//## begin module%3F4B4E7A036B.epilog preserve=yes
//## end module%3F4B4E7A036B.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CI2CDPAD5245::~CI2CDPAD5245%.body preserve=no
  CO_TRACE1(I2CDP_ID,_T("I2C Device %d DP AD5245 deleted"),m_uiID);
//## end CI2CDPAD5245::~CI2CDPAD5245%.body

#endif
