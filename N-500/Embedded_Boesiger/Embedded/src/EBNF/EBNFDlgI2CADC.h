#if !defined(AFX_EBNFDLGI2CADC_H__AA853796_01CC_4F76_A521_84889E516F84__INCLUDED_)
#define AFX_EBNFDLGI2CADC_H__AA853796_01CC_4F76_A521_84889E516F84__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EBNFDlgI2CADC.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CADC dialog
class IPII2CADCMAX1037;
class CDlgI2CADC : public CDialog
{
// Construction
public:
	CDlgI2CADC(CWnd* pParent = NULL);   // standard constructor

  IPII2CADCMAX1037* m_pADC;

// Dialog Data
	//{{AFX_DATA(CDlgI2CADC)
	enum { IDD = IDD_DLG_I2C_ADC };
	int		m_nAIN0;
	int		m_nAIN1;
	int		m_nAIN2;
	int		m_nAIN3;
	DWORD	m_dwDeviceID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgI2CADC)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgI2CADC)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAdcIni();
	afx_msg void OnBtnAdcGetData();
	afx_msg void OnBtnStartup();
	afx_msg void OnBtnShutdown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EBNFDLGI2CADC_H__AA853796_01CC_4F76_A521_84889E516F84__INCLUDED_)
