// DlgSetGetDWord.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBNFDlgSetGetDWord.h"

#include "EBHIintf.h"

#include "EBNFDlgEvent.h"


#include "EBPIenum.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetGetDWord dialog


CDlgSetGetDWord::CDlgSetGetDWord(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetGetDWord::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetGetDWord)
	m_dwGetDWord = 0;
	m_dwLogId = 0;
	m_dwSetDWord = 0;
	m_dwPCIAdrRead = 0;
	m_dwPCIAdrWrite = 0;
	m_dwPCIValRead = 0;
	m_dwPCIValWrite = 0;
	m_dTest = 0.0;
	m_strFPGAArtNr = _T("");
	m_strFPGASwVersion = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSetGetDWord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetGetDWord)
	DDX_Text(pDX, IDC_EDT_GETDWORD, m_dwGetDWord);
	DDX_Text(pDX, IDC_EDT_LOGID, m_dwLogId);
	DDX_Text(pDX, IDC_EDT_SETDWORD, m_dwSetDWord);
	DDX_Text(pDX, IDC_EDT_PCI_ADR_READ, m_dwPCIAdrRead);
	DDX_Text(pDX, IDC_EDT_PCI_ADR_WRITE, m_dwPCIAdrWrite);
	DDX_Text(pDX, IDC_EDT_PCI_VAL_READ, m_dwPCIValRead);
	DDX_Text(pDX, IDC_EDT_PCI_VAL_WRITE, m_dwPCIValWrite);
	DDX_Text(pDX, IDC_EDT_TEST, m_dTest);
	DDX_Text(pDX, IDC_EDT_FPGA_ARTNR, m_strFPGAArtNr);
	DDX_Text(pDX, IDC_EDT_FPGA_SWVERSION, m_strFPGASwVersion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetGetDWord, CDialog)
	//{{AFX_MSG_MAP(CDlgSetGetDWord)
	ON_BN_CLICKED(IDC_BTN_GETDWORD, OnBtnGetdword)
	ON_BN_CLICKED(IDC_BTN_SETDWORD, OnBtnSetdword)
	ON_BN_CLICKED(IDC_BTN_PCI_WRITE, OnBtnPciWrite)
	ON_BN_CLICKED(IDC_BTN_PCI_READ, OnBtnPciRead)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_EVENT, OnBtnEvent)
	ON_BN_CLICKED(IDC_BTN_TEST, OnBtnTest)
	ON_BN_CLICKED(IDC_BTN_FPGA_ARTNR, OnBtnFpgaArtnr)
	ON_BN_CLICKED(IDC_BTN_FPGA_SWVERSION, OnBtnFpgaSwversion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetGetDWord message handlers
BOOL CDlgSetGetDWord::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_pHWIntf = IHIInterface::GetInstance();
  ((CButton*)GetDlgItem(IDC_RDN_READ))->SetCheck(1);
    
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSetGetDWord::OnBtnGetdword() 
{
	UpdateData(TRUE);

	m_dwGetDWord = m_pHWIntf->GetDWord(m_dwLogId);

  UpdateData(FALSE);
}

void CDlgSetGetDWord::OnBtnSetdword() 
{
	UpdateData(TRUE);

	m_pHWIntf->SetDWord(m_dwLogId, m_dwSetDWord);
	
}


void CDlgSetGetDWord::OnBtnPciWrite() 
{
	UpdateData(TRUE);

	m_pHWIntf->DIWriteDWord(m_dwPCIAdrWrite, m_dwPCIValWrite, eWrite);
	
}

void CDlgSetGetDWord::OnBtnPciRead() 
{
	UpdateData(TRUE);

  if (((CButton*)GetDlgItem(IDC_RDO_READ))->GetCheck() == BST_CHECKED)
  {
    m_dwPCIValRead = m_pHWIntf->DIReadDWord(m_dwPCIAdrRead, eRead);
  }
  else if (((CButton*)GetDlgItem(IDC_RDO_WRITE))->GetCheck() == BST_CHECKED)
  {
    m_dwPCIValRead = m_pHWIntf->DIReadDWord(m_dwPCIAdrRead, eWrite);
  }
  else
  {
    MessageBox(_T("no Read / Write state active!"));
  }

  UpdateData(FALSE);
	
}


void CDlgSetGetDWord::OnClose() 
{
	
	CDialog::OnClose();
}


void CDlgSetGetDWord::OnBtnEvent() 
{
	CDlgEvent dlg;
  dlg.DoModal();
  m_pEvent = dlg.m_pEvent;
	
}

void CDlgSetGetDWord::OnBtnTest() 
{

  DWORD l_dwValue = 0x123;
  DWORD l_dwRetVal = 0;
  CCOSyncObjectInt* l_pSyncObj = NULL;

  l_pSyncObj = m_pHWIntf->PCGetActCurrent();
  l_pSyncObj->Synchronize();
  l_dwRetVal = l_pSyncObj->GetValue();


  l_pSyncObj =   m_pHWIntf->PCGetActVoltage(eSecondaryLamp);
  l_pSyncObj->Synchronize();
  l_dwRetVal = l_pSyncObj->GetValue();

  l_pSyncObj =   m_pHWIntf->PCGetLampIdentification(eSecondaryLamp);
  l_pSyncObj->Synchronize();
  l_dwRetVal = l_pSyncObj->GetValue();

  m_pHWIntf->PCLampOnOff(true);
  m_pHWIntf->PCLampSelection(eSecondaryLamp);
  m_pHWIntf->PCSetNomVoltage(l_dwValue);

}

void CDlgSetGetDWord::OnBtnFpgaArtnr() 
{
  CCOSyncObjectCString* l_pSyncObj = NULL;
  l_pSyncObj = m_pHWIntf->ReadFpgaArtNr();
  l_pSyncObj->Synchronize();
  
  m_strFPGAArtNr = l_pSyncObj->GetValue();
  l_pSyncObj->ReleaseRef();

  UpdateData(FALSE);
}

void CDlgSetGetDWord::OnBtnFpgaSwversion() 
{
  CCOSyncObjectCString* l_pSyncObj = NULL;
  l_pSyncObj = m_pHWIntf->ReadFpgaSwVersion();
  l_pSyncObj->Synchronize();
  
  m_strFPGASwVersion = l_pSyncObj->GetValue();
  l_pSyncObj->ReleaseRef();
  
  UpdateData(FALSE);
	
}
