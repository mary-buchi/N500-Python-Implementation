//## begin module%4023AA7402BE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%4023AA7402BE.cm

//## begin module%4023AA7402BE.cp preserve=no
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
//## end module%4023AA7402BE.cp

//## Module: EBPItias%4023AA7402BE; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPItias.cpp

// stdafx
#include "stdafx.h"
//## begin module%4023AA7402BE.additionalIncludes preserve=no
//## end module%4023AA7402BE.additionalIncludes

//## begin module%4023AA7402BE.includes preserve=yes
//## end module%4023AA7402BE.includes

// EBPItias
#include "EBPItias.h"


//## begin module%4023AA7402BE.declarations preserve=no
//## end module%4023AA7402BE.declarations

//## begin module%4023AA7402BE.additionalDeclarations preserve=yes
//## end module%4023AA7402BE.additionalDeclarations


// Class CPITicksAtStart 

//## begin CPITicksAtStart::dwTicksAtStartUp%40223D5100D3.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CPITicksAtStart::m_dwTicksAtStartUp = 0;
//## end CPITicksAtStart::dwTicksAtStartUp%40223D5100D3.role

//## begin CPITicksAtStart::eLamp%40238F7B0222.role preserve=no  public: static EPILamp {1..1 -> 1..1VHN}
EPILamp CPITicksAtStart::m_eLamp = ePrimaryLamp;
//## end CPITicksAtStart::eLamp%40238F7B0222.role

CPITicksAtStart::CPITicksAtStart()
  //## begin CPITicksAtStart::CPITicksAtStart%.hasinit preserve=no
  //## end CPITicksAtStart::CPITicksAtStart%.hasinit
  //## begin CPITicksAtStart::CPITicksAtStart%.initialization preserve=yes
  //## end CPITicksAtStart::CPITicksAtStart%.initialization
{
  //## begin CPITicksAtStart::CPITicksAtStart%.body preserve=yes
  //## end CPITicksAtStart::CPITicksAtStart%.body
}


CPITicksAtStart::~CPITicksAtStart()
{
  //## begin CPITicksAtStart::~CPITicksAtStart%.body preserve=yes
  //## end CPITicksAtStart::~CPITicksAtStart%.body
}


// Additional Declarations
  //## begin CPITicksAtStart%4022387001AD.declarations preserve=yes
  //## end CPITicksAtStart%4022387001AD.declarations

//## begin module%4023AA7402BE.epilog preserve=yes
//## end module%4023AA7402BE.epilog
