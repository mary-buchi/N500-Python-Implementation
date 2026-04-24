//## begin module%3DAAD46802A4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAD46802A4.cm

//## begin module%3DAAD46802A4.cp preserve=no
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
//## end module%3DAAD46802A4.cp

//## Module: EBMCregy%3DAAD46802A4; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCregy.h

#ifndef EBMCregy_h
#define EBMCregy_h 1

//## begin module%3DAAD46802A4.additionalIncludes preserve=no
//## end module%3DAAD46802A4.additionalIncludes

//## begin module%3DAAD46802A4.includes preserve=yes
//## end module%3DAAD46802A4.includes

//## begin module%3DAAD46802A4.declarations preserve=no
//## end module%3DAAD46802A4.declarations

//## begin module%3DAAD46802A4.additionalDeclarations preserve=yes
//## end module%3DAAD46802A4.additionalDeclarations


//## begin CMCInterfaceRegistry%3DAAD43D02E2.preface preserve=yes
//## end CMCInterfaceRegistry%3DAAD43D02E2.preface

//## Class: CMCInterfaceRegistry%3DAAD43D02E2
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAD4A100BF;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DAAD4E90311;CMCMeasurementChannelCreatorV0 { -> }
//## Uses: <unnamed>%3E1D442603D8;CMCStateMachineEngine { -> }

class EBMC_DLL_DECL CMCInterfaceRegistry 
{
  //## begin CMCInterfaceRegistry%3DAAD43D02E2.initialDeclarations preserve=yes
  //## end CMCInterfaceRegistry%3DAAD43D02E2.initialDeclarations

  public:
    //## Constructors (generated)
      CMCInterfaceRegistry();

    //## Destructor (generated)
      virtual ~CMCInterfaceRegistry();


    //## Other Operations (specified)
      //## Operation: RegisterInterfaces%1034575110
      static void RegisterInterfaces ();

    // Additional Public Declarations
      //## begin CMCInterfaceRegistry%3DAAD43D02E2.public preserve=yes
      //## end CMCInterfaceRegistry%3DAAD43D02E2.public

  protected:
    // Additional Protected Declarations
      //## begin CMCInterfaceRegistry%3DAAD43D02E2.protected preserve=yes
      //## end CMCInterfaceRegistry%3DAAD43D02E2.protected

  private:
    //## Constructors (generated)
      CMCInterfaceRegistry(const CMCInterfaceRegistry &right);

    //## Assignment Operation (generated)
      const CMCInterfaceRegistry & operator=(const CMCInterfaceRegistry &right);

    //## Equality Operations (generated)
      bool operator==(const CMCInterfaceRegistry &right) const;

      bool operator!=(const CMCInterfaceRegistry &right) const;

    // Additional Private Declarations
      //## begin CMCInterfaceRegistry%3DAAD43D02E2.private preserve=yes
      //## end CMCInterfaceRegistry%3DAAD43D02E2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCInterfaceRegistry%3DAAD43D02E2.implementation preserve=yes
      //## end CMCInterfaceRegistry%3DAAD43D02E2.implementation

};

//## begin CMCInterfaceRegistry%3DAAD43D02E2.postscript preserve=yes
//## end CMCInterfaceRegistry%3DAAD43D02E2.postscript

// Class CMCInterfaceRegistry 

//## begin module%3DAAD46802A4.epilog preserve=yes
//## end module%3DAAD46802A4.epilog


#endif
