//## begin module%3DA5C23E00E0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5C23E00E0.cm

//## begin module%3DA5C23E00E0.cp preserve=no
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
//## end module%3DA5C23E00E0.cp

//## Module: EBPIcrea%3DA5C23E00E0; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA5C23E00E0.additionalIncludes preserve=no
//## end module%3DA5C23E00E0.additionalIncludes

//## begin module%3DA5C23E00E0.includes preserve=yes
//## end module%3DA5C23E00E0.includes

// EBPIcrea
#include "EBPIcrea.h"
// EBPIintf
#include "EBPIintf.h"


//## begin module%3DA5C23E00E0.declarations preserve=no
//## end module%3DA5C23E00E0.declarations

//## begin module%3DA5C23E00E0.additionalDeclarations preserve=yes
//## end module%3DA5C23E00E0.additionalDeclarations


//## begin CPIObjCreatorStepperMotor.instantiation preserve=no
template class CPIObjCreator< IPIStepperMotorInterface >;
//## end CPIObjCreatorStepperMotor.instantiation
//## begin CPIObjCreatorMeasurementChannel.instantiation preserve=no
template class CPIObjCreator< IPIMeasurementChannelInterface >;
//## end CPIObjCreatorMeasurementChannel.instantiation
//## begin CPIObjCreatorSensorAnalog.instantiation preserve=no
template class CPIObjCreator< IPISensorAnalogInterface >;
//## end CPIObjCreatorSensorAnalog.instantiation
//## begin CPIObjCreatorTemperatureControl.instantiation preserve=no
template class CPIObjCreator< IPITemperatureControlInterface >;
//## end CPIObjCreatorTemperatureControl.instantiation
//## begin CPIObjCreatorWedgeControl.instantiation preserve=no
template class CPIObjCreator< IPIWedgeControlInterface >;
//## end CPIObjCreatorWedgeControl.instantiation
//## begin CPIObjCreatorPowerControl.instantiation preserve=no
template class CPIObjCreator< IPIPowerControlInterface >;
//## end CPIObjCreatorPowerControl.instantiation
//## begin CPIObjCreatorEventSource.instantiation preserve=no
template class CPIObjCreator< IPIEventSourceInterface >;
//## end CPIObjCreatorEventSource.instantiation
//## begin CPIObjCreatorPersistentObject.instantiation preserve=no
template class CPIObjCreator< IPIPersistentObjInterface >;
//## end CPIObjCreatorPersistentObject.instantiation
//## begin CPIObjCreatorSensorDigital.instantiation preserve=no
template class CPIObjCreator< IPISensorDigitalInterface >;
//## end CPIObjCreatorSensorDigital.instantiation
//## begin CPIObjCreatorOutputAnalog.instantiation preserve=no
template class CPIObjCreator< IPIOutputAnalogInterface >;
//## end CPIObjCreatorOutputAnalog.instantiation
//## begin CPIObjCreatorOutputDigital.instantiation preserve=no
template class CPIObjCreator< IPIOutputDigitalInterface >;
//## end CPIObjCreatorOutputDigital.instantiation
//## begin CPIObjCreatorDiagnostics.instantiation preserve=no
template class CPIObjCreator< IPIDiagnosticInterface >;
//## end CPIObjCreatorDiagnostics.instantiation
//## begin CPIObjCreatorI2CSensorDS1631Z.instantiation preserve=no
template class CPIObjCreator< IPII2CTempSensorDS1631Z >;
//## end CPIObjCreatorI2CSensorDS1631Z.instantiation
//## begin CPIObjCreatorI2CEprom24LC515.instantiation preserve=no
template class CPIObjCreator< IPII2CEprom24LC515 >;
//## end CPIObjCreatorI2CEprom24LC515.instantiation
//## begin CPIObjCreatorI2CADCMAX1037.instantiation preserve=no
template class CPIObjCreator< IPII2CADCMAX1037 >;
//## end CPIObjCreatorI2CADCMAX1037.instantiation
//## begin CPIObjCreatorI2CDigitalPotiAD5245.instantiation preserve=no
template class CPIObjCreator< IPII2CDigitalPotiAD5245 >;
//## end CPIObjCreatorI2CDigitalPotiAD5245.instantiation
//## begin module%3DA5C23E00E0.epilog preserve=yes
//## end module%3DA5C23E00E0.epilog
