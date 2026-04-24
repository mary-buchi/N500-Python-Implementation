//## begin module%3FDD88F2004E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD88F2004E.cm

//## begin module%3FDD88F2004E.cp preserve=no
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
//## end module%3FDD88F2004E.cp

//## Module: EBI2CEPROMregy%3FDD88F2004E; Package specification
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMregy.h

#ifndef EBI2CEPROMregy_h
#define EBI2CEPROMregy_h 1

//## begin module%3FDD88F2004E.additionalIncludes preserve=no
//## end module%3FDD88F2004E.additionalIncludes

//## begin module%3FDD88F2004E.includes preserve=yes
//## end module%3FDD88F2004E.includes

//## begin module%3FDD88F2004E.declarations preserve=no
//## end module%3FDD88F2004E.declarations

//## begin module%3FDD88F2004E.additionalDeclarations preserve=yes
//## end module%3FDD88F2004E.additionalDeclarations


//## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.preface preserve=yes
//## end CI2CEpromInterfaceRegistry%3FDD8A11038A.preface

//## Class: CI2CEpromInterfaceRegistry%3FDD8A11038A
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FDD8C870261;CI2CEprom24LC515CreatorV0s { -> }
//## Uses: <unnamed>%3FDD8DEC031C;CPIObjectFactory { -> }

class EBI2CEPROM_DLL_DECL CI2CEpromInterfaceRegistry 
{
  //## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.initialDeclarations preserve=yes
  //## end CI2CEpromInterfaceRegistry%3FDD8A11038A.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1071483520
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.public preserve=yes
      //## end CI2CEpromInterfaceRegistry%3FDD8A11038A.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.protected preserve=yes
      //## end CI2CEpromInterfaceRegistry%3FDD8A11038A.protected

  private:
    // Additional Private Declarations
      //## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.private preserve=yes
      //## end CI2CEpromInterfaceRegistry%3FDD8A11038A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.implementation preserve=yes
      //## end CI2CEpromInterfaceRegistry%3FDD8A11038A.implementation

};

//## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.postscript preserve=yes
//## end CI2CEpromInterfaceRegistry%3FDD8A11038A.postscript

// Class CI2CEpromInterfaceRegistry 

//## begin module%3FDD88F2004E.epilog preserve=yes
//## end module%3FDD88F2004E.epilog


#endif
