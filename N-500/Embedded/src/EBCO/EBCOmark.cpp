//## begin module%3FB3834C015F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FB3834C015F.cm

//## begin module%3FB3834C015F.cp preserve=no
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
//## end module%3FB3834C015F.cp

//## Module: EBCOmark%3FB3834C015F; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOmark.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FB3834C015F.additionalIncludes preserve=no
//## end module%3FB3834C015F.additionalIncludes

//## begin module%3FB3834C015F.includes preserve=yes
#include "afxconv.h"
//## end module%3FB3834C015F.includes

// EBCOmark
#include "EBCOmark.h"
//## begin module%3FB3834C015F.declarations preserve=no
//## end module%3FB3834C015F.declarations

//## begin module%3FB3834C015F.additionalDeclarations preserve=yes
#ifdef _WIN32_WCE
#define _tclen(p) 1
#define _tccpy(p1,p2) *(p1)=*(p2)
#endif
//## end module%3FB3834C015F.additionalDeclarations


// Class CCOMarkup::ElemPos 










CCOMarkup::ElemPos::ElemPos()
  //## begin ElemPos::ElemPos%.hasinit preserve=no
  //## end ElemPos::ElemPos%.hasinit
  //## begin ElemPos::ElemPos%.initialization preserve=yes
  //## end ElemPos::ElemPos%.initialization
{
  //## begin CCOMarkup::ElemPos::ElemPos%.body preserve=yes
    Clear();
  //## end CCOMarkup::ElemPos::ElemPos%.body
}

CCOMarkup::ElemPos::ElemPos(const CCOMarkup::ElemPos &right)
  //## begin ElemPos::ElemPos%copy.hasinit preserve=no
  //## end ElemPos::ElemPos%copy.hasinit
  //## begin ElemPos::ElemPos%copy.initialization preserve=yes
  //## end ElemPos::ElemPos%copy.initialization
{
  //## begin CCOMarkup::ElemPos::ElemPos%copy.body preserve=yes
    *this = right;
  //## end CCOMarkup::ElemPos::ElemPos%copy.body
}


CCOMarkup::ElemPos::~ElemPos()
{
  //## begin CCOMarkup::ElemPos::~ElemPos%.body preserve=yes
  //## end CCOMarkup::ElemPos::~ElemPos%.body
}



//## Other Operations (implementation)
bool CCOMarkup::ElemPos::IsEmptyElement () const
{
  //## begin CCOMarkup::ElemPos::IsEmptyElement%1068729239.body preserve=yes
    return (m_nStartR == m_nEndL + 1);
  //## end CCOMarkup::ElemPos::IsEmptyElement%1068729239.body
}

void CCOMarkup::ElemPos::Clear ()
{
  //## begin CCOMarkup::ElemPos::Clear%1068729240.body preserve=yes
	m_nStartL=0; m_nStartR=0; m_nEndL=0; m_nEndR=0; m_nNext=0;
	m_iElemParent=0; m_iElemChild=0; m_iElemNext=0;
  //## end CCOMarkup::ElemPos::Clear%1068729240.body
}

// Additional Declarations
  //## begin CCOMarkup::ElemPos%3FB3770D01C8.declarations preserve=yes
  //## end CCOMarkup::ElemPos%3FB3770D01C8.declarations

// Class CCOMarkup::TokenPos 





CCOMarkup::TokenPos::TokenPos()
  //## begin TokenPos::TokenPos%.hasinit preserve=no
  //## end TokenPos::TokenPos%.hasinit
  //## begin TokenPos::TokenPos%.initialization preserve=yes
  //## end TokenPos::TokenPos%.initialization
{
  //## begin CCOMarkup::TokenPos::TokenPos%.body preserve=yes
    Clear();
  //## end CCOMarkup::TokenPos::TokenPos%.body
}


CCOMarkup::TokenPos::~TokenPos()
{
  //## begin CCOMarkup::TokenPos::~TokenPos%.body preserve=yes
  //## end CCOMarkup::TokenPos::~TokenPos%.body
}



//## Other Operations (implementation)
bool CCOMarkup::TokenPos::IsValid () const
{
  //## begin CCOMarkup::TokenPos::IsValid%1068729242.body preserve=yes
    return (m_nL <= m_nR);
  //## end CCOMarkup::TokenPos::IsValid%1068729242.body
}

void CCOMarkup::TokenPos::Clear ()
{
  //## begin CCOMarkup::TokenPos::Clear%1068729243.body preserve=yes
    m_nL=0; m_nR=-1; m_bIsString=false;
  //## end CCOMarkup::TokenPos::Clear%1068729243.body
}

// Additional Declarations
  //## begin CCOMarkup::TokenPos%3FB3770D0204.declarations preserve=yes
  //## end CCOMarkup::TokenPos%3FB3770D0204.declarations

// Class CCOMarkup 








CCOMarkup::CCOMarkup()
  //## begin CCOMarkup::CCOMarkup%.hasinit preserve=no
  //## end CCOMarkup::CCOMarkup%.hasinit
  //## begin CCOMarkup::CCOMarkup%.initialization preserve=yes
  //## end CCOMarkup::CCOMarkup%.initialization
{
  //## begin CCOMarkup::CCOMarkup%.body preserve=yes
    SetDoc( NULL );
  //## end CCOMarkup::CCOMarkup%.body
}

CCOMarkup::CCOMarkup(const CCOMarkup &right)
  //## begin CCOMarkup::CCOMarkup%copy.hasinit preserve=no
  //## end CCOMarkup::CCOMarkup%copy.hasinit
  //## begin CCOMarkup::CCOMarkup%copy.initialization preserve=yes
  //## end CCOMarkup::CCOMarkup%copy.initialization
{
  //## begin CCOMarkup::CCOMarkup%copy.body preserve=yes
    *this = right;
  //## end CCOMarkup::CCOMarkup%copy.body
}

CCOMarkup::CCOMarkup (LPCTSTR szDoc)
  //## begin CCOMarkup::CCOMarkup%1068729245.hasinit preserve=no
  //## end CCOMarkup::CCOMarkup%1068729245.hasinit
  //## begin CCOMarkup::CCOMarkup%1068729245.initialization preserve=yes
  //## end CCOMarkup::CCOMarkup%1068729245.initialization
{
  //## begin CCOMarkup::CCOMarkup%1068729245.body preserve=yes
    SetDoc( szDoc );
  //## end CCOMarkup::CCOMarkup%1068729245.body
}


CCOMarkup::~CCOMarkup()
{
  //## begin CCOMarkup::~CCOMarkup%.body preserve=yes
  //## end CCOMarkup::~CCOMarkup%.body
}


const CCOMarkup & CCOMarkup::operator=(const CCOMarkup &right)
{
  //## begin CCOMarkup::operator=%.body preserve=yes
	m_iPos = right.m_iPos;
	m_iPosChild = right.m_iPosChild;
	m_iPosFree = right.m_iPosFree;
	m_aPos.RemoveAll();
	m_aPos.Append( right.m_aPos );
	m_nLevel = right.m_nLevel;
	m_csDoc = right.m_csDoc;

    return *this;
  //## end CCOMarkup::operator=%.body
}



//## Other Operations (implementation)
bool CCOMarkup::SetDoc (LPCTSTR szDoc)
{
  //## begin CCOMarkup::SetDoc%1068729249.body preserve=yes
	// Reset indexes
	m_iPosFree = 1;
	ResetPos();

	// Set document text
	if ( szDoc )
		m_csDoc = szDoc;
	else
		m_csDoc.Empty();

	// Starting size of position array: 1 element per 64 bytes of document
	// Tight fit when parsing small doc, only 0 to 2 reallocs when parsing large doc
	// Start at 8 when creating new document
	int nStartSize = m_csDoc.GetLength() / 64 + 8;
	if ( m_aPos.GetSize() < nStartSize )
		m_aPos.SetSize( nStartSize );

	// Parse document
	bool bWellFormed = false;
	if ( m_csDoc.GetLength() )
	{
		m_aPos[0].Clear();
		int iPos = x_ParseElem( 0 );
		if ( iPos > 0 )
		{
			m_aPos[0].m_iElemChild = iPos;
			bWellFormed = true;
		}
	}

	// Clear indexes if parse failed or empty document
	if ( ! bWellFormed )
	{
		m_aPos[0].Clear();
		m_iPosFree = 1;
	}

	ResetPos();
	return bWellFormed;
  //## end CCOMarkup::SetDoc%1068729249.body
}

bool CCOMarkup::IsWellFormed ()
{
  //## begin CCOMarkup::IsWellFormed%1068729250.body preserve=yes
	if ( m_aPos.GetSize() && m_aPos[0].m_iElemChild )
		return TRUE;
	return FALSE;
  //## end CCOMarkup::IsWellFormed%1068729250.body
}

bool CCOMarkup::FindElem (LPCTSTR szName)
{
  //## begin CCOMarkup::FindElem%1068729251.body preserve=yes
	// If szName is NULL or empty, go to next sibling element
	// Otherwise go to next sibling element with matching tag name
	// If the current position is valid, start looking from next
	// Change current position only if found
	//
	int iPos = m_iPos;
	if ( ! iPos )
	{
		if ( m_aPos.GetSize() )
			iPos = m_aPos[0].m_iElemChild;
	}
	else
	{
		iPos = m_aPos[iPos].m_iElemNext;
	}

	while ( iPos )
	{
		// Compare tag name unless szName is not specified
		if ( szName == NULL || !szName[0] || x_GetTagName(iPos) == szName )
		{
			// Assign new position
			m_iPos = iPos;
			m_iPosChild = 0;
			return true;
		}
		iPos = m_aPos[iPos].m_iElemNext;
	}
	return false;
  //## end CCOMarkup::FindElem%1068729251.body
}

bool CCOMarkup::FindChildElem (LPCTSTR szName)
{
  //## begin CCOMarkup::FindChildElem%1068729252.body preserve=yes
	// If szName is NULL or empty, go to next sibling child element
	// Otherwise go to next sibling child element with matching tag name
	// If the current child position is valid, start looking from next
	// Change current child position only if found
	//
	// Shorthand: call this with no current position means under root element
	if ( ! m_iPos )
		FindElem();

	// Is main position valid and not empty?
	if ( ! m_iPos || m_aPos[m_iPos].IsEmptyElement() )
		return false;

	// Is current child position valid?
	int iPosChild = m_iPosChild;
	if ( iPosChild )
		iPosChild = m_aPos[iPosChild].m_iElemNext;
	else
		iPosChild = m_aPos[m_iPos].m_iElemChild;

	// Search
	while ( iPosChild )
	{
		// Compare tag name unless szName is not specified
		if ( szName == NULL || !szName[0] || x_GetTagName(iPosChild) == szName )
		{
			// Assign new position
			m_iPosChild = iPosChild;
			return true;
		}
		iPosChild = m_aPos[iPosChild].m_iElemNext;
	}
	return false;
  //## end CCOMarkup::FindChildElem%1068729252.body
}

bool CCOMarkup::IntoElem ()
{
  //## begin CCOMarkup::IntoElem%1068729253.body preserve=yes
	if ( ! m_iPosChild )
		FindChildElem();

	if ( m_iPosChild )
	{
		m_iPos = m_iPosChild;
		m_iPosChild = 0;
		++m_nLevel;
		return true;
	}

	return false;
  //## end CCOMarkup::IntoElem%1068729253.body
}

bool CCOMarkup::OutOfElem ()
{
  //## begin CCOMarkup::OutOfElem%1068729254.body preserve=yes
	// Go to parent element
	if ( m_iPos && m_nLevel > 0 )
	{
		m_iPosChild = m_iPos;
		m_iPos = m_aPos[m_iPos].m_iElemParent;
		--m_nLevel;
		return true;
	}
	return false;
  //## end CCOMarkup::OutOfElem%1068729254.body
}

void CCOMarkup::ResetChildPos ()
{
  //## begin CCOMarkup::ResetChildPos%1068729255.body preserve=yes
  //## end CCOMarkup::ResetChildPos%1068729255.body
}

void CCOMarkup::ResetPos ()
{
  //## begin CCOMarkup::ResetPos%1068729256.body preserve=yes
	m_iPos = 0;
	m_iPosChild = 0;
	m_nLevel = 0;
  //## end CCOMarkup::ResetPos%1068729256.body
}

CString CCOMarkup::GetTagName ()
{
  //## begin CCOMarkup::GetTagName%1068729257.body preserve=yes
    return x_GetTagName(m_iPos);
  //## end CCOMarkup::GetTagName%1068729257.body
}

CString CCOMarkup::GetChildTagName ()
{
  //## begin CCOMarkup::GetChildTagName%1068729258.body preserve=yes
    return x_GetTagName(m_iPosChild);
  //## end CCOMarkup::GetChildTagName%1068729258.body
}

CString CCOMarkup::GetData ()
{
  //## begin CCOMarkup::GetData%1068729259.body preserve=yes
    return x_GetData(m_iPos);
  //## end CCOMarkup::GetData%1068729259.body
}

CString CCOMarkup::GetChildData ()
{
  //## begin CCOMarkup::GetChildData%1068729260.body preserve=yes
    return x_GetData(m_iPosChild);
  //## end CCOMarkup::GetChildData%1068729260.body
}

CString CCOMarkup::GetAttrib (LPCTSTR szAttrib)
{
  //## begin CCOMarkup::GetAttrib%1068729261.body preserve=yes
    return x_GetAttrib(m_iPos,szAttrib);
  //## end CCOMarkup::GetAttrib%1068729261.body
}

CString CCOMarkup::GetChildAttrib (LPCTSTR szAttrib)
{
  //## begin CCOMarkup::GetChildAttrib%1068729262.body preserve=yes
    return x_GetAttrib(m_iPosChild,szAttrib);
  //## end CCOMarkup::GetChildAttrib%1068729262.body
}

bool CCOMarkup::GetOffsets (int& nStart, int& nEnd)
{
  //## begin CCOMarkup::GetOffsets%1068729263.body preserve=yes
	// Return document offsets of current main position element
	// This is not part of EDOM but is used by the Markup project
	if ( m_iPos )
	{
		nStart = m_aPos[m_iPos].m_nStartL;
		nEnd = m_aPos[m_iPos].m_nEndR;
		return true;
	}
	return false;
  //## end CCOMarkup::GetOffsets%1068729263.body
}

CString CCOMarkup::GetError ()
{
  //## begin CCOMarkup::GetError%1068729264.body preserve=yes
    return m_csError;
  //## end CCOMarkup::GetError%1068729264.body
}

CString CCOMarkup::GetDoc ()
{
  //## begin CCOMarkup::GetDoc%1068729265.body preserve=yes
    return m_csDoc;
  //## end CCOMarkup::GetDoc%1068729265.body
}

bool CCOMarkup::AddElem (LPCTSTR szName, LPCTSTR szValue)
{
  //## begin CCOMarkup::AddElem%1068729266.body preserve=yes
	// Add an element after current main position
	int iPosParent = m_iPos? m_aPos[m_iPos].m_iElemParent : 0;
	m_iPosChild = 0;

	// Setting root element?
	if ( iPosParent == 0 )
	{
		if ( IsWellFormed() )
			return false;

		m_csDoc.Empty();
	}

	m_iPos = x_Add( iPosParent, m_iPos, szName, szValue );
	return true;
  //## end CCOMarkup::AddElem%1068729266.body
}

bool CCOMarkup::AddChildElem (LPCTSTR szName, LPCTSTR szValue)
{
  //## begin CCOMarkup::AddChildElem%1068729267.body preserve=yes
	// Add a child element under main position, after current child position
	if ( ! m_iPos )
		return false;

	// If no child position, add after last sibling
	int iPosLast = m_aPos[m_iPos].m_iElemChild;
	if ( ! m_iPosChild && iPosLast )
	{
		m_iPosChild = iPosLast;
		while ( (iPosLast=m_aPos[iPosLast].m_iElemNext) != 0 )
			m_iPosChild = iPosLast;
	}

	m_iPosChild = x_Add( m_iPos, m_iPosChild, szName, szValue );
	return true;
  //## end CCOMarkup::AddChildElem%1068729267.body
}

bool CCOMarkup::AddAttrib (LPCTSTR szAttrib, LPCTSTR szValue)
{
  //## begin CCOMarkup::AddAttrib%1068729268.body preserve=yes
	// Add attribute to current main position element
	if ( m_iPos )
	{
		x_AddAttrib( m_iPos, szAttrib, szValue );
		return true;
	}
	return false;
  //## end CCOMarkup::AddAttrib%1068729268.body
}

bool CCOMarkup::AddChildAttrib (LPCTSTR szAttrib, LPCTSTR szValue)
{
  //## begin CCOMarkup::AddChildAttrib%1068729269.body preserve=yes
	// Add attribute to current child position element
	if ( m_iPosChild )
	{
		x_AddAttrib( m_iPosChild, szAttrib, szValue );
		return true;
	}
	return false;
  //## end CCOMarkup::AddChildAttrib%1068729269.body
}

int CCOMarkup::x_GetFreePos ()
{
  //## begin CCOMarkup::x_GetFreePos%1068729270.body preserve=yes
	//
	// This returns the index of the next unused ElemPos in the array
	//
	if ( m_iPosFree == m_aPos.GetSize() )
		m_aPos.SetSize( m_iPosFree + m_iPosFree / 2 );
	++m_iPosFree;
	return m_iPosFree - 1;
  //## end CCOMarkup::x_GetFreePos%1068729270.body
}

int CCOMarkup::x_ReleasePos ()
{
  //## begin CCOMarkup::x_ReleasePos%1068729271.body preserve=yes
	//
	// This decrements the index of the next unused ElemPos in the array
	// allowing the element index returned by GetFreePos() to be reused
	//
	--m_iPosFree;
	return 0;
  //## end CCOMarkup::x_ReleasePos%1068729271.body
}

int CCOMarkup::x_ParseElem (int iPosParent)
{
  //## begin CCOMarkup::x_ParseElem%1068729272.body preserve=yes
	// This is either called by SetDoc, x_AddSubDoc, or itself recursively
	// m_aPos[iPosParent].m_nEndL is where to start parsing for the child element
	// This returns the new position if a tag is found, otherwise zero
	// In all cases we need to get a new ElemPos, but release it if unused
	//
	int iPos = x_GetFreePos();
	m_aPos[iPos].m_nStartL = m_aPos[iPosParent].m_nEndL;
	m_aPos[iPos].m_nNext = m_aPos[iPosParent].m_nStartR + 1;
	m_aPos[iPos].m_iElemParent = iPosParent;
	m_aPos[iPos].m_iElemChild = 0;
	m_aPos[iPos].m_iElemNext = 0;

	// Start Tag
	// A loop is used to ignore all remarks tags and special tags
	// i.e. <?xml version="1.0"?>, and <!-- comment here -->
	// So any tag beginning with ? or ! is ignored
	// Loop past ignored tags
	TokenPos token;
	token.m_nNext = m_aPos[iPosParent].m_nEndL;
	CString csName;
	while ( csName.IsEmpty() )
	{
		// Look for left angle bracket of start tag
		m_aPos[iPos].m_nStartL = token.m_nNext;
		if ( ! x_FindChar( m_aPos[iPos].m_nStartL, _T('<') ) )
			return x_ParseError( _T("Element tag not found") );

		// Set parent's End tag to start looking from here (or later)
		m_aPos[iPosParent].m_nEndL = m_aPos[iPos].m_nStartL;

		// Determine whether this is an element, comment or version tag
		LPCTSTR szEndOfTag = NULL;
		token.m_nNext = m_aPos[iPos].m_nStartL + 1;
		if ( x_FindToken( token ) )
		{
			if ( token.m_bIsString )
				return x_ParseError( _T("Tag starts with quote") );
			TCHAR cFirstChar = m_csDoc[token.m_nL];
			if ( cFirstChar == _T('?') )
				szEndOfTag = _T("?>"); // version
			else if ( cFirstChar == _T('!') )
			{
				TCHAR cSecondChar = 0;
				if ( token.m_nL+1 < m_csDoc.GetLength() )
					cSecondChar = m_csDoc[token.m_nL+1];
				if ( cSecondChar == _T('[') )
					szEndOfTag = _T("]]>"); // CDATA section
				else if ( cSecondChar == _T('-') )
					szEndOfTag = _T("-->"); // comment
				else
					szEndOfTag = _T(">"); // DTD
			}
			else if ( cFirstChar != _T('/') )
			{
				csName = x_GetToken( token );
				szEndOfTag = _T(">");
			}
			else
				return x_ReleasePos(); // probably end tag of parent
		}
		else
			return x_ParseError( _T("Abrupt end within tag") );

		// Look for end of tag
		token.m_nNext = m_csDoc.Find( szEndOfTag, token.m_nNext );
		if ( token.m_nNext == -1 )
			return x_ParseError( _T("End of tag not found") );
	}
	m_aPos[iPos].m_nStartR = token.m_nNext;

	// Is ending mark within start tag, i.e. empty element?
	if ( m_csDoc[m_aPos[iPos].m_nStartR-1] == _T('/') )
	{
		// Empty element
		// Close tag left is set to ending mark, and right to open tag right
		m_aPos[iPos].m_nEndL = m_aPos[iPos].m_nStartR-1;
		m_aPos[iPos].m_nEndR = m_aPos[iPos].m_nStartR;
	}
	else // look for end tag
	{
		// Element probably has contents
		// Determine where to start looking for left angle bracket of end tag
		// This is done by recursively parsing the contents of this element
		int iInner, iInnerPrev = 0;
		m_aPos[iPos].m_nEndL = m_aPos[iPos].m_nStartR + 1;
		while ( (iInner = x_ParseElem( iPos )) > 0 )
		{
			// Set links to iInner
			if ( iInnerPrev )
				m_aPos[iInnerPrev].m_iElemNext = iInner;
			else
				m_aPos[iPos].m_iElemChild = iInner;
			iInnerPrev = iInner;

			// Set offset to reflect child
			m_aPos[iPos].m_nEndL = m_aPos[iInner].m_nEndR + 1;
		}
		if ( iInner == -1 )
			return -1;

		// Look for left angle bracket of end tag
		if ( ! x_FindChar( m_aPos[iPos].m_nEndL, _T('<') ) )
			return x_ParseError( _T("End tag of %s element not found"), csName );

		// Look through tokens of end tag
		token.m_nNext = m_aPos[iPos].m_nEndL + 1;
		int nTokenCount = 0;
		while ( x_FindToken( token ) )
		{
			++nTokenCount;
			if ( ! token.m_bIsString )
			{
				// Is first token not an end slash mark?
				if ( nTokenCount == 1 && m_csDoc[token.m_nL] != _T('/') )
					return x_ParseError( _T("Expecting end tag of element %s"), csName );

				else if ( nTokenCount == 2 && csName != x_GetToken( token ) )
					return x_ParseError( _T("End tag does not correspond to %s"), csName );

				// Else is it a right angle bracket?
				else if ( m_csDoc[token.m_nL] == _T('>') )
					break;
			}
		}

		// Was a right angle bracket not found?
		if ( ! token.IsValid() || nTokenCount < 2 )
			return x_ParseError( _T("End tag not completed for element %s"), csName );
		m_aPos[iPos].m_nEndR = token.m_nL;
	}

	// Successfully found positions of angle brackets
	m_aPos[iPos].m_nNext = m_aPos[iPos].m_nEndR;
	x_FindChar( m_aPos[iPos].m_nNext, _T('<') );
	return iPos;
  //## end CCOMarkup::x_ParseElem%1068729272.body
}

int CCOMarkup::x_ParseError (LPCTSTR szError, LPCTSTR szTag)
{
  //## begin CCOMarkup::x_ParseError%1068729273.body preserve=yes
	if ( szTag )
		m_csError.Format( szError, szTag );
	else
		m_csError = szError;
	x_ReleasePos();
	return -1;
  //## end CCOMarkup::x_ParseError%1068729273.body
}

bool CCOMarkup::x_FindChar (int& n, _TCHAR c)
{
  //## begin CCOMarkup::x_FindChar%1068729274.body preserve=yes
	// Look for char c starting at n, and set n to point to it
	// c is always the first char of a multi-byte char
	// Return false if not found before end of document
	LPCTSTR szDoc = (LPCTSTR)m_csDoc;
	while ( szDoc[n] && szDoc[n] != c )
		n += _tclen( &szDoc[n] );
	if ( ! szDoc[n] )
		return false;
	return true;
  //## end CCOMarkup::x_FindChar%1068729274.body
}

bool CCOMarkup::x_FindToken (TokenPos& token)
{
  //## begin CCOMarkup::x_FindToken%1068729275.body preserve=yes
	// Starting at token.m_nNext, find the next token
	// upon successful return, token.m_nNext points after the retrieved token
	LPCTSTR szDoc = (LPCTSTR)m_csDoc;
	int n = token.m_nNext;

	// Statically defined CStrings for whitespace and special chars
	static CString csWhitespace = _T(" \t\n\r");
	static CString csSpecial = _T("<>=\\/?!");

	// By-pass leading whitespace
	while ( szDoc[n] && csWhitespace.Find(szDoc[n]) > -1 )
		++n;

	// Are we still within the document?
	token.m_bIsString = false;
	if ( szDoc[n] )
	{
		// Is it an opening quote?
		if ( szDoc[n] == _T('\"') )
		{
			// Move past opening quote
			++n;
			token.m_nL = n;

			// Look for closing quote
			x_FindChar( n, _T('\"') );

			// Set right to before closing quote
			token.m_nR = n-1;

			// Set n past closing quote unless at end of document
			if ( szDoc[n] )
				++n;

			// Set flag
			token.m_bIsString = true;
		}
		else
		{
			// Go until special char or whitespace
			token.m_nL = n;
			while ( szDoc[n] &&
				csSpecial.Find(m_csDoc[n]) == -1 &&
				csWhitespace.Find(m_csDoc[n]) == -1
				)
				n += _tclen(&szDoc[n]);

			// Adjust end position if it is one special char
			if ( n == token.m_nL )
				++n; // it is a special char
			token.m_nR = n-1;
		}
	}

	token.m_nNext = n;
	if ( ! szDoc[n] )
		return false;

	// m_nNext points to one past last char of token
	return true;
  //## end CCOMarkup::x_FindToken%1068729275.body
}

CString CCOMarkup::x_GetToken (const TokenPos& token)
{
  //## begin CCOMarkup::x_GetToken%1068729276.body preserve=yes
	// The token contains indexes into the document identifying a small substring
	// Build the substring from those indexes and return it
	if ( ! token.IsValid() )
		return _T("");
	return m_csDoc.Mid( token.m_nL,
		token.m_nR - token.m_nL + ((token.m_nR<m_csDoc.GetLength())? 1:0) );
  //## end CCOMarkup::x_GetToken%1068729276.body
}

CString CCOMarkup::x_GetTagName (int iPos)
{
  //## begin CCOMarkup::x_GetTagName%1068729277.body preserve=yes
	// Return the tag name at specified element
	TokenPos token;
	token.m_nNext = m_aPos[iPos].m_nStartL + 1;
	if ( ! iPos || ! x_FindToken( token ) )
		return _T("");

	// Return substring of document
	return x_GetToken( token );
  //## end CCOMarkup::x_GetTagName%1068729277.body
}

CString CCOMarkup::x_GetData (int iPos)
{
  //## begin CCOMarkup::x_GetData%1068729278.body preserve=yes
	// Return a string representing data between start and end tag
	// Return empty string if there are any children elements
	if ( ! m_aPos[iPos].m_iElemChild && ! m_aPos[iPos].IsEmptyElement() )
	{
		// See if it is a CDATA section
		TokenPos token;
		token.m_nNext = m_aPos[iPos].m_nStartR+1;
		if ( x_FindToken( token ) && m_csDoc[token.m_nL] == _T('<')
				&& token.m_nL + 11 < m_aPos[iPos].m_nEndL
				&& _tcsncmp( &((LPCTSTR)m_csDoc)[token.m_nL+1], _T("![CDATA["), 8 ) == 0 )
		{
			int nEndCDATA = m_csDoc.Find( _T("]]>"), token.m_nNext );
			if ( nEndCDATA != -1 && nEndCDATA < m_aPos[iPos].m_nEndL )
			{
				return m_csDoc.Mid( token.m_nL+9, nEndCDATA-token.m_nL-9 );
			}
		}
		return x_TextFromDoc( m_aPos[iPos].m_nStartR+1, m_aPos[iPos].m_nEndL-1 );
	}
	return "";
  //## end CCOMarkup::x_GetData%1068729278.body
}

CString CCOMarkup::x_GetAttrib (int iPos, LPCTSTR szAttrib)
{
  //## begin CCOMarkup::x_GetAttrib%1068729279.body preserve=yes
	// Return the value of the attrib at specified element
	TokenPos token;
	token.m_nNext = m_aPos[iPos].m_nStartL + 1;
	if ( szAttrib && x_FindAttrib( token, szAttrib ) )
		return x_TextFromDoc( token.m_nL, token.m_nR - ((token.m_nR<m_csDoc.GetLength())?0:1) );
	return _T("");
  //## end CCOMarkup::x_GetAttrib%1068729279.body
}

int CCOMarkup::x_Add (int iPosParent, int iPosBefore, LPCTSTR szName, LPCTSTR szValue)
{
  //## begin CCOMarkup::x_Add%1068729280.body preserve=yes
	// Create element and modify positions of affected elements
	// if iPosBefore is NULL, insert as first element under parent
	// If no szValue is specified, an empty element is created
	// i.e. either <NAME>value</NAME> or <NAME/>
	//
	int iPos = x_GetFreePos();
	bool bEmptyParent = false;
	if ( iPosBefore )
	{
		// Follow iPosBefore
		m_aPos[iPos].m_nStartL = m_aPos[iPosBefore].m_nNext;
	}
	else if ( m_aPos[iPosParent].m_iElemChild )
	{
		// Insert before first child of parent
		m_aPos[iPos].m_nStartL = m_aPos[m_aPos[iPosParent].m_iElemChild].m_nStartL;
	}
	else if ( m_aPos[iPosParent].IsEmptyElement() )
	{
		// Parent has no separate end tag
		m_aPos[iPos].m_nStartL = m_aPos[iPosParent].m_nStartR + 2;
		bEmptyParent = true;
	}
	else
	{
		// Parent has content, but no children
		m_aPos[iPos].m_nStartL = m_aPos[iPosParent].m_nEndL;
	}

	// Set links
	m_aPos[iPos].m_iElemParent = iPosParent;
	m_aPos[iPos].m_iElemChild = 0;
	if ( iPosBefore )
	{
		m_aPos[iPos].m_iElemNext = m_aPos[iPosBefore].m_iElemNext;
		m_aPos[iPosBefore].m_iElemNext = iPos;
	}
	else
	{
		m_aPos[iPos].m_iElemNext = m_aPos[iPosParent].m_iElemChild;
		m_aPos[iPosParent].m_iElemChild = iPos;
	}

	// Create string for insert
	CString csInsert;
	int nLenName = _tcslen(szName);
	int nLenValue = szValue? _tcslen(szValue) : 0;
	if ( ! nLenValue )
	{
		// <NAME/> empty element
		csInsert.Format( _T("<%s/>\r\n"), szName );
		m_aPos[iPos].m_nStartR = m_aPos[iPos].m_nStartL + nLenName + 2;
		m_aPos[iPos].m_nEndL = m_aPos[iPos].m_nStartR - 1;
		m_aPos[iPos].m_nEndR = m_aPos[iPos].m_nEndL + 1;
		m_aPos[iPos].m_nNext = m_aPos[iPos].m_nEndR + 3;
	}
	else
	{
		// <NAME>value</NAME>
		CString csValue = x_TextToDoc( szValue );
		nLenValue = csValue.GetLength();
		csInsert.Format( _T("<%s>%s</%s>\r\n"), szName, csValue, szName );
		m_aPos[iPos].m_nStartR = m_aPos[iPos].m_nStartL + nLenName + 1;
		m_aPos[iPos].m_nEndL = m_aPos[iPos].m_nStartR + nLenValue + 1;
		m_aPos[iPos].m_nEndR = m_aPos[iPos].m_nEndL + nLenName + 2;
		m_aPos[iPos].m_nNext = m_aPos[iPos].m_nEndR + 3;
	}

	// Insert
	int nReplace = 0, nLeft = m_aPos[iPos].m_nStartL;
	if ( bEmptyParent )
	{
		CString csParentTagName = x_GetTagName(iPosParent);
		csInsert = _T(">\r\n") + csInsert + _T("</") + csParentTagName;
		nLeft -= 3;
		nReplace = 1;
		// x_Adjust is going to update all affected indexes by one amount
		// This will satisfy all except the empty parent
		// Here we pre-adjust for the empty parent
		// The empty tag slash is removed
		m_aPos[iPosParent].m_nStartR -= 1;
		// For the newly created end tag, see the following example:
		// <A/> (len 4) becomes <A><B/></A> (len 11)
		// In x_Adjust everything will be adjusted 11 - 4 = 7
		// But the m_nEndL of element A should only be adjusted 5
		m_aPos[iPosParent].m_nEndL -= (csParentTagName.GetLength() + 1);
	}
	x_DocChange( nLeft, nReplace, csInsert );
	x_Adjust( iPos, csInsert.GetLength() - nReplace );

	// Return the index of the new element
	return iPos;
  //## end CCOMarkup::x_Add%1068729280.body
}

bool CCOMarkup::x_FindAttrib (TokenPos& token, LPCTSTR szAttrib)
{
  //## begin CCOMarkup::x_FindAttrib%1068729281.body preserve=yes
	// If szAttrib is NULL find next attrib, otherwise find named attrib
	// Return true if found
	int nAttrib = 0;
	for ( int nCount = 0; x_FindToken(token); ++nCount )
	{
		if ( ! token.m_bIsString )
		{
			// Is it the right angle bracket?
			if ( m_csDoc[token.m_nL] == _T('>') || m_csDoc[token.m_nL] == _T('/') )
				break; // attrib not found

			// Equal sign
			if ( m_csDoc[token.m_nL] == _T('=') )
				continue;

			// Potential attribute
			if ( ! nAttrib && nCount )
			{
				// Attribute name search?
				if ( ! szAttrib || ! szAttrib[0] )
					return true; // return with token at attrib name

				// Compare szAttrib
				if ( x_GetToken(token) == szAttrib )
					nAttrib = nCount;
			}
		}
		else if ( nAttrib && nCount == nAttrib + 2 )
		{
			return true;
		}
	}

	// Not found
	return false;
  //## end CCOMarkup::x_FindAttrib%1068729281.body
}

int CCOMarkup::x_AddAttrib (int iPos, LPCTSTR szAttrib, LPCTSTR szValue)
{
  //## begin CCOMarkup::x_AddAttrib%1068729282.body preserve=yes
	// Add attribute to iPos element
	CString csInsert;
	if ( iPos )
	{
		// Insert string taking into account whether it is a single tag
		CString csValue = x_TextToDoc( szValue, true );
		csInsert.Format( _T(" %s=\"%s\""), szAttrib, csValue );
		int m_nL = m_aPos[iPos].m_nStartR - (m_aPos[iPos].IsEmptyElement()?1:0);
		x_DocChange( m_nL, 0, csInsert );

		int nLen = csInsert.GetLength();
		m_aPos[iPos].m_nStartR += nLen;
		m_aPos[iPos].m_nEndL += nLen;
		m_aPos[iPos].m_nEndR += nLen;
		m_aPos[iPos].m_nNext += nLen;
		x_Adjust( iPos, nLen );
	}
	return csInsert.GetLength();
  //## end CCOMarkup::x_AddAttrib%1068729282.body
}

int CCOMarkup::x_SetAttrib (int iPos, LPCTSTR szAttrib, LPCTSTR szValue)
{
  //## begin CCOMarkup::x_SetAttrib%1068729283.body preserve=yes
    return 0;
  //## end CCOMarkup::x_SetAttrib%1068729283.body
}

bool CCOMarkup::x_SetData (int iPos, LPCTSTR szData, int nCDATA)
{
  //## begin CCOMarkup::x_SetData%1068729284.body preserve=yes
    return false;
  //## end CCOMarkup::x_SetData%1068729284.body
}

void CCOMarkup::x_DocChange (int nLeft, int nReplace, const CString& csInsert)
{
  //## begin CCOMarkup::x_DocChange%1068729285.body preserve=yes
	// Insert csInsert int m_csDoc at nLeft replacing nReplace chars
	// Do this with only one buffer reallocation if it grows
	//
	int nDocLength = m_csDoc.GetLength();
	int nInsLength = csInsert.GetLength();

	// Make sure nLeft and nReplace are within bounds
	nLeft = max( 0, min( nLeft, nDocLength ) );
	nReplace = max( 0, min( nReplace, nDocLength-nLeft ) );

	// Get pointer to buffer with enough room
	int nNewLength = nInsLength + nDocLength - nReplace;
	int nBufferLen = nNewLength;
	_TCHAR* pDoc = m_csDoc.GetBuffer( nBufferLen );

	// Move part of old doc that goes after insert
	if ( nLeft+nReplace < nDocLength )
		memmove( &pDoc[nLeft+nInsLength], &pDoc[nLeft+nReplace], (nDocLength-nLeft-nReplace)*sizeof(_TCHAR) );

	// Copy insert
	memcpy( &pDoc[nLeft], csInsert, nInsLength*sizeof(_TCHAR) );

	// Release
	m_csDoc.ReleaseBuffer( nNewLength );
  //## end CCOMarkup::x_DocChange%1068729285.body
}

void CCOMarkup::x_PosInsert (int iPos, int nInsertLength)
{
  //## begin CCOMarkup::x_PosInsert%1068729286.body preserve=yes
  //## end CCOMarkup::x_PosInsert%1068729286.body
}

void CCOMarkup::x_Adjust (int iPos, int nShift)
{
  //## begin CCOMarkup::x_Adjust%1068729287.body preserve=yes
	// Loop through affected elements and adjust indexes
	// Does not affect iPos itself
	// Algorithm:
	// 1. update next siblings and all their children
	// 2. then go up a level update end points and to step 1
	int iPosTop = m_aPos[iPos].m_iElemParent;
	while ( iPos )
	{
		// Were we at containing parent of affected position?
		bool bPosTop = false;
		if ( iPos == iPosTop )
		{
			// Move iPosTop up one towards root
			iPosTop = m_aPos[iPos].m_iElemParent;
			bPosTop = true;
		}

		// Traverse to the next update position
		if ( ! bPosTop && m_aPos[iPos].m_iElemChild )
		{
			// Depth first
			iPos = m_aPos[iPos].m_iElemChild;
		}
		else if ( m_aPos[iPos].m_iElemNext )
		{
			iPos = m_aPos[iPos].m_iElemNext;
		}
		else
		{
			// Look for next sibling of a parent of iPos
			// When going back up, parents have already been done except iPosTop
			while ( (iPos=m_aPos[iPos].m_iElemParent) != 0 && iPos != iPosTop )
				if ( m_aPos[iPos].m_iElemNext )
				{
					iPos = m_aPos[iPos].m_iElemNext;
					break;
				}
		}

		// Shift indexes at iPos
		if ( iPos != iPosTop )
		{
			// Move the start tag indexes
			// Don't do this for containing parent tag
			m_aPos[iPos].m_nStartL += nShift;
			m_aPos[iPos].m_nStartR += nShift;
		}
		// Move end tag indexes
		m_aPos[iPos].m_nEndL += nShift;
		m_aPos[iPos].m_nEndR += nShift;
		m_aPos[iPos].m_nNext += nShift;
	}
  //## end CCOMarkup::x_Adjust%1068729287.body
}

CString CCOMarkup::x_TextToDoc (LPCTSTR szText, bool bAttrib)
{
  //## begin CCOMarkup::x_TextToDoc%1068729288.body preserve=yes
	// Convert text as seen outside XML document to XML friendly
	// replacing special characters with ampersand escape codes
	// E.g. convert "6>7" to "6&gt;7"
	//
	// &lt;   less than
	// &amp;  ampersand
	// &gt;   greater than
	//
	// and for attributes:
	//
	// &apos; apostrophe or single quote
	// &quot; double quote
	//
	static _TCHAR* szaReplace[] = { _T("&lt;"),_T("&amp;"),_T("&gt;"),_T("&apos;"),_T("&quot;") };
	const _TCHAR* pFind = bAttrib?_T("<&>\'\""):_T("<&>");
	CString csText;
	const _TCHAR* pSource = szText;
	int nDestSize = _tcslen(pSource);
	nDestSize += nDestSize / 10 + 7;
	_TCHAR* pDest = csText.GetBuffer(nDestSize);
	int nLen = 0;
	_TCHAR cSource = *pSource;
	_TCHAR* pFound;
	while ( cSource )
	{
		if ( nLen > nDestSize - 6 )
		{
			csText.ReleaseBuffer(nLen);
			nDestSize *= 2;
			pDest = csText.GetBuffer(nDestSize);
		}

		//if ( (pFound=_tcschr(pFind,cSource)) != NULL ) 
		if ( (pFound=(_TCHAR*)_tcschr(pFind,cSource)) != NULL ) //scch
		{
			pFound = szaReplace[pFound-pFind];
			_tcscpy(&pDest[nLen],pFound);
			nLen += _tcslen(pFound);
		}
		else
		{
			_tccpy( &pDest[nLen], pSource );
			++nLen;
		}
		pSource += _tclen( pSource );
		cSource = *pSource;
	}
	csText.ReleaseBuffer(nLen);
	return csText;
  //## end CCOMarkup::x_TextToDoc%1068729288.body
}

CString CCOMarkup::x_TextFromDoc (int nLeft, int nRight)
{
  //## begin CCOMarkup::x_TextFromDoc%1068729289.body preserve=yes
	// Convert XML friendly text to text as seen outside XML document
	// replacing ampersand escape codes with special characters
	// E.g. convert "6&gt;7" to "6>7"
	//
	// Conveniently the result is always the same or shorter in length
	//
	static _TCHAR* szaCode[] = { _T("lt;"),_T("amp;"),_T("gt;"),_T("apos;"),_T("quot;") };
	static int anCodeLen[] = { 3,4,3,5,5 };
	static _TCHAR* szSymbol = _T("<&>\'\"");
	CString csText;
	const _TCHAR* pSource = m_csDoc;
	int nDestSize = nRight - nLeft + 1;
	_TCHAR* pDest = csText.GetBuffer(nDestSize);
	int nLen = 0;
	int nCharLen;
	int nChar = nLeft;
	int nMatch; //scch
	while ( nChar <= nRight )
	{
		if ( pSource[nChar] == _T('&') )
		{
			// Look for matching &code;
			//for ( int nMatch = 0; nMatch < 5; ++nMatch )
			for ( nMatch = 0; nMatch < 5; ++nMatch )
			{
				if ( nChar <= nRight - anCodeLen[nMatch]
					&& _tcsncmp(szaCode[nMatch],&pSource[nChar+1],anCodeLen[nMatch]) == 0 )
				{
					pDest[nLen++] = szSymbol[nMatch];
					nChar += anCodeLen[nMatch] + 1;
					break;
				}
			}

			// If no match is found it means XML doc is invalid
			// no devastating harm done, ampersand code will just be left in result
			if ( nMatch == 5 )
			{
				pDest[nLen++] = _T('&');
				++nChar;
			}
		}
		else
		{
			nCharLen = _tclen(&pSource[nChar]);
			_tccpy( &pDest[nLen], &pSource[nChar] );
			nLen += nCharLen;
			nChar += nCharLen;
		}
	}
	csText.ReleaseBuffer(nLen);
	return csText;
  //## end CCOMarkup::x_TextFromDoc%1068729289.body
}

// Additional Declarations
  //## begin CCOMarkup%3FB3770D001D.declarations preserve=yes
  //## end CCOMarkup%3FB3770D001D.declarations

//## begin module%3FB3834C015F.epilog preserve=yes
//## end module%3FB3834C015F.epilog


