//## begin module%3E22997D02D8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E22997D02D8.cm

//## begin module%3E22997D02D8.cp preserve=no
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
//## end module%3E22997D02D8.cp

//## Module: EBHIcomd%3E22997D02D8; Package body
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIcomd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E22997D02D8.additionalIncludes preserve=no
//## end module%3E22997D02D8.additionalIncludes

//## begin module%3E22997D02D8.includes preserve=yes
//## end module%3E22997D02D8.includes

// EBHIcomd
#include "EBHIcomd.h"
//## begin module%3E22997D02D8.declarations preserve=no
//## end module%3E22997D02D8.declarations

//## begin module%3E22997D02D8.additionalDeclarations preserve=yes
//## end module%3E22997D02D8.additionalDeclarations


// Class CHII2CCommand 



CHII2CCommand::CHII2CCommand()
  //## begin CHII2CCommand::CHII2CCommand%.hasinit preserve=no
      : m_pSyncObj(NULL)
  //## end CHII2CCommand::CHII2CCommand%.hasinit
  //## begin CHII2CCommand::CHII2CCommand%.initialization preserve=yes
  //## end CHII2CCommand::CHII2CCommand%.initialization
{
  //## begin CHII2CCommand::CHII2CCommand%.body preserve=yes
  //## end CHII2CCommand::CHII2CCommand%.body
}


CHII2CCommand::~CHII2CCommand()
{
  //## begin CHII2CCommand::~CHII2CCommand%.body preserve=yes
  if (m_pSyncObj)
    m_pSyncObj->ReleaseRef();
  m_pSyncObj = NULL;
  //## end CHII2CCommand::~CHII2CCommand%.body
}



//## Other Operations (implementation)
void CHII2CCommand::CreateSyncObjects ()
{
  //## begin CHII2CCommand::CreateSyncObjects%1042447558.body preserve=yes
  m_pSyncObj = new CPISyncObjI2CDataStream(_T("HI:I2CCommand::CreateSyncObjects"), NULL);
  //## end CHII2CCommand::CreateSyncObjects%1042447558.body
}

//## Get and Set Operations for Associations (implementation)

CPISyncObjI2CDataStream * CHII2CCommand::GetpSyncObj ()
{
  //## begin CHII2CCommand::GetpSyncObj%3E229A1D0134.get preserve=yes
    m_pSyncObj->AddRef();
    return m_pSyncObj;
  //## end CHII2CCommand::GetpSyncObj%3E229A1D0134.get
}

// Additional Declarations
  //## begin CHII2CCommand%3E22999502B9.declarations preserve=yes
  //## end CHII2CCommand%3E22999502B9.declarations

//## begin module%3E22997D02D8.epilog preserve=yes
//## end module%3E22997D02D8.epilog
