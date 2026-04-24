//## begin module%3DA5C23603A6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5C23603A6.cm

//## begin module%3DA5C23603A6.cp preserve=no
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
//## end module%3DA5C23603A6.cp

//## Module: EBPIcrea%3DA5C23603A6; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIcrea.h

#ifndef EBPIcrea_h
#define EBPIcrea_h 1

//## begin module%3DA5C23603A6.additionalIncludes preserve=no
//## end module%3DA5C23603A6.additionalIncludes

//## begin module%3DA5C23603A6.includes preserve=yes
//## end module%3DA5C23603A6.includes


class EBPI_DLL_DECL IPIMeasurementChannelInterface;
class EBPI_DLL_DECL IPIStepperMotorInterface;
class EBPI_DLL_DECL IPIPowerControlInterface;
class EBPI_DLL_DECL IPITemperatureControlInterface;
class EBPI_DLL_DECL IPIOutputDigitalInterface;
class EBPI_DLL_DECL IPIOutputAnalogInterface;
class EBPI_DLL_DECL IPISensorDigitalInterface;
class EBPI_DLL_DECL IPISensorAnalogInterface;
class EBPI_DLL_DECL IPIPersistentObjInterface;
class EBPI_DLL_DECL IPIEventSourceInterface;
class EBPI_DLL_DECL IPIWedgeControlInterface;
class EBPI_DLL_DECL IPII2CADCMAX1037;
class EBPI_DLL_DECL IPII2CDigitalPotiAD5245;
class EBPI_DLL_DECL IPII2CTempSensorDS1631Z;
class EBPI_DLL_DECL IPII2CEprom24LC515;
class EBPI_DLL_DECL IPIDiagnosticInterface;

//## begin module%3DA5C23603A6.declarations preserve=no
//## end module%3DA5C23603A6.declarations

//## begin module%3DA5C23603A6.additionalDeclarations preserve=yes
//## end module%3DA5C23603A6.additionalDeclarations


//## begin CPIObjCreator%3DA5C22100DF.preface preserve=yes
//## end CPIObjCreator%3DA5C22100DF.preface

//## Class: CPIObjCreator%3DA5C22100DF; Parameterized Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA5C2A402D2;IPIStepperMotorInterface { -> F}

template <class TYPE>
class CPIObjCreator 
{
  //## begin CPIObjCreator%3DA5C22100DF.initialDeclarations preserve=yes
  //## end CPIObjCreator%3DA5C22100DF.initialDeclarations

  public:
    //## Constructors (generated)
      CPIObjCreator();

    //## Constructors (specified)
      //## Operation: CPIObjCreator%1034272538
      CPIObjCreator (WCHAR* p_sVersion);

    //## Destructor (generated)
      virtual ~CPIObjCreator();


    //## Other Operations (specified)
      //## Operation: MatchesVersion%1034272539
      bool MatchesVersion (WCHAR* p_sVersion);

      //## Operation: Create%1034272540
      virtual TYPE* Create (UINT p_uiID) = 0;

    // Additional Public Declarations
      //## begin CPIObjCreator%3DA5C22100DF.public preserve=yes
      //## end CPIObjCreator%3DA5C22100DF.public

  protected:
    // Additional Protected Declarations
      //## begin CPIObjCreator%3DA5C22100DF.protected preserve=yes
      //## end CPIObjCreator%3DA5C22100DF.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: sVersion%3DA5C372026A
      //## begin CPIObjCreator::sVersion%3DA5C372026A.attr preserve=no  private: WCHAR[32] {U} 
      WCHAR m_sVersion[32];
      //## end CPIObjCreator::sVersion%3DA5C372026A.attr

    // Additional Private Declarations
      //## begin CPIObjCreator%3DA5C22100DF.private preserve=yes
      //## end CPIObjCreator%3DA5C22100DF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIObjCreator%3DA5C22100DF.implementation preserve=yes
      //## end CPIObjCreator%3DA5C22100DF.implementation

};

//## begin CPIObjCreator%3DA5C22100DF.postscript preserve=yes
//## end CPIObjCreator%3DA5C22100DF.postscript

//## begin CPIObjCreatorStepperMotor%3DAAC19100A0.preface preserve=yes
//## end CPIObjCreatorStepperMotor%3DAAC19100A0.preface

//## Class: CPIObjCreatorStepperMotor%3DAAC19100A0; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAC5610302;IPIStepperMotorInterface { -> F}

typedef CPIObjCreator< IPIStepperMotorInterface > CPIObjCreatorStepperMotor;

//## begin CPIObjCreatorStepperMotor%3DAAC19100A0.postscript preserve=yes
//## end CPIObjCreatorStepperMotor%3DAAC19100A0.postscript

//## begin CPIObjCreatorMeasurementChannel%3DAAC1D10311.preface preserve=yes
//## end CPIObjCreatorMeasurementChannel%3DAAC1D10311.preface

//## Class: CPIObjCreatorMeasurementChannel%3DAAC1D10311; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAC567038E;IPIMeasurementChannelInterface { -> F}

typedef CPIObjCreator< IPIMeasurementChannelInterface > CPIObjCreatorMeasurementChannel;

//## begin CPIObjCreatorMeasurementChannel%3DAAC1D10311.postscript preserve=yes
//## end CPIObjCreatorMeasurementChannel%3DAAC1D10311.postscript

//## begin CPIObjCreatorSensorAnalog%3DD0A3CA0227.preface preserve=yes
//## end CPIObjCreatorSensorAnalog%3DD0A3CA0227.preface

//## Class: CPIObjCreatorSensorAnalog%3DD0A3CA0227; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A6F60370;IPISensorAnalogInterface { -> F}

typedef CPIObjCreator< IPISensorAnalogInterface > CPIObjCreatorSensorAnalog;

//## begin CPIObjCreatorSensorAnalog%3DD0A3CA0227.postscript preserve=yes
//## end CPIObjCreatorSensorAnalog%3DD0A3CA0227.postscript

//## begin CPIObjCreatorTemperatureControl%3DD0A3F2017C.preface preserve=yes
//## end CPIObjCreatorTemperatureControl%3DD0A3F2017C.preface

//## Class: CPIObjCreatorTemperatureControl%3DD0A3F2017C; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A7020321;IPITemperatureControlInterface { -> F}

typedef CPIObjCreator< IPITemperatureControlInterface > CPIObjCreatorTemperatureControl;

//## begin CPIObjCreatorTemperatureControl%3DD0A3F2017C.postscript preserve=yes
//## end CPIObjCreatorTemperatureControl%3DD0A3F2017C.postscript

//## begin CPIObjCreatorWedgeControl%3DD0A40300DF.preface preserve=yes
//## end CPIObjCreatorWedgeControl%3DD0A40300DF.preface

//## Class: CPIObjCreatorWedgeControl%3DD0A40300DF; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A70403CD;IPIWedgeControlInterface { -> F}

typedef CPIObjCreator< IPIWedgeControlInterface > CPIObjCreatorWedgeControl;

//## begin CPIObjCreatorWedgeControl%3DD0A40300DF.postscript preserve=yes
//## end CPIObjCreatorWedgeControl%3DD0A40300DF.postscript

//## begin CPIObjCreatorPowerControl%3DD0A40E0266.preface preserve=yes
//## end CPIObjCreatorPowerControl%3DD0A40E0266.preface

//## Class: CPIObjCreatorPowerControl%3DD0A40E0266; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A7070091;IPIPowerControlInterface { -> F}

typedef CPIObjCreator< IPIPowerControlInterface > CPIObjCreatorPowerControl;

//## begin CPIObjCreatorPowerControl%3DD0A40E0266.postscript preserve=yes
//## end CPIObjCreatorPowerControl%3DD0A40E0266.postscript

//## begin CPIObjCreatorEventSource%3DD0A43203DD.preface preserve=yes
//## end CPIObjCreatorEventSource%3DD0A43203DD.preface

//## Class: CPIObjCreatorEventSource%3DD0A43203DD; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A70B02D3;IPIEventSourceInterface { -> F}

typedef CPIObjCreator< IPIEventSourceInterface > CPIObjCreatorEventSource;

//## begin CPIObjCreatorEventSource%3DD0A43203DD.postscript preserve=yes
//## end CPIObjCreatorEventSource%3DD0A43203DD.postscript

//## begin CPIObjCreatorPersistentObject%3DD0A43E02A4.preface preserve=yes
//## end CPIObjCreatorPersistentObject%3DD0A43E02A4.preface

//## Class: CPIObjCreatorPersistentObject%3DD0A43E02A4; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A70D037F;IPIPersistentObjInterface { -> F}

typedef CPIObjCreator< IPIPersistentObjInterface > CPIObjCreatorPersistentObject;

//## begin CPIObjCreatorPersistentObject%3DD0A43E02A4.postscript preserve=yes
//## end CPIObjCreatorPersistentObject%3DD0A43E02A4.postscript

//## begin CPIObjCreatorSensorDigital%3DD0A55B0227.preface preserve=yes
//## end CPIObjCreatorSensorDigital%3DD0A55B0227.preface

//## Class: CPIObjCreatorSensorDigital%3DD0A55B0227; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A6F9015C;IPISensorDigitalInterface { -> F}

typedef CPIObjCreator< IPISensorDigitalInterface > CPIObjCreatorSensorDigital;

//## begin CPIObjCreatorSensorDigital%3DD0A55B0227.postscript preserve=yes
//## end CPIObjCreatorSensorDigital%3DD0A55B0227.postscript

//## begin CPIObjCreatorOutputAnalog%3DD0A56700B0.preface preserve=yes
//## end CPIObjCreatorOutputAnalog%3DD0A56700B0.preface

//## Class: CPIObjCreatorOutputAnalog%3DD0A56700B0; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A6FB01F9;IPIOutputAnalogInterface { -> F}

typedef CPIObjCreator< IPIOutputAnalogInterface > CPIObjCreatorOutputAnalog;

//## begin CPIObjCreatorOutputAnalog%3DD0A56700B0.postscript preserve=yes
//## end CPIObjCreatorOutputAnalog%3DD0A56700B0.postscript

//## begin CPIObjCreatorOutputDigital%3DD0A5720062.preface preserve=yes
//## end CPIObjCreatorOutputDigital%3DD0A5720062.preface

//## Class: CPIObjCreatorOutputDigital%3DD0A5720062; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD0A70002F3;IPIOutputDigitalInterface { -> F}

typedef CPIObjCreator< IPIOutputDigitalInterface > CPIObjCreatorOutputDigital;

//## begin CPIObjCreatorOutputDigital%3DD0A5720062.postscript preserve=yes
//## end CPIObjCreatorOutputDigital%3DD0A5720062.postscript

//## begin CPIObjCreatorDiagnostics%3DF7314500F2.preface preserve=yes
//## end CPIObjCreatorDiagnostics%3DF7314500F2.preface

//## Class: CPIObjCreatorDiagnostics%3DF7314500F2; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF7319002E6;IPIDiagnosticInterface { -> F}

typedef CPIObjCreator< IPIDiagnosticInterface > CPIObjCreatorDiagnostics;

//## begin CPIObjCreatorDiagnostics%3DF7314500F2.postscript preserve=yes
//## end CPIObjCreatorDiagnostics%3DF7314500F2.postscript

//## begin CPIObjCreatorI2CSensorDS1631Z%3EE6CF3701DD.preface preserve=yes
//## end CPIObjCreatorI2CSensorDS1631Z%3EE6CF3701DD.preface

//## Class: CPIObjCreatorI2CSensorDS1631Z%3EE6CF3701DD; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE6CFB50121;IPII2CTempSensorDS1631Z { -> F}

typedef CPIObjCreator< IPII2CTempSensorDS1631Z > CPIObjCreatorI2CSensorDS1631Z;

//## begin CPIObjCreatorI2CSensorDS1631Z%3EE6CF3701DD.postscript preserve=yes
//## end CPIObjCreatorI2CSensorDS1631Z%3EE6CF3701DD.postscript

//## begin CPIObjCreatorI2CEprom24LC515%3EE6CF8602C7.preface preserve=yes
//## end CPIObjCreatorI2CEprom24LC515%3EE6CF8602C7.preface

//## Class: CPIObjCreatorI2CEprom24LC515%3EE6CF8602C7; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE6CFB70306;IPII2CEprom24LC515 { -> F}

typedef CPIObjCreator< IPII2CEprom24LC515 > CPIObjCreatorI2CEprom24LC515;

//## begin CPIObjCreatorI2CEprom24LC515%3EE6CF8602C7.postscript preserve=yes
//## end CPIObjCreatorI2CEprom24LC515%3EE6CF8602C7.postscript

//## begin CPIObjCreatorI2CADCMAX1037%3F49FB490119.preface preserve=yes
//## end CPIObjCreatorI2CADCMAX1037%3F49FB490119.preface

//## Class: CPIObjCreatorI2CADCMAX1037%3F49FB490119; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F49FB6801C5;IPII2CADCMAX1037 { -> F}

typedef CPIObjCreator< IPII2CADCMAX1037 > CPIObjCreatorI2CADCMAX1037;

//## begin CPIObjCreatorI2CADCMAX1037%3F49FB490119.postscript preserve=yes
//## end CPIObjCreatorI2CADCMAX1037%3F49FB490119.postscript

//## begin CPIObjCreatorI2CDigitalPotiAD5245%3F4B564500DA.preface preserve=yes
//## end CPIObjCreatorI2CDigitalPotiAD5245%3F4B564500DA.preface

//## Class: CPIObjCreatorI2CDigitalPotiAD5245%3F4B564500DA; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4B56DA0290;IPII2CDigitalPotiAD5245 { -> F}

typedef CPIObjCreator< IPII2CDigitalPotiAD5245 > CPIObjCreatorI2CDigitalPotiAD5245;

//## begin CPIObjCreatorI2CDigitalPotiAD5245%3F4B564500DA.postscript preserve=yes
//## end CPIObjCreatorI2CDigitalPotiAD5245%3F4B564500DA.postscript

// Parameterized Class CPIObjCreator 

// Parameterized Class CPIObjCreator 


template <class TYPE>
CPIObjCreator<TYPE>::CPIObjCreator()
  //## begin CPIObjCreator::CPIObjCreator%.hasinit preserve=no
  //## end CPIObjCreator::CPIObjCreator%.hasinit
  //## begin CPIObjCreator::CPIObjCreator%.initialization preserve=yes
  //## end CPIObjCreator::CPIObjCreator%.initialization
{
  //## begin CPIObjCreator::CPIObjCreator%.body preserve=yes
    memset(m_sVersion, 0, sizeof(m_sVersion));
  //## end CPIObjCreator::CPIObjCreator%.body
}

template <class TYPE>
CPIObjCreator<TYPE>::CPIObjCreator (WCHAR* p_sVersion)
  //## begin CPIObjCreator::CPIObjCreator%1034272538.hasinit preserve=no
  //## end CPIObjCreator::CPIObjCreator%1034272538.hasinit
  //## begin CPIObjCreator::CPIObjCreator%1034272538.initialization preserve=yes
  //## end CPIObjCreator::CPIObjCreator%1034272538.initialization
{
  //## begin CPIObjCreator::CPIObjCreator%1034272538.body preserve=yes
    memset(m_sVersion, 0, sizeof(m_sVersion));
	wcscpy(m_sVersion, p_sVersion);
  //## end CPIObjCreator::CPIObjCreator%1034272538.body
}


template <class TYPE>
CPIObjCreator<TYPE>::~CPIObjCreator()
{
  //## begin CPIObjCreator::~CPIObjCreator%.body preserve=yes
  //## end CPIObjCreator::~CPIObjCreator%.body
}



//## Other Operations (implementation)
template <class TYPE>
bool CPIObjCreator<TYPE>::MatchesVersion (WCHAR* p_sVersion)
{
  //## begin CPIObjCreator::MatchesVersion%1034272539.body preserve=yes
	return wcscmp(m_sVersion, p_sVersion) == 0;
  //## end CPIObjCreator::MatchesVersion%1034272539.body
}

// Additional Declarations
  //## begin CPIObjCreator%3DA5C22100DF.declarations preserve=yes
  //## end CPIObjCreator%3DA5C22100DF.declarations

//## begin module%3DA5C23603A6.epilog preserve=yes
//## end module%3DA5C23603A6.epilog


#endif
