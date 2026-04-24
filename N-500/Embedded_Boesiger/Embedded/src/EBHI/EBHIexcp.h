//## begin module%3E364B2F0177.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E364B2F0177.cm

//## begin module%3E364B2F0177.cp preserve=no
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
//## end module%3E364B2F0177.cp

//## Module: EBHIexcp%3E364B2F0177; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIexcp.h

#ifndef EBHIexcp_h
#define EBHIexcp_h 1

//## begin module%3E364B2F0177.additionalIncludes preserve=no
//## end module%3E364B2F0177.additionalIncludes

//## begin module%3E364B2F0177.includes preserve=yes
//## end module%3E364B2F0177.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3E364B2F0177.declarations preserve=no
//## end module%3E364B2F0177.declarations

//## begin module%3E364B2F0177.additionalDeclarations preserve=yes
//## end module%3E364B2F0177.additionalDeclarations


//## begin XHIExceptionError%3E364C4A0148.preface preserve=yes
//## end XHIExceptionError%3E364C4A0148.preface

//## Class: XHIExceptionError%3E364C4A0148
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XHIExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3E364C7E02BF
{
  //## begin XHIExceptionError%3E364C4A0148.initialDeclarations preserve=yes
  //## end XHIExceptionError%3E364C4A0148.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XHIExceptionError%1043738360
      XHIExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XHIExceptionError%1043738361
      XHIExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XHIExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1043738362
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1043738363
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XHIExceptionError%3E364C4A0148.public preserve=yes
      //## end XHIExceptionError%3E364C4A0148.public

  protected:
    // Additional Protected Declarations
      //## begin XHIExceptionError%3E364C4A0148.protected preserve=yes
      //## end XHIExceptionError%3E364C4A0148.protected

  private:
    //## Constructors (generated)
      XHIExceptionError();

      XHIExceptionError(const XHIExceptionError &right);

    //## Assignment Operation (generated)
      const XHIExceptionError & operator=(const XHIExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XHIExceptionError &right) const;

      bool operator!=(const XHIExceptionError &right) const;

    // Additional Private Declarations
      //## begin XHIExceptionError%3E364C4A0148.private preserve=yes
      //## end XHIExceptionError%3E364C4A0148.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XHIExceptionError%3E364C4A0148.implementation preserve=yes
      //## end XHIExceptionError%3E364C4A0148.implementation

};

//## begin XHIExceptionError%3E364C4A0148.postscript preserve=yes
//## end XHIExceptionError%3E364C4A0148.postscript

//## begin XHIHardwareExceptionError%3ECDDF21005D.preface preserve=yes
//## end XHIHardwareExceptionError%3ECDDF21005D.preface

//## Class: XHIHardwareExceptionError%3ECDDF21005D
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XHIHardwareExceptionError : public XHIExceptionError  //## Inherits: <unnamed>%3ECDDF320261
{
  //## begin XHIHardwareExceptionError%3ECDDF21005D.initialDeclarations preserve=yes
  //## end XHIHardwareExceptionError%3ECDDF21005D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XHIHardwareExceptionError%1053679531
      XHIHardwareExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, CArray <DWORD,DWORD>* p_pdwExceptionArray);

      //## Operation: XHIHardwareExceptionError%1053679532
      XHIHardwareExceptionError (XHIHardwareExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XHIHardwareExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1053679533
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1053679534
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: pdwExceptionArray%3ECDEADF030D
      const CArray <DWORD,DWORD>* GetpdwExceptionArray () const;

    // Additional Public Declarations
      //## begin XHIHardwareExceptionError%3ECDDF21005D.public preserve=yes
      //## end XHIHardwareExceptionError%3ECDDF21005D.public

  protected:
    // Additional Protected Declarations
      //## begin XHIHardwareExceptionError%3ECDDF21005D.protected preserve=yes
      //## end XHIHardwareExceptionError%3ECDDF21005D.protected

  private:
    //## Constructors (generated)
      XHIHardwareExceptionError();

      XHIHardwareExceptionError(const XHIHardwareExceptionError &right);

    //## Assignment Operation (generated)
      const XHIHardwareExceptionError & operator=(const XHIHardwareExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XHIHardwareExceptionError &right) const;

      bool operator!=(const XHIHardwareExceptionError &right) const;

    // Data Members for Class Attributes

      //## begin XHIHardwareExceptionError::pdwExceptionArray%3ECDEADF030D.attr preserve=no  public: CArray <DWORD,DWORD>* {U} 
      CArray <DWORD,DWORD>* m_pdwExceptionArray;
      //## end XHIHardwareExceptionError::pdwExceptionArray%3ECDEADF030D.attr

    // Additional Private Declarations
      //## begin XHIHardwareExceptionError%3ECDDF21005D.private preserve=yes
      //## end XHIHardwareExceptionError%3ECDDF21005D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XHIHardwareExceptionError%3ECDDF21005D.implementation preserve=yes
      //## end XHIHardwareExceptionError%3ECDDF21005D.implementation

};

//## begin XHIHardwareExceptionError%3ECDDF21005D.postscript preserve=yes
//## end XHIHardwareExceptionError%3ECDDF21005D.postscript

// Class XHIExceptionError 

// Class XHIHardwareExceptionError 

//## begin module%3E364B2F0177.epilog preserve=yes
//## end module%3E364B2F0177.epilog


#endif
