// TestCE.h : main header file for the TESTCE application
//

#if !defined(AFX_TESTCE_H__7330E473_B706_4684_9939_83A3328EE1FE__INCLUDED_)
#define AFX_TESTCE_H__7330E473_B706_4684_9939_83A3328EE1FE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestCEApp:
// See TestCE.cpp for the implementation of this class
//

class CTestCEApp : public CWinApp
{
public:
	CTestCEApp();
	virtual ~CTestCEApp();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestCEApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCE_H__7330E473_B706_4684_9939_83A3328EE1FE__INCLUDED_)
