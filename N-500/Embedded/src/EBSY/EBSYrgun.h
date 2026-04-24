//## begin module%3EE0871B0298.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE0871B0298.cm

//## begin module%3EE0871B0298.cp preserve=no
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
//## end module%3EE0871B0298.cp

//## Module: EBSYrgun%3EE0871B0298; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYrgun.h

#ifndef EBSYrgun_h
#define EBSYrgun_h 1

//## begin module%3EE0871B0298.additionalIncludes preserve=no
//## end module%3EE0871B0298.additionalIncludes

//## begin module%3EE0871B0298.includes preserve=yes
//## end module%3EE0871B0298.includes

// EBSYcons
#include "EBSYcons.h"
//## begin module%3EE0871B0298.declarations preserve=no
//## end module%3EE0871B0298.declarations

//## begin module%3EE0871B0298.additionalDeclarations preserve=yes
//## end module%3EE0871B0298.additionalDeclarations


//## begin CSYStateConstitutionRegisteringUnits%3EE080010278.preface preserve=yes
//## end CSYStateConstitutionRegisteringUnits%3EE080010278.preface

//## Class: CSYStateConstitutionRegisteringUnits%3EE080010278
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EEDD3C20362;CSYStateProcessIdle { -> }
//## Uses: <unnamed>%3EF70499039C;CSYModuleHandling { -> }

class CSYStateConstitutionRegisteringUnits : public CSYStateConstitution  //## Inherits: <unnamed>%400563C302BF
{
  //## begin CSYStateConstitutionRegisteringUnits%3EE080010278.initialDeclarations preserve=yes
  //## end CSYStateConstitutionRegisteringUnits%3EE080010278.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionRegisteringUnits();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionRegisteringUnits();


    //## Other Operations (specified)
      //## Operation: Create%1054888635
      static void Create ();

      //## Operation: Delete%1054888637
      static void Delete ();

      //## Operation: GetInstance%1054888636
      static CSYStateConstitutionRegisteringUnits* GetInstance ();

      //## Operation: GetDeviceState%1056436748
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: Do%1055753504
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSYStateConstitutionRegisteringUnits%3EE080010278.public preserve=yes
      //## end CSYStateConstitutionRegisteringUnits%3EE080010278.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionRegisteringUnits%3EE080010278.protected preserve=yes
      //## end CSYStateConstitutionRegisteringUnits%3EE080010278.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionRegisteringUnits(const CSYStateConstitutionRegisteringUnits &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionRegisteringUnits & operator=(const CSYStateConstitutionRegisteringUnits &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionRegisteringUnits &right) const;

      bool operator!=(const CSYStateConstitutionRegisteringUnits &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EE08001027D
      //## Role: CSYStateConstitutionRegisteringUnits::pInstance%3EE08001027F
      //## begin CSYStateConstitutionRegisteringUnits::pInstance%3EE08001027F.role preserve=no  public: static CSYStateConstitutionRegisteringUnits {1..1 -> RFHN}
      static CSYStateConstitutionRegisteringUnits *m_pInstance;
      //## end CSYStateConstitutionRegisteringUnits::pInstance%3EE08001027F.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionRegisteringUnits%3EE080010278.private preserve=yes
      //## end CSYStateConstitutionRegisteringUnits%3EE080010278.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionRegisteringUnits%3EE080010278.implementation preserve=yes
      //## end CSYStateConstitutionRegisteringUnits%3EE080010278.implementation

};

//## begin CSYStateConstitutionRegisteringUnits%3EE080010278.postscript preserve=yes
//## end CSYStateConstitutionRegisteringUnits%3EE080010278.postscript

//## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.preface preserve=yes
//## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.preface

//## Class: CSYStateConstitutionUnregisteringUnits%4523B00F0292
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4523BB9B024C;CPIObjectFactory { -> }

class CSYStateConstitutionUnregisteringUnits : public CSYStateConstitution  //## Inherits: <unnamed>%4523B0A6011C
{
  //## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.initialDeclarations preserve=yes
  //## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionUnregisteringUnits();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionUnregisteringUnits();


    //## Other Operations (specified)
      //## Operation: Create%1159966954
      static void Create ();

      //## Operation: Delete%1159966955
      static void Delete ();

      //## Operation: GetInstance%1159966956
      static CSYStateConstitutionUnregisteringUnits* GetInstance ();

      //## Operation: Do%1159966957
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.public preserve=yes
      //## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.protected preserve=yes
      //## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionUnregisteringUnits(const CSYStateConstitutionUnregisteringUnits &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionUnregisteringUnits & operator=(const CSYStateConstitutionUnregisteringUnits &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionUnregisteringUnits &right) const;

      bool operator!=(const CSYStateConstitutionUnregisteringUnits &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%4523B07903D4
      //## Role: CSYStateConstitutionUnregisteringUnits::pInstance%4523B07B0125
      //## begin CSYStateConstitutionUnregisteringUnits::pInstance%4523B07B0125.role preserve=no  public: static CSYStateConstitutionUnregisteringUnits {1..1 -> RFHN}
      static CSYStateConstitutionUnregisteringUnits *m_pInstance;
      //## end CSYStateConstitutionUnregisteringUnits::pInstance%4523B07B0125.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.private preserve=yes
      //## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.implementation preserve=yes
      //## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.implementation

};

//## begin CSYStateConstitutionUnregisteringUnits%4523B00F0292.postscript preserve=yes
//## end CSYStateConstitutionUnregisteringUnits%4523B00F0292.postscript

// Class CSYStateConstitutionRegisteringUnits 

// Class CSYStateConstitutionUnregisteringUnits 

//## begin module%3EE0871B0298.epilog preserve=yes
//## end module%3EE0871B0298.epilog


#endif
