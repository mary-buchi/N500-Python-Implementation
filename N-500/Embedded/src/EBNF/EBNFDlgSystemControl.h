#if !defined(AFX_DLGSYSTEMCONTROL_H__5329DAE4_E87C_4E73_9753_6391724B9DC1__INCLUDED_)
#define AFX_DLGSYSTEMCONTROL_H__5329DAE4_E87C_4E73_9753_6391724B9DC1__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSystemControl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgSystemControl dialog

class DlgSystemControl : public CDialog
{
// Construction
public:
	DlgSystemControl(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSystemControl)
	enum { IDD = IDD_DLG_SYSTEM };
	CString	m_sSystemState;
	CString	m_sSysConnState;
	CString	m_sVersion;
	CString	m_sFPGAVersion;
	CString	m_sOsVersion;
	CString	m_sIPAddress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSystemControl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

    UINT  m_uiTimerID;

    CString GetSoftwareVersion();
	CString GetIPAddress();

	// Generated message map functions
	//{{AFX_MSG(DlgSystemControl)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
    afx_msg void OnTimer(UINT nIDEvent);
    afx_msg void OnDestroy();
	afx_msg void OnBtnSysConnectionEstablished();
	afx_msg void OnBtnSysConnectionLost();
	afx_msg void OnBtnSysDlSwComp();
	afx_msg void OnBtnSysReadIdentifications();
	afx_msg void OnBtnSysReadSwVersions();
	afx_msg void OnBtnSysResetDevice();
	afx_msg void OnBtnSysSetIfConfig();
	afx_msg void OnBtnSysStartDevice();
	afx_msg void OnBtnSysWriteIdentifications();
	afx_msg void OnBtnSysComponentState();
	afx_msg void OnBtnSysDlSwTraceSync();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMCONTROL_H__5329DAE4_E87C_4E73_9753_6391724B9DC1__INCLUDED_)
