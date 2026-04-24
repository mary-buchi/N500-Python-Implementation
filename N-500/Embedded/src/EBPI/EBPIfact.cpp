//## begin module%3DA52FC9037D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA52FC9037D.cm

//## begin module%3DA52FC9037D.cp preserve=no
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
//## end module%3DA52FC9037D.cp

//## Module: EBPIfact%3DA52FC9037D; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIfact.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA52FC9037D.additionalIncludes preserve=no
//## end module%3DA52FC9037D.additionalIncludes

//## begin module%3DA52FC9037D.includes preserve=yes
//## end module%3DA52FC9037D.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPIidnt
#include "EBPIidnt.h"
// EBPIexcp
#include "EBPIexcp.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"


//## begin module%3DA52FC9037D.declarations preserve=no
//## end module%3DA52FC9037D.declarations

//## begin module%3DA52FC9037D.additionalDeclarations preserve=yes
//## end module%3DA52FC9037D.additionalDeclarations


// Class CPIObjectFactory 

//## begin CPIObjectFactory::pInstance%3DA52FFF0275.role preserve=no  public: static CPIObjectFactory {1..1 -> 1..1RFHN}
CPIObjectFactory *CPIObjectFactory::m_pInstance = NULL;
//## end CPIObjectFactory::pInstance%3DA52FFF0275.role



































CPIObjectFactory::CPIObjectFactory()
  //## begin CPIObjectFactory::CPIObjectFactory%.hasinit preserve=no
      : m_pSystemInterface(NULL)
  //## end CPIObjectFactory::CPIObjectFactory%.hasinit
  //## begin CPIObjectFactory::CPIObjectFactory%.initialization preserve=yes
  //## end CPIObjectFactory::CPIObjectFactory%.initialization
{
  //## begin CPIObjectFactory::CPIObjectFactory%.body preserve=yes
  //## end CPIObjectFactory::CPIObjectFactory%.body
}


CPIObjectFactory::~CPIObjectFactory()
{
  //## begin CPIObjectFactory::~CPIObjectFactory%.body preserve=yes
    Reset();
  //## end CPIObjectFactory::~CPIObjectFactory%.body
}



//## Other Operations (implementation)
void CPIObjectFactory::Create ()
{
  //## begin CPIObjectFactory::Create%1034230435.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CPIObjectFactory();
  //## end CPIObjectFactory::Create%1034230435.body
}

void CPIObjectFactory::Delete ()
{
  //## begin CPIObjectFactory::Delete%1034230436.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CPIObjectFactory::Delete%1034230436.body
}

CPIObjectFactory* CPIObjectFactory::GetInstance ()
{
  //## begin CPIObjectFactory::GetInstance%1034230437.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPIObjectFactory::GetInstance%1034230437.body
}

void CPIObjectFactory::SendCmdConnectionEstablished ()
{
  //## begin CPIObjectFactory::SendCmdConnectionEstablished%1056963208.body preserve=yes
    SendCmdToAll(&ICOObjectInterface::ConnectionEstablished);
  //## end CPIObjectFactory::SendCmdConnectionEstablished%1056963208.body
}

void CPIObjectFactory::SendCmdConnectionLost ()
{
  //## begin CPIObjectFactory::SendCmdConnectionLost%1056963209.body preserve=yes
    SendCmdToAll(&ICOObjectInterface::ConnectionLost);
  //## end CPIObjectFactory::SendCmdConnectionLost%1056963209.body
}

void CPIObjectFactory::SendCmdToAll (COAsyncCommandPtr p_pCommand)
{
  //## begin CPIObjectFactory::SendCmdToAll%1056963207.body preserve=yes

    POSITION                                l_Pos;
    CCOSyncObject*                          l_pSyncObject;
    CCOSyncObjectArrayPtr                   l_pSyncArray = new CCOSyncObjectArray();
    CStringArray                            l_TraceMsg;

    try
    {
        // send command to all stepper motors
        for (l_Pos=m_StepperList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIStepperMotorInterface* l_pMotor;
            m_StepperList.GetNextAssoc(l_Pos, l_uiKey, l_pMotor);

            l_pSyncObject = (l_pMotor->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("ST"));
        }

        // send command to all measurement channels
        for (l_Pos=m_MeasurementChannelList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIMeasurementChannelInterface* l_pChannel;
            m_MeasurementChannelList.GetNextAssoc(l_Pos, l_uiKey, l_pChannel);

            l_pSyncObject = (l_pChannel->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("MC"));
        }

        // send command to all digital sensors
        for (l_Pos=m_DigitalSensorList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPISensorDigitalInterface* l_pObj;
            m_DigitalSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("DS"));
        }

        // release all analog sensors
        for (l_Pos=m_AnalogSensorList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPISensorAnalogInterface* l_pObj;
            m_AnalogSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("AS"));
        }

        // send command to all digital outputs
        for (l_Pos=m_DigitalOutputList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIOutputDigitalInterface* l_pObj;
            m_DigitalOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("DO"));
        }

        // send command to all analog outputs
        for (l_Pos=m_AnalogOutputList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIOutputAnalogInterface* l_pObj;
            m_AnalogOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("AO"));
        }

        // send command to all temperature controls
        for (l_Pos=m_TemperatureControlList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPITemperatureControlInterface* l_pObj;
            m_TemperatureControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("TC"));
        }

        // send command to all controls
        for (l_Pos=m_PowerControlList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIPowerControlInterface* l_pObj;
            m_PowerControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("PC"));
        }

        // send command to all wedge controls
        for (l_Pos=m_WedgeControlList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIWedgeControlInterface* l_pObj;
            m_WedgeControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("WC"));
        }

        // send command to all event sources
        for (l_Pos=m_EventSourceList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIEventSourceInterface* l_pObj;
            m_EventSourceList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("ES"));
        }

        // release all persistent object managers
        for (l_Pos=m_PersistentObjList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIPersistentObjInterface* l_pObj;
            m_PersistentObjList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("PO"));
        }

        // release all persistent object managers
        for (l_Pos=m_DiagnosticObjList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPIDiagnosticInterface* l_pObj;
            m_DiagnosticObjList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("DI"));
        }

        // release all I2C Sensors DS1631Z
        for (l_Pos=m_SensorDS1631ZList.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPII2CTempSensorDS1631Z* l_pObj;
            m_SensorDS1631ZList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("I2CTEMP"));
        }

        // release all I2C Eproms 24LC515
        for (l_Pos=m_Eprom24LC515List.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPII2CEprom24LC515* l_pObj;
            m_Eprom24LC515List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("I2CEPROM"));
        }

        // release all I2C ADC MAX1037
        for (l_Pos=m_ADCMAX1037List.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPII2CADCMAX1037* l_pObj;
            m_ADCMAX1037List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("I2CADC"));
        }

        // release all I2C DP AD5245
        for (l_Pos=m_DigitalPotiAD5245List.GetStartPosition(); l_Pos!=NULL;)
        {
            UINT l_uiKey;
            IPII2CDigitalPotiAD5245* l_pObj;
            m_DigitalPotiAD5245List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

            l_pSyncObject = (l_pObj->*p_pCommand)();
            l_pSyncArray->Add(l_pSyncObject, false);
            l_TraceMsg.Add(_T("I2CDP"));
        }

        // Wait until all objacts have done their work
        l_pSyncArray->Synchronize(10000);
    }
    catch(XCOExceptionErrorTimeout* p_pException)
    {
        p_pException->Delete();
        for (int l_iCnt=0; l_iCnt<l_pSyncArray->GetSize(); l_iCnt++)
        {
            CString l_sMsg;
            l_sMsg.Format(_T("Object %s, signalled %d"), l_TraceMsg.GetAt(l_iCnt), (int)l_pSyncArray->GetAt(l_iCnt)->GetbIsSignalled());
            CO_TRACE(PI_ID, l_sMsg);
        }
        CCOSystemMonitorInterface::GetpMonitor()->FlushQueue();
        ASSERT(FALSE);
    }
  //## end CPIObjectFactory::SendCmdToAll%1056963207.body
}

void CPIObjectFactory::Reset (const bool p_bIncludingCreators)
{
  //## begin CPIObjectFactory::Reset%1056628600.body preserve=yes
    // release all stepper motors
	POSITION l_Pos; //scch
    for (l_Pos=m_StepperList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIStepperMotorInterface* l_pMotor;
        m_StepperList.GetNextAssoc(l_Pos, l_uiKey, l_pMotor);

		CCOSyncObjectPtr l_pSyncObj = l_pMotor->Shutdown();
		l_pSyncObj->Synchronize();
        l_pMotor->ExitInstance();
        delete l_pMotor;
    }
    m_StepperList.RemoveAll();
    if (p_bIncludingCreators)
    {
	    for (l_Pos=m_StepperCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_StepperCreators.GetNext(l_Pos);
	    }
	    m_StepperCreators.RemoveAll();
    }

    // release all measurement channels
    for (l_Pos=m_MeasurementChannelList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIMeasurementChannelInterface* l_pChannel;
        m_MeasurementChannelList.GetNextAssoc(l_Pos, l_uiKey, l_pChannel);

		CCOSyncObjectPtr l_pSyncObj = l_pChannel->Shutdown();
		l_pSyncObj->Synchronize();
        l_pChannel->ExitInstance();
        delete l_pChannel;
    }
    m_MeasurementChannelList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_MeasurementChannelCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_MeasurementChannelCreators.GetNext(l_Pos);
	    }
	    m_MeasurementChannelCreators.RemoveAll();
    }

    // release all digital sensors
    for (l_Pos=m_DigitalSensorList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPISensorDigitalInterface* l_pObj;
        m_DigitalSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DigitalSensorList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_DigitalSensorCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_DigitalSensorCreators.GetNext(l_Pos);
	    }
	    m_DigitalSensorCreators.RemoveAll();
    }

    // release all analog sensors
    for (l_Pos=m_AnalogSensorList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPISensorAnalogInterface* l_pObj;
        m_AnalogSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_AnalogSensorList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_AnalogSensorCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_AnalogSensorCreators.GetNext(l_Pos);
	    }
	    m_AnalogSensorCreators.RemoveAll();
    }

    // release all digital outputs
    for (l_Pos=m_DigitalOutputList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIOutputDigitalInterface* l_pObj;
        m_DigitalOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DigitalOutputList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_DigitalOutputCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_DigitalOutputCreators.GetNext(l_Pos);
	    }
	    m_DigitalOutputCreators.RemoveAll();
    }

    // release all analog outputs
    for (l_Pos=m_AnalogOutputList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIOutputAnalogInterface* l_pObj;
        m_AnalogOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_AnalogOutputList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_AnalogOutputCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_AnalogOutputCreators.GetNext(l_Pos);
	    }
	    m_AnalogOutputCreators.RemoveAll();
    }

    // release all temperature controls
    for (l_Pos=m_TemperatureControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPITemperatureControlInterface* l_pObj;
        m_TemperatureControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        l_pObj->ExitInstance();
        delete l_pObj;
    }
    m_TemperatureControlList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_TemperatureControlCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_TemperatureControlCreators.GetNext(l_Pos);
	    }
	    m_TemperatureControlCreators.RemoveAll();
    }

    // release all power controls
    for (l_Pos=m_PowerControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIPowerControlInterface* l_pObj;
        m_PowerControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        l_pObj->ExitInstance();
        delete l_pObj;
    }
    m_PowerControlList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_PowerControlCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_PowerControlCreators.GetNext(l_Pos);
	    }
	    m_PowerControlCreators.RemoveAll();
    }

    // release all wedge controls
    for (l_Pos=m_WedgeControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIWedgeControlInterface* l_pObj;
        m_WedgeControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        l_pObj->ExitInstance();
        delete l_pObj;
    }
    m_WedgeControlList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_WedgeControlCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_WedgeControlCreators.GetNext(l_Pos);
	    }
	    m_WedgeControlCreators.RemoveAll();
    }

    // release all event sources
    for (l_Pos=m_EventSourceList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIEventSourceInterface* l_pObj;
        m_EventSourceList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_EventSourceList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_EventSourceCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_EventSourceCreators.GetNext(l_Pos);
	    }
	    m_EventSourceCreators.RemoveAll();
    }

    // release all persistent object managers
    for (l_Pos=m_PersistentObjList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIPersistentObjInterface* l_pObj;
        m_PersistentObjList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        l_pObj->ExitInstance();
        delete l_pObj;
    }
    m_PersistentObjList.RemoveAll();
	// do not unregister PO which belongs to the core system!
    //if (p_bIncludingCreators)
    //{
    //    for (l_Pos=m_PersistentObjectCreators.GetHeadPosition(); l_Pos!=NULL;)
	//    {
	//	    delete m_PersistentObjectCreators.GetNext(l_Pos);
	//    }
	//    m_PersistentObjectCreators.RemoveAll();
    //}

    // release all persistent object managers
    for (l_Pos=m_DiagnosticObjList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIDiagnosticInterface* l_pObj;
        m_DiagnosticObjList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DiagnosticObjList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_DiagnosticCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_DiagnosticCreators.GetNext(l_Pos);
	    }
	    m_DiagnosticCreators.RemoveAll();
    }

    // release all I2C Sensors DS1631Z
    for (l_Pos=m_SensorDS1631ZList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CTempSensorDS1631Z* l_pObj;
        m_SensorDS1631ZList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_SensorDS1631ZList.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_I2CSensorDS1631ZCreators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_I2CSensorDS1631ZCreators.GetNext(l_Pos);
	    }
	    m_I2CSensorDS1631ZCreators.RemoveAll();
    }

    // release all I2C Eproms 24LC515
    for (l_Pos=m_Eprom24LC515List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CEprom24LC515* l_pObj;
        m_Eprom24LC515List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);
        
		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_Eprom24LC515List.RemoveAll();
	// Eprom belongs to the CORE
    //if (p_bIncludingCreators)
    //{
    //    for (l_Pos=m_I2CEprom24LC515Creators.GetHeadPosition(); l_Pos!=NULL;)
	//    {
	//	    delete m_I2CEprom24LC515Creators.GetNext(l_Pos);
	//    }
	//    m_I2CEprom24LC515Creators.RemoveAll();
    //}

    // release all I2C ADC MAX1037
    for (l_Pos=m_ADCMAX1037List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CADCMAX1037* l_pObj;
        m_ADCMAX1037List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_ADCMAX1037List.RemoveAll();

      if (p_bIncludingCreators)
    {
        for (l_Pos=m_I2CADCMAX1037Creators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_I2CADCMAX1037Creators.GetNext(l_Pos);
	    }
	    m_I2CADCMAX1037Creators.RemoveAll();
    }

    // release all I2C DP AD5245
    for (l_Pos=m_DigitalPotiAD5245List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CDigitalPotiAD5245* l_pObj;
        m_DigitalPotiAD5245List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DigitalPotiAD5245List.RemoveAll();
    if (p_bIncludingCreators)
    {
        for (l_Pos=m_I2CDigitalPotiAD5245Creators.GetHeadPosition(); l_Pos!=NULL;)
	    {
		    delete m_I2CDigitalPotiAD5245Creators.GetNext(l_Pos);
	    }
	    m_I2CDigitalPotiAD5245Creators.RemoveAll();
    }
  //## end CPIObjectFactory::Reset%1056628600.body
}

void CPIObjectFactory::RestartDevice (const bool p_bIncludingCreators)
{
  //## begin CPIObjectFactory::RestartDevice%1183536493.body preserve=yes
    // release all stepper motors
	POSITION l_Pos;
    for (l_Pos=m_StepperList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIStepperMotorInterface* l_pMotor;
        m_StepperList.GetNextAssoc(l_Pos, l_uiKey, l_pMotor);

		CCOSyncObjectPtr l_pSyncObj = l_pMotor->Shutdown();
		l_pSyncObj->Synchronize();
        l_pMotor->ExitInstance();
        delete l_pMotor;
    }
    m_StepperList.RemoveAll();

    // release all measurement channels
    for (l_Pos=m_MeasurementChannelList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIMeasurementChannelInterface* l_pChannel;
        m_MeasurementChannelList.GetNextAssoc(l_Pos, l_uiKey, l_pChannel);

		CCOSyncObjectPtr l_pSyncObj = l_pChannel->Shutdown();
		l_pSyncObj->Synchronize();
        l_pChannel->ExitInstance();
        delete l_pChannel;
    }
    m_MeasurementChannelList.RemoveAll();

    // release all digital sensors
    for (l_Pos=m_DigitalSensorList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPISensorDigitalInterface* l_pObj;
        m_DigitalSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DigitalSensorList.RemoveAll();

    // release all analog sensors
    for (l_Pos=m_AnalogSensorList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPISensorAnalogInterface* l_pObj;
        m_AnalogSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_AnalogSensorList.RemoveAll();

    // release all digital outputs
    for (l_Pos=m_DigitalOutputList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIOutputDigitalInterface* l_pObj;
        m_DigitalOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DigitalOutputList.RemoveAll();

    // release all analog outputs
    for (l_Pos=m_AnalogOutputList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIOutputAnalogInterface* l_pObj;
        m_AnalogOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_AnalogOutputList.RemoveAll();

    // release all temperature controls
    for (l_Pos=m_TemperatureControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPITemperatureControlInterface* l_pObj;
        m_TemperatureControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        l_pObj->ExitInstance();
        delete l_pObj;
    }
    m_TemperatureControlList.RemoveAll();

    // release all power controls
    for (l_Pos=m_PowerControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIPowerControlInterface* l_pObj;
        m_PowerControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        l_pObj->ExitInstance();
        delete l_pObj;
    }
    m_PowerControlList.RemoveAll();

    // release all wedge controls
    for (l_Pos=m_WedgeControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIWedgeControlInterface* l_pObj;
        m_WedgeControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        l_pObj->ExitInstance();
        delete l_pObj;
    }
    m_WedgeControlList.RemoveAll();

    // release all event sources
    for (l_Pos=m_EventSourceList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIEventSourceInterface* l_pObj;
        m_EventSourceList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_EventSourceList.RemoveAll();

    // release all persistent object managers
    for (l_Pos=m_DiagnosticObjList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIDiagnosticInterface* l_pObj;
        m_DiagnosticObjList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DiagnosticObjList.RemoveAll();

    // release all I2C Sensors DS1631Z
    for (l_Pos=m_SensorDS1631ZList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CTempSensorDS1631Z* l_pObj;
        m_SensorDS1631ZList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_SensorDS1631ZList.RemoveAll();

    // release all I2C ADC MAX1037
    for (l_Pos=m_ADCMAX1037List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CADCMAX1037* l_pObj;
        m_ADCMAX1037List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_ADCMAX1037List.RemoveAll();

    // release all I2C DP AD5245
    for (l_Pos=m_DigitalPotiAD5245List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CDigitalPotiAD5245* l_pObj;
        m_DigitalPotiAD5245List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

		CCOSyncObjectPtr l_pSyncObj = l_pObj->Shutdown();
		l_pSyncObj->Synchronize();
        delete l_pObj;
    }
    m_DigitalPotiAD5245List.RemoveAll();
  //## end CPIObjectFactory::RestartDevice%1183536493.body
}

void CPIObjectFactory::DeleteObject (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::DeleteObject%1034407674.body preserve=yes
	IPIStepperMotorInterface*       l_pStepper = NULL;
    IPIMeasurementChannelInterface* l_pMeasurementChannel = NULL;
    IPISensorDigitalInterface*      l_pSensorDigital = NULL;
    IPISensorAnalogInterface*       l_pSensorAnalog = NULL;
    IPIOutputDigitalInterface*      l_pOutputDigital = NULL;
    IPIOutputAnalogInterface*       l_pOutputAnalog = NULL;
    IPITemperatureControlInterface* l_pTemperatureControl = NULL;
    IPIPowerControlInterface*       l_pPowerControl = NULL;
    IPIWedgeControlInterface*       l_pWedgeControl = NULL;
    IPIEventSourceInterface*        l_pEventSource = NULL;
    IPIPersistentObjInterface*      l_pPersistentObj = NULL;
    IPIDiagnosticInterface*         l_pDiagnostic = NULL;
    IPII2CEprom24LC515*             l_pEprom24LC515 = NULL;
    IPII2CTempSensorDS1631Z*        l_pSensorDS1631Z = NULL;
    IPII2CADCMAX1037*               l_pADCMAX1037 = NULL;
    IPII2CDigitalPotiAD5245*        l_pDPAD5245 = NULL;

	if (m_StepperList.Lookup(p_uiObjectID, l_pStepper))
	{
		// stepper motor found
		m_StepperList.RemoveKey(p_uiObjectID);
		l_pStepper->ExitInstance();
		delete l_pStepper;
		return;
	}

    if (m_MeasurementChannelList.Lookup(p_uiObjectID, l_pMeasurementChannel))
	{
		// stepper motor found
		m_MeasurementChannelList.RemoveKey(p_uiObjectID);
		l_pMeasurementChannel->ExitInstance();
		delete l_pMeasurementChannel;
		return;
	}

    if (m_AnalogSensorList.Lookup(p_uiObjectID, l_pSensorAnalog))
	{
		// analog sensor found
		m_AnalogSensorList.RemoveKey(p_uiObjectID);
		delete l_pSensorAnalog;
		return;
	}

    if (m_DigitalSensorList.Lookup(p_uiObjectID, l_pSensorDigital))
	{
		// digital sensor found
		m_DigitalSensorList.RemoveKey(p_uiObjectID);
		delete l_pSensorDigital;
		return;
	}

    if (m_AnalogOutputList.Lookup(p_uiObjectID, l_pOutputAnalog))
	{
		// analog output found
		m_AnalogOutputList.RemoveKey(p_uiObjectID);
		delete l_pOutputAnalog;
		return;
	}

    if (m_DigitalOutputList.Lookup(p_uiObjectID, l_pOutputDigital))
	{
		// digital output found
		m_DigitalOutputList.RemoveKey(p_uiObjectID);
		delete l_pOutputDigital;
		return;
	}

    if (m_TemperatureControlList.Lookup(p_uiObjectID, l_pTemperatureControl))
	{
		// temperature control found
		m_TemperatureControlList.RemoveKey(p_uiObjectID);
		l_pTemperatureControl->ExitInstance();
		delete l_pTemperatureControl;
		return;
	}

    if (m_PowerControlList.Lookup(p_uiObjectID, l_pPowerControl))
	{
		// power control found
		m_PowerControlList.RemoveKey(p_uiObjectID);
		l_pPowerControl->ExitInstance();
		delete l_pPowerControl;
		return;
	}

    if (m_WedgeControlList.Lookup(p_uiObjectID, l_pWedgeControl))
	{
		// wedge control found
		m_WedgeControlList.RemoveKey(p_uiObjectID);
		l_pWedgeControl->ExitInstance();
		delete l_pWedgeControl;
		return;
	}

    if (m_EventSourceList.Lookup(p_uiObjectID, l_pEventSource))
	{
		// event source found
		m_EventSourceList.RemoveKey(p_uiObjectID);
		delete l_pEventSource;
		return;
	}

    if (m_PersistentObjList.Lookup(p_uiObjectID, l_pPersistentObj))
	{
		// persistent object manager found
		m_PersistentObjList.RemoveKey(p_uiObjectID);
		l_pPersistentObj->ExitInstance();
		delete l_pPersistentObj;
		return;
	}
    if (m_DiagnosticObjList.Lookup(p_uiObjectID, l_pDiagnostic))
	{
		// event source found
		m_DiagnosticObjList.RemoveKey(p_uiObjectID);
		delete l_pDiagnostic;
		return;
	}

  if (m_SensorDS1631ZList.Lookup(p_uiObjectID, l_pSensorDS1631Z))
	{
		// object found
		m_SensorDS1631ZList.RemoveKey(p_uiObjectID);
		delete l_pSensorDS1631Z;
		return;
	}

  if (m_Eprom24LC515List.Lookup(p_uiObjectID, l_pEprom24LC515))
	{
		// object found
		m_Eprom24LC515List.RemoveKey(p_uiObjectID);
		delete l_pEprom24LC515;
		return;
	}

  if (m_ADCMAX1037List.Lookup(p_uiObjectID, l_pADCMAX1037))
	{
		// object found
		m_ADCMAX1037List.RemoveKey(p_uiObjectID);
		delete l_pADCMAX1037;
		return;
	}

  if (m_DigitalPotiAD5245List.Lookup(p_uiObjectID, l_pDPAD5245))
	{
		// object found
		m_DigitalPotiAD5245List.RemoveKey(p_uiObjectID);
		delete l_pDPAD5245;
		return;
	}

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::DeleteObject%1034407674.body
}

IPISystemInterface* CPIObjectFactory::QuerySystemInterface ()
{
  //## begin CPIObjectFactory::QuerySystemInterface%1055243204.body preserve=yes
    if (m_pSystemInterface == NULL)
        throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);

    return m_pSystemInterface;
  //## end CPIObjectFactory::QuerySystemInterface%1055243204.body
}

IPIStepperMotorInterface* CPIObjectFactory::CreateStepperMotor (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateStepperMotor%1034230438.body preserve=yes
    // try to find existing motor
    IPIStepperMotorInterface* l_pMotor = NULL;
    if (m_StepperList.Lookup(p_uiObjectID, l_pMotor))
    {
        // motor already exists -> return same instance
        return l_pMotor;
    }

    // create new motor
	CPIObjCreatorStepperMotor* l_pCreator = FindStepperCreator(p_sObjVersion);
    l_pMotor = l_pCreator->Create(p_uiObjectID);
    m_StepperList.SetAt(p_uiObjectID, l_pMotor);

    return l_pMotor;
  //## end CPIObjectFactory::CreateStepperMotor%1034230438.body
}

IPIStepperMotorInterface* CPIObjectFactory::QueryStepperMotor (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryStepperMotor%1034329219.body preserve=yes
    // try to find existing motor
    IPIStepperMotorInterface* l_pMotor = NULL;
    if (m_StepperList.Lookup(p_uiObjectID, l_pMotor))
    {
        // motor found
        return l_pMotor;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryStepperMotor%1034329219.body
}

IPIMeasurementChannelInterface* CPIObjectFactory::CreateMeasurementChannel (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateMeasurementChannel%1034575102.body preserve=yes
    // try to find existing measurement channel
    IPIMeasurementChannelInterface* l_pMeasurementChannel = NULL;
    if (m_MeasurementChannelList.Lookup(p_uiObjectID, l_pMeasurementChannel))
    {
        // channel already exists -> return same instance
        return l_pMeasurementChannel;
    }

    // create new motor
	CPIObjCreatorMeasurementChannel* l_pCreator = FindMeasurementChannel(p_sObjVersion);
    l_pMeasurementChannel = l_pCreator->Create(p_uiObjectID);
    m_MeasurementChannelList.SetAt(p_uiObjectID, l_pMeasurementChannel);

    return l_pMeasurementChannel;
  //## end CPIObjectFactory::CreateMeasurementChannel%1034575102.body
}

IPIMeasurementChannelInterface* CPIObjectFactory::QueryMeasurementChannel (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryMeasurementChannel%1034575103.body preserve=yes
    // try to find existing motor
    IPIMeasurementChannelInterface* l_pMeasurmentChannel = NULL;
    if (m_MeasurementChannelList.Lookup(p_uiObjectID, l_pMeasurmentChannel))
    {
        // measurement channel found
        return l_pMeasurmentChannel;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryMeasurementChannel%1034575103.body
}

IPISensorAnalogInterface* CPIObjectFactory::CreateAnalogSensor (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateAnalogSensor%1037103438.body preserve=yes
    // try to find existing object
    IPISensorAnalogInterface* l_pObj = NULL;
    if (m_AnalogSensorList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorSensorAnalog* l_pCreator = FindAnalogSensor(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_AnalogSensorList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateAnalogSensor%1037103438.body
}

IPISensorAnalogInterface* CPIObjectFactory::QueryAnalogSensor (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryAnalogSensor%1037103447.body preserve=yes
    // try to find existing object
    IPISensorAnalogInterface* l_pObj = NULL;
    if (m_AnalogSensorList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryAnalogSensor%1037103447.body
}

IPIOutputAnalogInterface* CPIObjectFactory::CreateAnalogOutput (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateAnalogOutput%1037103439.body preserve=yes
    // try to find existing object
    IPIOutputAnalogInterface* l_pObj = NULL;
    if (m_AnalogOutputList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorOutputAnalog* l_pCreator = FindAnalogOutput(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_AnalogOutputList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateAnalogOutput%1037103439.body
}

IPIOutputAnalogInterface* CPIObjectFactory::QueryAnalogOutput (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryAnalogOutput%1037103448.body preserve=yes
    // try to find existing object
    IPIOutputAnalogInterface* l_pObj = NULL;
    if (m_AnalogOutputList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryAnalogOutput%1037103448.body
}

IPISensorDigitalInterface* CPIObjectFactory::CreateDigitalSensor (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateDigitalSensor%1037103440.body preserve=yes
    // try to find existing object
    IPISensorDigitalInterface* l_pObj = NULL;
    if (m_DigitalSensorList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorSensorDigital* l_pCreator = FindDigitalSensor(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_DigitalSensorList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateDigitalSensor%1037103440.body
}

IPISensorDigitalInterface* CPIObjectFactory::QueryDigitalSensor (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryDigitalSensor%1037103449.body preserve=yes
    // try to find existing object
    IPISensorDigitalInterface* l_pObj = NULL;
    if (m_DigitalSensorList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryDigitalSensor%1037103449.body
}

IPIOutputDigitalInterface* CPIObjectFactory::CreateDigitalOutput (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateDigitalOutput%1037103441.body preserve=yes
    // try to find existing object
    IPIOutputDigitalInterface* l_pObj = NULL;
    if (m_DigitalOutputList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorOutputDigital* l_pCreator = FindDigitalOutput(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_DigitalOutputList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateDigitalOutput%1037103441.body
}

IPIOutputDigitalInterface* CPIObjectFactory::QueryDigitalOutput (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryDigitalOutput%1037103450.body preserve=yes
    // try to find existing object
    IPIOutputDigitalInterface* l_pObj = NULL;
    if (m_DigitalOutputList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryDigitalOutput%1037103450.body
}

IPITemperatureControlInterface* CPIObjectFactory::CreateTemperatureControl (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateTemperatureControl%1037103442.body preserve=yes
    // try to find existing object
    IPITemperatureControlInterface* l_pObj = NULL;
    if (m_TemperatureControlList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorTemperatureControl* l_pCreator = FindTemperatureControl(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_TemperatureControlList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateTemperatureControl%1037103442.body
}

IPITemperatureControlInterface* CPIObjectFactory::QueryTemperatureControl (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryTemperatureControl%1037103451.body preserve=yes
    // try to find existing object
    IPITemperatureControlInterface* l_pObj = NULL;
    if (m_TemperatureControlList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryTemperatureControl%1037103451.body
}

IPIPowerControlInterface* CPIObjectFactory::CreatePowerControl (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreatePowerControl%1037103443.body preserve=yes
    // try to find existing object
    IPIPowerControlInterface* l_pObj = NULL;
    if (m_PowerControlList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorPowerControl* l_pCreator = FindPowerControl(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_PowerControlList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreatePowerControl%1037103443.body
}

IPIPowerControlInterface* CPIObjectFactory::QueryPowerControl (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryPowerControl%1037103452.body preserve=yes
    // try to find existing object
    IPIPowerControlInterface* l_pObj = NULL;
    if (m_PowerControlList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryPowerControl%1037103452.body
}

IPIWedgeControlInterface* CPIObjectFactory::CreateWedgeControl (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateWedgeControl%1037103444.body preserve=yes
    // try to find existing object
    IPIWedgeControlInterface* l_pObj = NULL;
    if (m_WedgeControlList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorWedgeControl* l_pCreator = FindWedgeControl(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_WedgeControlList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateWedgeControl%1037103444.body
}

IPIWedgeControlInterface* CPIObjectFactory::QueryWedgeControl (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryWedgeControl%1037103453.body preserve=yes
    // try to find existing object
    IPIWedgeControlInterface* l_pObj = NULL;
    if (m_WedgeControlList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryWedgeControl%1037103453.body
}

IPIEventSourceInterface* CPIObjectFactory::CreateEventSource (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateEventSource%1037103445.body preserve=yes
    // try to find existing object
    IPIEventSourceInterface* l_pObj = NULL;
    if (m_EventSourceList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorEventSource* l_pCreator = FindEventSource(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_EventSourceList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateEventSource%1037103445.body
}

IPIEventSourceInterface* CPIObjectFactory::QueryEventSource (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryEventSource%1037103454.body preserve=yes
    // try to find existing object
    IPIEventSourceInterface* l_pObj = NULL;
    if (m_EventSourceList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryEventSource%1037103454.body
}

IPIPersistentObjInterface* CPIObjectFactory::CreatePersistentObjectManager (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreatePersistentObjectManager%1037103446.body preserve=yes
    // try to find existing object
    IPIPersistentObjInterface* l_pObj = NULL;
    if (m_PersistentObjList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorPersistentObject* l_pCreator = FindPersistentObjectManager(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_PersistentObjList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreatePersistentObjectManager%1037103446.body
}

IPIPersistentObjInterface* CPIObjectFactory::QueryPersistentObjManager (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryPersistentObjManager%1037103455.body preserve=yes
    // try to find existing object
    IPIPersistentObjInterface* l_pObj = NULL;
    if (m_PersistentObjList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryPersistentObjManager%1037103455.body
}

IPIDiagnosticInterface* CPIObjectFactory::CreateDiagnostic (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateDiagnostic%1039609793.body preserve=yes
    // try to find existing object
    IPIDiagnosticInterface* l_pObj = NULL;
    if (m_DiagnosticObjList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorDiagnostics* l_pCreator = FindDiagnostic(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_DiagnosticObjList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateDiagnostic%1039609793.body
}

IPIDiagnosticInterface* CPIObjectFactory::QueryDiagnostic (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryDiagnostic%1039609794.body preserve=yes
    // try to find existing object
    IPIDiagnosticInterface* l_pObj = NULL;
    if (m_DiagnosticObjList.Lookup(p_uiObjectID, l_pObj))
    {
        // object found
        return l_pObj;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryDiagnostic%1039609794.body
}

ICOSyncInterface* CPIObjectFactory::QuerySensor (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QuerySensor%1037346560.body preserve=yes
    IPISensorAnalogInterface* l_pAnalogSensor = NULL;
    IPISensorDigitalInterface* l_pDigitalSensor = NULL;
    if (m_AnalogSensorList.Lookup(p_uiObjectID, l_pAnalogSensor))
    {
        // object found
        return l_pAnalogSensor;
    }
    if (m_DigitalSensorList.Lookup(p_uiObjectID, l_pDigitalSensor))
    {
        // object found
        return l_pDigitalSensor;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QuerySensor%1037346560.body
}

ICOSyncInterface* CPIObjectFactory::QueryOutput (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryOutput%1037346561.body preserve=yes
    IPIOutputAnalogInterface* l_pAnalogOutput = NULL;
    IPIOutputDigitalInterface* l_pDigitalOutput = NULL;
    if (m_AnalogOutputList.Lookup(p_uiObjectID, l_pAnalogOutput))
    {
        // object found
        return l_pAnalogOutput;
    }
    if (m_DigitalOutputList.Lookup(p_uiObjectID, l_pDigitalOutput))
    {
        // object found
        return l_pDigitalOutput;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryOutput%1037346561.body
}

IPII2CTempSensorDS1631Z* CPIObjectFactory::CreateSensorDS1631Z (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateSensorDS1631Z%1055243218.body preserve=yes
    // try to find existing object
    IPII2CTempSensorDS1631Z* l_pObj = NULL;
    if (m_SensorDS1631ZList.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorI2CSensorDS1631Z* l_pCreator = FindI2CSensorDS1631Z(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_SensorDS1631ZList.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateSensorDS1631Z%1055243218.body
}

IPII2CTempSensorDS1631Z* CPIObjectFactory::QuerySensorDS1631Z (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QuerySensorDS1631Z%1055243217.body preserve=yes
    IPII2CTempSensorDS1631Z* l_pSensor = NULL;
    if (m_SensorDS1631ZList.Lookup(p_uiObjectID, l_pSensor))
    {
        // object found
        return l_pSensor;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QuerySensorDS1631Z%1055243217.body
}

IPII2CEprom24LC515* CPIObjectFactory::CreateEprom24LC515 (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateEprom24LC515%1055313946.body preserve=yes
    // try to find existing object
    IPII2CEprom24LC515* l_pObj = NULL;
    if (m_Eprom24LC515List.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorI2CEprom24LC515* l_pCreator = FindI2CEprom24LC515(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_Eprom24LC515List.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateEprom24LC515%1055313946.body
}

IPII2CEprom24LC515* CPIObjectFactory::QueryEprom24LC515 (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryEprom24LC515%1055243219.body preserve=yes
    IPII2CEprom24LC515* l_pEprom = NULL;
    if (m_Eprom24LC515List.Lookup(p_uiObjectID, l_pEprom))
    {
        // object found
        return l_pEprom;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryEprom24LC515%1055243219.body
}

IPII2CADCMAX1037* CPIObjectFactory::CreateADCMAX1037 (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateADCMAX1037%1061804152.body preserve=yes
    // try to find existing object
    IPII2CADCMAX1037* l_pObj = NULL;
    if (m_ADCMAX1037List.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorI2CADCMAX1037* l_pCreator = FindI2CADCMAX1037(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_ADCMAX1037List.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateADCMAX1037%1061804152.body
}

IPII2CADCMAX1037* CPIObjectFactory::QueryADCMAX1037 (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryADCMAX1037%1061804153.body preserve=yes
    IPII2CADCMAX1037* l_pADC = NULL;
    if (m_ADCMAX1037List.Lookup(p_uiObjectID, l_pADC))
    {
        // object found
        return l_pADC;
    }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryADCMAX1037%1061804153.body
}

IPII2CDigitalPotiAD5245* CPIObjectFactory::CreateDigitalPotiAD5245 (UINT p_uiObjectID, WCHAR* p_sObjVersion)
{
  //## begin CPIObjectFactory::CreateDigitalPotiAD5245%1061902071.body preserve=yes
    // try to find existing object
    IPII2CDigitalPotiAD5245* l_pObj = NULL;
    if (m_DigitalPotiAD5245List.Lookup(p_uiObjectID, l_pObj))
    {
        // object already exists -> return same instance
        return l_pObj;
    }

    // create new object
    CPIObjCreatorI2CDigitalPotiAD5245* l_pCreator = FindI2CDigitalPotiAD5245(p_sObjVersion);
    l_pObj = l_pCreator->Create(p_uiObjectID);
    m_DigitalPotiAD5245List.SetAt(p_uiObjectID, l_pObj);

    return l_pObj;
  //## end CPIObjectFactory::CreateDigitalPotiAD5245%1061902071.body
}

IPII2CDigitalPotiAD5245* CPIObjectFactory::QueryDigitalPotiAD5245 (UINT p_uiObjectID)
{
  //## begin CPIObjectFactory::QueryDigitalPotiAD5245%1061902072.body preserve=yes
  IPII2CDigitalPotiAD5245* l_pADC = NULL;
  if (m_DigitalPotiAD5245List.Lookup(p_uiObjectID, l_pADC))
  {
      // object found
      return l_pADC;
  }

    throw new XPIExceptionInvalidObjReference(PI_ID, IDE_INVALID_OBJ_REF, _T(__FILE__), __LINE__);
  //## end CPIObjectFactory::QueryDigitalPotiAD5245%1061902072.body
}

void CPIObjectFactory::RegisterSystemInterface (IPISystemInterface* p_pSystemInterface)
{
  //## begin CPIObjectFactory::RegisterSystemInterface%1055492122.body preserve=yes
    m_pSystemInterface = p_pSystemInterface;
  //## end CPIObjectFactory::RegisterSystemInterface%1055492122.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorStepperMotor* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1034272537.body preserve=yes
	m_StepperCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1034272537.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorMeasurementChannel* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1034575105.body preserve=yes
    m_MeasurementChannelCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1034575105.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorSensorAnalog* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084577.body preserve=yes
    m_AnalogSensorCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084577.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorSensorDigital* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084578.body preserve=yes
    m_DigitalSensorCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084578.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorOutputDigital* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084579.body preserve=yes
    m_DigitalOutputCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084579.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorOutputAnalog* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084580.body preserve=yes
    m_AnalogOutputCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084580.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorWedgeControl* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084581.body preserve=yes
    m_WedgeControlCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084581.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorTemperatureControl* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084582.body preserve=yes
    m_TemperatureControlCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084582.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorPowerControl* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084583.body preserve=yes
    m_PowerControlCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084583.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorEventSource* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084584.body preserve=yes
    m_EventSourceCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084584.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorPersistentObject* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1037084585.body preserve=yes
    m_PersistentObjectCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1037084585.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorDiagnostics* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1039609795.body preserve=yes
    m_DiagnosticCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1039609795.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorI2CSensorDS1631Z* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1055313947.body preserve=yes
    m_I2CSensorDS1631ZCreators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1055313947.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorI2CEprom24LC515* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1055313948.body preserve=yes
    m_I2CEprom24LC515Creators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1055313948.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorI2CADCMAX1037* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1061804154.body preserve=yes
    m_I2CADCMAX1037Creators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1061804154.body
}

void CPIObjectFactory::RegisterCreator (CPIObjCreatorI2CDigitalPotiAD5245* p_pCreator)
{
  //## begin CPIObjectFactory::RegisterCreator%1061902073.body preserve=yes
    m_I2CDigitalPotiAD5245Creators.AddTail(p_pCreator);
  //## end CPIObjectFactory::RegisterCreator%1061902073.body
}

CPIObjCreatorStepperMotor* CPIObjectFactory::FindStepperCreator (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindStepperCreator%1034272544.body preserve=yes
	for (POSITION l_Pos=m_StepperCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
		CPIObjCreatorStepperMotor* l_pCreator = m_StepperCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindStepperCreator%1034272544.body
}

CPIObjCreatorMeasurementChannel* CPIObjectFactory::FindMeasurementChannel (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindMeasurementChannel%1034575104.body preserve=yes
    for (POSITION l_Pos=m_MeasurementChannelCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
		CPIObjCreatorMeasurementChannel* l_pCreator = m_MeasurementChannelCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);
	return NULL;
  //## end CPIObjectFactory::FindMeasurementChannel%1034575104.body
}

CPIObjCreatorSensorDigital* CPIObjectFactory::FindDigitalSensor (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindDigitalSensor%1037103429.body preserve=yes
	for (POSITION l_Pos=m_DigitalSensorCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorSensorDigital* l_pCreator = m_DigitalSensorCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

    return NULL;
  //## end CPIObjectFactory::FindDigitalSensor%1037103429.body
}

CPIObjCreatorSensorAnalog* CPIObjectFactory::FindAnalogSensor (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindAnalogSensor%1037103430.body preserve=yes
	for (POSITION l_Pos=m_AnalogSensorCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorSensorAnalog* l_pCreator = m_AnalogSensorCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindAnalogSensor%1037103430.body
}

CPIObjCreatorOutputDigital* CPIObjectFactory::FindDigitalOutput (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindDigitalOutput%1037103431.body preserve=yes
	for (POSITION l_Pos=m_DigitalOutputCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorOutputDigital* l_pCreator = m_DigitalOutputCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindDigitalOutput%1037103431.body
}

CPIObjCreatorOutputAnalog* CPIObjectFactory::FindAnalogOutput (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindAnalogOutput%1037103432.body preserve=yes
	for (POSITION l_Pos=m_AnalogOutputCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorOutputAnalog* l_pCreator = m_AnalogOutputCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindAnalogOutput%1037103432.body
}

CPIObjCreatorTemperatureControl* CPIObjectFactory::FindTemperatureControl (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindTemperatureControl%1037103433.body preserve=yes
	for (POSITION l_Pos=m_TemperatureControlCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorTemperatureControl* l_pCreator = m_TemperatureControlCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindTemperatureControl%1037103433.body
}

CPIObjCreatorPowerControl* CPIObjectFactory::FindPowerControl (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindPowerControl%1037103434.body preserve=yes
	for (POSITION l_Pos=m_PowerControlCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorPowerControl* l_pCreator = m_PowerControlCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindPowerControl%1037103434.body
}

CPIObjCreatorWedgeControl* CPIObjectFactory::FindWedgeControl (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindWedgeControl%1037103435.body preserve=yes
	for (POSITION l_Pos=m_WedgeControlCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorWedgeControl* l_pCreator = m_WedgeControlCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindWedgeControl%1037103435.body
}

CPIObjCreatorEventSource* CPIObjectFactory::FindEventSource (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindEventSource%1037103436.body preserve=yes
	for (POSITION l_Pos=m_EventSourceCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorEventSource* l_pCreator = m_EventSourceCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindEventSource%1037103436.body
}

CPIObjCreatorPersistentObject* CPIObjectFactory::FindPersistentObjectManager (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindPersistentObjectManager%1037103437.body preserve=yes
	for (POSITION l_Pos=m_PersistentObjectCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorPersistentObject* l_pCreator = m_PersistentObjectCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindPersistentObjectManager%1037103437.body
}

CPIObjCreatorDiagnostics* CPIObjectFactory::FindDiagnostic (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindDiagnostic%1039609796.body preserve=yes
    for (POSITION l_Pos=m_DiagnosticCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorDiagnostics* l_pCreator = m_DiagnosticCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindDiagnostic%1039609796.body
}

CPIObjCreatorI2CSensorDS1631Z* CPIObjectFactory::FindI2CSensorDS1631Z (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindI2CSensorDS1631Z%1055313949.body preserve=yes
    for (POSITION l_Pos=m_I2CSensorDS1631ZCreators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorI2CSensorDS1631Z* l_pCreator = m_I2CSensorDS1631ZCreators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindI2CSensorDS1631Z%1055313949.body
}

CPIObjCreatorI2CEprom24LC515* CPIObjectFactory::FindI2CEprom24LC515 (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindI2CEprom24LC515%1055313950.body preserve=yes
    for (POSITION l_Pos=m_I2CEprom24LC515Creators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorI2CEprom24LC515* l_pCreator = m_I2CEprom24LC515Creators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindI2CEprom24LC515%1055313950.body
}

CPIObjCreatorI2CADCMAX1037* CPIObjectFactory::FindI2CADCMAX1037 (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindI2CADCMAX1037%1061804155.body preserve=yes
  for (POSITION l_Pos=m_I2CADCMAX1037Creators.GetHeadPosition(); l_Pos!=NULL;)
	{
        CPIObjCreatorI2CADCMAX1037* l_pCreator = m_I2CADCMAX1037Creators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindI2CADCMAX1037%1061804155.body
}

CPIObjCreatorI2CDigitalPotiAD5245* CPIObjectFactory::FindI2CDigitalPotiAD5245 (WCHAR* p_sVersion)
{
  //## begin CPIObjectFactory::FindI2CDigitalPotiAD5245%1061902074.body preserve=yes
  for (POSITION l_Pos=m_I2CDigitalPotiAD5245Creators.GetHeadPosition(); l_Pos!=NULL;)
	{
     CPIObjCreatorI2CDigitalPotiAD5245* l_pCreator = m_I2CDigitalPotiAD5245Creators.GetNext(l_Pos);
		if (l_pCreator->MatchesVersion(p_sVersion))
		{
			// creator found
			return l_pCreator;
		}
	}
    throw new XPIExceptionErrorMissingCreator(PI_ID, IDE_INVALID_OBJ_TYPE, _T(__FILE__), __LINE__, 0);

	return NULL;
  //## end CPIObjectFactory::FindI2CDigitalPotiAD5245%1061902074.body
}

void CPIObjectFactory::GetObjectStates (CStringArray& p_sObjStates)
{
  //## begin CPIObjectFactory::GetObjectStates%1063715455.body preserve=yes
    // steppers
	POSITION l_Pos;
    for (l_Pos=m_StepperList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIStepperMotorInterface* l_pMotor;
        m_StepperList.GetNextAssoc(l_Pos, l_uiKey, l_pMotor);

        CString l_sStr;
        l_sStr.Format(_T("st(%d) : %s"), l_pMotor->GetuiID(), (LPCTSTR)l_pMotor->GetsCurrentState());
        p_sObjStates.Add(l_sStr);
    }

    // measurement channels
    for (l_Pos=m_MeasurementChannelList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIMeasurementChannelInterface* l_pChannel;
        m_MeasurementChannelList.GetNextAssoc(l_Pos, l_uiKey, l_pChannel);

        CString l_sStr;
        l_sStr.Format(_T("mc(%d) : %s"), l_pChannel->GetuiID(), (LPCTSTR)l_pChannel->GetsCurrentState());
        p_sObjStates.Add(l_sStr);
    }

    // digital sensors
    for (l_Pos=m_DigitalSensorList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPISensorDigitalInterface* l_pObj;
        m_DigitalSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("ds(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // analog sensors
    for (l_Pos=m_AnalogSensorList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPISensorAnalogInterface* l_pObj;
        m_AnalogSensorList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("as(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // digital outputs
    for (l_Pos=m_DigitalOutputList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIOutputDigitalInterface* l_pObj;
        m_DigitalOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("do(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // analog outputs
    for (l_Pos=m_AnalogOutputList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIOutputAnalogInterface* l_pObj;
        m_AnalogOutputList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("ao(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // temperature controls
    for (l_Pos=m_TemperatureControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPITemperatureControlInterface* l_pObj;
        m_TemperatureControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("tc(%d) : %s"), l_pObj->GetuiID(), l_pObj->GetsCurrentState());
        p_sObjStates.Add(l_sStr);
    }

    // power controls
    for (l_Pos=m_PowerControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIPowerControlInterface* l_pObj;
        m_PowerControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("pc(%d) : %s"), l_pObj->GetuiID(), l_pObj->GetsCurrentState());
        p_sObjStates.Add(l_sStr);
    }

    // wedge controls
    for (l_Pos=m_WedgeControlList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIWedgeControlInterface* l_pObj;
        m_WedgeControlList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("wc(%d) : %s"), l_pObj->GetuiID(), l_pObj->GetsCurrentState());
        p_sObjStates.Add(l_sStr);
    }

    // event sources
    for (l_Pos=m_EventSourceList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIEventSourceInterface* l_pObj;
        m_EventSourceList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("es(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // release all persistent object managers
    for (l_Pos=m_PersistentObjList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIPersistentObjInterface* l_pObj;
        m_PersistentObjList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("po(%d) : %s"), l_pObj->GetuiID(), l_pObj->GetsCurrentState());
        p_sObjStates.Add(l_sStr);
    }

    // diagnostic channels
    for (l_Pos=m_DiagnosticObjList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPIDiagnosticInterface* l_pObj;
        m_DiagnosticObjList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("di(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // I2C Sensors DS1631Z
    for (l_Pos=m_SensorDS1631ZList.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CTempSensorDS1631Z* l_pObj;
        m_SensorDS1631ZList.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("DS1631Z(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // I2C Eproms 24LC515
    for (l_Pos=m_Eprom24LC515List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CEprom24LC515* l_pObj;
        m_Eprom24LC515List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("24LC515(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // release all I2C ADC MAX1037
    for (l_Pos=m_ADCMAX1037List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CADCMAX1037* l_pObj;
        m_ADCMAX1037List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("ADCMAX1037(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

    // release all I2C DP AD5245
    for (l_Pos=m_DigitalPotiAD5245List.GetStartPosition(); l_Pos!=NULL;)
    {
        UINT l_uiKey;
        IPII2CDigitalPotiAD5245* l_pObj;
        m_DigitalPotiAD5245List.GetNextAssoc(l_Pos, l_uiKey, l_pObj);

        CString l_sStr;
        l_sStr.Format(_T("DPAD5245(%d)"), l_pObj->GetuiID());
        p_sObjStates.Add(l_sStr);
    }

  //## end CPIObjectFactory::GetObjectStates%1063715455.body
}

void CPIObjectFactory::ReleaseCreators ()
{
  //## begin CPIObjectFactory::ReleaseCreators%1164719557.body preserve=yes
	POSITION l_Pos; //scch
    for (l_Pos=m_I2CEprom24LC515Creators.GetHeadPosition(); l_Pos!=NULL;)
    {
	    delete m_I2CEprom24LC515Creators.GetNext(l_Pos);
    }
    m_I2CEprom24LC515Creators.RemoveAll();

    for (l_Pos=m_PersistentObjectCreators.GetHeadPosition(); l_Pos!=NULL;)
    {
	    delete m_PersistentObjectCreators.GetNext(l_Pos);
    }
	m_PersistentObjectCreators.RemoveAll();
  //## end CPIObjectFactory::ReleaseCreators%1164719557.body
}

// Additional Declarations
  //## begin CPIObjectFactory%3DA52FD80189.declarations preserve=yes
  //## end CPIObjectFactory%3DA52FD80189.declarations

//## begin module%3DA52FC9037D.epilog preserve=yes
//## end module%3DA52FC9037D.epilog
