//## begin module%3EED769F037C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F037C.cm

//## begin module%3EED769F037C.cp preserve=no
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
//## end module%3EED769F037C.cp

//## Module: EBPCcomd%3EED769F037C; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCcomd.h

#ifndef EBPCcomd_h
#define EBPCcomd_h 1

//## begin module%3EED769F037C.additionalIncludes preserve=no
//## end module%3EED769F037C.additionalIncludes

//## begin module%3EED769F037C.includes preserve=yes
//## end module%3EED769F037C.includes

// EBCOcomd
#include "EBCOcomd.h"

class EBPI_DLL_DECL CPIPowerControlProfile;
class EBPI_DLL_DECL CPIPowerControlConfig;
class CPCState;

//## begin module%3EED769F037C.declarations preserve=no
//## end module%3EED769F037C.declarations

//## begin module%3EED769F037C.additionalDeclarations preserve=yes
//## end module%3EED769F037C.additionalDeclarations


//## begin CPCCommand%3EED76CC063C.preface preserve=yes
//## end CPCCommand%3EED76CC063C.preface

//## Class: CPCCommand%3EED76CC063C
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC0641;CPCState { -> F}

class CPCCommand : public CCOCommand  //## Inherits: <unnamed>%3EED76CC063E
{
  //## begin CPCCommand%3EED76CC063C.initialDeclarations preserve=yes
  //## end CPCCommand%3EED76CC063C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommand%1046858370
      CPCCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCCommand();


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
      virtual bool Execute (CPCState* p_pCurrentState) = 0;

    // Additional Public Declarations
      //## begin CPCCommand%3EED76CC063C.public preserve=yes
      //## end CPCCommand%3EED76CC063C.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommand%3EED76CC063C.protected preserve=yes
      //## end CPCCommand%3EED76CC063C.protected

  private:
    //## Constructors (generated)
      CPCCommand();

      CPCCommand(const CPCCommand &right);

    //## Assignment Operation (generated)
      const CPCCommand & operator=(const CPCCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommand &right) const;

      bool operator!=(const CPCCommand &right) const;

    // Additional Private Declarations
      //## begin CPCCommand%3EED76CC063C.private preserve=yes
      //## end CPCCommand%3EED76CC063C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommand%3EED76CC063C.implementation preserve=yes
      //## end CPCCommand%3EED76CC063C.implementation

};

//## begin CPCCommand%3EED76CC063C.postscript preserve=yes
//## end CPCCommand%3EED76CC063C.postscript

//## begin CPCCommandStart%3EED76CC064F.preface preserve=yes
//## end CPCCommandStart%3EED76CC064F.preface

//## Class: CPCCommandStart%3EED76CC064F
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC0654;CCOSyncObject { -> }

class CPCCommandStart : public CPCCommand  //## Inherits: <unnamed>%3F9786630271
{
  //## begin CPCCommandStart%3EED76CC064F.initialDeclarations preserve=yes
  //## end CPCCommandStart%3EED76CC064F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandStart%1039429738
      CPCCommandStart (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCCommandStart();


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
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandStart%3EED76CC064F.public preserve=yes
      //## end CPCCommandStart%3EED76CC064F.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandStart%3EED76CC064F.protected preserve=yes
      //## end CPCCommandStart%3EED76CC064F.protected

  private:
    //## Constructors (generated)
      CPCCommandStart();

      CPCCommandStart(const CPCCommandStart &right);

    //## Assignment Operation (generated)
      const CPCCommandStart & operator=(const CPCCommandStart &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandStart &right) const;

      bool operator!=(const CPCCommandStart &right) const;

    // Additional Private Declarations
      //## begin CPCCommandStart%3EED76CC064F.private preserve=yes
      //## end CPCCommandStart%3EED76CC064F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandStart%3EED76CC064F.implementation preserve=yes
      //## end CPCCommandStart%3EED76CC064F.implementation

};

//## begin CPCCommandStart%3EED76CC064F.postscript preserve=yes
//## end CPCCommandStart%3EED76CC064F.postscript

//## begin CPCCommandStop%3EED76CC0663.preface preserve=yes
//## end CPCCommandStop%3EED76CC0663.preface

//## Class: CPCCommandStop%3EED76CC0663
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCCommandStop : public CPCCommand  //## Inherits: <unnamed>%3EED76CC0665
{
  //## begin CPCCommandStop%3EED76CC0663.initialDeclarations preserve=yes
  //## end CPCCommandStop%3EED76CC0663.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandStop%1039429742
      CPCCommandStop (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCCommandStop();


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
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandStop%3EED76CC0663.public preserve=yes
      //## end CPCCommandStop%3EED76CC0663.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandStop%3EED76CC0663.protected preserve=yes
      //## end CPCCommandStop%3EED76CC0663.protected

  private:
    //## Constructors (generated)
      CPCCommandStop();

      CPCCommandStop(const CPCCommandStop &right);

    //## Assignment Operation (generated)
      const CPCCommandStop & operator=(const CPCCommandStop &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandStop &right) const;

      bool operator!=(const CPCCommandStop &right) const;

    // Additional Private Declarations
      //## begin CPCCommandStop%3EED76CC0663.private preserve=yes
      //## end CPCCommandStop%3EED76CC0663.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandStop%3EED76CC0663.implementation preserve=yes
      //## end CPCCommandStop%3EED76CC0663.implementation

};

//## begin CPCCommandStop%3EED76CC0663.postscript preserve=yes
//## end CPCCommandStop%3EED76CC0663.postscript

//## begin CPCCommandSetProfile%3EED76CC0670.preface preserve=yes
//## end CPCCommandSetProfile%3EED76CC0670.preface

//## Class: CPCCommandSetProfile%3EED76CC0670
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCCommandSetProfile : public CPCCommand  //## Inherits: <unnamed>%3EED76CC0672
{
  //## begin CPCCommandSetProfile%3EED76CC0670.initialDeclarations preserve=yes
  //## end CPCCommandSetProfile%3EED76CC0670.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandSetProfile%1039429744
      CPCCommandSetProfile (ICOStateMachineContext* p_pContext, CPIPowerControlProfile* p_pProfile);

    //## Destructor (generated)
      virtual ~CPCCommandSetProfile();


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
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandSetProfile%3EED76CC0670.public preserve=yes
      //## end CPCCommandSetProfile%3EED76CC0670.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandSetProfile%3EED76CC0670.protected preserve=yes
      //## end CPCCommandSetProfile%3EED76CC0670.protected

  private:
    //## Constructors (generated)
      CPCCommandSetProfile();

      CPCCommandSetProfile(const CPCCommandSetProfile &right);

    //## Assignment Operation (generated)
      const CPCCommandSetProfile & operator=(const CPCCommandSetProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandSetProfile &right) const;

      bool operator!=(const CPCCommandSetProfile &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08A3
      //## Role: CPCCommandSetProfile::pProfile%3EED76CC08A8
      //## begin CPCCommandSetProfile::pProfile%3EED76CC08A8.role preserve=no  public: CPIPowerControlProfile {1..1 -> 1..1RFHN}
      CPIPowerControlProfile *m_pProfile;
      //## end CPCCommandSetProfile::pProfile%3EED76CC08A8.role

    // Additional Private Declarations
      //## begin CPCCommandSetProfile%3EED76CC0670.private preserve=yes
      //## end CPCCommandSetProfile%3EED76CC0670.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandSetProfile%3EED76CC0670.implementation preserve=yes
      //## end CPCCommandSetProfile%3EED76CC0670.implementation

};

//## begin CPCCommandSetProfile%3EED76CC0670.postscript preserve=yes
//## end CPCCommandSetProfile%3EED76CC0670.postscript

//## begin CPCCommandSetConfiguration%3EED76CC0796.preface preserve=yes
//## end CPCCommandSetConfiguration%3EED76CC0796.preface

//## Class: CPCCommandSetConfiguration%3EED76CC0796
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCCommandSetConfiguration : public CPCCommand  //## Inherits: <unnamed>%3F978666034B
{
  //## begin CPCCommandSetConfiguration%3EED76CC0796.initialDeclarations preserve=yes
  //## end CPCCommandSetConfiguration%3EED76CC0796.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandSetConfiguration%1046858371
      CPCCommandSetConfiguration (ICOStateMachineContext* p_pContext, CPIPowerControlConfig* p_pConfig);

    //## Destructor (generated)
      virtual ~CPCCommandSetConfiguration();


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
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandSetConfiguration%3EED76CC0796.public preserve=yes
      //## end CPCCommandSetConfiguration%3EED76CC0796.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandSetConfiguration%3EED76CC0796.protected preserve=yes
      //## end CPCCommandSetConfiguration%3EED76CC0796.protected

  private:
    //## Constructors (generated)
      CPCCommandSetConfiguration();

      CPCCommandSetConfiguration(const CPCCommandSetConfiguration &right);

    //## Assignment Operation (generated)
      const CPCCommandSetConfiguration & operator=(const CPCCommandSetConfiguration &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandSetConfiguration &right) const;

      bool operator!=(const CPCCommandSetConfiguration &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC0913
      //## Role: CPCCommandSetConfiguration::pConfig%3EED76CC0918
      //## begin CPCCommandSetConfiguration::pConfig%3EED76CC0918.role preserve=no  public: CPIPowerControlConfig {1..1 -> 1..1RFHN}
      CPIPowerControlConfig *m_pConfig;
      //## end CPCCommandSetConfiguration::pConfig%3EED76CC0918.role

    // Additional Private Declarations
      //## begin CPCCommandSetConfiguration%3EED76CC0796.private preserve=yes
      //## end CPCCommandSetConfiguration%3EED76CC0796.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandSetConfiguration%3EED76CC0796.implementation preserve=yes
      //## end CPCCommandSetConfiguration%3EED76CC0796.implementation

};

//## begin CPCCommandSetConfiguration%3EED76CC0796.postscript preserve=yes
//## end CPCCommandSetConfiguration%3EED76CC0796.postscript

//## begin CPCCommandConnectionEstablished%3EED76CC07D3.preface preserve=yes
//## end CPCCommandConnectionEstablished%3EED76CC07D3.preface

//## Class: CPCCommandConnectionEstablished%3EED76CC07D3
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCCommandConnectionEstablished : public CPCCommand  //## Inherits: <unnamed>%3EED76CC07D5
{
  //## begin CPCCommandConnectionEstablished%3EED76CC07D3.initialDeclarations preserve=yes
  //## end CPCCommandConnectionEstablished%3EED76CC07D3.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandConnectionEstablished%1055428406
      CPCCommandConnectionEstablished (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCCommandConnectionEstablished();


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
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandConnectionEstablished%3EED76CC07D3.public preserve=yes
      //## end CPCCommandConnectionEstablished%3EED76CC07D3.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandConnectionEstablished%3EED76CC07D3.protected preserve=yes
      //## end CPCCommandConnectionEstablished%3EED76CC07D3.protected

  private:
    //## Constructors (generated)
      CPCCommandConnectionEstablished();

      CPCCommandConnectionEstablished(const CPCCommandConnectionEstablished &right);

    //## Assignment Operation (generated)
      const CPCCommandConnectionEstablished & operator=(const CPCCommandConnectionEstablished &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandConnectionEstablished &right) const;

      bool operator!=(const CPCCommandConnectionEstablished &right) const;

    // Additional Private Declarations
      //## begin CPCCommandConnectionEstablished%3EED76CC07D3.private preserve=yes
      //## end CPCCommandConnectionEstablished%3EED76CC07D3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandConnectionEstablished%3EED76CC07D3.implementation preserve=yes
      //## end CPCCommandConnectionEstablished%3EED76CC07D3.implementation

};

//## begin CPCCommandConnectionEstablished%3EED76CC07D3.postscript preserve=yes
//## end CPCCommandConnectionEstablished%3EED76CC07D3.postscript

//## begin CPCCommandConnectionLost%3EED76CC07E0.preface preserve=yes
//## end CPCCommandConnectionLost%3EED76CC07E0.preface

//## Class: CPCCommandConnectionLost%3EED76CC07E0
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCCommandConnectionLost : public CPCCommand  //## Inherits: <unnamed>%3EED76CC07E2
{
  //## begin CPCCommandConnectionLost%3EED76CC07E0.initialDeclarations preserve=yes
  //## end CPCCommandConnectionLost%3EED76CC07E0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandConnectionLost%1055428408
      CPCCommandConnectionLost (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCCommandConnectionLost();


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
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandConnectionLost%3EED76CC07E0.public preserve=yes
      //## end CPCCommandConnectionLost%3EED76CC07E0.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandConnectionLost%3EED76CC07E0.protected preserve=yes
      //## end CPCCommandConnectionLost%3EED76CC07E0.protected

  private:
    //## Constructors (generated)
      CPCCommandConnectionLost();

      CPCCommandConnectionLost(const CPCCommandConnectionLost &right);

    //## Assignment Operation (generated)
      const CPCCommandConnectionLost & operator=(const CPCCommandConnectionLost &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandConnectionLost &right) const;

      bool operator!=(const CPCCommandConnectionLost &right) const;

    // Additional Private Declarations
      //## begin CPCCommandConnectionLost%3EED76CC07E0.private preserve=yes
      //## end CPCCommandConnectionLost%3EED76CC07E0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandConnectionLost%3EED76CC07E0.implementation preserve=yes
      //## end CPCCommandConnectionLost%3EED76CC07E0.implementation

};

//## begin CPCCommandConnectionLost%3EED76CC07E0.postscript preserve=yes
//## end CPCCommandConnectionLost%3EED76CC07E0.postscript

//## begin CPCCommandPowerOff%4027B5E00016.preface preserve=yes
//## end CPCCommandPowerOff%4027B5E00016.preface

//## Class: CPCCommandPowerOff%4027B5E00016
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCCommandPowerOff : public CPCCommand  //## Inherits: <unnamed>%4027B6150323
{
  //## begin CPCCommandPowerOff%4027B5E00016.initialDeclarations preserve=yes
  //## end CPCCommandPowerOff%4027B5E00016.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandPowerOff%1076339205
      CPCCommandPowerOff (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCCommandPowerOff();


    //## Other Operations (specified)
      //## Operation: Execute%1076339206
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandPowerOff%4027B5E00016.public preserve=yes
      //## end CPCCommandPowerOff%4027B5E00016.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandPowerOff%4027B5E00016.protected preserve=yes
      //## end CPCCommandPowerOff%4027B5E00016.protected

  private:
    //## Constructors (generated)
      CPCCommandPowerOff();

      CPCCommandPowerOff(const CPCCommandPowerOff &right);

    //## Assignment Operation (generated)
      const CPCCommandPowerOff & operator=(const CPCCommandPowerOff &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandPowerOff &right) const;

      bool operator!=(const CPCCommandPowerOff &right) const;

    // Additional Private Declarations
      //## begin CPCCommandPowerOff%4027B5E00016.private preserve=yes
      //## end CPCCommandPowerOff%4027B5E00016.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandPowerOff%4027B5E00016.implementation preserve=yes
      //## end CPCCommandPowerOff%4027B5E00016.implementation

};

//## begin CPCCommandPowerOff%4027B5E00016.postscript preserve=yes
//## end CPCCommandPowerOff%4027B5E00016.postscript

//## begin CPCCommandPowerOn%4027B5FF0314.preface preserve=yes
//## end CPCCommandPowerOn%4027B5FF0314.preface

//## Class: CPCCommandPowerOn%4027B5FF0314
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCCommandPowerOn : public CPCCommand  //## Inherits: <unnamed>%4027B61A02A6
{
  //## begin CPCCommandPowerOn%4027B5FF0314.initialDeclarations preserve=yes
  //## end CPCCommandPowerOn%4027B5FF0314.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCCommandPowerOn%1076339203
      CPCCommandPowerOn (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCCommandPowerOn();


    //## Other Operations (specified)
      //## Operation: Execute%1076339204
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPCCommandPowerOn%4027B5FF0314.public preserve=yes
      //## end CPCCommandPowerOn%4027B5FF0314.public

  protected:
    // Additional Protected Declarations
      //## begin CPCCommandPowerOn%4027B5FF0314.protected preserve=yes
      //## end CPCCommandPowerOn%4027B5FF0314.protected

  private:
    //## Constructors (generated)
      CPCCommandPowerOn();

      CPCCommandPowerOn(const CPCCommandPowerOn &right);

    //## Assignment Operation (generated)
      const CPCCommandPowerOn & operator=(const CPCCommandPowerOn &right);

    //## Equality Operations (generated)
      bool operator==(const CPCCommandPowerOn &right) const;

      bool operator!=(const CPCCommandPowerOn &right) const;

    // Additional Private Declarations
      //## begin CPCCommandPowerOn%4027B5FF0314.private preserve=yes
      //## end CPCCommandPowerOn%4027B5FF0314.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCCommandPowerOn%4027B5FF0314.implementation preserve=yes
      //## end CPCCommandPowerOn%4027B5FF0314.implementation

};

//## begin CPCCommandPowerOn%4027B5FF0314.postscript preserve=yes
//## end CPCCommandPowerOn%4027B5FF0314.postscript

// Class CPCCommand 

// Class CPCCommandStart 

// Class CPCCommandStop 

// Class CPCCommandSetProfile 

// Class CPCCommandSetConfiguration 

// Class CPCCommandConnectionEstablished 

// Class CPCCommandConnectionLost 

// Class CPCCommandPowerOff 

// Class CPCCommandPowerOn 

//## begin module%3EED769F037C.epilog preserve=yes
//## end module%3EED769F037C.epilog


#endif
