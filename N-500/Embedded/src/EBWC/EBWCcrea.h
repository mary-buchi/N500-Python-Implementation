//## begin module%3DD0B4800087.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0B4800087.cm

//## begin module%3DD0B4800087.cp preserve=no
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
//## end module%3DD0B4800087.cp

//## Module: EBWCcrea%3DD0B4800087; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCcrea.h

#ifndef EBWCcrea_h
#define EBWCcrea_h 1

//## begin module%3DD0B4800087.additionalIncludes preserve=no
//## end module%3DD0B4800087.additionalIncludes

//## begin module%3DD0B4800087.includes preserve=yes
//## end module%3DD0B4800087.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3DD0B4800087.declarations preserve=no
//## end module%3DD0B4800087.declarations

//## begin module%3DD0B4800087.additionalDeclarations preserve=yes
//## end module%3DD0B4800087.additionalDeclarations


//## begin CWCWedgeControlCreatorV0%3DD0B3420394.preface preserve=yes
//## end CWCWedgeControlCreatorV0%3DD0B3420394.preface

//## Class: CWCWedgeControlCreatorV0%3DD0B3420394
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0BCB00096;CWCWedgeControlInterface { -> }

class CWCWedgeControlCreatorV0 : public CPIObjCreatorWedgeControl  //## Inherits: <unnamed>%3DD0B52A0317
{
  //## begin CWCWedgeControlCreatorV0%3DD0B3420394.initialDeclarations preserve=yes
  //## end CWCWedgeControlCreatorV0%3DD0B3420394.initialDeclarations

  public:
    //## Constructors (generated)
      CWCWedgeControlCreatorV0();

    //## Destructor (generated)
      virtual ~CWCWedgeControlCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1037094237
      virtual IPIWedgeControlInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CWCWedgeControlCreatorV0%3DD0B3420394.public preserve=yes
      //## end CWCWedgeControlCreatorV0%3DD0B3420394.public

  protected:
    // Additional Protected Declarations
      //## begin CWCWedgeControlCreatorV0%3DD0B3420394.protected preserve=yes
      //## end CWCWedgeControlCreatorV0%3DD0B3420394.protected

  private:
    //## Constructors (generated)
      CWCWedgeControlCreatorV0(const CWCWedgeControlCreatorV0 &right);

    //## Assignment Operation (generated)
      const CWCWedgeControlCreatorV0 & operator=(const CWCWedgeControlCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CWCWedgeControlCreatorV0 &right) const;

      bool operator!=(const CWCWedgeControlCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CWCWedgeControlCreatorV0%3DD0B3420394.private preserve=yes
      //## end CWCWedgeControlCreatorV0%3DD0B3420394.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCWedgeControlCreatorV0%3DD0B3420394.implementation preserve=yes
      //## end CWCWedgeControlCreatorV0%3DD0B3420394.implementation

};

//## begin CWCWedgeControlCreatorV0%3DD0B3420394.postscript preserve=yes
//## end CWCWedgeControlCreatorV0%3DD0B3420394.postscript

// Class CWCWedgeControlCreatorV0 

//## begin module%3DD0B4800087.epilog preserve=yes
//## end module%3DD0B4800087.epilog


#endif
