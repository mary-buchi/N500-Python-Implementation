//## begin module%3F02C88B016C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F02C88B016C.cm

//## begin module%3F02C88B016C.cp preserve=no
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
//## end module%3F02C88B016C.cp

//## Module: EBI2CTEMPregy%3F02C88B016C; Package specification
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPregy.h

#ifndef EBI2CTEMPregy_h
#define EBI2CTEMPregy_h 1

//## begin module%3F02C88B016C.additionalIncludes preserve=no
//## end module%3F02C88B016C.additionalIncludes

//## begin module%3F02C88B016C.includes preserve=yes
//## end module%3F02C88B016C.includes

//## begin module%3F02C88B016C.declarations preserve=no
//## end module%3F02C88B016C.declarations

//## begin module%3F02C88B016C.additionalDeclarations preserve=yes
//## end module%3F02C88B016C.additionalDeclarations


//## begin CI2CTempInterfaceRegistry%3F02C7C900D7.preface preserve=yes
//## end CI2CTempInterfaceRegistry%3F02C7C900D7.preface

//## Class: CI2CTempInterfaceRegistry%3F02C7C900D7
//## Category: EBI2CTemp (I2C Temperature Device)%3EE73654004E
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F02C7C900D8;CPIObjectFactory { -> }
//## Uses: <unnamed>%3F02C7E4031A;CI2CTempSensorDS1631ZCreatorV0s { -> }

class EBI2CTEMP_DLL_DECL CI2CTempInterfaceRegistry 
{
  //## begin CI2CTempInterfaceRegistry%3F02C7C900D7.initialDeclarations preserve=yes
  //## end CI2CTempInterfaceRegistry%3F02C7C900D7.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1057146733
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CI2CTempInterfaceRegistry%3F02C7C900D7.public preserve=yes
      //## end CI2CTempInterfaceRegistry%3F02C7C900D7.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CTempInterfaceRegistry%3F02C7C900D7.protected preserve=yes
      //## end CI2CTempInterfaceRegistry%3F02C7C900D7.protected

  private:
    // Additional Private Declarations
      //## begin CI2CTempInterfaceRegistry%3F02C7C900D7.private preserve=yes
      //## end CI2CTempInterfaceRegistry%3F02C7C900D7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CTempInterfaceRegistry%3F02C7C900D7.implementation preserve=yes
      //## end CI2CTempInterfaceRegistry%3F02C7C900D7.implementation

};

//## begin CI2CTempInterfaceRegistry%3F02C7C900D7.postscript preserve=yes
//## end CI2CTempInterfaceRegistry%3F02C7C900D7.postscript

// Class CI2CTempInterfaceRegistry 

//## begin module%3F02C88B016C.epilog preserve=yes
//## end module%3F02C88B016C.epilog


#endif
