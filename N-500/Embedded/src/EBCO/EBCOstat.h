//## begin module%3B9146FF0231.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9146FF0231.cm

//## begin module%3B9146FF0231.cp preserve=no
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
//## end module%3B9146FF0231.cp

//## Module: EBCOstat%3B9146FF0231; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOstat.h

#ifndef EBCOstat_h
#define EBCOstat_h 1

//## begin module%3B9146FF0231.additionalIncludes preserve=no
//## end module%3B9146FF0231.additionalIncludes

//## begin module%3B9146FF0231.includes preserve=yes
//## end module%3B9146FF0231.includes


class EBCO_DLL_DECL ICOStateMachineContext;

//## begin module%3B9146FF0231.declarations preserve=no
//## end module%3B9146FF0231.declarations

//## begin module%3B9146FF0231.additionalDeclarations preserve=yes
//## end module%3B9146FF0231.additionalDeclarations


//## begin CCOState%3B9281FC00F2.preface preserve=yes
//## end CCOState%3B9281FC00F2.preface

//## Class: CCOState%3B9281FC00F2
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B9BDCA6024A; { -> }
//## Uses: <unnamed>%3B9BDCB40308;XCOExceptionInvalidState { -> }
//## Uses: <unnamed>%3DA6938A0107;CO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DA6AF0C01A3;ICOStateMachineContext { -> F}

class EBCO_DLL_DECL CCOState 
{
  //## begin CCOState%3B9281FC00F2.initialDeclarations preserve=yes
  //## end CCOState%3B9281FC00F2.initialDeclarations

  public:
    //## Constructors (generated)
      CCOState();

    //## Destructor (generated)
      virtual ~CCOState();


    //## Other Operations (specified)
      //## Operation: GetStateName%1034324674
      //	DESCRIPTION
      //
      //	RETURNS
      //	Returns the name of the state. (Uses class runtime info
      //	to extract the name)
      virtual CString GetStateName ();

      //## Operation: Enter%1034324675
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

      //## Operation: Do%1034324676
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: Exit%1034324677
      //	DESCRIPTION
      //	Leaves a state. Place to set up flags.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Exit (ICOStateMachineContext* p_pContext);

      //## Operation: SaveHistory%1034324678
      //	DESCRIPTION
      //	Returns a state to keep before changing to a new state.
      //	Can be used to restore a certain state (Suspend /
      //	Resume).
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	Pointer to state to keep or NULL.
      virtual CCOState* SaveHistory (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%999456380
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

      //## Operation: Shutdown%999456381
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: OnTimer%1053348763
      //	DESCRIPTION
      //	Notifies the subsystem of a timer event
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void OnTimer (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupStop%1001240160
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

      //## Operation: CleanupInitialize%1001240161
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

      //## Operation: ConnectionEstablished%1055313961
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1055313962
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
      //## begin CCOState%3B9281FC00F2.public preserve=yes
      //## end CCOState%3B9281FC00F2.public

  protected:
    // Additional Protected Declarations
      //## begin CCOState%3B9281FC00F2.protected preserve=yes
      //## end CCOState%3B9281FC00F2.protected

  private:
    //## Constructors (generated)
      CCOState(const CCOState &right);

    //## Assignment Operation (generated)
      const CCOState & operator=(const CCOState &right);

    //## Equality Operations (generated)
      bool operator==(const CCOState &right) const;

      bool operator!=(const CCOState &right) const;

    // Additional Private Declarations
      //## begin CCOState%3B9281FC00F2.private preserve=yes
      //## end CCOState%3B9281FC00F2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOState%3B9281FC00F2.implementation preserve=yes
      //## end CCOState%3B9281FC00F2.implementation

};

//## begin CCOState%3B9281FC00F2.postscript preserve=yes
//## end CCOState%3B9281FC00F2.postscript

// Class CCOState 

//## begin module%3B9146FF0231.epilog preserve=yes
//## end module%3B9146FF0231.epilog


#endif
