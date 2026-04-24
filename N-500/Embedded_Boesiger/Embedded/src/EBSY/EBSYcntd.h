//## begin module%3EEDB4F1018B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EEDB4F1018B.cm

//## begin module%3EEDB4F1018B.cp preserve=no
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
//## end module%3EEDB4F1018B.cp

//## Module: EBSYcntd%3EEDB4F1018B; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcntd.h

#ifndef EBSYcntd_h
#define EBSYcntd_h 1

//## begin module%3EEDB4F1018B.additionalIncludes preserve=no
//## end module%3EEDB4F1018B.additionalIncludes

//## begin module%3EEDB4F1018B.includes preserve=yes
//## end module%3EEDB4F1018B.includes

// EBSYcons
#include "EBSYcons.h"
//## begin module%3EEDB4F1018B.declarations preserve=no
//## end module%3EEDB4F1018B.declarations

//## begin module%3EEDB4F1018B.additionalDeclarations preserve=yes
//## end module%3EEDB4F1018B.additionalDeclarations


//## begin CSYStateConstitutionConnected%3EDC5B9C02A8.preface preserve=yes
//## end CSYStateConstitutionConnected%3EDC5B9C02A8.preface

//## Class: CSYStateConstitutionConnected%3EDC5B9C02A8
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EEDB1B90374;CSYStateConstitutionConfigInterface { -> }
//## Uses: <unnamed>%3EEDB1BD025B;CSYStateConstitutionDownloadSoftwareComponents { -> }
//## Uses: <unnamed>%3EEDB1BE0336;CSYStateConstitutionRegisteringUnits { -> }
//## Uses: <unnamed>%3EF7038F039C;CPISystem { -> }
//## Uses: <unnamed>%3EFBEFEF011B;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%3F0576F101DE;CSYModuleHandling { -> }
//## Uses: <unnamed>%3F431E3E0024;CPIComponentsState { -> }
//## Uses: <unnamed>%3F9D35C003BC;CHIInterface { -> }
//## Uses: <unnamed>%4006938F038D;CSYStateConstitutionReadSoftwareVersions { -> }
//## Uses: <unnamed>%4098135A03CA;CSYStateProcessStandBy { -> }
//## Uses: <unnamed>%409888D903D0;CSYSystemImplementation { -> }
//## Uses: <unnamed>%4098AE9A003B;CSYStateCreated { -> }

class CSYStateConstitutionConnected : public CSYStateConstitution  //## Inherits: <unnamed>%3EDC5B9C02AA
{
  //## begin CSYStateConstitutionConnected%3EDC5B9C02A8.initialDeclarations preserve=yes
  //## end CSYStateConstitutionConnected%3EDC5B9C02A8.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionConnected();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionConnected();


    //## Other Operations (specified)
      //## Operation: Create%1044959885
      static void Create ();

      //## Operation: Delete%1044959887
      static void Delete ();

      //## Operation: GetInstance%1044959886
      static CSYStateConstitutionConnected* GetInstance ();

      //## Operation: GetDeviceState%1056436751
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: Do%1057322343
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: SetInterfaceConfig%1055753495
      virtual void SetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig, CCOSyncObject* p_pClientSyncObj);

      //## Operation: ReadSoftwareVersions%1056358086
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

      //## Operation: DownloadSoftwareComponents%1055753506
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

      //## Operation: StartDevice%1055753496
      virtual void StartDevice (ICOStateMachineContext* p_pContext);

      //## Operation: ResetDevice%1056695969
      //	DESCRIPTION
      //	Shutdown system
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ResetDevice (ICOStateMachineContext* p_pContext);

      //## Operation: SetStandbyTimeout%1056695978
      virtual void SetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeout);

      //## Operation: SetComponentState%1061359183
      virtual void SetComponentState (ICOStateMachineContext* p_pContext, const CString& p_sComponentId, const bool p_bActive);

      //## Operation: ConnectionLost%1083744904
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: RegisterClient%1096656410
      virtual void RegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient);

      //## Operation: StartDownload%1200165526
      //	DESCRIPTION
      //	Starts a download process
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void StartDownload (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSYStateConstitutionConnected%3EDC5B9C02A8.public preserve=yes
      //## end CSYStateConstitutionConnected%3EDC5B9C02A8.public
  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionConnected%3EDC5B9C02A8.protected preserve=yes
      //## end CSYStateConstitutionConnected%3EDC5B9C02A8.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionConnected(const CSYStateConstitutionConnected &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionConnected & operator=(const CSYStateConstitutionConnected &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionConnected &right) const;

      bool operator!=(const CSYStateConstitutionConnected &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EDC5B9C0337
      //## Role: CSYStateConstitutionConnected::pInstance%3EDC5B9C033C
      //## begin CSYStateConstitutionConnected::pInstance%3EDC5B9C033C.role preserve=no  public: static CSYStateConstitutionConnected {1..1 -> RFHN}
      static CSYStateConstitutionConnected *m_pInstance;
      //## end CSYStateConstitutionConnected::pInstance%3EDC5B9C033C.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionConnected%3EDC5B9C02A8.private preserve=yes
      //## end CSYStateConstitutionConnected%3EDC5B9C02A8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionConnected%3EDC5B9C02A8.implementation preserve=yes
      //## end CSYStateConstitutionConnected%3EDC5B9C02A8.implementation

};

//## begin CSYStateConstitutionConnected%3EDC5B9C02A8.postscript preserve=yes
//## end CSYStateConstitutionConnected%3EDC5B9C02A8.postscript

// Class CSYStateConstitutionConnected 

//## begin module%3EEDB4F1018B.epilog preserve=yes
//## end module%3EEDB4F1018B.epilog


#endif
