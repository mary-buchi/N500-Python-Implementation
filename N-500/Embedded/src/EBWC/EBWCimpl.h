//## begin module%3DD0F8A601B7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0F8A601B7.cm

//## begin module%3DD0F8A601B7.cp preserve=no
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
//## end module%3DD0F8A601B7.cp

//## Module: EBWCimpl%3DD0F8A601B7; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCimpl.h

#ifndef EBWCimpl_h
#define EBWCimpl_h 1

//## begin module%3DD0F8A601B7.additionalIncludes preserve=no
//## end module%3DD0F8A601B7.additionalIncludes

//## begin module%3DD0F8A601B7.includes preserve=yes
//## end module%3DD0F8A601B7.includes

// EBCOimpl
#include "EBCOimpl.h"
// EBCOsypr
#include "EBCOsypr.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBWC_DLL_DECL CWCWedgeControlInterface;

//## begin module%3DD0F8A601B7.declarations preserve=no
//## end module%3DD0F8A601B7.declarations

//## begin module%3DD0F8A601B7.additionalDeclarations preserve=yes
//## end module%3DD0F8A601B7.additionalDeclarations


//## begin CWCWedgeControlImplementation%3DD0F8560188.preface preserve=yes
//## end CWCWedgeControlImplementation%3DD0F8560188.preface

//## Class: CWCWedgeControlImplementation%3DD0F8560188
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD1017701A8;CWCStateMachineEngine { -> }
//## Uses: <unnamed>%3DD205E10219;CWCWedgeControlInterface { -> F}
//## Uses: <unnamed>%3F9D06A903C4;CPIComponentsState { -> }
//## Uses: <unnamed>%3F9D06B401EF;WC_IDENTIFIERS { -> }
//## Uses: <unnamed>%400B9ED5029F;CCOSyncObjectInt { -> }

class CWCWedgeControlImplementation : public ICOAsyncImplementation  //## Inherits: <unnamed>%3DD0F872011B
{
  //## begin CWCWedgeControlImplementation%3DD0F8560188.initialDeclarations preserve=yes
  //## end CWCWedgeControlImplementation%3DD0F8560188.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCWedgeControlImplementation%1037094241
      CWCWedgeControlImplementation (CWCWedgeControlInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~CWCWedgeControlImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%1037094240
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bHWPresent%3F9D062E023C
      bool GetbHWPresent ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%4007E704029F
      //## Role: CWCWedgeControlImplementation::pSyncExcObj%4007E705010A
      CCOSyncObjectInt * GetpSyncExcObj ();
      void SetpSyncExcObj (CCOSyncObjectInt * value);

      //## Association: EBWC (Wedge Control)::<unnamed>%4007E7070271
      //## Role: CWCWedgeControlImplementation::pSyncStartObj%4007E7080128
      CCOSyncObject * GetpSyncStartObj ();
      void SetpSyncStartObj (CCOSyncObject * value);

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%4007E704029F
      //## begin CWCWedgeControlImplementation::pSyncExcObj%4007E705010A.role preserve=no  public: CCOSyncObjectInt {1..1 -> 1..1RFHN}
      CCOSyncObjectInt *m_pSyncExcObj;
      //## end CWCWedgeControlImplementation::pSyncExcObj%4007E705010A.role

      //## Association: EBWC (Wedge Control)::<unnamed>%4007E7070271
      //## begin CWCWedgeControlImplementation::pSyncStartObj%4007E7080128.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pSyncStartObj;
      //## end CWCWedgeControlImplementation::pSyncStartObj%4007E7080128.role

    // Additional Public Declarations
      //## begin CWCWedgeControlImplementation%3DD0F8560188.public preserve=yes
      //## end CWCWedgeControlImplementation%3DD0F8560188.public

  protected:
    // Additional Protected Declarations
      //## begin CWCWedgeControlImplementation%3DD0F8560188.protected preserve=yes
      //## end CWCWedgeControlImplementation%3DD0F8560188.protected

  private:
    //## Constructors (generated)
      CWCWedgeControlImplementation();

      CWCWedgeControlImplementation(const CWCWedgeControlImplementation &right);

    //## Assignment Operation (generated)
      const CWCWedgeControlImplementation & operator=(const CWCWedgeControlImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CWCWedgeControlImplementation &right) const;

      bool operator!=(const CWCWedgeControlImplementation &right) const;

    // Data Members for Class Attributes

      //## begin CWCWedgeControlImplementation::bHWPresent%3F9D062E023C.attr preserve=no  public: bool {U} false
      bool m_bHWPresent;
      //## end CWCWedgeControlImplementation::bHWPresent%3F9D062E023C.attr

    // Additional Private Declarations
      //## begin CWCWedgeControlImplementation%3DD0F8560188.private preserve=yes
      //## end CWCWedgeControlImplementation%3DD0F8560188.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCWedgeControlImplementation%3DD0F8560188.implementation preserve=yes
      //## end CWCWedgeControlImplementation%3DD0F8560188.implementation

};

//## begin CWCWedgeControlImplementation%3DD0F8560188.postscript preserve=yes
//## end CWCWedgeControlImplementation%3DD0F8560188.postscript

// Class CWCWedgeControlImplementation 

//## begin module%3DD0F8A601B7.epilog preserve=yes
//## end module%3DD0F8A601B7.epilog


#endif
