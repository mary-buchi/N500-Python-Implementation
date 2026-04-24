//## begin module%3F3234310266.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F3234310266.cm

//## begin module%3F3234310266.cp preserve=no
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
//## end module%3F3234310266.cp

//## Module: EBSThwconn%3F3234310266; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSThwconn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F3234310266.additionalIncludes preserve=no
//## end module%3F3234310266.additionalIncludes

//## begin module%3F3234310266.includes preserve=yes
//## end module%3F3234310266.includes

// EBCOsync
#include "EBCOsync.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTexcp
#include "EBSTexcp.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3F3234310266.declarations preserve=no
//## end module%3F3234310266.declarations

//## begin module%3F3234310266.additionalDeclarations preserve=yes
//## end module%3F3234310266.additionalDeclarations


// Class CSTHardwareConnection 






CSTHardwareConnection::CSTHardwareConnection (CSTStepperMotorImplementation* p_pContext)
  //## begin CSTHardwareConnection::CSTHardwareConnection%1060332619.hasinit preserve=no
      : m_bHardwarePresent(false), m_iHomingSteps(0), m_pContext(p_pContext), m_pMovingEvent(NULL)
  //## end CSTHardwareConnection::CSTHardwareConnection%1060332619.hasinit
  //## begin CSTHardwareConnection::CSTHardwareConnection%1060332619.initialization preserve=yes
  //## end CSTHardwareConnection::CSTHardwareConnection%1060332619.initialization
{
  //## begin CSTHardwareConnection::CSTHardwareConnection%1060332619.body preserve=yes
	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(ST_ID);

  //## end CSTHardwareConnection::CSTHardwareConnection%1060332619.body
}


CSTHardwareConnection::~CSTHardwareConnection()
{
  //## begin CSTHardwareConnection::~CSTHardwareConnection%.body preserve=yes
  //## end CSTHardwareConnection::~CSTHardwareConnection%.body
}



//## Other Operations (implementation)
void CSTHardwareConnection::SetSteps (const DWORD p_dwSteps)
{
  //## begin CSTHardwareConnection::SetSteps%1060256022.body preserve=yes

	DWORD l_dwSteps = p_dwSteps;

	// cut if value is to big
	if(l_dwSteps > CONTINUOUS)
		l_dwSteps = CONTINUOUS - 1;

	// Get ID's from config.
	DWORD l_dwStepID = m_pContext->GetpConfig()->GetdwIDStep();
	DWORD l_dwDirectionID = m_pContext->GetpConfig()->GetdwIDDirection();
	DWORD l_dwDirection = 0;

	// Get rotating direction
	EPIMotorPolarity l_ePolarity = m_pContext->GetpPositionMachine()->GetePolarity();
	switch (l_ePolarity)
	{
	case ePIMotorPolarityNormal:
	    // pos. Steps
		l_dwDirection = 0;
		CO_TRACE1(ST_ID,_T("Steps to hardware: %d"), l_dwSteps);
		break;
          
	case ePIMotorPolarityReverse:
	    // neg. Steps
		l_dwDirection = 1;
		CO_TRACE1(ST_ID,_T("Steps to hardware: %d"), -1*l_dwSteps);
		break;         		

	default:
		ASSERT(false);
	}

	if (m_bHardwarePresent)	
	{
		// Write steps to hardware.
		CHIInterface::GetInstance()->SetDWord(l_dwStepID, l_dwSteps);
		CHIInterface::GetInstance()->SetDWord(l_dwDirectionID, l_dwDirection);
	}

  //## end CSTHardwareConnection::SetSteps%1060256022.body
}

double CSTHardwareConnection::SetVelocity (const double p_dbVelocity)
{
  //## begin CSTHardwareConnection::SetVelocity%1060256024.body preserve=yes

	double m_dbFaktor = 5425.3472; // Details see "Spezificationen FPGA 030926.doc"

	// Convert speed ([Herz] or [Steps/s]) to hardware velocity.
	DWORD l_dwHWVelocity = (DWORD)((1/(double)p_dbVelocity * m_dbFaktor) + 0.5);
	
	// Get ID's from config.
	DWORD l_dwVelocitiyID = m_pContext->GetpConfig()->GetdwIDVelocity();

	CString l_sVelocityToHardware; 
	l_sVelocityToHardware.Format(_T("Velocity to hardware: %d"), l_dwHWVelocity);
	CO_TRACE(ST_ID, l_sVelocityToHardware);

	// Write to hardware.
	if (m_bHardwarePresent)
	{
		// Velocity.
		CHIInterface::GetInstance()->SetDWord(l_dwVelocitiyID, l_dwHWVelocity);
	}

	return m_dbFaktor / l_dwHWVelocity;
  //## end CSTHardwareConnection::SetVelocity%1060256024.body
}

INT CSTHardwareConnection::GetRelativePos (const int p_iPos)
{
  //## begin CSTHardwareConnection::GetRelativePos%1061458021.body preserve=yes

	// Declaration.
	int l_iRelPos = 0;
	DWORD l_dwActualDirection = 1;
    
	// Get ID's from config.
	DWORD l_dwActualPosID = m_pContext->GetpConfig()->GetdwIDActualPos();
	DWORD l_dwActualDirectionID = m_pContext->GetpConfig()->GetdwIDActualDirection();

	// Get position and direction from hardware.
	if (m_bHardwarePresent)
	{
		l_iRelPos = CHIInterface::GetInstance()->GetDWord(l_dwActualPosID);
		l_dwActualDirection = CHIInterface::GetInstance()->GetDWord(l_dwActualDirectionID);
	}
	else
	{	// Simulation.
		return p_iPos;
	}

	// Sign position. 0= Pos. direction. 1= Neg. direction.
	if (l_dwActualDirection)
		l_iRelPos*= -1;
	else
		l_iRelPos = l_iRelPos;

	// Position interpretation: moving pos steps
	// MotorPolarity eNormal	Answer form hardware is pos so position interpretation is pos
	// MotorPolarity eReverse	Answer form hardware is neg but position interpretation must be positiv

	EPIMotorPolarity l_ePolarity = m_pContext->GetpPositionMachine()->GetePolarity();

	if( l_ePolarity == ePIMotorPolarityReverse )
		l_iRelPos*= -1;  

	return l_iRelPos;

  //## end CSTHardwareConnection::GetRelativePos%1061458021.body
}

void CSTHardwareConnection::Stoping ()
{
  //## begin CSTHardwareConnection::Stoping%1064993962.body preserve=yes

	DWORD l_dwId = m_pContext->GetpConfig()->GetdwIDMovingTerminationEvent();
	CCOSyncObjectPtr l_pSyncObject = IHIInterface::GetInstance()->OpenEvent( l_dwId, eHIUndefined );
	ASSERT( l_pSyncObject != NULL);

	SetSteps(STOP);
	SetValid(eStepsValid);

	try
	{
		if( m_bHardwarePresent )
		{
			// wait until the motor has finished its moving
			l_pSyncObject->Synchronize();

			IHIInterface::GetInstance()->CloseEvent( l_dwId, l_pSyncObject );
			l_pSyncObject = NULL;
		}
		else
		{
			Sleep( 50 );
		}
	}
	catch(...)
	{
		if (l_pSyncObject)
			IHIInterface::GetInstance()->CloseEvent( l_dwId, l_pSyncObject );
	}
	
  //## end CSTHardwareConnection::Stoping%1064993962.body
}

void CSTHardwareConnection::SetValid (ESTValidType p_eValid)
{
  //## begin CSTHardwareConnection::SetValid%1066136883.body preserve=yes

	DWORD l_dwValidID = 0;

	switch(p_eValid)
	{
	case eVelocityValid:
		{
		// Get valid ID from config.
		l_dwValidID = m_pContext->GetpConfig()->GetdwIDVelValid();
		}
		break;

	case eStepsValid:
		{
		// Get valid ID from config.
		l_dwValidID = m_pContext->GetpConfig()->GetdwIDStepValid();

		}
		break;

	case eStepsAndVelocityValid:
		{
		// Get valid ID from config.
		l_dwValidID = m_pContext->GetpConfig()->GetdwIDRestartValid();
		}
		break;

	default:
		{
		ASSERT(false);
		}
		break;
	}

	if (m_bHardwarePresent)
	{
		CHIInterface::GetInstance()->SetDataValid(l_dwValidID);
	}


  //## end CSTHardwareConnection::SetValid%1066136883.body
}

void CSTHardwareConnection::Moving (const DWORD p_dwSteps)
{
  //## begin CSTHardwareConnection::Moving%1066202866.body preserve=yes
	SetSteps(p_dwSteps);
	SetValid(eStepsAndVelocityValid);
  //## end CSTHardwareConnection::Moving%1066202866.body
}

bool CSTHardwareConnection::IsActive (const DWORD p_dwInputID)
{
  //## begin CSTHardwareConnection::IsActive%1069341918.body preserve=yes

	DWORD l_dwValue = 0;
	bool l_bIsActive = false;

	if (m_bHardwarePresent)
	{
		// Get value from process image.
		l_dwValue = IHIInterface::GetInstance()->GetDWord(p_dwInputID);
		ASSERT((l_dwValue == 1) || (l_dwValue == 0));	// Return value not in range.
		l_bIsActive = (l_dwValue == 1);
	}
	else
	{	// No hardware.
		l_bIsActive = false;
	}

	return l_bIsActive;

  //## end CSTHardwareConnection::IsActive%1069341918.body
}

void CSTHardwareConnection::StartHoming (INT p_iCurrentPosition)
{
  //## begin CSTHardwareConnection::StartHoming%1193385554.body preserve=yes
	m_iHomingSteps = -p_iCurrentPosition;
  //## end CSTHardwareConnection::StartHoming%1193385554.body
}

void CSTHardwareConnection::TrackHomingSteps ()
{
  //## begin CSTHardwareConnection::TrackHomingSteps%1193385557.body preserve=yes
	DWORD l_dwActualPosID = m_pContext->GetpConfig()->GetdwIDActualPos();
	DWORD l_dwActualDirectionID = m_pContext->GetpConfig()->GetdwIDActualDirection();

	INT l_iRelPos = CHIInterface::GetInstance()->GetDWord(l_dwActualPosID);
	DWORD l_dwActualDirection = CHIInterface::GetInstance()->GetDWord(l_dwActualDirectionID);

	// Sign position. 0= Pos. direction. 1= Neg. direction.
	if (l_dwActualDirection)
		l_iRelPos*= -1;
	else
		l_iRelPos = l_iRelPos;

	m_iHomingSteps -= l_iRelPos;
  //## end CSTHardwareConnection::TrackHomingSteps%1193385557.body
}

INT CSTHardwareConnection::GetHomingSteps ()
{
  //## begin CSTHardwareConnection::GetHomingSteps%1193385555.body preserve=yes
	return m_iHomingSteps;
  //## end CSTHardwareConnection::GetHomingSteps%1193385555.body
}

//## Get and Set Operations for Class Attributes (implementation)

bool CSTHardwareConnection::GetbHardwarePresent ()
{
  //## begin CSTHardwareConnection::GetbHardwarePresent%3F423CC202F5.get preserve=no
  return m_bHardwarePresent;
  //## end CSTHardwareConnection::GetbHardwarePresent%3F423CC202F5.get
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObject * CSTHardwareConnection::GetpMovingEvent ()
{
  //## begin CSTHardwareConnection::GetpMovingEvent%415167B40271.get preserve=no
  return m_pMovingEvent;
  //## end CSTHardwareConnection::GetpMovingEvent%415167B40271.get
}

void CSTHardwareConnection::SetpMovingEvent (CCOSyncObject * value)
{
  //## begin CSTHardwareConnection::SetpMovingEvent%415167B40271.set preserve=yes
	if (m_pMovingEvent != NULL)
		m_pMovingEvent->ReleaseRef();
	m_pMovingEvent = value;
	if (m_pMovingEvent != NULL)
		m_pMovingEvent->AddRef();
  //## end CSTHardwareConnection::SetpMovingEvent%415167B40271.set
}

// Additional Declarations
  //## begin CSTHardwareConnection%3F3233A902A4.declarations preserve=yes
  //## end CSTHardwareConnection%3F3233A902A4.declarations

//## begin module%3F3234310266.epilog preserve=yes
//## end module%3F3234310266.epilog
