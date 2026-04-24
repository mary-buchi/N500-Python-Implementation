//## begin module%3EDC5B3C01DA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01DA.cm

//## begin module%3EDC5B3C01DA.cp preserve=no
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
//## end module%3EDC5B3C01DA.cp

//## Module: EBSYstat%3EDC5B3C01DA; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYstat.h

#ifndef EBSYstat_h
#define EBSYstat_h 1

//## begin module%3EDC5B3C01DA.additionalIncludes preserve=no
//## end module%3EDC5B3C01DA.additionalIncludes

//## begin module%3EDC5B3C01DA.includes preserve=yes
//## end module%3EDC5B3C01DA.includes

// EBCOstat
#include "EBCOstat.h"
// EBCOimct
#include "EBCOimct.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBSYidnt
#include "EBSYidnt.h"

class CSYSystemImplementation;

//## begin module%3EDC5B3C01DA.declarations preserve=no
//## end module%3EDC5B3C01DA.declarations

//## begin module%3EDC5B3C01DA.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01DA.additionalDeclarations


//## begin CSYState%3EDC5B9C00C2.preface preserve=yes
//## end CSYState%3EDC5B9C00C2.preface

//## Class: CSYState%3EDC5B9C00C2
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EDC5B9C00CD;SY_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EDC5B9C00D0;XCOException { -> }
//## Uses: <unnamed>%3EDC5B9C00D3;CCOSyncObject { -> }
//## Uses: <unnamed>%3EEDB13B0303;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EEDD2A80146;CPIPersistentSoftwareComponentList { -> }
//## Uses: <unnamed>%3EF6C5510264; { -> }
//## Uses: <unnamed>%3F670A180125;CPIObjectFactory { -> }
//## Uses: <unnamed>%403475090117;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%409887D201CC;CSYSystemImplementation { -> F}

class CSYState : public CCOState  //## Inherits: <unnamed>%3EDC5B9C00C4
{
  //## begin CSYState%3EDC5B9C00C2.initialDeclarations preserve=yes
  //## end CSYState%3EDC5B9C00C2.initialDeclarations

  public:
    //## Constructors (generated)
      CSYState();

    //## Destructor (generated)
      virtual ~CSYState();


    //## Other Operations (specified)
      //## Operation: GetDeviceState%1056436738
      virtual EPIDeviceState GetDeviceState () = 0;

      //## Operation: StartDevice%1055753497
      //	DESCRIPTION
      //	Download and settings done, register units
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void StartDevice (ICOStateMachineContext* p_pContext);

      //## Operation: ResetDevice%1055753498
      //	DESCRIPTION
      //	Shutdown system
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ResetDevice (ICOStateMachineContext* p_pContext);

      //## Operation: SetStandbyTimeout%1056695977
      virtual void SetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeout);

      //## Operation: SetInterfaceConfig%1056523873
      virtual void SetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig, CCOSyncObject* p_pClientSyncObj);

      //## Operation: ReadSoftwareVersions%1055753500
      //	DESCRIPTION
      //	Reads all software-versions
      //
      //	PARAMETER
      //	- Context
      //	- Sync object with list of software components
      //
      //	RETURNS
      //	void
      virtual void ReadSoftwareVersions (ICOStateMachineContext* p_pContext, CPISyncObjListSWCompVersion* p_pClientSyncObj);

      //## Operation: DownloadSoftwareComponents%1055753502
      //	DESCRIPTION
      //	Downloads the software components
      //
      //	PARAMETER
      //	- Context
      //	- ComponentList of software to download
      //
      //	RETURNS
      //	void
      virtual void DownloadSoftwareComponents (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponentList* p_pComponentList, CCOSyncObject* p_pClientSyncObj);

      //## Operation: DownloadSoftwareComponent%1199783729
      //	DESCRIPTION
      //	Downloads the software components
      //
      //	PARAMETER
      //	- Context
      //	- Component to download
      //
      //	RETURNS
      //	void
      virtual void DownloadSoftwareComponent (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponent* p_pComponent);

      //## Operation: SetComponentState%1061359182
      virtual void SetComponentState (ICOStateMachineContext* p_pContext, const CString& p_sComponentId, const bool p_bActive);

      //## Operation: GetObjectList%1063715461
      virtual void GetObjectList (ICOStateMachineContext* p_pContext, CPISyncObjectStringArray* p_pSyncObj);

      //## Operation: SetSystemTime%1064429418
      virtual void SetSystemTime (ICOStateMachineContext* p_pContext, const SYSTEMTIME& p_SystemTime);

      //## Operation: RegisterClient%1096656409
      virtual void RegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient);

      //## Operation: GetVersion%1096656417
      virtual void GetVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: CleanupInitialize%1077175169
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

      //## Operation: GetOsVersion%1108540798
      virtual void GetOsVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: GetFpgaVersion%1108540799
      virtual void GetFpgaVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: StartDownload%1199783740
      //	DESCRIPTION
      //	Starts a download process
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void StartDownload (ICOStateMachineContext* p_pContext);

      //## Operation: EndDownload%1199783741
      //	DESCRIPTION
      //	Ends and completes a download process
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void EndDownload (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CSYState%3EDC5B9C00C2.public preserve=yes
      //## end CSYState%3EDC5B9C00C2.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetpContext%1083737621
      CSYSystemImplementation* GetpContext (ICOStateMachineContext* p_pContext);

    // Additional Protected Declarations
      //## begin CSYState%3EDC5B9C00C2.protected preserve=yes
      //## end CSYState%3EDC5B9C00C2.protected

  private:
    //## Constructors (generated)
      CSYState(const CSYState &right);

    //## Assignment Operation (generated)
      const CSYState & operator=(const CSYState &right);

    //## Equality Operations (generated)
      bool operator==(const CSYState &right) const;

      bool operator!=(const CSYState &right) const;

    // Additional Private Declarations
      //## begin CSYState%3EDC5B9C00C2.private preserve=yes
      //## end CSYState%3EDC5B9C00C2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYState%3EDC5B9C00C2.implementation preserve=yes
      //## end CSYState%3EDC5B9C00C2.implementation

};

//## begin CSYState%3EDC5B9C00C2.postscript preserve=yes
//## end CSYState%3EDC5B9C00C2.postscript

// Class CSYState 

//## begin module%3EDC5B3C01DA.epilog preserve=yes
//## end module%3EDC5B3C01DA.epilog


#endif
