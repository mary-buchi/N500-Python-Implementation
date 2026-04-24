//## begin module%3E38FDFE00DA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E38FDFE00DA.cm

//## begin module%3E38FDFE00DA.cp preserve=no
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
//## end module%3E38FDFE00DA.cp

//## Module: EBWCinit%3E38FDFE00DA; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCinit.h

#ifndef EBWCinit_h
#define EBWCinit_h 1

//## begin module%3E38FDFE00DA.additionalIncludes preserve=no
//## end module%3E38FDFE00DA.additionalIncludes

//## begin module%3E38FDFE00DA.includes preserve=yes
//## end module%3E38FDFE00DA.includes

// EBCOsypr
#include "EBCOsypr.h"
// EBWCstat
#include "EBWCstat.h"


//## begin module%3E38FDFE00DA.declarations preserve=no
//## end module%3E38FDFE00DA.declarations

//## begin module%3E38FDFE00DA.additionalDeclarations preserve=yes
//## end module%3E38FDFE00DA.additionalDeclarations


//## begin CWCStateInitialize%3E38FD1B02CE.preface preserve=yes
//## end CWCStateInitialize%3E38FD1B02CE.preface

//## Class: CWCStateInitialize%3E38FD1B02CE
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E394CE9034B;IHIInterface { -> }
//## Uses: <unnamed>%3E394CEC003E;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E394D040261;CWCStateConfigProfile { -> }
//## Uses: <unnamed>%3E394D5202AF;CWCStateConfiguration { -> }
//## Uses: <unnamed>%3E394DFA0128;CWCStateCreated { -> }
//## Uses: <unnamed>%3E5E18E80280;WC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3E5E193F001F;XCOExceptionError { -> }
//## Uses: <unnamed>%3F60278A0232;CWCStateNotConnected { -> }
//## Uses: <unnamed>%3FBB833D037A;CWCActionInitialize { -> }
//## Uses: <unnamed>%3FCF06A702DE;XWCExceptionError { -> }
//## Uses: <unnamed>%3FD04A31036B;CWCStateEmergencyStop { -> }
//## Uses: <unnamed>%41D9435F030E;CWCStateProcess { -> }
//## Uses: <unnamed>%456EF206024A;XHIExceptionError { -> }

class CWCStateInitialize : public CWCState  //## Inherits: <unnamed>%3E38FE46005D
{
  //## begin CWCStateInitialize%3E38FD1B02CE.initialDeclarations preserve=yes
  //## end CWCStateInitialize%3E38FD1B02CE.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateInitialize();

    //## Destructor (generated)
      virtual ~CWCStateInitialize();


    //## Other Operations (specified)
      //## Operation: Startup%1066311477
      //	DESCRIPTION
      //	Brings the subsystem up to the state "WCConfigNotAssign"
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Startup (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1043917007
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: SetConfiguration%1043917050
      virtual void SetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig);

      //## Operation: CleanupStop%1053065380
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

      //## Operation: CleanupInitialize%1053065381
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

      //## Operation: ConnectionLost%1063260202
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Stop%1100615762
      virtual void Stop (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%3E394388002E
      //## Role: CWCStateInitialize::bWCInitialized%3E394388036C
      static const BOOL GetbWCInitialized ();
      static void SetbWCInitialized (BOOL value);

      //## Association: EBWC (Wedge Control)::<unnamed>%3FCB5A9B0290
      //## Role: CWCStateInitialize::bWCStartCmd%3FCB5A9C01A6
      static BOOL GetbWCStartCmd ();
      static void SetbWCStartCmd (BOOL value);

    // Additional Public Declarations
      //## begin CWCStateInitialize%3E38FD1B02CE.public preserve=yes
      //## end CWCStateInitialize%3E38FD1B02CE.public

  protected:
    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E394388002E
      //## begin CWCStateInitialize::bWCInitialized%3E394388036C.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
      static BOOL m_bWCInitialized;
      //## end CWCStateInitialize::bWCInitialized%3E394388036C.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3FCB5A9B0290
      //## begin CWCStateInitialize::bWCStartCmd%3FCB5A9C01A6.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
      static BOOL m_bWCStartCmd;
      //## end CWCStateInitialize::bWCStartCmd%3FCB5A9C01A6.role

    // Additional Protected Declarations
      //## begin CWCStateInitialize%3E38FD1B02CE.protected preserve=yes
      //## end CWCStateInitialize%3E38FD1B02CE.protected

  private:
    //## Constructors (generated)
      CWCStateInitialize(const CWCStateInitialize &right);

    //## Assignment Operation (generated)
      const CWCStateInitialize & operator=(const CWCStateInitialize &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateInitialize &right) const;

      bool operator!=(const CWCStateInitialize &right) const;

    // Additional Private Declarations
      //## begin CWCStateInitialize%3E38FD1B02CE.private preserve=yes
      //## end CWCStateInitialize%3E38FD1B02CE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateInitialize%3E38FD1B02CE.implementation preserve=yes
      //## end CWCStateInitialize%3E38FD1B02CE.implementation

};

//## begin CWCStateInitialize%3E38FD1B02CE.postscript preserve=yes
//## end CWCStateInitialize%3E38FD1B02CE.postscript

//## begin CWCStateInitializeStopped%3E3919A0002E.preface preserve=yes
//## end CWCStateInitializeStopped%3E3919A0002E.preface

//## Class: CWCStateInitializeStopped%3E3919A0002E
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4007EE0E031C;CWCWedgeControlImplementation { -> }
//## Uses: <unnamed>%400B9F0201F4;CCOSyncObjectInt { -> }

class CWCStateInitializeStopped : public CWCStateInitialize  //## Inherits: <unnamed>%3E391A1B034B
{
  //## begin CWCStateInitializeStopped%3E3919A0002E.initialDeclarations preserve=yes
  //## end CWCStateInitializeStopped%3E3919A0002E.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateInitializeStopped();

    //## Destructor (generated)
      virtual ~CWCStateInitializeStopped();


    //## Other Operations (specified)
      //## Operation: Create%1043917017
      static void Create ();

      //## Operation: Delete%1043917018
      static void Delete ();

      //## Operation: GetInstance%1043917019
      static CWCStateInitializeStopped* GetInstance ();

      //## Operation: Initialize%1052978389
      virtual void Initialize (ICOStateMachineContext* p_pContext);

      //## Operation: Referencing%1043996009
      virtual void Referencing (ICOStateMachineContext* p_pContext);

      //## Operation: Start%1070263840
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pSyncStartObj, CCOSyncObjectInt* p_pSyncExcObj);

      //## Operation: SetProfile%1104756850
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile);

      //## Operation: GetDacZeroCurrent%1149148977
      virtual void GetDacZeroCurrent (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CWCStateInitializeStopped%3E3919A0002E.public preserve=yes
      //## end CWCStateInitializeStopped%3E3919A0002E.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateInitializeStopped%3E3919A0002E.protected preserve=yes
      //## end CWCStateInitializeStopped%3E3919A0002E.protected

  private:
    //## Constructors (generated)
      CWCStateInitializeStopped(const CWCStateInitializeStopped &right);

    //## Assignment Operation (generated)
      const CWCStateInitializeStopped & operator=(const CWCStateInitializeStopped &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateInitializeStopped &right) const;

      bool operator!=(const CWCStateInitializeStopped &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E39225E0109
      //## Role: CWCStateInitializeStopped::pInstance%3E39226202A0
      //## begin CWCStateInitializeStopped::pInstance%3E39226202A0.role preserve=no  public: static CWCStateInitializeStopped {1..1 -> 1..1RFHN}
      static CWCStateInitializeStopped *m_pInstance;
      //## end CWCStateInitializeStopped::pInstance%3E39226202A0.role

    // Additional Private Declarations
      //## begin CWCStateInitializeStopped%3E3919A0002E.private preserve=yes
      //## end CWCStateInitializeStopped%3E3919A0002E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateInitializeStopped%3E3919A0002E.implementation preserve=yes
      //## end CWCStateInitializeStopped%3E3919A0002E.implementation

};

//## begin CWCStateInitializeStopped%3E3919A0002E.postscript preserve=yes
//## end CWCStateInitializeStopped%3E3919A0002E.postscript

//## begin CWCStateInitializing%3E3919C4037A.preface preserve=yes
//## end CWCStateInitializing%3E3919C4037A.preface

//## Class: CWCStateInitializing%3E3919C4037A
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateInitializing : public CWCStateInitialize  //## Inherits: <unnamed>%3E391A07033C
{
  //## begin CWCStateInitializing%3E3919C4037A.initialDeclarations preserve=yes
  //## end CWCStateInitializing%3E3919C4037A.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateInitializing();

    //## Destructor (generated)
      virtual ~CWCStateInitializing();


    //## Other Operations (specified)
      //## Operation: Create%1043917014
      static void Create ();

      //## Operation: Delete%1043917015
      static void Delete ();

      //## Operation: GetInstance%1043917016
      static CWCStateInitializing* GetInstance ();

      //## Operation: Do%1046252826
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
      //## begin CWCStateInitializing%3E3919C4037A.public preserve=yes
      //## end CWCStateInitializing%3E3919C4037A.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateInitializing%3E3919C4037A.protected preserve=yes
      //## end CWCStateInitializing%3E3919C4037A.protected

  private:
    //## Constructors (generated)
      CWCStateInitializing(const CWCStateInitializing &right);

    //## Assignment Operation (generated)
      const CWCStateInitializing & operator=(const CWCStateInitializing &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateInitializing &right) const;

      bool operator!=(const CWCStateInitializing &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E38FFD901A5
      //## Role: CWCStateInitializing::pInstance%3E38FFDD032C
      //## begin CWCStateInitializing::pInstance%3E38FFDD032C.role preserve=no  public: static CWCStateInitializing {1..1 -> 1..1RFHN}
      static CWCStateInitializing *m_pInstance;
      //## end CWCStateInitializing::pInstance%3E38FFDD032C.role

    // Additional Private Declarations
      //## begin CWCStateInitializing%3E3919C4037A.private preserve=yes
      //## end CWCStateInitializing%3E3919C4037A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateInitializing%3E3919C4037A.implementation preserve=yes
      //## end CWCStateInitializing%3E3919C4037A.implementation

};

//## begin CWCStateInitializing%3E3919C4037A.postscript preserve=yes
//## end CWCStateInitializing%3E3919C4037A.postscript

//## begin CWCStateInitializeReferencing%3E391A4200FA.preface preserve=yes
//## end CWCStateInitializeReferencing%3E391A4200FA.preface

//## Class: CWCStateInitializeReferencing%3E391A4200FA
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateInitializeReferencing : public CWCStateInitialize  //## Inherits: <unnamed>%3E391A69031C
{
  //## begin CWCStateInitializeReferencing%3E391A4200FA.initialDeclarations preserve=yes
  //## end CWCStateInitializeReferencing%3E391A4200FA.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateInitializeReferencing();

    //## Destructor (generated)
      virtual ~CWCStateInitializeReferencing();


    //## Other Operations (specified)
      //## Operation: Create%1043917020
      static void Create ();

      //## Operation: Delete%1043917021
      static void Delete ();

      //## Operation: GetInstance%1043917022
      static CWCStateInitializeReferencing* GetInstance ();

      //## Operation: Do%1046252827
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
      //## begin CWCStateInitializeReferencing%3E391A4200FA.public preserve=yes
      //## end CWCStateInitializeReferencing%3E391A4200FA.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateInitializeReferencing%3E391A4200FA.protected preserve=yes
      //## end CWCStateInitializeReferencing%3E391A4200FA.protected

  private:
    //## Constructors (generated)
      CWCStateInitializeReferencing(const CWCStateInitializeReferencing &right);

    //## Assignment Operation (generated)
      const CWCStateInitializeReferencing & operator=(const CWCStateInitializeReferencing &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateInitializeReferencing &right) const;

      bool operator!=(const CWCStateInitializeReferencing &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E3922DB006D
      //## Role: CWCStateInitializeReferencing::pInstance%3E3922DF033D
      //## begin CWCStateInitializeReferencing::pInstance%3E3922DF033D.role preserve=no  public: static CWCStateInitializeReferencing {1..1 -> 1..1RFHN}
      static CWCStateInitializeReferencing *m_pInstance;
      //## end CWCStateInitializeReferencing::pInstance%3E3922DF033D.role

    // Additional Private Declarations
      //## begin CWCStateInitializeReferencing%3E391A4200FA.private preserve=yes
      //## end CWCStateInitializeReferencing%3E391A4200FA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateInitializeReferencing%3E391A4200FA.implementation preserve=yes
      //## end CWCStateInitializeReferencing%3E391A4200FA.implementation

};

//## begin CWCStateInitializeReferencing%3E391A4200FA.postscript preserve=yes
//## end CWCStateInitializeReferencing%3E391A4200FA.postscript

// Class CWCStateInitialize 

// Class CWCStateInitializeStopped 

// Class CWCStateInitializing 

// Class CWCStateInitializeReferencing 

//## begin module%3E38FDFE00DA.epilog preserve=yes
//## end module%3E38FDFE00DA.epilog


#endif
