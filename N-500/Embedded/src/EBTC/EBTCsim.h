//## begin module%40CFFAC401C7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40CFFAC401C7.cm

//## begin module%40CFFAC401C7.cp preserve=no
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
//## end module%40CFFAC401C7.cp

//## Module: EBTCsim%40CFFAC401C7; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCsim.h

#ifndef EBTCsim_h
#define EBTCsim_h 1

//## begin module%40CFFAC401C7.additionalIncludes preserve=no
//## end module%40CFFAC401C7.additionalIncludes

//## begin module%40CFFAC401C7.includes preserve=yes
//## end module%40CFFAC401C7.includes

// EBCOthrd
#include "EBCOthrd.h"


//## begin module%40CFFAC401C7.declarations preserve=no
//## end module%40CFFAC401C7.declarations

//## begin module%40CFFAC401C7.additionalDeclarations preserve=yes
//## end module%40CFFAC401C7.additionalDeclarations


//## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.preface preserve=yes
//## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.preface

//## Class: CTCHeaterSimulatorWorkerThread%40CFFB09035E
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCHeaterSimulatorWorkerThread : public ICOThreadWork  //## Inherits: <unnamed>%40CFFB1B014A
{
  //## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.initialDeclarations preserve=yes
  //## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.initialDeclarations

  public:
    //## Constructors (generated)
      CTCHeaterSimulatorWorkerThread();

    //## Destructor (generated)
      virtual ~CTCHeaterSimulatorWorkerThread();


    //## Other Operations (specified)
      //## Operation: ThreadMain%1087372580
      virtual int ThreadMain ();

      //## Operation: HeaterOn%1087372587
      void HeaterOn (const double p_dDutyCycle);

      //## Operation: HeaterOff%1087372588
      void HeaterOff ();

      //## Operation: GetTemp%1087372589
      CCOSyncObjectInt* GetTemp ();

    // Additional Public Declarations
      //## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.public preserve=yes
      //## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.public

  protected:
    // Additional Protected Declarations
      //## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.protected preserve=yes
      //## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.protected

  private:
    //## Constructors (generated)
      CTCHeaterSimulatorWorkerThread(const CTCHeaterSimulatorWorkerThread &right);

    //## Assignment Operation (generated)
      const CTCHeaterSimulatorWorkerThread & operator=(const CTCHeaterSimulatorWorkerThread &right);

    //## Equality Operations (generated)
      bool operator==(const CTCHeaterSimulatorWorkerThread &right) const;

      bool operator!=(const CTCHeaterSimulatorWorkerThread &right) const;


    //## Other Operations (specified)
      //## Operation: IncreaseTemp%1087372583
      void IncreaseTemp ();

      //## Operation: DecreaseTemp%1087372584
      void DecreaseTemp ();

    // Data Members for Class Attributes

      //## Attribute: bHeaterOn%40D0024F0097
      //## begin CTCHeaterSimulatorWorkerThread::bHeaterOn%40D0024F0097.attr preserve=no  private: bool {U} false
      bool m_bHeaterOn;
      //## end CTCHeaterSimulatorWorkerThread::bHeaterOn%40D0024F0097.attr

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%40CFFC0D03AC
      //## Role: CTCHeaterSimulatorWorkerThread::StartEvent%40CFFC0E01F7
      //## begin CTCHeaterSimulatorWorkerThread::StartEvent%40CFFC0E01F7.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_StartEvent;
      //## end CTCHeaterSimulatorWorkerThread::StartEvent%40CFFC0E01F7.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40CFFC4801A8
      //## Role: CTCHeaterSimulatorWorkerThread::StopEvent%40CFFC490002
      //## begin CTCHeaterSimulatorWorkerThread::StopEvent%40CFFC490002.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_StopEvent;
      //## end CTCHeaterSimulatorWorkerThread::StopEvent%40CFFC490002.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40D000A3009E
      //## Role: CTCHeaterSimulatorWorkerThread::dTime%40D000A30255
      //## begin CTCHeaterSimulatorWorkerThread::dTime%40D000A30255.role preserve=no  public: double {1..1 -> 1..1VFHN}
      double m_dTime;
      //## end CTCHeaterSimulatorWorkerThread::dTime%40D000A30255.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40D003F302D9
      //## Role: CTCHeaterSimulatorWorkerThread::dActTemp%40D003F40088
      //## begin CTCHeaterSimulatorWorkerThread::dActTemp%40D003F40088.role preserve=no  public: double {1..1 -> 1..1VFHN}
      double m_dActTemp;
      //## end CTCHeaterSimulatorWorkerThread::dActTemp%40D003F40088.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40D018CB0375
      //## Role: CTCHeaterSimulatorWorkerThread::dTemp%40D018CC01DF
      //## begin CTCHeaterSimulatorWorkerThread::dTemp%40D018CC01DF.role preserve=no  public: double {1..1 -> 1..1VFHN}
      double m_dTemp;
      //## end CTCHeaterSimulatorWorkerThread::dTemp%40D018CC01DF.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40D018CE01FE
      //## Role: CTCHeaterSimulatorWorkerThread::dTempMinus1%40D018CE03B3
      //## begin CTCHeaterSimulatorWorkerThread::dTempMinus1%40D018CE03B3.role preserve=no  public: double {1..1 -> 1..1VFHN}
      double m_dTempMinus1;
      //## end CTCHeaterSimulatorWorkerThread::dTempMinus1%40D018CE03B3.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40D032AB01B0
      //## Role: CTCHeaterSimulatorWorkerThread::dDelay%40D032AC02CA
      //## begin CTCHeaterSimulatorWorkerThread::dDelay%40D032AC02CA.role preserve=no  public: double {1..1 -> 1..1VFHN}
      double m_dDelay;
      //## end CTCHeaterSimulatorWorkerThread::dDelay%40D032AC02CA.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40D04E7103E2
      //## Role: CTCHeaterSimulatorWorkerThread::dDutyCycle%40D04E7202F9
      //## begin CTCHeaterSimulatorWorkerThread::dDutyCycle%40D04E7202F9.role preserve=no  public: double {1..1 -> 1..1VFHN}
      double m_dDutyCycle;
      //## end CTCHeaterSimulatorWorkerThread::dDutyCycle%40D04E7202F9.role

    // Additional Private Declarations
      //## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.private preserve=yes
      //## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.implementation preserve=yes
      //## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.implementation

};

//## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.postscript preserve=yes
//## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.postscript

// Class CTCHeaterSimulatorWorkerThread 

//## begin module%40CFFAC401C7.epilog preserve=yes
//## end module%40CFFAC401C7.epilog


#endif
