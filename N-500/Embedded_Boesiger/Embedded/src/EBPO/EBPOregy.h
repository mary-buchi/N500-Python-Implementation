//## begin module%3DE5EAF401BA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EAF401BA.cm

//## begin module%3DE5EAF401BA.cp preserve=no
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
//## end module%3DE5EAF401BA.cp

//## Module: EBPOregy%3DE5EAF401BA; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOregy.h

#ifndef EBPOregy_h
#define EBPOregy_h 1

//## begin module%3DE5EAF401BA.additionalIncludes preserve=no
//## end module%3DE5EAF401BA.additionalIncludes

//## begin module%3DE5EAF401BA.includes preserve=yes
//## end module%3DE5EAF401BA.includes

//## begin module%3DE5EAF401BA.declarations preserve=no
//## end module%3DE5EAF401BA.declarations

//## begin module%3DE5EAF401BA.additionalDeclarations preserve=yes
//## end module%3DE5EAF401BA.additionalDeclarations


//## begin CPOInterfaceRegistry%3DE63D080014.preface preserve=yes
//## end CPOInterfaceRegistry%3DE63D080014.preface

//## Class: CPOInterfaceRegistry%3DE63D080014
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE63DB00266;CPOPersistentObjCreatorV0 { -> }
//## Uses: <unnamed>%3DE63DC50091;CPIObjectFactory { -> }
//## Uses: <unnamed>%3E1D4641034B;CPOStateMachineEngine { -> }

class EBPO_DLL_DECL CPOInterfaceRegistry 
{
  //## begin CPOInterfaceRegistry%3DE63D080014.initialDeclarations preserve=yes
  //## end CPOInterfaceRegistry%3DE63D080014.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1037094236
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CPOInterfaceRegistry%3DE63D080014.public preserve=yes
      //## end CPOInterfaceRegistry%3DE63D080014.public

  protected:
    // Additional Protected Declarations
      //## begin CPOInterfaceRegistry%3DE63D080014.protected preserve=yes
      //## end CPOInterfaceRegistry%3DE63D080014.protected

  private:
    // Additional Private Declarations
      //## begin CPOInterfaceRegistry%3DE63D080014.private preserve=yes
      //## end CPOInterfaceRegistry%3DE63D080014.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOInterfaceRegistry%3DE63D080014.implementation preserve=yes
      //## end CPOInterfaceRegistry%3DE63D080014.implementation

};

//## begin CPOInterfaceRegistry%3DE63D080014.postscript preserve=yes
//## end CPOInterfaceRegistry%3DE63D080014.postscript

// Class CPOInterfaceRegistry 

//## begin module%3DE5EAF401BA.epilog preserve=yes
//## end module%3DE5EAF401BA.epilog


#endif
