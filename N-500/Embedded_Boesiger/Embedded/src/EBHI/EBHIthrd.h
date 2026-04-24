//## begin module%3E227A6A0394.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E227A6A0394.cm

//## begin module%3E227A6A0394.cp preserve=no
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
//## end module%3E227A6A0394.cp

//## Module: EBHIthrd%3E227A6A0394; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIthrd.h

#ifndef EBHIthrd_h
#define EBHIthrd_h 1

//## begin module%3E227A6A0394.additionalIncludes preserve=no
//## end module%3E227A6A0394.additionalIncludes

//## begin module%3E227A6A0394.includes preserve=yes
//## end module%3E227A6A0394.includes

// EBCOthrd
#include "EBCOthrd.h"
// EBPItype
#include "EBPItype.h"
// EBHIenum
#include "EBHIenum.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBCO_DLL_DECL XCOExceptionError;
class XHIExceptionError;
class EBHI_DLL_DECL CHII2CCommand;
class XHIHardwareExceptionError;
class CHIEventRegistrationConfig;
class CHIEventRegistration;
class CHIProcessNodeConfig;

//## begin module%3E227A6A0394.declarations preserve=no
//## end module%3E227A6A0394.declarations

//## begin module%3E227A6A0394.additionalDeclarations preserve=yes
//## end module%3E227A6A0394.additionalDeclarations


//## begin CHII2CWorkerThread%3E227BB3027B.preface preserve=yes
//## end CHII2CWorkerThread%3E227BB3027B.preface

//## Class: CHII2CWorkerThread%3E227BB3027B
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FD83DD80271;CPISyncObjI2CDataStream { -> }

class EBHI_DLL_DECL CHII2CWorkerThread : public ICOThreadWork  //## Inherits: <unnamed>%3E227BEC02AA
{
  //## begin CHII2CWorkerThread%3E227BB3027B.initialDeclarations preserve=yes
  //## end CHII2CWorkerThread%3E227BB3027B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHII2CWorkerThread%1042447556
      CHII2CWorkerThread (const CString& p_sName, const UINT p_uiStackSize = 0);

    //## Destructor (generated)
      virtual ~CHII2CWorkerThread();


    //## Other Operations (specified)
      //## Operation: ThreadMain%1042447541
      virtual int ThreadMain ();

      //## Operation: CreateInstance%1042447550
      static void CreateInstance ();

      //## Operation: DeleteInstance%1042447551
      static void DeleteInstance ();

      //## Operation: GetInstance%1042447552
      static CHII2CWorkerThread* GetInstance ();

      //## Operation: AddCommand%1042447553
      //	DESCRIPTION
      //	adds a new command to the task list
      //
      //	RETURNS
      //	sync object signalling the completion of the command
      CPISyncObjI2CDataStream* AddCommand (CHII2CCommand* p_pCommand);

      //## Operation: ExecuteCommand%1042447555
      //	DESCRIPTION
      //	executes all commands in the thread queue
      //
      //	RETURNS
      //	true, if all commands are finished
      bool ExecuteCommand ();

    // Additional Public Declarations
      //## begin CHII2CWorkerThread%3E227BB3027B.public preserve=yes
      //## end CHII2CWorkerThread%3E227BB3027B.public

  protected:

    //## Other Operations (specified)
      //## Operation: DoIdle%1042447554
      //	DESCRIPTION
      //	waits for job respectively thread termination event
      //
      //	PARAMETERS
      //	-
      //
      //	RETURNS
      //	true, if the thread should terminate
      bool DoIdle ();

    // Additional Protected Declarations
      //## begin CHII2CWorkerThread%3E227BB3027B.protected preserve=yes
      //## end CHII2CWorkerThread%3E227BB3027B.protected

  private:
    //## Constructors (generated)
      CHII2CWorkerThread();

      CHII2CWorkerThread(const CHII2CWorkerThread &right);

    //## Assignment Operation (generated)
      const CHII2CWorkerThread & operator=(const CHII2CWorkerThread &right);

    //## Equality Operations (generated)
      bool operator==(const CHII2CWorkerThread &right) const;

      bool operator!=(const CHII2CWorkerThread &right) const;

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2298490394
      //## Role: CHII2CWorkerThread::pInstance%3E2298500162
      //## begin CHII2CWorkerThread::pInstance%3E2298500162.role preserve=no  public: static CHII2CWorkerThread {1..1 -> 1..1RFHN}
      static CHII2CWorkerThread *m_pInstance;
      //## end CHII2CWorkerThread::pInstance%3E2298500162.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2298980394
      //## Role: CHII2CWorkerThread::QueueEvent%3E2298990365
      //## begin CHII2CWorkerThread::QueueEvent%3E2298990365.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_QueueEvent;
      //## end CHII2CWorkerThread::QueueEvent%3E2298990365.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2298DD01B0
      //## Role: CHII2CWorkerThread::AccessLock%3E2298DE0048
      //## begin CHII2CWorkerThread::AccessLock%3E2298DE0048.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CHII2CWorkerThread::AccessLock%3E2298DE0048.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2299D401DE
      //## Role: CHII2CWorkerThread::QueueCommand%3E2299D50124
      //## begin CHII2CWorkerThread::QueueCommand%3E2299D50124.role preserve=no  public: CHII2CCommand {1 -> *RFHN}
      CTypedPtrList<CPtrList, CHII2CCommand*> m_QueueCommand;
      //## end CHII2CWorkerThread::QueueCommand%3E2299D50124.role

    // Additional Private Declarations
      //## begin CHII2CWorkerThread%3E227BB3027B.private preserve=yes
      //## end CHII2CWorkerThread%3E227BB3027B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHII2CWorkerThread%3E227BB3027B.implementation preserve=yes
      //## end CHII2CWorkerThread%3E227BB3027B.implementation

};

//## begin CHII2CWorkerThread%3E227BB3027B.postscript preserve=yes
//## end CHII2CWorkerThread%3E227BB3027B.postscript

//## begin CHIEventWorkerThread%3E5A23B80119.preface preserve=yes
//## end CHIEventWorkerThread%3E5A23B80119.preface

//## Class: CHIEventWorkerThread%3E5A23B80119
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E64513A0128;CHIInterface { -> }
//## Uses: <unnamed>%3E6EDB140280;CPISyncObjDataPackage { -> }
//## Uses: <unnamed>%3E6EE6C2033C;CHIMCParameter { -> }
//## Uses: <unnamed>%3E6EE71A000F;CHITReservedSharedMemory { -> }
//## Uses: <unnamed>%3E6EE7310271;XHIExceptionError { -> F}
//## Uses: <unnamed>%3E6EE7450000;HI_IDENTIFIERS { -> }
//## Uses: <unnamed>%3E9BCFF403B9;EHIOpenEventRegistration { -> }
//## Uses: <unnamed>%3EB675FD0138;CHIProcessNodeConfig { -> F}

class EBHI_DLL_DECL CHIEventWorkerThread : public ICOThreadWork  //## Inherits: <unnamed>%3E5A23E503D8
{
  //## begin CHIEventWorkerThread%3E5A23B80119.initialDeclarations preserve=yes
  //## end CHIEventWorkerThread%3E5A23B80119.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHIEventWorkerThread%1046077276
      CHIEventWorkerThread (const CString& p_sName, const UINT p_uiStackSize, const bool p_bHWPresent);

    //## Destructor (generated)
      virtual ~CHIEventWorkerThread();


    //## Other Operations (specified)
      //## Operation: ThreadMain%1046077277
      virtual int ThreadMain ();

      //## Operation: CreateInstance%1046077278
      static void CreateInstance (const bool p_bHWPresent);

      //## Operation: DeleteInstance%1046077279
      static void DeleteInstance ();

      //## Operation: GetInstance%1046077280
      static CHIEventWorkerThread* GetInstance ();

      //## Operation: TerminateThread%1067437968
      virtual void TerminateThread ();

      //## Operation: ExecuteISREvent%1046077282
      //	DESCRIPTION
      //	executes all events (exceptions, DIO inputs, etc.) from
      //	the ISR
      //
      //	RETURNS
      //	true, if all events are finished
      bool ExecuteISREvent ();

      //## Operation: OpenEvent%1050387899
      //	DESCRIPTION
      //	open a event. If a digital In-/Output has changed a sync
      //	object is set.
      //
      //	INPUT:
      //	- identifier of the spec. In-/Output
      //	- notification kind (high active, low active etc.)
      virtual CCOSyncObject* OpenEvent (DWORD p_dwID, EHIOpenEventRegistration p_eRegistration);

      //## Operation: CloseEvent%1050387900
      //	DESCRIPTION
      //	closes the spec event.
      virtual void CloseEvent (DWORD p_dwID, CCOSyncObject* p_pSyncObj);

      //## Operation: CheckHWExceptions%1054101545
      //	DESCRIPTION
      //	checks all hardware exception register
      virtual void CheckHWExceptions ();

      //## Operation: CheckWCEvents%1052803855
      //	DESCRIPTION
      //	checks all WC events
      virtual void CheckWCEvents ();

      //## Operation: CheckDigInputEvents%1050387901
      //	DESCRIPTION
      //	checks digital input events
      virtual void CheckDigInputEvents ();

      //## Operation: CheckStepperEvents%1066028228
      //	DESCRIPTION
      //	checks stepper motor events
      virtual void CheckStepperEvents ();

      //## Operation: CheckI2CEvent%1071211735
      //	DESCRIPTION
      //	checks I2C event register
      virtual void CheckI2CEvent ();

      //## Operation: EnableEventSignalisation%1066028226
      //	DESCRIPTION
      //	enables the event signalisation (open events)
      virtual CCOSyncObject* EnableEventSignalisation ();

      //## Operation: DisableEventSignalisation%1066028227
      //	DESCRIPTION
      //	disables the event signalisation (open events)
      virtual CCOSyncObject* DisableEventSignalisation ();

      //## Operation: DebugGetEvents%1067329236
      virtual CCOSyncObjectArray* DebugGetEvents (DWORD p_dwID);

      //## Operation: DebugSetEvents%1067329237
      virtual void DebugSetEvents (DWORD p_dwID);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHI (Hardware Interface)::<unnamed>%3FCCA24801E4
      //## Role: CHIEventWorkerThread::pSyncObj%3FCCA24803B9
      CCOSyncObject * GetpSyncObj ();

      //## Association: EBHI (Hardware Interface)::<unnamed>%400D1D2603A9
      //## Role: CHIEventWorkerThread::dwHWExceptionEventNr%400D1D270280
      DWORD GetdwHWExceptionEventNr ();
      void SetdwHWExceptionEventNr (DWORD value);

    // Additional Public Declarations
      //## begin CHIEventWorkerThread%3E5A23B80119.public preserve=yes
      //## end CHIEventWorkerThread%3E5A23B80119.public

  protected:

    //## Other Operations (specified)
      //## Operation: DoIdle%1046077281
      //	DESCRIPTION
      //	waits for job respectively thread termination event
      //
      //	PARAMETERS
      //	-
      //
      //	RETURNS
      //	true, if the thread should terminate
      bool DoIdle ();

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E632F9B0261
      //## Role: CHIEventWorkerThread::WCIrqEvent%3E632F9C007E
      //## begin CHIEventWorkerThread::WCIrqEvent%3E632F9C007E.role preserve=no  public: CEvent {1..1 -> 1..1VHN}
      CEvent m_WCIrqEvent;
      //## end CHIEventWorkerThread::WCIrqEvent%3E632F9C007E.role

    // Additional Protected Declarations
      //## begin CHIEventWorkerThread%3E5A23B80119.protected preserve=yes
      //## end CHIEventWorkerThread%3E5A23B80119.protected

  private:
    //## Constructors (generated)
      CHIEventWorkerThread();

      CHIEventWorkerThread(const CHIEventWorkerThread &right);

    //## Assignment Operation (generated)
      const CHIEventWorkerThread & operator=(const CHIEventWorkerThread &right);

    //## Equality Operations (generated)
      bool operator==(const CHIEventWorkerThread &right) const;

      bool operator!=(const CHIEventWorkerThread &right) const;

    // Data Members for Class Attributes

      //## Attribute: bHWPresent%3F9E2BF901DA
      //## begin CHIEventWorkerThread::bHWPresent%3F9E2BF901DA.attr preserve=no  private: bool {U} p_bHWPresent
      bool m_bHWPresent;
      //## end CHIEventWorkerThread::bHWPresent%3F9E2BF901DA.attr

      //## Attribute: bTerminating%3F9FD55802A5
      //## begin CHIEventWorkerThread::bTerminating%3F9FD55802A5.attr preserve=no  private: bool {U} false
      bool m_bTerminating;
      //## end CHIEventWorkerThread::bTerminating%3F9FD55802A5.attr

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E5A240A02CE
      //## Role: CHIEventWorkerThread::pInstance%3E5A240E0291
      //## begin CHIEventWorkerThread::pInstance%3E5A240E0291.role preserve=no  public: static CHIEventWorkerThread {1..1 -> RFHN}
      static CHIEventWorkerThread *m_pInstance;
      //## end CHIEventWorkerThread::pInstance%3E5A240E0291.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E6479510196
      //## Role: CHIEventWorkerThread::dwWCIrqNumber%3E647952009D
      //## begin CHIEventWorkerThread::dwWCIrqNumber%3E647952009D.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwWCIrqNumber;
      //## end CHIEventWorkerThread::dwWCIrqNumber%3E647952009D.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E6EE86E0000
      //## Role: CHIEventWorkerThread::AccessLock%3E6EE86E0233
      //## begin CHIEventWorkerThread::AccessLock%3E6EE86E0233.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CHIEventWorkerThread::AccessLock%3E6EE86E0233.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E9ABC1E0290
      //## Role: CHIEventWorkerThread::EventMap%3E9ABC1F0158
      //## Constraints:
      //	ordered
      //## Qualifier: class%3E9ABC5200FA; DWORD
      //## begin CHIEventWorkerThread::EventMap%3E9ABC1F0158.role preserve=no  public: CHIEventRegistration { -> 1RFHON}
      CMap<DWORD, DWORD&, CHIEventRegistration *, CHIEventRegistration *&> m_EventMap;
      //## end CHIEventWorkerThread::EventMap%3E9ABC1F0158.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3F8B91FA02DE
      //## Role: CHIEventWorkerThread::bEnableEventSignalisation%3F8B91FB011A
      //## begin CHIEventWorkerThread::bEnableEventSignalisation%3F8B91FB011A.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bEnableEventSignalisation;
      //## end CHIEventWorkerThread::bEnableEventSignalisation%3F8B91FB011A.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3FCCA24801E4
      //## begin CHIEventWorkerThread::pSyncObj%3FCCA24803B9.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pSyncObj;
      //## end CHIEventWorkerThread::pSyncObj%3FCCA24803B9.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%400D1D2603A9
      //## begin CHIEventWorkerThread::dwHWExceptionEventNr%400D1D270280.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwHWExceptionEventNr;
      //## end CHIEventWorkerThread::dwHWExceptionEventNr%400D1D270280.role

    // Additional Private Declarations
      //## begin CHIEventWorkerThread%3E5A23B80119.private preserve=yes
      //## end CHIEventWorkerThread%3E5A23B80119.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIEventWorkerThread%3E5A23B80119.implementation preserve=yes
      //## end CHIEventWorkerThread%3E5A23B80119.implementation

};

//## begin CHIEventWorkerThread%3E5A23B80119.postscript preserve=yes
//## end CHIEventWorkerThread%3E5A23B80119.postscript

//## begin CHIEventRegistration%3E9ABC11005D.preface preserve=yes
//## end CHIEventRegistration%3E9ABC11005D.preface

//## Class: CHIEventRegistration%3E9ABC11005D
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ECCC0D502FD;XCOExceptionError { -> F}
//## Uses: <unnamed>%3ECE11FF0280;XHIHardwareExceptionError { -> F}

class CHIEventRegistration 
{
  //## begin CHIEventRegistration%3E9ABC11005D.initialDeclarations preserve=yes
  //## end CHIEventRegistration%3E9ABC11005D.initialDeclarations

  public:
    //## Constructors (generated)
      CHIEventRegistration();

    //## Destructor (generated)
      virtual ~CHIEventRegistration();


    //## Other Operations (specified)
      //## Operation: Add%1067281894
      CCOSyncObject* Add (EHIOpenEventRegistration p_eEventType);

      //## Operation: Remove%1067281895
      //	returns true, if the whole registration can be removed
      bool Remove (CCOSyncObject* p_pSyncObj);

      //## Operation: CheckRegisteredWCState%1053584949
      //	DESCRIPTION:
      //	check registered wedge control WC state, WC exceptions
      //	and signal the registered state or attach an exception.
      void CheckRegisteredWCState (XHIHardwareExceptionError* p_pXException = NULL);

      //## Operation: CheckRegisteredExceptionState%1054101546
      //	DESCRIPTION:
      //	check registered HW exception state.
      void CheckRegisteredExceptionState (XHIExceptionError* p_pXException = NULL);

      //## Operation: CheckRegisteredHWState%1052117442
      //	DESCRIPTION:
      //	check registered hardware state (high or low) and signal
      //	the registered state
      void CheckRegisteredHWState (EHIOpenEventRegistration p_eStateChange, XHIHardwareExceptionError* p_pXException = NULL);

      //## Operation: CheckRegisteredI2CState%1071211739
      //	DESCRIPTION:
      //	check registered I2C state.
      void CheckRegisteredI2CState ();

      //## Operation: CheckRegisteredHWWarnErrState%1096438040
      //	DESCRIPTION:
      //	check registered Hardware warning and error states.
      void CheckRegisteredHWWarnErrState ();

      //## Operation: DebugGetEvents%1067329238
      CCOSyncObjectArray* DebugGetEvents ();

      //## Operation: DebugSetEvents%1067329239
      void DebugSetEvents ();

    // Additional Public Declarations
      //## begin CHIEventRegistration%3E9ABC11005D.public preserve=yes
      //## end CHIEventRegistration%3E9ABC11005D.public

  protected:
    // Additional Protected Declarations
      //## begin CHIEventRegistration%3E9ABC11005D.protected preserve=yes
      //## end CHIEventRegistration%3E9ABC11005D.protected

  private:
    //## Constructors (generated)
      CHIEventRegistration(const CHIEventRegistration &right);

    //## Assignment Operation (generated)
      const CHIEventRegistration & operator=(const CHIEventRegistration &right);

    //## Equality Operations (generated)
      bool operator==(const CHIEventRegistration &right) const;

      bool operator!=(const CHIEventRegistration &right) const;

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3EB62B760177
      //## Role: CHIEventRegistration::AccessLock%3EB62B77008D
      //## begin CHIEventRegistration::AccessLock%3EB62B77008D.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CHIEventRegistration::AccessLock%3EB62B77008D.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3F7D0AF10157
      //## Role: CHIEventRegistration::EventRegConfigList%3F7D0AF20243
      //## begin CHIEventRegistration::EventRegConfigList%3F7D0AF20243.role preserve=no  public: CHIEventRegistrationConfig { -> *RFHN}
      CTypedPtrList<CPtrList, CHIEventRegistrationConfig*> m_EventRegConfigList;
      //## end CHIEventRegistration::EventRegConfigList%3F7D0AF20243.role

    // Additional Private Declarations
      //## begin CHIEventRegistration%3E9ABC11005D.private preserve=yes
      //## end CHIEventRegistration%3E9ABC11005D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIEventRegistration%3E9ABC11005D.implementation preserve=yes
      //## end CHIEventRegistration%3E9ABC11005D.implementation

};

//## begin CHIEventRegistration%3E9ABC11005D.postscript preserve=yes
//## end CHIEventRegistration%3E9ABC11005D.postscript

//## begin CHIEventRegistrationConfig%3E9BA6230186.preface preserve=yes
//## end CHIEventRegistrationConfig%3E9BA6230186.preface

//## Class: CHIEventRegistrationConfig%3E9BA6230186
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHIEventRegistrationConfig 
{
  //## begin CHIEventRegistrationConfig%3E9BA6230186.initialDeclarations preserve=yes
  //## end CHIEventRegistrationConfig%3E9BA6230186.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHIEventRegistrationConfig%1050387898
      CHIEventRegistrationConfig (EHIOpenEventRegistration p_eRegistrationKind);

    //## Destructor (generated)
      virtual ~CHIEventRegistrationConfig();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: eRegistrationKind%3E9BA6D301C5
      EHIOpenEventRegistration GeteRegistrationKind ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E9BCBD7038A
      //## Role: CHIEventRegistrationConfig::pSyncObj%3E9BCBD80291
      CCOSyncObject * GetpSyncObj ();

    // Additional Public Declarations
      //## begin CHIEventRegistrationConfig%3E9BA6230186.public preserve=yes
      //## end CHIEventRegistrationConfig%3E9BA6230186.public

  protected:
    // Additional Protected Declarations
      //## begin CHIEventRegistrationConfig%3E9BA6230186.protected preserve=yes
      //## end CHIEventRegistrationConfig%3E9BA6230186.protected

  private:
    //## Constructors (generated)
      CHIEventRegistrationConfig();

      CHIEventRegistrationConfig(const CHIEventRegistrationConfig &right);

    //## Assignment Operation (generated)
      const CHIEventRegistrationConfig & operator=(const CHIEventRegistrationConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CHIEventRegistrationConfig &right) const;

      bool operator!=(const CHIEventRegistrationConfig &right) const;

    // Data Members for Class Attributes

      //## begin CHIEventRegistrationConfig::eRegistrationKind%3E9BA6D301C5.attr preserve=no  public: EHIOpenEventRegistration {U} p_eRegistrationKind
      EHIOpenEventRegistration m_eRegistrationKind;
      //## end CHIEventRegistrationConfig::eRegistrationKind%3E9BA6D301C5.attr

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E9BCBD7038A
      //## begin CHIEventRegistrationConfig::pSyncObj%3E9BCBD80291.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pSyncObj;
      //## end CHIEventRegistrationConfig::pSyncObj%3E9BCBD80291.role

    // Additional Private Declarations
      //## begin CHIEventRegistrationConfig%3E9BA6230186.private preserve=yes
      //## end CHIEventRegistrationConfig%3E9BA6230186.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIEventRegistrationConfig%3E9BA6230186.implementation preserve=yes
      //## end CHIEventRegistrationConfig%3E9BA6230186.implementation

};

//## begin CHIEventRegistrationConfig%3E9BA6230186.postscript preserve=yes
//## end CHIEventRegistrationConfig%3E9BA6230186.postscript

//## begin CHIDatapackageWorkerThread%3F9FD1000286.preface preserve=yes
//## end CHIDatapackageWorkerThread%3F9FD1000286.preface

//## Class: CHIDatapackageWorkerThread%3F9FD1000286
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%406432280203;XCOExceptionErrorMemoryAllocation { -> }

class CHIDatapackageWorkerThread : public ICOThreadWork  //## Inherits: <unnamed>%3F9FD1200257
{
  //## begin CHIDatapackageWorkerThread%3F9FD1000286.initialDeclarations preserve=yes
  //## end CHIDatapackageWorkerThread%3F9FD1000286.initialDeclarations

  public:
    //## Constructors (generated)
      CHIDatapackageWorkerThread();

    //## Destructor (generated)
      virtual ~CHIDatapackageWorkerThread();


    //## Other Operations (specified)
      //## Operation: ThreadMain%1067437963
      virtual int ThreadMain ();

      //## Operation: CreateInstance%1067437964
      static void CreateInstance (const bool p_bHWPresent);

      //## Operation: DeleteInstance%1067437965
      static void DeleteInstance ();

      //## Operation: GetInstance%1067437966
      static CHIDatapackageWorkerThread* GetInstance ();

      //## Operation: GetDataPackage%1083091762
      CPISyncObjDataPackage* GetDataPackage ();

      //## Operation: Stop%1083231111
      CCOSyncObject* Stop ();

      //## Operation: CopyStreamData%1179822604
      //	Copyies a number of bytes from the stream buffer to the
      //	temporary buffer p_pStreamDataBuffer
      //
      //	Returns the new offset in number of DWORD's in the
      //	stream buffer or zero when the end of the buffer is
      //	reached
      DWORD CopyStreamData (const DWORD* p_pBufferBaseAddr, const DWORD* p_pCurrentReadPtr, const DWORD p_dwBufferLength, BYTE* p_pStreamDataBuffer, const DWORD p_dwBytesToCopy, const bool p_bIsLaser);

    // Additional Public Declarations
      //## begin CHIDatapackageWorkerThread%3F9FD1000286.public preserve=yes
      //## end CHIDatapackageWorkerThread%3F9FD1000286.public

  protected:
    // Additional Protected Declarations
      //## begin CHIDatapackageWorkerThread%3F9FD1000286.protected preserve=yes
      //## end CHIDatapackageWorkerThread%3F9FD1000286.protected

  private:
    //## Constructors (generated)
      CHIDatapackageWorkerThread(const CHIDatapackageWorkerThread &right);

    //## Assignment Operation (generated)
      const CHIDatapackageWorkerThread & operator=(const CHIDatapackageWorkerThread &right);

    //## Equality Operations (generated)
      bool operator==(const CHIDatapackageWorkerThread &right) const;

      bool operator!=(const CHIDatapackageWorkerThread &right) const;


    //## Other Operations (specified)
      //## Operation: DoGetDataPackage%1067437967
      //	true, if a datapackage has been available
      bool DoGetDataPackage ();

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3F9FD15E0332
      //## Role: CHIDatapackageWorkerThread::pSyncObjDataPackage%3F9FD15F01EB
      //## begin CHIDatapackageWorkerThread::pSyncObjDataPackage%3F9FD15F01EB.role preserve=no  public: CPISyncObjDataPackage {1..1 -> 1..1RFHN}
      CPISyncObjDataPackage *m_pSyncObjDataPackage;
      //## end CHIDatapackageWorkerThread::pSyncObjDataPackage%3F9FD15F01EB.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3F9FD22D0342
      //## Role: CHIDatapackageWorkerThread::pInstance%3F9FD22E0391
      //## begin CHIDatapackageWorkerThread::pInstance%3F9FD22E0391.role preserve=no  public: static CHIDatapackageWorkerThread {1..1 -> 1..1RFHN}
      static CHIDatapackageWorkerThread *m_pInstance;
      //## end CHIDatapackageWorkerThread::pInstance%3F9FD22E0391.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3F9FD3A30073
      //## Role: CHIDatapackageWorkerThread::AccessLock%3F9FD3A301FB
      //## begin CHIDatapackageWorkerThread::AccessLock%3F9FD3A301FB.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CHIDatapackageWorkerThread::AccessLock%3F9FD3A301FB.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%408EAB05004C
      //## Role: CHIDatapackageWorkerThread::CommandEvent%408EAB050241
      //## begin CHIDatapackageWorkerThread::CommandEvent%408EAB050241.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_CommandEvent;
      //## end CHIDatapackageWorkerThread::CommandEvent%408EAB050241.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%4090CB5A0248
      //## Role: CHIDatapackageWorkerThread::pStopSyncObj%4090CB5B00B8
      //## begin CHIDatapackageWorkerThread::pStopSyncObj%4090CB5B00B8.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pStopSyncObj;
      //## end CHIDatapackageWorkerThread::pStopSyncObj%4090CB5B00B8.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%4090CC80038B
      //## Role: CHIDatapackageWorkerThread::StopEvent%4090CC8201DF
      //## begin CHIDatapackageWorkerThread::StopEvent%4090CC8201DF.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_StopEvent;
      //## end CHIDatapackageWorkerThread::StopEvent%4090CC8201DF.role

    // Additional Private Declarations
      //## begin CHIDatapackageWorkerThread%3F9FD1000286.private preserve=yes
      //## end CHIDatapackageWorkerThread%3F9FD1000286.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIDatapackageWorkerThread%3F9FD1000286.implementation preserve=yes
      //## end CHIDatapackageWorkerThread%3F9FD1000286.implementation

};

//## begin CHIDatapackageWorkerThread%3F9FD1000286.postscript preserve=yes
//## end CHIDatapackageWorkerThread%3F9FD1000286.postscript

// Class CHII2CWorkerThread 

// Class CHIEventWorkerThread 

// Class CHIEventRegistration 

// Class CHIEventRegistrationConfig 

// Class CHIDatapackageWorkerThread 

//## begin module%3E227A6A0394.epilog preserve=yes
//## end module%3E227A6A0394.epilog


#endif
