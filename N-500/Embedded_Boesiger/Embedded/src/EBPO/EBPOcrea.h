//## begin module%3DE5EB1D0341.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB1D0341.cm

//## begin module%3DE5EB1D0341.cp preserve=no
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
//## end module%3DE5EB1D0341.cp

//## Module: EBPOcrea%3DE5EB1D0341; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcrea.h

#ifndef EBPOcrea_h
#define EBPOcrea_h 1

//## begin module%3DE5EB1D0341.additionalIncludes preserve=no
//## end module%3DE5EB1D0341.additionalIncludes

//## begin module%3DE5EB1D0341.includes preserve=yes
//## end module%3DE5EB1D0341.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3DE5EB1D0341.declarations preserve=no
//## end module%3DE5EB1D0341.declarations

//## begin module%3DE5EB1D0341.additionalDeclarations preserve=yes
//## end module%3DE5EB1D0341.additionalDeclarations


//## begin CPOPersistentObjCreatorV0%3DE626DA02F2.preface preserve=yes
//## end CPOPersistentObjCreatorV0%3DE626DA02F2.preface

//## Class: CPOPersistentObjCreatorV0%3DE626DA02F2
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE62EE000C0;CPOPersistentObjInterface { -> }

class CPOPersistentObjCreatorV0 : public CPIObjCreatorPersistentObject  //## Inherits: <unnamed>%3DE626F50062
{
  //## begin CPOPersistentObjCreatorV0%3DE626DA02F2.initialDeclarations preserve=yes
  //## end CPOPersistentObjCreatorV0%3DE626DA02F2.initialDeclarations

  public:
    //## Constructors (generated)
      CPOPersistentObjCreatorV0();

    //## Destructor (generated)
      virtual ~CPOPersistentObjCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1038493580
      virtual IPIPersistentObjInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CPOPersistentObjCreatorV0%3DE626DA02F2.public preserve=yes
      //## end CPOPersistentObjCreatorV0%3DE626DA02F2.public

  protected:
    // Additional Protected Declarations
      //## begin CPOPersistentObjCreatorV0%3DE626DA02F2.protected preserve=yes
      //## end CPOPersistentObjCreatorV0%3DE626DA02F2.protected

  private:
    //## Constructors (generated)
      CPOPersistentObjCreatorV0(const CPOPersistentObjCreatorV0 &right);

    //## Assignment Operation (generated)
      const CPOPersistentObjCreatorV0 & operator=(const CPOPersistentObjCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CPOPersistentObjCreatorV0 &right) const;

      bool operator!=(const CPOPersistentObjCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CPOPersistentObjCreatorV0%3DE626DA02F2.private preserve=yes
      //## end CPOPersistentObjCreatorV0%3DE626DA02F2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOPersistentObjCreatorV0%3DE626DA02F2.implementation preserve=yes
      //## end CPOPersistentObjCreatorV0%3DE626DA02F2.implementation

};

//## begin CPOPersistentObjCreatorV0%3DE626DA02F2.postscript preserve=yes
//## end CPOPersistentObjCreatorV0%3DE626DA02F2.postscript

// Class CPOPersistentObjCreatorV0 

//## begin module%3DE5EB1D0341.epilog preserve=yes
//## end module%3DE5EB1D0341.epilog


#endif
