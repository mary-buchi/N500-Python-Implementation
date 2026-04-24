//## begin module%3DE5EDFE0331.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDFE0331.cm

//## begin module%3DE5EDFE0331.cp preserve=no
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
//## end module%3DE5EDFE0331.cp

//## Module: EBTCregy%3DE5EDFE0331; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCregy.h

#ifndef EBTCregy_h
#define EBTCregy_h 1

//## begin module%3DE5EDFE0331.additionalIncludes preserve=no
//## end module%3DE5EDFE0331.additionalIncludes

//## begin module%3DE5EDFE0331.includes preserve=yes
//## end module%3DE5EDFE0331.includes

//## begin module%3DE5EDFE0331.declarations preserve=no
//## end module%3DE5EDFE0331.declarations

//## begin module%3DE5EDFE0331.additionalDeclarations preserve=yes
//## end module%3DE5EDFE0331.additionalDeclarations


//## begin CTCInterfaceRegistry%3DEC56B201F4.preface preserve=yes
//## end CTCInterfaceRegistry%3DEC56B201F4.preface

//## Class: CTCInterfaceRegistry%3DEC56B201F4
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEC56D602CF;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DEC56DB0290;CTCTemperatureControlCreatorV0 { -> }
//## Uses: <unnamed>%3E1D474C01F3;CTCStateMachineEngine { -> }

class EBTC_DLL_DECL CTCInterfaceRegistry 
{
  //## begin CTCInterfaceRegistry%3DEC56B201F4.initialDeclarations preserve=yes
  //## end CTCInterfaceRegistry%3DEC56B201F4.initialDeclarations

  public:
    //## Constructors (generated)
      CTCInterfaceRegistry();

    //## Destructor (generated)
      virtual ~CTCInterfaceRegistry();


    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1038899300
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CTCInterfaceRegistry%3DEC56B201F4.public preserve=yes
      //## end CTCInterfaceRegistry%3DEC56B201F4.public

  protected:
    // Additional Protected Declarations
      //## begin CTCInterfaceRegistry%3DEC56B201F4.protected preserve=yes
      //## end CTCInterfaceRegistry%3DEC56B201F4.protected

  private:
    // Additional Private Declarations
      //## begin CTCInterfaceRegistry%3DEC56B201F4.private preserve=yes
      //## end CTCInterfaceRegistry%3DEC56B201F4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCInterfaceRegistry%3DEC56B201F4.implementation preserve=yes
      //## end CTCInterfaceRegistry%3DEC56B201F4.implementation

};

//## begin CTCInterfaceRegistry%3DEC56B201F4.postscript preserve=yes
//## end CTCInterfaceRegistry%3DEC56B201F4.postscript

// Class CTCInterfaceRegistry 

//## begin module%3DE5EDFE0331.epilog preserve=yes
//## end module%3DE5EDFE0331.epilog


#endif
