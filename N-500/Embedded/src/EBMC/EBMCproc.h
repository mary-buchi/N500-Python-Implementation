//## begin module%3E6DD9B601F4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E6DD9B601F4.cm

//## begin module%3E6DD9B601F4.cp preserve=no
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
//## end module%3E6DD9B601F4.cp

//## Module: EBMCproc%3E6DD9B601F4; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCproc.h

#ifndef EBMCproc_h
#define EBMCproc_h 1

//## begin module%3E6DD9B601F4.additionalIncludes preserve=no
//## end module%3E6DD9B601F4.additionalIncludes

//## begin module%3E6DD9B601F4.includes preserve=yes
//## end module%3E6DD9B601F4.includes

// EBMCstat
#include "EBMCstat.h"

class EBPI_DLL_DECL CPIMeasurementChannelProfile;

//## begin module%3E6DD9B601F4.declarations preserve=no
//## end module%3E6DD9B601F4.declarations

//## begin module%3E6DD9B601F4.additionalDeclarations preserve=yes
//## end module%3E6DD9B601F4.additionalDeclarations


//## begin CMCStateProcess%3E6DDA5E01E4.preface preserve=yes
//## end CMCStateProcess%3E6DDA5E01E4.preface

//## Class: CMCStateProcess%3E6DDA5E01E4
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F602B9F0138;CMCStateNotConnected { -> }

class CMCStateProcess : public CMCState  //## Inherits: <unnamed>%3E6DDA830186
{
  //## begin CMCStateProcess%3E6DDA5E01E4.initialDeclarations preserve=yes
  //## end CMCStateProcess%3E6DDA5E01E4.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateProcess();

    //## Destructor (generated)
      virtual ~CMCStateProcess();


    //## Other Operations (specified)
      //## Operation: Shutdown%1047364714
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1063260200
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1063717516
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

      //## Operation: CleanupStop%1080293048
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

      //## Operation: CleanupInitialize%1080293049
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

    // Additional Public Declarations
      //## begin CMCStateProcess%3E6DDA5E01E4.public preserve=yes
      //## end CMCStateProcess%3E6DDA5E01E4.public

  protected:
    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3E6DDFFF0196
      //## Role: CMCStateProcess::bMCInitialized%3E6DDFFF036C
      //## begin CMCStateProcess::bMCInitialized%3E6DDFFF036C.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
      static BOOL m_bMCInitialized;
      //## end CMCStateProcess::bMCInitialized%3E6DDFFF036C.role

    // Additional Protected Declarations
      //## begin CMCStateProcess%3E6DDA5E01E4.protected preserve=yes
      //## end CMCStateProcess%3E6DDA5E01E4.protected

  private:
    //## Constructors (generated)
      CMCStateProcess(const CMCStateProcess &right);

    //## Assignment Operation (generated)
      const CMCStateProcess & operator=(const CMCStateProcess &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateProcess &right) const;

      bool operator!=(const CMCStateProcess &right) const;

    // Additional Private Declarations
      //## begin CMCStateProcess%3E6DDA5E01E4.private preserve=yes
      //## end CMCStateProcess%3E6DDA5E01E4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateProcess%3E6DDA5E01E4.implementation preserve=yes
      //## end CMCStateProcess%3E6DDA5E01E4.implementation

};

//## begin CMCStateProcess%3E6DDA5E01E4.postscript preserve=yes
//## end CMCStateProcess%3E6DDA5E01E4.postscript

//## begin CMCStateProfileNotAssign%3E6DD9860290.preface preserve=yes
//## end CMCStateProfileNotAssign%3E6DD9860290.preface

//## Class: CMCStateProfileNotAssign%3E6DD9860290
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E6DED1A0000;CHIMCParameter { -> }
//## Uses: <unnamed>%3E6DF4B40186;ICOStateMachineContext { -> }

class CMCStateProfileNotAssign : public CMCStateProcess  //## Inherits: <unnamed>%3E6DD9DA0203
{
  //## begin CMCStateProfileNotAssign%3E6DD9860290.initialDeclarations preserve=yes
  //## end CMCStateProfileNotAssign%3E6DD9860290.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateProfileNotAssign();

    //## Destructor (generated)
      virtual ~CMCStateProfileNotAssign();


    //## Other Operations (specified)
      //## Operation: Delete%1047364721
      static void Delete ();

      //## Operation: Create%1047364722
      static void Create ();

      //## Operation: GetInstance%1047364723
      static CMCStateProfileNotAssign* GetInstance ();

      //## Operation: SetProfile%1047364713
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile);

    // Additional Public Declarations
      //## begin CMCStateProfileNotAssign%3E6DD9860290.public preserve=yes
      //## end CMCStateProfileNotAssign%3E6DD9860290.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateProfileNotAssign%3E6DD9860290.protected preserve=yes
      //## end CMCStateProfileNotAssign%3E6DD9860290.protected

  private:
    //## Constructors (generated)
      CMCStateProfileNotAssign(const CMCStateProfileNotAssign &right);

    //## Assignment Operation (generated)
      const CMCStateProfileNotAssign & operator=(const CMCStateProfileNotAssign &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateProfileNotAssign &right) const;

      bool operator!=(const CMCStateProfileNotAssign &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3E6DDC5902FD
      //## Role: CMCStateProfileNotAssign::pInstance%3E6DDC5B02CF
      //## begin CMCStateProfileNotAssign::pInstance%3E6DDC5B02CF.role preserve=no  public: static CMCStateProfileNotAssign {1..1 -> 1..1RFHN}
      static CMCStateProfileNotAssign *m_pInstance;
      //## end CMCStateProfileNotAssign::pInstance%3E6DDC5B02CF.role

    // Additional Private Declarations
      //## begin CMCStateProfileNotAssign%3E6DD9860290.private preserve=yes
      //## end CMCStateProfileNotAssign%3E6DD9860290.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateProfileNotAssign%3E6DD9860290.implementation preserve=yes
      //## end CMCStateProfileNotAssign%3E6DD9860290.implementation

};

//## begin CMCStateProfileNotAssign%3E6DD9860290.postscript preserve=yes
//## end CMCStateProfileNotAssign%3E6DD9860290.postscript

//## begin CMCStateProfile%3E6DDAF7000F.preface preserve=yes
//## end CMCStateProfile%3E6DDAF7000F.preface

//## Class: CMCStateProfile%3E6DDAF7000F
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCStateProfile : public CMCStateProcess  //## Inherits: <unnamed>%3E6DDB4E0251
{
  //## begin CMCStateProfile%3E6DDAF7000F.initialDeclarations preserve=yes
  //## end CMCStateProfile%3E6DDAF7000F.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateProfile();

    //## Destructor (generated)
      virtual ~CMCStateProfile();


    //## Other Operations (specified)
      //## Operation: Delete%1047364724
      static void Delete ();

      //## Operation: Create%1047364725
      static void Create ();

      //## Operation: GetInstance%1047364726
      static CMCStateProfile* GetInstance ();

      //## Operation: Initialize%1047364715
      virtual void Initialize (ICOStateMachineContext* p_pContext);

      //## Operation: Do%1085646424
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBMC (Measurement Channel)::<unnamed>%40B5A9E5038A
      //## Role: CMCStateProfile::pProfile%40B5A9E602B0
      void SetpProfile (CPIMeasurementChannelProfile * value);

    // Additional Public Declarations
      //## begin CMCStateProfile%3E6DDAF7000F.public preserve=yes
      //## end CMCStateProfile%3E6DDAF7000F.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateProfile%3E6DDAF7000F.protected preserve=yes
      //## end CMCStateProfile%3E6DDAF7000F.protected

  private:
    //## Constructors (generated)
      CMCStateProfile(const CMCStateProfile &right);

    //## Assignment Operation (generated)
      const CMCStateProfile & operator=(const CMCStateProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateProfile &right) const;

      bool operator!=(const CMCStateProfile &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3E6DDC8A035B
      //## Role: CMCStateProfile::pInstance%3E6DDC8E0243
      //## begin CMCStateProfile::pInstance%3E6DDC8E0243.role preserve=no  public: static CMCStateProfile {1..1 -> 1..1RFHN}
      static CMCStateProfile *m_pInstance;
      //## end CMCStateProfile::pInstance%3E6DDC8E0243.role

      //## Association: EBMC (Measurement Channel)::<unnamed>%40B5A9E5038A
      //## begin CMCStateProfile::pProfile%40B5A9E602B0.role preserve=no  public: CPIMeasurementChannelProfile {1..1 -> 1..1RFHN}
      CPIMeasurementChannelProfile *m_pProfile;
      //## end CMCStateProfile::pProfile%40B5A9E602B0.role

    // Additional Private Declarations
      //## begin CMCStateProfile%3E6DDAF7000F.private preserve=yes
      //## end CMCStateProfile%3E6DDAF7000F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateProfile%3E6DDAF7000F.implementation preserve=yes
      //## end CMCStateProfile%3E6DDAF7000F.implementation

};

//## begin CMCStateProfile%3E6DDAF7000F.postscript preserve=yes
//## end CMCStateProfile%3E6DDAF7000F.postscript

//## begin CMCStateInitialized%3E6DDB090251.preface preserve=yes
//## end CMCStateInitialized%3E6DDB090251.preface

//## Class: CMCStateInitialized%3E6DDB090251
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E6DF7C801B5;CMCStateDataAcquistionReady { -> }
//## Uses: <unnamed>%3E884BE6001F;IHIInterface { -> }
//## Uses: <unnamed>%3EB0D816007D;CMCStateCreated { -> }
//## Uses: <unnamed>%3F9788FE016A;CMCMeasurementChannelImplementation { -> }
//## Uses: <unnamed>%3FA1363E007D;CMCCtrlSimulation { -> }

class CMCStateInitialized : public CMCStateProcess  //## Inherits: <unnamed>%3E6DDB570000
{
  //## begin CMCStateInitialized%3E6DDB090251.initialDeclarations preserve=yes
  //## end CMCStateInitialized%3E6DDB090251.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateInitialized();

    //## Destructor (generated)
      virtual ~CMCStateInitialized();


    //## Other Operations (specified)
      //## Operation: Delete%1047364727
      static void Delete ();

      //## Operation: Create%1047364728
      static void Create ();

      //## Operation: GetInstance%1047364729
      static CMCStateInitialized* GetInstance ();

      //## Operation: Start%1047364717
      virtual void Start (ICOStateMachineContext* p_pContext, UINT p_uiCycleID);

      //## Operation: SetProfile%1047364718
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile);

      //## Operation: Enter%1067518846
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

      //## Operation: Initialize%1131608383
      virtual void Initialize (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CMCStateInitialized%3E6DDB090251.public preserve=yes
      //## end CMCStateInitialized%3E6DDB090251.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateInitialized%3E6DDB090251.protected preserve=yes
      //## end CMCStateInitialized%3E6DDB090251.protected

  private:
    //## Constructors (generated)
      CMCStateInitialized(const CMCStateInitialized &right);

    //## Assignment Operation (generated)
      const CMCStateInitialized & operator=(const CMCStateInitialized &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateInitialized &right) const;

      bool operator!=(const CMCStateInitialized &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3E6DDC9B002E
      //## Role: CMCStateInitialized::pInstance%3E6DDC9E02DF
      //## begin CMCStateInitialized::pInstance%3E6DDC9E02DF.role preserve=no  public: static CMCStateInitialized {1..1 -> 1..1RFHN}
      static CMCStateInitialized *m_pInstance;
      //## end CMCStateInitialized::pInstance%3E6DDC9E02DF.role

    // Additional Private Declarations
      //## begin CMCStateInitialized%3E6DDB090251.private preserve=yes
      //## end CMCStateInitialized%3E6DDB090251.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateInitialized%3E6DDB090251.implementation preserve=yes
      //## end CMCStateInitialized%3E6DDB090251.implementation

};

//## begin CMCStateInitialized%3E6DDB090251.postscript preserve=yes
//## end CMCStateInitialized%3E6DDB090251.postscript

//## begin CMCStateInitializing%3FA134A4005D.preface preserve=yes
//## end CMCStateInitializing%3FA134A4005D.preface

//## Class: CMCStateInitializing%3FA134A4005D
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCStateInitializing : public CMCStateProcess  //## Inherits: <unnamed>%3FA134F802FD
{
  //## begin CMCStateInitializing%3FA134A4005D.initialDeclarations preserve=yes
  //## end CMCStateInitializing%3FA134A4005D.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateInitializing();

    //## Destructor (generated)
      virtual ~CMCStateInitializing();


    //## Other Operations (specified)
      //## Operation: Delete%1067518842
      static void Delete ();

      //## Operation: Create%1067518843
      static void Create ();

      //## Operation: GetInstance%1067518844
      static CMCStateInitializing* GetInstance ();

      //## Operation: Do%1067518845
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
      //## begin CMCStateInitializing%3FA134A4005D.public preserve=yes
      //## end CMCStateInitializing%3FA134A4005D.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateInitializing%3FA134A4005D.protected preserve=yes
      //## end CMCStateInitializing%3FA134A4005D.protected

  private:
    //## Constructors (generated)
      CMCStateInitializing(const CMCStateInitializing &right);

    //## Assignment Operation (generated)
      const CMCStateInitializing & operator=(const CMCStateInitializing &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateInitializing &right) const;

      bool operator!=(const CMCStateInitializing &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3FA134D00222
      //## Role: CMCStateInitializing::pInstance%3FA134D1029F
      //## begin CMCStateInitializing::pInstance%3FA134D1029F.role preserve=no  public: static CMCStateInitializing {1..1 -> 1..1RFHN}
      static CMCStateInitializing *m_pInstance;
      //## end CMCStateInitializing::pInstance%3FA134D1029F.role

    // Additional Private Declarations
      //## begin CMCStateInitializing%3FA134A4005D.private preserve=yes
      //## end CMCStateInitializing%3FA134A4005D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateInitializing%3FA134A4005D.implementation preserve=yes
      //## end CMCStateInitializing%3FA134A4005D.implementation

};

//## begin CMCStateInitializing%3FA134A4005D.postscript preserve=yes
//## end CMCStateInitializing%3FA134A4005D.postscript

// Class CMCStateProcess 

// Class CMCStateProfileNotAssign 

// Class CMCStateProfile 

// Class CMCStateInitialized 

// Class CMCStateInitializing 

//## begin module%3E6DD9B601F4.epilog preserve=yes
//## end module%3E6DD9B601F4.epilog


#endif
