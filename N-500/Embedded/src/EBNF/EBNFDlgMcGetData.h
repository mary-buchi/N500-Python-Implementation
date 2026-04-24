#if !defined(AFX_DLGMCGETDATA_H__18996799_1EC6_4178_A7C4_3F196138CAA3__INCLUDED_)
#define AFX_DLGMCGETDATA_H__18996799_1EC6_4178_A7C4_3F196138CAA3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgMcGetData.h : header file
//
class IHIInterface;
class IPIMeasurementChannelInterface;
class CPIMeasurementChannelProfile;
/////////////////////////////////////////////////////////////////////////////
// CDlgMcGetData dialog

class CDlgMcGetData : public CDialog
{
// Construction
public:
	CDlgMcGetData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgMcGetData)
	enum { IDD = IDD_DLG_MCGETDATA };
	DWORD	m_SetData;
	CString	m_strActState;
	DWORD	m_dwNumberOfPackage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMcGetData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
  IHIInterface * m_pHWIntf;
  IPIMeasurementChannelInterface* m_pMCIntf;
  CPIMeasurementChannelProfile *m_pMCProfile;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMcGetData)
	afx_msg void OnBtnMcgetdata();
	afx_msg void OnBtnMcsetdata();
	afx_msg void OnBtnMcstartup();
	afx_msg void OnBtnMcsetprofile();
	afx_msg void OnBtnMcinitialize();
	afx_msg void OnBtnMcstart();
	afx_msg void OnBtnMcstop();
	afx_msg void OnBtnMcgetdatapackage();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBtnMcgetdatastart();
	afx_msg void OnBtnMcTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMCGETDATA_H__18996799_1EC6_4178_A7C4_3F196138CAA3__INCLUDED_)
