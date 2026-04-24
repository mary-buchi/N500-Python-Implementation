// DlgSystemCompState.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBNFDlgSystemCompState.h"

#include "EBPIcpst.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSystemCompState dialog


DlgSystemCompState::DlgSystemCompState(CWnd* pParent /*=NULL*/)
	: CDialog(DlgSystemCompState::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgSystemCompState)
	//}}AFX_DATA_INIT
}


void DlgSystemCompState::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSystemCompState)
	DDX_Check(pDX, IDC_DLG_SYSCP_DI,		m_dwSysCP_DI_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_ES,		m_dwSysCP_ES_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_HI,		m_dwSysCP_HI_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_I2CADC,	m_dwSysCP_I2CADC_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_I2CDP,  	m_dwSysCP_I2CDP_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_I2CEPROM,	m_dwSysCP_I2CEPROM_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_I2TEMP,	m_dwSysCP_I2TEMP_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_IO,        m_dwSysCP_IO_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_MC,        m_dwSysCP_MC_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_PC,        m_dwSysCP_PC_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_PO,        m_dwSysCP_PO_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_ST,        m_dwSysCP_ST_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_TC,        m_dwSysCP_TC_ID);
	DDX_Check(pDX, IDC_DLG_SYSCP_WC,        m_dwSysCP_WC_ID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSystemCompState, CDialog)
	//{{AFX_MSG_MAP(DlgSystemCompState)
	ON_BN_CLICKED(IDC_DLG_SYSCP_DI, OnDlgSyscpDi)
	ON_BN_CLICKED(IDC_DLG_SYSCP_ES, OnDlgSyscpEs)
	ON_BN_CLICKED(IDC_DLG_SYSCP_I2CEPROM, OnDlgSyscpI2ceprom)
	ON_BN_CLICKED(IDC_DLG_SYSCP_I2TEMP, OnDlgSyscpI2temp)
	ON_BN_CLICKED(IDC_DLG_SYSCP_MC, OnDlgSyscpMc)
	ON_BN_CLICKED(IDC_DLG_SYSCP_PC, OnDlgSyscpPc)
	ON_BN_CLICKED(IDC_DLG_SYSCP_PO, OnDlgSyscpPo)
	ON_BN_CLICKED(IDC_DLG_SYSCP_ST, OnDlgSyscpSt)
	ON_BN_CLICKED(IDC_DLG_SYSCP_TC, OnDlgSyscpTc)
	ON_BN_CLICKED(IDC_DLG_SYSCP_WC, OnDlgSyscpWc)
	ON_BN_CLICKED(IDC_DLG_SYSCP_HI, OnDlgSyscpHi)
	ON_BN_CLICKED(IDC_DLG_SYSCP_IO, OnDlgSyscpIo)
	ON_BN_CLICKED(IDC_DLG_SYSCP_I2CDP, OnDlgSyscpI2cdp)
	ON_BN_CLICKED(IDC_DLG_SYSCP_I2CADC, OnDlgSyscpI2cadc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSystemCompState message handlers

BOOL DlgSystemCompState::OnInitDialog() 
{
	CDialog::OnInitDialog();

    CPIComponentsState *pCS = CPIComponentsState::GetInstance();
    m_dwSysCP_DI_ID         = pCS->GetComponentState(_T("DI"));
	m_dwSysCP_ES_ID         = pCS->GetComponentState(_T("ES"));
	m_dwSysCP_HI_ID         = pCS->GetComponentState(_T("HI"));
	m_dwSysCP_IO_ID         = pCS->GetComponentState(_T("IO"));
	m_dwSysCP_I2CADC_ID     = pCS->GetComponentState(_T("I2CADC"));
	m_dwSysCP_I2CDP_ID      = pCS->GetComponentState(_T("I2CDP"));
	m_dwSysCP_I2CEPROM_ID   = pCS->GetComponentState(_T("I2CEPROM"));
	m_dwSysCP_I2TEMP_ID     = pCS->GetComponentState(_T("I2CTEMP"));
	m_dwSysCP_MC_ID         = pCS->GetComponentState(_T("MC"));
	m_dwSysCP_PC_ID         = pCS->GetComponentState(_T("PC"));
	m_dwSysCP_PO_ID         = pCS->GetComponentState(_T("PO"));
	m_dwSysCP_ST_ID         = pCS->GetComponentState(_T("ST"));
	m_dwSysCP_TC_ID         = pCS->GetComponentState(_T("TC"));
	m_dwSysCP_WC_ID         = pCS->GetComponentState(_T("WC"));

	UpdateData(FALSE);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgSystemCompState::ChangeState(const CString& sId, BOOL& bVal)
{
    bVal = !bVal;
    bool bSet = (bVal != 0);
    CPIComponentsState::GetInstance()->SetComponentState(sId, bSet);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpDi() 
{
    ChangeState(_T("DI"), m_dwSysCP_DI_ID);
}

void DlgSystemCompState::OnDlgSyscpEs() 
{
    ChangeState(_T("ES"), m_dwSysCP_ES_ID);
}

void DlgSystemCompState::OnDlgSyscpI2ceprom() 
{
    ChangeState(_T("I2CEPROM"), m_dwSysCP_I2CEPROM_ID);
}

void DlgSystemCompState::OnDlgSyscpI2temp() 
{
    ChangeState(_T("I2CTEMP"), m_dwSysCP_I2TEMP_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpMc() 
{
    ChangeState(_T("MC"), m_dwSysCP_MC_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpPc() 
{
    ChangeState(_T("PC"), m_dwSysCP_PC_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpPo() 
{
    ChangeState(_T("PO"), m_dwSysCP_PO_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpSt() 
{
    ChangeState(_T("ST"), m_dwSysCP_ST_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpTc() 
{
    ChangeState(_T("TC"), m_dwSysCP_TC_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpWc() 
{
    ChangeState(_T("WC"), m_dwSysCP_WC_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpHi() 
{
    ChangeState(_T("HI"), m_dwSysCP_HI_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpIo() 
{
    ChangeState(_T("IO"), m_dwSysCP_IO_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpI2cdp() 
{
    ChangeState(_T("I2CDP"), m_dwSysCP_I2CDP_ID);
	UpdateData(FALSE);
}

void DlgSystemCompState::OnDlgSyscpI2cadc() 
{
    ChangeState(_T("I2CADC"), m_dwSysCP_I2CADC_ID);
	UpdateData(FALSE);
}
