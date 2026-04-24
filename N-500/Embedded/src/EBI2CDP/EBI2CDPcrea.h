//## begin module%3F4B4EC70148.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4EC70148.cm

//## begin module%3F4B4EC70148.cp preserve=no
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
//## end module%3F4B4EC70148.cp

//## Module: EBI2CDPcrea%3F4B4EC70148; Package specification
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPcrea.h

#ifndef EBI2CDPcrea_h
#define EBI2CDPcrea_h 1

//## begin module%3F4B4EC70148.additionalIncludes preserve=no
//## end module%3F4B4EC70148.additionalIncludes

//## begin module%3F4B4EC70148.includes preserve=yes
//## end module%3F4B4EC70148.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3F4B4EC70148.declarations preserve=no
//## end module%3F4B4EC70148.declarations

//## begin module%3F4B4EC70148.additionalDeclarations preserve=yes
//## end module%3F4B4EC70148.additionalDeclarations


//## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.preface preserve=yes
//## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.preface

//## Class: CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B
//## Category: EBI2CDP (I2C Digital Potentiometer)%3F4B4CE20177
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4B649D03C8;CI2CDigitalPotiAD5245 { -> }

class CI2CDigitalPotiAD5245CreatorV0s : public CPIObjCreatorI2CDigitalPotiAD5245  //## Inherits: <unnamed>%3F4B61510271
{
  //## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.initialDeclarations preserve=yes
  //## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.initialDeclarations

  public:
    //## Constructors (generated)
      CI2CDigitalPotiAD5245CreatorV0s();

    //## Destructor (generated)
      virtual ~CI2CDigitalPotiAD5245CreatorV0s();


    //## Other Operations (specified)
      //## Operation: Create%1061902076
      virtual IPII2CDigitalPotiAD5245* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.public preserve=yes
      //## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.protected preserve=yes
      //## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.protected

  private:
    //## Constructors (generated)
      CI2CDigitalPotiAD5245CreatorV0s(const CI2CDigitalPotiAD5245CreatorV0s &right);

    //## Assignment Operation (generated)
      const CI2CDigitalPotiAD5245CreatorV0s & operator=(const CI2CDigitalPotiAD5245CreatorV0s &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CDigitalPotiAD5245CreatorV0s &right) const;

      bool operator!=(const CI2CDigitalPotiAD5245CreatorV0s &right) const;

    // Additional Private Declarations
      //## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.private preserve=yes
      //## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.implementation preserve=yes
      //## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.implementation

};

//## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.postscript preserve=yes
//## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.postscript

// Class CI2CDigitalPotiAD5245CreatorV0s 

//## begin module%3F4B4EC70148.epilog preserve=yes
//## end module%3F4B4EC70148.epilog


#endif
