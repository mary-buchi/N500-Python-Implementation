//## begin module%3EE0872F0036.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE0872F0036.cm

//## begin module%3EE0872F0036.cp preserve=no
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
//## end module%3EE0872F0036.cp

//## Module: EBSYrgun%3EE0872F0036; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYrgun.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE0872F0036.additionalIncludes preserve=no
//## end module%3EE0872F0036.additionalIncludes

//## begin module%3EE0872F0036.includes preserve=yes
//## end module%3EE0872F0036.includes

// EBPIfact
#include "EBPIfact.h"
// EBSYidle
#include "EBSYidle.h"
// EBSYrgun
#include "EBSYrgun.h"
// EBSYmhan
#include "EBSYmhan.h"
//## begin module%3EE0872F0036.declarations preserve=no
//## end module%3EE0872F0036.declarations

//## begin module%3EE0872F0036.additionalDeclarations preserve=yes
//## end module%3EE0872F0036.additionalDeclarations


// Class CSYStateConstitutionRegisteringUnits 

//## begin CSYStateConstitutionRegisteringUnits::pInstance%3EE08001027F.role preserve=no  public: static CSYStateConstitutionRegisteringUnits {1..1 -> RFHN}
CSYStateConstitutionRegisteringUnits *CSYStateConstitutionRegisteringUnits::m_pInstance = NULL;
//## end CSYStateConstitutionRegisteringUnits::pInstance%3EE08001027F.role


CSYStateConstitutionRegisteringUnits::CSYStateConstitutionRegisteringUnits()
  //## begin CSYStateConstitutionRegisteringUnits::CSYStateConstitutionRegisteringUnits%.hasinit preserve=no
  //## end CSYStateConstitutionRegisteringUnits::CSYStateConstitutionRegisteringUnits%.hasinit
  //## begin CSYStateConstitutionRegisteringUnits::CSYStateConstitutionRegisteringUnits%.initialization preserve=yes
  //## end CSYStateConstitutionRegisteringUnits::CSYStateConstitutionRegisteringUnits%.initialization
{
  //## begin CSYStateConstitutionRegisteringUnits::CSYStateConstitutionRegisteringUnits%.body preserve=yes
  //## end CSYStateConstitutionRegisteringUnits::CSYStateConstitutionRegisteringUnits%.body
}


CSYStateConstitutionRegisteringUnits::~CSYStateConstitutionRegisteringUnits()
{
  //## begin CSYStateConstitutionRegisteringUnits::~CSYStateConstitutionRegisteringUnits%.body preserve=yes
  //## end CSYStateConstitutionRegisteringUnits::~CSYStateConstitutionRegisteringUnits%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionRegisteringUnits::Create ()
{
  //## begin CSYStateConstitutionRegisteringUnits::Create%1054888635.body preserve=yes

	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionRegisteringUnits();

  //## end CSYStateConstitutionRegisteringUnits::Create%1054888635.body
}

void CSYStateConstitutionRegisteringUnits::Delete ()
{
  //## begin CSYStateConstitutionRegisteringUnits::Delete%1054888637.body preserve=yes

    if (m_pInstance)
        delete m_pInstance;
    m_pInstance = NULL;

  //## end CSYStateConstitutionRegisteringUnits::Delete%1054888637.body
}

CSYStateConstitutionRegisteringUnits* CSYStateConstitutionRegisteringUnits::GetInstance ()
{
  //## begin CSYStateConstitutionRegisteringUnits::GetInstance%1054888636.body preserve=yes

    ASSERT(m_pInstance != NULL);
    return m_pInstance;

  //## end CSYStateConstitutionRegisteringUnits::GetInstance%1054888636.body
}

EPIDeviceState CSYStateConstitutionRegisteringUnits::GetDeviceState ()
{
  //## begin CSYStateConstitutionRegisteringUnits::GetDeviceState%1056436748.body preserve=yes
    return eRunning;
  //## end CSYStateConstitutionRegisteringUnits::GetDeviceState%1056436748.body
}

void CSYStateConstitutionRegisteringUnits::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionRegisteringUnits::Do%1055753504.body preserve=yes

    CSYModuleHandling::LoadAllDLLs(false);		// todo exception if dll is not loaded
    CSYModuleHandling::RegisterAllInterfaces(false);

    p_pContext->ChangeState(CSYStateProcessIdle::GetInstance());

  //## end CSYStateConstitutionRegisteringUnits::Do%1055753504.body
}

// Additional Declarations
  //## begin CSYStateConstitutionRegisteringUnits%3EE080010278.declarations preserve=yes
  //## end CSYStateConstitutionRegisteringUnits%3EE080010278.declarations

// Class CSYStateConstitutionUnregisteringUnits 

//## begin CSYStateConstitutionUnregisteringUnits::pInstance%4523B07B0125.role preserve=no  public: static CSYStateConstitutionUnregisteringUnits {1..1 -> RFHN}
CSYStateConstitutionUnregisteringUnits *CSYStateConstitutionUnregisteringUnits::m_pInstance = NULL;
//## end CSYStateConstitutionUnregisteringUnits::pInstance%4523B07B0125.role


CSYStateConstitutionUnregisteringUnits::CSYStateConstitutionUnregisteringUnits()
  //## begin CSYStateConstitutionUnregisteringUnits::CSYStateConstitutionUnregisteringUnits%.hasinit preserve=no
  //## end CSYStateConstitutionUnregisteringUnits::CSYStateConstitutionUnregisteringUnits%.hasinit
  //## begin CSYStateConstitutionUnregisteringUnits::CSYStateConstitutionUnregisteringUnits%.initialization preserve=yes
  //## end CSYStateConstitutionUnregisteringUnits::CSYStateConstitutionUnregisteringUnits%.initialization
{
  //## begin CSYStateConstitutionUnregisteringUnits::CSYStateConstitutionUnregisteringUnits%.body preserve=yes
  //## end CSYStateConstitutionUnregisteringUnits::CSYStateConstitutionUnregisteringUnits%.body
}


CSYStateConstitutionUnregisteringUnits::~CSYStateConstitutionUnregisteringUnits()
{
  //## begin CSYStateConstitutionUnregisteringUnits::~CSYStateConstitutionUnregisteringUnits%.body preserve=yes
  //## end CSYStateConstitutionUnregisteringUnits::~CSYStateConstitutionUnregisteringUnits%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionUnregisteringUnits::Create ()
{
  //## begin CSYStateConstitutionUnregisteringUnits::Create%1159966954.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSYStateConstitutionUnregisteringUnits();
  //## end CSYStateConstitutionUnregisteringUnits::Create%1159966954.body
}

void CSYStateConstitutionUnregisteringUnits::Delete ()
{
  //## begin CSYStateConstitutionUnregisteringUnits::Delete%1159966955.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSYStateConstitutionUnregisteringUnits::Delete%1159966955.body
}

CSYStateConstitutionUnregisteringUnits* CSYStateConstitutionUnregisteringUnits::GetInstance ()
{
  //## begin CSYStateConstitutionUnregisteringUnits::GetInstance%1159966956.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSYStateConstitutionUnregisteringUnits::GetInstance%1159966956.body
}

void CSYStateConstitutionUnregisteringUnits::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionUnregisteringUnits::Do%1159966957.body preserve=yes
	CPIObjectFactory::GetInstance()->Reset();
	CSYModuleHandling::UnLoadDynamicDLLs();

    p_pContext->ChangeState(CSYStateConstitutionStandBy::GetInstance());
  //## end CSYStateConstitutionUnregisteringUnits::Do%1159966957.body
}

// Additional Declarations
  //## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.declarations preserve=yes
  //## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.declarations

//## begin module%3EE0872F0036.epilog preserve=yes
//## end module%3EE0872F0036.epilog
