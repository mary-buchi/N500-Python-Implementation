//## begin module%3EC8D24C0311.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EC8D24C0311.cm

//## begin module%3EC8D24C0311.cp preserve=no
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
//## end module%3EC8D24C0311.cp

//## Module: EBCOthtm%3EC8D24C0311; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOthtm.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EC8D24C0311.additionalIncludes preserve=no
//## end module%3EC8D24C0311.additionalIncludes

//## begin module%3EC8D24C0311.includes preserve=yes
//## end module%3EC8D24C0311.includes

// EBCOthtm
#include "EBCOthtm.h"
// EBCOwkth
#include "EBCOwkth.h"


//## begin module%3EC8D24C0311.declarations preserve=no
//## end module%3EC8D24C0311.declarations

//## begin module%3EC8D24C0311.additionalDeclarations preserve=yes
//## end module%3EC8D24C0311.additionalDeclarations


// Class CCOThreadTimer 





CCOThreadTimer::CCOThreadTimer (CCOThreadWorkImplementation* p_pClient, UINT p_uiInterval)
  //## begin CCOThreadTimer::CCOThreadTimer%1053348755.hasinit preserve=no
      : m_uiInterval(p_uiInterval), m_pClient(p_pClient)
  //## end CCOThreadTimer::CCOThreadTimer%1053348755.hasinit
  //## begin CCOThreadTimer::CCOThreadTimer%1053348755.initialization preserve=yes
  , ICOThreadWork("Timer Thread")
  //## end CCOThreadTimer::CCOThreadTimer%1053348755.initialization
{
  //## begin CCOThreadTimer::CCOThreadTimer%1053348755.body preserve=yes
  //## end CCOThreadTimer::CCOThreadTimer%1053348755.body
}


CCOThreadTimer::~CCOThreadTimer()
{
  //## begin CCOThreadTimer::~CCOThreadTimer%.body preserve=yes
  //## end CCOThreadTimer::~CCOThreadTimer%.body
}



//## Other Operations (implementation)
int CCOThreadTimer::ThreadMain ()
{
  //## begin CCOThreadTimer::ThreadMain%1053348756.body preserve=yes
    bool l_bRunning = true;
    while (l_bRunning)
    {
			  if (::WaitForSingleObject( m_TerminationEvent, m_uiInterval ) == WAIT_TIMEOUT)
        {

            // timeout expired
            CSingleLock l_AccessLock(&m_AccessLock, TRUE);
            if (m_bRunning)
            {
                try
                {
                    m_pClient->OnTimer();
                }
                catch(...)
                {
                }
            }
        }
        else
        {
            // thread should terminate
            l_bRunning = false;
        }
    }

    return 0;
  //## end CCOThreadTimer::ThreadMain%1053348756.body
}

// Additional Declarations
  //## begin CCOThreadTimer%3EC8D21403CC.declarations preserve=yes
  //## end CCOThreadTimer%3EC8D21403CC.declarations

//## begin module%3EC8D24C0311.epilog preserve=yes
//## end module%3EC8D24C0311.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CCOThreadTimer::TerminateThread%1053348758.body preserve=no
    ICOThreadWork::TerminateThread();
//## end CCOThreadTimer::TerminateThread%1053348758.body

#endif
