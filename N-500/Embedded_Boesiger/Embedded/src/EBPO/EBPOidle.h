//## begin module%3DE5EB6B0266.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB6B0266.cm

//## begin module%3DE5EB6B0266.cp preserve=no
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
//## end module%3DE5EB6B0266.cp

//## Module: EBPOidle%3DE5EB6B0266; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOidle.h

#ifndef EBPOidle_h
#define EBPOidle_h 1

//## begin module%3DE5EB6B0266.additionalIncludes preserve=no
//## end module%3DE5EB6B0266.additionalIncludes

//## begin module%3DE5EB6B0266.includes preserve=yes
//## end module%3DE5EB6B0266.includes

// EBPOstat
#include "EBPOstat.h"
//## begin module%3DE5EB6B0266.declarations preserve=no
//## end module%3DE5EB6B0266.declarations

//## begin module%3DE5EB6B0266.additionalDeclarations preserve=yes
//## end module%3DE5EB6B0266.additionalDeclarations


//## begin CPOStateIdle%3F93ADF202C6.preface preserve=yes
//## end CPOStateIdle%3F93ADF202C6.preface

//## Class: CPOStateIdle%3F93ADF202C6
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F9CF8C9021F;PO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F9D17F8000C;CPOStateStore { -> }
//## Uses: <unnamed>%3F9D1D610115;CPOStateConfig { -> }
//## Uses: <unnamed>%3F9E201201BC;CPOLifeTimeCounterHandler { -> }
//## Uses: <unnamed>%3F9E210D00C2;CPOStateLifeTimeCounter { -> }
//## Uses: <unnamed>%3FA60D5101D4;CPOStateNotConnected { -> }
//## Uses: <unnamed>%3FAF4ABE00BB;CPOLogic { -> }
//## Uses: <unnamed>%4002DDDB011B;CPIPersistentIdent { -> }
//## Uses: <unnamed>%40239E9D000E;CPITicksAtStart { -> }
//## Uses: <unnamed>%405AD16003A3;CPOStateShuttingDown { -> }
//## Uses: <unnamed>%4061B4710119;CPOEpromManager { -> }
//## Uses: <unnamed>%4202138E0133;XCOExceptionCellUndocked { -> }

class CPOStateIdle : public CPOState  //## Inherits: <unnamed>%3F93CAE203CF
{
  //## begin CPOStateIdle%3F93ADF202C6.initialDeclarations preserve=yes
  //## end CPOStateIdle%3F93ADF202C6.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateIdle();

    //## Destructor (generated)
      virtual ~CPOStateIdle();


    //## Other Operations (specified)
      //## Operation: CleanupInitialize%1066888978
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

      //## Operation: StartMonitoring%1066888979
      //	DESCRIPTION
      //	Starts counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual void StartMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice);

      //## Operation: StopMonitoring%1066888980
      //	DESCRIPTION
      //	Stops counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual void StopMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice);

      //## Operation: Save%1066888981
      //	DESCRIPTION
      //	Saves data (parameters, operating data, identifications)
      //	to eeprom.
      //
      //	RETURNS
      //	async - void
      virtual void Save (ICOStateMachineContext* p_pContext);

      //## Operation: ReadParameters%1066888982
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

      //## Operation: Create%1066888988
      static void Create ();

      //## Operation: Delete%1066888989
      static void Delete ();

      //## Operation: GetInstance%1066888990
      static CPOStateIdle * GetInstance ();

      //## Operation: ReadLifeTimeCounter%1066918322
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

      //## Operation: ReadIdentifications%1066980585
      //	DESCRIPTION
      //	Reads all identifications from the persistent object
      //	store.
      //
      //	PARAMETERS
      //
      //	RETURNS
      //	CPISyncObjListIPersistentItems*
      virtual void ReadIdentifications (ICOStateMachineContext* p_pContext, CPISyncObjListPersistentItems *p_pSyncObjParameters);

      //## Operation: Do%1067251213
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: OnTimer%1067251214
      //	DESCRIPTION
      //	Notifies the subsystem of a timer event
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void OnTimer (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1067251218
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1067251223
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

      //## Operation: Shutdown%1067262119
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: WriteLifeTimeCounter%1068458447
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

      //## Operation: WriteIdentification%1077884326
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

      //## Operation: WriteParameter%1077884328
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

      //## Operation: Reset%1077888067
      //	DESCRIPTION
      //	Reset a eprom section
      //
      //	PARAMETER
      //	eSection
      //
      //	RETURNS
      //	async - void
      virtual void Reset (ICOStateMachineContext* p_pContext, EPIEpromSection p_eSection);

      //## Operation: MeasurementCellUndocked%1080142969
      //	DESCRIPTION
      //	tells the persistent object manager that the measurement
      //	cell has been undocked, meaning that the eprom has gone
      //
      //	RETURNS
      //	async void
      virtual void MeasurementCellUndocked (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPOStateIdle%3F93ADF202C6.public preserve=yes
      //## end CPOStateIdle%3F93ADF202C6.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateIdle%3F93ADF202C6.protected preserve=yes
      //## end CPOStateIdle%3F93ADF202C6.protected

  private:
    //## Constructors (generated)
      CPOStateIdle(const CPOStateIdle &right);

    //## Assignment Operation (generated)
      const CPOStateIdle & operator=(const CPOStateIdle &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateIdle &right) const;

      bool operator!=(const CPOStateIdle &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD6F0249
      //## Role: CPOStateIdle::pInstance%3F97CD700334
      //## begin CPOStateIdle::pInstance%3F97CD700334.role preserve=no  public: static CPOStateIdle {1..1 -> 1..1RFHN}
      static CPOStateIdle *m_pInstance;
      //## end CPOStateIdle::pInstance%3F97CD700334.role

    // Additional Private Declarations
      //## begin CPOStateIdle%3F93ADF202C6.private preserve=yes
      //## end CPOStateIdle%3F93ADF202C6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateIdle%3F93ADF202C6.implementation preserve=yes
      //## end CPOStateIdle%3F93ADF202C6.implementation

};

//## begin CPOStateIdle%3F93ADF202C6.postscript preserve=yes
//## end CPOStateIdle%3F93ADF202C6.postscript

// Class CPOStateIdle 

//## begin module%3DE5EB6B0266.epilog preserve=yes
//## end module%3DE5EB6B0266.epilog


#endif
