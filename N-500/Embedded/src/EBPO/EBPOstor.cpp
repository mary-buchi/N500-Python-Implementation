//## begin module%3F93ABA60278.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93ABA60278.cm

//## begin module%3F93ABA60278.cp preserve=no
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
//## end module%3F93ABA60278.cp

//## Module: EBPOstor%3F93ABA60278; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOstor.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F93ABA60278.additionalIncludes preserve=no
//## end module%3F93ABA60278.additionalIncludes

//## begin module%3F93ABA60278.includes preserve=yes
//## end module%3F93ABA60278.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
// EBPOstor
#include "EBPOstor.h"
// EBPOidle
#include "EBPOidle.h"
//## begin module%3F93ABA60278.declarations preserve=no
//## end module%3F93ABA60278.declarations

//## begin module%3F93ABA60278.additionalDeclarations preserve=yes
//## end module%3F93ABA60278.additionalDeclarations


// Class CPOStateStore 

CPOStateStore::CPOStateStore()
  //## begin CPOStateStore::CPOStateStore%.hasinit preserve=no
  //## end CPOStateStore::CPOStateStore%.hasinit
  //## begin CPOStateStore::CPOStateStore%.initialization preserve=yes
  //## end CPOStateStore::CPOStateStore%.initialization
{
  //## begin CPOStateStore::CPOStateStore%.body preserve=yes
  //## end CPOStateStore::CPOStateStore%.body
}


CPOStateStore::~CPOStateStore()
{
  //## begin CPOStateStore::~CPOStateStore%.body preserve=yes
  //## end CPOStateStore::~CPOStateStore%.body
}



//## Other Operations (implementation)
void CPOStateStore::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateStore::CleanupInitialize%1067251219.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->MCUndock();
	p_pContext->ChangeState(CPOStateIdle::GetInstance());
  //## end CPOStateStore::CleanupInitialize%1067251219.body
}

// Additional Declarations
  //## begin CPOStateStore%3F93AE250035.declarations preserve=yes
  //## end CPOStateStore%3F93AE250035.declarations

// Class CPOStateStoreReading 

//## begin CPOStateStoreReading::pInstance%3F97CD9801AD.role preserve=no  public: static CPOStateStoreReading {1..1 -> 1..1RFHN}
CPOStateStoreReading *CPOStateStoreReading::m_pInstance;
//## end CPOStateStoreReading::pInstance%3F97CD9801AD.role


CPOStateStoreReading::CPOStateStoreReading()
  //## begin CPOStateStoreReading::CPOStateStoreReading%.hasinit preserve=no
  //## end CPOStateStoreReading::CPOStateStoreReading%.hasinit
  //## begin CPOStateStoreReading::CPOStateStoreReading%.initialization preserve=yes
  //## end CPOStateStoreReading::CPOStateStoreReading%.initialization
{
  //## begin CPOStateStoreReading::CPOStateStoreReading%.body preserve=yes
  //## end CPOStateStoreReading::CPOStateStoreReading%.body
}


CPOStateStoreReading::~CPOStateStoreReading()
{
  //## begin CPOStateStoreReading::~CPOStateStoreReading%.body preserve=yes
  //## end CPOStateStoreReading::~CPOStateStoreReading%.body
}



//## Other Operations (implementation)
void CPOStateStoreReading::Create ()
{
  //## begin CPOStateStoreReading::Create%1066889015.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateStoreReading();
  //## end CPOStateStoreReading::Create%1066889015.body
}

void CPOStateStoreReading::Delete ()
{
  //## begin CPOStateStoreReading::Delete%1066889016.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateStoreReading::Delete%1066889016.body
}

CPOStateStoreReading * CPOStateStoreReading::GetInstance ()
{
  //## begin CPOStateStoreReading::GetInstance%1066889017.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateStoreReading::GetInstance%1066889017.body
}

void CPOStateStoreReading::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateStoreReading::Do%1067251220.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->Save();
	p_pContext->ChangeState(CPOStateStoreParse::GetInstance());
  //## end CPOStateStoreReading::Do%1067251220.body
}

// Additional Declarations
  //## begin CPOStateStoreReading%3F93AE3B0287.declarations preserve=yes
  //## end CPOStateStoreReading%3F93AE3B0287.declarations

// Class CPOStateStoreParse 

//## begin CPOStateStoreParse::pInstance%3F97CD9A026A.role preserve=no  public: static CPOStateStoreParse {1..1 -> RFHN}
CPOStateStoreParse *CPOStateStoreParse::m_pInstance;
//## end CPOStateStoreParse::pInstance%3F97CD9A026A.role


CPOStateStoreParse::CPOStateStoreParse()
  //## begin CPOStateStoreParse::CPOStateStoreParse%.hasinit preserve=no
  //## end CPOStateStoreParse::CPOStateStoreParse%.hasinit
  //## begin CPOStateStoreParse::CPOStateStoreParse%.initialization preserve=yes
  //## end CPOStateStoreParse::CPOStateStoreParse%.initialization
{
  //## begin CPOStateStoreParse::CPOStateStoreParse%.body preserve=yes
  //## end CPOStateStoreParse::CPOStateStoreParse%.body
}


CPOStateStoreParse::~CPOStateStoreParse()
{
  //## begin CPOStateStoreParse::~CPOStateStoreParse%.body preserve=yes
  //## end CPOStateStoreParse::~CPOStateStoreParse%.body
}



//## Other Operations (implementation)
void CPOStateStoreParse::Create ()
{
  //## begin CPOStateStoreParse::Create%1066889012.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateStoreParse();
  //## end CPOStateStoreParse::Create%1066889012.body
}

void CPOStateStoreParse::Delete ()
{
  //## begin CPOStateStoreParse::Delete%1066889013.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateStoreParse::Delete%1066889013.body
}

CPOStateStoreParse * CPOStateStoreParse::GetInstance ()
{
  //## begin CPOStateStoreParse::GetInstance%1066889014.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateStoreParse::GetInstance%1066889014.body
}

void CPOStateStoreParse::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateStoreParse::Do%1067251221.body preserve=yes
	p_pContext->ChangeState(CPOStateStoreWriting::GetInstance());
  //## end CPOStateStoreParse::Do%1067251221.body
}

// Additional Declarations
  //## begin CPOStateStoreParse%3F93AE5101FB.declarations preserve=yes
  //## end CPOStateStoreParse%3F93AE5101FB.declarations

// Class CPOStateStoreWriting 

//## begin CPOStateStoreWriting::pInstance%3F97CD9D0018.role preserve=no  public: static CPOStateStoreWriting {1..1 -> 1..1RFHN}
CPOStateStoreWriting *CPOStateStoreWriting::m_pInstance;
//## end CPOStateStoreWriting::pInstance%3F97CD9D0018.role


CPOStateStoreWriting::CPOStateStoreWriting()
  //## begin CPOStateStoreWriting::CPOStateStoreWriting%.hasinit preserve=no
  //## end CPOStateStoreWriting::CPOStateStoreWriting%.hasinit
  //## begin CPOStateStoreWriting::CPOStateStoreWriting%.initialization preserve=yes
  //## end CPOStateStoreWriting::CPOStateStoreWriting%.initialization
{
  //## begin CPOStateStoreWriting::CPOStateStoreWriting%.body preserve=yes
  //## end CPOStateStoreWriting::CPOStateStoreWriting%.body
}


CPOStateStoreWriting::~CPOStateStoreWriting()
{
  //## begin CPOStateStoreWriting::~CPOStateStoreWriting%.body preserve=yes
  //## end CPOStateStoreWriting::~CPOStateStoreWriting%.body
}



//## Other Operations (implementation)
void CPOStateStoreWriting::Create ()
{
  //## begin CPOStateStoreWriting::Create%1066889009.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateStoreWriting();
  //## end CPOStateStoreWriting::Create%1066889009.body
}

void CPOStateStoreWriting::Delete ()
{
  //## begin CPOStateStoreWriting::Delete%1066889010.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateStoreWriting::Delete%1066889010.body
}

CPOStateStoreWriting * CPOStateStoreWriting::GetInstance ()
{
  //## begin CPOStateStoreWriting::GetInstance%1066889011.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateStoreWriting::GetInstance%1066889011.body
}

void CPOStateStoreWriting::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateStoreWriting::Do%1067251222.body preserve=yes
	p_pContext->ChangeState(CPOStateIdle::GetInstance());
  //## end CPOStateStoreWriting::Do%1067251222.body
}

// Additional Declarations
  //## begin CPOStateStoreWriting%3F93AE620258.declarations preserve=yes
  //## end CPOStateStoreWriting%3F93AE620258.declarations

//## begin module%3F93ABA60278.epilog preserve=yes
//## end module%3F93ABA60278.epilog
