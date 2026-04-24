#if !defined(AFX_DLGSYSTEMCOMPSTATE_H__E3ADEE11_C5F0_445E_8540_7CB6D9122DD8__INCLUDED_)
#define AFX_DLGSYSTEMCOMPSTATE_H__E3ADEE11_C5F0_445E_8540_7CB6D9122DD8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSystemCompState.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgSystemCompState dialog

class DlgSystemCompState : public CDialog
{
// Construction
public:
	DlgSystemCompState(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSystemCompState)
	enum { IDD = IDD_DLG_COMPONENT_STATE };
	BOOL	m_dwSysCP_DI_ID;
	BOOL	m_dwSysCP_ES_ID;
	BOOL	m_dwSysCP_HI_ID;    
	BOOL	m_dwSysCP_IO_ID;    
	BOOL	m_dwSysCP_I2CADC_ID;
	BOOL	m_dwSysCP_I2CDP_ID;
	BOOL	m_dwSysCP_I2CEPROM_ID;
	BOOL	m_dwSysCP_I2TEMP_ID;
	BOOL	m_dwSysCP_MC_ID;
	BOOL	m_dwSysCP_PC_ID;
	BOOL	m_dwSysCP_PO_ID;
	BOOL	m_dwSysCP_ST_ID;
	BOOL	m_dwSysCP_TC_ID;
	BOOL	m_dwSysCP_WC_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSystemCompState)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

    void DlgSystemCompState::ChangeState(const CString& sId, BOOL& bVal);

	// Generated message map functions
	//{{AFX_MSG(DlgSystemCompState)
	afx_msg void OnDlgSyscpDi();
	afx_msg void OnDlgSyscpEs();
	afx_msg void OnDlgSyscpI2ceprom();
	afx_msg void OnDlgSyscpI2temp();
	afx_msg void OnDlgSyscpMc();
	afx_msg void OnDlgSyscpPc();
	afx_msg void OnDlgSyscpPo();
	afx_msg void OnDlgSyscpSt();
	afx_msg void OnDlgSyscpTc();
	afx_msg void OnDlgSyscpWc();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck1();
	afx_msg void OnDlgSyscpHi();
	afx_msg void OnDlgSyscpIo();
	afx_msg void OnDlgSyscpI2cdp();
	afx_msg void OnDlgSyscpI2cadc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMCOMPSTATE_H__E3ADEE11_C5F0_445E_8540_7CB6D9122DD8__INCLUDED_)
