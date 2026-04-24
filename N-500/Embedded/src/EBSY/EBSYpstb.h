//## begin module%40980CB2018F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40980CB2018F.cm

//## begin module%40980CB2018F.cp preserve=no
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
//## end module%40980CB2018F.cp

//## Module: EBSYpstb%40980CB2018F; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYpstb.h

#ifndef EBSYpstb_h
#define EBSYpstb_h 1

//## begin module%40980CB2018F.additionalIncludes preserve=no
//## end module%40980CB2018F.additionalIncludes

//## begin module%40980CB2018F.includes preserve=yes
//## end module%40980CB2018F.includes

// EBSYproc
#include "EBSYproc.h"
//## begin module%40980CB2018F.declarations preserve=no
//## end module%40980CB2018F.declarations

//## begin module%40980CB2018F.additionalDeclarations preserve=yes
//## end module%40980CB2018F.additionalDeclarations


//## begin CSYStateProcessStandBy%40980BE903AD.preface preserve=yes
//## end CSYStateProcessStandBy%40980BE903AD.preface

//## Class: CSYStateProcessStandBy%40980BE903AD
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%40980F7F0245;CPIObjectFactory { -> }
//## Uses: <unnamed>%40980F9202A6;CSYStateProcessIdle { -> }
//## Uses: <unnamed>%4098112400EB;CSYStateCreated { -> }
//## Uses: <unnamed>%4098113B02CF;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%4098115203D7;CSYStateConstitutionStandBy { -> }
//## Uses: <unnamed>%409888330055;CSYSystemImplementation { -> }

class CSYStateProcessStandBy : public CSYStateProcess  //## Inherits: <unnamed>%40980CEE0290
{
  //## begin CSYStateProcessStandBy%40980BE903AD.initialDeclarations preserve=yes
  //## end CSYStateProcessStandBy%40980BE903AD.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateProcessStandBy();

    //## Destructor (generated)
      virtual ~CSYStateProcessStandBy();


    //## Other Operations (specified)
      //## Operation: GetDeviceState%1083700317
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: ResetDevice%1083700318
      //	DESCRIPTION
      //	Shutdown system
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ResetDevice (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSYStateProcessStandBy%40980BE903AD.public preserve=yes
      //## end CSYStateProcessStandBy%40980BE903AD.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateProcessStandBy%40980BE903AD.protected preserve=yes
      //## end CSYStateProcessStandBy%40980BE903AD.protected

  private:
    //## Constructors (generated)
      CSYStateProcessStandBy(const CSYStateProcessStandBy &right);

    //## Assignment Operation (generated)
      const CSYStateProcessStandBy & operator=(const CSYStateProcessStandBy &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateProcessStandBy &right) const;

      bool operator!=(const CSYStateProcessStandBy &right) const;

    // Additional Private Declarations
      //## begin CSYStateProcessStandBy%40980BE903AD.private preserve=yes
      //## end CSYStateProcessStandBy%40980BE903AD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateProcessStandBy%40980BE903AD.implementation preserve=yes
      //## end CSYStateProcessStandBy%40980BE903AD.implementation

};

//## begin CSYStateProcessStandBy%40980BE903AD.postscript preserve=yes
//## end CSYStateProcessStandBy%40980BE903AD.postscript

//## begin CSYStateProcessStandByDisconnecting%40980C760215.preface preserve=yes
//## end CSYStateProcessStandByDisconnecting%40980C760215.preface

//## Class: CSYStateProcessStandByDisconnecting%40980C760215
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYStateProcessStandByDisconnecting : public CSYStateProcessStandBy  //## Inherits: <unnamed>%40980CE50139
{
  //## begin CSYStateProcessStandByDisconnecting%40980C760215.initialDeclarations preserve=yes
  //## end CSYStateProcessStandByDisconnecting%40980C760215.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateProcessStandByDisconnecting();

    //## Destructor (generated)
      virtual ~CSYStateProcessStandByDisconnecting();


    //## Other Operations (specified)
      //## Operation: Create%1083700302
      static void Create ();

      //## Operation: Delete%1083700303
      static void Delete ();

      //## Operation: GetInstance%1083700304
      static CSYStateProcessStandByDisconnecting* GetInstance ();

      //## Operation: Do%1083700305
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
      //## begin CSYStateProcessStandByDisconnecting%40980C760215.public preserve=yes
      //## end CSYStateProcessStandByDisconnecting%40980C760215.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateProcessStandByDisconnecting%40980C760215.protected preserve=yes
      //## end CSYStateProcessStandByDisconnecting%40980C760215.protected

  private:
    //## Constructors (generated)
      CSYStateProcessStandByDisconnecting(const CSYStateProcessStandByDisconnecting &right);

    //## Assignment Operation (generated)
      const CSYStateProcessStandByDisconnecting & operator=(const CSYStateProcessStandByDisconnecting &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateProcessStandByDisconnecting &right) const;

      bool operator!=(const CSYStateProcessStandByDisconnecting &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%40980D270061
      //## Role: CSYStateProcessStandByDisconnecting::pInstance%40980D28013F
      //## begin CSYStateProcessStandByDisconnecting::pInstance%40980D28013F.role preserve=no  public: static CSYStateProcessStandByDisconnecting {1..1 -> 1..1RFHN}
      static CSYStateProcessStandByDisconnecting *m_pInstance;
      //## end CSYStateProcessStandByDisconnecting::pInstance%40980D28013F.role

    // Additional Private Declarations
      //## begin CSYStateProcessStandByDisconnecting%40980C760215.private preserve=yes
      //## end CSYStateProcessStandByDisconnecting%40980C760215.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateProcessStandByDisconnecting%40980C760215.implementation preserve=yes
      //## end CSYStateProcessStandByDisconnecting%40980C760215.implementation

};

//## begin CSYStateProcessStandByDisconnecting%40980C760215.postscript preserve=yes
//## end CSYStateProcessStandByDisconnecting%40980C760215.postscript

//## begin CSYStateProcessStandByIdle%40980C8702B0.preface preserve=yes
//## end CSYStateProcessStandByIdle%40980C8702B0.preface

//## Class: CSYStateProcessStandByIdle%40980C8702B0
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4523B37A00FF;CSYStateConstitutionUnregisteringUnits { -> }

class CSYStateProcessStandByIdle : public CSYStateProcessStandBy  //## Inherits: <unnamed>%40980CE70204
{
  //## begin CSYStateProcessStandByIdle%40980C8702B0.initialDeclarations preserve=yes
  //## end CSYStateProcessStandByIdle%40980C8702B0.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateProcessStandByIdle();

    //## Destructor (generated)
      virtual ~CSYStateProcessStandByIdle();


    //## Other Operations (specified)
      //## Operation: Create%1083700306
      static void Create ();

      //## Operation: Delete%1083700307
      static void Delete ();

      //## Operation: GetInstance%1083700308
      static CSYStateProcessStandByIdle* GetInstance ();

      //## Operation: ConnectionEstablished%1083700313
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Enter%1083737622
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

      //## Operation: Exit%1083737623
      //	DESCRIPTION
      //	Leaves a state. Place to set up flags.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Exit (ICOStateMachineContext* p_pContext);

      //## Operation: OnTimer%1083737624
      //	DESCRIPTION
      //	Notifies the subsystem of a timer event
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void OnTimer (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSYStateProcessStandByIdle%40980C8702B0.public preserve=yes
      //## end CSYStateProcessStandByIdle%40980C8702B0.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateProcessStandByIdle%40980C8702B0.protected preserve=yes
      //## end CSYStateProcessStandByIdle%40980C8702B0.protected

  private:
    //## Constructors (generated)
      CSYStateProcessStandByIdle(const CSYStateProcessStandByIdle &right);

    //## Assignment Operation (generated)
      const CSYStateProcessStandByIdle & operator=(const CSYStateProcessStandByIdle &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateProcessStandByIdle &right) const;

      bool operator!=(const CSYStateProcessStandByIdle &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%40980D3F0232
      //## Role: CSYStateProcessStandByIdle::pInstance%40980D40025D
      //## begin CSYStateProcessStandByIdle::pInstance%40980D40025D.role preserve=no  public: static CSYStateProcessStandByIdle {1..1 -> 1..1RFHN}
      static CSYStateProcessStandByIdle *m_pInstance;
      //## end CSYStateProcessStandByIdle::pInstance%40980D40025D.role

    // Additional Private Declarations
      //## begin CSYStateProcessStandByIdle%40980C8702B0.private preserve=yes
      //## end CSYStateProcessStandByIdle%40980C8702B0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateProcessStandByIdle%40980C8702B0.implementation preserve=yes
      //## end CSYStateProcessStandByIdle%40980C8702B0.implementation

};

//## begin CSYStateProcessStandByIdle%40980C8702B0.postscript preserve=yes
//## end CSYStateProcessStandByIdle%40980C8702B0.postscript

//## begin CSYStateProcessStandByConnecting%40980C9701C3.preface preserve=yes
//## end CSYStateProcessStandByConnecting%40980C9701C3.preface

//## Class: CSYStateProcessStandByConnecting%40980C9701C3
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYStateProcessStandByConnecting : public CSYStateProcessStandBy  //## Inherits: <unnamed>%40980CE902E3
{
  //## begin CSYStateProcessStandByConnecting%40980C9701C3.initialDeclarations preserve=yes
  //## end CSYStateProcessStandByConnecting%40980C9701C3.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateProcessStandByConnecting();

    //## Destructor (generated)
      virtual ~CSYStateProcessStandByConnecting();


    //## Other Operations (specified)
      //## Operation: Create%1083700309
      static void Create ();

      //## Operation: Delete%1083700310
      static void Delete ();

      //## Operation: GetInstance%1083700311
      static CSYStateProcessStandByConnecting* GetInstance ();

      //## Operation: Do%1083700312
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
      //## begin CSYStateProcessStandByConnecting%40980C9701C3.public preserve=yes
      //## end CSYStateProcessStandByConnecting%40980C9701C3.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateProcessStandByConnecting%40980C9701C3.protected preserve=yes
      //## end CSYStateProcessStandByConnecting%40980C9701C3.protected

  private:
    //## Constructors (generated)
      CSYStateProcessStandByConnecting(const CSYStateProcessStandByConnecting &right);

    //## Assignment Operation (generated)
      const CSYStateProcessStandByConnecting & operator=(const CSYStateProcessStandByConnecting &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateProcessStandByConnecting &right) const;

      bool operator!=(const CSYStateProcessStandByConnecting &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%40980D540188
      //## Role: CSYStateProcessStandByConnecting::pInstance%40980D55023E
      //## begin CSYStateProcessStandByConnecting::pInstance%40980D55023E.role preserve=no  public: static CSYStateProcessStandByConnecting {1..1 -> 1..1RFHN}
      static CSYStateProcessStandByConnecting *m_pInstance;
      //## end CSYStateProcessStandByConnecting::pInstance%40980D55023E.role

      //## Association: EBSY (System Control)::<unnamed>%40980D540188
      //## Role: CSYStateProcessStandByConnecting::<m_CSYStateProcessStandByConnecting>%40980D550234
      //## begin CSYStateProcessStandByConnecting::<m_CSYStateProcessStandByConnecting>%40980D550234.role preserve=no  public: CSYStateProcessStandByConnecting {1..1 -> 1..1RFHGN}
      CSYStateProcessStandByConnecting *m_CSYStateProcessStandByConnecting;
      //## end CSYStateProcessStandByConnecting::<m_CSYStateProcessStandByConnecting>%40980D550234.role

    // Additional Private Declarations
      //## begin CSYStateProcessStandByConnecting%40980C9701C3.private preserve=yes
      //## end CSYStateProcessStandByConnecting%40980C9701C3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateProcessStandByConnecting%40980C9701C3.implementation preserve=yes
      //## end CSYStateProcessStandByConnecting%40980C9701C3.implementation

};

//## begin CSYStateProcessStandByConnecting%40980C9701C3.postscript preserve=yes
//## end CSYStateProcessStandByConnecting%40980C9701C3.postscript

// Class CSYStateProcessStandBy 

// Class CSYStateProcessStandByDisconnecting 

// Class CSYStateProcessStandByIdle 

// Class CSYStateProcessStandByConnecting 

//## begin module%40980CB2018F.epilog preserve=yes
//## end module%40980CB2018F.epilog


#endif
