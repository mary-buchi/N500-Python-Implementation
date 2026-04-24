//## begin module%3DB51299013B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DB51299013B.cm

//## begin module%3DB51299013B.cp preserve=no
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
//## end module%3DB51299013B.cp

//## Module: EBCOtype%3DB51299013B; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOtype.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DB51299013B.additionalIncludes preserve=no
//## end module%3DB51299013B.additionalIncludes

//## begin module%3DB51299013B.includes preserve=yes
//## end module%3DB51299013B.includes

// EBCOtype
#include "EBCOtype.h"


//## begin module%3DB51299013B.declarations preserve=no
//## end module%3DB51299013B.declarations

//## begin module%3DB51299013B.additionalDeclarations preserve=yes
//## end module%3DB51299013B.additionalDeclarations


// Class CCOIntegerArray 



CCOIntegerArray::CCOIntegerArray()
  //## begin CCOIntegerArray::CCOIntegerArray%.hasinit preserve=no
  //## end CCOIntegerArray::CCOIntegerArray%.hasinit
  //## begin CCOIntegerArray::CCOIntegerArray%.initialization preserve=yes
  //## end CCOIntegerArray::CCOIntegerArray%.initialization
{
  //## begin CCOIntegerArray::CCOIntegerArray%.body preserve=yes
  //## end CCOIntegerArray::CCOIntegerArray%.body
}

CCOIntegerArray::CCOIntegerArray (const CArray<INT,INT>& p_Array)
  //## begin CCOIntegerArray::CCOIntegerArray%1037016804.hasinit preserve=no
  //## end CCOIntegerArray::CCOIntegerArray%1037016804.hasinit
  //## begin CCOIntegerArray::CCOIntegerArray%1037016804.initialization preserve=yes
  //## end CCOIntegerArray::CCOIntegerArray%1037016804.initialization
{
  //## begin CCOIntegerArray::CCOIntegerArray%1037016804.body preserve=yes
    m_Array.SetSize(p_Array.GetSize());
    m_Array.Copy(p_Array);
  //## end CCOIntegerArray::CCOIntegerArray%1037016804.body
}


CCOIntegerArray::~CCOIntegerArray()
{
  //## begin CCOIntegerArray::~CCOIntegerArray%.body preserve=yes
  //## end CCOIntegerArray::~CCOIntegerArray%.body
}


//## Get and Set Operations for Associations (implementation)

CArray<INT,INT>& CCOIntegerArray::GetArray ()
{
  //## begin CCOIntegerArray::GetArray%3DB5184301A9.get preserve=no
  return m_Array;
  //## end CCOIntegerArray::GetArray%3DB5184301A9.get
}

void CCOIntegerArray::SetArray (const CArray<INT,INT>& value)
{
  //## begin CCOIntegerArray::SetArray%3DB5184301A9.set preserve=yes
    m_Array.RemoveAll();
    m_Array.SetSize(value.GetSize());
    m_Array.Copy(value);
  //## end CCOIntegerArray::SetArray%3DB5184301A9.set
}

// Additional Declarations
  //## begin CCOIntegerArray%3DB512AD01E6.declarations preserve=yes
  //## end CCOIntegerArray%3DB512AD01E6.declarations

//## begin module%3DB51299013B.epilog preserve=yes
//## end module%3DB51299013B.epilog
