//## begin module%3FA1170C0242.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA1170C0242.cm

//## begin module%3FA1170C0242.cp preserve=no
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
//## end module%3FA1170C0242.cp

//## Module: EBIOstat%3FA1170C0242; Package specification
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOstat.h

#ifndef EBIOstat_h
#define EBIOstat_h 1

//## begin module%3FA1170C0242.additionalIncludes preserve=no
//## end module%3FA1170C0242.additionalIncludes

//## begin module%3FA1170C0242.includes preserve=yes
//## end module%3FA1170C0242.includes



//## begin module%3FA1170C0242.declarations preserve=no
//## end module%3FA1170C0242.declarations

//## begin module%3FA1170C0242.additionalDeclarations preserve=yes
//## end module%3FA1170C0242.additionalDeclarations


//## begin CIODigitalState%3FA115AC032C.preface preserve=yes
//## end CIODigitalState%3FA115AC032C.preface

//## Class: CIODigitalState%3FA115AC032C
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CIODigitalState 
{
  //## begin CIODigitalState%3FA115AC032C.initialDeclarations preserve=yes
  //## end CIODigitalState%3FA115AC032C.initialDeclarations

  public:
    //## Constructors (generated)
      CIODigitalState();

    //## Destructor (generated)
      virtual ~CIODigitalState();


    //## Other Operations (specified)
      //## Operation: SetState%1067518839
      static void SetState (DWORD p_dwID, bool p_bState);

      //## Operation: GetState%1067518840
      static bool GetState (DWORD p_dwID);

    // Additional Public Declarations
      //## begin CIODigitalState%3FA115AC032C.public preserve=yes
      //## end CIODigitalState%3FA115AC032C.public

  protected:
    // Additional Protected Declarations
      //## begin CIODigitalState%3FA115AC032C.protected preserve=yes
      //## end CIODigitalState%3FA115AC032C.protected

  private:
    //## Constructors (generated)
      CIODigitalState(const CIODigitalState &right);

    //## Assignment Operation (generated)
      const CIODigitalState & operator=(const CIODigitalState &right);

    //## Equality Operations (generated)
      bool operator==(const CIODigitalState &right) const;

      bool operator!=(const CIODigitalState &right) const;

    // Data Members for Associations

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3FA1175C03B9
      //## Role: CIODigitalState::Map%3FA1175D0233
      //## Constraints:
      //	ordered
      //## Qualifier: class%3FA1178C0261; DWORD
      //## begin CIODigitalState::Map%3FA1175D0233.role preserve=no  public: static bool { -> 1VFHON}
      static CMap<DWORD, DWORD&, bool, bool&> m_Map;
      //## end CIODigitalState::Map%3FA1175D0233.role

    // Additional Private Declarations
      //## begin CIODigitalState%3FA115AC032C.private preserve=yes
      //## end CIODigitalState%3FA115AC032C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIODigitalState%3FA115AC032C.implementation preserve=yes
      //## end CIODigitalState%3FA115AC032C.implementation

};

//## begin CIODigitalState%3FA115AC032C.postscript preserve=yes
//## end CIODigitalState%3FA115AC032C.postscript

// Class CIODigitalState 

//## begin module%3FA1170C0242.epilog preserve=yes
//## end module%3FA1170C0242.epilog


#endif
