//## begin module%3FB4AEF4031C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FB4AEF4031C.cm

//## begin module%3FB4AEF4031C.cp preserve=no
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
//## end module%3FB4AEF4031C.cp

//## Module: EBWCexcp%3FB4AEF4031C; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCexcp.h

#ifndef EBWCexcp_h
#define EBWCexcp_h 1

//## begin module%3FB4AEF4031C.additionalIncludes preserve=no
//## end module%3FB4AEF4031C.additionalIncludes

//## begin module%3FB4AEF4031C.includes preserve=yes
//## end module%3FB4AEF4031C.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3FB4AEF4031C.declarations preserve=no
//## end module%3FB4AEF4031C.declarations

//## begin module%3FB4AEF4031C.additionalDeclarations preserve=yes
//## end module%3FB4AEF4031C.additionalDeclarations


//## begin XWCExceptionError%3FB4AECD02CE.preface preserve=yes
//## end XWCExceptionError%3FB4AECD02CE.preface

//## Class: XWCExceptionError%3FB4AECD02CE
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XWCExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3FB4AF21031C
{
  //## begin XWCExceptionError%3FB4AECD02CE.initialDeclarations preserve=yes
  //## end XWCExceptionError%3FB4AECD02CE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XWCExceptionError%1068804683
      XWCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XWCExceptionError%1068804684
      XWCExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XWCExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1068804685
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1068804686
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XWCExceptionError%3FB4AECD02CE.public preserve=yes
      //## end XWCExceptionError%3FB4AECD02CE.public

  protected:
    // Additional Protected Declarations
      //## begin XWCExceptionError%3FB4AECD02CE.protected preserve=yes
      //## end XWCExceptionError%3FB4AECD02CE.protected

  private:
    //## Constructors (generated)
      XWCExceptionError(const XWCExceptionError &right);

    //## Assignment Operation (generated)
      const XWCExceptionError & operator=(const XWCExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XWCExceptionError &right) const;

      bool operator!=(const XWCExceptionError &right) const;

    // Additional Private Declarations
      //## begin XWCExceptionError%3FB4AECD02CE.private preserve=yes
      //## end XWCExceptionError%3FB4AECD02CE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XWCExceptionError%3FB4AECD02CE.implementation preserve=yes
      //## end XWCExceptionError%3FB4AECD02CE.implementation

};

//## begin XWCExceptionError%3FB4AECD02CE.postscript preserve=yes
//## end XWCExceptionError%3FB4AECD02CE.postscript

// Class XWCExceptionError 

//## begin module%3FB4AEF4031C.epilog preserve=yes
//## end module%3FB4AEF4031C.epilog


#endif
