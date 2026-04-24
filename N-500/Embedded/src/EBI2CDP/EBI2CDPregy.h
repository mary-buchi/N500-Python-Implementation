//## begin module%3F4B4EB6003E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4EB6003E.cm

//## begin module%3F4B4EB6003E.cp preserve=no
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
//## end module%3F4B4EB6003E.cp

//## Module: EBI2CDPregy%3F4B4EB6003E; Package specification
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPregy.h

#ifndef EBI2CDPregy_h
#define EBI2CDPregy_h 1

//## begin module%3F4B4EB6003E.additionalIncludes preserve=no
//## end module%3F4B4EB6003E.additionalIncludes

//## begin module%3F4B4EB6003E.includes preserve=yes
//## end module%3F4B4EB6003E.includes

//## begin module%3F4B4EB6003E.declarations preserve=no
//## end module%3F4B4EB6003E.declarations

//## begin module%3F4B4EB6003E.additionalDeclarations preserve=yes
//## end module%3F4B4EB6003E.additionalDeclarations


//## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.preface preserve=yes
//## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.preface

//## Class: CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D
//## Category: EBI2CDP (I2C Digital Potentiometer)%3F4B4CE20177
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4B62220261;CI2CDigitalPotiAD5245CreatorV0s { -> }
//## Uses: <unnamed>%3F4B6482036B;CPIObjectFactory { -> }

class EBI2CDP_DLL_DECL CI2CDigitalPotiInterfaceRegistry 
{
  //## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.initialDeclarations preserve=yes
  //## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1061902075
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.public preserve=yes
      //## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.protected preserve=yes
      //## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.protected

  private:
    // Additional Private Declarations
      //## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.private preserve=yes
      //## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.implementation preserve=yes
      //## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.implementation

};

//## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.postscript preserve=yes
//## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.postscript

// Class CI2CDigitalPotiInterfaceRegistry 

//## begin module%3F4B4EB6003E.epilog preserve=yes
//## end module%3F4B4EB6003E.epilog


#endif
