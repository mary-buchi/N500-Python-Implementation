//## begin module%3BA8E6D902DA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA8E6D902DA.cm

//## begin module%3BA8E6D902DA.cp preserve=no
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
//## end module%3BA8E6D902DA.cp

//## Module: EBCOactn%3BA8E6D902DA; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOactn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3BA8E6D902DA.additionalIncludes preserve=no
//## end module%3BA8E6D902DA.additionalIncludes

//## begin module%3BA8E6D902DA.includes preserve=yes
//## end module%3BA8E6D902DA.includes

// EBCOactn
#include "EBCOactn.h"
// EBCOimct
#include "EBCOimct.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"


//## begin module%3BA8E6D902DA.declarations preserve=no
//## end module%3BA8E6D902DA.declarations

//## begin module%3BA8E6D902DA.additionalDeclarations preserve=yes
//## end module%3BA8E6D902DA.additionalDeclarations


// Class CCOAction 






CCOAction::CCOAction (const UINT p_uiID, ICOStateMachineContext* p_pContext)
  //## begin CCOAction::CCOAction%1000925467.hasinit preserve=no
      : m_uiID(p_uiID), m_pClientSyncObj(NULL), m_pServerSyncObj(NULL), m_pContext(p_pContext)
  //## end CCOAction::CCOAction%1000925467.hasinit
  //## begin CCOAction::CCOAction%1000925467.initialization preserve=yes
  //## end CCOAction::CCOAction%1000925467.initialization
{
  //## begin CCOAction::CCOAction%1000925467.body preserve=yes
  //## end CCOAction::CCOAction%1000925467.body
}


CCOAction::~CCOAction()
{
  //## begin CCOAction::~CCOAction%.body preserve=yes
  //## end CCOAction::~CCOAction%.body
}



//## Other Operations (implementation)
void CCOAction::Execute ()
{
  //## begin CCOAction::Execute%1000925464.body preserve=yes
    // previously stored sync object must be reset at this time
    ASSERT(m_pServerSyncObj == NULL);

    // ok, execute action
    m_pServerSyncObj = ExecuteAction();
  //## end CCOAction::Execute%1000925464.body
}

void CCOAction::Cancel ()
{
  //## begin CCOAction::Cancel%1000925463.body preserve=yes
    // cancel existing sync objects
    if (m_pClientSyncObj)
    {
        m_pClientSyncObj->AttachException(
            new XCOExceptionCleanupStop(m_pContext->GetsContextID(), IDE_CORE_CLEANUP_STOP, __FILE__, __LINE__));
        m_pClientSyncObj->ReleaseRef();
        m_pClientSyncObj = NULL;
    }

    if (m_pServerSyncObj)
    {
        m_pServerSyncObj->AttachException(
            new XCOExceptionCleanupStop(m_pContext->GetsContextID(), IDE_CORE_CLEANUP_STOP, __FILE__, __LINE__));
        m_pServerSyncObj->ReleaseRef();
        m_pServerSyncObj = NULL;
    }
  //## end CCOAction::Cancel%1000925463.body
}

void CCOAction::Done ()
{
  //## begin CCOAction::Done%1000925468.body preserve=yes
    ASSERT(m_pServerSyncObj != NULL);
    m_pServerSyncObj->ReleaseRef();
    m_pServerSyncObj = NULL;

    // signal client, if it exists
    if (m_pClientSyncObj)
    {
        m_pClientSyncObj->SignalCompletion();
        m_pClientSyncObj->ReleaseRef();
        m_pClientSyncObj = NULL;
    }
  //## end CCOAction::Done%1000925468.body
}

void CCOAction::SetpClientSyncObj (CCOSyncObject* p_pSyncObject)
{
  //## begin CCOAction::SetpClientSyncObj%1000925469.body preserve=yes
    // destroy previously stored sync object
    if (m_pClientSyncObj)
    {
        m_pClientSyncObj->ReleaseRef();
        m_pClientSyncObj = NULL;
    }

    m_pClientSyncObj = p_pSyncObject;
    if (m_pClientSyncObj)
        m_pClientSyncObj->AddRef();
  //## end CCOAction::SetpClientSyncObj%1000925469.body
}

//## Get and Set Operations for Class Attributes (implementation)

UINT CCOAction::GetuiID ()
{
  //## begin CCOAction::GetuiID%3BA9001B0346.get preserve=no
  return m_uiID;
  //## end CCOAction::GetuiID%3BA9001B0346.get
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObject * CCOAction::GetpClientSyncObj ()
{
  //## begin CCOAction::GetpClientSyncObj%3DA69BAD0231.get preserve=no
  return m_pClientSyncObj;
  //## end CCOAction::GetpClientSyncObj%3DA69BAD0231.get
}

CCOSyncObject * CCOAction::GetpServerSyncObj ()
{
  //## begin CCOAction::GetpServerSyncObj%3DA69BB1004C.get preserve=no
  return m_pServerSyncObj;
  //## end CCOAction::GetpServerSyncObj%3DA69BB1004C.get
}

// Additional Declarations
  //## begin CCOAction%3BA8E6F2039E.declarations preserve=yes
  //## end CCOAction%3BA8E6F2039E.declarations

//## begin CCOActionArray.instantiation preserve=no
template class CTypedPtrArray< CPtrArray,CCOAction* >;
//## end CCOActionArray.instantiation
//## begin module%3BA8E6D902DA.epilog preserve=yes
//## end module%3BA8E6D902DA.epilog
