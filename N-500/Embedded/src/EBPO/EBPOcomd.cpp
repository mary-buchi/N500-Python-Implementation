//## begin module%3DE5EB5101BA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB5101BA.cm

//## begin module%3DE5EB5101BA.cp preserve=no
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
//## end module%3DE5EB5101BA.cp

//## Module: EBPOcomd%3DE5EB5101BA; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EB5101BA.additionalIncludes preserve=no
//## end module%3DE5EB5101BA.additionalIncludes

//## begin module%3DE5EB5101BA.includes preserve=yes
//## end module%3DE5EB5101BA.includes

// windef
#include "windef.h"
// EBPIenum
#include "EBPIenum.h"
// EBPOcomd
#include "EBPOcomd.h"
// EBPOstat
#include "EBPOstat.h"


//## begin module%3DE5EB5101BA.declarations preserve=no
//## end module%3DE5EB5101BA.declarations

//## begin module%3DE5EB5101BA.additionalDeclarations preserve=yes
//## end module%3DE5EB5101BA.additionalDeclarations


// Class CPOCommand 

CPOCommand::CPOCommand (ICOStateMachineContext* p_pContext)
  //## begin CPOCommand::CPOCommand%1038899353.hasinit preserve=no
  //## end CPOCommand::CPOCommand%1038899353.hasinit
  //## begin CPOCommand::CPOCommand%1038899353.initialization preserve=yes
  : CCOCommand(p_pContext)
  //## end CPOCommand::CPOCommand%1038899353.initialization
{
  //## begin CPOCommand::CPOCommand%1038899353.body preserve=yes
  //## end CPOCommand::CPOCommand%1038899353.body
}


CPOCommand::~CPOCommand()
{
  //## begin CPOCommand::~CPOCommand%.body preserve=yes
  //## end CPOCommand::~CPOCommand%.body
}



//## Other Operations (implementation)
bool CPOCommand::Execute (CCOState* p_pCurrentState)
{
  //## begin CPOCommand::Execute%1038899354.body preserve=yes
    CPOState* l_pState = dynamic_cast<CPOState*>(p_pCurrentState);
    ASSERT(l_pState != NULL);

    return Execute(l_pState);
  //## end CPOCommand::Execute%1038899354.body
}

// Additional Declarations
  //## begin CPOCommand%3DECB1FA035E.declarations preserve=yes
  //## end CPOCommand%3DECB1FA035E.declarations

// Class CPOCommandReadParameters 

CPOCommandReadParameters::CPOCommandReadParameters (ICOStateMachineContext* p_pContext)
  //## begin CPOCommandReadParameters::CPOCommandReadParameters%1039418956.hasinit preserve=no
  //## end CPOCommandReadParameters::CPOCommandReadParameters%1039418956.hasinit
  //## begin CPOCommandReadParameters::CPOCommandReadParameters%1039418956.initialization preserve=yes
  : CPOCommand(p_pContext)
  //## end CPOCommandReadParameters::CPOCommandReadParameters%1039418956.initialization
{
  //## begin CPOCommandReadParameters::CPOCommandReadParameters%1039418956.body preserve=yes
  //## end CPOCommandReadParameters::CPOCommandReadParameters%1039418956.body
}


CPOCommandReadParameters::~CPOCommandReadParameters()
{
  //## begin CPOCommandReadParameters::~CPOCommandReadParameters%.body preserve=yes
  //## end CPOCommandReadParameters::~CPOCommandReadParameters%.body
}



//## Other Operations (implementation)
void CPOCommandReadParameters::CreateSyncObjects ()
{
  //## begin CPOCommandReadParameters::CreateSyncObjects%1039418957.body preserve=yes

	// false means: don't keep own reference
    m_pSyncArray->Add(new CPISyncObjListPersistentItems(NULL), false);

  //## end CPOCommandReadParameters::CreateSyncObjects%1039418957.body
}

bool CPOCommandReadParameters::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandReadParameters::Execute%1039418958.body preserve=yes

	// Keep sync object.
	CPISyncObjListPersistentItems* pClientSyncObj = dynamic_cast<CPISyncObjListPersistentItems*>(m_pSyncArray->GetAt(0));
    ASSERT(pClientSyncObj != NULL);

    // Execute command.
    p_pCurrentState->ReadParameters(m_pContext, pClientSyncObj);

    return true;
  //## end CPOCommandReadParameters::Execute%1039418958.body
}

// Additional Declarations
  //## begin CPOCommandReadParameters%3DF44C5700C2.declarations preserve=yes
  //## end CPOCommandReadParameters%3DF44C5700C2.declarations

// Class CPOCommandWriteParameter 


CPOCommandWriteParameter::CPOCommandWriteParameter (ICOStateMachineContext *p_pContext, CPIPersistentPara *p_pParameter)
  //## begin CPOCommandWriteParameter::CPOCommandWriteParameter%1039418959.hasinit preserve=no
      : m_pParameter(p_pParameter)
  //## end CPOCommandWriteParameter::CPOCommandWriteParameter%1039418959.hasinit
  //## begin CPOCommandWriteParameter::CPOCommandWriteParameter%1039418959.initialization preserve=yes
  , CPOCommand(p_pContext)
  //## end CPOCommandWriteParameter::CPOCommandWriteParameter%1039418959.initialization
{
  //## begin CPOCommandWriteParameter::CPOCommandWriteParameter%1039418959.body preserve=yes
	m_pParameter->AddRef();
  //## end CPOCommandWriteParameter::CPOCommandWriteParameter%1039418959.body
}


CPOCommandWriteParameter::~CPOCommandWriteParameter()
{
  //## begin CPOCommandWriteParameter::~CPOCommandWriteParameter%.body preserve=yes
	if (m_pParameter != NULL)
		m_pParameter->ReleaseRef();

	m_pParameter = NULL;
  //## end CPOCommandWriteParameter::~CPOCommandWriteParameter%.body
}



//## Other Operations (implementation)
bool CPOCommandWriteParameter::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandWriteParameter::Execute%1039418960.body preserve=yes
    // execute command
    p_pCurrentState->WriteParameter( m_pContext, m_pParameter );
    return true;
  //## end CPOCommandWriteParameter::Execute%1039418960.body
}

// Additional Declarations
  //## begin CPOCommandWriteParameter%3DF4672D0385.declarations preserve=yes
  //## end CPOCommandWriteParameter%3DF4672D0385.declarations

// Class CPOCommandSetConfig 


CPOCommandSetConfig::CPOCommandSetConfig (ICOStateMachineContext* p_pContext, CPIPersistentConfig* p_pConfig)
  //## begin CPOCommandSetConfig::CPOCommandSetConfig%1066813276.hasinit preserve=no
      : m_pConfig(p_pConfig)
  //## end CPOCommandSetConfig::CPOCommandSetConfig%1066813276.hasinit
  //## begin CPOCommandSetConfig::CPOCommandSetConfig%1066813276.initialization preserve=yes
  ,CPOCommand(p_pContext)
  //## end CPOCommandSetConfig::CPOCommandSetConfig%1066813276.initialization
{
  //## begin CPOCommandSetConfig::CPOCommandSetConfig%1066813276.body preserve=yes
	m_pConfig->AddRef();
  //## end CPOCommandSetConfig::CPOCommandSetConfig%1066813276.body
}


CPOCommandSetConfig::~CPOCommandSetConfig()
{
  //## begin CPOCommandSetConfig::~CPOCommandSetConfig%.body preserve=yes

	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();
	m_pConfig = NULL;

  //## end CPOCommandSetConfig::~CPOCommandSetConfig%.body
}



//## Other Operations (implementation)
bool CPOCommandSetConfig::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandSetConfig::Execute%1066813277.body preserve=yes
	p_pCurrentState->SetConfig(m_pContext, m_pConfig);
	return true;
  //## end CPOCommandSetConfig::Execute%1066813277.body
}

// Additional Declarations
  //## begin CPOCommandSetConfig%3F96424A0395.declarations preserve=yes
  //## end CPOCommandSetConfig%3F96424A0395.declarations

// Class CPOCommandReadIdentifications 

CPOCommandReadIdentifications::CPOCommandReadIdentifications (ICOStateMachineContext* p_pContext)
  //## begin CPOCommandReadIdentifications::CPOCommandReadIdentifications%1066888952.hasinit preserve=no
  //## end CPOCommandReadIdentifications::CPOCommandReadIdentifications%1066888952.hasinit
  //## begin CPOCommandReadIdentifications::CPOCommandReadIdentifications%1066888952.initialization preserve=yes
  : CPOCommand(p_pContext)
  //## end CPOCommandReadIdentifications::CPOCommandReadIdentifications%1066888952.initialization
{
  //## begin CPOCommandReadIdentifications::CPOCommandReadIdentifications%1066888952.body preserve=yes
  //## end CPOCommandReadIdentifications::CPOCommandReadIdentifications%1066888952.body
}


CPOCommandReadIdentifications::~CPOCommandReadIdentifications()
{
  //## begin CPOCommandReadIdentifications::~CPOCommandReadIdentifications%.body preserve=yes
  //## end CPOCommandReadIdentifications::~CPOCommandReadIdentifications%.body
}



//## Other Operations (implementation)
bool CPOCommandReadIdentifications::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandReadIdentifications::Execute%1066813278.body preserve=yes
	
	// keep sync object
	CPISyncObjListPersistentItems *l_pClientSyncObj = dynamic_cast<CPISyncObjListPersistentItems*>(m_pSyncArray->GetAt(0));
	ASSERT(l_pClientSyncObj != NULL);
	p_pCurrentState->ReadIdentifications(m_pContext, l_pClientSyncObj);

	return false;
  //## end CPOCommandReadIdentifications::Execute%1066813278.body
}

void CPOCommandReadIdentifications::CreateSyncObjects ()
{
  //## begin CPOCommandReadIdentifications::CreateSyncObjects%1066918323.body preserve=yes

	// false means: don't keep own reference
    m_pSyncArray->Add(new CPISyncObjListPersistentItems(NULL), false);

  //## end CPOCommandReadIdentifications::CreateSyncObjects%1066918323.body
}

// Additional Declarations
  //## begin CPOCommandReadIdentifications%3F9642E001D0.declarations preserve=yes
  //## end CPOCommandReadIdentifications%3F9642E001D0.declarations

// Class CPOCommandWriteIdentification 


CPOCommandWriteIdentification::CPOCommandWriteIdentification (ICOStateMachineContext* p_pContext, CPIPersistentIdent* p_pIdentification)
  //## begin CPOCommandWriteIdentification::CPOCommandWriteIdentification%1066888953.hasinit preserve=no
      : m_pIdentification(p_pIdentification)
  //## end CPOCommandWriteIdentification::CPOCommandWriteIdentification%1066888953.hasinit
  //## begin CPOCommandWriteIdentification::CPOCommandWriteIdentification%1066888953.initialization preserve=yes
	, CPOCommand(p_pContext)
  //## end CPOCommandWriteIdentification::CPOCommandWriteIdentification%1066888953.initialization
{
  //## begin CPOCommandWriteIdentification::CPOCommandWriteIdentification%1066888953.body preserve=yes
	m_pIdentification->AddRef();
  //## end CPOCommandWriteIdentification::CPOCommandWriteIdentification%1066888953.body
}


CPOCommandWriteIdentification::~CPOCommandWriteIdentification()
{
  //## begin CPOCommandWriteIdentification::~CPOCommandWriteIdentification%.body preserve=yes
	if ( m_pIdentification != NULL)
		m_pIdentification->ReleaseRef();

	m_pIdentification = NULL;
  //## end CPOCommandWriteIdentification::~CPOCommandWriteIdentification%.body
}



//## Other Operations (implementation)
bool CPOCommandWriteIdentification::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandWriteIdentification::Execute%1066813279.body preserve=yes
	p_pCurrentState->WriteIdentification( m_pContext, m_pIdentification );
	return true;
  //## end CPOCommandWriteIdentification::Execute%1066813279.body
}

// Additional Declarations
  //## begin CPOCommandWriteIdentification%3F96436C0114.declarations preserve=yes
  //## end CPOCommandWriteIdentification%3F96436C0114.declarations

// Class CPOCommandReadLifeTimeCounter 


CPOCommandReadLifeTimeCounter::CPOCommandReadLifeTimeCounter (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter)
  //## begin CPOCommandReadLifeTimeCounter::CPOCommandReadLifeTimeCounter%1066888954.hasinit preserve=no
      : m_eCounter(p_eCounter)
  //## end CPOCommandReadLifeTimeCounter::CPOCommandReadLifeTimeCounter%1066888954.hasinit
  //## begin CPOCommandReadLifeTimeCounter::CPOCommandReadLifeTimeCounter%1066888954.initialization preserve=yes
  , CPOCommand(p_pContext)
  //## end CPOCommandReadLifeTimeCounter::CPOCommandReadLifeTimeCounter%1066888954.initialization
{
  //## begin CPOCommandReadLifeTimeCounter::CPOCommandReadLifeTimeCounter%1066888954.body preserve=yes
  //## end CPOCommandReadLifeTimeCounter::CPOCommandReadLifeTimeCounter%1066888954.body
}


CPOCommandReadLifeTimeCounter::~CPOCommandReadLifeTimeCounter()
{
  //## begin CPOCommandReadLifeTimeCounter::~CPOCommandReadLifeTimeCounter%.body preserve=yes
  //## end CPOCommandReadLifeTimeCounter::~CPOCommandReadLifeTimeCounter%.body
}



//## Other Operations (implementation)
bool CPOCommandReadLifeTimeCounter::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandReadLifeTimeCounter::Execute%1066813280.body preserve=yes
	// keep sync object
	CCOSyncObjectInt *l_pClientSyncObj = dynamic_cast<CCOSyncObjectInt*>(m_pSyncArray->GetAt(0));
	ASSERT(l_pClientSyncObj != NULL);
	p_pCurrentState->ReadLifeTimeCounter(m_pContext, l_pClientSyncObj, m_eCounter);

	return false;
  //## end CPOCommandReadLifeTimeCounter::Execute%1066813280.body
}

void CPOCommandReadLifeTimeCounter::CreateSyncObjects ()
{
  //## begin CPOCommandReadLifeTimeCounter::CreateSyncObjects%1066918324.body preserve=yes

	// false means: don't keep own reference
	m_pSyncArray->Add(new CCOSyncObjectInt(0), false);

  //## end CPOCommandReadLifeTimeCounter::CreateSyncObjects%1066918324.body
}

// Additional Declarations
  //## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.declarations preserve=yes
  //## end CPOCommandReadLifeTimeCounter%3F96438B01C0.declarations

// Class CPOCommandWriteLifeTimeCounter 



CPOCommandWriteLifeTimeCounter::CPOCommandWriteLifeTimeCounter (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter, UINT p_uiValue)
  //## begin CPOCommandWriteLifeTimeCounter::CPOCommandWriteLifeTimeCounter%1066888958.hasinit preserve=no
      : m_uiValue(p_uiValue), m_eCounter(p_eCounter)
  //## end CPOCommandWriteLifeTimeCounter::CPOCommandWriteLifeTimeCounter%1066888958.hasinit
  //## begin CPOCommandWriteLifeTimeCounter::CPOCommandWriteLifeTimeCounter%1066888958.initialization preserve=yes
  , CPOCommand(p_pContext)
  //## end CPOCommandWriteLifeTimeCounter::CPOCommandWriteLifeTimeCounter%1066888958.initialization
{
  //## begin CPOCommandWriteLifeTimeCounter::CPOCommandWriteLifeTimeCounter%1066888958.body preserve=yes
  //## end CPOCommandWriteLifeTimeCounter::CPOCommandWriteLifeTimeCounter%1066888958.body
}


CPOCommandWriteLifeTimeCounter::~CPOCommandWriteLifeTimeCounter()
{
  //## begin CPOCommandWriteLifeTimeCounter::~CPOCommandWriteLifeTimeCounter%.body preserve=yes
  //## end CPOCommandWriteLifeTimeCounter::~CPOCommandWriteLifeTimeCounter%.body
}



//## Other Operations (implementation)
bool CPOCommandWriteLifeTimeCounter::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandWriteLifeTimeCounter::Execute%1066813284.body preserve=yes
	p_pCurrentState->WriteLifeTimeCounter(m_pContext, m_eCounter, m_uiValue);
	return true;
  //## end CPOCommandWriteLifeTimeCounter::Execute%1066813284.body
}

// Additional Declarations
  //## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.declarations preserve=yes
  //## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.declarations

// Class CPOCommandStartMonitoring 


CPOCommandStartMonitoring::CPOCommandStartMonitoring (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter)
  //## begin CPOCommandStartMonitoring::CPOCommandStartMonitoring%1066888957.hasinit preserve=no
      : m_eCounter(p_eCounter)
  //## end CPOCommandStartMonitoring::CPOCommandStartMonitoring%1066888957.hasinit
  //## begin CPOCommandStartMonitoring::CPOCommandStartMonitoring%1066888957.initialization preserve=yes
 , CPOCommand(p_pContext)
  //## end CPOCommandStartMonitoring::CPOCommandStartMonitoring%1066888957.initialization
{
  //## begin CPOCommandStartMonitoring::CPOCommandStartMonitoring%1066888957.body preserve=yes
  //## end CPOCommandStartMonitoring::CPOCommandStartMonitoring%1066888957.body
}


CPOCommandStartMonitoring::~CPOCommandStartMonitoring()
{
  //## begin CPOCommandStartMonitoring::~CPOCommandStartMonitoring%.body preserve=yes
  //## end CPOCommandStartMonitoring::~CPOCommandStartMonitoring%.body
}



//## Other Operations (implementation)
bool CPOCommandStartMonitoring::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandStartMonitoring::Execute%1066813283.body preserve=yes
	p_pCurrentState->StartMonitoring(m_pContext, m_eCounter);
	return true;
  //## end CPOCommandStartMonitoring::Execute%1066813283.body
}

// Additional Declarations
  //## begin CPOCommandStartMonitoring%3F96454C01DF.declarations preserve=yes
  //## end CPOCommandStartMonitoring%3F96454C01DF.declarations

// Class CPOCommandStopMonitoring 


CPOCommandStopMonitoring::CPOCommandStopMonitoring (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter)
  //## begin CPOCommandStopMonitoring::CPOCommandStopMonitoring%1066888956.hasinit preserve=no
      : m_eCounter(p_eCounter)
  //## end CPOCommandStopMonitoring::CPOCommandStopMonitoring%1066888956.hasinit
  //## begin CPOCommandStopMonitoring::CPOCommandStopMonitoring%1066888956.initialization preserve=yes
  , CPOCommand(p_pContext)
  //## end CPOCommandStopMonitoring::CPOCommandStopMonitoring%1066888956.initialization
{
  //## begin CPOCommandStopMonitoring::CPOCommandStopMonitoring%1066888956.body preserve=yes
  //## end CPOCommandStopMonitoring::CPOCommandStopMonitoring%1066888956.body
}


CPOCommandStopMonitoring::~CPOCommandStopMonitoring()
{
  //## begin CPOCommandStopMonitoring::~CPOCommandStopMonitoring%.body preserve=yes
  //## end CPOCommandStopMonitoring::~CPOCommandStopMonitoring%.body
}



//## Other Operations (implementation)
bool CPOCommandStopMonitoring::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandStopMonitoring::Execute%1066813282.body preserve=yes
	p_pCurrentState->StopMonitoring(m_pContext, m_eCounter);
	return true;
  //## end CPOCommandStopMonitoring::Execute%1066813282.body
}

// Additional Declarations
  //## begin CPOCommandStopMonitoring%3F96455800D6.declarations preserve=yes
  //## end CPOCommandStopMonitoring%3F96455800D6.declarations

// Class CPOCommandSave 

CPOCommandSave::CPOCommandSave (ICOStateMachineContext* p_pContext)
  //## begin CPOCommandSave::CPOCommandSave%1066888955.hasinit preserve=no
  //## end CPOCommandSave::CPOCommandSave%1066888955.hasinit
  //## begin CPOCommandSave::CPOCommandSave%1066888955.initialization preserve=yes
  : CPOCommand(p_pContext)
  //## end CPOCommandSave::CPOCommandSave%1066888955.initialization
{
  //## begin CPOCommandSave::CPOCommandSave%1066888955.body preserve=yes
  //## end CPOCommandSave::CPOCommandSave%1066888955.body
}


CPOCommandSave::~CPOCommandSave()
{
  //## begin CPOCommandSave::~CPOCommandSave%.body preserve=yes
  //## end CPOCommandSave::~CPOCommandSave%.body
}



//## Other Operations (implementation)
bool CPOCommandSave::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandSave::Execute%1066813281.body preserve=yes
	p_pCurrentState->Save(m_pContext);
	return true;
  //## end CPOCommandSave::Execute%1066813281.body
}

// Additional Declarations
  //## begin CPOCommandSave%3F96458D01FE.declarations preserve=yes
  //## end CPOCommandSave%3F96458D01FE.declarations

// Class CPOCommandReset 


CPOCommandReset::CPOCommandReset (ICOStateMachineContext* p_pContext, EPIEpromSection p_eSection)
  //## begin CPOCommandReset::CPOCommandReset%1072788294.hasinit preserve=no
      : m_eSection(p_eSection)
  //## end CPOCommandReset::CPOCommandReset%1072788294.hasinit
  //## begin CPOCommandReset::CPOCommandReset%1072788294.initialization preserve=yes
  , CPOCommand(p_pContext)
  //## end CPOCommandReset::CPOCommandReset%1072788294.initialization
{
  //## begin CPOCommandReset::CPOCommandReset%1072788294.body preserve=yes
  //## end CPOCommandReset::CPOCommandReset%1072788294.body
}


CPOCommandReset::~CPOCommandReset()
{
  //## begin CPOCommandReset::~CPOCommandReset%.body preserve=yes
  //## end CPOCommandReset::~CPOCommandReset%.body
}



//## Other Operations (implementation)
bool CPOCommandReset::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandReset::Execute%1072788297.body preserve=yes
	p_pCurrentState->Reset(m_pContext, m_eSection);
	return true;
  //## end CPOCommandReset::Execute%1072788297.body
}

// Additional Declarations
  //## begin CPOCommandReset%3FF17A45017C.declarations preserve=yes
  //## end CPOCommandReset%3FF17A45017C.declarations

// Class CPOCommandMeasurementCellUndocked 

CPOCommandMeasurementCellUndocked::CPOCommandMeasurementCellUndocked (ICOStateMachineContext* p_pContext)
  //## begin CPOCommandMeasurementCellUndocked::CPOCommandMeasurementCellUndocked%1080142973.hasinit preserve=no
  //## end CPOCommandMeasurementCellUndocked::CPOCommandMeasurementCellUndocked%1080142973.hasinit
  //## begin CPOCommandMeasurementCellUndocked::CPOCommandMeasurementCellUndocked%1080142973.initialization preserve=yes
    : CPOCommand(p_pContext)
  //## end CPOCommandMeasurementCellUndocked::CPOCommandMeasurementCellUndocked%1080142973.initialization
{
  //## begin CPOCommandMeasurementCellUndocked::CPOCommandMeasurementCellUndocked%1080142973.body preserve=yes
  //## end CPOCommandMeasurementCellUndocked::CPOCommandMeasurementCellUndocked%1080142973.body
}


CPOCommandMeasurementCellUndocked::~CPOCommandMeasurementCellUndocked()
{
  //## begin CPOCommandMeasurementCellUndocked::~CPOCommandMeasurementCellUndocked%.body preserve=yes
  //## end CPOCommandMeasurementCellUndocked::~CPOCommandMeasurementCellUndocked%.body
}



//## Other Operations (implementation)
bool CPOCommandMeasurementCellUndocked::Execute (CPOState* p_pCurrentState)
{
  //## begin CPOCommandMeasurementCellUndocked::Execute%1080142974.body preserve=yes
	p_pCurrentState->MeasurementCellUndocked(m_pContext);
	return true;
  //## end CPOCommandMeasurementCellUndocked::Execute%1080142974.body
}

// Additional Declarations
  //## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.declarations preserve=yes
  //## end CPOCommandMeasurementCellUndocked%4061AEC801F4.declarations

//## begin module%3DE5EB5101BA.epilog preserve=yes
//## end module%3DE5EB5101BA.epilog
