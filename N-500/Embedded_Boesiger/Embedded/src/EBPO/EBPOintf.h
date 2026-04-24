//## begin module%3DE5EB25011E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB25011E.cm

//## begin module%3DE5EB25011E.cp preserve=no
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
//## end module%3DE5EB25011E.cp

//## Module: EBPOintf%3DE5EB25011E; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOintf.h

#ifndef EBPOintf_h
#define EBPOintf_h 1

//## begin module%3DE5EB25011E.additionalIncludes preserve=no
//## end module%3DE5EB25011E.additionalIncludes

//## begin module%3DE5EB25011E.includes preserve=yes
//## end module%3DE5EB25011E.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3DE5EB25011E.declarations preserve=no
//## end module%3DE5EB25011E.declarations

//## begin module%3DE5EB25011E.additionalDeclarations preserve=yes
//## end module%3DE5EB25011E.additionalDeclarations


//## begin CPOPersistentObjInterface%3DE62969019B.preface preserve=yes
//## end CPOPersistentObjInterface%3DE62969019B.preface

//## Class: CPOPersistentObjInterface%3DE62969019B
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE632F500EF;PO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DE6350C0295;CPOPersistentObjImplementation { -> }
//## Uses: <unnamed>%3DEE13260391;CPOCommand { -> }
//## Uses: <unnamed>%3F96417F001A;CPISyncObjListPersistentItems { -> }

class EBPO_DLL_DECL CPOPersistentObjInterface : public IPIPersistentObjInterface  //## Inherits: <unnamed>%3DE62981017B
{
  //## begin CPOPersistentObjInterface%3DE62969019B.initialDeclarations preserve=yes
  //## end CPOPersistentObjInterface%3DE62969019B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOPersistentObjInterface%1038493581
      CPOPersistentObjInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CPOPersistentObjInterface();


    //## Other Operations (specified)
      //## Operation: GetuiID%1038493582
      virtual UINT GetuiID ();

      //## Operation: InitInstance%1038493591
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: ReadParameters%1066717298
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
      virtual CPISyncObjListPersistentItems* ReadParameters ();

      //## Operation: WriteParameter%1035528318
      //	DESCRIPTION
      //	Writes a single parameter into the persistent memory.
      //
      //	PARAMETERS
      //	- Parameter to write
      //	- Parameter location
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteParameter (CPIPersistentPara* p_pParameter);

      //## Operation: StartMonitoring%1066717300
      //	DESCRIPTION
      //	Starts counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject * StartMonitoring (EPILifeTimeCounter p_eDevice);

      //## Operation: StopMonitoring%1066717301
      //	DESCRIPTION
      //	Stops counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject * StopMonitoring (EPILifeTimeCounter p_eDevice);

      //## Operation: Save%1066717302
      //	DESCRIPTION
      //	Saves data (parameters, operating data, identifications)
      //	to eeprom.
      //
      //	RETURNS
      //	async - void
      virtual CCOSyncObject* Save ();

      //## Operation: ReadLifeTimeCounter%1066808240
      //	DESCRIPTION
      //	Reads the value of the specified operating data counter
      //	from the persistent object store
      //
      //	PARAMETERS
      //	Operating data counter to read
      //
      //	RETURNS
      //	async: int [s] or [number of scans]
      virtual CCOSyncObjectInt* ReadLifeTimeCounter (EPILifeTimeCounter p_eCounter);

      //## Operation: WriteLifeTimeCounter%1066717304
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
      virtual CCOSyncObject* WriteLifeTimeCounter (EPILifeTimeCounter p_eCounter, UINT p_uiValue);

      //## Operation: ReadIdentifications%1066717305
      //	DESCRIPTION
      //	Reads all identifications from the persistent object
      //	store.
      //
      //	PARAMETERS
      //
      //	RETURNS
      //	CPISyncObjListIPersistentItems*
      virtual CPISyncObjListPersistentItems* ReadIdentifications ();

      //## Operation: WriteIdentification%1066808241
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
      virtual CCOSyncObject* WriteIdentification (CPIPersistentIdent* p_oIdentification);

      //## Operation: SetConfig%1066813275
      //	DESCRIPTION
      //	Configurates the persistent object parameters
      //
      //	PARAMETERS
      //	p_PersistentConfig
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfig (CPIPersistentConfig* p_pConfig);

      //## Operation: Reset%1072788293
      //	DESCRIPTION
      //	Resets a eprom section
      //
      //	PARAMETERS
      //	p_eSection
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Reset (EPIEpromSection p_eSection);

      //## Operation: MeasurementCellUndocked%1080142971
      //	DESCRIPTION
      //	tells the persistent object manager that the measurement
      //	cell has been undocked, meaning that the eprom has gone
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* MeasurementCellUndocked ();

    // Additional Public Declarations
      //## begin CPOPersistentObjInterface%3DE62969019B.public preserve=yes
      //## end CPOPersistentObjInterface%3DE62969019B.public

  protected:
    // Additional Protected Declarations
      //## begin CPOPersistentObjInterface%3DE62969019B.protected preserve=yes
      //## end CPOPersistentObjInterface%3DE62969019B.protected

  private:
    //## Constructors (generated)
      CPOPersistentObjInterface();

      CPOPersistentObjInterface(const CPOPersistentObjInterface &right);

    //## Assignment Operation (generated)
      const CPOPersistentObjInterface & operator=(const CPOPersistentObjInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CPOPersistentObjInterface &right) const;

      bool operator!=(const CPOPersistentObjInterface &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3DE62D6E0208
      //## Role: CPOPersistentObjInterface::uiID%3DE62D6F00C0
      //## begin CPOPersistentObjInterface::uiID%3DE62D6F00C0.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CPOPersistentObjInterface::uiID%3DE62D6F00C0.role

    // Additional Private Declarations
      //## begin CPOPersistentObjInterface%3DE62969019B.private preserve=yes
      //## end CPOPersistentObjInterface%3DE62969019B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOPersistentObjInterface%3DE62969019B.implementation preserve=yes
      //## end CPOPersistentObjInterface%3DE62969019B.implementation

};

//## begin CPOPersistentObjInterface%3DE62969019B.postscript preserve=yes
//## end CPOPersistentObjInterface%3DE62969019B.postscript

// Class CPOPersistentObjInterface 

//## begin module%3DE5EB25011E.epilog preserve=yes
//## end module%3DE5EB25011E.epilog


#endif
