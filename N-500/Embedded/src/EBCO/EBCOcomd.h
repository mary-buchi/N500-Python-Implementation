//## begin module%3B8EA57401FD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8EA57401FD.cm

//## begin module%3B8EA57401FD.cp preserve=no
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
//## end module%3B8EA57401FD.cp

//## Module: EBCOcomd%3B8EA57401FD; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOcomd.h

#ifndef EBCOcomd_h
#define EBCOcomd_h 1

//## begin module%3B8EA57401FD.additionalIncludes preserve=no
//## end module%3B8EA57401FD.additionalIncludes

//## begin module%3B8EA57401FD.includes preserve=yes
//## end module%3B8EA57401FD.includes


class EBCO_DLL_DECL XCOException;
class EBCO_DLL_DECL CCOSyncObjectArray;
class EBCO_DLL_DECL ICOStateMachineContext;
class EBCO_DLL_DECL CCOState;

//## begin module%3B8EA57401FD.declarations preserve=no
//## end module%3B8EA57401FD.declarations

//## begin module%3B8EA57401FD.additionalDeclarations preserve=yes
//## end module%3B8EA57401FD.additionalDeclarations


//## begin CCOCommand%3B927E1D0300.preface preserve=yes
//## end CCOCommand%3B927E1D0300.preface

//## Class: CCOCommand%3B927E1D0300
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B92838402F5;CCOState { -> F}
//## Uses: <unnamed>%3B9BE0020160;XCOException { -> F}
//## Uses: <unnamed>%3B9150A5012F;CCOState { -> F}

class EBCO_DLL_DECL CCOCommand 
{
  //## begin CCOCommand%3B927E1D0300.initialDeclarations preserve=yes
  //## end CCOCommand%3B927E1D0300.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommand%999456385
      CCOCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommand();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1034575091
      virtual void CreateSyncObjects ();

      //## Operation: AttachException%1000031218
      //	DESCRIPTION
      //	Attaches an exception to a command. Puts the exception
      //	into the active sync objects and signals them.
      //
      //	PARAMETER
      //	Pointer to current exception
      //
      //	RETURNS
      //	void
      virtual void AttachException (XCOException* p_pException);

      //## Operation: SignalCompletion%999456386
      //	DESCRIPTION
      //	Signals the entire array of sync objects attached to the
      //	command. This method is called by the state machine
      //	engine, before the unit threads gets idle again or in
      //	other words when the state machine has been processed
      //
      //	RETURNS
      //	void
      virtual void SignalCompletion ();

      //## Operation: SignalExecution%1001060416
      //	DESCRIPTION
      //	Signals the entire array of sync objects attached to the
      //	command. This method is called by the state machine
      //	engine directly after the command has been executed but
      //	before the state machine is going to be processed.
      //
      //	RETURNS
      //	void
      virtual void SignalExecution ();

      //## Operation: Execute%999456378
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState) = 0;

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3B9288D302D1
      //## Role: CCOCommand::pSyncArray%3B9288D4006F
      CCOSyncObjectArray * GetpSyncArray ();

    // Additional Public Declarations
      //## begin CCOCommand%3B927E1D0300.public preserve=yes
      //## end CCOCommand%3B927E1D0300.public

  protected:
    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3B9288D302D1
      //## begin CCOCommand::pSyncArray%3B9288D4006F.role preserve=no  public: CCOSyncObjectArray {1..1 -> 1..1RFHN}
      CCOSyncObjectArray *m_pSyncArray;
      //## end CCOCommand::pSyncArray%3B9288D4006F.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6B03B02CC
      //## Role: CCOCommand::pContext%3DA6B03C0117
      //## begin CCOCommand::pContext%3DA6B03C0117.role preserve=no  public: ICOStateMachineContext {1..1 -> 1..1RFHN}
      ICOStateMachineContext *m_pContext;
      //## end CCOCommand::pContext%3DA6B03C0117.role

    // Additional Protected Declarations
      //## begin CCOCommand%3B927E1D0300.protected preserve=yes
      //## end CCOCommand%3B927E1D0300.protected

  private:
    //## Constructors (generated)
      CCOCommand();

      CCOCommand(const CCOCommand &right);

    //## Assignment Operation (generated)
      const CCOCommand & operator=(const CCOCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommand &right) const;

      bool operator!=(const CCOCommand &right) const;

    // Additional Private Declarations
      //## begin CCOCommand%3B927E1D0300.private preserve=yes
      //## end CCOCommand%3B927E1D0300.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommand%3B927E1D0300.implementation preserve=yes
      //## end CCOCommand%3B927E1D0300.implementation

};

//## begin CCOCommand%3B927E1D0300.postscript preserve=yes
//## end CCOCommand%3B927E1D0300.postscript

//## begin CCOCommandStartup%3DA6B291028D.preface preserve=yes
//## end CCOCommandStartup%3DA6B291028D.preface

//## Class: CCOCommandStartup%3DA6B291028D
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOCommandStartup : public CCOCommand  //## Inherits: <unnamed>%3DA6B2A403B6
{
  //## begin CCOCommandStartup%3DA6B291028D.initialDeclarations preserve=yes
  //## end CCOCommandStartup%3DA6B291028D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandStartup%1034329201
      CCOCommandStartup (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommandStartup();


    //## Other Operations (specified)
      //## Operation: Execute%1034329202
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CCOCommandStartup%3DA6B291028D.public preserve=yes
      //## end CCOCommandStartup%3DA6B291028D.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandStartup%3DA6B291028D.protected preserve=yes
      //## end CCOCommandStartup%3DA6B291028D.protected

  private:
    //## Constructors (generated)
      CCOCommandStartup();

      CCOCommandStartup(const CCOCommandStartup &right);

    //## Assignment Operation (generated)
      const CCOCommandStartup & operator=(const CCOCommandStartup &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandStartup &right) const;

      bool operator!=(const CCOCommandStartup &right) const;

    // Additional Private Declarations
      //## begin CCOCommandStartup%3DA6B291028D.private preserve=yes
      //## end CCOCommandStartup%3DA6B291028D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandStartup%3DA6B291028D.implementation preserve=yes
      //## end CCOCommandStartup%3DA6B291028D.implementation

};

//## begin CCOCommandStartup%3DA6B291028D.postscript preserve=yes
//## end CCOCommandStartup%3DA6B291028D.postscript

//## begin CCOCommandShutdown%3DA6B2980378.preface preserve=yes
//## end CCOCommandShutdown%3DA6B2980378.preface

//## Class: CCOCommandShutdown%3DA6B2980378
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOCommandShutdown : public CCOCommand  //## Inherits: <unnamed>%3DA6B2A60397
{
  //## begin CCOCommandShutdown%3DA6B2980378.initialDeclarations preserve=yes
  //## end CCOCommandShutdown%3DA6B2980378.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandShutdown%1034329203
      CCOCommandShutdown (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommandShutdown();


    //## Other Operations (specified)
      //## Operation: Execute%1034329204
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CCOCommandShutdown%3DA6B2980378.public preserve=yes
      //## end CCOCommandShutdown%3DA6B2980378.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandShutdown%3DA6B2980378.protected preserve=yes
      //## end CCOCommandShutdown%3DA6B2980378.protected

  private:
    //## Constructors (generated)
      CCOCommandShutdown();

      CCOCommandShutdown(const CCOCommandShutdown &right);

    //## Assignment Operation (generated)
      const CCOCommandShutdown & operator=(const CCOCommandShutdown &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandShutdown &right) const;

      bool operator!=(const CCOCommandShutdown &right) const;

    // Additional Private Declarations
      //## begin CCOCommandShutdown%3DA6B2980378.private preserve=yes
      //## end CCOCommandShutdown%3DA6B2980378.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandShutdown%3DA6B2980378.implementation preserve=yes
      //## end CCOCommandShutdown%3DA6B2980378.implementation

};

//## begin CCOCommandShutdown%3DA6B2980378.postscript preserve=yes
//## end CCOCommandShutdown%3DA6B2980378.postscript

//## begin CCOCommandCleanupStop%3DA6B388030A.preface preserve=yes
//## end CCOCommandCleanupStop%3DA6B388030A.preface

//## Class: CCOCommandCleanupStop%3DA6B388030A
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOCommandCleanupStop : public CCOCommand  //## Inherits: <unnamed>%3DA6B3990220
{
  //## begin CCOCommandCleanupStop%3DA6B388030A.initialDeclarations preserve=yes
  //## end CCOCommandCleanupStop%3DA6B388030A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandCleanupStop%1034329205
      CCOCommandCleanupStop (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommandCleanupStop();


    //## Other Operations (specified)
      //## Operation: Execute%1034329206
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CCOCommandCleanupStop%3DA6B388030A.public preserve=yes
      //## end CCOCommandCleanupStop%3DA6B388030A.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandCleanupStop%3DA6B388030A.protected preserve=yes
      //## end CCOCommandCleanupStop%3DA6B388030A.protected

  private:
    //## Constructors (generated)
      CCOCommandCleanupStop();

      CCOCommandCleanupStop(const CCOCommandCleanupStop &right);

    //## Assignment Operation (generated)
      const CCOCommandCleanupStop & operator=(const CCOCommandCleanupStop &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandCleanupStop &right) const;

      bool operator!=(const CCOCommandCleanupStop &right) const;

    // Additional Private Declarations
      //## begin CCOCommandCleanupStop%3DA6B388030A.private preserve=yes
      //## end CCOCommandCleanupStop%3DA6B388030A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandCleanupStop%3DA6B388030A.implementation preserve=yes
      //## end CCOCommandCleanupStop%3DA6B388030A.implementation

};

//## begin CCOCommandCleanupStop%3DA6B388030A.postscript preserve=yes
//## end CCOCommandCleanupStop%3DA6B388030A.postscript

//## begin CCOCommandCleanupInitialize%3DA6B3900099.preface preserve=yes
//## end CCOCommandCleanupInitialize%3DA6B3900099.preface

//## Class: CCOCommandCleanupInitialize%3DA6B3900099
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL CCOCommandCleanupInitialize : public CCOCommand  //## Inherits: <unnamed>%3DA6B39B028D
{
  //## begin CCOCommandCleanupInitialize%3DA6B3900099.initialDeclarations preserve=yes
  //## end CCOCommandCleanupInitialize%3DA6B3900099.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandCleanupInitialize%1034329207
      CCOCommandCleanupInitialize (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommandCleanupInitialize();


    //## Other Operations (specified)
      //## Operation: Execute%1034329208
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CCOCommandCleanupInitialize%3DA6B3900099.public preserve=yes
      //## end CCOCommandCleanupInitialize%3DA6B3900099.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandCleanupInitialize%3DA6B3900099.protected preserve=yes
      //## end CCOCommandCleanupInitialize%3DA6B3900099.protected

  private:
    //## Constructors (generated)
      CCOCommandCleanupInitialize();

      CCOCommandCleanupInitialize(const CCOCommandCleanupInitialize &right);

    //## Assignment Operation (generated)
      const CCOCommandCleanupInitialize & operator=(const CCOCommandCleanupInitialize &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandCleanupInitialize &right) const;

      bool operator!=(const CCOCommandCleanupInitialize &right) const;

    // Additional Private Declarations
      //## begin CCOCommandCleanupInitialize%3DA6B3900099.private preserve=yes
      //## end CCOCommandCleanupInitialize%3DA6B3900099.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandCleanupInitialize%3DA6B3900099.implementation preserve=yes
      //## end CCOCommandCleanupInitialize%3DA6B3900099.implementation

};

//## begin CCOCommandCleanupInitialize%3DA6B3900099.postscript preserve=yes
//## end CCOCommandCleanupInitialize%3DA6B3900099.postscript

//## begin CCOCommandTimer%3EC8DB8F012C.preface preserve=yes
//## end CCOCommandTimer%3EC8DB8F012C.preface

//## Class: CCOCommandTimer%3EC8DB8F012C
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOCommandTimer : public CCOCommand  //## Inherits: <unnamed>%3EC8DB980236
{
  //## begin CCOCommandTimer%3EC8DB8F012C.initialDeclarations preserve=yes
  //## end CCOCommandTimer%3EC8DB8F012C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandTimer%1053348761
      CCOCommandTimer (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommandTimer();


    //## Other Operations (specified)
      //## Operation: Execute%1053348762
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CCOCommandTimer%3EC8DB8F012C.public preserve=yes
      //## end CCOCommandTimer%3EC8DB8F012C.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandTimer%3EC8DB8F012C.protected preserve=yes
      //## end CCOCommandTimer%3EC8DB8F012C.protected

  private:
    //## Constructors (generated)
      CCOCommandTimer();

      CCOCommandTimer(const CCOCommandTimer &right);

    //## Assignment Operation (generated)
      const CCOCommandTimer & operator=(const CCOCommandTimer &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandTimer &right) const;

      bool operator!=(const CCOCommandTimer &right) const;

    // Additional Private Declarations
      //## begin CCOCommandTimer%3EC8DB8F012C.private preserve=yes
      //## end CCOCommandTimer%3EC8DB8F012C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandTimer%3EC8DB8F012C.implementation preserve=yes
      //## end CCOCommandTimer%3EC8DB8F012C.implementation

};

//## begin CCOCommandTimer%3EC8DB8F012C.postscript preserve=yes
//## end CCOCommandTimer%3EC8DB8F012C.postscript

//## begin CCOCommandConnectionEstablished%3EE6ECD802D8.preface preserve=yes
//## end CCOCommandConnectionEstablished%3EE6ECD802D8.preface

//## Class: CCOCommandConnectionEstablished%3EE6ECD802D8
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOCommandConnectionEstablished : public CCOCommand  //## Inherits: <unnamed>%3EE6ED090190
{
  //## begin CCOCommandConnectionEstablished%3EE6ECD802D8.initialDeclarations preserve=yes
  //## end CCOCommandConnectionEstablished%3EE6ECD802D8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandConnectionEstablished%1055313957
      CCOCommandConnectionEstablished (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommandConnectionEstablished();


    //## Other Operations (specified)
      //## Operation: Execute%1055313958
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CCOCommandConnectionEstablished%3EE6ECD802D8.public preserve=yes
      //## end CCOCommandConnectionEstablished%3EE6ECD802D8.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandConnectionEstablished%3EE6ECD802D8.protected preserve=yes
      //## end CCOCommandConnectionEstablished%3EE6ECD802D8.protected

  private:
    //## Constructors (generated)
      CCOCommandConnectionEstablished();

      CCOCommandConnectionEstablished(const CCOCommandConnectionEstablished &right);

    //## Assignment Operation (generated)
      const CCOCommandConnectionEstablished & operator=(const CCOCommandConnectionEstablished &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandConnectionEstablished &right) const;

      bool operator!=(const CCOCommandConnectionEstablished &right) const;

    // Additional Private Declarations
      //## begin CCOCommandConnectionEstablished%3EE6ECD802D8.private preserve=yes
      //## end CCOCommandConnectionEstablished%3EE6ECD802D8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandConnectionEstablished%3EE6ECD802D8.implementation preserve=yes
      //## end CCOCommandConnectionEstablished%3EE6ECD802D8.implementation

};

//## begin CCOCommandConnectionEstablished%3EE6ECD802D8.postscript preserve=yes
//## end CCOCommandConnectionEstablished%3EE6ECD802D8.postscript

//## begin CCOCommandConnectionLost%3EE6ECED0317.preface preserve=yes
//## end CCOCommandConnectionLost%3EE6ECED0317.preface

//## Class: CCOCommandConnectionLost%3EE6ECED0317
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOCommandConnectionLost : public CCOCommand  //## Inherits: <unnamed>%3EE6ED0C0113
{
  //## begin CCOCommandConnectionLost%3EE6ECED0317.initialDeclarations preserve=yes
  //## end CCOCommandConnectionLost%3EE6ECED0317.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandConnectionLost%1055313959
      CCOCommandConnectionLost (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOCommandConnectionLost();


    //## Other Operations (specified)
      //## Operation: Execute%1055313960
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

      //## Operation: SignalExecution%1056695973
      //	DESCRIPTION
      //	Signals the entire array of sync objects attached to the
      //	command. This method is called by the state machine
      //	engine directly after the command has been executed but
      //	before the state machine is going to be processed.
      //
      //	RETURNS
      //	void
      virtual void SignalExecution ();

    // Additional Public Declarations
      //## begin CCOCommandConnectionLost%3EE6ECED0317.public preserve=yes
      //## end CCOCommandConnectionLost%3EE6ECED0317.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandConnectionLost%3EE6ECED0317.protected preserve=yes
      //## end CCOCommandConnectionLost%3EE6ECED0317.protected

  private:
    //## Constructors (generated)
      CCOCommandConnectionLost();

      CCOCommandConnectionLost(const CCOCommandConnectionLost &right);

    //## Assignment Operation (generated)
      const CCOCommandConnectionLost & operator=(const CCOCommandConnectionLost &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandConnectionLost &right) const;

      bool operator!=(const CCOCommandConnectionLost &right) const;

    // Additional Private Declarations
      //## begin CCOCommandConnectionLost%3EE6ECED0317.private preserve=yes
      //## end CCOCommandConnectionLost%3EE6ECED0317.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandConnectionLost%3EE6ECED0317.implementation preserve=yes
      //## end CCOCommandConnectionLost%3EE6ECED0317.implementation

};

//## begin CCOCommandConnectionLost%3EE6ECED0317.postscript preserve=yes
//## end CCOCommandConnectionLost%3EE6ECED0317.postscript

// Class CCOCommand 

// Class CCOCommandStartup 

// Class CCOCommandShutdown 

// Class CCOCommandCleanupStop 

// Class CCOCommandCleanupInitialize 

// Class CCOCommandTimer 

// Class CCOCommandConnectionEstablished 

// Class CCOCommandConnectionLost 

//## begin module%3B8EA57401FD.epilog preserve=yes
//## end module%3B8EA57401FD.epilog


#endif
