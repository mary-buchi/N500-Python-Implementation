//## begin module%3F49F8340177.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49F8340177.cm

//## begin module%3F49F8340177.cp preserve=no
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
//## end module%3F49F8340177.cp

//## Module: EBI2CADCexcp%3F49F8340177; Package specification
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCexcp.h

#ifndef EBI2CADCexcp_h
#define EBI2CADCexcp_h 1

//## begin module%3F49F8340177.additionalIncludes preserve=no
//## end module%3F49F8340177.additionalIncludes

//## begin module%3F49F8340177.includes preserve=yes
//## end module%3F49F8340177.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3F49F8340177.declarations preserve=no
//## end module%3F49F8340177.declarations

//## begin module%3F49F8340177.additionalDeclarations preserve=yes
//## end module%3F49F8340177.additionalDeclarations


//## begin XI2CADCExceptionError%3F4A1D06002E.preface preserve=yes
//## end XI2CADCExceptionError%3F4A1D06002E.preface

//## Class: XI2CADCExceptionError%3F4A1D06002E
//## Category: EBI2CADC (I2C ADC)%3F49CFE2030D
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XI2CADCExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3F4A1D180213
{
  //## begin XI2CADCExceptionError%3F4A1D06002E.initialDeclarations preserve=yes
  //## end XI2CADCExceptionError%3F4A1D06002E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XI2CADCExceptionError%1061804167
      XI2CADCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XI2CADCExceptionError%1061804168
      XI2CADCExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XI2CADCExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1061804169
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1061804170
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XI2CADCExceptionError%3F4A1D06002E.public preserve=yes
      //## end XI2CADCExceptionError%3F4A1D06002E.public

  protected:
    // Additional Protected Declarations
      //## begin XI2CADCExceptionError%3F4A1D06002E.protected preserve=yes
      //## end XI2CADCExceptionError%3F4A1D06002E.protected

  private:
    //## Constructors (generated)
      XI2CADCExceptionError();

      XI2CADCExceptionError(const XI2CADCExceptionError &right);

    //## Assignment Operation (generated)
      const XI2CADCExceptionError & operator=(const XI2CADCExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XI2CADCExceptionError &right) const;

      bool operator!=(const XI2CADCExceptionError &right) const;

    // Additional Private Declarations
      //## begin XI2CADCExceptionError%3F4A1D06002E.private preserve=yes
      //## end XI2CADCExceptionError%3F4A1D06002E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XI2CADCExceptionError%3F4A1D06002E.implementation preserve=yes
      //## end XI2CADCExceptionError%3F4A1D06002E.implementation

};

//## begin XI2CADCExceptionError%3F4A1D06002E.postscript preserve=yes
//## end XI2CADCExceptionError%3F4A1D06002E.postscript

// Class XI2CADCExceptionError 

//## begin module%3F49F8340177.epilog preserve=yes
//## end module%3F49F8340177.epilog


#endif
