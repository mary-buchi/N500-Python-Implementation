//## begin module%3DE5EC67015C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EC67015C.cm

//## begin module%3DE5EC67015C.cp preserve=no
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
//## end module%3DE5EC67015C.cp

//## Module: EBEScrea%3DE5EC67015C; Package specification
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Source file: R:\Embedded\src\EBES\EBEScrea.h

#ifndef EBEScrea_h
#define EBEScrea_h 1

//## begin module%3DE5EC67015C.additionalIncludes preserve=no
//## end module%3DE5EC67015C.additionalIncludes

//## begin module%3DE5EC67015C.includes preserve=yes
//## end module%3DE5EC67015C.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3DE5EC67015C.declarations preserve=no
//## end module%3DE5EC67015C.declarations

//## begin module%3DE5EC67015C.additionalDeclarations preserve=yes
//## end module%3DE5EC67015C.additionalDeclarations


//## begin CESEventSourceCreatorV0%3DE7107402CD.preface preserve=yes
//## end CESEventSourceCreatorV0%3DE7107402CD.preface

//## Class: CESEventSourceCreatorV0%3DE7107402CD
//## Category: EBES (Event Source)%3DE5E6910350
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEB72710259;CESEventSourceInterface { -> }

class CESEventSourceCreatorV0 : public CPIObjCreatorEventSource  //## Inherits: <unnamed>%3DE7109200C9
{
  //## begin CESEventSourceCreatorV0%3DE7107402CD.initialDeclarations preserve=yes
  //## end CESEventSourceCreatorV0%3DE7107402CD.initialDeclarations

  public:
    //## Constructors (generated)
      CESEventSourceCreatorV0();

    //## Destructor (generated)
      virtual ~CESEventSourceCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1038837051
      virtual IPIEventSourceInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CESEventSourceCreatorV0%3DE7107402CD.public preserve=yes
      //## end CESEventSourceCreatorV0%3DE7107402CD.public

  protected:
    // Additional Protected Declarations
      //## begin CESEventSourceCreatorV0%3DE7107402CD.protected preserve=yes
      //## end CESEventSourceCreatorV0%3DE7107402CD.protected

  private:
    //## Constructors (generated)
      CESEventSourceCreatorV0(const CESEventSourceCreatorV0 &right);

    //## Assignment Operation (generated)
      const CESEventSourceCreatorV0 & operator=(const CESEventSourceCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CESEventSourceCreatorV0 &right) const;

      bool operator!=(const CESEventSourceCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CESEventSourceCreatorV0%3DE7107402CD.private preserve=yes
      //## end CESEventSourceCreatorV0%3DE7107402CD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CESEventSourceCreatorV0%3DE7107402CD.implementation preserve=yes
      //## end CESEventSourceCreatorV0%3DE7107402CD.implementation

};

//## begin CESEventSourceCreatorV0%3DE7107402CD.postscript preserve=yes
//## end CESEventSourceCreatorV0%3DE7107402CD.postscript

// Class CESEventSourceCreatorV0 

//## begin module%3DE5EC67015C.epilog preserve=yes
//## end module%3DE5EC67015C.epilog


#endif
