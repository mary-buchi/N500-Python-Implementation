//## begin module%3F49F7E900BB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49F7E900BB.cm

//## begin module%3F49F7E900BB.cp preserve=no
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
//## end module%3F49F7E900BB.cp

//## Module: EBI2CADCintf%3F49F7E900BB; Package body
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F49F7E900BB.additionalIncludes preserve=no
//## end module%3F49F7E900BB.additionalIncludes

//## begin module%3F49F7E900BB.includes preserve=yes
//## end module%3F49F7E900BB.includes

// EBPIcpst
#include "EBPIcpst.h"
// EBPItype
#include "EBPItype.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBHIthrd
#include "EBHIthrd.h"
// EBHIintf
#include "EBHIintf.h"
// EBI2CSTDLIBcomd
#include "EBI2CSTDLIBcomd.h"
// EBI2CSTDLIBconv
#include "EBI2CSTDLIBconv.h"
// EBI2CADCcomd
#include "EBI2CADCcomd.h"
// EBI2CADCexcp
#include "EBI2CADCexcp.h"
// EBI2CADCintf
#include "EBI2CADCintf.h"
// EBI2CADCident
#include "EBI2CADCident.h"


//## begin module%3F49F7E900BB.declarations preserve=no
//## end module%3F49F7E900BB.declarations

//## begin module%3F49F7E900BB.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}
//## end module%3F49F7E900BB.additionalDeclarations


// Class CI2CADCMAX1037 














CI2CADCMAX1037::CI2CADCMAX1037 (UINT p_uiID)
  //## begin CI2CADCMAX1037::CI2CADCMAX1037%1061804165.hasinit preserve=no
      : m_cSetup(0xDA), m_cConfiguration(0x07), m_cAdrWrite(0xC8), m_cAdrRead(0xC9), m_cMaskWriteAccess(0xFE), m_cMaskReadAccess(0x01), m_cMaskADCMAX1037(0x1), m_uiID(p_uiID), m_bHWPresent(false)
  //## end CI2CADCMAX1037::CI2CADCMAX1037%1061804165.hasinit
  //## begin CI2CADCMAX1037::CI2CADCMAX1037%1061804165.initialization preserve=yes
   , IPII2CADCMAX1037(I2CADC_ID)
  //## end CI2CADCMAX1037::CI2CADCMAX1037%1061804165.initialization
{
  //## begin CI2CADCMAX1037::CI2CADCMAX1037%1061804165.body preserve=yes
  m_bHWPresent = CPIComponentsState::GetInstance()->GetComponentState(I2CADC_ID);

  // get log .object ID from map table
  CMap<DWORD, DWORD&, DWORD, DWORD&> &l_IdMap = IHIInterface::GetInstance()->GetIdMap(); 
  DWORD l_dwID = (DWORD)m_uiID;
  UINT l_uiID = l_IdMap[l_dwID];

  m_cI2CDeviceAdr = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr());
  m_cI2CBusNumber = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CBusNumber()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CBusNumber());
  m_cI2CTransferSpeed = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CTransferSpeed()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CTransferSpeed());
  m_cI2CDevice = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskControlStates()) >> CHIProcessImageParameter::GetcdwShiftCountsControlStates());

  CO_TRACE1(I2CADC_ID,_T("I2C Device %d ADC MAX1037 created"), m_uiID);
  CO_TRACE1(I2CADC_ID,_T("ADC MAX1037 - I2C Device Addresse: %#4x"), (DWORD)m_cI2CDeviceAdr);
  CO_TRACE1(I2CADC_ID,_T("ADC MAX1037 - I2C Bus Number: %d"), (DWORD)m_cI2CBusNumber);
  CO_TRACE1(I2CADC_ID,_T("ADC MAX1037 - I2C Transfer Speed: %d"), (DWORD)m_cI2CTransferSpeed);

  //## end CI2CADCMAX1037::CI2CADCMAX1037%1061804165.body
}


CI2CADCMAX1037::~CI2CADCMAX1037()
{
  //## begin CI2CADCMAX1037::~CI2CADCMAX1037%.body preserve=yes
  CO_TRACE1(I2CADC_ID,_T("I2C Device %d ADC MAX1037 deleted"), m_uiID);
  //## end CI2CADCMAX1037::~CI2CADCMAX1037%.body
}



//## Other Operations (implementation)
UINT CI2CADCMAX1037::GetuiID ()
{
  //## begin CI2CADCMAX1037::GetuiID%1061804158.body preserve=yes
  return m_uiID;
  //## end CI2CADCMAX1037::GetuiID%1061804158.body
}

CCOSyncObject* CI2CADCMAX1037::Startup ()
{
  //## begin CI2CADCMAX1037::Startup%1061804159.body preserve=yes
  DUMMY_RETURN;
  //## end CI2CADCMAX1037::Startup%1061804159.body
}

CCOSyncObject* CI2CADCMAX1037::Shutdown ()
{
  //## begin CI2CADCMAX1037::Shutdown%1061804160.body preserve=yes
  DUMMY_RETURN;
  //## end CI2CADCMAX1037::Shutdown%1061804160.body
}

CCOSyncObject* CI2CADCMAX1037::ConnectionEstablished ()
{
  //## begin CI2CADCMAX1037::ConnectionEstablished%1061804161.body preserve=yes
  DUMMY_RETURN;
  //## end CI2CADCMAX1037::ConnectionEstablished%1061804161.body
}

CCOSyncObject* CI2CADCMAX1037::ConnectionLost ()
{
  //## begin CI2CADCMAX1037::ConnectionLost%1061804162.body preserve=yes
  DUMMY_RETURN;
  //## end CI2CADCMAX1037::ConnectionLost%1061804162.body
}

CPISyncObjDataADCMAX1037* CI2CADCMAX1037::GetData ()
{
  //## begin CI2CADCMAX1037::GetData%1061804163.body preserve=yes
  BYTE l_cAIN[4] = {11,22,33,44};
  
  CPISyncObjDataADCMAX1037* l_pSyncObj = new CPISyncObjDataADCMAX1037(NULL);
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  CI2CADCMAX1037Command *l_pCmd = NULL;

  PDWORD l_pdwI2CStream = NULL;

  if (!m_bHWPresent)
  {
    CPIDataADCMAX1037 * l_pData = new CPIDataADCMAX1037(l_cAIN[0],l_cAIN[1],l_cAIN[2],l_cAIN[3]);
    l_pSyncObj->SetValue(l_pData);    
    l_pSyncObj->SignalCompletion();
    return l_pSyncObj;
  }

  BYTE *l_pcI2CStream = NULL;

  char l_cAdrByte = (m_cI2CDeviceAdr << 0x1);

  char l_cAdr[20], l_cData1[20], l_cData2[20], l_cData3[20], l_cData4[20], l_cI2CStream[1000];
  strcpy(l_cAdr,""); strcpy(l_cData1,""); strcpy(l_cData2,""); strcpy(l_cData3,""); strcpy(l_cData4,""); strcpy(l_cI2CStream,"");

  try
  {
    if (m_cI2CDevice && m_cMaskADCMAX1037)
    {
      // I2C digital ponti DP AD5245
      // set control address byte
      l_cAdrByte|= m_cMaskReadAccess;
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cAdrByte, l_cAdr);

      // data bytes
      CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cData1);
      CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cData2);
      CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cData3);
      CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cData4);
      
      // I2C stream string
      // START + Adr + ACK + Data0 + Data1 + Data2 + Data3 + NACK + STOP
      sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cAdr, CI2CSTDLIBCmd::m_cI2CAck,
                           l_cData1, CI2CSTDLIBCmd::m_cI2CNack,
                           l_cData2, CI2CSTDLIBCmd::m_cI2CNack, 
                           l_cData3, CI2CSTDLIBCmd::m_cI2CNack, 
                           l_cData4, CI2CSTDLIBCmd::m_cI2CAck,
                           CI2CSTDLIBCmd::m_cI2CStop);

      // Get Data
      CO_TRACE(I2CADC_ID, _T("Send:"));
      CO_TRACE(I2CADC_ID, l_cI2CStream);
      CO_TRACE(I2CADC_ID, _T("/"));

      // convert data stream string to data byte stream // byte data stream 
      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

      // add command (WriteMode) to the I2C worker thread queue
      l_pCmd = new CI2CADCMAX1037Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
  
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

      // Get Data
      CO_TRACE(I2CADC_ID, _T("Receive:"));
      CO_TRACE(I2CADC_ID, l_cI2CStream);
      CO_TRACE(I2CADC_ID, _T("/"));

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;

      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
           !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 54) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 72) ||
           !CI2CSTDLIBConvert::CheckACK(l_cI2CStream, 90))
      {
        // command failed
        throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_SETUP_ACK_ERROR, __FILE__, __LINE__, 0);
      }
      // get data 1
      strcpy(l_cData1, "");
      l_cAIN[0] = 0;
      strncat(l_cData1, &l_cI2CStream[20],16);
      if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cData1, l_cAIN[0]))
      {
        // no data found
        throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_DATA_ERROR, __FILE__, __LINE__, 0);
      }
      // get data 2
      strcpy(l_cData2, "");
      l_cAIN[1] = 0;
      strncat(l_cData2, &l_cI2CStream[38],16);
      if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cData2, l_cAIN[1]))
      {
        // no data found
        throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_DATA_ERROR, __FILE__, __LINE__, 0);
      }
      // get data 3
      strcpy(l_cData3, "");
      l_cAIN[2] = 0;
      strncat(l_cData3, &l_cI2CStream[56],16);
      if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cData3, l_cAIN[2]))
      {
        // no data found
        throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_DATA_ERROR, __FILE__, __LINE__, 0);
      }
      // get data 4
      strcpy(l_cData4, "");
      l_cAIN[3] = 0;
      strncat(l_cData4, &l_cI2CStream[74],16);
      if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cData4, l_cAIN[3]))
      {
        // no data found
        throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_DATA_ERROR, __FILE__, __LINE__, 0);
      }

      CPIDataADCMAX1037 * l_pData = new CPIDataADCMAX1037(l_cAIN[0],l_cAIN[1],l_cAIN[2],l_cAIN[3]);
      l_pSyncObj->SetValue(l_pData);
      l_pSyncObj->SignalCompletion();
    }
    else
    {
      throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_WRONG_ID, __FILE__, __LINE__, 0);
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
        l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CADC_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
    }
    else
    {
        l_pSyncObj->AttachException(p_pException);
    }    
  }
  return l_pSyncObj;
  //## end CI2CADCMAX1037::GetData%1061804163.body
}

CCOSyncObject* CI2CADCMAX1037::Initialize ()
{
  //## begin CI2CADCMAX1037::Initialize%1061804164.body preserve=yes
    CCOSyncObject* l_ReturnSyncObject = new CCOSyncObject();

    try
    {
        CCOSyncObjectPtr l_pSyncObjectSetup = Setup();
        l_pSyncObjectSetup->Synchronize();

        CCOSyncObjectPtr l_pSyncObjectConfig = Configure();
        l_pSyncObjectConfig->Synchronize();
    }
    catch(XCOExceptionError* p_pException)
    {
        if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
        {
            p_pException->Delete();
            l_ReturnSyncObject->AttachException(new XCOExceptionCellUndocked(I2CADC_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
        }
        else
        {
            l_ReturnSyncObject->AttachException(p_pException);
        }    
    }
    l_ReturnSyncObject->SignalCompletion();
    return l_ReturnSyncObject;

  //## end CI2CADCMAX1037::Initialize%1061804164.body
}

CCOSyncObject* CI2CADCMAX1037::Setup ()
{
  //## begin CI2CADCMAX1037::Setup%1073545769.body preserve=yes
  CCOSyncObject *l_pSyncObj = new CCOSyncObject();
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  CI2CADCMAX1037Command *l_pCmd = NULL;

  if (!m_bHWPresent)
  {
      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
  }

  PDWORD l_pdwI2CStream = NULL;

  char l_cAdrByte = (m_cI2CDeviceAdr << 0x1);

  char l_cAdr[20], l_cSetup[20], l_cI2CStream[1000];
  strcpy(l_cAdr,""); strcpy(l_cSetup,""); strcpy(l_cI2CStream,"");

  try
  {
    if (m_cI2CDevice && m_cMaskADCMAX1037)
    {
      // I2C digital ponti DP AD5245
      // set control address byte
      l_cAdrByte&= m_cMaskWriteAccess;
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cAdrByte, l_cAdr);

      // setup byte
      CI2CSTDLIBConvert::ByteToI2CCharStream(m_cSetup, l_cSetup);
      
      // I2C stream string
      // START + Adr + ACK + Setup + ACK + STOP
      sprintf(l_cI2CStream,"%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cAdr, CI2CSTDLIBCmd::m_cI2CAck,
                           l_cSetup,CI2CSTDLIBCmd::m_cI2CAck, CI2CSTDLIBCmd::m_cI2CStop);

      // Setup
      CO_TRACE(I2CADC_ID, _T("Send:"));
      CO_TRACE(I2CADC_ID, l_cI2CStream);
      CO_TRACE(I2CADC_ID, _T("/"));

      // convert data stream string to data byte stream // byte data stream 
      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

      // add command (WriteMode) to the I2C worker thread queue
      l_pCmd = new CI2CADCMAX1037Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
  
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

      // Setup
      CO_TRACE(I2CADC_ID, _T("Receive:"));
      CO_TRACE(I2CADC_ID, l_cI2CStream);
      CO_TRACE(I2CADC_ID, _T("/"));

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;

      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36))
      {
        // command failed
        throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_SETUP_ACK_ERROR, __FILE__, __LINE__, 0);
      }

      l_pSyncObj->SignalCompletion();
    }
    else
    {
      throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_WRONG_ID, __FILE__, __LINE__, 0);
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
    
    l_pSyncObj->AttachException(p_pException);
  }
  return l_pSyncObj;
  //## end CI2CADCMAX1037::Setup%1073545769.body
}

CCOSyncObject* CI2CADCMAX1037::Configure ()
{
  //## begin CI2CADCMAX1037::Configure%1073545770.body preserve=yes
  CCOSyncObject *l_pSyncObj = new CCOSyncObject();
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  CI2CADCMAX1037Command *l_pCmd = NULL;

  if (!m_bHWPresent)
  {
      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
  }

  PDWORD l_pdwI2CStream = NULL;

  char l_cAdrByte = (m_cI2CDeviceAdr << 0x1);

  char l_cAdr[20], l_cConfiguration[20], l_cI2CStream[1000];
  strcpy(l_cAdr,""); strcpy(l_cConfiguration,""); strcpy(l_cI2CStream,"");

  try
  {
    if (m_cI2CDevice && m_cMaskADCMAX1037)
    {
      // I2C digital ponti DP AD5245
      // set control address byte
      l_cAdrByte&= m_cMaskWriteAccess;
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cAdrByte, l_cAdr);

      // setup byte
      CI2CSTDLIBConvert::ByteToI2CCharStream(m_cConfiguration, l_cConfiguration);
      
      // I2C stream string
      // START + Adr + ACK + Config + ACK + STOP
      sprintf(l_cI2CStream,"%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cAdr, CI2CSTDLIBCmd::m_cI2CAck,
                           l_cConfiguration,CI2CSTDLIBCmd::m_cI2CAck, CI2CSTDLIBCmd::m_cI2CStop);

      // Configure
      CO_TRACE(I2CADC_ID, _T("Send:"));
      CO_TRACE(I2CADC_ID, l_cI2CStream);
      CO_TRACE(I2CADC_ID, _T("/"));

      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

      // add command (WriteMode) to the I2C worker thread queue
      l_pCmd = new CI2CADCMAX1037Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
  
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

      // Configure
      CO_TRACE(I2CADC_ID, _T("Receive:"));
      CO_TRACE(I2CADC_ID, l_cI2CStream);
      CO_TRACE(I2CADC_ID, _T("/"));

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;

      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36))
      {
        // command failed
        throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_SETUP_ACK_ERROR, __FILE__, __LINE__, 0);
      }

      l_pSyncObj->SignalCompletion();
    }
    else
    {
      throw new XI2CADCExceptionError(I2CADC_ID, IDE_I2C_INTF_MAX1037_WRONG_ID, __FILE__, __LINE__, 0);
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
    
    l_pSyncObj->AttachException(p_pException);
  }
  return l_pSyncObj;
  //## end CI2CADCMAX1037::Configure%1073545770.body
}

//## Get and Set Operations for Class Attributes (implementation)

const BYTE CI2CADCMAX1037::GetcI2CDeviceAdr () const
{
  //## begin CI2CADCMAX1037::GetcI2CDeviceAdr%3F5D79E90167.get preserve=no
  return m_cI2CDeviceAdr;
  //## end CI2CADCMAX1037::GetcI2CDeviceAdr%3F5D79E90167.get
}

const BYTE CI2CADCMAX1037::GetcI2CBusNumber () const
{
  //## begin CI2CADCMAX1037::GetcI2CBusNumber%3F5D79E90186.get preserve=no
  return m_cI2CBusNumber;
  //## end CI2CADCMAX1037::GetcI2CBusNumber%3F5D79E90186.get
}

const BYTE CI2CADCMAX1037::GetcI2CTransferSpeed () const
{
  //## begin CI2CADCMAX1037::GetcI2CTransferSpeed%3F5D79E90196.get preserve=no
  return m_cI2CTransferSpeed;
  //## end CI2CADCMAX1037::GetcI2CTransferSpeed%3F5D79E90196.get
}

const BYTE CI2CADCMAX1037::GetcI2CDevice () const
{
  //## begin CI2CADCMAX1037::GetcI2CDevice%3F5D79E901A5.get preserve=no
  return m_cI2CDevice;
  //## end CI2CADCMAX1037::GetcI2CDevice%3F5D79E901A5.get
}

// Additional Declarations
  //## begin CI2CADCMAX1037%3F4A122E0232.declarations preserve=yes
  //## end CI2CADCMAX1037%3F4A122E0232.declarations

//## begin module%3F49F7E900BB.epilog preserve=yes
//## end module%3F49F7E900BB.epilog
