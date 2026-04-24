// DlgEvent.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBCOsync.h"
#include "EBHIenum.h"


#include "EBHIintf.h"
#include "EBHITrsm.h"

#include "EBSYmain.h"

#include "EBNFDlgEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEvent dialog


CDlgEvent::CDlgEvent(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEvent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEvent)
	m_dwOpenEventID = 0;
	m_dwCloseEventID = 0;
	//}}AFX_DATA_INIT
  m_eEdge = eHIUndefined;
}


void CDlgEvent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEvent)
	DDX_Text(pDX, IDC_DLG_EVENT_OPEN_EVENT_ID, m_dwOpenEventID);
	DDX_Text(pDX, IDC_DLG_EVENT_CLOSE_EVENT_ID, m_dwCloseEventID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEvent, CDialog)
	//{{AFX_MSG_MAP(CDlgEvent)
	ON_BN_CLICKED(IDC_DLG_EVENT_CLOSE_EVENT, OnDlgEventCloseEvent)
	ON_BN_CLICKED(IDC_DLG_EVENT_OPEN_EVENT, OnDlgEventOpenEvent)
	ON_BN_CLICKED(IDC_DLG_EVENT_NEG, OnDlgEventNeg)
	ON_BN_CLICKED(IDC_DLG_EVENT_POS, OnDlgEventPos)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEvent message handlers

void CDlgEvent::OnDlgEventCloseEvent() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
  m_pHWIntf->CloseEvent(m_dwCloseEventID, m_pEvent);
  m_pEvent->ReleaseRef();
  m_pEvent = NULL;
}

void CDlgEvent::OnDlgEventOpenEvent() 
{
	UpdateData();
	m_pEvent = m_pHWIntf->OpenEvent(m_dwOpenEventID, m_eEdge);
  m_pEvent->Synchronize();

  //MessageBox(_T("Event Signaled!"));

  // test hw warn error exception
  //DWORD l_dwRetVal = m_pHWIntf->GetDWord(m_pHWIntf->GetStaticObjID(eHIIDHwExceptions));
  //CString l_strMessage = _T("");
  //l_strMessage.Format(_T("Exception Value: %#010x"),l_dwRetVal);
  //MessageBox(l_strMessage);

}

BOOL CDlgEvent::OnInitDialog() 
{
	CDialog::OnInitDialog();
	  
	// TODO: Add extra initialization here
	m_pHWIntf = IHIInterface::GetInstance();


  UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgEvent::OnDlgEventNeg() 
{
	m_eEdge = eHILow;
}

void CDlgEvent::OnDlgEventPos() 
{
	m_eEdge = eHIHigh;
}
