//## begin module%3B86D6E401F4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B86D6E401F4.cm

//## begin module%3B86D6E401F4.cp preserve=no
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
//## end module%3B86D6E401F4.cp

//## Module: EBCOintf%3B86D6E401F4; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B86D6E401F4.additionalIncludes preserve=no
//## end module%3B86D6E401F4.additionalIncludes

//## begin module%3B86D6E401F4.includes preserve=yes
//## end module%3B86D6E401F4.includes

// EBCOimpl
#include "EBCOimpl.h"
// EBCOintf
#include "EBCOintf.h"
// EBCOcomd
#include "EBCOcomd.h"
// EBCOsync
#include "EBCOsync.h"


//## begin module%3B86D6E401F4.declarations preserve=no
//## end module%3B86D6E401F4.declarations

//## begin module%3B86D6E401F4.additionalDeclarations preserve=yes
//## end module%3B86D6E401F4.additionalDeclarations


// Class ICOAsyncInterface 




ICOAsyncInterface::ICOAsyncInterface (const CString& p_sSubsystemID)
  //## begin ICOAsyncInterface::ICOAsyncInterface%999280839.hasinit preserve=no
      : m_sSubsystemID(p_sSubsystemID), m_pImplementation(NULL)
  //## end ICOAsyncInterface::ICOAsyncInterface%999280839.hasinit
  //## begin ICOAsyncInterface::ICOAsyncInterface%999280839.initialization preserve=yes
  //## end ICOAsyncInterface::ICOAsyncInterface%999280839.initialization
{
  //## begin ICOAsyncInterface::ICOAsyncInterface%999280839.body preserve=yes
  //## end ICOAsyncInterface::ICOAsyncInterface%999280839.body
}


ICOAsyncInterface::~ICOAsyncInterface()
{
  //## begin ICOAsyncInterface::~ICOAsyncInterface%.body preserve=yes
	delete m_pImplementation;
	m_pImplementation = NULL;
  //## end ICOAsyncInterface::~ICOAsyncInterface%.body
}



//## Other Operations (implementation)
void ICOAsyncInterface::InitInstance ()
{
  //## begin ICOAsyncInterface::InitInstance%999280837.body preserve=yes
	if (!m_pImplementation)
	{
		// create standard subsystem implementation
		m_pImplementation = new ICOAsyncImplementation(this);
	}

	// initialize implementation
	m_pImplementation->InitInstance();
  //## end ICOAsyncInterface::InitInstance%999280837.body
}

void ICOAsyncInterface::ExitInstance ()
{
  //## begin ICOAsyncInterface::ExitInstance%999280840.body preserve=yes
	ASSERT(m_pImplementation != NULL);
	m_pImplementation->ExitInstance();
  //## end ICOAsyncInterface::ExitInstance%999280840.body
}

CString ICOAsyncInterface::GetsCurrentState ()
{
  //## begin ICOAsyncInterface::GetsCurrentState%1000031199.body preserve=yes
    return m_pImplementation->GetsCurrentState();
  //## end ICOAsyncInterface::GetsCurrentState%1000031199.body
}

CCOSyncObject* ICOAsyncInterface::Startup ()
{
  //## begin ICOAsyncInterface::Startup%999280842.body preserve=yes
    return Execute(new CCOCommandStartup(m_pImplementation), eCOQueueNormal);
  //## end ICOAsyncInterface::Startup%999280842.body
}

CCOSyncObject* ICOAsyncInterface::Shutdown ()
{
  //## begin ICOAsyncInterface::Shutdown%999369758.body preserve=yes
    return Execute(new CCOCommandShutdown(m_pImplementation), eCOQueueHigh);
  //## end ICOAsyncInterface::Shutdown%999369758.body
}

CCOSyncObject* ICOAsyncInterface::ConnectionEstablished ()
{
  //## begin ICOAsyncInterface::ConnectionEstablished%1055313951.body preserve=yes
    return Execute(new CCOCommandConnectionEstablished(m_pImplementation), eCOQueueHigh);
  //## end ICOAsyncInterface::ConnectionEstablished%1055313951.body
}

CCOSyncObject* ICOAsyncInterface::ConnectionLost ()
{
  //## begin ICOAsyncInterface::ConnectionLost%1055313952.body preserve=yes
    return Execute(new CCOCommandConnectionLost(m_pImplementation), eCOQueueHigh);
  //## end ICOAsyncInterface::ConnectionLost%1055313952.body
}

CCOSyncObject* ICOAsyncInterface::Execute (CCOCommand* p_pCommand, const ECOAsyncCallQueue p_ePriority)
{
  //## begin ICOAsyncInterface::Execute%999280843.body preserve=yes
    p_pCommand->CreateSyncObjects();

    CCOSyncObject* l_pSyncObj = p_pCommand->GetpSyncArray()->GetAt(0);
    l_pSyncObj->AddRef();

    // add command to queue
    m_pImplementation->AddCommand(p_pCommand, p_ePriority);

    return l_pSyncObj;
  //## end ICOAsyncInterface::Execute%999280843.body
}

//## Get and Set Operations for Class Attributes (implementation)

const CString ICOAsyncInterface::GetsSubsystemID () const
{
  //## begin ICOAsyncInterface::GetsSubsystemID%3B8FD8D301B0.get preserve=no
  return m_sSubsystemID;
  //## end ICOAsyncInterface::GetsSubsystemID%3B8FD8D301B0.get
}

// Additional Declarations
  //## begin ICOAsyncInterface%3B86D700001E.declarations preserve=yes
  //## end ICOAsyncInterface%3B86D700001E.declarations

// Class ICOSyncInterface 

ICOSyncInterface::ICOSyncInterface (const CString& p_sSubsystemID)
  //## begin ICOSyncInterface::ICOSyncInterface%1039527157.hasinit preserve=no
  //## end ICOSyncInterface::ICOSyncInterface%1039527157.hasinit
  //## begin ICOSyncInterface::ICOSyncInterface%1039527157.initialization preserve=yes
  //## end ICOSyncInterface::ICOSyncInterface%1039527157.initialization
{
  //## begin ICOSyncInterface::ICOSyncInterface%1039527157.body preserve=yes
  //## end ICOSyncInterface::ICOSyncInterface%1039527157.body
}


ICOSyncInterface::~ICOSyncInterface()
{
  //## begin ICOSyncInterface::~ICOSyncInterface%.body preserve=yes
  //## end ICOSyncInterface::~ICOSyncInterface%.body
}


// Additional Declarations
  //## begin ICOSyncInterface%3DB92ED80037.declarations preserve=yes
  //## end ICOSyncInterface%3DB92ED80037.declarations

// Class ICOObjectInterface 

ICOObjectInterface::ICOObjectInterface()
  //## begin ICOObjectInterface::ICOObjectInterface%.hasinit preserve=no
  //## end ICOObjectInterface::ICOObjectInterface%.hasinit
  //## begin ICOObjectInterface::ICOObjectInterface%.initialization preserve=yes
  //## end ICOObjectInterface::ICOObjectInterface%.initialization
{
  //## begin ICOObjectInterface::ICOObjectInterface%.body preserve=yes
  //## end ICOObjectInterface::ICOObjectInterface%.body
}


ICOObjectInterface::~ICOObjectInterface()
{
  //## begin ICOObjectInterface::~ICOObjectInterface%.body preserve=yes
  //## end ICOObjectInterface::~ICOObjectInterface%.body
}


// Additional Declarations
  //## begin ICOObjectInterface%3DA5E00F0046.declarations preserve=yes
  //## end ICOObjectInterface%3DA5E00F0046.declarations

//## begin module%3B86D6E401F4.epilog preserve=yes
//## end module%3B86D6E401F4.epilog
