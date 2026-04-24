// DlgWedgeControl.cpp : implementation file
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

//#include "EBHIifid.h"

#include "EBNFDlgSetGetDWord.h"
#include "EBNFDlgWedgeControl.h"
#include "EBNFDlgWCSetProfile.h"
#include "EBNFDlgWCSetConfig.h"
#include "EBNFDlgWCVlcCnt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgWedgeControl dialog


DlgWedgeControl::DlgWedgeControl(CWnd* pParent /*=NULL*/)
	: CDialog(DlgWedgeControl::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgWedgeControl)
	m_strActWCState = _T("");
	m_dwTest = 0;
	//}}AFX_DATA_INIT
}


void DlgWedgeControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgWedgeControl)
	DDX_Text(pDX, IDC_EDT_WC_ACT_STATE, m_strActWCState);
	DDX_Text(pDX, IDC_EDT_TEST, m_dwTest);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgWedgeControl, CDialog)
	//{{AFX_MSG_MAP(DlgWedgeControl)
	ON_BN_CLICKED(IDC_BTN_WC_STARTUP, OnBtnWcStartup)
	ON_BN_CLICKED(IDC_BTN_WC_SETCONFIGURATION, OnBtnWcSetconfiguration)
	ON_BN_CLICKED(IDC_BTN_WC_SETPROFILE, OnBtnWcSetprofile)
	ON_BN_CLICKED(IDC_BTN_WC_INITIALIZE, OnBtnWcInitialize)
	ON_BN_CLICKED(IDC_BTN_WC_REFERENCING, OnBtnWcReferencing)
	ON_BN_CLICKED(IDC_BTN_WC_START, OnBtnWcStart)
	ON_BN_CLICKED(IDC_BTN_WC_STOP, OnBtnWcStop)
	ON_BN_CLICKED(IDC_BTN_WC_SHUTDOWN, OnBtnWcShutdown)
	ON_BN_CLICKED(IDC_BTN_SETGET_DWORD, OnBtnSetgetDword)
	ON_BN_CLICKED(IDC_BTN_UPDATE_STATE, OnBtnUpdateState)
	ON_BN_CLICKED(IDC_BTN_SHOW_VELOCITY_COUNTER, OnBtnShowVelocityCounter)
	ON_BN_CLICKED(IDC_BTN_WC_PID, OnBtnWcPid)
	ON_BN_CLICKED(IDC_BTN_WC_EMERGENCY_STOP, OnBtnWcEmergencyStop)
	ON_BN_CLICKED(IDC_BTN_WC_DAC_INI, OnBtnWcDacIni)
	ON_BN_CLICKED(IDC_BTN_LASER_ON_OFF, OnBtnLaserOnOff)
	ON_BN_CLICKED(IDC_BTN_READ_BUFFER, OnBtnReadBuffer)
	ON_BN_CLICKED(IDC_BTN_OSCI_ON_OFF, OnBtnOsciOnOff)
	ON_BN_CLICKED(IDC_BTN_ONLY_TEST, OnBtnOnlyTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgWedgeControl message handlers

void DlgWedgeControl::OnBtnWcStartup() 
{
  try
  {

	  CCOSyncObjectPtr l_SyncObjWC = m_pWCIntf->Startup();
	  ASSERT(l_SyncObjWC != NULL);
	  l_SyncObjWC->Synchronize();
    m_strActWCState = m_pWCIntf->GetsCurrentState();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
}

void DlgWedgeControl::OnBtnWcSetconfiguration() 
{

  WCHAR* l_pFileName = _T("\\Hard Disk\\NIRFlex\\WCConfig.txt");
  CFile l_f1;
  CString l_strVal;
  CString l_strConfig;
  int l_nLastPos = 0;
  int l_nActPos = 0;
  int l_nCount = 0;
  int l_nIndex = 0;
  char *l_pbuf;

  int l_nConfigSize = 35;
  DWORD *l_dwParamArray = new DWORD[l_nConfigSize];

  if( !l_f1.Open( l_pFileName, CFile::modeRead)) {
    MessageBox(_T("Could not load file -> \\Hard Disk\\NIRFlex\\WCConfig.txt"));
    return;
  }
  int l_nLength = (int)l_f1.GetLength(); // length in byte
  l_pbuf = new char[l_nLength];
  l_f1.Read(l_pbuf, l_nLength);
  l_strConfig+=l_pbuf;
  l_f1.Close();
  if (l_pbuf)
    delete l_pbuf;
  l_pbuf = NULL;

  while ((l_nCount + l_nActPos) < l_nLength)
  { 
    l_nActPos = l_strConfig.Find(_T(","), l_nLastPos);
    if (l_nActPos == -1)
    { // not found
      l_nActPos = l_nLength;
    }
    l_nCount = l_nActPos - l_nLastPos;
    if (l_nCount != 0)
    {
      l_strVal = l_strConfig.Mid(l_nLastPos,l_nCount);
      l_dwParamArray[l_nIndex] = _wtoi(((LPTSTR)l_strVal.GetBuffer(l_strVal.GetLength())));
      l_nIndex++;
      l_strVal.ReleaseBuffer();
      l_nLastPos = l_strConfig.Find(_T("\n"), l_nActPos) + 1;
    }
  }
  
  if(l_nIndex != l_nConfigSize)
  {
    MessageBox(_T("not all parameter of the wedge control configuration are be loaded!"));
  }

  CPIWedgeControlConfig* l_pConfig = new CPIWedgeControlConfig(
                                            l_dwParamArray[0],   // p_dwNomVelocity
                                            l_dwParamArray[1],   // p_dwNomAcc
                                            l_dwParamArray[2],   // p_dwNomDec
                                            l_dwParamArray[3],   // p_dwWedgeControllerVelocityEdge
                                            l_dwParamArray[4],   //p_dwStaticFrictionForward
                                            l_dwParamArray[5],   //p_dwStaticFrictionBackward
                                            l_dwParamArray[6],   // p_dwVelocityWarnHighRange
                                            l_dwParamArray[7],    // p_dwVelocityWarnLowRange
                                            l_dwParamArray[8],    // p_dwVelocityErrorHighRange
                                            l_dwParamArray[9],    // p_dwVelocityErrorLowRange
                                            l_dwParamArray[10],      // p_dwForwardStartDistance
                                            l_dwParamArray[11],       // p_dwForwardEndDistance
                                            l_dwParamArray[12],     // p_dwMeasuringDistance
                                            l_dwParamArray[13],      // p_dwBackwardStartDistance
                                            l_dwParamArray[14],     // p_dwRefDistance1
                                            l_dwParamArray[15],        // p_dwWC_P
                                            l_dwParamArray[16],       // p_dwWC_TN
                                            l_dwParamArray[17],        // p_dwWC_TV
                                            l_dwParamArray[18],        // p_dwWC_Kdac
                                            l_dwParamArray[19],        // p_dwWC_Gain_DAC
                                            l_dwParamArray[20],        // p_dwWC_Offset_DAC
                                            l_dwParamArray[21],     // p_dwDACLimitUp
                                            l_dwParamArray[22],    // p_dwDACLimitDown
                                            l_dwParamArray[23],    // p_dwDACLimitSlewRate
                                            l_dwParamArray[24],    // p_dwRunAfterTimeTicks
                                            l_dwParamArray[25],    //p_dwMaxCurrentTime [ms]
                                            l_dwParamArray[26],   // p_dwAccStandBy
                                            l_dwParamArray[27],   // p_dwWCIdInitializedEvent
                                            l_dwParamArray[28],   // p_dwWCIdReferencedEvent
                                            l_dwParamArray[29],   // p_dwWCIdStoppedEvent
                                            l_dwParamArray[30],   // p_dwWCIdParkedEvent
                                            l_dwParamArray[31],   // p_dwWCIdCurDirEvent
                                            l_dwParamArray[32],   // p_dwWCLightBarrierEvent
                                            l_dwParamArray[33],   //p_dwWCIdMeasuringExcEvent
                                            l_dwParamArray[34]);   // p_dwWCIdCurDirInput

  try
  {
    CCOSyncObjectPtr l_SyncObjWCSetConfig = m_pWCIntf->SetConfiguration(l_pConfig);
	  ASSERT(l_SyncObjWCSetConfig != NULL);
	  l_SyncObjWCSetConfig->Synchronize();
  }
	catch(XCOException* p_Exception)
	{
		p_Exception->Delete();
    MessageBox(_T("Exception while loading WC configuration"));
	}

  l_pConfig->ReleaseRef();
  
  if (l_dwParamArray)
    delete l_dwParamArray;
  l_dwParamArray = NULL;


  m_strActWCState = m_pWCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void DlgWedgeControl::OnBtnWcSetprofile() 
{
  WCHAR* l_pFileName = _T("\\Hard Disk\\NIRFlex\\WCProfile.txt");
  CFile l_f1;
  CString l_strVal;
  CString l_strConfig;
  int l_nLastPos = 0;
  int l_nActPos = 0;
  int l_nCount = 0;
  int l_nIndex = 0;
  char *l_pbuf;

  int l_nProfileSize = 2;
  DWORD *l_dwParamArray = new DWORD[l_nProfileSize];

  if( !l_f1.Open( l_pFileName, CFile::modeRead)) {
    MessageBox(_T("Could not load file -> \\Hard Disk\\NIRFlex\\WCProfile.txt"));
    return;
  }
  int l_nLength = (int)l_f1.GetLength(); // length in byte
  l_pbuf = new char[l_nLength];
  l_f1.Read(l_pbuf, l_nLength);
  l_strConfig+=l_pbuf;
  l_f1.Close();
  if (l_pbuf)
    delete l_pbuf;
  l_pbuf = NULL;

  while ((l_nCount + l_nActPos) < l_nLength)
  { 
    l_nActPos = l_strConfig.Find(_T(","), l_nLastPos);
    if (l_nActPos == -1)
    { // not found
      l_nActPos = l_nLength;
    }
    l_nCount = l_nActPos - l_nLastPos;
    if (l_nCount != 0)
    {
      l_strVal = l_strConfig.Mid(l_nLastPos,l_nCount);
      l_dwParamArray[l_nIndex] = _wtoi(((LPTSTR)l_strVal.GetBuffer(l_strVal.GetLength())));
      l_nIndex++;
      l_strVal.ReleaseBuffer();
      l_nLastPos = l_strConfig.Find(_T("\n"), l_nActPos) + 1;
    }
  }
  
  if(l_nIndex != l_nProfileSize)
  {
    MessageBox(_T("not all parameter of the wedge control profile are be loaded!"));
  }

  CPIWedgeControlProfile* l_pProfile = new CPIWedgeControlProfile(l_dwParamArray[0],  // p_dwScanMode
                                                                  l_dwParamArray[1]);  // p_dwRefDistance2
  try
  {
    CCOSyncObjectPtr l_SyncObjWCSetProfile = m_pWCIntf->SetProfile(l_pProfile);
	  ASSERT(l_SyncObjWCSetProfile != NULL);
	  l_SyncObjWCSetProfile->Synchronize();
  }
	catch(XCOException* p_Exception)
	{
		p_Exception->Delete();
    MessageBox(_T("Exception while loading WC profile"));
	}
  
  l_pProfile->ReleaseRef();
  
  if (l_dwParamArray)
    delete l_dwParamArray;
  l_dwParamArray = NULL;

  m_strActWCState = m_pWCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void DlgWedgeControl::OnBtnWcInitialize() 
{
  try
  {
    CCOSyncObjectPtr l_SyncObjWC = m_pWCIntf->Initialize();
	  ASSERT(l_SyncObjWC != NULL);
	  //l_SyncObjWC->Synchronize();
    m_strActWCState = m_pWCIntf->GetsCurrentState();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
  
  UpdateData(FALSE);
}

void DlgWedgeControl::OnBtnWcReferencing() 
{
  try
  {
    CCOSyncObjectPtr l_SyncObjWC = m_pWCIntf->Referencing();
	  ASSERT(l_SyncObjWC != NULL);
	  //l_SyncObjWC->Synchronize();
    m_strActWCState = m_pWCIntf->GetsCurrentState();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
}

void DlgWedgeControl::OnBtnWcStart() 
{
  try
  {
    CCOSyncObjectArrayPtr l_SyncObjWC = m_pWCIntf->Start();
	  ASSERT(l_SyncObjWC != NULL);
	  
    l_SyncObjWC->GetAt(0)->Synchronize();
    m_strActWCState = m_pWCIntf->GetsCurrentState();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
    
  
  UpdateData(FALSE);
}

void DlgWedgeControl::OnBtnWcStop() 
{
  try
  {
    CCOSyncObjectPtr l_SyncObjWC = m_pWCIntf->Stop();
	  ASSERT(l_SyncObjWC != NULL);
	  //l_SyncObjWC->Synchronize();
    m_strActWCState = m_pWCIntf->GetsCurrentState();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
  UpdateData(FALSE);
}


void DlgWedgeControl::OnBtnWcShutdown() 
{
  try
  {
    CCOSyncObjectPtr l_SyncObjWC = m_pWCIntf->Shutdown();
	  ASSERT(l_SyncObjWC != NULL);
	  //l_SyncObjWC->Synchronize();
    m_strActWCState = m_pWCIntf->GetsCurrentState();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
}


BOOL DlgWedgeControl::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  ((CButton*)GetDlgItem(IDC_RDO_CONTROLLER_ON))->SetCheck(1);

  m_pHWIntf = IHIInterface::GetInstance();

  m_pWCIntf = CPIObjectFactory::GetInstance()->CreateWedgeControl(1, _T(""));

  
  ((CButton*)GetDlgItem(IDC_RDO_LASER_ON))->SetCheck(1);		
  //((CButton*)GetDlgItem(IDC_RDO_OSCI_ON))->SetCheck(1);		

  m_strActWCState = m_pWCIntf->GetsCurrentState();
  UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgWedgeControl::OnBtnSetgetDword() 
{

  CDlgSetGetDWord dlg;
  dlg.DoModal();

}

void DlgWedgeControl::OnBtnUpdateState() 
{
  m_strActWCState = m_pWCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void DlgWedgeControl::OnBtnShowVelocityCounter() 
{
  
  CDlgWCVlcCnt dlg;
  dlg.DoModal();


}

void DlgWedgeControl::OnBtnWcPid() 
{

  UpdateData();
  // Controller On / Off
  try
  {

    if (((CButton*)GetDlgItem(IDC_RDO_CONTROLLER_ON))->GetCheck() == BST_CHECKED)
    { // ON
      m_pHWIntf->WCControllerON(TRUE);
    }
    else if (((CButton*)GetDlgItem(IDC_RDO_CONTROLLER_OFF))->GetCheck() == BST_CHECKED)
    { // OFF
      m_pHWIntf->WCControllerON(FALSE);
    }
    else
    {
      MessageBox(_T("no On / Off state active!"));
    }
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);

}

void DlgWedgeControl::OnBtnWcEmergencyStop() 
{
  try
  {
    m_pHWIntf->WCEmergencyStop();  
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
}

void DlgWedgeControl::OnBtnWcDacIni() 
{
  try
  {
    m_pHWIntf->WCInitializeDAC();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

}

void DlgWedgeControl::OnBtnLaserOnOff() 
{
  UpdateData();
  // Laser On / Off
  try
  {
    if (((CButton*)GetDlgItem(IDC_RDO_LASER_ON))->GetCheck() == BST_CHECKED)
    { // ON
      m_pHWIntf->SetDWord(2020, TRUE);
    }
    else if (((CButton*)GetDlgItem(IDC_RDO_LASER_OFF))->GetCheck() == BST_CHECKED)
    { // OFF
      m_pHWIntf->SetDWord(2020, FALSE);
    }
    else
    {
      MessageBox(_T("no On / Off state active!"));
    }
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
	
}

void DlgWedgeControl::OnBtnReadBuffer() 
{

  //char szTemp[200];
  int nStrLength = 0;
  DWORD numBytes = 0;

  int l_nRowCounter = 0;

  PDWORD l_pAdr = (PDWORD)0x48000000;

  DWORD l_dwSizeInDWord = *l_pAdr;

 // HANDLE hFile = CreateFile(_T("\\Windows\\MessData.txt"), GENERIC_WRITE|GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  
//  if (hFile == INVALID_HANDLE_VALUE)
//  {
//    MessageBox(_T("Couldn't create the file!"));
//    return;
//  }

  CStdioFile f1;
  if( !f1.Open( _T("\\Windows\\MessData.txt"), CFile::modeCreate | CFile::modeWrite | CFile::typeText ) )
  {
    MessageBox(_T("Couldn't create the file!"));
    return;
  }
  CString l_strData = _T("");

  for(DWORD ii = 0; ii < l_dwSizeInDWord; ii++)
  {
    
    //l_strData.Format(_T("%08x, %08x, %08x, %08x, %08x, %08x, %08x, %08x\r\n"),
    //f1.Write((LPCTSTR)l_strData, l_strData.GetLength());
    /*
    l_nRowCounter++;
    
    
    if (l_nRowCounter >= 8)
    {
      l_nRowCounter = 0;
      nStrLength = sprintf(szTemp,("%08x\r\n"),l_pAdr[ii]);
    }
    else
    {
      nStrLength = sprintf(szTemp,("%08x "),l_pAdr[ii]);
    }*/
    //WriteFile(hFile,&szTemp,nStrLength,&numBytes,0);
  }

  //CloseHandle(hFile);

}

void DlgWedgeControl::OnBtnOsciOnOff() 
{
  UpdateData();
  try
  {
    // Laser On / Off
    if (((CButton*)GetDlgItem(IDC_RDO_OSCI_ON))->GetCheck() == BST_CHECKED)
    { // ON
      //m_pHWIntf->WCOsciON(TRUE);
    }
    else if (((CButton*)GetDlgItem(IDC_RDO_OSCI_OFF))->GetCheck() == BST_CHECKED)
    { // OFF
      //m_pHWIntf->WCOsciON(FALSE);
    }
    else
    {
      MessageBox(_T("no On / Off state active!"));
    }
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
}


void DlgWedgeControl::OnBtnOnlyTest() 
{
  try
  {
    DWORD l_dwRetVal = 0;
    m_dwTest = 0;
    m_dwTest = (DWORD)m_pHWIntf->GetCurrentLaserLevelDetection();
  
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);

}
