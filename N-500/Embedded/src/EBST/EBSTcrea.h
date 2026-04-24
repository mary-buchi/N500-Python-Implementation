//## begin module%3DA5C60D024B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5C60D024B.cm

//## begin module%3DA5C60D024B.cp preserve=no
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
//## end module%3DA5C60D024B.cp

//## Module: EBSTcrea%3DA5C60D024B; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTcrea.h

#ifndef EBSTcrea_h
#define EBSTcrea_h 1

//## begin module%3DA5C60D024B.additionalIncludes preserve=no
//## end module%3DA5C60D024B.additionalIncludes

//## begin module%3DA5C60D024B.includes preserve=yes
//## end module%3DA5C60D024B.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3DA5C60D024B.declarations preserve=no
//## end module%3DA5C60D024B.declarations

//## begin module%3DA5C60D024B.additionalDeclarations preserve=yes
//## end module%3DA5C60D024B.additionalDeclarations


//## begin CSTStepperCreatorV0%3DA5C65500D2.preface preserve=yes
//## end CSTStepperCreatorV0%3DA5C65500D2.preface

//## Class: CSTStepperCreatorV0%3DA5C65500D2
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA5C6D801CB;CSTStepperMotorInterface { -> }

class EBST_DLL_DECL CSTStepperCreatorV0 : public CPIObjCreatorStepperMotor  //## Inherits: <unnamed>%3DAAC6DC036F
{
  //## begin CSTStepperCreatorV0%3DA5C65500D2.initialDeclarations preserve=yes
  //## end CSTStepperCreatorV0%3DA5C65500D2.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStepperCreatorV0();

    //## Destructor (generated)
      virtual ~CSTStepperCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1034272541
      virtual IPIStepperMotorInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CSTStepperCreatorV0%3DA5C65500D2.public preserve=yes
      //## end CSTStepperCreatorV0%3DA5C65500D2.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStepperCreatorV0%3DA5C65500D2.protected preserve=yes
      //## end CSTStepperCreatorV0%3DA5C65500D2.protected

  private:
    //## Constructors (generated)
      CSTStepperCreatorV0(const CSTStepperCreatorV0 &right);

    //## Assignment Operation (generated)
      const CSTStepperCreatorV0 & operator=(const CSTStepperCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStepperCreatorV0 &right) const;

      bool operator!=(const CSTStepperCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CSTStepperCreatorV0%3DA5C65500D2.private preserve=yes
      //## end CSTStepperCreatorV0%3DA5C65500D2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStepperCreatorV0%3DA5C65500D2.implementation preserve=yes
      //## end CSTStepperCreatorV0%3DA5C65500D2.implementation

};

//## begin CSTStepperCreatorV0%3DA5C65500D2.postscript preserve=yes
//## end CSTStepperCreatorV0%3DA5C65500D2.postscript

// Class CSTStepperCreatorV0 

//## begin module%3DA5C60D024B.epilog preserve=yes
//## end module%3DA5C60D024B.epilog


#endif
