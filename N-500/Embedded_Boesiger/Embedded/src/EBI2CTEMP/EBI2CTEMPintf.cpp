//## begin module%3EE7373A03C8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE7373A03C8.cm

//## begin module%3EE7373A03C8.cp preserve=no
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
//## end module%3EE7373A03C8.cp

//## Module: EBI2CTEMPintf%3EE7373A03C8; Package body
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE7373A03C8.additionalIncludes preserve=no
//## end module%3EE7373A03C8.additionalIncludes

//## begin module%3EE7373A03C8.includes preserve=yes
//## end module%3EE7373A03C8.includes

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
// EBI2CTEMPcomd
#include "EBI2CTEMPcomd.h"
// EBI2CTEMPexcp
#include "EBI2CTEMPexcp.h"
// EBI2CTEMPintf
#include "EBI2CTEMPintf.h"
// EBI2CTEMPident
#include "EBI2CTEMPident.h"
// EBI2CSTDLIBcomd
#include "EBI2CSTDLIBcomd.h"
// EBI2CSTDLIBconv
#include "EBI2CSTDLIBconv.h"


//## begin module%3EE7373A03C8.declarations preserve=no
//## end module%3EE7373A03C8.declarations

//## begin module%3EE7373A03C8.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
	l_pSyncObj->SignalCompletion();                     \
	return l_pSyncObj;                                  \
}


//////////////////////////////////////////////////////////////////////////////
// I2C Log ID Device Identifikation Number
//
// logical number layout:
//
//  MSB                                                                                          LSB
//  31                   24 23                   16 15                   8  7                    0
//  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
//  |        |  |                                            |  |              
//  |        |  |                                            |  |              
//  |        |  |                                            |  |              
//  |        |  |                                            |  - - - - - - - - - - I2C Device Identification; Values: 0 .. 4095
//  |        |  |                                            |
//  |        |  - - - - - - - - - - - - - - - - - - - - - - - - - - Address Offset I2C Device (DWORD); Value: 0x0 .. 0xFFFF FFFF
//  |        |
//  - - - - - - - - - - - - - - - - - - - - Data Control Bits; Values 0x0..0xF // Bit 28 = 1  =>  I2C Device

//## end module%3EE7373A03C8.additionalDeclarations


// Class CI2CTempSensorDS1631Z 
























CI2CTempSensorDS1631Z::CI2CTempSensorDS1631Z (UINT p_uiID)
//## begin CI2CTempSensorDS1631Z::CI2CTempSensorDS1631Z%1054707797.hasinit preserve=no
: m_cStartConvertT(0x51), m_cStopConvertT(0x22), m_cReadTemperature(0xAA), m_cAccessTH(0xA1), m_cAccessTL(0xA2), m_cAccessConfig(0xAC), m_cSoftwarePOR(0x54), m_cWriteControlByte(0x90), m_cReadControlByte(0x91), m_cMaskTempSensorDS1631Z(0x1), m_cdwMaskAddressOffset(0x00007000), m_cbMaskTempResolution(0xC), m_cdwAddressRightShifter(0xC), m_cnTempUnit(1000), m_hFile(NULL), m_uiID(p_uiID), m_eTempResolution(eHigh), m_eConversionMode(eModeOneShot), m_bHWPresent(false)
//## end CI2CTempSensorDS1631Z::CI2CTempSensorDS1631Z%1054707797.hasinit
//## begin CI2CTempSensorDS1631Z::CI2CTempSensorDS1631Z%1054707797.initialization preserve=yes
, IPII2CTempSensorDS1631Z(I2CTEMP_ID)
//## end CI2CTempSensorDS1631Z::CI2CTempSensorDS1631Z%1054707797.initialization
{
	//## begin CI2CTempSensorDS1631Z::CI2CTempSensorDS1631Z%1054707797.body preserve=yes

	m_bHWPresent = CPIComponentsState::GetInstance()->GetComponentState(I2CTEMP_ID);

	// get log .object ID from map table
	CMap<DWORD, DWORD&, DWORD, DWORD&> &l_IdMap = IHIInterface::GetInstance()->GetIdMap(); 
	DWORD l_dwID = (DWORD)m_uiID;
	UINT l_uiID = l_IdMap[l_dwID];

	// determin process image offset address
	m_cI2CDeviceAdr = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskOffsetAdr()) >> CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr());
	m_cI2CBusNumber = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CBusNumber()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CBusNumber());
	m_cI2CTransferSpeed = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskI2CTransferSpeed()) >> CHIProcessImageParameter::GetcdwShiftCountsI2CTransferSpeed());
	m_cI2CDevice = (BYTE)((l_uiID & CHIProcessImageParameter::GetcdwMaskControlStates()) >> CHIProcessImageParameter::GetcdwShiftCountsControlStates());

	CO_TRACE1(I2CTEMP_ID,_T("I2C Device %d TempSensor DS1631Z created"), m_uiID);
	CO_TRACE1(I2CTEMP_ID,_T("TempSensor DS1631Z - I2C Device Addresse: %#4x"), (DWORD)m_cI2CDeviceAdr);
	CO_TRACE1(I2CTEMP_ID,_T("TempSensor DS1631Z - I2C Bus Number: %d"), (DWORD)m_cI2CBusNumber);
	CO_TRACE1(I2CTEMP_ID,_T("TempSensor DS1631Z - I2C Transfer Speed: %d"), (DWORD)m_cI2CTransferSpeed);

	//## end CI2CTempSensorDS1631Z::CI2CTempSensorDS1631Z%1054707797.body
}


CI2CTempSensorDS1631Z::~CI2CTempSensorDS1631Z()
{
	//## begin CI2CTempSensorDS1631Z::~CI2CTempSensorDS1631Z%.body preserve=yes
	CO_TRACE1(I2CTEMP_ID,_T("I2C Device %d TempSensor DS1631Z deleted"), m_uiID);
	//## end CI2CTempSensorDS1631Z::~CI2CTempSensorDS1631Z%.body
}



//## Other Operations (implementation)
CCOSyncObject* CI2CTempSensorDS1631Z::Startup ()
{
	//## begin CI2CTempSensorDS1631Z::Startup%1054707808.body preserve=yes
	DWORD l_dwError = 0;

#ifdef _WIN32_WCE
#endif

	DUMMY_RETURN;
	//## end CI2CTempSensorDS1631Z::Startup%1054707808.body
}

CCOSyncObject* CI2CTempSensorDS1631Z::Shutdown ()
{
	//## begin CI2CTempSensorDS1631Z::Shutdown%1054707809.body preserve=yes
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
	l_pSyncObj->SignalCompletion();
	return l_pSyncObj;
	//## end CI2CTempSensorDS1631Z::Shutdown%1054707809.body
}

UINT CI2CTempSensorDS1631Z::GetuiID ()
{
	//## begin CI2CTempSensorDS1631Z::GetuiID%1054794434.body preserve=yes
	return m_uiID;
	//## end CI2CTempSensorDS1631Z::GetuiID%1054794434.body
}

CCOSyncObject* CI2CTempSensorDS1631Z::SetSensorConfig (CPIConfigDS1631Z* p_pConfig)
{
	//## begin CI2CTempSensorDS1631Z::SetSensorConfig%1054707798.body preserve=yes
	CCOSyncObject *l_pSyncObj = new CCOSyncObject(_T("DS1631Z:SetSensorConfig"));
	CCOSyncObjectPtr l_pSyncObjStartTempConv = NULL;
	CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
	CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
	CI2CTempSensor1631ZCommand *l_pCmd = NULL;

	if (!m_bHWPresent)
	{
		l_pSyncObj->SignalCompletion();
		return l_pSyncObj;
	}

	PDWORD l_pdwI2CStream = NULL;

	char l_cControlByte = m_cWriteControlByte;
	char l_cConfig = 0;

	char l_cControl[20], l_cCommand[20], l_cConfigData[20], l_cI2CStream[1000], l_cRetValue[1000];
	strcpy(l_cControl,""); strcpy(l_cCommand,""); strcpy(l_cConfigData,""); strcpy(l_cI2CStream,""); strcpy(l_cRetValue,"");

	DWORD l_dwErrorCode = 0;
	DWORD l_dwBytesWritten = 0;

	m_eTempResolution = p_pConfig->GeteResolution();
	switch (m_eTempResolution)
	{
	case eResLow:
		l_cConfig |= 0x0;
		break;

	case eAboveLow:
		l_cConfig |= 0x4;
		break;

	case eNormal:
		l_cConfig |= 0x8;
		break;

	case eHigh:
		l_cConfig |= 0xC;
		break;

	default:
		ASSERT(FALSE);
	}

	m_eConversionMode = p_pConfig->GeteMode();
	if (m_eConversionMode == eModeOneShot)
	{
		throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_MODEONESHOT_NOT_SUPPORTED, __FILE__, __LINE__, 0);
		//l_cConfig |= 0x1;
	}

	// check device identification (last 12 bit)
	try
	{
		if (m_cI2CDevice && m_cMaskTempSensorDS1631Z)
		{
			// I2C temp sensor DS1631Z 
			// set control byte
			l_cControlByte|= (m_cI2CDeviceAdr << 0x1);
			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlByte, l_cControl);

			// command byte
			CI2CSTDLIBConvert::ByteToI2CCharStream(m_cAccessConfig, l_cCommand);

			// data byte
			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cConfig, l_cConfigData);

			// I2C stream string
			sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s",
				CI2CSTDLIBCmd::m_cI2CStart,l_cControl, CI2CSTDLIBCmd::m_cI2CAck,
				l_cCommand,CI2CSTDLIBCmd::m_cI2CAck,l_cConfigData,CI2CSTDLIBCmd::m_cI2CAck,
				CI2CSTDLIBCmd::m_cI2CStop);

			// set config
			CO_TRACE(I2CTEMP_ID, _T("Send - SetConfig():"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			//int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 8);
			//BYTE* l_pcI2CData = new BYTE[l_nStreamLen];
			// convert data stream string to data byte stream // byte data stream 
			//CI2CSTDLIBConvert::CharStreamToByteStream(l_cI2CStream, l_pcI2CData, l_nStreamLen);

			// convert data stream string to data byte stream
			int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
			PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
			CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

			// add command (SetSensorConfig) to the I2C worker thread queue
			l_pCmd = new CI2CTempSensor1631ZCommand((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);
			//l_pcI2CData = NULL;

			l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
			l_pI2CSyncObj->Synchronize();
			l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
			l_pCmd->ReleaseRef();
			l_pCmd = NULL;

			// get answer data stream
			//l_pcI2CStream = l_pI2CAnswerDataStream->GetpcI2CDataStream();
			//l_nStreamLen = l_pI2CAnswerDataStream->GetnSize();
			// convert byte stream data to I2C char stream
			//strcpy(l_cRetValue,"");
			//CI2CSTDLIBConvert::ByteStreamToCharStream(l_pcI2CStream, l_nStreamLen, l_cRetValue);

			// convert byte stream data to I2C String
			l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
			l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);
			strcpy(l_cRetValue,"");
			CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cRetValue);

			// set config
			CO_TRACE(I2CTEMP_ID, _T("Recieve - SetConfig()::"));
			CO_TRACE(I2CTEMP_ID, l_cRetValue);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			l_pI2CAnswerDataStream->ReleaseRef();
			l_pI2CAnswerDataStream = NULL;
			l_pI2CSyncObj->ReleaseRef();
			l_pI2CSyncObj = NULL;

			// check ACK
			if ( !CI2CSTDLIBConvert::CheckNACK(l_cRetValue, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cRetValue, 36) ||
				!CI2CSTDLIBConvert::CheckNACK(l_cRetValue, 54))
			{
				// command failed
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_SET_CONFIG_ACK_ERROR, __FILE__, __LINE__, 0);
			}

			if (m_eConversionMode == eModeContinuous)
			{
				l_pSyncObjStartTempConv = StartTemperatureConvertion();
				l_pSyncObjStartTempConv->Synchronize();
			}

			l_pSyncObj->SignalCompletion();
		}
		else
		{
			throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_WRONG_ID, __FILE__, __LINE__, 0);
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

		//  was the cell undocked?
		if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
		{
			l_pException->Delete();
			l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CTEMP_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
		}
		else
		{
			l_pSyncObj->AttachException(l_pException);
		}    
	}
	return l_pSyncObj;
	//## end CI2CTempSensorDS1631Z::SetSensorConfig%1054707798.body
}

CCOSyncObjectInt* CI2CTempSensorDS1631Z::GetSensorConfig ()
{
	//## begin CI2CTempSensorDS1631Z::GetSensorConfig%1054707799.body preserve=yes
	CCOSyncObjectInt *l_pSyncObjInt = new CCOSyncObjectInt(_T("DS1631Z:GetSensorConfig"), 0);
	CI2CTempSensor1631ZCommand *l_pCmd = NULL;
	CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
	CPII2CDataStream* l_pI2CAnswerDataStream = NULL;
	ASSERT(l_pSyncObjInt != NULL);

	if (!m_bHWPresent)
	{
		l_pSyncObjInt->SignalCompletion();
		return l_pSyncObjInt;
	}

	PDWORD l_pdwI2CStream = NULL;

	char l_cControlReadByte = m_cReadControlByte;
	char l_cControlWriteByte = m_cWriteControlByte;
	BYTE l_cRetVal = 0;

	char l_cReadControl[20], l_cCommand[20], l_cWriteControl[20], l_cData[20], l_cI2CStream[1000], l_cRetValue[1000];
	strcpy(l_cReadControl,""); strcpy(l_cCommand,""); strcpy(l_cWriteControl,""); strcpy(l_cData,""), strcpy(l_cI2CStream,""), strcpy(l_cRetValue,"");

	DWORD l_dwErrorCode = 0;
	DWORD l_dwBytesRead = 0;

	try
	{
		if (m_cI2CDevice && m_cMaskTempSensorDS1631Z)
		{
			// Temp Sensor DS1631Z
			// set read control byte
			l_cControlReadByte|= (m_cI2CDeviceAdr << 0x1);
			// set write control byte
			l_cControlWriteByte|= (m_cI2CDeviceAdr << 0x1);

			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlReadByte, l_cReadControl);
			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlWriteByte, l_cWriteControl);

			// command byte
			CI2CSTDLIBConvert::ByteToI2CCharStream(m_cAccessConfig, l_cCommand);

			// data byte
			CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cData);

			sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s%s%s%s",
				CI2CSTDLIBCmd::m_cI2CStart,l_cWriteControl, CI2CSTDLIBCmd::m_cI2CAck,
				l_cCommand,CI2CSTDLIBCmd::m_cI2CAck,CI2CSTDLIBCmd::m_cI2CStart,
				l_cReadControl,CI2CSTDLIBCmd::m_cI2CAck,l_cData,
				CI2CSTDLIBCmd::m_cI2CAck,CI2CSTDLIBCmd::m_cI2CStop);

			// get Sensor Config
			CO_TRACE(I2CTEMP_ID, _T("Send - GetSensorConfig():"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			//int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 8);
			//BYTE* l_pcI2CData = new BYTE[l_nStreamLen];
			// convert data stream string to data byte stream // byte data stream 
			//CI2CSTDLIBConvert::CharStreamToByteStream(l_cI2CStream, l_pcI2CData, l_nStreamLen);

			// convert data stream string to data byte stream
			int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
			PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
			CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

			// add command to the I2C worker thread queue
			l_pCmd = new CI2CTempSensor1631ZCommand((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);

			l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
			l_pI2CSyncObj->Synchronize();
			l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
			l_pCmd->ReleaseRef();
			l_pCmd = NULL;

			// get answer data stream
			//l_pcI2CStream = l_pI2CAnswerDataStream->GetpcI2CDataStream();
			//l_nStreamLen = l_pI2CAnswerDataStream->GetnSize();
			// convert byte stream data to I2C char stream
			//strcpy(l_cI2CStream,"");
			//CI2CSTDLIBConvert::ByteStreamToCharStream(l_pcI2CStream, l_nStreamLen, l_cI2CStream);

			// convert byte stream data to I2C String
			l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
			l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);
			strcpy(l_cI2CStream,"");
			CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

			// get sensor config
			CO_TRACE(I2CTEMP_ID, _T("Recieve - GetSensorConfig():"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			l_pI2CAnswerDataStream->ReleaseRef();
			l_pI2CAnswerDataStream = NULL;
			l_pI2CSyncObj->ReleaseRef();
			l_pI2CSyncObj = NULL;

			// check ACK
			if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
				!CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 56))
			{
				// command failed
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_GET_CONFIG_ACK_ERROR, __FILE__, __LINE__, 0);
			}

			char l_cValue[100];
			strcpy(l_cValue, "");
			l_cRetVal = 0;
			strncat(l_cValue, &l_cI2CStream[58],16);
			if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cValue, l_cRetVal))
			{
				// no data found
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_GET_CONFIG_ERROR, __FILE__, __LINE__, 0);
			}

			l_pSyncObjInt->SetValue(l_cRetVal);
			l_pSyncObjInt->SignalCompletion();
		}
		else
		{
			throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_WRONG_ID, __FILE__, __LINE__, 0);
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

		// was the cell undocked?
		if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
		{
			l_pException->Delete();
			l_pSyncObjInt->AttachException(new XCOExceptionCellUndocked(I2CTEMP_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
		}
		else
		{
			l_pSyncObjInt->AttachException(l_pException);
		}    

	}
	return l_pSyncObjInt;
	//## end CI2CTempSensorDS1631Z::GetSensorConfig%1054707799.body
}

CCOSyncObjectInt* CI2CTempSensorDS1631Z::GetTemperature ()
{
	//## begin CI2CTempSensorDS1631Z::GetTemperature%1054707800.body preserve=yes
	CCOSyncObjectInt *l_pSyncObjInt = new CCOSyncObjectInt(_T("DS1631Z:GetTemperature"), 0);
	ASSERT(l_pSyncObjInt != NULL);
	CCOSyncObjectPtr l_pSyncObjStartTempConv = NULL;
	CI2CTempSensor1631ZCommand *l_pCmd = NULL;
	CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
	CPII2CDataStream* l_pI2CAnswerDataStream = NULL;

	if (!m_bHWPresent)
	{
		l_pSyncObjInt->SignalCompletion();
		return l_pSyncObjInt;
	}

	char l_cControlReadByte = m_cReadControlByte;
	char l_cControlWriteByte = m_cWriteControlByte;
	BYTE l_cMSBData = 0;
	BYTE l_cLSBData = 0;

	PDWORD l_pdwI2CStream = NULL;

	int l_nTemperature = 0;
	int l_nLength = 0;
	bool l_bRetVal = false;

	char l_cReadControl[20], l_cWriteControl[20], l_cCommand[20], l_cMSB[20], l_cLSB[20], l_cI2CStream[1000];
	strcpy(l_cReadControl,""); strcpy(l_cWriteControl,""); strcpy(l_cCommand,""); strcpy(l_cMSB,""); strcpy(l_cLSB,""); strcpy(l_cI2CStream,"");

	DWORD l_dwErrorCode = 0;
	DWORD l_dwBytesRead = 0;

	try
	{
		if (m_cI2CDevice && m_cMaskTempSensorDS1631Z)
		{
			//////////////////////////////////////////////////////
			// start temperature convertion
			if (m_eConversionMode == eModeOneShot)
			{
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_MODEONESHOT_NOT_SUPPORTED, __FILE__, __LINE__, 0);
			}

			// Temp Sensor DS1631Z
			// set read control byte
			l_cControlReadByte|= (m_cI2CDeviceAdr << 0x1);
			// set write control byte
			l_cControlWriteByte|= (m_cI2CDeviceAdr << 0x1);

			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlReadByte, l_cReadControl);
			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlWriteByte, l_cWriteControl);

			/////////////////////////////////////////////////////
			// read temperature
			// command byte
			CI2CSTDLIBConvert::ByteToI2CCharStream(m_cReadTemperature, l_cCommand);

			// data byte
			CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cLSB);
			CI2CSTDLIBConvert::ByteToI2CCharStream((char)0xFF, l_cMSB);

			sprintf(l_cI2CStream,"%s%s%s%s%s%s%s%s%s%s%s%s",
				CI2CSTDLIBCmd::m_cI2CStart,l_cWriteControl, CI2CSTDLIBCmd::m_cI2CAck,
				l_cCommand,CI2CSTDLIBCmd::m_cI2CAck,CI2CSTDLIBCmd::m_cI2CStart, 
				l_cReadControl,CI2CSTDLIBCmd::m_cI2CAck,l_cMSB,CI2CSTDLIBCmd::m_cI2CNack,
				l_cLSB,CI2CSTDLIBCmd::m_cI2CStop);

			// get temperature
			CO_TRACE(I2CTEMP_ID, _T("Send - GetTemperature():"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			//int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 8);
			//BYTE* l_pcI2CData = new BYTE[l_nStreamLen];
			// convert data stream string to data byte stream // byte data stream 
			//CI2CSTDLIBConvert::CharStreamToByteStream(l_cI2CStream, l_pcI2CData, l_nStreamLen);
			// convert data stream string to data byte stream
			int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
			PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
			CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

			// add command to the I2C worker thread queue
			l_pCmd = new CI2CTempSensor1631ZCommand((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);

			l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
			l_pI2CSyncObj->Synchronize();
			l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
			l_pCmd->ReleaseRef();
			l_pCmd = NULL;

			// get answer data stream
			//l_pcI2CStream = l_pI2CAnswerDataStream->GetpcI2CDataStream();
			//l_nStreamLen = l_pI2CAnswerDataStream->GetnSize();
			// convert byte stream data to I2C char stream
			//strcpy(l_cI2CStream,"");
			//CI2CSTDLIBConvert::ByteStreamToCharStream(l_pI2CAnswerDataStream->GetpcI2CDataStream(), l_pI2CAnswerDataStream->GetnSize(), l_cI2CStream);
			// convert byte stream data to I2C String
			l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
			l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);
			strcpy(l_cI2CStream,"");
			CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

			// get temperature
			CO_TRACE(I2CTEMP_ID, _T("Recieve - GetTemperature()::"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			l_pI2CAnswerDataStream->ReleaseRef();
			l_pI2CAnswerDataStream = NULL;
			l_pI2CSyncObj->ReleaseRef();
			l_pI2CSyncObj = NULL;

			// check ACK
			if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36) ||
				!CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 56) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 74))
			{
				// command failed
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_GET_TEMP_ACK_ERROR, __FILE__, __LINE__, 0);
			}

			// get data (upper byte)
			strcpy(l_cMSB, "");
			l_cMSBData = 0;
			strncat(l_cMSB, &l_cI2CStream[58],16);
			if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cMSB, l_cMSBData))
			{
				// no data found
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_GET_CONFIG_ERROR, __FILE__, __LINE__, 0);
			}

			// get data (lower byte)
			strcpy(l_cLSB, "");
			l_cLSBData = 0;
			strncat(l_cLSB, &l_cI2CStream[76],16);
			if (!CI2CSTDLIBConvert::I2CCharStreamToByte(l_cLSB, l_cLSBData))
			{
				// no data found
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_GET_CONFIG_ERROR, __FILE__, __LINE__, 0);
			}

			// convert temperature
			bool l_bTempIsNeg = false;
			if (l_cMSBData & 0x80)
			{
				// check sign byte -> temperature negative
				l_cMSBData = ~l_cMSBData;
				l_nTemperature = (-(int)l_cMSBData) * m_cnTempUnit;
				l_bTempIsNeg = true;
			}
			else
			{
				// temperature positive
				l_nTemperature = (int)l_cMSBData * m_cnTempUnit;
			}

			int l_nNumberOfDigits = 0; // decimal places
			switch (m_eTempResolution)
			{
			case eResLow:
				// bit 7
				l_nNumberOfDigits = 1;
				break;

			case eAboveLow:
				// bit 7,6 -> two digits
				l_nNumberOfDigits = 2;
				break;

			case eNormal:
				// bit 7,6,5 -> three digits
				l_nNumberOfDigits = 3;
				break;

			case eHigh:
				// bit 7,6,5,4 -> four digits
				l_nNumberOfDigits = 4;
				break;

			default:
				ASSERT(false);
			}

			double l_LSBTemp = 0;
			for (int ii = 0; ii < l_nNumberOfDigits; ii++)
			{
				if (l_cLSBData & (0x80 >> ii))
					l_LSBTemp+= pow((double)2,(double)-(ii + 1)); 
			}

			l_bTempIsNeg ? l_nTemperature+=(int)((l_LSBTemp - 1) * m_cnTempUnit) : l_nTemperature+=(int)(l_LSBTemp * m_cnTempUnit);

		}
		else
		{
			throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_WRONG_ID, __FILE__, __LINE__, 0);
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
			l_pSyncObjInt->AttachException(new XCOExceptionCellUndocked(I2CTEMP_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
		}
		else
		{
			l_pSyncObjInt->AttachException(l_pException);
		}
	}

	l_pSyncObjInt->SetValue(l_nTemperature);
	l_pSyncObjInt->SignalCompletion();
	return l_pSyncObjInt;
	//## end CI2CTempSensorDS1631Z::GetTemperature%1054707800.body
}

CCOSyncObject* CI2CTempSensorDS1631Z::ConnectionEstablished ()
{
	//## begin CI2CTempSensorDS1631Z::ConnectionEstablished%1056459658.body preserve=yes
	DUMMY_RETURN
		//## end CI2CTempSensorDS1631Z::ConnectionEstablished%1056459658.body
}

CCOSyncObject* CI2CTempSensorDS1631Z::ConnectionLost ()
{
	//## begin CI2CTempSensorDS1631Z::ConnectionLost%1056459659.body preserve=yes
	DUMMY_RETURN
		//## end CI2CTempSensorDS1631Z::ConnectionLost%1056459659.body
}

CCOSyncObject* CI2CTempSensorDS1631Z::StartTemperatureConvertion ()
{
	//## begin CI2CTempSensorDS1631Z::StartTemperatureConvertion%1056519544.body preserve=yes
	CCOSyncObject *l_pSyncObj = new CCOSyncObject(_T("DS1631Z:StartTemperatureConvertion"));
	ASSERT(l_pSyncObj != NULL);
	CI2CTempSensor1631ZCommand *l_pCmd = NULL;
	CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
	CPII2CDataStream* l_pI2CAnswerDataStream = NULL;

	PDWORD l_pdwI2CStream = NULL;

	char l_cControlWriteByte = m_cWriteControlByte;

	char l_cWriteControl[20], l_cCommand[20], l_cI2CStream[1000];
	strcpy(l_cWriteControl,""); strcpy(l_cCommand,""); strcpy(l_cI2CStream,"");

	DWORD l_dwErrorCode = 0;
	DWORD l_dwBytesRead = 0;

	try
	{
		if (m_cI2CDevice && m_cMaskTempSensorDS1631Z)
		{
			// Temp Sensor DS1631Z
			// set write control byte
			l_cControlWriteByte|= (m_cI2CDeviceAdr << 0x1);

			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlWriteByte, l_cWriteControl);
			//////////////////////////////////////////////////////
			// start temperature convertion
			// command byte
			CI2CSTDLIBConvert::ByteToI2CCharStream(m_cStartConvertT, l_cCommand);

			// I2C stream string
			sprintf(l_cI2CStream,"%s%s%s%s%s%s",
				CI2CSTDLIBCmd::m_cI2CStart,l_cWriteControl, CI2CSTDLIBCmd::m_cI2CAck,
				l_cCommand,CI2CSTDLIBCmd::m_cI2CAck, CI2CSTDLIBCmd::m_cI2CStop);

			// Start Temperature Convertion
			CO_TRACE(I2CTEMP_ID, _T("Send - StartTempConvertion():"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			//int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 8);
			//BYTE* l_pcI2CData = new BYTE[l_nStreamLen];
			// convert data stream string to data byte stream // byte data stream 
			//CI2CSTDLIBConvert::CharStreamToByteStream(l_cI2CStream, l_pcI2CData, l_nStreamLen);

			// convert data stream string to data byte stream
			int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
			PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
			CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

			// add command to the I2C worker thread queue
			l_pCmd = new CI2CTempSensor1631ZCommand((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);

			l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
			l_pI2CSyncObj->Synchronize();
			l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
			l_pCmd->ReleaseRef();
			l_pCmd = NULL;

			// get answer data stream
			//l_nStreamLen = l_pI2CAnswerDataStream->GetnSize();
			// convert byte stream data to I2C char stream
			//strcpy(l_cI2CStream,"");
			//CI2CSTDLIBConvert::ByteStreamToCharStream(l_pI2CAnswerDataStream->GetpcI2CDataStream(), l_nStreamLen, l_cI2CStream);

			// convert byte stream data to I2C String
			l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
			l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);
			strcpy(l_cI2CStream,"");
			CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

			// start temperature convertion
			CO_TRACE(I2CTEMP_ID, _T("Recieve - StartTempConvertion()::"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			l_pI2CAnswerDataStream->ReleaseRef();
			l_pI2CAnswerDataStream = NULL;
			l_pI2CSyncObj->ReleaseRef();
			l_pI2CSyncObj = NULL;

			// check ACK
			if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36))
			{
				// command failed
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_START_TEMP_ACK_ERROR, __FILE__, __LINE__, 0);
			}
		}
		else
		{
			throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_WRONG_ID, __FILE__, __LINE__, 0);
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

		// was the cell undocked?
		if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
		{
			l_pException->Delete();
			l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CTEMP_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
		}
		else
		{
			l_pSyncObj->AttachException(l_pException);
		}
	}

	return l_pSyncObj;
	//## end CI2CTempSensorDS1631Z::StartTemperatureConvertion%1056519544.body
}



CCOSyncObject* CI2CTempSensorDS1631Z::StopTemperatureConvertion () // OBSOLETE!
{
	//## begin CI2CTempSensorDS1631Z::StopTemperatureConvertion%1056519545.body preserve=yes
	CCOSyncObject *l_pSyncObj = new CCOSyncObject(_T("DS1631Z:StopTemperatureConvertion"));
	ASSERT(l_pSyncObj != NULL);
	CI2CTempSensor1631ZCommand *l_pCmd = NULL;
	CPISyncObjI2CDataStream* l_pI2CSyncObj = NULL;
	CPII2CDataStream* l_pI2CAnswerDataStream = NULL;

	PDWORD l_pdwI2CStream = NULL;

	BYTE l_cControlWriteByte = m_cWriteControlByte;

	CString l_strWriteControl, l_strCommand, l_strI2CStream;
	char l_cWriteControl[20], l_cCommand[20], l_cI2CStream[1000];
	strcpy(l_cWriteControl,""); strcpy(l_cCommand,""); strcpy(l_cI2CStream,"");

	DWORD l_dwErrorCode = 0;
	DWORD l_dwBytesRead = 0;

	try
	{
		if (m_cI2CDevice && m_cMaskTempSensorDS1631Z)
		{
			// Temp Sensor DS1631Z
			// set write control byte
			l_cControlWriteByte|= (m_cI2CDeviceAdr << 0x1);

			CI2CSTDLIBConvert::ByteToI2CCharStream(l_cControlWriteByte, l_cWriteControl);
			//////////////////////////////////////////////////////
			// stop temperature convertion
			// command byte
			CI2CSTDLIBConvert::ByteToI2CCharStream(m_cStopConvertT, l_cCommand);

			// I2C stream string
			sprintf(l_cI2CStream,"%s%s%s%s%s%s",
				CI2CSTDLIBCmd::m_cI2CStart,l_cWriteControl, CI2CSTDLIBCmd::m_cI2CAck,
				l_cCommand,CI2CSTDLIBCmd::m_cI2CAck, CI2CSTDLIBCmd::m_cI2CStop);

			// stop temp convertion
			CO_TRACE(I2CTEMP_ID, _T("Send - StopTempConvertion():"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			//int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 8);
			//BYTE* l_pcI2CData = new BYTE[l_nStreamLen];
			// convert data stream string to data byte stream // byte data stream 
			//CI2CSTDLIBConvert::CharStreamToByteStream(l_cI2CStream, l_pcI2CData, l_nStreamLen);
			// convert data stream string to data byte stream
			int l_nStreamLen = (int) ceil((double) strlen(l_cI2CStream) / (double) 32);
			PDWORD l_pdwI2CData = new DWORD[l_nStreamLen];
			CI2CSTDLIBConvert::CharStreamToDWordStream(l_cI2CStream, l_pdwI2CData, l_nStreamLen);

			// add command to the I2C worker thread queue
			l_pCmd = new CI2CTempSensor1631ZCommand((PBYTE)l_pdwI2CData,l_nStreamLen*sizeof(DWORD), (DWORD)m_cI2CBusNumber, (DWORD)m_cI2CTransferSpeed);

			l_pI2CSyncObj = CHII2CWorkerThread::GetInstance()->AddCommand(l_pCmd);
			l_pI2CSyncObj->Synchronize();
			l_pI2CAnswerDataStream = l_pI2CSyncObj->GetValue();
			l_pCmd->ReleaseRef();
			l_pCmd = NULL;

			// get answer data stream
			//l_nStreamLen = l_pI2CAnswerDataStream->GetnSize();
			// convert byte stream data to I2C char stream
			//strcpy(l_cI2CStream,"");
			//CI2CSTDLIBConvert::ByteStreamToCharStream(l_pI2CAnswerDataStream->GetpcI2CDataStream(), l_nStreamLen, l_cI2CStream);
			// convert byte stream data to I2C String
			l_pdwI2CStream = (PDWORD)l_pI2CAnswerDataStream->GetpcI2CDataStream();
			l_nStreamLen = l_pI2CAnswerDataStream->GetnSize() / sizeof(DWORD);
			strcpy(l_cI2CStream,"");
			CI2CSTDLIBConvert::DWordStreamToCharStream(l_pdwI2CStream, l_nStreamLen, l_cI2CStream);

			// stop temperature convertion
			CO_TRACE(I2CTEMP_ID, _T("Recieve - StopTempConvertion()::"));
			CO_TRACE(I2CTEMP_ID, l_cI2CStream);
			CO_TRACE(I2CTEMP_ID, _T("/"));

			l_pI2CAnswerDataStream->ReleaseRef();
			l_pI2CAnswerDataStream = NULL;
			l_pI2CSyncObj->ReleaseRef();
			l_pI2CSyncObj =NULL;

			// check ACK
			if ( !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 18) || !CI2CSTDLIBConvert::CheckNACK(l_cI2CStream, 36))
			{
				// command failed
				throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_STOP_TEMP_ACK_ERROR, __FILE__, __LINE__, 0);
			}
		}
		else
		{
			throw new XI2CTempExceptionError(I2CTEMP_ID, IDE_I2C_INTF_DS1631Z_WRONG_ID, __FILE__, __LINE__, 0);
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

		// was the cell undocked?
		if (CHIInterface::GetInstance()->GetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDDockingState)) == 0)
		{
			l_pException->Delete();
			l_pSyncObj->AttachException(new XCOExceptionCellUndocked(I2CTEMP_ID, IDE_CORE_CELL_UNDOCKED, _T(__FILE__), __LINE__));
		}
		else
		{
			l_pSyncObj->AttachException(l_pException);
		}    
	}

	return l_pSyncObj;
	//## end CI2CTempSensorDS1631Z::StopTemperatureConvertion%1056519545.body
}

//## Get and Set Operations for Class Attributes (implementation)

const BYTE CI2CTempSensorDS1631Z::GetcI2CDeviceAdr () const
{
	//## begin CI2CTempSensorDS1631Z::GetcI2CDeviceAdr%3F5C507D03D8.get preserve=no
	return m_cI2CDeviceAdr;
	//## end CI2CTempSensorDS1631Z::GetcI2CDeviceAdr%3F5C507D03D8.get
}

const BYTE CI2CTempSensorDS1631Z::GetcI2CBusNumber () const
{
	//## begin CI2CTempSensorDS1631Z::GetcI2CBusNumber%3F5C51070186.get preserve=no
	return m_cI2CBusNumber;
	//## end CI2CTempSensorDS1631Z::GetcI2CBusNumber%3F5C51070186.get
}

const BYTE CI2CTempSensorDS1631Z::GetcI2CTransferSpeed () const
{
	//## begin CI2CTempSensorDS1631Z::GetcI2CTransferSpeed%3F5C51080109.get preserve=no
	return m_cI2CTransferSpeed;
	//## end CI2CTempSensorDS1631Z::GetcI2CTransferSpeed%3F5C51080109.get
}

const BYTE CI2CTempSensorDS1631Z::GetcI2CDevice () const
{
	//## begin CI2CTempSensorDS1631Z::GetcI2CDevice%3F5C752C00EA.get preserve=no
	return m_cI2CDevice;
	//## end CI2CTempSensorDS1631Z::GetcI2CDevice%3F5C752C00EA.get
}

// Additional Declarations
//## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.declarations preserve=yes
//## end CI2CTempSensorDS1631Z%3EDD8EC503D8.declarations

//## begin module%3EE7373A03C8.epilog preserve=yes
//## end module%3EE7373A03C8.epilog
