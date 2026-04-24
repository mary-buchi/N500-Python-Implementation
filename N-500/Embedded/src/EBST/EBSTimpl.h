//## begin module%3DA5DDF202FB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5DDF202FB.cm

//## begin module%3DA5DDF202FB.cp preserve=no
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
//## end module%3DA5DDF202FB.cp

//## Module: EBSTimpl%3DA5DDF202FB; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTimpl.h

#ifndef EBSTimpl_h
#define EBSTimpl_h 1

//## begin module%3DA5DDF202FB.additionalIncludes preserve=no
//## end module%3DA5DDF202FB.additionalIncludes

//## begin module%3DA5DDF202FB.includes preserve=yes
//## end module%3DA5DDF202FB.includes

// EBCOimpl
#include "EBCOimpl.h"
// EBCOsypr
#include "EBCOsypr.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBPI_DLL_DECL CPIStepperMotorProfile;
class EBPI_DLL_DECL CPIStepperMotorConfig;
class EBST_DLL_DECL CSTStepperMotorInterface;
class CSTLimitHandler;
class EBST_DLL_DECL CSTPositionMachine;
class CSTLogic;
class CSTHardwareConnection;

//## begin module%3DA5DDF202FB.declarations preserve=no
//## end module%3DA5DDF202FB.declarations

//## begin module%3DA5DDF202FB.additionalDeclarations preserve=yes
//## end module%3DA5DDF202FB.additionalDeclarations


//## begin CSTStepperMotorImplementation%3DA5DE12038D.preface preserve=yes
//## end CSTStepperMotorImplementation%3DA5DE12038D.preface

//## Class: CSTStepperMotorImplementation%3DA5DE12038D
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA6C0AA01F1;CSTStepperMotorInterface { -> F}
//## Uses: <unnamed>%3DA6C3C60378;CSTStateMachineEngine { -> }
//## Uses: <unnamed>%3F85128D0138;CSTPositionMachine { -> }
//## Uses: <unnamed>%3F4F6D59003E;CSTLogic { -> }
//## Uses: <unnamed>%3F532EDE0242;CSTLogic { -> }
//## Uses: <unnamed>%3FE059A201A6;XSTExceptionLimit { -> }

class EBST_DLL_DECL CSTStepperMotorImplementation : public ICOAsyncImplementation  //## Inherits: <unnamed>%3DA6BF89000D
{
  //## begin CSTStepperMotorImplementation%3DA5DE12038D.initialDeclarations preserve=yes
  //## end CSTStepperMotorImplementation%3DA5DE12038D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTStepperMotorImplementation%1034272545
      CSTStepperMotorImplementation (CSTStepperMotorInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~CSTStepperMotorImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%1034329211
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797A8100A2
      //## Role: CSTStepperMotorImplementation::pLimitHandler%3E797A820371
      CSTLimitHandler * GetpLimitHandler ();

      //## Association: EBST (Stepper Motor)::<unnamed>%3E8AA63502B3
      //## Role: CSTStepperMotorImplementation::pPositionMachine%3E8AA63600A1
      CSTPositionMachine * GetpPositionMachine ();

      //## Association: EBST (Stepper Motor)::pConfig%3F3234070350
      //## Role: CSTStepperMotorImplementation::pHwConnection%3F323408018C
      CSTHardwareConnection * GetpHwConnection ();
      void SetpHwConnection (CSTHardwareConnection * value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3F4F6ACC0399
      //## Role: CSTStepperMotorImplementation::pProfile%3F4F6ACD0262
      CPIStepperMotorProfile * GetpProfile ();
      void SetpProfile (CPIStepperMotorProfile * value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3F4F6ACF035B
      //## Role: CSTStepperMotorImplementation::pConfig%3F4F6AD001F4
      CPIStepperMotorConfig * GetpConfig ();
      void SetpConfig (CPIStepperMotorConfig * value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3F4F7183009C
      //## Role: CSTStepperMotorImplementation::pLogic%3F4F7184000F
      CSTLogic * GetpLogic ();
      void SetpLogic (CSTLogic * value);

      //## Association: EBST (Stepper Motor)::<unnamed>%472606AB0232
      //## Role: CSTStepperMotorImplementation::pHomeSyncObj%472606AC0107
      CCOSyncObjectInt * GetpHomeSyncObj ();
      void SetpHomeSyncObj (CCOSyncObjectInt * value);

      //## Association: EBST (Stepper Motor)::<unnamed>%489AB3EF01E4
      //## Role: CSTStepperMotorImplementation::pStopSyncObj%489AB3F0007D
      CCOSyncObject * GetpStopSyncObj ();
      void SetpStopSyncObj (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CSTStepperMotorImplementation%3DA5DE12038D.public preserve=yes
      //## end CSTStepperMotorImplementation%3DA5DE12038D.public

  protected:

    //## Other Operations (specified)
      //## Operation: HandleErrorException%1071666884
      //	returns true, if the given exception should be thrown
      //	out of the subsystem interface
      virtual bool HandleErrorException (XCOExceptionError* p_pException);

    // Additional Protected Declarations
      //## begin CSTStepperMotorImplementation%3DA5DE12038D.protected preserve=yes
      //## end CSTStepperMotorImplementation%3DA5DE12038D.protected

  private:
    //## Constructors (generated)
      CSTStepperMotorImplementation(const CSTStepperMotorImplementation &right);

    //## Assignment Operation (generated)
      const CSTStepperMotorImplementation & operator=(const CSTStepperMotorImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStepperMotorImplementation &right) const;

      bool operator!=(const CSTStepperMotorImplementation &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797A8100A2
      //## begin CSTStepperMotorImplementation::pLimitHandler%3E797A820371.role preserve=no  public: CSTLimitHandler {1..1 -> 1..1RFHN}
      CSTLimitHandler *m_pLimitHandler;
      //## end CSTStepperMotorImplementation::pLimitHandler%3E797A820371.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E8AA63502B3
      //## begin CSTStepperMotorImplementation::pPositionMachine%3E8AA63600A1.role preserve=no  public: CSTPositionMachine {1..1 -> 1..1RFHN}
      CSTPositionMachine *m_pPositionMachine;
      //## end CSTStepperMotorImplementation::pPositionMachine%3E8AA63600A1.role

      //## Association: EBST (Stepper Motor)::pConfig%3F3234070350
      //## begin CSTStepperMotorImplementation::pHwConnection%3F323408018C.role preserve=no  public: CSTHardwareConnection {1..1 -> 1..1RFHN}
      CSTHardwareConnection *m_pHwConnection;
      //## end CSTStepperMotorImplementation::pHwConnection%3F323408018C.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3F4F6ACC0399
      //## begin CSTStepperMotorImplementation::pProfile%3F4F6ACD0262.role preserve=no  public: CPIStepperMotorProfile {1..1 -> 1..1RFHN}
      CPIStepperMotorProfile *m_pProfile;
      //## end CSTStepperMotorImplementation::pProfile%3F4F6ACD0262.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3F4F6ACF035B
      //## begin CSTStepperMotorImplementation::pConfig%3F4F6AD001F4.role preserve=no  public: CPIStepperMotorConfig {1..1 -> 1..1RFHN}
      CPIStepperMotorConfig *m_pConfig;
      //## end CSTStepperMotorImplementation::pConfig%3F4F6AD001F4.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3F4F7183009C
      //## begin CSTStepperMotorImplementation::pLogic%3F4F7184000F.role preserve=no  public: CSTLogic {1..1 -> 1..1RFHN}
      CSTLogic *m_pLogic;
      //## end CSTStepperMotorImplementation::pLogic%3F4F7184000F.role

      //## Association: EBST (Stepper Motor)::<unnamed>%472606AB0232
      //## begin CSTStepperMotorImplementation::pHomeSyncObj%472606AC0107.role preserve=no  public: CCOSyncObjectInt {1..1 -> 1..1RHN}
      CCOSyncObjectInt *m_pHomeSyncObj;
      //## end CSTStepperMotorImplementation::pHomeSyncObj%472606AC0107.role

      //## Association: EBST (Stepper Motor)::<unnamed>%489AB3EF01E4
      //## begin CSTStepperMotorImplementation::pStopSyncObj%489AB3F0007D.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pStopSyncObj;
      //## end CSTStepperMotorImplementation::pStopSyncObj%489AB3F0007D.role

    // Additional Private Declarations
      //## begin CSTStepperMotorImplementation%3DA5DE12038D.private preserve=yes
      //## end CSTStepperMotorImplementation%3DA5DE12038D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStepperMotorImplementation%3DA5DE12038D.implementation preserve=yes
      //## end CSTStepperMotorImplementation%3DA5DE12038D.implementation

};

//## begin CSTStepperMotorImplementation%3DA5DE12038D.postscript preserve=yes
//## end CSTStepperMotorImplementation%3DA5DE12038D.postscript

// Class CSTStepperMotorImplementation 

//## begin module%3DA5DDF202FB.epilog preserve=yes
//## end module%3DA5DDF202FB.epilog


#endif
