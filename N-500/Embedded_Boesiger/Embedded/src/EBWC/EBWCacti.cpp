//## begin module%3E5E0B6D00EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E5E0B6D00EA.cm

//## begin module%3E5E0B6D00EA.cp preserve=no
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
//## end module%3E5E0B6D00EA.cp

//## Module: EBWCacti%3E5E0B6D00EA; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCacti.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E5E0B6D00EA.additionalIncludes preserve=no
//## end module%3E5E0B6D00EA.additionalIncludes

//## begin module%3E5E0B6D00EA.includes preserve=yes
//## end module%3E5E0B6D00EA.includes

// EBWCacti
#include "EBWCacti.h"
// EBWCimpl
#include "EBWCimpl.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3E5E0B6D00EA.declarations preserve=no
//## end module%3E5E0B6D00EA.declarations

//## begin module%3E5E0B6D00EA.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}
//## end module%3E5E0B6D00EA.additionalDeclarations


// Class CWCActionInitialize 

//## begin CWCActionInitialize::dwInitializedEvent%3FBB7819032C.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CWCActionInitialize::m_dwInitializedEvent = 0;
//## end CWCActionInitialize::dwInitializedEvent%3FBB7819032C.role

CWCActionInitialize::CWCActionInitialize (const UINT p_uiID, ICOStateMachineContext* p_pContext)
  //## begin CWCActionInitialize::CWCActionInitialize%1046351112.hasinit preserve=no
  //## end CWCActionInitialize::CWCActionInitialize%1046351112.hasinit
  //## begin CWCActionInitialize::CWCActionInitialize%1046351112.initialization preserve=yes
  :CCOAction(p_uiID, p_pContext)
  //## end CWCActionInitialize::CWCActionInitialize%1046351112.initialization
{
  //## begin CWCActionInitialize::CWCActionInitialize%1046351112.body preserve=yes
  //## end CWCActionInitialize::CWCActionInitialize%1046351112.body
}


CWCActionInitialize::~CWCActionInitialize()
{
  //## begin CWCActionInitialize::~CWCActionInitialize%.body preserve=yes
  //## end CWCActionInitialize::~CWCActionInitialize%.body
}



//## Other Operations (implementation)
CCOSyncObject* CWCActionInitialize::ExecuteAction ()
{
  //## begin CWCActionInitialize::ExecuteAction%1046351113.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);

    if (l_pContext->GetbHWPresent())
    {
        return IHIInterface::GetInstance()->WCInitialize(m_dwInitializedEvent);
    }
    else
    {
        CCOSyncObject* l_pSyncObj = new CCOSyncObject();
        l_pSyncObj->SignalCompletion();
        return l_pSyncObj;
    }
  //## end CWCActionInitialize::ExecuteAction%1046351113.body
}

void CWCActionInitialize::Done ()
{
  //## begin CWCActionInitialize::Done%1052827018.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);

    if (l_pContext->GetbHWPresent())
        IHIInterface::GetInstance()->CloseEvent(m_dwInitializedEvent, m_pServerSyncObj);

    CCOAction::Done();
  //## end CWCActionInitialize::Done%1052827018.body
}

void CWCActionInitialize::Cancel ()
{
  //## begin CWCActionInitialize::Cancel%1164967778.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);

#ifdef _WIN32_WCE
	if (l_pContext->GetbHWPresent() && m_pServerSyncObj)
		IHIInterface::GetInstance()->CloseEvent(m_dwInitializedEvent, m_pServerSyncObj);
#endif

	CCOAction::Cancel();
  //## end CWCActionInitialize::Cancel%1164967778.body
}

//## Get and Set Operations for Associations (implementation)

DWORD CWCActionInitialize::GetdwInitializedEvent ()
{
  //## begin CWCActionInitialize::GetdwInitializedEvent%3FBB7819032C.get preserve=no
  return m_dwInitializedEvent;
  //## end CWCActionInitialize::GetdwInitializedEvent%3FBB7819032C.get
}

void CWCActionInitialize::SetdwInitializedEvent (DWORD value)
{
  //## begin CWCActionInitialize::SetdwInitializedEvent%3FBB7819032C.set preserve=no
  m_dwInitializedEvent = value;
  //## end CWCActionInitialize::SetdwInitializedEvent%3FBB7819032C.set
}

// Additional Declarations
  //## begin CWCActionInitialize%3E5E0B3000EA.declarations preserve=yes
  //## end CWCActionInitialize%3E5E0B3000EA.declarations

// Class CWCActionReferencing 

//## begin CWCActionReferencing::dwReferencedEvent%3FBB788102B0.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CWCActionReferencing::m_dwReferencedEvent = 0;
//## end CWCActionReferencing::dwReferencedEvent%3FBB788102B0.role

CWCActionReferencing::CWCActionReferencing (const UINT p_uiID, ICOStateMachineContext* p_pContext)
  //## begin CWCActionReferencing::CWCActionReferencing%1052922967.hasinit preserve=no
  //## end CWCActionReferencing::CWCActionReferencing%1052922967.hasinit
  //## begin CWCActionReferencing::CWCActionReferencing%1052922967.initialization preserve=yes
  :CCOAction(p_uiID, p_pContext)
  //## end CWCActionReferencing::CWCActionReferencing%1052922967.initialization
{
  //## begin CWCActionReferencing::CWCActionReferencing%1052922967.body preserve=yes
  //## end CWCActionReferencing::CWCActionReferencing%1052922967.body
}


CWCActionReferencing::~CWCActionReferencing()
{
  //## begin CWCActionReferencing::~CWCActionReferencing%.body preserve=yes
  //## end CWCActionReferencing::~CWCActionReferencing%.body
}



//## Other Operations (implementation)
CCOSyncObject* CWCActionReferencing::ExecuteAction ()
{
  //## begin CWCActionReferencing::ExecuteAction%1052922969.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);

    if (l_pContext->GetbHWPresent())
    {
        return IHIInterface::GetInstance()->WCReferencing(m_dwReferencedEvent);
    }
    else
    {
        CCOSyncObject* l_pSyncObj = new CCOSyncObject();
        l_pSyncObj->SignalCompletion();
        return l_pSyncObj;
    }
  //## end CWCActionReferencing::ExecuteAction%1052922969.body
}

void CWCActionReferencing::Done ()
{
  //## begin CWCActionReferencing::Done%1052922968.body preserve=yes
  CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
  ASSERT(l_pContext != NULL);

  if (l_pContext->GetbHWPresent())
      IHIInterface::GetInstance()->CloseEvent(m_dwReferencedEvent, m_pServerSyncObj);

  CCOAction::Done();
  //## end CWCActionReferencing::Done%1052922968.body
}

void CWCActionReferencing::Cancel ()
{
  //## begin CWCActionReferencing::Cancel%1164967779.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);
#ifdef _WIN32_WCE
	if (l_pContext->GetbHWPresent() && m_pServerSyncObj)
		IHIInterface::GetInstance()->CloseEvent(m_dwReferencedEvent, m_pServerSyncObj);
#endif

	CCOAction::Cancel();
  //## end CWCActionReferencing::Cancel%1164967779.body
}

//## Get and Set Operations for Associations (implementation)

DWORD CWCActionReferencing::GetdwReferencedEvent ()
{
  //## begin CWCActionReferencing::GetdwReferencedEvent%3FBB788102B0.get preserve=no
  return m_dwReferencedEvent;
  //## end CWCActionReferencing::GetdwReferencedEvent%3FBB788102B0.get
}

void CWCActionReferencing::SetdwReferencedEvent (DWORD value)
{
  //## begin CWCActionReferencing::SetdwReferencedEvent%3FBB788102B0.set preserve=no
  m_dwReferencedEvent = value;
  //## end CWCActionReferencing::SetdwReferencedEvent%3FBB788102B0.set
}

// Additional Declarations
  //## begin CWCActionReferencing%3EC252CD003E.declarations preserve=yes
  //## end CWCActionReferencing%3EC252CD003E.declarations

// Class CWCActionStopMeasuring 

//## begin CWCActionStopMeasuring::dwStoppedEvent%3FBB78A80290.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CWCActionStopMeasuring::m_dwStoppedEvent = 0;
//## end CWCActionStopMeasuring::dwStoppedEvent%3FBB78A80290.role

CWCActionStopMeasuring::CWCActionStopMeasuring (const UINT p_uiID, ICOStateMachineContext* p_pContext)
  //## begin CWCActionStopMeasuring::CWCActionStopMeasuring%1053065365.hasinit preserve=no
  //## end CWCActionStopMeasuring::CWCActionStopMeasuring%1053065365.hasinit
  //## begin CWCActionStopMeasuring::CWCActionStopMeasuring%1053065365.initialization preserve=yes
  :CCOAction(p_uiID, p_pContext)
  //## end CWCActionStopMeasuring::CWCActionStopMeasuring%1053065365.initialization
{
  //## begin CWCActionStopMeasuring::CWCActionStopMeasuring%1053065365.body preserve=yes
  //## end CWCActionStopMeasuring::CWCActionStopMeasuring%1053065365.body
}


CWCActionStopMeasuring::~CWCActionStopMeasuring()
{
  //## begin CWCActionStopMeasuring::~CWCActionStopMeasuring%.body preserve=yes
  //## end CWCActionStopMeasuring::~CWCActionStopMeasuring%.body
}



//## Other Operations (implementation)
CCOSyncObject* CWCActionStopMeasuring::ExecuteAction ()
{
  //## begin CWCActionStopMeasuring::ExecuteAction%1053065367.body preserve=yes
  CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
  ASSERT(l_pContext != NULL);

  if (l_pContext->GetbHWPresent())
  {
      return IHIInterface::GetInstance()->WCStop(m_dwStoppedEvent);
  }
  else
  {
      CCOSyncObject* l_pSyncObj = new CCOSyncObject();
      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
  }
  //## end CWCActionStopMeasuring::ExecuteAction%1053065367.body
}

void CWCActionStopMeasuring::Done ()
{
  //## begin CWCActionStopMeasuring::Done%1053065366.body preserve=yes
  CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
  ASSERT(l_pContext != NULL);

  if (l_pContext->GetbHWPresent())
      IHIInterface::GetInstance()->CloseEvent(m_dwStoppedEvent, m_pServerSyncObj);

  CCOAction::Done();
  //## end CWCActionStopMeasuring::Done%1053065366.body
}

void CWCActionStopMeasuring::Cancel ()
{
  //## begin CWCActionStopMeasuring::Cancel%1164967780.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);
#ifdef _WIN32_WCE
	if (l_pContext->GetbHWPresent() && m_pServerSyncObj)
		IHIInterface::GetInstance()->CloseEvent(m_dwStoppedEvent, m_pServerSyncObj);
#endif

	CCOAction::Cancel();
  //## end CWCActionStopMeasuring::Cancel%1164967780.body
}

//## Get and Set Operations for Associations (implementation)

DWORD CWCActionStopMeasuring::GetdwStoppedEvent ()
{
  //## begin CWCActionStopMeasuring::GetdwStoppedEvent%3FBB78A80290.get preserve=no
  return m_dwStoppedEvent;
  //## end CWCActionStopMeasuring::GetdwStoppedEvent%3FBB78A80290.get
}

void CWCActionStopMeasuring::SetdwStoppedEvent (DWORD value)
{
  //## begin CWCActionStopMeasuring::SetdwStoppedEvent%3FBB78A80290.set preserve=no
  m_dwStoppedEvent = value;
  //## end CWCActionStopMeasuring::SetdwStoppedEvent%3FBB78A80290.set
}

// Additional Declarations
  //## begin CWCActionStopMeasuring%3EC480C1032C.declarations preserve=yes
  //## end CWCActionStopMeasuring%3EC480C1032C.declarations

// Class CWCActionCurrDir 

//## begin CWCActionCurrDir::dwCurrDirEvent%3FBC855F02C0.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CWCActionCurrDir::m_dwCurrDirEvent = 0;
//## end CWCActionCurrDir::dwCurrDirEvent%3FBC855F02C0.role

//## begin CWCActionCurrDir::eEventRegistration%3FBC992002A0.role preserve=no  public: static EHIOpenEventRegistration {1..1 -> 1..1VFHN}
EHIOpenEventRegistration CWCActionCurrDir::m_eEventRegistration = eHIUndefined;
//## end CWCActionCurrDir::eEventRegistration%3FBC992002A0.role

CWCActionCurrDir::CWCActionCurrDir (const UINT p_uiID, ICOStateMachineContext* p_pContext)
  //## begin CWCActionCurrDir::CWCActionCurrDir%1069318245.hasinit preserve=no
  //## end CWCActionCurrDir::CWCActionCurrDir%1069318245.hasinit
  //## begin CWCActionCurrDir::CWCActionCurrDir%1069318245.initialization preserve=yes
  :CCOAction(p_uiID, p_pContext)
  //## end CWCActionCurrDir::CWCActionCurrDir%1069318245.initialization
{
  //## begin CWCActionCurrDir::CWCActionCurrDir%1069318245.body preserve=yes
  //## end CWCActionCurrDir::CWCActionCurrDir%1069318245.body
}


CWCActionCurrDir::~CWCActionCurrDir()
{
  //## begin CWCActionCurrDir::~CWCActionCurrDir%.body preserve=yes
  //## end CWCActionCurrDir::~CWCActionCurrDir%.body
}



//## Other Operations (implementation)
CCOSyncObject* CWCActionCurrDir::ExecuteAction ()
{
  //## begin CWCActionCurrDir::ExecuteAction%1069318247.body preserve=yes
  DWORD l_dwRetVal = 0;
  CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
  ASSERT(l_pContext != NULL);

#ifdef _WIN32_WCE
  if (l_pContext->GetbHWPresent())
  {   
      return IHIInterface::GetInstance()->OpenEvent(m_dwCurrDirEvent, m_eEventRegistration);
  }
  else
  {
      CCOSyncObject* l_pSyncObj = new CCOSyncObject();
      l_pSyncObj->SignalCompletion();
      return l_pSyncObj;
  }
#else
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();
    l_pSyncObj->SignalCompletion();
    return l_pSyncObj;
#endif
  //## end CWCActionCurrDir::ExecuteAction%1069318247.body
}

void CWCActionCurrDir::Done ()
{
  //## begin CWCActionCurrDir::Done%1069318246.body preserve=yes
  CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
  ASSERT(l_pContext != NULL);

#ifdef _WIN32_WCE
  if (l_pContext->GetbHWPresent())
      IHIInterface::GetInstance()->CloseEvent(m_dwCurrDirEvent, m_pServerSyncObj);
#endif

  CCOAction::Done();
  //## end CWCActionCurrDir::Done%1069318246.body
}

void CWCActionCurrDir::Cancel ()
{
  //## begin CWCActionCurrDir::Cancel%1164967781.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);
#ifdef _WIN32_WCE
	if (l_pContext->GetbHWPresent() && m_pServerSyncObj)
		IHIInterface::GetInstance()->CloseEvent(m_dwCurrDirEvent, m_pServerSyncObj);
#endif

	CCOAction::Cancel();
  //## end CWCActionCurrDir::Cancel%1164967781.body
}

//## Get and Set Operations for Associations (implementation)

DWORD CWCActionCurrDir::GetdwCurrDirEvent ()
{
  //## begin CWCActionCurrDir::GetdwCurrDirEvent%3FBC855F02C0.get preserve=no
  return m_dwCurrDirEvent;
  //## end CWCActionCurrDir::GetdwCurrDirEvent%3FBC855F02C0.get
}

void CWCActionCurrDir::SetdwCurrDirEvent (DWORD value)
{
  //## begin CWCActionCurrDir::SetdwCurrDirEvent%3FBC855F02C0.set preserve=no
  m_dwCurrDirEvent = value;
  //## end CWCActionCurrDir::SetdwCurrDirEvent%3FBC855F02C0.set
}

EHIOpenEventRegistration CWCActionCurrDir::GeteEventRegistration ()
{
  //## begin CWCActionCurrDir::GeteEventRegistration%3FBC992002A0.get preserve=no
  return m_eEventRegistration;
  //## end CWCActionCurrDir::GeteEventRegistration%3FBC992002A0.get
}

void CWCActionCurrDir::SeteEventRegistration (EHIOpenEventRegistration value)
{
  //## begin CWCActionCurrDir::SeteEventRegistration%3FBC992002A0.set preserve=no
  m_eEventRegistration = value;
  //## end CWCActionCurrDir::SeteEventRegistration%3FBC992002A0.set
}

// Additional Declarations
  //## begin CWCActionCurrDir%3FBC84DB0280.declarations preserve=yes
  //## end CWCActionCurrDir%3FBC84DB0280.declarations

// Class CWCActionMeasuring 

//## begin CWCActionMeasuring::dwMeasuringExcEvent%400B89400272.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CWCActionMeasuring::m_dwMeasuringExcEvent = 0;
//## end CWCActionMeasuring::dwMeasuringExcEvent%400B89400272.role

CWCActionMeasuring::CWCActionMeasuring (const UINT p_uiID, ICOStateMachineContext* p_pContext)
  //## begin CWCActionMeasuring::CWCActionMeasuring%1074497961.hasinit preserve=no
  //## end CWCActionMeasuring::CWCActionMeasuring%1074497961.hasinit
  //## begin CWCActionMeasuring::CWCActionMeasuring%1074497961.initialization preserve=yes
  :CCOAction(p_uiID, p_pContext)
  //## end CWCActionMeasuring::CWCActionMeasuring%1074497961.initialization
{
  //## begin CWCActionMeasuring::CWCActionMeasuring%1074497961.body preserve=yes
  //## end CWCActionMeasuring::CWCActionMeasuring%1074497961.body
}


CWCActionMeasuring::~CWCActionMeasuring()
{
  //## begin CWCActionMeasuring::~CWCActionMeasuring%.body preserve=yes
  //## end CWCActionMeasuring::~CWCActionMeasuring%.body
}



//## Other Operations (implementation)
CCOSyncObject* CWCActionMeasuring::ExecuteAction ()
{
  //## begin CWCActionMeasuring::ExecuteAction%1074497963.body preserve=yes
	CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
	ASSERT(l_pContext != NULL);

	CCOSyncObject* l_pSyncObj = NULL;
#ifdef _WIN32_WCE
	if (l_pContext->GetbHWPresent())
	{ 
		IHIInterface::GetInstance()->SetHWExceptionEventNr(m_dwMeasuringExcEvent);
		l_pSyncObj = IHIInterface::GetInstance()->OpenEvent(m_dwMeasuringExcEvent, eHIHigh);
	}
	else
	{
		l_pSyncObj = new CCOSyncObject();
	}
#else
	l_pSyncObj = new CCOSyncObject();
#endif

	return l_pSyncObj;
  //## end CWCActionMeasuring::ExecuteAction%1074497963.body
}

void CWCActionMeasuring::Done ()
{
  //## begin CWCActionMeasuring::Done%1074497962.body preserve=yes
  CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
  ASSERT(l_pContext != NULL);

#ifdef _WIN32_WCE
  if (l_pContext->GetbHWPresent())
      IHIInterface::GetInstance()->CloseEvent(m_dwMeasuringExcEvent, m_pServerSyncObj);
#endif

  CCOAction::Done();
  //## end CWCActionMeasuring::Done%1074497962.body
}

void CWCActionMeasuring::Cancel ()
{
  //## begin CWCActionMeasuring::Cancel%1164967777.body preserve=yes
    CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(m_pContext);
    ASSERT(l_pContext != NULL);
#ifdef _WIN32_WCE
	if (l_pContext->GetbHWPresent() && m_pServerSyncObj)
		IHIInterface::GetInstance()->CloseEvent(m_dwMeasuringExcEvent, m_pServerSyncObj);
#endif

	CCOAction::Cancel();
  //## end CWCActionMeasuring::Cancel%1164967777.body
}

//## Get and Set Operations for Associations (implementation)

DWORD CWCActionMeasuring::GetdwMeasuringExcEvent ()
{
  //## begin CWCActionMeasuring::GetdwMeasuringExcEvent%400B89400272.get preserve=no
  return m_dwMeasuringExcEvent;
  //## end CWCActionMeasuring::GetdwMeasuringExcEvent%400B89400272.get
}

void CWCActionMeasuring::SetdwMeasuringExcEvent (DWORD value)
{
  //## begin CWCActionMeasuring::SetdwMeasuringExcEvent%400B89400272.set preserve=no
  m_dwMeasuringExcEvent = value;
  //## end CWCActionMeasuring::SetdwMeasuringExcEvent%400B89400272.set
}

// Additional Declarations
  //## begin CWCActionMeasuring%400B88AC00AB.declarations preserve=yes
  //## end CWCActionMeasuring%400B88AC00AB.declarations

//## begin module%3E5E0B6D00EA.epilog preserve=yes
//## end module%3E5E0B6D00EA.epilog
