//## begin module%3EED769F0369.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0369.cm

//## begin module%3EED769F0369.cp preserve=no
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
//## end module%3EED769F0369.cp

//## Module: EBPCcomd%3EED769F0369; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F0369.additionalIncludes preserve=no
//## end module%3EED769F0369.additionalIncludes

//## begin module%3EED769F0369.includes preserve=yes
//## end module%3EED769F0369.includes

// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBPCcomd
#include "EBPCcomd.h"
// EBPCstat
#include "EBPCstat.h"


//## begin module%3EED769F0369.declarations preserve=no
//## end module%3EED769F0369.declarations

//## begin module%3EED769F0369.additionalDeclarations preserve=yes
//## end module%3EED769F0369.additionalDeclarations


// Class CPCCommand 

CPCCommand::CPCCommand (ICOStateMachineContext* p_pContext)
  //## begin CPCCommand::CPCCommand%1046858370.hasinit preserve=no
  //## end CPCCommand::CPCCommand%1046858370.hasinit
  //## begin CPCCommand::CPCCommand%1046858370.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CPCCommand::CPCCommand%1046858370.initialization
{
  //## begin CPCCommand::CPCCommand%1046858370.body preserve=yes
  //## end CPCCommand::CPCCommand%1046858370.body
}


CPCCommand::~CPCCommand()
{
  //## begin CPCCommand::~CPCCommand%.body preserve=yes
  //## end CPCCommand::~CPCCommand%.body
}



//## Other Operations (implementation)
bool CPCCommand::Execute (CCOState* p_pCurrentState)
{
  //## begin CPCCommand::Execute%1038899360.body preserve=yes
    CPCState* l_pState = dynamic_cast<CPCState*>(p_pCurrentState);
    ASSERT(l_pState != NULL);
    return Execute(l_pState);
  //## end CPCCommand::Execute%1038899360.body
}

// Additional Declarations
  //## begin CPCCommand%3EED76CC063C.declarations preserve=yes
  //## end CPCCommand%3EED76CC063C.declarations

// Class CPCCommandStart 

CPCCommandStart::CPCCommandStart (ICOStateMachineContext* p_pContext)
  //## begin CPCCommandStart::CPCCommandStart%1039429738.hasinit preserve=no
  //## end CPCCommandStart::CPCCommandStart%1039429738.hasinit
  //## begin CPCCommandStart::CPCCommandStart%1039429738.initialization preserve=yes
  : CPCCommand(p_pContext)
  //## end CPCCommandStart::CPCCommandStart%1039429738.initialization
{
  //## begin CPCCommandStart::CPCCommandStart%1039429738.body preserve=yes
  //## end CPCCommandStart::CPCCommandStart%1039429738.body
}


CPCCommandStart::~CPCCommandStart()
{
  //## begin CPCCommandStart::~CPCCommandStart%.body preserve=yes
  //## end CPCCommandStart::~CPCCommandStart%.body
}



//## Other Operations (implementation)
void CPCCommandStart::CreateSyncObjects ()
{
  //## begin CPCCommandStart::CreateSyncObjects%1039429739.body preserve=yes
    CPCCommand::CreateSyncObjects();
    m_pSyncArray->Add(new CCOSyncObjectInt(0), false);
  //## end CPCCommandStart::CreateSyncObjects%1039429739.body
}

void CPCCommandStart::SignalExecution ()
{
  //## begin CPCCommandStart::SignalExecution%1046858369.body preserve=yes
	// GetpSyncArray()->GetAt(0)->SignalCompletion();
  //## end CPCCommandStart::SignalExecution%1046858369.body
}

bool CPCCommandStart::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandStart::Execute%1039429740.body preserve=yes
    p_pCurrentState->Start(m_pContext, GetpSyncArray()->GetAt(0));
    return false;
  //## end CPCCommandStart::Execute%1039429740.body
}

// Additional Declarations
  //## begin CPCCommandStart%3EED76CC064F.declarations preserve=yes
  //## end CPCCommandStart%3EED76CC064F.declarations

// Class CPCCommandStop 

CPCCommandStop::CPCCommandStop (ICOStateMachineContext* p_pContext)
  //## begin CPCCommandStop::CPCCommandStop%1039429742.hasinit preserve=no
  //## end CPCCommandStop::CPCCommandStop%1039429742.hasinit
  //## begin CPCCommandStop::CPCCommandStop%1039429742.initialization preserve=yes
  : CPCCommand(p_pContext)
  //## end CPCCommandStop::CPCCommandStop%1039429742.initialization
{
  //## begin CPCCommandStop::CPCCommandStop%1039429742.body preserve=yes
  //## end CPCCommandStop::CPCCommandStop%1039429742.body
}


CPCCommandStop::~CPCCommandStop()
{
  //## begin CPCCommandStop::~CPCCommandStop%.body preserve=yes
  //## end CPCCommandStop::~CPCCommandStop%.body
}



//## Other Operations (implementation)
bool CPCCommandStop::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandStop::Execute%1039429743.body preserve=yes
    p_pCurrentState->Stop(m_pContext);
    return true;
  //## end CPCCommandStop::Execute%1039429743.body
}

// Additional Declarations
  //## begin CPCCommandStop%3EED76CC0663.declarations preserve=yes
  //## end CPCCommandStop%3EED76CC0663.declarations

// Class CPCCommandSetProfile 


CPCCommandSetProfile::CPCCommandSetProfile (ICOStateMachineContext* p_pContext, CPIPowerControlProfile* p_pProfile)
  //## begin CPCCommandSetProfile::CPCCommandSetProfile%1039429744.hasinit preserve=no
      : m_pProfile(p_pProfile)
  //## end CPCCommandSetProfile::CPCCommandSetProfile%1039429744.hasinit
  //## begin CPCCommandSetProfile::CPCCommandSetProfile%1039429744.initialization preserve=yes
  , CPCCommand(p_pContext)
  //## end CPCCommandSetProfile::CPCCommandSetProfile%1039429744.initialization
{
  //## begin CPCCommandSetProfile::CPCCommandSetProfile%1039429744.body preserve=yes
	m_pProfile->AddRef();
  //## end CPCCommandSetProfile::CPCCommandSetProfile%1039429744.body
}


CPCCommandSetProfile::~CPCCommandSetProfile()
{
  //## begin CPCCommandSetProfile::~CPCCommandSetProfile%.body preserve=yes
	if (m_pProfile)
		m_pProfile->ReleaseRef();
	m_pProfile = NULL;
  //## end CPCCommandSetProfile::~CPCCommandSetProfile%.body
}



//## Other Operations (implementation)
bool CPCCommandSetProfile::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandSetProfile::Execute%1039429745.body preserve=yes
  p_pCurrentState->SetProfile(m_pContext, m_pProfile);
  return true;
  //## end CPCCommandSetProfile::Execute%1039429745.body
}

// Additional Declarations
  //## begin CPCCommandSetProfile%3EED76CC0670.declarations preserve=yes
  //## end CPCCommandSetProfile%3EED76CC0670.declarations

// Class CPCCommandSetConfiguration 


CPCCommandSetConfiguration::CPCCommandSetConfiguration (ICOStateMachineContext* p_pContext, CPIPowerControlConfig* p_pConfig)
  //## begin CPCCommandSetConfiguration::CPCCommandSetConfiguration%1046858371.hasinit preserve=no
      : m_pConfig(p_pConfig)
  //## end CPCCommandSetConfiguration::CPCCommandSetConfiguration%1046858371.hasinit
  //## begin CPCCommandSetConfiguration::CPCCommandSetConfiguration%1046858371.initialization preserve=yes
  , CPCCommand(p_pContext)
  //## end CPCCommandSetConfiguration::CPCCommandSetConfiguration%1046858371.initialization
{
  //## begin CPCCommandSetConfiguration::CPCCommandSetConfiguration%1046858371.body preserve=yes
	ASSERT(m_pConfig != NULL);
	m_pConfig->AddRef();
  //## end CPCCommandSetConfiguration::CPCCommandSetConfiguration%1046858371.body
}


CPCCommandSetConfiguration::~CPCCommandSetConfiguration()
{
  //## begin CPCCommandSetConfiguration::~CPCCommandSetConfiguration%.body preserve=yes
	if (m_pConfig)
		m_pConfig->ReleaseRef();
	m_pConfig = NULL;
  //## end CPCCommandSetConfiguration::~CPCCommandSetConfiguration%.body
}



//## Other Operations (implementation)
bool CPCCommandSetConfiguration::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandSetConfiguration::Execute%1046858372.body preserve=yes
  p_pCurrentState->SetConfiguration(m_pContext, m_pConfig);
  return true;
  //## end CPCCommandSetConfiguration::Execute%1046858372.body
}

// Additional Declarations
  //## begin CPCCommandSetConfiguration%3EED76CC0796.declarations preserve=yes
  //## end CPCCommandSetConfiguration%3EED76CC0796.declarations

// Class CPCCommandConnectionEstablished 

CPCCommandConnectionEstablished::CPCCommandConnectionEstablished (ICOStateMachineContext* p_pContext)
  //## begin CPCCommandConnectionEstablished::CPCCommandConnectionEstablished%1055428406.hasinit preserve=no
  //## end CPCCommandConnectionEstablished::CPCCommandConnectionEstablished%1055428406.hasinit
  //## begin CPCCommandConnectionEstablished::CPCCommandConnectionEstablished%1055428406.initialization preserve=yes
  : CPCCommand(p_pContext)
  //## end CPCCommandConnectionEstablished::CPCCommandConnectionEstablished%1055428406.initialization
{
  //## begin CPCCommandConnectionEstablished::CPCCommandConnectionEstablished%1055428406.body preserve=yes
  //## end CPCCommandConnectionEstablished::CPCCommandConnectionEstablished%1055428406.body
}


CPCCommandConnectionEstablished::~CPCCommandConnectionEstablished()
{
  //## begin CPCCommandConnectionEstablished::~CPCCommandConnectionEstablished%.body preserve=yes
  //## end CPCCommandConnectionEstablished::~CPCCommandConnectionEstablished%.body
}



//## Other Operations (implementation)
bool CPCCommandConnectionEstablished::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandConnectionEstablished::Execute%1055428407.body preserve=yes
	p_pCurrentState->ConnectionEstablished(m_pContext);
	return true;
  //## end CPCCommandConnectionEstablished::Execute%1055428407.body
}

// Additional Declarations
  //## begin CPCCommandConnectionEstablished%3EED76CC07D3.declarations preserve=yes
  //## end CPCCommandConnectionEstablished%3EED76CC07D3.declarations

// Class CPCCommandConnectionLost 

CPCCommandConnectionLost::CPCCommandConnectionLost (ICOStateMachineContext* p_pContext)
  //## begin CPCCommandConnectionLost::CPCCommandConnectionLost%1055428408.hasinit preserve=no
  //## end CPCCommandConnectionLost::CPCCommandConnectionLost%1055428408.hasinit
  //## begin CPCCommandConnectionLost::CPCCommandConnectionLost%1055428408.initialization preserve=yes
  : CPCCommand(p_pContext)
  //## end CPCCommandConnectionLost::CPCCommandConnectionLost%1055428408.initialization
{
  //## begin CPCCommandConnectionLost::CPCCommandConnectionLost%1055428408.body preserve=yes
  //## end CPCCommandConnectionLost::CPCCommandConnectionLost%1055428408.body
}


CPCCommandConnectionLost::~CPCCommandConnectionLost()
{
  //## begin CPCCommandConnectionLost::~CPCCommandConnectionLost%.body preserve=yes
  //## end CPCCommandConnectionLost::~CPCCommandConnectionLost%.body
}



//## Other Operations (implementation)
bool CPCCommandConnectionLost::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandConnectionLost::Execute%1055428409.body preserve=yes
	p_pCurrentState->ConnectionLost(m_pContext);
	return true;
  //## end CPCCommandConnectionLost::Execute%1055428409.body
}

// Additional Declarations
  //## begin CPCCommandConnectionLost%3EED76CC07E0.declarations preserve=yes
  //## end CPCCommandConnectionLost%3EED76CC07E0.declarations

// Class CPCCommandPowerOff 

CPCCommandPowerOff::CPCCommandPowerOff (ICOStateMachineContext* p_pContext)
  //## begin CPCCommandPowerOff::CPCCommandPowerOff%1076339205.hasinit preserve=no
  //## end CPCCommandPowerOff::CPCCommandPowerOff%1076339205.hasinit
  //## begin CPCCommandPowerOff::CPCCommandPowerOff%1076339205.initialization preserve=yes
    : CPCCommand(p_pContext)
  //## end CPCCommandPowerOff::CPCCommandPowerOff%1076339205.initialization
{
  //## begin CPCCommandPowerOff::CPCCommandPowerOff%1076339205.body preserve=yes
  //## end CPCCommandPowerOff::CPCCommandPowerOff%1076339205.body
}


CPCCommandPowerOff::~CPCCommandPowerOff()
{
  //## begin CPCCommandPowerOff::~CPCCommandPowerOff%.body preserve=yes
  //## end CPCCommandPowerOff::~CPCCommandPowerOff%.body
}



//## Other Operations (implementation)
bool CPCCommandPowerOff::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandPowerOff::Execute%1076339206.body preserve=yes
	p_pCurrentState->PowerOff(m_pContext);
	return true;
  //## end CPCCommandPowerOff::Execute%1076339206.body
}

// Additional Declarations
  //## begin CPCCommandPowerOff%4027B5E00016.declarations preserve=yes
  //## end CPCCommandPowerOff%4027B5E00016.declarations

// Class CPCCommandPowerOn 

CPCCommandPowerOn::CPCCommandPowerOn (ICOStateMachineContext* p_pContext)
  //## begin CPCCommandPowerOn::CPCCommandPowerOn%1076339203.hasinit preserve=no
  //## end CPCCommandPowerOn::CPCCommandPowerOn%1076339203.hasinit
  //## begin CPCCommandPowerOn::CPCCommandPowerOn%1076339203.initialization preserve=yes
    : CPCCommand(p_pContext)
  //## end CPCCommandPowerOn::CPCCommandPowerOn%1076339203.initialization
{
  //## begin CPCCommandPowerOn::CPCCommandPowerOn%1076339203.body preserve=yes
  //## end CPCCommandPowerOn::CPCCommandPowerOn%1076339203.body
}


CPCCommandPowerOn::~CPCCommandPowerOn()
{
  //## begin CPCCommandPowerOn::~CPCCommandPowerOn%.body preserve=yes
  //## end CPCCommandPowerOn::~CPCCommandPowerOn%.body
}



//## Other Operations (implementation)
bool CPCCommandPowerOn::Execute (CPCState* p_pCurrentState)
{
  //## begin CPCCommandPowerOn::Execute%1076339204.body preserve=yes
	p_pCurrentState->PowerOn(m_pContext);
	return true;
  //## end CPCCommandPowerOn::Execute%1076339204.body
}

// Additional Declarations
  //## begin CPCCommandPowerOn%4027B5FF0314.declarations preserve=yes
  //## end CPCCommandPowerOn%4027B5FF0314.declarations

//## begin module%3EED769F0369.epilog preserve=yes
//## end module%3EED769F0369.epilog
