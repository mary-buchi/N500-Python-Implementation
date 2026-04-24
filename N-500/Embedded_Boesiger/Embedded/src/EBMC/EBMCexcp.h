//## begin module%3FD025E701E4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FD025E701E4.cm

//## begin module%3FD025E701E4.cp preserve=no
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
//## end module%3FD025E701E4.cp

//## Module: EBMCexcp%3FD025E701E4; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCexcp.h

#ifndef EBMCexcp_h
#define EBMCexcp_h 1

//## begin module%3FD025E701E4.additionalIncludes preserve=no
//## end module%3FD025E701E4.additionalIncludes

//## begin module%3FD025E701E4.includes preserve=yes
//## end module%3FD025E701E4.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3FD025E701E4.declarations preserve=no
//## end module%3FD025E701E4.declarations

//## begin module%3FD025E701E4.additionalDeclarations preserve=yes
//## end module%3FD025E701E4.additionalDeclarations


//## begin XMCExceptionError%3FD0273400EA.preface preserve=yes
//## end XMCExceptionError%3FD0273400EA.preface

//## Class: XMCExceptionError%3FD0273400EA
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XMCExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3FD0274E0213
{
  //## begin XMCExceptionError%3FD0273400EA.initialDeclarations preserve=yes
  //## end XMCExceptionError%3FD0273400EA.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XMCExceptionError%1070606790
      XMCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XMCExceptionError%1070606791
      XMCExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XMCExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1070606792
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1070606793
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XMCExceptionError%3FD0273400EA.public preserve=yes
      //## end XMCExceptionError%3FD0273400EA.public

  protected:
    // Additional Protected Declarations
      //## begin XMCExceptionError%3FD0273400EA.protected preserve=yes
      //## end XMCExceptionError%3FD0273400EA.protected

  private:
    //## Constructors (generated)
      XMCExceptionError(const XMCExceptionError &right);

    //## Assignment Operation (generated)
      const XMCExceptionError & operator=(const XMCExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XMCExceptionError &right) const;

      bool operator!=(const XMCExceptionError &right) const;

    // Additional Private Declarations
      //## begin XMCExceptionError%3FD0273400EA.private preserve=yes
      //## end XMCExceptionError%3FD0273400EA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XMCExceptionError%3FD0273400EA.implementation preserve=yes
      //## end XMCExceptionError%3FD0273400EA.implementation

};

//## begin XMCExceptionError%3FD0273400EA.postscript preserve=yes
//## end XMCExceptionError%3FD0273400EA.postscript

// Class XMCExceptionError 

//## begin module%3FD025E701E4.epilog preserve=yes
//## end module%3FD025E701E4.epilog


#endif
