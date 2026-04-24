#if !defined(AFX_DLGI2CTEMP_H__BCD1BFA5_F5BD_425D_BF86_9482431E2588__INCLUDED_)
#define AFX_DLGI2CTEMP_H__BCD1BFA5_F5BD_425D_BF86_9482431E2588__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgI2CTemp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CTemp dialog
class IHIInterface;
class IPII2CTempSensorDS1631Z;
class CDlgI2CTemp : public CDialog
{
// Construction
public:
	CDlgI2CTemp(CWnd* pParent = NULL);   // standard constructor

  IPII2CTempSensorDS1631Z*  m_pTemp;
// Dialog Data
	//{{AFX_DATA(CDlgI2CTemp)
	enum { IDD = IDD_DLG_I2C_TEMP };
	int		m_nGetConfig;
	int		m_nGetTemp;
	DWORD	m_dwDeviceId;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgI2CTemp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgI2CTemp)
	afx_msg void OnBtnGetConfig();
	afx_msg void OnBtnGetTemp();
	afx_msg void OnBtnSetConfig();
	afx_msg void OnBtnStartup();
	afx_msg void OnBtnShutdown();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGI2CTEMP_H__BCD1BFA5_F5BD_425D_BF86_9482431E2588__INCLUDED_)
