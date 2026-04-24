//## begin module%400248600322.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%400248600322.cm

//## begin module%400248600322.cp preserve=no
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
//## end module%400248600322.cp

//## Module: EBPOexcp%400248600322; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOexcp.h

#ifndef EBPOexcp_h
#define EBPOexcp_h 1

//## begin module%400248600322.additionalIncludes preserve=no
//## end module%400248600322.additionalIncludes

//## begin module%400248600322.includes preserve=yes
//## end module%400248600322.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%400248600322.declarations preserve=no
//## end module%400248600322.declarations

//## begin module%400248600322.additionalDeclarations preserve=yes
//## end module%400248600322.additionalDeclarations


//## begin XPOExceptionError%40024814038F.preface preserve=yes
//## end XPOExceptionError%40024814038F.preface

//## Class: XPOExceptionError%40024814038F
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPOExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%4002482C011E
{
  //## begin XPOExceptionError%40024814038F.initialDeclarations preserve=yes
  //## end XPOExceptionError%40024814038F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPOExceptionError%1073894412
      XPOExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPOExceptionError%1073894413
      XPOExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPOExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1073894414
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1073894415
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPOExceptionError%40024814038F.public preserve=yes
      //## end XPOExceptionError%40024814038F.public

  protected:
    // Additional Protected Declarations
      //## begin XPOExceptionError%40024814038F.protected preserve=yes
      //## end XPOExceptionError%40024814038F.protected

  private:
    //## Constructors (generated)
      XPOExceptionError(const XPOExceptionError &right);

    //## Assignment Operation (generated)
      const XPOExceptionError & operator=(const XPOExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XPOExceptionError &right) const;

      bool operator!=(const XPOExceptionError &right) const;

    // Additional Private Declarations
      //## begin XPOExceptionError%40024814038F.private preserve=yes
      //## end XPOExceptionError%40024814038F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPOExceptionError%40024814038F.implementation preserve=yes
      //## end XPOExceptionError%40024814038F.implementation

};

//## begin XPOExceptionError%40024814038F.postscript preserve=yes
//## end XPOExceptionError%40024814038F.postscript

//## begin XPOExceptionHeader%400249170014.preface preserve=yes
//## end XPOExceptionHeader%400249170014.preface

//## Class: XPOExceptionHeader%400249170014
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPOExceptionHeader : public XPOExceptionError  //## Inherits: <unnamed>%40024C7800DF
{
  //## begin XPOExceptionHeader%400249170014.initialDeclarations preserve=yes
  //## end XPOExceptionHeader%400249170014.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPOExceptionHeader%1073894416
      XPOExceptionHeader (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPOExceptionHeader%1073894417
      XPOExceptionHeader (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPOExceptionHeader();


    //## Other Operations (specified)
      //## Operation: Clone%1073894418
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

      //## Operation: Throw%1073894419
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

    // Additional Public Declarations
      //## begin XPOExceptionHeader%400249170014.public preserve=yes
      //## end XPOExceptionHeader%400249170014.public

  protected:
    // Additional Protected Declarations
      //## begin XPOExceptionHeader%400249170014.protected preserve=yes
      //## end XPOExceptionHeader%400249170014.protected

  private:
    //## Constructors (generated)
      XPOExceptionHeader(const XPOExceptionHeader &right);

    //## Assignment Operation (generated)
      const XPOExceptionHeader & operator=(const XPOExceptionHeader &right);

    //## Equality Operations (generated)
      bool operator==(const XPOExceptionHeader &right) const;

      bool operator!=(const XPOExceptionHeader &right) const;

    // Additional Private Declarations
      //## begin XPOExceptionHeader%400249170014.private preserve=yes
      //## end XPOExceptionHeader%400249170014.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPOExceptionHeader%400249170014.implementation preserve=yes
      //## end XPOExceptionHeader%400249170014.implementation

};

//## begin XPOExceptionHeader%400249170014.postscript preserve=yes
//## end XPOExceptionHeader%400249170014.postscript

//## begin XPOExceptionEpromFull%4002496E0237.preface preserve=yes
//## end XPOExceptionEpromFull%4002496E0237.preface

//## Class: XPOExceptionEpromFull%4002496E0237
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPOExceptionEpromFull : public XPOExceptionError  //## Inherits: <unnamed>%40024C7A02E3
{
  //## begin XPOExceptionEpromFull%4002496E0237.initialDeclarations preserve=yes
  //## end XPOExceptionEpromFull%4002496E0237.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPOExceptionEpromFull%1073894420
      XPOExceptionEpromFull (XCOExceptionError* p_pOrigException);

      //## Operation: XPOExceptionEpromFull%1073894421
      XPOExceptionEpromFull (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

    //## Destructor (generated)
      virtual ~XPOExceptionEpromFull();


    //## Other Operations (specified)
      //## Operation: Clone%1073894422
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

      //## Operation: Throw%1073894423
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

    // Additional Public Declarations
      //## begin XPOExceptionEpromFull%4002496E0237.public preserve=yes
      //## end XPOExceptionEpromFull%4002496E0237.public

  protected:
    // Additional Protected Declarations
      //## begin XPOExceptionEpromFull%4002496E0237.protected preserve=yes
      //## end XPOExceptionEpromFull%4002496E0237.protected

  private:
    //## Constructors (generated)
      XPOExceptionEpromFull(const XPOExceptionEpromFull &right);

    //## Assignment Operation (generated)
      const XPOExceptionEpromFull & operator=(const XPOExceptionEpromFull &right);

    //## Equality Operations (generated)
      bool operator==(const XPOExceptionEpromFull &right) const;

      bool operator!=(const XPOExceptionEpromFull &right) const;

    // Additional Private Declarations
      //## begin XPOExceptionEpromFull%4002496E0237.private preserve=yes
      //## end XPOExceptionEpromFull%4002496E0237.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPOExceptionEpromFull%4002496E0237.implementation preserve=yes
      //## end XPOExceptionEpromFull%4002496E0237.implementation

};

//## begin XPOExceptionEpromFull%4002496E0237.postscript preserve=yes
//## end XPOExceptionEpromFull%4002496E0237.postscript

//## begin XPOExceptionWrongDataSize%40024B62013D.preface preserve=yes
//## end XPOExceptionWrongDataSize%40024B62013D.preface

//## Class: XPOExceptionWrongDataSize%40024B62013D
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPOExceptionWrongDataSize : public XPOExceptionError  //## Inherits: <unnamed>%40024C7C03CD
{
  //## begin XPOExceptionWrongDataSize%40024B62013D.initialDeclarations preserve=yes
  //## end XPOExceptionWrongDataSize%40024B62013D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPOExceptionWrongDataSize%1073894424
      XPOExceptionWrongDataSize (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPOExceptionWrongDataSize%1073894425
      XPOExceptionWrongDataSize (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPOExceptionWrongDataSize();


    //## Other Operations (specified)
      //## Operation: Throw%1073894426
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1073894427
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPOExceptionWrongDataSize%40024B62013D.public preserve=yes
      //## end XPOExceptionWrongDataSize%40024B62013D.public

  protected:
    // Additional Protected Declarations
      //## begin XPOExceptionWrongDataSize%40024B62013D.protected preserve=yes
      //## end XPOExceptionWrongDataSize%40024B62013D.protected

  private:
    //## Constructors (generated)
      XPOExceptionWrongDataSize(const XPOExceptionWrongDataSize &right);

    //## Assignment Operation (generated)
      const XPOExceptionWrongDataSize & operator=(const XPOExceptionWrongDataSize &right);

    //## Equality Operations (generated)
      bool operator==(const XPOExceptionWrongDataSize &right) const;

      bool operator!=(const XPOExceptionWrongDataSize &right) const;

    // Additional Private Declarations
      //## begin XPOExceptionWrongDataSize%40024B62013D.private preserve=yes
      //## end XPOExceptionWrongDataSize%40024B62013D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPOExceptionWrongDataSize%40024B62013D.implementation preserve=yes
      //## end XPOExceptionWrongDataSize%40024B62013D.implementation

};

//## begin XPOExceptionWrongDataSize%40024B62013D.postscript preserve=yes
//## end XPOExceptionWrongDataSize%40024B62013D.postscript

// Class XPOExceptionError 

// Class XPOExceptionHeader 

// Class XPOExceptionEpromFull 

// Class XPOExceptionWrongDataSize 

//## begin module%400248600322.epilog preserve=yes
//## end module%400248600322.epilog


#endif
