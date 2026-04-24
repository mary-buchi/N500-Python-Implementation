//## begin module%3E6E06AE0280.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E6E06AE0280.cm

//## begin module%3E6E06AE0280.cp preserve=no
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
//## end module%3E6E06AE0280.cp

//## Module: EBMCacti%3E6E06AE0280; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCacti.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E6E06AE0280.additionalIncludes preserve=no
//## end module%3E6E06AE0280.additionalIncludes

//## begin module%3E6E06AE0280.includes preserve=yes
//## end module%3E6E06AE0280.includes

// EBMCidnt
#include "EBMCidnt.h"
// EBMCacti
#include "EBMCacti.h"
// EBHIexcp
#include "EBHIexcp.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3E6E06AE0280.declarations preserve=no
//## end module%3E6E06AE0280.declarations

//## begin module%3E6E06AE0280.additionalDeclarations preserve=yes
//## end module%3E6E06AE0280.additionalDeclarations


// Class CMCActionGetDataPackage 

CMCActionGetDataPackage::CMCActionGetDataPackage (const UINT p_uiID, ICOStateMachineContext* p_pContext)
  //## begin CMCActionGetDataPackage::CMCActionGetDataPackage%1047390945.hasinit preserve=no
  //## end CMCActionGetDataPackage::CMCActionGetDataPackage%1047390945.hasinit
  //## begin CMCActionGetDataPackage::CMCActionGetDataPackage%1047390945.initialization preserve=yes
  :CCOAction(p_uiID, p_pContext)
  //## end CMCActionGetDataPackage::CMCActionGetDataPackage%1047390945.initialization
{
  //## begin CMCActionGetDataPackage::CMCActionGetDataPackage%1047390945.body preserve=yes
  //## end CMCActionGetDataPackage::CMCActionGetDataPackage%1047390945.body
}


CMCActionGetDataPackage::~CMCActionGetDataPackage()
{
  //## begin CMCActionGetDataPackage::~CMCActionGetDataPackage%.body preserve=yes
  //## end CMCActionGetDataPackage::~CMCActionGetDataPackage%.body
}



//## Other Operations (implementation)
void CMCActionGetDataPackage::Done ()
{
  //## begin CMCActionGetDataPackage::Done%1047390947.body preserve=yes
    CO_TRACE(MC_ID, _T("CMCActionGetDataPackage::Done() - Begin"));
    if (m_pClientSyncObj && m_pServerSyncObj)
    {
      CPISyncObjDataPackage* l_pClientSyncObj = dynamic_cast<CPISyncObjDataPackage*>(m_pClientSyncObj);
      CPISyncObjDataPackage* l_pServerSyncObj = dynamic_cast<CPISyncObjDataPackage*>(m_pServerSyncObj);

      l_pClientSyncObj->SetValue(l_pServerSyncObj->GetValue());
    }

    CCOAction::Done();

    CO_TRACE(MC_ID, _T("CMCActionGetDataPackage::Done() - End"));
  //## end CMCActionGetDataPackage::Done%1047390947.body
}

CCOSyncObject* CMCActionGetDataPackage::ExecuteAction ()
{
  //## begin CMCActionGetDataPackage::ExecuteAction%1047390946.body preserve=yes
//  try
//  {
    CO_TRACE(MC_ID, _T("CMCActionGetDataPackage::ExecuteAction - Begin"));
    CPISyncObjDataPackage* l_pSyncObj = IHIInterface::GetInstance()->MCGetDataPackage();
    CO_TRACE(MC_ID, _T("CMCActionGetDataPackage::ExecuteAction - End"));
    return l_pSyncObj;
/*  }
  catch(XHIExceptionError* p_pException)
  {
    CPISyncObjDataPackage* l_pSyncObj = new CPISyncObjDataPackage(NULL);
    l_pSyncObj->AttachException(p_pException);

    return l_pSyncObj;
  } */
  //## end CMCActionGetDataPackage::ExecuteAction%1047390946.body
}

// Additional Declarations
  //## begin CMCActionGetDataPackage%3E6E068801F4.declarations preserve=yes
  //## end CMCActionGetDataPackage%3E6E068801F4.declarations

//## begin module%3E6E06AE0280.epilog preserve=yes
//## end module%3E6E06AE0280.epilog
