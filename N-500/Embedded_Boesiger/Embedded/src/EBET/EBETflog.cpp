//## begin module%468BA9850288.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%468BA9850288.cm

//## begin module%468BA9850288.cp preserve=no
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
//## end module%468BA9850288.cp

//## Module: EBETflog%468BA9850288; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETflog.cpp

// stdafx
#include "stdafx.h"
//## begin module%468BA9850288.additionalIncludes preserve=no
//## end module%468BA9850288.additionalIncludes

//## begin module%468BA9850288.includes preserve=yes
//## end module%468BA9850288.includes

// EBETflog
#include "EBETflog.h"


//## begin module%468BA9850288.declarations preserve=no
//## end module%468BA9850288.declarations

//## begin module%468BA9850288.additionalDeclarations preserve=yes
//## end module%468BA9850288.additionalDeclarations


// Class CETFileLogger 


//## begin CETFileLogger::pInstance%468BA9E50350.role preserve=no  public: static CETFileLogger {1..1 -> 1..1RFHN}
CETFileLogger *CETFileLogger::m_pInstance = NULL;
//## end CETFileLogger::pInstance%468BA9E50350.role




CETFileLogger::CETFileLogger()
  //## begin CETFileLogger::CETFileLogger%.hasinit preserve=no
      : m_iStartTick(0), m_pFile(NULL)
  //## end CETFileLogger::CETFileLogger%.hasinit
  //## begin CETFileLogger::CETFileLogger%.initialization preserve=yes
  //## end CETFileLogger::CETFileLogger%.initialization
{
  //## begin CETFileLogger::CETFileLogger%.body preserve=yes
#ifdef DEBUG
	m_iStartTick = ::GetTickCount();
	m_pFile = new CFile();
	m_pFile->Open(_T("EBETLogger.log"), CFile::modeCreate | CFile::modeWrite);
	m_pFile->Close();
#endif
  //## end CETFileLogger::CETFileLogger%.body
}


CETFileLogger::~CETFileLogger()
{
  //## begin CETFileLogger::~CETFileLogger%.body preserve=yes
#ifdef DEBUG
	delete m_pFile;
	m_pFile = NULL;
#endif
  //## end CETFileLogger::~CETFileLogger%.body
}



//## Other Operations (implementation)
void CETFileLogger::Create ()
{
  //## begin CETFileLogger::Create%1183536497.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CETFileLogger();
  //## end CETFileLogger::Create%1183536497.body
}

void CETFileLogger::Delete ()
{
  //## begin CETFileLogger::Delete%1183536498.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CETFileLogger::Delete%1183536498.body
}

CETFileLogger* CETFileLogger::GetInstance ()
{
  //## begin CETFileLogger::GetInstance%1183536499.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CETFileLogger::GetInstance%1183536499.body
}

void CETFileLogger::AddMessage (const WCHAR* p_sMsg)
{
  //## begin CETFileLogger::AddMessage%1183536500.body preserve=yes
#ifdef DEBUG
	CSingleLock l_Lock(&m_AccessLock, true);
	CString l_sLine;
	l_sLine.Format(_T("%08d %s\r\n"), ::GetTickCount() - m_iStartTick, p_sMsg);

	m_pFile->Open(_T("EBETLogger.log"), CFile::modeReadWrite);
	m_pFile->Seek(0, CFile::end);
	m_pFile->Write((LPCTSTR)l_sLine, 2*l_sLine.GetLength());
	m_pFile->Close();
#endif
  //## end CETFileLogger::AddMessage%1183536500.body
}

void CETFileLogger::AddMessage (const WCHAR* p_sMsg, const WCHAR* p_sPar)
{
  //## begin CETFileLogger::AddMessage%1183536501.body preserve=yes
#ifdef DEBUG
	CString msg;
	msg.Format(p_sMsg, p_sPar);
	AddMessage((LPCTSTR)msg);
#endif
  //## end CETFileLogger::AddMessage%1183536501.body
}

void CETFileLogger::AddMessage (const WCHAR* p_sMsg, int p_iPar)
{
  //## begin CETFileLogger::AddMessage%1183536502.body preserve=yes
#ifdef DEBUG
	CString msg;
	msg.Format(p_sMsg, p_iPar);
	AddMessage((LPCTSTR)msg);
#endif
  //## end CETFileLogger::AddMessage%1183536502.body
}

void CETFileLogger::AddMessage (const WCHAR* p_sMsg, int p_iPar1, int p_iPar2)
{
  //## begin CETFileLogger::AddMessage%1183615547.body preserve=yes
#ifdef DEBUG
	CString msg;
	msg.Format(p_sMsg, p_iPar1, p_iPar2);
	AddMessage((LPCTSTR)msg);
#endif
  //## end CETFileLogger::AddMessage%1183615547.body
}

// Additional Declarations
  //## begin CETFileLogger%468BA9A6033A.declarations preserve=yes
  //## end CETFileLogger%468BA9A6033A.declarations

//## begin module%468BA9850288.epilog preserve=yes
//## end module%468BA9850288.epilog
