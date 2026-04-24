//## begin module%3E38FE07007D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E38FE07007D.cm

//## begin module%3E38FE07007D.cp preserve=no
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
//## end module%3E38FE07007D.cp

//## Module: EBWCproc%3E38FE07007D; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCproc.h

#ifndef EBWCproc_h
#define EBWCproc_h 1

//## begin module%3E38FE07007D.additionalIncludes preserve=no
//## end module%3E38FE07007D.additionalIncludes

//## begin module%3E38FE07007D.includes preserve=yes
//## end module%3E38FE07007D.includes

// EBWCstat
#include "EBWCstat.h"
//## begin module%3E38FE07007D.declarations preserve=no
//## end module%3E38FE07007D.declarations

//## begin module%3E38FE07007D.additionalDeclarations preserve=yes
//## end module%3E38FE07007D.additionalDeclarations


//## begin CWCStateProcess%3E38FD340232.preface preserve=yes
//## end CWCStateProcess%3E38FD340232.preface

//## Class: CWCStateProcess%3E38FD340232
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E3A26A400EA;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E3A26A60148;IHIInterface { -> }
//## Uses: <unnamed>%3E3A26C50177;CWCStateCreated { -> }
//## Uses: <unnamed>%3EC49C9700CB;WC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EC49CEC037A;XCOExceptionError { -> }
//## Uses: <unnamed>%3EC4EB5B000F;CWCStateConfigProfile { -> }
//## Uses: <unnamed>%3ECA1A5B01F4;CWCWedgeControlImplementation { -> }
//## Uses: <unnamed>%3F6027B80271;CWCStateNotConnected { -> }
//## Uses: <unnamed>%3FBB847A030D;CWCActionStopMeasuring { -> }
//## Uses: <unnamed>%400CD4FE0109;XHIHardwareExceptionError { -> }

class CWCStateProcess : public CWCState  //## Inherits: <unnamed>%3E38FE4C02FD
{
  //## begin CWCStateProcess%3E38FD340232.initialDeclarations preserve=yes
  //## end CWCStateProcess%3E38FD340232.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateProcess();

    //## Destructor (generated)
      virtual ~CWCStateProcess();


    //## Other Operations (specified)
      //## Operation: Shutdown%1043917003
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupStop%1053065382
      //	DESCRIPTION
      //	Recovers from a 'Stop Cleanup' exception. State machine
      //	should be broght to the 'Initialized' state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void CleanupStop (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1053065383
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

      //## Operation: ConnectionLost%1063260203
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
      //## begin CWCStateProcess%3E38FD340232.public preserve=yes
      //## end CWCStateProcess%3E38FD340232.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateProcess%3E38FD340232.protected preserve=yes
      //## end CWCStateProcess%3E38FD340232.protected

  private:
    //## Constructors (generated)
      CWCStateProcess(const CWCStateProcess &right);

    //## Assignment Operation (generated)
      const CWCStateProcess & operator=(const CWCStateProcess &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateProcess &right) const;

      bool operator!=(const CWCStateProcess &right) const;

    // Additional Private Declarations
      //## begin CWCStateProcess%3E38FD340232.private preserve=yes
      //## end CWCStateProcess%3E38FD340232.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateProcess%3E38FD340232.implementation preserve=yes
      //## end CWCStateProcess%3E38FD340232.implementation

};

//## begin CWCStateProcess%3E38FD340232.postscript preserve=yes
//## end CWCStateProcess%3E38FD340232.postscript

//## begin CWCStateProcMeasuring%3E391A87002E.preface preserve=yes
//## end CWCStateProcMeasuring%3E391A87002E.preface

//## Class: CWCStateProcMeasuring%3E391A87002E
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FD0311E005D;XWCExceptionError { -> }
//## Uses: <unnamed>%3FD04A0F00EA;CWCStateEmergencyStop { -> }

class CWCStateProcMeasuring : public CWCStateProcess  //## Inherits: <unnamed>%3E391ADE03D8
{
  //## begin CWCStateProcMeasuring%3E391A87002E.initialDeclarations preserve=yes
  //## end CWCStateProcMeasuring%3E391A87002E.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateProcMeasuring();

    //## Destructor (generated)
      virtual ~CWCStateProcMeasuring();


    //## Other Operations (specified)
      //## Operation: Create%1043917026
      static void Create ();

      //## Operation: Delete%1043917027
      static void Delete ();

      //## Operation: GetInstance%1043917028
      static CWCStateProcMeasuring* GetInstance ();

      //## Operation: Stop%1043996013
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1165065052
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1165065054
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Do%1052978394
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CWCStateProcMeasuring%3E391A87002E.public preserve=yes
      //## end CWCStateProcMeasuring%3E391A87002E.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateProcMeasuring%3E391A87002E.protected preserve=yes
      //## end CWCStateProcMeasuring%3E391A87002E.protected

  private:
    //## Constructors (generated)
      CWCStateProcMeasuring(const CWCStateProcMeasuring &right);

    //## Assignment Operation (generated)
      const CWCStateProcMeasuring & operator=(const CWCStateProcMeasuring &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateProcMeasuring &right) const;

      bool operator!=(const CWCStateProcMeasuring &right) const;

    // Data Members for Class Attributes

      //## Attribute: bIsStopCmd%419B2DF50304
      //## begin CWCStateProcMeasuring::bIsStopCmd%419B2DF50304.attr preserve=no  private: bool {U} false
      bool m_bIsStopCmd;
      //## end CWCStateProcMeasuring::bIsStopCmd%419B2DF50304.attr

      //## Attribute: bIsShutdownCmd%45717B4B0284
      //## begin CWCStateProcMeasuring::bIsShutdownCmd%45717B4B0284.attr preserve=no  private: bool {U} false
      bool m_bIsShutdownCmd;
      //## end CWCStateProcMeasuring::bIsShutdownCmd%45717B4B0284.attr

      //## Attribute: bIsConnectionLostCmd%45717EA40128
      //## begin CWCStateProcMeasuring::bIsConnectionLostCmd%45717EA40128.attr preserve=no  private: bool {U} false
      bool m_bIsConnectionLostCmd;
      //## end CWCStateProcMeasuring::bIsConnectionLostCmd%45717EA40128.attr

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E39000B006D
      //## Role: CWCStateProcMeasuring::pInstance%3E39001900CC
      //## begin CWCStateProcMeasuring::pInstance%3E39001900CC.role preserve=no  public: static CWCStateProcMeasuring {1..1 -> 1..1RFHN}
      static CWCStateProcMeasuring *m_pInstance;
      //## end CWCStateProcMeasuring::pInstance%3E39001900CC.role

    // Additional Private Declarations
      //## begin CWCStateProcMeasuring%3E391A87002E.private preserve=yes
      //## end CWCStateProcMeasuring%3E391A87002E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateProcMeasuring%3E391A87002E.implementation preserve=yes
      //## end CWCStateProcMeasuring%3E391A87002E.implementation

};

//## begin CWCStateProcMeasuring%3E391A87002E.postscript preserve=yes
//## end CWCStateProcMeasuring%3E391A87002E.postscript

//## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.preface preserve=yes
//## end CWCStateProcFollowUpMeasuring%3E391A9E004E.preface

//## Class: CWCStateProcFollowUpMeasuring%3E391A9E004E
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E3A26F20280;CWCStateInitializeReferencing { -> }

class CWCStateProcFollowUpMeasuring : public CWCStateProcess  //## Inherits: <unnamed>%3E391AEE03B9
{
  //## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.initialDeclarations preserve=yes
  //## end CWCStateProcFollowUpMeasuring%3E391A9E004E.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateProcFollowUpMeasuring();

    //## Destructor (generated)
      virtual ~CWCStateProcFollowUpMeasuring();


    //## Other Operations (specified)
      //## Operation: Create%1043917029
      static void Create ();

      //## Operation: Delete%1043917030
      static void Delete ();

      //## Operation: GetInstance%1043917031
      static CWCStateProcFollowUpMeasuring* GetInstance ();

      //## Operation: Start%1100615761
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pSyncStartObj, CCOSyncObjectInt* p_pSyncExcObj);

      //## Operation: Stop%1043996015
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1165065053
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1165065055
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Do%1053429958
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.public preserve=yes
      //## end CWCStateProcFollowUpMeasuring%3E391A9E004E.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.protected preserve=yes
      //## end CWCStateProcFollowUpMeasuring%3E391A9E004E.protected

  private:
    //## Constructors (generated)
      CWCStateProcFollowUpMeasuring(const CWCStateProcFollowUpMeasuring &right);

    //## Assignment Operation (generated)
      const CWCStateProcFollowUpMeasuring & operator=(const CWCStateProcFollowUpMeasuring &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateProcFollowUpMeasuring &right) const;

      bool operator!=(const CWCStateProcFollowUpMeasuring &right) const;

    // Data Members for Class Attributes

      //## Attribute: bIsStartCmd%419B2E0C0344
      //## begin CWCStateProcFollowUpMeasuring::bIsStartCmd%419B2E0C0344.attr preserve=no  private: bool {U} false
      bool m_bIsStartCmd;
      //## end CWCStateProcFollowUpMeasuring::bIsStartCmd%419B2E0C0344.attr

      //## Attribute: bIsStopCmd%419B37AE02A9
      //## begin CWCStateProcFollowUpMeasuring::bIsStopCmd%419B37AE02A9.attr preserve=no  private: bool {U} false
      bool m_bIsStopCmd;
      //## end CWCStateProcFollowUpMeasuring::bIsStopCmd%419B37AE02A9.attr

      //## Attribute: bIsShutdownCmd%45717B2001EC
      //## begin CWCStateProcFollowUpMeasuring::bIsShutdownCmd%45717B2001EC.attr preserve=no  private: bool {U} false
      bool m_bIsShutdownCmd;
      //## end CWCStateProcFollowUpMeasuring::bIsShutdownCmd%45717B2001EC.attr

      //## Attribute: bIsConnectionLostCmd%45717E8F027C
      //## begin CWCStateProcFollowUpMeasuring::bIsConnectionLostCmd%45717E8F027C.attr preserve=no  private: bool {U} false
      bool m_bIsConnectionLostCmd;
      //## end CWCStateProcFollowUpMeasuring::bIsConnectionLostCmd%45717E8F027C.attr

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E39246203D8
      //## Role: CWCStateProcFollowUpMeasuring::pInstance%3E39246D035C
      //## begin CWCStateProcFollowUpMeasuring::pInstance%3E39246D035C.role preserve=no  public: static CWCStateProcFollowUpMeasuring {1..1 -> 1..1RFHN}
      static CWCStateProcFollowUpMeasuring *m_pInstance;
      //## end CWCStateProcFollowUpMeasuring::pInstance%3E39246D035C.role

    // Additional Private Declarations
      //## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.private preserve=yes
      //## end CWCStateProcFollowUpMeasuring%3E391A9E004E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.implementation preserve=yes
      //## end CWCStateProcFollowUpMeasuring%3E391A9E004E.implementation

};

//## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.postscript preserve=yes
//## end CWCStateProcFollowUpMeasuring%3E391A9E004E.postscript

//## begin CWCStateProcStopping%3EC4983B00DA.preface preserve=yes
//## end CWCStateProcStopping%3EC4983B00DA.preface

//## Class: CWCStateProcStopping%3EC4983B00DA
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateProcStopping : public CWCStateProcess  //## Inherits: <unnamed>%3EC4984D02CE
{
  //## begin CWCStateProcStopping%3EC4983B00DA.initialDeclarations preserve=yes
  //## end CWCStateProcStopping%3EC4983B00DA.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateProcStopping();

    //## Destructor (generated)
      virtual ~CWCStateProcStopping();


    //## Other Operations (specified)
      //## Operation: Create%1053065368
      static void Create ();

      //## Operation: Delete%1053065369
      static void Delete ();

      //## Operation: GetInstance%1053065370
      static CWCStateProcStopping* GetInstance ();

      //## Operation: Do%1053065371
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CWCStateProcStopping%3EC4983B00DA.public preserve=yes
      //## end CWCStateProcStopping%3EC4983B00DA.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateProcStopping%3EC4983B00DA.protected preserve=yes
      //## end CWCStateProcStopping%3EC4983B00DA.protected

  private:
    //## Constructors (generated)
      CWCStateProcStopping(const CWCStateProcStopping &right);

    //## Assignment Operation (generated)
      const CWCStateProcStopping & operator=(const CWCStateProcStopping &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateProcStopping &right) const;

      bool operator!=(const CWCStateProcStopping &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3EC4990000FA
      //## Role: CWCStateProcStopping::pInstance%3EC499030272
      //## begin CWCStateProcStopping::pInstance%3EC499030272.role preserve=no  public: static CWCStateProcStopping {1..1 -> 1..1RFHN}
      static CWCStateProcStopping *m_pInstance;
      //## end CWCStateProcStopping::pInstance%3EC499030272.role

    // Additional Private Declarations
      //## begin CWCStateProcStopping%3EC4983B00DA.private preserve=yes
      //## end CWCStateProcStopping%3EC4983B00DA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateProcStopping%3EC4983B00DA.implementation preserve=yes
      //## end CWCStateProcStopping%3EC4983B00DA.implementation

};

//## begin CWCStateProcStopping%3EC4983B00DA.postscript preserve=yes
//## end CWCStateProcStopping%3EC4983B00DA.postscript

//## begin CWCStateProcStarting%419A1C280387.preface preserve=yes
//## end CWCStateProcStarting%419A1C280387.preface

//## Class: CWCStateProcStarting%419A1C280387
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateProcStarting : public CWCStateProcess  //## Inherits: <unnamed>%419A1C5303C5
{
  //## begin CWCStateProcStarting%419A1C280387.initialDeclarations preserve=yes
  //## end CWCStateProcStarting%419A1C280387.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateProcStarting();

    //## Destructor (generated)
      virtual ~CWCStateProcStarting();


    //## Other Operations (specified)
      //## Operation: Create%1100615763
      static void Create ();

      //## Operation: Delete%1100615764
      static void Delete ();

      //## Operation: GetInstance%1100615765
      static CWCStateProcStarting* GetInstance ();

      //## Operation: Do%1100615766
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CWCStateProcStarting%419A1C280387.public preserve=yes
      //## end CWCStateProcStarting%419A1C280387.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateProcStarting%419A1C280387.protected preserve=yes
      //## end CWCStateProcStarting%419A1C280387.protected

  private:
    //## Constructors (generated)
      CWCStateProcStarting(const CWCStateProcStarting &right);

    //## Assignment Operation (generated)
      const CWCStateProcStarting & operator=(const CWCStateProcStarting &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateProcStarting &right) const;

      bool operator!=(const CWCStateProcStarting &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%419A20F7023D
      //## Role: CWCStateProcStarting::pInstance%419A20F9010A
      //## begin CWCStateProcStarting::pInstance%419A20F9010A.role preserve=no  public: static CWCStateProcStarting {1..1 -> 1..1RFHN}
      static CWCStateProcStarting *m_pInstance;
      //## end CWCStateProcStarting::pInstance%419A20F9010A.role

      //## Association: EBWC (Wedge Control)::<unnamed>%419A20F7023D
      //## Role: CWCStateProcStarting::<m_CWCStateProcStarting>%419A20F90109
      //## begin CWCStateProcStarting::<m_CWCStateProcStarting>%419A20F90109.role preserve=no  public: CWCStateProcStarting {1..1 -> 1..1RFHGN}
      CWCStateProcStarting *m_CWCStateProcStarting;
      //## end CWCStateProcStarting::<m_CWCStateProcStarting>%419A20F90109.role

    // Additional Private Declarations
      //## begin CWCStateProcStarting%419A1C280387.private preserve=yes
      //## end CWCStateProcStarting%419A1C280387.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateProcStarting%419A1C280387.implementation preserve=yes
      //## end CWCStateProcStarting%419A1C280387.implementation

};

//## begin CWCStateProcStarting%419A1C280387.postscript preserve=yes
//## end CWCStateProcStarting%419A1C280387.postscript

// Class CWCStateProcess 

// Class CWCStateProcMeasuring 

// Class CWCStateProcFollowUpMeasuring 

// Class CWCStateProcStopping 

// Class CWCStateProcStarting 

//## begin module%3E38FE07007D.epilog preserve=yes
//## end module%3E38FE07007D.epilog


#endif
