//## begin module%3DD0B1DF00E4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0B1DF00E4.cm

//## begin module%3DD0B1DF00E4.cp preserve=no
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
//## end module%3DD0B1DF00E4.cp

//## Module: EBWCregy%3DD0B1DF00E4; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCregy.h

#ifndef EBWCregy_h
#define EBWCregy_h 1

//## begin module%3DD0B1DF00E4.additionalIncludes preserve=no
//## end module%3DD0B1DF00E4.additionalIncludes

//## begin module%3DD0B1DF00E4.includes preserve=yes
//## end module%3DD0B1DF00E4.includes

//## begin module%3DD0B1DF00E4.declarations preserve=no
//## end module%3DD0B1DF00E4.declarations

//## begin module%3DD0B1DF00E4.additionalDeclarations preserve=yes
//## end module%3DD0B1DF00E4.additionalDeclarations


//## begin CWCInterfaceRegistry%3DD0B2E2000A.preface preserve=yes
//## end CWCInterfaceRegistry%3DD0B2E2000A.preface

//## Class: CWCInterfaceRegistry%3DD0B2E2000A
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0B38D03D2;CWCWedgeControlCreatorV0 { -> }
//## Uses: <unnamed>%3DD0B56101FE;CPIObjectFactory { -> }
//## Uses: <unnamed>%3E1D41A3009C;CWCStateMachineEngine { -> }

class EBWC_DLL_DECL CWCInterfaceRegistry 
{
  //## begin CWCInterfaceRegistry%3DD0B2E2000A.initialDeclarations preserve=yes
  //## end CWCInterfaceRegistry%3DD0B2E2000A.initialDeclarations

  public:
    //## Constructors (generated)
      CWCInterfaceRegistry();

    //## Destructor (generated)
      virtual ~CWCInterfaceRegistry();


    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1042097141
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CWCInterfaceRegistry%3DD0B2E2000A.public preserve=yes
      //## end CWCInterfaceRegistry%3DD0B2E2000A.public

  protected:
    // Additional Protected Declarations
      //## begin CWCInterfaceRegistry%3DD0B2E2000A.protected preserve=yes
      //## end CWCInterfaceRegistry%3DD0B2E2000A.protected

  private:
    // Additional Private Declarations
      //## begin CWCInterfaceRegistry%3DD0B2E2000A.private preserve=yes
      //## end CWCInterfaceRegistry%3DD0B2E2000A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCInterfaceRegistry%3DD0B2E2000A.implementation preserve=yes
      //## end CWCInterfaceRegistry%3DD0B2E2000A.implementation

};

//## begin CWCInterfaceRegistry%3DD0B2E2000A.postscript preserve=yes
//## end CWCInterfaceRegistry%3DD0B2E2000A.postscript

// Class CWCInterfaceRegistry 

//## begin module%3DD0B1DF00E4.epilog preserve=yes
//## end module%3DD0B1DF00E4.epilog


#endif
