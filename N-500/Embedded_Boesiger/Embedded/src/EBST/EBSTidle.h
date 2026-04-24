//## begin module%3DA6C26303D5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA6C26303D5.cm

//## begin module%3DA6C26303D5.cp preserve=no
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
//## end module%3DA6C26303D5.cp

//## Module: EBSTidle%3DA6C26303D5; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTidle.h

#ifndef EBSTidle_h
#define EBSTidle_h 1

//## begin module%3DA6C26303D5.additionalIncludes preserve=no
//## end module%3DA6C26303D5.additionalIncludes

//## begin module%3DA6C26303D5.includes preserve=yes
//## end module%3DA6C26303D5.includes

// EBSTstat
#include "EBSTstat.h"
//## begin module%3DA6C26303D5.declarations preserve=no
//## end module%3DA6C26303D5.declarations

//## begin module%3DA6C26303D5.additionalDeclarations preserve=yes
//## end module%3DA6C26303D5.additionalDeclarations


//## begin CSTStateCreated%3DA6C2BD03C6.preface preserve=yes
//## end CSTStateCreated%3DA6C2BD03C6.preface

//## Class: CSTStateCreated%3DA6C2BD03C6
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAA6BC80198;CSTCommandGetPosition { -> }
//## Uses: <unnamed>%3E76E6B80070;ICOStateMachineContext { -> }

class CSTStateCreated : public CSTState  //## Inherits: <unnamed>%3DA6C2C7001C
{
  //## begin CSTStateCreated%3DA6C2BD03C6.initialDeclarations preserve=yes
  //## end CSTStateCreated%3DA6C2BD03C6.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateCreated();

    //## Destructor (generated)
      virtual ~CSTStateCreated();


    //## Other Operations (specified)
      //## Operation: Create%1034329216
      static void Create ();

      //## Operation: Delete%1034329217
      static void Delete ();

      //## Operation: GetInstance%1034329218
      static CSTStateCreated* GetInstance ();

      //## Operation: Startup%1034329220
      //	DESCRIPTION
      //	Brings the subsystem up to the state 'ConfigProcessModel
      //	Setup'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Startup (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1034449586
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1063223343
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1063223344
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSTStateCreated%3DA6C2BD03C6.public preserve=yes
      //## end CSTStateCreated%3DA6C2BD03C6.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateCreated%3DA6C2BD03C6.protected preserve=yes
      //## end CSTStateCreated%3DA6C2BD03C6.protected

  private:
    //## Constructors (generated)
      CSTStateCreated(const CSTStateCreated &right);

    //## Assignment Operation (generated)
      const CSTStateCreated & operator=(const CSTStateCreated &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateCreated &right) const;

      bool operator!=(const CSTStateCreated &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DA6C2D90387
      //## Role: CSTStateCreated::pInstance%3DA6C2DA02DC
      //## begin CSTStateCreated::pInstance%3DA6C2DA02DC.role preserve=no  public: static CSTStateCreated {1..1 -> 1..1RFHN}
      static CSTStateCreated *m_pInstance;
      //## end CSTStateCreated::pInstance%3DA6C2DA02DC.role

    // Additional Private Declarations
      //## begin CSTStateCreated%3DA6C2BD03C6.private preserve=yes
      //## end CSTStateCreated%3DA6C2BD03C6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateCreated%3DA6C2BD03C6.implementation preserve=yes
      //## end CSTStateCreated%3DA6C2BD03C6.implementation

};

//## begin CSTStateCreated%3DA6C2BD03C6.postscript preserve=yes
//## end CSTStateCreated%3DA6C2BD03C6.postscript

//## begin CSTStateIdle%3E71A0870118.preface preserve=yes
//## end CSTStateIdle%3E71A0870118.preface

//## Class: CSTStateIdle%3E71A0870118
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E76E6DA0013;CSTStateCreated { -> }
//## Uses: <unnamed>%3E76EFAF03BC;CSTStateMovingIncreaseSpeed { -> }
//## Uses: <unnamed>%3E82CDC502AF;CSTLimitWorkerThread { -> }
//## Uses: <unnamed>%3E8AB24B0080;CSTPositionMachine { -> }
//## Uses: <unnamed>%3E956A570139;CPIStepperMotorProfile { -> }
//## Uses: <unnamed>%3E7EE45102F8;CSTLimitSwitch { -> }
//## Uses: <unnamed>%3E7EE10D0366;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%3EF04C490061;CSTStateConfigStart { -> }
//## Uses: <unnamed>%3EF05D4C022F;CSTStateConnectionNotConnected { -> }
//## Uses: <unnamed>%3F49D481031C;CSTHardwareConnection { -> }
//## Uses: <unnamed>%3F718EF20186;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FE062650263;XSTExceptionLimit { -> }
//## Uses: <unnamed>%41516FE90129;IHIInterface { -> }
//## Uses: <unnamed>%434156EF01CC;CSTStateHomePrepare { -> }

class CSTStateIdle : public CSTState  //## Inherits: <unnamed>%3E75A0E30217
{
  //## begin CSTStateIdle%3E71A0870118.initialDeclarations preserve=yes
  //## end CSTStateIdle%3E71A0870118.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateIdle();

    //## Destructor (generated)
      virtual ~CSTStateIdle();


    //## Other Operations (specified)
      //## Operation: Shutdown%1047971035
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: GetPosition%1047904776
      virtual void GetPosition (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj);

      //## Operation: MoveAbsolute%1047904777
      virtual void MoveAbsolute (ICOStateMachineContext* p_pContext, INT p_iTargetPosition, INT p_iSearchDistance);

      //## Operation: MoveRelative%1047904778
      virtual void MoveRelative (ICOStateMachineContext* p_pContext, INT p_iTotalDistance, INT p_iSearchDistance);

      //## Operation: SetProfile%1047904779
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile);

      //## Operation: SetSpeed%1038217303
      virtual void SetSpeed (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj, UINT p_uiSpeed);

      //## Operation: LimitAdd%1047904780
      virtual void LimitAdd (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor);

      //## Operation: LimitActivate%1047904782
      virtual void LimitActivate (ICOStateMachineContext* p_pContext);

      //## Operation: LimitDeactivate%1047904783
      virtual void LimitDeactivate (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1066295284
      //	DESCRIPTION
      //	Brings the subsystem up to the state 'ConfigProcessModel
      //	Setup'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Startup (ICOStateMachineContext* p_pContext);

      //## Operation: HomeSetPosition%1047904785
      virtual void HomeSetPosition (ICOStateMachineContext* p_pContext, INT p_iPosition);

      //## Operation: LimitGetFootPrint%1047904786
      virtual void LimitGetFootPrint (ICOStateMachineContext* p_pContext, CCOSyncObjectIntArray* p_pClientSyncObj);

      //## Operation: Create%1047971032
      static void Create ();

      //## Operation: Delete%1047971033
      static void Delete ();

      //## Operation: GetInstance%1047971034
      static CSTStateIdle* GetInstance ();

      //## Operation: Do%1047971036
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: Enter%1048757601
      //	DESCRIPTION
      //	Enters into a state. Place to set some flags or init
      //	vars.
      //	Actions should be placed in the Do method.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Enter (ICOStateMachineContext* p_pContext);

      //## Operation: StopImmediately%1048771776
      virtual void StopImmediately (ICOStateMachineContext* p_pContext);

      //## Operation: Stop%1048771777
      //	returns true, if the stop sync object maybe signalled
      virtual bool Stop (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: LimitConfig%1048771779
      virtual void LimitConfig (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor);

      //## Operation: CleanupInitialize%1053438560
      //	DESCRIPTION
      //	Recovers from a 'Initialize Cleanup' exception. State
      //	machine should be broght to the 'ConfigReady' state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void CleanupInitialize (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1055922856
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Home%1069341917
      virtual void Home (ICOStateMachineContext* p_pContext, const EPIMotorPolarity p_eFastFindingDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID, CCOSyncObjectInt* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CSTStateIdle%3E71A0870118.public preserve=yes
      //## end CSTStateIdle%3E71A0870118.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateIdle%3E71A0870118.protected preserve=yes
      //## end CSTStateIdle%3E71A0870118.protected

  private:
    //## Constructors (generated)
      CSTStateIdle(const CSTStateIdle &right);

    //## Assignment Operation (generated)
      const CSTStateIdle & operator=(const CSTStateIdle &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateIdle &right) const;

      bool operator!=(const CSTStateIdle &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E76C489034B
      //## Role: CSTStateIdle::pInstance%3E76C48A0280
      //## begin CSTStateIdle::pInstance%3E76C48A0280.role preserve=no  public: static CSTStateIdle {1..1 -> 1..1RFHN}
      static CSTStateIdle *m_pInstance;
      //## end CSTStateIdle::pInstance%3E76C48A0280.role

    // Additional Private Declarations
      //## begin CSTStateIdle%3E71A0870118.private preserve=yes
      //## end CSTStateIdle%3E71A0870118.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateIdle%3E71A0870118.implementation preserve=yes
      //## end CSTStateIdle%3E71A0870118.implementation

};

//## begin CSTStateIdle%3E71A0870118.postscript preserve=yes
//## end CSTStateIdle%3E71A0870118.postscript

// Class CSTStateCreated 

// Class CSTStateIdle 

//## begin module%3DA6C26303D5.epilog preserve=yes
//## end module%3DA6C26303D5.epilog


#endif
