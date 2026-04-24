//## begin module%415D8C0F02E6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%415D8C0F02E6.cm

//## begin module%415D8C0F02E6.cp preserve=no
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
//## end module%415D8C0F02E6.cp

//## Module: EBSYexcp%415D8C0F02E6; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYexcp.h

#ifndef EBSYexcp_h
#define EBSYexcp_h 1

//## begin module%415D8C0F02E6.additionalIncludes preserve=no
//## end module%415D8C0F02E6.additionalIncludes

//## begin module%415D8C0F02E6.includes preserve=yes
//## end module%415D8C0F02E6.includes

// EBCOexcp
#include "EBCOexcp.h"


//## begin module%415D8C0F02E6.declarations preserve=no
//## end module%415D8C0F02E6.declarations

//## begin module%415D8C0F02E6.additionalDeclarations preserve=yes
//## end module%415D8C0F02E6.additionalDeclarations


//## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.preface preserve=yes
//## end XSYExceptionErrorDeviceBusy%415D8BA5015D.preface

//## Class: XSYExceptionErrorDeviceBusy%415D8BA5015D
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XSYExceptionErrorDeviceBusy : public XCOExceptionError  //## Inherits: <unnamed>%415D8BCB0021
{
  //## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.initialDeclarations preserve=yes
  //## end XSYExceptionErrorDeviceBusy%415D8BA5015D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: XSYExceptionErrorDeviceBusy%1096648857
      XSYExceptionErrorDeviceBusy (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sClient);

      //## Operation: XSYExceptionErrorDeviceBusy%1096648858
      XSYExceptionErrorDeviceBusy (XCOExceptionError* p_pOrigException);

    //## Destructor (generated)
      virtual ~XSYExceptionErrorDeviceBusy();


    //## Other Operations (specified)
      //## Operation: GetPlainText%1096656424
      virtual CString GetPlainText ();

      //## Operation: Throw%1096648859
      //	DESCRIPTION
      //	Re-throws an exception without losing type information.
      virtual void Throw ();

      //## Operation: Clone%1096648860
      //	DESCRIPTION
      //	Clones the current exception.
      //
      //	RETURNS
      //	Pointer to clone
      virtual XCOException* Clone ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBSY (System Control)::<unnamed>%415D8CE30150
      //## Role: XSYExceptionErrorDeviceBusy::sClient%415D8CE303B4
      CString& GetsClient ();

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%415D8CE30150
      //## begin XSYExceptionErrorDeviceBusy::sClient%415D8CE303B4.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sClient;
      //## end XSYExceptionErrorDeviceBusy::sClient%415D8CE303B4.role

    // Additional Public Declarations
      //## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.public preserve=yes
      //## end XSYExceptionErrorDeviceBusy%415D8BA5015D.public

  protected:
    // Additional Protected Declarations
      //## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.protected preserve=yes
      //## end XSYExceptionErrorDeviceBusy%415D8BA5015D.protected

  private:
    //## Constructors (generated)
      XSYExceptionErrorDeviceBusy(const XSYExceptionErrorDeviceBusy &right);

    //## Assignment Operation (generated)
      const XSYExceptionErrorDeviceBusy & operator=(const XSYExceptionErrorDeviceBusy &right);

    //## Equality Operations (generated)
      bool operator==(const XSYExceptionErrorDeviceBusy &right) const;

      bool operator!=(const XSYExceptionErrorDeviceBusy &right) const;

    // Additional Private Declarations
      //## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.private preserve=yes
      //## end XSYExceptionErrorDeviceBusy%415D8BA5015D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.implementation preserve=yes
      //## end XSYExceptionErrorDeviceBusy%415D8BA5015D.implementation

};

//## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.postscript preserve=yes
//## end XSYExceptionErrorDeviceBusy%415D8BA5015D.postscript

// Class XSYExceptionErrorDeviceBusy 

//## begin module%415D8C0F02E6.epilog preserve=yes
//## end module%415D8C0F02E6.epilog


#endif
