//## begin module%3DAAE3CB0294.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE3CB0294.cm

//## begin module%3DAAE3CB0294.cp preserve=no
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
//## end module%3DAAE3CB0294.cp

//## Module: EBMCimpl%3DAAE3CB0294; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAE3CB0294.additionalIncludes preserve=no
//## end module%3DAAE3CB0294.additionalIncludes

//## begin module%3DAAE3CB0294.includes preserve=yes
//## end module%3DAAE3CB0294.includes

// EBPIcpst
#include "EBPIcpst.h"
// EBMCsten
#include "EBMCsten.h"
// EBMCimpl
#include "EBMCimpl.h"
// EBMCintf
#include "EBMCintf.h"
// EBMCidnt
#include "EBMCidnt.h"
// EBMCsimu
#include "EBMCsimu.h"


//## begin module%3DAAE3CB0294.declarations preserve=no
//## end module%3DAAE3CB0294.declarations

//## begin module%3DAAE3CB0294.additionalDeclarations preserve=yes
//## end module%3DAAE3CB0294.additionalDeclarations


// Class CMCMeasurementChannelImplementation 



CMCMeasurementChannelImplementation::CMCMeasurementChannelImplementation (CMCMeasurementChannelInterface* p_pInterface)
  //## begin CMCMeasurementChannelImplementation::CMCMeasurementChannelImplementation%1034611448.hasinit preserve=no
      : m_bHWPresent(false), m_pCtrlSimulation(NULL)
  //## end CMCMeasurementChannelImplementation::CMCMeasurementChannelImplementation%1034611448.hasinit
  //## begin CMCMeasurementChannelImplementation::CMCMeasurementChannelImplementation%1034611448.initialization preserve=yes
  , ICOAsyncImplementation(p_pInterface)
  //## end CMCMeasurementChannelImplementation::CMCMeasurementChannelImplementation%1034611448.initialization
{
  //## begin CMCMeasurementChannelImplementation::CMCMeasurementChannelImplementation%1034611448.body preserve=yes
  //## end CMCMeasurementChannelImplementation::CMCMeasurementChannelImplementation%1034611448.body
}


CMCMeasurementChannelImplementation::~CMCMeasurementChannelImplementation()
{
  //## begin CMCMeasurementChannelImplementation::~CMCMeasurementChannelImplementation%.body preserve=yes
    delete m_pCtrlSimulation;
    m_pCtrlSimulation = NULL;
  //## end CMCMeasurementChannelImplementation::~CMCMeasurementChannelImplementation%.body
}



//## Other Operations (implementation)
void CMCMeasurementChannelImplementation::InitInstance ()
{
  //## begin CMCMeasurementChannelImplementation::InitInstance%1034611449.body preserve=yes
    m_pStateMachineEngine = new CMCStateMachineEngine(this);

    // init hw present flag
    m_bHWPresent = CPIComponentsState::GetInstance()->GetComponentState(MC_ID);
    if (!m_bHWPresent)
    {
        m_pCtrlSimulation = new CMCCtrlSimulation();
    }

    ICOAsyncImplementation::InitInstance();
  //## end CMCMeasurementChannelImplementation::InitInstance%1034611449.body
}

//## Get and Set Operations for Class Attributes (implementation)

bool CMCMeasurementChannelImplementation::GetbHWPresent ()
{
  //## begin CMCMeasurementChannelImplementation::GetbHWPresent%3F97846101F7.get preserve=no
  return m_bHWPresent;
  //## end CMCMeasurementChannelImplementation::GetbHWPresent%3F97846101F7.get
}

//## Get and Set Operations for Associations (implementation)

CMCCtrlSimulation * CMCMeasurementChannelImplementation::GetpCtrlSimulation ()
{
  //## begin CMCMeasurementChannelImplementation::GetpCtrlSimulation%3F97885303DB.get preserve=no
  return m_pCtrlSimulation;
  //## end CMCMeasurementChannelImplementation::GetpCtrlSimulation%3F97885303DB.get
}

// Additional Declarations
  //## begin CMCMeasurementChannelImplementation%3DAAE59100EE.declarations preserve=yes
  //## end CMCMeasurementChannelImplementation%3DAAE59100EE.declarations

//## begin module%3DAAE3CB0294.epilog preserve=yes
//## end module%3DAAE3CB0294.epilog
