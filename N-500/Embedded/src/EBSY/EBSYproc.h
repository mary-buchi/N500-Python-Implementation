//## begin module%3EDC5B3C020A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C020A.cm

//## begin module%3EDC5B3C020A.cp preserve=no
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
//## end module%3EDC5B3C020A.cp

//## Module: EBSYproc%3EDC5B3C020A; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYproc.h

#ifndef EBSYproc_h
#define EBSYproc_h 1

//## begin module%3EDC5B3C020A.additionalIncludes preserve=no
//## end module%3EDC5B3C020A.additionalIncludes

//## begin module%3EDC5B3C020A.includes preserve=yes
//## end module%3EDC5B3C020A.includes

// EBSYstat
#include "EBSYstat.h"
//## begin module%3EDC5B3C020A.declarations preserve=no
//## end module%3EDC5B3C020A.declarations

//## begin module%3EDC5B3C020A.additionalDeclarations preserve=yes
//## end module%3EDC5B3C020A.additionalDeclarations


//## begin CSYStateProcess%3EDC5B9C02EA.preface preserve=yes
//## end CSYStateProcess%3EDC5B9C02EA.preface

//## Class: CSYStateProcess%3EDC5B9C02EA
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF1BC1B01C3;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%409812DE02FA;CSYStateProcessStandBy { -> }
//## Uses: <unnamed>%4098AE7F02EB;CSYStateCreated { -> }
//## Uses: <unnamed>%415D8B5F030B;CSYSystemImplementation { -> }

class CSYStateProcess : public CSYState  //## Inherits: <unnamed>%3EDC5B9C02EC
{
  //## begin CSYStateProcess%3EDC5B9C02EA.initialDeclarations preserve=yes
  //## end CSYStateProcess%3EDC5B9C02EA.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateProcess();

    //## Destructor (generated)
      virtual ~CSYStateProcess();


    //## Other Operations (specified)
      //## Operation: GetDeviceState%1056436740
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: ConnectionLost%1055753509
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: ResetDevice%1056027090
      //	DESCRIPTION
      //	Shutdown system
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ResetDevice (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1064318156
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

      //## Operation: StartDevice%1064318157
      //	DESCRIPTION
      //	Download and settings done, register units
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void StartDevice (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1083744905
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: RegisterClient%1096656411
      virtual void RegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient);

      //## Operation: GetVersion%1096656420
      virtual void GetVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: GetOsVersion%1108540794
      virtual void GetOsVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: GetFpgaVersion%1108540795
      virtual void GetFpgaVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CSYStateProcess%3EDC5B9C02EA.public preserve=yes
      //## end CSYStateProcess%3EDC5B9C02EA.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateProcess%3EDC5B9C02EA.protected preserve=yes
      //## end CSYStateProcess%3EDC5B9C02EA.protected

  private:
    //## Constructors (generated)
      CSYStateProcess(const CSYStateProcess &right);

    //## Assignment Operation (generated)
      const CSYStateProcess & operator=(const CSYStateProcess &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateProcess &right) const;

      bool operator!=(const CSYStateProcess &right) const;

    // Additional Private Declarations
      //## begin CSYStateProcess%3EDC5B9C02EA.private preserve=yes
      //## end CSYStateProcess%3EDC5B9C02EA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateProcess%3EDC5B9C02EA.implementation preserve=yes
      //## end CSYStateProcess%3EDC5B9C02EA.implementation

};

//## begin CSYStateProcess%3EDC5B9C02EA.postscript preserve=yes
//## end CSYStateProcess%3EDC5B9C02EA.postscript

// Class CSYStateProcess 

//## begin module%3EDC5B3C020A.epilog preserve=yes
//## end module%3EDC5B3C020A.epilog


#endif
