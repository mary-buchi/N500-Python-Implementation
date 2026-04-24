//## begin module%3DE5EB140275.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB140275.cm

//## begin module%3DE5EB140275.cp preserve=no
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
//## end module%3DE5EB140275.cp

//## Module: EBPOimpl%3DE5EB140275; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EB140275.additionalIncludes preserve=no
//## end module%3DE5EB140275.additionalIncludes

//## begin module%3DE5EB140275.includes preserve=yes
//## end module%3DE5EB140275.includes

// windef
#include "windef.h"
// EBPItype
#include "EBPItype.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
// EBPOsten
#include "EBPOsten.h"
// EBPOimpl
#include "EBPOimpl.h"
// EBPOintf
#include "EBPOintf.h"


//## begin module%3DE5EB140275.declarations preserve=no
//## end module%3DE5EB140275.declarations

//## begin module%3DE5EB140275.additionalDeclarations preserve=yes
//## end module%3DE5EB140275.additionalDeclarations


// Class CPOPersistentObjImplementation 








CPOPersistentObjImplementation::CPOPersistentObjImplementation (CPOPersistentObjInterface* p_pInterface)
  //## begin CPOPersistentObjImplementation::CPOPersistentObjImplementation%1038495055.hasinit preserve=no
      : m_pLogic(NULL), m_pLifeTimeCounterHandler(NULL), m_pConfig(NULL), m_uiID(0)
  //## end CPOPersistentObjImplementation::CPOPersistentObjImplementation%1038495055.hasinit
  //## begin CPOPersistentObjImplementation::CPOPersistentObjImplementation%1038495055.initialization preserve=yes
  , ICOAsyncImplementation(p_pInterface)
  //## end CPOPersistentObjImplementation::CPOPersistentObjImplementation%1038495055.initialization
{
  //## begin CPOPersistentObjImplementation::CPOPersistentObjImplementation%1038495055.body preserve=yes
	m_uiID = p_pInterface->GetuiID();
	ASSERT(m_uiID != 0);
  //## end CPOPersistentObjImplementation::CPOPersistentObjImplementation%1038495055.body
}


CPOPersistentObjImplementation::~CPOPersistentObjImplementation()
{
  //## begin CPOPersistentObjImplementation::~CPOPersistentObjImplementation%.body preserve=yes

	if (m_pStateMachineEngine != NULL)
		delete m_pStateMachineEngine;
	m_pStateMachineEngine = NULL;

	if (m_pLogic != NULL)
		delete m_pLogic;
	m_pLogic = NULL;
		
	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();
	m_pConfig = NULL;

	if (m_pLifeTimeCounterHandler != NULL)
		delete m_pLifeTimeCounterHandler;
	m_pLifeTimeCounterHandler = NULL;

  //## end CPOPersistentObjImplementation::~CPOPersistentObjImplementation%.body
}



//## Other Operations (implementation)
void CPOPersistentObjImplementation::InitInstance ()
{
  //## begin CPOPersistentObjImplementation::InitInstance%1038495056.body preserve=yes

	m_pStateMachineEngine		= new CPOStateMachineEngine(this);
	m_pLogic					= new CPOLogic(this);
	m_pLifeTimeCounterHandler	= new CPOLifeTimeCounterHandler(this);

	ICOAsyncImplementation::InitInstance();
  //## end CPOPersistentObjImplementation::InitInstance%1038495056.body
}

//## Get and Set Operations for Associations (implementation)

CPOLogic * CPOPersistentObjImplementation::GetpLogic ()
{
  //## begin CPOPersistentObjImplementation::GetpLogic%3F9D154E03E4.get preserve=yes
	ASSERT(m_pLogic != NULL);
	return m_pLogic;
  //## end CPOPersistentObjImplementation::GetpLogic%3F9D154E03E4.get
}

CPOLifeTimeCounterHandler * CPOPersistentObjImplementation::GetpLifeTimeCounterHandler ()
{
  //## begin CPOPersistentObjImplementation::GetpLifeTimeCounterHandler%3F9D41310378.get preserve=yes
	ASSERT(m_pLifeTimeCounterHandler != NULL);
	return m_pLifeTimeCounterHandler;
  //## end CPOPersistentObjImplementation::GetpLifeTimeCounterHandler%3F9D41310378.get
}

CPIPersistentConfig * CPOPersistentObjImplementation::GetpConfig ()
{
  //## begin CPOPersistentObjImplementation::GetpConfig%403F13840187.get preserve=yes
	ASSERT(m_pConfig != NULL);
    return m_pConfig;
  //## end CPOPersistentObjImplementation::GetpConfig%403F13840187.get
}

void CPOPersistentObjImplementation::SetpConfig (CPIPersistentConfig * value)
{
  //## begin CPOPersistentObjImplementation::SetpConfig%403F13840187.set preserve=yes
  	ASSERT(value != NULL);

  	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();

	m_pConfig = value;
	m_pConfig->AddRef();
  //## end CPOPersistentObjImplementation::SetpConfig%403F13840187.set
}

UINT CPOPersistentObjImplementation::GetuiID ()
{
  //## begin CPOPersistentObjImplementation::GetuiID%4057FC0E004B.get preserve=no
  return m_uiID;
  //## end CPOPersistentObjImplementation::GetuiID%4057FC0E004B.get
}

// Additional Declarations
  //## begin CPOPersistentObjImplementation%3DE633A00247.declarations preserve=yes
  //## end CPOPersistentObjImplementation%3DE633A00247.declarations

//## begin module%3DE5EB140275.epilog preserve=yes
//## end module%3DE5EB140275.epilog
