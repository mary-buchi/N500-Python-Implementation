//## begin module%3EED769F03B2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F03B2.cm

//## begin module%3EED769F03B2.cp preserve=no
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
//## end module%3EED769F03B2.cp

//## Module: EBPCexcp%3EED769F03B2; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCexcp.h

#ifndef EBPCexcp_h
#define EBPCexcp_h 1

//## begin module%3EED769F03B2.additionalIncludes preserve=no
//## end module%3EED769F03B2.additionalIncludes

//## begin module%3EED769F03B2.includes preserve=yes
//## end module%3EED769F03B2.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3EED769F03B2.declarations preserve=no
//## end module%3EED769F03B2.declarations

//## begin module%3EED769F03B2.additionalDeclarations preserve=yes
//## end module%3EED769F03B2.additionalDeclarations


//## begin XPCExceptionError%3EED76CC0808.preface preserve=yes
//## end XPCExceptionError%3EED76CC0808.preface

//## Class: XPCExceptionError%3EED76CC0808
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPCExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3EED8EFF0262
{
  //## begin XPCExceptionError%3EED76CC0808.initialDeclarations preserve=yes
  //## end XPCExceptionError%3EED76CC0808.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPCExceptionError%1055484806
      XPCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPCExceptionError%1055484807
      XPCExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPCExceptionError();

    // Additional Public Declarations
      //## begin XPCExceptionError%3EED76CC0808.public preserve=yes
      //## end XPCExceptionError%3EED76CC0808.public

  protected:
    // Additional Protected Declarations
      //## begin XPCExceptionError%3EED76CC0808.protected preserve=yes
      //## end XPCExceptionError%3EED76CC0808.protected

  private:
    //## Constructors (generated)
      XPCExceptionError(const XPCExceptionError &right);

    //## Assignment Operation (generated)
      const XPCExceptionError & operator=(const XPCExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XPCExceptionError &right) const;

      bool operator!=(const XPCExceptionError &right) const;

    // Additional Private Declarations
      //## begin XPCExceptionError%3EED76CC0808.private preserve=yes
      //## end XPCExceptionError%3EED76CC0808.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPCExceptionError%3EED76CC0808.implementation preserve=yes
      //## end XPCExceptionError%3EED76CC0808.implementation

};

//## begin XPCExceptionError%3EED76CC0808.postscript preserve=yes
//## end XPCExceptionError%3EED76CC0808.postscript

//## begin XPCExceptionErrorShorted%3EED76CC082A.preface preserve=yes
//## end XPCExceptionErrorShorted%3EED76CC082A.preface

//## Class: XPCExceptionErrorShorted%3EED76CC082A
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPCExceptionErrorShorted : public XPCExceptionError  //## Inherits: <unnamed>%3EED76CC082C
{
  //## begin XPCExceptionErrorShorted%3EED76CC082A.initialDeclarations preserve=yes
  //## end XPCExceptionErrorShorted%3EED76CC082A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPCExceptionErrorShorted%1055484810
      XPCExceptionErrorShorted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPCExceptionErrorShorted%1055484811
      XPCExceptionErrorShorted (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPCExceptionErrorShorted();


    //## Other Operations (specified)
      //## Operation: Throw%1055484812
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055484813
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPCExceptionErrorShorted%3EED76CC082A.public preserve=yes
      //## end XPCExceptionErrorShorted%3EED76CC082A.public

  protected:
    // Additional Protected Declarations
      //## begin XPCExceptionErrorShorted%3EED76CC082A.protected preserve=yes
      //## end XPCExceptionErrorShorted%3EED76CC082A.protected

  private:
    //## Constructors (generated)
      XPCExceptionErrorShorted(const XPCExceptionErrorShorted &right);

    //## Assignment Operation (generated)
      const XPCExceptionErrorShorted & operator=(const XPCExceptionErrorShorted &right);

    //## Equality Operations (generated)
      bool operator==(const XPCExceptionErrorShorted &right) const;

      bool operator!=(const XPCExceptionErrorShorted &right) const;

    // Additional Private Declarations
      //## begin XPCExceptionErrorShorted%3EED76CC082A.private preserve=yes
      //## end XPCExceptionErrorShorted%3EED76CC082A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPCExceptionErrorShorted%3EED76CC082A.implementation preserve=yes
      //## end XPCExceptionErrorShorted%3EED76CC082A.implementation

};

//## begin XPCExceptionErrorShorted%3EED76CC082A.postscript preserve=yes
//## end XPCExceptionErrorShorted%3EED76CC082A.postscript

//## begin XPCExceptionErrorInterrupted%3EEF09F200AB.preface preserve=yes
//## end XPCExceptionErrorInterrupted%3EEF09F200AB.preface

//## Class: XPCExceptionErrorInterrupted%3EEF09F200AB
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPCExceptionErrorInterrupted : public XPCExceptionError  //## Inherits: <unnamed>%3EEF0A150399
{
  //## begin XPCExceptionErrorInterrupted%3EEF09F200AB.initialDeclarations preserve=yes
  //## end XPCExceptionErrorInterrupted%3EEF09F200AB.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPCExceptionErrorInterrupted%1055833080
      XPCExceptionErrorInterrupted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPCExceptionErrorInterrupted%1055833081
      XPCExceptionErrorInterrupted (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPCExceptionErrorInterrupted();


    //## Other Operations (specified)
      //## Operation: Throw%1055833082
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055833083
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPCExceptionErrorInterrupted%3EEF09F200AB.public preserve=yes
      //## end XPCExceptionErrorInterrupted%3EEF09F200AB.public

  protected:
    // Additional Protected Declarations
      //## begin XPCExceptionErrorInterrupted%3EEF09F200AB.protected preserve=yes
      //## end XPCExceptionErrorInterrupted%3EEF09F200AB.protected

  private:
    //## Constructors (generated)
      XPCExceptionErrorInterrupted(const XPCExceptionErrorInterrupted &right);

    //## Assignment Operation (generated)
      const XPCExceptionErrorInterrupted & operator=(const XPCExceptionErrorInterrupted &right);

    //## Equality Operations (generated)
      bool operator==(const XPCExceptionErrorInterrupted &right) const;

      bool operator!=(const XPCExceptionErrorInterrupted &right) const;

    // Additional Private Declarations
      //## begin XPCExceptionErrorInterrupted%3EEF09F200AB.private preserve=yes
      //## end XPCExceptionErrorInterrupted%3EEF09F200AB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPCExceptionErrorInterrupted%3EEF09F200AB.implementation preserve=yes
      //## end XPCExceptionErrorInterrupted%3EEF09F200AB.implementation

};

//## begin XPCExceptionErrorInterrupted%3EEF09F200AB.postscript preserve=yes
//## end XPCExceptionErrorInterrupted%3EEF09F200AB.postscript

//## begin XPCExceptionErrorSettlingTime%4035D7C50130.preface preserve=yes
//## end XPCExceptionErrorSettlingTime%4035D7C50130.preface

//## Class: XPCExceptionErrorSettlingTime%4035D7C50130
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XPCExceptionErrorSettlingTime : public XPCExceptionError  //## Inherits: <unnamed>%4035D7D80324
{
  //## begin XPCExceptionErrorSettlingTime%4035D7C50130.initialDeclarations preserve=yes
  //## end XPCExceptionErrorSettlingTime%4035D7C50130.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XPCExceptionErrorSettlingTime%1077262884
      XPCExceptionErrorSettlingTime (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XPCExceptionErrorSettlingTime%1077262885
      XPCExceptionErrorSettlingTime (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XPCExceptionErrorSettlingTime();


    //## Other Operations (specified)
      //## Operation: Throw%1077262886
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1077262887
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XPCExceptionErrorSettlingTime%4035D7C50130.public preserve=yes
      //## end XPCExceptionErrorSettlingTime%4035D7C50130.public

  protected:
    // Additional Protected Declarations
      //## begin XPCExceptionErrorSettlingTime%4035D7C50130.protected preserve=yes
      //## end XPCExceptionErrorSettlingTime%4035D7C50130.protected

  private:
    //## Constructors (generated)
      XPCExceptionErrorSettlingTime(const XPCExceptionErrorSettlingTime &right);

    //## Assignment Operation (generated)
      const XPCExceptionErrorSettlingTime & operator=(const XPCExceptionErrorSettlingTime &right);

    //## Equality Operations (generated)
      bool operator==(const XPCExceptionErrorSettlingTime &right) const;

      bool operator!=(const XPCExceptionErrorSettlingTime &right) const;

    // Additional Private Declarations
      //## begin XPCExceptionErrorSettlingTime%4035D7C50130.private preserve=yes
      //## end XPCExceptionErrorSettlingTime%4035D7C50130.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XPCExceptionErrorSettlingTime%4035D7C50130.implementation preserve=yes
      //## end XPCExceptionErrorSettlingTime%4035D7C50130.implementation

};

//## begin XPCExceptionErrorSettlingTime%4035D7C50130.postscript preserve=yes
//## end XPCExceptionErrorSettlingTime%4035D7C50130.postscript

// Class XPCExceptionError 

// Class XPCExceptionErrorShorted 

// Class XPCExceptionErrorInterrupted 

// Class XPCExceptionErrorSettlingTime 

//## begin module%3EED769F03B2.epilog preserve=yes
//## end module%3EED769F03B2.epilog


#endif
