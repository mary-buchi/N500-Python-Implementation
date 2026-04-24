//## begin module%3EDC5B3C01CB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01CB.cm

//## begin module%3EDC5B3C01CB.cp preserve=no
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
//## end module%3EDC5B3C01CB.cp

//## Module: EBSYmain%3EDC5B3C01CB; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C01CB.additionalIncludes preserve=no
//## end module%3EDC5B3C01CB.additionalIncludes

//## begin module%3EDC5B3C01CB.includes preserve=yes
#include "EBSYdlsf.h"
//## end module%3EDC5B3C01CB.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
// EBPImain
#include "EBPImain.h"
// EBSYintf
#include "EBSYintf.h"
// EBSYsten
#include "EBSYsten.h"
// EBSYmain
#include "EBSYmain.h"
// EBHIintf
#include "EBHIintf.h"
// EBSYmhan
#include "EBSYmhan.h"


//## begin module%3EDC5B3C01CB.declarations preserve=no
//## end module%3EDC5B3C01CB.declarations

//## begin module%3EDC5B3C01CB.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01CB.additionalDeclarations


// Class CSYSystem 

//## begin CSYSystem::pSystemInterface%3EE9943C02E0.role preserve=no  public: static CSYSystemInterface { -> RFHN}
CSYSystemInterface *CSYSystem::m_pSystemInterface = NULL;
//## end CSYSystem::pSystemInterface%3EE9943C02E0.role

CSYSystem::CSYSystem()
  //## begin CSYSystem::CSYSystem%.hasinit preserve=no
  //## end CSYSystem::CSYSystem%.hasinit
  //## begin CSYSystem::CSYSystem%.initialization preserve=yes
  //## end CSYSystem::CSYSystem%.initialization
{
  //## begin CSYSystem::CSYSystem%.body preserve=yes
  //## end CSYSystem::CSYSystem%.body
}


CSYSystem::~CSYSystem()
{
  //## begin CSYSystem::~CSYSystem%.body preserve=yes
  //## end CSYSystem::~CSYSystem%.body
}



//## Other Operations (implementation)
bool CSYSystem::Create ()
{
  //## begin CSYSystem::Create%1055493755.body preserve=yes
  // AFX_MANAGE_STATE(AfxGetStaticModuleState( ))

  try
  {
    CHIInterface::Create();
	CPISystem::Create();
    CSYStateMachineEngine::BuildStateMachine();
    m_pSystemInterface = new CSYSystemInterface(0);
    CPIObjectFactory::GetInstance()->RegisterSystemInterface(m_pSystemInterface);
    m_pSystemInterface->InitInstance();
	CCOSyncObjectPtr l_SyncObj = m_pSystemInterface->Startup();

    // do not synchronize for startup
	// l_SyncObj->Synchronize();

    return true;
  }
  catch(XCOException* p_pException)
  {
	ShowException(p_pException);
    return false;
  }
  //## end CSYSystem::Create%1055493755.body
}

void CSYSystem::Delete ()
{
  //## begin CSYSystem::Delete%1055493756.body preserve=yes
	try
	{
		CCOSyncObjectPtr l_pSyncObj = m_pSystemInterface->Shutdown();
		l_pSyncObj->Synchronize();
	}
	catch(...)
	{
	}

    CPISystem::Stop();

    m_pSystemInterface->ExitInstance();
    CPIObjectFactory::GetInstance()->RegisterSystemInterface(NULL);
    delete m_pSystemInterface;

    CSYStateMachineEngine::DeleteStateMachine();

    CPISystem::Delete();
    CHIInterface::Delete();

  //## end CSYSystem::Delete%1055493756.body
}

void CSYSystem::ShowException (XCOException* p_pException)
{
  //## begin CSYSystem::ShowException%1077175167.body preserve=yes
	CString l_sMsg;
	l_sMsg.Format(_T("Exception: %s.%d\nFile: %s\nLine: %d\n"), 
        p_pException->GetsUnitID(),
        p_pException->GetuiExceptionID(),
        p_pException->GetsModuleName(),
        p_pException->GetuiModuleLine());
    CO_TRACE(_T("SY"), l_sMsg);

	CSYDialogStartupFailure* l_pDlg = new CSYDialogStartupFailure(l_sMsg);
	l_pDlg->Create((UINT)IDD_DIALOG_STARTUP_FAILURE, NULL);
	l_pDlg->ShowWindow(SW_SHOW);
	l_pDlg->UpdateWindow();

	WriteLogFile(p_pException);
	p_pException->Delete();

	Sleep(5000);
	l_pDlg->DestroyWindow();
  //## end CSYSystem::ShowException%1077175167.body
}

void CSYSystem::WriteLogFile (XCOException* p_pException)
{
  //## begin CSYSystem::WriteLogFile%1077175166.body preserve=yes
#ifdef _WIN32_WCE
    const CString l_sFileName = _T("\\Hard Disk\\NIRFlex\\Startup.log");
	CFile l_File;
	if (l_File.Open(l_sFileName, CFile::modeReadWrite | CFile::modeCreate))
#else
    const CString l_sFileName = _T("R:\\Bin\\Debug\\Startup.log");
	CStdioFile l_File;
	if (l_File.Open(l_sFileName, CFile::modeReadWrite | CFile::modeCreate | CFile::typeText))
#endif
	{
		CString l_sLine;
		l_sLine.Format(_T("%s.%d | %s.%d"),
			p_pException->GetsUnitID(),
			p_pException->GetdwErrorCode(),
			p_pException->GetsModuleName(),
			p_pException->GetuiModuleLine());

#ifdef _WIN32_WCE
		l_File.Write((LPCTSTR)l_sLine, 2*l_sLine.GetLength());
		l_File.Write(_T("\r\n"), 2*sizeof(TCHAR));
#else
        l_File.WriteString(l_sLine);
#endif
	}
	l_File.Close();
  //## end CSYSystem::WriteLogFile%1077175166.body
}

// Additional Declarations
  //## begin CSYSystem%3EE886FE0308.declarations preserve=yes
  //## end CSYSystem%3EE886FE0308.declarations

//## begin module%3EDC5B3C01CB.epilog preserve=yes
//## end module%3EDC5B3C01CB.epilog
