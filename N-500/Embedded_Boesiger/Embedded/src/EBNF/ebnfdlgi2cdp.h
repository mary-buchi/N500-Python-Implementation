#if !defined(AFX_EBNFDLGI2CDP_H__932BF5FE_FA9D_4342_AAB6_E7ED20E7C694__INCLUDED_)
#define AFX_EBNFDLGI2CDP_H__932BF5FE_FA9D_4342_AAB6_E7ED20E7C694__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ebnfdlgi2cdp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CDp dialog
class IHIInterface;
class IPII2CDigitalPotiAD5245;

class CDlgI2CDp : public CDialog
{
// Construction
public:
	CDlgI2CDp(CWnd* pParent = NULL);   // standard constructor
  IPII2CDigitalPotiAD5245* m_pDP;

// Dialog Data
	//{{AFX_DATA(CDlgI2CDp)
	enum { IDD = IDD_DLG_I2C_DP };
	int		m_nDPRead;
	int		m_nDPWrite;
	DWORD	m_dwDeviceID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgI2CDp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgI2CDp)
	afx_msg void OnBtnDpRead();
	afx_msg void OnBtnDpWrite();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnStartup();
	afx_msg void OnBtnShutdown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EBNFDLGI2CDP_H__932BF5FE_FA9D_4342_AAB6_E7ED20E7C694__INCLUDED_)
