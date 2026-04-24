//## begin module%3ECA3D3F0208.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ECA3D3F0208.cm

//## begin module%3ECA3D3F0208.cp preserve=no
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
//## end module%3ECA3D3F0208.cp

//## Module: EBSTexcp%3ECA3D3F0208; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTexcp.h

#ifndef EBSTexcp_h
#define EBSTexcp_h 1

//## begin module%3ECA3D3F0208.additionalIncludes preserve=no
//## end module%3ECA3D3F0208.additionalIncludes

//## begin module%3ECA3D3F0208.includes preserve=yes
//## end module%3ECA3D3F0208.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3ECA3D3F0208.declarations preserve=no
//## end module%3ECA3D3F0208.declarations

//## begin module%3ECA3D3F0208.additionalDeclarations preserve=yes
//## end module%3ECA3D3F0208.additionalDeclarations


//## begin XSTExceptionError%3ECA418D01E9.preface preserve=yes
//## end XSTExceptionError%3ECA418D01E9.preface

//## Class: XSTExceptionError%3ECA418D01E9
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3ECB49DB007D
{
  //## begin XSTExceptionError%3ECA418D01E9.initialDeclarations preserve=yes
  //## end XSTExceptionError%3ECA418D01E9.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionError%1053507529
      XSTExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionError%1053507530
      XSTExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionError();


    //## Other Operations (specified)
      //## Operation: Throw%1053507531
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1053507532
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionError%3ECA418D01E9.public preserve=yes
      //## end XSTExceptionError%3ECA418D01E9.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionError%3ECA418D01E9.protected preserve=yes
      //## end XSTExceptionError%3ECA418D01E9.protected

  private:
    //## Constructors (generated)
      XSTExceptionError(const XSTExceptionError &right);

    //## Assignment Operation (generated)
      const XSTExceptionError & operator=(const XSTExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionError &right) const;

      bool operator!=(const XSTExceptionError &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionError%3ECA418D01E9.private preserve=yes
      //## end XSTExceptionError%3ECA418D01E9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionError%3ECA418D01E9.implementation preserve=yes
      //## end XSTExceptionError%3ECA418D01E9.implementation

};

//## begin XSTExceptionError%3ECA418D01E9.postscript preserve=yes
//## end XSTExceptionError%3ECA418D01E9.postscript

//## begin XSTExceptionLimit%3ECB4CBF01A5.preface preserve=yes
//## end XSTExceptionLimit%3ECB4CBF01A5.preface

//## Class: XSTExceptionLimit%3ECB4CBF01A5
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionLimit : public XCOExceptionError  //## Inherits: <unnamed>%3ECB4CD1034B
{
  //## begin XSTExceptionLimit%3ECB4CBF01A5.initialDeclarations preserve=yes
  //## end XSTExceptionLimit%3ECB4CBF01A5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionLimit%1053507534
      XSTExceptionLimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionLimit%1053507535
      XSTExceptionLimit (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionLimit();


    //## Other Operations (specified)
      //## Operation: Throw%1053507536
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1053507537
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionLimit%3ECB4CBF01A5.public preserve=yes
      //## end XSTExceptionLimit%3ECB4CBF01A5.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionLimit%3ECB4CBF01A5.protected preserve=yes
      //## end XSTExceptionLimit%3ECB4CBF01A5.protected

  private:
    //## Constructors (generated)
      XSTExceptionLimit(const XSTExceptionLimit &right);

    //## Assignment Operation (generated)
      const XSTExceptionLimit & operator=(const XSTExceptionLimit &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionLimit &right) const;

      bool operator!=(const XSTExceptionLimit &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionLimit%3ECB4CBF01A5.private preserve=yes
      //## end XSTExceptionLimit%3ECB4CBF01A5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionLimit%3ECB4CBF01A5.implementation preserve=yes
      //## end XSTExceptionLimit%3ECB4CBF01A5.implementation

};

//## begin XSTExceptionLimit%3ECB4CBF01A5.postscript preserve=yes
//## end XSTExceptionLimit%3ECB4CBF01A5.postscript

//## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.preface preserve=yes
//## end XSTExceptionSoftLimitHit%3EED7D4F02EF.preface

//## Class: XSTExceptionSoftLimitHit%3EED7D4F02EF
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionSoftLimitHit : public XSTExceptionLimit  //## Inherits: <unnamed>%3EED7E2F0159
{
  //## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.initialDeclarations preserve=yes
  //## end XSTExceptionSoftLimitHit%3EED7D4F02EF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionSoftLimitHit%1055751813
      XSTExceptionSoftLimitHit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionSoftLimitHit%1055751814
      XSTExceptionSoftLimitHit (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionSoftLimitHit();


    //## Other Operations (specified)
      //## Operation: Throw%1055751815
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055751816
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.public preserve=yes
      //## end XSTExceptionSoftLimitHit%3EED7D4F02EF.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.protected preserve=yes
      //## end XSTExceptionSoftLimitHit%3EED7D4F02EF.protected

  private:
    //## Constructors (generated)
      XSTExceptionSoftLimitHit(const XSTExceptionSoftLimitHit &right);

    //## Assignment Operation (generated)
      const XSTExceptionSoftLimitHit & operator=(const XSTExceptionSoftLimitHit &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionSoftLimitHit &right) const;

      bool operator!=(const XSTExceptionSoftLimitHit &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.private preserve=yes
      //## end XSTExceptionSoftLimitHit%3EED7D4F02EF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.implementation preserve=yes
      //## end XSTExceptionSoftLimitHit%3EED7D4F02EF.implementation

};

//## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.postscript preserve=yes
//## end XSTExceptionSoftLimitHit%3EED7D4F02EF.postscript

//## begin XSTExceptionErrorStepsDeviation%3F826BA90341.preface preserve=yes
//## end XSTExceptionErrorStepsDeviation%3F826BA90341.preface

//## Class: XSTExceptionErrorStepsDeviation%3F826BA90341
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionErrorStepsDeviation : public XSTExceptionError  //## Inherits: <unnamed>%3F826BDD0295
{
  //## begin XSTExceptionErrorStepsDeviation%3F826BA90341.initialDeclarations preserve=yes
  //## end XSTExceptionErrorStepsDeviation%3F826BA90341.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionErrorStepsDeviation%1065511409
      XSTExceptionErrorStepsDeviation (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionErrorStepsDeviation%1065511410
      XSTExceptionErrorStepsDeviation (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionErrorStepsDeviation();


    //## Other Operations (specified)
      //## Operation: Throw%1065511411
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1065511412
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionErrorStepsDeviation%3F826BA90341.public preserve=yes
      //## end XSTExceptionErrorStepsDeviation%3F826BA90341.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionErrorStepsDeviation%3F826BA90341.protected preserve=yes
      //## end XSTExceptionErrorStepsDeviation%3F826BA90341.protected

  private:
    //## Constructors (generated)
      XSTExceptionErrorStepsDeviation(const XSTExceptionErrorStepsDeviation &right);

    //## Assignment Operation (generated)
      const XSTExceptionErrorStepsDeviation & operator=(const XSTExceptionErrorStepsDeviation &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionErrorStepsDeviation &right) const;

      bool operator!=(const XSTExceptionErrorStepsDeviation &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionErrorStepsDeviation%3F826BA90341.private preserve=yes
      //## end XSTExceptionErrorStepsDeviation%3F826BA90341.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionErrorStepsDeviation%3F826BA90341.implementation preserve=yes
      //## end XSTExceptionErrorStepsDeviation%3F826BA90341.implementation

};

//## begin XSTExceptionErrorStepsDeviation%3F826BA90341.postscript preserve=yes
//## end XSTExceptionErrorStepsDeviation%3F826BA90341.postscript

//## begin XSTExceptionHoming%3F8A5FEF0269.preface preserve=yes
//## end XSTExceptionHoming%3F8A5FEF0269.preface

//## Class: XSTExceptionHoming%3F8A5FEF0269
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionHoming : public XCOExceptionError  //## Inherits: <unnamed>%3F8A6003015F
{
  //## begin XSTExceptionHoming%3F8A5FEF0269.initialDeclarations preserve=yes
  //## end XSTExceptionHoming%3F8A5FEF0269.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionHoming%1066031269
      XSTExceptionHoming (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionHoming%1066031270
      XSTExceptionHoming (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionHoming();


    //## Other Operations (specified)
      //## Operation: Throw%1066031271
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1066031272
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionHoming%3F8A5FEF0269.public preserve=yes
      //## end XSTExceptionHoming%3F8A5FEF0269.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionHoming%3F8A5FEF0269.protected preserve=yes
      //## end XSTExceptionHoming%3F8A5FEF0269.protected

  private:
    //## Constructors (generated)
      XSTExceptionHoming(const XSTExceptionHoming &right);

    //## Assignment Operation (generated)
      const XSTExceptionHoming & operator=(const XSTExceptionHoming &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionHoming &right) const;

      bool operator!=(const XSTExceptionHoming &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionHoming%3F8A5FEF0269.private preserve=yes
      //## end XSTExceptionHoming%3F8A5FEF0269.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionHoming%3F8A5FEF0269.implementation preserve=yes
      //## end XSTExceptionHoming%3F8A5FEF0269.implementation

};

//## begin XSTExceptionHoming%3F8A5FEF0269.postscript preserve=yes
//## end XSTExceptionHoming%3F8A5FEF0269.postscript

//## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.preface preserve=yes
//## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.preface

//## Class: XSTExcepitonHomingSensorNotFound%3F8A6008018E
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExcepitonHomingSensorNotFound : public XSTExceptionHoming  //## Inherits: <unnamed>%3F8A62FA02F5
{
  //## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.initialDeclarations preserve=yes
  //## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExcepitonHomingSensorNotFound%1066031273
      XSTExcepitonHomingSensorNotFound (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExcepitonHomingSensorNotFound%1066031274
      XSTExcepitonHomingSensorNotFound (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExcepitonHomingSensorNotFound();


    //## Other Operations (specified)
      //## Operation: Throw%1066031275
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1066031276
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.public preserve=yes
      //## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.protected preserve=yes
      //## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.protected

  private:
    //## Constructors (generated)
      XSTExcepitonHomingSensorNotFound(const XSTExcepitonHomingSensorNotFound &right);

    //## Assignment Operation (generated)
      const XSTExcepitonHomingSensorNotFound & operator=(const XSTExcepitonHomingSensorNotFound &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExcepitonHomingSensorNotFound &right) const;

      bool operator!=(const XSTExcepitonHomingSensorNotFound &right) const;

    // Additional Private Declarations
      //## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.private preserve=yes
      //## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.implementation preserve=yes
      //## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.implementation

};

//## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.postscript preserve=yes
//## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.postscript

//## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.preface preserve=yes
//## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.preface

//## Class: XSTExceptionHomingRepeatAccuracy%3F8A604403E0
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionHomingRepeatAccuracy : public XSTExceptionHoming  //## Inherits: <unnamed>%3F8A62FD022A
{
  //## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.initialDeclarations preserve=yes
  //## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionHomingRepeatAccuracy%1066031277
      XSTExceptionHomingRepeatAccuracy (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionHomingRepeatAccuracy%1066031278
      XSTExceptionHomingRepeatAccuracy (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionHomingRepeatAccuracy();


    //## Other Operations (specified)
      //## Operation: Throw%1066031279
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1066031280
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.public preserve=yes
      //## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.protected preserve=yes
      //## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.protected

  private:
    //## Constructors (generated)
      XSTExceptionHomingRepeatAccuracy(const XSTExceptionHomingRepeatAccuracy &right);

    //## Assignment Operation (generated)
      const XSTExceptionHomingRepeatAccuracy & operator=(const XSTExceptionHomingRepeatAccuracy &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionHomingRepeatAccuracy &right) const;

      bool operator!=(const XSTExceptionHomingRepeatAccuracy &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.private preserve=yes
      //## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.implementation preserve=yes
      //## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.implementation

};

//## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.postscript preserve=yes
//## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.postscript

//## begin XSTExceptionTimeOnTime%3F8A64730396.preface preserve=yes
//## end XSTExceptionTimeOnTime%3F8A64730396.preface

//## Class: XSTExceptionTimeOnTime%3F8A64730396
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionTimeOnTime : public XSTExceptionError  //## Inherits: <unnamed>%3F8A64FA02EA
{
  //## begin XSTExceptionTimeOnTime%3F8A64730396.initialDeclarations preserve=yes
  //## end XSTExceptionTimeOnTime%3F8A64730396.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionTimeOnTime%1066031281
      XSTExceptionTimeOnTime (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionTimeOnTime%1066031282
      XSTExceptionTimeOnTime (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionTimeOnTime();


    //## Other Operations (specified)
      //## Operation: Throw%1066031283
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1066031284
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionTimeOnTime%3F8A64730396.public preserve=yes
      //## end XSTExceptionTimeOnTime%3F8A64730396.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionTimeOnTime%3F8A64730396.protected preserve=yes
      //## end XSTExceptionTimeOnTime%3F8A64730396.protected

  private:
    //## Constructors (generated)
      XSTExceptionTimeOnTime(const XSTExceptionTimeOnTime &right);

    //## Assignment Operation (generated)
      const XSTExceptionTimeOnTime & operator=(const XSTExceptionTimeOnTime &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionTimeOnTime &right) const;

      bool operator!=(const XSTExceptionTimeOnTime &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionTimeOnTime%3F8A64730396.private preserve=yes
      //## end XSTExceptionTimeOnTime%3F8A64730396.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionTimeOnTime%3F8A64730396.implementation preserve=yes
      //## end XSTExceptionTimeOnTime%3F8A64730396.implementation

};

//## begin XSTExceptionTimeOnTime%3F8A64730396.postscript preserve=yes
//## end XSTExceptionTimeOnTime%3F8A64730396.postscript

//## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.preface preserve=yes
//## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.preface

//## Class: XSTExceptionHomingLimitConfig%3F8A8D9E00C7
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionHomingLimitConfig : public XSTExceptionHoming  //## Inherits: <unnamed>%3F8A8FEE0376
{
  //## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.initialDeclarations preserve=yes
  //## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionHomingLimitConfig%1066031287
      XSTExceptionHomingLimitConfig (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionHomingLimitConfig%1066031288
      XSTExceptionHomingLimitConfig (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionHomingLimitConfig();


    //## Other Operations (specified)
      //## Operation: Throw%1066031289
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1066031290
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.public preserve=yes
      //## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.protected preserve=yes
      //## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.protected

  private:
    //## Constructors (generated)
      XSTExceptionHomingLimitConfig(const XSTExceptionHomingLimitConfig &right);

    //## Assignment Operation (generated)
      const XSTExceptionHomingLimitConfig & operator=(const XSTExceptionHomingLimitConfig &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionHomingLimitConfig &right) const;

      bool operator!=(const XSTExceptionHomingLimitConfig &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.private preserve=yes
      //## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.implementation preserve=yes
      //## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.implementation

};

//## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.postscript preserve=yes
//## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.postscript

//## begin XSTExceptionLimitJitter%3FCC6F180196.preface preserve=yes
//## end XSTExceptionLimitJitter%3FCC6F180196.preface

//## Class: XSTExceptionLimitJitter%3FCC6F180196
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionLimitJitter : public XCOExceptionError  //## Inherits: <unnamed>%3FE04D4B00FC
{
  //## begin XSTExceptionLimitJitter%3FCC6F180196.initialDeclarations preserve=yes
  //## end XSTExceptionLimitJitter%3FCC6F180196.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionLimitJitter%1071664278
      XSTExceptionLimitJitter (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionLimitJitter%1071664279
      XSTExceptionLimitJitter (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionLimitJitter();


    //## Other Operations (specified)
      //## Operation: Throw%1071664280
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1071664281
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionLimitJitter%3FCC6F180196.public preserve=yes
      //## end XSTExceptionLimitJitter%3FCC6F180196.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionLimitJitter%3FCC6F180196.protected preserve=yes
      //## end XSTExceptionLimitJitter%3FCC6F180196.protected

  private:
    //## Constructors (generated)
      XSTExceptionLimitJitter(const XSTExceptionLimitJitter &right);

    //## Assignment Operation (generated)
      const XSTExceptionLimitJitter & operator=(const XSTExceptionLimitJitter &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionLimitJitter &right) const;

      bool operator!=(const XSTExceptionLimitJitter &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionLimitJitter%3FCC6F180196.private preserve=yes
      //## end XSTExceptionLimitJitter%3FCC6F180196.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionLimitJitter%3FCC6F180196.implementation preserve=yes
      //## end XSTExceptionLimitJitter%3FCC6F180196.implementation

};

//## begin XSTExceptionLimitJitter%3FCC6F180196.postscript preserve=yes
//## end XSTExceptionLimitJitter%3FCC6F180196.postscript

//## begin XSTExceptionHardLimitHit%3FE04C170235.preface preserve=yes
//## end XSTExceptionHardLimitHit%3FE04C170235.preface

//## Class: XSTExceptionHardLimitHit%3FE04C170235
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSTExceptionHardLimitHit : public XSTExceptionLimit  //## Inherits: <unnamed>%3FE04C33036D
{
  //## begin XSTExceptionHardLimitHit%3FE04C170235.initialDeclarations preserve=yes
  //## end XSTExceptionHardLimitHit%3FE04C170235.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSTExceptionHardLimitHit%1071664274
      XSTExceptionHardLimitHit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XSTExceptionHardLimitHit%1071664275
      XSTExceptionHardLimitHit (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSTExceptionHardLimitHit();


    //## Other Operations (specified)
      //## Operation: Throw%1071664276
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1071664277
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XSTExceptionHardLimitHit%3FE04C170235.public preserve=yes
      //## end XSTExceptionHardLimitHit%3FE04C170235.public

  protected:
    // Additional Protected Declarations
      //## begin XSTExceptionHardLimitHit%3FE04C170235.protected preserve=yes
      //## end XSTExceptionHardLimitHit%3FE04C170235.protected

  private:
    //## Constructors (generated)
      XSTExceptionHardLimitHit(const XSTExceptionHardLimitHit &right);

    //## Assignment Operation (generated)
      const XSTExceptionHardLimitHit & operator=(const XSTExceptionHardLimitHit &right);

    //## Equality Operations (generated)
      bool operator==(const XSTExceptionHardLimitHit &right) const;

      bool operator!=(const XSTExceptionHardLimitHit &right) const;

    // Additional Private Declarations
      //## begin XSTExceptionHardLimitHit%3FE04C170235.private preserve=yes
      //## end XSTExceptionHardLimitHit%3FE04C170235.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSTExceptionHardLimitHit%3FE04C170235.implementation preserve=yes
      //## end XSTExceptionHardLimitHit%3FE04C170235.implementation

};

//## begin XSTExceptionHardLimitHit%3FE04C170235.postscript preserve=yes
//## end XSTExceptionHardLimitHit%3FE04C170235.postscript

// Class XSTExceptionError 

// Class XSTExceptionLimit 

// Class XSTExceptionSoftLimitHit 

// Class XSTExceptionErrorStepsDeviation 

// Class XSTExceptionHoming 

// Class XSTExcepitonHomingSensorNotFound 

// Class XSTExceptionHomingRepeatAccuracy 

// Class XSTExceptionTimeOnTime 

// Class XSTExceptionHomingLimitConfig 

// Class XSTExceptionLimitJitter 

// Class XSTExceptionHardLimitHit 

//## begin module%3ECA3D3F0208.epilog preserve=yes
//## end module%3ECA3D3F0208.epilog


#endif
