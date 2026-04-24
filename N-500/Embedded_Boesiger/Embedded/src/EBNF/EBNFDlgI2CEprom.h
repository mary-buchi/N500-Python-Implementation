#if !defined(AFX_DLGI2CEPROM_H__3CDC8DF5_D00A_4C8A_98B5_F2A5B4C56072__INCLUDED_)
#define AFX_DLGI2CEPROM_H__3CDC8DF5_D00A_4C8A_98B5_F2A5B4C56072__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgI2CEprom.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CEprom dialog
class IHIInterface;
class IPII2CEprom24LC515;

class CDlgI2CEprom : public CDialog
{
// Construction
public:
	CDlgI2CEprom(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgI2CEprom)
	enum { IDD = IDD_DLG_I2C_EPROM };
	DWORD	m_dwByteWriteAdr;
	DWORD	m_dwByteWriteVal;
	DWORD	m_dwWriteContentVal;
	DWORD	m_dwPageWriteAdr;
	DWORD	m_dwPageWriteVal;
	DWORD	m_dwReadByteAdr;
	DWORD	m_dwReadPageAdr;
	DWORD	m_dwReadByteVal;
	DWORD	m_dwNumberOfPages;
	DWORD	m_dwDeviceID;
	//}}AFX_DATA

  IHIInterface * m_pHWIntf;
  IPII2CEprom24LC515* m_pI2CIntf;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgI2CEprom)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgI2CEprom)
	afx_msg void OnBtnRdByte();
	afx_msg void OnBtnRdContent();
	afx_msg void OnBtnRdPage();
	afx_msg void OnBtnWrBlock();
	afx_msg void OnBtnWrByte();
	afx_msg void OnBtnWrContent();
	virtual BOOL OnInitDialog();
	afx_msg void OnTestI2cadc();
	afx_msg void OnBtnStartup();
	afx_msg void OnBtnShutdown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGI2CEPROM_H__3CDC8DF5_D00A_4C8A_98B5_F2A5B4C56072__INCLUDED_)
