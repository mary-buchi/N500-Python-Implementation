//## begin module%3BAA50270271.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BAA50270271.cm

//## begin module%3BAA50270271.cp preserve=no
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
//## end module%3BAA50270271.cp

//## Module: EBCOtype%3BAA50270271; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOtype.h

#ifndef EBCOtype_h
#define EBCOtype_h 1

//## begin module%3BAA50270271.additionalIncludes preserve=no
//## end module%3BAA50270271.additionalIncludes

//## begin module%3BAA50270271.includes preserve=yes
//## end module%3BAA50270271.includes

// EBCOrefc
#include "EBCOrefc.h"


//## begin module%3BAA50270271.declarations preserve=no
#define CO_WAKE_MASK_CMD_ABOVE_NORMAL       1
#define CO_WAKE_MASK_CMD_HIGH               2
#define CO_WAKE_MASK_ACTIONS_ONE            32
#define CO_WAKE_MASK_ACTIONS_ALL            64
#define CO_WAKE_MASK_DEFAULT                (CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_ACTIONS_ALL)
//## end module%3BAA50270271.declarations

//## begin module%3BAA50270271.additionalDeclarations preserve=yes
//## end module%3BAA50270271.additionalDeclarations


//## begin ECOInterruptReason%3BAA4CBF026D.preface preserve=yes
//## end ECOInterruptReason%3BAA4CBF026D.preface

//## Class: ECOInterruptReason%3BAA4CBF026D
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eIRActionsDone, eIRCmdAboveNormal, eIRCmdHigh, eIRTimeout } ECOInterruptReason;

//## begin ECOInterruptReason%3BAA4CBF026D.postscript preserve=yes
//## end ECOInterruptReason%3BAA4CBF026D.postscript

//## begin CO_WAKE_UP_MASK%3BAA4E100019.preface preserve=yes
//## end CO_WAKE_UP_MASK%3BAA4E100019.preface

//## Class: CO_WAKE_UP_MASK%3BAA4E100019; Class Utility
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin CO_WAKE_UP_MASK%3BAA4E100019.postscript preserve=yes
//## end CO_WAKE_UP_MASK%3BAA4E100019.postscript

//## begin CCOIntegerArray%3DB512AD01E6.preface preserve=yes
//## end CCOIntegerArray%3DB512AD01E6.preface

//## Class: CCOIntegerArray%3DB512AD01E6
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL CCOIntegerArray : public ICORefCounting  //## Inherits: <unnamed>%3DB512E7031F
{
  //## begin CCOIntegerArray%3DB512AD01E6.initialDeclarations preserve=yes
  //## end CCOIntegerArray%3DB512AD01E6.initialDeclarations

  public:
    //## Constructors (generated)
      CCOIntegerArray();

    //## Constructors (specified)
      //## Operation: CCOIntegerArray%1037016804
      CCOIntegerArray (const CArray<INT,INT>& p_Array);

    //## Destructor (generated)
      virtual ~CCOIntegerArray();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3DB5184203CB
      //## Role: CCOIntegerArray::Array%3DB5184301A9
      //## Constraints:
      //	ordered
      CArray<INT,INT>& GetArray ();
      void SetArray (const CArray<INT,INT>& value);

    // Additional Public Declarations
      //## begin CCOIntegerArray%3DB512AD01E6.public preserve=yes
      //## end CCOIntegerArray%3DB512AD01E6.public

  protected:
    // Additional Protected Declarations
      //## begin CCOIntegerArray%3DB512AD01E6.protected preserve=yes
      //## end CCOIntegerArray%3DB512AD01E6.protected

  private:
    //## Constructors (generated)
      CCOIntegerArray(const CCOIntegerArray &right);

    //## Assignment Operation (generated)
      const CCOIntegerArray & operator=(const CCOIntegerArray &right);

    //## Equality Operations (generated)
      bool operator==(const CCOIntegerArray &right) const;

      bool operator!=(const CCOIntegerArray &right) const;

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DB5184203CB
      //## begin CCOIntegerArray::Array%3DB5184301A9.role preserve=no  public: INT { -> 0..10VFHON}
      CArray<INT,INT> m_Array;
      //## end CCOIntegerArray::Array%3DB5184301A9.role

    // Additional Private Declarations
      //## begin CCOIntegerArray%3DB512AD01E6.private preserve=yes
      //## end CCOIntegerArray%3DB512AD01E6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOIntegerArray%3DB512AD01E6.implementation preserve=yes
      //## end CCOIntegerArray%3DB512AD01E6.implementation

};

//## begin CCOIntegerArray%3DB512AD01E6.postscript preserve=yes
//## end CCOIntegerArray%3DB512AD01E6.postscript

// Class CCOIntegerArray 

//## begin module%3BAA50270271.epilog preserve=yes
//## end module%3BAA50270271.epilog


#endif
