//## begin module%3EDC5B3C01EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01EA.cm

//## begin module%3EDC5B3C01EA.cp preserve=no
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
//## end module%3EDC5B3C01EA.cp

//## Module: EBSYsten%3EDC5B3C01EA; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYsten.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C01EA.additionalIncludes preserve=no
//## end module%3EDC5B3C01EA.additionalIncludes

//## begin module%3EDC5B3C01EA.includes preserve=yes
//## end module%3EDC5B3C01EA.includes

// EBSYshdn
#include "EBSYshdn.h"
// EBSYcrea
#include "EBSYcrea.h"
// EBSYsten
#include "EBSYsten.h"
// EBSYidnt
#include "EBSYidnt.h"
// EBSYpstb
#include "EBSYpstb.h"
// EBSYcntd
#include "EBSYcntd.h"
// EBSYcons
#include "EBSYcons.h"
// EBSYidle
#include "EBSYidle.h"
// EBSYifcf
#include "EBSYifcf.h"
// EBSYrdsw
#include "EBSYrdsw.h"
// EBSYrgun
#include "EBSYrgun.h"
// EBSYswdl
#include "EBSYswdl.h"
//## begin module%3EDC5B3C01EA.declarations preserve=no
//## end module%3EDC5B3C01EA.declarations

//## begin module%3EDC5B3C01EA.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01EA.additionalDeclarations


// Class CSYStateMachineEngine 

CSYStateMachineEngine::CSYStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CSYStateMachineEngine::CSYStateMachineEngine%1038899322.hasinit preserve=no
  //## end CSYStateMachineEngine::CSYStateMachineEngine%1038899322.hasinit
  //## begin CSYStateMachineEngine::CSYStateMachineEngine%1038899322.initialization preserve=yes
  : CCOStateMachineEngine(p_pContext)
  //## end CSYStateMachineEngine::CSYStateMachineEngine%1038899322.initialization
{
  //## begin CSYStateMachineEngine::CSYStateMachineEngine%1038899322.body preserve=yes
  //## end CSYStateMachineEngine::CSYStateMachineEngine%1038899322.body
}


CSYStateMachineEngine::~CSYStateMachineEngine()
{
  //## begin CSYStateMachineEngine::~CSYStateMachineEngine%.body preserve=yes
  //## end CSYStateMachineEngine::~CSYStateMachineEngine%.body
}



//## Other Operations (implementation)
void CSYStateMachineEngine::BuildStateMachine ()
{
  //## begin CSYStateMachineEngine::BuildStateMachine%1038899323.body preserve=yes

    CSYStateCreated::Create();
    CSYStateShuttingDown::Create();

	CSYStateConstitutionStartingUp::Create();
	CSYStateConstitutionStandBy::Create();
	CSYStateConstitutionStandByWarmingUp::Create();
    CSYStateConstitutionConfigInterface::Create();
    CSYStateConstitutionConnected::Create();
    CSYStateConstitutionDownloadSoftwareComponents::Create();
    CSYStateConstitutionReadSoftwareVersions::Create();
    CSYStateConstitutionRegisteringUnits::Create();
    CSYStateConstitutionConsiderInterfaceReset::Create();
    CSYStateConstitutionResetInterface::Create();
	CSYStateConstitutionUnregisteringUnits::Create();
    CSYStateConstitutionDownloadStarted::Create();

    CSYStateProcessIdle::Create();
    CSYStateProcessReadSoftwareVersions::Create();

	CSYStateProcessStandByConnecting::Create();
	CSYStateProcessStandByDisconnecting::Create();
	CSYStateProcessStandByIdle::Create();

  //## end CSYStateMachineEngine::BuildStateMachine%1038899323.body
}

CCOState* CSYStateMachineEngine::GetInitializeState ()
{
  //## begin CSYStateMachineEngine::GetInitializeState%1042097144.body preserve=yes
    return CSYStateCreated::GetInstance(); // default state subsystem
  //## end CSYStateMachineEngine::GetInitializeState%1042097144.body
}

void CSYStateMachineEngine::CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList)
{
  //## begin CSYStateMachineEngine::CreateActions%1038899324.body preserve=yes
  //## end CSYStateMachineEngine::CreateActions%1038899324.body
}

void CSYStateMachineEngine::DeleteStateMachine ()
{
  //## begin CSYStateMachineEngine::DeleteStateMachine%1038899325.body preserve=yes

    CSYStateCreated::Delete();
    CSYStateShuttingDown::Delete();

	CSYStateConstitutionStartingUp::Delete();
	CSYStateConstitutionStandBy::Delete();
	CSYStateConstitutionStandByWarmingUp::Delete();
    CSYStateConstitutionConfigInterface::Delete();
    CSYStateConstitutionConnected::Delete();
    CSYStateConstitutionDownloadSoftwareComponents::Delete();
    CSYStateConstitutionReadSoftwareVersions::Delete();
    CSYStateConstitutionRegisteringUnits::Delete();
    CSYStateConstitutionConsiderInterfaceReset::Delete();
    CSYStateConstitutionResetInterface::Delete();
	CSYStateConstitutionUnregisteringUnits::Delete();
    CSYStateConstitutionDownloadStarted::Delete();

    CSYStateProcessIdle::Delete();
    CSYStateProcessReadSoftwareVersions::Delete();

	CSYStateProcessStandByConnecting::Delete();
	CSYStateProcessStandByDisconnecting::Delete();
	CSYStateProcessStandByIdle::Delete();

  //## end CSYStateMachineEngine::DeleteStateMachine%1038899325.body
}

EPIDeviceState CSYStateMachineEngine::GetDeviceState ()
{
  //## begin CSYStateMachineEngine::GetDeviceState%1056436745.body preserve=yes
    CSYState *pCurrentState = dynamic_cast<CSYState*>(m_pCurrentState);
    return pCurrentState->GetDeviceState();
  //## end CSYStateMachineEngine::GetDeviceState%1056436745.body
}

// Additional Declarations
  //## begin CSYStateMachineEngine%3EDC5B9C00AC.declarations preserve=yes
  //## end CSYStateMachineEngine%3EDC5B9C00AC.declarations

//## begin module%3EDC5B3C01EA.epilog preserve=yes
//## end module%3EDC5B3C01EA.epilog
