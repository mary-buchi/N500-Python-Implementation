//## begin module%3FA65ADE00FA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA65ADE00FA.cm

//## begin module%3FA65ADE00FA.cp preserve=no
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
//## end module%3FA65ADE00FA.cp

//## Module: EBPOsimu%3FA65ADE00FA; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOsimu.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FA65ADE00FA.additionalIncludes preserve=no
//## end module%3FA65ADE00FA.additionalIncludes

//## begin module%3FA65ADE00FA.includes preserve=yes
//## end module%3FA65ADE00FA.includes

// EBPOsimu
#include "EBPOsimu.h"
// EBPOidnt
#include "EBPOidnt.h"


//## begin module%3FA65ADE00FA.declarations preserve=no
//## end module%3FA65ADE00FA.declarations

//## begin module%3FA65ADE00FA.additionalDeclarations preserve=yes
#include  <stdio.h>
//## end module%3FA65ADE00FA.additionalDeclarations


// Class CPOEpromSimulation 




CPOEpromSimulation::CPOEpromSimulation (LPCTSTR p_uiFileName)
  //## begin CPOEpromSimulation::CPOEpromSimulation%1067863157.hasinit preserve=no
      : m_sFileName(_T(""))
  //## end CPOEpromSimulation::CPOEpromSimulation%1067863157.hasinit
  //## begin CPOEpromSimulation::CPOEpromSimulation%1067863157.initialization preserve=yes
  , IPII2CEprom24LC515(_T("I2CEPROM"))
  //## end CPOEpromSimulation::CPOEpromSimulation%1067863157.initialization
{
  //## begin CPOEpromSimulation::CPOEpromSimulation%1067863157.body preserve=yes
#ifdef _WIN32_WCE
	CString l_sPath = _T("Hard Disk\\NIRFlex\\");
#else
	CString l_sPath = _T("R:\\Bin\\Data\\");
#endif

	m_sFileName = l_sPath + p_uiFileName;
  //## end CPOEpromSimulation::CPOEpromSimulation%1067863157.body
}


CPOEpromSimulation::~CPOEpromSimulation()
{
  //## begin CPOEpromSimulation::~CPOEpromSimulation%.body preserve=yes
  //## end CPOEpromSimulation::~CPOEpromSimulation%.body
}



//## Other Operations (implementation)
void CPOEpromSimulation::OpenFile ()
{
  //## begin CPOEpromSimulation::OpenFile%1067863158.body preserve=yes

	//example for CFile::GetStatus
	CFileStatus l_FileStatus;
	if (CFile::GetStatus((LPCTSTR) m_sFileName, l_FileStatus))
	{
		// file exists
		// remove readOnly attribute
		l_FileStatus.m_attribute = 0;
		CFile::SetStatus((LPCTSTR)m_sFileName, l_FileStatus);
	}

	CFileException e;
	m_File.Open(m_sFileName, CFile::modeReadWrite | CFile::modeCreate | CFile::modeNoTruncate , &e);

  //## end CPOEpromSimulation::OpenFile%1067863158.body
}

void CPOEpromSimulation::CloseFile ()
{
  //## begin CPOEpromSimulation::CloseFile%1067863159.body preserve=yes
	m_File.Close();
  //## end CPOEpromSimulation::CloseFile%1067863159.body
}

CCOSyncObjectInt* CPOEpromSimulation::ByteRead (WORD p_uiAddress)
{
  //## begin CPOEpromSimulation::ByteRead%1074846582.body preserve=yes
    CCOSyncObjectInt *l_pSyncObjInt = NULL;

    try
    {
        BYTE l_byBuffer = 0;
  	    OpenFile();
        m_File.Seek(p_uiAddress, CFile::begin);
        m_File.Read(&l_byBuffer, 1);
	    CloseFile();
		l_pSyncObjInt = new CCOSyncObjectInt((int)l_byBuffer);
		l_pSyncObjInt->SignalCompletion();
   }
    catch(CFileException *l_pException)
    {
        l_pException->Delete();
        ASSERT(false);
    }
    return l_pSyncObjInt;
  //## end CPOEpromSimulation::ByteRead%1074846582.body
}

CPISyncObjI2CDataStream* CPOEpromSimulation::BlockRead (WORD p_uiAddress, UINT p_uiSize)
{
  //## begin CPOEpromSimulation::BlockRead%1074846583.body preserve=yes
    CPII2CDataStream *l_pData = NULL;
    CPISyncObjI2CDataStream *l_pSyncObj = NULL;
    BYTE *l_pBuf = NULL; 
    ASSERT((p_uiSize % BYTES_PER_CHAR) == 0);

    try
    {
        l_pBuf = new BYTE[p_uiSize];
		ZeroMemory(l_pBuf, p_uiSize);            
  	    OpenFile();
        m_File.Seek(p_uiAddress, CFile::begin);
        m_File.Read(l_pBuf, p_uiSize);
	    CloseFile();
        l_pData = new CPII2CDataStream(l_pBuf, p_uiSize);
        l_pSyncObj = new CPISyncObjI2CDataStream(l_pData);
        l_pSyncObj->SignalCompletion();
   }
    catch(CFileException *l_pException)
    {
        if (l_pBuf != NULL)
   	        delete [] l_pBuf;
        l_pBuf = NULL;

        l_pException->Delete();
        ASSERT(false);
    }
    return l_pSyncObj;
  //## end CPOEpromSimulation::BlockRead%1074846583.body
}

CPISyncObjI2CDataStream* CPOEpromSimulation::ReadContent ()
{
  //## begin CPOEpromSimulation::ReadContent%1074846584.body preserve=yes
	CPII2CDataStream *l_pData = NULL;
	CPISyncObjI2CDataStream *l_pSyncObj = NULL;
	BYTE *l_pBuf = NULL; 
	const UINT l_uiSize = 0xffff;

	try
	{
		l_pBuf = new BYTE[l_uiSize];
		ZeroMemory(l_pBuf, l_uiSize);

  		OpenFile();
		m_File.Seek(0, CFile::begin);
		UINT l_uiBytesRead = m_File.Read(l_pBuf, l_uiSize);
		CloseFile();
		l_pData = new CPII2CDataStream(l_pBuf, l_uiSize);
		l_pSyncObj = new CPISyncObjI2CDataStream(l_pData);
		l_pSyncObj->SignalCompletion();
	}
    catch(CFileException *l_pException)
    {
        if (l_pBuf != NULL)
   	        delete [] l_pBuf;
        l_pBuf = NULL;

        l_pException->Delete();
        ASSERT(false);
    }
    return l_pSyncObj;
  //## end CPOEpromSimulation::ReadContent%1074846584.body
}

CCOSyncObject* CPOEpromSimulation::ByteWrite (WORD p_uiAddress, BYTE p_cValue)
{
  //## begin CPOEpromSimulation::ByteWrite%1074846585.body preserve=yes
	CCOSyncObject *l_pSyncObj = new CCOSyncObject();
	try
	{
   		OpenFile();
		m_File.Seek(p_uiAddress, CFile::begin);
		m_File.Write(&p_cValue, 1);
		CloseFile();
		l_pSyncObj->SignalCompletion();
	}
	catch(CFileException *l_pException)
	{
		delete l_pException;
		ASSERT(false);
	}

	return l_pSyncObj;
  //## end CPOEpromSimulation::ByteWrite%1074846585.body
}

CCOSyncObject* CPOEpromSimulation::PageWrite (WORD p_uiAddress, BYTE* p_pcValue, UINT p_uiSize)
{
  //## begin CPOEpromSimulation::PageWrite%1074846586.body preserve=yes
    CCOSyncObject *l_pSyncObj = new CCOSyncObject();

    try
    {
   	    OpenFile();
	    m_File.Seek(p_uiAddress, CFile::begin);
	    m_File.Write(p_pcValue, p_uiSize);
	    CloseFile();
        l_pSyncObj->SignalCompletion();
    }
    catch(CFileException *l_pException)
    {
        delete l_pException;
        ASSERT(false);
    }

    return l_pSyncObj;
  //## end CPOEpromSimulation::PageWrite%1074846586.body
}

CCOSyncObject* CPOEpromSimulation::WriteContent (BYTE* &p_pContent, UINT p_uiDataSize)
{
  //## begin CPOEpromSimulation::WriteContent%1074846587.body preserve=yes
    CCOSyncObject *l_pSyncObj = new CCOSyncObject();

	// test data size
	div_t l_DivResult;
	l_DivResult = div(p_uiDataSize, 64);
	ASSERT(l_DivResult.rem == 0);

    try
    {
   	    OpenFile();
	    m_File.Seek(0, CFile::begin);
	    m_File.Write(p_pContent, p_uiDataSize);
	    CloseFile();
        l_pSyncObj->SignalCompletion();
    }
    catch(CFileException *l_pException)
    {
        delete l_pException;
        ASSERT(false);
    }

    return l_pSyncObj;
  //## end CPOEpromSimulation::WriteContent%1074846587.body
}

UINT CPOEpromSimulation::GetEprom24LC515SizeInByte ()
{
  //## begin CPOEpromSimulation::GetEprom24LC515SizeInByte%1074846588.body preserve=yes
    return 65536;
  //## end CPOEpromSimulation::GetEprom24LC515SizeInByte%1074846588.body
}

UINT CPOEpromSimulation::GetEprom24LC515PageSizeInByte ()
{
  //## begin CPOEpromSimulation::GetEprom24LC515PageSizeInByte%1074846589.body preserve=yes
    return 64;
  //## end CPOEpromSimulation::GetEprom24LC515PageSizeInByte%1074846589.body
}

UINT CPOEpromSimulation::GetuiID ()
{
  //## begin CPOEpromSimulation::GetuiID%1074846598.body preserve=yes
    ASSERT(false);
    return NULL;
  //## end CPOEpromSimulation::GetuiID%1074846598.body
}

CCOSyncObject* CPOEpromSimulation::Startup ()
{
  //## begin CPOEpromSimulation::Startup%1074846599.body preserve=yes
    ASSERT(false);
    return NULL;
  //## end CPOEpromSimulation::Startup%1074846599.body
}

CCOSyncObject* CPOEpromSimulation::Shutdown ()
{
  //## begin CPOEpromSimulation::Shutdown%1074846600.body preserve=yes
    ASSERT(false);
    return NULL;
  //## end CPOEpromSimulation::Shutdown%1074846600.body
}

CCOSyncObject* CPOEpromSimulation::ConnectionEstablished ()
{
  //## begin CPOEpromSimulation::ConnectionEstablished%1074846601.body preserve=yes
    ASSERT(false);
    return NULL;
  //## end CPOEpromSimulation::ConnectionEstablished%1074846601.body
}

CCOSyncObject* CPOEpromSimulation::ConnectionLost ()
{
  //## begin CPOEpromSimulation::ConnectionLost%1074846602.body preserve=yes
    ASSERT(false);
    return NULL;
  //## end CPOEpromSimulation::ConnectionLost%1074846602.body
}

// Additional Declarations
  //## begin CPOEpromSimulation%3FA65A9C03C8.declarations preserve=yes
  //## end CPOEpromSimulation%3FA65A9C03C8.declarations

//## begin module%3FA65ADE00FA.epilog preserve=yes
//## end module%3FA65ADE00FA.epilog
