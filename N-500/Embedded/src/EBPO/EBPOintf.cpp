//## begin module%3DE5EB0C0208.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB0C0208.cm

//## begin module%3DE5EB0C0208.cp preserve=no
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
//## end module%3DE5EB0C0208.cp

//## Module: EBPOintf%3DE5EB0C0208; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EB0C0208.additionalIncludes preserve=no
//## end module%3DE5EB0C0208.additionalIncludes

//## begin module%3DE5EB0C0208.includes preserve=yes
//## end module%3DE5EB0C0208.includes

// windef
#include "windef.h"
// EBPItype
#include "EBPItype.h"
// EBPOcomd
#include "EBPOcomd.h"
// EBPOimpl
#include "EBPOimpl.h"
// EBPOintf
#include "EBPOintf.h"
// EBPOidnt
#include "EBPOidnt.h"


//## begin module%3DE5EB0C0208.declarations preserve=no
//## end module%3DE5EB0C0208.declarations

//## begin module%3DE5EB0C0208.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}
#define DUMMY_LISTIDENT_RETURN {  \
    CPISyncObjListIdent* l_pSyncObjListIdent = new CPISyncObjListIdent(0);    \
    l_pSyncObjListIdent->SignalCompletion();                     \
    return l_pSyncObjListIdent;                                  \
}
#define DUMMY_LISTPARA_RETURN {  \
    CPISyncObjListPersistentItems* l_pSyncObjListPara = new CPISyncObjListPersistentItems(0);    \
    l_pSyncObjListPara->SignalCompletion();                     \
    return l_pSyncObjListPara;                                  \
}
#define DUMMY_LISTSWVERSION_RETURN {  \
    CPISyncObjListSWCompVersion* l_pSyncObjListSWV = new CPISyncObjListSWCompVersion(0);    \
    l_pSyncObjListSWV->SignalCompletion();                     \
    return l_pSyncObjListSWV;                                  \
}
//## end module%3DE5EB0C0208.additionalDeclarations


// Class CPOPersistentObjInterface 


CPOPersistentObjInterface::CPOPersistentObjInterface (UINT p_uiID)
  //## begin CPOPersistentObjInterface::CPOPersistentObjInterface%1038493581.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CPOPersistentObjInterface::CPOPersistentObjInterface%1038493581.hasinit
  //## begin CPOPersistentObjInterface::CPOPersistentObjInterface%1038493581.initialization preserve=yes
  , IPIPersistentObjInterface(PO_ID)
  //## end CPOPersistentObjInterface::CPOPersistentObjInterface%1038493581.initialization
{
  //## begin CPOPersistentObjInterface::CPOPersistentObjInterface%1038493581.body preserve=yes
  //## end CPOPersistentObjInterface::CPOPersistentObjInterface%1038493581.body
}


CPOPersistentObjInterface::~CPOPersistentObjInterface()
{
  //## begin CPOPersistentObjInterface::~CPOPersistentObjInterface%.body preserve=yes
  //## end CPOPersistentObjInterface::~CPOPersistentObjInterface%.body
}



//## Other Operations (implementation)
UINT CPOPersistentObjInterface::GetuiID ()
{
  //## begin CPOPersistentObjInterface::GetuiID%1038493582.body preserve=yes
  return m_uiID;
  //## end CPOPersistentObjInterface::GetuiID%1038493582.body
}

void CPOPersistentObjInterface::InitInstance ()
{
  //## begin CPOPersistentObjInterface::InitInstance%1038493591.body preserve=yes
  m_pImplementation = new CPOPersistentObjImplementation(this);

  IPIPersistentObjInterface::InitInstance();
  //## end CPOPersistentObjInterface::InitInstance%1038493591.body
}

CPISyncObjListPersistentItems* CPOPersistentObjInterface::ReadParameters ()
{
  //## begin CPOPersistentObjInterface::ReadParameters%1066717298.body preserve=yes
	CCOSyncObject *l_pSyncObj = Execute(new CPOCommandReadParameters(m_pImplementation));
    CPISyncObjListPersistentItems* l_pSyncObj1 = dynamic_cast<CPISyncObjListPersistentItems*>(l_pSyncObj);
    ASSERT(l_pSyncObj != NULL);

    return l_pSyncObj1;
  //## end CPOPersistentObjInterface::ReadParameters%1066717298.body
}

CCOSyncObject* CPOPersistentObjInterface::WriteParameter (CPIPersistentPara* p_pParameter)
{
  //## begin CPOPersistentObjInterface::WriteParameter%1035528318.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandWriteParameter(m_pImplementation, p_pParameter));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::WriteParameter%1035528318.body
}

CCOSyncObject * CPOPersistentObjInterface::StartMonitoring (EPILifeTimeCounter p_eDevice)
{
  //## begin CPOPersistentObjInterface::StartMonitoring%1066717300.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandStartMonitoring(m_pImplementation, p_eDevice));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::StartMonitoring%1066717300.body
}

CCOSyncObject * CPOPersistentObjInterface::StopMonitoring (EPILifeTimeCounter p_eDevice)
{
  //## begin CPOPersistentObjInterface::StopMonitoring%1066717301.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandStopMonitoring(m_pImplementation, p_eDevice));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::StopMonitoring%1066717301.body
}

CCOSyncObject* CPOPersistentObjInterface::Save ()
{
  //## begin CPOPersistentObjInterface::Save%1066717302.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandSave(m_pImplementation));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::Save%1066717302.body
}

CCOSyncObjectInt* CPOPersistentObjInterface::ReadLifeTimeCounter (EPILifeTimeCounter p_eCounter)
{
  //## begin CPOPersistentObjInterface::ReadLifeTimeCounter%1066808240.body preserve=yes
	CCOSyncObjectInt* l_pSyncObj = dynamic_cast<CCOSyncObjectInt*>( Execute( new CPOCommandReadLifeTimeCounter( m_pImplementation, p_eCounter ) ) );
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::ReadLifeTimeCounter%1066808240.body
}

CCOSyncObject* CPOPersistentObjInterface::WriteLifeTimeCounter (EPILifeTimeCounter p_eCounter, UINT p_uiValue)
{
  //## begin CPOPersistentObjInterface::WriteLifeTimeCounter%1066717304.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandWriteLifeTimeCounter(m_pImplementation, p_eCounter, p_uiValue));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::WriteLifeTimeCounter%1066717304.body
}

CPISyncObjListPersistentItems* CPOPersistentObjInterface::ReadIdentifications ()
{
  //## begin CPOPersistentObjInterface::ReadIdentifications%1066717305.body preserve=yes
	CPISyncObjListPersistentItems* l_pSyncObj = dynamic_cast<CPISyncObjListPersistentItems*>(Execute(new CPOCommandReadIdentifications(m_pImplementation)));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::ReadIdentifications%1066717305.body
}

CCOSyncObject* CPOPersistentObjInterface::WriteIdentification (CPIPersistentIdent* p_oIdentification)
{
  //## begin CPOPersistentObjInterface::WriteIdentification%1066808241.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandWriteIdentification(m_pImplementation, p_oIdentification));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::WriteIdentification%1066808241.body
}

CCOSyncObject* CPOPersistentObjInterface::SetConfig (CPIPersistentConfig* p_pConfig)
{
  //## begin CPOPersistentObjInterface::SetConfig%1066813275.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandSetConfig(m_pImplementation, p_pConfig));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::SetConfig%1066813275.body
}

CCOSyncObject* CPOPersistentObjInterface::Reset (EPIEpromSection p_eSection)
{
  //## begin CPOPersistentObjInterface::Reset%1072788293.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandReset(m_pImplementation, p_eSection));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::Reset%1072788293.body
}

CCOSyncObject* CPOPersistentObjInterface::MeasurementCellUndocked ()
{
  //## begin CPOPersistentObjInterface::MeasurementCellUndocked%1080142971.body preserve=yes
	CCOSyncObject* l_pSyncObj = Execute(new CPOCommandMeasurementCellUndocked(m_pImplementation));
	ASSERT(l_pSyncObj != NULL);

	return l_pSyncObj;
  //## end CPOPersistentObjInterface::MeasurementCellUndocked%1080142971.body
}

// Additional Declarations
  //## begin CPOPersistentObjInterface%3DE62969019B.declarations preserve=yes
  //## end CPOPersistentObjInterface%3DE62969019B.declarations

//## begin module%3DE5EB0C0208.epilog preserve=yes
//## end module%3DE5EB0C0208.epilog
