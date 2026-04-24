//## begin module%3EE7379A036B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE7379A036B.cm

//## begin module%3EE7379A036B.cp preserve=no
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
//## end module%3EE7379A036B.cp

//## Module: EBI2CEPROMintf%3EE7379A036B; Package body
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE7379A036B.additionalIncludes preserve=no
//## end module%3EE7379A036B.additionalIncludes

//## begin module%3EE7379A036B.includes preserve=yes
//## end module%3EE7379A036B.includes

// EBCOsync
#include "EBCOsync.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPItype
#include "EBPItype.h"
// EBHIthrd
#include "EBHIthrd.h"
// EBHIintf
#include "EBHIintf.h"
// EBI2CEPROMcomd
#include "EBI2CEPROMcomd.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBI2CEPROMexcp
#include "EBI2CEPROMexcp.h"
// EBI2CEPROMintf
#include "EBI2CEPROMintf.h"
// EBI2CEPROMident
#include "EBI2CEPROMident.h"
// EBI2CSTDLIBcomd
#include "EBI2CSTDLIBcomd.h"
// EBI2CSTDLIBconv
#include "EBI2CSTDLIBconv.h"


//## begin module%3EE7379A036B.declarations preserve=no
//## end module%3EE7379A036B.declarations

//## begin module%3EE7379A036B.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}
//## end module%3EE7379A036B.additionalDeclarations


// Class CI2CEprom24LC515 





//## begin CI2CEprom24LC515::cnPageSize%3EFC302C031C.attr preserve=no  public: static int {U} 64
int CI2CEprom24LC515::m_cnPageSize = 64;
//## end CI2CEprom24LC515::cnPageSize%3EFC302C031C.attr











CI2CEprom24LC515::CI2CEprom24LC515 (UINT p_uiID)
  //## begin CI2CEprom24LC515::CI2CEprom24LC515%1054707801.hasinit preserve=no
      : m_cMaskE2PROM24LC515(0x1), m_cdwAddressBoundary(0x8000), m_cWriteControlByte(0xA0), m_cReadControlByte(0xA1), m_cBlockSelectBit(0x08), m_cuiEEPROMSizeInByte(65536), m_uiID(p_uiID), m_hFile(NULL), m_pEpromSimulation(NULL), m_bHWPresent(false)
  //## end CI2CEprom24LC515::CI2CEprom24LC515%1054707801.hasinit
  //## begin CI2CEprom24LC515::CI2CEprom24LC515%1054707801.initialization preserve=yes
  , IPII2CEprom24LC515(I2CEPROM_ID)
  //## end CI2CEprom24LC515::CI2CEprom24LC515%1054707801.initialization
{
  //## begin CI2CEprom24LC515::CI2CEprom24LC515%1054707801.body preserve=yes
  
  m_bHWPresent = CPIComponentsState::GetInstance()->GetComponentState(I2CEPROM_ID);
  if (!m_bHWPresent)
  {
    m_pEpromSimulation = new CI2CEpromSimulation(m_uiID);
  }

  // get log .object ID from map table
  CMap<DWORD, DWORD&, DWORD, DWORD&> &l_IdMap = IHIInterface::GetInstance()->GetIdMap(); 
  DWORD l_dwID = (DWORD)m_uiID;
  UINT l_uiID = l_IdMap[l_dwID];

  m_cI2CDeviceAdr = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr());
  m_cI2CBusNumber = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CBusNumber()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CBusNumber());
  m_cI2CTransferSpeed = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CTransferSpeed()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CTransferSpeed());
  m_cI2CDevice = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskControlStates()) >> CHIProcessImageParameter::GetcdwShiftCountsControlStates());

  CO_TRACE1(I2CEPROM_ID,_T("I2C Device %d EPROM 24LC515 created"),m_uiID);
  CO_TRACE1(I2CEPROM_ID,_T("EPROM 24LC515 - I2C Device Addresse: %#4x"), (DWORD)m_cI2CDeviceAdr);
  CO_TRACE1(I2CEPROM_ID,_T("EPROM 24LC515 - I2C Bus Number: %d"), (DWORD)m_cI2CBusNumber);
  CO_TRACE1(I2CEPROM_ID,_T("EPROM 24LC515 - I2C Transfer Speed: %d"), (DWORD)m_cI2CTransferSpeed);
  //## end CI2CEprom24LC515::CI2CEprom24LC515%1054707801.body
}


CI2CEprom24LC515::~CI2CEprom24LC515()
{
  //## begin CI2CEprom24LC515::~CI2CEprom24LC515%.body preserve=yes
  if (m_pEpromSimulation)
    delete m_pEpromSimulation;
  m_pEpromSimulation = NULL;

  CO_TRACE1(I2CEPROM_ID,_T("I2C Device %d EPROM 24LC515 deleted"),m_uiID);
  //## end CI2CEprom24LC515::~CI2CEprom24LC515%.body
}



//## Other Operations (implementation)
CCOSyncObject* CI2CEprom24LC515::Startup ()
{
  //## begin CI2CEprom24LC515::Startup%1054707810.body preserve=yes
  DWORD l_dwError = 0;

#ifdef _WIN32_WCE
#endif

  DUMMY_RETURN;
  //## end CI2CEprom24LC515::Startup%1054707810.body
}

CCOSyncObject* CI2CEprom24LC515::Shutdown ()
{
  //## begin CI2CEprom24LC515::Shutdown%1054707811.body preserve=yes
#ifdef _WIN32_WCE
#endif

  DUMMY_RETURN;
  //## end CI2CEprom24LC515::Shutdown%1054707811.body
}

UINT CI2CEprom24LC515::GetuiID ()
{
  //## begin CI2CEprom24LC515::GetuiID%1054794435.body preserve=yes
  return m_uiID;
  //## end CI2CEprom24LC515::GetuiID%1054794435.body
}

CCOSyncObjectInt* CI2CEprom24LC515::ByteRead (WORD p_uiAddress)
{
  //## begin CI2CEprom24LC515::ByteRead%1054707802.body preserve=yes
  CCOSyncObjectInt *l_pSyncObjInt = new CCOSyncObjectInt(_T("EPROM:ByteRead"), 0);
  CI2CEprom24LC515Command *l_pCmd = NULL;
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;

  PDWORD l_pdwI2CStream = NULL;

  char l_cControlByteWrite = m_cWriteControlByte;
  char l_cControlByteRead = m_cReadControlByte;
  char l_cE2promLowAdr = 0;
  char l_cE2promHighAdr = 0;
  BYTE l_cRetVal = 0;

  char l_cControlWrite[20], l_cControlRead[20], l_cLowAdr[20], l_cHighAdr[20], l_cData[20], l_cI2CStream[1000], l_cValue[20];
  strcpy(l_cControlWrite,""); strcpy(l_cControlRead,""); strcpy(l_cLowAdr,""); strcpy(l_cHighAdr,""); strcpy(l_cData,""); strcpy(l_cI2CStream,""); strcpy(l_cValue,"");
  
  DWORD l_dwErrorCode = 0;
  DWORD l_dwBytesWritten = 0;
  try
  {
    // eprom simulation
    if (!m_bHWPresent)
    {
      BYTE l_cValue = 0;
    
      m_pEpromSimulation->ByteRead(p_uiAddress, &l_cValue);
    
      l_pSyncObjInt->SetValue(l_cValue);
      l_pSyncObjInt->SignalCompletion();
      return l_pSyncObjInt;
    }

    // check device identification (last 12 bit)
    if (m_cI2CDevice && m_cMaskE2PROM24LC515)
    {    
      // set control byte write
      l_cControlByteWrite|= (m_cI2CDeviceAdr << 0x1);
      if (p_uiAddress >= m_cdwAddressBoundary)
      {
        l_cControlByteWrite|= m_cBlockSelectBit;
      }
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlByteWrite, l_cControlWrite);
      
      // set control byte read
      l_cControlByteRead|= (m_cI2CDeviceAdr << 0x1);
      if (p_uiAddress >= m_cdwAddressBoundary)
      {
        l_cControlByteRead|= m_cBlockSelectBit;
      }
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlByteRead, l_cControlRead);

      // low byte address
      l_cE2promLowAdr = (BYTE)(p_uiAddress & 0xFF);
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promLowAdr, l_cLowAdr);
      
      // high byte address
      l_cE2promHighAdr = (BYTE)((p_uiAddress  & 0xFF00) >> 0x8);
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promHighAdr, l_cHighAdr);

      // data byte
      CI2CSTDLIBConvert::ByteToI2CCharStream(0xFF, l_cData);

      // I2C stream string
      // START + CTRL WRITE + ACK + HIGH ADR + ACK + LOW ADR + ACK + START + CTRL READ + DATA + STOP
      sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cControlWrite, CI2CSTDLIBCmd::m_cI2CAck,
                           l_cHighAdr,CI2CSTDLIBCmd::m_cI2CAck,l_cLowAdr,CI2CSTDLIBCmd::m_cI2CAck,
                           CI2CSTDLIBCmd::m_cI2CStart,l_cControlRead,CI2CSTDLIBCmd::m_cI2CAck, 
                           l_cData,CI2CSTDLIBCmd::m_cI2CAck,CI2CSTDLIBCmd::m_cI2CStop);

      //CO_TRACE(I2CEPROM_ID, _T("Send:"));
      //CO_TRACE(I2CEPROM_ID, l_cI2CStream);
      //CO_TRACE(I2CEPROM_ID, _T("\r\n"));


      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);
      
      /////////////////////////////
      // add command to the I2C worker thread queue
      l_pCmd = new CI2CEprom24LC515Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
      l_pdwI2CData = NULL;

      l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
      l_pI2CSyncObj->Synchronize();
      l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
      l_pCmd->ReleaseRef();
      l_pCmd = NULL;

      // get answer data stream
      l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
      l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);

      // convert byte stream data to I2C String
      strcpy(l_cI2CStream,"");
      CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

      // byte read
      //CO_TRACE(I2CEPROM_ID, _T("Receive:"));
      //CO_TRACE(I2CEPROM_ID, l_cI2CStream);
      //CO_TRACE(I2CEPROM_ID, _T("\r\n"));

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pdwI2CStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;

      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
           !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 54) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 74))
      {
        // command failed
        throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_READ_BYTE_ACK_ERROR, __FILE__, __LINE__, 0);
      }
      
      char l_cValue[100];
      strcpy(l_cValue, "");
      strncat(l_cValue, &l_cI2CStream[76],16);

      if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cValue, l_cRetVal))
      {
        // no data found
       throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_READ_BYTE_ERROR, __FILE__, __LINE__, 0);
      }
    }
    else
    {
      throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_HW_INTF_ERROR, __FILE__, __LINE__, 0);
    }
  }
  catch(XCOExceptionError* l_pException)
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
        l_pException->Delete();
        l_pSyncObjInt->AttachException(new XCOExceptionCellUndocked(I2CEPROM_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
    }
    else
    {
        l_pSyncObjInt->AttachException(l_pException);
    }    
  }
  
  l_pSyncObjInt->SetValue((int)l_cRetVal);
  l_pSyncObjInt->SignalCompletion();
  return l_pSyncObjInt;
  //## end CI2CEprom24LC515::ByteRead%1054707802.body
}

CPISyncObjI2CDataStream* CI2CEprom24LC515::BlockRead (WORD p_uiAddress, UINT p_uiSize)
{
  //## begin CI2CEprom24LC515::BlockRead%1054707803.body preserve=yes
  CI2CEprom24LC515Command *l_pCmd = NULL;
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  CPII2CDataStream* l_pEpromData = NULL;
  CPISyncObjI2CDataStream* l_pSyncObj = new CPISyncObjI2CDataStream(_T("EPROM:BlockRead"), NULL);
  BYTE *l_pRetVal = new BYTE[p_uiSize];

  PDWORD l_pdwI2CStream = NULL;

  BYTE l_cControlByteWrite = m_cWriteControlByte;
  BYTE l_cControlByteRead = m_cReadControlByte;
  BYTE l_cE2promLowAdr = 0;
  BYTE l_cE2promHighAdr = 0;
  BYTE l_cRetVal = 0;

  WORD l_uiActReadAdr = p_uiAddress;
  int l_nActDataSize = p_uiSize;
  int l_nDataSizeToRead = 0;
  int l_nDataCounter = 0;
  
  //int l_nLength = 0;
  char l_cControlWrite[64], l_cControlRead[64], l_cLowAdr[64], l_cHighAdr[64], l_cData[64], l_cI2CStream[5000], l_cValue[64];
  strcpy(l_cData,""); strcpy(l_cI2CStream,""); strcpy(l_cValue,"");
  
  DWORD l_dwErrorCode = 0;
  DWORD l_dwBytesWritten = 0;

  try
  {
    // eprom simulation
    if (!m_bHWPresent)
    {
      m_pEpromSimulation->BlockRead(p_uiAddress, l_pRetVal, p_uiSize);

      l_pEpromData = new CPII2CDataStream(l_pRetVal, p_uiSize);
      l_pSyncObj->SetValue(l_pEpromData);
      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
    }

    // check device identification (last 12 bit)
    if (m_cI2CDevice && m_cMaskE2PROM24LC515)
    {    
      do
      {
        UINT l_uiByteCounter = 0;
        l_nDataSizeToRead = 0;

        // low byte address
        l_cE2promLowAdr = (BYTE)(l_uiActReadAdr & 0xFF);
        strcpy(l_cLowAdr,""); 
        CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promLowAdr, l_cLowAdr);
        
        // high byte address
        l_cE2promHighAdr = (BYTE)((l_uiActReadAdr  & 0xFF00) >> 0x8);
        strcpy(l_cHighAdr,"");
        CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promHighAdr, l_cHighAdr);
  
        if ((l_nActDataSize - m_cnPageSize) > 0)
        {
          l_nDataSizeToRead = m_cnPageSize;
        }
        else
        {
          l_nDataSizeToRead = l_nActDataSize;
        }
      
        if (l_uiActReadAdr < m_cdwAddressBoundary)
        {
          if (((DWORD)(l_uiActReadAdr + l_nDataSizeToRead)) <= m_cdwAddressBoundary)
          {
            // set control byte write - B0 (Byte) = 0
            l_cControlByteWrite|= (m_cI2CDeviceAdr << 0x1);
      
            // set control byte read - B0 (Byte) = 0
            l_cControlByteRead|= (m_cI2CDeviceAdr << 0x1);
          }
          else // (l_uiActReadAdr + l_nDataSizeToRead) > m_cdwAddressBoundary
          {
            // need to wrap (EEPROM access)
            // set control byte write - B0 (Byte) = 0
            l_cControlByteWrite|= (m_cI2CDeviceAdr << 0x1);
        
            // set control byte read - B0 (Byte) = 0
            l_cControlByteRead|= (m_cI2CDeviceAdr << 0x1);
        
            // actual available data size
            l_nDataSizeToRead = m_cdwAddressBoundary - l_uiActReadAdr;
          }
        }
        else // l_uiActReadAdr > m_cdwAddressBoundary
        {
          // set control byte wite - B0 (Byte) = 1
          l_cControlByteWrite|= (m_cI2CDeviceAdr << 0x1);
          l_cControlByteWrite|= m_cBlockSelectBit; // this bit acts as the A15 address bit
            
          // set control byte read - B0 (Byte) = 1
          l_cControlByteRead|= (m_cI2CDeviceAdr << 0x1);
          l_cControlByteRead|= m_cBlockSelectBit; // this bit acts as the A15 address bit
        }
        
        strcpy(l_cControlWrite,""); strcpy(l_cControlRead,"");
        CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlByteWrite, l_cControlWrite);
        CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlByteRead, l_cControlRead);

        // I2C stream string
        // START + CTRL WRITE + ACK + HIGH ADR + ACK + LOW ADR + ACK + START + CTRL READ + ACK
        strcpy(l_cI2CStream,"");
        sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s%s",
                              CI2CSTDLIBCmd::m_cI2CStart,l_cControlWrite, CI2CSTDLIBCmd::m_cI2CAck,
                              l_cHighAdr,CI2CSTDLIBCmd::m_cI2CAck,l_cLowAdr,CI2CSTDLIBCmd::m_cI2CAck,
                              CI2CSTDLIBCmd::m_cI2CStart,l_cControlRead);

        // add number of DATA to I2C stream
        bool l_bFirst = true;
        do
        {
          if (l_bFirst)
          {
            strcat(l_cI2CStream,CI2CSTDLIBCmd::m_cI2CAck);
            l_bFirst = false;
          }
          else
          {
            strcat(l_cI2CStream,CI2CSTDLIBCmd::m_cI2CNack);
          }
          strcat(l_cI2CStream,"1111111111111111");
          l_uiByteCounter++;
        }
        while(l_uiByteCounter < (UINT)l_nDataSizeToRead);
        
        // add STOP condition
        strcat(l_cI2CStream,CI2CSTDLIBCmd::m_cI2CAck);
        strcat(l_cI2CStream,CI2CSTDLIBCmd::m_cI2CStop);

        int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
        PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
        ASSERT (l_pdwI2CData != NULL);
        CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

        //CString strTmp;
        //strTmp.Format(_T("BlockRead from Adr:%d Size:%d\r\n"),l_uiActReadAdr,l_nDataSizeToRead);
        //CO_TRACE(I2CEPROM_ID, strTmp);

        /////////////////////////////
        // add command to the I2C worker thread queue
        l_pCmd = new CI2CEprom24LC515Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
        ASSERT(l_pCmd != NULL);
        l_pdwI2CData = NULL;

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
        l_pdwI2CStream = NULL;
        l_pI2CSyncObj->ReleaseRef();
        l_pI2CSyncObj = NULL;

        //CO_TRACE(I2CEPROM_ID, _T("Read Recieve\r\n"));

        // check ACK       
        if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
              !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 54))
        {
          // command failed
          CCOSystemMonitorInterface::GetpMonitor()->FlushQueue();
          throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_READ_BYTE_ACK_ERROR, __FILE__, __LINE__, 0);
        }

        // check DATA ACK
        for (int ii = 0; ii < l_nDataSizeToRead; ii++)
        {
          if (!CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, (74 + (18 * ii))))
          {
            // command failed
            CCOSystemMonitorInterface::GetpMonitor()->FlushQueue();
            throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_READ_BYTE_ACK_ERROR, __FILE__, __LINE__, 0);
          }
        }
        
        // get DATA
        for (int jj = 0; jj < l_nDataSizeToRead; jj++)
        {
          char l_cValue[100];
          strcpy(l_cValue, "");
          strncat(l_cValue, &l_cI2CStream[76 + (18 * jj)],16);
          if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cValue, l_cRetVal))
          {
            // no data found
            CCOSystemMonitorInterface::GetpMonitor()->FlushQueue();
			throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_READ_BYTE_ERROR, __FILE__, __LINE__, 0);
          }
          else
          {
            if ((UINT)(jj + l_nDataCounter) < p_uiSize)
            {
              l_pRetVal[jj + l_nDataCounter] = l_cRetVal; // add I2C data
            }
            else
            {
              CCOSystemMonitorInterface::GetpMonitor()->FlushQueue();
              throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_DATA_BUFFER_ERROR, __FILE__, __LINE__, 0);
            }
          }

        }
        // set remaining data size
        l_nActDataSize = l_nActDataSize - l_nDataSizeToRead;
        // set new read address
        l_uiActReadAdr+= l_nDataSizeToRead;
        l_nDataCounter+= l_nDataSizeToRead;
      }
      while(l_nActDataSize > 0);

      // set data
      l_pEpromData = new CPII2CDataStream(l_pRetVal, p_uiSize);
      ASSERT(l_pEpromData != NULL);  //TEST.PB

      l_pSyncObj->SetValue(l_pEpromData);
      l_pSyncObj->SignalCompletion();
    }
    else
    {
		throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_HW_INTF_ERROR, __FILE__, __LINE__, 0);
    }
  }
  catch(XCOExceptionError* l_pException)
  {
    
    ////////////////////////////////
    // START TEST.PB
    CCOSystemMonitorInterface::GetpMonitor()->FlushQueue();
    //CFile l_File;
    //CString l_strData, l_strTmp;
    //char buffer[5000];
    //int l_nLength = strlen(l_cI2CStream);
    //l_File.Open(_T("\\ReadPage.TXT"), CFile::modeCreate | CFile::modeReadWrite);

    //int qq = sprintf(buffer,"%s",l_cI2CStream);

    //l_nLength = qq;//l_strData.GetLength();
    //l_File.Write(buffer, l_nLength);
    //l_File.Close();
    // END TEST.PB
    ////////////////////////////////
    if (l_pCmd)
      l_pCmd->ReleaseRef();
    l_pCmd = NULL;

    if (l_pI2CSyncObj)
      l_pI2CSyncObj->ReleaseRef();
    l_pI2CSyncObj = NULL;

    if (l_pI2CAnswerDataStream)
      l_pI2CAnswerDataStream->ReleaseRef();
    l_pI2CAnswerDataStream = NULL;

    if (l_pRetVal)
      delete [] l_pRetVal;
    l_pRetVal = NULL;

        // 
    if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
    {
        l_pException->Delete();
        l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CEPROM_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
    }
    else
    {
        l_pSyncObj->AttachException(l_pException);
    }    

  }
  //CO_TRACE(I2CEPROM_ID, _T("end CI2CEprom24LC515::BlockRead\r\n"));

  return l_pSyncObj;
  //## end CI2CEprom24LC515::BlockRead%1054707803.body
}

CPISyncObjI2CDataStream* CI2CEprom24LC515::ReadContent ()
{
  //## begin CI2CEprom24LC515::ReadContent%1054707804.body preserve=yes
  CPISyncObjI2CDataStream *l_pSyncObj = NULL;
  l_pSyncObj = BlockRead(0x0, m_cuiEEPROMSizeInByte);
  return l_pSyncObj;
  //## end CI2CEprom24LC515::ReadContent%1054707804.body
}

CCOSyncObject* CI2CEprom24LC515::ByteWrite (WORD p_uiAddress, BYTE p_cValue)
{
  //## begin CI2CEprom24LC515::ByteWrite%1054707805.body preserve=yes
  CCOSyncObject *l_pSyncObj = new CCOSyncObject(_T("EPROM:ByteWrite"));
  CI2CEprom24LC515Command *l_pCmd = NULL;
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;

  PDWORD l_pdwI2CStream = NULL;

  BYTE l_cControlByteWrite = m_cWriteControlByte;
  BYTE l_cE2promLowAdr = 0;
  BYTE l_cE2promHighAdr = 0;

  char l_cControlWrite[20], l_cLowAdr[20], l_cHighAdr[20], l_cData[20], l_cI2CStream[1000], l_cValue[20];
  strcpy(l_cControlWrite,""); strcpy(l_cLowAdr,""); strcpy(l_cHighAdr,""); strcpy(l_cData,""); strcpy(l_cI2CStream,""); strcpy(l_cValue,"");

  DWORD l_dwErrorCode = 0;
  DWORD l_dwBytesWritten = 0;
  try
  {
    // eprom simulation
    if (!m_bHWPresent)
    {
        m_pEpromSimulation->ByteWrite(p_uiAddress, p_cValue);
        l_pSyncObj->SignalCompletion();
        return l_pSyncObj;
    }
    
	//CString sWriteAdr = _T("");
	//sWriteAdr.Format(_T("WriteAdr: %d, Value: %d \r\n"), p_uiAddress, p_cValue);
    //CO_TRACE(I2CEPROM_ID, sWriteAdr);

	// check device identification (last 12 bit)
    if (m_cI2CDevice && m_cMaskE2PROM24LC515)
    {    
      // set control byte write
      l_cControlByteWrite|= (m_cI2CDeviceAdr << 0x1);
      if (p_uiAddress >= m_cdwAddressBoundary)
      {
        l_cControlByteWrite|= m_cBlockSelectBit;
      }
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlByteWrite, l_cControlWrite);
      
      // low byte address
      l_cE2promLowAdr = (BYTE)(p_uiAddress & 0xFF);
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promLowAdr, l_cLowAdr);

      // high byte address
      l_cE2promHighAdr = (BYTE)((p_uiAddress  & 0xFF00) >> 0x8);
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promHighAdr, l_cHighAdr);

      // data byte
      CI2CSTDLIBConvert::ByteToI2CCharStream(p_cValue, l_cData);

      // I2C stream string
      // START + CTRL WRITE + ACK + HIGH ADR + ACK + LOW ADR + ACK + DATA + ACK + STOP
      sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cControlWrite, CI2CSTDLIBCmd::m_cI2CAck,
                           l_cHighAdr,CI2CSTDLIBCmd::m_cI2CAck,l_cLowAdr,CI2CSTDLIBCmd::m_cI2CAck,
                           l_cData,CI2CSTDLIBCmd::m_cI2CAck,CI2CSTDLIBCmd::m_cI2CStop);

      //CO_TRACE(I2CEPROM_ID, _T("Send Stream"));
      //CO_TRACE(I2CEPROM_ID, l_cI2CStream);
      //CO_TRACE(I2CEPROM_ID, _T("\r\n"));

      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

      /////////////////////////////
      // add command to the I2C worker thread queue
      l_pCmd = new CI2CEprom24LC515Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);

      l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
      l_pI2CSyncObj->Synchronize();
      l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
      l_pCmd->ReleaseRef();
      l_pCmd = NULL;

      // get answer data stream
      l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
      l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);

      // convert byte stream data to I2C String
      strcpy(l_cI2CStream,"");
      CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

      // byte write
      //CO_TRACE(I2CEPROM_ID, _T("Receive Stream"));
      //CO_TRACE(I2CEPROM_ID, l_cI2CStream);
      //CO_TRACE(I2CEPROM_ID, _T("\r\n"));

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pdwI2CStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;

      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
            !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 54))
      {
        // command failed
        throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_READ_BYTE_ACK_ERROR, __FILE__, __LINE__, 0);
      }

	  // check if E2prom is ready for Writing
	  AcknowledgePolling(l_cControlByteWrite);

    }
    else
    {
      throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_HW_INTF_ERROR, __FILE__, __LINE__, 0);
    }
  }
  catch(XCOExceptionError* l_pException)
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

    // 
    if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
    {
        l_pException->Delete();
        l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CEPROM_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
    }
    else
    {
        l_pSyncObj->AttachException(l_pException);
    }    

  }
  l_pSyncObj->SignalCompletion();
  return l_pSyncObj;
  //## end CI2CEprom24LC515::ByteWrite%1054707805.body
}

CCOSyncObject* CI2CEprom24LC515::PageWrite (WORD p_uiAddress, BYTE* p_pcValue, UINT p_uiSize)
{
  //## begin CI2CEprom24LC515::PageWrite%1054707806.body preserve=yes
  // test write address -> page boundary
  div_t l_DivResult;
  l_DivResult = div(p_uiAddress, m_cnPageSize);
  ASSERT(!l_DivResult.rem);

  CI2CEprom24LC515Command *l_pCmd = NULL;
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  CCOSyncObject *l_pSyncObj = new CCOSyncObject(_T("EPROM:PageWrite"));
  
  PDWORD l_pdwI2CStream = NULL;

  BYTE l_cControlByteWrite = m_cWriteControlByte;
  BYTE l_cE2promLowAdr = 0;
  BYTE l_cE2promHighAdr = 0;

  char l_cControlWrite[20], l_cLowAdr[20], l_cHighAdr[20], l_cData[20], l_cI2CStream[5000], l_cValue[1000];
  strcpy(l_cControlWrite,""); strcpy(l_cLowAdr,""); strcpy(l_cHighAdr,""); strcpy(l_cData,""); strcpy(l_cI2CStream,""); strcpy(l_cValue,"");

  DWORD l_dwErrorCode = 0;
  DWORD l_dwBytesWritten = 0;
  
  //CString strTmp;
  //strTmp.Format(_T("Start CI2CEprom24LC515::PageWrite Adr:%d Size:%d\r\n"),p_uiAddress,p_uiSize);
  //CO_TRACE(I2CEPROM_ID, strTmp)
  
  try
  {
    // eprom simulation
    if (!m_bHWPresent)
    {
      m_pEpromSimulation->PageWrite(p_uiAddress, p_pcValue, p_uiSize);

      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
    }

    // check data size vs page size
    if (p_uiSize > (UINT)m_cnPageSize)
    {
      CO_TRACE(I2CEPROM_ID, _T("PageWrite - Data Size larger than Page Size \r\n"));
	  throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_WRITE_PAGE_DATA_ERROR, __FILE__, __LINE__, 0);
    }

    // check device identification (last 12 bit)
    if (m_cI2CDevice && m_cMaskE2PROM24LC515)
    {    
      // set control byte write
      l_cControlByteWrite|= (m_cI2CDeviceAdr << 0x1);
      if (p_uiAddress >= m_cdwAddressBoundary)
      {
        l_cControlByteWrite|= m_cBlockSelectBit;
      }
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlByteWrite, l_cControlWrite);

      // low byte address
      l_cE2promLowAdr = (BYTE)(p_uiAddress & 0xFF);
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promLowAdr, l_cLowAdr);

      // high byte address
      l_cE2promHighAdr = (BYTE)((p_uiAddress  & 0xFF00) >> 0x8);
      CI2CSTDLIBConvert::ByteToI2CCharStream(l_cE2promHighAdr, l_cHighAdr);

      // I2C stream string
      // START + CTRL WRITE + ACK + HIGH ADR + ACK + LOW ADR
      sprintf(l_cI2CStream,"%s%s%s%s%s%s%s",
                           CI2CSTDLIBCmd::m_cI2CStart,l_cControlWrite, CI2CSTDLIBCmd::m_cI2CAck,
                           l_cHighAdr,CI2CSTDLIBCmd::m_cI2CAck,l_cLowAdr,CI2CSTDLIBCmd::m_cI2CAck);

      // add number of DATA (page size) to I2C stream
      for (int ii = 0; ii < m_cnPageSize; ii++)
      {
        if ((UINT)ii < p_uiSize)
        {
          // data byte
          strcpy(l_cData,"");
          CI2CSTDLIBConvert::ByteToI2CCharStream(p_pcValue[ii], l_cData);
          strcat(l_cI2CStream, l_cData);
          strcat(l_cI2CStream, CI2CSTDLIBCmd::m_cI2CNack);
        }
        else
        {
          CI2CSTDLIBConvert::ByteToI2CCharStream(0xFF, l_cData);
          strcat(l_cI2CStream, l_cData);
          strcat(l_cI2CStream, CI2CSTDLIBCmd::m_cI2CNack);
        }
      }


      // add STOP condition
      strcat(l_cI2CStream, CI2CSTDLIBCmd::m_cI2CStop);

      ////////////////////////////////
      // START TEST.PB
      //CFile l_File;
      //char buffer[5000];
      //int l_nLength = strlen(l_cI2CStream);
      //l_File.Open(_T("\\WritePage.TXT"), CFile::modeCreate | CFile::modeReadWrite);

      //int qq = sprintf(buffer,"%s",l_cI2CStream);

      //l_nLength = qq;
      //l_File.Write(buffer, l_nLength);
      //l_File.Close();
      // END TEST.PB
      ////////////////////////////////

      // convert data stream string to data byte stream
      int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
      PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
      ASSERT(l_pdwI2CData != NULL);
      CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

      /////////////////////////////
      // add command to the I2C worker thread queue
      l_pCmd = new CI2CEprom24LC515Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
      l_pdwI2CData = NULL;


      l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
      l_pI2CSyncObj->Synchronize();
      l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
      l_pCmd->ReleaseRef();
      l_pCmd = NULL;

      // convert byte stream data to I2C String
      l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
      l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);

      // convert byte stream data to I2C String
      strcpy(l_cI2CStream,"");
      CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

      //CO_TRACE(I2CEPROM_ID, _T("Write Recieve\r\n"));

      l_pI2CAnswerDataStream->ReleaseRef();
      l_pI2CAnswerDataStream = NULL;
      l_pdwI2CStream = NULL;
      l_pI2CSyncObj->ReleaseRef();
      l_pI2CSyncObj = NULL;
      
      // check ACK
      if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
            !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 54))
      {
        // command failed
        throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_READ_BYTE_ACK_ERROR, __FILE__, __LINE__, 0);
      }

      // check DATA ACK
      for (int jj = 0; jj < m_cnPageSize; jj++)
      {
        if (!CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, (72 + (18 * jj))))
        {
          // command failed
          throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_WRITE_PAGE_ACK_ERROR, __FILE__, __LINE__, 0);
        }
      }

	  // check if E2prom is ready for Writing
	  AcknowledgePolling(l_cControlByteWrite);

    }
    else
    {
      throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_HW_INTF_ERROR, __FILE__, __LINE__, 0);
    }
    l_pSyncObj->SignalCompletion();
  }
  catch(XCOExceptionError* l_pException)
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
    
    // 
    if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
    {
        l_pException->Delete();
        l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CEPROM_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
    }
    else
    {
        l_pSyncObj->AttachException(l_pException);
    }    

  }
  //CO_TRACE(I2CEPROM_ID, _T("end CI2CEprom24LC515::PageWrite\r\n"));

  return l_pSyncObj;
  //## end CI2CEprom24LC515::PageWrite%1054707806.body
}

CCOSyncObject* CI2CEprom24LC515::WriteContent (BYTE* &p_pContent, UINT p_uiDataSize)
{
  //## begin CI2CEprom24LC515::WriteContent%1054707807.body preserve=yes
  int l_NumberOfPages = 0;
  UINT l_WriteAdr = 0;
  
  // test data size
  div_t l_DivResult;
  l_DivResult = div(p_uiDataSize, m_cnPageSize);
  ASSERT(!l_DivResult.rem);
  // number of pages to write to EPROM
  l_NumberOfPages = l_DivResult.quot;

  CCOSyncObject* l_pSyncObj = NULL;
  CCOSyncObject* l_pSyncObjRet = NULL;

  try
  {
    for (int ii = 0; ii < l_NumberOfPages; ii++)
    {
      l_WriteAdr = ii * m_cnPageSize;
      l_pSyncObj = PageWrite(l_WriteAdr, &p_pContent[l_WriteAdr], m_cnPageSize);
      l_pSyncObj->Synchronize();
      Sleep(10);
      l_pSyncObj->ReleaseRef();
    }
    l_pSyncObjRet = new CCOSyncObject;
    l_pSyncObjRet->SignalCompletion();
  }
  catch(XCOExceptionError* l_pException)
  {
    l_pSyncObjRet->AttachException(l_pException);
  }
  
  return l_pSyncObjRet;

  //## end CI2CEprom24LC515::WriteContent%1054707807.body
}

CCOSyncObject* CI2CEprom24LC515::ConnectionEstablished ()
{
  //## begin CI2CEprom24LC515::ConnectionEstablished%1056459656.body preserve=yes
  DUMMY_RETURN
  //## end CI2CEprom24LC515::ConnectionEstablished%1056459656.body
}

CCOSyncObject* CI2CEprom24LC515::ConnectionLost ()
{
  //## begin CI2CEprom24LC515::ConnectionLost%1056459657.body preserve=yes
  DUMMY_RETURN
  //## end CI2CEprom24LC515::ConnectionLost%1056459657.body
}

UINT CI2CEprom24LC515::GetEprom24LC515SizeInByte ()
{
  //## begin CI2CEprom24LC515::GetEprom24LC515SizeInByte%1061369815.body preserve=yes
  return GetcuiEEPROMSizeInByte();
  //## end CI2CEprom24LC515::GetEprom24LC515SizeInByte%1061369815.body
}

UINT CI2CEprom24LC515::GetEprom24LC515PageSizeInByte ()
{
  //## begin CI2CEprom24LC515::GetEprom24LC515PageSizeInByte%1061378414.body preserve=yes
  return m_cnPageSize;
  //## end CI2CEprom24LC515::GetEprom24LC515PageSizeInByte%1061378414.body
}

bool CI2CEprom24LC515::AcknowledgePolling (BYTE p_cWriteCmd)
{
  //## begin CI2CEprom24LC515::AcknowledgePolling%1108044741.body preserve=yes
  CI2CEprom24LC515Command *l_pCmd = NULL;
  CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
  CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
  PDWORD l_pdwI2CStream = NULL;

  try
  {
	  int l_iPollingCounter = 0;

	  char l_cControlWrite[20], l_cI2CStream[1000], l_cValue[20];
	  strcpy(l_cControlWrite,""); strcpy(l_cI2CStream,""); strcpy(l_cValue,"");

	  CI2CSTDLIBConvert::ByteToI2CCharStream(p_cWriteCmd, l_cControlWrite);

	  do
	  {
		  l_iPollingCounter++;

		  // I2C stream string
		  // START + CTRL WRITE + ACK + STOP
		  sprintf(l_cI2CStream,"%s%s%s%s",
							   CI2CSTDLIBCmd::m_cI2CStart,
							   l_cControlWrite,
							   CI2CSTDLIBCmd::m_cI2CAck,
							   CI2CSTDLIBCmd::m_cI2CStop);

		   //CO_TRACE(I2CEPROM_ID, _T("Acknowledge Polling Send:"));
		   //CO_TRACE(I2CEPROM_ID, l_cI2CStream);
		   //CO_TRACE(I2CEPROM_ID, _T("\r\n"));

		   int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
		   PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
		   CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

		   /////////////////////////////
		   // add command to the I2C worker thread queue
		   l_pCmd = new CI2CEprom24LC515Command((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);

		   l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
		   l_pI2CSyncObj->Synchronize();
		   l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
		   l_pCmd->ReleaseRef();
		   l_pCmd = NULL;

		   // get answer data stream
		   l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
		   l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);

		   // convert byte stream data to I2C String
		   strcpy(l_cI2CStream,"");
		   CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

		   // byte write
		   //CO_TRACE(I2CEPROM_ID, _T("Acknowledge Polling Receive:"));
		   //CO_TRACE(I2CEPROM_ID, l_cI2CStream);
		   //CO_TRACE(I2CEPROM_ID, _T("\r\n"));

		   l_pI2CAnswerDataStream->ReleaseRef();
		   l_pI2CAnswerDataStream = NULL;
		   l_pdwI2CStream = NULL;
		   l_pI2CSyncObj->ReleaseRef();
		   l_pI2CSyncObj = NULL;

		   // check ACK
		   if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18))
		   {
			   // ACK != 0 -> retry
			   if (l_iPollingCounter >= 10)
			   {
				   throw new XI2CEpromExceptionError(I2CEPROM_ID, IDE_I2C_INTF_24LC515_ACKNOWLEDGE_ERROR, __FILE__, __LINE__, 0);
			   }
		   }
		   else
		   {
			   break;
		   }
	  }
	  while(true);

	  return true;
  }
  catch(...)
  {
	   if(l_pCmd != NULL)
		   l_pCmd->ReleaseRef();
	   if(l_pI2CSyncObj != NULL)
		   l_pI2CSyncObj->ReleaseRef();
	   if(l_pI2CAnswerDataStream != NULL)
		   l_pI2CAnswerDataStream->ReleaseRef();

	   throw;
  }
  //## end CI2CEprom24LC515::AcknowledgePolling%1108044741.body
}

//## Get and Set Operations for Class Attributes (implementation)

int CI2CEprom24LC515::GetcnPageSize ()
{
  //## begin CI2CEprom24LC515::GetcnPageSize%3EFC302C031C.get preserve=no
  return m_cnPageSize;
  //## end CI2CEprom24LC515::GetcnPageSize%3EFC302C031C.get
}

const UINT CI2CEprom24LC515::GetcuiEEPROMSizeInByte () const
{
  //## begin CI2CEprom24LC515::GetcuiEEPROMSizeInByte%3F278BB101D4.get preserve=no
  return m_cuiEEPROMSizeInByte;
  //## end CI2CEprom24LC515::GetcuiEEPROMSizeInByte%3F278BB101D4.get
}

const BYTE CI2CEprom24LC515::GetcI2CDeviceAdr () const
{
  //## begin CI2CEprom24LC515::GetcI2CDeviceAdr%3F5D708C0242.get preserve=no
  return m_cI2CDeviceAdr;
  //## end CI2CEprom24LC515::GetcI2CDeviceAdr%3F5D708C0242.get
}

const BYTE CI2CEprom24LC515::GetcI2CBusNumber () const
{
  //## begin CI2CEprom24LC515::GetcI2CBusNumber%3F5D708C0251.get preserve=no
  return m_cI2CBusNumber;
  //## end CI2CEprom24LC515::GetcI2CBusNumber%3F5D708C0251.get
}

const BYTE CI2CEprom24LC515::GetcI2CTransferSpeed () const
{
  //## begin CI2CEprom24LC515::GetcI2CTransferSpeed%3F5D708C0261.get preserve=no
  return m_cI2CTransferSpeed;
  //## end CI2CEprom24LC515::GetcI2CTransferSpeed%3F5D708C0261.get
}

const BYTE CI2CEprom24LC515::GetcI2CDevice () const
{
  //## begin CI2CEprom24LC515::GetcI2CDevice%3F5D708C0280.get preserve=no
  return m_cI2CDevice;
  //## end CI2CEprom24LC515::GetcI2CDevice%3F5D708C0280.get
}

// Additional Declarations
  //## begin CI2CEprom24LC515%3EDD9FC402FD.declarations preserve=yes
  //## end CI2CEprom24LC515%3EDD9FC402FD.declarations

// Class CI2CEpromSimulation 





CI2CEpromSimulation::CI2CEpromSimulation (const UINT p_uiID)
  //## begin CI2CEpromSimulation::CI2CEpromSimulation%1073630608.hasinit preserve=no
      : m_bSimulationFilePresent(false), m_sFileName(_T(""))
  //## end CI2CEpromSimulation::CI2CEpromSimulation%1073630608.hasinit
  //## begin CI2CEpromSimulation::CI2CEpromSimulation%1073630608.initialization preserve=yes
  //## end CI2CEpromSimulation::CI2CEpromSimulation%1073630608.initialization
{
  //## begin CI2CEpromSimulation::CI2CEpromSimulation%1073630608.body preserve=yes
#ifdef _WIN32_WCE
	CString l_sPath = _T("\\Hard Disk\\NIRFlex\\");
#else
  CString l_sPath = _T("R:\\Bin\\Data\\");
#endif

	switch(p_uiID)
	{
	case 5006:
		{
			m_sFileName = l_sPath + _T("EpromMainboard.bin");
		}
		break;

	case 5102:
		{
			m_sFileName = l_sPath + _T("EpromApplication.bin");
		}
		break;

	case 5103:
		{
			m_sFileName = l_sPath + _T("EpromDetector.bin");
		}
		break;

	default:
		{
			ASSERT(false);
		}
	}
  //## end CI2CEpromSimulation::CI2CEpromSimulation%1073630608.body
}


CI2CEpromSimulation::~CI2CEpromSimulation()
{
  //## begin CI2CEpromSimulation::~CI2CEpromSimulation%.body preserve=yes
  //## end CI2CEpromSimulation::~CI2CEpromSimulation%.body
}



//## Other Operations (implementation)
void CI2CEpromSimulation::ByteRead (WORD p_uiAddress, BYTE* p_cValue)
{
  //## begin CI2CEpromSimulation::ByteRead%1073920700.body preserve=yes
  bool l_bSimulationFilePresent = OpenFile();
 
  if (l_bSimulationFilePresent)
  {
    m_File.Seek(p_uiAddress, CFile::begin);
	  m_File.Read(p_cValue, 0x1);

    CloseFile();
  }
  else
  {
    *p_cValue = 0;
  }
  //## end CI2CEpromSimulation::ByteRead%1073920700.body
}

void CI2CEpromSimulation::BlockRead (WORD p_uiAddress, BYTE* &p_cValue, UINT p_uiSize)
{
  //## begin CI2CEpromSimulation::BlockRead%1073630609.body preserve=yes
  bool l_bSimulationFilePresent = OpenFile();

  if (l_bSimulationFilePresent)
  {
    m_File.Seek(p_uiAddress, CFile::begin);
	  m_File.Read(p_cValue, p_uiSize);
	  CloseFile();
  }
  else
  {
    ZeroMemory(p_cValue, p_uiSize);
  }
  //## end CI2CEpromSimulation::BlockRead%1073630609.body
}

void CI2CEpromSimulation::ReadContent (BYTE* &p_pContent, UINT& p_uiDataSize)
{
  //## begin CI2CEpromSimulation::ReadContent%1073630610.body preserve=yes
  //## end CI2CEpromSimulation::ReadContent%1073630610.body
}

void CI2CEpromSimulation::ByteWrite (WORD p_uiAddress, BYTE p_cValue)
{
  //## begin CI2CEpromSimulation::ByteWrite%1073630611.body preserve=yes
	bool l_bSimulationFilePresent = OpenFile();

  if (l_bSimulationFilePresent)
  {
	  m_File.Seek(p_uiAddress, CFile::begin);
	  m_File.Write(&p_cValue, 0x1);
	  CloseFile();
  }
  else
  {

  }
  //## end CI2CEpromSimulation::ByteWrite%1073630611.body
}

void CI2CEpromSimulation::PageWrite (WORD p_uiAddress, BYTE* p_pcValue, UINT p_uiSize)
{
  //## begin CI2CEpromSimulation::PageWrite%1073630612.body preserve=yes
	bool l_bSimulationFilePresent = OpenFile();

  if (l_bSimulationFilePresent)
  {
	  m_File.Seek(p_uiAddress, CFile::begin);
	  m_File.Write(p_pcValue, p_uiSize);
	  CloseFile();
  }
  else
  {

  }
  //## end CI2CEpromSimulation::PageWrite%1073630612.body
}

void CI2CEpromSimulation::WriteContent (BYTE* &p_pContent, UINT p_uiDataSize)
{
  //## begin CI2CEpromSimulation::WriteContent%1073630613.body preserve=yes
  //## end CI2CEpromSimulation::WriteContent%1073630613.body
}

bool CI2CEpromSimulation::OpenFile ()
{
  //## begin CI2CEpromSimulation::OpenFile%1073630614.body preserve=yes
	CFileException e;
	if( !m_File.Open(m_sFileName, CFile::modeReadWrite, &e ))
	{
		return false;
	}
  return true;
  //## end CI2CEpromSimulation::OpenFile%1073630614.body
}

void CI2CEpromSimulation::CloseFile ()
{
  //## begin CI2CEpromSimulation::CloseFile%1073630615.body preserve=yes
	m_File.Close();
  //## end CI2CEpromSimulation::CloseFile%1073630615.body
}

// Additional Declarations
  //## begin CI2CEpromSimulation%3FFE805A03D8.declarations preserve=yes
  //## end CI2CEpromSimulation%3FFE805A03D8.declarations

//## begin module%3EE7379A036B.epilog preserve=yes
//## end module%3EE7379A036B.epilog
