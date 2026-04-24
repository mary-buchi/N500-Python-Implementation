//## begin module%3DE5EB64037F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB64037F.cm

//## begin module%3DE5EB64037F.cp preserve=no
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
//## end module%3DE5EB64037F.cp

//## Module: EBPOstat%3DE5EB64037F; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOstat.h

#ifndef EBPOstat_h
#define EBPOstat_h 1

//## begin module%3DE5EB64037F.additionalIncludes preserve=no
//## end module%3DE5EB64037F.additionalIncludes

//## begin module%3DE5EB64037F.includes preserve=yes
//## end module%3DE5EB64037F.includes

// EBCOsypr
#include "EBCOsypr.h"
// EBCOstat
#include "EBCOstat.h"
// EBPIenum
#include "EBPIenum.h"
// EBPItype
#include "EBPItype.h"
// EBPOimpl
#include "EBPOimpl.h"
//## begin module%3DE5EB64037F.declarations preserve=no
//## end module%3DE5EB64037F.declarations

//## begin module%3DE5EB64037F.additionalDeclarations preserve=yes
//## end module%3DE5EB64037F.additionalDeclarations


//## begin CPOState%3DE63804016C.preface preserve=yes
//## end CPOState%3DE63804016C.preface

//## Class: CPOState%3DE63804016C
//	<virtual>> GetpContext(p_pContext : ICOStateMachine
//	Context*) : CSTStepperMotorImplementation*
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE638F9012D;PO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DE639000302;XCOException { -> }
//## Uses: <unnamed>%3F97D96200D2;XCOException { -> }
//## Uses: <unnamed>%3F98E8F2026B;CPIIdentificationVersion { -> }
//## Uses: <unnamed>%3F9CDB8900D7;CPOPersistentObjImplementation { -> }
//## Uses: <unnamed>%4002DD29039A;EPILifeTimeCounter { -> }
//## Uses: <unnamed>%4002DD6E00EB;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%4002DDFC00AE;CPIPersistentIdent { -> }

class CPOState : public CCOState  //## Inherits: <unnamed>%3DE6381E03CD
{
  //## begin CPOState%3DE63804016C.initialDeclarations preserve=yes
  //## end CPOState%3DE63804016C.initialDeclarations

  public:
    //## Constructors (generated)
      CPOState();

    //## Destructor (generated)
      virtual ~CPOState();


    //## Other Operations (specified)
      //## Operation: ReadParameters%1066888959
      //	DESCRIPTION
      //	Returns a list with CPIPersistentParameter Objects,
      //	describing the complete set of persistent parameter
      //	information
      //
      //	PARAMETERS
      //
      //
      //	RETURNS
      //	CPISyncObjListParameter*
      virtual void ReadParameters (ICOStateMachineContext* p_pContext, CPISyncObjListPersistentItems *p_pSyncObjParameters);

      //## Operation: WriteParameter%1066888960
      //	DESCRIPTION
      //	Writes a single parameter into the persistent memory.
      //
      //	PARAMETERS
      //	- Parameter to write
      //	- Parameter location
      //
      //	RETURNS
      //	async void
      virtual void WriteParameter (ICOStateMachineContext* p_pContext, CPIPersistentPara* p_pParameter);

      //## Operation: StartMonitoring%1066888961
      //	DESCRIPTION
      //	Starts counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual void StartMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice);

      //## Operation: StopMonitoring%1066888962
      //	DESCRIPTION
      //	Stops counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual void StopMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice);

      //## Operation: Save%1066888963
      //	DESCRIPTION
      //	Saves data (parameters, operating data, identifications)
      //	to eeprom.
      //
      //	RETURNS
      //	async - void
      virtual void Save (ICOStateMachineContext* p_pContext);

      //## Operation: ReadLifeTimeCounter%1066888964
      //	DESCRIPTION
      //	Reads the value of the specified operating data counter
      //	from the persistent object store
      //
      //	PARAMETERS
      //	Operating data counter to read
      //
      //	RETURNS
      //	async: int [s] or [number of scans]
      virtual void ReadLifeTimeCounter (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj, EPILifeTimeCounter p_eCounter);

      //## Operation: WriteLifeTimeCounter%1066888965
      //	DESCRIPTION
      //	Writes the value of the specified operating data counter
      //	to the persistent object store
      //
      //	PARAMETERS
      //	- Operating data counter to write
      //	- Value to write
      //
      //	RETURNS
      //	async void
      virtual void WriteLifeTimeCounter (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eCounter, const UINT &p_uiValue);

      //## Operation: ReadIdentifications%1066888966
      //	DESCRIPTION
      //	Reads all identifications from the persistent object
      //	store.
      //
      //	PARAMETERS
      //
      //	RETURNS
      //	CPISyncObjListIPersistentItems*
      virtual void ReadIdentifications (ICOStateMachineContext* p_pContext, CPISyncObjListPersistentItems *p_pSyncObjParameters);

      //## Operation: WriteIdentification%1066888967
      //	DESCRIPTION
      //	Writes the value of the specified identification to the
      //	persistent object store
      //
      //	PARAMETERS
      //	- PersistentItem
      //	- Parameter item location
      //
      //	RETURNS
      //	async void
      virtual void WriteIdentification (ICOStateMachineContext* p_pContext, CPIPersistentIdent* p_pIdentification);

      //## Operation: SetConfig%1066888968
      //	DESCRIPTION
      //	Configurates the persistent object parameters
      //
      //	PARAMETERS
      //	p_PersistentConfig
      //
      //	RETURNS
      //	async void
      virtual void SetConfig (ICOStateMachineContext* p_pContext, CPIPersistentConfig* p_pConfig);

      //## Operation: GetpImpl%1067243912
      virtual CPOPersistentObjImplementation* GetpImpl (ICOStateMachineContext* p_pContext);

      //## Operation: Reset%1072788296
      //	DESCRIPTION
      //	Reset a eprom section
      //
      //	PARAMETER
      //	eSection
      //
      //	RETURNS
      //	async - void
      virtual void Reset (ICOStateMachineContext* p_pContext, EPIEpromSection p_eSection);

      //## Operation: MeasurementCellUndocked%1080142970
      //	DESCRIPTION
      //	tells the persistent object manager that the measurement
      //	cell has been undocked, meaning that the eprom has gone
      //
      //	RETURNS
      //	async void
      virtual void MeasurementCellUndocked (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPOState%3DE63804016C.public preserve=yes
      //## end CPOState%3DE63804016C.public

  protected:
    // Additional Protected Declarations
      //## begin CPOState%3DE63804016C.protected preserve=yes
      //## end CPOState%3DE63804016C.protected

  private:
    //## Constructors (generated)
      CPOState(const CPOState &right);

    //## Assignment Operation (generated)
      const CPOState & operator=(const CPOState &right);

    //## Equality Operations (generated)
      bool operator==(const CPOState &right) const;

      bool operator!=(const CPOState &right) const;

    // Additional Private Declarations
      //## begin CPOState%3DE63804016C.private preserve=yes
      //## end CPOState%3DE63804016C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOState%3DE63804016C.implementation preserve=yes
      //## end CPOState%3DE63804016C.implementation

};

//## begin CPOState%3DE63804016C.postscript preserve=yes
//## end CPOState%3DE63804016C.postscript

//## begin CPOStateCreated%3DE63B310321.preface preserve=yes
//## end CPOStateCreated%3DE63B310321.preface

//## Class: CPOStateCreated%3DE63B310321
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F9930AA001A;CPOStateConfig { -> }
//## Uses: <unnamed>%3F9931CF02D9;ICOStateMachineContext { -> }

class CPOStateCreated : public CPOState  //## Inherits: <unnamed>%3DE63B3D0312
{
  //## begin CPOStateCreated%3DE63B310321.initialDeclarations preserve=yes
  //## end CPOStateCreated%3DE63B310321.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateCreated();

    //## Destructor (generated)
      virtual ~CPOStateCreated();


    //## Other Operations (specified)
      //## Operation: Create%1038495068
      static void Create ();

      //## Operation: Delete%1038495069
      static void Delete ();

      //## Operation: GetInstance%1038495070
      static CPOStateCreated* GetInstance ();

      //## Operation: Startup%1038495071
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

      //## Operation: Shutdown%1038495072
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1063223341
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1063223342
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
      //## begin CPOStateCreated%3DE63B310321.public preserve=yes
      //## end CPOStateCreated%3DE63B310321.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateCreated%3DE63B310321.protected preserve=yes
      //## end CPOStateCreated%3DE63B310321.protected

  private:
    //## Constructors (generated)
      CPOStateCreated(const CPOStateCreated &right);

    //## Assignment Operation (generated)
      const CPOStateCreated & operator=(const CPOStateCreated &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateCreated &right) const;

      bool operator!=(const CPOStateCreated &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3DE63BEA0256
      //## Role: CPOStateCreated::pInstance%3DE63BEF0360
      //## begin CPOStateCreated::pInstance%3DE63BEF0360.role preserve=no  public: static CPOStateCreated {1..1 -> 1..1RFHN}
      static CPOStateCreated *m_pInstance;
      //## end CPOStateCreated::pInstance%3DE63BEF0360.role

    // Additional Private Declarations
      //## begin CPOStateCreated%3DE63B310321.private preserve=yes
      //## end CPOStateCreated%3DE63B310321.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateCreated%3DE63B310321.implementation preserve=yes
      //## end CPOStateCreated%3DE63B310321.implementation

};

//## begin CPOStateCreated%3DE63B310321.postscript preserve=yes
//## end CPOStateCreated%3DE63B310321.postscript

// Class CPOState 

// Class CPOStateCreated 

//## begin module%3DE5EB64037F.epilog preserve=yes
//## end module%3DE5EB64037F.epilog


#endif
