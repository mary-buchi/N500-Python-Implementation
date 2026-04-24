//## begin module%3DAAE3EA00A0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE3EA00A0.cm

//## begin module%3DAAE3EA00A0.cp preserve=no
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
//## end module%3DAAE3EA00A0.cp

//## Module: EBMCstat%3DAAE3EA00A0; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCstat.h

#ifndef EBMCstat_h
#define EBMCstat_h 1

//## begin module%3DAAE3EA00A0.additionalIncludes preserve=no
//## end module%3DAAE3EA00A0.additionalIncludes

//## begin module%3DAAE3EA00A0.includes preserve=yes
//## end module%3DAAE3EA00A0.includes

// EBCOstat
#include "EBCOstat.h"
// EBPItype
#include "EBPItype.h"

class CMCMeasurementChannelImplementation;

//## begin module%3DAAE3EA00A0.declarations preserve=no
//## end module%3DAAE3EA00A0.declarations

//## begin module%3DAAE3EA00A0.additionalDeclarations preserve=yes
//## end module%3DAAE3EA00A0.additionalDeclarations


//## begin CMCState%3DAAE7F800FE.preface preserve=yes
//## end CMCState%3DAAE7F800FE.preface

//## Class: CMCState%3DAAE7F800FE
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAE5989029B;XCOException { -> }
//## Uses: <unnamed>%3DAE59B00124;MC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DE4C6CB01CB;CPISyncObjDataPackage { -> }
//## Uses: <unnamed>%3E6D846701B5;CHIInterface { -> }
//## Uses: <unnamed>%3F9788D80070;CMCMeasurementChannelImplementation { -> F}

class CMCState : public CCOState  //## Inherits: <unnamed>%3DAAE80002E2
{
  //## begin CMCState%3DAAE7F800FE.initialDeclarations preserve=yes
  //## end CMCState%3DAAE7F800FE.initialDeclarations

  public:
    //## Constructors (generated)
      CMCState();

    //## Destructor (generated)
      virtual ~CMCState();


    //## Other Operations (specified)
      //## Operation: GetDataPackage%1034835010
      virtual void GetDataPackage (ICOStateMachineContext* p_pContext, CPISyncObjDataPackage* p_pClientSyncObj);

      //## Operation: Stop%1038405591
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: Start%1038405592
      virtual void Start (ICOStateMachineContext* p_pContext, UINT p_uiCycleID);

      //## Operation: SetProfile%1038405593
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile);

      //## Operation: Initialize%1038405594
      virtual void Initialize (ICOStateMachineContext* p_pContext);

      //## Operation: GetpContext%1066894462
      virtual CMCMeasurementChannelImplementation* GetpContext (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CMCState%3DAAE7F800FE.public preserve=yes
      //## end CMCState%3DAAE7F800FE.public

  protected:
    // Additional Protected Declarations
      //## begin CMCState%3DAAE7F800FE.protected preserve=yes
      //## end CMCState%3DAAE7F800FE.protected

  private:
    //## Constructors (generated)
      CMCState(const CMCState &right);

    //## Assignment Operation (generated)
      const CMCState & operator=(const CMCState &right);

    //## Equality Operations (generated)
      bool operator==(const CMCState &right) const;

      bool operator!=(const CMCState &right) const;

    // Additional Private Declarations
      //## begin CMCState%3DAAE7F800FE.private preserve=yes
      //## end CMCState%3DAAE7F800FE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCState%3DAAE7F800FE.implementation preserve=yes
      //## end CMCState%3DAAE7F800FE.implementation

};

//## begin CMCState%3DAAE7F800FE.postscript preserve=yes
//## end CMCState%3DAAE7F800FE.postscript

// Class CMCState 

//## begin module%3DAAE3EA00A0.epilog preserve=yes
//## end module%3DAAE3EA00A0.epilog


#endif
