//## begin module%3DF5AF9E01B5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF5AF9E01B5.cm

//## begin module%3DF5AF9E01B5.cp preserve=no
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
//## end module%3DF5AF9E01B5.cp

//## Module: EBIOregy%3DF5AF9E01B5; Package specification
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOregy.h

#ifndef EBIOregy_h
#define EBIOregy_h 1

//## begin module%3DF5AF9E01B5.additionalIncludes preserve=no
//## end module%3DF5AF9E01B5.additionalIncludes

//## begin module%3DF5AF9E01B5.includes preserve=yes
//## end module%3DF5AF9E01B5.includes

//## begin module%3DF5AF9E01B5.declarations preserve=no
//## end module%3DF5AF9E01B5.declarations

//## begin module%3DF5AF9E01B5.additionalDeclarations preserve=yes
//## end module%3DF5AF9E01B5.additionalDeclarations


//## begin CIOInterfaceRegistry%3DF5B9C201B5.preface preserve=yes
//## end CIOInterfaceRegistry%3DF5B9C201B5.preface

//## Class: CIOInterfaceRegistry%3DF5B9C201B5
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5BA85038A;CIOOutputAnalogCreatorV0 { -> }
//## Uses: <unnamed>%3DF5BC5E0109;CIOSensorAnalogCreatorV0 { -> }
//## Uses: <unnamed>%3DF5BC6101C5;CIOOutputDigitalCreatorV0 { -> }
//## Uses: <unnamed>%3DF5BC640223;CIOSensorDigitalCreatorV0 { -> }
//## Uses: <unnamed>%3DF5FF5C0129;CPIObjectFactory { -> }

class EBIO_DLL_DECL CIOInterfaceRegistry 
{
  //## begin CIOInterfaceRegistry%3DF5B9C201B5.initialDeclarations preserve=yes
  //## end CIOInterfaceRegistry%3DF5B9C201B5.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1039513439
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CIOInterfaceRegistry%3DF5B9C201B5.public preserve=yes
      //## end CIOInterfaceRegistry%3DF5B9C201B5.public

  protected:
    // Additional Protected Declarations
      //## begin CIOInterfaceRegistry%3DF5B9C201B5.protected preserve=yes
      //## end CIOInterfaceRegistry%3DF5B9C201B5.protected

  private:
    // Additional Private Declarations
      //## begin CIOInterfaceRegistry%3DF5B9C201B5.private preserve=yes
      //## end CIOInterfaceRegistry%3DF5B9C201B5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOInterfaceRegistry%3DF5B9C201B5.implementation preserve=yes
      //## end CIOInterfaceRegistry%3DF5B9C201B5.implementation

};

//## begin CIOInterfaceRegistry%3DF5B9C201B5.postscript preserve=yes
//## end CIOInterfaceRegistry%3DF5B9C201B5.postscript

// Class CIOInterfaceRegistry 

//## begin module%3DF5AF9E01B5.epilog preserve=yes
//## end module%3DF5AF9E01B5.epilog


#endif
