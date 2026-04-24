//## begin module%3DD39EA203A6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD39EA203A6.cm

//## begin module%3DD39EA203A6.cp preserve=no
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
//## end module%3DD39EA203A6.cp

//## Module: EBWCcomd%3DD39EA203A6; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCcomd.h

#ifndef EBWCcomd_h
#define EBWCcomd_h 1

//## begin module%3DD39EA203A6.additionalIncludes preserve=no
//## end module%3DD39EA203A6.additionalIncludes

//## begin module%3DD39EA203A6.includes preserve=yes
//## end module%3DD39EA203A6.includes

// EBCOcomd
#include "EBCOcomd.h"

class EBPI_DLL_DECL CPIWedgeControlConfig;
class EBPI_DLL_DECL CPIWedgeControlProfile;
class CWCState;

//## begin module%3DD39EA203A6.declarations preserve=no
//## end module%3DD39EA203A6.declarations

//## begin module%3DD39EA203A6.additionalDeclarations preserve=yes
//## end module%3DD39EA203A6.additionalDeclarations


//## begin CWCCommand%3DE1D3920083.preface preserve=yes
//## end CWCCommand%3DE1D3920083.preface

//## Class: CWCCommand%3DE1D3920083
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE1D4A301BB;CWCState { -> F}

class CWCCommand : public CCOCommand  //## Inherits: <unnamed>%3DE1D3A000D1
{
  //## begin CWCCommand%3DE1D3920083.initialDeclarations preserve=yes
  //## end CWCCommand%3DE1D3920083.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommand%1038209093
      CWCCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1038209094
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

      //## Operation: Execute%1038209095
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState) = 0;

    // Additional Public Declarations
      //## begin CWCCommand%3DE1D3920083.public preserve=yes
      //## end CWCCommand%3DE1D3920083.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommand%3DE1D3920083.protected preserve=yes
      //## end CWCCommand%3DE1D3920083.protected

  private:
    //## Constructors (generated)
      CWCCommand();

      CWCCommand(const CWCCommand &right);

    //## Assignment Operation (generated)
      const CWCCommand & operator=(const CWCCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommand &right) const;

      bool operator!=(const CWCCommand &right) const;

    // Additional Private Declarations
      //## begin CWCCommand%3DE1D3920083.private preserve=yes
      //## end CWCCommand%3DE1D3920083.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommand%3DE1D3920083.implementation preserve=yes
      //## end CWCCommand%3DE1D3920083.implementation

};

//## begin CWCCommand%3DE1D3920083.postscript preserve=yes
//## end CWCCommand%3DE1D3920083.postscript

//## begin CWCCommandSetConfiguration%3DE1D0A803A0.preface preserve=yes
//## end CWCCommandSetConfiguration%3DE1D0A803A0.preface

//## Class: CWCCommandSetConfiguration%3DE1D0A803A0
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandSetConfiguration : public CWCCommand  //## Inherits: <unnamed>%3DE1D48300C1
{
  //## begin CWCCommandSetConfiguration%3DE1D0A803A0.initialDeclarations preserve=yes
  //## end CWCCommandSetConfiguration%3DE1D0A803A0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandSetConfiguration%1038209085
      CWCCommandSetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig);

    //## Destructor (generated)
      virtual ~CWCCommandSetConfiguration();


    //## Other Operations (specified)
      //## Operation: Execute%1038209086
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandSetConfiguration%3DE1D0A803A0.public preserve=yes
      //## end CWCCommandSetConfiguration%3DE1D0A803A0.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandSetConfiguration%3DE1D0A803A0.protected preserve=yes
      //## end CWCCommandSetConfiguration%3DE1D0A803A0.protected

  private:
    //## Constructors (generated)
      CWCCommandSetConfiguration();

      CWCCommandSetConfiguration(const CWCCommandSetConfiguration &right);

    //## Assignment Operation (generated)
      const CWCCommandSetConfiguration & operator=(const CWCCommandSetConfiguration &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandSetConfiguration &right) const;

      bool operator!=(const CWCCommandSetConfiguration &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3DE323380264
      //## Role: CWCCommandSetConfiguration::pConfig%3DE323390032
      //## begin CWCCommandSetConfiguration::pConfig%3DE323390032.role preserve=no  public: CPIWedgeControlConfig {1..1 -> 1..1RFHN}
      CPIWedgeControlConfig *m_pConfig;
      //## end CWCCommandSetConfiguration::pConfig%3DE323390032.role

    // Additional Private Declarations
      //## begin CWCCommandSetConfiguration%3DE1D0A803A0.private preserve=yes
      //## end CWCCommandSetConfiguration%3DE1D0A803A0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandSetConfiguration%3DE1D0A803A0.implementation preserve=yes
      //## end CWCCommandSetConfiguration%3DE1D0A803A0.implementation

};

//## begin CWCCommandSetConfiguration%3DE1D0A803A0.postscript preserve=yes
//## end CWCCommandSetConfiguration%3DE1D0A803A0.postscript

//## begin CWCCommandStop%3DE1D1510332.preface preserve=yes
//## end CWCCommandStop%3DE1D1510332.preface

//## Class: CWCCommandStop%3DE1D1510332
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandStop : public CWCCommand  //## Inherits: <unnamed>%3DE1D4790035
{
  //## begin CWCCommandStop%3DE1D1510332.initialDeclarations preserve=yes
  //## end CWCCommandStop%3DE1D1510332.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandStop%1038209087
      CWCCommandStop (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommandStop();


    //## Other Operations (specified)
      //## Operation: Execute%1038209088
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandStop%3DE1D1510332.public preserve=yes
      //## end CWCCommandStop%3DE1D1510332.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandStop%3DE1D1510332.protected preserve=yes
      //## end CWCCommandStop%3DE1D1510332.protected

  private:
    //## Constructors (generated)
      CWCCommandStop();

      CWCCommandStop(const CWCCommandStop &right);

    //## Assignment Operation (generated)
      const CWCCommandStop & operator=(const CWCCommandStop &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandStop &right) const;

      bool operator!=(const CWCCommandStop &right) const;

    // Additional Private Declarations
      //## begin CWCCommandStop%3DE1D1510332.private preserve=yes
      //## end CWCCommandStop%3DE1D1510332.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandStop%3DE1D1510332.implementation preserve=yes
      //## end CWCCommandStop%3DE1D1510332.implementation

};

//## begin CWCCommandStop%3DE1D1510332.postscript preserve=yes
//## end CWCCommandStop%3DE1D1510332.postscript

//## begin CWCCommandReferencing%3DE1D4C003A0.preface preserve=yes
//## end CWCCommandReferencing%3DE1D4C003A0.preface

//## Class: CWCCommandReferencing%3DE1D4C003A0
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandReferencing : public CWCCommand  //## Inherits: <unnamed>%3DE1D4EB03DE
{
  //## begin CWCCommandReferencing%3DE1D4C003A0.initialDeclarations preserve=yes
  //## end CWCCommandReferencing%3DE1D4C003A0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandReferencing%1038209091
      CWCCommandReferencing (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommandReferencing();


    //## Other Operations (specified)
      //## Operation: Execute%1038209092
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandReferencing%3DE1D4C003A0.public preserve=yes
      //## end CWCCommandReferencing%3DE1D4C003A0.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandReferencing%3DE1D4C003A0.protected preserve=yes
      //## end CWCCommandReferencing%3DE1D4C003A0.protected

  private:
    //## Constructors (generated)
      CWCCommandReferencing();

      CWCCommandReferencing(const CWCCommandReferencing &right);

    //## Assignment Operation (generated)
      const CWCCommandReferencing & operator=(const CWCCommandReferencing &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandReferencing &right) const;

      bool operator!=(const CWCCommandReferencing &right) const;

    // Additional Private Declarations
      //## begin CWCCommandReferencing%3DE1D4C003A0.private preserve=yes
      //## end CWCCommandReferencing%3DE1D4C003A0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandReferencing%3DE1D4C003A0.implementation preserve=yes
      //## end CWCCommandReferencing%3DE1D4C003A0.implementation

};

//## begin CWCCommandReferencing%3DE1D4C003A0.postscript preserve=yes
//## end CWCCommandReferencing%3DE1D4C003A0.postscript

//## begin CWCCommandStart%3DE23608004A.preface preserve=yes
//## end CWCCommandStart%3DE23608004A.preface

//## Class: CWCCommandStart%3DE23608004A
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE23E84021F;CCOSyncObject { -> }

class CWCCommandStart : public CWCCommand  //## Inherits: <unnamed>%3DE2363C003B
{
  //## begin CWCCommandStart%3DE23608004A.initialDeclarations preserve=yes
  //## end CWCCommandStart%3DE23608004A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandStart%1038217311
      CWCCommandStart (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommandStart();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1038217313
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1038217312
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

      //## Operation: AttachException%1077175171
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

    // Additional Public Declarations
      //## begin CWCCommandStart%3DE23608004A.public preserve=yes
      //## end CWCCommandStart%3DE23608004A.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandStart%3DE23608004A.protected preserve=yes
      //## end CWCCommandStart%3DE23608004A.protected

  private:
    //## Constructors (generated)
      CWCCommandStart();

      CWCCommandStart(const CWCCommandStart &right);

    //## Assignment Operation (generated)
      const CWCCommandStart & operator=(const CWCCommandStart &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandStart &right) const;

      bool operator!=(const CWCCommandStart &right) const;

    // Additional Private Declarations
      //## begin CWCCommandStart%3DE23608004A.private preserve=yes
      //## end CWCCommandStart%3DE23608004A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandStart%3DE23608004A.implementation preserve=yes
      //## end CWCCommandStart%3DE23608004A.implementation

};

//## begin CWCCommandStart%3DE23608004A.postscript preserve=yes
//## end CWCCommandStart%3DE23608004A.postscript

//## begin CWCCommandSetProfile%3DE23B6101C1.preface preserve=yes
//## end CWCCommandSetProfile%3DE23B6101C1.preface

//## Class: CWCCommandSetProfile%3DE23B6101C1
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandSetProfile : public CWCCommand  //## Inherits: <unnamed>%3DE23B6D0329
{
  //## begin CWCCommandSetProfile%3DE23B6101C1.initialDeclarations preserve=yes
  //## end CWCCommandSetProfile%3DE23B6101C1.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandSetProfile%1038217315
      CWCCommandSetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile);

    //## Destructor (generated)
      virtual ~CWCCommandSetProfile();


    //## Other Operations (specified)
      //## Operation: Execute%1038217316
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandSetProfile%3DE23B6101C1.public preserve=yes
      //## end CWCCommandSetProfile%3DE23B6101C1.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandSetProfile%3DE23B6101C1.protected preserve=yes
      //## end CWCCommandSetProfile%3DE23B6101C1.protected

  private:
    //## Constructors (generated)
      CWCCommandSetProfile();

      CWCCommandSetProfile(const CWCCommandSetProfile &right);

    //## Assignment Operation (generated)
      const CWCCommandSetProfile & operator=(const CWCCommandSetProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandSetProfile &right) const;

      bool operator!=(const CWCCommandSetProfile &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3DE247D5000C
      //## Role: CWCCommandSetProfile::pProfile%3DE247D5027E
      //## begin CWCCommandSetProfile::pProfile%3DE247D5027E.role preserve=no  public: CPIWedgeControlProfile {1..1 -> 1..1RFHN}
      CPIWedgeControlProfile *m_pProfile;
      //## end CWCCommandSetProfile::pProfile%3DE247D5027E.role

    // Additional Private Declarations
      //## begin CWCCommandSetProfile%3DE23B6101C1.private preserve=yes
      //## end CWCCommandSetProfile%3DE23B6101C1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandSetProfile%3DE23B6101C1.implementation preserve=yes
      //## end CWCCommandSetProfile%3DE23B6101C1.implementation

};

//## begin CWCCommandSetProfile%3DE23B6101C1.postscript preserve=yes
//## end CWCCommandSetProfile%3DE23B6101C1.postscript

//## begin CWCCommandInitialize%3DE2438101F0.preface preserve=yes
//## end CWCCommandInitialize%3DE2438101F0.preface

//## Class: CWCCommandInitialize%3DE2438101F0
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandInitialize : public CWCCommand  //## Inherits: <unnamed>%3DE24391024E
{
  //## begin CWCCommandInitialize%3DE2438101F0.initialDeclarations preserve=yes
  //## end CWCCommandInitialize%3DE2438101F0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandInitialize%1038217319
      CWCCommandInitialize (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommandInitialize();


    //## Other Operations (specified)
      //## Operation: Execute%1038217320
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandInitialize%3DE2438101F0.public preserve=yes
      //## end CWCCommandInitialize%3DE2438101F0.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandInitialize%3DE2438101F0.protected preserve=yes
      //## end CWCCommandInitialize%3DE2438101F0.protected

  private:
    //## Constructors (generated)
      CWCCommandInitialize();

      CWCCommandInitialize(const CWCCommandInitialize &right);

    //## Assignment Operation (generated)
      const CWCCommandInitialize & operator=(const CWCCommandInitialize &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandInitialize &right) const;

      bool operator!=(const CWCCommandInitialize &right) const;

    // Additional Private Declarations
      //## begin CWCCommandInitialize%3DE2438101F0.private preserve=yes
      //## end CWCCommandInitialize%3DE2438101F0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandInitialize%3DE2438101F0.implementation preserve=yes
      //## end CWCCommandInitialize%3DE2438101F0.implementation

};

//## begin CWCCommandInitialize%3DE2438101F0.postscript preserve=yes
//## end CWCCommandInitialize%3DE2438101F0.postscript

//## begin CWCCommandConnectionEstablished%3F60108103D8.preface preserve=yes
//## end CWCCommandConnectionEstablished%3F60108103D8.preface

//## Class: CWCCommandConnectionEstablished%3F60108103D8
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandConnectionEstablished : public CWCCommand  //## Inherits: <unnamed>%3F60109100EA
{
  //## begin CWCCommandConnectionEstablished%3F60108103D8.initialDeclarations preserve=yes
  //## end CWCCommandConnectionEstablished%3F60108103D8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandConnectionEstablished%1063260185
      CWCCommandConnectionEstablished (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommandConnectionEstablished();


    //## Other Operations (specified)
      //## Operation: Execute%1063260186
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandConnectionEstablished%3F60108103D8.public preserve=yes
      //## end CWCCommandConnectionEstablished%3F60108103D8.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandConnectionEstablished%3F60108103D8.protected preserve=yes
      //## end CWCCommandConnectionEstablished%3F60108103D8.protected

  private:
    //## Constructors (generated)
      CWCCommandConnectionEstablished();

      CWCCommandConnectionEstablished(const CWCCommandConnectionEstablished &right);

    //## Assignment Operation (generated)
      const CWCCommandConnectionEstablished & operator=(const CWCCommandConnectionEstablished &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandConnectionEstablished &right) const;

      bool operator!=(const CWCCommandConnectionEstablished &right) const;

    // Additional Private Declarations
      //## begin CWCCommandConnectionEstablished%3F60108103D8.private preserve=yes
      //## end CWCCommandConnectionEstablished%3F60108103D8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandConnectionEstablished%3F60108103D8.implementation preserve=yes
      //## end CWCCommandConnectionEstablished%3F60108103D8.implementation

};

//## begin CWCCommandConnectionEstablished%3F60108103D8.postscript preserve=yes
//## end CWCCommandConnectionEstablished%3F60108103D8.postscript

//## begin CWCCommandConnectionLost%3F6010E10000.preface preserve=yes
//## end CWCCommandConnectionLost%3F6010E10000.preface

//## Class: CWCCommandConnectionLost%3F6010E10000
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandConnectionLost : public CWCCommand  //## Inherits: <unnamed>%3F6010EB0271
{
  //## begin CWCCommandConnectionLost%3F6010E10000.initialDeclarations preserve=yes
  //## end CWCCommandConnectionLost%3F6010E10000.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandConnectionLost%1063260187
      CWCCommandConnectionLost (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommandConnectionLost();


    //## Other Operations (specified)
      //## Operation: Execute%1063260188
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandConnectionLost%3F6010E10000.public preserve=yes
      //## end CWCCommandConnectionLost%3F6010E10000.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandConnectionLost%3F6010E10000.protected preserve=yes
      //## end CWCCommandConnectionLost%3F6010E10000.protected

  private:
    //## Constructors (generated)
      CWCCommandConnectionLost();

      CWCCommandConnectionLost(const CWCCommandConnectionLost &right);

    //## Assignment Operation (generated)
      const CWCCommandConnectionLost & operator=(const CWCCommandConnectionLost &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandConnectionLost &right) const;

      bool operator!=(const CWCCommandConnectionLost &right) const;

    // Additional Private Declarations
      //## begin CWCCommandConnectionLost%3F6010E10000.private preserve=yes
      //## end CWCCommandConnectionLost%3F6010E10000.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandConnectionLost%3F6010E10000.implementation preserve=yes
      //## end CWCCommandConnectionLost%3F6010E10000.implementation

};

//## begin CWCCommandConnectionLost%3F6010E10000.postscript preserve=yes
//## end CWCCommandConnectionLost%3F6010E10000.postscript

//## begin CWCCommandGetDacZeroCurrent%447EAA32014F.preface preserve=yes
//## end CWCCommandGetDacZeroCurrent%447EAA32014F.preface

//## Class: CWCCommandGetDacZeroCurrent%447EAA32014F
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCCommandGetDacZeroCurrent : public CWCCommand  //## Inherits: <unnamed>%447EAA54020C
{
  //## begin CWCCommandGetDacZeroCurrent%447EAA32014F.initialDeclarations preserve=yes
  //## end CWCCommandGetDacZeroCurrent%447EAA32014F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCCommandGetDacZeroCurrent%1149148974
      CWCCommandGetDacZeroCurrent (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCCommandGetDacZeroCurrent();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1149148976
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1149159895
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CWCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CWCCommandGetDacZeroCurrent%447EAA32014F.public preserve=yes
      //## end CWCCommandGetDacZeroCurrent%447EAA32014F.public

  protected:
    // Additional Protected Declarations
      //## begin CWCCommandGetDacZeroCurrent%447EAA32014F.protected preserve=yes
      //## end CWCCommandGetDacZeroCurrent%447EAA32014F.protected

  private:
    //## Constructors (generated)
      CWCCommandGetDacZeroCurrent(const CWCCommandGetDacZeroCurrent &right);

    //## Assignment Operation (generated)
      const CWCCommandGetDacZeroCurrent & operator=(const CWCCommandGetDacZeroCurrent &right);

    //## Equality Operations (generated)
      bool operator==(const CWCCommandGetDacZeroCurrent &right) const;

      bool operator!=(const CWCCommandGetDacZeroCurrent &right) const;

    // Additional Private Declarations
      //## begin CWCCommandGetDacZeroCurrent%447EAA32014F.private preserve=yes
      //## end CWCCommandGetDacZeroCurrent%447EAA32014F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCCommandGetDacZeroCurrent%447EAA32014F.implementation preserve=yes
      //## end CWCCommandGetDacZeroCurrent%447EAA32014F.implementation

};

//## begin CWCCommandGetDacZeroCurrent%447EAA32014F.postscript preserve=yes
//## end CWCCommandGetDacZeroCurrent%447EAA32014F.postscript

// Class CWCCommand 

// Class CWCCommandSetConfiguration 

// Class CWCCommandStop 

// Class CWCCommandReferencing 

// Class CWCCommandStart 

// Class CWCCommandSetProfile 

// Class CWCCommandInitialize 

// Class CWCCommandConnectionEstablished 

// Class CWCCommandConnectionLost 

// Class CWCCommandGetDacZeroCurrent 

//## begin module%3DD39EA203A6.epilog preserve=yes
//## end module%3DD39EA203A6.epilog


#endif
