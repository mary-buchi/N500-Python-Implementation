//## begin module%3FA117230177.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA117230177.cm

//## begin module%3FA117230177.cp preserve=no
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
//## end module%3FA117230177.cp

//## Module: EBIOstat%3FA117230177; Package body
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FA117230177.additionalIncludes preserve=no
//## end module%3FA117230177.additionalIncludes

//## begin module%3FA117230177.includes preserve=yes
//## end module%3FA117230177.includes

// EBIOstat
#include "EBIOstat.h"


//## begin module%3FA117230177.declarations preserve=no
//## end module%3FA117230177.declarations

//## begin module%3FA117230177.additionalDeclarations preserve=yes
//## end module%3FA117230177.additionalDeclarations


// Class CIODigitalState 

//## begin CIODigitalState::Map%3FA1175D0233.role preserve=no  public: static bool { -> 1VFHON}
CMap<DWORD, DWORD&, bool, bool&> CIODigitalState::m_Map;
//## end CIODigitalState::Map%3FA1175D0233.role

CIODigitalState::CIODigitalState()
  //## begin CIODigitalState::CIODigitalState%.hasinit preserve=no
  //## end CIODigitalState::CIODigitalState%.hasinit
  //## begin CIODigitalState::CIODigitalState%.initialization preserve=yes
  //## end CIODigitalState::CIODigitalState%.initialization
{
  //## begin CIODigitalState::CIODigitalState%.body preserve=yes
  //## end CIODigitalState::CIODigitalState%.body
}


CIODigitalState::~CIODigitalState()
{
  //## begin CIODigitalState::~CIODigitalState%.body preserve=yes
  //## end CIODigitalState::~CIODigitalState%.body
}



//## Other Operations (implementation)
void CIODigitalState::SetState (DWORD p_dwID, bool p_bState)
{
  //## begin CIODigitalState::SetState%1067518839.body preserve=yes
  m_Map.SetAt(p_dwID, p_bState);
  //## end CIODigitalState::SetState%1067518839.body
}

bool CIODigitalState::GetState (DWORD p_dwID)
{
  //## begin CIODigitalState::GetState%1067518840.body preserve=yes
  bool l_bState = false;

  if (!m_Map.Lookup(p_dwID, l_bState))
  {
    m_Map.SetAt(p_dwID, l_bState);
  }

  return l_bState;
  //## end CIODigitalState::GetState%1067518840.body
}

// Additional Declarations
  //## begin CIODigitalState%3FA115AC032C.declarations preserve=yes
  //## end CIODigitalState%3FA115AC032C.declarations

//## begin module%3FA117230177.epilog preserve=yes
//## end module%3FA117230177.epilog
