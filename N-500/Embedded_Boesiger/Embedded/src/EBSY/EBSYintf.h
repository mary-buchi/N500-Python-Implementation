//## begin module%3EDC5B3C01D4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01D4.cm

//## begin module%3EDC5B3C01D4.cp preserve=no
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
//## end module%3EDC5B3C01D4.cp

//## Module: EBSYintf%3EDC5B3C01D4; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYintf.h

#ifndef EBSYintf_h
#define EBSYintf_h 1

//## begin module%3EDC5B3C01D4.additionalIncludes preserve=no
//## end module%3EDC5B3C01D4.additionalIncludes

//## begin module%3EDC5B3C01D4.includes preserve=yes
//## end module%3EDC5B3C01D4.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3EDC5B3C01D4.declarations preserve=no
//## end module%3EDC5B3C01D4.declarations

//## begin module%3EDC5B3C01D4.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01D4.additionalDeclarations


//## begin CSYSystemInterface%3EDC5B9C0076.preface preserve=yes
//## end CSYSystemInterface%3EDC5B9C0076.preface

//## Class: CSYSystemInterface%3EDC5B9C0076
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EDC5B9C007B;SY_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EDC5B9C007E;CSYSystemImplementation { -> }
//## Uses: <unnamed>%3EDC5B9C0081;CCOSyncObject { -> }
//## Uses: <unnamed>%3EDC5B9C0084;CSYCommand { -> }

class EBSY_DLL_DECL CSYSystemInterface : public IPISystemInterface  //## Inherits: <unnamed>%3EE733DC00CB
{
  //## begin CSYSystemInterface%3EDC5B9C0076.initialDeclarations preserve=yes
  //## end CSYSystemInterface%3EDC5B9C0076.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYSystemInterface%1038899309
      CSYSystemInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CSYSystemInterface();


    //## Other Operations (specified)
      //## Operation: InitInstance%1039429760
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: ExitInstance%1056628599
      //	DESCRIPTION
      //	stops the implementation's worker thread and prepares
      //	for the final cleanup
      //
      //	RETURNS
      //	void
      virtual void ExitInstance ();

      //## Operation: GetuiID%1038899352
      virtual UINT GetuiID ();

      //## Operation: RegisterClient%1096656406
      //	registers a certain user as the current client.
      //	throws an 'XSYSystemBusy' exeption in case another
      //	client is already registered
      virtual CCOSyncObject* RegisterClient (const CString& p_sClient);

      //## Operation: StartDevice%1055330886
      //	DESCRIPTION
      //	Starts the device
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* StartDevice ();

      //## Operation: ResetDevice%1055330887
      //	DESCRIPTION
      //	Reset's the device
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ResetDevice ();

      //## Operation: GetDeviceState%1055330888
      //	DESCRIPTION
      //	Queries for the device' state
      //
      //	RETURNS
      //	device state
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: GetVersion%1096656414
      virtual CCOSyncObjectCString* GetVersion ();

      //## Operation: ReadSoftwareVersions%1055402516
      //	DESCRIPTION
      //	Returns a list with CPIPersistentSoftwareComponent
      //	Version Objects, describing the current software version
      //	of the modules managing the inital startup and
      //	communication
      //
      //	PARAMETERS
      //
      //
      //	RETURNS
      //	CPISyncObjListSWCompVersion*
      virtual CPISyncObjListSWCompVersion* ReadSoftwareVersions ();

      //## Operation: DownloadSoftwareComponents%1055330891
      //	DESCRIPTION
      //	Installs software components on the embedded system.
      //
      //	PARAMETERS
      //	software components for download
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* DownloadSoftwareComponents (CPIPersistentSoftwareComponentList* p_pComponentList);

      //## Operation: DownloadSoftwareComponent%1199783745
      //	DESCRIPTION
      //	Installs software components on the embedded system.
      //
      //	PARAMETERS
      //	software component for download
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* DownloadSoftwareComponent (CPIPersistentSoftwareComponent* p_pComponent);

      //## Operation: SetInterfaceConfig%1055429122
      //	DESCRIPTION
      //	Configures the PC Interface of the device
      //
      //	PARAMETERS
      //	Interface Config
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetInterfaceConfig (CPIInterfaceConfig* p_pInterfaceConfig);

      //## Operation: SetStandbyTimeout%1056695976
      //	DESCRIPTION
      //	Configures the timeout for connectionlost to put the
      //	device in the standby mode
      //
      //	PARAMETERS
      //	Standby Timeout value in ms
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetStandbyTimeout (const UINT p_uiTimeout);

      //## Operation: SetComponentState%1061301416
      //	DESCRIPTION
      //	Sets the state for a component to on (true) or off
      //	(false)
      //
      //	PARAMETERS
      //	ComponentId (String)
      //	State (bool)
      //
      //	RETURNS
      //	void
      virtual CCOSyncObject* SetComponentState (const CString& p_sComponentId, const bool p_bActive);

      //## Operation: GetObjectList%1063715457
      //	DESCRIPTION
      //	Returns a complete list of present objects in the
      //	currently living in the embedded system
      //
      //	RETURNS
      //	async: CStringArray
      virtual CPISyncObjectStringArray* GetObjectList ();

      //## Operation: SetSystemTime%1064429417
      //	DESCRIPTION
      //	sets the system time according to the given parameter
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetSystemTime (const SYSTEMTIME& p_SystemTime);

      //## Operation: GetOsVersion%1108540786
      //	DESCRIPTION
      //	Gets the WinCE OS Version
      //
      //	RETURNS:
      //	Version Major.Minor.Build.0 e.g. 5.0.1400.0
      virtual CCOSyncObjectCString* GetOsVersion ();

      //## Operation: GetFpgaVersion%1108540787
      //	DESCRIPTION
      //	Gets the FPGA Version
      //
      //	RETURNS:
      //	Version Major.Minor.Build.0 e.g. 5.0.1400.0
      virtual CCOSyncObjectCString* GetFpgaVersion ();

      //## Operation: StartDownload%1199783746
      //	DESCRIPTION
      //	Starts a download process
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* StartDownload ();

      //## Operation: EndDownload%1199783747
      //	DESCRIPTION
      //	Ends and completes a download process
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* EndDownload ();

    // Additional Public Declarations
      //## begin CSYSystemInterface%3EDC5B9C0076.public preserve=yes
      //## end CSYSystemInterface%3EDC5B9C0076.public

  protected:
    // Additional Protected Declarations
      //## begin CSYSystemInterface%3EDC5B9C0076.protected preserve=yes
      //## end CSYSystemInterface%3EDC5B9C0076.protected

  private:
    //## Constructors (generated)
      CSYSystemInterface();

      CSYSystemInterface(const CSYSystemInterface &right);

    //## Assignment Operation (generated)
      const CSYSystemInterface & operator=(const CSYSystemInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CSYSystemInterface &right) const;

      bool operator!=(const CSYSystemInterface &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EDC5B9C02F7
      //## Role: CSYSystemInterface::uiID%3EDC5B9C02FC
      //## begin CSYSystemInterface::uiID%3EDC5B9C02FC.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CSYSystemInterface::uiID%3EDC5B9C02FC.role

    // Additional Private Declarations
      //## begin CSYSystemInterface%3EDC5B9C0076.private preserve=yes
      //## end CSYSystemInterface%3EDC5B9C0076.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYSystemInterface%3EDC5B9C0076.implementation preserve=yes
      //## end CSYSystemInterface%3EDC5B9C0076.implementation

};

//## begin CSYSystemInterface%3EDC5B9C0076.postscript preserve=yes
//## end CSYSystemInterface%3EDC5B9C0076.postscript

// Class CSYSystemInterface 

//## begin module%3EDC5B3C01D4.epilog preserve=yes
//## end module%3EDC5B3C01D4.epilog


#endif
