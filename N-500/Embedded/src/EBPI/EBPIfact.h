//## begin module%3DA52FC200ED.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA52FC200ED.cm

//## begin module%3DA52FC200ED.cp preserve=no
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
//## end module%3DA52FC200ED.cp

//## Module: EBPIfact%3DA52FC200ED; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIfact.h

#ifndef EBPIfact_h
#define EBPIfact_h 1

//## begin module%3DA52FC200ED.additionalIncludes preserve=no
//## end module%3DA52FC200ED.additionalIncludes

//## begin module%3DA52FC200ED.includes preserve=yes
//## end module%3DA52FC200ED.includes

// EBCOintf
#include "EBCOintf.h"
// EBPIcrea
#include "EBPIcrea.h"

class EBPI_DLL_DECL IPIStepperMotorInterface;
class EBPI_DLL_DECL IPIOutputDigitalInterface;
class EBPI_DLL_DECL IPIOutputAnalogInterface;
class EBPI_DLL_DECL IPISensorDigitalInterface;
class EBPI_DLL_DECL IPISensorAnalogInterface;
class EBPI_DLL_DECL IPIPersistentObjInterface;
class EBPI_DLL_DECL IPIMeasurementChannelInterface;
class EBPI_DLL_DECL IPIEventSourceInterface;
class EBPI_DLL_DECL IPIWedgeControlInterface;
class EBPI_DLL_DECL IPIPowerControlInterface;
class EBPI_DLL_DECL IPITemperatureControlInterface;
class EBPI_DLL_DECL IPISystemInterface;
class EBPI_DLL_DECL IPII2CTempSensorDS1631Z;
class EBPI_DLL_DECL IPII2CEprom24LC515;
class EBPI_DLL_DECL IPIDiagnosticInterface;
class EBPI_DLL_DECL IPII2CADCMAX1037;
class EBPI_DLL_DECL IPII2CDigitalPotiAD5245;

//## begin module%3DA52FC200ED.declarations preserve=no
//## end module%3DA52FC200ED.declarations

//## begin module%3DA52FC200ED.additionalDeclarations preserve=yes
//## end module%3DA52FC200ED.additionalDeclarations


//## begin CPIObjectFactory%3DA52FD80189.preface preserve=yes
//## end CPIObjectFactory%3DA52FD80189.preface

//## Class: CPIObjectFactory%3DA52FD80189
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD4CFDB00F4;ICOSyncInterface { -> F}
//## Uses: <unnamed>%3EE5C4C50040;IPISystemInterface { -> F}
//## Uses: <unnamed>%3F0028ED0307;ICOAsyncInterface { -> }
//## Uses: <unnamed>%3F01391F007C;XCOException { -> }
//## Uses: <unnamed>%3F01984F016F;XPIExceptionErrorMissingCreator { -> }
//## Uses: <unnamed>%3F019AC80353;PI_IDENTIFIERS { -> }

class EBPI_DLL_DECL CPIObjectFactory 
{
  //## begin CPIObjectFactory%3DA52FD80189.initialDeclarations preserve=yes
  //## end CPIObjectFactory%3DA52FD80189.initialDeclarations

  public:
    //## Constructors (generated)
      CPIObjectFactory();

    //## Destructor (generated)
      virtual ~CPIObjectFactory();


    //## Other Operations (specified)
      //## Operation: Create%1034230435
      static void Create ();

      //## Operation: Delete%1034230436
      static void Delete ();

      //## Operation: GetInstance%1034230437
      static CPIObjectFactory* GetInstance ();

      //## Operation: SendCmdConnectionEstablished%1056963208
      void SendCmdConnectionEstablished ();

      //## Operation: SendCmdConnectionLost%1056963209
      void SendCmdConnectionLost ();

      //## Operation: SendCmdToAll%1056963207
      void SendCmdToAll (COAsyncCommandPtr p_pCommand);

      //## Operation: Reset%1056628600
      void Reset (const bool p_bIncludingCreators = true);

      //## Operation: RestartDevice%1183536493
      //	reset end release all living objects expect system,
      //	persistent object managers and eproms
      void RestartDevice (const bool p_bIncludingCreators = true);

      //## Operation: DeleteObject%1034407674
      void DeleteObject (UINT p_uiObjectID);

      //## Operation: QuerySystemInterface%1055243204
      IPISystemInterface* QuerySystemInterface ();

      //## Operation: CreateStepperMotor%1034230438
      IPIStepperMotorInterface* CreateStepperMotor (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryStepperMotor%1034329219
      IPIStepperMotorInterface* QueryStepperMotor (UINT p_uiObjectID);

      //## Operation: CreateMeasurementChannel%1034575102
      IPIMeasurementChannelInterface* CreateMeasurementChannel (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryMeasurementChannel%1034575103
      IPIMeasurementChannelInterface* QueryMeasurementChannel (UINT p_uiObjectID);

      //## Operation: CreateAnalogSensor%1037103438
      IPISensorAnalogInterface* CreateAnalogSensor (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryAnalogSensor%1037103447
      IPISensorAnalogInterface* QueryAnalogSensor (UINT p_uiObjectID);

      //## Operation: CreateAnalogOutput%1037103439
      IPIOutputAnalogInterface* CreateAnalogOutput (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryAnalogOutput%1037103448
      IPIOutputAnalogInterface* QueryAnalogOutput (UINT p_uiObjectID);

      //## Operation: CreateDigitalSensor%1037103440
      IPISensorDigitalInterface* CreateDigitalSensor (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryDigitalSensor%1037103449
      IPISensorDigitalInterface* QueryDigitalSensor (UINT p_uiObjectID);

      //## Operation: CreateDigitalOutput%1037103441
      IPIOutputDigitalInterface* CreateDigitalOutput (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryDigitalOutput%1037103450
      IPIOutputDigitalInterface* QueryDigitalOutput (UINT p_uiObjectID);

      //## Operation: CreateTemperatureControl%1037103442
      IPITemperatureControlInterface* CreateTemperatureControl (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryTemperatureControl%1037103451
      IPITemperatureControlInterface* QueryTemperatureControl (UINT p_uiObjectID);

      //## Operation: CreatePowerControl%1037103443
      IPIPowerControlInterface* CreatePowerControl (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryPowerControl%1037103452
      IPIPowerControlInterface* QueryPowerControl (UINT p_uiObjectID);

      //## Operation: CreateWedgeControl%1037103444
      IPIWedgeControlInterface* CreateWedgeControl (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryWedgeControl%1037103453
      IPIWedgeControlInterface* QueryWedgeControl (UINT p_uiObjectID);

      //## Operation: CreateEventSource%1037103445
      IPIEventSourceInterface* CreateEventSource (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryEventSource%1037103454
      IPIEventSourceInterface* QueryEventSource (UINT p_uiObjectID);

      //## Operation: CreatePersistentObjectManager%1037103446
      IPIPersistentObjInterface* CreatePersistentObjectManager (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryPersistentObjManager%1037103455
      IPIPersistentObjInterface* QueryPersistentObjManager (UINT p_uiObjectID);

      //## Operation: CreateDiagnostic%1039609793
      IPIDiagnosticInterface* CreateDiagnostic (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryDiagnostic%1039609794
      IPIDiagnosticInterface* QueryDiagnostic (UINT p_uiObjectID);

      //## Operation: QuerySensor%1037346560
      ICOSyncInterface* QuerySensor (UINT p_uiObjectID);

      //## Operation: QueryOutput%1037346561
      ICOSyncInterface* QueryOutput (UINT p_uiObjectID);

      //## Operation: CreateSensorDS1631Z%1055243218
      IPII2CTempSensorDS1631Z* CreateSensorDS1631Z (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QuerySensorDS1631Z%1055243217
      IPII2CTempSensorDS1631Z* QuerySensorDS1631Z (UINT p_uiObjectID);

      //## Operation: CreateEprom24LC515%1055313946
      IPII2CEprom24LC515* CreateEprom24LC515 (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryEprom24LC515%1055243219
      IPII2CEprom24LC515* QueryEprom24LC515 (UINT p_uiObjectID);

      //## Operation: CreateADCMAX1037%1061804152
      IPII2CADCMAX1037* CreateADCMAX1037 (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryADCMAX1037%1061804153
      IPII2CADCMAX1037* QueryADCMAX1037 (UINT p_uiObjectID);

      //## Operation: CreateDigitalPotiAD5245%1061902071
      IPII2CDigitalPotiAD5245* CreateDigitalPotiAD5245 (UINT p_uiObjectID, WCHAR* p_sObjVersion);

      //## Operation: QueryDigitalPotiAD5245%1061902072
      IPII2CDigitalPotiAD5245* QueryDigitalPotiAD5245 (UINT p_uiObjectID);

      //## Operation: RegisterSystemInterface%1055492122
      void RegisterSystemInterface (IPISystemInterface* p_pSystemInterface);

      //## Operation: RegisterCreator%1034272537
      void RegisterCreator (CPIObjCreatorStepperMotor* p_pCreator);

      //## Operation: RegisterCreator%1034575105
      void RegisterCreator (CPIObjCreatorMeasurementChannel* p_pCreator);

      //## Operation: RegisterCreator%1037084577
      void RegisterCreator (CPIObjCreatorSensorAnalog* p_pCreator);

      //## Operation: RegisterCreator%1037084578
      void RegisterCreator (CPIObjCreatorSensorDigital* p_pCreator);

      //## Operation: RegisterCreator%1037084579
      void RegisterCreator (CPIObjCreatorOutputDigital* p_pCreator);

      //## Operation: RegisterCreator%1037084580
      void RegisterCreator (CPIObjCreatorOutputAnalog* p_pCreator);

      //## Operation: RegisterCreator%1037084581
      void RegisterCreator (CPIObjCreatorWedgeControl* p_pCreator);

      //## Operation: RegisterCreator%1037084582
      void RegisterCreator (CPIObjCreatorTemperatureControl* p_pCreator);

      //## Operation: RegisterCreator%1037084583
      void RegisterCreator (CPIObjCreatorPowerControl* p_pCreator);

      //## Operation: RegisterCreator%1037084584
      void RegisterCreator (CPIObjCreatorEventSource* p_pCreator);

      //## Operation: RegisterCreator%1037084585
      void RegisterCreator (CPIObjCreatorPersistentObject* p_pCreator);

      //## Operation: RegisterCreator%1039609795
      void RegisterCreator (CPIObjCreatorDiagnostics* p_pCreator);

      //## Operation: RegisterCreator%1055313947
      void RegisterCreator (CPIObjCreatorI2CSensorDS1631Z* p_pCreator);

      //## Operation: RegisterCreator%1055313948
      void RegisterCreator (CPIObjCreatorI2CEprom24LC515* p_pCreator);

      //## Operation: RegisterCreator%1061804154
      void RegisterCreator (CPIObjCreatorI2CADCMAX1037* p_pCreator);

      //## Operation: RegisterCreator%1061902073
      void RegisterCreator (CPIObjCreatorI2CDigitalPotiAD5245* p_pCreator);

      //## Operation: GetObjectStates%1063715455
      void GetObjectStates (CStringArray& p_sObjStates);

      //## Operation: ReleaseCreators%1164719557
      //	Releases all creators from statically registered DLL's
      //	such as the PO and EPROM models
      void ReleaseCreators ();

    // Additional Public Declarations
      //## begin CPIObjectFactory%3DA52FD80189.public preserve=yes
      //## end CPIObjectFactory%3DA52FD80189.public

  protected:

    //## Other Operations (specified)
      //## Operation: FindStepperCreator%1034272544
      virtual CPIObjCreatorStepperMotor* FindStepperCreator (WCHAR* p_sVersion);

      //## Operation: FindMeasurementChannel%1034575104
      virtual CPIObjCreatorMeasurementChannel* FindMeasurementChannel (WCHAR* p_sVersion);

      //## Operation: FindDigitalSensor%1037103429
      virtual CPIObjCreatorSensorDigital* FindDigitalSensor (WCHAR* p_sVersion);

      //## Operation: FindAnalogSensor%1037103430
      virtual CPIObjCreatorSensorAnalog* FindAnalogSensor (WCHAR* p_sVersion);

      //## Operation: FindDigitalOutput%1037103431
      virtual CPIObjCreatorOutputDigital* FindDigitalOutput (WCHAR* p_sVersion);

      //## Operation: FindAnalogOutput%1037103432
      virtual CPIObjCreatorOutputAnalog* FindAnalogOutput (WCHAR* p_sVersion);

      //## Operation: FindTemperatureControl%1037103433
      virtual CPIObjCreatorTemperatureControl* FindTemperatureControl (WCHAR* p_sVersion);

      //## Operation: FindPowerControl%1037103434
      virtual CPIObjCreatorPowerControl* FindPowerControl (WCHAR* p_sVersion);

      //## Operation: FindWedgeControl%1037103435
      virtual CPIObjCreatorWedgeControl* FindWedgeControl (WCHAR* p_sVersion);

      //## Operation: FindEventSource%1037103436
      virtual CPIObjCreatorEventSource* FindEventSource (WCHAR* p_sVersion);

      //## Operation: FindPersistentObjectManager%1037103437
      virtual CPIObjCreatorPersistentObject* FindPersistentObjectManager (WCHAR* p_sVersion);

      //## Operation: FindDiagnostic%1039609796
      virtual CPIObjCreatorDiagnostics* FindDiagnostic (WCHAR* p_sVersion);

      //## Operation: FindI2CSensorDS1631Z%1055313949
      virtual CPIObjCreatorI2CSensorDS1631Z* FindI2CSensorDS1631Z (WCHAR* p_sVersion);

      //## Operation: FindI2CEprom24LC515%1055313950
      virtual CPIObjCreatorI2CEprom24LC515* FindI2CEprom24LC515 (WCHAR* p_sVersion);

      //## Operation: FindI2CADCMAX1037%1061804155
      virtual CPIObjCreatorI2CADCMAX1037* FindI2CADCMAX1037 (WCHAR* p_sVersion);

      //## Operation: FindI2CDigitalPotiAD5245%1061902074
      virtual CPIObjCreatorI2CDigitalPotiAD5245* FindI2CDigitalPotiAD5245 (WCHAR* p_sVersion);

    // Additional Protected Declarations
      //## begin CPIObjectFactory%3DA52FD80189.protected preserve=yes
      //## end CPIObjectFactory%3DA52FD80189.protected

  private:
    //## Constructors (generated)
      CPIObjectFactory(const CPIObjectFactory &right);

    //## Assignment Operation (generated)
      const CPIObjectFactory & operator=(const CPIObjectFactory &right);

    //## Equality Operations (generated)
      bool operator==(const CPIObjectFactory &right) const;

      bool operator!=(const CPIObjectFactory &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3DA52FFE0245
      //## Role: CPIObjectFactory::pInstance%3DA52FFF0275
      //## begin CPIObjectFactory::pInstance%3DA52FFF0275.role preserve=no  public: static CPIObjectFactory {1..1 -> 1..1RFHN}
      static CPIObjectFactory *m_pInstance;
      //## end CPIObjectFactory::pInstance%3DA52FFF0275.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DA533AD0245
      //## Role: CPIObjectFactory::StepperList%3DA533B0016B
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DA53575011C; UINT
      //## begin CPIObjectFactory::StepperList%3DA533B0016B.role preserve=no  public: IPIStepperMotorInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIStepperMotorInterface *, IPIStepperMotorInterface *&> m_StepperList;
      //## end CPIObjectFactory::StepperList%3DA533B0016B.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DA5C3D4027F
      //## Role: CPIObjectFactory::StepperCreators%3DA5C3D501C3
      //## begin CPIObjectFactory::StepperCreators%3DA5C3D501C3.role preserve=no  public: CPIObjCreatorStepperMotor {0 -> nRHN}
      CTypedPtrList<CPtrList, CPIObjCreatorStepperMotor*> m_StepperCreators;
      //## end CPIObjectFactory::StepperCreators%3DA5C3D501C3.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DAABB9B0265
      //## Role: CPIObjectFactory::MeasurementChannelList%3DAABB9C00CF
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DAABBC500EE; UINT
      //## begin CPIObjectFactory::MeasurementChannelList%3DAABB9C00CF.role preserve=no  public: IPIMeasurementChannelInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIMeasurementChannelInterface *, IPIMeasurementChannelInterface *&> m_MeasurementChannelList;
      //## end CPIObjectFactory::MeasurementChannelList%3DAABB9C00CF.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DAABDCF0265
      //## Role: CPIObjectFactory::MeasurementChannelCreators%3DAABDD000B1
      //## begin CPIObjectFactory::MeasurementChannelCreators%3DAABDD000B1.role preserve=no  public: CPIObjCreatorMeasurementChannel {0 -> nRHN}
      CTypedPtrList<CPtrList, CPIObjCreatorMeasurementChannel*> m_MeasurementChannelCreators;
      //## end CPIObjectFactory::MeasurementChannelCreators%3DAABDD000B1.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0DA49030B
      //## Role: CPIObjectFactory::AnalogSensorCreators%3DD0DA4A01E2
      //## begin CPIObjectFactory::AnalogSensorCreators%3DD0DA4A01E2.role preserve=no  public: CPIObjCreatorSensorAnalog {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorSensorAnalog*> m_AnalogSensorCreators;
      //## end CPIObjectFactory::AnalogSensorCreators%3DD0DA4A01E2.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0EF800155
      //## Role: CPIObjectFactory::DigitalSensorCreators%3DD0EF81003C
      //## begin CPIObjectFactory::DigitalSensorCreators%3DD0EF81003C.role preserve=no  public: CPIObjCreatorSensorDigital {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorSensorDigital*> m_DigitalSensorCreators;
      //## end CPIObjectFactory::DigitalSensorCreators%3DD0EF81003C.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0F03301E2
      //## Role: CPIObjectFactory::AnalogOutputCreators%3DD0F034009B
      //## begin CPIObjectFactory::AnalogOutputCreators%3DD0F034009B.role preserve=no  public: CPIObjCreatorOutputAnalog {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorOutputAnalog*> m_AnalogOutputCreators;
      //## end CPIObjectFactory::AnalogOutputCreators%3DD0F034009B.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0F04900D8
      //## Role: CPIObjectFactory::DigitalOutputCreators%3DD0F049033A
      //## begin CPIObjectFactory::DigitalOutputCreators%3DD0F049033A.role preserve=no  public: CPIObjCreatorOutputDigital {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorOutputDigital*> m_DigitalOutputCreators;
      //## end CPIObjectFactory::DigitalOutputCreators%3DD0F049033A.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0F060029D
      //## Role: CPIObjectFactory::TemperatureControlCreators%3DD0F0610194
      //## begin CPIObjectFactory::TemperatureControlCreators%3DD0F0610194.role preserve=no  public: CPIObjCreatorTemperatureControl {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorTemperatureControl*> m_TemperatureControlCreators;
      //## end CPIObjectFactory::TemperatureControlCreators%3DD0F0610194.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0F077008A
      //## Role: CPIObjectFactory::PowerControlCreators%3DD0F077034A
      //## begin CPIObjectFactory::PowerControlCreators%3DD0F077034A.role preserve=no  public: CPIObjCreatorPowerControl {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorPowerControl*> m_PowerControlCreators;
      //## end CPIObjectFactory::PowerControlCreators%3DD0F077034A.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0F08800C9
      //## Role: CPIObjectFactory::WedgeControlCreators%3DD0F08803E6
      //## begin CPIObjectFactory::WedgeControlCreators%3DD0F08803E6.role preserve=no  public: CPIObjCreatorWedgeControl {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorWedgeControl*> m_WedgeControlCreators;
      //## end CPIObjectFactory::WedgeControlCreators%3DD0F08803E6.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0F09B00E8
      //## Role: CPIObjectFactory::EventSourceCreators%3DD0F09C00A9
      //## begin CPIObjectFactory::EventSourceCreators%3DD0F09C00A9.role preserve=no  public: CPIObjCreatorEventSource {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorEventSource*> m_EventSourceCreators;
      //## end CPIObjectFactory::EventSourceCreators%3DD0F09C00A9.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0F0AC003C
      //## Role: CPIObjectFactory::PersistentObjectCreators%3DD0F0AC033A
      //## begin CPIObjectFactory::PersistentObjectCreators%3DD0F0AC033A.role preserve=no  public: CPIObjCreatorPersistentObject {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorPersistentObject*> m_PersistentObjectCreators;
      //## end CPIObjectFactory::PersistentObjectCreators%3DD0F0AC033A.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FA91008A
      //## Role: CPIObjectFactory::AnalogSensorList%3DD0FA910349
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FB23028E; UINT
      //## begin CPIObjectFactory::AnalogSensorList%3DD0FA910349.role preserve=no  public: IPISensorAnalogInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPISensorAnalogInterface *, IPISensorAnalogInterface *&> m_AnalogSensorList;
      //## end CPIObjectFactory::AnalogSensorList%3DD0FA910349.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FAB2009A
      //## Role: CPIObjectFactory::DigitalSensorList%3DD0FAB2025F
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FF44033A; UINT
      //## begin CPIObjectFactory::DigitalSensorList%3DD0FAB2025F.role preserve=no  public: IPISensorDigitalInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPISensorDigitalInterface *, IPISensorDigitalInterface *&> m_DigitalSensorList;
      //## end CPIObjectFactory::DigitalSensorList%3DD0FAB2025F.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FABD0211
      //## Role: CPIObjectFactory::AnalogOutputList%3DD0FABE008A
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FBAB00D8; UINT
      //## begin CPIObjectFactory::AnalogOutputList%3DD0FABE008A.role preserve=no  public: IPIOutputAnalogInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIOutputAnalogInterface *, IPIOutputAnalogInterface *&> m_AnalogOutputList;
      //## end CPIObjectFactory::AnalogOutputList%3DD0FABE008A.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FACA03B7
      //## Role: CPIObjectFactory::DigitalOutputList%3DD0FACC00A9
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FBCC032A; UINT
      //## begin CPIObjectFactory::DigitalOutputList%3DD0FACC00A9.role preserve=no  public: IPIOutputDigitalInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIOutputDigitalInterface *, IPIOutputDigitalInterface *&> m_DigitalOutputList;
      //## end CPIObjectFactory::DigitalOutputList%3DD0FACC00A9.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FAD5025F
      //## Role: CPIObjectFactory::TemperatureControlList%3DD0FAD600D8
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FBE003D6; UINT
      //## begin CPIObjectFactory::TemperatureControlList%3DD0FAD600D8.role preserve=no  public: IPITemperatureControlInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPITemperatureControlInterface *, IPITemperatureControlInterface *&> m_TemperatureControlList;
      //## end CPIObjectFactory::TemperatureControlList%3DD0FAD600D8.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FADF033A
      //## Role: CPIObjectFactory::PowerControlList%3DD0FAE001D2
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FBF80136; UINT
      //## begin CPIObjectFactory::PowerControlList%3DD0FAE001D2.role preserve=no  public: IPIPowerControlInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIPowerControlInterface *, IPIPowerControlInterface *&> m_PowerControlList;
      //## end CPIObjectFactory::PowerControlList%3DD0FAE001D2.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FAE802BD
      //## Role: CPIObjectFactory::WedgeControlList%3DD0FAE900CA
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FC130397; UINT
      //## begin CPIObjectFactory::WedgeControlList%3DD0FAE900CA.role preserve=no  public: IPIWedgeControlInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIWedgeControlInterface *, IPIWedgeControlInterface *&> m_WedgeControlList;
      //## end CPIObjectFactory::WedgeControlList%3DD0FAE900CA.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FAF2000D
      //## Role: CPIObjectFactory::EventSourceList%3DD0FAF202DC
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FC270136; UINT
      //## begin CPIObjectFactory::EventSourceList%3DD0FAF202DC.role preserve=no  public: IPIEventSourceInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIEventSourceInterface *, IPIEventSourceInterface *&> m_EventSourceList;
      //## end CPIObjectFactory::EventSourceList%3DD0FAF202DC.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DD0FAFA0155
      //## Role: CPIObjectFactory::PersistentObjList%3DD0FAFB007A
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DD0FC3A00C9; UINT
      //## begin CPIObjectFactory::PersistentObjList%3DD0FAFB007A.role preserve=no  public: IPIPersistentObjInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIPersistentObjInterface *, IPIPersistentObjInterface *&> m_PersistentObjList;
      //## end CPIObjectFactory::PersistentObjList%3DD0FAFB007A.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DF7310100A4
      //## Role: CPIObjectFactory::DiagnosticObjList%3DF7310200D3
      //## Constraints:
      //	order
      //## Qualifier: uiID%3DF7312D0288; UINT
      //## begin CPIObjectFactory::DiagnosticObjList%3DF7310200D3.role preserve=no  public: IPIDiagnosticInterface {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPIDiagnosticInterface *, IPIDiagnosticInterface *&> m_DiagnosticObjList;
      //## end CPIObjectFactory::DiagnosticObjList%3DF7310200D3.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DF731E801EC
      //## Role: CPIObjectFactory::DiagnosticCreators%3DF731E901FC
      //## begin CPIObjectFactory::DiagnosticCreators%3DF731E901FC.role preserve=no  public: CPIObjCreatorDiagnostics {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorDiagnostics*> m_DiagnosticCreators;
      //## end CPIObjectFactory::DiagnosticCreators%3DF731E901FC.role

      //## Association: EBPI (PC Interface)::<unnamed>%3EE5EF09014A
      //## Role: CPIObjectFactory::SensorDS1631ZList%3EE5EF0A00DD
      //## Constraints:
      //	order
      //## Qualifier: uiID%3EE5EF5C038C; UINT
      //## begin CPIObjectFactory::SensorDS1631ZList%3EE5EF0A00DD.role preserve=no  public: IPII2CTempSensorDS1631Z {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPII2CTempSensorDS1631Z *, IPII2CTempSensorDS1631Z *&> m_SensorDS1631ZList;
      //## end CPIObjectFactory::SensorDS1631ZList%3EE5EF0A00DD.role

      //## Association: EBPI (PC Interface)::<unnamed>%3EE5EF77036D
      //## Role: CPIObjectFactory::Eprom24LC515List%3EE5EF78037C
      //## Constraints:
      //	order
      //## Qualifier: uiID%3EE5EF9A01C7; UINT
      //## begin CPIObjectFactory::Eprom24LC515List%3EE5EF78037C.role preserve=no  public: IPII2CEprom24LC515 {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPII2CEprom24LC515 *, IPII2CEprom24LC515 *&> m_Eprom24LC515List;
      //## end CPIObjectFactory::Eprom24LC515List%3EE5EF78037C.role

      //## Association: EBPI (PC Interface)::<unnamed>%3EE6D0500269
      //## Role: CPIObjectFactory::I2CSensorDS1631ZCreators%3EE6D051022B
      //## begin CPIObjectFactory::I2CSensorDS1631ZCreators%3EE6D051022B.role preserve=no  public: CPIObjCreatorI2CSensorDS1631Z {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorI2CSensorDS1631Z*> m_I2CSensorDS1631ZCreators;
      //## end CPIObjectFactory::I2CSensorDS1631ZCreators%3EE6D051022B.role

      //## Association: EBPI (PC Interface)::<unnamed>%3EE6D09600F2
      //## Role: CPIObjectFactory::I2CEprom24LC515Creators%3EE6D0980095
      //## begin CPIObjectFactory::I2CEprom24LC515Creators%3EE6D0980095.role preserve=no  public: CPIObjCreatorI2CEprom24LC515 {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorI2CEprom24LC515*> m_I2CEprom24LC515Creators;
      //## end CPIObjectFactory::I2CEprom24LC515Creators%3EE6D0980095.role

      //## Association: EBPI (PC Interface)::<unnamed>%3EE9897F0384
      //## Role: CPIObjectFactory::pSystemInterface%3EE98980025B
      //## begin CPIObjectFactory::pSystemInterface%3EE98980025B.role preserve=no  public: IPISystemInterface {1..1 -> 1..1RFHN}
      IPISystemInterface *m_pSystemInterface;
      //## end CPIObjectFactory::pSystemInterface%3EE98980025B.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F49FC18004E
      //## Role: CPIObjectFactory::I2CADCMAX1037Creators%3F49FC1901B5
      //## begin CPIObjectFactory::I2CADCMAX1037Creators%3F49FC1901B5.role preserve=no  public: CPIObjCreatorI2CADCMAX1037 {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorI2CADCMAX1037*> m_I2CADCMAX1037Creators;
      //## end CPIObjectFactory::I2CADCMAX1037Creators%3F49FC1901B5.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F4A006103C8
      //## Role: CPIObjectFactory::ADCMAX1037List%3F4A006400FA
      //## Constraints:
      //	order
      //## Qualifier: uiID%3F4A00960148; UINT
      //## begin CPIObjectFactory::ADCMAX1037List%3F4A006400FA.role preserve=no  public: IPII2CADCMAX1037 {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPII2CADCMAX1037 *, IPII2CADCMAX1037 *&> m_ADCMAX1037List;
      //## end CPIObjectFactory::ADCMAX1037List%3F4A006400FA.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F4B57640213
      //## Role: CPIObjectFactory::I2CDigitalPotiAD5245Creators%3F4B576602CE
      //## begin CPIObjectFactory::I2CDigitalPotiAD5245Creators%3F4B576602CE.role preserve=no  public: CPIObjCreatorI2CDigitalPotiAD5245 {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIObjCreatorI2CDigitalPotiAD5245*> m_I2CDigitalPotiAD5245Creators;
      //## end CPIObjectFactory::I2CDigitalPotiAD5245Creators%3F4B576602CE.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F4B57BB02FD
      //## Role: CPIObjectFactory::DigitalPotiAD5245List%3F4B57BE002E
      //## Constraints:
      //	order
      //## Qualifier: uiID%3F4B586C02DE; UINT
      //## begin CPIObjectFactory::DigitalPotiAD5245List%3F4B57BE002E.role preserve=no  public: IPII2CDigitalPotiAD5245 {1..1 -> 1..1RFHN}
      CMap<UINT, UINT&, IPII2CDigitalPotiAD5245 *, IPII2CDigitalPotiAD5245 *&> m_DigitalPotiAD5245List;
      //## end CPIObjectFactory::DigitalPotiAD5245List%3F4B57BE002E.role

    // Additional Private Declarations
      //## begin CPIObjectFactory%3DA52FD80189.private preserve=yes
      //## end CPIObjectFactory%3DA52FD80189.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIObjectFactory%3DA52FD80189.implementation preserve=yes
      //## end CPIObjectFactory%3DA52FD80189.implementation

};

//## begin CPIObjectFactory%3DA52FD80189.postscript preserve=yes
//## end CPIObjectFactory%3DA52FD80189.postscript

// Class CPIObjectFactory 

//## begin module%3DA52FC200ED.epilog preserve=yes
//## end module%3DA52FC200ED.epilog


#endif
