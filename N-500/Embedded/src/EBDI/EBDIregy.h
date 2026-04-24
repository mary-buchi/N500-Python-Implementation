//## begin module%3E1981010337.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E1981010337.cm

//## begin module%3E1981010337.cp preserve=no
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
//## end module%3E1981010337.cp

//## Module: EBDIregy%3E1981010337; Package specification
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDIregy.h

#ifndef EBDIregy_h
#define EBDIregy_h 1

//## begin module%3E1981010337.additionalIncludes preserve=no
//## end module%3E1981010337.additionalIncludes

//## begin module%3E1981010337.includes preserve=yes
//## end module%3E1981010337.includes

//## begin module%3E1981010337.declarations preserve=no
//## end module%3E1981010337.declarations

//## begin module%3E1981010337.additionalDeclarations preserve=yes
//## end module%3E1981010337.additionalDeclarations


//## begin CDIInterfaceRegistry%3E198BCC0143.preface preserve=yes
//## end CDIInterfaceRegistry%3E198BCC0143.preface

//## Class: CDIInterfaceRegistry%3E198BCC0143
//## Category: EBDI (Diagnostics)%3E197C790124
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E198C330162;CDIDiagnosticCreatorV0 { -> }
//## Uses: <unnamed>%3E198C5601A1;CPIObjectFactory { -> }

class EBDI_DLL_DECL CDIInterfaceRegistry 
{
  //## begin CDIInterfaceRegistry%3E198BCC0143.initialDeclarations preserve=yes
  //## end CDIInterfaceRegistry%3E198BCC0143.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1041861674
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CDIInterfaceRegistry%3E198BCC0143.public preserve=yes
      //## end CDIInterfaceRegistry%3E198BCC0143.public

  protected:
    // Additional Protected Declarations
      //## begin CDIInterfaceRegistry%3E198BCC0143.protected preserve=yes
      //## end CDIInterfaceRegistry%3E198BCC0143.protected

  private:
    // Additional Private Declarations
      //## begin CDIInterfaceRegistry%3E198BCC0143.private preserve=yes
      //## end CDIInterfaceRegistry%3E198BCC0143.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CDIInterfaceRegistry%3E198BCC0143.implementation preserve=yes
      //## end CDIInterfaceRegistry%3E198BCC0143.implementation

};

//## begin CDIInterfaceRegistry%3E198BCC0143.postscript preserve=yes
//## end CDIInterfaceRegistry%3E198BCC0143.postscript

// Class CDIInterfaceRegistry 

//## begin module%3E1981010337.epilog preserve=yes
//## end module%3E1981010337.epilog


#endif
