//## begin module%3FDD88D302BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD88D302BF.cm

//## begin module%3FDD88D302BF.cp preserve=no
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
//## end module%3FDD88D302BF.cp

//## Module: EBI2CEPROMcrea%3FDD88D302BF; Package specification
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMcrea.h

#ifndef EBI2CEPROMcrea_h
#define EBI2CEPROMcrea_h 1

//## begin module%3FDD88D302BF.additionalIncludes preserve=no
//## end module%3FDD88D302BF.additionalIncludes

//## begin module%3FDD88D302BF.includes preserve=yes
//## end module%3FDD88D302BF.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3FDD88D302BF.declarations preserve=no
//## end module%3FDD88D302BF.declarations

//## begin module%3FDD88D302BF.additionalDeclarations preserve=yes
//## end module%3FDD88D302BF.additionalDeclarations


//## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.preface preserve=yes
//## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.preface

//## Class: CI2CEprom24LC515CreatorV0s%3FDD8BA2002E
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FDD8C8003D8;CI2CEprom24LC515 { -> }

class CI2CEprom24LC515CreatorV0s : public CPIObjCreatorI2CEprom24LC515  //## Inherits: <unnamed>%3FDD8BC3038A
{
  //## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.initialDeclarations preserve=yes
  //## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.initialDeclarations

  public:
    //## Constructors (generated)
      CI2CEprom24LC515CreatorV0s();

    //## Destructor (generated)
      virtual ~CI2CEprom24LC515CreatorV0s();


    //## Other Operations (specified)
      //## Operation: Create%1071483521
      virtual IPII2CEprom24LC515* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.public preserve=yes
      //## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.protected preserve=yes
      //## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.protected

  private:
    //## Constructors (generated)
      CI2CEprom24LC515CreatorV0s(const CI2CEprom24LC515CreatorV0s &right);

    //## Assignment Operation (generated)
      const CI2CEprom24LC515CreatorV0s & operator=(const CI2CEprom24LC515CreatorV0s &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CEprom24LC515CreatorV0s &right) const;

      bool operator!=(const CI2CEprom24LC515CreatorV0s &right) const;

    // Additional Private Declarations
      //## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.private preserve=yes
      //## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.implementation preserve=yes
      //## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.implementation

};

//## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.postscript preserve=yes
//## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.postscript

// Class CI2CEprom24LC515CreatorV0s 

//## begin module%3FDD88D302BF.epilog preserve=yes
//## end module%3FDD88D302BF.epilog


#endif
