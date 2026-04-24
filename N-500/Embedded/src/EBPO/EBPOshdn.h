//## begin module%3FA609EA001F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA609EA001F.cm

//## begin module%3FA609EA001F.cp preserve=no
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
//## end module%3FA609EA001F.cp

//## Module: EBPOshdn%3FA609EA001F; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOshdn.h

#ifndef EBPOshdn_h
#define EBPOshdn_h 1

//## begin module%3FA609EA001F.additionalIncludes preserve=no
//## end module%3FA609EA001F.additionalIncludes

//## begin module%3FA609EA001F.includes preserve=yes
//## end module%3FA609EA001F.includes

// EBPOstat
#include "EBPOstat.h"
//## begin module%3FA609EA001F.declarations preserve=no
//## end module%3FA609EA001F.declarations

//## begin module%3FA609EA001F.additionalDeclarations preserve=yes
//## end module%3FA609EA001F.additionalDeclarations


//## begin CPOStateShuttingDown%3F93AF0403DF.preface preserve=yes
//## end CPOStateShuttingDown%3F93AF0403DF.preface

//## Class: CPOStateShuttingDown%3F93AF0403DF
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%405ACF440058;CPOLifeTimeCounterHandler { -> }
//## Uses: <unnamed>%4061BCC1005D;CPOLogic { -> }
//## Uses: <unnamed>%4061BCC5001F;CPOEpromManager { -> }

class CPOStateShuttingDown : public CPOState  //## Inherits: <unnamed>%3F93CAE90314
{
  //## begin CPOStateShuttingDown%3F93AF0403DF.initialDeclarations preserve=yes
  //## end CPOStateShuttingDown%3F93AF0403DF.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateShuttingDown();

    //## Destructor (generated)
      virtual ~CPOStateShuttingDown();


    //## Other Operations (specified)
      //## Operation: Do%1066888971
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: Create%1066888997
      static void Create ();

      //## Operation: Delete%1066888998
      static void Delete ();

      //## Operation: GetInstance%1066888999
      static CPOStateShuttingDown* GetInstance ();

      //## Operation: CleanupStop%1087983835
      //	DESCRIPTION
      //	Recovers from a 'Stop Cleanup' exception. State machine
      //	should be broght to the 'Initialized' state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void CleanupStop (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1087983836
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

    // Additional Public Declarations
      //## begin CPOStateShuttingDown%3F93AF0403DF.public preserve=yes
      //## end CPOStateShuttingDown%3F93AF0403DF.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateShuttingDown%3F93AF0403DF.protected preserve=yes
      //## end CPOStateShuttingDown%3F93AF0403DF.protected

  private:
    //## Constructors (generated)
      CPOStateShuttingDown(const CPOStateShuttingDown &right);

    //## Assignment Operation (generated)
      const CPOStateShuttingDown & operator=(const CPOStateShuttingDown &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateShuttingDown &right) const;

      bool operator!=(const CPOStateShuttingDown &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD7703A1
      //## Role: CPOStateShuttingDown::pInstance%3F97CD780354
      //## begin CPOStateShuttingDown::pInstance%3F97CD780354.role preserve=no  public: static CPOStateShuttingDown {1..1 -> 1..1RFHN}
      static CPOStateShuttingDown *m_pInstance;
      //## end CPOStateShuttingDown::pInstance%3F97CD780354.role

    // Additional Private Declarations
      //## begin CPOStateShuttingDown%3F93AF0403DF.private preserve=yes
      //## end CPOStateShuttingDown%3F93AF0403DF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateShuttingDown%3F93AF0403DF.implementation preserve=yes
      //## end CPOStateShuttingDown%3F93AF0403DF.implementation

};

//## begin CPOStateShuttingDown%3F93AF0403DF.postscript preserve=yes
//## end CPOStateShuttingDown%3F93AF0403DF.postscript

// Class CPOStateShuttingDown 

//## begin module%3FA609EA001F.epilog preserve=yes
//## end module%3FA609EA001F.epilog


#endif
