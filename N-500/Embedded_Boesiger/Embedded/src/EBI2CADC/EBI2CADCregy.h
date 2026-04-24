//## begin module%3F49FA0C007D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49FA0C007D.cm

//## begin module%3F49FA0C007D.cp preserve=no
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
//## end module%3F49FA0C007D.cp

//## Module: EBI2CADCregy%3F49FA0C007D; Package specification
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCregy.h

#ifndef EBI2CADCregy_h
#define EBI2CADCregy_h 1

//## begin module%3F49FA0C007D.additionalIncludes preserve=no
//## end module%3F49FA0C007D.additionalIncludes

//## begin module%3F49FA0C007D.includes preserve=yes
//## end module%3F49FA0C007D.includes

//## begin module%3F49FA0C007D.declarations preserve=no
//## end module%3F49FA0C007D.declarations

//## begin module%3F49FA0C007D.additionalDeclarations preserve=yes
//## end module%3F49FA0C007D.additionalDeclarations


//## begin CI2CADCInterfaceRegistry%3F4A1046035B.preface preserve=yes
//## end CI2CADCInterfaceRegistry%3F4A1046035B.preface

//## Class: CI2CADCInterfaceRegistry%3F4A1046035B
//## Category: EBI2CADC (I2C ADC)%3F49CFE2030D
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4A18B0009C;CI2CADCMAX1037CreatorV0s { -> }
//## Uses: <unnamed>%3F4A1BD00177;CPIObjectFactory { -> }

class EBI2CADC_DLL_DECL CI2CADCInterfaceRegistry 
{
  //## begin CI2CADCInterfaceRegistry%3F4A1046035B.initialDeclarations preserve=yes
  //## end CI2CADCInterfaceRegistry%3F4A1046035B.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1061804157
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CI2CADCInterfaceRegistry%3F4A1046035B.public preserve=yes
      //## end CI2CADCInterfaceRegistry%3F4A1046035B.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CADCInterfaceRegistry%3F4A1046035B.protected preserve=yes
      //## end CI2CADCInterfaceRegistry%3F4A1046035B.protected

  private:
    // Additional Private Declarations
      //## begin CI2CADCInterfaceRegistry%3F4A1046035B.private preserve=yes
      //## end CI2CADCInterfaceRegistry%3F4A1046035B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CADCInterfaceRegistry%3F4A1046035B.implementation preserve=yes
      //## end CI2CADCInterfaceRegistry%3F4A1046035B.implementation

};

//## begin CI2CADCInterfaceRegistry%3F4A1046035B.postscript preserve=yes
//## end CI2CADCInterfaceRegistry%3F4A1046035B.postscript

// Class CI2CADCInterfaceRegistry 

//## begin module%3F49FA0C007D.epilog preserve=yes
//## end module%3F49FA0C007D.epilog


#endif
