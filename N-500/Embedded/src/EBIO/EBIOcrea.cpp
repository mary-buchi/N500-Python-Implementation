//## begin module%3DF5AF72034B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF5AF72034B.cm

//## begin module%3DF5AF72034B.cp preserve=no
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
//## end module%3DF5AF72034B.cp

//## Module: EBIOcrea%3DF5AF72034B; Package body
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DF5AF72034B.additionalIncludes preserve=no
//## end module%3DF5AF72034B.additionalIncludes

//## begin module%3DF5AF72034B.includes preserve=yes
//## end module%3DF5AF72034B.includes

// EBIOintf
#include "EBIOintf.h"
// EBIOcrea
#include "EBIOcrea.h"
//## begin module%3DF5AF72034B.declarations preserve=no
//## end module%3DF5AF72034B.declarations

//## begin module%3DF5AF72034B.additionalDeclarations preserve=yes
//## end module%3DF5AF72034B.additionalDeclarations


// Class CIOOutputAnalogCreatorV0 

CIOOutputAnalogCreatorV0::CIOOutputAnalogCreatorV0()
  //## begin CIOOutputAnalogCreatorV0::CIOOutputAnalogCreatorV0%.hasinit preserve=no
  //## end CIOOutputAnalogCreatorV0::CIOOutputAnalogCreatorV0%.hasinit
  //## begin CIOOutputAnalogCreatorV0::CIOOutputAnalogCreatorV0%.initialization preserve=yes
  :CPIObjCreatorOutputAnalog(_T(""))
  //## end CIOOutputAnalogCreatorV0::CIOOutputAnalogCreatorV0%.initialization
{
  //## begin CIOOutputAnalogCreatorV0::CIOOutputAnalogCreatorV0%.body preserve=yes
  //## end CIOOutputAnalogCreatorV0::CIOOutputAnalogCreatorV0%.body
}


CIOOutputAnalogCreatorV0::~CIOOutputAnalogCreatorV0()
{
  //## begin CIOOutputAnalogCreatorV0::~CIOOutputAnalogCreatorV0%.body preserve=yes
  //## end CIOOutputAnalogCreatorV0::~CIOOutputAnalogCreatorV0%.body
}



//## Other Operations (implementation)
IPIOutputAnalogInterface* CIOOutputAnalogCreatorV0::Create (UINT p_uiID)
{
  //## begin CIOOutputAnalogCreatorV0::Create%1039513438.body preserve=yes
	IPIOutputAnalogInterface* l_Intf = new CIOOutputAnalogInterface(p_uiID);

	return l_Intf;
  //## end CIOOutputAnalogCreatorV0::Create%1039513438.body
}

// Additional Declarations
  //## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.declarations preserve=yes
  //## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.declarations

// Class CIOSensorAnalogCreatorV0 

CIOSensorAnalogCreatorV0::CIOSensorAnalogCreatorV0()
  //## begin CIOSensorAnalogCreatorV0::CIOSensorAnalogCreatorV0%.hasinit preserve=no
  //## end CIOSensorAnalogCreatorV0::CIOSensorAnalogCreatorV0%.hasinit
  //## begin CIOSensorAnalogCreatorV0::CIOSensorAnalogCreatorV0%.initialization preserve=yes
  :CPIObjCreatorSensorAnalog(_T(""))
  //## end CIOSensorAnalogCreatorV0::CIOSensorAnalogCreatorV0%.initialization
{
  //## begin CIOSensorAnalogCreatorV0::CIOSensorAnalogCreatorV0%.body preserve=yes
  //## end CIOSensorAnalogCreatorV0::CIOSensorAnalogCreatorV0%.body
}


CIOSensorAnalogCreatorV0::~CIOSensorAnalogCreatorV0()
{
  //## begin CIOSensorAnalogCreatorV0::~CIOSensorAnalogCreatorV0%.body preserve=yes
  //## end CIOSensorAnalogCreatorV0::~CIOSensorAnalogCreatorV0%.body
}



//## Other Operations (implementation)
IPISensorAnalogInterface* CIOSensorAnalogCreatorV0::Create (UINT p_uiID)
{
  //## begin CIOSensorAnalogCreatorV0::Create%1039513440.body preserve=yes
	IPISensorAnalogInterface* l_Intf = new CIOSensorAnalogInterface(p_uiID);

	return l_Intf;
  //## end CIOSensorAnalogCreatorV0::Create%1039513440.body
}

// Additional Declarations
  //## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.declarations preserve=yes
  //## end CIOSensorAnalogCreatorV0%3DF5BAE10148.declarations

// Class CIOSensorDigitalCreatorV0 

CIOSensorDigitalCreatorV0::CIOSensorDigitalCreatorV0()
  //## begin CIOSensorDigitalCreatorV0::CIOSensorDigitalCreatorV0%.hasinit preserve=no
  //## end CIOSensorDigitalCreatorV0::CIOSensorDigitalCreatorV0%.hasinit
  //## begin CIOSensorDigitalCreatorV0::CIOSensorDigitalCreatorV0%.initialization preserve=yes
  :CPIObjCreatorSensorDigital(_T(""))
  //## end CIOSensorDigitalCreatorV0::CIOSensorDigitalCreatorV0%.initialization
{
  //## begin CIOSensorDigitalCreatorV0::CIOSensorDigitalCreatorV0%.body preserve=yes
  //## end CIOSensorDigitalCreatorV0::CIOSensorDigitalCreatorV0%.body
}


CIOSensorDigitalCreatorV0::~CIOSensorDigitalCreatorV0()
{
  //## begin CIOSensorDigitalCreatorV0::~CIOSensorDigitalCreatorV0%.body preserve=yes
  //## end CIOSensorDigitalCreatorV0::~CIOSensorDigitalCreatorV0%.body
}



//## Other Operations (implementation)
IPISensorDigitalInterface* CIOSensorDigitalCreatorV0::Create (UINT p_uiID)
{
  //## begin CIOSensorDigitalCreatorV0::Create%1039513442.body preserve=yes
	IPISensorDigitalInterface* l_Intf = new CIOSensorDigitalInterface(p_uiID);

	return l_Intf;
  //## end CIOSensorDigitalCreatorV0::Create%1039513442.body
}

// Additional Declarations
  //## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.declarations preserve=yes
  //## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.declarations

// Class CIOOutputDigitalCreatorV0 

CIOOutputDigitalCreatorV0::CIOOutputDigitalCreatorV0()
  //## begin CIOOutputDigitalCreatorV0::CIOOutputDigitalCreatorV0%.hasinit preserve=no
  //## end CIOOutputDigitalCreatorV0::CIOOutputDigitalCreatorV0%.hasinit
  //## begin CIOOutputDigitalCreatorV0::CIOOutputDigitalCreatorV0%.initialization preserve=yes
  :CPIObjCreatorOutputDigital(_T(""))
  //## end CIOOutputDigitalCreatorV0::CIOOutputDigitalCreatorV0%.initialization
{
  //## begin CIOOutputDigitalCreatorV0::CIOOutputDigitalCreatorV0%.body preserve=yes
  //## end CIOOutputDigitalCreatorV0::CIOOutputDigitalCreatorV0%.body
}


CIOOutputDigitalCreatorV0::~CIOOutputDigitalCreatorV0()
{
  //## begin CIOOutputDigitalCreatorV0::~CIOOutputDigitalCreatorV0%.body preserve=yes
  //## end CIOOutputDigitalCreatorV0::~CIOOutputDigitalCreatorV0%.body
}



//## Other Operations (implementation)
IPIOutputDigitalInterface* CIOOutputDigitalCreatorV0::Create (UINT p_uiID)
{
  //## begin CIOOutputDigitalCreatorV0::Create%1039513441.body preserve=yes
	IPIOutputDigitalInterface* l_Intf = new CIOOutputDigitalInterface(p_uiID);

	return l_Intf;
  //## end CIOOutputDigitalCreatorV0::Create%1039513441.body
}

// Additional Declarations
  //## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.declarations preserve=yes
  //## end CIOOutputDigitalCreatorV0%3DF5BB14038A.declarations

//## begin module%3DF5AF72034B.epilog preserve=yes
//## end module%3DF5AF72034B.epilog
