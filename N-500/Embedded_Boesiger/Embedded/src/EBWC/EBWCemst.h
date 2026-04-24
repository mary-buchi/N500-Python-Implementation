//## begin module%3FCB35360251.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FCB35360251.cm

//## begin module%3FCB35360251.cp preserve=no
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
//## end module%3FCB35360251.cp

//## Module: EBWCemst%3FCB35360251; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCemst.h

#ifndef EBWCemst_h
#define EBWCemst_h 1

//## begin module%3FCB35360251.additionalIncludes preserve=no
//## end module%3FCB35360251.additionalIncludes

//## begin module%3FCB35360251.includes preserve=yes
//## end module%3FCB35360251.includes

// EBWCstat
#include "EBWCstat.h"
//## begin module%3FCB35360251.declarations preserve=no
//## end module%3FCB35360251.declarations

//## begin module%3FCB35360251.additionalDeclarations preserve=yes
//## end module%3FCB35360251.additionalDeclarations


//## begin CWCStateEmergencyStop%3FCB349E009C.preface preserve=yes
//## end CWCStateEmergencyStop%3FCB349E009C.preface

//## Class: CWCStateEmergencyStop%3FCB349E009C
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FCB39DC038A;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3FCB39DE038A;CWCStateNotConnected { -> }
//## Uses: <unnamed>%3FCB3A0302DE;CWCStateCreated { -> }
//## Uses: <unnamed>%3FCB3A6B038A;IHIInterface { -> }

class CWCStateEmergencyStop : public CWCState  //## Inherits: <unnamed>%3FCB378D0213
{
  //## begin CWCStateEmergencyStop%3FCB349E009C.initialDeclarations preserve=yes
  //## end CWCStateEmergencyStop%3FCB349E009C.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateEmergencyStop();

    //## Destructor (generated)
      virtual ~CWCStateEmergencyStop();


    //## Other Operations (specified)
      //## Operation: Create%1070263834
      static void Create ();

      //## Operation: GetInstance%1070263835
      static CWCStateEmergencyStop* GetInstance ();

      //## Operation: Delete%1070263836
      static void Delete ();

      //## Operation: Shutdown%1070263837
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: Do%1070263838
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CWCStateEmergencyStop%3FCB349E009C.public preserve=yes
      //## end CWCStateEmergencyStop%3FCB349E009C.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateEmergencyStop%3FCB349E009C.protected preserve=yes
      //## end CWCStateEmergencyStop%3FCB349E009C.protected

  private:
    //## Constructors (generated)
      CWCStateEmergencyStop(const CWCStateEmergencyStop &right);

    //## Assignment Operation (generated)
      const CWCStateEmergencyStop & operator=(const CWCStateEmergencyStop &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateEmergencyStop &right) const;

      bool operator!=(const CWCStateEmergencyStop &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FCB37670203
      //## Role: CWCStateEmergencyStop::pInstance%3FCB37680223
      //## begin CWCStateEmergencyStop::pInstance%3FCB37680223.role preserve=no  public: static CWCStateEmergencyStop {1..1 -> 1..1RFHN}
      static CWCStateEmergencyStop *m_pInstance;
      //## end CWCStateEmergencyStop::pInstance%3FCB37680223.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3FCB37670203
      //## Role: CWCStateEmergencyStop::<m_CWCStateEmergencyStop>%3FCB37680222
      //## begin CWCStateEmergencyStop::<m_CWCStateEmergencyStop>%3FCB37680222.role preserve=no  public: CWCStateEmergencyStop {1..1 -> 1..1RFHGN}
      CWCStateEmergencyStop *m_CWCStateEmergencyStop;
      //## end CWCStateEmergencyStop::<m_CWCStateEmergencyStop>%3FCB37680222.role

    // Additional Private Declarations
      //## begin CWCStateEmergencyStop%3FCB349E009C.private preserve=yes
      //## end CWCStateEmergencyStop%3FCB349E009C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateEmergencyStop%3FCB349E009C.implementation preserve=yes
      //## end CWCStateEmergencyStop%3FCB349E009C.implementation

};

//## begin CWCStateEmergencyStop%3FCB349E009C.postscript preserve=yes
//## end CWCStateEmergencyStop%3FCB349E009C.postscript

// Class CWCStateEmergencyStop 

//## begin module%3FCB35360251.epilog preserve=yes
//## end module%3FCB35360251.epilog


#endif
