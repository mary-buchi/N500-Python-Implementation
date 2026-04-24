//## begin module%3EC8D242033F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EC8D242033F.cm

//## begin module%3EC8D242033F.cp preserve=no
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
//## end module%3EC8D242033F.cp

//## Module: EBCOthtm%3EC8D242033F; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOthtm.h

#ifndef EBCOthtm_h
#define EBCOthtm_h 1

//## begin module%3EC8D242033F.additionalIncludes preserve=no
//## end module%3EC8D242033F.additionalIncludes

//## begin module%3EC8D242033F.includes preserve=yes
//## end module%3EC8D242033F.includes

// EBCOthrd
#include "EBCOthrd.h"

class CCOThreadWorkImplementation;

//## begin module%3EC8D242033F.declarations preserve=no
//## end module%3EC8D242033F.declarations

//## begin module%3EC8D242033F.additionalDeclarations preserve=yes
//## end module%3EC8D242033F.additionalDeclarations


//## begin CCOThreadTimer%3EC8D21403CC.preface preserve=yes
//## end CCOThreadTimer%3EC8D21403CC.preface

//## Class: CCOThreadTimer%3EC8D21403CC
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCOThreadTimer : public ICOThreadWork  //## Inherits: <unnamed>%3EC8D2660330
{
  //## begin CCOThreadTimer%3EC8D21403CC.initialDeclarations preserve=yes
  //## end CCOThreadTimer%3EC8D21403CC.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOThreadTimer%1053348755
      CCOThreadTimer (CCOThreadWorkImplementation* p_pClient, UINT p_uiInterval);

    //## Destructor (generated)
      virtual ~CCOThreadTimer();


    //## Other Operations (specified)
      //## Operation: ThreadMain%1053348756
      virtual int ThreadMain ();

    // Additional Public Declarations
      //## begin CCOThreadTimer%3EC8D21403CC.public preserve=yes
      //## end CCOThreadTimer%3EC8D21403CC.public

  protected:
    // Additional Protected Declarations
      //## begin CCOThreadTimer%3EC8D21403CC.protected preserve=yes
      //## end CCOThreadTimer%3EC8D21403CC.protected

  private:
    //## Constructors (generated)
      CCOThreadTimer();

      CCOThreadTimer(const CCOThreadTimer &right);

    //## Assignment Operation (generated)
      const CCOThreadTimer & operator=(const CCOThreadTimer &right);

    //## Equality Operations (generated)
      bool operator==(const CCOThreadTimer &right) const;

      bool operator!=(const CCOThreadTimer &right) const;

    // Data Members for Class Attributes

      //## Attribute: uiInterval%3EC8D35401F7
      //## begin CCOThreadTimer::uiInterval%3EC8D35401F7.attr preserve=no  private: UINT {U} p_uiInterval
      UINT m_uiInterval;
      //## end CCOThreadTimer::uiInterval%3EC8D35401F7.attr

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3EC8D2BB00EE
      //## Role: CCOThreadTimer::pClient%3EC8D2BC0014
      //## begin CCOThreadTimer::pClient%3EC8D2BC0014.role preserve=no  public: CCOThreadWorkImplementation {1..1 -> 1..1RFHN}
      CCOThreadWorkImplementation *m_pClient;
      //## end CCOThreadTimer::pClient%3EC8D2BC0014.role

      //## Association: EBCO (Core Classes)::<unnamed>%3EC8D5140013
      //## Role: CCOThreadTimer::AccessLock%3EC8D5140218
      //## begin CCOThreadTimer::AccessLock%3EC8D5140218.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CCOThreadTimer::AccessLock%3EC8D5140218.role

    // Additional Private Declarations
      //## begin CCOThreadTimer%3EC8D21403CC.private preserve=yes
      //## end CCOThreadTimer%3EC8D21403CC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOThreadTimer%3EC8D21403CC.implementation preserve=yes
      //## end CCOThreadTimer%3EC8D21403CC.implementation

};

//## begin CCOThreadTimer%3EC8D21403CC.postscript preserve=yes
//## end CCOThreadTimer%3EC8D21403CC.postscript

// Class CCOThreadTimer 

//## begin module%3EC8D242033F.epilog preserve=yes
//## end module%3EC8D242033F.epilog


#endif
