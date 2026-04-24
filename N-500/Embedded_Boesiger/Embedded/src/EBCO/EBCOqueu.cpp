//## begin module%3B8D4D4A022F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D4D4A022F.cm

//## begin module%3B8D4D4A022F.cp preserve=no
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
//## end module%3B8D4D4A022F.cp

//## Module: EBCOqueu%3B8D4D4A022F; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOqueu.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B8D4D4A022F.additionalIncludes preserve=no
//## end module%3B8D4D4A022F.additionalIncludes

//## begin module%3B8D4D4A022F.includes preserve=yes
//## end module%3B8D4D4A022F.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOidnt
#include "EBCOidnt.h"
// EBCOcomd
#include "EBCOcomd.h"
// EBCOqueu
#include "EBCOqueu.h"


//## begin module%3B8D4D4A022F.declarations preserve=no
//## end module%3B8D4D4A022F.declarations

//## begin module%3B8D4D4A022F.additionalDeclarations preserve=yes
#include <typeinfo.h>
//## end module%3B8D4D4A022F.additionalDeclarations


// Class CCOCommandQueue 







CCOCommandQueue::CCOCommandQueue (ECOAsyncCallQueue p_eQueueType)
  //## begin CCOCommandQueue::CCOCommandQueue%1066286189.hasinit preserve=no
      : m_bSuspended(false), m_eQueueType(p_eQueueType)
  //## end CCOCommandQueue::CCOCommandQueue%1066286189.hasinit
  //## begin CCOCommandQueue::CCOCommandQueue%1066286189.initialization preserve=yes
  //## end CCOCommandQueue::CCOCommandQueue%1066286189.initialization
{
  //## begin CCOCommandQueue::CCOCommandQueue%1066286189.body preserve=yes
  //## end CCOCommandQueue::CCOCommandQueue%1066286189.body
}


CCOCommandQueue::~CCOCommandQueue()
{
  //## begin CCOCommandQueue::~CCOCommandQueue%.body preserve=yes
  //## end CCOCommandQueue::~CCOCommandQueue%.body
}



//## Other Operations (implementation)
void CCOCommandQueue::AddTail (CCOCommand* p_pCommand, const bool p_bUniqCommand)
{
  //## begin CCOCommandQueue::AddTail%999108319.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

    if (!p_bUniqCommand || IsUniq(p_pCommand))
    {
	    m_Commands.AddTail(p_pCommand);

        if (!m_bSuspended)
        {
	        // signal event
	        m_QueueEvent.SetEvent();
        }
    }
  //## end CCOCommandQueue::AddTail%999108319.body
}

CCOCommand* CCOCommandQueue::RemoveHead ()
{
  //## begin CCOCommandQueue::RemoveHead%999108320.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

	if (m_Commands.GetCount() == 0)
    {
        // no command in the queue any more. This might happen due to
        // a SkipCommand call (Timer events)
        m_QueueEvent.ResetEvent();
        return NULL;
    }

	// if we got just one command in the queue then we can reset the event
	if (m_Commands.GetCount() == 1)
	{
		m_QueueEvent.ResetEvent();
	}
    else
        m_QueueEvent.SetEvent();

	return m_Commands.RemoveHead();
  //## end CCOCommandQueue::RemoveHead%999108320.body
}

void CCOCommandQueue::Suspend ()
{
  //## begin CCOCommandQueue::Suspend%1000752287.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

    m_bSuspended = true;
  //## end CCOCommandQueue::Suspend%1000752287.body
}

void CCOCommandQueue::Resume ()
{
  //## begin CCOCommandQueue::Resume%1000752288.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

    m_bSuspended = false;

    if (m_Commands.GetCount())
    {
        m_QueueEvent.SetEvent();
    }
  //## end CCOCommandQueue::Resume%1000752288.body
}

void CCOCommandQueue::Flush ()
{
  //## begin CCOCommandQueue::Flush%1000752289.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

    m_bSuspended = false;

    // skip all commands in queue
    for (POSITION l_Pos=m_Commands.GetHeadPosition(); l_Pos!=NULL;)
    {
        CCOCommand* l_pCmd = m_Commands.GetNext(l_Pos);

        l_pCmd->AttachException(new XCOExceptionCleanupStop(CO_ID, 0, __FILE__,__LINE__));
        delete l_pCmd;
    }

    m_Commands.RemoveAll();
    m_QueueEvent.ResetEvent();
  //## end CCOCommandQueue::Flush%1000752289.body
}

void CCOCommandQueue::SkipCommand (const type_info& p_CommandType)
{
  //## begin CCOCommandQueue::SkipCommand%1053348765.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

    for(POSITION l_Pos=m_Commands.GetHeadPosition(); l_Pos!=NULL;)
    {
        POSITION l_CurPos = l_Pos;
        const type_info& l_CmdType = typeid(m_Commands.GetNext(l_Pos));
        if (l_CmdType == p_CommandType)
        {
            m_Commands.RemoveAt(l_CurPos);
        }
    }

    if (m_Commands.GetCount() == 0)
        m_QueueEvent.ResetEvent();
  //## end CCOCommandQueue::SkipCommand%1053348765.body
}

bool CCOCommandQueue::IsUniq (CCOCommand* p_pCommand)
{
  //## begin CCOCommandQueue::IsUniq%1053348764.body preserve=yes
    const type_info& l_CmdInfoRef = typeid(p_pCommand);

    for (POSITION l_Pos=m_Commands.GetHeadPosition(); l_Pos!=NULL;)
    {
        CCOCommand* l_pCmd = m_Commands.GetNext(l_Pos);
        const type_info& l_CmdInfo = typeid(l_pCmd);
        if (l_CmdInfo == l_CmdInfoRef)
            return false;
    }

    return true;
  //## end CCOCommandQueue::IsUniq%1053348764.body
}

//## Get and Set Operations for Associations (implementation)

CEvent& CCOCommandQueue::GetQueueEvent ()
{
  //## begin CCOCommandQueue::GetQueueEvent%3DA69EA601F2.get preserve=no
  return m_QueueEvent;
  //## end CCOCommandQueue::GetQueueEvent%3DA69EA601F2.get
}

// Additional Declarations
  //## begin CCOCommandQueue%3B8D4D120026.declarations preserve=yes
  //## end CCOCommandQueue%3B8D4D120026.declarations

//## begin module%3B8D4D4A022F.epilog preserve=yes
//## end module%3B8D4D4A022F.epilog
