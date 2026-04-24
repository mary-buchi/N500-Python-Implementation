//## begin module%3B8EA57B024D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8EA57B024D.cm

//## begin module%3B8EA57B024D.cp preserve=no
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
//## end module%3B8EA57B024D.cp

//## Module: EBCOcomd%3B8EA57B024D; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B8EA57B024D.additionalIncludes preserve=no
//## end module%3B8EA57B024D.additionalIncludes

//## begin module%3B8EA57B024D.includes preserve=yes
//## end module%3B8EA57B024D.includes

// EBCOstat
#include "EBCOstat.h"
// EBCOcomd
#include "EBCOcomd.h"
// EBCOimct
#include "EBCOimct.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"


//## begin module%3B8EA57B024D.declarations preserve=no
//## end module%3B8EA57B024D.declarations

//## begin module%3B8EA57B024D.additionalDeclarations preserve=yes
//## end module%3B8EA57B024D.additionalDeclarations


// Class CCOCommand 




CCOCommand::CCOCommand (ICOStateMachineContext* p_pContext)
  //## begin CCOCommand::CCOCommand%999456385.hasinit preserve=no
      : m_pSyncArray(NULL), m_pContext(p_pContext)
  //## end CCOCommand::CCOCommand%999456385.hasinit
  //## begin CCOCommand::CCOCommand%999456385.initialization preserve=yes
  //## end CCOCommand::CCOCommand%999456385.initialization
{
  //## begin CCOCommand::CCOCommand%999456385.body preserve=yes
    m_pSyncArray = new CCOSyncObjectArray();
  //## end CCOCommand::CCOCommand%999456385.body
}


CCOCommand::~CCOCommand()
{
  //## begin CCOCommand::~CCOCommand%.body preserve=yes
    m_pSyncArray->ReleaseRef();
  //## end CCOCommand::~CCOCommand%.body
}



//## Other Operations (implementation)
void CCOCommand::CreateSyncObjects ()
{
  //## begin CCOCommand::CreateSyncObjects%1034575091.body preserve=yes
    if (m_pSyncArray->GetSize() == 0)
    {
        // add default sync object
        m_pSyncArray->Add(new CCOSyncObject(_T("CO:CCOCommand::CreateSyncObjects")), false);
    }
  //## end CCOCommand::CreateSyncObjects%1034575091.body
}

void CCOCommand::AttachException (XCOException* p_pException)
{
  //## begin CCOCommand::AttachException%1000031218.body preserve=yes
    // put exception into active sync objects
    m_pSyncArray->AttachException(p_pException);
  //## end CCOCommand::AttachException%1000031218.body
}

void CCOCommand::SignalCompletion ()
{
  //## begin CCOCommand::SignalCompletion%999456386.body preserve=yes
    // signal first sync object in array
    m_pSyncArray->GetAt(0)->SignalCompletion();
  //## end CCOCommand::SignalCompletion%999456386.body
}

void CCOCommand::SignalExecution ()
{
  //## begin CCOCommand::SignalExecution%1001060416.body preserve=yes
    // defaults to nothing ...
  //## end CCOCommand::SignalExecution%1001060416.body
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObjectArray * CCOCommand::GetpSyncArray ()
{
  //## begin CCOCommand::GetpSyncArray%3B9288D4006F.get preserve=no
  return m_pSyncArray;
  //## end CCOCommand::GetpSyncArray%3B9288D4006F.get
}

// Additional Declarations
  //## begin CCOCommand%3B927E1D0300.declarations preserve=yes
  //## end CCOCommand%3B927E1D0300.declarations

// Class CCOCommandStartup 

CCOCommandStartup::CCOCommandStartup (ICOStateMachineContext* p_pContext)
  //## begin CCOCommandStartup::CCOCommandStartup%1034329201.hasinit preserve=no
  //## end CCOCommandStartup::CCOCommandStartup%1034329201.hasinit
  //## begin CCOCommandStartup::CCOCommandStartup%1034329201.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CCOCommandStartup::CCOCommandStartup%1034329201.initialization
{
  //## begin CCOCommandStartup::CCOCommandStartup%1034329201.body preserve=yes
  //## end CCOCommandStartup::CCOCommandStartup%1034329201.body
}


CCOCommandStartup::~CCOCommandStartup()
{
  //## begin CCOCommandStartup::~CCOCommandStartup%.body preserve=yes
  //## end CCOCommandStartup::~CCOCommandStartup%.body
}



//## Other Operations (implementation)
bool CCOCommandStartup::Execute (CCOState* p_pCurrentState)
{
  //## begin CCOCommandStartup::Execute%1034329202.body preserve=yes
    p_pCurrentState->Startup(m_pContext);

    return true;
  //## end CCOCommandStartup::Execute%1034329202.body
}

// Additional Declarations
  //## begin CCOCommandStartup%3DA6B291028D.declarations preserve=yes
  //## end CCOCommandStartup%3DA6B291028D.declarations

// Class CCOCommandShutdown 

CCOCommandShutdown::CCOCommandShutdown (ICOStateMachineContext* p_pContext)
  //## begin CCOCommandShutdown::CCOCommandShutdown%1034329203.hasinit preserve=no
  //## end CCOCommandShutdown::CCOCommandShutdown%1034329203.hasinit
  //## begin CCOCommandShutdown::CCOCommandShutdown%1034329203.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CCOCommandShutdown::CCOCommandShutdown%1034329203.initialization
{
  //## begin CCOCommandShutdown::CCOCommandShutdown%1034329203.body preserve=yes
  //## end CCOCommandShutdown::CCOCommandShutdown%1034329203.body
}


CCOCommandShutdown::~CCOCommandShutdown()
{
  //## begin CCOCommandShutdown::~CCOCommandShutdown%.body preserve=yes
  //## end CCOCommandShutdown::~CCOCommandShutdown%.body
}



//## Other Operations (implementation)
bool CCOCommandShutdown::Execute (CCOState* p_pCurrentState)
{
  //## begin CCOCommandShutdown::Execute%1034329204.body preserve=yes
    p_pCurrentState->Shutdown(m_pContext);

    return true;
  //## end CCOCommandShutdown::Execute%1034329204.body
}

// Additional Declarations
  //## begin CCOCommandShutdown%3DA6B2980378.declarations preserve=yes
  //## end CCOCommandShutdown%3DA6B2980378.declarations

// Class CCOCommandCleanupStop 

CCOCommandCleanupStop::CCOCommandCleanupStop (ICOStateMachineContext* p_pContext)
  //## begin CCOCommandCleanupStop::CCOCommandCleanupStop%1034329205.hasinit preserve=no
  //## end CCOCommandCleanupStop::CCOCommandCleanupStop%1034329205.hasinit
  //## begin CCOCommandCleanupStop::CCOCommandCleanupStop%1034329205.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CCOCommandCleanupStop::CCOCommandCleanupStop%1034329205.initialization
{
  //## begin CCOCommandCleanupStop::CCOCommandCleanupStop%1034329205.body preserve=yes
  //## end CCOCommandCleanupStop::CCOCommandCleanupStop%1034329205.body
}


CCOCommandCleanupStop::~CCOCommandCleanupStop()
{
  //## begin CCOCommandCleanupStop::~CCOCommandCleanupStop%.body preserve=yes
  //## end CCOCommandCleanupStop::~CCOCommandCleanupStop%.body
}



//## Other Operations (implementation)
bool CCOCommandCleanupStop::Execute (CCOState* p_pCurrentState)
{
  //## begin CCOCommandCleanupStop::Execute%1034329206.body preserve=yes
    p_pCurrentState->CleanupStop(m_pContext);

    return true;
  //## end CCOCommandCleanupStop::Execute%1034329206.body
}

// Additional Declarations
  //## begin CCOCommandCleanupStop%3DA6B388030A.declarations preserve=yes
  //## end CCOCommandCleanupStop%3DA6B388030A.declarations

// Class CCOCommandCleanupInitialize 

CCOCommandCleanupInitialize::CCOCommandCleanupInitialize (ICOStateMachineContext* p_pContext)
  //## begin CCOCommandCleanupInitialize::CCOCommandCleanupInitialize%1034329207.hasinit preserve=no
  //## end CCOCommandCleanupInitialize::CCOCommandCleanupInitialize%1034329207.hasinit
  //## begin CCOCommandCleanupInitialize::CCOCommandCleanupInitialize%1034329207.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CCOCommandCleanupInitialize::CCOCommandCleanupInitialize%1034329207.initialization
{
  //## begin CCOCommandCleanupInitialize::CCOCommandCleanupInitialize%1034329207.body preserve=yes
  //## end CCOCommandCleanupInitialize::CCOCommandCleanupInitialize%1034329207.body
}


CCOCommandCleanupInitialize::~CCOCommandCleanupInitialize()
{
  //## begin CCOCommandCleanupInitialize::~CCOCommandCleanupInitialize%.body preserve=yes
  //## end CCOCommandCleanupInitialize::~CCOCommandCleanupInitialize%.body
}



//## Other Operations (implementation)
bool CCOCommandCleanupInitialize::Execute (CCOState* p_pCurrentState)
{
  //## begin CCOCommandCleanupInitialize::Execute%1034329208.body preserve=yes
    p_pCurrentState->CleanupInitialize(m_pContext);

    return true;
  //## end CCOCommandCleanupInitialize::Execute%1034329208.body
}

// Additional Declarations
  //## begin CCOCommandCleanupInitialize%3DA6B3900099.declarations preserve=yes
  //## end CCOCommandCleanupInitialize%3DA6B3900099.declarations

// Class CCOCommandTimer 

CCOCommandTimer::CCOCommandTimer (ICOStateMachineContext* p_pContext)
  //## begin CCOCommandTimer::CCOCommandTimer%1053348761.hasinit preserve=no
  //## end CCOCommandTimer::CCOCommandTimer%1053348761.hasinit
  //## begin CCOCommandTimer::CCOCommandTimer%1053348761.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CCOCommandTimer::CCOCommandTimer%1053348761.initialization
{
  //## begin CCOCommandTimer::CCOCommandTimer%1053348761.body preserve=yes
  //## end CCOCommandTimer::CCOCommandTimer%1053348761.body
}


CCOCommandTimer::~CCOCommandTimer()
{
  //## begin CCOCommandTimer::~CCOCommandTimer%.body preserve=yes
  //## end CCOCommandTimer::~CCOCommandTimer%.body
}



//## Other Operations (implementation)
bool CCOCommandTimer::Execute (CCOState* p_pCurrentState)
{
  //## begin CCOCommandTimer::Execute%1053348762.body preserve=yes
    p_pCurrentState->OnTimer(m_pContext);

    return true;
  //## end CCOCommandTimer::Execute%1053348762.body
}

// Additional Declarations
  //## begin CCOCommandTimer%3EC8DB8F012C.declarations preserve=yes
  //## end CCOCommandTimer%3EC8DB8F012C.declarations

// Class CCOCommandConnectionEstablished 

CCOCommandConnectionEstablished::CCOCommandConnectionEstablished (ICOStateMachineContext* p_pContext)
  //## begin CCOCommandConnectionEstablished::CCOCommandConnectionEstablished%1055313957.hasinit preserve=no
  //## end CCOCommandConnectionEstablished::CCOCommandConnectionEstablished%1055313957.hasinit
  //## begin CCOCommandConnectionEstablished::CCOCommandConnectionEstablished%1055313957.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CCOCommandConnectionEstablished::CCOCommandConnectionEstablished%1055313957.initialization
{
  //## begin CCOCommandConnectionEstablished::CCOCommandConnectionEstablished%1055313957.body preserve=yes
  //## end CCOCommandConnectionEstablished::CCOCommandConnectionEstablished%1055313957.body
}


CCOCommandConnectionEstablished::~CCOCommandConnectionEstablished()
{
  //## begin CCOCommandConnectionEstablished::~CCOCommandConnectionEstablished%.body preserve=yes
  //## end CCOCommandConnectionEstablished::~CCOCommandConnectionEstablished%.body
}



//## Other Operations (implementation)
bool CCOCommandConnectionEstablished::Execute (CCOState* p_pCurrentState)
{
  //## begin CCOCommandConnectionEstablished::Execute%1055313958.body preserve=yes
    p_pCurrentState->ConnectionEstablished(m_pContext);
    return true;
  //## end CCOCommandConnectionEstablished::Execute%1055313958.body
}

// Additional Declarations
  //## begin CCOCommandConnectionEstablished%3EE6ECD802D8.declarations preserve=yes
  //## end CCOCommandConnectionEstablished%3EE6ECD802D8.declarations

// Class CCOCommandConnectionLost 

CCOCommandConnectionLost::CCOCommandConnectionLost (ICOStateMachineContext* p_pContext)
  //## begin CCOCommandConnectionLost::CCOCommandConnectionLost%1055313959.hasinit preserve=no
  //## end CCOCommandConnectionLost::CCOCommandConnectionLost%1055313959.hasinit
  //## begin CCOCommandConnectionLost::CCOCommandConnectionLost%1055313959.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CCOCommandConnectionLost::CCOCommandConnectionLost%1055313959.initialization
{
  //## begin CCOCommandConnectionLost::CCOCommandConnectionLost%1055313959.body preserve=yes
  //## end CCOCommandConnectionLost::CCOCommandConnectionLost%1055313959.body
}


CCOCommandConnectionLost::~CCOCommandConnectionLost()
{
  //## begin CCOCommandConnectionLost::~CCOCommandConnectionLost%.body preserve=yes
  //## end CCOCommandConnectionLost::~CCOCommandConnectionLost%.body
}



//## Other Operations (implementation)
bool CCOCommandConnectionLost::Execute (CCOState* p_pCurrentState)
{
  //## begin CCOCommandConnectionLost::Execute%1055313960.body preserve=yes
    p_pCurrentState->ConnectionLost(m_pContext);
    return false;
  //## end CCOCommandConnectionLost::Execute%1055313960.body
}

void CCOCommandConnectionLost::SignalExecution ()
{
  //## begin CCOCommandConnectionLost::SignalExecution%1056695973.body preserve=yes
    m_pSyncArray->SignalCompletion();
  //## end CCOCommandConnectionLost::SignalExecution%1056695973.body
}

// Additional Declarations
  //## begin CCOCommandConnectionLost%3EE6ECED0317.declarations preserve=yes
  //## end CCOCommandConnectionLost%3EE6ECED0317.declarations

//## begin module%3B8EA57B024D.epilog preserve=yes
//## end module%3B8EA57B024D.epilog
