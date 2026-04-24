//## begin module%3DA52EEB00AE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA52EEB00AE.cm

//## begin module%3DA52EEB00AE.cp preserve=no
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
//## end module%3DA52EEB00AE.cp

//## Module: EBPIintf%3DA52EEB00AE; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA52EEB00AE.additionalIncludes preserve=no
//## end module%3DA52EEB00AE.additionalIncludes

//## begin module%3DA52EEB00AE.includes preserve=yes
//## end module%3DA52EEB00AE.includes

// EBCOsync
#include "EBCOsync.h"
// EBPIintf
#include "EBPIintf.h"


//## begin module%3DA52EEB00AE.declarations preserve=no
//## end module%3DA52EEB00AE.declarations

//## begin module%3DA52EEB00AE.additionalDeclarations preserve=yes
//## end module%3DA52EEB00AE.additionalDeclarations


// Class IPIStepperMotorInterface 


IPIStepperMotorInterface::IPIStepperMotorInterface (const CString& p_sSubsystemID)
  //## begin IPIStepperMotorInterface::IPIStepperMotorInterface%1034329209.hasinit preserve=no
  //## end IPIStepperMotorInterface::IPIStepperMotorInterface%1034329209.hasinit
  //## begin IPIStepperMotorInterface::IPIStepperMotorInterface%1034329209.initialization preserve=yes
  : ICOAsyncInterface(p_sSubsystemID)
  //## end IPIStepperMotorInterface::IPIStepperMotorInterface%1034329209.initialization
{
  //## begin IPIStepperMotorInterface::IPIStepperMotorInterface%1034329209.body preserve=yes
  //## end IPIStepperMotorInterface::IPIStepperMotorInterface%1034329209.body
}


IPIStepperMotorInterface::~IPIStepperMotorInterface()
{
  //## begin IPIStepperMotorInterface::~IPIStepperMotorInterface%.body preserve=yes
  //## end IPIStepperMotorInterface::~IPIStepperMotorInterface%.body
}


// Additional Declarations
  //## begin IPIStepperMotorInterface%3DA52EF90225.declarations preserve=yes
  //## end IPIStepperMotorInterface%3DA52EF90225.declarations

// Class IPIMeasurementChannelInterface 


IPIMeasurementChannelInterface::IPIMeasurementChannelInterface (const CString& p_sSubsystemID)
  //## begin IPIMeasurementChannelInterface::IPIMeasurementChannelInterface%1034575106.hasinit preserve=no
  //## end IPIMeasurementChannelInterface::IPIMeasurementChannelInterface%1034575106.hasinit
  //## begin IPIMeasurementChannelInterface::IPIMeasurementChannelInterface%1034575106.initialization preserve=yes
  : ICOAsyncInterface(p_sSubsystemID)
  //## end IPIMeasurementChannelInterface::IPIMeasurementChannelInterface%1034575106.initialization
{
  //## begin IPIMeasurementChannelInterface::IPIMeasurementChannelInterface%1034575106.body preserve=yes
  //## end IPIMeasurementChannelInterface::IPIMeasurementChannelInterface%1034575106.body
}


IPIMeasurementChannelInterface::~IPIMeasurementChannelInterface()
{
  //## begin IPIMeasurementChannelInterface::~IPIMeasurementChannelInterface%.body preserve=yes
  //## end IPIMeasurementChannelInterface::~IPIMeasurementChannelInterface%.body
}


// Additional Declarations
  //## begin IPIMeasurementChannelInterface%3DAAAC33012D.declarations preserve=yes
  //## end IPIMeasurementChannelInterface%3DAAAC33012D.declarations

// Class IPIPersistentObjInterface 


IPIPersistentObjInterface::IPIPersistentObjInterface (const CString& p_sSubsystemID)
  //## begin IPIPersistentObjInterface::IPIPersistentObjInterface%1037103456.hasinit preserve=no
  //## end IPIPersistentObjInterface::IPIPersistentObjInterface%1037103456.hasinit
  //## begin IPIPersistentObjInterface::IPIPersistentObjInterface%1037103456.initialization preserve=yes
  : ICOAsyncInterface(p_sSubsystemID)
  //## end IPIPersistentObjInterface::IPIPersistentObjInterface%1037103456.initialization
{
  //## begin IPIPersistentObjInterface::IPIPersistentObjInterface%1037103456.body preserve=yes
  //## end IPIPersistentObjInterface::IPIPersistentObjInterface%1037103456.body
}


IPIPersistentObjInterface::~IPIPersistentObjInterface()
{
  //## begin IPIPersistentObjInterface::~IPIPersistentObjInterface%.body preserve=yes
  //## end IPIPersistentObjInterface::~IPIPersistentObjInterface%.body
}


// Additional Declarations
  //## begin IPIPersistentObjInterface%3DB8095A0065.declarations preserve=yes
  //## end IPIPersistentObjInterface%3DB8095A0065.declarations

// Class IPISensorAnalogInterface 


IPISensorAnalogInterface::IPISensorAnalogInterface (const CString& p_sSubsystemID)
  //## begin IPISensorAnalogInterface::IPISensorAnalogInterface%1039527541.hasinit preserve=no
  //## end IPISensorAnalogInterface::IPISensorAnalogInterface%1039527541.hasinit
  //## begin IPISensorAnalogInterface::IPISensorAnalogInterface%1039527541.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPISensorAnalogInterface::IPISensorAnalogInterface%1039527541.initialization
{
  //## begin IPISensorAnalogInterface::IPISensorAnalogInterface%1039527541.body preserve=yes
  //## end IPISensorAnalogInterface::IPISensorAnalogInterface%1039527541.body
}


IPISensorAnalogInterface::~IPISensorAnalogInterface()
{
  //## begin IPISensorAnalogInterface::~IPISensorAnalogInterface%.body preserve=yes
  //## end IPISensorAnalogInterface::~IPISensorAnalogInterface%.body
}


// Additional Declarations
  //## begin IPISensorAnalogInterface%3DB9120A021B.declarations preserve=yes
  //## end IPISensorAnalogInterface%3DB9120A021B.declarations

// Class IPISensorDigitalInterface 


IPISensorDigitalInterface::IPISensorDigitalInterface (const CString& p_sSubsystemID)
  //## begin IPISensorDigitalInterface::IPISensorDigitalInterface%1039527542.hasinit preserve=no
  //## end IPISensorDigitalInterface::IPISensorDigitalInterface%1039527542.hasinit
  //## begin IPISensorDigitalInterface::IPISensorDigitalInterface%1039527542.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPISensorDigitalInterface::IPISensorDigitalInterface%1039527542.initialization
{
  //## begin IPISensorDigitalInterface::IPISensorDigitalInterface%1039527542.body preserve=yes
  //## end IPISensorDigitalInterface::IPISensorDigitalInterface%1039527542.body
}


IPISensorDigitalInterface::~IPISensorDigitalInterface()
{
  //## begin IPISensorDigitalInterface::~IPISensorDigitalInterface%.body preserve=yes
  //## end IPISensorDigitalInterface::~IPISensorDigitalInterface%.body
}


// Additional Declarations
  //## begin IPISensorDigitalInterface%3DB928DC0121.declarations preserve=yes
  //## end IPISensorDigitalInterface%3DB928DC0121.declarations

// Class IPIOutputAnalogInterface 


IPIOutputAnalogInterface::IPIOutputAnalogInterface (const CString& p_sSubsystemID)
  //## begin IPIOutputAnalogInterface::IPIOutputAnalogInterface%1039527543.hasinit preserve=no
  //## end IPIOutputAnalogInterface::IPIOutputAnalogInterface%1039527543.hasinit
  //## begin IPIOutputAnalogInterface::IPIOutputAnalogInterface%1039527543.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPIOutputAnalogInterface::IPIOutputAnalogInterface%1039527543.initialization
{
  //## begin IPIOutputAnalogInterface::IPIOutputAnalogInterface%1039527543.body preserve=yes
  //## end IPIOutputAnalogInterface::IPIOutputAnalogInterface%1039527543.body
}


IPIOutputAnalogInterface::~IPIOutputAnalogInterface()
{
  //## begin IPIOutputAnalogInterface::~IPIOutputAnalogInterface%.body preserve=yes
  //## end IPIOutputAnalogInterface::~IPIOutputAnalogInterface%.body
}


// Additional Declarations
  //## begin IPIOutputAnalogInterface%3DB92AB900C4.declarations preserve=yes
  //## end IPIOutputAnalogInterface%3DB92AB900C4.declarations

// Class IPIOutputDigitalInterface 


IPIOutputDigitalInterface::IPIOutputDigitalInterface (const CString& p_sSubsystemID)
  //## begin IPIOutputDigitalInterface::IPIOutputDigitalInterface%1039527544.hasinit preserve=no
  //## end IPIOutputDigitalInterface::IPIOutputDigitalInterface%1039527544.hasinit
  //## begin IPIOutputDigitalInterface::IPIOutputDigitalInterface%1039527544.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPIOutputDigitalInterface::IPIOutputDigitalInterface%1039527544.initialization
{
  //## begin IPIOutputDigitalInterface::IPIOutputDigitalInterface%1039527544.body preserve=yes
  //## end IPIOutputDigitalInterface::IPIOutputDigitalInterface%1039527544.body
}


IPIOutputDigitalInterface::~IPIOutputDigitalInterface()
{
  //## begin IPIOutputDigitalInterface::~IPIOutputDigitalInterface%.body preserve=yes
  //## end IPIOutputDigitalInterface::~IPIOutputDigitalInterface%.body
}


// Additional Declarations
  //## begin IPIOutputDigitalInterface%3DB92BE30121.declarations preserve=yes
  //## end IPIOutputDigitalInterface%3DB92BE30121.declarations

// Class IPITemperatureControlInterface 


IPITemperatureControlInterface::IPITemperatureControlInterface (const CString& p_sSubsystemID)
  //## begin IPITemperatureControlInterface::IPITemperatureControlInterface%1035548923.hasinit preserve=no
  //## end IPITemperatureControlInterface::IPITemperatureControlInterface%1035548923.hasinit
  //## begin IPITemperatureControlInterface::IPITemperatureControlInterface%1035548923.initialization preserve=yes
  : ICOAsyncInterface(p_sSubsystemID)
  //## end IPITemperatureControlInterface::IPITemperatureControlInterface%1035548923.initialization
{
  //## begin IPITemperatureControlInterface::IPITemperatureControlInterface%1035548923.body preserve=yes
  //## end IPITemperatureControlInterface::IPITemperatureControlInterface%1035548923.body
}


IPITemperatureControlInterface::~IPITemperatureControlInterface()
{
  //## begin IPITemperatureControlInterface::~IPITemperatureControlInterface%.body preserve=yes
  //## end IPITemperatureControlInterface::~IPITemperatureControlInterface%.body
}


// Additional Declarations
  //## begin IPITemperatureControlInterface%3DB939EB0037.declarations preserve=yes
  //## end IPITemperatureControlInterface%3DB939EB0037.declarations

// Class IPIPowerControlInterface 


IPIPowerControlInterface::IPIPowerControlInterface (const CString& p_sSubsystemID)
  //## begin IPIPowerControlInterface::IPIPowerControlInterface%1035548929.hasinit preserve=no
  //## end IPIPowerControlInterface::IPIPowerControlInterface%1035548929.hasinit
  //## begin IPIPowerControlInterface::IPIPowerControlInterface%1035548929.initialization preserve=yes
  : ICOAsyncInterface(p_sSubsystemID)
  //## end IPIPowerControlInterface::IPIPowerControlInterface%1035548929.initialization
{
  //## begin IPIPowerControlInterface::IPIPowerControlInterface%1035548929.body preserve=yes
  //## end IPIPowerControlInterface::IPIPowerControlInterface%1035548929.body
}


IPIPowerControlInterface::~IPIPowerControlInterface()
{
  //## begin IPIPowerControlInterface::~IPIPowerControlInterface%.body preserve=yes
  //## end IPIPowerControlInterface::~IPIPowerControlInterface%.body
}


// Additional Declarations
  //## begin IPIPowerControlInterface%3DB947960315.declarations preserve=yes
  //## end IPIPowerControlInterface%3DB947960315.declarations

// Class IPIWedgeControlInterface 


IPIWedgeControlInterface::IPIWedgeControlInterface (const CString& p_sSubsystemID)
  //## begin IPIWedgeControlInterface::IPIWedgeControlInterface%1035548934.hasinit preserve=no
  //## end IPIWedgeControlInterface::IPIWedgeControlInterface%1035548934.hasinit
  //## begin IPIWedgeControlInterface::IPIWedgeControlInterface%1035548934.initialization preserve=yes
  : ICOAsyncInterface(p_sSubsystemID)
  //## end IPIWedgeControlInterface::IPIWedgeControlInterface%1035548934.initialization
{
  //## begin IPIWedgeControlInterface::IPIWedgeControlInterface%1035548934.body preserve=yes
  //## end IPIWedgeControlInterface::IPIWedgeControlInterface%1035548934.body
}


IPIWedgeControlInterface::~IPIWedgeControlInterface()
{
  //## begin IPIWedgeControlInterface::~IPIWedgeControlInterface%.body preserve=yes
  //## end IPIWedgeControlInterface::~IPIWedgeControlInterface%.body
}


// Additional Declarations
  //## begin IPIWedgeControlInterface%3DB949A6018F.declarations preserve=yes
  //## end IPIWedgeControlInterface%3DB949A6018F.declarations

// Class IPIEventSourceInterface 


IPIEventSourceInterface::IPIEventSourceInterface (const CString& p_sSubsystemID)
  //## begin IPIEventSourceInterface::IPIEventSourceInterface%1038845452.hasinit preserve=no
  //## end IPIEventSourceInterface::IPIEventSourceInterface%1038845452.hasinit
  //## begin IPIEventSourceInterface::IPIEventSourceInterface%1038845452.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPIEventSourceInterface::IPIEventSourceInterface%1038845452.initialization
{
  //## begin IPIEventSourceInterface::IPIEventSourceInterface%1038845452.body preserve=yes
  //## end IPIEventSourceInterface::IPIEventSourceInterface%1038845452.body
}


IPIEventSourceInterface::~IPIEventSourceInterface()
{
  //## begin IPIEventSourceInterface::~IPIEventSourceInterface%.body preserve=yes
  //## end IPIEventSourceInterface::~IPIEventSourceInterface%.body
}


// Additional Declarations
  //## begin IPIEventSourceInterface%3DB94D5F02B8.declarations preserve=yes
  //## end IPIEventSourceInterface%3DB94D5F02B8.declarations

// Class IPIDiagnosticInterface 


IPIDiagnosticInterface::IPIDiagnosticInterface (const CString& p_sSubsystemID)
  //## begin IPIDiagnosticInterface::IPIDiagnosticInterface%1039528813.hasinit preserve=no
  //## end IPIDiagnosticInterface::IPIDiagnosticInterface%1039528813.hasinit
  //## begin IPIDiagnosticInterface::IPIDiagnosticInterface%1039528813.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPIDiagnosticInterface::IPIDiagnosticInterface%1039528813.initialization
{
  //## begin IPIDiagnosticInterface::IPIDiagnosticInterface%1039528813.body preserve=yes
  //## end IPIDiagnosticInterface::IPIDiagnosticInterface%1039528813.body
}


IPIDiagnosticInterface::~IPIDiagnosticInterface()
{
  //## begin IPIDiagnosticInterface::~IPIDiagnosticInterface%.body preserve=yes
  //## end IPIDiagnosticInterface::~IPIDiagnosticInterface%.body
}


// Additional Declarations
  //## begin IPIDiagnosticInterface%3DF5F2B4014F.declarations preserve=yes
  //## end IPIDiagnosticInterface%3DF5F2B4014F.declarations

// Class IPII2CEprom24LC515 



IPII2CEprom24LC515::IPII2CEprom24LC515 (const CString& p_sSubsystemID)
  //## begin IPII2CEprom24LC515::IPII2CEprom24LC515%1054620987.hasinit preserve=no
  //## end IPII2CEprom24LC515::IPII2CEprom24LC515%1054620987.hasinit
  //## begin IPII2CEprom24LC515::IPII2CEprom24LC515%1054620987.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPII2CEprom24LC515::IPII2CEprom24LC515%1054620987.initialization
{
  //## begin IPII2CEprom24LC515::IPII2CEprom24LC515%1054620987.body preserve=yes
  //## end IPII2CEprom24LC515::IPII2CEprom24LC515%1054620987.body
}


IPII2CEprom24LC515::~IPII2CEprom24LC515()
{
  //## begin IPII2CEprom24LC515::~IPII2CEprom24LC515%.body preserve=yes
  //## end IPII2CEprom24LC515::~IPII2CEprom24LC515%.body
}


// Additional Declarations
  //## begin IPII2CEprom24LC515%3EDC3C5901B5.declarations preserve=yes
  //## end IPII2CEprom24LC515%3EDC3C5901B5.declarations

// Class IPII2CTempSensorDS1631Z 



IPII2CTempSensorDS1631Z::IPII2CTempSensorDS1631Z (const CString& p_sSubsystemID)
  //## begin IPII2CTempSensorDS1631Z::IPII2CTempSensorDS1631Z%1054620988.hasinit preserve=no
  //## end IPII2CTempSensorDS1631Z::IPII2CTempSensorDS1631Z%1054620988.hasinit
  //## begin IPII2CTempSensorDS1631Z::IPII2CTempSensorDS1631Z%1054620988.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPII2CTempSensorDS1631Z::IPII2CTempSensorDS1631Z%1054620988.initialization
{
  //## begin IPII2CTempSensorDS1631Z::IPII2CTempSensorDS1631Z%1054620988.body preserve=yes
  //## end IPII2CTempSensorDS1631Z::IPII2CTempSensorDS1631Z%1054620988.body
}


IPII2CTempSensorDS1631Z::~IPII2CTempSensorDS1631Z()
{
  //## begin IPII2CTempSensorDS1631Z::~IPII2CTempSensorDS1631Z%.body preserve=yes
  //## end IPII2CTempSensorDS1631Z::~IPII2CTempSensorDS1631Z%.body
}


// Additional Declarations
  //## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.declarations preserve=yes
  //## end IPII2CTempSensorDS1631Z%3EDC3DC60261.declarations

// Class IPISystemInterface 


IPISystemInterface::IPISystemInterface (const CString& p_sSubsystemID)
  //## begin IPISystemInterface::IPISystemInterface%1055243187.hasinit preserve=no
  //## end IPISystemInterface::IPISystemInterface%1055243187.hasinit
  //## begin IPISystemInterface::IPISystemInterface%1055243187.initialization preserve=yes
  : ICOAsyncInterface(p_sSubsystemID)
  //## end IPISystemInterface::IPISystemInterface%1055243187.initialization
{
  //## begin IPISystemInterface::IPISystemInterface%1055243187.body preserve=yes
  //## end IPISystemInterface::IPISystemInterface%1055243187.body
}


IPISystemInterface::~IPISystemInterface()
{
  //## begin IPISystemInterface::~IPISystemInterface%.body preserve=yes
  //## end IPISystemInterface::~IPISystemInterface%.body
}


// Additional Declarations
  //## begin IPISystemInterface%3EE5A73D02D1.declarations preserve=yes
  //## end IPISystemInterface%3EE5A73D02D1.declarations

// Class IPII2CDigitalPotiAD5245 


IPII2CDigitalPotiAD5245::IPII2CDigitalPotiAD5245 (const CString& p_sSubsystemID)
  //## begin IPII2CDigitalPotiAD5245::IPII2CDigitalPotiAD5245%1061902089.hasinit preserve=no
  //## end IPII2CDigitalPotiAD5245::IPII2CDigitalPotiAD5245%1061902089.hasinit
  //## begin IPII2CDigitalPotiAD5245::IPII2CDigitalPotiAD5245%1061902089.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPII2CDigitalPotiAD5245::IPII2CDigitalPotiAD5245%1061902089.initialization
{
  //## begin IPII2CDigitalPotiAD5245::IPII2CDigitalPotiAD5245%1061902089.body preserve=yes
  //## end IPII2CDigitalPotiAD5245::IPII2CDigitalPotiAD5245%1061902089.body
}


IPII2CDigitalPotiAD5245::~IPII2CDigitalPotiAD5245()
{
  //## begin IPII2CDigitalPotiAD5245::~IPII2CDigitalPotiAD5245%.body preserve=yes
  //## end IPII2CDigitalPotiAD5245::~IPII2CDigitalPotiAD5245%.body
}


// Additional Declarations
  //## begin IPII2CDigitalPotiAD5245%3F44C077032C.declarations preserve=yes
  //## end IPII2CDigitalPotiAD5245%3F44C077032C.declarations

// Class IPII2CADCMAX1037 


IPII2CADCMAX1037::IPII2CADCMAX1037 (const CString& p_sSubsystemID)
  //## begin IPII2CADCMAX1037::IPII2CADCMAX1037%1061804166.hasinit preserve=no
  //## end IPII2CADCMAX1037::IPII2CADCMAX1037%1061804166.hasinit
  //## begin IPII2CADCMAX1037::IPII2CADCMAX1037%1061804166.initialization preserve=yes
  : ICOSyncInterface(p_sSubsystemID)
  //## end IPII2CADCMAX1037::IPII2CADCMAX1037%1061804166.initialization
{
  //## begin IPII2CADCMAX1037::IPII2CADCMAX1037%1061804166.body preserve=yes
  //## end IPII2CADCMAX1037::IPII2CADCMAX1037%1061804166.body
}


IPII2CADCMAX1037::~IPII2CADCMAX1037()
{
  //## begin IPII2CADCMAX1037::~IPII2CADCMAX1037%.body preserve=yes
  //## end IPII2CADCMAX1037::~IPII2CADCMAX1037%.body
}


// Additional Declarations
  //## begin IPII2CADCMAX1037%3F49C9660290.declarations preserve=yes
  //## end IPII2CADCMAX1037%3F49C9660290.declarations

//## begin module%3DA52EEB00AE.epilog preserve=yes
//## end module%3DA52EEB00AE.epilog
