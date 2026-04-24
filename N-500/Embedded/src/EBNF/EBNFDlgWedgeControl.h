#if !defined(AFX_DLGWEDGECONTROL_H__D0B69FCA_FAC0_4467_9D33_3F40E5346522__INCLUDED_)
#define AFX_DLGWEDGECONTROL_H__D0B69FCA_FAC0_4467_9D33_3F40E5346522__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgWedgeControl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgWedgeControl dialog
class IHIInterface;
class CPIWedgeControlConfig;
class CPIWedgeControlProfile;
class IPIWedgeControlInterface;
class DlgWedgeControl : public CDialog
{
// Construction
public:
	DlgWedgeControl(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgWedgeControl)
	enum { IDD = IDD_DLG_WC };
	CString	m_strActWCState;
	DWORD	m_dwTest;
	//}}AFX_DATA

  IHIInterface * m_pHWIntf;
  IPIWedgeControlInterface* m_pWCIntf;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgWedgeControl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
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

	DWORD	m_dw01NomAcc;
	DWORD	m_dw02NomDec;
	DWORD	m_dw03NomVelocity;
  CPIWedgeControlConfig * m_pWCConfig;
  CPIWedgeControlProfile * m_pWCProfile;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgWedgeControl)
	afx_msg void OnBtnWcStartup();
	afx_msg void OnBtnWcSetconfiguration();
	afx_msg void OnBtnWcSetprofile();
	afx_msg void OnBtnWcInitialize();
	afx_msg void OnBtnWcReferencing();
	afx_msg void OnBtnWcStart();
	afx_msg void OnBtnWcStop();
	afx_msg void OnBtnWcShutdown();
	afx_msg void OnBtnSetconfig();
	afx_msg void OnBtnSetprofile();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnSetgetDword();
	afx_msg void OnBtnUpdateState();
	afx_msg void OnBtnShowVelocityCounter();
	afx_msg void OnBtnWcPid();
	afx_msg void OnBtnWcEmergencyStop();
	afx_msg void OnBtnWcDacIni();
	afx_msg void OnBtnLaserOnOff();
	afx_msg void OnBtnReadBuffer();
	afx_msg void OnBtnOsciOnOff();
	afx_msg void OnBtnOnlyTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWEDGECONTROL_H__D0B69FCA_FAC0_4467_9D33_3F40E5346522__INCLUDED_)
