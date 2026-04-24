//## begin module%3DE5EC52016C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EC52016C.cm

//## begin module%3DE5EC52016C.cp preserve=no
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
//## end module%3DE5EC52016C.cp

//## Module: EBESintf%3DE5EC52016C; Package body
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Source file: R:\Embedded\src\EBES\EBESintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EC52016C.additionalIncludes preserve=no
//## end module%3DE5EC52016C.additionalIncludes

//## begin module%3DE5EC52016C.includes preserve=yes
//## end module%3DE5EC52016C.includes

// EBCOsync
#include "EBCOsync.h"
// EBESintf
#include "EBESintf.h"
// EBESidnt
#include "EBESidnt.h"
// EBHIenum
#include "EBHIenum.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3DE5EC52016C.declarations preserve=no
//## end module%3DE5EC52016C.declarations

//## begin module%3DE5EC52016C.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}

#define DUMMY_RETURN_ARRAY {  \
    CCOSyncObjectArray* l_pSyncObjArray = new CCOSyncObjectArray();		\
    l_pSyncObjArray->SignalCompletion();								\
    return l_pSyncObjArray;												\
}
//## end module%3DE5EC52016C.additionalDeclarations


// Class CESEventSourceInterface 

//## begin CESEventSourceInterface::uiNextClientID%3EF320A40196.attr preserve=no  private: static UINT {U} 0
UINT CESEventSourceInterface::m_uiNextClientID = 0;
//## end CESEventSourceInterface::uiNextClientID%3EF320A40196.attr



CESEventSourceInterface::CESEventSourceInterface (UINT p_uiID)
  //## begin CESEventSourceInterface::CESEventSourceInterface%1038837056.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CESEventSourceInterface::CESEventSourceInterface%1038837056.hasinit
  //## begin CESEventSourceInterface::CESEventSourceInterface%1038837056.initialization preserve=yes
    ,IPIEventSourceInterface(ES_ID)
  //## end CESEventSourceInterface::CESEventSourceInterface%1038837056.initialization
{
  //## begin CESEventSourceInterface::CESEventSourceInterface%1038837056.body preserve=yes
  //## end CESEventSourceInterface::CESEventSourceInterface%1038837056.body
}


CESEventSourceInterface::~CESEventSourceInterface()
{
  //## begin CESEventSourceInterface::~CESEventSourceInterface%.body preserve=yes
  //## end CESEventSourceInterface::~CESEventSourceInterface%.body
}



//## Other Operations (implementation)
UINT CESEventSourceInterface::GetuiID ()
{
  //## begin CESEventSourceInterface::GetuiID%1038837052.body preserve=yes
  return m_uiID;
  //## end CESEventSourceInterface::GetuiID%1038837052.body
}

CCOSyncObject* CESEventSourceInterface::ConnectionEstablished ()
{
  //## begin CESEventSourceInterface::ConnectionEstablished%1055744816.body preserve=yes
	TRACE(_T("ES - ConnectionEstablished executed\n"));
    CCOSyncObject* l_pSyncObject = new CCOSyncObject();
    l_pSyncObject->SignalCompletion();

    return l_pSyncObject;
  //## end CESEventSourceInterface::ConnectionEstablished%1055744816.body
}

CCOSyncObject* CESEventSourceInterface::ConnectionLost ()
{
  //## begin CESEventSourceInterface::ConnectionLost%1055744817.body preserve=yes
	TRACE(_T("ES - ConnectionLost executed\n"));

	Cleanup();

    CCOSyncObject* l_pSyncObject = new CCOSyncObject();
    l_pSyncObject->SignalCompletion();

    return l_pSyncObject;
  //## end CESEventSourceInterface::ConnectionLost%1055744817.body
}

CCOSyncObject* CESEventSourceInterface::Startup ()
{
  //## begin CESEventSourceInterface::Startup%1056098156.body preserve=yes
	TRACE(_T("ES - Startup executed\n"));
    CCOSyncObject* l_pSyncObject = new CCOSyncObject();
    l_pSyncObject->SignalCompletion();

    return l_pSyncObject;
  //## end CESEventSourceInterface::Startup%1056098156.body
}

CCOSyncObject* CESEventSourceInterface::Shutdown ()
{
  //## begin CESEventSourceInterface::Shutdown%1056098157.body preserve=yes
	TRACE(_T("ES - Shutdown executed\n"));

	Cleanup();

    CCOSyncObject* l_pSyncObject = new CCOSyncObject();
    l_pSyncObject->SignalCompletion();

    return l_pSyncObject;
  //## end CESEventSourceInterface::Shutdown%1056098157.body
}

CCOSyncObjectArray* CESEventSourceInterface::RegisterForEvent (UINT p_uiInputID, INT& p_iEventID)
{
  //## begin CESEventSourceInterface::RegisterForEvent%1056353484.body preserve=yes

    TRACE(_T("EBES - RegisterForEvent executed\n"));

	// client counter
	UINT l_uiCurClientID = m_uiNextClientID++;
	TRACE1("Client ID for unregister: %d\n", l_uiCurClientID);
	TRACE1("Event ID for fire event: %d\n", p_uiInputID);


	// sync object 0
	// returns a unique number to ident the event
	CCOSyncObjectInt* l_pSyncObject0 = new CCOSyncObjectInt(_T("ES:RegisterForEvent"), l_uiCurClientID);
    p_iEventID = (INT)l_uiCurClientID;
	l_pSyncObject0->SignalCompletion();

	// open event on hi interface
	CCOSyncObjectPtr l_pSyncObject1 = CHIInterface::GetInstance()->OpenEvent(p_uiInputID, eHIUndefined);
	ASSERT(l_pSyncObject1 != NULL);

	// generate new client
	CESClient* l_pClient = new CESClient(l_pSyncObject1, p_uiInputID);

	// save client
	m_Clients.SetAt(l_uiCurClientID, l_pClient);

	// new sync object array
	CCOSyncObjectArray* l_pSyncArray = new CCOSyncObjectArray();

	// add objects and return array
	l_pSyncArray->Add(l_pSyncObject0, false);
	l_pSyncArray->Add(l_pSyncObject1);
	ASSERT(l_pSyncArray->GetSize() == 2);

    return l_pSyncArray;

  //## end CESEventSourceInterface::RegisterForEvent%1056353484.body
}

CCOSyncObject* CESEventSourceInterface::UnRegisterFromEvent (UINT p_uiClientID)
{
  //## begin CESEventSourceInterface::UnRegisterFromEvent%1056353485.body preserve=yes
	TRACE(_T("ES - UnRegisterFromEvent executed\n"));
	CESClient* l_pClient = NULL;

	// search event in list
	BOOL l_bRes = m_Clients.Lookup(p_uiClientID, l_pClient);
	ASSERT(l_bRes != 0);

	// get inputID from saved client
	UINT l_uiInputID = l_pClient->GetuiInputID();

	// close event
	CHIInterface::GetInstance()->CloseEvent(l_uiInputID, l_pClient->GetpSyncObj());

	// delete client from map
	m_Clients.RemoveKey(p_uiClientID);
	delete l_pClient;

	// signal completion to the client
	CCOSyncObject* l_pSyncObject = new CCOSyncObject(_T("ES:UnRegisterFromEvent"));
    l_pSyncObject->SignalCompletion();

    return l_pSyncObject;
  //## end CESEventSourceInterface::UnRegisterFromEvent%1056353485.body
}

void CESEventSourceInterface::Cleanup ()
{
  //## begin CESEventSourceInterface::Cleanup%1164898825.body preserve=yes
	// close all events
	for (POSITION l_Pos=m_Clients.GetStartPosition(); l_Pos!=NULL;)
	{
		UINT l_uiClientID;
		CESClient* l_pClient;
		m_Clients.GetNextAssoc(l_Pos, l_uiClientID, l_pClient);
		CHIInterface::GetInstance()->CloseEvent(l_pClient->GetuiInputID(), l_pClient->GetpSyncObj());
		delete l_pClient;
	}
	m_Clients.RemoveAll();
  //## end CESEventSourceInterface::Cleanup%1164898825.body
}

// Additional Declarations
  //## begin CESEventSourceInterface%3DE713B402CD.declarations preserve=yes
  //## end CESEventSourceInterface%3DE713B402CD.declarations

// Class CESClient 




CESClient::CESClient (CCOSyncObject* p_pSyncObj, UINT p_uiInputID)
  //## begin CESClient::CESClient%1056098158.hasinit preserve=no
      : m_pSyncObj(p_pSyncObj), m_uiInputID(p_uiInputID)
  //## end CESClient::CESClient%1056098158.hasinit
  //## begin CESClient::CESClient%1056098158.initialization preserve=yes
  //## end CESClient::CESClient%1056098158.initialization
{
  //## begin CESClient::CESClient%1056098158.body preserve=yes
	m_pSyncObj->AddRef();
  //## end CESClient::CESClient%1056098158.body
}


CESClient::~CESClient()
{
  //## begin CESClient::~CESClient%.body preserve=yes
	m_pSyncObj->ReleaseRef();
	m_pSyncObj = NULL;
  //## end CESClient::~CESClient%.body
}


//## Get and Set Operations for Associations (implementation)

CCOSyncObject * CESClient::GetpSyncObj ()
{
  //## begin CESClient::GetpSyncObj%3EF31F320252.get preserve=no
  return m_pSyncObj;
  //## end CESClient::GetpSyncObj%3EF31F320252.get
}

UINT CESClient::GetuiInputID ()
{
  //## begin CESClient::GetuiInputID%3EF6AF20006E.get preserve=no
  return m_uiInputID;
  //## end CESClient::GetuiInputID%3EF6AF20006E.get
}

// Additional Declarations
  //## begin CESClient%3EF31EEE01E4.declarations preserve=yes
  //## end CESClient%3EF31EEE01E4.declarations

//## begin module%3DE5EC52016C.epilog preserve=yes
//## end module%3DE5EC52016C.epilog
