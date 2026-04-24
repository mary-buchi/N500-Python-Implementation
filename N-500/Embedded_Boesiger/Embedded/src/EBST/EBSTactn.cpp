//## begin module%3FBA385B018B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FBA385B018B.cm

//## begin module%3FBA385B018B.cp preserve=no
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
//## end module%3FBA385B018B.cp

//## Module: EBSTactn%3FBA385B018B; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTactn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FBA385B018B.additionalIncludes preserve=no
//## end module%3FBA385B018B.additionalIncludes

//## begin module%3FBA385B018B.includes preserve=yes
//## end module%3FBA385B018B.includes

// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSTactn
#include "EBSTactn.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIenum
#include "EBHIenum.h"


//## begin module%3FBA385B018B.declarations preserve=no
//## end module%3FBA385B018B.declarations

//## begin module%3FBA385B018B.additionalDeclarations preserve=yes
//## end module%3FBA385B018B.additionalDeclarations


// Class CSTActionMove 



CSTActionMove::CSTActionMove (ICOStateMachineContext* p_pContext)
  //## begin CSTActionMove::CSTActionMove%1069168815.hasinit preserve=no
      : m_dwSteps(0), m_dwSpeed(0)
  //## end CSTActionMove::CSTActionMove%1069168815.hasinit
  //## begin CSTActionMove::CSTActionMove%1069168815.initialization preserve=yes
  , CCOAction(IDA_MOVE, p_pContext)
  //## end CSTActionMove::CSTActionMove%1069168815.initialization
{
  //## begin CSTActionMove::CSTActionMove%1069168815.body preserve=yes
  //## end CSTActionMove::CSTActionMove%1069168815.body
}


CSTActionMove::~CSTActionMove()
{
  //## begin CSTActionMove::~CSTActionMove%.body preserve=yes
  //## end CSTActionMove::~CSTActionMove%.body
}



//## Other Operations (implementation)
CCOSyncObject* CSTActionMove::ExecuteAction ()
{
  //## begin CSTActionMove::ExecuteAction%1069168816.body preserve=yes
	CSTStepperMotorImplementation* l_pContext = dynamic_cast<CSTStepperMotorImplementation*>(m_pContext);
	ASSERT(l_pContext != NULL);

	if( l_pContext->GetpHwConnection()->GetbHardwarePresent() )
	{
		l_pContext->GetpHwConnection()->SetVelocity(m_dwSpeed);
		l_pContext->GetpHwConnection()->Moving(m_dwSteps);

		// wait until the moving is finish
		DWORD l_dwId = l_pContext->GetpConfig()->GetdwIDMovingTerminationEvent();
		CCOSyncObject *l_pSyncObject = NULL;
		l_pSyncObject = IHIInterface::GetInstance()->OpenEvent( l_dwId, eHIUndefined );
		ASSERT( l_pSyncObject != NULL);

		return l_pSyncObject;
	}
	else
	{
		CCOSyncObject* l_pSyncObj = new CCOSyncObject(_T("ST:ActionMove dummy"));
        l_pSyncObj->SignalCompletion();
        return l_pSyncObj;
	}
  //## end CSTActionMove::ExecuteAction%1069168816.body
}

void CSTActionMove::Done ()
{
  //## begin CSTActionMove::Done%1095785913.body preserve=yes
	CSTStepperMotorImplementation* l_pContext = dynamic_cast<CSTStepperMotorImplementation*>(m_pContext);
	ASSERT(l_pContext != NULL);

	if( l_pContext->GetpHwConnection()->GetbHardwarePresent() )
	{
		DWORD l_dwId = l_pContext->GetpConfig()->GetdwIDMovingTerminationEvent();
		if( m_pServerSyncObj != NULL )
			IHIInterface::GetInstance()->CloseEvent( l_dwId, m_pServerSyncObj );
	}

    CCOAction::Done();
  //## end CSTActionMove::Done%1095785913.body
}

void CSTActionMove::Cancel ()
{
  //## begin CSTActionMove::Cancel%1095854205.body preserve=yes
	CSTStepperMotorImplementation* l_pContext = dynamic_cast<CSTStepperMotorImplementation*>(m_pContext);
	ASSERT(l_pContext != NULL);

	if( l_pContext->GetpHwConnection()->GetbHardwarePresent() )
	{
		DWORD l_dwId = l_pContext->GetpConfig()->GetdwIDMovingTerminationEvent();
		if( m_pServerSyncObj != NULL )
			IHIInterface::GetInstance()->CloseEvent( l_dwId, m_pServerSyncObj );
	}

    CCOAction::Cancel();
  //## end CSTActionMove::Cancel%1095854205.body
}

//## Get and Set Operations for Associations (implementation)

void CSTActionMove::SetdwSteps (DWORD value)
{
  //## begin CSTActionMove::SetdwSteps%3FBA393502A5.set preserve=no
  m_dwSteps = value;
  //## end CSTActionMove::SetdwSteps%3FBA393502A5.set
}

void CSTActionMove::SetdwSpeed (DWORD value)
{
  //## begin CSTActionMove::SetdwSpeed%3FBA3D830024.set preserve=no
  m_dwSpeed = value;
  //## end CSTActionMove::SetdwSpeed%3FBA3D830024.set
}

// Additional Declarations
  //## begin CSTActionMove%3FBA381E015C.declarations preserve=yes
  //## end CSTActionMove%3FBA381E015C.declarations

//## begin module%3FBA385B018B.epilog preserve=yes
//## end module%3FBA385B018B.epilog
