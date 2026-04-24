//## begin module%3DE5EE2E014D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EE2E014D.cm

//## begin module%3DE5EE2E014D.cp preserve=no
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
//## end module%3DE5EE2E014D.cp

//## Module: EBTCcomd%3DE5EE2E014D; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCcomd.h

#ifndef EBTCcomd_h
#define EBTCcomd_h 1

//## begin module%3DE5EE2E014D.additionalIncludes preserve=no
//## end module%3DE5EE2E014D.additionalIncludes

//## begin module%3DE5EE2E014D.includes preserve=yes
//## end module%3DE5EE2E014D.includes

// EBCOcomd
#include "EBCOcomd.h"

class EBPI_DLL_DECL CPITemperatureControlConfig;
class EBPI_DLL_DECL CPITemperatureControlProfile;
class CTCState;

//## begin module%3DE5EE2E014D.declarations preserve=no
//## end module%3DE5EE2E014D.declarations

//## begin module%3DE5EE2E014D.additionalDeclarations preserve=yes
//## end module%3DE5EE2E014D.additionalDeclarations


//## begin CTCCommand%3DECB4BE03BC.preface preserve=yes
//## end CTCCommand%3DECB4BE03BC.preface

//## Class: CTCCommand%3DECB4BE03BC
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DECB50E0310;CTCState { -> F}

class CTCCommand : public CCOCommand  //## Inherits: <unnamed>%3DECB4C90320
{
  //## begin CTCCommand%3DECB4BE03BC.initialDeclarations preserve=yes
  //## end CTCCommand%3DECB4BE03BC.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommand%1046858370
      CTCCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1038899360
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

      //## Operation: Execute%1046858373
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState) = 0;

    // Additional Public Declarations
      //## begin CTCCommand%3DECB4BE03BC.public preserve=yes
      //## end CTCCommand%3DECB4BE03BC.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommand%3DECB4BE03BC.protected preserve=yes
      //## end CTCCommand%3DECB4BE03BC.protected

  private:
    //## Constructors (generated)
      CTCCommand();

      CTCCommand(const CTCCommand &right);

    //## Assignment Operation (generated)
      const CTCCommand & operator=(const CTCCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommand &right) const;

      bool operator!=(const CTCCommand &right) const;

    // Additional Private Declarations
      //## begin CTCCommand%3DECB4BE03BC.private preserve=yes
      //## end CTCCommand%3DECB4BE03BC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommand%3DECB4BE03BC.implementation preserve=yes
      //## end CTCCommand%3DECB4BE03BC.implementation

};

//## begin CTCCommand%3DECB4BE03BC.postscript preserve=yes
//## end CTCCommand%3DECB4BE03BC.postscript

//## begin CTCCommandStart%3DF48BA7002A.preface preserve=yes
//## end CTCCommandStart%3DF48BA7002A.preface

//## Class: CTCCommandStart%3DF48BA7002A
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF48C2301D0;CCOSyncObject { -> }

class CTCCommandStart : public CTCCommand  //## Inherits: <unnamed>%3DF48BB10172
{
  //## begin CTCCommandStart%3DF48BA7002A.initialDeclarations preserve=yes
  //## end CTCCommandStart%3DF48BA7002A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandStart%1039429738
      CTCCommandStart (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCCommandStart();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1039429739
      virtual void CreateSyncObjects ();

      //## Operation: SignalExecution%1046858369
      //	DESCRIPTION
      //	Signals the entire array of sync objects attached to the
      //	command. This method is called by the state machine
      //	engine directly after the command has been executed but
      //	before the state machine is going to be processed.
      //
      //	RETURNS
      //	void
      virtual void SignalExecution ();

      //## Operation: Execute%1039429740
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandStart%3DF48BA7002A.public preserve=yes
      //## end CTCCommandStart%3DF48BA7002A.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandStart%3DF48BA7002A.protected preserve=yes
      //## end CTCCommandStart%3DF48BA7002A.protected

  private:
    //## Constructors (generated)
      CTCCommandStart();

      CTCCommandStart(const CTCCommandStart &right);

    //## Assignment Operation (generated)
      const CTCCommandStart & operator=(const CTCCommandStart &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandStart &right) const;

      bool operator!=(const CTCCommandStart &right) const;

    // Additional Private Declarations
      //## begin CTCCommandStart%3DF48BA7002A.private preserve=yes
      //## end CTCCommandStart%3DF48BA7002A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandStart%3DF48BA7002A.implementation preserve=yes
      //## end CTCCommandStart%3DF48BA7002A.implementation

};

//## begin CTCCommandStart%3DF48BA7002A.postscript preserve=yes
//## end CTCCommandStart%3DF48BA7002A.postscript

//## begin CTCCommandStop%3DF497D60318.preface preserve=yes
//## end CTCCommandStop%3DF497D60318.preface

//## Class: CTCCommandStop%3DF497D60318
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCCommandStop : public CTCCommand  //## Inherits: <unnamed>%3DF497E2001A
{
  //## begin CTCCommandStop%3DF497D60318.initialDeclarations preserve=yes
  //## end CTCCommandStop%3DF497D60318.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandStop%1039429742
      CTCCommandStop (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCCommandStop();


    //## Other Operations (specified)
      //## Operation: Execute%1039429743
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandStop%3DF497D60318.public preserve=yes
      //## end CTCCommandStop%3DF497D60318.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandStop%3DF497D60318.protected preserve=yes
      //## end CTCCommandStop%3DF497D60318.protected

  private:
    //## Constructors (generated)
      CTCCommandStop();

      CTCCommandStop(const CTCCommandStop &right);

    //## Assignment Operation (generated)
      const CTCCommandStop & operator=(const CTCCommandStop &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandStop &right) const;

      bool operator!=(const CTCCommandStop &right) const;

    // Additional Private Declarations
      //## begin CTCCommandStop%3DF497D60318.private preserve=yes
      //## end CTCCommandStop%3DF497D60318.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandStop%3DF497D60318.implementation preserve=yes
      //## end CTCCommandStop%3DF497D60318.implementation

};

//## begin CTCCommandStop%3DF497D60318.postscript preserve=yes
//## end CTCCommandStop%3DF497D60318.postscript

//## begin CTCCommandSetProfile%3DF498E80068.preface preserve=yes
//## end CTCCommandSetProfile%3DF498E80068.preface

//## Class: CTCCommandSetProfile%3DF498E80068
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCCommandSetProfile : public CTCCommand  //## Inherits: <unnamed>%3DF498F60385
{
  //## begin CTCCommandSetProfile%3DF498E80068.initialDeclarations preserve=yes
  //## end CTCCommandSetProfile%3DF498E80068.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandSetProfile%1039429744
      CTCCommandSetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile);

    //## Destructor (generated)
      virtual ~CTCCommandSetProfile();


    //## Other Operations (specified)
      //## Operation: Execute%1039429745
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandSetProfile%3DF498E80068.public preserve=yes
      //## end CTCCommandSetProfile%3DF498E80068.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandSetProfile%3DF498E80068.protected preserve=yes
      //## end CTCCommandSetProfile%3DF498E80068.protected

  private:
    //## Constructors (generated)
      CTCCommandSetProfile();

      CTCCommandSetProfile(const CTCCommandSetProfile &right);

    //## Assignment Operation (generated)
      const CTCCommandSetProfile & operator=(const CTCCommandSetProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandSetProfile &right) const;

      bool operator!=(const CTCCommandSetProfile &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3DF4993E0172
      //## Role: CTCCommandSetProfile::pProfile%3DF4993E03B5
      //## begin CTCCommandSetProfile::pProfile%3DF4993E03B5.role preserve=no  public: CPITemperatureControlProfile {1..1 -> 1..1RFHN}
      CPITemperatureControlProfile *m_pProfile;
      //## end CTCCommandSetProfile::pProfile%3DF4993E03B5.role

    // Additional Private Declarations
      //## begin CTCCommandSetProfile%3DF498E80068.private preserve=yes
      //## end CTCCommandSetProfile%3DF498E80068.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandSetProfile%3DF498E80068.implementation preserve=yes
      //## end CTCCommandSetProfile%3DF498E80068.implementation

};

//## begin CTCCommandSetProfile%3DF498E80068.postscript preserve=yes
//## end CTCCommandSetProfile%3DF498E80068.postscript

//## begin CTCCommandGetTemperature%3DF49B3F00E5.preface preserve=yes
//## end CTCCommandGetTemperature%3DF49B3F00E5.preface

//## Class: CTCCommandGetTemperature%3DF49B3F00E5
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCCommandGetTemperature : public CTCCommand  //## Inherits: <unnamed>%3DF49B4B022E
{
  //## begin CTCCommandGetTemperature%3DF49B3F00E5.initialDeclarations preserve=yes
  //## end CTCCommandGetTemperature%3DF49B3F00E5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandGetTemperature%1039429748
      CTCCommandGetTemperature (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCCommandGetTemperature();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1039429749
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1039429750
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandGetTemperature%3DF49B3F00E5.public preserve=yes
      //## end CTCCommandGetTemperature%3DF49B3F00E5.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandGetTemperature%3DF49B3F00E5.protected preserve=yes
      //## end CTCCommandGetTemperature%3DF49B3F00E5.protected

  private:
    //## Constructors (generated)
      CTCCommandGetTemperature();

      CTCCommandGetTemperature(const CTCCommandGetTemperature &right);

    //## Assignment Operation (generated)
      const CTCCommandGetTemperature & operator=(const CTCCommandGetTemperature &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandGetTemperature &right) const;

      bool operator!=(const CTCCommandGetTemperature &right) const;

    // Additional Private Declarations
      //## begin CTCCommandGetTemperature%3DF49B3F00E5.private preserve=yes
      //## end CTCCommandGetTemperature%3DF49B3F00E5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandGetTemperature%3DF49B3F00E5.implementation preserve=yes
      //## end CTCCommandGetTemperature%3DF49B3F00E5.implementation

};

//## begin CTCCommandGetTemperature%3DF49B3F00E5.postscript preserve=yes
//## end CTCCommandGetTemperature%3DF49B3F00E5.postscript

//## begin CTCCommandSetConfiguration%3E6626190031.preface preserve=yes
//## end CTCCommandSetConfiguration%3E6626190031.preface

//## Class: CTCCommandSetConfiguration%3E6626190031
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCCommandSetConfiguration : public CTCCommand  //## Inherits: <unnamed>%3E662628007F
{
  //## begin CTCCommandSetConfiguration%3E6626190031.initialDeclarations preserve=yes
  //## end CTCCommandSetConfiguration%3E6626190031.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandSetConfiguration%1046858371
      CTCCommandSetConfiguration (ICOStateMachineContext* p_pContext, CPITemperatureControlConfig* p_pConfig);

    //## Destructor (generated)
      virtual ~CTCCommandSetConfiguration();


    //## Other Operations (specified)
      //## Operation: Execute%1046858372
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandSetConfiguration%3E6626190031.public preserve=yes
      //## end CTCCommandSetConfiguration%3E6626190031.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandSetConfiguration%3E6626190031.protected preserve=yes
      //## end CTCCommandSetConfiguration%3E6626190031.protected

  private:
    //## Constructors (generated)
      CTCCommandSetConfiguration();

      CTCCommandSetConfiguration(const CTCCommandSetConfiguration &right);

    //## Assignment Operation (generated)
      const CTCCommandSetConfiguration & operator=(const CTCCommandSetConfiguration &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandSetConfiguration &right) const;

      bool operator!=(const CTCCommandSetConfiguration &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E66270A008F
      //## Role: CTCCommandSetConfiguration::pConfig%3E66270A03DB
      //## begin CTCCommandSetConfiguration::pConfig%3E66270A03DB.role preserve=no  public: CPITemperatureControlConfig {1..1 -> 1..1RFHN}
      CPITemperatureControlConfig *m_pConfig;
      //## end CTCCommandSetConfiguration::pConfig%3E66270A03DB.role

    // Additional Private Declarations
      //## begin CTCCommandSetConfiguration%3E6626190031.private preserve=yes
      //## end CTCCommandSetConfiguration%3E6626190031.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandSetConfiguration%3E6626190031.implementation preserve=yes
      //## end CTCCommandSetConfiguration%3E6626190031.implementation

};

//## begin CTCCommandSetConfiguration%3E6626190031.postscript preserve=yes
//## end CTCCommandSetConfiguration%3E6626190031.postscript

//## begin CTCCommandConnectionEstablished%3EE89B3E0117.preface preserve=yes
//## end CTCCommandConnectionEstablished%3EE89B3E0117.preface

//## Class: CTCCommandConnectionEstablished%3EE89B3E0117
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCCommandConnectionEstablished : public CTCCommand  //## Inherits: <unnamed>%3EE89B75009A
{
  //## begin CTCCommandConnectionEstablished%3EE89B3E0117.initialDeclarations preserve=yes
  //## end CTCCommandConnectionEstablished%3EE89B3E0117.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandConnectionEstablished%1055428406
      CTCCommandConnectionEstablished (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCCommandConnectionEstablished();


    //## Other Operations (specified)
      //## Operation: Execute%1055428407
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandConnectionEstablished%3EE89B3E0117.public preserve=yes
      //## end CTCCommandConnectionEstablished%3EE89B3E0117.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandConnectionEstablished%3EE89B3E0117.protected preserve=yes
      //## end CTCCommandConnectionEstablished%3EE89B3E0117.protected

  private:
    //## Constructors (generated)
      CTCCommandConnectionEstablished();

      CTCCommandConnectionEstablished(const CTCCommandConnectionEstablished &right);

    //## Assignment Operation (generated)
      const CTCCommandConnectionEstablished & operator=(const CTCCommandConnectionEstablished &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandConnectionEstablished &right) const;

      bool operator!=(const CTCCommandConnectionEstablished &right) const;

    // Additional Private Declarations
      //## begin CTCCommandConnectionEstablished%3EE89B3E0117.private preserve=yes
      //## end CTCCommandConnectionEstablished%3EE89B3E0117.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandConnectionEstablished%3EE89B3E0117.implementation preserve=yes
      //## end CTCCommandConnectionEstablished%3EE89B3E0117.implementation

};

//## begin CTCCommandConnectionEstablished%3EE89B3E0117.postscript preserve=yes
//## end CTCCommandConnectionEstablished%3EE89B3E0117.postscript

//## begin CTCCommandConnectionLost%3EE89B4002DC.preface preserve=yes
//## end CTCCommandConnectionLost%3EE89B4002DC.preface

//## Class: CTCCommandConnectionLost%3EE89B4002DC
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCCommandConnectionLost : public CTCCommand  //## Inherits: <unnamed>%3EE89B780155
{
  //## begin CTCCommandConnectionLost%3EE89B4002DC.initialDeclarations preserve=yes
  //## end CTCCommandConnectionLost%3EE89B4002DC.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandConnectionLost%1055428408
      CTCCommandConnectionLost (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCCommandConnectionLost();


    //## Other Operations (specified)
      //## Operation: Execute%1055428409
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandConnectionLost%3EE89B4002DC.public preserve=yes
      //## end CTCCommandConnectionLost%3EE89B4002DC.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandConnectionLost%3EE89B4002DC.protected preserve=yes
      //## end CTCCommandConnectionLost%3EE89B4002DC.protected

  private:
    //## Constructors (generated)
      CTCCommandConnectionLost();

      CTCCommandConnectionLost(const CTCCommandConnectionLost &right);

    //## Assignment Operation (generated)
      const CTCCommandConnectionLost & operator=(const CTCCommandConnectionLost &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandConnectionLost &right) const;

      bool operator!=(const CTCCommandConnectionLost &right) const;

    // Additional Private Declarations
      //## begin CTCCommandConnectionLost%3EE89B4002DC.private preserve=yes
      //## end CTCCommandConnectionLost%3EE89B4002DC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandConnectionLost%3EE89B4002DC.implementation preserve=yes
      //## end CTCCommandConnectionLost%3EE89B4002DC.implementation

};

//## begin CTCCommandConnectionLost%3EE89B4002DC.postscript preserve=yes
//## end CTCCommandConnectionLost%3EE89B4002DC.postscript

//## begin CTCCommandCellUndocked%488999F80064.preface preserve=yes
//## end CTCCommandCellUndocked%488999F80064.preface

//## Class: CTCCommandCellUndocked%488999F80064
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCCommandCellUndocked : public CTCCommand  //## Inherits: <unnamed>%48899A120202
{
  //## begin CTCCommandCellUndocked%488999F80064.initialDeclarations preserve=yes
  //## end CTCCommandCellUndocked%488999F80064.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCCommandCellUndocked%1216975783
      CTCCommandCellUndocked (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCCommandCellUndocked();


    //## Other Operations (specified)
      //## Operation: Execute%1216975784
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CTCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CTCCommandCellUndocked%488999F80064.public preserve=yes
      //## end CTCCommandCellUndocked%488999F80064.public

  protected:
    // Additional Protected Declarations
      //## begin CTCCommandCellUndocked%488999F80064.protected preserve=yes
      //## end CTCCommandCellUndocked%488999F80064.protected

  private:
    //## Constructors (generated)
      CTCCommandCellUndocked();

      CTCCommandCellUndocked(const CTCCommandCellUndocked &right);

    //## Assignment Operation (generated)
      const CTCCommandCellUndocked & operator=(const CTCCommandCellUndocked &right);

    //## Equality Operations (generated)
      bool operator==(const CTCCommandCellUndocked &right) const;

      bool operator!=(const CTCCommandCellUndocked &right) const;

    // Additional Private Declarations
      //## begin CTCCommandCellUndocked%488999F80064.private preserve=yes
      //## end CTCCommandCellUndocked%488999F80064.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCCommandCellUndocked%488999F80064.implementation preserve=yes
      //## end CTCCommandCellUndocked%488999F80064.implementation

};

//## begin CTCCommandCellUndocked%488999F80064.postscript preserve=yes
//## end CTCCommandCellUndocked%488999F80064.postscript

// Class CTCCommand 

// Class CTCCommandStart 

// Class CTCCommandStop 

// Class CTCCommandSetProfile 

// Class CTCCommandGetTemperature 

// Class CTCCommandSetConfiguration 

// Class CTCCommandConnectionEstablished 

// Class CTCCommandConnectionLost 

// Class CTCCommandCellUndocked 

//## begin module%3DE5EE2E014D.epilog preserve=yes
//## end module%3DE5EE2E014D.epilog


#endif
