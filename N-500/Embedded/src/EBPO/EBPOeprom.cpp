//## begin module%3FA118390232.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA118390232.cm

//## begin module%3FA118390232.cp preserve=no
//	/*====================================================*
//	  * Copyright  : Büchi Labortechnik AG, Meierseggstr. 40,
//	  *                   9230 Flawil, Switzerland.
//	  *
//	  * Filename   : $Workfile:$
//	  * System     :
//	  * Function   :
//	  * Author     :
//	  * References :
//	  * Contents   :
//	  *
//	  * $History:$
//	  *=====================================================*
//	  */
//## end module%3FA118390232.cp

//## Module: EBPOeprom%3FA118390232; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOeprom.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FA118390232.additionalIncludes preserve=no
//## end module%3FA118390232.additionalIncludes

//## begin module%3FA118390232.includes preserve=yes
//## end module%3FA118390232.includes

// windef
#include "windef.h"
// EBPIconst
#include "EBPIconst.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPItype
#include "EBPItype.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
// EBPOexcp
#include "EBPOexcp.h"
// EBPOsimu
#include "EBPOsimu.h"
// EBPOeprom
#include "EBPOeprom.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOimpl
#include "EBPOimpl.h"
// EBPOidnt
#include "EBPOidnt.h"


//## begin module%3FA118390232.declarations preserve=no
//## end module%3FA118390232.declarations

//## begin module%3FA118390232.additionalDeclarations preserve=yes
//## end module%3FA118390232.additionalDeclarations


// Class CPOEpromManager 

























CPOEpromManager::CPOEpromManager (const DWORD p_dwEpromID, CPOPersistentObjImplementation* p_pImpl)
  //## begin CPOEpromManager::CPOEpromManager%1067522287.hasinit preserve=no
      : m_bHardwarePresent(false), m_pEpromSimulation(NULL), m_pImpl(p_pImpl), m_bHeaderInfoUpToDate(false), m_iIdentLength(0), m_iParaLegth(0), m_iLifeTimeLegth(0), m_iPageSize(0), m_pEprom(NULL), m_iActiveEpromHalf(0)
  //## end CPOEpromManager::CPOEpromManager%1067522287.hasinit
  //## begin CPOEpromManager::CPOEpromManager%1067522287.initialization preserve=yes
  //## end CPOEpromManager::CPOEpromManager%1067522287.initialization
{
  //## begin CPOEpromManager::CPOEpromManager%1067522287.body preserve=yes
    m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(PO_ID);

	if (m_bHardwarePresent)
	{
		m_pEprom = CPIObjectFactory::GetInstance()->CreateEprom24LC515(p_dwEpromID, _T(""));
	}
	else
	{
		CString l_sFileName;

		if (p_dwEpromID == 5006)
		{
			l_sFileName = _T("EpromMainboard.bin");
		}
		else if (p_dwEpromID == 5102)
		{
			l_sFileName = _T("EpromApplication.bin");
		}
		else if (p_dwEpromID == 5103)
		{
			l_sFileName = _T("EpromDetector.bin");
		}
		else
		{
			ASSERT(false);
		}

		m_pEprom = new CPOEpromSimulation(l_sFileName);
	}

    m_iPageSize = m_pEprom->GetEprom24LC515PageSizeInByte();
	m_iEpromSizeInByte = m_pEprom->GetEprom24LC515SizeInByte();
	UpgradeEpromVersion();
  //## end CPOEpromManager::CPOEpromManager%1067522287.body
}


CPOEpromManager::~CPOEpromManager()
{
  //## begin CPOEpromManager::~CPOEpromManager%.body preserve=yes

	// if m_bHardwarePresent==true then the interface belongs to the object factory
	if (!m_bHardwarePresent)
		delete m_pEprom;
	m_pEprom = NULL;

	ResetMergedList(ePISectionIdent);
	ResetMergedList(ePISectionPara);
	ResetMergedList(ePISectionLifeTimeCounter);

	ResetNewLists();
	ResetExistingList(ePISectionIdent);
	ResetExistingList(ePISectionPara);
	ResetExistingList(ePISectionLifeTimeCounter);

	ResetUpdatedLifeTimeList();

  //## end CPOEpromManager::~CPOEpromManager%.body
}



//## Other Operations (implementation)
CString CPOEpromManager::CreateHeader ()
{
  //## begin CPOEpromManager::CreateHeader%1067522279.body preserve=yes
    // CO_TRACE(PO_ID, _T("start CreateHeader"));

	m_bHeaderInfoUpToDate = false;

	m_iIdentLength = SectionLength(ePISectionIdent);
	m_iParaLegth = SectionLength(ePISectionPara);
	m_iLifeTimeLegth = SectionLength(ePISectionLifeTimeCounter);
	
	CString l_sHeader, l_sDummy, l_sFormatString;

	l_sDummy.Format(HEADER_VER + _T("=%d,"), HEADER_VERSION);
    l_sHeader += l_sDummy;

	l_sDummy.Format(ID_LEN + _T("=%d,"), m_iIdentLength);
    l_sHeader += l_sDummy;

	l_sDummy.Format(PARA_LEN + _T("=%d,"), m_iParaLegth);
    l_sHeader += l_sDummy;

	l_sDummy.Format(LTC_LEN + _T("=%d;"), m_iLifeTimeLegth);
    l_sHeader += l_sDummy;

	l_sDummy.Format(_T("%d"), HEADER_LEN);
	l_sFormatString = _T("%.") + l_sDummy + _T("d");

	m_iHeaderLength = (l_sHeader.GetLength() + 1);

	l_sDummy.Format(l_sFormatString, m_iHeaderLength);
	l_sHeader.Insert(0, l_sDummy);

    // CO_TRACE(PO_ID, _T("end CreateHeader"));
	return l_sHeader;

  //## end CPOEpromManager::CreateHeader%1067522279.body
}

void CPOEpromManager::EpromCapacity ()
{
  //## begin CPOEpromManager::EpromCapacity%1072775571.body preserve=yes
	
    // CO_TRACE(PO_ID, _T("start EpromCapacity"));

	int l_iTotLen = CalcNoOfPages(SectionLength(ePISectionHeader)) * m_iPageSize;
	l_iTotLen += CalcNoOfPages(SectionLength(ePISectionIdent)) * m_iPageSize;
	l_iTotLen += CalcNoOfPages(SectionLength(ePISectionPara)) * m_iPageSize;
	l_iTotLen += CalcNoOfPages(SectionLength(ePISectionLifeTimeCounter)) * m_iPageSize;
	l_iTotLen += HEADER_LEN;

	int l_iMaxSize = (m_iEpromSizeInByte-1) / BYTES_PER_CHAR / 2;

	if (l_iTotLen  >= l_iMaxSize)
	{
		// Exception eprom full.
		CString l_sTrace;
		l_sTrace.Format(_T("Exception in file: %s line: %d. Eprom full."),_T(__FILE__), __LINE__);
		// CO_TRACE(PO_ID, l_sTrace);
		throw new XPOExceptionEpromFull(PO_ID, IDE_EPROM_FULL, _T(__FILE__), __LINE__, 0);
	}
    // CO_TRACE(PO_ID, _T("end EpromCapacity"));

  //## end CPOEpromManager::EpromCapacity%1072775571.body
}

void CPOEpromManager::WritePageBlocks (const int p_iStartAdr, const CString& p_sContent)
{
  //## begin CPOEpromManager::WritePageBlocks%1068021102.body preserve=yes

	CCOSyncObject *l_pSyncObj = NULL;
	int l_iNop = CalcNoOfPages(p_sContent.GetLength() + 1);

	// Memory for the unicode char buffer.
	wchar_t *l_pWcharBuf = new wchar_t[l_iNop * m_iPageSize];
 	ZeroMemory(l_pWcharBuf, (l_iNop * m_iPageSize) * BYTES_PER_CHAR);

	try
	{
		wcscpy(l_pWcharBuf, (LPCTSTR)p_sContent);
		BYTE *l_pByteBuf = (BYTE*)l_pWcharBuf;
	    
		int l_iPageAdr = 0;
		for (int l_it = 0; l_it < l_iNop; l_it++)
		{
			l_iPageAdr = l_it * m_iPageSize;
			l_pSyncObj = m_pEprom->PageWrite((l_iPageAdr + p_iStartAdr), &l_pByteBuf[l_iPageAdr], m_iPageSize); 
			l_pSyncObj->Synchronize(TIME_OUT);

			if (l_pSyncObj != NULL)
				l_pSyncObj->ReleaseRef();
			l_pSyncObj = NULL;
   		}
		if (l_pWcharBuf != NULL)
			delete [] l_pWcharBuf;
		l_pWcharBuf = NULL;
	}
	catch(...)
	{
   		if (l_pWcharBuf != NULL)
			delete [] l_pWcharBuf;
		l_pWcharBuf = NULL;

		if (l_pSyncObj != NULL)
			l_pSyncObj->ReleaseRef();
		l_pSyncObj = NULL;

        throw;
	}
	
    // CO_TRACE(PO_ID, _T("end WritePageBlocks"));

  //## end CPOEpromManager::WritePageBlocks%1068021102.body
}

int CPOEpromManager::GetHeaderLength ()
{
  //## begin CPOEpromManager::GetHeaderLength%1068021107.body preserve=yes
    // CO_TRACE(PO_ID, _T("start GetHeaderLength"));

    CPISyncObjI2CDataStream *l_pSyncObj = NULL;
	CPII2CDataStream *l_pData = NULL;

	try
	{
		int l_nBufSize = HEADER_LEN * BYTES_PER_CHAR;
		int l_iLength = 0;

		if (!m_bHeaderInfoUpToDate)
		{
			GetEpromHalf();
        
			// Read header first 6 chars. This is the value for the Header length.
			int l_iStartAdr = m_iActiveEpromHalf * m_iEpromSizeInByte / 2;
			l_pSyncObj = m_pEprom->BlockRead(l_iStartAdr, l_nBufSize);

   			l_pSyncObj->Synchronize(TIME_OUT);
			l_pData = l_pSyncObj->GetValue();
			l_pSyncObj->ReleaseRef();
			l_pSyncObj = NULL;

			if (l_pData->GetnSize() != l_nBufSize)
			{
				// Exception wrong data size.
				CString l_sTrace;
				l_sTrace.Format(_T("Exception in file: %s line: %d. Wrong data size returned form eprom."),_T(__FILE__), __LINE__);
				// CO_TRACE(PO_ID, l_sTrace);
				throw new XPOExceptionHeader(PO_ID, IDE_WRONG_DATASIZE, _T(__FILE__), __LINE__, 0);
			}

			l_iLength = _wtoi((LPCTSTR)l_pData->GetpcI2CDataStream());
			l_iLength += HEADER_LEN;

  			if (l_pData != NULL)
				l_pData->ReleaseRef();
			l_pData = NULL;

			m_iHeaderLength = l_iLength;
		}
		// CO_TRACE(PO_ID, _T("end GetHeaderLength"));

		return m_iHeaderLength;
	}
	catch(...)
	{
		if (l_pSyncObj != NULL)
			l_pSyncObj->ReleaseRef();
		if (l_pData != NULL)
			l_pData->ReleaseRef();

		throw;
	}

  //## end CPOEpromManager::GetHeaderLength%1068021107.body
}

int CPOEpromManager::CalcNoOfPages (const int p_iLength)
{
  //## begin CPOEpromManager::CalcNoOfPages%1068021111.body preserve=yes
    // CO_TRACE(PO_ID, _T("start CalcNoOfPages"));
	return (int) ceil((double)p_iLength * BYTES_PER_CHAR / (double) m_iPageSize);
    // CO_TRACE(PO_ID, _T("end CalcNoOfPages"));

  //## end CPOEpromManager::CalcNoOfPages%1068021111.body
}

int CPOEpromManager::ReadStartAddress (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::ReadStartAddress%1068021115.body preserve=yes

    // CO_TRACE(PO_ID, _T("begin ReadStartAddress"));

	int l_iAdr = 0;

	switch(p_eSection)
	{
	case ePISectionLifeTimeCounter:
		l_iAdr += CalcNoOfPages(ReadSectionLength(ePISectionPara));

	case ePISectionPara:
		l_iAdr += CalcNoOfPages(ReadSectionLength(ePISectionIdent));

	case ePISectionIdent:
		l_iAdr += CalcNoOfPages(GetHeaderLength());

	case ePISectionHeader:
		break;

	default:
		ASSERT(false);
		break;
	}

	l_iAdr *= m_iPageSize;

	// determine eprom half
	l_iAdr += (m_iEpromSizeInByte / 2) * m_iActiveEpromHalf;

    // CO_TRACE(PO_ID, _T("end ReadStartAddress"));
	return l_iAdr;
  //## end CPOEpromManager::ReadStartAddress%1068021115.body
}

int CPOEpromManager::CalcStartAddress (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::CalcStartAddress%1068104009.body preserve=yes
    // CO_TRACE(PO_ID, _T("start CalcStartAddress"));

	//	1. Seciton:	Header		startAddress: start address
	//	2. Section:	Ident		startAddress: start address + (number of pages of header)
	//  3. Section: Para		startAddress: start address + (number of pages of header) + (number of pages of ident)
	//	4. Section: Lifetime	ect.

	int l_iPage = 0;

	switch(p_eSection)
	{
	case ePISectionLifeTimeCounter:
		l_iPage += CalcNoOfPages(SectionLength(ePISectionPara));

	case ePISectionPara:
		l_iPage += CalcNoOfPages(SectionLength(ePISectionIdent));

	case ePISectionIdent:
		l_iPage += CalcNoOfPages(SectionLength(ePISectionHeader));

	case ePISectionHeader:
		l_iPage += 0;
		break;

	default:
		ASSERT(false);
	}

	l_iPage *= m_iPageSize;

	// determine eprom half
	if (m_iActiveEpromHalf == 0)
        l_iPage += (m_iEpromSizeInByte / 2);

    // CO_TRACE(PO_ID, _T("end CalcStartAddress"));
	return (l_iPage);
  //## end CPOEpromManager::CalcStartAddress%1068104009.body
}

int CPOEpromManager::ReadSectionLength (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::ReadSectionLength%1068104010.body preserve=yes

    // CO_TRACE(PO_ID, _T("begin ReadSectionLength"));

	if (!m_bHeaderInfoUpToDate)
	{
		// try to read header
		CString l_sHeader = ReadHeader(false);
		m_bHeaderInfoUpToDate = ParseHeader(l_sHeader);
	}

    // CO_TRACE(PO_ID, _T("end ReadSectionLength"));
	if (m_bHeaderInfoUpToDate)
	{
		switch(p_eSection)
		{
		case ePISectionIdent:
			return m_iIdentLength;
			break;

		case ePISectionPara:
			return m_iParaLegth;
			break;

		case ePISectionLifeTimeCounter:
			return m_iLifeTimeLegth;
			break;

		default:
			ASSERT(false);
			return 0;
		}
	}
	else
	{
		return 0;
	}

  //## end CPOEpromManager::ReadSectionLength%1068104010.body
}

void CPOEpromManager::Write (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::Write%1068104008.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin Write"));
	m_bHeaderInfoUpToDate = false;
	CString l_sSection = CreateSectionString(p_eSection);
	int l_iStartAdr = CalcStartAddress(p_eSection);
	int l_iLen = SectionLength(p_eSection);

	if (l_iLen > 0)
	{
		WritePageBlocks(l_iStartAdr, l_sSection);
	}
    // CO_TRACE(PO_ID, _T("end Write"));
  //## end CPOEpromManager::Write%1068104008.body
}

CString CPOEpromManager::CreateSectionString (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::CreateSectionString%1068104012.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin CreateSectionString"));

	CTypedPtrList<CPtrList, CPIPersistentItem*> *l_pItemList;
	CString l_sSection = _T(""), l_sDummy;
    
	switch (p_eSection)
	{
	case ePISectionHeader:
		return CreateHeader();
		break;

	case ePISectionIdent:
		l_pItemList = &m_IdentMergedList;
		break;

	case ePISectionPara:
		l_pItemList = &m_ParaMergedList;
		break;

	case ePISectionLifeTimeCounter:
		l_pItemList = &m_LifeTimeMergedList;
		break;

	default:
		ASSERT(false);
	}

	// make one long long string
	for (POSITION l_Pos = l_pItemList->GetHeadPosition(); l_Pos != NULL;)
	{
		CPIPersistentItem *l_pItem = l_pItemList->GetNext(l_Pos);
		ASSERT(l_pItem != NULL);
		
		l_sDummy = l_pItem->ToString();
		l_sSection += l_sDummy;
	}

    // CO_TRACE(PO_ID, _T("end CreateSectionString"));
	return l_sSection;

  //## end CPOEpromManager::CreateSectionString%1068104012.body
}

int CPOEpromManager::SectionLength (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::SectionLength%1068104014.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin SectionLength"));

	CString l_sSection = CreateSectionString(p_eSection);
	int l_iLen = l_sSection.GetLength();

	if (l_iLen > 0)
	{
		// each eprom section is terminated with zero \0
		l_iLen += 1;
	}
    // CO_TRACE(PO_ID, _T("end SectionLength"));

	return l_iLen;
  //## end CPOEpromManager::SectionLength%1068104014.body
}

void CPOEpromManager::Save ()
{
  //## begin CPOEpromManager::Save%1068194979.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin Save"));

	ReadAll();

	Merge();
	ResetNewLists();

	EpromCapacity();

	WriteAll();

	m_bHeaderInfoUpToDate = true;

	ResetExistingList(ePISectionIdent);
	ResetExistingList(ePISectionPara);
	ResetExistingList(ePISectionLifeTimeCounter);

	ResetMergedList(ePISectionIdent);
	ResetMergedList(ePISectionPara);
	ResetMergedList(ePISectionLifeTimeCounter);
    // CO_TRACE(PO_ID, _T("end Save"));

  //## end CPOEpromManager::Save%1068194979.body
}

void CPOEpromManager::CreateItemList (EPIEpromSection p_eSection, CString& p_sSectionString)
{
  //## begin CPOEpromManager::CreateItemList%1068194980.body preserve=yes

    // CO_TRACE(PO_ID, _T("begin CreateItemList"));

	// Reset list before creating new one.
	ResetExistingList(p_eSection);
	CStringList l_List;
	POSITION l_Pos;
	CString l_sItem;
	CPIPersistentItem *l_pItem = NULL;

	CPIPersistentItem::Split(p_sSectionString, _T(";"), l_List);
	for (l_Pos = l_List.GetHeadPosition(); l_Pos != NULL;)
	{
		l_sItem = l_List.GetNext(l_Pos);
		ASSERT(l_sItem != _T(""));

		switch (p_eSection)
		{
		case ePISectionHeader:
			ASSERT(false);
			break;
		
		case ePISectionIdent:
			{
				l_pItem = new CPIPersistentIdent(l_sItem);
				m_IdentExistingList.AddTail(l_pItem);
			}
			break;

		case ePISectionPara:
			{
				l_pItem = new CPIPersistentPara(l_sItem);
				m_ParaExistingList.AddTail(l_pItem);
			}
			break;

		case ePISectionLifeTimeCounter:
			{
				l_pItem = new CPOLifeTimeCounter(l_sItem);
				m_LifeTimeExistingList.AddTail(l_pItem);
			}
			break;

		default:
			{
				ASSERT(false);
			}
		}
	}

    // CO_TRACE(PO_ID, _T("end CreateItemList"));

  //## end CPOEpromManager::CreateItemList%1068194980.body
}

void CPOEpromManager::WriteParameter (CPIPersistentPara* p_pPara)
{
  //## begin CPOEpromManager::WriteParameter%1068448308.body preserve=yes
    
    // CO_TRACE(PO_ID, _T("begin WriteParameter"));

	RemovePara(p_pPara);			// remove para if it exists already.
	m_ParaNewList.AddTail(p_pPara);	// add new para to list
	p_pPara->AddRef();
    // CO_TRACE(PO_ID, _T("end WriteParameter"));

  //## end CPOEpromManager::WriteParameter%1068448308.body
}

void CPOEpromManager::WriteLifeTimeCounter (CPOLifeTimeCounter* p_pLifeTime)
{
  //## begin CPOEpromManager::WriteLifeTimeCounter%1068448309.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin WriteLifeTimeCounter"));

    RemoveLifeTime(p_pLifeTime);			// remove para if it exists already.
	m_LifeTimeNewList.AddTail(p_pLifeTime);	// add new para to list
	p_pLifeTime->AddRef();
    // CO_TRACE(PO_ID, _T("end WriteLifeTimeCounter"));
  //## end CPOEpromManager::WriteLifeTimeCounter%1068448309.body
}

void CPOEpromManager::WriteIdentification (CPIPersistentIdent* p_pIdentification)
{
  //## begin CPOEpromManager::WriteIdentification%1068448310.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin WriteIdentification"));

	RemoveIdent(p_pIdentification);			// remove para if it exists already.
	m_IdentNewList.AddTail(p_pIdentification);	// add new para to list
	p_pIdentification->AddRef();
    // CO_TRACE(PO_ID, _T("end WriteIdentification"));
  //## end CPOEpromManager::WriteIdentification%1068448310.body
}

void CPOEpromManager::Merge ()
{
  //## begin CPOEpromManager::Merge%1068458449.body preserve=yes

    // CO_TRACE(PO_ID, _T("begin Merge"));

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// Identification:
	CPIPersistentIdent* l_pExistingIdent = NULL;
	CPIPersistentItem* l_pItem = NULL;
	bool l_bFound = false;

	// add all new items to merged list
	POSITION l_Pos = m_IdentNewList.GetHeadPosition();
	while (l_Pos != NULL)
	{
		l_pItem = m_IdentNewList.GetNext(l_Pos);
		m_IdentMergedList.AddTail(l_pItem);
		l_pItem->AddRef();
	}

	// add existing items to merged list if they are not in the new list
    l_Pos = m_IdentExistingList.GetHeadPosition();
	while (l_Pos != NULL)
	{
		l_pItem = m_IdentExistingList.GetNext(l_Pos);
        l_pExistingIdent = dynamic_cast<CPIPersistentIdent*>(l_pItem);

		l_bFound = FindIdent(l_pExistingIdent, eNew); // Find ident in new list.

		if (!l_bFound)
		{
			m_IdentMergedList.AddTail(l_pExistingIdent);
			l_pExistingIdent->AddRef();
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// Parameter:
	CPIPersistentPara *l_pExistingPara = NULL;

	// add all new items to merged list
	l_Pos = m_ParaNewList.GetHeadPosition();
	while (l_Pos != NULL)
	{
		l_pItem = m_ParaNewList.GetNext(l_Pos);
		m_ParaMergedList.AddTail(l_pItem);
		l_pItem->AddRef();
	}

	// add existing items to merged list if they are not in the new list
    l_Pos = m_ParaExistingList.GetHeadPosition();
	while (l_Pos != NULL)
	{
		l_pItem = m_ParaExistingList.GetNext(l_Pos);
        l_pExistingPara = dynamic_cast<CPIPersistentPara*>(l_pItem);

		l_bFound = FindPara(l_pExistingPara, eNew);

		if (!l_bFound)
		{
			m_ParaMergedList.AddTail(l_pExistingPara);
			l_pExistingPara->AddRef();
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// Lifetime counter:
	CPOLifeTimeCounter *l_pDummy, *l_pNewCounter = NULL, *l_pExistingCounter = NULL;

	// add all new items to merged list
	l_Pos = m_LifeTimeNewList.GetHeadPosition();
	while (l_Pos != NULL)
	{
		l_pItem = m_ParaNewList.GetNext(l_Pos);
		m_LifeTimeMergedList.AddTail(l_pItem);
		l_pItem->AddRef();
	}

	// add existing items to merged list if they are not in the new list
	l_Pos = m_LifeTimeExistingList.GetHeadPosition();
	while (l_Pos != NULL)
	{
		l_pItem = m_LifeTimeExistingList.GetNext(l_Pos);
        l_pExistingCounter = dynamic_cast<CPOLifeTimeCounter*>(l_pItem);

		l_pDummy = FindLifeTime(l_pExistingCounter, eNew);

		if (l_pDummy == NULL)
		{
			m_LifeTimeMergedList.AddTail(l_pExistingCounter);
			l_pExistingCounter->AddRef();
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////
    // CO_TRACE(PO_ID, _T("end Merge"));

  //## end CPOEpromManager::Merge%1068458449.body
}

void CPOEpromManager::UpdateLifeTimeCounter (CPOLifeTimeCounter* p_pLifeTimeCounter)
{
  //## begin CPOEpromManager::UpdateLifeTimeCounter%1068458450.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin UpdateLifeTimeCounter"));
	m_UpdateLifeTimeCounterList.AddTail(p_pLifeTimeCounter);
	p_pLifeTimeCounter->AddRef();
    // CO_TRACE(PO_ID, _T("end UpdateLifeTimeCounter"));
  //## end CPOEpromManager::UpdateLifeTimeCounter%1068458450.body
}

void CPOEpromManager::ResetMergedList (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::ResetMergedList%1068534762.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin ResetMergedList"));

    switch (p_eSection)
	{
	case ePISectionIdent:
		{
			for (POSITION l_Pos1 = m_IdentMergedList.GetHeadPosition(); l_Pos1 != NULL;)
			{
				CPIPersistentItem *l_pItem = m_IdentMergedList.GetNext(l_Pos1);        
				l_pItem->ReleaseRef();
				l_pItem = NULL;
			}
			m_IdentMergedList.RemoveAll();
		}
		break;

	case ePISectionPara:
		{
			for (POSITION l_Pos2 = m_ParaMergedList.GetHeadPosition(); l_Pos2 != NULL;)
			{
				CPIPersistentItem *l_pItem = m_ParaMergedList.GetNext(l_Pos2);        
				l_pItem->ReleaseRef();
				l_pItem = NULL;
			}
			m_ParaMergedList.RemoveAll();
		}
		break;

	case ePISectionLifeTimeCounter:
		{
			for (POSITION l_Pos3 = m_LifeTimeMergedList.GetHeadPosition(); l_Pos3 != NULL;)
			{
				CPIPersistentItem *l_pItem = m_LifeTimeMergedList.GetNext(l_Pos3);        
				l_pItem->ReleaseRef();
				l_pItem = NULL;
			}
			m_LifeTimeMergedList.RemoveAll();
		}
		break;

	default:
		ASSERT(false);
	}
    // CO_TRACE(PO_ID, _T("end ResetMergedList"));

  //## end CPOEpromManager::ResetMergedList%1068534762.body
}

void CPOEpromManager::ResetNewLists ()
{
  //## begin CPOEpromManager::ResetNewLists%1068534763.body preserve=yes

	for (POSITION l_Pos1 = m_IdentNewList.GetHeadPosition(); l_Pos1 != NULL;)
	{
		CPIPersistentItem *l_pItem = m_IdentNewList.GetNext(l_Pos1);        
		l_pItem->ReleaseRef();
		l_pItem = NULL;
	}
	m_IdentNewList.RemoveAll();

	for (POSITION l_Pos2 = m_ParaNewList.GetHeadPosition(); l_Pos2 != NULL;)
	{
		CPIPersistentItem *l_pItem = m_ParaNewList.GetNext(l_Pos2);        
		l_pItem->ReleaseRef();
		l_pItem = NULL;
	}
	m_ParaNewList.RemoveAll();

	for (POSITION l_Pos3 = m_LifeTimeNewList.GetHeadPosition(); l_Pos3 != NULL;)
	{
		CPIPersistentItem *l_pItem = m_LifeTimeNewList.GetNext(l_Pos3);        
		l_pItem->ReleaseRef();
		l_pItem = NULL;
	}
	m_LifeTimeNewList.RemoveAll();

  //## end CPOEpromManager::ResetNewLists%1068534763.body
}

void CPOEpromManager::Reset (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::Reset%1073378944.body preserve=yes

	ResetExistingList(ePISectionIdent);
	ResetExistingList(ePISectionPara);
	ResetExistingList(ePISectionLifeTimeCounter);

	ResetMergedList(ePISectionIdent);
	ResetMergedList(ePISectionPara);
	ResetMergedList(ePISectionLifeTimeCounter);

	ResetNewLists();

	switch(p_eSection)
	{
	case ePISectionHeader:
		break;

	case ePISectionIdent:
		ReadSection(ePISectionPara);
		ReadSection(ePISectionLifeTimeCounter);
		break;

	case ePISectionPara:
		ReadSection(ePISectionIdent);
		ReadSection(ePISectionLifeTimeCounter);
		break;

	case ePISectionLifeTimeCounter:
		ReadSection(ePISectionIdent);
		ReadSection(ePISectionPara);
		break;

	default:
		ASSERT(false);
		break;
	}

	Merge();
	WriteAll();

	ResetNewLists();

	ResetExistingList(ePISectionIdent);
	ResetExistingList(ePISectionPara);
	ResetExistingList(ePISectionLifeTimeCounter);

	ResetMergedList(ePISectionIdent);
	ResetMergedList(ePISectionPara);
	ResetMergedList(ePISectionLifeTimeCounter);

  //## end CPOEpromManager::Reset%1073378944.body
}

bool CPOEpromManager::FindIdent (CPIPersistentIdent* p_pIdent, EPOListType p_eListType)
{
  //## begin CPOEpromManager::FindIdent%1073378945.body preserve=yes
	CString l_sNewArtNo;
	CString l_sExistingArtNo = p_pIdent->GetsArticleNo();
	CPIPersistentIdent *l_pNew = NULL;
	CPIPersistentItem *l_pItem = NULL;
	POSITION l_Pos = NULL;
	bool l_bFound = false;

	CTypedPtrList<CPtrList, CPIPersistentItem*> *l_pList;

	// select list
	switch(p_eListType)
	{
	case eNew:
		l_pList = &m_IdentNewList;
		break;

	case eExisting:
		l_pList = &m_IdentExistingList;
		break;

	case eMerged:
		l_pList = &m_IdentMergedList;
		break;

	default:
		ASSERT(false);
	}

	l_Pos = l_pList->GetHeadPosition();
	while ((l_Pos != NULL) && !l_bFound)
	{
		l_pItem = l_pList->GetNext(l_Pos);
		l_pNew = dynamic_cast<CPIPersistentIdent*>(l_pItem);
		ASSERT(l_pNew != NULL);
		l_sNewArtNo = l_pNew->GetsArticleNo();

		l_bFound = (l_sNewArtNo == l_sExistingArtNo);
	}

	return l_bFound;

  //## end CPOEpromManager::FindIdent%1073378945.body
}

bool CPOEpromManager::FindPara (CPIPersistentPara* p_pPara, EPOListType p_eListType)
{
  //## begin CPOEpromManager::FindPara%1073460966.body preserve=yes

	CString l_sNewParaName;
	CString l_sExistingParaName = p_pPara->GetsParaName();
	CPIPersistentPara *l_pNew = NULL;
	CPIPersistentItem *l_pItem = NULL;
	bool l_bFound = false;

	CTypedPtrList<CPtrList, CPIPersistentItem*> *l_pList;

	// select list
	switch(p_eListType)
	{
	case eNew:
		l_pList = &m_ParaNewList;
		break;

	case eExisting:
		l_pList = &m_ParaExistingList;
		break;

	case eMerged:
		l_pList = &m_ParaMergedList;
		break;

	default:
		ASSERT(false);
	}

	POSITION l_Pos = l_pList->GetHeadPosition();
	while ((l_Pos != NULL) && !l_bFound)
	{
		l_pItem = l_pList->GetNext(l_Pos);
		l_pNew = dynamic_cast<CPIPersistentPara*>(l_pItem);
		ASSERT(l_pNew != NULL);
		l_sNewParaName = l_pNew->GetsParaName();

		l_bFound = (l_sNewParaName == l_sExistingParaName);
	}

	return l_bFound;

  //## end CPOEpromManager::FindPara%1073460966.body
}

CPOLifeTimeCounter* CPOEpromManager::FindLifeTime (CPOLifeTimeCounter* p_pLifeTime, EPOListType p_eListType)
{
  //## begin CPOEpromManager::FindLifeTime%1073460967.body preserve=yes

	// returns counter if found, NULL otherwise

	EPILifeTimeCounter l_eCntFound;
	EPILifeTimeCounter l_eCntToSearch = p_pLifeTime->GeteDevice();
	CPOLifeTimeCounter *l_pNew = NULL;
	CPIPersistentItem *l_pItem = NULL;

	CTypedPtrList<CPtrList, CPIPersistentItem*> *l_pSearchList;

	// select list
	switch(p_eListType)
	{
	case eNew:
		l_pSearchList = &m_LifeTimeNewList;
		break;

	case eExisting:
		l_pSearchList = &m_LifeTimeExistingList;
		break;

	case eMerged:
		l_pSearchList = &m_LifeTimeMergedList;
		break;

	default:
		ASSERT(false);
	}

	POSITION l_Pos = l_pSearchList->GetHeadPosition();
	while (l_Pos != NULL) 
	{
		l_pItem = l_pSearchList->GetNext(l_Pos);
		l_pNew = dynamic_cast<CPOLifeTimeCounter*>(l_pItem);
		ASSERT(l_pNew != NULL);

		l_eCntFound = l_pNew->GeteDevice();
		if (l_eCntFound == l_eCntToSearch)
		{
			return l_pNew;
		}
	}
	return NULL;

  //## end CPOEpromManager::FindLifeTime%1073460967.body
}

CString CPOEpromManager::ReadSection (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::ReadSection%1073460968.body preserve=yes
	
    CPISyncObjI2CDataStream *l_pSyncObj = NULL;
    CPII2CDataStream *l_pData = NULL;

	try
	{
		CString l_sSection;
		int l_iSize = ReadSectionLength(p_eSection) * BYTES_PER_CHAR;
		CPISyncObjI2CDataStream *l_pSyncObj = NULL;
		CPII2CDataStream *l_pData = NULL;

		if (l_iSize != 0)
		{
			int l_iStartAdr = ReadStartAddress(p_eSection);

			// Read header content.
			l_pSyncObj = m_pEprom->BlockRead((WORD)l_iStartAdr, l_iSize);
			l_pSyncObj->Synchronize(TIME_OUT);
			l_pData = l_pSyncObj->GetValue();
			l_pSyncObj->ReleaseRef();
			l_pSyncObj = NULL;

			if (l_pData->GetnSize() != l_iSize)
			{
				// Exception wrong data size.
				CString l_sTrace;
				l_sTrace.Format(_T("Exception in file: %s line: %d. Wrong data size returned form eprom."),_T(__FILE__), __LINE__);
				// CO_TRACE(PO_ID, l_sTrace);
				throw new XPOExceptionHeader(PO_ID, IDE_WRONG_DATASIZE, _T(__FILE__), __LINE__, 0);
			}

			switch (p_eSection)
			{
			case ePISectionHeader:
				{
				// We don't need the first 6 chars (12 bytes). Start copy at the 6th char. 			
				l_sSection = (LPCTSTR) &l_pData->GetpcI2CDataStream()[HEADER_LEN * BYTES_PER_CHAR];
				}
				break;
    		
			case ePISectionIdent:
			case ePISectionPara:
			case ePISectionLifeTimeCounter:
				{
				l_sSection = (LPCTSTR) l_pData->GetpcI2CDataStream();
				CreateItemList(p_eSection, l_sSection);
				}
				break;

			default:
				{
					ASSERT(false);
				}
			}

			if (l_pData != NULL)
				l_pData->ReleaseRef();
			l_pData = NULL;
		}

		// CO_TRACE(PO_ID, _T("end ReadSection"));

		return l_sSection;
	}
	catch(...)
	{
		if (l_pSyncObj != NULL)
			l_pSyncObj->ReleaseRef();
		if (l_pData != NULL)
			l_pData->ReleaseRef();

		throw;
	}
  //## end CPOEpromManager::ReadSection%1073460968.body
}

void CPOEpromManager::ReadAll ()
{
  //## begin CPOEpromManager::ReadAll%1073460969.body preserve=yes
	ReadSection(ePISectionIdent);
	ReadSection(ePISectionPara);
	ReadSection(ePISectionLifeTimeCounter);
  //## end CPOEpromManager::ReadAll%1073460969.body
}

void CPOEpromManager::ResetExistingList (EPIEpromSection p_eSection)
{
  //## begin CPOEpromManager::ResetExistingList%1073460970.body preserve=yes
	switch (p_eSection)
	{
	case ePISectionIdent:
		{
			for (POSITION l_Pos1 = m_IdentExistingList.GetHeadPosition(); l_Pos1 != NULL;)
			{
				CPIPersistentItem *l_pItem = m_IdentExistingList.GetNext(l_Pos1);        
				ASSERT(l_pItem != NULL);
				l_pItem->ReleaseRef();
				l_pItem = NULL;
			}
			m_IdentExistingList.RemoveAll();
		}
		break;

	case ePISectionPara:
		{
			for (POSITION l_Pos2 = m_ParaExistingList.GetHeadPosition(); l_Pos2 != NULL;)
			{
				CPIPersistentItem *l_pItem = m_ParaExistingList.GetNext(l_Pos2);     
				ASSERT(l_pItem != NULL);
				l_pItem->ReleaseRef();
				l_pItem = NULL;
			}
			m_ParaExistingList.RemoveAll();
		}
		break;

	case ePISectionLifeTimeCounter:
		{
			for (POSITION l_Pos3 = m_LifeTimeExistingList.GetHeadPosition(); l_Pos3 != NULL;)
			{
				CPIPersistentItem *l_pItem = m_LifeTimeExistingList.GetNext(l_Pos3);        
				ASSERT(l_pItem != NULL);
				l_pItem->ReleaseRef();
				l_pItem = NULL;
			}
			m_LifeTimeExistingList.RemoveAll();
		}
		break;

	default:
		ASSERT(false);
	}
  //## end CPOEpromManager::ResetExistingList%1073460970.body
}

void CPOEpromManager::WriteAll ()
{
  //## begin CPOEpromManager::WriteAll%1073556131.body preserve=yes
	GetEpromHalf();
	Write(ePISectionHeader);
	Write(ePISectionIdent);
	Write(ePISectionPara);
	Write(ePISectionLifeTimeCounter);
	SetEpromHalf();
  //## end CPOEpromManager::WriteAll%1073556131.body
}

void CPOEpromManager::SaveLifeTime ()
{
  //## begin CPOEpromManager::SaveLifeTime%1073565438.body preserve=yes
    // CO_TRACE(PO_ID, _T("begin SaveLifeTime"));

	CPIPersistentItem *l_pItem = NULL;
	CPOLifeTimeCounter *l_pCounterDelta = NULL, *l_pCounterValue = NULL, *l_pDummy = NULL;
	UINT l_uiDeltaValue = 0;
    
	ReadAll();

	POSITION l_Pos = m_UpdateLifeTimeCounterList.GetHeadPosition();
    while (l_Pos != NULL)
	{
		l_pItem = m_UpdateLifeTimeCounterList.GetNext(l_Pos);
		l_pCounterDelta = dynamic_cast<CPOLifeTimeCounter*>(l_pItem);
		ASSERT(l_pCounterDelta != NULL);

		l_pCounterValue = FindLifeTime(l_pCounterDelta, eExisting); // returns NULL if not found
		if (l_pCounterValue != NULL)
		{
            // Counter exist. Add delta value.
			l_uiDeltaValue = l_pCounterDelta->GetuiDeltaValue();
			l_pCounterValue->IncCounterValue(l_uiDeltaValue);
			
			l_pDummy = FindLifeTime(l_pCounterValue, eNew);
			if (l_pDummy == NULL)
			{
				// counter not in new list.
				m_LifeTimeNewList.AddTail(l_pCounterValue);
				l_pCounterValue->AddRef();
			}

		}
		else
		{
			// Counter doesnt exist. Add counter to list.
			l_uiDeltaValue = l_pCounterDelta->GetuiDeltaValue();
			l_pCounterDelta->IncCounterValue(l_uiDeltaValue);

			l_pDummy = FindLifeTime(l_pCounterDelta, eNew);
			if (l_pDummy == NULL)
			{
				// counter not in new list.
				m_LifeTimeNewList.AddTail(l_pCounterDelta);
				l_pCounterDelta->AddRef();
			}
		}
	}

	ResetUpdatedLifeTimeList(); 
	Merge();
	ResetNewLists();
	EpromCapacity();
	WriteAll();
	ResetExistingList(ePISectionIdent);
	ResetExistingList(ePISectionPara);
	ResetExistingList(ePISectionLifeTimeCounter);

	ResetMergedList(ePISectionIdent);
	ResetMergedList(ePISectionPara);
	ResetMergedList(ePISectionLifeTimeCounter);
    // CO_TRACE(PO_ID, _T("end SaveLifeTime"));

  //## end CPOEpromManager::SaveLifeTime%1073565438.body
}

void CPOEpromManager::ResetUpdatedLifeTimeList ()
{
  //## begin CPOEpromManager::ResetUpdatedLifeTimeList%1073631917.body preserve=yes
	for (POSITION l_Pos3 = m_UpdateLifeTimeCounterList.GetHeadPosition(); l_Pos3 != NULL;)
	{
		CPIPersistentItem *l_pItem = m_UpdateLifeTimeCounterList.GetNext(l_Pos3);        
		ASSERT(l_pItem != NULL);
		l_pItem->ReleaseRef();
		l_pItem = NULL;
	}
	m_UpdateLifeTimeCounterList.RemoveAll();
  //## end CPOEpromManager::ResetUpdatedLifeTimeList%1073631917.body
}

void CPOEpromManager::RemovePara (CPIPersistentPara* p_pWanted)
{
  //## begin CPOEpromManager::RemovePara%1074183149.body preserve=yes
	POSITION l_Pos1, l_Pos2;
	CPIPersistentPara *l_pFound = NULL;
	CPIPersistentItem *l_pItem = NULL;
	CString l_sWanted, l_sFound;
	
	for(l_Pos1 = m_ParaNewList.GetHeadPosition(); (l_Pos2 = l_Pos1) != NULL;)
	{
		l_pItem = m_ParaNewList.GetNext(l_Pos1);
		l_pFound = dynamic_cast<CPIPersistentPara*>(l_pItem);
		ASSERT(l_pFound != NULL);
		l_sFound = l_pFound->GetsParaName();
		l_sWanted = p_pWanted->GetsParaName();

		if (l_sWanted == l_sFound)
		{            
           l_pItem = m_ParaNewList.GetAt(l_Pos2); // Save the old pointer for deletion.
           m_ParaNewList.RemoveAt(l_Pos2);
           l_pItem->ReleaseRef(); // Avoids memory leak.
       }
   }
  //## end CPOEpromManager::RemovePara%1074183149.body
}

void CPOEpromManager::RemoveIdent (CPIPersistentIdent* p_pWanted)
{
  //## begin CPOEpromManager::RemoveIdent%1074183150.body preserve=yes
	POSITION l_Pos1, l_Pos2;
	CPIPersistentIdent *l_pFound = NULL;
	CPIPersistentItem *l_pItem = NULL;
	CString l_sWanted, l_sFound;
	
	for(l_Pos1 = m_IdentNewList.GetHeadPosition(); (l_Pos2 = l_Pos1) != NULL;)
	{
		l_pItem = m_IdentNewList.GetNext(l_Pos1);
		l_pFound = dynamic_cast<CPIPersistentIdent*>(l_pItem);
		ASSERT(l_pFound != NULL);
		l_sFound = l_pFound->GetsArticleNo();
		l_sWanted = p_pWanted->GetsArticleNo();

		if (l_sWanted == l_sFound)
		{            
           l_pItem = m_IdentNewList.GetAt(l_Pos2); // Save the old pointer for deletion.
           m_IdentNewList.RemoveAt(l_Pos2);
           l_pItem->ReleaseRef(); // Avoids memory leak.
       }
   }
  //## end CPOEpromManager::RemoveIdent%1074183150.body
}

void CPOEpromManager::RemoveLifeTime (CPOLifeTimeCounter* p_pWanted)
{
  //## begin CPOEpromManager::RemoveLifeTime%1074183151.body preserve=yes
	POSITION l_Pos1, l_Pos2;
	CPOLifeTimeCounter *l_pFound = NULL;
	CPIPersistentItem *l_pItem = NULL;
	EPILifeTimeCounter l_eWanted, l_eFound;
	
	for(l_Pos1 = m_LifeTimeNewList.GetHeadPosition(); (l_Pos2 = l_Pos1) != NULL;)
	{
		l_pItem = m_LifeTimeNewList.GetNext(l_Pos1);
		l_pFound = dynamic_cast<CPOLifeTimeCounter*>(l_pItem);
		ASSERT(l_pFound != NULL);
		l_eFound = l_pFound->GeteDevice();
		l_eWanted = p_pWanted->GeteDevice();

		if (l_eWanted == l_eFound)
		{            
           l_pItem = m_LifeTimeNewList.GetAt(l_Pos2); // Save the old pointer for deletion.
           m_LifeTimeNewList.RemoveAt(l_Pos2);
           l_pItem->ReleaseRef(); // Avoids memory leak.
       }
   }
  //## end CPOEpromManager::RemoveLifeTime%1074183151.body
}

bool CPOEpromManager::ParseHeader (LPCTSTR p_sHeader)
{
  //## begin CPOEpromManager::ParseHeader%1074239267.body preserve=yes
	CStringList l_List;
	POSITION l_Pos;
	CString l_sResToken;

	// split herader string into words
	CPIPersistentItem::Split(p_sHeader, _T(",;="), l_List);

	// Check header
	if (l_List.Find(HEADER_VER) && l_List.Find(ID_LEN) && l_List.Find(PARA_LEN) && l_List.Find(LTC_LEN))
	{
		// Version ////////////////////////////////////////////////////////////////////
		l_Pos = l_List.Find(HEADER_VER);
		l_List.GetNext(l_Pos);
		l_sResToken = l_List.GetAt(l_Pos);
		m_iHeaderVersion = _wtoi(l_sResToken);

		if (m_iHeaderVersion > HEADER_VERSION)
		{
			// Exception.
			CString l_sTrace;
			l_sTrace.Format(_T("Exception in file: %s line: %d. Wrong header version."),_T(__FILE__), __LINE__);
			// CO_TRACE(PO_ID, l_sTrace);
			throw new XPOExceptionHeader(PO_ID, IDE_HEADER_VERSION, _T(__FILE__), __LINE__, 0);
		}
		//////////////////////////////////////////////////////////////////////////////

		// Indent len  ///////////////////////////////////////////////////////////////
		l_Pos = l_List.Find(ID_LEN);
		l_List.GetNext(l_Pos);
		l_sResToken = l_List.GetAt(l_Pos);

		if (_wtoi(l_sResToken) >= 0)
		{
			m_iIdentLength = _wtoi(l_sResToken);
		}
		else
		{
			// Exception.
			CString l_sTrace;
			l_sTrace.Format(_T("Exception in file: %s line: %d. Header length not ok."),_T(__FILE__), __LINE__);
			// CO_TRACE(PO_ID, l_sTrace);
			throw new XPOExceptionHeader(PO_ID, IDE_HEADER_IDENT_LENGTH, _T(__FILE__), __LINE__, 0);
		}
		//////////////////////////////////////////////////////////////////////////////

		// Para len //////////////////////////////////////////////////////////////////

		l_Pos = l_List.Find(PARA_LEN);
		l_List.GetNext(l_Pos);
		l_sResToken = l_List.GetAt(l_Pos);

		if (_wtoi(l_sResToken) >= 0)
		{
			m_iParaLegth = _wtoi(l_sResToken);
		}
		else
		{
			// Exception.
			CString l_sTrace;
			l_sTrace.Format(_T("Exception in file: %s line: %d. Para length not correct."),_T(__FILE__), __LINE__);
			// CO_TRACE(PO_ID, l_sTrace);
			throw new XPOExceptionHeader(PO_ID, IDE_HEADER_PARA_LENGTH, _T(__FILE__), __LINE__, 0);
		}
		//////////////////////////////////////////////////////////////////////////////

		// Life time len /////////////////////////////////////////////////////////////
		l_Pos = l_List.Find(LTC_LEN);
		l_List.GetNext(l_Pos);
		l_sResToken = l_List.GetAt(l_Pos);

		if (_wtoi(l_sResToken) >= 0)
		{
			m_iLifeTimeLegth = _wtoi(l_sResToken);
		}
		else
		{
			// Exception.
			CString l_sTrace;
			l_sTrace.Format(_T("Exception in file: %s line: %d. Life time length not correct.\n"),_T(__FILE__), __LINE__);
			// CO_TRACE(PO_ID, l_sTrace);
			throw new XPOExceptionHeader(PO_ID, IDE_HEADER_LIFETIME_LENGTH, _T(__FILE__), __LINE__, 0);
		}
		//////////////////////////////////////////////////////////////////////////////

		return true;
	}
	else
	{
		return false;
	}
  //## end CPOEpromManager::ParseHeader%1074239267.body
}

CString CPOEpromManager::ReadHeader (bool p_bWithLength)
{
  //## begin CPOEpromManager::ReadHeader%1074505551.body preserve=yes
	CPISyncObjI2CDataStream *l_pSyncObj = NULL;
	CPII2CDataStream *l_pData = NULL;
	CString l_sHeader;

	try
	{
		int l_iSize = CalcNoOfPages(GetHeaderLength());
		l_iSize *= m_iPageSize;

		// determine eprom half
		int l_iStartAdr = (m_iEpromSizeInByte / 2) * m_iActiveEpromHalf;

		// Read header content.
		l_pSyncObj = m_pEprom->BlockRead((WORD)l_iStartAdr, l_iSize);
		l_pSyncObj->Synchronize(TIME_OUT);
		l_pData = l_pSyncObj->GetValue();
		l_pSyncObj->ReleaseRef();
		l_pSyncObj = NULL;

		if (l_pData->GetnSize() != l_iSize)
		{
			// Exception wrong data size.
			CString l_sTrace;
			l_sTrace.Format(_T("Exception in file: %s line: %d. Wrong data size returned form eprom."),_T(__FILE__), __LINE__);
			// CO_TRACE(PO_ID, l_sTrace);
			throw new XPOExceptionHeader(PO_ID, IDE_WRONG_DATASIZE, _T(__FILE__), __LINE__, 0);
		}

		// We don't need the first 6 chars (12 bytes). Start copy at the 6th char. 			
		if (p_bWithLength)
		{
			l_sHeader = (LPCTSTR)l_pData->GetpcI2CDataStream();
		}
		else
		{
			l_sHeader = (LPCTSTR) &l_pData->GetpcI2CDataStream()[HEADER_LEN * BYTES_PER_CHAR];
		}    

		// house keeping
		if (l_pData != NULL)
			l_pData->ReleaseRef();
		l_pData = NULL;

		// CO_TRACE(PO_ID, "end ReadHeader");
		return l_sHeader;
	}
	catch(...)
	{
		if (l_pSyncObj != NULL)
			l_pSyncObj->ReleaseRef();
		if (l_pData != NULL)
			l_pData->ReleaseRef();

		throw;
	}

  //## end CPOEpromManager::ReadHeader%1074505551.body
}

void CPOEpromManager::ResetExistingLists ()
{
  //## begin CPOEpromManager::ResetExistingLists%1107176860.body preserve=yes
  //## end CPOEpromManager::ResetExistingLists%1107176860.body
}

void CPOEpromManager::GetEpromHalf ()
{
  //## begin CPOEpromManager::GetEpromHalf%1107176861.body preserve=yes

	CCOSyncObjectInt* l_pSyncObj = NULL;
	try
	{
		l_pSyncObj = m_pEprom->ByteRead(m_iEpromSizeInByte-1);
		l_pSyncObj->Synchronize(TIME_OUT);
		m_iActiveEpromHalf = (INT)l_pSyncObj->GetValue(); // 0 = first half /1 = second half
		l_pSyncObj->ReleaseRef();
		l_pSyncObj = NULL;

		if (m_iActiveEpromHalf > 1)
			m_iActiveEpromHalf = 0;
	}
	catch(...)
	{
		if (l_pSyncObj != NULL)
			l_pSyncObj->ReleaseRef();
		l_pSyncObj = NULL;

		throw;
	}

  //## end CPOEpromManager::GetEpromHalf%1107176861.body
}

void CPOEpromManager::SetEpromHalf ()
{
  //## begin CPOEpromManager::SetEpromHalf%1107176862.body preserve=yes
    // set value
	if (m_iActiveEpromHalf > 0)
		m_iActiveEpromHalf = 0;

	else 
		m_iActiveEpromHalf = 1;

	// write acive eprom half information to last bype of eprom
	CCOSyncObjectPtr l_SyncObj = m_pEprom->ByteWrite(m_iEpromSizeInByte-1, (BYTE)m_iActiveEpromHalf);
	l_SyncObj->Synchronize(TIME_OUT);
  //## end CPOEpromManager::SetEpromHalf%1107176862.body
}

void CPOEpromManager::UpgradeEpromVersion ()
{
  //## begin CPOEpromManager::UpgradeEpromVersion%1107246382.body preserve=yes
	CString l_sHeader, l_sVersion;

	// read header
    l_sHeader = ReadHeader(true);
	int l_iVersionPos = l_sHeader.Find(HEADER_VER);

	if (l_iVersionPos > -1)
	{
		l_iVersionPos += HEADER_VER.GetLength() + 1;

		l_sVersion = l_sHeader.Mid(l_iVersionPos,1);
		LPCTSTR l_pBuffer = (LPCTSTR)l_sVersion;
		wchar_t* l_pVersion = (wchar_t*)l_pBuffer;
		int l_iHeaderVersion = _wtoi(l_pVersion);
		ASSERT(l_iHeaderVersion != 0);

		switch (l_iHeaderVersion)
		{
		case -1:
			break;

		case 1:
			{
				// change header version
				l_sVersion = _T("");
				l_sVersion.Format(_T("%d"), HEADER_VERSION);
				l_sHeader.SetAt(l_iVersionPos, l_sVersion.GetAt(0));

                // write header
				WritePageBlocks(0, l_sHeader);

				// reset last eprom bit
				CCOSyncObjectPtr l_pSyncObj = m_pEprom->ByteWrite(m_iEpromSizeInByte-1, 0);
				l_pSyncObj->Synchronize(TIME_OUT);
			}
			break;

		case 2:
			// do nothing
			break;

		default:
			ASSERT(false);
		}
	}
	else
	{
		m_iActiveEpromHalf = 1;
		Write(ePISectionHeader);
		SetEpromHalf();
	}


  //## end CPOEpromManager::UpgradeEpromVersion%1107246382.body
}

void CPOEpromManager::ResetHeader ()
{
  //## begin CPOEpromManager::ResetHeader%1108565315.body preserve=yes
	
	CCOSyncObject *l_pSyncObj = NULL;
	int l_iNop = m_iEpromSizeInByte / m_iPageSize;

	// Memory for the unicode char buffer.
	BYTE *l_pByteBuf = new BYTE[m_iEpromSizeInByte];
 	ZeroMemory(l_pByteBuf, m_iEpromSizeInByte);

	try
	{
		int l_iPageAdr = 0;
		for (int l_it = 0; l_it < l_iNop; l_it++)
		{
			l_iPageAdr = l_it * m_iPageSize;
			l_pSyncObj = m_pEprom->PageWrite(l_iPageAdr, &l_pByteBuf[l_iPageAdr], m_iPageSize); 
			l_pSyncObj->Synchronize(TIME_OUT);

			if (l_pSyncObj != NULL)
				l_pSyncObj->ReleaseRef();
			l_pSyncObj = NULL;
   		}
		if (l_pByteBuf != NULL)
			delete [] l_pByteBuf;
		l_pByteBuf = NULL;
	}
	catch(...)
	{
   		if (l_pByteBuf != NULL)
			delete [] l_pByteBuf;
		l_pByteBuf = NULL;

		if (l_pSyncObj != NULL)
			l_pSyncObj->ReleaseRef();
		l_pSyncObj = NULL;

        throw;
	}
  //## end CPOEpromManager::ResetHeader%1108565315.body
}

//## Get and Set Operations for Associations (implementation)

CTypedPtrList<CPtrList, CPIPersistentItem*>& CPOEpromManager::GetParaExistingList ()
{
  //## begin CPOEpromManager::GetParaExistingList%3FAF3F6E01E4.get preserve=no
  return m_ParaExistingList;
  //## end CPOEpromManager::GetParaExistingList%3FAF3F6E01E4.get
}

CTypedPtrList<CPtrList, CPIPersistentItem*>& CPOEpromManager::GetLifeTimeExistingList ()
{
  //## begin CPOEpromManager::GetLifeTimeExistingList%3FAF405501D5.get preserve=no
  return m_LifeTimeExistingList;
  //## end CPOEpromManager::GetLifeTimeExistingList%3FAF405501D5.get
}

CTypedPtrList<CPtrList, CPIPersistentItem*>& CPOEpromManager::GetIdentExistingList ()
{
  //## begin CPOEpromManager::GetIdentExistingList%3FAF405C006E.get preserve=no
  return m_IdentExistingList;
  //## end CPOEpromManager::GetIdentExistingList%3FAF405C006E.get
}

bool CPOEpromManager::GetbHeaderInfoUpToDate ()
{
  //## begin CPOEpromManager::GetbHeaderInfoUpToDate%400BA6900026.get preserve=no
  return m_bHeaderInfoUpToDate;
  //## end CPOEpromManager::GetbHeaderInfoUpToDate%400BA6900026.get
}

void CPOEpromManager::SetbHeaderInfoUpToDate (bool value)
{
  //## begin CPOEpromManager::SetbHeaderInfoUpToDate%400BA6900026.set preserve=no
  m_bHeaderInfoUpToDate = value;
  //## end CPOEpromManager::SetbHeaderInfoUpToDate%400BA6900026.set
}

INT CPOEpromManager::GetiIdentLength ()
{
  //## begin CPOEpromManager::GetiIdentLength%400BA6CD03DF.get preserve=no
  return m_iIdentLength;
  //## end CPOEpromManager::GetiIdentLength%400BA6CD03DF.get
}

// Additional Declarations
  //## begin CPOEpromManager%3FA119170177.declarations preserve=yes
  //## end CPOEpromManager%3FA119170177.declarations

//## begin module%3FA118390232.epilog preserve=yes
//## end module%3FA118390232.epilog
