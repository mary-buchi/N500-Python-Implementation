#if !defined(AFX_DLGWCSETCONFIG_H__A44DA82C_6D34_446B_B997_9F1B9870464D__INCLUDED_)
#define AFX_DLGWCSETCONFIG_H__A44DA82C_6D34_446B_B997_9F1B9870464D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgWCSetConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgWCSetConfig dialog

class DlgWCSetConfig : public CDialog
{
// Construction
public:
	DlgWCSetConfig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgWCSetConfig)
	enum { IDD = IDD_DLG_SET_WC_CONFIGURATION };
	DWORD	m_dw01VelocityWarnLevelHigh;
	DWORD	m_dw02VelocityWarnLevelLow;
	DWORD	m_dw03VelocityErrorLevelHigh;
	DWORD	m_dw04VelocityErrorLevelLow;
	DWORD	m_dw05IniWatchTime;
	DWORD	m_dw06NomVelocityIniTime;
	DWORD	m_dw07ForwardWatchTime;
	DWORD	m_dw08BackwardWatchTime;
	DWORD	m_dw09ParkWatchTime;
	DWORD	m_dw10WatchTime;
	DWORD	m_dw11RefWatchTime1;
	DWORD	m_dw12RefWatchTime2;
	DWORD	m_dw13StartDisForward;
	DWORD	m_dw15MeasuringDistance;
	DWORD	m_dw14EndDisForward;
	DWORD	m_dw16StartDisBackward;
	DWORD	m_dw17RefDistance1;
	DWORD	m_dw18RefDistance2;
	DWORD	m_dw19PFactor;
	DWORD	m_dwIFactor;
	DWORD	m_dw21DFactor;
	DWORD	m_dw22UpperLimit;
	int		m_i23LowerLimit;
	DWORD	m_dw24RunAfterTime;
	DWORD	m_dw25AccStandByMode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgWCSetConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgWCSetConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnWcconfigSetDefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWCSETCONFIG_H__A44DA82C_6D34_446B_B997_9F1B9870464D__INCLUDED_)
