//## begin module%3EE9C87E020F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE9C87E020F.cm

//## begin module%3EE9C87E020F.cp preserve=no
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
//## end module%3EE9C87E020F.cp

//## Module: EBTCexcp%3EE9C87E020F; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCexcp.h

#ifndef EBTCexcp_h
#define EBTCexcp_h 1

//## begin module%3EE9C87E020F.additionalIncludes preserve=no
//## end module%3EE9C87E020F.additionalIncludes

//## begin module%3EE9C87E020F.includes preserve=yes
//## end module%3EE9C87E020F.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3EE9C87E020F.declarations preserve=no
//## end module%3EE9C87E020F.declarations

//## begin module%3EE9C87E020F.additionalDeclarations preserve=yes
//## end module%3EE9C87E020F.additionalDeclarations


//## begin XTCExceptionError%3EE9C402000B.preface preserve=yes
//## end XTCExceptionError%3EE9C402000B.preface

//## Class: XTCExceptionError%3EE9C402000B
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionError : public XCOExceptionError  //## Inherits: <unnamed>%3EEF0C4D030C
{
  //## begin XTCExceptionError%3EE9C402000B.initialDeclarations preserve=yes
  //## end XTCExceptionError%3EE9C402000B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionError%1055484806
      XTCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionError%1055484807
      XTCExceptionError (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionError();

    // Additional Public Declarations
      //## begin XTCExceptionError%3EE9C402000B.public preserve=yes
      //## end XTCExceptionError%3EE9C402000B.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionError%3EE9C402000B.protected preserve=yes
      //## end XTCExceptionError%3EE9C402000B.protected

  private:
    //## Constructors (generated)
      XTCExceptionError(const XTCExceptionError &right);

    //## Assignment Operation (generated)
      const XTCExceptionError & operator=(const XTCExceptionError &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionError &right) const;

      bool operator!=(const XTCExceptionError &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionError%3EE9C402000B.private preserve=yes
      //## end XTCExceptionError%3EE9C402000B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionError%3EE9C402000B.implementation preserve=yes
      //## end XTCExceptionError%3EE9C402000B.implementation

};

//## begin XTCExceptionError%3EE9C402000B.postscript preserve=yes
//## end XTCExceptionError%3EE9C402000B.postscript

//## begin XTCExceptionTemperature%3EE9C4860182.preface preserve=yes
//## end XTCExceptionTemperature%3EE9C4860182.preface

//## Class: XTCExceptionTemperature%3EE9C4860182
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionTemperature : public XTCExceptionError  //## Inherits: <unnamed>%3EEF0C560203
{
  //## begin XTCExceptionTemperature%3EE9C4860182.initialDeclarations preserve=yes
  //## end XTCExceptionTemperature%3EE9C4860182.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionTemperature%1055484804
      XTCExceptionTemperature (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionTemperature%1055484805
      XTCExceptionTemperature (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionTemperature();

    // Additional Public Declarations
      //## begin XTCExceptionTemperature%3EE9C4860182.public preserve=yes
      //## end XTCExceptionTemperature%3EE9C4860182.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionTemperature%3EE9C4860182.protected preserve=yes
      //## end XTCExceptionTemperature%3EE9C4860182.protected

  private:
    //## Constructors (generated)
      XTCExceptionTemperature(const XTCExceptionTemperature &right);

    //## Assignment Operation (generated)
      const XTCExceptionTemperature & operator=(const XTCExceptionTemperature &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionTemperature &right) const;

      bool operator!=(const XTCExceptionTemperature &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionTemperature%3EE9C4860182.private preserve=yes
      //## end XTCExceptionTemperature%3EE9C4860182.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionTemperature%3EE9C4860182.implementation preserve=yes
      //## end XTCExceptionTemperature%3EE9C4860182.implementation

};

//## begin XTCExceptionTemperature%3EE9C4860182.postscript preserve=yes
//## end XTCExceptionTemperature%3EE9C4860182.postscript

//## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.preface preserve=yes
//## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.preface

//## Class: XTCExceptionErrorHeaterFailure%3EE9C6BD022E
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionErrorHeaterFailure : public XTCExceptionError  //## Inherits: <unnamed>%3EE9C6D80105
{
  //## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.initialDeclarations preserve=yes
  //## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionErrorHeaterFailure%1055484810
      XTCExceptionErrorHeaterFailure (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionErrorHeaterFailure%1055484811
      XTCExceptionErrorHeaterFailure (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionErrorHeaterFailure();

    // Additional Public Declarations
      //## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.public preserve=yes
      //## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.protected preserve=yes
      //## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.protected

  private:
    //## Constructors (generated)
      XTCExceptionErrorHeaterFailure(const XTCExceptionErrorHeaterFailure &right);

    //## Assignment Operation (generated)
      const XTCExceptionErrorHeaterFailure & operator=(const XTCExceptionErrorHeaterFailure &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionErrorHeaterFailure &right) const;

      bool operator!=(const XTCExceptionErrorHeaterFailure &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.private preserve=yes
      //## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.implementation preserve=yes
      //## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.implementation

};

//## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.postscript preserve=yes
//## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.postscript

//## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.preface preserve=yes
//## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.preface

//## Class: XTCExceptionTemperatureErrorLLimit%3EE9D0670124
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionTemperatureErrorLLimit : public XTCExceptionTemperature  //## Inherits: <unnamed>%3EE9D0ED03A5
{
  //## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.initialDeclarations preserve=yes
  //## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionTemperatureErrorLLimit%1055484822
      XTCExceptionTemperatureErrorLLimit (XCOExceptionError* p_pOrigException);

      //## Operation: XTCExceptionTemperatureErrorLLimit%1055484823
      XTCExceptionTemperatureErrorLLimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

    //## Destructor (generated)
      virtual ~XTCExceptionTemperatureErrorLLimit();


    //## Other Operations (specified)
      //## Operation: Throw%1055484820
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055484821
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.public preserve=yes
      //## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.protected preserve=yes
      //## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.protected

  private:
    //## Constructors (generated)
      XTCExceptionTemperatureErrorLLimit(const XTCExceptionTemperatureErrorLLimit &right);

    //## Assignment Operation (generated)
      const XTCExceptionTemperatureErrorLLimit & operator=(const XTCExceptionTemperatureErrorLLimit &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionTemperatureErrorLLimit &right) const;

      bool operator!=(const XTCExceptionTemperatureErrorLLimit &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.private preserve=yes
      //## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.implementation preserve=yes
      //## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.implementation

};

//## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.postscript preserve=yes
//## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.postscript

//## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.preface preserve=yes
//## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.preface

//## Class: XTCExceptionTemperatureWarningLLimit%3EE9D08D0337
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionTemperatureWarningLLimit : public XTCExceptionTemperature  //## Inherits: <unnamed>%3EE9D0F100D6
{
  //## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.initialDeclarations preserve=yes
  //## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionTemperatureWarningLLimit%1055484824
      XTCExceptionTemperatureWarningLLimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionTemperatureWarningLLimit%1055484825
      XTCExceptionTemperatureWarningLLimit (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionTemperatureWarningLLimit();


    //## Other Operations (specified)
      //## Operation: Throw%1055484826
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055484827
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.public preserve=yes
      //## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.protected preserve=yes
      //## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.protected

  private:
    //## Constructors (generated)
      XTCExceptionTemperatureWarningLLimit(const XTCExceptionTemperatureWarningLLimit &right);

    //## Assignment Operation (generated)
      const XTCExceptionTemperatureWarningLLimit & operator=(const XTCExceptionTemperatureWarningLLimit &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionTemperatureWarningLLimit &right) const;

      bool operator!=(const XTCExceptionTemperatureWarningLLimit &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.private preserve=yes
      //## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.implementation preserve=yes
      //## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.implementation

};

//## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.postscript preserve=yes
//## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.postscript

//## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.preface preserve=yes
//## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.preface

//## Class: XTCExceptionTemperatureWarningULimit%3EE9D0A0001B
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionTemperatureWarningULimit : public XTCExceptionTemperature  //## Inherits: <unnamed>%3EE9D0F5025D
{
  //## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.initialDeclarations preserve=yes
  //## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionTemperatureWarningULimit%1055484828
      XTCExceptionTemperatureWarningULimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionTemperatureWarningULimit%1055484829
      XTCExceptionTemperatureWarningULimit (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionTemperatureWarningULimit();


    //## Other Operations (specified)
      //## Operation: Throw%1055484830
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055484831
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.public preserve=yes
      //## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.protected preserve=yes
      //## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.protected

  private:
    //## Constructors (generated)
      XTCExceptionTemperatureWarningULimit(const XTCExceptionTemperatureWarningULimit &right);

    //## Assignment Operation (generated)
      const XTCExceptionTemperatureWarningULimit & operator=(const XTCExceptionTemperatureWarningULimit &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionTemperatureWarningULimit &right) const;

      bool operator!=(const XTCExceptionTemperatureWarningULimit &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.private preserve=yes
      //## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.implementation preserve=yes
      //## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.implementation

};

//## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.postscript preserve=yes
//## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.postscript

//## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.preface preserve=yes
//## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.preface

//## Class: XTCExceptionTemperatureErrorULimit%3EE9D0DA026C
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionTemperatureErrorULimit : public XTCExceptionTemperature  //## Inherits: <unnamed>%3EE9D0EB0098
{
  //## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.initialDeclarations preserve=yes
  //## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionTemperatureErrorULimit%1055484818
      XTCExceptionTemperatureErrorULimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionTemperatureErrorULimit%1055484819
      XTCExceptionTemperatureErrorULimit (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionTemperatureErrorULimit();


    //## Other Operations (specified)
      //## Operation: Throw%1055484816
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055484817
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.public preserve=yes
      //## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.protected preserve=yes
      //## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.protected

  private:
    //## Constructors (generated)
      XTCExceptionTemperatureErrorULimit(const XTCExceptionTemperatureErrorULimit &right);

    //## Assignment Operation (generated)
      const XTCExceptionTemperatureErrorULimit & operator=(const XTCExceptionTemperatureErrorULimit &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionTemperatureErrorULimit &right) const;

      bool operator!=(const XTCExceptionTemperatureErrorULimit &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.private preserve=yes
      //## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.implementation preserve=yes
      //## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.implementation

};

//## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.postscript preserve=yes
//## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.postscript

//## begin XTCExceptionErrorInterrupted%3EEF0D230109.preface preserve=yes
//## end XTCExceptionErrorInterrupted%3EEF0D230109.preface

//## Class: XTCExceptionErrorInterrupted%3EEF0D230109
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionErrorInterrupted : public XTCExceptionErrorHeaterFailure  //## Inherits: <unnamed>%3EEF0D3E003E
{
  //## begin XTCExceptionErrorInterrupted%3EEF0D230109.initialDeclarations preserve=yes
  //## end XTCExceptionErrorInterrupted%3EEF0D230109.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionErrorInterrupted%1055833084
      XTCExceptionErrorInterrupted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionErrorInterrupted%1055833085
      XTCExceptionErrorInterrupted (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionErrorInterrupted();


    //## Other Operations (specified)
      //## Operation: Throw%1055833086
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055833087
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XTCExceptionErrorInterrupted%3EEF0D230109.public preserve=yes
      //## end XTCExceptionErrorInterrupted%3EEF0D230109.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionErrorInterrupted%3EEF0D230109.protected preserve=yes
      //## end XTCExceptionErrorInterrupted%3EEF0D230109.protected

  private:
    //## Constructors (generated)
      XTCExceptionErrorInterrupted(const XTCExceptionErrorInterrupted &right);

    //## Assignment Operation (generated)
      const XTCExceptionErrorInterrupted & operator=(const XTCExceptionErrorInterrupted &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionErrorInterrupted &right) const;

      bool operator!=(const XTCExceptionErrorInterrupted &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionErrorInterrupted%3EEF0D230109.private preserve=yes
      //## end XTCExceptionErrorInterrupted%3EEF0D230109.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionErrorInterrupted%3EEF0D230109.implementation preserve=yes
      //## end XTCExceptionErrorInterrupted%3EEF0D230109.implementation

};

//## begin XTCExceptionErrorInterrupted%3EEF0D230109.postscript preserve=yes
//## end XTCExceptionErrorInterrupted%3EEF0D230109.postscript

//## begin XTCExceptionErrorShorted%3EEF0D410147.preface preserve=yes
//## end XTCExceptionErrorShorted%3EEF0D410147.preface

//## Class: XTCExceptionErrorShorted%3EEF0D410147
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XTCExceptionErrorShorted : public XTCExceptionErrorHeaterFailure  //## Inherits: <unnamed>%3EEF0D790261
{
  //## begin XTCExceptionErrorShorted%3EEF0D410147.initialDeclarations preserve=yes
  //## end XTCExceptionErrorShorted%3EEF0D410147.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XTCExceptionErrorShorted%1055833088
      XTCExceptionErrorShorted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode);

      //## Operation: XTCExceptionErrorShorted%1055833089
      XTCExceptionErrorShorted (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XTCExceptionErrorShorted();


    //## Other Operations (specified)
      //## Operation: Throw%1055833090
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1055833091
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    // Additional Public Declarations
      //## begin XTCExceptionErrorShorted%3EEF0D410147.public preserve=yes
      //## end XTCExceptionErrorShorted%3EEF0D410147.public

  protected:
    // Additional Protected Declarations
      //## begin XTCExceptionErrorShorted%3EEF0D410147.protected preserve=yes
      //## end XTCExceptionErrorShorted%3EEF0D410147.protected

  private:
    //## Constructors (generated)
      XTCExceptionErrorShorted(const XTCExceptionErrorShorted &right);

    //## Assignment Operation (generated)
      const XTCExceptionErrorShorted & operator=(const XTCExceptionErrorShorted &right);

    //## Equality Operations (generated)
      bool operator==(const XTCExceptionErrorShorted &right) const;

      bool operator!=(const XTCExceptionErrorShorted &right) const;

    // Additional Private Declarations
      //## begin XTCExceptionErrorShorted%3EEF0D410147.private preserve=yes
      //## end XTCExceptionErrorShorted%3EEF0D410147.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XTCExceptionErrorShorted%3EEF0D410147.implementation preserve=yes
      //## end XTCExceptionErrorShorted%3EEF0D410147.implementation

};

//## begin XTCExceptionErrorShorted%3EEF0D410147.postscript preserve=yes
//## end XTCExceptionErrorShorted%3EEF0D410147.postscript

// Class XTCExceptionError 

// Class XTCExceptionTemperature 

// Class XTCExceptionErrorHeaterFailure 

// Class XTCExceptionTemperatureErrorLLimit 

// Class XTCExceptionTemperatureWarningLLimit 

// Class XTCExceptionTemperatureWarningULimit 

// Class XTCExceptionTemperatureErrorULimit 

// Class XTCExceptionErrorInterrupted 

// Class XTCExceptionErrorShorted 

//## begin module%3EE9C87E020F.epilog preserve=yes
//## end module%3EE9C87E020F.epilog


#endif
