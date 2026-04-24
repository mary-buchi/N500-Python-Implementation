//## begin module%3EDC5B3C01DC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01DC.cm

//## begin module%3EDC5B3C01DC.cp preserve=no
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
//## end module%3EDC5B3C01DC.cp

//## Module: EBSYcrea%3EDC5B3C01DC; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcrea.h

#ifndef EBSYcrea_h
#define EBSYcrea_h 1

//## begin module%3EDC5B3C01DC.additionalIncludes preserve=no
//## end module%3EDC5B3C01DC.additionalIncludes

//## begin module%3EDC5B3C01DC.includes preserve=yes
//## end module%3EDC5B3C01DC.includes

// EBSYstat
#include "EBSYstat.h"
//## begin module%3EDC5B3C01DC.declarations preserve=no
//## end module%3EDC5B3C01DC.declarations

//## begin module%3EDC5B3C01DC.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01DC.additionalDeclarations


//## begin CSYStateCreated%3EDC5B9C0227.preface preserve=yes
//## end CSYStateCreated%3EDC5B9C0227.preface

//## Class: CSYStateCreated%3EDC5B9C0227
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EDC5B9C022C;CSYStateConstitutionStandByWarmingUp { -> }
//## Uses: <unnamed>%3EDC5B9C022F;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EF6ACF8031F;CPISystem { -> }
//## Uses: <unnamed>%3F9D3580016A;CHIInterface { -> }

class CSYStateCreated : public CSYState  //## Inherits: <unnamed>%4005632A02FD
{
  //## begin CSYStateCreated%3EDC5B9C0227.initialDeclarations preserve=yes
  //## end CSYStateCreated%3EDC5B9C0227.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateCreated();

    //## Destructor (generated)
      virtual ~CSYStateCreated();


    //## Other Operations (specified)
      //## Operation: Create%1038899336
      static void Create ();

      //## Operation: Delete%1038899337
      static void Delete ();

      //## Operation: GetInstance%1056027096
      static CSYStateCreated* GetInstance ();

      //## Operation: GetDeviceState%1056436754
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: Do%1056027095
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1056027097
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

      //## Operation: Shutdown%1077175170
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bReset%403485A300FA
      bool GetbReset ();
      void SetbReset (bool value);

    // Additional Public Declarations
      //## begin CSYStateCreated%3EDC5B9C0227.public preserve=yes
      //## end CSYStateCreated%3EDC5B9C0227.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateCreated%3EDC5B9C0227.protected preserve=yes
      //## end CSYStateCreated%3EDC5B9C0227.protected

  private:
    //## Constructors (generated)
      CSYStateCreated(const CSYStateCreated &right);

    //## Assignment Operation (generated)
      const CSYStateCreated & operator=(const CSYStateCreated &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateCreated &right) const;

      bool operator!=(const CSYStateCreated &right) const;

    // Data Members for Class Attributes

      //## begin CSYStateCreated::bReset%403485A300FA.attr preserve=no  public: bool {U} false
      bool m_bReset;
      //## end CSYStateCreated::bReset%403485A300FA.attr

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EDC5B9C02FF
      //## Role: CSYStateCreated::pInstance%3EDC5B9C0304
      //## begin CSYStateCreated::pInstance%3EDC5B9C0304.role preserve=no  public: static CSYStateCreated {1..1 -> 1..1RFHN}
      static CSYStateCreated *m_pInstance;
      //## end CSYStateCreated::pInstance%3EDC5B9C0304.role

    // Additional Private Declarations
      //## begin CSYStateCreated%3EDC5B9C0227.private preserve=yes
      //## end CSYStateCreated%3EDC5B9C0227.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateCreated%3EDC5B9C0227.implementation preserve=yes
      //## end CSYStateCreated%3EDC5B9C0227.implementation

};

//## begin CSYStateCreated%3EDC5B9C0227.postscript preserve=yes
//## end CSYStateCreated%3EDC5B9C0227.postscript

// Class CSYStateCreated 

//## begin module%3EDC5B3C01DC.epilog preserve=yes
//## end module%3EDC5B3C01DC.epilog


#endif
