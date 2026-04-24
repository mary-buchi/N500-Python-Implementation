//## begin module%3DE5EDF203AE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDF203AE.cm

//## begin module%3DE5EDF203AE.cp preserve=no
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
//## end module%3DE5EDF203AE.cp

//## Module: EBTCcomd%3DE5EDF203AE; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EDF203AE.additionalIncludes preserve=no
//## end module%3DE5EDF203AE.additionalIncludes

//## begin module%3DE5EDF203AE.includes preserve=yes
//## end module%3DE5EDF203AE.includes

// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBTCcomd
#include "EBTCcomd.h"
// EBTCstat
#include "EBTCstat.h"


//## begin module%3DE5EDF203AE.declarations preserve=no
//## end module%3DE5EDF203AE.declarations

//## begin module%3DE5EDF203AE.additionalDeclarations preserve=yes
//## end module%3DE5EDF203AE.additionalDeclarations


// Class CTCCommand 

CTCCommand::CTCCommand (ICOStateMachineContext* p_pContext)
  //## begin CTCCommand::CTCCommand%1046858370.hasinit preserve=no
  //## end CTCCommand::CTCCommand%1046858370.hasinit
  //## begin CTCCommand::CTCCommand%1046858370.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CTCCommand::CTCCommand%1046858370.initialization
{
  //## begin CTCCommand::CTCCommand%1046858370.body preserve=yes
  //## end CTCCommand::CTCCommand%1046858370.body
}


CTCCommand::~CTCCommand()
{
  //## begin CTCCommand::~CTCCommand%.body preserve=yes
  //## end CTCCommand::~CTCCommand%.body
}



//## Other Operations (implementation)
bool CTCCommand::Execute (CCOState* p_pCurrentState)
{
  //## begin CTCCommand::Execute%1038899360.body preserve=yes
    CTCState* l_pState = dynamic_cast<CTCState*>(p_pCurrentState);
    ASSERT(l_pState != NULL);

    return Execute(l_pState);
  //## end CTCCommand::Execute%1038899360.body
}

// Additional Declarations
  //## begin CTCCommand%3DECB4BE03BC.declarations preserve=yes
  //## end CTCCommand%3DECB4BE03BC.declarations

// Class CTCCommandStart 

CTCCommandStart::CTCCommandStart (ICOStateMachineContext* p_pContext)
  //## begin CTCCommandStart::CTCCommandStart%1039429738.hasinit preserve=no
  //## end CTCCommandStart::CTCCommandStart%1039429738.hasinit
  //## begin CTCCommandStart::CTCCommandStart%1039429738.initialization preserve=yes
  : CTCCommand(p_pContext)
  //## end CTCCommandStart::CTCCommandStart%1039429738.initialization
{
  //## begin CTCCommandStart::CTCCommandStart%1039429738.body preserve=yes
  //## end CTCCommandStart::CTCCommandStart%1039429738.body
}


CTCCommandStart::~CTCCommandStart()
{
  //## begin CTCCommandStart::~CTCCommandStart%.body preserve=yes
  //## end CTCCommandStart::~CTCCommandStart%.body
}



//## Other Operations (implementation)
void CTCCommandStart::CreateSyncObjects ()
{
  //## begin CTCCommandStart::CreateSyncObjects%1039429739.body preserve=yes
    CTCCommand::CreateSyncObjects();
    m_pSyncArray->Add(new CCOSyncObject(), false);
  //## end CTCCommandStart::CreateSyncObjects%1039429739.body
}

void CTCCommandStart::SignalExecution ()
{
  //## begin CTCCommandStart::SignalExecution%1046858369.body preserve=yes
	GetpSyncArray()->GetAt(0)->SignalCompletion();
  //## end CTCCommandStart::SignalExecution%1046858369.body
}

bool CTCCommandStart::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandStart::Execute%1039429740.body preserve=yes
    p_pCurrentState->Start(m_pContext, m_pSyncArray->GetAt(1));

    return false;
  //## end CTCCommandStart::Execute%1039429740.body
}

// Additional Declarations
  //## begin CTCCommandStart%3DF48BA7002A.declarations preserve=yes
  //## end CTCCommandStart%3DF48BA7002A.declarations

// Class CTCCommandStop 

CTCCommandStop::CTCCommandStop (ICOStateMachineContext* p_pContext)
  //## begin CTCCommandStop::CTCCommandStop%1039429742.hasinit preserve=no
  //## end CTCCommandStop::CTCCommandStop%1039429742.hasinit
  //## begin CTCCommandStop::CTCCommandStop%1039429742.initialization preserve=yes
  : CTCCommand(p_pContext)
  //## end CTCCommandStop::CTCCommandStop%1039429742.initialization
{
  //## begin CTCCommandStop::CTCCommandStop%1039429742.body preserve=yes
  //## end CTCCommandStop::CTCCommandStop%1039429742.body
}


CTCCommandStop::~CTCCommandStop()
{
  //## begin CTCCommandStop::~CTCCommandStop%.body preserve=yes
  //## end CTCCommandStop::~CTCCommandStop%.body
}



//## Other Operations (implementation)
bool CTCCommandStop::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandStop::Execute%1039429743.body preserve=yes
    p_pCurrentState->Stop(m_pContext);

    return true;
  //## end CTCCommandStop::Execute%1039429743.body
}

// Additional Declarations
  //## begin CTCCommandStop%3DF497D60318.declarations preserve=yes
  //## end CTCCommandStop%3DF497D60318.declarations

// Class CTCCommandSetProfile 


CTCCommandSetProfile::CTCCommandSetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile)
  //## begin CTCCommandSetProfile::CTCCommandSetProfile%1039429744.hasinit preserve=no
      : m_pProfile(p_pProfile)
  //## end CTCCommandSetProfile::CTCCommandSetProfile%1039429744.hasinit
  //## begin CTCCommandSetProfile::CTCCommandSetProfile%1039429744.initialization preserve=yes
  , CTCCommand(p_pContext)
  //## end CTCCommandSetProfile::CTCCommandSetProfile%1039429744.initialization
{
  //## begin CTCCommandSetProfile::CTCCommandSetProfile%1039429744.body preserve=yes
	m_pProfile->AddRef();
  //## end CTCCommandSetProfile::CTCCommandSetProfile%1039429744.body
}


CTCCommandSetProfile::~CTCCommandSetProfile()
{
  //## begin CTCCommandSetProfile::~CTCCommandSetProfile%.body preserve=yes
	if (m_pProfile)
		m_pProfile->ReleaseRef();
	m_pProfile = NULL;
  //## end CTCCommandSetProfile::~CTCCommandSetProfile%.body
}



//## Other Operations (implementation)
bool CTCCommandSetProfile::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandSetProfile::Execute%1039429745.body preserve=yes
  p_pCurrentState->SetProfile(m_pContext, m_pProfile);

  return true;
  //## end CTCCommandSetProfile::Execute%1039429745.body
}

// Additional Declarations
  //## begin CTCCommandSetProfile%3DF498E80068.declarations preserve=yes
  //## end CTCCommandSetProfile%3DF498E80068.declarations

// Class CTCCommandGetTemperature 

CTCCommandGetTemperature::CTCCommandGetTemperature (ICOStateMachineContext* p_pContext)
  //## begin CTCCommandGetTemperature::CTCCommandGetTemperature%1039429748.hasinit preserve=no
  //## end CTCCommandGetTemperature::CTCCommandGetTemperature%1039429748.hasinit
  //## begin CTCCommandGetTemperature::CTCCommandGetTemperature%1039429748.initialization preserve=yes
  : CTCCommand(p_pContext)
  //## end CTCCommandGetTemperature::CTCCommandGetTemperature%1039429748.initialization
{
  //## begin CTCCommandGetTemperature::CTCCommandGetTemperature%1039429748.body preserve=yes
  //## end CTCCommandGetTemperature::CTCCommandGetTemperature%1039429748.body
}


CTCCommandGetTemperature::~CTCCommandGetTemperature()
{
  //## begin CTCCommandGetTemperature::~CTCCommandGetTemperature%.body preserve=yes
  //## end CTCCommandGetTemperature::~CTCCommandGetTemperature%.body
}



//## Other Operations (implementation)
void CTCCommandGetTemperature::CreateSyncObjects ()
{
  //## begin CTCCommandGetTemperature::CreateSyncObjects%1039429749.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectInt(0), false);
  //## end CTCCommandGetTemperature::CreateSyncObjects%1039429749.body
}

bool CTCCommandGetTemperature::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandGetTemperature::Execute%1039429750.body preserve=yes
    CCOSyncObjectInt* pClientSyncObj = dynamic_cast<CCOSyncObjectInt*>(m_pSyncArray->GetAt(0));
    ASSERT(pClientSyncObj != NULL);

    // execute command
    p_pCurrentState->GetTemperature(m_pContext, pClientSyncObj);

    return false;
  //## end CTCCommandGetTemperature::Execute%1039429750.body
}

// Additional Declarations
  //## begin CTCCommandGetTemperature%3DF49B3F00E5.declarations preserve=yes
  //## end CTCCommandGetTemperature%3DF49B3F00E5.declarations

// Class CTCCommandSetConfiguration 


CTCCommandSetConfiguration::CTCCommandSetConfiguration (ICOStateMachineContext* p_pContext, CPITemperatureControlConfig* p_pConfig)
  //## begin CTCCommandSetConfiguration::CTCCommandSetConfiguration%1046858371.hasinit preserve=no
      : m_pConfig(p_pConfig)
  //## end CTCCommandSetConfiguration::CTCCommandSetConfiguration%1046858371.hasinit
  //## begin CTCCommandSetConfiguration::CTCCommandSetConfiguration%1046858371.initialization preserve=yes
  , CTCCommand(p_pContext)
  //## end CTCCommandSetConfiguration::CTCCommandSetConfiguration%1046858371.initialization
{
  //## begin CTCCommandSetConfiguration::CTCCommandSetConfiguration%1046858371.body preserve=yes
	ASSERT(m_pConfig != NULL);
	m_pConfig->AddRef();
  //## end CTCCommandSetConfiguration::CTCCommandSetConfiguration%1046858371.body
}


CTCCommandSetConfiguration::~CTCCommandSetConfiguration()
{
  //## begin CTCCommandSetConfiguration::~CTCCommandSetConfiguration%.body preserve=yes
	if (m_pConfig)
		m_pConfig->ReleaseRef();
	m_pConfig = NULL;
  //## end CTCCommandSetConfiguration::~CTCCommandSetConfiguration%.body
}



//## Other Operations (implementation)
bool CTCCommandSetConfiguration::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandSetConfiguration::Execute%1046858372.body preserve=yes
  p_pCurrentState->SetConfiguration(m_pContext, m_pConfig);
 
  return true;
  //## end CTCCommandSetConfiguration::Execute%1046858372.body
}

// Additional Declarations
  //## begin CTCCommandSetConfiguration%3E6626190031.declarations preserve=yes
  //## end CTCCommandSetConfiguration%3E6626190031.declarations

// Class CTCCommandConnectionEstablished 

CTCCommandConnectionEstablished::CTCCommandConnectionEstablished (ICOStateMachineContext* p_pContext)
  //## begin CTCCommandConnectionEstablished::CTCCommandConnectionEstablished%1055428406.hasinit preserve=no
  //## end CTCCommandConnectionEstablished::CTCCommandConnectionEstablished%1055428406.hasinit
  //## begin CTCCommandConnectionEstablished::CTCCommandConnectionEstablished%1055428406.initialization preserve=yes
  : CTCCommand(p_pContext)
  //## end CTCCommandConnectionEstablished::CTCCommandConnectionEstablished%1055428406.initialization
{
  //## begin CTCCommandConnectionEstablished::CTCCommandConnectionEstablished%1055428406.body preserve=yes
  //## end CTCCommandConnectionEstablished::CTCCommandConnectionEstablished%1055428406.body
}


CTCCommandConnectionEstablished::~CTCCommandConnectionEstablished()
{
  //## begin CTCCommandConnectionEstablished::~CTCCommandConnectionEstablished%.body preserve=yes
  //## end CTCCommandConnectionEstablished::~CTCCommandConnectionEstablished%.body
}



//## Other Operations (implementation)
bool CTCCommandConnectionEstablished::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandConnectionEstablished::Execute%1055428407.body preserve=yes
	p_pCurrentState->ConnectionEstablished(m_pContext);
	return true;
  //## end CTCCommandConnectionEstablished::Execute%1055428407.body
}

// Additional Declarations
  //## begin CTCCommandConnectionEstablished%3EE89B3E0117.declarations preserve=yes
  //## end CTCCommandConnectionEstablished%3EE89B3E0117.declarations

// Class CTCCommandConnectionLost 

CTCCommandConnectionLost::CTCCommandConnectionLost (ICOStateMachineContext* p_pContext)
  //## begin CTCCommandConnectionLost::CTCCommandConnectionLost%1055428408.hasinit preserve=no
  //## end CTCCommandConnectionLost::CTCCommandConnectionLost%1055428408.hasinit
  //## begin CTCCommandConnectionLost::CTCCommandConnectionLost%1055428408.initialization preserve=yes
  : CTCCommand(p_pContext)
  //## end CTCCommandConnectionLost::CTCCommandConnectionLost%1055428408.initialization
{
  //## begin CTCCommandConnectionLost::CTCCommandConnectionLost%1055428408.body preserve=yes
  //## end CTCCommandConnectionLost::CTCCommandConnectionLost%1055428408.body
}


CTCCommandConnectionLost::~CTCCommandConnectionLost()
{
  //## begin CTCCommandConnectionLost::~CTCCommandConnectionLost%.body preserve=yes
  //## end CTCCommandConnectionLost::~CTCCommandConnectionLost%.body
}



//## Other Operations (implementation)
bool CTCCommandConnectionLost::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandConnectionLost::Execute%1055428409.body preserve=yes
	p_pCurrentState->ConnectionLost(m_pContext);
	return true;
  //## end CTCCommandConnectionLost::Execute%1055428409.body
}

// Additional Declarations
  //## begin CTCCommandConnectionLost%3EE89B4002DC.declarations preserve=yes
  //## end CTCCommandConnectionLost%3EE89B4002DC.declarations

// Class CTCCommandCellUndocked 

CTCCommandCellUndocked::CTCCommandCellUndocked (ICOStateMachineContext* p_pContext)
  //## begin CTCCommandCellUndocked::CTCCommandCellUndocked%1216975783.hasinit preserve=no
  //## end CTCCommandCellUndocked::CTCCommandCellUndocked%1216975783.hasinit
  //## begin CTCCommandCellUndocked::CTCCommandCellUndocked%1216975783.initialization preserve=yes
  : CTCCommand(p_pContext)
  //## end CTCCommandCellUndocked::CTCCommandCellUndocked%1216975783.initialization
{
  //## begin CTCCommandCellUndocked::CTCCommandCellUndocked%1216975783.body preserve=yes
  //## end CTCCommandCellUndocked::CTCCommandCellUndocked%1216975783.body
}


CTCCommandCellUndocked::~CTCCommandCellUndocked()
{
  //## begin CTCCommandCellUndocked::~CTCCommandCellUndocked%.body preserve=yes
  //## end CTCCommandCellUndocked::~CTCCommandCellUndocked%.body
}



//## Other Operations (implementation)
bool CTCCommandCellUndocked::Execute (CTCState* p_pCurrentState)
{
  //## begin CTCCommandCellUndocked::Execute%1216975784.body preserve=yes
	p_pCurrentState->CellUndocked(m_pContext);
	return true;
  //## end CTCCommandCellUndocked::Execute%1216975784.body
}

// Additional Declarations
  //## begin CTCCommandCellUndocked%488999F80064.declarations preserve=yes
  //## end CTCCommandCellUndocked%488999F80064.declarations

//## begin module%3DE5EDF203AE.epilog preserve=yes
//## end module%3DE5EDF203AE.epilog
