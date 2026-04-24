//## begin module%3E4131920119.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E4131920119.cm

//## begin module%3E4131920119.cp preserve=no
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
//## end module%3E4131920119.cp

//## Module: EBISRcont%3E4131920119; Package body
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Source file: R:\Embedded\src\EBISR\EBISRcont.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E4131920119.additionalIncludes preserve=no
//## end module%3E4131920119.additionalIncludes

//## begin module%3E4131920119.includes preserve=yes
#ifdef _WIN32_WCE
  #include <pkfuncs.h>
#else
  #include  <math.h>
  #include  <stdlib.h>
#endif
//## end module%3E4131920119.includes

// EBHITrsm
#include "EBHITrsm.h"
// EBISRident
#include "EBISRident.h"
// EBISRcont
#include "EBISRcont.h"


//## begin module%3E4131920119.declarations preserve=no
//## end module%3E4131920119.declarations

//## begin module%3E4131920119.additionalDeclarations preserve=yes
#define DUMMY return 1;   
//  
// Ramp Defintions
//                                   REVERSE_POSITION
//                                         |
//                                                                             END_POSITION
//         |    ForwardDistance       |    |                                        |
//          __________________________
//        /                           \    |                                        |
//       /                             \
//      /                               \  |                                        |
//     /                                 \
//  __/                                  _\|                                       _|_________
//    |                                    \                           LS_POS      /
//  START_POS                               \                            |        /
//                                           \                           |       /
//                                            \                          |      /
//                                             \_______________________________/
//
//                                              |      BackwardDistance        |
//                                                                        


CHIIOCSetWCConfiguration* g_pConfig = NULL;
CHIIOCSetWCProfile* g_pProfile = NULL;

#ifndef _WIN32_WCE

#endif
//## end module%3E4131920119.additionalDeclarations


// Class CISRWCPIDControl 

//## begin CISRWCPIDControl::cMemorySize%3E47646A009C.attr preserve=no  private: static char[256] {U} 
char CISRWCPIDControl::m_cMemorySize[256];
//## end CISRWCPIDControl::cMemorySize%3E47646A009C.attr

//## begin CISRWCPIDControl::cdwFactor%3F827E9C0157.attr preserve=no  private: static DWORD {U} 10000
DWORD CISRWCPIDControl::m_cdwFactor = 10000;
//## end CISRWCPIDControl::cdwFactor%3F827E9C0157.attr

//## begin CISRWCPIDControl::cnIniAvStaticFriction%3FAB909500BB.attr preserve=no  private: static int {U} 130
int CISRWCPIDControl::m_cnIniAvStaticFriction = 130;
//## end CISRWCPIDControl::cnIniAvStaticFriction%3FAB909500BB.attr

























//## begin CISRWCPIDControl::cnMaxMovementDistance%3FAA17EE0251.attr preserve=no  private: static int {U} 2480
int CISRWCPIDControl::m_cnMaxMovementDistance = 2480;
//## end CISRWCPIDControl::cnMaxMovementDistance%3FAA17EE0251.attr




//## begin CISRWCPIDControl::cnDACEmergencyStopValue%3FAF4BD701E4.attr preserve=no  private: static int {U} 0x97000000
int CISRWCPIDControl::m_cnDACEmergencyStopValue = 0x97000000;
//## end CISRWCPIDControl::cnDACEmergencyStopValue%3FAF4BD701E4.attr





















CISRWCPIDControl::CISRWCPIDControl()
  //## begin CISRWCPIDControl::CISRWCPIDControl%.hasinit preserve=no
      : m_nNumberOfScan(0), m_bWCStart(false), m_bOsciOn(false), m_dwActLightBarrierState(0), m_dwLastLightBarrierState(0), m_TEST_ACT_DIR(0), m_TEST_LAST_VELOCITY(0), m_TEST_ACT_VELOCITY(0), m_TEST_POSITION(0), m_TEST_DAC(0), m_TEST_LB_LEFT(0), m_TEST_LB_ACHIEVED(0), m_nAccMovementDistance(0), m_nDecMovementDistance(0), m_nForwardMovementDistance(0), m_nBackwardMovementDistance(0), m_nAccCounter(0), m_nDecCounter(0), m_nAvForwardFriction(0), m_nAvBackwardFriction(0), m_nAvStaticFriction(m_cnIniAvStaticFriction), m_bWCControllerOn(false), m_dwWCWriteRegValue(0), m_nWCCnt(0), m_bFirstStateInitialization(false), m_bFirstControllerIni(false), m_bFirstAcc(false), m_nWCMaxCurCounter(0), m_eWCPosState(eWCIdle), m_pWCConfig(NULL), m_pWCProfile(NULL), m_nActValue(0), m_dwActPosCounterForward(0), m_dwActPosCounterBackward(0), m_eWCState(eWCNoConfig), m_nControllOutputValue(0), m_nNomValue(0), m_bDirection(false), m_bLBFoundInBackwardMovement(FALSE)
  //## end CISRWCPIDControl::CISRWCPIDControl%.hasinit
  //## begin CISRWCPIDControl::CISRWCPIDControl%.initialization preserve=yes
  //## end CISRWCPIDControl::CISRWCPIDControl%.initialization
{
  //## begin CISRWCPIDControl::CISRWCPIDControl%.body preserve=yes
  m_fnPtrNomValue = &CISRWCPIDControl::NomValueIdleState;
  
  // reset exception register
  WCClearException();
  //## end CISRWCPIDControl::CISRWCPIDControl%.body
}


CISRWCPIDControl::~CISRWCPIDControl()
{
  //## begin CISRWCPIDControl::~CISRWCPIDControl%.body preserve=yes
  //## end CISRWCPIDControl::~CISRWCPIDControl%.body
}


void * CISRWCPIDControl::operator new(size_t size)
{
  //## begin CISRWCPIDControl::operatornew%.body preserve=yes
  if (size > sizeof(m_cMemorySize))
  {
    return NULL;
  }
  else
  {
    return (void*)m_cMemorySize;
  }
  //## end CISRWCPIDControl::operatornew%.body
}

void CISRWCPIDControl::operator delete(void *object)
{
  //## begin CISRWCPIDControl::operatordelete%.body preserve=yes
  //## end CISRWCPIDControl::operatordelete%.body
}



//## Other Operations (implementation)
DWORD CISRWCPIDControl::WCPIDControlHandler (DWORD p_dwWCCmd, LPVOID p_pInBufWC, DWORD p_dwInBufSizeWC, LPVOID p_pOutBufWC, DWORD p_dwOutBufSizeWC)
{
  //## begin CISRWCPIDControl::WCPIDControlHandler%1044516520.body preserve=yes
  bool l_bRetVal = false;
#ifndef _WIN32_WCE
  m_TEST_INDEX = 0;
  m_TEST_LAST_VELOCITY = CHITReservedSharedMemory::GetcdwBitMaskWCActValue();
  m_TEST_ACT_VELOCITY = CHITReservedSharedMemory::GetcdwBitMaskWCActValue();
  m_TEST_POSITION = 0;
  m_TEST_LB_ACHIEVED = 0;
  m_TEST_LB_LEFT = 0;
#endif
  PDWORD l_pdwAdr = NULL;

  switch(p_dwWCCmd)
  {
    // resets the wedge control
    case IOCTL_HAL_PCI_WC_RESET:
      {
        m_pWCConfig = NULL;
        m_pWCProfile = NULL;
        m_fnPtrNomValue = &CISRWCPIDControl::NomValueIdleState;
        m_nNumberOfScan = 0;
        m_bWCStart = false; 
        m_dwActLightBarrierState = 0; 
        m_dwLastLightBarrierState = 0; 
        m_nAccMovementDistance = 0;
        m_nDecMovementDistance = 0;
        m_nForwardMovementDistance =0;
        m_nBackwardMovementDistance = 0;
        m_nAccCounter = 0;
        m_nDecCounter = 0;
        m_nAvForwardFriction = 0;
        m_nAvBackwardFriction = 0;
        m_nAvStaticFriction = m_cnIniAvStaticFriction;
        m_bWCControllerOn = false;
        m_dwWCWriteRegValue = 0;
        m_nWCCnt = 0;
        m_bFirstStateInitialization = false;
        m_bFirstControllerIni = false;
        m_bFirstAcc = false;
        m_nWCMaxCurCounter = 0;
        m_eWCPosState = eWCIdle;
        m_nActValue = 0;
        m_dwActPosCounterForward = 0;
        m_dwActPosCounterBackward = 0;
        m_eWCState = eWCNoConfig;
        m_nControllOutputValue = 0;
        m_nNomValue = 0;
        m_bDirection = false;
        // reset exception register
        WCClearException();
        break;
      }

    case IOCTL_HAL_PCI_WC_SETCONFIG:
      if ((p_dwInBufSizeWC != sizeof(CHIIOCSetWCConfiguration)) || !p_pInBufWC) {
          // Invalid size of input buffer or input buffer pointer
          WCSetException(IDE_ISR_BM_WRONG_DATA_SIZE);    
          return FALSE;
      }      
      g_pConfig = (CHIIOCSetWCConfiguration*)p_pInBufWC;
      m_pWCConfig = new CHIIOCSetWCConfiguration(*g_pConfig);
      m_eWCState = eWCConfig;
      WCClearEventRegister(); // clear WC event register
      WCClearException();
      m_fnPtrNomValue = &CISRWCPIDControl::NomValueIdleState;
      break;

    // sets the wedge control profile
    case IOCTL_HAL_PCI_WC_SETPROFILE:
        if ((p_dwInBufSizeWC != sizeof(CHIIOCSetWCProfile)) || !p_pInBufWC)
        {
            // Invalid size of input buffer or input buffer pointer
            WCSetException(IDE_ISR_BM_WRONG_DATA_SIZE);    
            return FALSE;
        }
        g_pProfile = (CHIIOCSetWCProfile*)p_pInBufWC;
        m_pWCProfile = new CHIIOCSetWCProfile(*g_pProfile);
        m_eWCState = eWCProfile;
        WCClearEventRegister(); // clear WC event register
        WCClearException();
        m_fnPtrNomValue = &CISRWCPIDControl::NomValueIdleState;
        break;

    // starts the wedge control
    case IOCTL_HAL_PCI_WC_START:
        if (!WCGetLightBarrierState())
        {
          WCSetException(IDE_ISR_BM_DRIVE_NOT_IN_LIGHT_BARRIER); 
          return FALSE;
        }
        
        if (!m_bWCStart && (m_eWCPosState == eWCIdle))
        {
          m_bWCStart = true;
          m_eWCState = eWCMeasuring;
          m_bFirstStateInitialization = true;
          m_bFirstControllerIni = true;
          m_fnPtrNomValue = &CISRWCPIDControl::NomValueInit;
        }
        else
        {
          WCSetException(IDE_ISR_BM_WEDGE_DRIVE_NOT_STOPPED); 
          return FALSE;
        }
        break;

    // stops the wedge control
    case IOCTL_HAL_PCI_WC_STOP:
        m_bWCStart = false;
        break;

    // starts the referencing mode
    case IOCTL_HAL_PCI_WC_REFERENCING:
        if (!WCGetLightBarrierState())
        {
          WCSetException(IDE_ISR_BM_DRIVE_NOT_IN_LIGHT_BARRIER); 
          return FALSE;
        }

        if (m_eWCPosState == eWCIdle)
        {
          m_eWCState = eWCReferencing;
          m_bFirstStateInitialization = true;
          m_bFirstControllerIni = true;
          m_fnPtrNomValue = &CISRWCPIDControl::NomValueInit;
        }
        else
        {
          WCSetException(IDE_ISR_BM_WEDGE_DRIVE_NOT_STOPPED);
          return FALSE;
        }
        break;

    // initialize the wedge control
    case IOCTL_HAL_PCI_WC_INI:
        if (WCGetLightBarrierState())
        { // light barrier occupied -> wedge is initialized!
          m_eWCState = eWCInitialized;
          DWORD l_dwBitMask = CHITReservedSharedMemory::GetcdwBitMaskWCInitialized() | CHITReservedSharedMemory::GetcdwBitMaskWCStoped();
          WCSetEventRegister(l_dwBitMask);
        }
        else
        {
          if (m_eWCPosState == eWCIdle)
          {
            m_eWCState = eWCInitialize;
          
            m_bFirstStateInitialization = true;
            m_bFirstControllerIni = true;
            m_fnPtrNomValue = &CISRWCPIDControl::NomValueInit;
          }
          else
          {
            WCSetException(IDE_ISR_BM_WEDGE_DRIVE_NOT_STOPPED);
            return FALSE;
          }
        }

        break;

    // light barrier state
    case IOCTL_HAL_PCI_WC_LB_STATE:
        (*(DWORD*)p_pOutBufWC) = WCGetLightBarrierState();
        p_dwOutBufSizeWC = sizeof(DWORD);
        break;
    
    // stops the wedge drive immediately
    case IOCTL_HAL_PCI_WC_EMERGENCY_STOP:
        WCEmergencyStop();
        break;

    // gets the actual wedge velocity (Wdg_Act_Vlc)
    case IOCTL_HAL_PCI_WC_GET_ACT_VELOCITY:
        (*(DWORD*)p_pOutBufWC) = WCGetActVelocityCounts();
        p_dwOutBufSizeWC = sizeof(DWORD);
        break;
    
    // gets the last wedge velocity (Wdg_Last_Vlc)
    case IOCTL_HAL_PCI_WC_GET_LAST_VELOCITY:
        (*(DWORD*)p_pOutBufWC) = WCGetLastVelocityCounts();
        p_dwOutBufSizeWC = sizeof(DWORD);
        break;
    
    // gets the wedge position (Wdg_Pos)
    case IOCTL_HAL_PCI_WC_GET_POSITION:
        (*(DWORD*)p_pOutBufWC) = WCGetActPositionCounter();
        p_dwOutBufSizeWC = sizeof(DWORD);
        break;
    
    // sets the wedge DAC value (Wdg_Volt)
    case IOCTL_HAL_PCI_WC_SET_DAC:
        if ((p_dwInBufSizeWC != sizeof(int)) || !p_pInBufWC)
        {
            // Invalid size of input buffer or input buffer pointer
            WCSetException(IDE_ISR_BM_WRONG_DATA_SIZE);   
            return FALSE;
        }
        WCSetDACValue(*((DWORD*)p_pInBufWC));
        break;
    
    // switches on/off wedge controller
    case IOCTL_HAL_PCI_WC_CONTROLLER:
        if ((p_dwInBufSizeWC != sizeof(int)) || !p_pInBufWC) {
            // Invalid size of input buffer or input buffer pointer
            WCSetException(IDE_ISR_BM_WRONG_DATA_SIZE);   
            return FALSE;
        }
        if (*((int*)p_pInBufWC) == TRUE)
        {
          m_bWCControllerOn = true;
        }
        else
        {
          m_bWCControllerOn = false;
        }
        break;
    

    default:
      WCSetException(IDE_ISR_BM_INVALID_CMD);
      return FALSE;
  }

  return TRUE;
  //## end CISRWCPIDControl::WCPIDControlHandler%1044516520.body
}

void CISRWCPIDControl::WCPIDController ()
{
  //## begin CISRWCPIDControl::WCPIDController%1045489184.body preserve=yes
#ifndef _WIN32_WCE
    m_TEST_LB_ACHIEVED = 0;
    m_TEST_LB_LEFT = 0;
#endif
  int l_nRetVal = 0;
  int l_nNomValue = 0;
  
  if (m_bWCControllerOn)
  {
    if ((m_pWCConfig != NULL) && (m_pWCProfile != NULL))
    {
      m_dwActLightBarrierState = WCGetLightBarrierState();
    
      if (m_bFirstStateInitialization)
      {
        m_nActValue = 0;
        m_dwLastLightBarrierState = m_dwActLightBarrierState;
        m_bFirstStateInitialization = false;
        m_nControllOutputValue = m_pWCConfig->GetdwWC_Ydac();
      }

      // nominal value
      l_nNomValue = WCGetNomValue();

      // simulate actual value
#ifndef _WIN32_WCE
      int l_nDirection = 0;
      if (m_bDirection)
      { // backward
        l_nDirection = -1;
      }
      else
      { // forward
        l_nDirection = 1;
      }
    
      TEST_WCGetActValue(m_nControllOutputValue, // input signal [digit]
                        l_nDirection, // direction
                        m_TEST_LAST_VELOCITY, // Last Velocity
                        m_TEST_ACT_VELOCITY, // act velocity
                        m_TEST_POSITION);// act position

#endif

      // actual value
      m_nActValue = WCGetActValue();
   
      WCCalculateStaticFriction();

      // WC PID Controller
      l_nRetVal = WCPIDControllerAlgorithm(l_nNomValue,
                                           m_nActValue,
                                           m_pWCConfig->GetdwWC_Kp(),
                                           m_pWCConfig->GetdwWC_Ki(),
                                           m_pWCConfig->GetdwWC_Kd(),
                                           m_pWCConfig->GetdwDACLimitUp(),
                                           m_pWCConfig->GetdwDACLimitDown(),
                                           m_pWCConfig->GetdwDACLimitSlr(),
                                           m_HWDef.GetdwIsrSampleTime(),
                                           m_pWCConfig->GetdwWC_DACConvFactor(),
                                           m_pWCConfig->GetdwWC_Ydac(),
                                           m_nControllOutputValue);

      // Output Signal
      WCSetDACValue(m_nControllOutputValue);

      // store actual light barrier state
      m_dwLastLightBarrierState = m_dwActLightBarrierState;
    

      // wedge drive velocity monitoring
      switch(m_eWCPosState)
      {
        case eWCAccForward:
          if ((m_nControllOutputValue >= (int)m_pWCConfig->GetdwDACLimitUp()) || 
              (m_nControllOutputValue <= (int)m_pWCConfig->GetdwDACLimitDown()))
          {
            m_nWCMaxCurCounter++;
          }
          else
          {
            m_nWCMaxCurCounter = 0;
          }

          if (m_nWCMaxCurCounter > (int)m_pWCConfig->GetdwMaxCurrentTimeTicks())
          {
            WCSetException(IDE_ISR_BM_MAX_CURRENT);
            WCEmergencyStop();
          }
          break;

        case eWCNomVelocityForward:
          if ((m_nControllOutputValue >= (int)m_pWCConfig->GetdwDACLimitUp()) || 
              (m_nControllOutputValue <= (int)m_pWCConfig->GetdwDACLimitDown()))
          {
            m_nWCMaxCurCounter++;
          }
          else
          {
            m_nWCMaxCurCounter = 0;
          }

          if (m_nWCMaxCurCounter > (int)m_pWCConfig->GetdwMaxCurrentTimeTicks())
          {
            WCSetException(IDE_ISR_BM_MAX_CURRENT);
            WCEmergencyStop();
          }
          else if (abs(m_nActValue) >= (int)m_pWCConfig->GetdwVelocityErrorHighRange())
          {
            WCSetException(IDE_ISR_BM_UPPER_VELOCITY_RANGE);
            WCEmergencyStop();
          }
          else if (abs(m_nActValue) <= (int)m_pWCConfig->GetdwVelocityErrorLowRange())
          {
            WCSetException(IDE_ISR_BM_LOWER_VELOCITY_RANGE);
            WCEmergencyStop();
          }
          break;

        case eWCDecForward:
          if ((m_nControllOutputValue >= (int)m_pWCConfig->GetdwDACLimitUp()) || 
              (m_nControllOutputValue <= (int)m_pWCConfig->GetdwDACLimitDown()))
          {
            m_nWCMaxCurCounter++;
          }
          else
          {
            m_nWCMaxCurCounter = 0;
          }

          if (m_nWCMaxCurCounter > (int)m_pWCConfig->GetdwMaxCurrentTimeTicks())
          {
            WCSetException(IDE_ISR_BM_MAX_CURRENT);
            WCEmergencyStop();
          }
          break;

        case eWCAccBackward:
          if ((m_nControllOutputValue >= (int)m_pWCConfig->GetdwDACLimitUp()) || 
              (m_nControllOutputValue <= (int)m_pWCConfig->GetdwDACLimitDown()))
          {
            m_nWCMaxCurCounter++;
          }
          else
          {
            m_nWCMaxCurCounter = 0;
          }

          if (m_nWCMaxCurCounter > (int)m_pWCConfig->GetdwMaxCurrentTimeTicks())
          {
            WCSetException(IDE_ISR_BM_MAX_CURRENT);
            WCEmergencyStop();
          }
          break;

        case eWCNomVelocityBackward:
          if ((m_nControllOutputValue >= (int)m_pWCConfig->GetdwDACLimitUp()) || 
              (m_nControllOutputValue <= (int)m_pWCConfig->GetdwDACLimitDown()))
          {
            m_nWCMaxCurCounter++;
          }
          else
          {
            m_nWCMaxCurCounter = 0;
          }

          if (m_nWCMaxCurCounter > (int)m_pWCConfig->GetdwMaxCurrentTimeTicks())
          {
            WCSetException(IDE_ISR_BM_MAX_CURRENT);
            WCEmergencyStop();
          }
          else if (abs(m_nActValue) >= (int)m_pWCConfig->GetdwVelocityErrorHighRange())
          {
            WCSetException(IDE_ISR_BM_UPPER_VELOCITY_RANGE);
            WCEmergencyStop();
          }
          else if (abs(m_nActValue) <= (int)m_pWCConfig->GetdwVelocityErrorLowRange())
          {
            WCSetException(IDE_ISR_BM_LOWER_VELOCITY_RANGE);
            WCEmergencyStop();
          }
          break;

        case eWCDecBackward:
          if ((m_nControllOutputValue >= (int)m_pWCConfig->GetdwDACLimitUp()) || 
              (m_nControllOutputValue <= (int)m_pWCConfig->GetdwDACLimitDown()))
          {
            m_nWCMaxCurCounter++;
          }
          else
          {
            m_nWCMaxCurCounter = 0;
          }

          if (m_nWCMaxCurCounter > (int)m_pWCConfig->GetdwMaxCurrentTimeTicks())
          {
            WCSetException(IDE_ISR_BM_MAX_CURRENT);
            WCEmergencyStop();
          }
          break;

        default:
          break;
      }

	  if (m_eWCPosState != eWCIdle)
	  {
		  // do not validate laser when the wedge drive is not running
		  // this way the laser can be turned off/on when the wedge drive is stopped
		  if (!WCCheckLaserDetection())
		  {
			WCSetException(IDE_ISR_BM_LASER_DETECTION);
			WCEmergencyStop();
		  }
	  }

#ifndef _WIN32_WCE
      m_TEST_X_NOM = l_nNomValue;
      m_TEST_X_ACT = m_nActValue;
      m_TEST_DAC = m_nControllOutputValue;
      m_TEST_INDEX++;
#endif
    } // if ((m_pWCConfig..
  } // if (m_bWCControllerON)

  //## end CISRWCPIDControl::WCPIDController%1045489184.body
}

DWORD CISRWCPIDControl::WCPIDControllerAlgorithm (ControllerType& p_x_nom, ControllerType& p_x_act, const ControllerType& p_Kp, const ControllerType& p_Ki, const ControllerType& p_Kd, const ControllerType& p_LimitUp, const ControllerType& p_LimitDown, const ControllerType& p_LimitSlr, const ControllerType& p_Ts, const ControllerType& p_DAC_ConvFactor, const ControllerType& p_y_DAC_Os, ControllerType& p_y_k)
{
  //## begin CISRWCPIDControl::WCPIDControllerAlgorithm%1045489183.body preserve=yes
  ///////////////////////////////////////////////////
  // p_x_nom      -> Regler Sollwert
  // p_x_act      -> aktueller Istwert
  // p_Kp         -> P-Verstärkungsfaktor
  // p_Ki         -> Faktor Nachstellzeit (I-Anteil) Berechnung siehe WC Config
  // p_Kd         -> Faktor Vorstellzeit (D-Anteil) Berechnung siehe WC Config
  // p_LimitUp    -> oberes Limit - Stellwert Begrenzung
  // p_LimitDown  -> unteres Limit - Stellwert Begrenzung
  // p_LimitSlr   -> Slew Rate Limit - d p_y_k/Ts
  // p_Ts         -> Reglertakt
  // p_y_DAC_Os   -> DAC Offset Korrektur
  // p_y_k        -> Stellsignal [Digit] begrenzt
  //////////////////////////////////////////////////////////////////////////////////////////////////
  // Definition Controller Variablen
	DWORD dwRetVal = 0;
  static ControllerType l_x_d = 0;	        // Regelabweichung zum Zeitpunkt k	
	static ControllerType l_y_I = 0;       	  // I-Anteil(k)
	static ControllerType l_y_p = 0;       	  // P-Anteil(k)
	static ControllerType l_y_D = 0;       	  // D-Anteil(k)
	static ControllerType l_y_I1 = 0;	        // I-Anteil(k-1) 
	static ControllerType l_x_d1 = 0;      	  // Regelabweichung zum Zeitpunkt k-1
	static ControllerType l_y_k1 = 0;      	  // Stellsignal [Digit] zum Zeitpunkt k-1
  static ControllerType l_y_DAC_Os = p_y_DAC_Os;
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  if (m_bFirstControllerIni)
  {
    l_x_d = 0;	        // Regelabweichung zum Zeitpunkt k	
    l_y_I = 0;       	  // I-Anteil(k)
    l_y_p = 0;       	  // P-Anteil(k)
    l_y_D = 0;       	  // D-Anteil(k)
    l_y_I1 = 0;	        // I-Anteil(k-1) 
    l_x_d1 = 0;      	  // Regelabweichung zum Zeitpunkt k-1
    l_y_k1 = p_y_DAC_Os;// + (2 * m_cnIniAvStaticFriction);      	  // Stellsignal [Digit] zum Zeitpunkt k-1
    l_y_DAC_Os = p_y_DAC_Os;
    m_bFirstControllerIni = false;
  }

  //if (abs(p_x_nom) < abs(m_pWCConfig->GetdwWedgeControllerVelocityEdge()))
  if (abs((long)p_x_nom) < abs((long)m_pWCConfig->GetdwWedgeControllerVelocityEdge())) //scch
  {
    // drive without PID controller
    switch(GeteWCPosState())
    {
      //case eWCStartPos:
      case eWCAccForward:
           if (m_bFirstAcc)
           {
             p_y_k = m_pWCConfig->GetdwStaticFrictionForward(); 
             
           }
           else
           {
             p_y_k = l_y_k1 - (2 * m_nAvStaticFriction);
           }
           break;
      case eWCDecForward:
           p_y_k = l_y_k1;
           break;
      case eWCReversePos:
      case eWCAccBackward:
           if (m_bFirstAcc)
           {
             p_y_k = m_pWCConfig->GetdwStaticFrictionBackward(); 
             
           }
           else
           {
             p_y_k = l_y_k1 + (2 * m_nAvStaticFriction);
           }
           break;
      case eWCDecBackward:
           p_y_k = l_y_k1;
           break;
      default:
           p_y_k = p_y_DAC_Os;
           break;
    }

    (p_y_k > p_LimitUp) ? p_y_k = p_LimitUp : p_y_k = p_y_k;
    (p_y_k < p_LimitDown) ? p_y_k = p_LimitDown : p_y_k = p_y_k;
  }
  else
  {
    // deviation
    l_x_d = p_x_nom - p_x_act;

    // P-control
    l_y_p = p_Kp * l_x_d;

    // D-control
    l_y_D = p_Kd * (l_x_d - l_x_d1);

    // control signal
    if (p_DAC_ConvFactor != 0)
    {
      p_y_k = ((l_y_p + l_y_I + l_y_D) / p_DAC_ConvFactor) + p_y_DAC_Os;
    }
    else
    {
      p_y_k = p_y_DAC_Os;
    }

    // upper limit control signal
    if (p_y_k > p_LimitUp)
    { // Wenn der Stellwert p_y_k am oberen Anschlag ist wird er auf den Anschlagwert gesetzt.
		  // In dieser Situation erfolgt ein Aufsummieren des Integralanteils nur dann, wenn der
		  // Istwert über dem Sollwert liegt.
      p_y_k = p_LimitUp;
      dwRetVal = 1;
		  if (l_x_d < 0)
		  { // Integrate
			  l_y_I = l_y_I1 + (p_Ki * (l_x_d + l_x_d1));
		  }
    } 
	  else if (p_y_k < p_LimitDown) // lower limit control signal
    { // Wenn der Stellwert p_y_k am unteren Anschlag ist wird er auf den Anschlagwert gesetzt.
		  // In dieser Situation erfolgt ein Aufsummieren des Integralanteils nur dann, wenn der
		  // Istwert unter dem Sollwert liegt.
      p_y_k = p_LimitDown;
      dwRetVal = 2;
		  if (l_x_d > 0)
		  {	// Integrate
			  l_y_I = l_y_I1 + (p_Ki * (l_x_d + l_x_d1));
		  }
    }
	  else
	  {	// Integrate
		  l_y_I = l_y_I1 + (p_Ki * (l_x_d + l_x_d1));
	  }

    // Slew Rate Limit
    if ((p_y_k - l_y_k1) >= p_y_DAC_Os)
    {
      p_y_k = p_y_DAC_Os;
    }
    l_y_k1 = p_y_k;

	  // xd(k-1) = xd(k)
	  l_x_d1 = l_x_d;

    // yi(k-1) = y(k)
    l_y_I1 = l_y_I;
  } // if (x_nom..
  
  return dwRetVal;
  //## end CISRWCPIDControl::WCPIDControllerAlgorithm%1045489183.body
}

int CISRWCPIDControl::WCGetNomValue ()
{
  //## begin CISRWCPIDControl::WCGetNomValue%1044516521.body preserve=yes
  int l_nRetVal = 0;
  (this->*m_fnPtrNomValue)();
  //WCGetDirection() ? l_nRetval = -m_nNomValue /*BACKWARD*/ : l_nRetval = m_nNomValue /*FORWARD*/;
  if (m_bDirection)
    l_nRetVal = m_nNomValue;/*backward*/ 
  else
    l_nRetVal = -m_nNomValue; /*forward*/;
 
  return l_nRetVal;
  //## end CISRWCPIDControl::WCGetNomValue%1044516521.body
}

DWORD CISRWCPIDControl::WCGetLastVelocityCounts ()
{
  //## begin CISRWCPIDControl::WCGetLastVelocityCounts%1044873119.body preserve=yes
#ifdef _WIN32_WCE
  DWORD* l_pAdr = CHITReservedSharedMemory::GetWedgeLastVelocityAdr();
  DWORD l_dwRetVal = *l_pAdr;
  return l_dwRetVal;
#else
  return m_TEST_LAST_VELOCITY;
#endif
  //## end CISRWCPIDControl::WCGetLastVelocityCounts%1044873119.body
}

DWORD CISRWCPIDControl::WCGetActVelocityCounts ()
{
  //## begin CISRWCPIDControl::WCGetActVelocityCounts%1044873120.body preserve=yes
#ifdef _WIN32_WCE
  DWORD* l_pAdr =  CHITReservedSharedMemory::GetWedgeActVelocityAdr();
  DWORD l_dwRetVal = *l_pAdr;
  return l_dwRetVal;
#else
  return m_TEST_ACT_VELOCITY;
#endif
  //## end CISRWCPIDControl::WCGetActVelocityCounts%1044873120.body
}

int CISRWCPIDControl::WCGetActPositionCounter ()
{
  //## begin CISRWCPIDControl::WCGetActPositionCounter%1044873121.body preserve=yes
  int l_nRetVal = 0;
#ifdef _WIN32_WCE
  DWORD* l_pAdr = CHITReservedSharedMemory::GetWedgePositionAdr();
#else
  DWORD *l_pAdr = (DWORD*)&m_TEST_POSITION;
#endif
  // determine the leading sign
  if (*l_pAdr & CHITReservedSharedMemory::GetcdwBitMaskLeadingSignWCPosition())
  { // leading sign = 1 -> value negative
    l_nRetVal = *l_pAdr | (~CHITReservedSharedMemory::GetcdwBitMaskWCActValue());
  }
  else
  { // leading sign = 0 -> value positive
    l_nRetVal = *l_pAdr & CHITReservedSharedMemory::GetcdwBitMaskWCActValue();
  }

  return l_nRetVal;
  //## end CISRWCPIDControl::WCGetActPositionCounter%1044873121.body
}

void CISRWCPIDControl::WCSetDACValue (DWORD p_dwDACValue)
{
  //## begin CISRWCPIDControl::WCSetDACValue%1045557184.body preserve=yes
#ifdef _WIN32_WCE
  m_dwWCWriteRegValue = 0;
  PDWORD l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
  m_dwWCWriteRegValue = *l_pAdr & (~CHITReservedSharedMemory::GetcdwBitMaskWCDACWakeUp());
  m_dwWCWriteRegValue|= ((p_dwDACValue << CHITReservedSharedMemory::GetcdwWCDACValueLeftShiftCounts()) & CHITReservedSharedMemory::GetcdwBitMaskWCDACValue());
  *l_pAdr = m_dwWCWriteRegValue;
#else
  m_TEST_Y_K = p_dwDACValue;
#endif
  //## end CISRWCPIDControl::WCSetDACValue%1045557184.body
}

void CISRWCPIDControl::WCSetDirection (bool p_bDirection)
{
  //## begin CISRWCPIDControl::WCSetDirection%1044873122.body preserve=yes
#ifdef _WIN32_WCE
  DWORD *l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
  if (!p_bDirection)
  { // forward direction
    *l_pAdr |= CHITReservedSharedMemory::GetcdwBitMaskWCDirection();
  }
  else
  { // backward direction
    *l_pAdr &= ~CHITReservedSharedMemory::GetcdwBitMaskWCDirection();
  }
#else
  m_TEST_ACT_DIR = p_bDirection;
#endif
  //## end CISRWCPIDControl::WCSetDirection%1044873122.body
}

void CISRWCPIDControl::WCSetEventRegister (DWORD p_dwEventMask)
{
  //## begin CISRWCPIDControl::WCSetEventRegister%1053327437.body preserve=yes
#ifdef _WIN32_WCE
  DWORD* l_pdwWCEventAdr = CHITReservedSharedMemory::GetWCEventRegStartAdr();
  *l_pdwWCEventAdr|= p_dwEventMask;
#endif
  //## end CISRWCPIDControl::WCSetEventRegister%1053327437.body
}

void CISRWCPIDControl::WCClearEventRegister (DWORD p_dwEventMask)
{
  //## begin CISRWCPIDControl::WCClearEventRegister%1053327438.body preserve=yes
#ifdef _WIN32_WCE
  DWORD* l_pdwWCEventAdr = CHITReservedSharedMemory::GetKernelProcImReadBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetWCEventReg() / sizeof(DWORD));
  *l_pdwWCEventAdr&= ~p_dwEventMask;
#endif
  //## end CISRWCPIDControl::WCClearEventRegister%1053327438.body
}

DWORD CISRWCPIDControl::WCGetDirection ()
{
  //## begin CISRWCPIDControl::WCGetDirection%1045031044.body preserve=yes
#ifdef _WIN32_WCE
  DWORD l_dwRetVal = 0;
  DWORD *l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
  if (!((*l_pAdr) & CHITReservedSharedMemory::GetcdwBitMaskWCDirection()))
  { // forward direction
    l_dwRetVal = 0;
  }
  else
  { // backward direction
    l_dwRetVal = 1;
  }
  return l_dwRetVal;
#else
  return m_TEST_ACT_DIR;
#endif
  //## end CISRWCPIDControl::WCGetDirection%1045031044.body
}

DWORD CISRWCPIDControl::WCGetLightBarrierState ()
{
  //## begin CISRWCPIDControl::WCGetLightBarrierState%1044873123.body preserve=yes
#ifdef _WIN32_WCE
  DWORD l_dwRetVal = 0;
  DWORD *l_pAdr = CHITReservedSharedMemory::GetDigInputRegStartAdr();
  DWORD l_dwMask = CHITReservedSharedMemory::GetcdwBitMaskWCLightBarrier();
  if ((*l_pAdr) & l_dwMask)
  { // light barrier free
    l_dwRetVal = 0;
  }
  else
  { // light barrier occupied
    l_dwRetVal = 1;
  }
  return l_dwRetVal;
#else
  if (m_TEST_ACT_DIR)
  { // 1 = BACKWARD
    if (abs(m_TEST_POSITION) < (int)m_TEST_POS_BACKWARD)
    { // not in LB
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  { // 0 = FORWARD m_TEST_INDEX
    if (m_TEST_POSITION < (int)m_TEST_POS_FORWARD)
    { // in LB
      return 1;
    }
    else
    {
      return 0;
    }
  }
#endif
  //## end CISRWCPIDControl::WCGetLightBarrierState%1044873123.body
}

int CISRWCPIDControl::WCGetActValue ()
{
  //## begin CISRWCPIDControl::WCGetActValue%1044873126.body preserve=yes
  int l_nRetVal = 0;
  EISRWCPosState l_ePosState = GeteWCPosState();
  int static l_nPrevPosition = 0;
  int static l_nLaserZeroCrossWatchCounter = 0;
  // velocity at time t(k-1)
  int static l_nPrev_1_WCLastVelocityCounts = CHITReservedSharedMemory::GetcdwBitMaskWCActValue(); // 0xFFFFF
  // velocity at time t(k-2)
  int static l_nPrev_2_WCLastVelocityCounts = CHITReservedSharedMemory::GetcdwBitMaskWCActValue(); // 0xFFFFF 

  if (l_ePosState == eWCIniPos)
  {
    l_nPrevPosition = 0;
    l_nLaserZeroCrossWatchCounter = 0;
    // velocity at time t(k-1)
    l_nPrev_1_WCLastVelocityCounts = CHITReservedSharedMemory::GetcdwBitMaskWCActValue(); // 0xFFFFF
    // velocity at time t(k-2)
    l_nPrev_2_WCLastVelocityCounts = CHITReservedSharedMemory::GetcdwBitMaskWCActValue(); // 0xFFFFF 
  }

  if ((l_ePosState > eWCIniPos) && (l_ePosState < eWCEnd))
  {
    //int static l_nPrevPosition = 0;
    //int static l_nLaserZeroCrossWatchCounter = 0;
    // velocity at time t(k-1)
    //int static l_nPrev_1_WCLastVelocityCounts = CHITReservedSharedMemory::GetcdwBitMaskWCActValue(); // 0xFFFFF
    // velocity at time t(k-2)
    //int static l_nPrev_2_WCLastVelocityCounts = CHITReservedSharedMemory::GetcdwBitMaskWCActValue(); // 0xFFFFF 

    int l_nActPosition = (int)WCGetActPositionCounter();
    int l_nActValueCounts = 0;
    int l_nWCLastVelocityCounts = (int)WCGetLastVelocityCounts();
    int l_nActVelocityCounts = (int)WCGetActVelocityCounts();

    int l_nFactor01 = 0;
    int l_nFactor02 = 0;
    int l_nFactor03 = 0;

    if ((l_nActPosition == l_nPrevPosition) || (l_nActPosition == (l_nPrevPosition+ 1)))
    { // no laser zero cross or one laser zero cross 
      l_nLaserZeroCrossWatchCounter = 0;
    }
    else
    { // two or more zero crosses
      l_nLaserZeroCrossWatchCounter++;
      if (l_nLaserZeroCrossWatchCounter >= 2) // !!! >= 2 i.o. ???? TEST.PB
      {
        //WCSetException(IDE_ISR_BM_ZERO_CROSS_WATCH_CNT_RANGE);
        l_nLaserZeroCrossWatchCounter = 0;
      }
    }

    if ((l_nActPosition != l_nPrevPosition))
    {
      l_nPrev_2_WCLastVelocityCounts = l_nPrev_1_WCLastVelocityCounts;
      l_nPrev_1_WCLastVelocityCounts = l_nWCLastVelocityCounts;
    }
    // add division factor
    l_nActVelocityCounts = l_nActVelocityCounts * m_cdwFactor;
    
    // extrapolate act value counts
    if (l_nWCLastVelocityCounts != 0)
    {
      l_nFactor01 = (l_nActVelocityCounts/l_nPrev_1_WCLastVelocityCounts);
      l_nFactor03 = (((int)CHITDefinitions::GetcdwPCIFrequenz()) / l_nWCLastVelocityCounts);
    }    
    if (l_nPrev_2_WCLastVelocityCounts != 0)
    {
      l_nFactor02 = (l_nActVelocityCounts/l_nPrev_2_WCLastVelocityCounts);
    }    
    l_nActValueCounts = (l_nFactor01 - l_nFactor02 + ((int)m_cdwFactor)) * l_nFactor03;
    
    //remove division factor
    l_nActValueCounts = l_nActValueCounts / ((int)m_cdwFactor);

    if (l_nActValueCounts < 0)
    { // limit act value
      l_nActValueCounts = 0;
    }

    // save actual states
    l_nPrevPosition = l_nActPosition;
    l_nPrev_1_WCLastVelocityCounts = l_nWCLastVelocityCounts;

    //WCGetDirection() ? (l_nRetVal = -l_nActValueCounts)/*backward*/ : (l_nRetVal = l_nActValueCounts) /*forward*/;
    if (m_bDirection)
      l_nRetVal = l_nActValueCounts;/*backward*/ 
    else
      l_nRetVal = -l_nActValueCounts; /*forward*/;
    
    return l_nRetVal;
  }
  else
  {
    return l_nRetVal;
  }

  //## end CISRWCPIDControl::WCGetActValue%1044873126.body
}

void CISRWCPIDControl::NomValueIdleState ()
{
  //## begin CISRWCPIDControl::NomValueIdleState%1068703781.body preserve=yes
  m_nNomValue = 0;
  m_eWCPosState = eWCIdle;
  m_eWCState = eWCStopped;
  m_bDirection = false; // Forward
  m_bFirstAcc = false;
  m_nWCMaxCurCounter = 0;
  //## end CISRWCPIDControl::NomValueIdleState%1068703781.body
}

void CISRWCPIDControl::NomValueInit ()
{
  //## begin CISRWCPIDControl::NomValueInit%1067936068.body preserve=yes
  DWORD l_dwMeasuringDistance = 0;
  if ((m_pWCProfile != NULL) && (m_pWCConfig != NULL))
  {
    m_nNomValue = 0;
    m_nAccCounter = 0;
    m_nDecCounter = 0;
    m_eWCPosState = eWCIniPos;
    m_bDirection = false; // Forward
    m_bFirstAcc = true;
    
    // reset position counter
    WCSetPositionReset(true);
  
    switch(m_eWCState)
    {
      case eWCReferencing:
        m_fnPtrNomValue = &CISRWCPIDControl::NomValueStartPosition;
        m_nForwardMovementDistance = (int)(m_pWCConfig->GetdwRefDistance1());
        m_nBackwardMovementDistance = (int)(m_pWCConfig->GetdwRefDistance1() + m_pWCProfile->GetdwRefDistance2());
        break;
      case eWCInitialize:
        m_fnPtrNomValue = &CISRWCPIDControl::NomValueReversePosition;
        m_nBackwardMovementDistance = m_cnMaxMovementDistance;
        break;
      case eWCMeasuring:
        m_fnPtrNomValue = &CISRWCPIDControl::NomValueStartPosition;
        if (m_pWCProfile->GetdwScanMode())
        { 
          // full scan
          l_dwMeasuringDistance = m_pWCConfig->GetdwMeasuringDistance();
        }
        else
        {
          // half scan
          l_dwMeasuringDistance = m_pWCConfig->GetdwMeasuringDistance() / 2;
        }
        m_nForwardMovementDistance = (int)(m_pWCConfig->GetdwForwardStartDistance() + l_dwMeasuringDistance + m_pWCConfig->GetdwForwardEndDistance());
        m_nBackwardMovementDistance = (int)(m_pWCConfig->GetdwBackwardStartDistance() + l_dwMeasuringDistance + m_pWCProfile->GetdwRefDistance2());
        break;
      default:
        m_eWCState = eWCStopped;
        break;
    };

  }
  //## end CISRWCPIDControl::NomValueInit%1067936068.body
}

void CISRWCPIDControl::NomValueStartPosition ()
{
  //## begin CISRWCPIDControl::NomValueStartPosition%1067936069.body preserve=yes
  m_eWCPosState = eWCStartPos;
  m_nNomValue = 0;
  m_fnPtrNomValue = &CISRWCPIDControl::NomValueForwardAcc;
  
  // set default values
  m_nAccMovementDistance = m_pWCConfig->GetdwAccDistance();
  m_nDecMovementDistance = m_pWCConfig->GetdwDecDistance();

  m_bDirection = false; // Forward

  // set direction
  WCSetDirection(m_bDirection); // forward direction
  // reset actual position counter
  WCSetPositionReset(false);

#ifndef _WIN32_WCE
  static bool l_bFirst = true;
  if (l_bFirst)
  {
    m_TEST_INDEX = 0;
    m_TEST_LAST_VELOCITY = CHITReservedSharedMemory::GetcdwBitMaskWCActValue();
    m_TEST_ACT_VELOCITY = CHITReservedSharedMemory::GetcdwBitMaskWCActValue();
    m_TEST_POSITION = 0;
    l_bFirst = false;
  }
#endif

  //## end CISRWCPIDControl::NomValueStartPosition%1067936069.body
}

void CISRWCPIDControl::NomValueForwardAcc ()
{
  //## begin CISRWCPIDControl::NomValueForwardAcc%1067936066.body preserve=yes
  static bool l_bFirstIni = true;
  static bool l_bLBLeftDetected = false;
  m_eWCPosState = eWCAccForward;
  if (l_bFirstIni)
  { // first initialization  
    // ini. acceleration value
    m_nNomValue = (int)m_pWCConfig->GetdwIniAcc();
    l_bFirstIni = false;
    m_nWCMaxCurCounter = 0;
  }
  
  // add acceleration delta
  m_nNomValue+= (int)m_pWCConfig->GetdwNomAcc();
  if (m_nNomValue > (int)m_pWCConfig->GetdwNomVelocity())
    m_nNomValue = (int)m_pWCConfig->GetdwNomVelocity();

  if (WCLightBarrierLeft() && (m_eWCState == eWCReferencing))
  { // light barrier left during referencing detected
    // calculate new forward movement distance for referencing
    int l_nRemainingAccDistance = m_nAccMovementDistance - WCGetActPositionCounter();
    int l_nRemainingRefDistance1 = m_pWCConfig->GetdwRefDistance1() - l_nRemainingAccDistance;
    if (l_nRemainingAccDistance <= (int)m_pWCConfig->GetdwRefDistance1())
    {
      m_nForwardMovementDistance = l_nRemainingRefDistance1;
    }
    else
    { // < 0
      m_nAccMovementDistance+= l_nRemainingRefDistance1;
      m_nDecMovementDistance = m_nAccMovementDistance;
      l_bLBLeftDetected = true;
    }
  }

  if (!(WCGetActPositionCounter() < m_nAccMovementDistance))
  { // end acceleration
    if (l_bLBLeftDetected)
    {
      m_fnPtrNomValue = &CISRWCPIDControl::NomValueForwardDec;
      m_nDecMovementDistance+=WCGetActPositionCounter();
    }
    else
    {
      m_fnPtrNomValue = &CISRWCPIDControl::NomValueForwardMeasuring;
      m_nForwardMovementDistance+=WCGetActPositionCounter();
    }
    l_bFirstIni = true;
    l_bLBLeftDetected = false;
    m_bFirstAcc = false;
  }

  //## end CISRWCPIDControl::NomValueForwardAcc%1067936066.body
}

void CISRWCPIDControl::NomValueForwardMeasuring ()
{
  //## begin CISRWCPIDControl::NomValueForwardMeasuring%1067936067.body preserve=yes
  static bool l_bFirstIni = true;
  m_eWCPosState = eWCNomVelocityForward;

  if (l_bFirstIni)
  { // first initialization  
    l_bFirstIni = false;
    m_nWCMaxCurCounter = 0;
  }

  if (WCLightBarrierLeft() && (m_eWCState == eWCReferencing))
  { // light barrier left during referencing detected
    // calculate new forward movement distance for referencing
    m_nForwardMovementDistance = WCGetActPositionCounter() + m_pWCConfig->GetdwRefDistance1();
  }

  m_nNomValue = (int)m_pWCConfig->GetdwNomVelocity();
  if (m_nNomValue < 0)
    m_nNomValue = 0;

  if (WCGetActPositionCounter() >= m_nForwardMovementDistance)
  { 
    m_fnPtrNomValue = &CISRWCPIDControl::NomValueForwardDec;
    l_bFirstIni = true;
    m_nDecMovementDistance+=WCGetActPositionCounter();
  }
  //## end CISRWCPIDControl::NomValueForwardMeasuring%1067936067.body
}

void CISRWCPIDControl::NomValueForwardDec ()
{
  //## begin CISRWCPIDControl::NomValueForwardDec%1067936070.body preserve=yes
  static bool l_bFirstIni = true;

  if (l_bFirstIni)
  { // first initialization  
    l_bFirstIni = false;
    m_nWCMaxCurCounter = 0;
  }

  m_eWCPosState = eWCDecForward;
  
  m_nNomValue-= (int)m_pWCConfig->GetdwNomDec();
  if (m_nNomValue < 0)
    m_nNomValue = 0;

  if ((!(WCGetActPositionCounter() < m_nDecMovementDistance)) || (m_nNomValue == 0))
  { // end deceleration
    l_bFirstIni = true;

    m_fnPtrNomValue = &CISRWCPIDControl::NomValueReversePosition;
    // set actual position counter = 0
    WCSetPositionReset(true);

    // WCIncScanCounter();
  }
  //## end CISRWCPIDControl::NomValueForwardDec%1067936070.body
}

void CISRWCPIDControl::NomValueReversePosition ()
{
  //## begin CISRWCPIDControl::NomValueReversePosition%1067936071.body preserve=yes
  m_eWCPosState = eWCReversePos;
  m_bDirection = true; //Backward  

  // set direction
  WCSetDirection(m_bDirection); // backward direction
  // release actual position counter
  WCSetPositionReset(false);
  
  m_nNomValue = 0;
 
  m_nWCMaxCurCounter = 0;
  
  m_nAccMovementDistance = m_pWCConfig->GetdwAccDistance();
  m_nDecMovementDistance = m_pWCConfig->GetdwDecDistance();

  m_fnPtrNomValue = &CISRWCPIDControl::NomValueBackwardAcc;
  m_bLBFoundInBackwardMovement = false;

  //## end CISRWCPIDControl::NomValueReversePosition%1067936071.body
}

void CISRWCPIDControl::NomValueBackwardAcc ()
{
  //## begin CISRWCPIDControl::NomValueBackwardAcc%1067936072.body preserve=yes
  static bool l_bFirstIni = true;
  static DWORD l_dwPositionAtLightBarrier = 0;

  m_eWCPosState = eWCAccBackward;
  if (l_bFirstIni)
  { // ini. acceleration value
    m_nNomValue = (int)m_pWCConfig->GetdwIniAcc();
    l_bFirstIni = false;
    m_nWCMaxCurCounter = 0;
  }

  // add acceleration delta
  m_nNomValue+= (int)m_pWCConfig->GetdwNomAcc();
  if (m_nNomValue > (int)m_pWCConfig->GetdwNomVelocity())
    m_nNomValue = (int)m_pWCConfig->GetdwNomVelocity();

  
  if (WCLightBarrierAchieved())
  { // light barrier achieved
    // -> finish accelerating and change to decelerating procedure afterwards
	m_bLBFoundInBackwardMovement = true;
	l_dwPositionAtLightBarrier = abs(WCGetActPositionCounter());
  }

  if (!(abs(WCGetActPositionCounter()) < m_nAccMovementDistance))
  { // end acceleration
    if (m_bLBFoundInBackwardMovement)
    {
      m_fnPtrNomValue = &CISRWCPIDControl::NomValueBackwardMeasuring;
      m_nBackwardMovementDistance = m_pWCProfile->GetdwRefDistance2() + l_dwPositionAtLightBarrier;
    }
    else
    {
      m_fnPtrNomValue = &CISRWCPIDControl::NomValueBackwardMeasuring;
      m_nBackwardMovementDistance+= abs(WCGetActPositionCounter());
    }
    l_bFirstIni = true;
    m_bFirstAcc = false;
  }
  //## end CISRWCPIDControl::NomValueBackwardAcc%1067936072.body
}

void CISRWCPIDControl::NomValueBackwardMeasuring ()
{
  //## begin CISRWCPIDControl::NomValueBackwardMeasuring%1067936073.body preserve=yes
  static bool l_bFirstIni = true;
  // static bool l_bLBFound = false;
  m_eWCPosState = eWCNomVelocityBackward;

  if (l_bFirstIni)
  { // first initialization  
    l_bFirstIni = false;
    m_nWCMaxCurCounter = 0;
  }
  
  m_nNomValue = (int)m_pWCConfig->GetdwNomVelocity();

  if (WCLightBarrierAchieved())
  {
	  m_bLBFoundInBackwardMovement = true;
      m_nBackwardMovementDistance = abs(WCGetActPositionCounter()) + m_pWCProfile->GetdwRefDistance2();
  }


  if ((abs(WCGetActPositionCounter()) >= m_nBackwardMovementDistance))
  { 
	if (!m_bLBFoundInBackwardMovement)
	{
		// light barrier did never change -> treat as error
		m_fnPtrNomValue = &CISRWCPIDControl::NomValueIdleState;
		WCSetException(IDE_ISR_BM_REFERENCE_LIGHT_BARRIER);
		WCEmergencyStop();
	}
	else
	{
		m_fnPtrNomValue = &CISRWCPIDControl::NomValueBackwardDec;
		m_nDecMovementDistance+= abs(WCGetActPositionCounter());
	}

    l_bFirstIni = true;
	m_bLBFoundInBackwardMovement = false;
  }
  //## end CISRWCPIDControl::NomValueBackwardMeasuring%1067936073.body
}

void CISRWCPIDControl::NomValueBackwardDec ()
{
  //## begin CISRWCPIDControl::NomValueBackwardDec%1067936074.body preserve=yes
  DWORD l_dwBitMask = 0;
  DWORD l_dwMeasuringDistance = 0;
  static bool l_bFirstIni = true;

  if (l_bFirstIni)
  { // first initialization  
    l_bFirstIni = false;
    m_nWCMaxCurCounter = 0;
  }
  
  m_eWCPosState = eWCDecBackward;
  
  m_nNomValue-= (int)m_pWCConfig->GetdwNomDec();
  if (m_nNomValue < 0)
    m_nNomValue = 0;

  if ((!(abs(WCGetActPositionCounter()) < m_nDecMovementDistance)) || (m_nNomValue == 0))
  { // end deceleration    
    // check number of actual scans
    l_bFirstIni = true;

    if (m_nNumberOfScan > 0)
    {
      m_nNumberOfScan--;
      if (m_nNumberOfScan <= 0) 
      { // no scans to do -> stop wedge drive
        m_bWCStart = false;
      }
    }

    switch (m_eWCState)
    {
      case eWCInitialize:
        m_eWCState = eWCInitialized;
        l_dwBitMask = CHITReservedSharedMemory::GetcdwBitMaskWCInitialized() | CHITReservedSharedMemory::GetcdwBitMaskWCStoped();
        m_eWCPosState = eWCEnd;
        break;

      case eWCReferencing:
        m_eWCState = eWCReferenced;
        l_dwBitMask = CHITReservedSharedMemory::GetcdwBitMaskWCReferenced() | CHITReservedSharedMemory::GetcdwBitMaskWCStoped();
        m_eWCPosState = eWCEnd;
        break;

      case eWCMeasuring:
        // l_dwBitMask = CHITReservedSharedMemory::GetcdwBitMaskWCMeasuring();
        if (!m_bWCStart)
        {
          m_eWCState = eWCEndMeasuring;
          l_dwBitMask = CHITReservedSharedMemory::GetcdwBitMaskWCStoped();
          m_eWCPosState = eWCEnd;
        }
        else
        {
          // set movement distances to default values
          if (m_pWCProfile->GetdwScanMode())
          { 
            // full scan
            l_dwMeasuringDistance = m_pWCConfig->GetdwMeasuringDistance();
          }
          else
          {
            // half scan
            l_dwMeasuringDistance = m_pWCConfig->GetdwMeasuringDistance() / 2;
          }
          m_nForwardMovementDistance = (int)(m_pWCConfig->GetdwForwardStartDistance() + l_dwMeasuringDistance + m_pWCConfig->GetdwForwardEndDistance());
          m_nBackwardMovementDistance = (int)(m_pWCConfig->GetdwBackwardStartDistance() + l_dwMeasuringDistance + m_pWCProfile->GetdwRefDistance2());
        }
        break;
      
      default:
        break;
    }
    
    WCSetEventRegister(l_dwBitMask);

    WCIncScanCounter();

    m_bDirection = false; //Forward  

    if (m_bWCStart)
    {
      m_fnPtrNomValue = &CISRWCPIDControl::NomValueStartPosition;
      // reset position counter
      WCSetPositionReset(true);
    }
    else
    {
      m_fnPtrNomValue = &CISRWCPIDControl::NomValueIdleState;
    }
  }
  //## end CISRWCPIDControl::NomValueBackwardDec%1067936074.body
}

DWORD CISRWCPIDControl::WCLightBarrierLeft ()
{
  //## begin CISRWCPIDControl::WCLightBarrierLeft%1067936075.body preserve=yes
  DWORD l_dwRetVal = 0;

  if (!m_dwActLightBarrierState && m_dwLastLightBarrierState)
  {
    l_dwRetVal = 1; // light barrier state has changed

#ifndef _WIN32_WCE
    m_TEST_LB_LEFT = 1;
#endif
  }

  return l_dwRetVal;
  //## end CISRWCPIDControl::WCLightBarrierLeft%1067936075.body
}

DWORD CISRWCPIDControl::WCLightBarrierAchieved ()
{
  //## begin CISRWCPIDControl::WCLightBarrierAchieved%1067936076.body preserve=yes
  DWORD l_dwRetVal = 0;
  if (m_dwActLightBarrierState && !m_dwLastLightBarrierState)
  {
    l_dwRetVal = 1; // light barrier  state has changed from occupied to free

#ifndef _WIN32_WCE
    m_TEST_LB_ACHIEVED = 1;
#endif
  }
  return l_dwRetVal;
  //## end CISRWCPIDControl::WCLightBarrierAchieved%1067936076.body
}

void CISRWCPIDControl::WCSetEnable (bool p_bValue)
{
  //## begin CISRWCPIDControl::WCSetEnable%1068014454.body preserve=yes
#ifdef _WIN32_WCE
  DWORD *l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
  if (p_bValue)
  { // factor normal
    *l_pAdr |= CHITReservedSharedMemory::GetcdwBitMaskWCEnable();
  }
  else
  { // factor low (off)
    *l_pAdr &= ~CHITReservedSharedMemory::GetcdwBitMaskWCEnable();
  }
#else
  
#endif
  //## end CISRWCPIDControl::WCSetEnable%1068014454.body
}

void CISRWCPIDControl::WCSetPositionReset (bool p_bValue)
{
  //## begin CISRWCPIDControl::WCSetPositionReset%1068014455.body preserve=yes
#ifdef _WIN32_WCE
  DWORD *l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
  if (p_bValue)
  { // position reset high
    *l_pAdr |= CHITReservedSharedMemory::GetcdwBitMaskWCPosReset();
  }
  else
  { // position reset low - position counter counts
    *l_pAdr &= ~CHITReservedSharedMemory::GetcdwBitMaskWCPosReset();
  }
#else
  if (p_bValue)
  { 
    m_TEST_POSITION = 0;
  }
#endif
  //## end CISRWCPIDControl::WCSetPositionReset%1068014455.body
}

int CISRWCPIDControl::TEST_WCGetActValue (int p_Wdg_Volt, int p_dfa, DWORD& p_clast, DWORD& p_cdiff, int& p_cp)
{
  //## begin CISRWCPIDControl::TEST_WCGetActValue%1066825080.body preserve=yes
#ifndef _WIN32_WCE
  //TEST_WCGetActValue calculates the state of a voice coil drive
  //in the next time interval if an electrical current Ia is applied to the
  //coil and the direction of movement is dfa (1=fw, -1=rv). The state of the
  //vc in the last time interval is passed as a paramter.
  //
  //other output arguments:
  //p_clast: duration timer of last laser-oscillation [20Bit integer]
  //p_cdiff: timer count since last rising edge of laser signal [20Bit integer]
  //p_cp:    external position counter (sensitive to direction dfa)
  //
  //internal variables are stored in the vector state:
  //
  //v:     velocity [m/s]
  //x:     position [m] (peak is x=0, wedge tip is <0)
  //p_cp:    external position counter (sensitive to direction dfa)
  //tlast: duration of last laser-oscillation [s]
  //tdiff: time passed since last rising edge of laser signal [s]
  
  //initial values
  static double vv=0;           //v last cycle
  static double xv=-0.00484;    //starting position [m] (wedge tip, 0=peak-position)
  static double tlast=0;        //duration of last laser oscillation
  static double tdiff=0;        //time since last laser oscillation
  
  static double deltat=92.155e-6;   //sampling-interval [s]
  static double m=70e-3;            //moving mass [kg]
  static double k=1.65;             //force-constant of coil [N/A]
  static double Fr=0.165;           //friction-force [N]
  static double skeil=2*6.05e-6;    //distance of a laser-oscillation [m]
  static double fpci=33.335e6;      //PCI-frequency [Hz]

  //DAC-current conversion
  static double Mot_OS_Adj=2416;        //offset adjustment [digits]
  static double MotGain=1;              //gain adjustment []
  static double Mot_Gain_Adj=769.78e-6; //amplification factor [A/digit]
  double xneu = 0;
  double cneu = 0;
  double cv = 0;
  double vneu = 0;
  double Ia = 0;

  Ia = (p_Wdg_Volt-Mot_OS_Adj)*(MotGain*Mot_Gain_Adj);

  //vneu=0;
  if (vv > 0)
  {
    vneu=vv+((k*deltat/m)*Ia)-(Fr*deltat/m); //new velocity
  }
  else if (vv == 0)
  {
    vneu=vv+((k*deltat/m)*Ia); //new velocity
  }
  else
  {
    vneu=vv+((k*deltat/m)*Ia)+(Fr*deltat/m); //new velocity
  }
  xneu=xv+vneu*deltat;                            //new position

  if (vneu >= 0)     //make sure, that rising edge is chosen inside the current x-interval
  {   
      cneu=floor(xneu/skeil);
  } 
  else
  {
    cneu=ceil(xneu/skeil);
  }  

  //cv = 0;
  if (vv >= 0)       //absolute position last cycle
  {
    cv=floor(xv/skeil);
  }
  else
  {
    cv=ceil(xv/skeil);
  }
  
  if (cneu != cv)//rising edge of laser-signal?
  {
      p_cp=(int)(p_cp+(p_dfa*fabs(cneu-cv))); //inc-/decrement the direction-dependent counter 
      if (fabs(cneu-cv)==1)//only one laser-oscillation in this time interval?
      {
          tlast=tdiff+fabs((((cneu*skeil)-xv)/vneu));  //time delay so far + delta in the current interval
      }
      else
      {       
        tlast=fabs(skeil/vneu);                  //more than one laser oscillation? -> t=dx/vneu (last oscillation-period)
      }
      tdiff=fabs((xneu-(cneu*skeil))/vneu);        //reset time delay since last rising edge
  }
  else                        //no rising edge?
  {
    tdiff=tdiff+deltat;     //increase time delay by one cycle
  }

  p_clast=(DWORD)floor(tlast*fpci);    //convert time to counter increments and truncate
  //if (p_clast > (DWORD)pow(2,20))
  if (p_clast > (DWORD)pow((float)2,20)) //scch
  {
    p_clast=(DWORD)pow((float)2,20);
  }

  p_cdiff=(DWORD)floor(tdiff*fpci);
  if (p_cdiff > (DWORD)pow((float)2,20))
  {
    p_cdiff=(DWORD)pow((float)2,20);
  }
  
  CO_TRACE(_T("EBISR"),_T("vv = %1.3f; xv = %1.4f; cneu = %2.1f; cv = %2.1f; tlast = %10.3e; tdiff = %10.3e;\n"),vv,xv,cneu,cv,tlast,tdiff);

  vv=vneu;           //save state
  xv=xneu;
#endif
  return 0;
  //## end CISRWCPIDControl::TEST_WCGetActValue%1066825080.body
}

void CISRWCPIDControl::WCCalculateStaticFriction ()
{
  //## begin CISRWCPIDControl::WCCalculateStaticFriction%1068189083.body preserve=yes
  static int l_nForwardCnt = 0;
  static int l_nBackwardCnt = 0;

  // forward friction
  if (m_eWCPosState < eWCNomVelocityForward)
  { 
    l_nForwardCnt = 0;
    m_nAvForwardFriction = 0;
  }
  if (m_eWCPosState == eWCNomVelocityForward)
  { // calculate forward friction
    m_nAvForwardFriction+= m_nControllOutputValue;
    l_nForwardCnt++;
  }

  // backward friction
  if (m_eWCPosState < eWCNomVelocityBackward)
  { 
    l_nBackwardCnt = 0;
    m_nAvBackwardFriction = 0;
  }
  if (m_eWCPosState == eWCNomVelocityBackward)
  { // calculate backward friction
    m_nAvBackwardFriction+= m_nControllOutputValue;
    l_nBackwardCnt++;
  }

  // calculate static friction
  if (m_eWCPosState == eWCEnd)
  {
    if ((l_nForwardCnt!=0) && (l_nBackwardCnt!=0))
    {
      m_nAvForwardFriction/= l_nForwardCnt;
      m_nAvBackwardFriction/= l_nBackwardCnt;
      m_nAvStaticFriction = abs((m_nAvForwardFriction - m_nAvBackwardFriction) / 2);
    }
    else
    {
      m_nAvStaticFriction = m_cnIniAvStaticFriction;
    }
  }
  //## end CISRWCPIDControl::WCCalculateStaticFriction%1068189083.body
}

void CISRWCPIDControl::WCEmergencyStop ()
{
  //## begin CISRWCPIDControl::WCEmergencyStop%1068453036.body preserve=yes
#ifdef _WIN32_WCE
  m_bWCControllerOn = false;

  DWORD *l_pAdr = CHITReservedSharedMemory::GetWedgeWriteRegAdr();
  *l_pAdr = m_cnDACEmergencyStopValue;

  m_bWCStart = false;
  m_eWCState = eWCStopped;
  m_eWCPosState = eWCIdle;

  // set controller values 0
  m_nNomValue = 0;
  m_nControllOutputValue = 0;
  m_nActValue = 0;
  
  WCClearEventRegister(); // clear WC event register

  WCSetEventRegister(CHITReservedSharedMemory::GetcdwBitMaskWCStoped() | CHITReservedSharedMemory::GetcdwBitMaskWCException());
  
  m_fnPtrNomValue = &CISRWCPIDControl::NomValueIdleState;
#else
  
#endif
  //## end CISRWCPIDControl::WCEmergencyStop%1068453036.body
}

void CISRWCPIDControl::WCSetDigOutput (DWORD p_dwValue)
{
  //## begin CISRWCPIDControl::WCSetDigOutput%1068703783.body preserve=yes
  PDWORD l_pdwAdr = CHITReservedSharedMemory::GetDigOutputRegStartAdr();
  *l_pdwAdr |= p_dwValue;
  //## end CISRWCPIDControl::WCSetDigOutput%1068703783.body
}

void CISRWCPIDControl::WCClearDigOutput (DWORD p_dwValue)
{
  //## begin CISRWCPIDControl::WCClearDigOutput%1068703784.body preserve=yes
  PDWORD l_pdwAdr = CHITReservedSharedMemory::GetDigOutputRegStartAdr();
  *l_pdwAdr &= ~p_dwValue;
  //## end CISRWCPIDControl::WCClearDigOutput%1068703784.body
}

void CISRWCPIDControl::WCIncScanCounter ()
{
  //## begin CISRWCPIDControl::WCIncScanCounter%1073896760.body preserve=yes
  PDWORD l_pdwAdr = CHITReservedSharedMemory::GetNumberOfWCScanAdr();
  *l_pdwAdr = *l_pdwAdr + 1;
  //## end CISRWCPIDControl::WCIncScanCounter%1073896760.body
}

bool CISRWCPIDControl::WCCheckLaserDetection ()
{
  //## begin CISRWCPIDControl::WCCheckLaserDetection%1073998356.body preserve=yes
  PDWORD l_pdwAdr = CHITReservedSharedMemory::GetLaserDetectionAdr();
  
  DWORD l_dwADCDigit = (*l_pdwAdr & CHITADCMAX1281::GetcdwBitMaskCurLaserDet()) >> CHITADCMAX1281::GetcdwShiftCountsCurLaserDet();

  if (l_dwADCDigit <= CHITADCMAX1281::GetcdwADCLowerLimitDigit())
    return false;

  return true;
  //## end CISRWCPIDControl::WCCheckLaserDetection%1073998356.body
}

void CISRWCPIDControl::WCSetException (DWORD p_dwExceptionBitMask)
{
  //## begin CISRWCPIDControl::WCSetException%1073998357.body preserve=yes
  PDWORD l_pdwAdr = CHITReservedSharedMemory::GetHWExceptionRegStartAdr();
  *l_pdwAdr|= p_dwExceptionBitMask;
  //## end CISRWCPIDControl::WCSetException%1073998357.body
}

void CISRWCPIDControl::WCClearException ()
{
  //## begin CISRWCPIDControl::WCClearException%1076491968.body preserve=yes
  PDWORD l_pdwAdr = CHITReservedSharedMemory::GetHWExceptionRegStartAdr();
  *l_pdwAdr = 0;
  //## end CISRWCPIDControl::WCClearException%1076491968.body
}

//## Get and Set Operations for Class Attributes (implementation)

bool CISRWCPIDControl::GetbWCStart ()
{
  //## begin CISRWCPIDControl::GetbWCStart%3E491C5D004E.get preserve=no
  return m_bWCStart;
  //## end CISRWCPIDControl::GetbWCStart%3E491C5D004E.get
}

void CISRWCPIDControl::SetbWCStart (bool value)
{
  //## begin CISRWCPIDControl::SetbWCStart%3E491C5D004E.set preserve=no
  m_bWCStart = value;
  //## end CISRWCPIDControl::SetbWCStart%3E491C5D004E.set
}

bool CISRWCPIDControl::GetbOsciOn ()
{
  //## begin CISRWCPIDControl::GetbOsciOn%3FABBAFA02BF.get preserve=no
  return m_bOsciOn;
  //## end CISRWCPIDControl::GetbOsciOn%3FABBAFA02BF.get
}

void CISRWCPIDControl::SetbOsciOn (bool value)
{
  //## begin CISRWCPIDControl::SetbOsciOn%3FABBAFA02BF.set preserve=no
  m_bOsciOn = value;
  //## end CISRWCPIDControl::SetbOsciOn%3FABBAFA02BF.set
}

DWORD CISRWCPIDControl::GetTEST_ACT_DIR ()
{
  //## begin CISRWCPIDControl::GetTEST_ACT_DIR%3E4A749E0138.get preserve=no
  return m_TEST_ACT_DIR;
  //## end CISRWCPIDControl::GetTEST_ACT_DIR%3E4A749E0138.get
}

void CISRWCPIDControl::SetTEST_ACT_DIR (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_ACT_DIR%3E4A749E0138.set preserve=no
  m_TEST_ACT_DIR = value;
  //## end CISRWCPIDControl::SetTEST_ACT_DIR%3E4A749E0138.set
}

DWORD CISRWCPIDControl::GetTEST_X_NOM ()
{
  //## begin CISRWCPIDControl::GetTEST_X_NOM%3E523C8A0290.get preserve=no
  return m_TEST_X_NOM;
  //## end CISRWCPIDControl::GetTEST_X_NOM%3E523C8A0290.get
}

void CISRWCPIDControl::SetTEST_X_NOM (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_X_NOM%3E523C8A0290.set preserve=no
  m_TEST_X_NOM = value;
  //## end CISRWCPIDControl::SetTEST_X_NOM%3E523C8A0290.set
}

DWORD CISRWCPIDControl::GetTEST_X_ACT ()
{
  //## begin CISRWCPIDControl::GetTEST_X_ACT%3E523CB0001F.get preserve=no
  return m_TEST_X_ACT;
  //## end CISRWCPIDControl::GetTEST_X_ACT%3E523CB0001F.get
}

void CISRWCPIDControl::SetTEST_X_ACT (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_X_ACT%3E523CB0001F.set preserve=no
  m_TEST_X_ACT = value;
  //## end CISRWCPIDControl::SetTEST_X_ACT%3E523CB0001F.set
}

DWORD CISRWCPIDControl::GetTEST_Y_K ()
{
  //## begin CISRWCPIDControl::GetTEST_Y_K%3E523CC002CE.get preserve=no
  return m_TEST_Y_K;
  //## end CISRWCPIDControl::GetTEST_Y_K%3E523CC002CE.get
}

DWORD CISRWCPIDControl::GetTEST_INDEX ()
{
  //## begin CISRWCPIDControl::GetTEST_INDEX%3E524A55002E.get preserve=no
  return m_TEST_INDEX;
  //## end CISRWCPIDControl::GetTEST_INDEX%3E524A55002E.get
}

void CISRWCPIDControl::SetTEST_INDEX (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_INDEX%3E524A55002E.set preserve=no
  m_TEST_INDEX = value;
  //## end CISRWCPIDControl::SetTEST_INDEX%3E524A55002E.set
}

DWORD CISRWCPIDControl::GetTEST_POS_FORWARD ()
{
  //## begin CISRWCPIDControl::GetTEST_POS_FORWARD%3F8A4D6801C5.get preserve=no
  return m_TEST_POS_FORWARD;
  //## end CISRWCPIDControl::GetTEST_POS_FORWARD%3F8A4D6801C5.get
}

void CISRWCPIDControl::SetTEST_POS_FORWARD (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_POS_FORWARD%3F8A4D6801C5.set preserve=no
  m_TEST_POS_FORWARD = value;
  //## end CISRWCPIDControl::SetTEST_POS_FORWARD%3F8A4D6801C5.set
}

DWORD CISRWCPIDControl::GetTEST_POS_BACKWARD ()
{
  //## begin CISRWCPIDControl::GetTEST_POS_BACKWARD%3F8A4D69005D.get preserve=no
  return m_TEST_POS_BACKWARD;
  //## end CISRWCPIDControl::GetTEST_POS_BACKWARD%3F8A4D69005D.get
}

void CISRWCPIDControl::SetTEST_POS_BACKWARD (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_POS_BACKWARD%3F8A4D69005D.set preserve=no
  m_TEST_POS_BACKWARD = value;
  //## end CISRWCPIDControl::SetTEST_POS_BACKWARD%3F8A4D69005D.set
}

DWORD CISRWCPIDControl::GetTEST_LAST_VELOCITY ()
{
  //## begin CISRWCPIDControl::GetTEST_LAST_VELOCITY%3F979FD10148.get preserve=no
  return m_TEST_LAST_VELOCITY;
  //## end CISRWCPIDControl::GetTEST_LAST_VELOCITY%3F979FD10148.get
}

void CISRWCPIDControl::SetTEST_LAST_VELOCITY (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_LAST_VELOCITY%3F979FD10148.set preserve=no
  m_TEST_LAST_VELOCITY = value;
  //## end CISRWCPIDControl::SetTEST_LAST_VELOCITY%3F979FD10148.set
}

DWORD CISRWCPIDControl::GetTEST_ACT_VELOCITY ()
{
  //## begin CISRWCPIDControl::GetTEST_ACT_VELOCITY%3F979FD102DE.get preserve=no
  return m_TEST_ACT_VELOCITY;
  //## end CISRWCPIDControl::GetTEST_ACT_VELOCITY%3F979FD102DE.get
}

void CISRWCPIDControl::SetTEST_ACT_VELOCITY (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_ACT_VELOCITY%3F979FD102DE.set preserve=no
  m_TEST_ACT_VELOCITY = value;
  //## end CISRWCPIDControl::SetTEST_ACT_VELOCITY%3F979FD102DE.set
}

int CISRWCPIDControl::GetTEST_POSITION ()
{
  //## begin CISRWCPIDControl::GetTEST_POSITION%3F979FD201E4.get preserve=no
  return m_TEST_POSITION;
  //## end CISRWCPIDControl::GetTEST_POSITION%3F979FD201E4.get
}

void CISRWCPIDControl::SetTEST_POSITION (int value)
{
  //## begin CISRWCPIDControl::SetTEST_POSITION%3F979FD201E4.set preserve=no
  m_TEST_POSITION = value;
  //## end CISRWCPIDControl::SetTEST_POSITION%3F979FD201E4.set
}

DWORD CISRWCPIDControl::GetTEST_DAC ()
{
  //## begin CISRWCPIDControl::GetTEST_DAC%3FA6556E01E4.get preserve=no
  return m_TEST_DAC;
  //## end CISRWCPIDControl::GetTEST_DAC%3FA6556E01E4.get
}

void CISRWCPIDControl::SetTEST_DAC (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_DAC%3FA6556E01E4.set preserve=no
  m_TEST_DAC = value;
  //## end CISRWCPIDControl::SetTEST_DAC%3FA6556E01E4.set
}

DWORD CISRWCPIDControl::GetTEST_LB_LEFT ()
{
  //## begin CISRWCPIDControl::GetTEST_LB_LEFT%3FA91D6B0157.get preserve=no
  return m_TEST_LB_LEFT;
  //## end CISRWCPIDControl::GetTEST_LB_LEFT%3FA91D6B0157.get
}

void CISRWCPIDControl::SetTEST_LB_LEFT (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_LB_LEFT%3FA91D6B0157.set preserve=no
  m_TEST_LB_LEFT = value;
  //## end CISRWCPIDControl::SetTEST_LB_LEFT%3FA91D6B0157.set
}

DWORD CISRWCPIDControl::GetTEST_LB_ACHIEVED ()
{
  //## begin CISRWCPIDControl::GetTEST_LB_ACHIEVED%3FA91D7B01E4.get preserve=no
  return m_TEST_LB_ACHIEVED;
  //## end CISRWCPIDControl::GetTEST_LB_ACHIEVED%3FA91D7B01E4.get
}

void CISRWCPIDControl::SetTEST_LB_ACHIEVED (DWORD value)
{
  //## begin CISRWCPIDControl::SetTEST_LB_ACHIEVED%3FA91D7B01E4.set preserve=no
  m_TEST_LB_ACHIEVED = value;
  //## end CISRWCPIDControl::SetTEST_LB_ACHIEVED%3FA91D7B01E4.set
}

int CISRWCPIDControl::GetnAvStaticFriction ()
{
  //## begin CISRWCPIDControl::GetnAvStaticFriction%3FAB445A00BB.get preserve=no
  return m_nAvStaticFriction;
  //## end CISRWCPIDControl::GetnAvStaticFriction%3FAB445A00BB.get
}

DWORD CISRWCPIDControl::GetdwWCWriteRegValue ()
{
  //## begin CISRWCPIDControl::GetdwWCWriteRegValue%3FB3830F006D.get preserve=no
  return m_dwWCWriteRegValue;
  //## end CISRWCPIDControl::GetdwWCWriteRegValue%3FB3830F006D.get
}

int CISRWCPIDControl::GetnWCCnt ()
{
  //## begin CISRWCPIDControl::GetnWCCnt%3FB3A7BF029F.get preserve=no
  return m_nWCCnt;
  //## end CISRWCPIDControl::GetnWCCnt%3FB3A7BF029F.get
}

int CISRWCPIDControl::GetnWCMaxCurCounter ()
{
  //## begin CISRWCPIDControl::GetnWCMaxCurCounter%4028F6D70186.get preserve=no
  return m_nWCMaxCurCounter;
  //## end CISRWCPIDControl::GetnWCMaxCurCounter%4028F6D70186.get
}

//## Get and Set Operations for Associations (implementation)

const EISRWCPosState CISRWCPIDControl::GeteWCPosState () const
{
  //## begin CISRWCPIDControl::GeteWCPosState%3E4223B00223.get preserve=no
  return m_eWCPosState;
  //## end CISRWCPIDControl::GeteWCPosState%3E4223B00223.get
}

const CISRWCPIDControl::ControllerType CISRWCPIDControl::GetnActValue () const
{
  //## begin CISRWCPIDControl::GetnActValue%3E422F0B02A0.get preserve=no
  return m_nActValue;
  //## end CISRWCPIDControl::GetnActValue%3E422F0B02A0.get
}

const DWORD CISRWCPIDControl::GetdwActPosCounterForward () const
{
  //## begin CISRWCPIDControl::GetdwActPosCounterForward%3E435B290001.get preserve=no
  return m_dwActPosCounterForward;
  //## end CISRWCPIDControl::GetdwActPosCounterForward%3E435B290001.get
}

const DWORD CISRWCPIDControl::GetdwActPosCounterBackward () const
{
  //## begin CISRWCPIDControl::GetdwActPosCounterBackward%3E47B89C0252.get preserve=no
  return m_dwActPosCounterBackward;
  //## end CISRWCPIDControl::GetdwActPosCounterBackward%3E47B89C0252.get
}

CISRWCPIDControl::ControllerType CISRWCPIDControl::GetnControllOutputValue ()
{
  //## begin CISRWCPIDControl::GetnControllOutputValue%3FAB65DD02DF.get preserve=no
  return m_nControllOutputValue;
  //## end CISRWCPIDControl::GetnControllOutputValue%3FAB65DD02DF.get
}

CISRWCPIDControl::ControllerType CISRWCPIDControl::GetnNomValue ()
{
  //## begin CISRWCPIDControl::GetnNomValue%3FAB78A800FB.get preserve=no
  return m_nNomValue;
  //## end CISRWCPIDControl::GetnNomValue%3FAB78A800FB.get
}

// Additional Declarations
  //## begin CISRWCPIDControl%3E40E116000F.declarations preserve=yes
  //## end CISRWCPIDControl%3E40E116000F.declarations

//## begin module%3E4131920119.epilog preserve=yes
//## end module%3E4131920119.epilog
