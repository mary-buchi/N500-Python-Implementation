//## begin module%3EDC5B3C01E0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01E0.cm

//## begin module%3EDC5B3C01E0.cp preserve=no
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
//## end module%3EDC5B3C01E0.cp

//## Module: EBSYintf%3EDC5B3C01E0; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C01E0.additionalIncludes preserve=no
//## end module%3EDC5B3C01E0.additionalIncludes

//## begin module%3EDC5B3C01E0.includes preserve=yes
//## end module%3EDC5B3C01E0.includes

// EBSYcomd
#include "EBSYcomd.h"
// EBCOsync
#include "EBCOsync.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYintf
#include "EBSYintf.h"
// EBSYidnt
#include "EBSYidnt.h"


//## begin module%3EDC5B3C01E0.declarations preserve=no
//## end module%3EDC5B3C01E0.declarations

//## begin module%3EDC5B3C01E0.additionalDeclarations preserve=yes
#define DUMMYARRAY_RETURN {  \
    CCOSyncObjectArray* l_pSyncObjArray = new CCOSyncObjectArray();    \
    l_pSyncObjArray->SignalCompletion();                     \
    return l_pSyncObjArray;                                  \
}

#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();    \
    l_pSyncObj->SignalCompletion();                     \
    return l_pSyncObj;                                  \
}

//## end module%3EDC5B3C01E0.additionalDeclarations


// Class CSYSystemInterface 



CSYSystemInterface::CSYSystemInterface (UINT p_uiID)
  //## begin CSYSystemInterface::CSYSystemInterface%1038899309.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CSYSystemInterface::CSYSystemInterface%1038899309.hasinit
  //## begin CSYSystemInterface::CSYSystemInterface%1038899309.initialization preserve=yes
  ,IPISystemInterface(SY_ID)
  //## end CSYSystemInterface::CSYSystemInterface%1038899309.initialization
{
  //## begin CSYSystemInterface::CSYSystemInterface%1038899309.body preserve=yes
  //## end CSYSystemInterface::CSYSystemInterface%1038899309.body
}


CSYSystemInterface::~CSYSystemInterface()
{
  //## begin CSYSystemInterface::~CSYSystemInterface%.body preserve=yes
  //## end CSYSystemInterface::~CSYSystemInterface%.body
}



//## Other Operations (implementation)
void CSYSystemInterface::InitInstance ()
{
  //## begin CSYSystemInterface::InitInstance%1039429760.body preserve=yes
    m_pImplementation = new CSYSystemImplementation(this);
    IPISystemInterface::InitInstance();
  //## end CSYSystemInterface::InitInstance%1039429760.body
}

void CSYSystemInterface::ExitInstance ()
{
  //## begin CSYSystemInterface::ExitInstance%1056628599.body preserve=yes
	IPISystemInterface::ExitInstance();
  //## end CSYSystemInterface::ExitInstance%1056628599.body
}

UINT CSYSystemInterface::GetuiID ()
{
  //## begin CSYSystemInterface::GetuiID%1038899352.body preserve=yes
  return m_uiID;
  //## end CSYSystemInterface::GetuiID%1038899352.body
}

CCOSyncObject* CSYSystemInterface::RegisterClient (const CString& p_sClient)
{
  //## begin CSYSystemInterface::RegisterClient%1096656406.body preserve=yes
    return Execute(new CSYCommandRegisterClient(m_pImplementation, p_sClient));
  //## end CSYSystemInterface::RegisterClient%1096656406.body
}

CCOSyncObject* CSYSystemInterface::StartDevice ()
{
  //## begin CSYSystemInterface::StartDevice%1055330886.body preserve=yes
    return Execute(new CSYCommandStartDevice(m_pImplementation));
  //## end CSYSystemInterface::StartDevice%1055330886.body
}

CCOSyncObject* CSYSystemInterface::ResetDevice ()
{
  //## begin CSYSystemInterface::ResetDevice%1055330887.body preserve=yes
    return Execute(new CSYCommandResetDevice(m_pImplementation), eCOQueueHigh);
  //## end CSYSystemInterface::ResetDevice%1055330887.body
}

EPIDeviceState CSYSystemInterface::GetDeviceState ()
{
  //## begin CSYSystemInterface::GetDeviceState%1055330888.body preserve=yes
    return dynamic_cast<CSYSystemImplementation*>(m_pImplementation)->GetDeviceState();
  //## end CSYSystemInterface::GetDeviceState%1055330888.body
}

CCOSyncObjectCString* CSYSystemInterface::GetVersion ()
{
  //## begin CSYSystemInterface::GetVersion%1096656414.body preserve=yes
    CCOSyncObjectCString* pSyncObj = dynamic_cast<CCOSyncObjectCString*>
        (Execute(new CSYCommandGetVersion(m_pImplementation)));
    ASSERT(pSyncObj != NULL);

    return pSyncObj;
  //## end CSYSystemInterface::GetVersion%1096656414.body
}

CPISyncObjListSWCompVersion* CSYSystemInterface::ReadSoftwareVersions ()
{
  //## begin CSYSystemInterface::ReadSoftwareVersions%1055402516.body preserve=yes

    CPISyncObjListSWCompVersion* pSyncObj = dynamic_cast<CPISyncObjListSWCompVersion*>
        (Execute(new CSYCommandReadSoftwareVersions(m_pImplementation)));
    ASSERT(pSyncObj != NULL);

    return pSyncObj;

  //## end CSYSystemInterface::ReadSoftwareVersions%1055402516.body
}

CCOSyncObject* CSYSystemInterface::DownloadSoftwareComponents (CPIPersistentSoftwareComponentList* p_pComponentList)
{
  //## begin CSYSystemInterface::DownloadSoftwareComponents%1055330891.body preserve=yes
    return(Execute(new CSYCommandDownloadSoftwareComponents(m_pImplementation, p_pComponentList)));
  //## end CSYSystemInterface::DownloadSoftwareComponents%1055330891.body
}

CCOSyncObject* CSYSystemInterface::DownloadSoftwareComponent (CPIPersistentSoftwareComponent* p_pComponent)
{
  //## begin CSYSystemInterface::DownloadSoftwareComponent%1199783745.body preserve=yes
    return(Execute(new CSYCommandDownloadSoftwareComponent(m_pImplementation, p_pComponent)));
  //## end CSYSystemInterface::DownloadSoftwareComponent%1199783745.body
}

CCOSyncObject* CSYSystemInterface::SetInterfaceConfig (CPIInterfaceConfig* p_pInterfaceConfig)
{
  //## begin CSYSystemInterface::SetInterfaceConfig%1055429122.body preserve=yes
    return(Execute(new CSYCommandSetInterfaceConfig(m_pImplementation, p_pInterfaceConfig)));
  //## end CSYSystemInterface::SetInterfaceConfig%1055429122.body
}

CCOSyncObject* CSYSystemInterface::SetStandbyTimeout (const UINT p_uiTimeout)
{
  //## begin CSYSystemInterface::SetStandbyTimeout%1056695976.body preserve=yes
    return(Execute(new CSYCommandSetStandbyTimeout(m_pImplementation, p_uiTimeout)));
  //## end CSYSystemInterface::SetStandbyTimeout%1056695976.body
}

CCOSyncObject* CSYSystemInterface::SetComponentState (const CString& p_sComponentId, const bool p_bActive)
{
  //## begin CSYSystemInterface::SetComponentState%1061301416.body preserve=yes
    // execute command
    return(Execute(new CSYCommandSetComponentState(m_pImplementation, p_sComponentId, p_bActive)));
  //## end CSYSystemInterface::SetComponentState%1061301416.body
}

CPISyncObjectStringArray* CSYSystemInterface::GetObjectList ()
{
  //## begin CSYSystemInterface::GetObjectList%1063715457.body preserve=yes

    CPISyncObjectStringArray* pSyncObj = dynamic_cast<CPISyncObjectStringArray*>
        (Execute(new CSYCommandGetObjectList(m_pImplementation), eCOQueueAboveNormal));
    ASSERT(pSyncObj != NULL);

    return pSyncObj;

  //## end CSYSystemInterface::GetObjectList%1063715457.body
}

CCOSyncObject* CSYSystemInterface::SetSystemTime (const SYSTEMTIME& p_SystemTime)
{
  //## begin CSYSystemInterface::SetSystemTime%1064429417.body preserve=yes
	return Execute(new CSYCommandSetSystemTime(m_pImplementation, p_SystemTime));
  //## end CSYSystemInterface::SetSystemTime%1064429417.body
}

CCOSyncObjectCString* CSYSystemInterface::GetOsVersion ()
{
  //## begin CSYSystemInterface::GetOsVersion%1108540786.body preserve=yes
    CCOSyncObjectCString* pSyncObj = dynamic_cast<CCOSyncObjectCString*>
        (Execute(new CSYCommandGetOsVersion(m_pImplementation)));
    ASSERT(pSyncObj != NULL);

    return pSyncObj;
  //## end CSYSystemInterface::GetOsVersion%1108540786.body
}

CCOSyncObjectCString* CSYSystemInterface::GetFpgaVersion ()
{
  //## begin CSYSystemInterface::GetFpgaVersion%1108540787.body preserve=yes
    CCOSyncObjectCString* pSyncObj = dynamic_cast<CCOSyncObjectCString*>
        (Execute(new CSYCommandGetFpgaVersion(m_pImplementation)));
    ASSERT(pSyncObj != NULL);

    return pSyncObj;
  //## end CSYSystemInterface::GetFpgaVersion%1108540787.body
}

CCOSyncObject* CSYSystemInterface::StartDownload ()
{
  //## begin CSYSystemInterface::StartDownload%1199783746.body preserve=yes
    return(Execute(new CSYCommandStartDownload(m_pImplementation)));
  //## end CSYSystemInterface::StartDownload%1199783746.body
}

CCOSyncObject* CSYSystemInterface::EndDownload ()
{
  //## begin CSYSystemInterface::EndDownload%1199783747.body preserve=yes
    return(Execute(new CSYCommandEndDownload(m_pImplementation)));
  //## end CSYSystemInterface::EndDownload%1199783747.body
}

// Additional Declarations
  //## begin CSYSystemInterface%3EDC5B9C0076.declarations preserve=yes
  //## end CSYSystemInterface%3EDC5B9C0076.declarations

//## begin module%3EDC5B3C01E0.epilog preserve=yes
//## end module%3EDC5B3C01E0.epilog
