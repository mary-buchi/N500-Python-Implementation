//## begin module%3DA5BCCD006F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5BCCD006F.cm

//## begin module%3DA5BCCD006F.cp preserve=no
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
//## end module%3DA5BCCD006F.cp

//## Module: EBSTintf%3DA5BCCD006F; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA5BCCD006F.additionalIncludes preserve=no
//## end module%3DA5BCCD006F.additionalIncludes

//## begin module%3DA5BCCD006F.includes preserve=yes
//## end module%3DA5BCCD006F.includes

// EBSTidnt
#include "EBSTidnt.h"
// EBCOimpl
#include "EBCOimpl.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSTintf
#include "EBSTintf.h"
// EBSTcomd
#include "EBSTcomd.h"


//## begin module%3DA5BCCD006F.declarations preserve=no
//## end module%3DA5BCCD006F.declarations

//## begin module%3DA5BCCD006F.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}

//## end module%3DA5BCCD006F.additionalDeclarations


// Class CSTStepperMotorInterface 


CSTStepperMotorInterface::CSTStepperMotorInterface (UINT p_uiID)
  //## begin CSTStepperMotorInterface::CSTStepperMotorInterface%1034230439.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CSTStepperMotorInterface::CSTStepperMotorInterface%1034230439.hasinit
  //## begin CSTStepperMotorInterface::CSTStepperMotorInterface%1034230439.initialization preserve=yes
  , IPIStepperMotorInterface(ST_ID)
  //## end CSTStepperMotorInterface::CSTStepperMotorInterface%1034230439.initialization
{
  //## begin CSTStepperMotorInterface::CSTStepperMotorInterface%1034230439.body preserve=yes
  //## end CSTStepperMotorInterface::CSTStepperMotorInterface%1034230439.body
}


CSTStepperMotorInterface::~CSTStepperMotorInterface()
{
  //## begin CSTStepperMotorInterface::~CSTStepperMotorInterface%.body preserve=yes
  //## end CSTStepperMotorInterface::~CSTStepperMotorInterface%.body
}



//## Other Operations (implementation)
void CSTStepperMotorInterface::InitInstance ()
{
  //## begin CSTStepperMotorInterface::InitInstance%1034329210.body preserve=yes
    m_pImplementation = new CSTStepperMotorImplementation(this);
    
    IPIStepperMotorInterface::InitInstance();
  //## end CSTStepperMotorInterface::InitInstance%1034329210.body
}

CCOSyncObject* CSTStepperMotorInterface::MoveAbsolute (INT p_iTargetPosition, INT p_iSearchDistance)
{
  //## begin CSTStepperMotorInterface::MoveAbsolute%1035273363.body preserve=yes
    return(Execute(new CSTCommandMoveAbsolute(m_pImplementation, p_iTargetPosition, p_iSearchDistance)));
  //## end CSTStepperMotorInterface::MoveAbsolute%1035273363.body
}

CCOSyncObject* CSTStepperMotorInterface::MoveRelative (INT p_iTotalDistance, INT p_iSearchDistance)
{
  //## begin CSTStepperMotorInterface::MoveRelative%1035273364.body preserve=yes
    return(Execute(new CSTCommandMoveRelative(m_pImplementation, p_iTotalDistance, p_iSearchDistance)));
  //## end CSTStepperMotorInterface::MoveRelative%1035273364.body
}

CCOSyncObject* CSTStepperMotorInterface::MoveManual (INT p_iEndPosition, UINT p_uiSpeed)
{
  //## begin CSTStepperMotorInterface::MoveManual%1035273365.body preserve=yes
    return(Execute(new CSTCommandMoveManual(m_pImplementation, p_iEndPosition, p_uiSpeed)));
  //## end CSTStepperMotorInterface::MoveManual%1035273365.body
}

CCOSyncObjectInt* CSTStepperMotorInterface::GetPosition ()
{
  //## begin CSTStepperMotorInterface::GetPosition%1034575080.body preserve=yes
    CCOSyncObjectInt* l_pSyncObj = dynamic_cast<CCOSyncObjectInt*>(Execute(new CSTCommandGetPosition(m_pImplementation)));
    ASSERT(l_pSyncObj != NULL);

    return l_pSyncObj;
  //## end CSTStepperMotorInterface::GetPosition%1034575080.body
}

CCOSyncObject* CSTStepperMotorInterface::Stop ()
{
  //## begin CSTStepperMotorInterface::Stop%1035273366.body preserve=yes
  return(Execute(new CSTCommandStop(m_pImplementation), eCOQueueHigh));
  //## end CSTStepperMotorInterface::Stop%1035273366.body
}

CCOSyncObject* CSTStepperMotorInterface::StopImmediately ()
{
  //## begin CSTStepperMotorInterface::StopImmediately%1035273367.body preserve=yes
  return(Execute(new CSTCommandStopImmediately(m_pImplementation), eCOQueueHigh));
  //## end CSTStepperMotorInterface::StopImmediately%1035273367.body
}

CCOSyncObject* CSTStepperMotorInterface::SetProfile (CPIStepperMotorProfile* p_pProfile)
{
  //## begin CSTStepperMotorInterface::SetProfile%1035273368.body preserve=yes
  return(Execute(new CSTCommandSetProfile(m_pImplementation, p_pProfile)));
  //## end CSTStepperMotorInterface::SetProfile%1035273368.body
}

CCOSyncObjectInt* CSTStepperMotorInterface::SetSpeed (UINT p_uiSpeed)
{
  //## begin CSTStepperMotorInterface::SetSpeed%1035273369.body preserve=yes
	CCOSyncObjectInt* l_pSyncObj = dynamic_cast<CCOSyncObjectInt*>(Execute(new CSTCommandSetSpeed(m_pImplementation, p_uiSpeed)));
    ASSERT(l_pSyncObj != NULL);
 
    return l_pSyncObj;
  //## end CSTStepperMotorInterface::SetSpeed%1035273369.body
}

CCOSyncObject* CSTStepperMotorInterface::LimitAdd (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction)
{
  //## begin CSTStepperMotorInterface::LimitAdd%1035273370.body preserve=yes
  return(Execute(new CSTCommandLimitAdd(m_pImplementation, p_eLimitCharacteristics, p_eLimitAction, p_pSensorID)));
  //## end CSTStepperMotorInterface::LimitAdd%1035273370.body
}

CCOSyncObject* CSTStepperMotorInterface::LimitConfig (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction)
{
  //## begin CSTStepperMotorInterface::LimitConfig%1035273371.body preserve=yes
  return(Execute(new CSTCommandLimitConfig(m_pImplementation, p_eLimitCharacteristics, p_eLimitAction, p_pSensorID)));
  //## end CSTStepperMotorInterface::LimitConfig%1035273371.body
}

CCOSyncObject* CSTStepperMotorInterface::LimitActivate ()
{
  //## begin CSTStepperMotorInterface::LimitActivate%1035273372.body preserve=yes
  return(Execute(new CSTCommandLimitActivate(m_pImplementation)));
  //## end CSTStepperMotorInterface::LimitActivate%1035273372.body
}

CCOSyncObject* CSTStepperMotorInterface::LimitDeactivate ()
{
  //## begin CSTStepperMotorInterface::LimitDeactivate%1035273373.body preserve=yes
  return(Execute(new CSTCommandLimitDeactivate(m_pImplementation)));
  //## end CSTStepperMotorInterface::LimitDeactivate%1035273373.body
}

CCOSyncObjectInt* CSTStepperMotorInterface::Home (const EPIMotorPolarity p_eMotorPolarity, CPIObjIdentification* p_pHomeLimitID)
{
  //## begin CSTStepperMotorInterface::Home%1035273374.body preserve=yes
  return Home(p_eMotorPolarity, false, p_pHomeLimitID);
  //## end CSTStepperMotorInterface::Home%1035273374.body
}

CCOSyncObjectInt* CSTStepperMotorInterface::Home (const EPIMotorPolarity p_eFastFindDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID)
{
  //## begin CSTStepperMotorInterface::Home%1193077630.body preserve=yes
    CCOSyncObjectInt* l_pSyncObj = dynamic_cast<CCOSyncObjectInt*>(Execute(new CSTCommandHome(m_pImplementation, p_eFastFindDirection, p_bSearchLimitFromOpposite, p_pHomeLimitID)));
    ASSERT(l_pSyncObj != NULL);

    return l_pSyncObj;
  //## end CSTStepperMotorInterface::Home%1193077630.body
}

CCOSyncObject* CSTStepperMotorInterface::HomeSetPosition (INT p_iPosition)
{
  //## begin CSTStepperMotorInterface::HomeSetPosition%1035273375.body preserve=yes
  return(Execute(new CSTCommandHomeSetPosition(m_pImplementation, p_iPosition)));
  //## end CSTStepperMotorInterface::HomeSetPosition%1035273375.body
}

CCOSyncObjectIntArray* CSTStepperMotorInterface::LimitGetFootPrint ()
{
  //## begin CSTStepperMotorInterface::LimitGetFootPrint%1035273376.body preserve=yes
  CCOSyncObjectIntArray* l_pSyncObj = dynamic_cast<CCOSyncObjectIntArray*>(Execute(new CSTCommandLimitGetFootPrint(m_pImplementation)));
  ASSERT(l_pSyncObj != NULL);

  return l_pSyncObj;

  //## end CSTStepperMotorInterface::LimitGetFootPrint%1035273376.body
}

CCOSyncObject* CSTStepperMotorInterface::SetConfig (CPIStepperMotorConfig* p_pConfig)
{
  //## begin CSTStepperMotorInterface::SetConfig%1048149993.body preserve=yes
	return(Execute(new CSTCommandSetConfig(m_pImplementation, p_pConfig)));
  //## end CSTStepperMotorInterface::SetConfig%1048149993.body
}

CCOSyncObject* CSTStepperMotorInterface::OnLimitHit (CPIObjIdentification* p_pLimitSwitch)
{
  //## begin CSTStepperMotorInterface::OnLimitHit%1048581159.body preserve=yes
	return(Execute(new CSTCommandOnLimitHit(m_pImplementation, p_pLimitSwitch), eCOQueueAboveNormal));
  //## end CSTStepperMotorInterface::OnLimitHit%1048581159.body
}

CSTStepperMotorImplementation* CSTStepperMotorInterface::GetpImplementation ()
{
  //## begin CSTStepperMotorInterface::GetpImplementation%1049871950.body preserve=yes
	CSTStepperMotorImplementation* l_pImpl = dynamic_cast<CSTStepperMotorImplementation*>(m_pImplementation);
	ASSERT(l_pImpl != NULL);
	return l_pImpl;
  //## end CSTStepperMotorInterface::GetpImplementation%1049871950.body
}

//## Get and Set Operations for Associations (implementation)

UINT CSTStepperMotorInterface::GetuiID ()
{
  //## begin CSTStepperMotorInterface::GetuiID%3DA537A10078.get preserve=no
  return m_uiID;
  //## end CSTStepperMotorInterface::GetuiID%3DA537A10078.get
}

// Additional Declarations
  //## begin CSTStepperMotorInterface%3DA5340400AE.declarations preserve=yes
  //## end CSTStepperMotorInterface%3DA5340400AE.declarations

//## begin module%3DA5BCCD006F.epilog preserve=yes
//## end module%3DA5BCCD006F.epilog
