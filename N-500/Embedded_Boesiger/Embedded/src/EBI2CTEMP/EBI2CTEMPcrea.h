//## begin module%3F02C6AE0166.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F02C6AE0166.cm

//## begin module%3F02C6AE0166.cp preserve=no
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
//## end module%3F02C6AE0166.cp

//## Module: EBI2CTEMPcrea%3F02C6AE0166; Package specification
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPcrea.h

#ifndef EBI2CTEMPcrea_h
#define EBI2CTEMPcrea_h 1

//## begin module%3F02C6AE0166.additionalIncludes preserve=no
//## end module%3F02C6AE0166.additionalIncludes

//## begin module%3F02C6AE0166.includes preserve=yes
//## end module%3F02C6AE0166.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3F02C6AE0166.declarations preserve=no
//## end module%3F02C6AE0166.declarations

//## begin module%3F02C6AE0166.additionalDeclarations preserve=yes
//## end module%3F02C6AE0166.additionalDeclarations


//## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.preface preserve=yes
//## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.preface

//## Class: CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135
//## Category: EBI2CTemp (I2C Temperature Device)%3EE73654004E
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F02C843035D;CI2CTempSensorDS1631Z { -> }

class CI2CTempSensorDS1631ZCreatorV0s : public CPIObjCreatorI2CSensorDS1631Z  //## Inherits: <unnamed>%3F02C5DA00EF
{
  //## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.initialDeclarations preserve=yes
  //## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.initialDeclarations

  public:
    //## Constructors (generated)
      CI2CTempSensorDS1631ZCreatorV0s();

    //## Destructor (generated)
      virtual ~CI2CTempSensorDS1631ZCreatorV0s();


    //## Other Operations (specified)
      //## Operation: Create%1057146616
      virtual IPII2CTempSensorDS1631Z* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.public preserve=yes
      //## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.protected preserve=yes
      //## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.protected

  private:
    //## Constructors (generated)
      CI2CTempSensorDS1631ZCreatorV0s(const CI2CTempSensorDS1631ZCreatorV0s &right);

    //## Assignment Operation (generated)
      const CI2CTempSensorDS1631ZCreatorV0s & operator=(const CI2CTempSensorDS1631ZCreatorV0s &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CTempSensorDS1631ZCreatorV0s &right) const;

      bool operator!=(const CI2CTempSensorDS1631ZCreatorV0s &right) const;

    // Additional Private Declarations
      //## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.private preserve=yes
      //## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.implementation preserve=yes
      //## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.implementation

};

//## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.postscript preserve=yes
//## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.postscript

// Class CI2CTempSensorDS1631ZCreatorV0s 

//## begin module%3F02C6AE0166.epilog preserve=yes
//## end module%3F02C6AE0166.epilog


#endif
