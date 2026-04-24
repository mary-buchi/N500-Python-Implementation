//## begin module%3F0190540120.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F0190540120.cm

//## begin module%3F0190540120.cp preserve=no
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
//## end module%3F0190540120.cp

//## Module: EBPIexcp%3F0190540120; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIexcp.h

#ifndef EBPIexcp_h
#define EBPIexcp_h 1

//## begin module%3F0190540120.additionalIncludes preserve=no
//## end module%3F0190540120.additionalIncludes

//## begin module%3F0190540120.includes preserve=yes
//## end module%3F0190540120.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3F0190540120.declarations preserve=no
//## end module%3F0190540120.declarations

//## begin module%3F0190540120.additionalDeclarations preserve=yes
//## end module%3F0190540120.additionalDeclarations


//## begin XPIExceptionErrorMissingCreator%3F018EED02E6.preface preserve=yes
//## end XPIExceptionErrorMissingCreator%3F018EED02E6.preface

//## Class: XPIExceptionErrorMissingCreator%3F018EED02E6
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPIExceptionErrorMissingCreator : public XCOExceptionError  //## Inherits: <unnamed>%3F018F310007
{
  //## begin XPIExceptionErrorMissingCreator%3F018EED02E6.initialDeclarations preserve=yes
  //## end XPIExceptionErrorMissingCreator%3F018EED02E6.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPIExceptionErrorMissingCreator%1057067246
      XPIExceptionErrorMissingCreator (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText = "");

      //## Operation: XPIExceptionErrorMissingCreator%1057067247
      XPIExceptionErrorMissingCreator (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPIExceptionErrorMissingCreator%1057067248
      XPIExceptionErrorMissingCreator (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPIExceptionErrorMissingCreator();


    //## Other Operations (specified)
      //## Operation: Throw%1057067249
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1057067250
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPIExceptionErrorMissingCreator%3F018EED02E6.public preserve=yes
      //## end XPIExceptionErrorMissingCreator%3F018EED02E6.public

  protected:
    // Additional Protected Declarations
      //## begin XPIExceptionErrorMissingCreator%3F018EED02E6.protected preserve=yes
      //## end XPIExceptionErrorMissingCreator%3F018EED02E6.protected

  private:
    //## Constructors (generated)
      XPIExceptionErrorMissingCreator();

      XPIExceptionErrorMissingCreator(const XPIExceptionErrorMissingCreator &right);

    //## Assignment Operation (generated)
      const XPIExceptionErrorMissingCreator & operator=(const XPIExceptionErrorMissingCreator &right);

    //## Equality Operations (generated)
      bool operator==(const XPIExceptionErrorMissingCreator &right) const;

      bool operator!=(const XPIExceptionErrorMissingCreator &right) const;

    // Additional Private Declarations
      //## begin XPIExceptionErrorMissingCreator%3F018EED02E6.private preserve=yes
      //## end XPIExceptionErrorMissingCreator%3F018EED02E6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPIExceptionErrorMissingCreator%3F018EED02E6.implementation preserve=yes
      //## end XPIExceptionErrorMissingCreator%3F018EED02E6.implementation

};

//## begin XPIExceptionErrorMissingCreator%3F018EED02E6.postscript preserve=yes
//## end XPIExceptionErrorMissingCreator%3F018EED02E6.postscript

//## begin XPIExceptionInvalidObjReference%3F58927D00BE.preface preserve=yes
//## end XPIExceptionInvalidObjReference%3F58927D00BE.preface

//## Class: XPIExceptionInvalidObjReference%3F58927D00BE
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPIExceptionInvalidObjReference : public XCOExceptionError  //## Inherits: <unnamed>%3F5892930022
{
  //## begin XPIExceptionInvalidObjReference%3F58927D00BE.initialDeclarations preserve=yes
  //## end XPIExceptionInvalidObjReference%3F58927D00BE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPIExceptionInvalidObjReference%1062769442
      XPIExceptionInvalidObjReference (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XPIExceptionInvalidObjReference%1062769443
      XPIExceptionInvalidObjReference (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPIExceptionInvalidObjReference();


    //## Other Operations (specified)
      //## Operation: Throw%1062769444
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1062769445
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPIExceptionInvalidObjReference%3F58927D00BE.public preserve=yes
      //## end XPIExceptionInvalidObjReference%3F58927D00BE.public

  protected:
    // Additional Protected Declarations
      //## begin XPIExceptionInvalidObjReference%3F58927D00BE.protected preserve=yes
      //## end XPIExceptionInvalidObjReference%3F58927D00BE.protected

  private:
    //## Constructors (generated)
      XPIExceptionInvalidObjReference();

      XPIExceptionInvalidObjReference(const XPIExceptionInvalidObjReference &right);

    //## Assignment Operation (generated)
      const XPIExceptionInvalidObjReference & operator=(const XPIExceptionInvalidObjReference &right);

    //## Equality Operations (generated)
      bool operator==(const XPIExceptionInvalidObjReference &right) const;

      bool operator!=(const XPIExceptionInvalidObjReference &right) const;

    // Additional Private Declarations
      //## begin XPIExceptionInvalidObjReference%3F58927D00BE.private preserve=yes
      //## end XPIExceptionInvalidObjReference%3F58927D00BE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPIExceptionInvalidObjReference%3F58927D00BE.implementation preserve=yes
      //## end XPIExceptionInvalidObjReference%3F58927D00BE.implementation

};

//## begin XPIExceptionInvalidObjReference%3F58927D00BE.postscript preserve=yes
//## end XPIExceptionInvalidObjReference%3F58927D00BE.postscript

//## begin XPIExceptionErrorTokenizing%42009B6F00E1.preface preserve=yes
//## end XPIExceptionErrorTokenizing%42009B6F00E1.preface

//## Class: XPIExceptionErrorTokenizing%42009B6F00E1
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPIExceptionErrorTokenizing : public XCOExceptionError  //## Inherits: <unnamed>%42009B910278
{
  //## begin XPIExceptionErrorTokenizing%42009B6F00E1.initialDeclarations preserve=yes
  //## end XPIExceptionErrorTokenizing%42009B6F00E1.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPIExceptionErrorTokenizing%1107335986
      XPIExceptionErrorTokenizing (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XPIExceptionErrorTokenizing%1107335987
      XPIExceptionErrorTokenizing (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPIExceptionErrorTokenizing();


    //## Other Operations (specified)
      //## Operation: Throw%1107335988
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1107335989
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPIExceptionErrorTokenizing%42009B6F00E1.public preserve=yes
      //## end XPIExceptionErrorTokenizing%42009B6F00E1.public

  protected:
    // Additional Protected Declarations
      //## begin XPIExceptionErrorTokenizing%42009B6F00E1.protected preserve=yes
      //## end XPIExceptionErrorTokenizing%42009B6F00E1.protected

  private:
    //## Constructors (generated)
      XPIExceptionErrorTokenizing();

      XPIExceptionErrorTokenizing(const XPIExceptionErrorTokenizing &right);

    //## Assignment Operation (generated)
      const XPIExceptionErrorTokenizing & operator=(const XPIExceptionErrorTokenizing &right);

    //## Equality Operations (generated)
      bool operator==(const XPIExceptionErrorTokenizing &right) const;

      bool operator!=(const XPIExceptionErrorTokenizing &right) const;

    // Additional Private Declarations
      //## begin XPIExceptionErrorTokenizing%42009B6F00E1.private preserve=yes
      //## end XPIExceptionErrorTokenizing%42009B6F00E1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPIExceptionErrorTokenizing%42009B6F00E1.implementation preserve=yes
      //## end XPIExceptionErrorTokenizing%42009B6F00E1.implementation

};

//## begin XPIExceptionErrorTokenizing%42009B6F00E1.postscript preserve=yes
//## end XPIExceptionErrorTokenizing%42009B6F00E1.postscript

// Class XPIExceptionErrorMissingCreator 

// Class XPIExceptionInvalidObjReference 

// Class XPIExceptionErrorTokenizing 

//## begin module%3F0190540120.epilog preserve=yes
//## end module%3F0190540120.epilog


#endif
