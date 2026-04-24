//## begin module%3EE737BB01C5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE737BB01C5.cm

//## begin module%3EE737BB01C5.cp preserve=no
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
//## end module%3EE737BB01C5.cp

//## Module: EBI2CEPROMexcp%3EE737BB01C5; Package specification
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMexcp.h

#ifndef EBI2CEPROMexcp_h
#define EBI2CEPROMexcp_h 1

//## begin module%3EE737BB01C5.additionalIncludes preserve=no
//## end module%3EE737BB01C5.additionalIncludes

//## begin module%3EE737BB01C5.includes preserve=yes
//## end module%3EE737BB01C5.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3EE737BB01C5.declarations preserve=no
//## end module%3EE737BB01C5.declarations

//## begin module%3EE737BB01C5.additionalDeclarations preserve=yes
//## end module%3EE737BB01C5.additionalDeclarations


//## begin XI2CEpromExceptionError%3EDDB7BB0128.preface preserve=yes
//## end XI2CEpromExceptionError%3EDDB7BB0128.preface

//## Class: XI2CEpromExceptionError%3EDDB7BB0128
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XI2CEpromExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3EDDB7C800FA
{
  //## begin XI2CEpromExceptionError%3EDDB7BB0128.initialDeclarations preserve=yes
  //## end XI2CEpromExceptionError%3EDDB7BB0128.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XI2CEpromExceptionError%1054707812
      XI2CEpromExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XI2CEpromExceptionError%1054707813
      XI2CEpromExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XI2CEpromExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1054707814
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1054707815
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XI2CEpromExceptionError%3EDDB7BB0128.public preserve=yes
      //## end XI2CEpromExceptionError%3EDDB7BB0128.public

  protected:
    // Additional Protected Declarations
      //## begin XI2CEpromExceptionError%3EDDB7BB0128.protected preserve=yes
      //## end XI2CEpromExceptionError%3EDDB7BB0128.protected

  private:
    //## Constructors (generated)
      XI2CEpromExceptionError();

      XI2CEpromExceptionError(const XI2CEpromExceptionError &right);

    //## Assignment Operation (generated)
      const XI2CEpromExceptionError & operator=(const XI2CEpromExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XI2CEpromExceptionError &right) const;

      bool operator!=(const XI2CEpromExceptionError &right) const;

    // Additional Private Declarations
      //## begin XI2CEpromExceptionError%3EDDB7BB0128.private preserve=yes
      //## end XI2CEpromExceptionError%3EDDB7BB0128.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XI2CEpromExceptionError%3EDDB7BB0128.implementation preserve=yes
      //## end XI2CEpromExceptionError%3EDDB7BB0128.implementation

};

//## begin XI2CEpromExceptionError%3EDDB7BB0128.postscript preserve=yes
//## end XI2CEpromExceptionError%3EDDB7BB0128.postscript

// Class XI2CEpromExceptionError 

//## begin module%3EE737BB01C5.epilog preserve=yes
//## end module%3EE737BB01C5.epilog


#endif
