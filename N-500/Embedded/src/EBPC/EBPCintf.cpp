//## begin module%3EED769F037E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F037E.cm

//## begin module%3EED769F037E.cp preserve=no
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
//## end module%3EED769F037E.cp

//## Module: EBPCintf%3EED769F037E; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F037E.additionalIncludes preserve=no
//## end module%3EED769F037E.additionalIncludes

//## begin module%3EED769F037E.includes preserve=yes
//## end module%3EED769F037E.includes

// EBCOsync
#include "EBCOsync.h"
// EBPCcomd
#include "EBPCcomd.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCintf
#include "EBPCintf.h"
// EBPCident
#include "EBPCident.h"


//## begin module%3EED769F037E.declarations preserve=no
//## end module%3EED769F037E.declarations

//## begin module%3EED769F037E.additionalDeclarations preserve=yes
#define DUMMYARRAY_RETURN {  \
    CCOSyncObjectArray* l_pSyncObjArray = new CCOSyncObjectArray();    \
    l_pSyncObjArray->SignalCompletion();                     \
    return l_pSyncObjArray;                                  \
}

#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}

#define DUMMYINT_RETURN {  \
    CCOSyncObjectInt* l_pSyncObjInt = dynamic_cast<CCOSyncObjectInt*>(new CCOSyncObject());    \
    l_pSyncObjInt->SignalCompletion();                     \
    return l_pSyncObjInt;                                  \
}

//## end module%3EED769F037E.additionalDeclarations


// Class CPCPowerControlInterface 


CPCPowerControlInterface::CPCPowerControlInterface (UINT p_uiID)
  //## begin CPCPowerControlInterface::CPCPowerControlInterface%1038899302.hasinit preserve=no
  //## end CPCPowerControlInterface::CPCPowerControlInterface%1038899302.hasinit
  //## begin CPCPowerControlInterface::CPCPowerControlInterface%1038899302.initialization preserve=yes
  : IPIPowerControlInterface(PC_ID), m_uiID(p_uiID)
  //## end CPCPowerControlInterface::CPCPowerControlInterface%1038899302.initialization
{
  //## begin CPCPowerControlInterface::CPCPowerControlInterface%1038899302.body preserve=yes
  //## end CPCPowerControlInterface::CPCPowerControlInterface%1038899302.body
}


CPCPowerControlInterface::~CPCPowerControlInterface()
{
  //## begin CPCPowerControlInterface::~CPCPowerControlInterface%.body preserve=yes
  //## end CPCPowerControlInterface::~CPCPowerControlInterface%.body
}



//## Other Operations (implementation)
void CPCPowerControlInterface::InitInstance ()
{
  //## begin CPCPowerControlInterface::InitInstance%1039429741.body preserve=yes
  m_pImplementation = new CPCPowerControlImplementation(this);

  IPIPowerControlInterface::InitInstance();
  //## end CPCPowerControlInterface::InitInstance%1039429741.body
}

UINT CPCPowerControlInterface::GetuiID ()
{
  //## begin CPCPowerControlInterface::GetuiID%1038899351.body preserve=yes
  return m_uiID;
  //## end CPCPowerControlInterface::GetuiID%1038899351.body
}

CCOSyncObject* CPCPowerControlInterface::SetProfile (CPIPowerControlProfile* p_pProfile)
{
  //## begin CPCPowerControlInterface::SetProfile%1038899307.body preserve=yes
  return(Execute(new CPCCommandSetProfile (m_pImplementation, p_pProfile)));
  //## end CPCPowerControlInterface::SetProfile%1038899307.body
}

CCOSyncObject* CPCPowerControlInterface::SetConfiguration (CPIPowerControlConfig* p_pConfig)
{
  //## begin CPCPowerControlInterface::SetConfiguration%1038899303.body preserve=yes
  return(Execute(new CPCCommandSetConfiguration(m_pImplementation, p_pConfig)));
  //## end CPCPowerControlInterface::SetConfiguration%1038899303.body
}

CCOSyncObjectArray* CPCPowerControlInterface::Start ()
{
  //## begin CPCPowerControlInterface::Start%1038899304.body preserve=yes
  CCOSyncObjectArray* l_pSyncArray = new CCOSyncObjectArray();
  CPCCommandStart* l_pCmd = new CPCCommandStart(m_pImplementation);
  CCOSyncObjectArray* l_pCmdSyncObjs = l_pCmd->GetpSyncArray();
  l_pCmdSyncObjs->AddRef();

  CCOSyncObjectPtr l_pCmdCompletedSyncObj = Execute(l_pCmd);

  // prepare array for client
  ASSERT(l_pCmdSyncObjs->GetSize() == 2);
  l_pSyncArray->Add(l_pCmdSyncObjs->GetAt(0));
  l_pSyncArray->Add(l_pCmdSyncObjs->GetAt(1));
  l_pCmdSyncObjs->ReleaseRef();

  return l_pSyncArray;
  //## end CPCPowerControlInterface::Start%1038899304.body
}

CCOSyncObject* CPCPowerControlInterface::Stop ()
{
  //## begin CPCPowerControlInterface::Stop%1038899305.body preserve=yes
  return Execute(new CPCCommandStop(m_pImplementation), eCOQueueHigh);
  //## end CPCPowerControlInterface::Stop%1038899305.body
}

CCOSyncObject* CPCPowerControlInterface::ConnectionEstablished ()
{
  //## begin CPCPowerControlInterface::ConnectionEstablished%1055922849.body preserve=yes
	return Execute(new CPCCommandConnectionEstablished(m_pImplementation), eCOQueueNormal);
  //## end CPCPowerControlInterface::ConnectionEstablished%1055922849.body
}

CCOSyncObject* CPCPowerControlInterface::ConnectionLost ()
{
  //## begin CPCPowerControlInterface::ConnectionLost%1055922850.body preserve=yes
    return Execute(new CPCCommandConnectionLost(m_pImplementation), eCOQueueHigh);
  //## end CPCPowerControlInterface::ConnectionLost%1055922850.body
}

CCOSyncObject* CPCPowerControlInterface::PowerOff ()
{
  //## begin CPCPowerControlInterface::PowerOff%1076339197.body preserve=yes
	return Execute( new CPCCommandPowerOff( m_pImplementation ) );
  //## end CPCPowerControlInterface::PowerOff%1076339197.body
}

CCOSyncObject* CPCPowerControlInterface::PowerOn ()
{
  //## begin CPCPowerControlInterface::PowerOn%1076339198.body preserve=yes
	return Execute( new CPCCommandPowerOn( m_pImplementation ) );
  //## end CPCPowerControlInterface::PowerOn%1076339198.body
}

// Additional Declarations
  //## begin CPCPowerControlInterface%3EED76CC0307.declarations preserve=yes
  //## end CPCPowerControlInterface%3EED76CC0307.declarations

//## begin module%3EED769F037E.epilog preserve=yes
//## end module%3EED769F037E.epilog
