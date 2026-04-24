//## begin module%3DD0F89E0050.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0F89E0050.cm

//## begin module%3DD0F89E0050.cp preserve=no
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
//## end module%3DD0F89E0050.cp

//## Module: EBWCimpl%3DD0F89E0050; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD0F89E0050.additionalIncludes preserve=no
//## end module%3DD0F89E0050.additionalIncludes

//## begin module%3DD0F89E0050.includes preserve=yes
//## end module%3DD0F89E0050.includes

// EBCOsync
#include "EBCOsync.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBWCsten
#include "EBWCsten.h"
// EBWCimpl
#include "EBWCimpl.h"
// EBWCintf
#include "EBWCintf.h"
// EBWCidnt
#include "EBWCidnt.h"


//## begin module%3DD0F89E0050.declarations preserve=no
//## end module%3DD0F89E0050.declarations

//## begin module%3DD0F89E0050.additionalDeclarations preserve=yes
//## end module%3DD0F89E0050.additionalDeclarations


// Class CWCWedgeControlImplementation 




CWCWedgeControlImplementation::CWCWedgeControlImplementation (CWCWedgeControlInterface* p_pInterface)
  //## begin CWCWedgeControlImplementation::CWCWedgeControlImplementation%1037094241.hasinit preserve=no
      : m_bHWPresent(false), m_pSyncExcObj(NULL), m_pSyncStartObj(NULL)
  //## end CWCWedgeControlImplementation::CWCWedgeControlImplementation%1037094241.hasinit
  //## begin CWCWedgeControlImplementation::CWCWedgeControlImplementation%1037094241.initialization preserve=yes
  , ICOAsyncImplementation(p_pInterface)
  //## end CWCWedgeControlImplementation::CWCWedgeControlImplementation%1037094241.initialization
{
  //## begin CWCWedgeControlImplementation::CWCWedgeControlImplementation%1037094241.body preserve=yes
  //## end CWCWedgeControlImplementation::CWCWedgeControlImplementation%1037094241.body
}


CWCWedgeControlImplementation::~CWCWedgeControlImplementation()
{
  //## begin CWCWedgeControlImplementation::~CWCWedgeControlImplementation%.body preserve=yes
  if (m_pSyncExcObj)
    m_pSyncExcObj->ReleaseRef();
  
  if (m_pSyncStartObj)
    m_pSyncStartObj->ReleaseRef();
  //## end CWCWedgeControlImplementation::~CWCWedgeControlImplementation%.body
}



//## Other Operations (implementation)
void CWCWedgeControlImplementation::InitInstance ()
{
  //## begin CWCWedgeControlImplementation::InitInstance%1037094240.body preserve=yes
  // init hw present flag
  m_bHWPresent = CPIComponentsState::GetInstance()->GetComponentState(WC_ID);

  m_pStateMachineEngine = new CWCStateMachineEngine(this);

  ICOAsyncImplementation::InitInstance();
  //## end CWCWedgeControlImplementation::InitInstance%1037094240.body
}

//## Get and Set Operations for Class Attributes (implementation)

bool CWCWedgeControlImplementation::GetbHWPresent ()
{
  //## begin CWCWedgeControlImplementation::GetbHWPresent%3F9D062E023C.get preserve=no
  return m_bHWPresent;
  //## end CWCWedgeControlImplementation::GetbHWPresent%3F9D062E023C.get
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObjectInt * CWCWedgeControlImplementation::GetpSyncExcObj ()
{
  //## begin CWCWedgeControlImplementation::GetpSyncExcObj%4007E705010A.get preserve=no
  return m_pSyncExcObj;
  //## end CWCWedgeControlImplementation::GetpSyncExcObj%4007E705010A.get
}

void CWCWedgeControlImplementation::SetpSyncExcObj (CCOSyncObjectInt * value)
{
  //## begin CWCWedgeControlImplementation::SetpSyncExcObj%4007E705010A.set preserve=yes
  if (m_pSyncExcObj)
    m_pSyncExcObj->ReleaseRef();

  m_pSyncExcObj = value;
  m_pSyncExcObj->AddRef();
  //## end CWCWedgeControlImplementation::SetpSyncExcObj%4007E705010A.set
}

CCOSyncObject * CWCWedgeControlImplementation::GetpSyncStartObj ()
{
  //## begin CWCWedgeControlImplementation::GetpSyncStartObj%4007E7080128.get preserve=no
  return m_pSyncStartObj;
  //## end CWCWedgeControlImplementation::GetpSyncStartObj%4007E7080128.get
}

void CWCWedgeControlImplementation::SetpSyncStartObj (CCOSyncObject * value)
{
  //## begin CWCWedgeControlImplementation::SetpSyncStartObj%4007E7080128.set preserve=yes
  if (m_pSyncStartObj)
    m_pSyncStartObj->ReleaseRef();

  m_pSyncStartObj = value;
  m_pSyncStartObj->AddRef();
  //## end CWCWedgeControlImplementation::SetpSyncStartObj%4007E7080128.set
}

// Additional Declarations
  //## begin CWCWedgeControlImplementation%3DD0F8560188.declarations preserve=yes
  //## end CWCWedgeControlImplementation%3DD0F8560188.declarations

//## begin module%3DD0F89E0050.epilog preserve=yes
//## end module%3DD0F89E0050.epilog
