//## begin module%3B8D539F0154.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D539F0154.cm

//## begin module%3B8D539F0154.cp preserve=no
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
//## end module%3B8D539F0154.cp

//## Module: EBCOrefc%3B8D539F0154; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOrefc.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B8D539F0154.additionalIncludes preserve=no
//## end module%3B8D539F0154.additionalIncludes

//## begin module%3B8D539F0154.includes preserve=yes
#include <typeinfo.h>
//## end module%3B8D539F0154.includes

// EBCOrefc
#include "EBCOrefc.h"


//## begin module%3B8D539F0154.declarations preserve=no
//## end module%3B8D539F0154.declarations

//## begin module%3B8D539F0154.additionalDeclarations preserve=yes
//## end module%3B8D539F0154.additionalDeclarations


// Class ICORefCounting 




//## begin ICORefCounting::LivingObjects%4565C96E03D4.role preserve=no  public: static ICORefCounting {0..0 -> 1..nRFHN}
CTypedPtrList<CPtrList, ICORefCounting*> ICORefCounting::m_LivingObjects;
//## end ICORefCounting::LivingObjects%4565C96E03D4.role


//## begin ICORefCounting::LivingObjectsLock%4565C99B031A.role preserve=no  public: static CCriticalSection {1..1 -> 1..1VFHN}
CCriticalSection ICORefCounting::m_LivingObjectsLock;
//## end ICORefCounting::LivingObjectsLock%4565C99B031A.role

ICORefCounting::ICORefCounting()
  //## begin ICORefCounting::ICORefCounting%.hasinit preserve=no
      : m_uiRefCount(1)
  //## end ICORefCounting::ICORefCounting%.hasinit
  //## begin ICORefCounting::ICORefCounting%.initialization preserve=yes
  //## end ICORefCounting::ICORefCounting%.initialization
{
  //## begin ICORefCounting::ICORefCounting%.body preserve=yes
#ifdef DEBUG
	CSingleLock l_Lock(&m_LivingObjectsLock, true);

	m_LivingObjects.AddTail(this);
#endif
  //## end ICORefCounting::ICORefCounting%.body
}

ICORefCounting::ICORefCounting (const CString& p_sName)
  //## begin ICORefCounting::ICORefCounting%1164298708.hasinit preserve=no
      : m_uiRefCount(1)
  //## end ICORefCounting::ICORefCounting%1164298708.hasinit
  //## begin ICORefCounting::ICORefCounting%1164298708.initialization preserve=yes
  , m_sName(p_sName)
  //## end ICORefCounting::ICORefCounting%1164298708.initialization
{
  //## begin ICORefCounting::ICORefCounting%1164298708.body preserve=yes
#ifdef DEBUG
	CSingleLock l_Lock(&m_LivingObjectsLock, true);

	m_LivingObjects.AddTail(this);
#endif
  //## end ICORefCounting::ICORefCounting%1164298708.body
}


ICORefCounting::~ICORefCounting()
{
  //## begin ICORefCounting::~ICORefCounting%.body preserve=yes
#ifdef DEBUG
	CSingleLock l_Lock(&m_LivingObjectsLock, true);

	for (POSITION l_Pos=m_LivingObjects.GetHeadPosition(); l_Pos!=NULL;)
	{
		POSITION l_CurPos = l_Pos;
		ICORefCounting* l_pObj = m_LivingObjects.GetNext(l_Pos);
		if (l_pObj == this)
		{
			m_LivingObjects.RemoveAt(l_CurPos);
			break;
		}
	}
#endif
  //## end ICORefCounting::~ICORefCounting%.body
}



//## Other Operations (implementation)
void ICORefCounting::AddRef ()
{
  //## begin ICORefCounting::AddRef%999108322.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

	m_uiRefCount++;
  //## end ICORefCounting::AddRef%999108322.body
}

void ICORefCounting::ReleaseRef ()
{
  //## begin ICORefCounting::ReleaseRef%999108323.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

	ASSERT(m_uiRefCount > 0);

	m_uiRefCount--;
	if (m_uiRefCount == 0)
	{
		// commit suicide
		l_Lock.Unlock();
		delete this;
	}
  //## end ICORefCounting::ReleaseRef%999108323.body
}

int ICORefCounting::TraceLivingObjects ()
{
  //## begin ICORefCounting::TraceLivingObjects%1164298707.body preserve=yes
#ifdef DEBUG
	CSingleLock l_Lock(&m_LivingObjectsLock, true);

	CString l_sMsg;
	for (POSITION l_Pos=m_LivingObjects.GetHeadPosition(); l_Pos!=NULL;)
	{
		ICORefCounting* l_pObj = m_LivingObjects.GetNext(l_Pos);
		const type_info& l_TypeInfo = typeid(*l_pObj);
		CString l_sTypeInfo = l_TypeInfo.name();

		l_sMsg.Format(_T("RefCount Object 0x%X, type='%s', named '%s', RefCount=%d\n"), (UINT)l_pObj, (LPCTSTR)l_sTypeInfo, (LPCTSTR)l_pObj->m_sName, l_pObj->m_uiRefCount);
		TRACE(l_sMsg);
	}
	l_sMsg.Format(_T("Number of living ref count objects: %d\n"), m_LivingObjects.GetCount());
	TRACE(l_sMsg);
	return m_LivingObjects.GetCount();
#else
	return 0;
#endif
  //## end ICORefCounting::TraceLivingObjects%1164298707.body
}

CString ICORefCounting::GetLivingObjectInfo ()
{
  //## begin ICORefCounting::GetLivingObjectInfo%1174997739.body preserve=yes
	CString l_sInfo;
#ifdef DEBUG
	CSingleLock l_Lock(&m_LivingObjectsLock, true);

	CString l_sMsg;
	for (POSITION l_Pos=m_LivingObjects.GetHeadPosition(); l_Pos!=NULL;)
	{
		ICORefCounting* l_pObj = m_LivingObjects.GetNext(l_Pos);
		const type_info& l_TypeInfo = typeid(*l_pObj);
		CString l_sTypeInfo = l_TypeInfo.name();

		l_sMsg.Format(_T("RefCount Object 0x%X, type='%s', named '%s', RefCount=%d\n"), (UINT)l_pObj, (LPCTSTR)l_sTypeInfo, (LPCTSTR)l_pObj->m_sName, l_pObj->m_uiRefCount);
		l_sInfo += l_sMsg;
	}
	l_sMsg.Format(_T("Number of living ref count objects=%d\n"), m_LivingObjects.GetCount());
	l_sInfo = l_sMsg + l_sInfo;
#endif

	return l_sInfo;
  //## end ICORefCounting::GetLivingObjectInfo%1174997739.body
}

//## Get and Set Operations for Class Attributes (implementation)

void ICORefCounting::SetsName (CString value)
{
  //## begin ICORefCounting::SetsName%4565CAE100CA.set preserve=no
  m_sName = value;
  //## end ICORefCounting::SetsName%4565CAE100CA.set
}

// Additional Declarations
  //## begin ICORefCounting%3B8D53C70238.declarations preserve=yes
  //## end ICORefCounting%3B8D53C70238.declarations

//## begin module%3B8D539F0154.epilog preserve=yes
//## end module%3B8D539F0154.epilog
