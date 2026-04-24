//## begin module%3B8D591101F9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D591101F9.cm

//## begin module%3B8D591101F9.cp preserve=no
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
//## end module%3B8D591101F9.cp

//## Module: EBCOexcp%3B8D591101F9; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOexcp.h

#ifndef EBCOexcp_h
#define EBCOexcp_h 1

//## begin module%3B8D591101F9.additionalIncludes preserve=no
//## end module%3B8D591101F9.additionalIncludes

//## begin module%3B8D591101F9.includes preserve=yes
//## end module%3B8D591101F9.includes

// EBCOidnt
#include "EBCOidnt.h"
//## begin module%3B8D591101F9.declarations preserve=no
#define XCO_INVALID_STATE(unit) throw new XCOExceptionInvalidState(unit,IDE_CORE_WRONG_STATE,__FILE__,__LINE__);

#define XCO_CLEANUP_STOP(unit) throw new XCOExceptionCleanupStop(unit,IDE_CORE_CLEANUP_STOP,__FILE__,__LINE__);

#define XCO_CLEANUP_INIT(unit) throw new XCOExceptionCleanupInitialize(unit,IDE_CORE_CLEANUP_INITIALIZE,__FILE__,__LINE__);

#define XCO_EXCEPTION(class,unit,id) throw new (class)(unit,id,__FILE__,__LINE__);
//## end module%3B8D591101F9.declarations

//## begin module%3B8D591101F9.additionalDeclarations preserve=yes
//## end module%3B8D591101F9.additionalDeclarations


//## begin XCOException%3B8D5928002F.preface preserve=yes
//## end XCOException%3B8D5928002F.preface

//## Class: XCOException%3B8D5928002F
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA884DC0004;CO_IDENTIFIERS { -> }

class EBCO_DLL_DECL XCOException : public CException  //## Inherits: <unnamed>%3B8D59490113
{
  //## begin XCOException%3B8D5928002F.initialDeclarations preserve=yes
  //## end XCOException%3B8D5928002F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOException%1000031206
      XCOException (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText = _T(""));

      //## Operation: XCOException%1043748201
      XCOException (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XCOException%1000031213
      XCOException (XCOException* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOException();


    //## Other Operations (specified)
      //## Operation: GetPlainText%1096656423
      virtual CString GetPlainText ();

      //## Operation: Throw%999119008
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw () = 0;

      //## Operation: Clone%1000031211
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone () = 0;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sUnitID%3B9BD67A002B
      const CString GetsUnitID () const;

      //## Attribute: uiExceptionID%3B9BD64502D8
      const UINT GetuiExceptionID () const;

      //## Attribute: sModuleName%3B9BD5D403DA
      const CString GetsModuleName () const;

      //## Attribute: uiModuleLine%3B9BD6020386
      const UINT GetuiModuleLine () const;

      //## Attribute: sRawText%3B9BD6A2000A
      const CString GetsRawText () const;

      //## Attribute: dwErrorCode%3E3678D503B9
      const DWORD GetdwErrorCode () const;

    // Additional Public Declarations
      //## begin XCOException%3B8D5928002F.public preserve=yes
      //## end XCOException%3B8D5928002F.public

  protected:
    // Additional Protected Declarations
      //## begin XCOException%3B8D5928002F.protected preserve=yes
      //## end XCOException%3B8D5928002F.protected

  private:
    //## Constructors (generated)
      XCOException();

      XCOException(const XCOException &right);

    //## Assignment Operation (generated)
      const XCOException & operator=(const XCOException &right);

    //## Equality Operations (generated)
      bool operator==(const XCOException &right) const;

      bool operator!=(const XCOException &right) const;

    // Data Members for Class Attributes

      //## begin XCOException::sUnitID%3B9BD67A002B.attr preserve=no  public: CString {U} 
      CString m_sUnitID;
      //## end XCOException::sUnitID%3B9BD67A002B.attr

      //## begin XCOException::uiExceptionID%3B9BD64502D8.attr preserve=no  public: UINT {U} 
      UINT m_uiExceptionID;
      //## end XCOException::uiExceptionID%3B9BD64502D8.attr

      //## begin XCOException::sModuleName%3B9BD5D403DA.attr preserve=no  public: CString {U} 
      CString m_sModuleName;
      //## end XCOException::sModuleName%3B9BD5D403DA.attr

      //## begin XCOException::uiModuleLine%3B9BD6020386.attr preserve=no  public: UINT {U} 
      UINT m_uiModuleLine;
      //## end XCOException::uiModuleLine%3B9BD6020386.attr

      //## begin XCOException::sRawText%3B9BD6A2000A.attr preserve=no  public: CString {U} 
      CString m_sRawText;
      //## end XCOException::sRawText%3B9BD6A2000A.attr

      //## begin XCOException::dwErrorCode%3E3678D503B9.attr preserve=no  public: DWORD {U} 
      DWORD m_dwErrorCode;
      //## end XCOException::dwErrorCode%3E3678D503B9.attr

    // Additional Private Declarations
      //## begin XCOException%3B8D5928002F.private preserve=yes
      //## end XCOException%3B8D5928002F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOException%3B8D5928002F.implementation preserve=yes
      //## end XCOException%3B8D5928002F.implementation

};

//## begin XCOException%3B8D5928002F.postscript preserve=yes
//## end XCOException%3B8D5928002F.postscript

//## begin XCOExceptionInvalidState%3B9BD7BF02BD.preface preserve=yes
//## end XCOExceptionInvalidState%3B9BD7BF02BD.preface

//## Class: XCOExceptionInvalidState%3B9BD7BF02BD
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionInvalidState : public XCOException  //## Inherits: <unnamed>%3B9BD855016E
{
  //## begin XCOExceptionInvalidState%3B9BD7BF02BD.initialDeclarations preserve=yes
  //## end XCOExceptionInvalidState%3B9BD7BF02BD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionInvalidState%1000031208
      XCOExceptionInvalidState (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XCOExceptionInvalidState%1000031214
      XCOExceptionInvalidState (XCOException* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionInvalidState();


    //## Other Operations (specified)
      //## Operation: Throw%1000031209
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1000031210
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XCOExceptionInvalidState%3B9BD7BF02BD.public preserve=yes
      //## end XCOExceptionInvalidState%3B9BD7BF02BD.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionInvalidState%3B9BD7BF02BD.protected preserve=yes
      //## end XCOExceptionInvalidState%3B9BD7BF02BD.protected

  private:
    //## Constructors (generated)
      XCOExceptionInvalidState();

      XCOExceptionInvalidState(const XCOExceptionInvalidState &right);

    //## Assignment Operation (generated)
      const XCOExceptionInvalidState & operator=(const XCOExceptionInvalidState &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionInvalidState &right) const;

      bool operator!=(const XCOExceptionInvalidState &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionInvalidState%3B9BD7BF02BD.private preserve=yes
      //## end XCOExceptionInvalidState%3B9BD7BF02BD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionInvalidState%3B9BD7BF02BD.implementation preserve=yes
      //## end XCOExceptionInvalidState%3B9BD7BF02BD.implementation

};

//## begin XCOExceptionInvalidState%3B9BD7BF02BD.postscript preserve=yes
//## end XCOExceptionInvalidState%3B9BD7BF02BD.postscript

//## begin XCOExceptionCleanup%3BA6498E00F2.preface preserve=yes
//## end XCOExceptionCleanup%3BA6498E00F2.preface

//## Class: XCOExceptionCleanup%3BA6498E00F2
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionCleanup : public XCOException  //## Inherits: <unnamed>%3BA649C401AE
{
  //## begin XCOExceptionCleanup%3BA6498E00F2.initialDeclarations preserve=yes
  //## end XCOExceptionCleanup%3BA6498E00F2.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionCleanup%1000752296
      XCOExceptionCleanup (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XCOExceptionCleanup%1000752306
      XCOExceptionCleanup (XCOException* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionCleanup();

    // Additional Public Declarations
      //## begin XCOExceptionCleanup%3BA6498E00F2.public preserve=yes
      //## end XCOExceptionCleanup%3BA6498E00F2.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionCleanup%3BA6498E00F2.protected preserve=yes
      //## end XCOExceptionCleanup%3BA6498E00F2.protected

  private:
    //## Constructors (generated)
      XCOExceptionCleanup();

      XCOExceptionCleanup(const XCOExceptionCleanup &right);

    //## Assignment Operation (generated)
      const XCOExceptionCleanup & operator=(const XCOExceptionCleanup &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionCleanup &right) const;

      bool operator!=(const XCOExceptionCleanup &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionCleanup%3BA6498E00F2.private preserve=yes
      //## end XCOExceptionCleanup%3BA6498E00F2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionCleanup%3BA6498E00F2.implementation preserve=yes
      //## end XCOExceptionCleanup%3BA6498E00F2.implementation

};

//## begin XCOExceptionCleanup%3BA6498E00F2.postscript preserve=yes
//## end XCOExceptionCleanup%3BA6498E00F2.postscript

//## begin XCOExceptionError%3BA649E20099.preface preserve=yes
//## end XCOExceptionError%3BA649E20099.preface

//## Class: XCOExceptionError%3BA649E20099
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionError : public XCOException  //## Inherits: <unnamed>%3BA64A400261
{
  //## begin XCOExceptionError%3BA649E20099.initialDeclarations preserve=yes
  //## end XCOExceptionError%3BA649E20099.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionError%1000752297
      XCOExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText = _T(""));

      //## Operation: XCOExceptionError%1043748200
      XCOExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XCOExceptionError%1001060427
      XCOExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionError();

    // Additional Public Declarations
      //## begin XCOExceptionError%3BA649E20099.public preserve=yes
      //## end XCOExceptionError%3BA649E20099.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionError%3BA649E20099.protected preserve=yes
      //## end XCOExceptionError%3BA649E20099.protected

  private:
    //## Constructors (generated)
      XCOExceptionError();

      XCOExceptionError(const XCOExceptionError &right);

    //## Assignment Operation (generated)
      const XCOExceptionError & operator=(const XCOExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionError &right) const;

      bool operator!=(const XCOExceptionError &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionError%3BA649E20099.private preserve=yes
      //## end XCOExceptionError%3BA649E20099.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionError%3BA649E20099.implementation preserve=yes
      //## end XCOExceptionError%3BA649E20099.implementation

};

//## begin XCOExceptionError%3BA649E20099.postscript preserve=yes
//## end XCOExceptionError%3BA649E20099.postscript

//## begin XCOExceptionCleanupInitialize%3BA64A6701EF.preface preserve=yes
//## end XCOExceptionCleanupInitialize%3BA64A6701EF.preface

//## Class: XCOExceptionCleanupInitialize%3BA64A6701EF
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionCleanupInitialize : public XCOExceptionCleanup  //## Inherits: <unnamed>%3BA64AD603B1
{
  //## begin XCOExceptionCleanupInitialize%3BA64A6701EF.initialDeclarations preserve=yes
  //## end XCOExceptionCleanupInitialize%3BA64A6701EF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionCleanupInitialize%1000752298
      XCOExceptionCleanupInitialize (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XCOExceptionCleanupInitialize%1000752299
      XCOExceptionCleanupInitialize (XCOException* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionCleanupInitialize();


    //## Other Operations (specified)
      //## Operation: Throw%1000752300
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1000752301
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XCOExceptionCleanupInitialize%3BA64A6701EF.public preserve=yes
      //## end XCOExceptionCleanupInitialize%3BA64A6701EF.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionCleanupInitialize%3BA64A6701EF.protected preserve=yes
      //## end XCOExceptionCleanupInitialize%3BA64A6701EF.protected

  private:
    //## Constructors (generated)
      XCOExceptionCleanupInitialize();

      XCOExceptionCleanupInitialize(const XCOExceptionCleanupInitialize &right);

    //## Assignment Operation (generated)
      const XCOExceptionCleanupInitialize & operator=(const XCOExceptionCleanupInitialize &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionCleanupInitialize &right) const;

      bool operator!=(const XCOExceptionCleanupInitialize &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionCleanupInitialize%3BA64A6701EF.private preserve=yes
      //## end XCOExceptionCleanupInitialize%3BA64A6701EF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionCleanupInitialize%3BA64A6701EF.implementation preserve=yes
      //## end XCOExceptionCleanupInitialize%3BA64A6701EF.implementation

};

//## begin XCOExceptionCleanupInitialize%3BA64A6701EF.postscript preserve=yes
//## end XCOExceptionCleanupInitialize%3BA64A6701EF.postscript

//## begin XCOExceptionCleanupStop%3BA64A9E01C6.preface preserve=yes
//## end XCOExceptionCleanupStop%3BA64A9E01C6.preface

//## Class: XCOExceptionCleanupStop%3BA64A9E01C6
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionCleanupStop : public XCOExceptionCleanup  //## Inherits: <unnamed>%3BA64AD80364
{
  //## begin XCOExceptionCleanupStop%3BA64A9E01C6.initialDeclarations preserve=yes
  //## end XCOExceptionCleanupStop%3BA64A9E01C6.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionCleanupStop%1000752302
      XCOExceptionCleanupStop (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XCOExceptionCleanupStop%1000752303
      XCOExceptionCleanupStop (XCOException* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionCleanupStop();


    //## Other Operations (specified)
      //## Operation: Throw%1000752304
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1000752305
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XCOExceptionCleanupStop%3BA64A9E01C6.public preserve=yes
      //## end XCOExceptionCleanupStop%3BA64A9E01C6.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionCleanupStop%3BA64A9E01C6.protected preserve=yes
      //## end XCOExceptionCleanupStop%3BA64A9E01C6.protected

  private:
    //## Constructors (generated)
      XCOExceptionCleanupStop();

      XCOExceptionCleanupStop(const XCOExceptionCleanupStop &right);

    //## Assignment Operation (generated)
      const XCOExceptionCleanupStop & operator=(const XCOExceptionCleanupStop &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionCleanupStop &right) const;

      bool operator!=(const XCOExceptionCleanupStop &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionCleanupStop%3BA64A9E01C6.private preserve=yes
      //## end XCOExceptionCleanupStop%3BA64A9E01C6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionCleanupStop%3BA64A9E01C6.implementation preserve=yes
      //## end XCOExceptionCleanupStop%3BA64A9E01C6.implementation

};

//## begin XCOExceptionCleanupStop%3BA64A9E01C6.postscript preserve=yes
//## end XCOExceptionCleanupStop%3BA64A9E01C6.postscript

//## begin XCOExceptionErrorNative%3BAE269E03CD.preface preserve=yes
//## end XCOExceptionErrorNative%3BAE269E03CD.preface

//## Class: XCOExceptionErrorNative%3BAE269E03CD
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XCOExceptionErrorNative : public XCOExceptionError  //## Inherits: <unnamed>%3BAE26C40165
{
  //## begin XCOExceptionErrorNative%3BAE269E03CD.initialDeclarations preserve=yes
  //## end XCOExceptionErrorNative%3BAE269E03CD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionErrorNative%1001268501
      XCOExceptionErrorNative (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText);

      //## Operation: XCOExceptionErrorNative%1001268502
      XCOExceptionErrorNative (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionErrorNative();


    //## Other Operations (specified)
      //## Operation: Throw%1001268503
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1001268504
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XCOExceptionErrorNative%3BAE269E03CD.public preserve=yes
      //## end XCOExceptionErrorNative%3BAE269E03CD.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionErrorNative%3BAE269E03CD.protected preserve=yes
      //## end XCOExceptionErrorNative%3BAE269E03CD.protected

  private:
    //## Constructors (generated)
      XCOExceptionErrorNative();

      XCOExceptionErrorNative(const XCOExceptionErrorNative &right);

    //## Assignment Operation (generated)
      const XCOExceptionErrorNative & operator=(const XCOExceptionErrorNative &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionErrorNative &right) const;

      bool operator!=(const XCOExceptionErrorNative &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionErrorNative%3BAE269E03CD.private preserve=yes
      //## end XCOExceptionErrorNative%3BAE269E03CD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionErrorNative%3BAE269E03CD.implementation preserve=yes
      //## end XCOExceptionErrorNative%3BAE269E03CD.implementation

};

//## begin XCOExceptionErrorNative%3BAE269E03CD.postscript preserve=yes
//## end XCOExceptionErrorNative%3BAE269E03CD.postscript

//## begin XCOExceptionErrorMemoryAllocation%40642D890119.preface preserve=yes
//## end XCOExceptionErrorMemoryAllocation%40642D890119.preface

//## Class: XCOExceptionErrorMemoryAllocation%40642D890119
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionErrorMemoryAllocation : public XCOExceptionError  //## Inherits: <unnamed>%40642DA10222
{
  //## begin XCOExceptionErrorMemoryAllocation%40642D890119.initialDeclarations preserve=yes
  //## end XCOExceptionErrorMemoryAllocation%40642D890119.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionErrorMemoryAllocation%1080293051
      XCOExceptionErrorMemoryAllocation (const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XCOExceptionErrorMemoryAllocation%1080293052
      XCOExceptionErrorMemoryAllocation (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionErrorMemoryAllocation();


    //## Other Operations (specified)
      //## Operation: Throw%1080293053
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1080293054
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XCOExceptionErrorMemoryAllocation%40642D890119.public preserve=yes
      //## end XCOExceptionErrorMemoryAllocation%40642D890119.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionErrorMemoryAllocation%40642D890119.protected preserve=yes
      //## end XCOExceptionErrorMemoryAllocation%40642D890119.protected

  private:
    //## Constructors (generated)
      XCOExceptionErrorMemoryAllocation();

      XCOExceptionErrorMemoryAllocation(const XCOExceptionErrorMemoryAllocation &right);

    //## Assignment Operation (generated)
      const XCOExceptionErrorMemoryAllocation & operator=(const XCOExceptionErrorMemoryAllocation &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionErrorMemoryAllocation &right) const;

      bool operator!=(const XCOExceptionErrorMemoryAllocation &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionErrorMemoryAllocation%40642D890119.private preserve=yes
      //## end XCOExceptionErrorMemoryAllocation%40642D890119.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionErrorMemoryAllocation%40642D890119.implementation preserve=yes
      //## end XCOExceptionErrorMemoryAllocation%40642D890119.implementation

};

//## begin XCOExceptionErrorMemoryAllocation%40642D890119.postscript preserve=yes
//## end XCOExceptionErrorMemoryAllocation%40642D890119.postscript

//## begin XCOExceptionErrorTimeout%409B7ECF02F4.preface preserve=yes
//## end XCOExceptionErrorTimeout%409B7ECF02F4.preface

//## Class: XCOExceptionErrorTimeout%409B7ECF02F4
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionErrorTimeout : public XCOExceptionError  //## Inherits: <unnamed>%409B7F0D02DF
{
  //## begin XCOExceptionErrorTimeout%409B7ECF02F4.initialDeclarations preserve=yes
  //## end XCOExceptionErrorTimeout%409B7ECF02F4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionErrorTimeout%1083932475
      XCOExceptionErrorTimeout (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XCOExceptionErrorTimeout%1083932476
      XCOExceptionErrorTimeout (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionErrorTimeout();


    //## Other Operations (specified)
      //## Operation: Throw%1083932477
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1083932478
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XCOExceptionErrorTimeout%409B7ECF02F4.public preserve=yes
      //## end XCOExceptionErrorTimeout%409B7ECF02F4.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionErrorTimeout%409B7ECF02F4.protected preserve=yes
      //## end XCOExceptionErrorTimeout%409B7ECF02F4.protected

  private:
    //## Constructors (generated)
      XCOExceptionErrorTimeout();

      XCOExceptionErrorTimeout(const XCOExceptionErrorTimeout &right);

    //## Assignment Operation (generated)
      const XCOExceptionErrorTimeout & operator=(const XCOExceptionErrorTimeout &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionErrorTimeout &right) const;

      bool operator!=(const XCOExceptionErrorTimeout &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionErrorTimeout%409B7ECF02F4.private preserve=yes
      //## end XCOExceptionErrorTimeout%409B7ECF02F4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionErrorTimeout%409B7ECF02F4.implementation preserve=yes
      //## end XCOExceptionErrorTimeout%409B7ECF02F4.implementation

};

//## begin XCOExceptionErrorTimeout%409B7ECF02F4.postscript preserve=yes
//## end XCOExceptionErrorTimeout%409B7ECF02F4.postscript

//## begin XCOExceptionCellUndocked%417FAE9300FE.preface preserve=yes
//## end XCOExceptionCellUndocked%417FAE9300FE.preface

//## Class: XCOExceptionCellUndocked%417FAE9300FE
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL XCOExceptionCellUndocked : public XCOExceptionError  //## Inherits: <unnamed>%417FAEA2007D
{
  //## begin XCOExceptionCellUndocked%417FAE9300FE.initialDeclarations preserve=yes
  //## end XCOExceptionCellUndocked%417FAE9300FE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XCOExceptionCellUndocked%1098886885
      XCOExceptionCellUndocked (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine);

      //## Operation: XCOExceptionCellUndocked%1098886886
      XCOExceptionCellUndocked (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XCOExceptionCellUndocked();


    //## Other Operations (specified)
      //## Operation: Throw%1098886887
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1098886888
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XCOExceptionCellUndocked%417FAE9300FE.public preserve=yes
      //## end XCOExceptionCellUndocked%417FAE9300FE.public

  protected:
    // Additional Protected Declarations
      //## begin XCOExceptionCellUndocked%417FAE9300FE.protected preserve=yes
      //## end XCOExceptionCellUndocked%417FAE9300FE.protected

  private:
    //## Constructors (generated)
      XCOExceptionCellUndocked();

      XCOExceptionCellUndocked(const XCOExceptionCellUndocked &right);

    //## Assignment Operation (generated)
      const XCOExceptionCellUndocked & operator=(const XCOExceptionCellUndocked &right);

    //## Equality Operations (generated)
      bool operator==(const XCOExceptionCellUndocked &right) const;

      bool operator!=(const XCOExceptionCellUndocked &right) const;

    // Additional Private Declarations
      //## begin XCOExceptionCellUndocked%417FAE9300FE.private preserve=yes
      //## end XCOExceptionCellUndocked%417FAE9300FE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XCOExceptionCellUndocked%417FAE9300FE.implementation preserve=yes
      //## end XCOExceptionCellUndocked%417FAE9300FE.implementation

};

//## begin XCOExceptionCellUndocked%417FAE9300FE.postscript preserve=yes
//## end XCOExceptionCellUndocked%417FAE9300FE.postscript

// Class XCOException 

// Class XCOExceptionInvalidState 

// Class XCOExceptionCleanup 

// Class XCOExceptionError 

// Class XCOExceptionCleanupInitialize 

// Class XCOExceptionCleanupStop 

// Class XCOExceptionErrorNative 

// Class XCOExceptionErrorMemoryAllocation 

// Class XCOExceptionErrorTimeout 

// Class XCOExceptionCellUndocked 

//## begin module%3B8D591101F9.epilog preserve=yes
//## end module%3B8D591101F9.epilog


#endif
