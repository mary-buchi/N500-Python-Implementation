// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "EBNF.h"

#include "EBNFmain.h"

#include "EBHIintf.h"
#include "EBSYmain.h"

#include "EBNFDlgMcGetData.h"
#include "EBNFDlgSetGetDWord.h"
#include "EBNFDlgWedgeControl.h"
#include "EBNFDlgSystemControl.h"
#include "EBNFDlgEvent.h"
#include "EBNFDlgShuttingDown.h"
#include "EBNFDlgI2CEprom.h"
#include "EBNFDlgI2CTemp.h"
#include "ebnfdlgi2cdp.h"
#include "EBNFDlgI2CADC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const DWORD dwAdornmentFlags = 0; // exit button

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_DESTROY()
	ON_COMMAND(IDD_DLG_MCGETDATA, OnDlgMcgetdata)
	ON_COMMAND(IDD_DLG_TEST, OnDlgTest)
	ON_COMMAND(IDD_DLG_SETGET_DWORD, OnDlgSetgetDword)
	ON_COMMAND(ID_TEST_EVENTS, OnTestEvents)
	ON_COMMAND(ID_TEST_WEDGECONTROL, OnTestWedgecontrol)
	ON_COMMAND(TEST_SYSTEM, OnSystem)
	ON_WM_CLOSE()
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_COMMAND(ID_TEST_I2CEPROM, OnTestI2ceprom)
	ON_COMMAND(ID_TEST_I2CTEMPERATURE, OnTestI2ctemperature)
	ON_COMMAND(ID_TEST_I2CDP, OnTestI2cdp)
	ON_COMMAND(ID_TEST_I2CADC, OnTestI2cadc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initializateon code here
	m_bFirstFocus = true;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	
	if(!m_wndCommandBar.Create(this) ||
	   !m_wndCommandBar.InsertMenuBar(IDR_MAINFRAME) ||
	   !m_wndCommandBar.AddAdornments(dwAdornmentFlags))
	{
		TRACE0("Failed to create CommandBar\n");
		return -1;      // fail to create
	}

	m_wndCommandBar.SetBarStyle(m_wndCommandBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_FIXED);

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

    return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs


	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
	m_wndView.SetFocus();
	if (m_bFirstFocus)
	{
		// Display system menu as standard
        m_bFirstFocus = false;
		DlgSystemControl	dlg;
		dlg.DoModal();
	}
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnDestroy() 
{
	
  // CSYSystem::Delete();

	CFrameWnd::OnDestroy();
  
}

void CMainFrame::OnDlgMcgetdata() 
{

  CDlgMcGetData dlg;
  dlg.DoModal();
}

void CMainFrame::OnDlgTest() 
{
  CHIInterface::GetInstance()->TEST(1);
}

void CMainFrame::OnDlgSetgetDword() 
{
	CDlgSetGetDWord dlg;
    dlg.DoModal();
	
}

void CMainFrame::OnTestEvents() 
{
  CDlgEvent dlg;
  dlg.DoModal();
  
}

void CMainFrame::OnTestWedgecontrol() 
{
  DlgWedgeControl	dlg;
  dlg.DoModal();
}

void CMainFrame::OnSystem() 
{
  DlgSystemControl	dlg;
  dlg.DoModal();
}

void CMainFrame::OnClose() 
{
  ShuttdownSystem();

	CFrameWnd::OnClose();
}

void CMainFrame::OnAppExit() 
{
  ShuttdownSystem();

  DestroyWindow();
}

void CMainFrame::ShuttdownSystem()
{
  CDlgShuttingDown* l_pDlg = new CDlgShuttingDown(this);
  l_pDlg->Create(IDD_DIALOG_SHUTDOWN, this);
  l_pDlg->ShowWindow(SW_SHOW);
  l_pDlg->UpdateWindow();

  CSYSystem::Delete();
  l_pDlg->DestroyWindow();
}

void CMainFrame::OnTestI2ceprom() 
{
  CDlgI2CEprom	dlg;
  dlg.DoModal();
}

void CMainFrame::OnTestI2ctemperature() 
{
  CDlgI2CTemp	dlg;
  dlg.DoModal();
}

void CMainFrame::OnTestI2cdp() 
{
  CDlgI2CDp dlg;	
  dlg.DoModal();
}

void CMainFrame::OnTestI2cadc() 
{
  CDlgI2CADC dlg;	
  dlg.DoModal();
}
