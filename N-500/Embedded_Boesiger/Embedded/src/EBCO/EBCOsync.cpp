//## begin module%3B8D53B800A6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D53B800A6.cm

//## begin module%3B8D53B800A6.cp preserve=no
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
//## end module%3B8D53B800A6.cp

//## Module: EBCOsync%3B8D53B800A6; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOsync.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B8D53B800A6.additionalIncludes preserve=no
//## end module%3B8D53B800A6.additionalIncludes

//## begin module%3B8D53B800A6.includes preserve=yes
//## end module%3B8D53B800A6.includes

// EBCOidnt
#include "EBCOidnt.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"


//## begin module%3B8D53B800A6.declarations preserve=no
//## end module%3B8D53B800A6.declarations

//## begin module%3B8D53B800A6.additionalDeclarations preserve=yes
//## end module%3B8D53B800A6.additionalDeclarations


// Class CCOSyncObject 






















CCOSyncObject::CCOSyncObject()
  //## begin CCOSyncObject::CCOSyncObject%.hasinit preserve=no
      : m_pException(NULL), m_bIsSignalled(false)
  //## end CCOSyncObject::CCOSyncObject%.hasinit
  //## begin CCOSyncObject::CCOSyncObject%.initialization preserve=yes
  //## end CCOSyncObject::CCOSyncObject%.initialization
{
  //## begin CCOSyncObject::CCOSyncObject%.body preserve=yes
  //## end CCOSyncObject::CCOSyncObject%.body
}

CCOSyncObject::CCOSyncObject (const CString& p_sName)
  //## begin CCOSyncObject::CCOSyncObject%1164093766.hasinit preserve=no
      : m_pException(NULL), m_bIsSignalled(false)
  //## end CCOSyncObject::CCOSyncObject%1164093766.hasinit
  //## begin CCOSyncObject::CCOSyncObject%1164093766.initialization preserve=yes
  , ICORefCounting(p_sName)
  //## end CCOSyncObject::CCOSyncObject%1164093766.initialization
{
  //## begin CCOSyncObject::CCOSyncObject%1164093766.body preserve=yes
  //## end CCOSyncObject::CCOSyncObject%1164093766.body
}


CCOSyncObject::~CCOSyncObject()
{
  //## begin CCOSyncObject::~CCOSyncObject%.body preserve=yes
    if (m_pException)
        m_pException->Delete();
    m_pException = NULL;
  //## end CCOSyncObject::~CCOSyncObject%.body
}



//## Other Operations (implementation)
void CCOSyncObject::SignalCompletion ()
{
  //## begin CCOSyncObject::SignalCompletion%999108324.body preserve=yes
	m_bIsSignalled = true;
	SetEvent();
  //## end CCOSyncObject::SignalCompletion%999108324.body
}

void CCOSyncObject::ResetCompletion ()
{
  //## begin CCOSyncObject::ResetCompletion%1040029833.body preserve=yes
    m_bIsSignalled = false;
    ResetEvent();
  //## end CCOSyncObject::ResetCompletion%1040029833.body
}

void CCOSyncObject::HasException ()
{
  //## begin CCOSyncObject::HasException%999280849.body preserve=yes
	XCOException* l_pException = NULL;

	CSingleLock l_Lock(&m_AccessLock, TRUE);

	// look for present exceptions
	l_pException = m_pException;
	m_pException = NULL;

	// throw existing exceptions
	if (l_pException)
		l_pException->Throw();
  //## end CCOSyncObject::HasException%999280849.body
}

void CCOSyncObject::Synchronize ()
{
  //## begin CCOSyncObject::Synchronize%999291448.body preserve=yes
    CSingleLock l_Lock(this, true);
    l_Lock.Unlock();

    // watch for exceptions
    HasException();
  //## end CCOSyncObject::Synchronize%999291448.body
}

void CCOSyncObject::Synchronize (const UINT p_uiTimeout)
{
  //## begin CCOSyncObject::Synchronize%1083932479.body preserve=yes
    if (::WaitForSingleObject(*this, p_uiTimeout) == WAIT_TIMEOUT)
    {
        // timeout expired
        throw new XCOExceptionErrorTimeout(CO_ID, IDE_CORE_TIMEOUT, _T(__FILE__), __LINE__);
    }

    // watch for exceptions
    HasException();
  //## end CCOSyncObject::Synchronize%1083932479.body
}

void CCOSyncObject::AttachException (XCOException* p_pException)
{
  //## begin CCOSyncObject::AttachException%1000031215.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);
	if (m_pException == NULL)
	{
		// attach new exception
		m_pException = p_pException;
	}
	else
	{
		// we already have an exception attached, ignore the new one
		p_pException->Delete();
	}
	l_Lock.Unlock();

    SignalCompletion();
  //## end CCOSyncObject::AttachException%1000031215.body
}

//## Get and Set Operations for Associations (implementation)

bool CCOSyncObject::GetbIsSignalled ()
{
  //## begin CCOSyncObject::GetbIsSignalled%409B80AC0142.get preserve=no
  return m_bIsSignalled;
  //## end CCOSyncObject::GetbIsSignalled%409B80AC0142.get
}

// Additional Declarations
  //## begin CCOSyncObject%3B8D554D00B2.declarations preserve=yes
  //## end CCOSyncObject%3B8D554D00B2.declarations

// Class CCOSyncObjectArray 


CCOSyncObjectArray::CCOSyncObjectArray()
  //## begin CCOSyncObjectArray::CCOSyncObjectArray%.hasinit preserve=no
  //## end CCOSyncObjectArray::CCOSyncObjectArray%.hasinit
  //## begin CCOSyncObjectArray::CCOSyncObjectArray%.initialization preserve=yes
  //## end CCOSyncObjectArray::CCOSyncObjectArray%.initialization
{
  //## begin CCOSyncObjectArray::CCOSyncObjectArray%.body preserve=yes
  //## end CCOSyncObjectArray::CCOSyncObjectArray%.body
}


CCOSyncObjectArray::~CCOSyncObjectArray()
{
  //## begin CCOSyncObjectArray::~CCOSyncObjectArray%.body preserve=yes
	// decrement ref count on contained objects
	for (int l_iCnt=0; l_iCnt<GetSize(); l_iCnt++)
	{
		CCOSyncObject* l_pSyncObj = GetAt(l_iCnt);
		if (l_pSyncObj)
		{
			// release reference
			l_pSyncObj->ReleaseRef();
		}
	}
  //## end CCOSyncObjectArray::~CCOSyncObjectArray%.body
}



//## Other Operations (implementation)
void CCOSyncObjectArray::Add (CCOSyncObject* p_pSyncObj, const bool p_bKeepOwnReference)
{
  //## begin CCOSyncObjectArray::Add%999119009.body preserve=yes
	if (p_bKeepOwnReference)
		p_pSyncObj->AddRef();

	CCOSyncObjectArrayInstantiated::Add(p_pSyncObj);
  //## end CCOSyncObjectArray::Add%999119009.body
}

void CCOSyncObjectArray::SignalCompletion ()
{
  //## begin CCOSyncObjectArray::SignalCompletion%999280847.body preserve=yes
    for (int l_iCnt=0; l_iCnt<GetSize(); l_iCnt++)
    {
        CCOSyncObject* l_pSyncObject = GetAt(l_iCnt);
        ASSERT(l_pSyncObject != NULL);

        l_pSyncObject->SignalCompletion();
    }
  //## end CCOSyncObjectArray::SignalCompletion%999280847.body
}

void CCOSyncObjectArray::HasException ()
{
  //## begin CCOSyncObjectArray::HasException%999280850.body preserve=yes
    for (int l_iCnt=0; l_iCnt<GetSize(); l_iCnt++)
    {
        CCOSyncObject* l_pSyncObject = GetAt(l_iCnt);
        ASSERT(l_pSyncObject != NULL);

        l_pSyncObject->HasException();
    }
  //## end CCOSyncObjectArray::HasException%999280850.body
}

void CCOSyncObjectArray::AttachException (XCOException* p_pException)
{
  //## begin CCOSyncObjectArray::AttachException%1000031216.body preserve=yes
    XCOException* l_pException = p_pException;

    for (int l_iCnt=0; l_iCnt<GetSize(); l_iCnt++)
    {
        CCOSyncObject* l_pSyncObject = GetAt(l_iCnt);
        ASSERT(l_pSyncObject != NULL);

        if (!l_pException)
            l_pException = p_pException->Clone();

        l_pSyncObject->AttachException(l_pException);
        l_pException = NULL;
    }
  //## end CCOSyncObjectArray::AttachException%1000031216.body
}

void CCOSyncObjectArray::Synchronize (DWORD p_dwTimeout)
{
  //## begin CCOSyncObjectArray::Synchronize%1090935982.body preserve=yes
    for (int l_iCnt=0; l_iCnt<GetSize(); l_iCnt++)
    {
        CCOSyncObject* l_pSyncObj = GetAt(l_iCnt);
        l_pSyncObj->Synchronize(p_dwTimeout);
    }
  //## end CCOSyncObjectArray::Synchronize%1090935982.body
}

// Additional Declarations
  //## begin CCOSyncObjectArray%3B8D5CD80267.declarations preserve=yes
  //## end CCOSyncObjectArray%3B8D5CD80267.declarations

//## begin module%3B8D53B800A6.epilog preserve=yes
//## end module%3B8D53B800A6.epilog
