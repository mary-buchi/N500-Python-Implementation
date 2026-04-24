//## begin module%3EE08A320249.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE08A320249.cm

//## begin module%3EE08A320249.cp preserve=no
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
//## end module%3EE08A320249.cp

//## Module: EBSYrdsw%3EE08A320249; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYrdsw.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE08A320249.additionalIncludes preserve=no
//## end module%3EE08A320249.additionalIncludes

//## begin module%3EE08A320249.includes preserve=yes
//## end module%3EE08A320249.includes

// EBCOsync
#include "EBCOsync.h"
// EBSYmhan
#include "EBSYmhan.h"
// EBSYcntd
#include "EBSYcntd.h"
// EBSYidle
#include "EBSYidle.h"
// EBSYrdsw
#include "EBSYrdsw.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3EE08A320249.declarations preserve=no
//## end module%3EE08A320249.declarations

//## begin module%3EE08A320249.additionalDeclarations preserve=yes
//## end module%3EE08A320249.additionalDeclarations


// Class CSYStateProcessReadSoftwareVersions 

//## begin CSYStateProcessReadSoftwareVersions::pInstance%3FA232AF01B6.role preserve=no  public: static CSYStateProcessReadSoftwareVersions {1..1 -> RFHN}
CSYStateProcessReadSoftwareVersions *CSYStateProcessReadSoftwareVersions::m_pInstance = NULL;
//## end CSYStateProcessReadSoftwareVersions::pInstance%3FA232AF01B6.role



CSYStateProcessReadSoftwareVersions::CSYStateProcessReadSoftwareVersions()
  //## begin CSYStateProcessReadSoftwareVersions::CSYStateProcessReadSoftwareVersions%.hasinit preserve=no
      : m_pClientSyncObj(NULL)
  //## end CSYStateProcessReadSoftwareVersions::CSYStateProcessReadSoftwareVersions%.hasinit
  //## begin CSYStateProcessReadSoftwareVersions::CSYStateProcessReadSoftwareVersions%.initialization preserve=yes
  //## end CSYStateProcessReadSoftwareVersions::CSYStateProcessReadSoftwareVersions%.initialization
{
  //## begin CSYStateProcessReadSoftwareVersions::CSYStateProcessReadSoftwareVersions%.body preserve=yes
  //## end CSYStateProcessReadSoftwareVersions::CSYStateProcessReadSoftwareVersions%.body
}


CSYStateProcessReadSoftwareVersions::~CSYStateProcessReadSoftwareVersions()
{
  //## begin CSYStateProcessReadSoftwareVersions::~CSYStateProcessReadSoftwareVersions%.body preserve=yes
    if (m_pClientSyncObj)
        m_pClientSyncObj->ReleaseRef();
  //## end CSYStateProcessReadSoftwareVersions::~CSYStateProcessReadSoftwareVersions%.body
}



//## Other Operations (implementation)
void CSYStateProcessReadSoftwareVersions::Create ()
{
  //## begin CSYStateProcessReadSoftwareVersions::Create%1067594679.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSYStateProcessReadSoftwareVersions();
  //## end CSYStateProcessReadSoftwareVersions::Create%1067594679.body
}

void CSYStateProcessReadSoftwareVersions::Delete ()
{
  //## begin CSYStateProcessReadSoftwareVersions::Delete%1067594680.body preserve=yes
	if (m_pInstance)
		delete m_pInstance;
	m_pInstance = NULL;
  //## end CSYStateProcessReadSoftwareVersions::Delete%1067594680.body
}

CSYStateProcessReadSoftwareVersions* CSYStateProcessReadSoftwareVersions::GetInstance ()
{
  //## begin CSYStateProcessReadSoftwareVersions::GetInstance%1067594681.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CSYStateProcessReadSoftwareVersions::GetInstance%1067594681.body
}

void CSYStateProcessReadSoftwareVersions::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessReadSoftwareVersions::Do%1067594682.body preserve=yes
    try
    {
        CString  sDLLName;
        CString  sDLLVersion;
        CMapStringToString cDLLVersionList;
        CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*> cList;

        CSYModuleHandling::ReadAllDLLVersions(cDLLVersionList);

		for (POSITION l_Pos = cDLLVersionList.GetStartPosition(); l_Pos!=NULL;)
        {
            cDLLVersionList.GetNextAssoc(l_Pos, sDLLName, sDLLVersion);
            CPIPersistentSoftwareComponentVersion* pComponentVersion = 
                new CPIPersistentSoftwareComponentVersion((WCHAR*)(LPCTSTR)sDLLName, (WCHAR*)(LPCTSTR)sDLLVersion);

            cList.AddTail(pComponentVersion);
        }

        // add HIConfig info
        CPIPersistentSoftwareComponentVersion* pComponentVersion = 
            new CPIPersistentSoftwareComponentVersion(_T("HIConfig.xml"), (WCHAR*)(LPCTSTR)IHIInterface::GetInstance()->GetsXMLVersion());
        cList.AddTail(pComponentVersion);

        dynamic_cast<CPISyncObjListSWCompVersion*>(m_pClientSyncObj)->
            SetValue(new CPIPersistentSoftwareComponentVersionList(cList));
        m_pClientSyncObj->SignalCompletion();
        m_pClientSyncObj->ReleaseRef();
        m_pClientSyncObj = NULL;

        p_pContext->ChangeState(CSYStateProcessIdle::GetInstance());
    }
    catch(XCOExceptionError* p_pException)
    {
        // TODO: 
        ASSERT(FALSE);
        p_pException->Delete();
    }
  //## end CSYStateProcessReadSoftwareVersions::Do%1067594682.body
}

//## Get and Set Operations for Associations (implementation)

void CSYStateProcessReadSoftwareVersions::SetpClientSyncObj (CCOSyncObject * value)
{
  //## begin CSYStateProcessReadSoftwareVersions::SetpClientSyncObj%409114E202B8.set preserve=yes
    if (m_pClientSyncObj)
        m_pClientSyncObj->ReleaseRef();
    
    m_pClientSyncObj = value;
    m_pClientSyncObj->AddRef();
  //## end CSYStateProcessReadSoftwareVersions::SetpClientSyncObj%409114E202B8.set
}

// Additional Declarations
  //## begin CSYStateProcessReadSoftwareVersions%3FA232640138.declarations preserve=yes
  //## end CSYStateProcessReadSoftwareVersions%3FA232640138.declarations

// Class CSYStateConstitutionReadSoftwareVersions 

//## begin CSYStateConstitutionReadSoftwareVersions::pInstance%400687740013.role preserve=no  public: static CSYStateConstitutionReadSoftwareVersions {1..1 -> 1..1RFHN}
CSYStateConstitutionReadSoftwareVersions *CSYStateConstitutionReadSoftwareVersions::m_pInstance = NULL;
//## end CSYStateConstitutionReadSoftwareVersions::pInstance%400687740013.role



CSYStateConstitutionReadSoftwareVersions::CSYStateConstitutionReadSoftwareVersions()
  //## begin CSYStateConstitutionReadSoftwareVersions::CSYStateConstitutionReadSoftwareVersions%.hasinit preserve=no
      : m_pClientSyncObj(NULL)
  //## end CSYStateConstitutionReadSoftwareVersions::CSYStateConstitutionReadSoftwareVersions%.hasinit
  //## begin CSYStateConstitutionReadSoftwareVersions::CSYStateConstitutionReadSoftwareVersions%.initialization preserve=yes
  //## end CSYStateConstitutionReadSoftwareVersions::CSYStateConstitutionReadSoftwareVersions%.initialization
{
  //## begin CSYStateConstitutionReadSoftwareVersions::CSYStateConstitutionReadSoftwareVersions%.body preserve=yes
  //## end CSYStateConstitutionReadSoftwareVersions::CSYStateConstitutionReadSoftwareVersions%.body
}


CSYStateConstitutionReadSoftwareVersions::~CSYStateConstitutionReadSoftwareVersions()
{
  //## begin CSYStateConstitutionReadSoftwareVersions::~CSYStateConstitutionReadSoftwareVersions%.body preserve=yes
  //## end CSYStateConstitutionReadSoftwareVersions::~CSYStateConstitutionReadSoftwareVersions%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionReadSoftwareVersions::Create ()
{
  //## begin CSYStateConstitutionReadSoftwareVersions::Create%1074169738.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionReadSoftwareVersions();
  //## end CSYStateConstitutionReadSoftwareVersions::Create%1074169738.body
}

void CSYStateConstitutionReadSoftwareVersions::Delete ()
{
  //## begin CSYStateConstitutionReadSoftwareVersions::Delete%1074169739.body preserve=yes
    if (m_pInstance)
       delete m_pInstance;
    m_pInstance = NULL;
  //## end CSYStateConstitutionReadSoftwareVersions::Delete%1074169739.body
}

CSYStateConstitutionReadSoftwareVersions* CSYStateConstitutionReadSoftwareVersions::GetInstance ()
{
  //## begin CSYStateConstitutionReadSoftwareVersions::GetInstance%1074169740.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSYStateConstitutionReadSoftwareVersions::GetInstance%1074169740.body
}

void CSYStateConstitutionReadSoftwareVersions::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionReadSoftwareVersions::Do%1074169741.body preserve=yes
    try
    {
        CString  sDLLName;
        CString  sDLLVersion;
        CMapStringToString cDLLVersionList;
        CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*> cList;

        CSYModuleHandling::ReadAllDLLVersions(cDLLVersionList);

		for (POSITION l_Pos = cDLLVersionList.GetStartPosition(); l_Pos!=NULL;)
        {
            cDLLVersionList.GetNextAssoc(l_Pos, sDLLName, sDLLVersion);
            CPIPersistentSoftwareComponentVersion* pComponentVersion = 
                new CPIPersistentSoftwareComponentVersion((WCHAR*)(LPCTSTR)sDLLName, (WCHAR*)(LPCTSTR)sDLLVersion);

            cList.AddTail(pComponentVersion);
        }

        // add HIConfig info
        CPIPersistentSoftwareComponentVersion* pComponentVersion = 
            new CPIPersistentSoftwareComponentVersion(_T("HIConfig.xml"), (WCHAR*)(LPCTSTR)IHIInterface::GetInstance()->GetsXMLVersion());
        cList.AddTail(pComponentVersion);

        dynamic_cast<CPISyncObjListSWCompVersion*>(m_pClientSyncObj)->
            SetValue(new CPIPersistentSoftwareComponentVersionList(cList));
        m_pClientSyncObj->SignalCompletion();
        m_pClientSyncObj->ReleaseRef();
        m_pClientSyncObj = NULL;

        p_pContext->ChangeState(CSYStateConstitutionConnected::GetInstance());
    }
    catch(XCOExceptionError* p_pException)
    {
        // TODO: 
        ASSERT(FALSE);
        p_pException->Delete();
    }
  //## end CSYStateConstitutionReadSoftwareVersions::Do%1074169741.body
}

EPIDeviceState CSYStateConstitutionReadSoftwareVersions::GetDeviceState ()
{
  //## begin CSYStateConstitutionReadSoftwareVersions::GetDeviceState%1074169742.body preserve=yes
    return eRunning;
  //## end CSYStateConstitutionReadSoftwareVersions::GetDeviceState%1074169742.body
}

//## Get and Set Operations for Associations (implementation)

void CSYStateConstitutionReadSoftwareVersions::SetpClientSyncObj (CCOSyncObject * value)
{
  //## begin CSYStateConstitutionReadSoftwareVersions::SetpClientSyncObj%409113480047.set preserve=yes
    if (m_pClientSyncObj)
        m_pClientSyncObj->ReleaseRef();
    
    m_pClientSyncObj = value;
    m_pClientSyncObj->AddRef();
  //## end CSYStateConstitutionReadSoftwareVersions::SetpClientSyncObj%409113480047.set
}

// Additional Declarations
  //## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.declarations preserve=yes
  //## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.declarations

//## begin module%3EE08A320249.epilog preserve=yes
//## end module%3EE08A320249.epilog
