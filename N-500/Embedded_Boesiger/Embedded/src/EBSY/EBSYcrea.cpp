//## begin module%3EDC5B3C01F4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01F4.cm

//## begin module%3EDC5B3C01F4.cp preserve=no
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
//## end module%3EDC5B3C01F4.cp

//## Module: EBSYcrea%3EDC5B3C01F4; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C01F4.additionalIncludes preserve=no
//## end module%3EDC5B3C01F4.additionalIncludes

//## begin module%3EDC5B3C01F4.includes preserve=yes
//## end module%3EDC5B3C01F4.includes

// EBCOimct
#include "EBCOimct.h"
// EBPImain
#include "EBPImain.h"
// EBSYcrea
#include "EBSYcrea.h"
// EBSYcons
#include "EBSYcons.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3EDC5B3C01F4.declarations preserve=no
//## end module%3EDC5B3C01F4.declarations

//## begin module%3EDC5B3C01F4.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01F4.additionalDeclarations


// Class CSYStateCreated 


//## begin CSYStateCreated::pInstance%3EDC5B9C0304.role preserve=no  public: static CSYStateCreated {1..1 -> 1..1RFHN}
CSYStateCreated *CSYStateCreated::m_pInstance = NULL;
//## end CSYStateCreated::pInstance%3EDC5B9C0304.role


CSYStateCreated::CSYStateCreated()
  //## begin CSYStateCreated::CSYStateCreated%.hasinit preserve=no
      : m_bReset(false)
  //## end CSYStateCreated::CSYStateCreated%.hasinit
  //## begin CSYStateCreated::CSYStateCreated%.initialization preserve=yes
  //## end CSYStateCreated::CSYStateCreated%.initialization
{
  //## begin CSYStateCreated::CSYStateCreated%.body preserve=yes
  //## end CSYStateCreated::CSYStateCreated%.body
}


CSYStateCreated::~CSYStateCreated()
{
  //## begin CSYStateCreated::~CSYStateCreated%.body preserve=yes
  //## end CSYStateCreated::~CSYStateCreated%.body
}



//## Other Operations (implementation)
void CSYStateCreated::Create ()
{
  //## begin CSYStateCreated::Create%1038899336.body preserve=yes

    ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateCreated();

  //## end CSYStateCreated::Create%1038899336.body
}

void CSYStateCreated::Delete ()
{
  //## begin CSYStateCreated::Delete%1038899337.body preserve=yes

    if (m_pInstance)
    {
        delete m_pInstance;
    }

    m_pInstance = NULL;

  //## end CSYStateCreated::Delete%1038899337.body
}

CSYStateCreated* CSYStateCreated::GetInstance ()
{
  //## begin CSYStateCreated::GetInstance%1056027096.body preserve=yes

	ASSERT(m_pInstance != NULL);
    return m_pInstance;

  //## end CSYStateCreated::GetInstance%1056027096.body
}

EPIDeviceState CSYStateCreated::GetDeviceState ()
{
  //## begin CSYStateCreated::GetDeviceState%1056436754.body preserve=yes
    return eNotConnected;
  //## end CSYStateCreated::GetDeviceState%1056436754.body
}

void CSYStateCreated::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateCreated::Do%1056027095.body preserve=yes

	// TODO Bug: The "::Do" of the 1st state in the statemachine engine is not executed the first time. 

    // it IS executed the second time... 
    if (m_bReset)
    {
	    IHIInterface *l_pHIIntf = CHIInterface::GetInstance();
	    ASSERT(l_pHIIntf != NULL);
        bool l_bStartButtonPressed = l_pHIIntf->GetDWord(l_pHIIntf->GetStaticObjID(eHIIDButtonStart)) != 0;
        bool l_bStopButtonPressed  = l_pHIIntf->GetDWord(l_pHIIntf->GetStaticObjID(eHIIDButtonStop)) != 0;
        
        if (l_bStartButtonPressed && l_bStopButtonPressed)
        {
            p_pContext->ChangeState(CSYStateConstitutionConsiderInterfaceReset::GetInstance());
        }
        else
        {
		    p_pContext->ChangeState(CSYStateConstitutionStartingUp::GetInstance());
        }
    }

    m_bReset = false;
  //## end CSYStateCreated::Do%1056027095.body
}

void CSYStateCreated::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateCreated::Startup%1056027097.body preserve=yes
	IHIInterface *l_pHIIntf = CHIInterface::GetInstance();
	ASSERT(l_pHIIntf != NULL);
    bool l_bStartButtonPressed = l_pHIIntf->GetDWord(l_pHIIntf->GetStaticObjID(eHIIDButtonStart)) != 0;
    bool l_bStopButtonPressed  = l_pHIIntf->GetDWord(l_pHIIntf->GetStaticObjID(eHIIDButtonStop)) != 0;
    
    if (l_bStartButtonPressed && l_bStopButtonPressed)
    {
        p_pContext->ChangeState(CSYStateConstitutionConsiderInterfaceReset::GetInstance());
    }
    else
    {
	    p_pContext->ChangeState(CSYStateConstitutionStartingUp::GetInstance());
    }
  //## end CSYStateCreated::Startup%1056027097.body
}

void CSYStateCreated::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateCreated::Shutdown%1077175170.body preserve=yes
  //## end CSYStateCreated::Shutdown%1077175170.body
}

//## Get and Set Operations for Class Attributes (implementation)

bool CSYStateCreated::GetbReset ()
{
  //## begin CSYStateCreated::GetbReset%403485A300FA.get preserve=no
  return m_bReset;
  //## end CSYStateCreated::GetbReset%403485A300FA.get
}

void CSYStateCreated::SetbReset (bool value)
{
  //## begin CSYStateCreated::SetbReset%403485A300FA.set preserve=no
  m_bReset = value;
  //## end CSYStateCreated::SetbReset%403485A300FA.set
}

// Additional Declarations
  //## begin CSYStateCreated%3EDC5B9C0227.declarations preserve=yes
  //## end CSYStateCreated%3EDC5B9C0227.declarations

//## begin module%3EDC5B3C01F4.epilog preserve=yes
//## end module%3EDC5B3C01F4.epilog
