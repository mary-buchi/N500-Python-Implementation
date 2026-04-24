//## begin module%3DE5EFB5012D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EFB5012D.cm

//## begin module%3DE5EFB5012D.cp preserve=no
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
//## end module%3DE5EFB5012D.cp

//## Module: EBTCintf%3DE5EFB5012D; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EFB5012D.additionalIncludes preserve=no
//## end module%3DE5EFB5012D.additionalIncludes

//## begin module%3DE5EFB5012D.includes preserve=yes
//## end module%3DE5EFB5012D.includes

// EBCOsync
#include "EBCOsync.h"
// EBTCcomd
#include "EBTCcomd.h"
// EBTCimpl
#include "EBTCimpl.h"
// EBTCintf
#include "EBTCintf.h"
// EBTCident
#include "EBTCident.h"


//## begin module%3DE5EFB5012D.declarations preserve=no
//## end module%3DE5EFB5012D.declarations

//## begin module%3DE5EFB5012D.additionalDeclarations preserve=yes
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

//## end module%3DE5EFB5012D.additionalDeclarations


// Class CTCTemperatureControlInterface 


CTCTemperatureControlInterface::CTCTemperatureControlInterface (UINT p_uiID)
  //## begin CTCTemperatureControlInterface::CTCTemperatureControlInterface%1038899302.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CTCTemperatureControlInterface::CTCTemperatureControlInterface%1038899302.hasinit
  //## begin CTCTemperatureControlInterface::CTCTemperatureControlInterface%1038899302.initialization preserve=yes
    ,IPITemperatureControlInterface(TC_ID)
  //## end CTCTemperatureControlInterface::CTCTemperatureControlInterface%1038899302.initialization
{
  //## begin CTCTemperatureControlInterface::CTCTemperatureControlInterface%1038899302.body preserve=yes
  //## end CTCTemperatureControlInterface::CTCTemperatureControlInterface%1038899302.body
}


CTCTemperatureControlInterface::~CTCTemperatureControlInterface()
{
  //## begin CTCTemperatureControlInterface::~CTCTemperatureControlInterface%.body preserve=yes
	if (m_pImplementation != NULL)	// scro: (alle zeilen neu eingefügt)
		delete m_pImplementation;
	m_pImplementation = NULL;


  //## end CTCTemperatureControlInterface::~CTCTemperatureControlInterface%.body
}



//## Other Operations (implementation)
void CTCTemperatureControlInterface::InitInstance ()
{
  //## begin CTCTemperatureControlInterface::InitInstance%1039429741.body preserve=yes
	if (m_pImplementation == NULL)
		m_pImplementation = new CTCTemperatureControlImplementation(this);

	IPITemperatureControlInterface::InitInstance();
  //## end CTCTemperatureControlInterface::InitInstance%1039429741.body
}

UINT CTCTemperatureControlInterface::GetuiID ()
{
  //## begin CTCTemperatureControlInterface::GetuiID%1038899351.body preserve=yes
  return m_uiID;
  //## end CTCTemperatureControlInterface::GetuiID%1038899351.body
}

CCOSyncObject* CTCTemperatureControlInterface::SetProfile (CPITemperatureControlProfile* p_pProfile)
{
  //## begin CTCTemperatureControlInterface::SetProfile%1038899307.body preserve=yes
  return(Execute(new CTCCommandSetProfile (m_pImplementation, p_pProfile)));
  //## end CTCTemperatureControlInterface::SetProfile%1038899307.body
}

CCOSyncObject* CTCTemperatureControlInterface::SetConfiguration (CPITemperatureControlConfig* p_pConfig)
{
  //## begin CTCTemperatureControlInterface::SetConfiguration%1038899303.body preserve=yes
  return(Execute(new CTCCommandSetConfiguration(m_pImplementation, p_pConfig)));
  //## end CTCTemperatureControlInterface::SetConfiguration%1038899303.body
}

CCOSyncObjectArray* CTCTemperatureControlInterface::Start ()
{
  //## begin CTCTemperatureControlInterface::Start%1038899304.body preserve=yes
  
  // create new sync object array
  CCOSyncObjectArray* l_pSyncArray = new CCOSyncObjectArray();

  // add start command to this array
  CTCCommandStart* l_pCmd = new CTCCommandStart(m_pImplementation);

  // save command sync object array to local array
  CCOSyncObjectArray* l_pCmdSyncObjs = l_pCmd->GetpSyncArray();
  l_pCmdSyncObjs->AddRef();

  // execute start command
  CCOSyncObjectPtr l_pCmdCompletedSyncObj = Execute(l_pCmd);

  // array must contain two objects
  ASSERT(l_pCmdSyncObjs->GetSize() == 2);

  // prepare array for client
  l_pSyncArray->Add(l_pCmdSyncObjs->GetAt(0));
  l_pSyncArray->Add(l_pCmdSyncObjs->GetAt(1));
  l_pCmdSyncObjs->ReleaseRef();

  return l_pSyncArray;
  //## end CTCTemperatureControlInterface::Start%1038899304.body
}

CCOSyncObject* CTCTemperatureControlInterface::Stop ()
{
  //## begin CTCTemperatureControlInterface::Stop%1038899305.body preserve=yes
  return Execute(new CTCCommandStop(m_pImplementation), eCOQueueHigh);
  //## end CTCTemperatureControlInterface::Stop%1038899305.body
}

CCOSyncObjectInt* CTCTemperatureControlInterface::GetTemperature ()
{
  //## begin CTCTemperatureControlInterface::GetTemperature%1038899306.body preserve=yes
    CCOSyncObjectInt* l_pSyncObj = dynamic_cast<CCOSyncObjectInt*>(Execute(new CTCCommandGetTemperature(m_pImplementation)));
    ASSERT(l_pSyncObj != NULL);

    return l_pSyncObj;
  //## end CTCTemperatureControlInterface::GetTemperature%1038899306.body
}

CCOSyncObject* CTCTemperatureControlInterface::ConnectionEstablished ()
{
  //## begin CTCTemperatureControlInterface::ConnectionEstablished%1055922847.body preserve=yes
	return Execute(new CTCCommandConnectionEstablished(m_pImplementation), eCOQueueNormal);
  //## end CTCTemperatureControlInterface::ConnectionEstablished%1055922847.body
}

CCOSyncObject* CTCTemperatureControlInterface::ConnectionLost ()
{
  //## begin CTCTemperatureControlInterface::ConnectionLost%1055922848.body preserve=yes
	return Execute(new CTCCommandConnectionLost(m_pImplementation), eCOQueueHigh);
  //## end CTCTemperatureControlInterface::ConnectionLost%1055922848.body
}

// Additional Declarations
  //## begin CTCTemperatureControlInterface%3DEC5892036B.declarations preserve=yes
  //## end CTCTemperatureControlInterface%3DEC5892036B.declarations

// Class CTCTemperatureControlInterface2 

CTCTemperatureControlInterface2::CTCTemperatureControlInterface2 (UINT p_uiID)
  //## begin CTCTemperatureControlInterface2::CTCTemperatureControlInterface2%1218193719.hasinit preserve=no
  //## end CTCTemperatureControlInterface2::CTCTemperatureControlInterface2%1218193719.hasinit
  //## begin CTCTemperatureControlInterface2::CTCTemperatureControlInterface2%1218193719.initialization preserve=yes
	:CTCTemperatureControlInterface (p_uiID)
  //## end CTCTemperatureControlInterface2::CTCTemperatureControlInterface2%1218193719.initialization
{
  //## begin CTCTemperatureControlInterface2::CTCTemperatureControlInterface2%1218193719.body preserve=yes
  //## end CTCTemperatureControlInterface2::CTCTemperatureControlInterface2%1218193719.body
}


CTCTemperatureControlInterface2::~CTCTemperatureControlInterface2()
{
  //## begin CTCTemperatureControlInterface2::~CTCTemperatureControlInterface2%.body preserve=yes
  //## end CTCTemperatureControlInterface2::~CTCTemperatureControlInterface2%.body
}



//## Other Operations (implementation)
void CTCTemperatureControlInterface2::InitInstance ()
{
  //## begin CTCTemperatureControlInterface2::InitInstance%1217858755.body preserve=yes
	m_pImplementation = new CTCTemperatureControlImplementation2(this);

	CTCTemperatureControlInterface::InitInstance();
  //## end CTCTemperatureControlInterface2::InitInstance%1217858755.body
}

// Additional Declarations
  //## begin CTCTemperatureControlInterface2%48971482009A.declarations preserve=yes
  //## end CTCTemperatureControlInterface2%48971482009A.declarations

//## begin module%3DE5EFB5012D.epilog preserve=yes
//## end module%3DE5EFB5012D.epilog
