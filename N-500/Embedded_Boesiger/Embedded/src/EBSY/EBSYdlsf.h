#if !defined(AFX_SYDIALOGSTARTUPFAILURE_H__E2BDBA03_1E29_437D_9D5B_CA34B297CCB1__INCLUDED_)
#define AFX_SYDIALOGSTARTUPFAILURE_H__E2BDBA03_1E29_437D_9D5B_CA34B297CCB1__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SYDialogStartupFailure.h : header file
//

#include "EBSY_res.h"

/////////////////////////////////////////////////////////////////////////////
// CSYDialogStartupFailure dialog

class CSYDialogStartupFailure : public CDialog
{
// Construction
public:
	CSYDialogStartupFailure(const CString& p_sMsg);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSYDialogStartupFailure)
	enum { IDD = IDD_DIALOG_STARTUP_FAILURE };
	CString	m_sDisplayedText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSYDialogStartupFailure)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_sMsg;

	// Generated message map functions
	//{{AFX_MSG(CSYDialogStartupFailure)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYDIALOGSTARTUPFAILURE_H__E2BDBA03_1E29_437D_9D5B_CA34B297CCB1__INCLUDED_)
