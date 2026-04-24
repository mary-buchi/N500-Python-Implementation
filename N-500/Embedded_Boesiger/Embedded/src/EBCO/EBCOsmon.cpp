//## begin module%3F708CEF008A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F708CEF008A.cm

//## begin module%3F708CEF008A.cp preserve=no
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
//## end module%3F708CEF008A.cp

//## Module: EBCOsmon%3F708CEF008A; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOsmon.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F708CEF008A.additionalIncludes preserve=no
//## end module%3F708CEF008A.additionalIncludes

//## begin module%3F708CEF008A.includes preserve=yes
//## end module%3F708CEF008A.includes

// EBCOsmon
#include "EBCOsmon.h"
//## begin module%3F708CEF008A.declarations preserve=no
//## end module%3F708CEF008A.declarations

//## begin module%3F708CEF008A.additionalDeclarations preserve=yes
//## end module%3F708CEF008A.additionalDeclarations


// Class CCOSystemMonitorInterface 

//## begin CCOSystemMonitorInterface::pMonitor%3F708E5D0092.role preserve=no  public: static CCOSystemMonitorInterface {1..1 -> 1..1RFHN}
CCOSystemMonitorInterface *CCOSystemMonitorInterface::m_pMonitor = NULL;
//## end CCOSystemMonitorInterface::pMonitor%3F708E5D0092.role


//## Get and Set Operations for Associations (implementation)

CCOSystemMonitorInterface * CCOSystemMonitorInterface::GetpMonitor ()
{
  //## begin CCOSystemMonitorInterface::GetpMonitor%3F708E5D0092.get preserve=no
  return m_pMonitor;
  //## end CCOSystemMonitorInterface::GetpMonitor%3F708E5D0092.get
}

// Additional Declarations
  //## begin CCOSystemMonitorInterface%3F708CB8023A.declarations preserve=yes
  //## end CCOSystemMonitorInterface%3F708CB8023A.declarations

//## begin module%3F708CEF008A.epilog preserve=yes
//## end module%3F708CEF008A.epilog
