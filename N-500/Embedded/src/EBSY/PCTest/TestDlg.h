// TestDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CTestDlg dialog
class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
    UINT  m_uiTimerID;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonStartDevice();
    afx_msg void OnBnClickedButtonConnectionEstablished();
    afx_msg void OnBnClickedButtonConnectionLost();
    afx_msg void OnTimer(UINT nIDEvent);
private:
    CString m_sState;
    CString m_sCommState;
public:
    afx_msg void OnBnClickedButtonResetDevice();
    afx_msg void OnBnClickedButtonReadIdentfications();
    afx_msg void OnBnClickedButtonReadSoftwareVersions();
    afx_msg void OnBnClickedButtonSetinterfaceConfig();
    afx_msg void OnBnClickedButtonWriteIdentfication();
    afx_msg void OnBnClickedButtonDownloadSoftwareComponents();
    afx_msg void OnBnClickedButtonSpecialTest1();
    afx_msg void OnBnClickedButtonSpecialTest2();
    afx_msg void OnDestroy();
    afx_msg void OnStnClickedState();
    CListBox m_ListBoxObjects;
    afx_msg void OnBnClickedButtonShowObjlist();
	afx_msg void OnBnClickedButtonTraceRefobjs();
};
