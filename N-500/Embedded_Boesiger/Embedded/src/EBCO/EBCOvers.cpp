//## begin module%406C1D97002C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%406C1D97002C.cm

//## begin module%406C1D97002C.cp preserve=no
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
//## end module%406C1D97002C.cp

//## Module: EBCOvers%406C1D97002C; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOvers.cpp

// stdafx
#include "stdafx.h"
//## begin module%406C1D97002C.additionalIncludes preserve=no
//## end module%406C1D97002C.additionalIncludes

//## begin module%406C1D97002C.includes preserve=yes
//## end module%406C1D97002C.includes

// EBCOvers
#include "EBCOvers.h"
//## begin module%406C1D97002C.declarations preserve=no
//## end module%406C1D97002C.declarations

//## begin module%406C1D97002C.additionalDeclarations preserve=yes
//## end module%406C1D97002C.additionalDeclarations


// Class CCOVersion 



CCOVersion::CCOVersion()
  //## begin CCOVersion::CCOVersion%.hasinit preserve=no
  //## end CCOVersion::CCOVersion%.hasinit
  //## begin CCOVersion::CCOVersion%.initialization preserve=yes
  //## end CCOVersion::CCOVersion%.initialization
{
  //## begin CCOVersion::CCOVersion%.body preserve=yes
	m_sMajor = _T("*");
  //## end CCOVersion::CCOVersion%.body
}

CCOVersion::CCOVersion(const CCOVersion &right)
  //## begin CCOVersion::CCOVersion%copy.hasinit preserve=no
  //## end CCOVersion::CCOVersion%copy.hasinit
  //## begin CCOVersion::CCOVersion%copy.initialization preserve=yes
  //## end CCOVersion::CCOVersion%copy.initialization
{
  //## begin CCOVersion::CCOVersion%copy.body preserve=yes
	m_sMajor = right.m_sMajor;
	m_sMinor = right.m_sMinor;
  //## end CCOVersion::CCOVersion%copy.body
}

CCOVersion::CCOVersion (const CString& p_sVersion)
  //## begin CCOVersion::CCOVersion%1080827389.hasinit preserve=no
  //## end CCOVersion::CCOVersion%1080827389.hasinit
  //## begin CCOVersion::CCOVersion%1080827389.initialization preserve=yes
  //## end CCOVersion::CCOVersion%1080827389.initialization
{
  //## begin CCOVersion::CCOVersion%1080827389.body preserve=yes
	int l_iSep = p_sVersion.Find('.');
	if (l_iSep == -1)
	{
		m_sMajor = p_sVersion;
	}
	else
	{
		if (l_iSep > 0)
			m_sMajor = p_sVersion.Left(l_iSep);
		m_sMinor = p_sVersion.Right(p_sVersion.GetLength()-l_iSep-1);
	}

	if (m_sMajor == _T(""))
		m_sMajor = _T("*");
  //## end CCOVersion::CCOVersion%1080827389.body
}


CCOVersion::~CCOVersion()
{
  //## begin CCOVersion::~CCOVersion%.body preserve=yes
  //## end CCOVersion::~CCOVersion%.body
}


bool CCOVersion::operator==(const CCOVersion &right) const
{
  //## begin CCOVersion::operator==%.body preserve=yes
	return m_sMajor == right.m_sMajor && m_sMinor == right.m_sMinor;
  //## end CCOVersion::operator==%.body
}

bool CCOVersion::operator!=(const CCOVersion &right) const
{
  //## begin CCOVersion::operator!=%.body preserve=yes
	return !(m_sMajor == right.m_sMajor && m_sMinor == right.m_sMinor);
  //## end CCOVersion::operator!=%.body
}


bool CCOVersion::operator<(const CCOVersion &right) const
{
  //## begin CCOVersion::operator<%.body preserve=yes
	int l_iMajor = CompareMajor(right);

	if (l_iMajor < 0)
		return true;
	else if (l_iMajor == 0)
	{
		if (CompareMinor(right) < 0)
			return true;
	}

	return false;
  //## end CCOVersion::operator<%.body
}

bool CCOVersion::operator>(const CCOVersion &right) const
{
  //## begin CCOVersion::operator>%.body preserve=yes
	int l_iMajor = CompareMajor(right);

	if (l_iMajor > 0)
		return true;
	else if (l_iMajor == 0)
	{
		if (CompareMinor(right) > 0)
			return true;
	}

	return false;
  //## end CCOVersion::operator>%.body
}

bool CCOVersion::operator<=(const CCOVersion &right) const
{
  //## begin CCOVersion::operator<=%.body preserve=yes
	int l_iMajor = CompareMajor(right);

	if (l_iMajor <= 0)
		return true;
	else if (l_iMajor == 0)
	{
		if (CompareMinor(right) <= 0)
			return true;
	}

	return false;
  //## end CCOVersion::operator<=%.body
}

bool CCOVersion::operator>=(const CCOVersion &right) const
{
  //## begin CCOVersion::operator>=%.body preserve=yes
	int l_iMajor = CompareMajor(right);

	if (l_iMajor >= 0)
		return true;
	else if (l_iMajor == 0)
	{
		if (CompareMinor(right) >= 0)
			return true;
	}

	return false;
  //## end CCOVersion::operator>=%.body
}



//## Other Operations (implementation)
int CCOVersion::CompareMajor (const CCOVersion& p_Right) const
{
  //## begin CCOVersion::CompareMajor%1080827390.body preserve=yes
	if (m_sMajor == _T("*") || p_Right.m_sMajor == _T("*"))
		return 0;

	return m_sMajor.CompareNoCase(p_Right.m_sMajor);
  //## end CCOVersion::CompareMajor%1080827390.body
}

int CCOVersion::CompareMinor (const CCOVersion& p_Right) const
{
  //## begin CCOVersion::CompareMinor%1080827391.body preserve=yes
	if (m_sMinor == _T("*") || p_Right.m_sMinor == _T("*"))
		return 0;

	return m_sMinor.CompareNoCase(p_Right.m_sMinor);
  //## end CCOVersion::CompareMinor%1080827391.body
}

CString CCOVersion::operator () (CString )
{
  //## begin CCOVersion::operator()%1080827392.body preserve=yes
	return m_sMajor + "." + m_sMinor;
  //## end CCOVersion::operator()%1080827392.body
}

// Additional Declarations
  //## begin CCOVersion%406C1D6601C6.declarations preserve=yes
  //## end CCOVersion%406C1D6601C6.declarations

//## begin module%406C1D97002C.epilog preserve=yes
//## end module%406C1D97002C.epilog
