//## begin module%3DAAE8AA03BD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE8AA03BD.cm

//## begin module%3DAAE8AA03BD.cp preserve=no
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
//## end module%3DAAE8AA03BD.cp

//## Module: EBMCcomd%3DAAE8AA03BD; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCcomd.h

#ifndef EBMCcomd_h
#define EBMCcomd_h 1

//## begin module%3DAAE8AA03BD.additionalIncludes preserve=no
//## end module%3DAAE8AA03BD.additionalIncludes

//## begin module%3DAAE8AA03BD.includes preserve=yes
//## end module%3DAAE8AA03BD.includes

// EBCOcomd
#include "EBCOcomd.h"

class EBPI_DLL_DECL CPIMeasurementChannelDataPackage;
class EBPI_DLL_DECL CPIMeasurementChannelProfile;
class CMCState;

//## begin module%3DAAE8AA03BD.declarations preserve=no
//## end module%3DAAE8AA03BD.declarations

//## begin module%3DAAE8AA03BD.additionalDeclarations preserve=yes
//## end module%3DAAE8AA03BD.additionalDeclarations


//## begin CMCCommand%3DAAE8C6012D.preface preserve=yes
//## end CMCCommand%3DAAE8C6012D.preface

//## Class: CMCCommand%3DAAE8C6012D
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAE9110062;CMCState { -> F}

class CMCCommand : public CCOCommand  //## Inherits: <unnamed>%3DAAE8CF019A
{
  //## begin CMCCommand%3DAAE8C6012D.initialDeclarations preserve=yes
  //## end CMCCommand%3DAAE8C6012D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommand%1034575111
      CMCCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1034575112
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

      //## Operation: Execute%1034575113
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState) = 0;

    // Additional Public Declarations
      //## begin CMCCommand%3DAAE8C6012D.public preserve=yes
      //## end CMCCommand%3DAAE8C6012D.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommand%3DAAE8C6012D.protected preserve=yes
      //## end CMCCommand%3DAAE8C6012D.protected

  private:
    //## Constructors (generated)
      CMCCommand();

      CMCCommand(const CMCCommand &right);

    //## Assignment Operation (generated)
      const CMCCommand & operator=(const CMCCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommand &right) const;

      bool operator!=(const CMCCommand &right) const;

    // Additional Private Declarations
      //## begin CMCCommand%3DAAE8C6012D.private preserve=yes
      //## end CMCCommand%3DAAE8C6012D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommand%3DAAE8C6012D.implementation preserve=yes
      //## end CMCCommand%3DAAE8C6012D.implementation

};

//## begin CMCCommand%3DAAE8C6012D.postscript preserve=yes
//## end CMCCommand%3DAAE8C6012D.postscript

//## begin CMCCommandGetDataPackage%3DAE53C0038B.preface preserve=yes
//## end CMCCommandGetDataPackage%3DAE53C0038B.preface

//## Class: CMCCommandGetDataPackage%3DAE53C0038B
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAE583002B8;CPIMeasurementChannelDataPackage { -> F}

class CMCCommandGetDataPackage : public CMCCommand  //## Inherits: <unnamed>%3DAE53D90021
{
  //## begin CMCCommandGetDataPackage%3DAE53C0038B.initialDeclarations preserve=yes
  //## end CMCCommandGetDataPackage%3DAE53C0038B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommandGetDataPackage%1034835014
      CMCCommandGetDataPackage (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCCommandGetDataPackage();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1034835016
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1034835015
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CMCCommandGetDataPackage%3DAE53C0038B.public preserve=yes
      //## end CMCCommandGetDataPackage%3DAE53C0038B.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommandGetDataPackage%3DAE53C0038B.protected preserve=yes
      //## end CMCCommandGetDataPackage%3DAE53C0038B.protected

  private:
    //## Constructors (generated)
      CMCCommandGetDataPackage();

      CMCCommandGetDataPackage(const CMCCommandGetDataPackage &right);

    //## Assignment Operation (generated)
      const CMCCommandGetDataPackage & operator=(const CMCCommandGetDataPackage &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommandGetDataPackage &right) const;

      bool operator!=(const CMCCommandGetDataPackage &right) const;

    // Additional Private Declarations
      //## begin CMCCommandGetDataPackage%3DAE53C0038B.private preserve=yes
      //## end CMCCommandGetDataPackage%3DAE53C0038B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommandGetDataPackage%3DAE53C0038B.implementation preserve=yes
      //## end CMCCommandGetDataPackage%3DAE53C0038B.implementation

};

//## begin CMCCommandGetDataPackage%3DAE53C0038B.postscript preserve=yes
//## end CMCCommandGetDataPackage%3DAE53C0038B.postscript

//## begin CMCCommandStart%3DE4D5700323.preface preserve=yes
//## end CMCCommandStart%3DE4D5700323.preface

//## Class: CMCCommandStart%3DE4D5700323
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCCommandStart : public CMCCommand  //## Inherits: <unnamed>%3DE4D5EC0035
{
  //## begin CMCCommandStart%3DE4D5700323.initialDeclarations preserve=yes
  //## end CMCCommandStart%3DE4D5700323.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommandStart%1038405583
      CMCCommandStart (ICOStateMachineContext* p_pContext, UINT p_uiCycleID);

    //## Destructor (generated)
      virtual ~CMCCommandStart();


    //## Other Operations (specified)
      //## Operation: Execute%1038405584
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CMCCommandStart%3DE4D5700323.public preserve=yes
      //## end CMCCommandStart%3DE4D5700323.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommandStart%3DE4D5700323.protected preserve=yes
      //## end CMCCommandStart%3DE4D5700323.protected

  private:
    //## Constructors (generated)
      CMCCommandStart();

      CMCCommandStart(const CMCCommandStart &right);

    //## Assignment Operation (generated)
      const CMCCommandStart & operator=(const CMCCommandStart &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommandStart &right) const;

      bool operator!=(const CMCCommandStart &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3DE4D6840083
      //## Role: CMCCommandStart::uiCycleID%3DE4D68402D6
      //## begin CMCCommandStart::uiCycleID%3DE4D68402D6.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiCycleID;
      //## end CMCCommandStart::uiCycleID%3DE4D68402D6.role

    // Additional Private Declarations
      //## begin CMCCommandStart%3DE4D5700323.private preserve=yes
      //## end CMCCommandStart%3DE4D5700323.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommandStart%3DE4D5700323.implementation preserve=yes
      //## end CMCCommandStart%3DE4D5700323.implementation

};

//## begin CMCCommandStart%3DE4D5700323.postscript preserve=yes
//## end CMCCommandStart%3DE4D5700323.postscript

//## begin CMCCommandStop%3DE4D58303AF.preface preserve=yes
//## end CMCCommandStop%3DE4D58303AF.preface

//## Class: CMCCommandStop%3DE4D58303AF
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCCommandStop : public CMCCommand  //## Inherits: <unnamed>%3DE4D5F101AC
{
  //## begin CMCCommandStop%3DE4D58303AF.initialDeclarations preserve=yes
  //## end CMCCommandStop%3DE4D58303AF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommandStop%1038405585
      CMCCommandStop (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCCommandStop();


    //## Other Operations (specified)
      //## Operation: Execute%1038405586
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CMCCommandStop%3DE4D58303AF.public preserve=yes
      //## end CMCCommandStop%3DE4D58303AF.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommandStop%3DE4D58303AF.protected preserve=yes
      //## end CMCCommandStop%3DE4D58303AF.protected

  private:
    //## Constructors (generated)
      CMCCommandStop();

      CMCCommandStop(const CMCCommandStop &right);

    //## Assignment Operation (generated)
      const CMCCommandStop & operator=(const CMCCommandStop &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommandStop &right) const;

      bool operator!=(const CMCCommandStop &right) const;

    // Additional Private Declarations
      //## begin CMCCommandStop%3DE4D58303AF.private preserve=yes
      //## end CMCCommandStop%3DE4D58303AF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommandStop%3DE4D58303AF.implementation preserve=yes
      //## end CMCCommandStop%3DE4D58303AF.implementation

};

//## begin CMCCommandStop%3DE4D58303AF.postscript preserve=yes
//## end CMCCommandStop%3DE4D58303AF.postscript

//## begin CMCCommandSetProfile%3DE4D59102F4.preface preserve=yes
//## end CMCCommandSetProfile%3DE4D59102F4.preface

//## Class: CMCCommandSetProfile%3DE4D59102F4
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCCommandSetProfile : public CMCCommand  //## Inherits: <unnamed>%3DE4D5FA0248
{
  //## begin CMCCommandSetProfile%3DE4D59102F4.initialDeclarations preserve=yes
  //## end CMCCommandSetProfile%3DE4D59102F4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommandSetProfile%1038405587
      CMCCommandSetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile);

    //## Destructor (generated)
      virtual ~CMCCommandSetProfile();


    //## Other Operations (specified)
      //## Operation: Execute%1038405588
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CMCCommandSetProfile%3DE4D59102F4.public preserve=yes
      //## end CMCCommandSetProfile%3DE4D59102F4.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommandSetProfile%3DE4D59102F4.protected preserve=yes
      //## end CMCCommandSetProfile%3DE4D59102F4.protected

  private:
    //## Constructors (generated)
      CMCCommandSetProfile();

      CMCCommandSetProfile(const CMCCommandSetProfile &right);

    //## Assignment Operation (generated)
      const CMCCommandSetProfile & operator=(const CMCCommandSetProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommandSetProfile &right) const;

      bool operator!=(const CMCCommandSetProfile &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3DE4D98C00E1
      //## Role: CMCCommandSetProfile::pProfile%3DE4D98C0372
      //## begin CMCCommandSetProfile::pProfile%3DE4D98C0372.role preserve=no  public: CPIMeasurementChannelProfile {1..1 -> 1..1RFHN}
      CPIMeasurementChannelProfile *m_pProfile;
      //## end CMCCommandSetProfile::pProfile%3DE4D98C0372.role

    // Additional Private Declarations
      //## begin CMCCommandSetProfile%3DE4D59102F4.private preserve=yes
      //## end CMCCommandSetProfile%3DE4D59102F4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommandSetProfile%3DE4D59102F4.implementation preserve=yes
      //## end CMCCommandSetProfile%3DE4D59102F4.implementation

};

//## begin CMCCommandSetProfile%3DE4D59102F4.postscript preserve=yes
//## end CMCCommandSetProfile%3DE4D59102F4.postscript

//## begin CMCCommandInitialize%3DE4D5A000F0.preface preserve=yes
//## end CMCCommandInitialize%3DE4D5A000F0.preface

//## Class: CMCCommandInitialize%3DE4D5A000F0
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCCommandInitialize : public CMCCommand  //## Inherits: <unnamed>%3DE4D5FF0110
{
  //## begin CMCCommandInitialize%3DE4D5A000F0.initialDeclarations preserve=yes
  //## end CMCCommandInitialize%3DE4D5A000F0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommandInitialize%1038405589
      CMCCommandInitialize (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCCommandInitialize();


    //## Other Operations (specified)
      //## Operation: Execute%1038405590
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CMCCommandInitialize%3DE4D5A000F0.public preserve=yes
      //## end CMCCommandInitialize%3DE4D5A000F0.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommandInitialize%3DE4D5A000F0.protected preserve=yes
      //## end CMCCommandInitialize%3DE4D5A000F0.protected

  private:
    //## Constructors (generated)
      CMCCommandInitialize();

      CMCCommandInitialize(const CMCCommandInitialize &right);

    //## Assignment Operation (generated)
      const CMCCommandInitialize & operator=(const CMCCommandInitialize &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommandInitialize &right) const;

      bool operator!=(const CMCCommandInitialize &right) const;

    // Additional Private Declarations
      //## begin CMCCommandInitialize%3DE4D5A000F0.private preserve=yes
      //## end CMCCommandInitialize%3DE4D5A000F0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommandInitialize%3DE4D5A000F0.implementation preserve=yes
      //## end CMCCommandInitialize%3DE4D5A000F0.implementation

};

//## begin CMCCommandInitialize%3DE4D5A000F0.postscript preserve=yes
//## end CMCCommandInitialize%3DE4D5A000F0.postscript

//## begin CMCCommandConnectionEstablished%3F60109B02BF.preface preserve=yes
//## end CMCCommandConnectionEstablished%3F60109B02BF.preface

//## Class: CMCCommandConnectionEstablished%3F60109B02BF
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCCommandConnectionEstablished : public CMCCommand  //## Inherits: <unnamed>%3F6010A900BB
{
  //## begin CMCCommandConnectionEstablished%3F60109B02BF.initialDeclarations preserve=yes
  //## end CMCCommandConnectionEstablished%3F60109B02BF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommandConnectionEstablished%1063260181
      CMCCommandConnectionEstablished (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCCommandConnectionEstablished();


    //## Other Operations (specified)
      //## Operation: Execute%1063260182
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CMCCommandConnectionEstablished%3F60109B02BF.public preserve=yes
      //## end CMCCommandConnectionEstablished%3F60109B02BF.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommandConnectionEstablished%3F60109B02BF.protected preserve=yes
      //## end CMCCommandConnectionEstablished%3F60109B02BF.protected

  private:
    //## Constructors (generated)
      CMCCommandConnectionEstablished();

      CMCCommandConnectionEstablished(const CMCCommandConnectionEstablished &right);

    //## Assignment Operation (generated)
      const CMCCommandConnectionEstablished & operator=(const CMCCommandConnectionEstablished &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommandConnectionEstablished &right) const;

      bool operator!=(const CMCCommandConnectionEstablished &right) const;

    // Additional Private Declarations
      //## begin CMCCommandConnectionEstablished%3F60109B02BF.private preserve=yes
      //## end CMCCommandConnectionEstablished%3F60109B02BF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommandConnectionEstablished%3F60109B02BF.implementation preserve=yes
      //## end CMCCommandConnectionEstablished%3F60109B02BF.implementation

};

//## begin CMCCommandConnectionEstablished%3F60109B02BF.postscript preserve=yes
//## end CMCCommandConnectionEstablished%3F60109B02BF.postscript

//## begin CMCCommandConnectionLost%3F6010CC0148.preface preserve=yes
//## end CMCCommandConnectionLost%3F6010CC0148.preface

//## Class: CMCCommandConnectionLost%3F6010CC0148
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCCommandConnectionLost : public CMCCommand  //## Inherits: <unnamed>%3F6010D70399
{
  //## begin CMCCommandConnectionLost%3F6010CC0148.initialDeclarations preserve=yes
  //## end CMCCommandConnectionLost%3F6010CC0148.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCCommandConnectionLost%1063260183
      CMCCommandConnectionLost (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCCommandConnectionLost();


    //## Other Operations (specified)
      //## Operation: Execute%1063260184
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CMCState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CMCCommandConnectionLost%3F6010CC0148.public preserve=yes
      //## end CMCCommandConnectionLost%3F6010CC0148.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCommandConnectionLost%3F6010CC0148.protected preserve=yes
      //## end CMCCommandConnectionLost%3F6010CC0148.protected

  private:
    //## Constructors (generated)
      CMCCommandConnectionLost();

      CMCCommandConnectionLost(const CMCCommandConnectionLost &right);

    //## Assignment Operation (generated)
      const CMCCommandConnectionLost & operator=(const CMCCommandConnectionLost &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCommandConnectionLost &right) const;

      bool operator!=(const CMCCommandConnectionLost &right) const;

    // Additional Private Declarations
      //## begin CMCCommandConnectionLost%3F6010CC0148.private preserve=yes
      //## end CMCCommandConnectionLost%3F6010CC0148.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCommandConnectionLost%3F6010CC0148.implementation preserve=yes
      //## end CMCCommandConnectionLost%3F6010CC0148.implementation

};

//## begin CMCCommandConnectionLost%3F6010CC0148.postscript preserve=yes
//## end CMCCommandConnectionLost%3F6010CC0148.postscript

// Class CMCCommand 

// Class CMCCommandGetDataPackage 

// Class CMCCommandStart 

// Class CMCCommandStop 

// Class CMCCommandSetProfile 

// Class CMCCommandInitialize 

// Class CMCCommandConnectionEstablished 

// Class CMCCommandConnectionLost 

//## begin module%3DAAE8AA03BD.epilog preserve=yes
//## end module%3DAAE8AA03BD.epilog


#endif
