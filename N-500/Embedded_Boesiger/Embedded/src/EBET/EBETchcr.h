//## begin module%3DAAAD6E0052.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAAD6E0052.cm

//## begin module%3DAAAD6E0052.cp preserve=no
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
//## end module%3DAAAD6E0052.cp

//## Module: EBETchcr%3DAAAD6E0052; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchcr.h

#ifndef EBETchcr_h
#define EBETchcr_h 1

//## begin module%3DAAAD6E0052.additionalIncludes preserve=no
//## end module%3DAAAD6E0052.additionalIncludes

//## begin module%3DAAAD6E0052.includes preserve=yes
//## end module%3DAAAD6E0052.includes

// EBETchan
#include "EBETchan.h"

class CETChannelMessage;

//## begin module%3DAAAD6E0052.declarations preserve=no
//## end module%3DAAAD6E0052.declarations

//## begin module%3DAAAD6E0052.additionalDeclarations preserve=yes
//## end module%3DAAAD6E0052.additionalDeclarations


//## begin CETChannelObjCreator%3DA2F3260378.preface preserve=yes
//## end CETChannelObjCreator%3DA2F3260378.preface

//## Class: CETChannelObjCreator%3DA2F3260378
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA53189011C;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DA543D80009;IPIStepperMotorInterface { -> }
//## Uses: <unnamed>%3DAAAE540023;CETChannelMessage { -> F}
//## Uses: <unnamed>%3DAAAE770062;CETChannelWriter { -> }
//## Uses: <unnamed>%3DD1146D0155;IPIEventSourceInterface { -> }
//## Uses: <unnamed>%3DD1146F0194;IPIMeasurementChannelInterface { -> }
//## Uses: <unnamed>%3DD114710220;IPIWedgeControlInterface { -> }
//## Uses: <unnamed>%3DD1147302DC;IPITemperatureControlInterface { -> }
//## Uses: <unnamed>%3DD1147502EB;IPIOutputAnalogInterface { -> }
//## Uses: <unnamed>%3DD11477031A;IPIOutputDigitalInterface { -> }
//## Uses: <unnamed>%3DD1147902CC;IPIPersistentObjInterface { -> }
//## Uses: <unnamed>%3DD1147B0359;IPIPowerControlInterface { -> }
//## Uses: <unnamed>%3DD1147D033A;IPISensorAnalogInterface { -> }
//## Uses: <unnamed>%3DD1147F0397;IPISensorDigitalInterface { -> }
//## Uses: <unnamed>%3DF765250027;IPIDiagnosticInterface { -> }
//## Uses: <unnamed>%4010E4D700D7;IPII2CTempSensorDS1631Z { -> }
//## Uses: <unnamed>%4010E4DD028C;IPII2CDigitalPotiAD5245 { -> }
//## Uses: <unnamed>%4010E4DF021F;IPII2CADCMAX1037 { -> }

class CETChannelObjCreator : public CETChannel  //## Inherits: <unnamed>%3DA2F33E008A
{
  //## begin CETChannelObjCreator%3DA2F3260378.initialDeclarations preserve=yes
  //## end CETChannelObjCreator%3DA2F3260378.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelObjCreator();

    //## Destructor (generated)
      virtual ~CETChannelObjCreator();

    // Additional Public Declarations
      //## begin CETChannelObjCreator%3DA2F3260378.public preserve=yes
      //## end CETChannelObjCreator%3DA2F3260378.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1034230433
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDeleteObject%1034407673
      virtual void OnDeleteObject (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateStepper%1034230434
      virtual void OnCreateStepper (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateMeasurementChannel%1034575101
      virtual void OnCreateMeasurementChannel (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateAnalogSensor%1037103457
      virtual void OnCreateAnalogSensor (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateDigitalSensor%1037103458
      virtual void OnCreateDigitalSensor (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateAnalogOutput%1037103459
      virtual void OnCreateAnalogOutput (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateDigitalOutput%1037103460
      virtual void OnCreateDigitalOutput (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateTemperatureControl%1037103461
      virtual void OnCreateTemperatureControl (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreatePowerControl%1037103462
      virtual void OnCreatePowerControl (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateWedgeControl%1037103463
      virtual void OnCreateWedgeControl (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateEventSource%1037103464
      virtual void OnCreateEventSource (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreatePersistentObjManager%1037103465
      virtual void OnCreatePersistentObjManager (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateDiagnostics%1039623391
      virtual void OnCreateDiagnostics (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateSystem%1055492120
      virtual void OnCreateSystem (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateI2CTempSensorDS1631Z%1055492121
      virtual void OnCreateI2CTempSensorDS1631Z (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnCreateI2CAdcMax1037%1074848545
      void OnCreateI2CAdcMax1037 (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnI2CDigitalPotiAD5245%1074848546
      void OnI2CDigitalPotiAD5245 (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelObjCreator%3DA2F3260378.protected preserve=yes
      //## end CETChannelObjCreator%3DA2F3260378.protected

  private:
    //## Constructors (generated)
      CETChannelObjCreator(const CETChannelObjCreator &right);

    //## Assignment Operation (generated)
      const CETChannelObjCreator & operator=(const CETChannelObjCreator &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelObjCreator &right) const;

      bool operator!=(const CETChannelObjCreator &right) const;

    // Additional Private Declarations
      //## begin CETChannelObjCreator%3DA2F3260378.private preserve=yes
      //## end CETChannelObjCreator%3DA2F3260378.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelObjCreator%3DA2F3260378.implementation preserve=yes
      //## end CETChannelObjCreator%3DA2F3260378.implementation

};

//## begin CETChannelObjCreator%3DA2F3260378.postscript preserve=yes
//## end CETChannelObjCreator%3DA2F3260378.postscript

// Class CETChannelObjCreator 

//## begin module%3DAAAD6E0052.epilog preserve=yes
//## end module%3DAAAD6E0052.epilog


#endif
