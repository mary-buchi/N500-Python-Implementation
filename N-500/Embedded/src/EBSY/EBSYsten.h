//## begin module%3EDC5B3C01D8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01D8.cm

//## begin module%3EDC5B3C01D8.cp preserve=no
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
//## end module%3EDC5B3C01D8.cp

//## Module: EBSYsten%3EDC5B3C01D8; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYsten.h

#ifndef EBSYsten_h
#define EBSYsten_h 1

//## begin module%3EDC5B3C01D8.additionalIncludes preserve=no
//## end module%3EDC5B3C01D8.additionalIncludes

//## begin module%3EDC5B3C01D8.includes preserve=yes
//## end module%3EDC5B3C01D8.includes

// EBCOimct
#include "EBCOimct.h"
// EBPItype
#include "EBPItype.h"
//## begin module%3EDC5B3C01D8.declarations preserve=no
//## end module%3EDC5B3C01D8.declarations

//## begin module%3EDC5B3C01D8.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01D8.additionalDeclarations


//## begin CSYStateMachineEngine%3EDC5B9C00AC.preface preserve=yes
//## end CSYStateMachineEngine%3EDC5B9C00AC.preface

//## Class: CSYStateMachineEngine%3EDC5B9C00AC
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EDC5B9C00B1;CSYStateCreated { -> }
//## Uses: <unnamed>%3EE9BDA2007E;CSYStateConstitutionStandByWarmingUp { -> }
//## Uses: <unnamed>%3EE9BDA300EB;CSYStateConstitutionConfigInterface { -> }
//## Uses: <unnamed>%3EE9BDA50197;CSYStateConstitutionConnected { -> }
//## Uses: <unnamed>%3EE9BDA7038B;CSYStateConstitutionDownloadSoftwareComponents { -> }
//## Uses: <unnamed>%3EE9BDAA0262;CSYStateConstitutionRegisteringUnits { -> }
//## Uses: <unnamed>%3EE9BDAC0001;CSYStateProcessIdle { -> }
//## Uses: <unnamed>%3EE9BDAD01B6;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%3EF6EC460002;SY_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EF83F7C0315;EPIDeviceState { -> }
//## Uses: <unnamed>%40068F24011C;CSYStateConstitutionReadSoftwareVersions { -> }
//## Uses: <unnamed>%40068F5D03BB;CSYStateProcessReadSoftwareVersions { -> }
//## Uses: <unnamed>%40980EE80233;CSYStateProcessStandBy { -> }

class CSYStateMachineEngine : public CCOStateMachineEngine  //## Inherits: <unnamed>%3EDC5B9C00AE
{
  //## begin CSYStateMachineEngine%3EDC5B9C00AC.initialDeclarations preserve=yes
  //## end CSYStateMachineEngine%3EDC5B9C00AC.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYStateMachineEngine%1038899322
      CSYStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSYStateMachineEngine();


    //## Other Operations (specified)
      //## Operation: BuildStateMachine%1038899323
      //	DESCRIPTION
      //	Builds up the entire state machine.
      //
      //	RETURNS
      //	void
      static void BuildStateMachine ();

      //## Operation: DeleteStateMachine%1038899325
      //	DESCRIPTION
      //	Cleans up the entire state machine.
      //
      //	RETURNS
      //	void
      static void DeleteStateMachine ();

      //## Operation: GetDeviceState%1056436745
      virtual EPIDeviceState GetDeviceState ();

    // Additional Public Declarations
      //## begin CSYStateMachineEngine%3EDC5B9C00AC.public preserve=yes
      //## end CSYStateMachineEngine%3EDC5B9C00AC.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetInitializeState%1042097144
      //	DESCRIPTION
      //	Gets the initialize state
      //
      //	RETURNS
      //	Pointer to initial state
      virtual CCOState* GetInitializeState ();

      //## Operation: CreateActions%1038899324
      //	DESCRIPTION
      //	Creates all existing actions and places them into the
      //	array of actions.
      //
      //	PARAMETER
      //	Action pointer List
      //
      //	RETURNS
      //	void
      virtual void CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList);

    // Additional Protected Declarations
      //## begin CSYStateMachineEngine%3EDC5B9C00AC.protected preserve=yes
      //## end CSYStateMachineEngine%3EDC5B9C00AC.protected

  private:
    //## Constructors (generated)
      CSYStateMachineEngine();

      CSYStateMachineEngine(const CSYStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CSYStateMachineEngine & operator=(const CSYStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateMachineEngine &right) const;

      bool operator!=(const CSYStateMachineEngine &right) const;

    // Additional Private Declarations
      //## begin CSYStateMachineEngine%3EDC5B9C00AC.private preserve=yes
      //## end CSYStateMachineEngine%3EDC5B9C00AC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateMachineEngine%3EDC5B9C00AC.implementation preserve=yes
      //## end CSYStateMachineEngine%3EDC5B9C00AC.implementation

};

//## begin CSYStateMachineEngine%3EDC5B9C00AC.postscript preserve=yes
//## end CSYStateMachineEngine%3EDC5B9C00AC.postscript

// Class CSYStateMachineEngine 

//## begin module%3EDC5B3C01D8.epilog preserve=yes
//## end module%3EDC5B3C01D8.epilog


#endif
