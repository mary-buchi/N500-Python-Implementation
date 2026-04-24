//## begin module%3DE5EC600237.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EC600237.cm

//## begin module%3DE5EC600237.cp preserve=no
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
//## end module%3DE5EC600237.cp

//## Module: EBESregy%3DE5EC600237; Package specification
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Source file: R:\Embedded\src\EBES\EBESregy.h

#ifndef EBESregy_h
#define EBESregy_h 1

//## begin module%3DE5EC600237.additionalIncludes preserve=no
//## end module%3DE5EC600237.additionalIncludes

//## begin module%3DE5EC600237.includes preserve=yes
//## end module%3DE5EC600237.includes

//## begin module%3DE5EC600237.declarations preserve=no
//## end module%3DE5EC600237.declarations

//## begin module%3DE5EC600237.additionalDeclarations preserve=yes
//## end module%3DE5EC600237.additionalDeclarations


//## begin CESInterfaceRegistry%3DEB71E90334.preface preserve=yes
//## end CESInterfaceRegistry%3DEB71E90334.preface

//## Class: CESInterfaceRegistry%3DEB71E90334
//## Category: EBES (Event Source)%3DE5E6910350
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEB725F02C6;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DEB72740314;CESEventSourceCreatorV0 { -> }

class EBES_DLL_DECL CESInterfaceRegistry 
{
  //## begin CESInterfaceRegistry%3DEB71E90334.initialDeclarations preserve=yes
  //## end CESInterfaceRegistry%3DEB71E90334.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1038837066
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CESInterfaceRegistry%3DEB71E90334.public preserve=yes
      //## end CESInterfaceRegistry%3DEB71E90334.public

  protected:
    // Additional Protected Declarations
      //## begin CESInterfaceRegistry%3DEB71E90334.protected preserve=yes
      //## end CESInterfaceRegistry%3DEB71E90334.protected

  private:
    // Additional Private Declarations
      //## begin CESInterfaceRegistry%3DEB71E90334.private preserve=yes
      //## end CESInterfaceRegistry%3DEB71E90334.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CESInterfaceRegistry%3DEB71E90334.implementation preserve=yes
      //## end CESInterfaceRegistry%3DEB71E90334.implementation

};

//## begin CESInterfaceRegistry%3DEB71E90334.postscript preserve=yes
//## end CESInterfaceRegistry%3DEB71E90334.postscript

// Class CESInterfaceRegistry 

//## begin module%3DE5EC600237.epilog preserve=yes
//## end module%3DE5EC600237.epilog


#endif
