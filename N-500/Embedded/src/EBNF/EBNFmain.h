// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__F353ACB9_00D3_405B_B078_A9EDA93404CB__INCLUDED_)
#define AFX_MAINFRM_H__F353ACB9_00D3_405B_B078_A9EDA93404CB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "EBNFChildView.h"

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
  virtual void ShuttdownSystem();

protected:  // control bar embedded members
	CCeCommandBar	m_wndCommandBar;
	CStatusBar		m_wndStatusBar;
	CChildView    m_wndView;

// Generated message map functions
protected:
	bool m_bFirstFocus;
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnDestroy();
	afx_msg void OnDlgMcgetdata();
	afx_msg void OnDlgTest();
	afx_msg void OnDlgSetgetDword();
	afx_msg void OnTestEvents();
	afx_msg void OnTestWedgecontrol();
	afx_msg void OnSystem();
	afx_msg void OnClose();
	afx_msg void OnAppExit();
	afx_msg void OnTestI2ceprom();
	afx_msg void OnTestI2ctemperature();
	afx_msg void OnTestI2cdp();
	afx_msg void OnTestI2cadc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__F353ACB9_00D3_405B_B078_A9EDA93404CB__INCLUDED_)
