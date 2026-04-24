//## begin module%3DE5EB3D0208.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB3D0208.cm

//## begin module%3DE5EB3D0208.cp preserve=no
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
//## end module%3DE5EB3D0208.cp

//## Module: EBPOstat%3DE5EB3D0208; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EB3D0208.additionalIncludes preserve=no
//## end module%3DE5EB3D0208.additionalIncludes

//## begin module%3DE5EB3D0208.includes preserve=yes
//## end module%3DE5EB3D0208.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOimct
#include "EBCOimct.h"
// EBPOcnfg
#include "EBPOcnfg.h"
// EBPOstat
#include "EBPOstat.h"
// EBPOidnt
#include "EBPOidnt.h"
//## begin module%3DE5EB3D0208.declarations preserve=no
//## end module%3DE5EB3D0208.declarations

//## begin module%3DE5EB3D0208.additionalDeclarations preserve=yes
//## end module%3DE5EB3D0208.additionalDeclarations


// Class CPOState 

CPOState::CPOState()
  //## begin CPOState::CPOState%.hasinit preserve=no
  //## end CPOState::CPOState%.hasinit
  //## begin CPOState::CPOState%.initialization preserve=yes
  //## end CPOState::CPOState%.initialization
{
  //## begin CPOState::CPOState%.body preserve=yes
  //## end CPOState::CPOState%.body
}


CPOState::~CPOState()
{
  //## begin CPOState::~CPOState%.body preserve=yes
  //## end CPOState::~CPOState%.body
}



//## Other Operations (implementation)
void CPOState::ReadParameters (ICOStateMachineContext* p_pContext, CPISyncObjListPersistentItems *p_pSyncObjParameters)
{
  //## begin CPOState::ReadParameters%1066888959.body preserve=yes
  	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::ReadParameters%1066888959.body
}

void CPOState::WriteParameter (ICOStateMachineContext* p_pContext, CPIPersistentPara* p_pParameter)
{
  //## begin CPOState::WriteParameter%1066888960.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::WriteParameter%1066888960.body
}

void CPOState::StartMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice)
{
  //## begin CPOState::StartMonitoring%1066888961.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::StartMonitoring%1066888961.body
}

void CPOState::StopMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice)
{
  //## begin CPOState::StopMonitoring%1066888962.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::StopMonitoring%1066888962.body
}

void CPOState::Save (ICOStateMachineContext* p_pContext)
{
  //## begin CPOState::Save%1066888963.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::Save%1066888963.body
}

void CPOState::ReadLifeTimeCounter (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj, EPILifeTimeCounter p_eCounter)
{
  //## begin CPOState::ReadLifeTimeCounter%1066888964.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::ReadLifeTimeCounter%1066888964.body
}

void CPOState::WriteLifeTimeCounter (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eCounter, const UINT &p_uiValue)
{
  //## begin CPOState::WriteLifeTimeCounter%1066888965.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::WriteLifeTimeCounter%1066888965.body
}

void CPOState::ReadIdentifications (ICOStateMachineContext* p_pContext, CPISyncObjListPersistentItems *p_pSyncObjParameters)
{
  //## begin CPOState::ReadIdentifications%1066888966.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::ReadIdentifications%1066888966.body
}

void CPOState::WriteIdentification (ICOStateMachineContext* p_pContext, CPIPersistentIdent* p_pIdentification)
{
  //## begin CPOState::WriteIdentification%1066888967.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::WriteIdentification%1066888967.body
}

void CPOState::SetConfig (ICOStateMachineContext* p_pContext, CPIPersistentConfig* p_pConfig)
{
  //## begin CPOState::SetConfig%1066888968.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::SetConfig%1066888968.body
}

CPOPersistentObjImplementation* CPOState::GetpImpl (ICOStateMachineContext* p_pContext)
{
  //## begin CPOState::GetpImpl%1067243912.body preserve=yes
	CPOPersistentObjImplementation* l_pContext;
	l_pContext = dynamic_cast<CPOPersistentObjImplementation*>(p_pContext);
	ASSERT(l_pContext != NULL);
	return l_pContext;
  //## end CPOState::GetpImpl%1067243912.body
}

void CPOState::Reset (ICOStateMachineContext* p_pContext, EPIEpromSection p_eSection)
{
  //## begin CPOState::Reset%1072788296.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::Reset%1072788296.body
}

void CPOState::MeasurementCellUndocked (ICOStateMachineContext* p_pContext)
{
  //## begin CPOState::MeasurementCellUndocked%1080142970.body preserve=yes
	XCO_INVALID_STATE(PO_ID);
  //## end CPOState::MeasurementCellUndocked%1080142970.body
}

// Additional Declarations
  //## begin CPOState%3DE63804016C.declarations preserve=yes
  //## end CPOState%3DE63804016C.declarations

// Class CPOStateCreated 

//## begin CPOStateCreated::pInstance%3DE63BEF0360.role preserve=no  public: static CPOStateCreated {1..1 -> 1..1RFHN}
CPOStateCreated *CPOStateCreated::m_pInstance;
//## end CPOStateCreated::pInstance%3DE63BEF0360.role


CPOStateCreated::CPOStateCreated()
  //## begin CPOStateCreated::CPOStateCreated%.hasinit preserve=no
  //## end CPOStateCreated::CPOStateCreated%.hasinit
  //## begin CPOStateCreated::CPOStateCreated%.initialization preserve=yes
  //## end CPOStateCreated::CPOStateCreated%.initialization
{
  //## begin CPOStateCreated::CPOStateCreated%.body preserve=yes
  //## end CPOStateCreated::CPOStateCreated%.body
}


CPOStateCreated::~CPOStateCreated()
{
  //## begin CPOStateCreated::~CPOStateCreated%.body preserve=yes
  //## end CPOStateCreated::~CPOStateCreated%.body
}



//## Other Operations (implementation)
void CPOStateCreated::Create ()
{
  //## begin CPOStateCreated::Create%1038495068.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateCreated();
  //## end CPOStateCreated::Create%1038495068.body
}

void CPOStateCreated::Delete ()
{
  //## begin CPOStateCreated::Delete%1038495069.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateCreated::Delete%1038495069.body
}

CPOStateCreated* CPOStateCreated::GetInstance ()
{
  //## begin CPOStateCreated::GetInstance%1038495070.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateCreated::GetInstance%1038495070.body
}

void CPOStateCreated::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateCreated::Startup%1038495071.body preserve=yes
	p_pContext->ChangeState(CPOStateConfigStart::GetInstance());
  //## end CPOStateCreated::Startup%1038495071.body
}

void CPOStateCreated::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateCreated::Shutdown%1038495072.body preserve=yes
  //## end CPOStateCreated::Shutdown%1038495072.body
}

void CPOStateCreated::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateCreated::ConnectionEstablished%1063223341.body preserve=yes
  //## end CPOStateCreated::ConnectionEstablished%1063223341.body
}

void CPOStateCreated::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateCreated::ConnectionLost%1063223342.body preserve=yes
  //## end CPOStateCreated::ConnectionLost%1063223342.body
}

// Additional Declarations
  //## begin CPOStateCreated%3DE63B310321.declarations preserve=yes
  //## end CPOStateCreated%3DE63B310321.declarations

//## begin module%3DE5EB3D0208.epilog preserve=yes
//## end module%3DE5EB3D0208.epilog
