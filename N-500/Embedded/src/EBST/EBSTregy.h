//## begin module%3DA5C915023D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5C915023D.cm

//## begin module%3DA5C915023D.cp preserve=no
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
//## end module%3DA5C915023D.cp

//## Module: EBSTregy%3DA5C915023D; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTregy.h

#ifndef EBSTregy_h
#define EBSTregy_h 1

//## begin module%3DA5C915023D.additionalIncludes preserve=no
//## end module%3DA5C915023D.additionalIncludes

//## begin module%3DA5C915023D.includes preserve=yes
//## end module%3DA5C915023D.includes

//## begin module%3DA5C915023D.declarations preserve=no
//## end module%3DA5C915023D.declarations

//## begin module%3DA5C915023D.additionalDeclarations preserve=yes
//## end module%3DA5C915023D.additionalDeclarations


//## begin CSTInterfaceRegistry%3DA5C93A018C.preface preserve=yes
//## end CSTInterfaceRegistry%3DA5C93A018C.preface

//## Class: CSTInterfaceRegistry%3DA5C93A018C
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA5C9740257;CSTStepperCreatorV0 { -> }
//## Uses: <unnamed>%3DA5C98E0128;CPIObjectFactory { -> }
//## Uses: <unnamed>%3E1D46D9032C;CSTStateMachineEngine { -> }

class EBST_DLL_DECL CSTInterfaceRegistry 
{
  //## begin CSTInterfaceRegistry%3DA5C93A018C.initialDeclarations preserve=yes
  //## end CSTInterfaceRegistry%3DA5C93A018C.initialDeclarations

  public:
    //## Constructors (generated)
      CSTInterfaceRegistry();

    //## Destructor (generated)
      virtual ~CSTInterfaceRegistry();


    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1034272543
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CSTInterfaceRegistry%3DA5C93A018C.public preserve=yes
      //## end CSTInterfaceRegistry%3DA5C93A018C.public

  protected:
    // Additional Protected Declarations
      //## begin CSTInterfaceRegistry%3DA5C93A018C.protected preserve=yes
      //## end CSTInterfaceRegistry%3DA5C93A018C.protected

  private:
    // Additional Private Declarations
      //## begin CSTInterfaceRegistry%3DA5C93A018C.private preserve=yes
      //## end CSTInterfaceRegistry%3DA5C93A018C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTInterfaceRegistry%3DA5C93A018C.implementation preserve=yes
      //## end CSTInterfaceRegistry%3DA5C93A018C.implementation

};

//## begin CSTInterfaceRegistry%3DA5C93A018C.postscript preserve=yes
//## end CSTInterfaceRegistry%3DA5C93A018C.postscript

// Class CSTInterfaceRegistry 

//## begin module%3DA5C915023D.epilog preserve=yes
//## end module%3DA5C915023D.epilog


#endif
