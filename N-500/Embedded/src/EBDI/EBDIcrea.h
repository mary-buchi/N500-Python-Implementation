//## begin module%3E1981110328.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E1981110328.cm

//## begin module%3E1981110328.cp preserve=no
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
//## end module%3E1981110328.cp

//## Module: EBDIcrea%3E1981110328; Package specification
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDIcrea.h

#ifndef EBDIcrea_h
#define EBDIcrea_h 1

//## begin module%3E1981110328.additionalIncludes preserve=no
//## end module%3E1981110328.additionalIncludes

//## begin module%3E1981110328.includes preserve=yes
//## end module%3E1981110328.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3E1981110328.declarations preserve=no
//## end module%3E1981110328.declarations

//## begin module%3E1981110328.additionalDeclarations preserve=yes
//## end module%3E1981110328.additionalDeclarations


//## begin CDIDiagnosticCreatorV0%3E198B090328.preface preserve=yes
//## end CDIDiagnosticCreatorV0%3E198B090328.preface

//## Class: CDIDiagnosticCreatorV0%3E198B090328
//## Category: EBDI (Diagnostics)%3E197C790124
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E19999500A7;CDIDiagnosticInterface { -> }

class CDIDiagnosticCreatorV0 : public CPIObjCreatorDiagnostics  //## Inherits: <unnamed>%3E198B6E0105
{
  //## begin CDIDiagnosticCreatorV0%3E198B090328.initialDeclarations preserve=yes
  //## end CDIDiagnosticCreatorV0%3E198B090328.initialDeclarations

  public:
    //## Constructors (generated)
      CDIDiagnosticCreatorV0();

    //## Destructor (generated)
      virtual ~CDIDiagnosticCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1041861675
      virtual IPIDiagnosticInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CDIDiagnosticCreatorV0%3E198B090328.public preserve=yes
      //## end CDIDiagnosticCreatorV0%3E198B090328.public

  protected:
    // Additional Protected Declarations
      //## begin CDIDiagnosticCreatorV0%3E198B090328.protected preserve=yes
      //## end CDIDiagnosticCreatorV0%3E198B090328.protected

  private:
    //## Constructors (generated)
      CDIDiagnosticCreatorV0(const CDIDiagnosticCreatorV0 &right);

    //## Assignment Operation (generated)
      const CDIDiagnosticCreatorV0 & operator=(const CDIDiagnosticCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CDIDiagnosticCreatorV0 &right) const;

      bool operator!=(const CDIDiagnosticCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CDIDiagnosticCreatorV0%3E198B090328.private preserve=yes
      //## end CDIDiagnosticCreatorV0%3E198B090328.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CDIDiagnosticCreatorV0%3E198B090328.implementation preserve=yes
      //## end CDIDiagnosticCreatorV0%3E198B090328.implementation

};

//## begin CDIDiagnosticCreatorV0%3E198B090328.postscript preserve=yes
//## end CDIDiagnosticCreatorV0%3E198B090328.postscript

// Class CDIDiagnosticCreatorV0 

//## begin module%3E1981110328.epilog preserve=yes
//## end module%3E1981110328.epilog


#endif
