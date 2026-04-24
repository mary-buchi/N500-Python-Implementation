#if !defined(AFX_DLGWCVLCCNT_H__9D962175_8AA2_4C8D_A170_FCCE8C27C7BB__INCLUDED_)
#define AFX_DLGWCVLCCNT_H__9D962175_8AA2_4C8D_A170_FCCE8C27C7BB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgWCVlcCnt.h : header file
//
class IHIInterface;
class IPIWedgeControlInterface;

/////////////////////////////////////////////////////////////////////////////
// CDlgWCVlcCnt dialog

class CDlgWCVlcCnt : public CDialog
{
// Construction
public:
	CDlgWCVlcCnt(CWnd* pParent = NULL);   // standard constructor
  
  IHIInterface * m_pHWIntf;
  IPIWedgeControlInterface* m_pWCIntf;
// Dialog Data
	//{{AFX_DATA(CDlgWCVlcCnt)
	enum { IDD = IDD_DLG_VELOCITY_COUNTER };
	CString	m_strWCActPos;
	CString	m_strWCLastVlc;
	CString	m_strWCActVlc;
	DWORD	m_dwWCDAC;
	CString	m_strLBState;
	int		m_nActPos;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgWCVlcCnt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgWCVlcCnt)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnUpdateCounter();
	afx_msg void OnBtnResetPosition();
	afx_msg void OnRdoPosDir();
	afx_msg void OnRdoNegDir();
	afx_msg void OnBtnEmergencyStop();
	afx_msg void OnBtnDacSet();
	afx_msg void OnBtnDacControllerOnOff();
	afx_msg void OnBtnDacIni();
	afx_msg void OnBtnLaserOn();
	afx_msg void OnBtnLb();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWCVLCCNT_H__9D962175_8AA2_4C8D_A170_FCCE8C27C7BB__INCLUDED_)
