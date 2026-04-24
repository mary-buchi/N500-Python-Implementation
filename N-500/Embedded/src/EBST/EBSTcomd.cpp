//## begin module%3DAA5DD403AB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAA5DD403AB.cm

//## begin module%3DAA5DD403AB.cp preserve=no
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
//## end module%3DAA5DD403AB.cp

//## Module: EBSTcomd%3DAA5DD403AB; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAA5DD403AB.additionalIncludes preserve=no
//## end module%3DAA5DD403AB.additionalIncludes

//## begin module%3DAA5DD403AB.includes preserve=yes
//## end module%3DAA5DD403AB.includes

// EBPItype
#include "EBPItype.h"
// EBSTstat
#include "EBSTstat.h"
// EBSTcomd
#include "EBSTcomd.h"


//## begin module%3DAA5DD403AB.declarations preserve=no
//## end module%3DAA5DD403AB.declarations

//## begin module%3DAA5DD403AB.additionalDeclarations preserve=yes
//## end module%3DAA5DD403AB.additionalDeclarations


// Class CSTCommandGetPosition 

CSTCommandGetPosition::CSTCommandGetPosition (ICOStateMachineContext* p_pContext)
  //## begin CSTCommandGetPosition::CSTCommandGetPosition%1034575081.hasinit preserve=no
  //## end CSTCommandGetPosition::CSTCommandGetPosition%1034575081.hasinit
  //## begin CSTCommandGetPosition::CSTCommandGetPosition%1034575081.initialization preserve=yes
  : CSTCommand(p_pContext)
  //## end CSTCommandGetPosition::CSTCommandGetPosition%1034575081.initialization
{
  //## begin CSTCommandGetPosition::CSTCommandGetPosition%1034575081.body preserve=yes
  //## end CSTCommandGetPosition::CSTCommandGetPosition%1034575081.body
}


CSTCommandGetPosition::~CSTCommandGetPosition()
{
  //## begin CSTCommandGetPosition::~CSTCommandGetPosition%.body preserve=yes
  //## end CSTCommandGetPosition::~CSTCommandGetPosition%.body
}



//## Other Operations (implementation)
void CSTCommandGetPosition::CreateSyncObjects ()
{
  //## begin CSTCommandGetPosition::CreateSyncObjects%1034575092.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectInt(0), false);
  //## end CSTCommandGetPosition::CreateSyncObjects%1034575092.body
}

bool CSTCommandGetPosition::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandGetPosition::Execute%1034575082.body preserve=yes
    // keep sync object
    CCOSyncObjectInt* pClientSyncObj = dynamic_cast<CCOSyncObjectInt*>(m_pSyncArray->GetAt(0));
    ASSERT(pClientSyncObj != NULL);

    // execute command
    p_pCurrentState->GetPosition(m_pContext, pClientSyncObj);

    return true;
  //## end CSTCommandGetPosition::Execute%1034575082.body
}

// Additional Declarations
  //## begin CSTCommandGetPosition%3DAA5DAE02D1.declarations preserve=yes
  //## end CSTCommandGetPosition%3DAA5DAE02D1.declarations

// Class CSTCommand 

CSTCommand::CSTCommand (ICOStateMachineContext* p_pContext)
  //## begin CSTCommand::CSTCommand%1034575083.hasinit preserve=no
  //## end CSTCommand::CSTCommand%1034575083.hasinit
  //## begin CSTCommand::CSTCommand%1034575083.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CSTCommand::CSTCommand%1034575083.initialization
{
  //## begin CSTCommand::CSTCommand%1034575083.body preserve=yes
  //## end CSTCommand::CSTCommand%1034575083.body
}


CSTCommand::~CSTCommand()
{
  //## begin CSTCommand::~CSTCommand%.body preserve=yes
  //## end CSTCommand::~CSTCommand%.body
}



//## Other Operations (implementation)
bool CSTCommand::Execute (CCOState* p_pCurrentState)
{
  //## begin CSTCommand::Execute%1034575084.body preserve=yes
    CSTState* l_pState = dynamic_cast<CSTState*>(p_pCurrentState);
    return Execute(l_pState);
  //## end CSTCommand::Execute%1034575084.body
}

// Additional Declarations
  //## begin CSTCommand%3DAA5E350215.declarations preserve=yes
  //## end CSTCommand%3DAA5E350215.declarations

// Class CSTCommandMoveAbsolute 



CSTCommandMoveAbsolute::CSTCommandMoveAbsolute (ICOStateMachineContext* p_pContext, INT p_iTargetPosition, INT p_iSearchDistance)
  //## begin CSTCommandMoveAbsolute::CSTCommandMoveAbsolute%1038217265.hasinit preserve=no
      : m_iTargetPosition(p_iTargetPosition), m_iSearchDistance(p_iSearchDistance)
  //## end CSTCommandMoveAbsolute::CSTCommandMoveAbsolute%1038217265.hasinit
  //## begin CSTCommandMoveAbsolute::CSTCommandMoveAbsolute%1038217265.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandMoveAbsolute::CSTCommandMoveAbsolute%1038217265.initialization
{
  //## begin CSTCommandMoveAbsolute::CSTCommandMoveAbsolute%1038217265.body preserve=yes
  //## end CSTCommandMoveAbsolute::CSTCommandMoveAbsolute%1038217265.body
}


CSTCommandMoveAbsolute::~CSTCommandMoveAbsolute()
{
  //## begin CSTCommandMoveAbsolute::~CSTCommandMoveAbsolute%.body preserve=yes
  //## end CSTCommandMoveAbsolute::~CSTCommandMoveAbsolute%.body
}



//## Other Operations (implementation)
bool CSTCommandMoveAbsolute::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandMoveAbsolute::Execute%1038217266.body preserve=yes
  p_pCurrentState->MoveAbsolute(m_pContext, m_iTargetPosition, m_iSearchDistance);

  return true;
  //## end CSTCommandMoveAbsolute::Execute%1038217266.body
}

// Additional Declarations
  //## begin CSTCommandMoveAbsolute%3DE1EF47021F.declarations preserve=yes
  //## end CSTCommandMoveAbsolute%3DE1EF47021F.declarations

// Class CSTCommandMoveRelative 



CSTCommandMoveRelative::CSTCommandMoveRelative (ICOStateMachineContext* p_pContext, INT p_iTotalDistance, INT p_iSearchDistance)
  //## begin CSTCommandMoveRelative::CSTCommandMoveRelative%1038217267.hasinit preserve=no
      : m_iTotalDistance(p_iTotalDistance), m_iSearchDistance(p_iSearchDistance)
  //## end CSTCommandMoveRelative::CSTCommandMoveRelative%1038217267.hasinit
  //## begin CSTCommandMoveRelative::CSTCommandMoveRelative%1038217267.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandMoveRelative::CSTCommandMoveRelative%1038217267.initialization
{
  //## begin CSTCommandMoveRelative::CSTCommandMoveRelative%1038217267.body preserve=yes
  //## end CSTCommandMoveRelative::CSTCommandMoveRelative%1038217267.body
}


CSTCommandMoveRelative::~CSTCommandMoveRelative()
{
  //## begin CSTCommandMoveRelative::~CSTCommandMoveRelative%.body preserve=yes
  //## end CSTCommandMoveRelative::~CSTCommandMoveRelative%.body
}



//## Other Operations (implementation)
bool CSTCommandMoveRelative::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandMoveRelative::Execute%1038217268.body preserve=yes
  p_pCurrentState->MoveRelative(m_pContext, m_iTotalDistance, m_iSearchDistance);

  return true;
  //## end CSTCommandMoveRelative::Execute%1038217268.body
}

// Additional Declarations
  //## begin CSTCommandMoveRelative%3DE1F01100D7.declarations preserve=yes
  //## end CSTCommandMoveRelative%3DE1F01100D7.declarations

// Class CSTCommandStop 

CSTCommandStop::CSTCommandStop (ICOStateMachineContext* p_pContext)
  //## begin CSTCommandStop::CSTCommandStop%1038217271.hasinit preserve=no
  //## end CSTCommandStop::CSTCommandStop%1038217271.hasinit
  //## begin CSTCommandStop::CSTCommandStop%1038217271.initialization preserve=yes
  : CSTCommand(p_pContext)
  //## end CSTCommandStop::CSTCommandStop%1038217271.initialization
{
  //## begin CSTCommandStop::CSTCommandStop%1038217271.body preserve=yes
  //## end CSTCommandStop::CSTCommandStop%1038217271.body
}


CSTCommandStop::~CSTCommandStop()
{
  //## begin CSTCommandStop::~CSTCommandStop%.body preserve=yes
  //## end CSTCommandStop::~CSTCommandStop%.body
}



//## Other Operations (implementation)
bool CSTCommandStop::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandStop::Execute%1038217272.body preserve=yes
  return p_pCurrentState->Stop(m_pContext, m_pSyncArray->GetAt(0));
  //## end CSTCommandStop::Execute%1038217272.body
}

// Additional Declarations
  //## begin CSTCommandStop%3DE1F1EE0183.declarations preserve=yes
  //## end CSTCommandStop%3DE1F1EE0183.declarations

// Class CSTCommandStopImmediately 

CSTCommandStopImmediately::CSTCommandStopImmediately (ICOStateMachineContext* p_pContext)
  //## begin CSTCommandStopImmediately::CSTCommandStopImmediately%1038217273.hasinit preserve=no
  //## end CSTCommandStopImmediately::CSTCommandStopImmediately%1038217273.hasinit
  //## begin CSTCommandStopImmediately::CSTCommandStopImmediately%1038217273.initialization preserve=yes
  : CSTCommand(p_pContext)
  //## end CSTCommandStopImmediately::CSTCommandStopImmediately%1038217273.initialization
{
  //## begin CSTCommandStopImmediately::CSTCommandStopImmediately%1038217273.body preserve=yes
  //## end CSTCommandStopImmediately::CSTCommandStopImmediately%1038217273.body
}


CSTCommandStopImmediately::~CSTCommandStopImmediately()
{
  //## begin CSTCommandStopImmediately::~CSTCommandStopImmediately%.body preserve=yes
  //## end CSTCommandStopImmediately::~CSTCommandStopImmediately%.body
}



//## Other Operations (implementation)
bool CSTCommandStopImmediately::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandStopImmediately::Execute%1038217274.body preserve=yes
  p_pCurrentState->StopImmediately(m_pContext);

  return true;
  //## end CSTCommandStopImmediately::Execute%1038217274.body
}

// Additional Declarations
  //## begin CSTCommandStopImmediately%3DE1F2C200A8.declarations preserve=yes
  //## end CSTCommandStopImmediately%3DE1F2C200A8.declarations

// Class CSTCommandSetProfile 


CSTCommandSetProfile::CSTCommandSetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile)
  //## begin CSTCommandSetProfile::CSTCommandSetProfile%1038217275.hasinit preserve=no
      : m_pProfile(p_pProfile)
  //## end CSTCommandSetProfile::CSTCommandSetProfile%1038217275.hasinit
  //## begin CSTCommandSetProfile::CSTCommandSetProfile%1038217275.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandSetProfile::CSTCommandSetProfile%1038217275.initialization
{
  //## begin CSTCommandSetProfile::CSTCommandSetProfile%1038217275.body preserve=yes
  ASSERT(m_pProfile != NULL);
  m_pProfile->AddRef();
  //## end CSTCommandSetProfile::CSTCommandSetProfile%1038217275.body
}


CSTCommandSetProfile::~CSTCommandSetProfile()
{
  //## begin CSTCommandSetProfile::~CSTCommandSetProfile%.body preserve=yes
  if (m_pProfile)
    m_pProfile->ReleaseRef();

  m_pProfile = NULL;
  //## end CSTCommandSetProfile::~CSTCommandSetProfile%.body
}



//## Other Operations (implementation)
bool CSTCommandSetProfile::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandSetProfile::Execute%1038217276.body preserve=yes
  p_pCurrentState->SetProfile(m_pContext, m_pProfile);
  return true;
  //## end CSTCommandSetProfile::Execute%1038217276.body
}

// Additional Declarations
  //## begin CSTCommandSetProfile%3DE1F36E01B2.declarations preserve=yes
  //## end CSTCommandSetProfile%3DE1F36E01B2.declarations

// Class CSTCommandSetSpeed 


CSTCommandSetSpeed::CSTCommandSetSpeed (ICOStateMachineContext* p_pContext, UINT p_uiSpeed)
  //## begin CSTCommandSetSpeed::CSTCommandSetSpeed%1038217277.hasinit preserve=no
      : m_uiSpeed(p_uiSpeed)
  //## end CSTCommandSetSpeed::CSTCommandSetSpeed%1038217277.hasinit
  //## begin CSTCommandSetSpeed::CSTCommandSetSpeed%1038217277.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandSetSpeed::CSTCommandSetSpeed%1038217277.initialization
{
  //## begin CSTCommandSetSpeed::CSTCommandSetSpeed%1038217277.body preserve=yes
  //## end CSTCommandSetSpeed::CSTCommandSetSpeed%1038217277.body
}


CSTCommandSetSpeed::~CSTCommandSetSpeed()
{
  //## begin CSTCommandSetSpeed::~CSTCommandSetSpeed%.body preserve=yes
  //## end CSTCommandSetSpeed::~CSTCommandSetSpeed%.body
}



//## Other Operations (implementation)
void CSTCommandSetSpeed::CreateSyncObjects ()
{
  //## begin CSTCommandSetSpeed::CreateSyncObjects%1038217279.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectInt(m_uiSpeed), false);
  //## end CSTCommandSetSpeed::CreateSyncObjects%1038217279.body
}

bool CSTCommandSetSpeed::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandSetSpeed::Execute%1038217278.body preserve=yes

    // keep sync object
    CCOSyncObjectInt* pClientSyncObj = dynamic_cast<CCOSyncObjectInt*>(m_pSyncArray->GetAt(0));
    ASSERT(pClientSyncObj != NULL);

    // execute command
    p_pCurrentState->SetSpeed(m_pContext, pClientSyncObj, m_uiSpeed);

    return false;
  //## end CSTCommandSetSpeed::Execute%1038217278.body
}

// Additional Declarations
  //## begin CSTCommandSetSpeed%3DE1F3D10348.declarations preserve=yes
  //## end CSTCommandSetSpeed%3DE1F3D10348.declarations

// Class CSTCommandLimitAdd 




CSTCommandLimitAdd::CSTCommandLimitAdd (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor)
  //## begin CSTCommandLimitAdd::CSTCommandLimitAdd%1038217281.hasinit preserve=no
      : m_eLimitCharacteristics(p_eLimitCharacteristics), m_eLimitAction(p_eLimitAction), m_pSensor(p_pSensor)
  //## end CSTCommandLimitAdd::CSTCommandLimitAdd%1038217281.hasinit
  //## begin CSTCommandLimitAdd::CSTCommandLimitAdd%1038217281.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandLimitAdd::CSTCommandLimitAdd%1038217281.initialization
{
  //## begin CSTCommandLimitAdd::CSTCommandLimitAdd%1038217281.body preserve=yes
  m_pSensor->AddRef();
  //## end CSTCommandLimitAdd::CSTCommandLimitAdd%1038217281.body
}


CSTCommandLimitAdd::~CSTCommandLimitAdd()
{
  //## begin CSTCommandLimitAdd::~CSTCommandLimitAdd%.body preserve=yes
  if (m_pSensor)
    m_pSensor->ReleaseRef();
  m_pSensor = NULL;
  //## end CSTCommandLimitAdd::~CSTCommandLimitAdd%.body
}



//## Other Operations (implementation)
bool CSTCommandLimitAdd::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandLimitAdd::Execute%1038217282.body preserve=yes
  p_pCurrentState->LimitAdd(m_pContext, m_eLimitCharacteristics, m_eLimitAction, m_pSensor);

  return true;
  //## end CSTCommandLimitAdd::Execute%1038217282.body
}

// Additional Declarations
  //## begin CSTCommandLimitAdd%3DE1F6F20069.declarations preserve=yes
  //## end CSTCommandLimitAdd%3DE1F6F20069.declarations

// Class CSTCommandLimitConfig 




CSTCommandLimitConfig::CSTCommandLimitConfig (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor)
  //## begin CSTCommandLimitConfig::CSTCommandLimitConfig%1038217283.hasinit preserve=no
      : m_eLimitCharacteristics(p_eLimitCharacteristics), m_eLimitAction(p_eLimitAction), m_pSensor(p_pSensor)
  //## end CSTCommandLimitConfig::CSTCommandLimitConfig%1038217283.hasinit
  //## begin CSTCommandLimitConfig::CSTCommandLimitConfig%1038217283.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandLimitConfig::CSTCommandLimitConfig%1038217283.initialization
{
  //## begin CSTCommandLimitConfig::CSTCommandLimitConfig%1038217283.body preserve=yes
  m_pSensor->AddRef();
  //## end CSTCommandLimitConfig::CSTCommandLimitConfig%1038217283.body
}


CSTCommandLimitConfig::~CSTCommandLimitConfig()
{
  //## begin CSTCommandLimitConfig::~CSTCommandLimitConfig%.body preserve=yes
  if (m_pSensor)
    m_pSensor->ReleaseRef();
  m_pSensor = NULL;
  //## end CSTCommandLimitConfig::~CSTCommandLimitConfig%.body
}



//## Other Operations (implementation)
bool CSTCommandLimitConfig::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandLimitConfig::Execute%1038217284.body preserve=yes
  p_pCurrentState->LimitConfig(m_pContext, m_eLimitCharacteristics, m_eLimitAction, m_pSensor);

  return true;
  //## end CSTCommandLimitConfig::Execute%1038217284.body
}

// Additional Declarations
  //## begin CSTCommandLimitConfig%3DE1F764001B.declarations preserve=yes
  //## end CSTCommandLimitConfig%3DE1F764001B.declarations

// Class CSTCommandLimitActivate 

CSTCommandLimitActivate::CSTCommandLimitActivate (ICOStateMachineContext* p_pContext)
  //## begin CSTCommandLimitActivate::CSTCommandLimitActivate%1038217285.hasinit preserve=no
  //## end CSTCommandLimitActivate::CSTCommandLimitActivate%1038217285.hasinit
  //## begin CSTCommandLimitActivate::CSTCommandLimitActivate%1038217285.initialization preserve=yes
  : CSTCommand(p_pContext)
  //## end CSTCommandLimitActivate::CSTCommandLimitActivate%1038217285.initialization
{
  //## begin CSTCommandLimitActivate::CSTCommandLimitActivate%1038217285.body preserve=yes
  //## end CSTCommandLimitActivate::CSTCommandLimitActivate%1038217285.body
}


CSTCommandLimitActivate::~CSTCommandLimitActivate()
{
  //## begin CSTCommandLimitActivate::~CSTCommandLimitActivate%.body preserve=yes
  //## end CSTCommandLimitActivate::~CSTCommandLimitActivate%.body
}



//## Other Operations (implementation)
bool CSTCommandLimitActivate::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandLimitActivate::Execute%1038217286.body preserve=yes
  p_pCurrentState->LimitActivate(m_pContext);

  return true;
  //## end CSTCommandLimitActivate::Execute%1038217286.body
}

// Additional Declarations
  //## begin CSTCommandLimitActivate%3DE1F833003B.declarations preserve=yes
  //## end CSTCommandLimitActivate%3DE1F833003B.declarations

// Class CSTCommandLimitDeactivate 

CSTCommandLimitDeactivate::CSTCommandLimitDeactivate (ICOStateMachineContext* p_pContext)
  //## begin CSTCommandLimitDeactivate::CSTCommandLimitDeactivate%1038217287.hasinit preserve=no
  //## end CSTCommandLimitDeactivate::CSTCommandLimitDeactivate%1038217287.hasinit
  //## begin CSTCommandLimitDeactivate::CSTCommandLimitDeactivate%1038217287.initialization preserve=yes
  : CSTCommand(p_pContext)
  //## end CSTCommandLimitDeactivate::CSTCommandLimitDeactivate%1038217287.initialization
{
  //## begin CSTCommandLimitDeactivate::CSTCommandLimitDeactivate%1038217287.body preserve=yes
  //## end CSTCommandLimitDeactivate::CSTCommandLimitDeactivate%1038217287.body
}


CSTCommandLimitDeactivate::~CSTCommandLimitDeactivate()
{
  //## begin CSTCommandLimitDeactivate::~CSTCommandLimitDeactivate%.body preserve=yes
  //## end CSTCommandLimitDeactivate::~CSTCommandLimitDeactivate%.body
}



//## Other Operations (implementation)
bool CSTCommandLimitDeactivate::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandLimitDeactivate::Execute%1038217288.body preserve=yes
  p_pCurrentState->LimitDeactivate(m_pContext);

  return true;
  //## end CSTCommandLimitDeactivate::Execute%1038217288.body
}

// Additional Declarations
  //## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.declarations preserve=yes
  //## end CSTCommandLimitDeactivate%3DE1F8AE01C1.declarations

// Class CSTCommandHome 




CSTCommandHome::CSTCommandHome (ICOStateMachineContext* p_pContext, const EPIMotorPolarity p_eFastFindingDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID)
  //## begin CSTCommandHome::CSTCommandHome%1038217289.hasinit preserve=no
      : m_eFastFindingDirection(p_eFastFindingDirection), m_pHomeLimitID(p_pHomeLimitID), m_bSearchLimitFromOpposite(p_bSearchLimitFromOpposite)
  //## end CSTCommandHome::CSTCommandHome%1038217289.hasinit
  //## begin CSTCommandHome::CSTCommandHome%1038217289.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandHome::CSTCommandHome%1038217289.initialization
{
  //## begin CSTCommandHome::CSTCommandHome%1038217289.body preserve=yes
	m_pHomeLimitID->AddRef();
  //## end CSTCommandHome::CSTCommandHome%1038217289.body
}


CSTCommandHome::~CSTCommandHome()
{
  //## begin CSTCommandHome::~CSTCommandHome%.body preserve=yes
	if (m_pHomeLimitID != NULL)
	{
		m_pHomeLimitID->ReleaseRef();
	}
	m_pHomeLimitID = NULL;
  //## end CSTCommandHome::~CSTCommandHome%.body
}



//## Other Operations (implementation)
void CSTCommandHome::CreateSyncObjects ()
{
  //## begin CSTCommandHome::CreateSyncObjects%1193385558.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectInt(0), false);
  //## end CSTCommandHome::CreateSyncObjects%1193385558.body
}

bool CSTCommandHome::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandHome::Execute%1038217290.body preserve=yes

	CCOSyncObjectInt* l_pClientSyncObj = dynamic_cast<CCOSyncObjectInt*>(m_pSyncArray->GetAt(0));
    ASSERT(l_pClientSyncObj != NULL);

	p_pCurrentState->Home(m_pContext, m_eFastFindingDirection, m_bSearchLimitFromOpposite, m_pHomeLimitID, l_pClientSyncObj);
    return true;
  //## end CSTCommandHome::Execute%1038217290.body
}

// Additional Declarations
  //## begin CSTCommandHome%3DE1F92501D1.declarations preserve=yes
  //## end CSTCommandHome%3DE1F92501D1.declarations

// Class CSTCommandHomeSetPosition 


CSTCommandHomeSetPosition::CSTCommandHomeSetPosition (ICOStateMachineContext* p_pContext, INT p_iPosition)
  //## begin CSTCommandHomeSetPosition::CSTCommandHomeSetPosition%1038217291.hasinit preserve=no
      : m_iPosition(p_iPosition)
  //## end CSTCommandHomeSetPosition::CSTCommandHomeSetPosition%1038217291.hasinit
  //## begin CSTCommandHomeSetPosition::CSTCommandHomeSetPosition%1038217291.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandHomeSetPosition::CSTCommandHomeSetPosition%1038217291.initialization
{
  //## begin CSTCommandHomeSetPosition::CSTCommandHomeSetPosition%1038217291.body preserve=yes
  //## end CSTCommandHomeSetPosition::CSTCommandHomeSetPosition%1038217291.body
}


CSTCommandHomeSetPosition::~CSTCommandHomeSetPosition()
{
  //## begin CSTCommandHomeSetPosition::~CSTCommandHomeSetPosition%.body preserve=yes
  //## end CSTCommandHomeSetPosition::~CSTCommandHomeSetPosition%.body
}



//## Other Operations (implementation)
bool CSTCommandHomeSetPosition::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandHomeSetPosition::Execute%1038217292.body preserve=yes
  p_pCurrentState->HomeSetPosition(m_pContext, m_iPosition);

  return true;
  //## end CSTCommandHomeSetPosition::Execute%1038217292.body
}

// Additional Declarations
  //## begin CSTCommandHomeSetPosition%3DE1F97A00F6.declarations preserve=yes
  //## end CSTCommandHomeSetPosition%3DE1F97A00F6.declarations

// Class CSTCommandLimitGetFootPrint 

CSTCommandLimitGetFootPrint::CSTCommandLimitGetFootPrint (ICOStateMachineContext* p_pContext)
  //## begin CSTCommandLimitGetFootPrint::CSTCommandLimitGetFootPrint%1038217293.hasinit preserve=no
  //## end CSTCommandLimitGetFootPrint::CSTCommandLimitGetFootPrint%1038217293.hasinit
  //## begin CSTCommandLimitGetFootPrint::CSTCommandLimitGetFootPrint%1038217293.initialization preserve=yes
  : CSTCommand(p_pContext)
  //## end CSTCommandLimitGetFootPrint::CSTCommandLimitGetFootPrint%1038217293.initialization
{
  //## begin CSTCommandLimitGetFootPrint::CSTCommandLimitGetFootPrint%1038217293.body preserve=yes
  //## end CSTCommandLimitGetFootPrint::CSTCommandLimitGetFootPrint%1038217293.body
}


CSTCommandLimitGetFootPrint::~CSTCommandLimitGetFootPrint()
{
  //## begin CSTCommandLimitGetFootPrint::~CSTCommandLimitGetFootPrint%.body preserve=yes
  //## end CSTCommandLimitGetFootPrint::~CSTCommandLimitGetFootPrint%.body
}



//## Other Operations (implementation)
void CSTCommandLimitGetFootPrint::CreateSyncObjects ()
{
  //## begin CSTCommandLimitGetFootPrint::CreateSyncObjects%1038217295.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectIntArray(0), false);
  //## end CSTCommandLimitGetFootPrint::CreateSyncObjects%1038217295.body
}

bool CSTCommandLimitGetFootPrint::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandLimitGetFootPrint::Execute%1038217294.body preserve=yes

  // keep sync object
  CCOSyncObjectIntArray* pClientSyncObj = dynamic_cast<CCOSyncObjectIntArray*>(m_pSyncArray->GetAt(0));
  ASSERT(pClientSyncObj != NULL);

  // execute command
  p_pCurrentState->LimitGetFootPrint(m_pContext, pClientSyncObj);

  return false;

  //## end CSTCommandLimitGetFootPrint::Execute%1038217294.body
}

// Additional Declarations
  //## begin CSTCommandLimitGetFootPrint%3DE1FA110183.declarations preserve=yes
  //## end CSTCommandLimitGetFootPrint%3DE1FA110183.declarations

// Class CSTCommandSetConfig 


CSTCommandSetConfig::CSTCommandSetConfig (ICOStateMachineContext* p_pContext, CPIStepperMotorConfig* p_pConfig)
  //## begin CSTCommandSetConfig::CSTCommandSetConfig%1047647375.hasinit preserve=no
      : m_pConfig(p_pConfig)
  //## end CSTCommandSetConfig::CSTCommandSetConfig%1047647375.hasinit
  //## begin CSTCommandSetConfig::CSTCommandSetConfig%1047647375.initialization preserve=yes
  	, CSTCommand(p_pContext)
  //## end CSTCommandSetConfig::CSTCommandSetConfig%1047647375.initialization
{
  //## begin CSTCommandSetConfig::CSTCommandSetConfig%1047647375.body preserve=yes
	m_pConfig->AddRef();
  //## end CSTCommandSetConfig::CSTCommandSetConfig%1047647375.body
}


CSTCommandSetConfig::~CSTCommandSetConfig()
{
  //## begin CSTCommandSetConfig::~CSTCommandSetConfig%.body preserve=yes
  if (m_pConfig)
    m_pConfig->ReleaseRef();
  m_pConfig = NULL;
  //## end CSTCommandSetConfig::~CSTCommandSetConfig%.body
}



//## Other Operations (implementation)
bool CSTCommandSetConfig::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandSetConfig::Execute%1047647376.body preserve=yes
  p_pCurrentState->SetConfig(m_pContext, m_pConfig);

  return true;
  //## end CSTCommandSetConfig::Execute%1047647376.body
}

// Additional Declarations
  //## begin CSTCommandSetConfig%3E71EC1A0261.declarations preserve=yes
  //## end CSTCommandSetConfig%3E71EC1A0261.declarations

// Class CSTCommandOnLimitHit 


CSTCommandOnLimitHit::CSTCommandOnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
  //## begin CSTCommandOnLimitHit::CSTCommandOnLimitHit%1048581160.hasinit preserve=no
      : m_pLimitID(p_pLimitID)
  //## end CSTCommandOnLimitHit::CSTCommandOnLimitHit%1048581160.hasinit
  //## begin CSTCommandOnLimitHit::CSTCommandOnLimitHit%1048581160.initialization preserve=yes
    , CSTCommand(p_pContext)
  //## end CSTCommandOnLimitHit::CSTCommandOnLimitHit%1048581160.initialization
{
  //## begin CSTCommandOnLimitHit::CSTCommandOnLimitHit%1048581160.body preserve=yes
	m_pLimitID->AddRef();
  //## end CSTCommandOnLimitHit::CSTCommandOnLimitHit%1048581160.body
}


CSTCommandOnLimitHit::~CSTCommandOnLimitHit()
{
  //## begin CSTCommandOnLimitHit::~CSTCommandOnLimitHit%.body preserve=yes
	m_pLimitID->ReleaseRef();
	m_pLimitID = NULL;
  //## end CSTCommandOnLimitHit::~CSTCommandOnLimitHit%.body
}



//## Other Operations (implementation)
bool CSTCommandOnLimitHit::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandOnLimitHit::Execute%1048581161.body preserve=yes
	p_pCurrentState->OnLimitHit(m_pContext, m_pLimitID);

	return true;
  //## end CSTCommandOnLimitHit::Execute%1048581161.body
}

// Additional Declarations
  //## begin CSTCommandOnLimitHit%3E8060F7021B.declarations preserve=yes
  //## end CSTCommandOnLimitHit%3E8060F7021B.declarations

// Class CSTCcommandConnectionLost 

CSTCcommandConnectionLost::~CSTCcommandConnectionLost()
{
  //## begin CSTCcommandConnectionLost::~CSTCcommandConnectionLost%.body preserve=yes
  //## end CSTCcommandConnectionLost::~CSTCcommandConnectionLost%.body
}



//## Other Operations (implementation)
bool CSTCcommandConnectionLost::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCcommandConnectionLost::Execute%1055428402.body preserve=yes
	p_pCurrentState->ConnectionLost(m_pContext);
	return false;
  //## end CSTCcommandConnectionLost::Execute%1055428402.body
}

void CSTCcommandConnectionLost::CSTcommandConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSTCcommandConnectionLost::CSTcommandConnectionLost%1055428405.body preserve=yes
  //## end CSTCcommandConnectionLost::CSTcommandConnectionLost%1055428405.body
}

// Additional Declarations
  //## begin CSTCcommandConnectionLost%3EE892D80184.declarations preserve=yes
  //## end CSTCcommandConnectionLost%3EE892D80184.declarations

// Class CSTCommandConnectionEstablished 

CSTCommandConnectionEstablished::~CSTCommandConnectionEstablished()
{
  //## begin CSTCommandConnectionEstablished::~CSTCommandConnectionEstablished%.body preserve=yes
  //## end CSTCommandConnectionEstablished::~CSTCommandConnectionEstablished%.body
}



//## Other Operations (implementation)
bool CSTCommandConnectionEstablished::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandConnectionEstablished::Execute%1055428404.body preserve=yes
	p_pCurrentState->ConnectionEstablished(m_pContext);
	return false;
  //## end CSTCommandConnectionEstablished::Execute%1055428404.body
}

void CSTCommandConnectionEstablished::CStCommandConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CSTCommandConnectionEstablished::CStCommandConnectionEstablished%1055428403.body preserve=yes
  //## end CSTCommandConnectionEstablished::CStCommandConnectionEstablished%1055428403.body
}

// Additional Declarations
  //## begin CSTCommandConnectionEstablished%3EE89369007A.declarations preserve=yes
  //## end CSTCommandConnectionEstablished%3EE89369007A.declarations

// Class CSTCommandMoveManual 



CSTCommandMoveManual::CSTCommandMoveManual (ICOStateMachineContext* p_pContext, INT p_iEndPosition, INT p_uiSpeed)
  //## begin CSTCommandMoveManual::CSTCommandMoveManual%1038217269.hasinit preserve=no
      : m_iEndPosition(p_iEndPosition), m_uiSpeed(p_uiSpeed)
  //## end CSTCommandMoveManual::CSTCommandMoveManual%1038217269.hasinit
  //## begin CSTCommandMoveManual::CSTCommandMoveManual%1038217269.initialization preserve=yes
  , CSTCommand(p_pContext)
  //## end CSTCommandMoveManual::CSTCommandMoveManual%1038217269.initialization
{
  //## begin CSTCommandMoveManual::CSTCommandMoveManual%1038217269.body preserve=yes
  //## end CSTCommandMoveManual::CSTCommandMoveManual%1038217269.body
}


CSTCommandMoveManual::~CSTCommandMoveManual()
{
  //## begin CSTCommandMoveManual::~CSTCommandMoveManual%.body preserve=yes
  //## end CSTCommandMoveManual::~CSTCommandMoveManual%.body
}



//## Other Operations (implementation)
bool CSTCommandMoveManual::Execute (CSTState* p_pCurrentState)
{
  //## begin CSTCommandMoveManual::Execute%1038217270.body preserve=yes
  p_pCurrentState->MoveManual(m_pContext, m_iEndPosition, m_uiSpeed);

  return true;
  //## end CSTCommandMoveManual::Execute%1038217270.body
}

// Additional Declarations
  //## begin CSTCommandMoveManual%3DE1F1160357.declarations preserve=yes
  //## end CSTCommandMoveManual%3DE1F1160357.declarations

//## begin module%3DAA5DD403AB.epilog preserve=yes
//## end module%3DAA5DD403AB.epilog
