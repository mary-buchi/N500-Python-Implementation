#if !defined(AFX_DLGEVENT_H__7A4D93AC_7B04_44D4_BC5B_36E0436860DE__INCLUDED_)
#define AFX_DLGEVENT_H__7A4D93AC_7B04_44D4_BC5B_36E0436860DE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgEvent.h : header file
//

class CCOSyncObject;

/////////////////////////////////////////////////////////////////////////////
// CDlgEvent dialog
class IHIInterface;

class CDlgEvent : public CDialog
{
// Construction
public:
	CDlgEvent(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgEvent)
	enum { IDD = IDD_DLG_EVENT };
	DWORD	m_dwOpenEventID;
	DWORD	m_dwCloseEventID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEvent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
  IHIInterface * m_pHWIntf;
  EHIOpenEventRegistration m_eEdge;
  CCOSyncObject* m_pEvent;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgEvent)
	afx_msg void OnDlgEventCloseEvent();
	afx_msg void OnDlgEventOpenEvent();
	virtual BOOL OnInitDialog();
	afx_msg void OnDlgEventNeg();
	afx_msg void OnDlgEventPos();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEVENT_H__7A4D93AC_7B04_44D4_BC5B_36E0436860DE__INCLUDED_)
