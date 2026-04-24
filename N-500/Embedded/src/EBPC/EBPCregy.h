//## begin module%3EED769F036E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F036E.cm

//## begin module%3EED769F036E.cp preserve=no
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
//## end module%3EED769F036E.cp

//## Module: EBPCregy%3EED769F036E; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCregy.h

#ifndef EBPCregy_h
#define EBPCregy_h 1

//## begin module%3EED769F036E.additionalIncludes preserve=no
//## end module%3EED769F036E.additionalIncludes

//## begin module%3EED769F036E.includes preserve=yes
//## end module%3EED769F036E.includes

//## begin module%3EED769F036E.declarations preserve=no
//## end module%3EED769F036E.declarations

//## begin module%3EED769F036E.additionalDeclarations preserve=yes
//## end module%3EED769F036E.additionalDeclarations


//## begin CPCInterfaceRegistry%3EED76CC02F8.preface preserve=yes
//## end CPCInterfaceRegistry%3EED76CC02F8.preface

//## Class: CPCInterfaceRegistry%3EED76CC02F8
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC02FA;CPIObjectFactory { -> }
//## Uses: <unnamed>%3EED76CC02FD;CPCPowerControlCreatorV0 { -> }
//## Uses: <unnamed>%3EED76CC0300;CPCStateMachineEngine { -> }

class EBPC_DLL_DECL CPCInterfaceRegistry 
{
  //## begin CPCInterfaceRegistry%3EED76CC02F8.initialDeclarations preserve=yes
  //## end CPCInterfaceRegistry%3EED76CC02F8.initialDeclarations

  public:
    //## Constructors (generated)
      CPCInterfaceRegistry();

    //## Destructor (generated)
      virtual ~CPCInterfaceRegistry();


    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1038899300
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CPCInterfaceRegistry%3EED76CC02F8.public preserve=yes
      //## end CPCInterfaceRegistry%3EED76CC02F8.public

  protected:
    // Additional Protected Declarations
      //## begin CPCInterfaceRegistry%3EED76CC02F8.protected preserve=yes
      //## end CPCInterfaceRegistry%3EED76CC02F8.protected

  private:
    // Additional Private Declarations
      //## begin CPCInterfaceRegistry%3EED76CC02F8.private preserve=yes
      //## end CPCInterfaceRegistry%3EED76CC02F8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCInterfaceRegistry%3EED76CC02F8.implementation preserve=yes
      //## end CPCInterfaceRegistry%3EED76CC02F8.implementation

};

//## begin CPCInterfaceRegistry%3EED76CC02F8.postscript preserve=yes
//## end CPCInterfaceRegistry%3EED76CC02F8.postscript

// Class CPCInterfaceRegistry 

//## begin module%3EED769F036E.epilog preserve=yes
//## end module%3EED769F036E.epilog


#endif
