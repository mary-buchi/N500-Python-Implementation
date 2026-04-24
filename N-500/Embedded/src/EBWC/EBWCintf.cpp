//## begin module%3DD0BBEA0317.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0BBEA0317.cm

//## begin module%3DD0BBEA0317.cp preserve=no
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
//## end module%3DD0BBEA0317.cp

//## Module: EBWCintf%3DD0BBEA0317; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD0BBEA0317.additionalIncludes preserve=no
//## end module%3DD0BBEA0317.additionalIncludes

//## begin module%3DD0BBEA0317.includes preserve=yes
//## end module%3DD0BBEA0317.includes

// EBCOsync
#include "EBCOsync.h"
// EBWCcomd
#include "EBWCcomd.h"
// EBWCimpl
#include "EBWCimpl.h"
// EBWCintf
#include "EBWCintf.h"
// EBWCidnt
#include "EBWCidnt.h"


//## begin module%3DD0BBEA0317.declarations preserve=no
//## end module%3DD0BBEA0317.declarations

//## begin module%3DD0BBEA0317.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}
//## end module%3DD0BBEA0317.additionalDeclarations


// Class CWCWedgeControlInterface 


CWCWedgeControlInterface::CWCWedgeControlInterface (UINT p_uiID)
  //## begin CWCWedgeControlInterface::CWCWedgeControlInterface%1037094239.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CWCWedgeControlInterface::CWCWedgeControlInterface%1037094239.hasinit
  //## begin CWCWedgeControlInterface::CWCWedgeControlInterface%1037094239.initialization preserve=yes
  , IPIWedgeControlInterface(WC_ID)
  //## end CWCWedgeControlInterface::CWCWedgeControlInterface%1037094239.initialization
{
  //## begin CWCWedgeControlInterface::CWCWedgeControlInterface%1037094239.body preserve=yes
  //## end CWCWedgeControlInterface::CWCWedgeControlInterface%1037094239.body
}


CWCWedgeControlInterface::~CWCWedgeControlInterface()
{
  //## begin CWCWedgeControlInterface::~CWCWedgeControlInterface%.body preserve=yes
  //## end CWCWedgeControlInterface::~CWCWedgeControlInterface%.body
}



//## Other Operations (implementation)
void CWCWedgeControlInterface::InitInstance ()
{
  //## begin CWCWedgeControlInterface::InitInstance%1037094238.body preserve=yes
  m_pImplementation = new CWCWedgeControlImplementation(this);

  IPIWedgeControlInterface::InitInstance();
  //## end CWCWedgeControlInterface::InitInstance%1037094238.body
}

UINT CWCWedgeControlInterface::GetuiID ()
{
  //## begin CWCWedgeControlInterface::GetuiID%1037174257.body preserve=yes
  return m_uiID;
  //## end CWCWedgeControlInterface::GetuiID%1037174257.body
}

CCOSyncObject* CWCWedgeControlInterface::SetProfile (CPIWedgeControlProfile* p_pProfile)
{
  //## begin CWCWedgeControlInterface::SetProfile%1037174258.body preserve=yes
  return(Execute(new CWCCommandSetProfile (m_pImplementation, p_pProfile)));
  //## end CWCWedgeControlInterface::SetProfile%1037174258.body
}

CCOSyncObject* CWCWedgeControlInterface::SetConfiguration (CPIWedgeControlConfig* p_pConfig)
{
  //## begin CWCWedgeControlInterface::SetConfiguration%1037174259.body preserve=yes
  return(Execute(new CWCCommandSetConfiguration(m_pImplementation, p_pConfig)));
  //## end CWCWedgeControlInterface::SetConfiguration%1037174259.body
}

CCOSyncObject* CWCWedgeControlInterface::Initialize ()
{
  //## begin CWCWedgeControlInterface::Initialize%1037174260.body preserve=yes
  return(Execute(new CWCCommandInitialize (m_pImplementation)));
  //## end CWCWedgeControlInterface::Initialize%1037174260.body
}

CCOSyncObjectArray* CWCWedgeControlInterface::Start (int p_iScan)
{
  //## begin CWCWedgeControlInterface::Start%1037174261.body preserve=yes

  CWCCommandStart* l_pCmd = new CWCCommandStart(m_pImplementation);
  
  CCOSyncObjectArray* l_pCmdSyncObjs = l_pCmd->GetpSyncArray();
  l_pCmdSyncObjs->AddRef();

  CCOSyncObjectPtr l_pCmdCompletedSyncObj = Execute(l_pCmd, eCOQueueAboveNormal);

  // prepare array for client
  ASSERT(l_pCmdSyncObjs->GetSize() == 2);

  CCOSyncObjectArray* l_pSyncArray = new CCOSyncObjectArray();
  l_pSyncArray->Add(l_pCmdSyncObjs->GetAt(0));
  l_pSyncArray->Add(l_pCmdSyncObjs->GetAt(1));
  
  l_pCmdSyncObjs->ReleaseRef();

  return l_pSyncArray;
  //## end CWCWedgeControlInterface::Start%1037174261.body
}

CCOSyncObject* CWCWedgeControlInterface::Stop ()
{
  //## begin CWCWedgeControlInterface::Stop%1037174262.body preserve=yes
  return(Execute(new CWCCommandStop(m_pImplementation), eCOQueueHigh));
  //## end CWCWedgeControlInterface::Stop%1037174262.body
}

CCOSyncObject* CWCWedgeControlInterface::Referencing ()
{
  //## begin CWCWedgeControlInterface::Referencing%1037976625.body preserve=yes
  return(Execute(new CWCCommandReferencing(m_pImplementation)));
  //## end CWCWedgeControlInterface::Referencing%1037976625.body
}

CCOSyncObject* CWCWedgeControlInterface::Park ()
{
  //## begin CWCWedgeControlInterface::Park%1053509632.body preserve=yes
  return NULL;
  //## end CWCWedgeControlInterface::Park%1053509632.body
}

CCOSyncObject* CWCWedgeControlInterface::ConnectionEstablished ()
{
  //## begin CWCWedgeControlInterface::ConnectionEstablished%1063260177.body preserve=yes
	return Execute(new CWCCommandConnectionEstablished(m_pImplementation), eCOQueueNormal);
  //## end CWCWedgeControlInterface::ConnectionEstablished%1063260177.body
}

CCOSyncObject* CWCWedgeControlInterface::ConnectionLost ()
{
  //## begin CWCWedgeControlInterface::ConnectionLost%1063260178.body preserve=yes
    return Execute(new CWCCommandConnectionLost(m_pImplementation), eCOQueueHigh);
  //## end CWCWedgeControlInterface::ConnectionLost%1063260178.body
}

CCOSyncObjectInt* CWCWedgeControlInterface::GetDacZeroCurrent ()
{
  //## begin CWCWedgeControlInterface::GetDacZeroCurrent%1149159894.body preserve=yes
	CCOSyncObjectInt* l_pSyncObj = dynamic_cast<CCOSyncObjectInt*>(Execute(new CWCCommandGetDacZeroCurrent(m_pImplementation)));
	ASSERT(l_pSyncObj != NULL);
	return l_pSyncObj;
  //## end CWCWedgeControlInterface::GetDacZeroCurrent%1149159894.body
}

// Additional Declarations
  //## begin CWCWedgeControlInterface%3DD0BC940123.declarations preserve=yes
  //## end CWCWedgeControlInterface%3DD0BC940123.declarations

//## begin module%3DD0BBEA0317.epilog preserve=yes
//## end module%3DD0BBEA0317.epilog
