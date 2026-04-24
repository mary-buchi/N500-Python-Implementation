//## begin module%3EDC5B3C01DE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01DE.cm

//## begin module%3EDC5B3C01DE.cp preserve=no
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
//## end module%3EDC5B3C01DE.cp

//## Module: EBSYcomd%3EDC5B3C01DE; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcomd.h

#ifndef EBSYcomd_h
#define EBSYcomd_h 1

//## begin module%3EDC5B3C01DE.additionalIncludes preserve=no
//## end module%3EDC5B3C01DE.additionalIncludes

//## begin module%3EDC5B3C01DE.includes preserve=yes
//## end module%3EDC5B3C01DE.includes

// EBCOcomd
#include "EBCOcomd.h"

class EBPI_DLL_DECL CPIPersistentSoftwareComponent;
class EBPI_DLL_DECL CPIInterfaceConfig;
class EBPI_DLL_DECL CPIPersistentSoftwareComponentList;
class CSYState;

//## begin module%3EDC5B3C01DE.declarations preserve=no
//## end module%3EDC5B3C01DE.declarations

//## begin module%3EDC5B3C01DE.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01DE.additionalDeclarations


//## begin CSYCommand%3EDC5B9C0240.preface preserve=yes
//## end CSYCommand%3EDC5B9C0240.preface

//## Class: CSYCommand%3EDC5B9C0240
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EDC5B9C0245;CSYState { -> F}

class CSYCommand : public CCOCommand  //## Inherits: <unnamed>%3EDC5B9C0242
{
  //## begin CSYCommand%3EDC5B9C0240.initialDeclarations preserve=yes
  //## end CSYCommand%3EDC5B9C0240.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommand%1038899362
      CSYCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1038899363
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

      //## Operation: Execute%1038899364
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState) = 0;

    // Additional Public Declarations
      //## begin CSYCommand%3EDC5B9C0240.public preserve=yes
      //## end CSYCommand%3EDC5B9C0240.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommand%3EDC5B9C0240.protected preserve=yes
      //## end CSYCommand%3EDC5B9C0240.protected

  private:
    //## Constructors (generated)
      CSYCommand();

      CSYCommand(const CSYCommand &right);

    //## Assignment Operation (generated)
      const CSYCommand & operator=(const CSYCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommand &right) const;

      bool operator!=(const CSYCommand &right) const;

    // Additional Private Declarations
      //## begin CSYCommand%3EDC5B9C0240.private preserve=yes
      //## end CSYCommand%3EDC5B9C0240.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommand%3EDC5B9C0240.implementation preserve=yes
      //## end CSYCommand%3EDC5B9C0240.implementation

};

//## begin CSYCommand%3EDC5B9C0240.postscript preserve=yes
//## end CSYCommand%3EDC5B9C0240.postscript

//## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.preface preserve=yes
//## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.preface

//## Class: CSYCommandSetInterfaceConfig%3EDC5B9C0261
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandSetInterfaceConfig : public CSYCommand  //## Inherits: <unnamed>%3EDC5B9C0263
{
  //## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.initialDeclarations preserve=yes
  //## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandSetInterfaceConfig%1039429751
      CSYCommandSetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig);

    //## Destructor (generated)
      virtual ~CSYCommandSetInterfaceConfig();


    //## Other Operations (specified)
      //## Operation: Execute%1039429753
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.public preserve=yes
      //## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.protected preserve=yes
      //## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.protected

  private:
    //## Constructors (generated)
      CSYCommandSetInterfaceConfig();

      CSYCommandSetInterfaceConfig(const CSYCommandSetInterfaceConfig &right);

    //## Assignment Operation (generated)
      const CSYCommandSetInterfaceConfig & operator=(const CSYCommandSetInterfaceConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandSetInterfaceConfig &right) const;

      bool operator!=(const CSYCommandSetInterfaceConfig &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EE711170044
      //## Role: CSYCommandSetInterfaceConfig::pInterfaceConfig%3EE7111701FB
      //## begin CSYCommandSetInterfaceConfig::pInterfaceConfig%3EE7111701FB.role preserve=no  public: CPIInterfaceConfig {1..1 -> 1..1RFHN}
      CPIInterfaceConfig *m_pInterfaceConfig;
      //## end CSYCommandSetInterfaceConfig::pInterfaceConfig%3EE7111701FB.role

    // Additional Private Declarations
      //## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.private preserve=yes
      //## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.implementation preserve=yes
      //## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.implementation

};

//## begin CSYCommandSetInterfaceConfig%3EDC5B9C0261.postscript preserve=yes
//## end CSYCommandSetInterfaceConfig%3EDC5B9C0261.postscript

//## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.preface preserve=yes
//## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.preface

//## Class: CSYCommandDownloadSoftwareComponents%3DF46F0C01FF
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandDownloadSoftwareComponents : public CSYCommand  //## Inherits: <unnamed>%3EE71BCF01A4
{
  //## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.initialDeclarations preserve=yes
  //## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandDownloadSoftwareComponents%1039429736
      CSYCommandDownloadSoftwareComponents (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponentList* p_pComponentList);

    //## Destructor (generated)
      virtual ~CSYCommandDownloadSoftwareComponents();


    //## Other Operations (specified)
      //## Operation: Execute%1039429737
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.public preserve=yes
      //## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.protected preserve=yes
      //## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.protected

  private:
    //## Constructors (generated)
      CSYCommandDownloadSoftwareComponents();

      CSYCommandDownloadSoftwareComponents(const CSYCommandDownloadSoftwareComponents &right);

    //## Assignment Operation (generated)
      const CSYCommandDownloadSoftwareComponents & operator=(const CSYCommandDownloadSoftwareComponents &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandDownloadSoftwareComponents &right) const;

      bool operator!=(const CSYCommandDownloadSoftwareComponents &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EF1B925009B
      //## Role: CSYCommandDownloadSoftwareComponents::pPersistentSoftwareComponentList%3EF1B9270137
      //## begin CSYCommandDownloadSoftwareComponents::pPersistentSoftwareComponentList%3EF1B9270137.role preserve=no  public: CPIPersistentSoftwareComponentList {1..1 -> 1..1RFHN}
      CPIPersistentSoftwareComponentList *m_pPersistentSoftwareComponentList;
      //## end CSYCommandDownloadSoftwareComponents::pPersistentSoftwareComponentList%3EF1B9270137.role

    // Additional Private Declarations
      //## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.private preserve=yes
      //## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.implementation preserve=yes
      //## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.implementation

};

//## begin CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.postscript preserve=yes
//## end CSYCommandDownloadSoftwareComponents%3DF46F0C01FF.postscript

//## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.preface preserve=yes
//## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.preface

//## Class: CSYCommandReadSoftwareVersions%3DF46AEE03E3
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandReadSoftwareVersions : public CSYCommand  //## Inherits: <unnamed>%3EE716DB01E1
{
  //## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.initialDeclarations preserve=yes
  //## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandReadSoftwareVersions%1039418961
      CSYCommandReadSoftwareVersions (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandReadSoftwareVersions();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1039418962
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1039418963
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.public preserve=yes
      //## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.protected preserve=yes
      //## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.protected

  private:
    //## Constructors (generated)
      CSYCommandReadSoftwareVersions();

      CSYCommandReadSoftwareVersions(const CSYCommandReadSoftwareVersions &right);

    //## Assignment Operation (generated)
      const CSYCommandReadSoftwareVersions & operator=(const CSYCommandReadSoftwareVersions &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandReadSoftwareVersions &right) const;

      bool operator!=(const CSYCommandReadSoftwareVersions &right) const;

    // Additional Private Declarations
      //## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.private preserve=yes
      //## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.implementation preserve=yes
      //## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.implementation

};

//## begin CSYCommandReadSoftwareVersions%3DF46AEE03E3.postscript preserve=yes
//## end CSYCommandReadSoftwareVersions%3DF46AEE03E3.postscript

//## begin CSYCommandStartDevice%3EE84D2C0317.preface preserve=yes
//## end CSYCommandStartDevice%3EE84D2C0317.preface

//## Class: CSYCommandStartDevice%3EE84D2C0317
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandStartDevice : public CSYCommand  //## Inherits: <unnamed>%3EE84D2C0318
{
  //## begin CSYCommandStartDevice%3EE84D2C0317.initialDeclarations preserve=yes
  //## end CSYCommandStartDevice%3EE84D2C0317.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandStartDevice%1055402512
      CSYCommandStartDevice (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandStartDevice();


    //## Other Operations (specified)
      //## Operation: Execute%1055402513
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandStartDevice%3EE84D2C0317.public preserve=yes
      //## end CSYCommandStartDevice%3EE84D2C0317.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandStartDevice%3EE84D2C0317.protected preserve=yes
      //## end CSYCommandStartDevice%3EE84D2C0317.protected

  private:
    //## Constructors (generated)
      CSYCommandStartDevice();

      CSYCommandStartDevice(const CSYCommandStartDevice &right);

    //## Assignment Operation (generated)
      const CSYCommandStartDevice & operator=(const CSYCommandStartDevice &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandStartDevice &right) const;

      bool operator!=(const CSYCommandStartDevice &right) const;

    // Additional Private Declarations
      //## begin CSYCommandStartDevice%3EE84D2C0317.private preserve=yes
      //## end CSYCommandStartDevice%3EE84D2C0317.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandStartDevice%3EE84D2C0317.implementation preserve=yes
      //## end CSYCommandStartDevice%3EE84D2C0317.implementation

};

//## begin CSYCommandStartDevice%3EE84D2C0317.postscript preserve=yes
//## end CSYCommandStartDevice%3EE84D2C0317.postscript

//## begin CSYCommandResetDevice%3EE84D5B0327.preface preserve=yes
//## end CSYCommandResetDevice%3EE84D5B0327.preface

//## Class: CSYCommandResetDevice%3EE84D5B0327
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandResetDevice : public CSYCommand  //## Inherits: <unnamed>%3EE84D5B0328
{
  //## begin CSYCommandResetDevice%3EE84D5B0327.initialDeclarations preserve=yes
  //## end CSYCommandResetDevice%3EE84D5B0327.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandResetDevice%1055402514
      CSYCommandResetDevice (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandResetDevice();


    //## Other Operations (specified)
      //## Operation: Execute%1055402515
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

      //## Operation: SignalExecution%1064337358
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
      //## begin CSYCommandResetDevice%3EE84D5B0327.public preserve=yes
      //## end CSYCommandResetDevice%3EE84D5B0327.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandResetDevice%3EE84D5B0327.protected preserve=yes
      //## end CSYCommandResetDevice%3EE84D5B0327.protected

  private:
    //## Constructors (generated)
      CSYCommandResetDevice();

      CSYCommandResetDevice(const CSYCommandResetDevice &right);

    //## Assignment Operation (generated)
      const CSYCommandResetDevice & operator=(const CSYCommandResetDevice &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandResetDevice &right) const;

      bool operator!=(const CSYCommandResetDevice &right) const;

    // Additional Private Declarations
      //## begin CSYCommandResetDevice%3EE84D5B0327.private preserve=yes
      //## end CSYCommandResetDevice%3EE84D5B0327.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandResetDevice%3EE84D5B0327.implementation preserve=yes
      //## end CSYCommandResetDevice%3EE84D5B0327.implementation

};

//## begin CSYCommandResetDevice%3EE84D5B0327.postscript preserve=yes
//## end CSYCommandResetDevice%3EE84D5B0327.postscript

//## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.preface preserve=yes
//## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.preface

//## Class: CSYCommandSetStandbyTimeout%3EFC3FEA010B
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandSetStandbyTimeout : public CSYCommand  //## Inherits: <unnamed>%3EFC3FEA010C
{
  //## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.initialDeclarations preserve=yes
  //## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandSetStandbyTimeout%1056695974
      CSYCommandSetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeOut);

    //## Destructor (generated)
      virtual ~CSYCommandSetStandbyTimeout();


    //## Other Operations (specified)
      //## Operation: Execute%1056695975
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.public preserve=yes
      //## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.protected preserve=yes
      //## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.protected

  private:
    //## Constructors (generated)
      CSYCommandSetStandbyTimeout();

      CSYCommandSetStandbyTimeout(const CSYCommandSetStandbyTimeout &right);

    //## Assignment Operation (generated)
      const CSYCommandSetStandbyTimeout & operator=(const CSYCommandSetStandbyTimeout &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandSetStandbyTimeout &right) const;

      bool operator!=(const CSYCommandSetStandbyTimeout &right) const;

    // Data Members for Class Attributes

      //## Attribute: uiTimeout%3EFC40490244
      //## begin CSYCommandSetStandbyTimeout::uiTimeout%3EFC40490244.attr preserve=no  private: unsigned int {U} 
      unsigned int m_uiTimeout;
      //## end CSYCommandSetStandbyTimeout::uiTimeout%3EFC40490244.attr

    // Additional Private Declarations
      //## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.private preserve=yes
      //## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.implementation preserve=yes
      //## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.implementation

};

//## begin CSYCommandSetStandbyTimeout%3EFC3FEA010B.postscript preserve=yes
//## end CSYCommandSetStandbyTimeout%3EFC3FEA010B.postscript

//## begin CSYCommandSetComponentState%3F42377E0312.preface preserve=yes
//## end CSYCommandSetComponentState%3F42377E0312.preface

//## Class: CSYCommandSetComponentState%3F42377E0312
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandSetComponentState : public CSYCommand  //## Inherits: <unnamed>%3F42377E0313
{
  //## begin CSYCommandSetComponentState%3F42377E0312.initialDeclarations preserve=yes
  //## end CSYCommandSetComponentState%3F42377E0312.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandSetComponentState%1061301414
      CSYCommandSetComponentState (ICOStateMachineContext* p_pContext, const CString& p_sComponentId, const bool p_bActive);

    //## Destructor (generated)
      virtual ~CSYCommandSetComponentState();


    //## Other Operations (specified)
      //## Operation: Execute%1061301415
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandSetComponentState%3F42377E0312.public preserve=yes
      //## end CSYCommandSetComponentState%3F42377E0312.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandSetComponentState%3F42377E0312.protected preserve=yes
      //## end CSYCommandSetComponentState%3F42377E0312.protected

  private:
    //## Constructors (generated)
      CSYCommandSetComponentState();

      CSYCommandSetComponentState(const CSYCommandSetComponentState &right);

    //## Assignment Operation (generated)
      const CSYCommandSetComponentState & operator=(const CSYCommandSetComponentState &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandSetComponentState &right) const;

      bool operator!=(const CSYCommandSetComponentState &right) const;

    // Data Members for Class Attributes

      //## Attribute: sComponentId%3F4315360351
      //## begin CSYCommandSetComponentState::sComponentId%3F4315360351.attr preserve=no  private: CString {U} 
      CString m_sComponentId;
      //## end CSYCommandSetComponentState::sComponentId%3F4315360351.attr

      //## Attribute: bActive%3F4314EC0295
      //## begin CSYCommandSetComponentState::bActive%3F4314EC0295.attr preserve=no  private: bool {U} 
      bool m_bActive;
      //## end CSYCommandSetComponentState::bActive%3F4314EC0295.attr

    // Additional Private Declarations
      //## begin CSYCommandSetComponentState%3F42377E0312.private preserve=yes
      //## end CSYCommandSetComponentState%3F42377E0312.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandSetComponentState%3F42377E0312.implementation preserve=yes
      //## end CSYCommandSetComponentState%3F42377E0312.implementation

};

//## begin CSYCommandSetComponentState%3F42377E0312.postscript preserve=yes
//## end CSYCommandSetComponentState%3F42377E0312.postscript

//## begin CSYCommandGetObjectList%3F6708D90200.preface preserve=yes
//## end CSYCommandGetObjectList%3F6708D90200.preface

//## Class: CSYCommandGetObjectList%3F6708D90200
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandGetObjectList : public CSYCommand  //## Inherits: <unnamed>%3F67090F028D
{
  //## begin CSYCommandGetObjectList%3F6708D90200.initialDeclarations preserve=yes
  //## end CSYCommandGetObjectList%3F6708D90200.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandGetObjectList%1063715458
      CSYCommandGetObjectList (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandGetObjectList();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1063715459
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1063715460
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandGetObjectList%3F6708D90200.public preserve=yes
      //## end CSYCommandGetObjectList%3F6708D90200.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandGetObjectList%3F6708D90200.protected preserve=yes
      //## end CSYCommandGetObjectList%3F6708D90200.protected

  private:
    //## Constructors (generated)
      CSYCommandGetObjectList();

      CSYCommandGetObjectList(const CSYCommandGetObjectList &right);

    //## Assignment Operation (generated)
      const CSYCommandGetObjectList & operator=(const CSYCommandGetObjectList &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandGetObjectList &right) const;

      bool operator!=(const CSYCommandGetObjectList &right) const;

    // Additional Private Declarations
      //## begin CSYCommandGetObjectList%3F6708D90200.private preserve=yes
      //## end CSYCommandGetObjectList%3F6708D90200.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandGetObjectList%3F6708D90200.implementation preserve=yes
      //## end CSYCommandGetObjectList%3F6708D90200.implementation

};

//## begin CSYCommandGetObjectList%3F6708D90200.postscript preserve=yes
//## end CSYCommandGetObjectList%3F6708D90200.postscript

//## begin CSYCommandSetSystemTime%3F71EAAB03CD.preface preserve=yes
//## end CSYCommandSetSystemTime%3F71EAAB03CD.preface

//## Class: CSYCommandSetSystemTime%3F71EAAB03CD
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandSetSystemTime : public CSYCommand  //## Inherits: <unnamed>%3F71EAD20011
{
  //## begin CSYCommandSetSystemTime%3F71EAAB03CD.initialDeclarations preserve=yes
  //## end CSYCommandSetSystemTime%3F71EAAB03CD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandSetSystemTime%1064429415
      CSYCommandSetSystemTime (ICOStateMachineContext* p_pContext, const SYSTEMTIME& p_SystemTime);

    //## Destructor (generated)
      virtual ~CSYCommandSetSystemTime();


    //## Other Operations (specified)
      //## Operation: Execute%1064429416
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandSetSystemTime%3F71EAAB03CD.public preserve=yes
      //## end CSYCommandSetSystemTime%3F71EAAB03CD.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandSetSystemTime%3F71EAAB03CD.protected preserve=yes
      //## end CSYCommandSetSystemTime%3F71EAAB03CD.protected

  private:
    //## Constructors (generated)
      CSYCommandSetSystemTime();

      CSYCommandSetSystemTime(const CSYCommandSetSystemTime &right);

    //## Assignment Operation (generated)
      const CSYCommandSetSystemTime & operator=(const CSYCommandSetSystemTime &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandSetSystemTime &right) const;

      bool operator!=(const CSYCommandSetSystemTime &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3F71EB0100AF
      //## Role: CSYCommandSetSystemTime::SystemTime%3F71EB0102CD
      //## begin CSYCommandSetSystemTime::SystemTime%3F71EB0102CD.role preserve=no  public: SYSTEMTIME {1..1 -> 1..1VFHN}
      SYSTEMTIME m_SystemTime;
      //## end CSYCommandSetSystemTime::SystemTime%3F71EB0102CD.role

    // Additional Private Declarations
      //## begin CSYCommandSetSystemTime%3F71EAAB03CD.private preserve=yes
      //## end CSYCommandSetSystemTime%3F71EAAB03CD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandSetSystemTime%3F71EAAB03CD.implementation preserve=yes
      //## end CSYCommandSetSystemTime%3F71EAAB03CD.implementation

};

//## begin CSYCommandSetSystemTime%3F71EAAB03CD.postscript preserve=yes
//## end CSYCommandSetSystemTime%3F71EAAB03CD.postscript

//## begin CSYCommandRegisterClient%415DA6560176.preface preserve=yes
//## end CSYCommandRegisterClient%415DA6560176.preface

//## Class: CSYCommandRegisterClient%415DA6560176
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandRegisterClient : public CSYCommand  //## Inherits: <unnamed>%415DA66302DD
{
  //## begin CSYCommandRegisterClient%415DA6560176.initialDeclarations preserve=yes
  //## end CSYCommandRegisterClient%415DA6560176.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandRegisterClient%1096656407
      CSYCommandRegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient);

    //## Destructor (generated)
      virtual ~CSYCommandRegisterClient();


    //## Other Operations (specified)
      //## Operation: Execute%1096656408
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandRegisterClient%415DA6560176.public preserve=yes
      //## end CSYCommandRegisterClient%415DA6560176.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandRegisterClient%415DA6560176.protected preserve=yes
      //## end CSYCommandRegisterClient%415DA6560176.protected

  private:
    //## Constructors (generated)
      CSYCommandRegisterClient();

      CSYCommandRegisterClient(const CSYCommandRegisterClient &right);

    //## Assignment Operation (generated)
      const CSYCommandRegisterClient & operator=(const CSYCommandRegisterClient &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandRegisterClient &right) const;

      bool operator!=(const CSYCommandRegisterClient &right) const;

    // Data Members for Class Attributes

      //## Attribute: sClient%415DA6A9017F
      //## begin CSYCommandRegisterClient::sClient%415DA6A9017F.attr preserve=no  private: CString {U} p_sClient
      CString m_sClient;
      //## end CSYCommandRegisterClient::sClient%415DA6A9017F.attr

    // Additional Private Declarations
      //## begin CSYCommandRegisterClient%415DA6560176.private preserve=yes
      //## end CSYCommandRegisterClient%415DA6560176.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandRegisterClient%415DA6560176.implementation preserve=yes
      //## end CSYCommandRegisterClient%415DA6560176.implementation

};

//## begin CSYCommandRegisterClient%415DA6560176.postscript preserve=yes
//## end CSYCommandRegisterClient%415DA6560176.postscript

//## begin CSYCommandGetVersion%415E51ED0059.preface preserve=yes
//## end CSYCommandGetVersion%415E51ED0059.preface

//## Class: CSYCommandGetVersion%415E51ED0059
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandGetVersion : public CSYCommand  //## Inherits: <unnamed>%415E521C00BA
{
  //## begin CSYCommandGetVersion%415E51ED0059.initialDeclarations preserve=yes
  //## end CSYCommandGetVersion%415E51ED0059.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandGetVersion%1096656415
      CSYCommandGetVersion (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandGetVersion();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1096656422
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1096656416
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandGetVersion%415E51ED0059.public preserve=yes
      //## end CSYCommandGetVersion%415E51ED0059.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandGetVersion%415E51ED0059.protected preserve=yes
      //## end CSYCommandGetVersion%415E51ED0059.protected

  private:
    //## Constructors (generated)
      CSYCommandGetVersion();

      CSYCommandGetVersion(const CSYCommandGetVersion &right);

    //## Assignment Operation (generated)
      const CSYCommandGetVersion & operator=(const CSYCommandGetVersion &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandGetVersion &right) const;

      bool operator!=(const CSYCommandGetVersion &right) const;

    // Additional Private Declarations
      //## begin CSYCommandGetVersion%415E51ED0059.private preserve=yes
      //## end CSYCommandGetVersion%415E51ED0059.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandGetVersion%415E51ED0059.implementation preserve=yes
      //## end CSYCommandGetVersion%415E51ED0059.implementation

};

//## begin CSYCommandGetVersion%415E51ED0059.postscript preserve=yes
//## end CSYCommandGetVersion%415E51ED0059.postscript

//## begin CSYCommandGetOsVersion%421308920213.preface preserve=yes
//## end CSYCommandGetOsVersion%421308920213.preface

//## Class: CSYCommandGetOsVersion%421308920213
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandGetOsVersion : public CSYCommand  //## Inherits: <unnamed>%421308E900CB
{
  //## begin CSYCommandGetOsVersion%421308920213.initialDeclarations preserve=yes
  //## end CSYCommandGetOsVersion%421308920213.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandGetOsVersion%1108540788
      CSYCommandGetOsVersion (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandGetOsVersion();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1108540789
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1108540790
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandGetOsVersion%421308920213.public preserve=yes
      //## end CSYCommandGetOsVersion%421308920213.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandGetOsVersion%421308920213.protected preserve=yes
      //## end CSYCommandGetOsVersion%421308920213.protected

  private:
    //## Constructors (generated)
      CSYCommandGetOsVersion();

      CSYCommandGetOsVersion(const CSYCommandGetOsVersion &right);

    //## Assignment Operation (generated)
      const CSYCommandGetOsVersion & operator=(const CSYCommandGetOsVersion &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandGetOsVersion &right) const;

      bool operator!=(const CSYCommandGetOsVersion &right) const;

    // Additional Private Declarations
      //## begin CSYCommandGetOsVersion%421308920213.private preserve=yes
      //## end CSYCommandGetOsVersion%421308920213.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandGetOsVersion%421308920213.implementation preserve=yes
      //## end CSYCommandGetOsVersion%421308920213.implementation

};

//## begin CSYCommandGetOsVersion%421308920213.postscript preserve=yes
//## end CSYCommandGetOsVersion%421308920213.postscript

//## begin CSYCommandGetFpgaVersion%4213094B0128.preface preserve=yes
//## end CSYCommandGetFpgaVersion%4213094B0128.preface

//## Class: CSYCommandGetFpgaVersion%4213094B0128
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandGetFpgaVersion : public CSYCommand  //## Inherits: <unnamed>%421309520399
{
  //## begin CSYCommandGetFpgaVersion%4213094B0128.initialDeclarations preserve=yes
  //## end CSYCommandGetFpgaVersion%4213094B0128.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandGetFpgaVersion%1108540791
      CSYCommandGetFpgaVersion (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandGetFpgaVersion();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1108540792
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1108540793
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandGetFpgaVersion%4213094B0128.public preserve=yes
      //## end CSYCommandGetFpgaVersion%4213094B0128.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandGetFpgaVersion%4213094B0128.protected preserve=yes
      //## end CSYCommandGetFpgaVersion%4213094B0128.protected

  private:
    //## Constructors (generated)
      CSYCommandGetFpgaVersion();

      CSYCommandGetFpgaVersion(const CSYCommandGetFpgaVersion &right);

    //## Assignment Operation (generated)
      const CSYCommandGetFpgaVersion & operator=(const CSYCommandGetFpgaVersion &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandGetFpgaVersion &right) const;

      bool operator!=(const CSYCommandGetFpgaVersion &right) const;

    // Additional Private Declarations
      //## begin CSYCommandGetFpgaVersion%4213094B0128.private preserve=yes
      //## end CSYCommandGetFpgaVersion%4213094B0128.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandGetFpgaVersion%4213094B0128.implementation preserve=yes
      //## end CSYCommandGetFpgaVersion%4213094B0128.implementation

};

//## begin CSYCommandGetFpgaVersion%4213094B0128.postscript preserve=yes
//## end CSYCommandGetFpgaVersion%4213094B0128.postscript

//## begin CSYCommandDownloadSoftwareComponent%478340A2024F.preface preserve=yes
//## end CSYCommandDownloadSoftwareComponent%478340A2024F.preface

//## Class: CSYCommandDownloadSoftwareComponent%478340A2024F
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandDownloadSoftwareComponent : public CSYCommand  //## Inherits: <unnamed>%478340D40125
{
  //## begin CSYCommandDownloadSoftwareComponent%478340A2024F.initialDeclarations preserve=yes
  //## end CSYCommandDownloadSoftwareComponent%478340A2024F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandDownloadSoftwareComponent%1199783734
      CSYCommandDownloadSoftwareComponent (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponent* p_pComponent);

    //## Destructor (generated)
      virtual ~CSYCommandDownloadSoftwareComponent();


    //## Other Operations (specified)
      //## Operation: Execute%1199783735
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandDownloadSoftwareComponent%478340A2024F.public preserve=yes
      //## end CSYCommandDownloadSoftwareComponent%478340A2024F.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandDownloadSoftwareComponent%478340A2024F.protected preserve=yes
      //## end CSYCommandDownloadSoftwareComponent%478340A2024F.protected

  private:
    //## Constructors (generated)
      CSYCommandDownloadSoftwareComponent();

      CSYCommandDownloadSoftwareComponent(const CSYCommandDownloadSoftwareComponent &right);

    //## Assignment Operation (generated)
      const CSYCommandDownloadSoftwareComponent & operator=(const CSYCommandDownloadSoftwareComponent &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandDownloadSoftwareComponent &right) const;

      bool operator!=(const CSYCommandDownloadSoftwareComponent &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%478341E60088
      //## Role: CSYCommandDownloadSoftwareComponent::pComponent%478341E60359
      //## begin CSYCommandDownloadSoftwareComponent::pComponent%478341E60359.role preserve=no  public: CPIPersistentSoftwareComponent {1..1 -> 1..1RFHN}
      CPIPersistentSoftwareComponent *m_pComponent;
      //## end CSYCommandDownloadSoftwareComponent::pComponent%478341E60359.role

    // Additional Private Declarations
      //## begin CSYCommandDownloadSoftwareComponent%478340A2024F.private preserve=yes
      //## end CSYCommandDownloadSoftwareComponent%478340A2024F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandDownloadSoftwareComponent%478340A2024F.implementation preserve=yes
      //## end CSYCommandDownloadSoftwareComponent%478340A2024F.implementation

};

//## begin CSYCommandDownloadSoftwareComponent%478340A2024F.postscript preserve=yes
//## end CSYCommandDownloadSoftwareComponent%478340A2024F.postscript

//## begin CSYCommandStartDownload%478344690137.preface preserve=yes
//## end CSYCommandStartDownload%478344690137.preface

//## Class: CSYCommandStartDownload%478344690137
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandStartDownload : public CSYCommand  //## Inherits: <unnamed>%47834D7600D5
{
  //## begin CSYCommandStartDownload%478344690137.initialDeclarations preserve=yes
  //## end CSYCommandStartDownload%478344690137.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandStartDownload%1199783736
      CSYCommandStartDownload (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandStartDownload();


    //## Other Operations (specified)
      //## Operation: Execute%1199783737
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandStartDownload%478344690137.public preserve=yes
      //## end CSYCommandStartDownload%478344690137.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandStartDownload%478344690137.protected preserve=yes
      //## end CSYCommandStartDownload%478344690137.protected

  private:
    //## Constructors (generated)
      CSYCommandStartDownload();

      CSYCommandStartDownload(const CSYCommandStartDownload &right);

    //## Assignment Operation (generated)
      const CSYCommandStartDownload & operator=(const CSYCommandStartDownload &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandStartDownload &right) const;

      bool operator!=(const CSYCommandStartDownload &right) const;

    // Additional Private Declarations
      //## begin CSYCommandStartDownload%478344690137.private preserve=yes
      //## end CSYCommandStartDownload%478344690137.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandStartDownload%478344690137.implementation preserve=yes
      //## end CSYCommandStartDownload%478344690137.implementation

};

//## begin CSYCommandStartDownload%478344690137.postscript preserve=yes
//## end CSYCommandStartDownload%478344690137.postscript

//## begin CSYCommandEndDownload%47834474002F.preface preserve=yes
//## end CSYCommandEndDownload%47834474002F.preface

//## Class: CSYCommandEndDownload%47834474002F
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYCommandEndDownload : public CSYCommand  //## Inherits: <unnamed>%47834D7F029A
{
  //## begin CSYCommandEndDownload%47834474002F.initialDeclarations preserve=yes
  //## end CSYCommandEndDownload%47834474002F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYCommandEndDownload%1199783738
      CSYCommandEndDownload (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYCommandEndDownload();


    //## Other Operations (specified)
      //## Operation: Execute%1199783739
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSYState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSYCommandEndDownload%47834474002F.public preserve=yes
      //## end CSYCommandEndDownload%47834474002F.public

  protected:
    // Additional Protected Declarations
      //## begin CSYCommandEndDownload%47834474002F.protected preserve=yes
      //## end CSYCommandEndDownload%47834474002F.protected

  private:
    //## Constructors (generated)
      CSYCommandEndDownload();

      CSYCommandEndDownload(const CSYCommandEndDownload &right);

    //## Assignment Operation (generated)
      const CSYCommandEndDownload & operator=(const CSYCommandEndDownload &right);

    //## Equality Operations (generated)
      bool operator==(const CSYCommandEndDownload &right) const;

      bool operator!=(const CSYCommandEndDownload &right) const;

    // Additional Private Declarations
      //## begin CSYCommandEndDownload%47834474002F.private preserve=yes
      //## end CSYCommandEndDownload%47834474002F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYCommandEndDownload%47834474002F.implementation preserve=yes
      //## end CSYCommandEndDownload%47834474002F.implementation

};

//## begin CSYCommandEndDownload%47834474002F.postscript preserve=yes
//## end CSYCommandEndDownload%47834474002F.postscript

// Class CSYCommand 

// Class CSYCommandSetInterfaceConfig 

// Class CSYCommandDownloadSoftwareComponents 

// Class CSYCommandReadSoftwareVersions 

// Class CSYCommandStartDevice 

// Class CSYCommandResetDevice 

// Class CSYCommandSetStandbyTimeout 

// Class CSYCommandSetComponentState 

// Class CSYCommandGetObjectList 

// Class CSYCommandSetSystemTime 

// Class CSYCommandRegisterClient 

// Class CSYCommandGetVersion 

// Class CSYCommandGetOsVersion 

// Class CSYCommandGetFpgaVersion 

// Class CSYCommandDownloadSoftwareComponent 

// Class CSYCommandStartDownload 

// Class CSYCommandEndDownload 

//## begin module%3EDC5B3C01DE.epilog preserve=yes
//## end module%3EDC5B3C01DE.epilog


#endif
