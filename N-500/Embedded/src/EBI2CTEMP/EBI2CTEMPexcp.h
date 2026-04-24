//## begin module%3EE73764002E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE73764002E.cm

//## begin module%3EE73764002E.cp preserve=no
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
//## end module%3EE73764002E.cp

//## Module: EBI2CTEMPexcp%3EE73764002E; Package specification
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPexcp.h

#ifndef EBI2CTEMPexcp_h
#define EBI2CTEMPexcp_h 1

//## begin module%3EE73764002E.additionalIncludes preserve=no
//## end module%3EE73764002E.additionalIncludes

//## begin module%3EE73764002E.includes preserve=yes
//## end module%3EE73764002E.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3EE73764002E.declarations preserve=no
//## end module%3EE73764002E.declarations

//## begin module%3EE73764002E.additionalDeclarations preserve=yes
//## end module%3EE73764002E.additionalDeclarations


//## begin XI2CTempExceptionError%3EE876FF0222.preface preserve=yes
//## end XI2CTempExceptionError%3EE876FF0222.preface

//## Class: XI2CTempExceptionError%3EE876FF0222
//## Category: EBI2CTemp (I2C Temperature Device)%3EE73654004E
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XI2CTempExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3EE877120186
{
  //## begin XI2CTempExceptionError%3EE876FF0222.initialDeclarations preserve=yes
  //## end XI2CTempExceptionError%3EE876FF0222.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XI2CTempExceptionError%1055398085
      XI2CTempExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XI2CTempExceptionError%1055398086
      XI2CTempExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XI2CTempExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1055398087
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055398088
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XI2CTempExceptionError%3EE876FF0222.public preserve=yes
      //## end XI2CTempExceptionError%3EE876FF0222.public

  protected:
    // Additional Protected Declarations
      //## begin XI2CTempExceptionError%3EE876FF0222.protected preserve=yes
      //## end XI2CTempExceptionError%3EE876FF0222.protected

  private:
    //## Constructors (generated)
      XI2CTempExceptionError();

      XI2CTempExceptionError(const XI2CTempExceptionError &right);

    //## Assignment Operation (generated)
      const XI2CTempExceptionError & operator=(const XI2CTempExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XI2CTempExceptionError &right) const;

      bool operator!=(const XI2CTempExceptionError &right) const;

    // Additional Private Declarations
      //## begin XI2CTempExceptionError%3EE876FF0222.private preserve=yes
      //## end XI2CTempExceptionError%3EE876FF0222.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XI2CTempExceptionError%3EE876FF0222.implementation preserve=yes
      //## end XI2CTempExceptionError%3EE876FF0222.implementation

};

//## begin XI2CTempExceptionError%3EE876FF0222.postscript preserve=yes
//## end XI2CTempExceptionError%3EE876FF0222.postscript

// Class XI2CTempExceptionError 

//## begin module%3EE73764002E.epilog preserve=yes
//## end module%3EE73764002E.epilog


#endif
