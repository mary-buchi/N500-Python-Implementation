// EBNFDlgShuttingDown.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBNFDlgShuttingDown.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgShuttingDown dialog


CDlgShuttingDown::CDlgShuttingDown(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShuttingDown::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgShuttingDown)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgShuttingDown::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgShuttingDown)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgShuttingDown, CDialog)
	//{{AFX_MSG_MAP(CDlgShuttingDown)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgShuttingDown message handlers
