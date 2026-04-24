//## begin module%3DD39E9A0397.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD39E9A0397.cm

//## begin module%3DD39E9A0397.cp preserve=no
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
//## end module%3DD39E9A0397.cp

//## Module: EBWCcomd%3DD39E9A0397; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD39E9A0397.additionalIncludes preserve=no
//## end module%3DD39E9A0397.additionalIncludes

//## begin module%3DD39E9A0397.includes preserve=yes
//## end module%3DD39E9A0397.includes

// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBWCcomd
#include "EBWCcomd.h"
// EBWCstat
#include "EBWCstat.h"


//## begin module%3DD39E9A0397.declarations preserve=no
//## end module%3DD39E9A0397.declarations

//## begin module%3DD39E9A0397.additionalDeclarations preserve=yes
//## end module%3DD39E9A0397.additionalDeclarations


// Class CWCCommandSetConfiguration 


CWCCommandSetConfiguration::CWCCommandSetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig)
  //## begin CWCCommandSetConfiguration::CWCCommandSetConfiguration%1038209085.hasinit preserve=no
      : m_pConfig(p_pConfig)
  //## end CWCCommandSetConfiguration::CWCCommandSetConfiguration%1038209085.hasinit
  //## begin CWCCommandSetConfiguration::CWCCommandSetConfiguration%1038209085.initialization preserve=yes
   , CWCCommand(p_pContext)
  //## end CWCCommandSetConfiguration::CWCCommandSetConfiguration%1038209085.initialization
{
  //## begin CWCCommandSetConfiguration::CWCCommandSetConfiguration%1038209085.body preserve=yes
  m_pConfig->AddRef();
  //## end CWCCommandSetConfiguration::CWCCommandSetConfiguration%1038209085.body
}


CWCCommandSetConfiguration::~CWCCommandSetConfiguration()
{
  //## begin CWCCommandSetConfiguration::~CWCCommandSetConfiguration%.body preserve=yes
  if (m_pConfig)
    m_pConfig->ReleaseRef();
  m_pConfig = NULL;
  //## end CWCCommandSetConfiguration::~CWCCommandSetConfiguration%.body
}



//## Other Operations (implementation)
bool CWCCommandSetConfiguration::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandSetConfiguration::Execute%1038209086.body preserve=yes
  p_pCurrentState->SetConfiguration(m_pContext, m_pConfig);

  return true;
  //## end CWCCommandSetConfiguration::Execute%1038209086.body
}

// Additional Declarations
  //## begin CWCCommandSetConfiguration%3DE1D0A803A0.declarations preserve=yes
  //## end CWCCommandSetConfiguration%3DE1D0A803A0.declarations

// Class CWCCommandStop 

CWCCommandStop::CWCCommandStop (ICOStateMachineContext* p_pContext)
  //## begin CWCCommandStop::CWCCommandStop%1038209087.hasinit preserve=no
  //## end CWCCommandStop::CWCCommandStop%1038209087.hasinit
  //## begin CWCCommandStop::CWCCommandStop%1038209087.initialization preserve=yes
   : CWCCommand(p_pContext)
  //## end CWCCommandStop::CWCCommandStop%1038209087.initialization
{
  //## begin CWCCommandStop::CWCCommandStop%1038209087.body preserve=yes
  //## end CWCCommandStop::CWCCommandStop%1038209087.body
}


CWCCommandStop::~CWCCommandStop()
{
  //## begin CWCCommandStop::~CWCCommandStop%.body preserve=yes
  //## end CWCCommandStop::~CWCCommandStop%.body
}



//## Other Operations (implementation)
bool CWCCommandStop::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandStop::Execute%1038209088.body preserve=yes
  p_pCurrentState->Stop(m_pContext);

  return true;
  //## end CWCCommandStop::Execute%1038209088.body
}

// Additional Declarations
  //## begin CWCCommandStop%3DE1D1510332.declarations preserve=yes
  //## end CWCCommandStop%3DE1D1510332.declarations

// Class CWCCommand 

CWCCommand::CWCCommand (ICOStateMachineContext* p_pContext)
  //## begin CWCCommand::CWCCommand%1038209093.hasinit preserve=no
  //## end CWCCommand::CWCCommand%1038209093.hasinit
  //## begin CWCCommand::CWCCommand%1038209093.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CWCCommand::CWCCommand%1038209093.initialization
{
  //## begin CWCCommand::CWCCommand%1038209093.body preserve=yes
  //## end CWCCommand::CWCCommand%1038209093.body
}


CWCCommand::~CWCCommand()
{
  //## begin CWCCommand::~CWCCommand%.body preserve=yes
  //## end CWCCommand::~CWCCommand%.body
}



//## Other Operations (implementation)
bool CWCCommand::Execute (CCOState* p_pCurrentState)
{
  //## begin CWCCommand::Execute%1038209094.body preserve=yes
    CWCState* l_pState = dynamic_cast<CWCState*>(p_pCurrentState);
    ASSERT(l_pState != NULL);

    return Execute(l_pState);
  //## end CWCCommand::Execute%1038209094.body
}

// Additional Declarations
  //## begin CWCCommand%3DE1D3920083.declarations preserve=yes
  //## end CWCCommand%3DE1D3920083.declarations

// Class CWCCommandReferencing 

CWCCommandReferencing::CWCCommandReferencing (ICOStateMachineContext* p_pContext)
  //## begin CWCCommandReferencing::CWCCommandReferencing%1038209091.hasinit preserve=no
  //## end CWCCommandReferencing::CWCCommandReferencing%1038209091.hasinit
  //## begin CWCCommandReferencing::CWCCommandReferencing%1038209091.initialization preserve=yes
   : CWCCommand(p_pContext)
  //## end CWCCommandReferencing::CWCCommandReferencing%1038209091.initialization
{
  //## begin CWCCommandReferencing::CWCCommandReferencing%1038209091.body preserve=yes
  //## end CWCCommandReferencing::CWCCommandReferencing%1038209091.body
}


CWCCommandReferencing::~CWCCommandReferencing()
{
  //## begin CWCCommandReferencing::~CWCCommandReferencing%.body preserve=yes
  //## end CWCCommandReferencing::~CWCCommandReferencing%.body
}



//## Other Operations (implementation)
bool CWCCommandReferencing::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandReferencing::Execute%1038209092.body preserve=yes
  p_pCurrentState->Referencing(m_pContext);

  return true;
  //## end CWCCommandReferencing::Execute%1038209092.body
}

// Additional Declarations
  //## begin CWCCommandReferencing%3DE1D4C003A0.declarations preserve=yes
  //## end CWCCommandReferencing%3DE1D4C003A0.declarations

// Class CWCCommandStart 

CWCCommandStart::CWCCommandStart (ICOStateMachineContext* p_pContext)
  //## begin CWCCommandStart::CWCCommandStart%1038217311.hasinit preserve=no
  //## end CWCCommandStart::CWCCommandStart%1038217311.hasinit
  //## begin CWCCommandStart::CWCCommandStart%1038217311.initialization preserve=yes
  :CWCCommand(p_pContext)
  //## end CWCCommandStart::CWCCommandStart%1038217311.initialization
{
  //## begin CWCCommandStart::CWCCommandStart%1038217311.body preserve=yes
  //## end CWCCommandStart::CWCCommandStart%1038217311.body
}


CWCCommandStart::~CWCCommandStart()
{
  //## begin CWCCommandStart::~CWCCommandStart%.body preserve=yes
  //## end CWCCommandStart::~CWCCommandStart%.body
}



//## Other Operations (implementation)
void CWCCommandStart::CreateSyncObjects ()
{
  //## begin CWCCommandStart::CreateSyncObjects%1038217313.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObject(), false);
    m_pSyncArray->Add(new CCOSyncObjectInt(0), false);
  //## end CWCCommandStart::CreateSyncObjects%1038217313.body
}

bool CWCCommandStart::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandStart::Execute%1038217312.body preserve=yes
    // execute command
    p_pCurrentState->Start(m_pContext, m_pSyncArray->GetAt(0), (CCOSyncObjectInt*)m_pSyncArray->GetAt(1));
    return true;
  //## end CWCCommandStart::Execute%1038217312.body
}

void CWCCommandStart::AttachException (XCOException* p_pException)
{
  //## begin CWCCommandStart::AttachException%1077175171.body preserve=yes

	// attach exception only to the first sync object
	m_pSyncArray->GetAt(0)->AttachException(p_pException);
  //## end CWCCommandStart::AttachException%1077175171.body
}

// Additional Declarations
  //## begin CWCCommandStart%3DE23608004A.declarations preserve=yes
  //## end CWCCommandStart%3DE23608004A.declarations

// Class CWCCommandSetProfile 


CWCCommandSetProfile::CWCCommandSetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile)
  //## begin CWCCommandSetProfile::CWCCommandSetProfile%1038217315.hasinit preserve=no
      : m_pProfile(p_pProfile)
  //## end CWCCommandSetProfile::CWCCommandSetProfile%1038217315.hasinit
  //## begin CWCCommandSetProfile::CWCCommandSetProfile%1038217315.initialization preserve=yes
  , CWCCommand(p_pContext)
  //## end CWCCommandSetProfile::CWCCommandSetProfile%1038217315.initialization
{
  //## begin CWCCommandSetProfile::CWCCommandSetProfile%1038217315.body preserve=yes
  m_pProfile->AddRef();
  //## end CWCCommandSetProfile::CWCCommandSetProfile%1038217315.body
}


CWCCommandSetProfile::~CWCCommandSetProfile()
{
  //## begin CWCCommandSetProfile::~CWCCommandSetProfile%.body preserve=yes
  if (m_pProfile)
    m_pProfile->ReleaseRef();
  m_pProfile = NULL;
  //## end CWCCommandSetProfile::~CWCCommandSetProfile%.body
}



//## Other Operations (implementation)
bool CWCCommandSetProfile::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandSetProfile::Execute%1038217316.body preserve=yes
  p_pCurrentState->SetProfile(m_pContext, m_pProfile);
  return true;
  //## end CWCCommandSetProfile::Execute%1038217316.body
}

// Additional Declarations
  //## begin CWCCommandSetProfile%3DE23B6101C1.declarations preserve=yes
  //## end CWCCommandSetProfile%3DE23B6101C1.declarations

// Class CWCCommandInitialize 

CWCCommandInitialize::CWCCommandInitialize (ICOStateMachineContext* p_pContext)
  //## begin CWCCommandInitialize::CWCCommandInitialize%1038217319.hasinit preserve=no
  //## end CWCCommandInitialize::CWCCommandInitialize%1038217319.hasinit
  //## begin CWCCommandInitialize::CWCCommandInitialize%1038217319.initialization preserve=yes
  : CWCCommand(p_pContext)
  //## end CWCCommandInitialize::CWCCommandInitialize%1038217319.initialization
{
  //## begin CWCCommandInitialize::CWCCommandInitialize%1038217319.body preserve=yes
  //## end CWCCommandInitialize::CWCCommandInitialize%1038217319.body
}


CWCCommandInitialize::~CWCCommandInitialize()
{
  //## begin CWCCommandInitialize::~CWCCommandInitialize%.body preserve=yes
  //## end CWCCommandInitialize::~CWCCommandInitialize%.body
}



//## Other Operations (implementation)
bool CWCCommandInitialize::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandInitialize::Execute%1038217320.body preserve=yes
  p_pCurrentState->Initialize(m_pContext);

  return true;
  //## end CWCCommandInitialize::Execute%1038217320.body
}

// Additional Declarations
  //## begin CWCCommandInitialize%3DE2438101F0.declarations preserve=yes
  //## end CWCCommandInitialize%3DE2438101F0.declarations

// Class CWCCommandConnectionEstablished 

CWCCommandConnectionEstablished::CWCCommandConnectionEstablished (ICOStateMachineContext* p_pContext)
  //## begin CWCCommandConnectionEstablished::CWCCommandConnectionEstablished%1063260185.hasinit preserve=no
  //## end CWCCommandConnectionEstablished::CWCCommandConnectionEstablished%1063260185.hasinit
  //## begin CWCCommandConnectionEstablished::CWCCommandConnectionEstablished%1063260185.initialization preserve=yes
  : CWCCommand(p_pContext)
  //## end CWCCommandConnectionEstablished::CWCCommandConnectionEstablished%1063260185.initialization
{
  //## begin CWCCommandConnectionEstablished::CWCCommandConnectionEstablished%1063260185.body preserve=yes
  //## end CWCCommandConnectionEstablished::CWCCommandConnectionEstablished%1063260185.body
}


CWCCommandConnectionEstablished::~CWCCommandConnectionEstablished()
{
  //## begin CWCCommandConnectionEstablished::~CWCCommandConnectionEstablished%.body preserve=yes
  //## end CWCCommandConnectionEstablished::~CWCCommandConnectionEstablished%.body
}



//## Other Operations (implementation)
bool CWCCommandConnectionEstablished::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandConnectionEstablished::Execute%1063260186.body preserve=yes
	p_pCurrentState->ConnectionEstablished(m_pContext);
	return true;
  //## end CWCCommandConnectionEstablished::Execute%1063260186.body
}

// Additional Declarations
  //## begin CWCCommandConnectionEstablished%3F60108103D8.declarations preserve=yes
  //## end CWCCommandConnectionEstablished%3F60108103D8.declarations

// Class CWCCommandConnectionLost 

CWCCommandConnectionLost::CWCCommandConnectionLost (ICOStateMachineContext* p_pContext)
  //## begin CWCCommandConnectionLost::CWCCommandConnectionLost%1063260187.hasinit preserve=no
  //## end CWCCommandConnectionLost::CWCCommandConnectionLost%1063260187.hasinit
  //## begin CWCCommandConnectionLost::CWCCommandConnectionLost%1063260187.initialization preserve=yes
  : CWCCommand(p_pContext)
  //## end CWCCommandConnectionLost::CWCCommandConnectionLost%1063260187.initialization
{
  //## begin CWCCommandConnectionLost::CWCCommandConnectionLost%1063260187.body preserve=yes
  //## end CWCCommandConnectionLost::CWCCommandConnectionLost%1063260187.body
}


CWCCommandConnectionLost::~CWCCommandConnectionLost()
{
  //## begin CWCCommandConnectionLost::~CWCCommandConnectionLost%.body preserve=yes
  //## end CWCCommandConnectionLost::~CWCCommandConnectionLost%.body
}



//## Other Operations (implementation)
bool CWCCommandConnectionLost::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandConnectionLost::Execute%1063260188.body preserve=yes
	p_pCurrentState->ConnectionLost(m_pContext);
	return true;
  //## end CWCCommandConnectionLost::Execute%1063260188.body
}

// Additional Declarations
  //## begin CWCCommandConnectionLost%3F6010E10000.declarations preserve=yes
  //## end CWCCommandConnectionLost%3F6010E10000.declarations

// Class CWCCommandGetDacZeroCurrent 

CWCCommandGetDacZeroCurrent::CWCCommandGetDacZeroCurrent (ICOStateMachineContext* p_pContext)
  //## begin CWCCommandGetDacZeroCurrent::CWCCommandGetDacZeroCurrent%1149148974.hasinit preserve=no
  //## end CWCCommandGetDacZeroCurrent::CWCCommandGetDacZeroCurrent%1149148974.hasinit
  //## begin CWCCommandGetDacZeroCurrent::CWCCommandGetDacZeroCurrent%1149148974.initialization preserve=yes
  : CWCCommand(p_pContext)
  //## end CWCCommandGetDacZeroCurrent::CWCCommandGetDacZeroCurrent%1149148974.initialization
{
  //## begin CWCCommandGetDacZeroCurrent::CWCCommandGetDacZeroCurrent%1149148974.body preserve=yes
  //## end CWCCommandGetDacZeroCurrent::CWCCommandGetDacZeroCurrent%1149148974.body
}


CWCCommandGetDacZeroCurrent::~CWCCommandGetDacZeroCurrent()
{
  //## begin CWCCommandGetDacZeroCurrent::~CWCCommandGetDacZeroCurrent%.body preserve=yes
  //## end CWCCommandGetDacZeroCurrent::~CWCCommandGetDacZeroCurrent%.body
}



//## Other Operations (implementation)
void CWCCommandGetDacZeroCurrent::CreateSyncObjects ()
{
  //## begin CWCCommandGetDacZeroCurrent::CreateSyncObjects%1149148976.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectInt(0), false);
  //## end CWCCommandGetDacZeroCurrent::CreateSyncObjects%1149148976.body
}

bool CWCCommandGetDacZeroCurrent::Execute (CWCState* p_pCurrentState)
{
  //## begin CWCCommandGetDacZeroCurrent::Execute%1149159895.body preserve=yes
    // keep sync object
    CCOSyncObjectInt* pClientSyncObj = dynamic_cast<CCOSyncObjectInt*>(m_pSyncArray->GetAt(0));
    ASSERT(pClientSyncObj != NULL);

    // execute command
    p_pCurrentState->GetDacZeroCurrent(m_pContext, pClientSyncObj);

    return false;
  //## end CWCCommandGetDacZeroCurrent::Execute%1149159895.body
}

// Additional Declarations
  //## begin CWCCommandGetDacZeroCurrent%447EAA32014F.declarations preserve=yes
  //## end CWCCommandGetDacZeroCurrent%447EAA32014F.declarations

//## begin module%3DD39E9A0397.epilog preserve=yes
//## end module%3DD39E9A0397.epilog
