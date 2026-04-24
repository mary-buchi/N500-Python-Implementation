//## begin module%3DAAD53F0091.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAD53F0091.cm

//## begin module%3DAAD53F0091.cp preserve=no
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
//## end module%3DAAD53F0091.cp

//## Module: EBMCintf%3DAAD53F0091; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAD53F0091.additionalIncludes preserve=no
//## end module%3DAAD53F0091.additionalIncludes

//## begin module%3DAAD53F0091.includes preserve=yes
//## end module%3DAAD53F0091.includes

// EBMCidnt
#include "EBMCidnt.h"
// EBMCcomd
#include "EBMCcomd.h"
// EBMCimpl
#include "EBMCimpl.h"
// EBMCintf
#include "EBMCintf.h"


//## begin module%3DAAD53F0091.declarations preserve=no
//## end module%3DAAD53F0091.declarations

//## begin module%3DAAD53F0091.additionalDeclarations preserve=yes
//## end module%3DAAD53F0091.additionalDeclarations


// Class CMCMeasurementChannelInterface 


CMCMeasurementChannelInterface::CMCMeasurementChannelInterface (UINT p_uiID)
  //## begin CMCMeasurementChannelInterface::CMCMeasurementChannelInterface%1034575107.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CMCMeasurementChannelInterface::CMCMeasurementChannelInterface%1034575107.hasinit
  //## begin CMCMeasurementChannelInterface::CMCMeasurementChannelInterface%1034575107.initialization preserve=yes
  , IPIMeasurementChannelInterface(MC_ID)
  //## end CMCMeasurementChannelInterface::CMCMeasurementChannelInterface%1034575107.initialization
{
  //## begin CMCMeasurementChannelInterface::CMCMeasurementChannelInterface%1034575107.body preserve=yes
  //## end CMCMeasurementChannelInterface::CMCMeasurementChannelInterface%1034575107.body
}


CMCMeasurementChannelInterface::~CMCMeasurementChannelInterface()
{
  //## begin CMCMeasurementChannelInterface::~CMCMeasurementChannelInterface%.body preserve=yes
  //## end CMCMeasurementChannelInterface::~CMCMeasurementChannelInterface%.body
}



//## Other Operations (implementation)
void CMCMeasurementChannelInterface::InitInstance ()
{
  //## begin CMCMeasurementChannelInterface::InitInstance%1034575108.body preserve=yes
    m_pImplementation = new CMCMeasurementChannelImplementation(this);
    
    IPIMeasurementChannelInterface::InitInstance();
  //## end CMCMeasurementChannelInterface::InitInstance%1034575108.body
}

CCOSyncObject* CMCMeasurementChannelInterface::SetProfile (CPIMeasurementChannelProfile* p_pProfile)
{
  //## begin CMCMeasurementChannelInterface::SetProfile%1035789471.body preserve=yes
  return(Execute(new CMCCommandSetProfile(m_pImplementation, p_pProfile)));
  //## end CMCMeasurementChannelInterface::SetProfile%1035789471.body
}

CCOSyncObject* CMCMeasurementChannelInterface::Initialize ()
{
  //## begin CMCMeasurementChannelInterface::Initialize%1035789472.body preserve=yes
  return(Execute(new CMCCommandInitialize(m_pImplementation)));
  //## end CMCMeasurementChannelInterface::Initialize%1035789472.body
}

CCOSyncObject* CMCMeasurementChannelInterface::Start (UINT p_uiCycleID)
{
  //## begin CMCMeasurementChannelInterface::Start%1035789473.body preserve=yes
  return(Execute(new CMCCommandStart(m_pImplementation, p_uiCycleID)));
  //## end CMCMeasurementChannelInterface::Start%1035789473.body
}

CCOSyncObject* CMCMeasurementChannelInterface::Stop ()
{
  //## begin CMCMeasurementChannelInterface::Stop%1035789474.body preserve=yes
  return(Execute(new CMCCommandStop(m_pImplementation), eCOQueueHigh));
  //## end CMCMeasurementChannelInterface::Stop%1035789474.body
}

CPISyncObjDataPackage* CMCMeasurementChannelInterface::GetDataPackage ()
{
  //## begin CMCMeasurementChannelInterface::GetDataPackage%1034835013.body preserve=yes
  CO_TRACE(MC_ID, _T("CMCMeasurementChannelInterface::GetDataPackage () - Begin"));
  CPISyncObjDataPackage* l_pSyncObj = dynamic_cast<CPISyncObjDataPackage*>(Execute(new CMCCommandGetDataPackage(m_pImplementation)));
  ASSERT(l_pSyncObj != NULL);

  CO_TRACE(MC_ID, _T("CMCMeasurementChannelInterface::GetDataPackage () - End"));
  return l_pSyncObj;
  //## end CMCMeasurementChannelInterface::GetDataPackage%1034835013.body
}

CCOSyncObject* CMCMeasurementChannelInterface::ConnectionEstablished ()
{
  //## begin CMCMeasurementChannelInterface::ConnectionEstablished%1063260179.body preserve=yes
	return Execute(new CMCCommandConnectionEstablished(m_pImplementation), eCOQueueNormal);
  //## end CMCMeasurementChannelInterface::ConnectionEstablished%1063260179.body
}

CCOSyncObject* CMCMeasurementChannelInterface::ConnectionLost ()
{
  //## begin CMCMeasurementChannelInterface::ConnectionLost%1063260180.body preserve=yes
    return Execute(new CMCCommandConnectionLost(m_pImplementation), eCOQueueHigh);
  //## end CMCMeasurementChannelInterface::ConnectionLost%1063260180.body
}

//## Get and Set Operations for Associations (implementation)

UINT CMCMeasurementChannelInterface::GetuiID ()
{
  //## begin CMCMeasurementChannelInterface::GetuiID%3DAAD5A30082.get preserve=no
  return m_uiID;
  //## end CMCMeasurementChannelInterface::GetuiID%3DAAD5A30082.get
}

// Additional Declarations
  //## begin CMCMeasurementChannelInterface%3DAAD55E00BF.declarations preserve=yes
  //## end CMCMeasurementChannelInterface%3DAAD55E00BF.declarations

//## begin module%3DAAD53F0091.epilog preserve=yes
//## end module%3DAAD53F0091.epilog
