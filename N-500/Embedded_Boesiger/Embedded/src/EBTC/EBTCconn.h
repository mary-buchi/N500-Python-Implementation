//## begin module%3EE6DFD900EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE6DFD900EA.cm

//## begin module%3EE6DFD900EA.cp preserve=no
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
//## end module%3EE6DFD900EA.cp

//## Module: EBTCconn%3EE6DFD900EA; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCconn.h

#ifndef EBTCconn_h
#define EBTCconn_h 1

//## begin module%3EE6DFD900EA.additionalIncludes preserve=no
//## end module%3EE6DFD900EA.additionalIncludes

//## begin module%3EE6DFD900EA.includes preserve=yes
//## end module%3EE6DFD900EA.includes

// EBTCstat
#include "EBTCstat.h"
//## begin module%3EE6DFD900EA.declarations preserve=no
//## end module%3EE6DFD900EA.declarations

//## begin module%3EE6DFD900EA.additionalDeclarations preserve=yes
//## end module%3EE6DFD900EA.additionalDeclarations


//## begin CTCStateNotConnected%4125B18C00B8.preface preserve=yes
//## end CTCStateNotConnected%4125B18C00B8.preface

//## Class: CTCStateNotConnected%4125B18C00B8
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%468BB95702A0;IHIInterface { -> }

class CTCStateNotConnected : public CTCState  //## Inherits: <unnamed>%3EE72056006D
{
  //## begin CTCStateNotConnected%4125B18C00B8.initialDeclarations preserve=yes
  //## end CTCStateNotConnected%4125B18C00B8.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateNotConnected();

    //## Destructor (generated)
      virtual ~CTCStateNotConnected();


    //## Other Operations (specified)
      //## Operation: Shutdown%1092990419
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1092990420
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

      //## Operation: CellUndocked%1216975791
      virtual void CellUndocked (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CTCStateNotConnected%4125B18C00B8.public preserve=yes
      //## end CTCStateNotConnected%4125B18C00B8.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateNotConnected%4125B18C00B8.protected preserve=yes
      //## end CTCStateNotConnected%4125B18C00B8.protected

  private:
    //## Constructors (generated)
      CTCStateNotConnected(const CTCStateNotConnected &right);

    //## Assignment Operation (generated)
      const CTCStateNotConnected & operator=(const CTCStateNotConnected &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateNotConnected &right) const;

      bool operator!=(const CTCStateNotConnected &right) const;

    // Additional Private Declarations
      //## begin CTCStateNotConnected%4125B18C00B8.private preserve=yes
      //## end CTCStateNotConnected%4125B18C00B8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateNotConnected%4125B18C00B8.implementation preserve=yes
      //## end CTCStateNotConnected%4125B18C00B8.implementation

};

//## begin CTCStateNotConnected%4125B18C00B8.postscript preserve=yes
//## end CTCStateNotConnected%4125B18C00B8.postscript

//## begin CTCStateNotConnectedProcess%3EE6E70F0196.preface preserve=yes
//## end CTCStateNotConnectedProcess%3EE6E70F0196.preface

//## Class: CTCStateNotConnectedProcess%3EE6E70F0196
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE819C8009E;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EE81A040041;CTCStateCreated { -> }
//## Uses: <unnamed>%3EF06F2A0219;CTCStateConfigIdle { -> }

class CTCStateNotConnectedProcess : public CTCStateNotConnected  //## Inherits: <unnamed>%4125B2150106
{
  //## begin CTCStateNotConnectedProcess%3EE6E70F0196.initialDeclarations preserve=yes
  //## end CTCStateNotConnectedProcess%3EE6E70F0196.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateNotConnectedProcess();

    //## Destructor (generated)
      virtual ~CTCStateNotConnectedProcess();


    //## Other Operations (specified)
      //## Operation: Create%1055317642
      static void Create ();

      //## Operation: GetInstance%1055317643
      static CTCStateNotConnectedProcess* GetInstance ();

      //## Operation: Delete%1055317644
      static void Delete ();

      //## Operation: ConnectionEstablished%1055317654
      void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Enter%1183536503
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

    // Additional Public Declarations
      //## begin CTCStateNotConnectedProcess%3EE6E70F0196.public preserve=yes
      //## end CTCStateNotConnectedProcess%3EE6E70F0196.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateNotConnectedProcess%3EE6E70F0196.protected preserve=yes
      //## end CTCStateNotConnectedProcess%3EE6E70F0196.protected

  private:
    //## Constructors (generated)
      CTCStateNotConnectedProcess(const CTCStateNotConnectedProcess &right);

    //## Assignment Operation (generated)
      const CTCStateNotConnectedProcess & operator=(const CTCStateNotConnectedProcess &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateNotConnectedProcess &right) const;

      bool operator!=(const CTCStateNotConnectedProcess &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3EE6E70F019D
      //## Role: CTCStateNotConnectedProcess::pInstance%3EE6E70F019F
      //## begin CTCStateNotConnectedProcess::pInstance%3EE6E70F019F.role preserve=no  public: static CTCStateNotConnectedProcess {1..1 -> 1..1RFHN}
      static CTCStateNotConnectedProcess *m_pInstance;
      //## end CTCStateNotConnectedProcess::pInstance%3EE6E70F019F.role

    // Additional Private Declarations
      //## begin CTCStateNotConnectedProcess%3EE6E70F0196.private preserve=yes
      //## end CTCStateNotConnectedProcess%3EE6E70F0196.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateNotConnectedProcess%3EE6E70F0196.implementation preserve=yes
      //## end CTCStateNotConnectedProcess%3EE6E70F0196.implementation

};

//## begin CTCStateNotConnectedProcess%3EE6E70F0196.postscript preserve=yes
//## end CTCStateNotConnectedProcess%3EE6E70F0196.postscript

//## begin CTCStateNotConnectedConfig%4125B1FC03E5.preface preserve=yes
//## end CTCStateNotConnectedConfig%4125B1FC03E5.preface

//## Class: CTCStateNotConnectedConfig%4125B1FC03E5
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateNotConnectedConfig : public CTCStateNotConnected  //## Inherits: <unnamed>%4125B2190200
{
  //## begin CTCStateNotConnectedConfig%4125B1FC03E5.initialDeclarations preserve=yes
  //## end CTCStateNotConnectedConfig%4125B1FC03E5.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateNotConnectedConfig();

    //## Destructor (generated)
      virtual ~CTCStateNotConnectedConfig();


    //## Other Operations (specified)
      //## Operation: Create%1092990421
      static void Create ();

      //## Operation: GetInstance%1092990422
      static CTCStateNotConnectedConfig* GetInstance ();

      //## Operation: Delete%1092990423
      static void Delete ();

      //## Operation: ConnectionEstablished%1092990424
      void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Enter%1183536504
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

    // Additional Public Declarations
      //## begin CTCStateNotConnectedConfig%4125B1FC03E5.public preserve=yes
      //## end CTCStateNotConnectedConfig%4125B1FC03E5.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateNotConnectedConfig%4125B1FC03E5.protected preserve=yes
      //## end CTCStateNotConnectedConfig%4125B1FC03E5.protected

  private:
    //## Constructors (generated)
      CTCStateNotConnectedConfig(const CTCStateNotConnectedConfig &right);

    //## Assignment Operation (generated)
      const CTCStateNotConnectedConfig & operator=(const CTCStateNotConnectedConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateNotConnectedConfig &right) const;

      bool operator!=(const CTCStateNotConnectedConfig &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%4125B52C03B6
      //## Role: CTCStateNotConnectedConfig::pInstance%4125B52E003C
      //## begin CTCStateNotConnectedConfig::pInstance%4125B52E003C.role preserve=no  public: static CTCStateNotConnectedConfig {1..1 -> 1..1RFHN}
      static CTCStateNotConnectedConfig *m_pInstance;
      //## end CTCStateNotConnectedConfig::pInstance%4125B52E003C.role

    // Additional Private Declarations
      //## begin CTCStateNotConnectedConfig%4125B1FC03E5.private preserve=yes
      //## end CTCStateNotConnectedConfig%4125B1FC03E5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateNotConnectedConfig%4125B1FC03E5.implementation preserve=yes
      //## end CTCStateNotConnectedConfig%4125B1FC03E5.implementation

};

//## begin CTCStateNotConnectedConfig%4125B1FC03E5.postscript preserve=yes
//## end CTCStateNotConnectedConfig%4125B1FC03E5.postscript

// Class CTCStateNotConnected 

// Class CTCStateNotConnectedProcess 

// Class CTCStateNotConnectedConfig 

//## begin module%3EE6DFD900EA.epilog preserve=yes
//## end module%3EE6DFD900EA.epilog


#endif
