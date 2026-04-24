//## begin module%3F4B4E97031C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4E97031C.cm

//## begin module%3F4B4E97031C.cp preserve=no
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
//## end module%3F4B4E97031C.cp

//## Module: EBI2CDPexcp%3F4B4E97031C; Package specification
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPexcp.h

#ifndef EBI2CDPexcp_h
#define EBI2CDPexcp_h 1

//## begin module%3F4B4E97031C.additionalIncludes preserve=no
//## end module%3F4B4E97031C.additionalIncludes

//## begin module%3F4B4E97031C.includes preserve=yes
//## end module%3F4B4E97031C.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3F4B4E97031C.declarations preserve=no
//## end module%3F4B4E97031C.declarations

//## begin module%3F4B4E97031C.additionalDeclarations preserve=yes
//## end module%3F4B4E97031C.additionalDeclarations


//## begin XI2CDPExceptionError%3F4B63C200FA.preface preserve=yes
//## end XI2CDPExceptionError%3F4B63C200FA.preface

//## Class: XI2CDPExceptionError%3F4B63C200FA
//## Category: EBI2CDP (I2C Digital Potentiometer)%3F4B4CE20177
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XI2CDPExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3F4B63D0038A
{
  //## begin XI2CDPExceptionError%3F4B63C200FA.initialDeclarations preserve=yes
  //## end XI2CDPExceptionError%3F4B63C200FA.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XI2CDPExceptionError%1061902085
      XI2CDPExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XI2CDPExceptionError%1061902086
      XI2CDPExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XI2CDPExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1061902087
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1061902088
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XI2CDPExceptionError%3F4B63C200FA.public preserve=yes
      //## end XI2CDPExceptionError%3F4B63C200FA.public

  protected:
    // Additional Protected Declarations
      //## begin XI2CDPExceptionError%3F4B63C200FA.protected preserve=yes
      //## end XI2CDPExceptionError%3F4B63C200FA.protected

  private:
    //## Constructors (generated)
      XI2CDPExceptionError();

      XI2CDPExceptionError(const XI2CDPExceptionError &right);

    //## Assignment Operation (generated)
      const XI2CDPExceptionError & operator=(const XI2CDPExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XI2CDPExceptionError &right) const;

      bool operator!=(const XI2CDPExceptionError &right) const;

    // Additional Private Declarations
      //## begin XI2CDPExceptionError%3F4B63C200FA.private preserve=yes
      //## end XI2CDPExceptionError%3F4B63C200FA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XI2CDPExceptionError%3F4B63C200FA.implementation preserve=yes
      //## end XI2CDPExceptionError%3F4B63C200FA.implementation

};

//## begin XI2CDPExceptionError%3F4B63C200FA.postscript preserve=yes
//## end XI2CDPExceptionError%3F4B63C200FA.postscript

// Class XI2CDPExceptionError 

//## begin module%3F4B4E97031C.epilog preserve=yes
//## end module%3F4B4E97031C.epilog


#endif
