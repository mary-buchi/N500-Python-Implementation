// SYDialogStartupFailure.cpp : implementation file
//
#include "stdafx.h"
#include "EBSYdlsf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSYDialogStartupFailure dialog


CSYDialogStartupFailure::CSYDialogStartupFailure(const CString& p_sMsg)
	: CDialog(CSYDialogStartupFailure::IDD, NULL)
{
	//{{AFX_DATA_INIT(CSYDialogStartupFailure)
	//}}AFX_DATA_INIT

	m_sMsg = p_sMsg;
}


void CSYDialogStartupFailure::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSYDialogStartupFailure)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSYDialogStartupFailure, CDialog)
	//{{AFX_MSG_MAP(CSYDialogStartupFailure)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSYDialogStartupFailure message handlers

BOOL CSYDialogStartupFailure::OnInitDialog() 
{
	CDialog::OnInitDialog();

	GetDlgItem(IDC_STATIC_TEXT)->SetWindowText(m_sMsg);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
