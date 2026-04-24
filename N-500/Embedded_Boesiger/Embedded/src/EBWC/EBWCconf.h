//## begin module%3E38FDF2005D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E38FDF2005D.cm

//## begin module%3E38FDF2005D.cp preserve=no
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
//## end module%3E38FDF2005D.cp

//## Module: EBWCconf%3E38FDF2005D; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCconf.h

#ifndef EBWCconf_h
#define EBWCconf_h 1

//## begin module%3E38FDF2005D.additionalIncludes preserve=no
//## end module%3E38FDF2005D.additionalIncludes

//## begin module%3E38FDF2005D.includes preserve=yes
//## end module%3E38FDF2005D.includes

// EBWCstat
#include "EBWCstat.h"
// EBHITtype
#include "EBHITtype.h"

class EBPI_DLL_DECL CPIWedgeControlConfig;
class EBPI_DLL_DECL CPIWedgeControlProfile;

//## begin module%3E38FDF2005D.declarations preserve=no
//## end module%3E38FDF2005D.declarations

//## begin module%3E38FDF2005D.additionalDeclarations preserve=yes
//## end module%3E38FDF2005D.additionalDeclarations


//## begin CWCStateConfig%3E38FD1000DA.preface preserve=yes
//## end CWCStateConfig%3E38FD1000DA.preface

//## Class: CWCStateConfig%3E38FD1000DA
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E393BA101E4;IHIInterface { -> }
//## Uses: <unnamed>%3E393BB002FD;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E394A8B0119;CWCStateCreated { -> }
//## Uses: <unnamed>%3F602762005D;CWCStateNotConnected { -> }
//## Uses: <unnamed>%3FB4C1E401D4;XWCExceptionError { -> }
//## Uses: <unnamed>%3FBB80520186;CWCActionInitialize { -> }
//## Uses: <unnamed>%3E393C39034B;CHIIOCSetWCConfiguration { -> F}
//## Uses: <unnamed>%3FBCB3FB0232;CHITDACMAX5712 { -> }

class CWCStateConfig : public CWCState  //## Inherits: <unnamed>%3E38FE3100CB
{
  //## begin CWCStateConfig%3E38FD1000DA.initialDeclarations preserve=yes
  //## end CWCStateConfig%3E38FD1000DA.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfig();

    //## Destructor (generated)
      virtual ~CWCStateConfig();


    //## Other Operations (specified)
      //## Operation: Shutdown%1043916999
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupStop%1053065378
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

      //## Operation: CleanupInitialize%1053065379
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

      //## Operation: ConnectionLost%1063260201
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1063723576
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

      //## Operation: SetConfiguration%1066973962
      virtual void SetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig);

      //## Operation: Stop%1076932561
      virtual void Stop (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%3E3936F8032C
      //## Role: CWCStateConfig::pConfig%3E3936F90158
      static CPIWedgeControlConfig * GetpConfig ();
      static void SetpConfig (CPIWedgeControlConfig * value);

      //## Association: EBWC (Wedge Control)::<unnamed>%3E393F99029F
      //## Role: CWCStateConfig::bWCProfileExist%3E393F9A0168
      static const BOOL GetbWCProfileExist ();
      static void SetbWCProfileExist (BOOL value);

      //## Association: EBWC (Wedge Control)::<unnamed>%3ECA2FE203B9
      //## Role: CWCStateConfig::dwRunAfterTime%3ECA2FE301E5
      static const DWORD GetdwRunAfterTime ();
      static void SetdwRunAfterTime (DWORD value);

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB8B250203
      //## Role: CWCStateConfig::pHWConfig%3FBB8B26011A
      static CHIIOCSetWCConfiguration * GetpHWConfig ();
      static void SetpHWConfig (CHIIOCSetWCConfiguration * value);

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBCB26B0186
      //## Role: CWCStateConfig::dwCalibDACOffsetValue%3FBCB26C00BB
      static DWORD GetdwCalibDACOffsetValue ();
      static void SetdwCalibDACOffsetValue (DWORD value);

    // Additional Public Declarations
      //## begin CWCStateConfig%3E38FD1000DA.public preserve=yes
      //## end CWCStateConfig%3E38FD1000DA.public

  protected:
    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E3936F8032C
      //## begin CWCStateConfig::pConfig%3E3936F90158.role preserve=no  public: static CPIWedgeControlConfig {1..1 -> 1..1RFHN}
      static CPIWedgeControlConfig *m_pConfig;
      //## end CWCStateConfig::pConfig%3E3936F90158.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3E393F99029F
      //## begin CWCStateConfig::bWCProfileExist%3E393F9A0168.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
      static BOOL m_bWCProfileExist;
      //## end CWCStateConfig::bWCProfileExist%3E393F9A0168.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3E50F03B01E4
      //## Role: CWCStateConfig::HWDef%3E50F03B03AA
      //## begin CWCStateConfig::HWDef%3E50F03B03AA.role preserve=no  public: static CHITDefinitions {1..1 -> 1..1VHN}
      static CHITDefinitions m_HWDef;
      //## end CWCStateConfig::HWDef%3E50F03B03AA.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3ECA2FE203B9
      //## begin CWCStateConfig::dwRunAfterTime%3ECA2FE301E5.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwRunAfterTime;
      //## end CWCStateConfig::dwRunAfterTime%3ECA2FE301E5.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB8B250203
      //## begin CWCStateConfig::pHWConfig%3FBB8B26011A.role preserve=no  public: static CHIIOCSetWCConfiguration {1..1 -> 1..1RFHN}
      static CHIIOCSetWCConfiguration *m_pHWConfig;
      //## end CWCStateConfig::pHWConfig%3FBB8B26011A.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBCB26B0186
      //## begin CWCStateConfig::dwCalibDACOffsetValue%3FBCB26C00BB.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwCalibDACOffsetValue;
      //## end CWCStateConfig::dwCalibDACOffsetValue%3FBCB26C00BB.role

    // Additional Protected Declarations
      //## begin CWCStateConfig%3E38FD1000DA.protected preserve=yes
      //## end CWCStateConfig%3E38FD1000DA.protected

  private:
    //## Constructors (generated)
      CWCStateConfig(const CWCStateConfig &right);

    //## Assignment Operation (generated)
      const CWCStateConfig & operator=(const CWCStateConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfig &right) const;

      bool operator!=(const CWCStateConfig &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB6F450399
      //## Role: CWCStateConfig::pInstance%3FBB6F490149
      //## begin CWCStateConfig::pInstance%3FBB6F490149.role preserve=no  public: static CWCStateConfig {1..1 -> 1..1RFHN}
      static CWCStateConfig *m_pInstance;
      //## end CWCStateConfig::pInstance%3FBB6F490149.role

    // Additional Private Declarations
      //## begin CWCStateConfig%3E38FD1000DA.private preserve=yes
      //## end CWCStateConfig%3E38FD1000DA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfig%3E38FD1000DA.implementation preserve=yes
      //## end CWCStateConfig%3E38FD1000DA.implementation

};

//## begin CWCStateConfig%3E38FD1000DA.postscript preserve=yes
//## end CWCStateConfig%3E38FD1000DA.postscript

//## begin CWCStateConfiguration%3E39192D001F.preface preserve=yes
//## end CWCStateConfiguration%3E39192D001F.preface

//## Class: CWCStateConfiguration%3E39192D001F
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateConfiguration : public CWCStateConfig  //## Inherits: <unnamed>%3E391948034B
{
  //## begin CWCStateConfiguration%3E39192D001F.initialDeclarations preserve=yes
  //## end CWCStateConfiguration%3E39192D001F.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfiguration();

    //## Destructor (generated)
      virtual ~CWCStateConfiguration();


    //## Other Operations (specified)
      //## Operation: Create%1043917008
      static void Create ();

      //## Operation: Delete%1043917009
      static void Delete ();

      //## Operation: GetInstance%1043917010
      static CWCStateConfiguration* GetInstance ();

      //## Operation: Do%1043917043
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: DebugWriteWCConfigToFile%1065698584
      //	DESCRIPTION:
      //	Help debug function. Writes the WC configuration to the
      //	spec. file.
      void DebugWriteWCConfigToFile (CString p_strFileName, CHIIOCSetWCConfiguration* p_pConfig);

    // Additional Public Declarations
      //## begin CWCStateConfiguration%3E39192D001F.public preserve=yes
      //## end CWCStateConfiguration%3E39192D001F.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateConfiguration%3E39192D001F.protected preserve=yes
      //## end CWCStateConfiguration%3E39192D001F.protected

  private:
    //## Constructors (generated)
      CWCStateConfiguration(const CWCStateConfiguration &right);

    //## Assignment Operation (generated)
      const CWCStateConfiguration & operator=(const CWCStateConfiguration &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfiguration &right) const;

      bool operator!=(const CWCStateConfiguration &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E38FF0B029F
      //## Role: CWCStateConfiguration::pInstance%3E38FF1401A6
      //## begin CWCStateConfiguration::pInstance%3E38FF1401A6.role preserve=no  public: static CWCStateConfiguration {1..1 -> 1..1RFHN}
      static CWCStateConfiguration *m_pInstance;
      //## end CWCStateConfiguration::pInstance%3E38FF1401A6.role

    // Additional Private Declarations
      //## begin CWCStateConfiguration%3E39192D001F.private preserve=yes
      //## end CWCStateConfiguration%3E39192D001F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfiguration%3E39192D001F.implementation preserve=yes
      //## end CWCStateConfiguration%3E39192D001F.implementation

};

//## begin CWCStateConfiguration%3E39192D001F.postscript preserve=yes
//## end CWCStateConfiguration%3E39192D001F.postscript

//## begin CWCStateConfigProfile%3E39197700AB.preface preserve=yes
//## end CWCStateConfigProfile%3E39197700AB.preface

//## Class: CWCStateConfigProfile%3E39197700AB
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E393BC8036B;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E393EE3037A;CHIIOCSetWCProfile { -> F}
//## Uses: <unnamed>%3E39454202CE;CWCStateInitialized { -> }
//## Uses: <unnamed>%3E39454403D8;CWCStateInitializing { -> }
//## Uses: <unnamed>%3E5E19700261;WC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F9D112A00F8;CWCWedgeControlImplementation { -> }

class CWCStateConfigProfile : public CWCStateConfig  //## Inherits: <unnamed>%3E39198F0399
{
  //## begin CWCStateConfigProfile%3E39197700AB.initialDeclarations preserve=yes
  //## end CWCStateConfigProfile%3E39197700AB.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfigProfile();

    //## Destructor (generated)
      virtual ~CWCStateConfigProfile();


    //## Other Operations (specified)
      //## Operation: Create%1043917011
      static void Create ();

      //## Operation: Delete%1043917012
      static void Delete ();

      //## Operation: GetInstance%1043917013
      static CWCStateConfigProfile* GetInstance ();

      //## Operation: Enter%1046351114
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

      //## Operation: Do%1043917047
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: SetProfile%1052978388
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile);

      //## Operation: Initialize%1043917048
      virtual void Initialize (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%3E393D1D01F4
      //## Role: CWCStateConfigProfile::pProfile%3E393D1E0020
      void SetpProfile (CPIWedgeControlProfile * value);

    // Additional Public Declarations
      //## begin CWCStateConfigProfile%3E39197700AB.public preserve=yes
      //## end CWCStateConfigProfile%3E39197700AB.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateConfigProfile%3E39197700AB.protected preserve=yes
      //## end CWCStateConfigProfile%3E39197700AB.protected

  private:
    //## Constructors (generated)
      CWCStateConfigProfile(const CWCStateConfigProfile &right);

    //## Assignment Operation (generated)
      const CWCStateConfigProfile & operator=(const CWCStateConfigProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfigProfile &right) const;

      bool operator!=(const CWCStateConfigProfile &right) const;


    //## Other Operations (specified)
      //## Operation: DebugWriteWCProfileToFile%1065698585
      //	DESCRIPTION:
      //	Help debug function. Writes the WC profile to the spec.
      //	file.
      void DebugWriteWCProfileToFile (CString p_strFileName, CHIIOCSetWCProfile* p_pProfile);

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E39216300EA
      //## Role: CWCStateConfigProfile::pInstance%3E392166030E
      //## begin CWCStateConfigProfile::pInstance%3E392166030E.role preserve=no  public: static CWCStateConfigProfile {1..1 -> 1..1RFHN}
      static CWCStateConfigProfile *m_pInstance;
      //## end CWCStateConfigProfile::pInstance%3E392166030E.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3E393D1D01F4
      //## begin CWCStateConfigProfile::pProfile%3E393D1E0020.role preserve=no  public: CPIWedgeControlProfile {1..1 -> 1..1RFHN}
      CPIWedgeControlProfile *m_pProfile;
      //## end CWCStateConfigProfile::pProfile%3E393D1E0020.role

    // Additional Private Declarations
      //## begin CWCStateConfigProfile%3E39197700AB.private preserve=yes
      //## end CWCStateConfigProfile%3E39197700AB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfigProfile%3E39197700AB.implementation preserve=yes
      //## end CWCStateConfigProfile%3E39197700AB.implementation

};

//## begin CWCStateConfigProfile%3E39197700AB.postscript preserve=yes
//## end CWCStateConfigProfile%3E39197700AB.postscript

//## begin CWCStateConfigNotAssign%3E3927950138.preface preserve=yes
//## end CWCStateConfigNotAssign%3E3927950138.preface

//## Class: CWCStateConfigNotAssign%3E3927950138
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateConfigNotAssign : public CWCStateConfig  //## Inherits: <unnamed>%3E3927D702CE
{
  //## begin CWCStateConfigNotAssign%3E3927950138.initialDeclarations preserve=yes
  //## end CWCStateConfigNotAssign%3E3927950138.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfigNotAssign();

    //## Destructor (generated)
      virtual ~CWCStateConfigNotAssign();


    //## Other Operations (specified)
      //## Operation: Create%1043917038
      static void Create ();

      //## Operation: Delete%1043917039
      static void Delete ();

      //## Operation: GetInstance%1043917040
      static CWCStateConfigNotAssign* GetInstance ();

      //## Operation: Do%1088517553
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
      //## begin CWCStateConfigNotAssign%3E3927950138.public preserve=yes
      //## end CWCStateConfigNotAssign%3E3927950138.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateConfigNotAssign%3E3927950138.protected preserve=yes
      //## end CWCStateConfigNotAssign%3E3927950138.protected

  private:
    //## Constructors (generated)
      CWCStateConfigNotAssign(const CWCStateConfigNotAssign &right);

    //## Assignment Operation (generated)
      const CWCStateConfigNotAssign & operator=(const CWCStateConfigNotAssign &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfigNotAssign &right) const;

      bool operator!=(const CWCStateConfigNotAssign &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E3927EC00AB
      //## Role: CWCStateConfigNotAssign::pInstance%3E3927F300FB
      //## begin CWCStateConfigNotAssign::pInstance%3E3927F300FB.role preserve=no  public: static CWCStateConfigNotAssign {1..1 -> 1..1RFHN}
      static CWCStateConfigNotAssign *m_pInstance;
      //## end CWCStateConfigNotAssign::pInstance%3E3927F300FB.role

    // Additional Private Declarations
      //## begin CWCStateConfigNotAssign%3E3927950138.private preserve=yes
      //## end CWCStateConfigNotAssign%3E3927950138.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfigNotAssign%3E3927950138.implementation preserve=yes
      //## end CWCStateConfigNotAssign%3E3927950138.implementation

};

//## begin CWCStateConfigNotAssign%3E3927950138.postscript preserve=yes
//## end CWCStateConfigNotAssign%3E3927950138.postscript

//## begin CWCStateConfigInitDAC%3FBB6DE602BF.preface preserve=yes
//## end CWCStateConfigInitDAC%3FBB6DE602BF.preface

//## Class: CWCStateConfigInitDAC%3FBB6DE602BF
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateConfigInitDAC : public CWCStateConfig  //## Inherits: <unnamed>%3FBB6ECB029F
{
  //## begin CWCStateConfigInitDAC%3FBB6DE602BF.initialDeclarations preserve=yes
  //## end CWCStateConfigInitDAC%3FBB6DE602BF.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfigInitDAC();

    //## Destructor (generated)
      virtual ~CWCStateConfigInitDAC();


    //## Other Operations (specified)
      //## Operation: Create%1069248595
      static void Create ();

      //## Operation: Delete%1069248596
      static void Delete ();

      //## Operation: GetInstance%1069248597
      static CWCStateConfigInitDAC* GetInstance ();

      //## Operation: Enter%1074582787
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

      //## Operation: Do%1069248599
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
      //## begin CWCStateConfigInitDAC%3FBB6DE602BF.public preserve=yes
      //## end CWCStateConfigInitDAC%3FBB6DE602BF.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateConfigInitDAC%3FBB6DE602BF.protected preserve=yes
      //## end CWCStateConfigInitDAC%3FBB6DE602BF.protected

  private:
    //## Constructors (generated)
      CWCStateConfigInitDAC(const CWCStateConfigInitDAC &right);

    //## Assignment Operation (generated)
      const CWCStateConfigInitDAC & operator=(const CWCStateConfigInitDAC &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfigInitDAC &right) const;

      bool operator!=(const CWCStateConfigInitDAC &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB6E9E003E
      //## Role: CWCStateConfigInitDAC::pInstance%3FBB6EA100FB
      //## begin CWCStateConfigInitDAC::pInstance%3FBB6EA100FB.role preserve=no  public: static CWCStateConfigInitDAC {1..1 -> RFHN}
      static CWCStateConfigInitDAC *m_pInstance;
      //## end CWCStateConfigInitDAC::pInstance%3FBB6EA100FB.role

    // Additional Private Declarations
      //## begin CWCStateConfigInitDAC%3FBB6DE602BF.private preserve=yes
      //## end CWCStateConfigInitDAC%3FBB6DE602BF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfigInitDAC%3FBB6DE602BF.implementation preserve=yes
      //## end CWCStateConfigInitDAC%3FBB6DE602BF.implementation

};

//## begin CWCStateConfigInitDAC%3FBB6DE602BF.postscript preserve=yes
//## end CWCStateConfigInitDAC%3FBB6DE602BF.postscript

//## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.preface preserve=yes
//## end CWCStateConfigDACCalibrated%3FBB6FA900EA.preface

//## Class: CWCStateConfigDACCalibrated%3FBB6FA900EA
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateConfigDACCalibrated : public CWCStateConfig  //## Inherits: <unnamed>%3FBB6FE1036B
{
  //## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.initialDeclarations preserve=yes
  //## end CWCStateConfigDACCalibrated%3FBB6FA900EA.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfigDACCalibrated();

    //## Destructor (generated)
      virtual ~CWCStateConfigDACCalibrated();


    //## Other Operations (specified)
      //## Operation: Create%1069248605
      static void Create ();

      //## Operation: Delete%1069248606
      static void Delete ();

      //## Operation: GetInstance%1069248607
      static CWCStateConfigDACCalibrated* GetInstance ();

      //## Operation: Enter%1069318248
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

      //## Operation: Do%1069248609
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: SetProfile%1069248610
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile);

    // Additional Public Declarations
      //## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.public preserve=yes
      //## end CWCStateConfigDACCalibrated%3FBB6FA900EA.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.protected preserve=yes
      //## end CWCStateConfigDACCalibrated%3FBB6FA900EA.protected

  private:
    //## Constructors (generated)
      CWCStateConfigDACCalibrated(const CWCStateConfigDACCalibrated &right);

    //## Assignment Operation (generated)
      const CWCStateConfigDACCalibrated & operator=(const CWCStateConfigDACCalibrated &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfigDACCalibrated &right) const;

      bool operator!=(const CWCStateConfigDACCalibrated &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB6FE60109
      //## Role: CWCStateConfigDACCalibrated::pInstance%3FBB6FE900CC
      //## begin CWCStateConfigDACCalibrated::pInstance%3FBB6FE900CC.role preserve=no  public: static CWCStateConfigDACCalibrated {1..1 -> 1..1RFHN}
      static CWCStateConfigDACCalibrated *m_pInstance;
      //## end CWCStateConfigDACCalibrated::pInstance%3FBB6FE900CC.role

    // Additional Private Declarations
      //## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.private preserve=yes
      //## end CWCStateConfigDACCalibrated%3FBB6FA900EA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.implementation preserve=yes
      //## end CWCStateConfigDACCalibrated%3FBB6FA900EA.implementation

};

//## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.postscript preserve=yes
//## end CWCStateConfigDACCalibrated%3FBB6FA900EA.postscript

//## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.preface preserve=yes
//## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.preface

//## Class: CWCStateConfigCalibDACIncCurr%3FBC810B0138
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateConfigCalibDACIncCurr : public CWCStateConfig  //## Inherits: <unnamed>%3FBC816F0196
{
  //## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.initialDeclarations preserve=yes
  //## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfigCalibDACIncCurr();

    //## Destructor (generated)
      virtual ~CWCStateConfigCalibDACIncCurr();


    //## Other Operations (specified)
      //## Operation: Create%1069318237
      static void Create ();

      //## Operation: Delete%1069318238
      static void Delete ();

      //## Operation: GetInstance%1069318239
      static CWCStateConfigCalibDACIncCurr* GetInstance ();

      //## Operation: Enter%1069318249
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

      //## Operation: Do%1069318240
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
      //## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.public preserve=yes
      //## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.protected preserve=yes
      //## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.protected

  private:
    //## Constructors (generated)
      CWCStateConfigCalibDACIncCurr(const CWCStateConfigCalibDACIncCurr &right);

    //## Assignment Operation (generated)
      const CWCStateConfigCalibDACIncCurr & operator=(const CWCStateConfigCalibDACIncCurr &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfigCalibDACIncCurr &right) const;

      bool operator!=(const CWCStateConfigCalibDACIncCurr &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBC8174029F
      //## Role: CWCStateConfigCalibDACIncCurr::pInstance%3FBC81770178
      //## begin CWCStateConfigCalibDACIncCurr::pInstance%3FBC81770178.role preserve=no  public: static CWCStateConfigCalibDACIncCurr {1..1 -> 1..1RFHN}
      static CWCStateConfigCalibDACIncCurr *m_pInstance;
      //## end CWCStateConfigCalibDACIncCurr::pInstance%3FBC81770178.role

    // Additional Private Declarations
      //## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.private preserve=yes
      //## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.implementation preserve=yes
      //## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.implementation

};

//## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.postscript preserve=yes
//## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.postscript

//## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.preface preserve=yes
//## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.preface

//## Class: CWCStateConfigCalibDACDecCurr%3FBC81A5033C
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCStateConfigCalibDACDecCurr : public CWCStateConfig  //## Inherits: <unnamed>%3FBC822901E4
{
  //## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.initialDeclarations preserve=yes
  //## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateConfigCalibDACDecCurr();

    //## Destructor (generated)
      virtual ~CWCStateConfigCalibDACDecCurr();


    //## Other Operations (specified)
      //## Operation: Create%1069318241
      static void Create ();

      //## Operation: Delete%1069318242
      static void Delete ();

      //## Operation: GetInstance%1069318243
      static CWCStateConfigCalibDACDecCurr* GetInstance ();

      //## Operation: Enter%1069318250
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

      //## Operation: Do%1069318244
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
      //## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.public preserve=yes
      //## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.protected preserve=yes
      //## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.protected

  private:
    //## Constructors (generated)
      CWCStateConfigCalibDACDecCurr(const CWCStateConfigCalibDACDecCurr &right);

    //## Assignment Operation (generated)
      const CWCStateConfigCalibDACDecCurr & operator=(const CWCStateConfigCalibDACDecCurr &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateConfigCalibDACDecCurr &right) const;

      bool operator!=(const CWCStateConfigCalibDACDecCurr &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBC81FD035B
      //## Role: CWCStateConfigCalibDACDecCurr::pInstance%3FBC81FF03D9
      //## begin CWCStateConfigCalibDACDecCurr::pInstance%3FBC81FF03D9.role preserve=no  public: static CWCStateConfigCalibDACDecCurr {1..1 -> 1..1RFHN}
      static CWCStateConfigCalibDACDecCurr *m_pInstance;
      //## end CWCStateConfigCalibDACDecCurr::pInstance%3FBC81FF03D9.role

    // Additional Private Declarations
      //## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.private preserve=yes
      //## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.implementation preserve=yes
      //## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.implementation

};

//## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.postscript preserve=yes
//## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.postscript

// Class CWCStateConfig 

// Class CWCStateConfiguration 

// Class CWCStateConfigProfile 

// Class CWCStateConfigNotAssign 

// Class CWCStateConfigInitDAC 

// Class CWCStateConfigDACCalibrated 

// Class CWCStateConfigCalibDACIncCurr 

// Class CWCStateConfigCalibDACDecCurr 

//## begin module%3E38FDF2005D.epilog preserve=yes
//## end module%3E38FDF2005D.epilog


#endif
