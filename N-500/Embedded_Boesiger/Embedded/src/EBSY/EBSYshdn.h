//## begin module%3ED3620402BC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ED3620402BC.cm

//## begin module%3ED3620402BC.cp preserve=no
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
//## end module%3ED3620402BC.cp

//## Module: EBSYshdn%3ED3620402BC; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYshdn.h

#ifndef EBSYshdn_h
#define EBSYshdn_h 1

//## begin module%3ED3620402BC.additionalIncludes preserve=no
//## end module%3ED3620402BC.additionalIncludes

//## begin module%3ED3620402BC.includes preserve=yes
//## end module%3ED3620402BC.includes

// EBSYstat
#include "EBSYstat.h"
//## begin module%3ED3620402BC.declarations preserve=no
//## end module%3ED3620402BC.declarations

//## begin module%3ED3620402BC.additionalDeclarations preserve=yes
//## end module%3ED3620402BC.additionalDeclarations


//## begin CSYStateShuttingDown%3EE5E2D901E4.preface preserve=yes
//## end CSYStateShuttingDown%3EE5E2D901E4.preface

//## Class: CSYStateShuttingDown%3EE5E2D901E4
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE5E2D901E6;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EF1C137000E;CSYStateCreated { -> }
//## Uses: <unnamed>%3EF6AB2602F0;CPISystem { -> }
//## Uses: <unnamed>%3EF84BA301DC;CSYModuleHandling { -> }
//## Uses: <unnamed>%3F9D3565013B;CHIInterface { -> }

class CSYStateShuttingDown : public CSYState  //## Inherits: <unnamed>%4005632602DE
{
  //## begin CSYStateShuttingDown%3EE5E2D901E4.initialDeclarations preserve=yes
  //## end CSYStateShuttingDown%3EE5E2D901E4.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateShuttingDown();

    //## Destructor (generated)
      virtual ~CSYStateShuttingDown();


    //## Other Operations (specified)
      //## Operation: Create%1055252194
      static void Create ();

      //## Operation: Delete%1055252195
      static void Delete ();

      //## Operation: GetInstance%1055252196
      static CSYStateShuttingDown* GetInstance ();

      //## Operation: GetDeviceState%1056436742
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: Do%1056027091
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bRebootSystem%4098B0760348
      BOOL GetbRebootSystem ();
      void SetbRebootSystem (BOOL value);

    // Additional Public Declarations
      //## begin CSYStateShuttingDown%3EE5E2D901E4.public preserve=yes
      //## end CSYStateShuttingDown%3EE5E2D901E4.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateShuttingDown%3EE5E2D901E4.protected preserve=yes
      //## end CSYStateShuttingDown%3EE5E2D901E4.protected

  private:
    //## Constructors (generated)
      CSYStateShuttingDown(const CSYStateShuttingDown &right);

    //## Assignment Operation (generated)
      const CSYStateShuttingDown & operator=(const CSYStateShuttingDown &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateShuttingDown &right) const;

      bool operator!=(const CSYStateShuttingDown &right) const;

    // Data Members for Class Attributes

      //## begin CSYStateShuttingDown::bRebootSystem%4098B0760348.attr preserve=no  public: BOOL {U} false
      BOOL m_bRebootSystem;
      //## end CSYStateShuttingDown::bRebootSystem%4098B0760348.attr

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EE5E2D901EA
      //## Role: CSYStateShuttingDown::pInstance%3EE5E2D901EC
      //## begin CSYStateShuttingDown::pInstance%3EE5E2D901EC.role preserve=no  public: static CSYStateShuttingDown {1..1 -> 1..1RFHN}
      static CSYStateShuttingDown *m_pInstance;
      //## end CSYStateShuttingDown::pInstance%3EE5E2D901EC.role

    // Additional Private Declarations
      //## begin CSYStateShuttingDown%3EE5E2D901E4.private preserve=yes
      //## end CSYStateShuttingDown%3EE5E2D901E4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateShuttingDown%3EE5E2D901E4.implementation preserve=yes
      //## end CSYStateShuttingDown%3EE5E2D901E4.implementation

};

//## begin CSYStateShuttingDown%3EE5E2D901E4.postscript preserve=yes
//## end CSYStateShuttingDown%3EE5E2D901E4.postscript

// Class CSYStateShuttingDown 

//## begin module%3ED3620402BC.epilog preserve=yes
//## end module%3ED3620402BC.epilog


#endif
