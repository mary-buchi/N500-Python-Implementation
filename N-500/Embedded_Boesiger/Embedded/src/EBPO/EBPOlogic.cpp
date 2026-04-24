//## begin module%3F9D14CF023E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F9D14CF023E.cm

//## begin module%3F9D14CF023E.cp preserve=no
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
//## end module%3F9D14CF023E.cp

//## Module: EBPOlogic%3F9D14CF023E; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOlogic.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F9D14CF023E.additionalIncludes preserve=no
//## end module%3F9D14CF023E.additionalIncludes

//## begin module%3F9D14CF023E.includes preserve=yes
//## end module%3F9D14CF023E.includes

// EBPItype
#include "EBPItype.h"
// EBPOeprom
#include "EBPOeprom.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
// EBPOimpl
#include "EBPOimpl.h"


//## begin module%3F9D14CF023E.declarations preserve=no
//## end module%3F9D14CF023E.declarations

//## begin module%3F9D14CF023E.additionalDeclarations preserve=yes
//## end module%3F9D14CF023E.additionalDeclarations


// Class CPOLogic 




CPOLogic::CPOLogic (CPOPersistentObjImplementation* p_pImpl)
  //## begin CPOLogic::CPOLogic%1067262117.hasinit preserve=no
      : m_pImpl(p_pImpl), m_pEprom(NULL)
  //## end CPOLogic::CPOLogic%1067262117.hasinit
  //## begin CPOLogic::CPOLogic%1067262117.initialization preserve=yes
  //## end CPOLogic::CPOLogic%1067262117.initialization
{
  //## begin CPOLogic::CPOLogic%1067262117.body preserve=yes
  //## end CPOLogic::CPOLogic%1067262117.body
}


CPOLogic::~CPOLogic()
{
  //## begin CPOLogic::~CPOLogic%.body preserve=yes
	if (m_pEprom != NULL)
		delete m_pEprom;
	m_pEprom = NULL;
  //## end CPOLogic::~CPOLogic%.body
}



//## Other Operations (implementation)
void CPOLogic::WriteParameter (CPIPersistentPara* p_pPara)
{
  //## begin CPOLogic::WriteParameter%1068021101.body preserve=yes
	m_pEprom->WriteParameter(p_pPara);
  //## end CPOLogic::WriteParameter%1068021101.body
}

void CPOLogic::WriteLifeTimeCounter (const EPILifeTimeCounter p_eDevice, const UINT p_uiValue)
{
  //## begin CPOLogic::WriteLifeTimeCounter%1068021103.body preserve=yes
	CPOLifeTimeCounter *l_pCounter = new CPOLifeTimeCounter(p_eDevice, p_uiValue);
	m_pEprom->WriteLifeTimeCounter(l_pCounter);
	l_pCounter->ReleaseRef();
  //## end CPOLogic::WriteLifeTimeCounter%1068021103.body
}

void CPOLogic::UpdateLifeTimeCounter (CPOLifeTimeCounter *p_pCounter)
{
  //## begin CPOLogic::UpdateLifeTimeCounter%1068021104.body preserve=yes
	m_pEprom->UpdateLifeTimeCounter( p_pCounter );
  //## end CPOLogic::UpdateLifeTimeCounter%1068021104.body
}

void CPOLogic::WriteIdent (CPIPersistentIdent* p_pIdent)
{
  //## begin CPOLogic::WriteIdent%1068448311.body preserve=yes
	m_pEprom->WriteIdentification(p_pIdent);
  //## end CPOLogic::WriteIdent%1068448311.body
}

void CPOLogic::Save ()
{
  //## begin CPOLogic::Save%1068458451.body preserve=yes
	m_pEprom->Save();
  //## end CPOLogic::Save%1068458451.body
}

void CPOLogic::Reset (EPIEpromSection p_eSection)
{
  //## begin CPOLogic::Reset%1073378942.body preserve=yes
	m_pEprom->Reset(p_eSection);
  //## end CPOLogic::Reset%1073378942.body
}

void CPOLogic::ReadIdentifications (CTypedPtrList<CPtrList, CPIPersistentItem*> &p_List)
{
  //## begin CPOLogic::ReadIdentifications%1073292443.body preserve=yes
	m_pEprom->ReadSection(ePISectionIdent);
	CTypedPtrList<CPtrList, CPIPersistentItem*> &l_EpromList1 = m_pEprom->GetIdentExistingList();

	for( POSITION l_Pos1 = l_EpromList1.GetHeadPosition(); l_Pos1 != NULL; )
	{
		CPIPersistentItem *l_pItem = l_EpromList1.GetNext( l_Pos1 );
		ASSERT( l_pItem != NULL );

		p_List.AddTail(l_pItem);
		l_pItem->AddRef();
	}
  //## end CPOLogic::ReadIdentifications%1073292443.body
}

void CPOLogic::ReadParameter (CTypedPtrList<CPtrList, CPIPersistentItem*> &p_List)
{
  //## begin CPOLogic::ReadParameter%1073460971.body preserve=yes
	m_pEprom->ReadSection( ePISectionPara );
	CTypedPtrList<CPtrList, CPIPersistentItem*> &l_EpromList1 = m_pEprom->GetParaExistingList();
	for( POSITION l_Pos1 = l_EpromList1.GetHeadPosition(); l_Pos1 != NULL; )
	{
		CPIPersistentItem *l_pItem = l_EpromList1.GetNext( l_Pos1 );
		ASSERT( l_pItem != NULL );
		p_List.AddTail(l_pItem);
		l_pItem->AddRef();
	}
  //## end CPOLogic::ReadParameter%1073460971.body
}

int CPOLogic::ReadLifeTimeCounter (EPILifeTimeCounter p_eDevice)
{
  //## begin CPOLogic::ReadLifeTimeCounter%1073460972.body preserve=yes

	// create a dummy counter to get the counters location. see couter construction.
	CPOLifeTimeCounter *l_pDummyCounter = new CPOLifeTimeCounter(p_eDevice, 0);
	EPILifeTimeCounter l_eDevice = l_pDummyCounter->GeteDevice();

	if( l_pDummyCounter != NULL )
		l_pDummyCounter->ReleaseRef();
	l_pDummyCounter = NULL;

	int l_iCounterValue = 0;
	bool l_bCounterFound = false;
	POSITION l_Pos = NULL; 
	CPIPersistentItem *l_pItem = NULL;
	CPOLifeTimeCounter *l_pCounter = NULL;

	m_pEprom->ReadSection( ePISectionLifeTimeCounter );
	for(l_Pos = m_pEprom->GetLifeTimeExistingList().GetHeadPosition(); l_Pos != NULL;)
	{
		l_pItem = m_pEprom->GetLifeTimeExistingList().GetNext( l_Pos );
		CPOLifeTimeCounter *l_pCounter = dynamic_cast<CPOLifeTimeCounter*>( l_pItem );
		ASSERT( l_pCounter != NULL);
		l_eDevice = l_pCounter->GeteDevice();

		if( l_eDevice == p_eDevice )
		{
			return l_pCounter->GetuiValue();
		}
	}
	return 0;
  //## end CPOLogic::ReadLifeTimeCounter%1073460972.body
}

void CPOLogic::SaveLifeTime ()
{
  //## begin CPOLogic::SaveLifeTime%1073631916.body preserve=yes
	m_pEprom->SaveLifeTime();
  //## end CPOLogic::SaveLifeTime%1073631916.body
}

void CPOLogic::SetConfig ()
{
  //## begin CPOLogic::SetConfig%1079509389.body preserve=yes
	UINT l_uiEpromID = m_pImpl->GetuiID();
	
	if (m_pEprom != NULL)
	{
		delete m_pEprom;
		m_pEprom = NULL;
	}

    m_pEprom = new CPOEpromManager(l_uiEpromID, m_pImpl);
  //## end CPOLogic::SetConfig%1079509389.body
}

void CPOLogic::MCUndock ()
{
  //## begin CPOLogic::MCUndock%1107449341.body preserve=yes
	// Delete old life timecounter from old measurement cell.
	m_pImpl->StopTimer();
	m_pImpl->GetpLifeTimeCounterHandler()->DeleteCounterList();

	// Delete parameter list.
	m_pEprom->ResetNewLists();
	m_pEprom->ResetUpdatedLifeTimeList();
	m_pEprom->SetbHeaderInfoUpToDate(false);
  //## end CPOLogic::MCUndock%1107449341.body
}

//## Get and Set Operations for Associations (implementation)

CPOEpromManager * CPOLogic::GetpEprom ()
{
  //## begin CPOLogic::GetpEprom%3FA8B4A0012D.get preserve=no
  return m_pEprom;
  //## end CPOLogic::GetpEprom%3FA8B4A0012D.get
}

// Additional Declarations
  //## begin CPOLogic%3F9D1517006A.declarations preserve=yes
  //## end CPOLogic%3F9D1517006A.declarations

//## begin module%3F9D14CF023E.epilog preserve=yes
//## end module%3F9D14CF023E.epilog
