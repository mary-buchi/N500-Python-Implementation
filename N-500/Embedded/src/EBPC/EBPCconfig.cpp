//## begin module%3EED769F0383.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0383.cm

//## begin module%3EED769F0383.cp preserve=no
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
//## end module%3EED769F0383.cp

//## Module: EBPCconfig%3EED769F0383; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCconfig.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F0383.additionalIncludes preserve=no
//## end module%3EED769F0383.additionalIncludes

//## begin module%3EED769F0383.includes preserve=yes
//## end module%3EED769F0383.includes

// EBCOimct
#include "EBCOimct.h"
// EBPItype
#include "EBPItype.h"
// EBPCconn
#include "EBPCconn.h"
// EBPClogic
#include "EBPClogic.h"
// EBPCconfig
#include "EBPCconfig.h"
// EBPCidle
#include "EBPCidle.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCcrea
#include "EBPCcrea.h"
// EBPCident
#include "EBPCident.h"
// EBPCpid
#include "EBPCpid.h"
//## begin module%3EED769F0383.declarations preserve=no
//## end module%3EED769F0383.declarations

//## begin module%3EED769F0383.additionalDeclarations preserve=yes
//## end module%3EED769F0383.additionalDeclarations


// Class CPCStateConfigNotSet 

//## begin CPCStateConfigNotSet::pInstance%3EED76CC08C0.role preserve=no  public: static CPCStateConfigNotSet {1..1 -> 1..1RFHN}
CPCStateConfigNotSet *CPCStateConfigNotSet::m_pInstance;
//## end CPCStateConfigNotSet::pInstance%3EED76CC08C0.role


CPCStateConfigNotSet::CPCStateConfigNotSet()
  //## begin CPCStateConfigNotSet::CPCStateConfigNotSet%.hasinit preserve=no
  //## end CPCStateConfigNotSet::CPCStateConfigNotSet%.hasinit
  //## begin CPCStateConfigNotSet::CPCStateConfigNotSet%.initialization preserve=yes
  //## end CPCStateConfigNotSet::CPCStateConfigNotSet%.initialization
{
  //## begin CPCStateConfigNotSet::CPCStateConfigNotSet%.body preserve=yes
  //## end CPCStateConfigNotSet::CPCStateConfigNotSet%.body
}


CPCStateConfigNotSet::~CPCStateConfigNotSet()
{
  //## begin CPCStateConfigNotSet::~CPCStateConfigNotSet%.body preserve=yes
  //## end CPCStateConfigNotSet::~CPCStateConfigNotSet%.body
}



//## Other Operations (implementation)
void CPCStateConfigNotSet::Create ()
{
  //## begin CPCStateConfigNotSet::Create%1044457421.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateConfigNotSet();
  //## end CPCStateConfigNotSet::Create%1044457421.body
}

CPCStateConfigNotSet* CPCStateConfigNotSet::GetInstance ()
{
  //## begin CPCStateConfigNotSet::GetInstance%1044457422.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateConfigNotSet::GetInstance%1044457422.body
}

void CPCStateConfigNotSet::Delete ()
{
  //## begin CPCStateConfigNotSet::Delete%1038899332.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateConfigNotSet::Delete%1038899332.body
}

// Additional Declarations
  //## begin CPCStateConfigNotSet%3EED76CC068D.declarations preserve=yes
  //## end CPCStateConfigNotSet%3EED76CC068D.declarations

// Class CPCStateConfig 

CPCStateConfig::CPCStateConfig()
  //## begin CPCStateConfig::CPCStateConfig%.hasinit preserve=no
  //## end CPCStateConfig::CPCStateConfig%.hasinit
  //## begin CPCStateConfig::CPCStateConfig%.initialization preserve=yes
  //## end CPCStateConfig::CPCStateConfig%.initialization
{
  //## begin CPCStateConfig::CPCStateConfig%.body preserve=yes
  //## end CPCStateConfig::CPCStateConfig%.body
}


CPCStateConfig::~CPCStateConfig()
{
  //## begin CPCStateConfig::~CPCStateConfig%.body preserve=yes
  //## end CPCStateConfig::~CPCStateConfig%.body
}



//## Other Operations (implementation)
void CPCStateConfig::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateConfig::Shutdown%1044457420.body preserve=yes
	 p_pContext->ChangeState(CPCStateCreated::GetInstance());
  //## end CPCStateConfig::Shutdown%1044457420.body
}

void CPCStateConfig::SetConfiguration (ICOStateMachineContext* p_pContext, CPIPowerControlConfig* p_pConfig)
{
  //## begin CPCStateConfig::SetConfiguration%1044604253.body preserve=yes
	GetpImplementation(p_pContext)->SetpConfig(p_pConfig);
    p_pContext->ChangeState(CPCStateConfigSet::GetInstance());
  //## end CPCStateConfig::SetConfiguration%1044604253.body
}

void CPCStateConfig::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateConfig::CleanupInitialize%1055317629.body preserve=yes
	GetpImplementation(p_pContext)->GetpLogic()->PowerOff();
	p_pContext->ChangeState(CPCStateCreated::GetInstance());
  //## end CPCStateConfig::CleanupInitialize%1055317629.body
}

void CPCStateConfig::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateConfig::ConnectionLost%1055335989.body preserve=yes
	p_pContext->ChangeState( CPCStateNotConnectedNoConfig::GetInstance() );
  //## end CPCStateConfig::ConnectionLost%1055335989.body
}

void CPCStateConfig::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateConfig::Startup%1063717517.body preserve=yes
	p_pContext->ChangeState(CPCStateConfigNotSet::GetInstance());
  //## end CPCStateConfig::Startup%1063717517.body
}

// Additional Declarations
  //## begin CPCStateConfig%3EED76CC069A.declarations preserve=yes
  //## end CPCStateConfig%3EED76CC069A.declarations

// Class CPCStateConfigProfileNotSet 

//## begin CPCStateConfigProfileNotSet::pInstance%3EED76CC08B0.role preserve=no  public: static CPCStateConfigProfileNotSet {1..1 -> 1..1RFHN}
CPCStateConfigProfileNotSet *CPCStateConfigProfileNotSet::m_pInstance;
//## end CPCStateConfigProfileNotSet::pInstance%3EED76CC08B0.role


CPCStateConfigProfileNotSet::CPCStateConfigProfileNotSet()
  //## begin CPCStateConfigProfileNotSet::CPCStateConfigProfileNotSet%.hasinit preserve=no
  //## end CPCStateConfigProfileNotSet::CPCStateConfigProfileNotSet%.hasinit
  //## begin CPCStateConfigProfileNotSet::CPCStateConfigProfileNotSet%.initialization preserve=yes
  //## end CPCStateConfigProfileNotSet::CPCStateConfigProfileNotSet%.initialization
{
  //## begin CPCStateConfigProfileNotSet::CPCStateConfigProfileNotSet%.body preserve=yes
  //## end CPCStateConfigProfileNotSet::CPCStateConfigProfileNotSet%.body
}


CPCStateConfigProfileNotSet::~CPCStateConfigProfileNotSet()
{
  //## begin CPCStateConfigProfileNotSet::~CPCStateConfigProfileNotSet%.body preserve=yes
  //## end CPCStateConfigProfileNotSet::~CPCStateConfigProfileNotSet%.body
}



//## Other Operations (implementation)
void CPCStateConfigProfileNotSet::Delete ()
{
  //## begin CPCStateConfigProfileNotSet::Delete%1044522141.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateConfigProfileNotSet::Delete%1044522141.body
}

void CPCStateConfigProfileNotSet::Create ()
{
  //## begin CPCStateConfigProfileNotSet::Create%1044522142.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateConfigProfileNotSet();
  //## end CPCStateConfigProfileNotSet::Create%1044522142.body
}

CPCStateConfigProfileNotSet* CPCStateConfigProfileNotSet::GetInstance ()
{
  //## begin CPCStateConfigProfileNotSet::GetInstance%1044522143.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateConfigProfileNotSet::GetInstance%1044522143.body
}

void CPCStateConfigProfileNotSet::SetProfile (ICOStateMachineContext* p_pContext, CPIPowerControlProfile* p_pProfile)
{
  //## begin CPCStateConfigProfileNotSet::SetProfile%1044604256.body preserve=yes
	GetpImplementation(p_pContext)->SetpProfile(p_pProfile);
	p_pContext->ChangeState(CPCStateConfigProfileSet::GetInstance());
  //## end CPCStateConfigProfileNotSet::SetProfile%1044604256.body
}

// Additional Declarations
  //## begin CPCStateConfigProfileNotSet%3EED76CC06ED.declarations preserve=yes
  //## end CPCStateConfigProfileNotSet%3EED76CC06ED.declarations

// Class CPCStateConfigProfileSet 

//## begin CPCStateConfigProfileSet::pInstance%3EED76CC08B8.role preserve=no  public: static CPCStateConfigProfileSet {1..1 -> 1..1RFHN}
CPCStateConfigProfileSet *CPCStateConfigProfileSet::m_pInstance;
//## end CPCStateConfigProfileSet::pInstance%3EED76CC08B8.role


CPCStateConfigProfileSet::CPCStateConfigProfileSet()
  //## begin CPCStateConfigProfileSet::CPCStateConfigProfileSet%.hasinit preserve=no
  //## end CPCStateConfigProfileSet::CPCStateConfigProfileSet%.hasinit
  //## begin CPCStateConfigProfileSet::CPCStateConfigProfileSet%.initialization preserve=yes
  //## end CPCStateConfigProfileSet::CPCStateConfigProfileSet%.initialization
{
  //## begin CPCStateConfigProfileSet::CPCStateConfigProfileSet%.body preserve=yes
  //## end CPCStateConfigProfileSet::CPCStateConfigProfileSet%.body
}


CPCStateConfigProfileSet::~CPCStateConfigProfileSet()
{
  //## begin CPCStateConfigProfileSet::~CPCStateConfigProfileSet%.body preserve=yes
  //## end CPCStateConfigProfileSet::~CPCStateConfigProfileSet%.body
}



//## Other Operations (implementation)
void CPCStateConfigProfileSet::Delete ()
{
  //## begin CPCStateConfigProfileSet::Delete%1044522144.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateConfigProfileSet::Delete%1044522144.body
}

void CPCStateConfigProfileSet::Create ()
{
  //## begin CPCStateConfigProfileSet::Create%1044522145.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateConfigProfileSet();
  //## end CPCStateConfigProfileSet::Create%1044522145.body
}

CPCStateConfigProfileSet* CPCStateConfigProfileSet::GetInstance ()
{
  //## begin CPCStateConfigProfileSet::GetInstance%1044522146.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateConfigProfileSet::GetInstance%1044522146.body
}

void CPCStateConfigProfileSet::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateConfigProfileSet::Do%1076339192.body preserve=yes
	p_pContext->ChangeState(CPCStateIdleCheckPower::GetInstance());
  //## end CPCStateConfigProfileSet::Do%1076339192.body
}

// Additional Declarations
  //## begin CPCStateConfigProfileSet%3EED76CC0701.declarations preserve=yes
  //## end CPCStateConfigProfileSet%3EED76CC0701.declarations

// Class CPCStateConfigSet 

//## begin CPCStateConfigSet::pInstance%3EED76CC08D8.role preserve=no  public: static CPCStateConfigSet {1..1 -> 1..1RFHN}
CPCStateConfigSet *CPCStateConfigSet::m_pInstance;
//## end CPCStateConfigSet::pInstance%3EED76CC08D8.role



CPCStateConfigSet::CPCStateConfigSet()
  //## begin CPCStateConfigSet::CPCStateConfigSet%.hasinit preserve=no
  //## end CPCStateConfigSet::CPCStateConfigSet%.hasinit
  //## begin CPCStateConfigSet::CPCStateConfigSet%.initialization preserve=yes
  //## end CPCStateConfigSet::CPCStateConfigSet%.initialization
{
  //## begin CPCStateConfigSet::CPCStateConfigSet%.body preserve=yes
  //## end CPCStateConfigSet::CPCStateConfigSet%.body
}


CPCStateConfigSet::~CPCStateConfigSet()
{
  //## begin CPCStateConfigSet::~CPCStateConfigSet%.body preserve=yes
  //## end CPCStateConfigSet::~CPCStateConfigSet%.body
}



//## Other Operations (implementation)
void CPCStateConfigSet::Create ()
{
  //## begin CPCStateConfigSet::Create%1044522148.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateConfigSet();
  //## end CPCStateConfigSet::Create%1044522148.body
}

CPCStateConfigSet* CPCStateConfigSet::GetInstance ()
{
  //## begin CPCStateConfigSet::GetInstance%1044522149.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateConfigSet::GetInstance%1044522149.body
}

void CPCStateConfigSet::Delete ()
{
  //## begin CPCStateConfigSet::Delete%1044522147.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateConfigSet::Delete%1044522147.body
}

void CPCStateConfigSet::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateConfigSet::Do%1076339194.body preserve=yes
	
	// Set config to pid
	double l_dKp = GetpImplementation(p_pContext)->GetpConfig()->GetuiPid_Kp();
	// convert 10^-3 --> 10^0
	l_dKp /= 1E3;

	double l_dTi = GetpImplementation(p_pContext)->GetpConfig()->GetuiPid_Ti();
	// convert 10^-3 --> 10^0
	l_dTi /= 1E3;

	double l_dTv = GetpImplementation(p_pContext)->GetpConfig()->GetuiPid_Tv();
	// convert 10^-3 --> 10^0
	l_dTv /= 1E3;

	double l_dULimit = GetpImplementation(p_pContext)->GetpConfig()->GetiPid_ULimit(); // dac digits

	double l_dLLimit = GetpImplementation(p_pContext)->GetpConfig()->GetiPid_LLimit(); // dac digits

	double l_dTs = GetpImplementation(p_pContext)->GetpConfig()->GetuiPid_Ts();
	l_dTs /= 1E3;

	double l_dDACGain = GetpImplementation(p_pContext)->GetpConfig()->GetuiNominalVoltageGain();
	// convert 10^-3 --> 10^0
	l_dDACGain /= 1E3;

	double l_dDACOffset = GetpImplementation(p_pContext)->GetpConfig()->GetiNominalVoltageOffset();

	GetpImplementation(p_pContext)->GetpPID()->Set(l_dKp,
		l_dTi, 
		l_dTv, 
		l_dLLimit, 
		l_dULimit, 
		l_dTs,
		l_dDACGain,
		l_dDACOffset);
	
	p_pContext->ChangeState(CPCStateConfigProfileNotSet::GetInstance());

  //## end CPCStateConfigSet::Do%1076339194.body
}

// Additional Declarations
  //## begin CPCStateConfigSet%3EED76CC0734.declarations preserve=yes
  //## end CPCStateConfigSet%3EED76CC0734.declarations

//## begin module%3EED769F0383.epilog preserve=yes
//## end module%3EED769F0383.epilog
