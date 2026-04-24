#if !defined(AFX_DLGWCSETPROFILE_H__C8C4F90C_EBFE_4E61_917E_367C92C3253D__INCLUDED_)
#define AFX_DLGWCSETPROFILE_H__C8C4F90C_EBFE_4E61_917E_367C92C3253D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgWCSetProfile.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgWCSetProfile dialog

class DlgWCSetProfile : public CDialog
{
// Construction
public:
	DlgWCSetProfile(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgWCSetProfile)
	enum { IDD = IDD_DLG_SET_WC_PROFILE };
	DWORD	m_dw01NomAcc;
	DWORD	m_dw02NomDec;
	DWORD	m_dw03NomVelocity;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgWCSetProfile)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgWCSetProfile)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnWcprofileSetDefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWCSETPROFILE_H__C8C4F90C_EBFE_4E61_917E_367C92C3253D__INCLUDED_)
