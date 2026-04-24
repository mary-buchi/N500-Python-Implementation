#if !defined(AFX_DLGSETGETDWORD_H__4B2E5D2A_CA35_461C_8883_AF3637E45D49__INCLUDED_)
#define AFX_DLGSETGETDWORD_H__4B2E5D2A_CA35_461C_8883_AF3637E45D49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSetGetDWord.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetGetDWord dialog
class IHIInterface;
class CCOSyncObject;

class CDlgSetGetDWord : public CDialog
{
// Construction
public:
	CDlgSetGetDWord(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetGetDWord)
	enum { IDD = IDD_DLG_SETGET };
	DWORD	m_dwGetDWord;
	DWORD	m_dwLogId;
	DWORD	m_dwSetDWord;
	DWORD	m_dwPCIAdrRead;
	DWORD	m_dwPCIAdrWrite;
	DWORD	m_dwPCIValRead;
	DWORD	m_dwPCIValWrite;
	double	m_dTest;
	CString	m_strFPGAArtNr;
	CString	m_strFPGASwVersion;
	//}}AFX_DATA
  IHIInterface * m_pHWIntf;
  CCOSyncObject* m_pEvent;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetGetDWord)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetGetDWord)
	afx_msg void OnBtnGetdword();
	afx_msg void OnBtnSetdword();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnPciWrite();
	afx_msg void OnBtnPciRead();
	afx_msg void OnClose();
	afx_msg void OnBtnEvent();
	afx_msg void OnBtnTest();
	afx_msg void OnBtnFpgaArtnr();
	afx_msg void OnBtnFpgaSwversion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETGETDWORD_H__4B2E5D2A_CA35_461C_8883_AF3637E45D49__INCLUDED_)
