//## begin module%3EED8824024F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED8824024F.cm

//## begin module%3EED8824024F.cp preserve=no
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
//## end module%3EED8824024F.cp

//## Module: EBSYidle%3EED8824024F; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYidle.h

#ifndef EBSYidle_h
#define EBSYidle_h 1

//## begin module%3EED8824024F.additionalIncludes preserve=no
//## end module%3EED8824024F.additionalIncludes

//## begin module%3EED8824024F.includes preserve=yes
//## end module%3EED8824024F.includes

// EBSYproc
#include "EBSYproc.h"
//## begin module%3EED8824024F.declarations preserve=no
//## end module%3EED8824024F.declarations

//## begin module%3EED8824024F.additionalDeclarations preserve=yes
//## end module%3EED8824024F.additionalDeclarations


//## begin CSYStateProcessIdle%3EDC5B9C02C2.preface preserve=yes
//## end CSYStateProcessIdle%3EDC5B9C02C2.preface

//## Class: CSYStateProcessIdle%3EDC5B9C02C2
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%40069841035E;CSYStateProcessReadSoftwareVersions { -> }
//## Uses: <unnamed>%4111DB8B0357;CSYStateConstitutionConfigInterface { -> }
//## Uses: <unnamed>%4111FC900364;CSYSystemImplementation { -> }
//## Uses: <unnamed>%468BB3E60012;CPIObjectFactory { -> }

class CSYStateProcessIdle : public CSYStateProcess  //## Inherits: <unnamed>%3EDC5B9C02C4
{
  //## begin CSYStateProcessIdle%3EDC5B9C02C2.initialDeclarations preserve=yes
  //## end CSYStateProcessIdle%3EDC5B9C02C2.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateProcessIdle();

    //## Destructor (generated)
      virtual ~CSYStateProcessIdle();


    //## Other Operations (specified)
      //## Operation: Create%1044959879
      static void Create ();

      //## Operation: Delete%1044959880
      static void Delete ();

      //## Operation: GetInstance%1044959881
      static CSYStateProcessIdle* GetInstance ();

      //## Operation: ReadSoftwareVersions%1067594683
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

      //## Operation: SetInterfaceConfig%1091689304
      virtual void SetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig, CCOSyncObject* p_pClientSyncObj);

      //## Operation: SetStandbyTimeout%1096722426
      virtual void SetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeout);

      //## Operation: StartDevice%1182780770
      //	DESCRIPTION
      //	Download and settings done, register units
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void StartDevice (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1183536496
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSYStateProcessIdle%3EDC5B9C02C2.public preserve=yes
      //## end CSYStateProcessIdle%3EDC5B9C02C2.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateProcessIdle%3EDC5B9C02C2.protected preserve=yes
      //## end CSYStateProcessIdle%3EDC5B9C02C2.protected

  private:
    //## Constructors (generated)
      CSYStateProcessIdle(const CSYStateProcessIdle &right);

    //## Assignment Operation (generated)
      const CSYStateProcessIdle & operator=(const CSYStateProcessIdle &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateProcessIdle &right) const;

      bool operator!=(const CSYStateProcessIdle &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EDC5B9C0347
      //## Role: CSYStateProcessIdle::pInstance%3EDC5B9C034C
      //## begin CSYStateProcessIdle::pInstance%3EDC5B9C034C.role preserve=no  public: static CSYStateProcessIdle {1..1 -> 1..1RFHN}
      static CSYStateProcessIdle *m_pInstance;
      //## end CSYStateProcessIdle::pInstance%3EDC5B9C034C.role

    // Additional Private Declarations
      //## begin CSYStateProcessIdle%3EDC5B9C02C2.private preserve=yes
      //## end CSYStateProcessIdle%3EDC5B9C02C2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateProcessIdle%3EDC5B9C02C2.implementation preserve=yes
      //## end CSYStateProcessIdle%3EDC5B9C02C2.implementation

};

//## begin CSYStateProcessIdle%3EDC5B9C02C2.postscript preserve=yes
//## end CSYStateProcessIdle%3EDC5B9C02C2.postscript

// Class CSYStateProcessIdle 

//## begin module%3EED8824024F.epilog preserve=yes
//## end module%3EED8824024F.epilog


#endif
