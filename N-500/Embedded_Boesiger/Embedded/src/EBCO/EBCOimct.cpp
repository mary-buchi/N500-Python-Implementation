//## begin module%3B9127CD0224.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9127CD0224.cm

//## begin module%3B9127CD0224.cp preserve=no
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
//## end module%3B9127CD0224.cp

//## Module: EBCOimct%3B9127CD0224; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOimct.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B9127CD0224.additionalIncludes preserve=no
//## end module%3B9127CD0224.additionalIncludes

//## begin module%3B9127CD0224.includes preserve=yes
//## end module%3B9127CD0224.includes

// EBCOimct
#include "EBCOimct.h"
// EBCOsync
#include "EBCOsync.h"
// EBCOstat
#include "EBCOstat.h"
// EBCOcomd
#include "EBCOcomd.h"


//## begin module%3B9127CD0224.declarations preserve=no
//## end module%3B9127CD0224.declarations

//## begin module%3B9127CD0224.additionalDeclarations preserve=yes
#include <typeinfo.h>
//## end module%3B9127CD0224.additionalDeclarations


// Class CCOStateMachineEngine 







CCOStateMachineEngine::CCOStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CCOStateMachineEngine::CCOStateMachineEngine%999369756.hasinit preserve=no
      : m_pContext(p_pContext), m_pCurrentState(NULL), m_pNextState(NULL), m_pHistoryState(NULL)
  //## end CCOStateMachineEngine::CCOStateMachineEngine%999369756.hasinit
  //## begin CCOStateMachineEngine::CCOStateMachineEngine%999369756.initialization preserve=yes
  //## end CCOStateMachineEngine::CCOStateMachineEngine%999369756.initialization
{
  //## begin CCOStateMachineEngine::CCOStateMachineEngine%999369756.body preserve=yes
  //## end CCOStateMachineEngine::CCOStateMachineEngine%999369756.body
}


CCOStateMachineEngine::~CCOStateMachineEngine()
{
  //## begin CCOStateMachineEngine::~CCOStateMachineEngine%.body preserve=yes
    // delete all actions
    for (POSITION l_Pos=m_ActionMap.GetStartPosition(); l_Pos!=NULL;)
    {
        CCOAction*  l_pAction;
        UINT        l_uiActionID;

        m_ActionMap.GetNextAssoc(l_Pos, l_uiActionID, l_pAction);
        delete l_pAction;
    }
  //## end CCOStateMachineEngine::~CCOStateMachineEngine%.body
}



//## Other Operations (implementation)
void CCOStateMachineEngine::Create ()
{
  //## begin CCOStateMachineEngine::Create%1000406958.body preserve=yes
    m_pCurrentState = GetInitializeState();
    ASSERT(m_pCurrentState != NULL);

    // create actions and store it in map table
    CTypedPtrList<CPtrList, CCOAction*> l_ActionList;
    CreateActions(l_ActionList);

    for (POSITION l_Pos=l_ActionList.GetHeadPosition(); l_Pos!=NULL;)
    {
        CCOAction*  l_pAction       = l_ActionList.GetNext(l_Pos);
        UINT        l_uiActionID    = l_pAction->GetuiID();
        m_ActionMap.SetAt(l_uiActionID, l_pAction);
    }
  //## end CCOStateMachineEngine::Create%1000406958.body
}

void CCOStateMachineEngine::Run (CCOCommand* p_pCommand)
{
  //## begin CCOStateMachineEngine::Run%999369751.body preserve=yes
    bool l_bSignalCompletion = false;

    if (p_pCommand)
    {
#ifdef _DEBUG
		{
			// TRACE message command on state
			CString l_sStr;
			const type_info& l_StateInfo = typeid(*m_pCurrentState);
			const type_info& l_CmdInfo   = typeid(*p_pCommand);
			CString l_sState = l_StateInfo.name();
			CString l_sCmd   = l_CmdInfo.name();
			l_sStr.Format(_T("Executing Command '%s' on State '%s'"), (LPCTSTR)l_sCmd, (LPCTSTR)l_sState);
			CO_TRACE(m_pContext->GetsContextID(), (LPCTSTR)l_sStr);
		}
#endif

        // execute given command and signal execution
        l_bSignalCompletion = p_pCommand->Execute(m_pCurrentState);

        // signal command execution (normally not used)
        p_pCommand->SignalExecution();
    }

    // process state machine
    while (m_pNextState)
    {
#ifdef _DEBUG
		{
			// TRACE message enter state
			const type_info& l_StateInfo = typeid(*m_pCurrentState);
			CString l_sState = l_StateInfo.name();
			CO_TRACE1(m_pContext->GetsContextID(), _T("Leaving State '%s'"), (LPCTSTR)l_sState);
		}
#endif

        // exit from current state
        m_pCurrentState->Exit(m_pContext);

        // enter new state
        m_pCurrentState = m_pNextState;
        m_pNextState    = NULL;

#ifdef _DEBUG
		{
			// TRACE message enter state
			const type_info& l_StateInfo = typeid(*m_pCurrentState);
			CString l_sState = l_StateInfo.name();
			CO_TRACE1(m_pContext->GetsContextID(), _T("Entering State '%s'"), (LPCTSTR)l_sState);
		}
#endif

        m_pCurrentState->Enter(m_pContext);
        m_pCurrentState->Do(m_pContext);
    }

    if (l_bSignalCompletion)
    {
        // signal client, that the command has been executed and the state machine has
        // been processed
        p_pCommand->SignalCompletion();
    }
  //## end CCOStateMachineEngine::Run%999369751.body
}

void CCOStateMachineEngine::ChangeState (CCOState* p_pNextState, CCOActionArray& p_ActionArray)
{
  //## begin CCOStateMachineEngine::ChangeState%999369763.body preserve=yes

    // keep history
    m_pHistoryState = m_pCurrentState->SaveHistory(m_pContext);

    // keep state to enter
    m_pNextState = p_pNextState;

    if (&p_ActionArray)
    {
        // execute actions
        for (int l_iCnt=0; l_iCnt < p_ActionArray.GetSize(); l_iCnt++)
        {
            CCOAction* l_pAction = p_ActionArray.GetAt(l_iCnt);
            l_pAction->Execute();
        }
    }
  //## end CCOStateMachineEngine::ChangeState%999369763.body
}

void CCOStateMachineEngine::ChangeState (CCOState* p_pNextState, CCOAction* p_pSingleAction)
{
  //## begin CCOStateMachineEngine::ChangeState%1000925462.body preserve=yes
    CCOActionArray l_ActionArray;
    l_ActionArray.Add(p_pSingleAction);

    ChangeState(p_pNextState, l_ActionArray);
  //## end CCOStateMachineEngine::ChangeState%1000925462.body
}

void CCOStateMachineEngine::Cleanup ()
{
  //## begin CCOStateMachineEngine::Cleanup%1001240168.body preserve=yes
    // cleanup actions
    for (POSITION l_Pos=m_ActionMap.GetStartPosition(); l_Pos!=NULL;)
    {
        CCOAction*  l_pAction;
        UINT        l_uiActionID;

        m_ActionMap.GetNextAssoc(l_Pos, l_uiActionID, l_pAction);
        l_pAction->Cancel();
    }
  //## end CCOStateMachineEngine::Cleanup%1001240168.body
}

CString CCOStateMachineEngine::GetsCurrentState ()
{
  //## begin CCOStateMachineEngine::GetsCurrentState%1000031201.body preserve=yes
    if (!m_pCurrentState)
        return _T("");

    const type_info& l_TypeInfo = typeid(*m_pCurrentState);

    CString l_sState = l_TypeInfo.name();
    if (l_sState.Left(6) == "class ")
    {
        // cut off class 
        l_sState = l_sState.Right(l_sState.GetLength() - 6);
    }

    return l_sState;
  //## end CCOStateMachineEngine::GetsCurrentState%1000031201.body
}

CCOAction* CCOStateMachineEngine::GetAction (const UINT p_uiID)
{
  //## begin CCOStateMachineEngine::GetAction%1000925475.body preserve=yes
    CCOAction*  l_pAction       = NULL;
    UINT        l_uiActionID    = p_uiID;

    BOOL l_bRes = m_ActionMap.Lookup(l_uiActionID, l_pAction);
    ASSERT(l_bRes);

    return l_pAction;
  //## end CCOStateMachineEngine::GetAction%1000925475.body
}

//## Get and Set Operations for Associations (implementation)

CCOState * CCOStateMachineEngine::GetpCurrentState ()
{
  //## begin CCOStateMachineEngine::GetpCurrentState%3DA6A192023F.get preserve=no
  return m_pCurrentState;
  //## end CCOStateMachineEngine::GetpCurrentState%3DA6A192023F.get
}

CCOState * CCOStateMachineEngine::GetpNextState ()
{
  //## begin CCOStateMachineEngine::GetpNextState%3DA6A1A802FC.get preserve=no
  return m_pNextState;
  //## end CCOStateMachineEngine::GetpNextState%3DA6A1A802FC.get
}

CCOState * CCOStateMachineEngine::GetpHistoryState ()
{
  //## begin CCOStateMachineEngine::GetpHistoryState%3DA6A1BE0359.get preserve=no
  return m_pHistoryState;
  //## end CCOStateMachineEngine::GetpHistoryState%3DA6A1BE0359.get
}

// Additional Declarations
  //## begin CCOStateMachineEngine%3B91276F0143.declarations preserve=yes
  //## end CCOStateMachineEngine%3B91276F0143.declarations

// Class ICOStateMachineContext 





ICOStateMachineContext::ICOStateMachineContext()
  //## begin ICOStateMachineContext::ICOStateMachineContext%.hasinit preserve=no
      : m_pStateMachineEngine(NULL)
  //## end ICOStateMachineContext::ICOStateMachineContext%.hasinit
  //## begin ICOStateMachineContext::ICOStateMachineContext%.initialization preserve=yes
  //## end ICOStateMachineContext::ICOStateMachineContext%.initialization
{
  //## begin ICOStateMachineContext::ICOStateMachineContext%.body preserve=yes
  //## end ICOStateMachineContext::ICOStateMachineContext%.body
}


ICOStateMachineContext::~ICOStateMachineContext()
{
  //## begin ICOStateMachineContext::~ICOStateMachineContext%.body preserve=yes
    delete m_pStateMachineEngine;
    m_pStateMachineEngine = NULL;
  //## end ICOStateMachineContext::~ICOStateMachineContext%.body
}



//## Other Operations (implementation)
void ICOStateMachineContext::ChangeState (CCOState* p_pNextState, CCOActionArray& p_ActionArray)
{
  //## begin ICOStateMachineContext::ChangeState%1001010367.body preserve=yes
    m_pStateMachineEngine->ChangeState(p_pNextState, p_ActionArray);
  //## end ICOStateMachineContext::ChangeState%1001010367.body
}

void ICOStateMachineContext::ChangeState (CCOState* p_pNextState, CCOAction* p_pSingleAction)
{
  //## begin ICOStateMachineContext::ChangeState%1001010368.body preserve=yes
    m_pStateMachineEngine->ChangeState(p_pNextState, p_pSingleAction);
  //## end ICOStateMachineContext::ChangeState%1001010368.body
}

void ICOStateMachineContext::RestoreHistory ()
{
  //## begin ICOStateMachineContext::RestoreHistory%1000836380.body preserve=yes
    // history state must exist
    CCOState* l_pHistoryState = m_pStateMachineEngine->GetpHistoryState();
    ASSERT(l_pHistoryState != NULL);

    ChangeState(l_pHistoryState);
  //## end ICOStateMachineContext::RestoreHistory%1000836380.body
}

CCOAction* ICOStateMachineContext::GetAction (const UINT p_uiID)
{
  //## begin ICOStateMachineContext::GetAction%1001017246.body preserve=yes
    return m_pStateMachineEngine->GetAction(p_uiID);
  //## end ICOStateMachineContext::GetAction%1001017246.body
}

//## Get and Set Operations for Associations (implementation)

CCOStateMachineEngine * ICOStateMachineContext::GetpStateMachineEngine ()
{
  //## begin ICOStateMachineContext::GetpStateMachineEngine%3DA6A0A7029D.get preserve=no
  return m_pStateMachineEngine;
  //## end ICOStateMachineContext::GetpStateMachineEngine%3DA6A0A7029D.get
}

// Additional Declarations
  //## begin ICOStateMachineContext%3B913B7C0053.declarations preserve=yes
  //## end ICOStateMachineContext%3B913B7C0053.declarations

//## begin module%3B9127CD0224.epilog preserve=yes
//## end module%3B9127CD0224.epilog
