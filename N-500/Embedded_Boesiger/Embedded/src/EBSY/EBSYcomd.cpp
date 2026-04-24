//## begin module%3EDC5B3C01F9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01F9.cm

//## begin module%3EDC5B3C01F9.cp preserve=no
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
//## end module%3EDC5B3C01F9.cp

//## Module: EBSYcomd%3EDC5B3C01F9; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C01F9.additionalIncludes preserve=no
//## end module%3EDC5B3C01F9.additionalIncludes

//## begin module%3EDC5B3C01F9.includes preserve=yes
//## end module%3EDC5B3C01F9.includes

// EBSYcomd
#include "EBSYcomd.h"
// EBPItype
#include "EBPItype.h"
// EBSYstat
#include "EBSYstat.h"


//## begin module%3EDC5B3C01F9.declarations preserve=no
//## end module%3EDC5B3C01F9.declarations

//## begin module%3EDC5B3C01F9.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01F9.additionalDeclarations


// Class CSYCommand 

CSYCommand::CSYCommand (ICOStateMachineContext* p_pContext)
  //## begin CSYCommand::CSYCommand%1038899362.hasinit preserve=no
  //## end CSYCommand::CSYCommand%1038899362.hasinit
  //## begin CSYCommand::CSYCommand%1038899362.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CSYCommand::CSYCommand%1038899362.initialization
{
  //## begin CSYCommand::CSYCommand%1038899362.body preserve=yes
  //## end CSYCommand::CSYCommand%1038899362.body
}


CSYCommand::~CSYCommand()
{
  //## begin CSYCommand::~CSYCommand%.body preserve=yes
  //## end CSYCommand::~CSYCommand%.body
}



//## Other Operations (implementation)
bool CSYCommand::Execute (CCOState* p_pCurrentState)
{
  //## begin CSYCommand::Execute%1038899363.body preserve=yes
    CSYState* l_pState = dynamic_cast<CSYState*>(p_pCurrentState);
    return Execute(l_pState);
  //## end CSYCommand::Execute%1038899363.body
}

// Additional Declarations
  //## begin CSYCommand%3EDC5B9C0240.declarations preserve=yes
  //## end CSYCommand%3EDC5B9C0240.declarations

// Class CSYCommandSetInterfaceConfig 


CSYCommandSetInterfaceConfig::CSYCommandSetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig)
  //## begin CSYCommandSetInterfaceConfig::CSYCommandSetInterfaceConfig%1039429751.hasinit preserve=no
      : m_pInterfaceConfig(p_pInterfaceConfig)
  //## end CSYCommandSetInterfaceConfig::CSYCommandSetInterfaceConfig%1039429751.hasinit
  //## begin CSYCommandSetInterfaceConfig::CSYCommandSetInterfaceConfig%1039429751.initialization preserve=yes
  , CSYCommand(p_pContext)
  //## end CSYCommandSetInterfaceConfig::CSYCommandSetInterfaceConfig%1039429751.initialization
{
  //## begin CSYCommandSetInterfaceConfig::CSYCommandSetInterfaceConfig%1039429751.body preserve=yes
  //## end CSYCommandSetInterfaceConfig::CSYCommandSetInterfaceConfig%1039429751.body
}


CSYCommandSetInterfaceConfig::~CSYCommandSetInterfaceConfig()
{
  //## begin CSYCommandSetInterfaceConfig::~CSYCommandSetInterfaceConfig%.body preserve=yes
  //## end CSYCommandSetInterfaceConfig::~CSYCommandSetInterfaceConfig%.body
}



//## Other Operations (implementation)
bool CSYCommandSetInterfaceConfig::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandSetInterfaceConfig::Execute%1039429753.body preserve=yes

    // execute command
    p_pCurrentState->SetInterfaceConfig(m_pContext, m_pInterfaceConfig, m_pSyncArray->GetAt(0));

    return true;

  //## end CSYCommandSetInterfaceConfig::Execute%1039429753.body
}

// Additional Declarations
  //## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.declarations preserve=yes
  //## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.declarations

// Class CSYCommandDownloadSoftwareComponents 


CSYCommandDownloadSoftwareComponents::CSYCommandDownloadSoftwareComponents (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponentList* p_pComponentList)
  //## begin CSYCommandDownloadSoftwareComponents::CSYCommandDownloadSoftwareComponents%1039429736.hasinit preserve=no
      : m_pPersistentSoftwareComponentList(p_pComponentList)
  //## end CSYCommandDownloadSoftwareComponents::CSYCommandDownloadSoftwareComponents%1039429736.hasinit
  //## begin CSYCommandDownloadSoftwareComponents::CSYCommandDownloadSoftwareComponents%1039429736.initialization preserve=yes
  , CSYCommand(p_pContext)
  //## end CSYCommandDownloadSoftwareComponents::CSYCommandDownloadSoftwareComponents%1039429736.initialization
{
  //## begin CSYCommandDownloadSoftwareComponents::CSYCommandDownloadSoftwareComponents%1039429736.body preserve=yes
    m_pPersistentSoftwareComponentList->AddRef();
  //## end CSYCommandDownloadSoftwareComponents::CSYCommandDownloadSoftwareComponents%1039429736.body
}


CSYCommandDownloadSoftwareComponents::~CSYCommandDownloadSoftwareComponents()
{
  //## begin CSYCommandDownloadSoftwareComponents::~CSYCommandDownloadSoftwareComponents%.body preserve=yes
    m_pPersistentSoftwareComponentList->ReleaseRef();
  //## end CSYCommandDownloadSoftwareComponents::~CSYCommandDownloadSoftwareComponents%.body
}



//## Other Operations (implementation)
bool CSYCommandDownloadSoftwareComponents::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandDownloadSoftwareComponents::Execute%1039429737.body preserve=yes

    // execute command
    p_pCurrentState->DownloadSoftwareComponents(m_pContext, m_pPersistentSoftwareComponentList, m_pSyncArray->GetAt(0));

    return true;

  //## end CSYCommandDownloadSoftwareComponents::Execute%1039429737.body
}

// Additional Declarations
  //## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.declarations preserve=yes
  //## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.declarations

// Class CSYCommandReadSoftwareVersions 

CSYCommandReadSoftwareVersions::CSYCommandReadSoftwareVersions (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandReadSoftwareVersions::CSYCommandReadSoftwareVersions%1039418961.hasinit preserve=no
  //## end CSYCommandReadSoftwareVersions::CSYCommandReadSoftwareVersions%1039418961.hasinit
  //## begin CSYCommandReadSoftwareVersions::CSYCommandReadSoftwareVersions%1039418961.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandReadSoftwareVersions::CSYCommandReadSoftwareVersions%1039418961.initialization
{
  //## begin CSYCommandReadSoftwareVersions::CSYCommandReadSoftwareVersions%1039418961.body preserve=yes
  //## end CSYCommandReadSoftwareVersions::CSYCommandReadSoftwareVersions%1039418961.body
}


CSYCommandReadSoftwareVersions::~CSYCommandReadSoftwareVersions()
{
  //## begin CSYCommandReadSoftwareVersions::~CSYCommandReadSoftwareVersions%.body preserve=yes
  //## end CSYCommandReadSoftwareVersions::~CSYCommandReadSoftwareVersions%.body
}



//## Other Operations (implementation)
void CSYCommandReadSoftwareVersions::CreateSyncObjects ()
{
  //## begin CSYCommandReadSoftwareVersions::CreateSyncObjects%1039418962.body preserve=yes
    m_pSyncArray->Add(new CPISyncObjListSWCompVersion(NULL), false);
  //## end CSYCommandReadSoftwareVersions::CreateSyncObjects%1039418962.body
}

bool CSYCommandReadSoftwareVersions::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandReadSoftwareVersions::Execute%1039418963.body preserve=yes

    // keep sync object
    CPISyncObjListSWCompVersion* pClientSyncObj = dynamic_cast<CPISyncObjListSWCompVersion*>(m_pSyncArray->GetAt(0));
    ASSERT(pClientSyncObj != NULL);

    // execute command
    p_pCurrentState->ReadSoftwareVersions(m_pContext, pClientSyncObj);

    return false;

  //## end CSYCommandReadSoftwareVersions::Execute%1039418963.body
}

// Additional Declarations
  //## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.declarations preserve=yes
  //## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.declarations

// Class CSYCommandStartDevice 

CSYCommandStartDevice::CSYCommandStartDevice (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandStartDevice::CSYCommandStartDevice%1055402512.hasinit preserve=no
  //## end CSYCommandStartDevice::CSYCommandStartDevice%1055402512.hasinit
  //## begin CSYCommandStartDevice::CSYCommandStartDevice%1055402512.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandStartDevice::CSYCommandStartDevice%1055402512.initialization
{
  //## begin CSYCommandStartDevice::CSYCommandStartDevice%1055402512.body preserve=yes
  //## end CSYCommandStartDevice::CSYCommandStartDevice%1055402512.body
}


CSYCommandStartDevice::~CSYCommandStartDevice()
{
  //## begin CSYCommandStartDevice::~CSYCommandStartDevice%.body preserve=yes
  //## end CSYCommandStartDevice::~CSYCommandStartDevice%.body
}



//## Other Operations (implementation)
bool CSYCommandStartDevice::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandStartDevice::Execute%1055402513.body preserve=yes
    p_pCurrentState->StartDevice(m_pContext);
    return true;
  //## end CSYCommandStartDevice::Execute%1055402513.body
}

// Additional Declarations
  //## begin CSYCommandStartDevice%3EE84D2C0317.declarations preserve=yes
  //## end CSYCommandStartDevice%3EE84D2C0317.declarations

// Class CSYCommandResetDevice 

CSYCommandResetDevice::CSYCommandResetDevice (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandResetDevice::CSYCommandResetDevice%1055402514.hasinit preserve=no
  //## end CSYCommandResetDevice::CSYCommandResetDevice%1055402514.hasinit
  //## begin CSYCommandResetDevice::CSYCommandResetDevice%1055402514.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandResetDevice::CSYCommandResetDevice%1055402514.initialization
{
  //## begin CSYCommandResetDevice::CSYCommandResetDevice%1055402514.body preserve=yes
  //## end CSYCommandResetDevice::CSYCommandResetDevice%1055402514.body
}


CSYCommandResetDevice::~CSYCommandResetDevice()
{
  //## begin CSYCommandResetDevice::~CSYCommandResetDevice%.body preserve=yes
  //## end CSYCommandResetDevice::~CSYCommandResetDevice%.body
}



//## Other Operations (implementation)
bool CSYCommandResetDevice::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandResetDevice::Execute%1055402515.body preserve=yes

    p_pCurrentState->ResetDevice(m_pContext);
    return false;

  //## end CSYCommandResetDevice::Execute%1055402515.body
}

void CSYCommandResetDevice::SignalExecution ()
{
  //## begin CSYCommandResetDevice::SignalExecution%1064337358.body preserve=yes
	m_pSyncArray->GetAt(0)->SignalCompletion();
  //## end CSYCommandResetDevice::SignalExecution%1064337358.body
}

// Additional Declarations
  //## begin CSYCommandResetDevice%3EE84D5B0327.declarations preserve=yes
  //## end CSYCommandResetDevice%3EE84D5B0327.declarations

// Class CSYCommandSetStandbyTimeout 


CSYCommandSetStandbyTimeout::CSYCommandSetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeOut)
  //## begin CSYCommandSetStandbyTimeout::CSYCommandSetStandbyTimeout%1056695974.hasinit preserve=no
  //## end CSYCommandSetStandbyTimeout::CSYCommandSetStandbyTimeout%1056695974.hasinit
  //## begin CSYCommandSetStandbyTimeout::CSYCommandSetStandbyTimeout%1056695974.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandSetStandbyTimeout::CSYCommandSetStandbyTimeout%1056695974.initialization
{
  //## begin CSYCommandSetStandbyTimeout::CSYCommandSetStandbyTimeout%1056695974.body preserve=yes
    m_uiTimeout = p_uiTimeOut;
  //## end CSYCommandSetStandbyTimeout::CSYCommandSetStandbyTimeout%1056695974.body
}


CSYCommandSetStandbyTimeout::~CSYCommandSetStandbyTimeout()
{
  //## begin CSYCommandSetStandbyTimeout::~CSYCommandSetStandbyTimeout%.body preserve=yes
  //## end CSYCommandSetStandbyTimeout::~CSYCommandSetStandbyTimeout%.body
}



//## Other Operations (implementation)
bool CSYCommandSetStandbyTimeout::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandSetStandbyTimeout::Execute%1056695975.body preserve=yes
    p_pCurrentState->SetStandbyTimeout(m_pContext, m_uiTimeout);
    return true;
  //## end CSYCommandSetStandbyTimeout::Execute%1056695975.body
}

// Additional Declarations
  //## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.declarations preserve=yes
  //## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.declarations

// Class CSYCommandSetComponentState 



CSYCommandSetComponentState::CSYCommandSetComponentState (ICOStateMachineContext* p_pContext, const CString& p_sComponentId, const bool p_bActive)
  //## begin CSYCommandSetComponentState::CSYCommandSetComponentState%1061301414.hasinit preserve=no
  //## end CSYCommandSetComponentState::CSYCommandSetComponentState%1061301414.hasinit
  //## begin CSYCommandSetComponentState::CSYCommandSetComponentState%1061301414.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandSetComponentState::CSYCommandSetComponentState%1061301414.initialization
{
  //## begin CSYCommandSetComponentState::CSYCommandSetComponentState%1061301414.body preserve=yes
    m_sComponentId = p_sComponentId;
    m_bActive      = p_bActive;
  //## end CSYCommandSetComponentState::CSYCommandSetComponentState%1061301414.body
}


CSYCommandSetComponentState::~CSYCommandSetComponentState()
{
  //## begin CSYCommandSetComponentState::~CSYCommandSetComponentState%.body preserve=yes
  //## end CSYCommandSetComponentState::~CSYCommandSetComponentState%.body
}



//## Other Operations (implementation)
bool CSYCommandSetComponentState::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandSetComponentState::Execute%1061301415.body preserve=yes

    // execute command
    p_pCurrentState->SetComponentState(m_pContext, m_sComponentId, m_bActive);
    return true;

  //## end CSYCommandSetComponentState::Execute%1061301415.body
}

// Additional Declarations
  //## begin CSYCommandSetComponentState%3F42377E0312.declarations preserve=yes
  //## end CSYCommandSetComponentState%3F42377E0312.declarations

// Class CSYCommandGetObjectList 

CSYCommandGetObjectList::CSYCommandGetObjectList (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandGetObjectList::CSYCommandGetObjectList%1063715458.hasinit preserve=no
  //## end CSYCommandGetObjectList::CSYCommandGetObjectList%1063715458.hasinit
  //## begin CSYCommandGetObjectList::CSYCommandGetObjectList%1063715458.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandGetObjectList::CSYCommandGetObjectList%1063715458.initialization
{
  //## begin CSYCommandGetObjectList::CSYCommandGetObjectList%1063715458.body preserve=yes
  //## end CSYCommandGetObjectList::CSYCommandGetObjectList%1063715458.body
}


CSYCommandGetObjectList::~CSYCommandGetObjectList()
{
  //## begin CSYCommandGetObjectList::~CSYCommandGetObjectList%.body preserve=yes
  //## end CSYCommandGetObjectList::~CSYCommandGetObjectList%.body
}



//## Other Operations (implementation)
void CSYCommandGetObjectList::CreateSyncObjects ()
{
  //## begin CSYCommandGetObjectList::CreateSyncObjects%1063715459.body preserve=yes
    m_pSyncArray->Add(new CPISyncObjectStringArray(NULL), false);
  //## end CSYCommandGetObjectList::CreateSyncObjects%1063715459.body
}

bool CSYCommandGetObjectList::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandGetObjectList::Execute%1063715460.body preserve=yes
    CPISyncObjectStringArray* l_pSyncObj = dynamic_cast<CPISyncObjectStringArray*>(m_pSyncArray->GetAt(0));
    ASSERT(l_pSyncObj != NULL);

    p_pCurrentState->GetObjectList(m_pContext, l_pSyncObj);
    return true;
  //## end CSYCommandGetObjectList::Execute%1063715460.body
}

// Additional Declarations
  //## begin CSYCommandGetObjectList%3F6708D90200.declarations preserve=yes
  //## end CSYCommandGetObjectList%3F6708D90200.declarations

// Class CSYCommandSetSystemTime 


CSYCommandSetSystemTime::CSYCommandSetSystemTime (ICOStateMachineContext* p_pContext, const SYSTEMTIME& p_SystemTime)
  //## begin CSYCommandSetSystemTime::CSYCommandSetSystemTime%1064429415.hasinit preserve=no
      : m_SystemTime(p_SystemTime)
  //## end CSYCommandSetSystemTime::CSYCommandSetSystemTime%1064429415.hasinit
  //## begin CSYCommandSetSystemTime::CSYCommandSetSystemTime%1064429415.initialization preserve=yes
  , CSYCommand(p_pContext)
  //## end CSYCommandSetSystemTime::CSYCommandSetSystemTime%1064429415.initialization
{
  //## begin CSYCommandSetSystemTime::CSYCommandSetSystemTime%1064429415.body preserve=yes
  //## end CSYCommandSetSystemTime::CSYCommandSetSystemTime%1064429415.body
}


CSYCommandSetSystemTime::~CSYCommandSetSystemTime()
{
  //## begin CSYCommandSetSystemTime::~CSYCommandSetSystemTime%.body preserve=yes
  //## end CSYCommandSetSystemTime::~CSYCommandSetSystemTime%.body
}



//## Other Operations (implementation)
bool CSYCommandSetSystemTime::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandSetSystemTime::Execute%1064429416.body preserve=yes
	p_pCurrentState->SetSystemTime(m_pContext, m_SystemTime);
	return true;
  //## end CSYCommandSetSystemTime::Execute%1064429416.body
}

// Additional Declarations
  //## begin CSYCommandSetSystemTime%3F71EAAB03CD.declarations preserve=yes
  //## end CSYCommandSetSystemTime%3F71EAAB03CD.declarations

// Class CSYCommandRegisterClient 


CSYCommandRegisterClient::CSYCommandRegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient)
  //## begin CSYCommandRegisterClient::CSYCommandRegisterClient%1096656407.hasinit preserve=no
      : m_sClient(p_sClient)
  //## end CSYCommandRegisterClient::CSYCommandRegisterClient%1096656407.hasinit
  //## begin CSYCommandRegisterClient::CSYCommandRegisterClient%1096656407.initialization preserve=yes
  , CSYCommand(p_pContext)
  //## end CSYCommandRegisterClient::CSYCommandRegisterClient%1096656407.initialization
{
  //## begin CSYCommandRegisterClient::CSYCommandRegisterClient%1096656407.body preserve=yes
  //## end CSYCommandRegisterClient::CSYCommandRegisterClient%1096656407.body
}


CSYCommandRegisterClient::~CSYCommandRegisterClient()
{
  //## begin CSYCommandRegisterClient::~CSYCommandRegisterClient%.body preserve=yes
  //## end CSYCommandRegisterClient::~CSYCommandRegisterClient%.body
}



//## Other Operations (implementation)
bool CSYCommandRegisterClient::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandRegisterClient::Execute%1096656408.body preserve=yes
    p_pCurrentState->RegisterClient(m_pContext, m_sClient);
    return true;
  //## end CSYCommandRegisterClient::Execute%1096656408.body
}

// Additional Declarations
  //## begin CSYCommandRegisterClient%415DA6560176.declarations preserve=yes
  //## end CSYCommandRegisterClient%415DA6560176.declarations

// Class CSYCommandGetVersion 

CSYCommandGetVersion::CSYCommandGetVersion (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandGetVersion::CSYCommandGetVersion%1096656415.hasinit preserve=no
  //## end CSYCommandGetVersion::CSYCommandGetVersion%1096656415.hasinit
  //## begin CSYCommandGetVersion::CSYCommandGetVersion%1096656415.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandGetVersion::CSYCommandGetVersion%1096656415.initialization
{
  //## begin CSYCommandGetVersion::CSYCommandGetVersion%1096656415.body preserve=yes
  //## end CSYCommandGetVersion::CSYCommandGetVersion%1096656415.body
}


CSYCommandGetVersion::~CSYCommandGetVersion()
{
  //## begin CSYCommandGetVersion::~CSYCommandGetVersion%.body preserve=yes
  //## end CSYCommandGetVersion::~CSYCommandGetVersion%.body
}



//## Other Operations (implementation)
void CSYCommandGetVersion::CreateSyncObjects ()
{
  //## begin CSYCommandGetVersion::CreateSyncObjects%1096656422.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectCString(_T("")), false);
  //## end CSYCommandGetVersion::CreateSyncObjects%1096656422.body
}

bool CSYCommandGetVersion::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandGetVersion::Execute%1096656416.body preserve=yes
    p_pCurrentState->GetVersion(m_pContext, m_pSyncArray->GetAt(0));
    return true;
  //## end CSYCommandGetVersion::Execute%1096656416.body
}

// Additional Declarations
  //## begin CSYCommandGetVersion%415E51ED0059.declarations preserve=yes
  //## end CSYCommandGetVersion%415E51ED0059.declarations

// Class CSYCommandGetOsVersion 

CSYCommandGetOsVersion::CSYCommandGetOsVersion (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandGetOsVersion::CSYCommandGetOsVersion%1108540788.hasinit preserve=no
  //## end CSYCommandGetOsVersion::CSYCommandGetOsVersion%1108540788.hasinit
  //## begin CSYCommandGetOsVersion::CSYCommandGetOsVersion%1108540788.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandGetOsVersion::CSYCommandGetOsVersion%1108540788.initialization
{
  //## begin CSYCommandGetOsVersion::CSYCommandGetOsVersion%1108540788.body preserve=yes
  //## end CSYCommandGetOsVersion::CSYCommandGetOsVersion%1108540788.body
}


CSYCommandGetOsVersion::~CSYCommandGetOsVersion()
{
  //## begin CSYCommandGetOsVersion::~CSYCommandGetOsVersion%.body preserve=yes
  //## end CSYCommandGetOsVersion::~CSYCommandGetOsVersion%.body
}



//## Other Operations (implementation)
void CSYCommandGetOsVersion::CreateSyncObjects ()
{
  //## begin CSYCommandGetOsVersion::CreateSyncObjects%1108540789.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectCString(_T("")), false);
  //## end CSYCommandGetOsVersion::CreateSyncObjects%1108540789.body
}

bool CSYCommandGetOsVersion::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandGetOsVersion::Execute%1108540790.body preserve=yes
    p_pCurrentState->GetOsVersion(m_pContext, m_pSyncArray->GetAt(0));
    return true;
  //## end CSYCommandGetOsVersion::Execute%1108540790.body
}

// Additional Declarations
  //## begin CSYCommandGetOsVersion%421308920213.declarations preserve=yes
  //## end CSYCommandGetOsVersion%421308920213.declarations

// Class CSYCommandGetFpgaVersion 

CSYCommandGetFpgaVersion::CSYCommandGetFpgaVersion (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandGetFpgaVersion::CSYCommandGetFpgaVersion%1108540791.hasinit preserve=no
  //## end CSYCommandGetFpgaVersion::CSYCommandGetFpgaVersion%1108540791.hasinit
  //## begin CSYCommandGetFpgaVersion::CSYCommandGetFpgaVersion%1108540791.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandGetFpgaVersion::CSYCommandGetFpgaVersion%1108540791.initialization
{
  //## begin CSYCommandGetFpgaVersion::CSYCommandGetFpgaVersion%1108540791.body preserve=yes
  //## end CSYCommandGetFpgaVersion::CSYCommandGetFpgaVersion%1108540791.body
}


CSYCommandGetFpgaVersion::~CSYCommandGetFpgaVersion()
{
  //## begin CSYCommandGetFpgaVersion::~CSYCommandGetFpgaVersion%.body preserve=yes
  //## end CSYCommandGetFpgaVersion::~CSYCommandGetFpgaVersion%.body
}



//## Other Operations (implementation)
void CSYCommandGetFpgaVersion::CreateSyncObjects ()
{
  //## begin CSYCommandGetFpgaVersion::CreateSyncObjects%1108540792.body preserve=yes
    m_pSyncArray->Add(new CCOSyncObjectCString(_T("")), false);
  //## end CSYCommandGetFpgaVersion::CreateSyncObjects%1108540792.body
}

bool CSYCommandGetFpgaVersion::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandGetFpgaVersion::Execute%1108540793.body preserve=yes
    p_pCurrentState->GetFpgaVersion(m_pContext, m_pSyncArray->GetAt(0));
    return true;
  //## end CSYCommandGetFpgaVersion::Execute%1108540793.body
}

// Additional Declarations
  //## begin CSYCommandGetFpgaVersion%4213094B0128.declarations preserve=yes
  //## end CSYCommandGetFpgaVersion%4213094B0128.declarations

// Class CSYCommandDownloadSoftwareComponent 


CSYCommandDownloadSoftwareComponent::CSYCommandDownloadSoftwareComponent (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponent* p_pComponent)
  //## begin CSYCommandDownloadSoftwareComponent::CSYCommandDownloadSoftwareComponent%1199783734.hasinit preserve=no
      : m_pComponent(p_pComponent)
  //## end CSYCommandDownloadSoftwareComponent::CSYCommandDownloadSoftwareComponent%1199783734.hasinit
  //## begin CSYCommandDownloadSoftwareComponent::CSYCommandDownloadSoftwareComponent%1199783734.initialization preserve=yes
  , CSYCommand(p_pContext)
  //## end CSYCommandDownloadSoftwareComponent::CSYCommandDownloadSoftwareComponent%1199783734.initialization
{
  //## begin CSYCommandDownloadSoftwareComponent::CSYCommandDownloadSoftwareComponent%1199783734.body preserve=yes
    m_pComponent->AddRef();
  //## end CSYCommandDownloadSoftwareComponent::CSYCommandDownloadSoftwareComponent%1199783734.body
}


CSYCommandDownloadSoftwareComponent::~CSYCommandDownloadSoftwareComponent()
{
  //## begin CSYCommandDownloadSoftwareComponent::~CSYCommandDownloadSoftwareComponent%.body preserve=yes
    m_pComponent->ReleaseRef();
    m_pComponent = NULL;
  //## end CSYCommandDownloadSoftwareComponent::~CSYCommandDownloadSoftwareComponent%.body
}



//## Other Operations (implementation)
bool CSYCommandDownloadSoftwareComponent::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandDownloadSoftwareComponent::Execute%1199783735.body preserve=yes
    p_pCurrentState->DownloadSoftwareComponent(m_pContext, m_pComponent);
    return true;
  //## end CSYCommandDownloadSoftwareComponent::Execute%1199783735.body
}

// Additional Declarations
  //## begin CSYCommandDownloadSoftwareComponent%478340A2024F.declarations preserve=yes
  //## end CSYCommandDownloadSoftwareComponent%478340A2024F.declarations

// Class CSYCommandStartDownload 

CSYCommandStartDownload::CSYCommandStartDownload (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandStartDownload::CSYCommandStartDownload%1199783736.hasinit preserve=no
  //## end CSYCommandStartDownload::CSYCommandStartDownload%1199783736.hasinit
  //## begin CSYCommandStartDownload::CSYCommandStartDownload%1199783736.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandStartDownload::CSYCommandStartDownload%1199783736.initialization
{
  //## begin CSYCommandStartDownload::CSYCommandStartDownload%1199783736.body preserve=yes
  //## end CSYCommandStartDownload::CSYCommandStartDownload%1199783736.body
}


CSYCommandStartDownload::~CSYCommandStartDownload()
{
  //## begin CSYCommandStartDownload::~CSYCommandStartDownload%.body preserve=yes
  //## end CSYCommandStartDownload::~CSYCommandStartDownload%.body
}



//## Other Operations (implementation)
bool CSYCommandStartDownload::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandStartDownload::Execute%1199783737.body preserve=yes
    p_pCurrentState->StartDownload(m_pContext);
    return true;
  //## end CSYCommandStartDownload::Execute%1199783737.body
}

// Additional Declarations
  //## begin CSYCommandStartDownload%478344690137.declarations preserve=yes
  //## end CSYCommandStartDownload%478344690137.declarations

// Class CSYCommandEndDownload 

CSYCommandEndDownload::CSYCommandEndDownload (ICOStateMachineContext* p_pContext)
  //## begin CSYCommandEndDownload::CSYCommandEndDownload%1199783738.hasinit preserve=no
  //## end CSYCommandEndDownload::CSYCommandEndDownload%1199783738.hasinit
  //## begin CSYCommandEndDownload::CSYCommandEndDownload%1199783738.initialization preserve=yes
  : CSYCommand(p_pContext)
  //## end CSYCommandEndDownload::CSYCommandEndDownload%1199783738.initialization
{
  //## begin CSYCommandEndDownload::CSYCommandEndDownload%1199783738.body preserve=yes
  //## end CSYCommandEndDownload::CSYCommandEndDownload%1199783738.body
}


CSYCommandEndDownload::~CSYCommandEndDownload()
{
  //## begin CSYCommandEndDownload::~CSYCommandEndDownload%.body preserve=yes
  //## end CSYCommandEndDownload::~CSYCommandEndDownload%.body
}



//## Other Operations (implementation)
bool CSYCommandEndDownload::Execute (CSYState* p_pCurrentState)
{
  //## begin CSYCommandEndDownload::Execute%1199783739.body preserve=yes
    p_pCurrentState->EndDownload(m_pContext, m_pSyncArray->GetAt(0));
    return true;
  //## end CSYCommandEndDownload::Execute%1199783739.body
}

// Additional Declarations
  //## begin CSYCommandEndDownload%47834474002F.declarations preserve=yes
  //## end CSYCommandEndDownload%47834474002F.declarations

//## begin module%3EDC5B3C01F9.epilog preserve=yes
//## end module%3EDC5B3C01F9.epilog
