//## begin module%3E538BD000EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E538BD000EA.cm

//## begin module%3E538BD000EA.cp preserve=no
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
//## end module%3E538BD000EA.cp

//## Module: EBTClogic%3E538BD000EA; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTClogic.h

#ifndef EBTClogic_h
#define EBTClogic_h 1

//## begin module%3E538BD000EA.additionalIncludes preserve=no
//## end module%3E538BD000EA.additionalIncludes

//## begin module%3E538BD000EA.includes preserve=yes
//## end module%3E538BD000EA.includes


class EBCO_DLL_DECL CCOSyncObject;
class EBPI_DLL_DECL IPII2CTempSensorDS1631Z;
class CTCTemperatureControlImplementation;
class CTCHeaterSimulatorWorkerThread;

//## begin module%3E538BD000EA.declarations preserve=no
//## end module%3E538BD000EA.declarations

//## begin module%3E538BD000EA.additionalDeclarations preserve=yes
//## end module%3E538BD000EA.additionalDeclarations


//## begin CTCLogic%3E535FA20138.preface preserve=yes
//## end CTCLogic%3E535FA20138.preface

//## Class: CTCLogic%3E535FA20138
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EEF11970280;XTCExceptionTemperatureErrorLLimit { -> }
//## Uses: <unnamed>%3EEF119A00DA;XTCExceptionTemperatureErrorULimit { -> }
//## Uses: <unnamed>%3EEF119B036A;XTCExceptionTemperatureWarningLLimit { -> }
//## Uses: <unnamed>%3EEF119E032C;XTCExceptionTemperatureWarningULimit { -> }
//## Uses: <unnamed>%3F16ACA8022C;IHIInterface { -> }
//## Uses: <unnamed>%3F4B55E700F2;CTCStateMachineEngine { -> }
//## Uses: <unnamed>%3F4B5629014F;CPIComponentsState { -> }
//## Uses: <unnamed>%40C8247502C1;IPII2CTempSensorDS1631Z { -> }
//## Uses: <unnamed>%40C824A80254;CPIObjectFactory { -> }
//## Uses: <unnamed>%40CDAE510065;CTCPid { -> }
//## Uses: <unnamed>%40D002AA0104;CTCHeaterSimulatorWorkerThread { -> }

class EBTC_DLL_DECL CTCLogic 
{
  //## begin CTCLogic%3E535FA20138.initialDeclarations preserve=yes
  //## end CTCLogic%3E535FA20138.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCLogic%1045561403
      CTCLogic (CTCTemperatureControlImplementation* p_pContext);

    //## Destructor (generated)
      virtual ~CTCLogic();


    //## Other Operations (specified)
      //## Operation: CheckTemp%1046071779
      void CheckTemp ();

      //## Operation: GetTemp%1058349232
      void GetTemp ();

      //## Operation: HeaterOn%1086854780
      void HeaterOn ();

      //## Operation: HeaterOff%1086854781
      void HeaterOff ();

      //## Operation: Init%1086959230
      void Init ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dTempAct%40CD733702C7
      double GetdTempAct ();

      //## Attribute: dDutyCycle%40CEB110030E
      double GetdDutyCycle ();
      void SetdDutyCycle (double value);

      //## Attribute: dwOn%419487960182
      DWORD GetdwOn ();
      void SetdwOn (DWORD value);

      //## Attribute: dwOff%419487B103A8
      DWORD GetdwOff ();
      void SetdwOff (DWORD value);

      //## Attribute: dwOutputID%4194B21801F6
      DWORD GetdwOutputID ();
      void SetdwOutputID (DWORD value);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBTC (Temperature Control)::<unnamed>%3E539AB50073
      //## Role: CTCLogic::pContext%3E539AB50296
      CTCTemperatureControlImplementation * GetpContext ();

      //## Association: EBTC (Temperature Control)::<unnamed>%3EEF2E530128
      //## Role: CTCLogic::pIncidentSyncObject%3EEF2E5302EE
      CCOSyncObject * GetpIncidentSyncObject ();
      void SetpIncidentSyncObject (CCOSyncObject * value);

      //## Association: EBTC (Temperature Control)::<unnamed>%40CD89900324
      //## Role: CTCLogic::eHeaterState%40CD89910130
      EPIHeaterState GeteHeaterState ();
      void SeteHeaterState (EPIHeaterState value);

    // Additional Public Declarations
      //## begin CTCLogic%3E535FA20138.public preserve=yes
      //## end CTCLogic%3E535FA20138.public

  protected:
    // Additional Protected Declarations
      //## begin CTCLogic%3E535FA20138.protected preserve=yes
      //## end CTCLogic%3E535FA20138.protected

  private:
    //## Constructors (generated)
      CTCLogic();

      CTCLogic(const CTCLogic &right);

    //## Assignment Operation (generated)
      const CTCLogic & operator=(const CTCLogic &right);

    //## Equality Operations (generated)
      bool operator==(const CTCLogic &right) const;

      bool operator!=(const CTCLogic &right) const;

    // Data Members for Class Attributes

      //## Attribute: bHardwarePresent%3F42365702D6
      //## begin CTCLogic::bHardwarePresent%3F42365702D6.attr preserve=no  private: bool {U} false
      bool m_bHardwarePresent;
      //## end CTCLogic::bHardwarePresent%3F42365702D6.attr

      //## Attribute: bHeaterOn%40C9A581022F
      //## begin CTCLogic::bHeaterOn%40C9A581022F.attr preserve=no  private: bool {U} false
      bool m_bHeaterOn;
      //## end CTCLogic::bHeaterOn%40C9A581022F.attr

      //## begin CTCLogic::dTempAct%40CD733702C7.attr preserve=no  public: double {U} 0
      double m_dTempAct;
      //## end CTCLogic::dTempAct%40CD733702C7.attr

      //## begin CTCLogic::dDutyCycle%40CEB110030E.attr preserve=no  public: double {U} 0
      double m_dDutyCycle;
      //## end CTCLogic::dDutyCycle%40CEB110030E.attr

      //## Attribute: bStartWatchErrorLimits%40D1A2A00231
      //## begin CTCLogic::bStartWatchErrorLimits%40D1A2A00231.attr preserve=no  public: bool {U} false
      bool m_bStartWatchErrorLimits;
      //## end CTCLogic::bStartWatchErrorLimits%40D1A2A00231.attr

      //## begin CTCLogic::dwOn%419487960182.attr preserve=no  public: DWORD {U} 
      DWORD m_dwOn;
      //## end CTCLogic::dwOn%419487960182.attr

      //## begin CTCLogic::dwOff%419487B103A8.attr preserve=no  public: DWORD {U} 
      DWORD m_dwOff;
      //## end CTCLogic::dwOff%419487B103A8.attr

      //## begin CTCLogic::dwOutputID%4194B21801F6.attr preserve=no  public: DWORD {U} 
      DWORD m_dwOutputID;
      //## end CTCLogic::dwOutputID%4194B21801F6.attr

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E539AB50073
      //## begin CTCLogic::pContext%3E539AB50296.role preserve=no  public: CTCTemperatureControlImplementation {1..1 -> 1..1RFHN}
      CTCTemperatureControlImplementation *m_pContext;
      //## end CTCLogic::pContext%3E539AB50296.role

      //## Association: EBTC (Temperature Control)::<unnamed>%3EEF2E530128
      //## begin CTCLogic::pIncidentSyncObject%3EEF2E5302EE.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pIncidentSyncObject;
      //## end CTCLogic::pIncidentSyncObject%3EEF2E5302EE.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40C9B79A023F
      //## Role: CTCLogic::pSensor%40C9B79B002C
      //## begin CTCLogic::pSensor%40C9B79B002C.role preserve=no  public: IPII2CTempSensorDS1631Z {1..1 -> 1..1RFHN}
      IPII2CTempSensorDS1631Z *m_pSensor;
      //## end CTCLogic::pSensor%40C9B79B002C.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40CD89900324
      //## begin CTCLogic::eHeaterState%40CD89910130.role preserve=no  public: EPIHeaterState {1..1 -> 1..1VFHN}
      EPIHeaterState m_eHeaterState;
      //## end CTCLogic::eHeaterState%40CD89910130.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40D00CC8023C
      //## Role: CTCLogic::pHeaterSimulatorWorkerThread%40D00CC900C6
      //## begin CTCLogic::pHeaterSimulatorWorkerThread%40D00CC900C6.role preserve=no  public: CTCHeaterSimulatorWorkerThread {1..1 -> 1..1RFHN}
      CTCHeaterSimulatorWorkerThread *m_pHeaterSimulatorWorkerThread;
      //## end CTCLogic::pHeaterSimulatorWorkerThread%40D00CC900C6.role

    // Additional Private Declarations
      //## begin CTCLogic%3E535FA20138.private preserve=yes
      //## end CTCLogic%3E535FA20138.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCLogic%3E535FA20138.implementation preserve=yes
      //## end CTCLogic%3E535FA20138.implementation

};

//## begin CTCLogic%3E535FA20138.postscript preserve=yes
//## end CTCLogic%3E535FA20138.postscript

// Class CTCLogic 

//## begin module%3E538BD000EA.epilog preserve=yes
//## end module%3E538BD000EA.epilog


#endif
