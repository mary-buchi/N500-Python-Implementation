//## begin module%40223A3B0278.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40223A3B0278.cm

//## begin module%40223A3B0278.cp preserve=no
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
//## end module%40223A3B0278.cp

//## Module: EBPItias%40223A3B0278; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPItias.h

#ifndef EBPItias_h
#define EBPItias_h 1

//## begin module%40223A3B0278.additionalIncludes preserve=no
//## end module%40223A3B0278.additionalIncludes

//## begin module%40223A3B0278.includes preserve=yes
//## end module%40223A3B0278.includes

// EBPIenum
#include "EBPIenum.h"


//## begin module%40223A3B0278.declarations preserve=no
//## end module%40223A3B0278.declarations

//## begin module%40223A3B0278.additionalDeclarations preserve=yes
//## end module%40223A3B0278.additionalDeclarations


//## begin CPITicksAtStart%4022387001AD.preface preserve=yes
//## end CPITicksAtStart%4022387001AD.preface

//## Class: CPITicksAtStart%4022387001AD
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPITicksAtStart 
{
  //## begin CPITicksAtStart%4022387001AD.initialDeclarations preserve=yes
  //## end CPITicksAtStart%4022387001AD.initialDeclarations

  public:
    //## Constructors (generated)
      CPITicksAtStart();

    //## Destructor (generated)
      virtual ~CPITicksAtStart();

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%40223D500363
      //## Role: CPITicksAtStart::dwTicksAtStartUp%40223D5100D3
      //## begin CPITicksAtStart::dwTicksAtStartUp%40223D5100D3.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwTicksAtStartUp;
      //## end CPITicksAtStart::dwTicksAtStartUp%40223D5100D3.role

      //## Association: EBPI (PC Interface)::<unnamed>%40238F7A0202
      //## Role: CPITicksAtStart::eLamp%40238F7B0222
      //## begin CPITicksAtStart::eLamp%40238F7B0222.role preserve=no  public: static EPILamp {1..1 -> 1..1VHN}
      static EPILamp m_eLamp;
      //## end CPITicksAtStart::eLamp%40238F7B0222.role

    // Additional Public Declarations
      //## begin CPITicksAtStart%4022387001AD.public preserve=yes
      //## end CPITicksAtStart%4022387001AD.public

  protected:
    // Additional Protected Declarations
      //## begin CPITicksAtStart%4022387001AD.protected preserve=yes
      //## end CPITicksAtStart%4022387001AD.protected

  private:
    //## Constructors (generated)
      CPITicksAtStart(const CPITicksAtStart &right);

    //## Assignment Operation (generated)
      const CPITicksAtStart & operator=(const CPITicksAtStart &right);

    //## Equality Operations (generated)
      bool operator==(const CPITicksAtStart &right) const;

      bool operator!=(const CPITicksAtStart &right) const;

    // Additional Private Declarations
      //## begin CPITicksAtStart%4022387001AD.private preserve=yes
      //## end CPITicksAtStart%4022387001AD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPITicksAtStart%4022387001AD.implementation preserve=yes
      //## end CPITicksAtStart%4022387001AD.implementation

};

//## begin CPITicksAtStart%4022387001AD.postscript preserve=yes
//## end CPITicksAtStart%4022387001AD.postscript

// Class CPITicksAtStart 

//## begin module%40223A3B0278.epilog preserve=yes
//## end module%40223A3B0278.epilog


#endif
