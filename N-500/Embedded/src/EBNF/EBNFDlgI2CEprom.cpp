// DlgI2CEprom.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBCOexcp.h"

#include "EBPImain.h"
#include "EBPIenum.h"
#include "EBPIfact.h"
#include "EBPIintf.h"
#include "EBPItype.h"
#include "EBHIintf.h"
#include "EBHITrsm.h"


#include "EBNFDlgI2CEprom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CEprom dialog


CDlgI2CEprom::CDlgI2CEprom(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgI2CEprom::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgI2CEprom)
	m_dwByteWriteAdr = 0;
	m_dwByteWriteVal = 0;
	m_dwWriteContentVal = 0;
	m_dwPageWriteAdr = 0;
	m_dwPageWriteVal = 0;
	m_dwReadByteAdr = 0;
	m_dwReadPageAdr = 0;
	m_dwReadByteVal = 0;
	m_dwNumberOfPages = 1;
	m_dwDeviceID = 5006;
	//}}AFX_DATA_INIT
}


void CDlgI2CEprom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgI2CEprom)
	DDX_Text(pDX, IDC_EDT_BYTE_WRITE_ADR_WB, m_dwByteWriteAdr);
	DDX_Text(pDX, IDC_EDT_BYTE_WRITE_VALUE, m_dwByteWriteVal);
	DDX_Text(pDX, IDC_EDT_CONTENT_WRITE_VALUE, m_dwWriteContentVal);
	DDX_Text(pDX, IDC_EDT_PAGE_WRITE_ADR_WB, m_dwPageWriteAdr);
	DDX_Text(pDX, IDC_EDT_PAGE_WRITE_VALUE, m_dwPageWriteVal);
	DDX_Text(pDX, IDC_EDT_READ_ADR_RB, m_dwReadByteAdr);
	DDX_Text(pDX, IDC_EDT_READ_ADR_RP, m_dwReadPageAdr);
	DDX_Text(pDX, IDC_EDT_READ_VALUE, m_dwReadByteVal);
	DDX_Text(pDX, IDC_EDT_NUMBEROFPAGES, m_dwNumberOfPages);
	DDX_Text(pDX, IDC_EDT_DEVICE_ID, m_dwDeviceID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgI2CEprom, CDialog)
	//{{AFX_MSG_MAP(CDlgI2CEprom)
	ON_BN_CLICKED(IDC_BTN_RD_BYTE, OnBtnRdByte)
	ON_BN_CLICKED(IDC_BTN_RD_CONTENT, OnBtnRdContent)
	ON_BN_CLICKED(IDC_BTN_RD_PAGE, OnBtnRdPage)
	ON_BN_CLICKED(IDC_BTN_WR_BLOCK, OnBtnWrBlock)
	ON_BN_CLICKED(IDC_BTN_WR_BYTE, OnBtnWrByte)
	ON_BN_CLICKED(IDC_BTN_WR_CONTENT, OnBtnWrContent)
	ON_BN_CLICKED(IDC_BTN_STARTUP, OnBtnStartup)
	ON_BN_CLICKED(IDC_BTN_SHUTDOWN, OnBtnShutdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CEprom message handlers

void CDlgI2CEprom::OnBtnRdByte() 
{
  if (m_pI2CIntf == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }

  UpdateData();

  try
  {
    CCOSyncObjectInt* l_pSyncObj = NULL;
    l_pSyncObj = m_pI2CIntf->ByteRead((WORD)m_dwReadByteAdr);
    l_pSyncObj->Synchronize();
  
    m_dwReadByteVal = l_pSyncObj->GetValue();

    l_pSyncObj->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
}

void CDlgI2CEprom::OnBtnRdContent() 
{
  if (m_pI2CIntf == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData();
  try
  {
    BYTE * l_pRetValue = NULL; //new BYTE[m_pIntf->GetEprom24LC515SizeInByte()];
    CPII2CDataStream *l_pData = NULL;
    UpdateData();
    CPISyncObjI2CDataStream* l_pSyncObj = NULL;

    l_pSyncObj = m_pI2CIntf->ReadContent();
    l_pSyncObj->Synchronize();
  
    l_pData = l_pSyncObj->GetValue();
    l_pRetValue = l_pData->GetpcI2CDataStream();
	  
    if (((CButton*)GetDlgItem(IDC_CHK_WRITE_FILE))->GetCheck())
    {

       HANDLE hFile = CreateFile(_T("\\ReadE2PROM.TXT"),
                                 GENERIC_WRITE, FILE_SHARE_READ,
                                 NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
       CFile myFile((int)hFile);

       if (hFile == INVALID_HANDLE_VALUE)
       {
          AfxMessageBox(_T("Could not create the file!"));
       }
       else
       {
          myFile.Write(l_pData->GetpcI2CDataStream(), l_pData->GetnSize());
          myFile.Close();
       }
    }
	else
	{
		AfxMessageBox(_T("Could not create the file!"));
	}

    l_pSyncObj->ReleaseRef();
    l_pData->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
  
  UpdateData(FALSE);
}

void CDlgI2CEprom::OnBtnRdPage() 
{
  if (m_pI2CIntf == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData();
	int l_nSize = m_dwNumberOfPages * 64;

  try
  {
    CPII2CDataStream *l_pData = NULL;
    CPISyncObjI2CDataStream* l_pSyncObj = NULL;
    l_pSyncObj =   m_pI2CIntf->BlockRead((WORD)m_dwReadPageAdr, l_nSize);
    l_pSyncObj->Synchronize();
  
    l_pData = l_pSyncObj->GetValue();
    l_nSize = l_pData->GetnSize();
  
    if (((CButton*)GetDlgItem(IDC_CHK_WRITE_FILE))->GetCheck())
    {

       HANDLE hFile = CreateFile(_T("\\PageRead.TXT"),
                                 GENERIC_WRITE, FILE_SHARE_READ,
                                 NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
       CFile myFile((int)hFile);
       char *sz = new char[l_nSize*4];
       if (hFile == INVALID_HANDLE_VALUE)
       {
          AfxMessageBox(_T("Could not create the file!"));
       }
       else
       {
          int jj = 0;
          for (int ii = 0; ii < l_nSize; ii++)
          {
            jj+= sprintf(sz + jj, "%d,\r\n",(BYTE)l_pData->GetpcI2CDataStream()[ii]);
          }

          int l_nLength = strlen(sz);
          myFile.Write(sz, l_nLength);

          myFile.Close();
       }
  
      if (sz)
        delete [] sz;
      sz = NULL;
    }

    l_pData->ReleaseRef();
    l_pSyncObj->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
	
}

void CDlgI2CEprom::OnBtnWrBlock() 
{
  if (m_pI2CIntf == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData();
  BYTE *l_cValue = new BYTE[64];

  for (int ii = 0; ii < 64; ii++)
  {
    l_cValue[ii] = ii+1;
  }

  try
  {
    CCOSyncObject* l_pSyncObj = NULL;
    l_pSyncObj = m_pI2CIntf->PageWrite((WORD)m_dwPageWriteAdr, l_cValue, (UINT)64);
    l_pSyncObj->Synchronize();
    l_pSyncObj->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  if (l_cValue)
  {
    delete [] l_cValue;
    l_cValue = NULL;
  }
  UpdateData(FALSE);
	
}

void CDlgI2CEprom::OnBtnWrByte() 
{
  if (m_pI2CIntf == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData();
  try
  {
    CCOSyncObject* l_pSyncObj = NULL;
    l_pSyncObj = m_pI2CIntf->ByteWrite((WORD)m_dwByteWriteAdr, (BYTE)m_dwByteWriteVal);

    l_pSyncObj->Synchronize();
    l_pSyncObj->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
	
}

void CDlgI2CEprom::OnBtnWrContent() 
{
  if (m_pI2CIntf == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData();
  try
  {
    int l_uiSize = m_pI2CIntf->GetEprom24LC515SizeInByte();
    BYTE * l_pValue = new BYTE[l_uiSize];
  
    for (int ii = 0; ii < l_uiSize; ii++)
    {
      l_pValue[ii] = 0x0;
    }

    CCOSyncObject* l_pSyncObj = NULL;
    l_pSyncObj = m_pI2CIntf->WriteContent(l_pValue, l_uiSize);
    l_pSyncObj->Synchronize();
    l_pSyncObj->ReleaseRef();

    if (l_pValue)
    {
      delete [] l_pValue;
    }
    l_pValue = NULL;
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
  UpdateData(FALSE);
}


BOOL CDlgI2CEprom::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_pHWIntf = IHIInterface::GetInstance();

  m_pI2CIntf = NULL;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgI2CEprom::OnBtnStartup() 
{
  UpdateData(TRUE);
  if (m_dwDeviceID == 0)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
 
  m_pI2CIntf = CPIObjectFactory::GetInstance()->CreateEprom24LC515(m_dwDeviceID, _T(""));
  
}

void CDlgI2CEprom::OnBtnShutdown() 
{
  UpdateData(TRUE);
  if (m_pI2CIntf == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  if (m_pI2CIntf)
  {
	CCOSyncObjectPtr l_pSyncObj = m_pI2CIntf->Shutdown();
	l_pSyncObj->Synchronize();	
	m_pI2CIntf = NULL;
  }
}
