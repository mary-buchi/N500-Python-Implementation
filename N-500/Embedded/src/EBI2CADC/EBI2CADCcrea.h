//## begin module%3F49FA5003A9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49FA5003A9.cm

//## begin module%3F49FA5003A9.cp preserve=no
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
//## end module%3F49FA5003A9.cp

//## Module: EBI2CADCcrea%3F49FA5003A9; Package specification
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCcrea.h

#ifndef EBI2CADCcrea_h
#define EBI2CADCcrea_h 1

//## begin module%3F49FA5003A9.additionalIncludes preserve=no
//## end module%3F49FA5003A9.additionalIncludes

//## begin module%3F49FA5003A9.includes preserve=yes
//## end module%3F49FA5003A9.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3F49FA5003A9.declarations preserve=no
//## end module%3F49FA5003A9.declarations

//## begin module%3F49FA5003A9.additionalDeclarations preserve=yes
//## end module%3F49FA5003A9.additionalDeclarations


//## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.preface preserve=yes
//## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.preface

//## Class: CI2CADCMAX1037CreatorV0s%3F4A070A007D
//## Category: EBI2CADC (I2C ADC)%3F49CFE2030D
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4A18BE0203;CI2CADCMAX1037 { -> }

class CI2CADCMAX1037CreatorV0s : public CPIObjCreatorI2CADCMAX1037  //## Inherits: <unnamed>%3F4A07260203
{
  //## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.initialDeclarations preserve=yes
  //## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.initialDeclarations

  public:
    //## Constructors (generated)
      CI2CADCMAX1037CreatorV0s();

    //## Destructor (generated)
      virtual ~CI2CADCMAX1037CreatorV0s();


    //## Other Operations (specified)
      //## Operation: Create%1061804156
      virtual IPII2CADCMAX1037* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.public preserve=yes
      //## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.protected preserve=yes
      //## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.protected

  private:
    //## Constructors (generated)
      CI2CADCMAX1037CreatorV0s(const CI2CADCMAX1037CreatorV0s &right);

    //## Assignment Operation (generated)
      const CI2CADCMAX1037CreatorV0s & operator=(const CI2CADCMAX1037CreatorV0s &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CADCMAX1037CreatorV0s &right) const;

      bool operator!=(const CI2CADCMAX1037CreatorV0s &right) const;

    // Additional Private Declarations
      //## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.private preserve=yes
      //## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.implementation preserve=yes
      //## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.implementation

};

//## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.postscript preserve=yes
//## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.postscript

// Class CI2CADCMAX1037CreatorV0s 

//## begin module%3F49FA5003A9.epilog preserve=yes
//## end module%3F49FA5003A9.epilog


#endif
