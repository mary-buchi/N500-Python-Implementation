//## begin module%3DAAE8B0036F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE8B0036F.cm

//## begin module%3DAAE8B0036F.cp preserve=no
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
//## end module%3DAAE8B0036F.cp

//## Module: EBMCcomd%3DAAE8B0036F; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAE8B0036F.additionalIncludes preserve=no
//## end module%3DAAE8B0036F.additionalIncludes

//## begin module%3DAAE8B0036F.includes preserve=yes
//## end module%3DAAE8B0036F.includes

// EBPItype
#include "EBPItype.h"
// EBMCcomd
#include "EBMCcomd.h"
// EBMCstat
#include "EBMCstat.h"


//## begin module%3DAAE8B0036F.declarations preserve=no
//## end module%3DAAE8B0036F.declarations

//## begin module%3DAAE8B0036F.additionalDeclarations preserve=yes
//## end module%3DAAE8B0036F.additionalDeclarations


// Class CMCCommand 

CMCCommand::CMCCommand (ICOStateMachineContext* p_pContext)
  //## begin CMCCommand::CMCCommand%1034575111.hasinit preserve=no
  //## end CMCCommand::CMCCommand%1034575111.hasinit
  //## begin CMCCommand::CMCCommand%1034575111.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CMCCommand::CMCCommand%1034575111.initialization
{
  //## begin CMCCommand::CMCCommand%1034575111.body preserve=yes
  //## end CMCCommand::CMCCommand%1034575111.body
}


CMCCommand::~CMCCommand()
{
  //## begin CMCCommand::~CMCCommand%.body preserve=yes
  //## end CMCCommand::~CMCCommand%.body
}



//## Other Operations (implementation)
bool CMCCommand::Execute (CCOState* p_pCurrentState)
{
  //## begin CMCCommand::Execute%1034575112.body preserve=yes
    CMCState* l_pState = dynamic_cast<CMCState*>(p_pCurrentState);
    ASSERT(l_pState != NULL);

    return Execute(l_pState);
  //## end CMCCommand::Execute%1034575112.body
}

// Additional Declarations
  //## begin CMCCommand%3DAAE8C6012D.declarations preserve=yes
  //## end CMCCommand%3DAAE8C6012D.declarations

// Class CMCCommandGetDataPackage 

CMCCommandGetDataPackage::CMCCommandGetDataPackage (ICOStateMachineContext* p_pContext)
  //## begin CMCCommandGetDataPackage::CMCCommandGetDataPackage%1034835014.hasinit preserve=no
  //## end CMCCommandGetDataPackage::CMCCommandGetDataPackage%1034835014.hasinit
  //## begin CMCCommandGetDataPackage::CMCCommandGetDataPackage%1034835014.initialization preserve=yes
  : CMCCommand(p_pContext)
  //## end CMCCommandGetDataPackage::CMCCommandGetDataPackage%1034835014.initialization
{
  //## begin CMCCommandGetDataPackage::CMCCommandGetDataPackage%1034835014.body preserve=yes
  //## end CMCCommandGetDataPackage::CMCCommandGetDataPackage%1034835014.body
}


CMCCommandGetDataPackage::~CMCCommandGetDataPackage()
{
  //## begin CMCCommandGetDataPackage::~CMCCommandGetDataPackage%.body preserve=yes
  //## end CMCCommandGetDataPackage::~CMCCommandGetDataPackage%.body
}



//## Other Operations (implementation)
void CMCCommandGetDataPackage::CreateSyncObjects ()
{
  //## begin CMCCommandGetDataPackage::CreateSyncObjects%1034835016.body preserve=yes
    m_pSyncArray->Add(new CPISyncObjDataPackage(NULL), false);
  //## end CMCCommandGetDataPackage::CreateSyncObjects%1034835016.body
}

bool CMCCommandGetDataPackage::Execute (CMCState* p_pCurrentState)
{
  //## begin CMCCommandGetDataPackage::Execute%1034835015.body preserve=yes
    // keep sync object
    CPISyncObjDataPackage* pClientSyncObj = dynamic_cast<CPISyncObjDataPackage*>(m_pSyncArray->GetAt(0));
    ASSERT(pClientSyncObj != NULL);

    // execute command
    p_pCurrentState->GetDataPackage(m_pContext, pClientSyncObj);

    return false;
    
  //## end CMCCommandGetDataPackage::Execute%1034835015.body
}

// Additional Declarations
  //## begin CMCCommandGetDataPackage%3DAE53C0038B.declarations preserve=yes
  //## end CMCCommandGetDataPackage%3DAE53C0038B.declarations

// Class CMCCommandStart 


CMCCommandStart::CMCCommandStart (ICOStateMachineContext* p_pContext, UINT p_uiCycleID)
  //## begin CMCCommandStart::CMCCommandStart%1038405583.hasinit preserve=no
      : m_uiCycleID(p_uiCycleID)
  //## end CMCCommandStart::CMCCommandStart%1038405583.hasinit
  //## begin CMCCommandStart::CMCCommandStart%1038405583.initialization preserve=yes
  , CMCCommand(p_pContext)
  //## end CMCCommandStart::CMCCommandStart%1038405583.initialization
{
  //## begin CMCCommandStart::CMCCommandStart%1038405583.body preserve=yes
  //## end CMCCommandStart::CMCCommandStart%1038405583.body
}


CMCCommandStart::~CMCCommandStart()
{
  //## begin CMCCommandStart::~CMCCommandStart%.body preserve=yes
  //## end CMCCommandStart::~CMCCommandStart%.body
}



//## Other Operations (implementation)
bool CMCCommandStart::Execute (CMCState* p_pCurrentState)
{
  //## begin CMCCommandStart::Execute%1038405584.body preserve=yes
  p_pCurrentState->Start(m_pContext, m_uiCycleID);

  return true;
  //## end CMCCommandStart::Execute%1038405584.body
}

// Additional Declarations
  //## begin CMCCommandStart%3DE4D5700323.declarations preserve=yes
  //## end CMCCommandStart%3DE4D5700323.declarations

// Class CMCCommandStop 

CMCCommandStop::CMCCommandStop (ICOStateMachineContext* p_pContext)
  //## begin CMCCommandStop::CMCCommandStop%1038405585.hasinit preserve=no
  //## end CMCCommandStop::CMCCommandStop%1038405585.hasinit
  //## begin CMCCommandStop::CMCCommandStop%1038405585.initialization preserve=yes
  : CMCCommand(p_pContext)
  //## end CMCCommandStop::CMCCommandStop%1038405585.initialization
{
  //## begin CMCCommandStop::CMCCommandStop%1038405585.body preserve=yes
  //## end CMCCommandStop::CMCCommandStop%1038405585.body
}


CMCCommandStop::~CMCCommandStop()
{
  //## begin CMCCommandStop::~CMCCommandStop%.body preserve=yes
  //## end CMCCommandStop::~CMCCommandStop%.body
}



//## Other Operations (implementation)
bool CMCCommandStop::Execute (CMCState* p_pCurrentState)
{
  //## begin CMCCommandStop::Execute%1038405586.body preserve=yes
  p_pCurrentState->Stop(m_pContext);

  return true;
  //## end CMCCommandStop::Execute%1038405586.body
}

// Additional Declarations
  //## begin CMCCommandStop%3DE4D58303AF.declarations preserve=yes
  //## end CMCCommandStop%3DE4D58303AF.declarations

// Class CMCCommandSetProfile 


CMCCommandSetProfile::CMCCommandSetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile)
  //## begin CMCCommandSetProfile::CMCCommandSetProfile%1038405587.hasinit preserve=no
      : m_pProfile(p_pProfile)
  //## end CMCCommandSetProfile::CMCCommandSetProfile%1038405587.hasinit
  //## begin CMCCommandSetProfile::CMCCommandSetProfile%1038405587.initialization preserve=yes
  , CMCCommand(p_pContext)
  //## end CMCCommandSetProfile::CMCCommandSetProfile%1038405587.initialization
{
  //## begin CMCCommandSetProfile::CMCCommandSetProfile%1038405587.body preserve=yes
  //## end CMCCommandSetProfile::CMCCommandSetProfile%1038405587.body
}


CMCCommandSetProfile::~CMCCommandSetProfile()
{
  //## begin CMCCommandSetProfile::~CMCCommandSetProfile%.body preserve=yes
  //## end CMCCommandSetProfile::~CMCCommandSetProfile%.body
}



//## Other Operations (implementation)
bool CMCCommandSetProfile::Execute (CMCState* p_pCurrentState)
{
  //## begin CMCCommandSetProfile::Execute%1038405588.body preserve=yes
  p_pCurrentState->SetProfile(m_pContext, m_pProfile);

  return true;
  //## end CMCCommandSetProfile::Execute%1038405588.body
}

// Additional Declarations
  //## begin CMCCommandSetProfile%3DE4D59102F4.declarations preserve=yes
  //## end CMCCommandSetProfile%3DE4D59102F4.declarations

// Class CMCCommandInitialize 

CMCCommandInitialize::CMCCommandInitialize (ICOStateMachineContext* p_pContext)
  //## begin CMCCommandInitialize::CMCCommandInitialize%1038405589.hasinit preserve=no
  //## end CMCCommandInitialize::CMCCommandInitialize%1038405589.hasinit
  //## begin CMCCommandInitialize::CMCCommandInitialize%1038405589.initialization preserve=yes
  : CMCCommand(p_pContext)
  //## end CMCCommandInitialize::CMCCommandInitialize%1038405589.initialization
{
  //## begin CMCCommandInitialize::CMCCommandInitialize%1038405589.body preserve=yes
  //## end CMCCommandInitialize::CMCCommandInitialize%1038405589.body
}


CMCCommandInitialize::~CMCCommandInitialize()
{
  //## begin CMCCommandInitialize::~CMCCommandInitialize%.body preserve=yes
  //## end CMCCommandInitialize::~CMCCommandInitialize%.body
}



//## Other Operations (implementation)
bool CMCCommandInitialize::Execute (CMCState* p_pCurrentState)
{
  //## begin CMCCommandInitialize::Execute%1038405590.body preserve=yes
  p_pCurrentState->Initialize(m_pContext);

  return true;
  //## end CMCCommandInitialize::Execute%1038405590.body
}

// Additional Declarations
  //## begin CMCCommandInitialize%3DE4D5A000F0.declarations preserve=yes
  //## end CMCCommandInitialize%3DE4D5A000F0.declarations

// Class CMCCommandConnectionEstablished 

CMCCommandConnectionEstablished::CMCCommandConnectionEstablished (ICOStateMachineContext* p_pContext)
  //## begin CMCCommandConnectionEstablished::CMCCommandConnectionEstablished%1063260181.hasinit preserve=no
  //## end CMCCommandConnectionEstablished::CMCCommandConnectionEstablished%1063260181.hasinit
  //## begin CMCCommandConnectionEstablished::CMCCommandConnectionEstablished%1063260181.initialization preserve=yes
  : CMCCommand(p_pContext)
  //## end CMCCommandConnectionEstablished::CMCCommandConnectionEstablished%1063260181.initialization
{
  //## begin CMCCommandConnectionEstablished::CMCCommandConnectionEstablished%1063260181.body preserve=yes
  //## end CMCCommandConnectionEstablished::CMCCommandConnectionEstablished%1063260181.body
}


CMCCommandConnectionEstablished::~CMCCommandConnectionEstablished()
{
  //## begin CMCCommandConnectionEstablished::~CMCCommandConnectionEstablished%.body preserve=yes
  //## end CMCCommandConnectionEstablished::~CMCCommandConnectionEstablished%.body
}



//## Other Operations (implementation)
bool CMCCommandConnectionEstablished::Execute (CMCState* p_pCurrentState)
{
  //## begin CMCCommandConnectionEstablished::Execute%1063260182.body preserve=yes
	p_pCurrentState->ConnectionEstablished(m_pContext);
	return true;
  //## end CMCCommandConnectionEstablished::Execute%1063260182.body
}

// Additional Declarations
  //## begin CMCCommandConnectionEstablished%3F60109B02BF.declarations preserve=yes
  //## end CMCCommandConnectionEstablished%3F60109B02BF.declarations

// Class CMCCommandConnectionLost 

CMCCommandConnectionLost::CMCCommandConnectionLost (ICOStateMachineContext* p_pContext)
  //## begin CMCCommandConnectionLost::CMCCommandConnectionLost%1063260183.hasinit preserve=no
  //## end CMCCommandConnectionLost::CMCCommandConnectionLost%1063260183.hasinit
  //## begin CMCCommandConnectionLost::CMCCommandConnectionLost%1063260183.initialization preserve=yes
  : CMCCommand(p_pContext)
  //## end CMCCommandConnectionLost::CMCCommandConnectionLost%1063260183.initialization
{
  //## begin CMCCommandConnectionLost::CMCCommandConnectionLost%1063260183.body preserve=yes
  //## end CMCCommandConnectionLost::CMCCommandConnectionLost%1063260183.body
}


CMCCommandConnectionLost::~CMCCommandConnectionLost()
{
  //## begin CMCCommandConnectionLost::~CMCCommandConnectionLost%.body preserve=yes
  //## end CMCCommandConnectionLost::~CMCCommandConnectionLost%.body
}



//## Other Operations (implementation)
bool CMCCommandConnectionLost::Execute (CMCState* p_pCurrentState)
{
  //## begin CMCCommandConnectionLost::Execute%1063260184.body preserve=yes
	p_pCurrentState->ConnectionLost(m_pContext);
	return true;
  //## end CMCCommandConnectionLost::Execute%1063260184.body
}

// Additional Declarations
  //## begin CMCCommandConnectionLost%3F6010CC0148.declarations preserve=yes
  //## end CMCCommandConnectionLost%3F6010CC0148.declarations

//## begin module%3DAAE8B0036F.epilog preserve=yes
//## end module%3DAAE8B0036F.epilog

