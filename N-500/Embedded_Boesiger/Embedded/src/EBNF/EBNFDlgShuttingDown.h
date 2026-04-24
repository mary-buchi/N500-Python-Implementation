#if !defined(AFX_EBNFDLGSHUTTINGDOWN_H__33AD1D5A_EF07_4BB3_997B_A4B2CCB3BCC5__INCLUDED_)
#define AFX_EBNFDLGSHUTTINGDOWN_H__33AD1D5A_EF07_4BB3_997B_A4B2CCB3BCC5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EBNFDlgShuttingDown.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgShuttingDown dialog

class CDlgShuttingDown : public CDialog
{
// Construction
public:
	CDlgShuttingDown(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgShuttingDown)
	enum { IDD = IDD_DIALOG_SHUTDOWN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgShuttingDown)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgShuttingDown)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EBNFDLGSHUTTINGDOWN_H__33AD1D5A_EF07_4BB3_997B_A4B2CCB3BCC5__INCLUDED_)
