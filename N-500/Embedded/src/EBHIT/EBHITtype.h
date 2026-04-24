//## begin module%3E26C6DC02DC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E26C6DC02DC.cm

//## begin module%3E26C6DC02DC.cp preserve=no
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
//## end module%3E26C6DC02DC.cp

//## Module: EBHITtype%3E26C6DC02DC; Package specification
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Source file: R:\Embedded\src\EBHIT\EBHITtype.h

#ifndef EBHITtype_h
#define EBHITtype_h 1

//## begin module%3E26C6DC02DC.additionalIncludes preserve=no
//## end module%3E26C6DC02DC.additionalIncludes

//## begin module%3E26C6DC02DC.includes preserve=yes
//## end module%3E26C6DC02DC.includes

// EBHITrsm
#include "EBHITrsm.h"


//## begin module%3E26C6DC02DC.declarations preserve=no
//## end module%3E26C6DC02DC.declarations

//## begin module%3E26C6DC02DC.additionalDeclarations preserve=yes
#ifndef _WIN32_WCE
  #define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
      ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
  )
  #define FILE_DEVICE_HAL 1
  #define METHOD_BUFFERED 2
  #define FILE_ANY_ACCESS 3

#endif
/////////////////////////////////////////////////////////////////////////////////////////////
// Exception Error Codes
// exception ID's
#define IDE_ISR_ERROR	            		  1000

#define IDE_PCI_ERROR	            		  2000


/////////////////////////////////////////////////////////////////////////////////////////////
// IOCTL to controll ISR load manipulation
//
#define IOCTL_HAL_ISRLOAD                CTL_CODE(FILE_DEVICE_HAL, 0x1020, METHOD_BUFFERED, FILE_ANY_ACCESS)

/////////////////////////////////////////////////////////////////////////////////////////////
// IOCTL to controll VIA-Tetstfeature ISRTIME
//
#define IOCTL_HAL_GET_MAX_ISRTIME       CTL_CODE(FILE_DEVICE_HAL,   0x1040,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_HAL_GET_ISR_TIME          CTL_CODE(FILE_DEVICE_HAL,   0x1041,METHOD_BUFFERED,FILE_ANY_ACCESS)



/////////////////////////////////////////////////////////////////////////////////////////////
// IOCTL to controll PCI (SPARTAN-II) device driver
//
///////////////////////////////
// DESCRIPTION:     sets the PCI settings
// INPUT:           
// OUTPUT:          - 
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_SET_ISR_PCI_SETTINGS  CTL_CODE(FILE_DEVICE_HAL,   0x9042,METHOD_BUFFERED,FILE_ANY_ACCESS)
///////////////////////////////
// DESCRIPTION:     checks the driver state
// INPUT:           -
// OUTPUT:          DWORD - log. IRQ number
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_DRIVER_READY       CTL_CODE(FILE_DEVICE_HAL, 0x9043, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     read from the PCI register with the specified input address
// INPUT:           PCI register address -> DWORD
// OUTPUT:          value from the spec. PCI address -> DWORD
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_READ_REGISTER      CTL_CODE(FILE_DEVICE_HAL, 0x9044, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     write to the PCI register with the specified input address
// INPUT:           structur "CHIIOCWriteDWord"
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WRITE_REGISTER     CTL_CODE(FILE_DEVICE_HAL, 0x9045, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Reserved
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_03                 CTL_CODE(FILE_DEVICE_HAL, 0x9046, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     clears the WC ISR
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WCISR_CLEAR        CTL_CODE(FILE_DEVICE_HAL, 0x9047, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Reserved
// INPUT:
// OUTPUT:
// RETURN VALUES:
#define IOCTL_HAL_PCI_GET_LAST_ERROR     CTL_CODE(FILE_DEVICE_HAL, 0x9048, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Enables the WC ISR
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WCISR_ENABLE       CTL_CODE(FILE_DEVICE_HAL, 0x9049, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Disables the WC ISR
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WCISR_DISABLE      CTL_CODE(FILE_DEVICE_HAL, 0x9050, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Reserved
// INPUT:
// OUTPUT:
// RETURN VALUES:
#define IOCTL_HAL_PCI_SET_RSM_ADDRESS    CTL_CODE(FILE_DEVICE_HAL, 0x9051, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Reserved
// INPUT:
// OUTPUT:
// RETURN VALUES:
#define IOCTL_HAL_PCI_CLEAR_RSM_ADDRESS   CTL_CODE(FILE_DEVICE_HAL, 0x9052, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Sets the configuration for the Wedge Control
// INPUT:           structure "CHIIOCSetWCConfiguration"
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_SETCONFIG       CTL_CODE(FILE_DEVICE_HAL, 0x9053, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Sets the profile for the Wedge Control
// INPUT:           structure "CHIIOCSetWCProfile"
// OUTPUT:
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_SETPROFILE      CTL_CODE(FILE_DEVICE_HAL, 0x9054, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Starts the Wedge Control
// INPUT:           Number of scans -> DWORD
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_START           CTL_CODE(FILE_DEVICE_HAL, 0x9055, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Stops the Wedge Control
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_STOP            CTL_CODE(FILE_DEVICE_HAL, 0x9056, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Starts the referencing mode of the wedge control
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_REFERENCING     CTL_CODE(FILE_DEVICE_HAL, 0x9057, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Starts the initialization mode of the wedge control
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_INI             CTL_CODE(FILE_DEVICE_HAL, 0x9058, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     stops the wedge drive immediately
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_EMERGENCY_STOP  CTL_CODE(FILE_DEVICE_HAL, 0x9059, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     reads the state of the light barrier (wedge control)
// INPUT:           -
// OUTPUT:          state of the light barrier 0: LB not active 1: LB active
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_LB_STATE         CTL_CODE(FILE_DEVICE_HAL, 0x9060, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Starts the data acquisition  (IFM and Laser)
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_DATA_ON            CTL_CODE(FILE_DEVICE_HAL, 0x9061, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Stops the data acquisition  (IFM and Laser)
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_DATA_OFF           CTL_CODE(FILE_DEVICE_HAL, 0x9062, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     gets the actual wedge velocity (Wdg_Act_Vlc)
// INPUT:           -
// OUTPUT:          actual wedge velocity
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_GET_ACT_VELOCITY   CTL_CODE(FILE_DEVICE_HAL, 0x9063, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     gets the last wedge velocity (Wdg_Last_Vlc)
// INPUT:           -
// OUTPUT:          last wedge velocity
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_GET_LAST_VELOCITY   CTL_CODE(FILE_DEVICE_HAL, 0x9064, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     gets the wedge position (Wdg_Pos)
// INPUT:           -
// OUTPUT:          wedge position
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_GET_POSITION      CTL_CODE(FILE_DEVICE_HAL, 0x9065, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     sets the wedge DAC value (Wdg_Volt)
// INPUT:           DAC value
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_SET_DAC      CTL_CODE(FILE_DEVICE_HAL, 0x9066, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     switchs on/off the wedge controller
// INPUT:           1: WC controller ON / 0:  WC controller OFF
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_CONTROLLER    CTL_CODE(FILE_DEVICE_HAL, 0x9067, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     sets a new buffer size for the stream buffer
// INPUT:           new size
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_SET_BUFFERSIZE     CTL_CODE(FILE_DEVICE_HAL, 0x9068, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     mask HW and WC event register
// INPUT:           structure "CHIIOCEventMasks"
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_MASK_EVENT_REG  CTL_CODE(FILE_DEVICE_HAL, 0x9069, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     notify the ISR to send an event
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_SEND_EVENT     CTL_CODE(FILE_DEVICE_HAL, 0x9070, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     disables the watchdog
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WD_DISABLE     CTL_CODE(FILE_DEVICE_HAL, 0x9071, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     refresh the watchdog
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WD_REFRESH     CTL_CODE(FILE_DEVICE_HAL, 0x9072, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     resets the WC objects
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_WC_RESET      CTL_CODE(FILE_DEVICE_HAL, 0x9073, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     Acknowledge the ISR event signalisation
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_ACK_EVENT     CTL_CODE(FILE_DEVICE_HAL, 0x9074, METHOD_BUFFERED, FILE_ANY_ACCESS)

///////////////////////////////
// DESCRIPTION:     -
// INPUT:           -
// OUTPUT:          -
// RETURN VALUES:   Nonzero indicates success
#define IOCTL_HAL_PCI_     CTL_CODE(FILE_DEVICE_HAL, 0x9075, METHOD_BUFFERED, FILE_ANY_ACCESS)



/////////////////////////////////////////////////////////////////////////////////////////////
// ERROR Codes PCI (SPARTAN-II) device driver
//
///////////////////////////////
// DESCRIPTION:     The operation completed successfully.
#define PCI_ERROR_SUCCESS                  0

///////////////////////////////
// DESCRIPTION:     Incorrect function
#define PCI_ERROR_INVALID_FUNCTION         1

///////////////////////////////
// DESCRIPTION:     Access is denied
#define PCI_ERROR_ACCESS_DENIED            2

///////////////////////////////
// DESCRIPTION:     Invalid handle (PCI driver)
#define PCI_INVALID_HANDLE_VALUE           3


///////////////////////////////
// DESCRIPTION:     IFM and Laser Data / Sample (WC IRQ)
#define DATA_STACK_DIVIDER        8

//## end module%3E26C6DC02DC.additionalDeclarations


//## begin CHIIOCWriteDWord%3E26CCC202CD.preface preserve=yes
//## end CHIIOCWriteDWord%3E26CCC202CD.preface

//## Class: CHIIOCWriteDWord%3E26CCC202CD
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHIIOCWriteDWord 
{
  //## begin CHIIOCWriteDWord%3E26CCC202CD.initialDeclarations preserve=yes
  //## end CHIIOCWriteDWord%3E26CCC202CD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHIIOCWriteDWord%1042699232
      CHIIOCWriteDWord (DWORD p_dwAddress = 0, DWORD p_dwValue = 0);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E26CCE802CD
      //## Role: CHIIOCWriteDWord::dwAddress%3E26CCE90251
      const DWORD GetdwAddress () const;

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E26CE74034A
      //## Role: CHIIOCWriteDWord::dwValue%3E26CE750156
      const DWORD GetdwValue () const;

    // Additional Public Declarations
      //## begin CHIIOCWriteDWord%3E26CCC202CD.public preserve=yes
      //## end CHIIOCWriteDWord%3E26CCC202CD.public

  protected:
    // Additional Protected Declarations
      //## begin CHIIOCWriteDWord%3E26CCC202CD.protected preserve=yes
      //## end CHIIOCWriteDWord%3E26CCC202CD.protected

  private:
    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E26CCE802CD
      //## begin CHIIOCWriteDWord::dwAddress%3E26CCE90251.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwAddress;
      //## end CHIIOCWriteDWord::dwAddress%3E26CCE90251.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E26CE74034A
      //## begin CHIIOCWriteDWord::dwValue%3E26CE750156.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwValue;
      //## end CHIIOCWriteDWord::dwValue%3E26CE750156.role

    // Additional Private Declarations
      //## begin CHIIOCWriteDWord%3E26CCC202CD.private preserve=yes
      //## end CHIIOCWriteDWord%3E26CCC202CD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIIOCWriteDWord%3E26CCC202CD.implementation preserve=yes
      //## end CHIIOCWriteDWord%3E26CCC202CD.implementation

};

//## begin CHIIOCWriteDWord%3E26CCC202CD.postscript preserve=yes
//## end CHIIOCWriteDWord%3E26CCC202CD.postscript

//## begin CHIIOCSetRSMAddress%3E2C215E01B3.preface preserve=yes
//## end CHIIOCSetRSMAddress%3E2C215E01B3.preface

//## Class: CHIIOCSetRSMAddress%3E2C215E01B3
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHIIOCSetRSMAddress 
{
  //## begin CHIIOCSetRSMAddress%3E2C215E01B3.initialDeclarations preserve=yes
  //## end CHIIOCSetRSMAddress%3E2C215E01B3.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHIIOCSetRSMAddress%1043067484
      CHIIOCSetRSMAddress (LPVOID p_pRSMStreamBuffer = NULL, LPVOID p_pRSMProcessImage = NULL);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E54807200CB
      //## Role: CHIIOCSetRSMAddress::pRSMProcessImage%3E54807202FE
      const LPVOID GetpRSMProcessImage () const;

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2C219D01C3
      //## Role: CHIIOCSetRSMAddress::pRSMStreamBuffer%3E2C219E00BA
      const LPVOID GetpRSMStreamBuffer () const;
      void SetpRSMStreamBuffer (LPVOID value);

    // Additional Public Declarations
      //## begin CHIIOCSetRSMAddress%3E2C215E01B3.public preserve=yes
      //## end CHIIOCSetRSMAddress%3E2C215E01B3.public

  protected:
    // Additional Protected Declarations
      //## begin CHIIOCSetRSMAddress%3E2C215E01B3.protected preserve=yes
      //## end CHIIOCSetRSMAddress%3E2C215E01B3.protected

  private:
    // Data Members for Associations

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E54807200CB
      //## begin CHIIOCSetRSMAddress::pRSMProcessImage%3E54807202FE.role preserve=no  public: LPVOID {1..1 -> 1..1VFHN}
      LPVOID m_pRSMProcessImage;
      //## end CHIIOCSetRSMAddress::pRSMProcessImage%3E54807202FE.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2C219D01C3
      //## begin CHIIOCSetRSMAddress::pRSMStreamBuffer%3E2C219E00BA.role preserve=no  public: LPVOID {1..1 -> 1..1VFHN}
      LPVOID m_pRSMStreamBuffer;
      //## end CHIIOCSetRSMAddress::pRSMStreamBuffer%3E2C219E00BA.role

    // Additional Private Declarations
      //## begin CHIIOCSetRSMAddress%3E2C215E01B3.private preserve=yes
      //## end CHIIOCSetRSMAddress%3E2C215E01B3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIIOCSetRSMAddress%3E2C215E01B3.implementation preserve=yes
      //## end CHIIOCSetRSMAddress%3E2C215E01B3.implementation

};

//## begin CHIIOCSetRSMAddress%3E2C215E01B3.postscript preserve=yes
//## end CHIIOCSetRSMAddress%3E2C215E01B3.postscript

//## begin CHITDefinitions%3E4BB85401C5.preface preserve=yes
//## end CHITDefinitions%3E4BB85401C5.preface

//## Class: CHITDefinitions%3E4BB85401C5
//	DESCRIPTION:
//	hardware constants class
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHITDefinitions 
{
  //## begin CHITDefinitions%3E4BB85401C5.initialDeclarations preserve=yes
  //## end CHITDefinitions%3E4BB85401C5.initialDeclarations

  public:
    //## begin CHITDefinitions::EHITDividerDefinitions%3E6D9F1E03C8.preface preserve=yes
    //## end CHITDefinitions::EHITDividerDefinitions%3E6D9F1E03C8.preface

    //## Class: EHITDividerDefinitions%3E6D9F1E03C8
    //## Category: EBHIT (Hardware Interface Types)%3E425F410109
    //## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum{eOverSampleDivider = 6, eDataStackDivider = 8, eDataSampleDivider = 64} EHITDividerDefinitions;

    //## begin CHITDefinitions::EHITDividerDefinitions%3E6D9F1E03C8.postscript preserve=yes
    //## end CHITDefinitions::EHITDividerDefinitions%3E6D9F1E03C8.postscript

    //## Constructors (generated)
      CHITDefinitions();

    //## Destructor (generated)
      ~CHITDefinitions();

    //## Storage Management Operations (generated)
      static void * operator new(size_t size);

      static void operator delete(void *object);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cdwPCIFrequenz%3E30F1D000C6
      //	DESCRPTION:
      //	PCI cycle frequenz
      //
      //	UNIT:
      //	[Hz]
      static const DWORD GetcdwPCIFrequenz ();

      //## Attribute: cdwDataSampleDivider%3E3100F7009A
      static const DWORD GetcdwDataSampleDivider ();

      //## Attribute: cdwOverSampleDivider%3E3100E800F7
      static const DWORD GetcdwOverSampleDivider ();

      //## Attribute: cdwDataStackDivider%3E310100001D
      //	DESCRIPTION
      //	IFM and Laser Data / Sample (WC IRQ)
      static const DWORD GetcdwDataStackDivider ();

      //## Attribute: cdLaserZeroCrossDistance%3E54B13F00AB
      static const double GetcdLaserZeroCrossDistance ();

      //## Attribute: dwIsrSampleTime%3E5227940290
      //	DESCRIPTION:
      //	interrupt service routine (wedge control) sample time
      //
      //	UNIT:
      //	[ns]
      static const DWORD GetdwIsrSampleTime ();

  public:
    // Additional Public Declarations
      //## begin CHITDefinitions%3E4BB85401C5.public preserve=yes
      //## end CHITDefinitions%3E4BB85401C5.public

  protected:
    // Additional Protected Declarations
      //## begin CHITDefinitions%3E4BB85401C5.protected preserve=yes
      //## end CHITDefinitions%3E4BB85401C5.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: cMemorySize%3FABB366000F
      //## begin CHITDefinitions::cMemorySize%3FABB366000F.attr preserve=no  private: static char[256] {U} 
      static char m_cMemorySize[256];
      //## end CHITDefinitions::cMemorySize%3FABB366000F.attr

      //## begin CHITDefinitions::cdwPCIFrequenz%3E30F1D000C6.attr preserve=no  public: static DWORD {UC} 33334919
      static const DWORD  m_cdwPCIFrequenz;
      //## end CHITDefinitions::cdwPCIFrequenz%3E30F1D000C6.attr

      //## begin CHITDefinitions::cdwDataSampleDivider%3E3100F7009A.attr preserve=no  public: static DWORD {UC} 64
      static const DWORD  m_cdwDataSampleDivider;
      //## end CHITDefinitions::cdwDataSampleDivider%3E3100F7009A.attr

      //## begin CHITDefinitions::cdwOverSampleDivider%3E3100E800F7.attr preserve=no  public: static DWORD {UC} 6
      static const DWORD  m_cdwOverSampleDivider;
      //## end CHITDefinitions::cdwOverSampleDivider%3E3100E800F7.attr

      //## begin CHITDefinitions::cdwDataStackDivider%3E310100001D.attr preserve=no  public: static DWORD {UC} DATA_STACK_DIVIDER
      static const DWORD  m_cdwDataStackDivider;
      //## end CHITDefinitions::cdwDataStackDivider%3E310100001D.attr

      //## begin CHITDefinitions::cdLaserZeroCrossDistance%3E54B13F00AB.attr preserve=no  public: static double {UC} 0.0000121
      static const double  m_cdLaserZeroCrossDistance;
      //## end CHITDefinitions::cdLaserZeroCrossDistance%3E54B13F00AB.attr

      //## begin CHITDefinitions::dwIsrSampleTime%3E5227940290.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwIsrSampleTime;
      //## end CHITDefinitions::dwIsrSampleTime%3E5227940290.attr

    // Additional Private Declarations
      //## begin CHITDefinitions%3E4BB85401C5.private preserve=yes
      //## end CHITDefinitions%3E4BB85401C5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHITDefinitions%3E4BB85401C5.implementation preserve=yes
      //## end CHITDefinitions%3E4BB85401C5.implementation

};

//## begin CHITDefinitions%3E4BB85401C5.postscript preserve=yes
//## end CHITDefinitions%3E4BB85401C5.postscript

//## begin CHIIOCPCISettings%3E9D051D01C5.preface preserve=yes
//## end CHIIOCPCISettings%3E9D051D01C5.preface

//## Class: CHIIOCPCISettings%3E9D051D01C5
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHIIOCPCISettings 
{
  //## begin CHIIOCPCISettings%3E9D051D01C5.initialDeclarations preserve=yes
  //## end CHIIOCPCISettings%3E9D051D01C5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHIIOCPCISettings%1050478287
      CHIIOCPCISettings (DWORD p_dwPCIReadBaseAdr = 0, DWORD p_dwPCIWriteBaseAdr = 0, DWORD p_dwSysintr = 0, DWORD p_IntMask = 0);

    //## Storage Management Operations (generated)
      static void * operator new(size_t size);

      static void operator delete(void *object);


    //## Other Operations (specified)
      //## Operation: GetpPCIWriteBasePtr%1064568409
      BYTE* GetpPCIWriteBasePtr ();

      //## Operation: GetpPCIUserWriteBasePtr%1064568411
      BYTE* GetpPCIUserWriteBasePtr ();

      //## Operation: GetpPCIReadBasePtr%1064913332
      BYTE* GetpPCIReadBasePtr ();

      //## Operation: GetpPCIUserReadBasePtr%1064913333
      BYTE* GetpPCIUserReadBasePtr ();

      //## Operation: GetpPCIReadIFMDataAdr%1076310548
      BYTE* GetpPCIReadIFMDataAdr ();

      //## Operation: GetpPCIReadLaserDataAdr%1076310549
      BYTE* GetpPCIReadLaserDataAdr ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: clpAdrPCIMasterTransferMemory%3EAD1F7F00DA
      static const LPVOID GetclpAdrPCIMasterTransferMemory ();

      //## Attribute: cdwAdrOffsetFpgaArtNr%402762C10109
      static const DWORD GetcdwAdrOffsetFpgaArtNr ();

      //## Attribute: cdwAdrOffsetFpgaSwVersion%402762E703B9
      //	DESCRIPTION:
      //	address offset (in DWORD) FPGA Software Version
      static const DWORD GetcdwAdrOffsetFpgaSwVersion ();

      //## Attribute: cdwNumberOfDWordFpgaArtNr%4027A72C02AF
      static const DWORD GetcdwNumberOfDWordFpgaArtNr ();

      //## Attribute: cdwNumberOfDWordFpgaSwVersion%4027A7540000
      static const DWORD GetcdwNumberOfDWordFpgaSwVersion ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E9D084203C8
      //## Role: CHIIOCPCISettings::dwSysintr%3E9D084302B0
      DWORD GetdwSysintr ();
      void SetdwSysintr (DWORD value);

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E9D09290157
      //## Role: CHIIOCPCISettings::IntMask%3E9D092A00AC
      DWORD GetIntMask ();
      void SetIntMask (DWORD value);

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F74063800DA
      //## Role: CHIIOCPCISettings::dwWriteDataBaseOffset%3F74063802CF
      DWORD GetdwWriteDataBaseOffset ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7408B9032C
      //## Role: CHIIOCPCISettings::dwReadDataTransferDWordSize%3F7408BA0233
      DWORD GetdwReadDataTransferDWordSize ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F74094C00DA
      //## Role: CHIIOCPCISettings::dwOffsetInterruptClear%3F74094C03D9
      DWORD GetdwOffsetInterruptClear ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7996910222
      //## Role: CHIIOCPCISettings::dwOffsetIrqValue%3F7996920178
      DWORD GetdwOffsetIrqValue ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7A8CB2003E
      //## Role: CHIIOCPCISettings::dwWriteDataTransferDWordSize%3F7A8CB203BA
      DWORD GetdwWriteDataTransferDWordSize ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7A8D7B0196
      //## Role: CHIIOCPCISettings::dwReadDataBaseOffset%3F7A8D7B039A
      DWORD GetdwReadDataBaseOffset ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%40274B7C0261
      //## Role: CHIIOCPCISettings::dwReadIFMDataAdrOffset%40274B7D00FB
      DWORD GetdwReadIFMDataAdrOffset ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%40274B7F036B
      //## Role: CHIIOCPCISettings::dwReadLaserDataAdrOffset%40274B8001F5
      DWORD GetdwReadLaserDataAdrOffset ();

    // Additional Public Declarations
      //## begin CHIIOCPCISettings%3E9D051D01C5.public preserve=yes
      //## end CHIIOCPCISettings%3E9D051D01C5.public

  protected:
    // Additional Protected Declarations
      //## begin CHIIOCPCISettings%3E9D051D01C5.protected preserve=yes
      //## end CHIIOCPCISettings%3E9D051D01C5.protected

  private:
    // Data Members for Class Attributes

      //## begin CHIIOCPCISettings::clpAdrPCIMasterTransferMemory%3EAD1F7F00DA.attr preserve=no  public: static LPVOID {UC} (LPVOID)0x81420000
      static const LPVOID  m_clpAdrPCIMasterTransferMemory;
      //## end CHIIOCPCISettings::clpAdrPCIMasterTransferMemory%3EAD1F7F00DA.attr

      //## Attribute: cMemorySize%3F1D2C4401F4
      //## begin CHIIOCPCISettings::cMemorySize%3F1D2C4401F4.attr preserve=no  private: static char[256] {U} 
      static char m_cMemorySize[256];
      //## end CHIIOCPCISettings::cMemorySize%3F1D2C4401F4.attr

      //## begin CHIIOCPCISettings::cdwAdrOffsetFpgaArtNr%402762C10109.attr preserve=no  public: static DWORD {UC} 0x0
      static const DWORD  m_cdwAdrOffsetFpgaArtNr;
      //## end CHIIOCPCISettings::cdwAdrOffsetFpgaArtNr%402762C10109.attr

      //## begin CHIIOCPCISettings::cdwAdrOffsetFpgaSwVersion%402762E703B9.attr preserve=no  public: static DWORD {UC} 0x4
      static const DWORD  m_cdwAdrOffsetFpgaSwVersion;
      //## end CHIIOCPCISettings::cdwAdrOffsetFpgaSwVersion%402762E703B9.attr

      //## begin CHIIOCPCISettings::cdwNumberOfDWordFpgaArtNr%4027A72C02AF.attr preserve=no  public: static DWORD {UC} 0x2
      static const DWORD  m_cdwNumberOfDWordFpgaArtNr;
      //## end CHIIOCPCISettings::cdwNumberOfDWordFpgaArtNr%4027A72C02AF.attr

      //## begin CHIIOCPCISettings::cdwNumberOfDWordFpgaSwVersion%4027A7540000.attr preserve=no  public: static DWORD {UC} 0x2
      static const DWORD  m_cdwNumberOfDWordFpgaSwVersion;
      //## end CHIIOCPCISettings::cdwNumberOfDWordFpgaSwVersion%4027A7540000.attr

    // Data Members for Associations

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E9D07A0006D
      //## Role: CHIIOCPCISettings::dwPCIWriteBaseAdr%3E9D07A002B0
      //	DESCRIPTION:
      //	PCI base address
      //## begin CHIIOCPCISettings::dwPCIWriteBaseAdr%3E9D07A002B0.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwPCIWriteBaseAdr;
      //## end CHIIOCPCISettings::dwPCIWriteBaseAdr%3E9D07A002B0.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E9D084203C8
      //## begin CHIIOCPCISettings::dwSysintr%3E9D084302B0.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwSysintr;
      //## end CHIIOCPCISettings::dwSysintr%3E9D084302B0.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E9D09290157
      //## begin CHIIOCPCISettings::IntMask%3E9D092A00AC.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_IntMask;
      //## end CHIIOCPCISettings::IntMask%3E9D092A00AC.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F74063800DA
      //## begin CHIIOCPCISettings::dwWriteDataBaseOffset%3F74063802CF.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwWriteDataBaseOffset;
      //## end CHIIOCPCISettings::dwWriteDataBaseOffset%3F74063802CF.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7408B9032C
      //## begin CHIIOCPCISettings::dwReadDataTransferDWordSize%3F7408BA0233.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwReadDataTransferDWordSize;
      //## end CHIIOCPCISettings::dwReadDataTransferDWordSize%3F7408BA0233.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F74094C00DA
      //## begin CHIIOCPCISettings::dwOffsetInterruptClear%3F74094C03D9.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwOffsetInterruptClear;
      //## end CHIIOCPCISettings::dwOffsetInterruptClear%3F74094C03D9.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7996910222
      //## begin CHIIOCPCISettings::dwOffsetIrqValue%3F7996920178.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwOffsetIrqValue;
      //## end CHIIOCPCISettings::dwOffsetIrqValue%3F7996920178.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7A79A900EA
      //## Role: CHIIOCPCISettings::dwPCIReadBaseAdr%3F7A79AA00AC
      //## begin CHIIOCPCISettings::dwPCIReadBaseAdr%3F7A79AA00AC.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwPCIReadBaseAdr;
      //## end CHIIOCPCISettings::dwPCIReadBaseAdr%3F7A79AA00AC.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7A8CB2003E
      //## begin CHIIOCPCISettings::dwWriteDataTransferDWordSize%3F7A8CB203BA.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwWriteDataTransferDWordSize;
      //## end CHIIOCPCISettings::dwWriteDataTransferDWordSize%3F7A8CB203BA.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3F7A8D7B0196
      //## begin CHIIOCPCISettings::dwReadDataBaseOffset%3F7A8D7B039A.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwReadDataBaseOffset;
      //## end CHIIOCPCISettings::dwReadDataBaseOffset%3F7A8D7B039A.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%40274B7C0261
      //## begin CHIIOCPCISettings::dwReadIFMDataAdrOffset%40274B7D00FB.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwReadIFMDataAdrOffset;
      //## end CHIIOCPCISettings::dwReadIFMDataAdrOffset%40274B7D00FB.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%40274B7F036B
      //## begin CHIIOCPCISettings::dwReadLaserDataAdrOffset%40274B8001F5.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwReadLaserDataAdrOffset;
      //## end CHIIOCPCISettings::dwReadLaserDataAdrOffset%40274B8001F5.role

    // Additional Private Declarations
      //## begin CHIIOCPCISettings%3E9D051D01C5.private preserve=yes
      //## end CHIIOCPCISettings%3E9D051D01C5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIIOCPCISettings%3E9D051D01C5.implementation preserve=yes
      //## end CHIIOCPCISettings%3E9D051D01C5.implementation

};

//## begin CHIIOCPCISettings%3E9D051D01C5.postscript preserve=yes
//## end CHIIOCPCISettings%3E9D051D01C5.postscript

//## begin CHIIOCSetWCProfile%3F93FCF600DA.preface preserve=yes
//## end CHIIOCSetWCProfile%3F93FCF600DA.preface

//## Class: CHIIOCSetWCProfile%3F93FCF600DA
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHIIOCSetWCProfile 
{
  //## begin CHIIOCSetWCProfile%3F93FCF600DA.initialDeclarations preserve=yes
  //## end CHIIOCSetWCProfile%3F93FCF600DA.initialDeclarations

  public:
    //## Constructors (generated)
      CHIIOCSetWCProfile(const CHIIOCSetWCProfile &right);

    //## Constructors (specified)
      //## Operation: CHIIOCSetWCProfile%1066663001
      CHIIOCSetWCProfile (DWORD p_dwScanMode = 0, DWORD p_dwRefDistance2 = 0);

    //## Storage Management Operations (generated)
      static void * operator new(size_t size);

      static void operator delete(void *object);

    //## Assignment Operation (generated)
      const CHIIOCSetWCProfile & operator=(const CHIIOCSetWCProfile &right);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwScanMode%3FBC8F4D00CB
      //	DESCRIPTION
      //	half or full scan
      //
      //	0: half scan
      //	1: full scan
      const DWORD GetdwScanMode () const;
      void SetdwScanMode (DWORD value);

      //## Attribute: dwRefDistance2%3FD5C17401A5
      //	UNIT: [Laser Zero Cross Counts]
      const DWORD GetdwRefDistance2 () const;
      void SetdwRefDistance2 (DWORD value);

    // Data Members for Class Attributes

      //## begin CHIIOCSetWCProfile::dwScanMode%3FBC8F4D00CB.attr preserve=no  public: DWORD {U} 
      DWORD m_dwScanMode;
      //## end CHIIOCSetWCProfile::dwScanMode%3FBC8F4D00CB.attr

      //## begin CHIIOCSetWCProfile::dwRefDistance2%3FD5C17401A5.attr preserve=no  public: DWORD {U} 
      DWORD m_dwRefDistance2;
      //## end CHIIOCSetWCProfile::dwRefDistance2%3FD5C17401A5.attr

    // Additional Public Declarations
      //## begin CHIIOCSetWCProfile%3F93FCF600DA.public preserve=yes
      //## end CHIIOCSetWCProfile%3F93FCF600DA.public

  protected:
    // Additional Protected Declarations
      //## begin CHIIOCSetWCProfile%3F93FCF600DA.protected preserve=yes
      //## end CHIIOCSetWCProfile%3F93FCF600DA.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: cMemorySize%3F93FD1F034B
      //## begin CHIIOCSetWCProfile::cMemorySize%3F93FD1F034B.attr preserve=no  private: static char[256] {U} 
      static char m_cMemorySize[256];
      //## end CHIIOCSetWCProfile::cMemorySize%3F93FD1F034B.attr

    // Additional Private Declarations
      //## begin CHIIOCSetWCProfile%3F93FCF600DA.private preserve=yes
      //## end CHIIOCSetWCProfile%3F93FCF600DA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIIOCSetWCProfile%3F93FCF600DA.implementation preserve=yes
      //## end CHIIOCSetWCProfile%3F93FCF600DA.implementation

};

//## begin CHIIOCSetWCProfile%3F93FCF600DA.postscript preserve=yes
//## end CHIIOCSetWCProfile%3F93FCF600DA.postscript

//## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.preface preserve=yes
//## end CHIIOCSetWCConfiguration%3F94C3BB01D4.preface

//## Class: CHIIOCSetWCConfiguration%3F94C3BB01D4
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHIIOCSetWCConfiguration 
{
  //## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.initialDeclarations preserve=yes
  //## end CHIIOCSetWCConfiguration%3F94C3BB01D4.initialDeclarations

  public:
    //## Constructors (generated)
      CHIIOCSetWCConfiguration(const CHIIOCSetWCConfiguration &right);

    //## Constructors (specified)
      //## Operation: CHIIOCSetWCConfiguration%1066714379
      CHIIOCSetWCConfiguration (DWORD p_dwNomVelocity = 0, DWORD p_dwNomAcc = 0, DWORD p_dwIniAcc = 0, DWORD p_dwAccDistance = 0, DWORD p_dwNomDec = 0, DWORD p_dwRestDec = 0, DWORD p_dwDecDistance = 0, DWORD p_dwWedgeControllerVelocityEdge = 0, DWORD p_dwStaticFrictionForward = 0, DWORD p_dwStaticFrictionBackward = 0, DWORD p_dwVelocityWarnHighRange = 0, DWORD p_dwVelocityWarnLowRange = 0, DWORD p_dwVelocityErrorHighRange = 0, DWORD p_dwVelocityErrorLowRange = 0, DWORD p_dwForwardStartDistance = 0, DWORD p_dwForwardEndDistance = 0, DWORD p_dwMeasuringDistance = 0, DWORD p_dwBackwardStartDistance = 0, DWORD p_dwRefDistance1 = 0, DWORD p_dwWC_Kp = 0, DWORD p_dwWC_Ki = 0, DWORD p_dwWC_Kd = 0, DWORD p_dwWC_DACConvFactor = 0, DWORD p_dwWC_Ydac = 0, DWORD p_dwDACLimitUp = 0, DWORD p_dwDACLimitDown = 0, DWORD p_dwDACLimitSlr = 0, DWORD p_dwRunAfterTimeTicks = 0, DWORD p_dwAccStandBy = 0, DWORD p_dwMaxCurrentTimeTicks = 0);

    //## Storage Management Operations (generated)
      static void * operator new(size_t size);

      static void operator delete(void *object);

    //## Assignment Operation (generated)
      const CHIIOCSetWCConfiguration & operator=(const CHIIOCSetWCConfiguration &right);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwNomVelocity%3FD5C156000F
      //	DESCRIPTION
      //	Nominal velocity for the wedge control
      //
      //	UNIT
      //	[Hz]
      const DWORD GetdwNomVelocity () const;

      //## Attribute: dwNomAcc%3FD5C15502AF
      //	DESCRIPTION
      //	nominal acceleration increase per ISR sample for the
      //	wedge control
      //
      //	UNIT
      //	[Hz/s]
      const DWORD GetdwNomAcc () const;

      //## Attribute: dwIniAcc%3FD5C15502EE
      //	DESCRIPTION
      //	nominal initialization acceleration for the wedge control
      //
      //	UNIT
      //	[Hz/s]
      const DWORD GetdwIniAcc () const;

      //## Attribute: dwAccDistance%3FD5C155031C
      const DWORD GetdwAccDistance () const;

      //## Attribute: dwNomDec%3FD5C155035B
      //	DESCRIPTION
      //	nominal deceleration increase per ISR sample for the
      //	wedge control
      //
      //	UNIT
      //	[Hz/s]
      const DWORD GetdwNomDec () const;

      //## Attribute: dwRestDec%3FD5C155038A
      //	DESCRIPTION
      //	nominal rest counts deceleration for the wedge control
      //
      //	UNIT
      //	[Hz/s]
      const DWORD GetdwRestDec () const;

      //## Attribute: dwDecDistance%3FD5C15503B9
      const DWORD GetdwDecDistance () const;

      //## Attribute: dwWedgeControllerVelocityEdge%3FB49FCD032C
      //	DESCRIPTION
      //	velocity limit, which the wedge controller switch off
      //
      //	UNIT: [Hz]
      const DWORD GetdwWedgeControllerVelocityEdge () const;

      //## Attribute: dwStaticFrictionForward%402B9D26005D
      //	DESCRIPTION
      //	init value to overcome the static friction during the
      //	forward acceleration
      //	(only first acc, and max until Parameter   "p_dwWedge
      //	ControllerVelocityEdge")
      //
      //	UNIT: [DAC Digit]
      const DWORD GetdwStaticFrictionForward () const;

      //## Attribute: dwStaticFrictionBackward%402B9D26008C
      //	DESCRIPTION
      //	init value to overcome the static friction during the
      //	forward acceleration
      //	(only first acc, and max until Parameter   "p_dwWedge
      //	ControllerVelocityEdge")
      //
      //	UNIT: [DAC Digit]
      const DWORD GetdwStaticFrictionBackward () const;

      //## Attribute: dwVelocityWarnHighRange%3F94C3E7032C
      //	UNIT: [Hz]
      const DWORD GetdwVelocityWarnHighRange () const;
      void SetdwVelocityWarnHighRange (DWORD value);

      //## Attribute: dwVelocityWarnLowRange%3F94C3E7033C
      //	UNIT: [Hz]
      const DWORD GetdwVelocityWarnLowRange () const;
      void SetdwVelocityWarnLowRange (DWORD value);

      //## Attribute: dwVelocityErrorHighRange%3F94C3E7035B
      //	UNIT: [Hz]
      const DWORD GetdwVelocityErrorHighRange () const;
      void SetdwVelocityErrorHighRange (DWORD value);

      //## Attribute: dwVelocityErrorLowRange%3F94C3E7036B
      //	UNIT: [Hz]
      const DWORD GetdwVelocityErrorLowRange () const;
      void SetdwVelocityErrorLowRange (DWORD value);

      //## Attribute: dwForwardStartDistance%3F94C3E8002E
      //	UNIT: [Laser Zero Cross Counts]
      const DWORD GetdwForwardStartDistance () const;
      void SetdwForwardStartDistance (DWORD value);

      //## Attribute: dwForwardEndDistance%3F94C3E8003E
      //	UNIT: [Laser Zero Cross Counts]
      const DWORD GetdwForwardEndDistance () const;
      void SetdwForwardEndDistance (DWORD value);

      //## Attribute: dwMeasuringDistance%3F94C3E8004E
      //	UNIT: [Laser Zero Cross Counts]
      const DWORD GetdwMeasuringDistance () const;
      void SetdwMeasuringDistance (DWORD value);

      //## Attribute: dwBackwardStartDistance%3F94C3E8006D
      //	UNIT: [Laser Zero Cross Counts]
      const DWORD GetdwBackwardStartDistance () const;
      void SetdwBackwardStartDistance (DWORD value);

      //## Attribute: dwRefDistance1%3F94C3E8007D
      //	UNIT: [Laser Zero Cross Counts]
      const DWORD GetdwRefDistance1 () const;
      void SetdwRefDistance1 (DWORD value);

      //## Attribute: dwWC_Kp%3F94C3E8009C
      //	UNIT: [-]
      const DWORD GetdwWC_Kp () const;
      void SetdwWC_Kp (DWORD value);

      //## Attribute: dwWC_Ki%3F94C3E800BB
      //	UNIT: [-]
      const DWORD GetdwWC_Ki () const;
      void SetdwWC_Ki (DWORD value);

      //## Attribute: dwWC_Kd%3F94C3E800CB
      //	UNIT: [-]
      const DWORD GetdwWC_Kd () const;
      void SetdwWC_Kd (DWORD value);

      //## Attribute: dwWC_DACConvFactor%3F97DE13004E
      //	DESCRIPTION:
      //	DAC conersion factor
      //
      //	UNIT: [-]
      const DWORD GetdwWC_DACConvFactor () const;
      void SetdwWC_DACConvFactor (DWORD value);

      //## Attribute: dwWC_Ydac%3F952D3C002E
      //	DESCRIPTION:
      //	DAC Offset correction factor
      //
      //	UNIT: [Digit]
      const DWORD GetdwWC_Ydac () const;
      void SetdwWC_Ydac (DWORD value);

      //## Attribute: dwDACLimitUp%3F94C3E800DA
      //	UNIT: [Digit]
      //
      //	(DAC MAX5712 12 Bit digits)
      const DWORD GetdwDACLimitUp () const;
      void SetdwDACLimitUp (DWORD value);

      //## Attribute: dwDACLimitDown%3F94C3E800EA
      //	UNIT: [Digit]
      //
      //	(DAC MAX5712 12 Bit digits)
      const DWORD GetdwDACLimitDown () const;
      void SetdwDACLimitDown (DWORD value);

      //## Attribute: dwDACLimitSlr%3F952DA60167
      //	DESCRIPTION:
      //	Slew Rate Limit (dt/T)
      //
      //	UNIT: [Digit]
      //
      //	(DAC MAX5712 12 Bit digits)
      const DWORD GetdwDACLimitSlr () const;
      void SetdwDACLimitSlr (DWORD value);

      //## Attribute: dwRunAfterTimeTicks%3F94C3E800FA
      //	UNIT: [ISR Time Ticks]
      const DWORD GetdwRunAfterTimeTicks () const;
      void SetdwRunAfterTimeTicks (DWORD value);

      //## Attribute: dwAccStandBy%3F94C3E80119
      //	UNIT: [1/s^2]
      const DWORD GetdwAccStandBy () const;
      void SetdwAccStandBy (DWORD value);

      //## Attribute: dwMaxCurrentTimeTicks%402B9D6D0232
      //	DESCRIPTION
      //	Max.Time, in which the max electric current may be apply
      //	at the wedge drive
      //
      //	UNIT: [ISR Time Ticks]
      const DWORD GetdwMaxCurrentTimeTicks () const;

    // Data Members for Class Attributes

      //## begin CHIIOCSetWCConfiguration::dwNomVelocity%3FD5C156000F.attr preserve=no  public: DWORD {U} 
      DWORD m_dwNomVelocity;
      //## end CHIIOCSetWCConfiguration::dwNomVelocity%3FD5C156000F.attr

      //## begin CHIIOCSetWCConfiguration::dwNomAcc%3FD5C15502AF.attr preserve=no  public: DWORD {U} 
      DWORD m_dwNomAcc;
      //## end CHIIOCSetWCConfiguration::dwNomAcc%3FD5C15502AF.attr

      //## begin CHIIOCSetWCConfiguration::dwIniAcc%3FD5C15502EE.attr preserve=no  public: DWORD {U} 
      DWORD m_dwIniAcc;
      //## end CHIIOCSetWCConfiguration::dwIniAcc%3FD5C15502EE.attr

      //## begin CHIIOCSetWCConfiguration::dwAccDistance%3FD5C155031C.attr preserve=no  public: DWORD {U} 
      DWORD m_dwAccDistance;
      //## end CHIIOCSetWCConfiguration::dwAccDistance%3FD5C155031C.attr

      //## begin CHIIOCSetWCConfiguration::dwNomDec%3FD5C155035B.attr preserve=no  public: DWORD {U} 
      DWORD m_dwNomDec;
      //## end CHIIOCSetWCConfiguration::dwNomDec%3FD5C155035B.attr

      //## begin CHIIOCSetWCConfiguration::dwRestDec%3FD5C155038A.attr preserve=no  public: DWORD {U} 
      DWORD m_dwRestDec;
      //## end CHIIOCSetWCConfiguration::dwRestDec%3FD5C155038A.attr

      //## begin CHIIOCSetWCConfiguration::dwDecDistance%3FD5C15503B9.attr preserve=no  public: DWORD {U} 
      DWORD m_dwDecDistance;
      //## end CHIIOCSetWCConfiguration::dwDecDistance%3FD5C15503B9.attr

      //## begin CHIIOCSetWCConfiguration::dwWedgeControllerVelocityEdge%3FB49FCD032C.attr preserve=no  public: DWORD {U} 
      DWORD m_dwWedgeControllerVelocityEdge;
      //## end CHIIOCSetWCConfiguration::dwWedgeControllerVelocityEdge%3FB49FCD032C.attr

      //## begin CHIIOCSetWCConfiguration::dwStaticFrictionForward%402B9D26005D.attr preserve=no  public: DWORD {U} 
      DWORD m_dwStaticFrictionForward;
      //## end CHIIOCSetWCConfiguration::dwStaticFrictionForward%402B9D26005D.attr

      //## begin CHIIOCSetWCConfiguration::dwStaticFrictionBackward%402B9D26008C.attr preserve=no  public: DWORD {U} 
      DWORD m_dwStaticFrictionBackward;
      //## end CHIIOCSetWCConfiguration::dwStaticFrictionBackward%402B9D26008C.attr

      //## begin CHIIOCSetWCConfiguration::dwVelocityWarnHighRange%3F94C3E7032C.attr preserve=no  public: DWORD {U} 
      DWORD m_dwVelocityWarnHighRange;
      //## end CHIIOCSetWCConfiguration::dwVelocityWarnHighRange%3F94C3E7032C.attr

      //## begin CHIIOCSetWCConfiguration::dwVelocityWarnLowRange%3F94C3E7033C.attr preserve=no  public: DWORD {U} 
      DWORD m_dwVelocityWarnLowRange;
      //## end CHIIOCSetWCConfiguration::dwVelocityWarnLowRange%3F94C3E7033C.attr

      //## begin CHIIOCSetWCConfiguration::dwVelocityErrorHighRange%3F94C3E7035B.attr preserve=no  public: DWORD {U} 
      DWORD m_dwVelocityErrorHighRange;
      //## end CHIIOCSetWCConfiguration::dwVelocityErrorHighRange%3F94C3E7035B.attr

      //## begin CHIIOCSetWCConfiguration::dwVelocityErrorLowRange%3F94C3E7036B.attr preserve=no  public: DWORD {U} 
      DWORD m_dwVelocityErrorLowRange;
      //## end CHIIOCSetWCConfiguration::dwVelocityErrorLowRange%3F94C3E7036B.attr

      //## begin CHIIOCSetWCConfiguration::dwForwardStartDistance%3F94C3E8002E.attr preserve=no  public: DWORD {U} 
      DWORD m_dwForwardStartDistance;
      //## end CHIIOCSetWCConfiguration::dwForwardStartDistance%3F94C3E8002E.attr

      //## begin CHIIOCSetWCConfiguration::dwForwardEndDistance%3F94C3E8003E.attr preserve=no  public: DWORD {U} 
      DWORD m_dwForwardEndDistance;
      //## end CHIIOCSetWCConfiguration::dwForwardEndDistance%3F94C3E8003E.attr

      //## begin CHIIOCSetWCConfiguration::dwMeasuringDistance%3F94C3E8004E.attr preserve=no  public: DWORD {U} 
      DWORD m_dwMeasuringDistance;
      //## end CHIIOCSetWCConfiguration::dwMeasuringDistance%3F94C3E8004E.attr

      //## begin CHIIOCSetWCConfiguration::dwBackwardStartDistance%3F94C3E8006D.attr preserve=no  public: DWORD {U} 
      DWORD m_dwBackwardStartDistance;
      //## end CHIIOCSetWCConfiguration::dwBackwardStartDistance%3F94C3E8006D.attr

      //## begin CHIIOCSetWCConfiguration::dwRefDistance1%3F94C3E8007D.attr preserve=no  public: DWORD {U} 
      DWORD m_dwRefDistance1;
      //## end CHIIOCSetWCConfiguration::dwRefDistance1%3F94C3E8007D.attr

      //## begin CHIIOCSetWCConfiguration::dwWC_Kp%3F94C3E8009C.attr preserve=no  public: DWORD {U} 
      DWORD m_dwWC_Kp;
      //## end CHIIOCSetWCConfiguration::dwWC_Kp%3F94C3E8009C.attr

      //## begin CHIIOCSetWCConfiguration::dwWC_Ki%3F94C3E800BB.attr preserve=no  public: DWORD {U} 
      DWORD m_dwWC_Ki;
      //## end CHIIOCSetWCConfiguration::dwWC_Ki%3F94C3E800BB.attr

      //## begin CHIIOCSetWCConfiguration::dwWC_Kd%3F94C3E800CB.attr preserve=no  public: DWORD {U} 
      DWORD m_dwWC_Kd;
      //## end CHIIOCSetWCConfiguration::dwWC_Kd%3F94C3E800CB.attr

      //## begin CHIIOCSetWCConfiguration::dwWC_DACConvFactor%3F97DE13004E.attr preserve=no  public: DWORD {U} 
      DWORD m_dwWC_DACConvFactor;
      //## end CHIIOCSetWCConfiguration::dwWC_DACConvFactor%3F97DE13004E.attr

      //## begin CHIIOCSetWCConfiguration::dwWC_Ydac%3F952D3C002E.attr preserve=no  public: DWORD {U} 
      DWORD m_dwWC_Ydac;
      //## end CHIIOCSetWCConfiguration::dwWC_Ydac%3F952D3C002E.attr

      //## begin CHIIOCSetWCConfiguration::dwDACLimitUp%3F94C3E800DA.attr preserve=no  public: DWORD {U} 
      DWORD m_dwDACLimitUp;
      //## end CHIIOCSetWCConfiguration::dwDACLimitUp%3F94C3E800DA.attr

      //## begin CHIIOCSetWCConfiguration::dwDACLimitDown%3F94C3E800EA.attr preserve=no  public: DWORD {U} 
      DWORD m_dwDACLimitDown;
      //## end CHIIOCSetWCConfiguration::dwDACLimitDown%3F94C3E800EA.attr

      //## begin CHIIOCSetWCConfiguration::dwDACLimitSlr%3F952DA60167.attr preserve=no  public: DWORD {U} 
      DWORD m_dwDACLimitSlr;
      //## end CHIIOCSetWCConfiguration::dwDACLimitSlr%3F952DA60167.attr

      //## begin CHIIOCSetWCConfiguration::dwRunAfterTimeTicks%3F94C3E800FA.attr preserve=no  public: DWORD {U} 
      DWORD m_dwRunAfterTimeTicks;
      //## end CHIIOCSetWCConfiguration::dwRunAfterTimeTicks%3F94C3E800FA.attr

      //## begin CHIIOCSetWCConfiguration::dwAccStandBy%3F94C3E80119.attr preserve=no  public: DWORD {U} 
      DWORD m_dwAccStandBy;
      //## end CHIIOCSetWCConfiguration::dwAccStandBy%3F94C3E80119.attr

      //## begin CHIIOCSetWCConfiguration::dwMaxCurrentTimeTicks%402B9D6D0232.attr preserve=no  public: DWORD {U} 
      DWORD m_dwMaxCurrentTimeTicks;
      //## end CHIIOCSetWCConfiguration::dwMaxCurrentTimeTicks%402B9D6D0232.attr

    // Additional Public Declarations
      //## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.public preserve=yes
      //## end CHIIOCSetWCConfiguration%3F94C3BB01D4.public

  protected:
    // Additional Protected Declarations
      //## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.protected preserve=yes
      //## end CHIIOCSetWCConfiguration%3F94C3BB01D4.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: cMemorySize%3F94C3E7031C
      //## begin CHIIOCSetWCConfiguration::cMemorySize%3F94C3E7031C.attr preserve=no  private: static char[256] {U} 
      static char m_cMemorySize[256];
      //## end CHIIOCSetWCConfiguration::cMemorySize%3F94C3E7031C.attr

    // Additional Private Declarations
      //## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.private preserve=yes
      //## end CHIIOCSetWCConfiguration%3F94C3BB01D4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.implementation preserve=yes
      //## end CHIIOCSetWCConfiguration%3F94C3BB01D4.implementation

};

//## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.postscript preserve=yes
//## end CHIIOCSetWCConfiguration%3F94C3BB01D4.postscript

//## begin CHITDACMAX5712%3FAB9F6A01B5.preface preserve=yes
//## end CHITDACMAX5712%3FAB9F6A01B5.preface

//## Class: CHITDACMAX5712%3FAB9F6A01B5
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHITDACMAX5712 
{
  //## begin CHITDACMAX5712%3FAB9F6A01B5.initialDeclarations preserve=yes
  //## end CHITDACMAX5712%3FAB9F6A01B5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHITDACMAX5712%1068189085
      CHITDACMAX5712 ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cdwWakeUpValue%3FABA043001F
      //	DESCRPTION:
      //	DAC wake up value
      //
      //	UNIT:
      //	DAC counts
      static const DWORD GetcdwWakeUpValue ();

      //## Attribute: cdwWaitTimePwrEnable%3FABA0A30222
      //	DESCRPTION:
      //	DAC wait time after power on
      //
      //	UNIT:
      //	[us]
      static const DWORD GetcdwWaitTimePwrEnable ();

      //## Attribute: cdwWaitTimeCalibration%3FABA0F50251
      //	DESCRPTION:
      //	DAC wait time after wake up
      //
      //	UNIT:
      //	[us]
      static const DWORD GetcdwWaitTimeCalibration ();

      //## Attribute: cdwWaitTimeAutoCalibration%3FBCBAFE00AB
      //	DESCRPTION:
      //	DAC wait time for auto offset calibration (inc. or dec.
      //	between DAC counts)
      //
      //	UNIT:
      //	[ms]
      static const DWORD GetcdwWaitTimeAutoCalibration ();

      //## Attribute: cdwEmergencyStopDAC%3FABB98D0251
      //	DESCRPTION:
      //	DAC emergency value -> DAC interrupt the current
      //
      //	UNIT:
      //	DAC counts
      static const DWORD GetcdwEmergencyStopDAC ();

      //## Attribute: cdwDefaultOffsetValue%3FB1F2B80280
      //	DESCRPTION:
      //	DAC default offset value 2416
      //
      //
      //	UNIT:
      //	DAC counts
      static const DWORD GetcdwDefaultOffsetValue ();

      //## Attribute: cdwLowerLimit%3FB39C96007D
      //	DESCRPTION:
      //	DAC lower limit
      //
      //
      //	UNIT:
      //	DAC counts
      static const DWORD GetcdwLowerLimit ();

      //## Attribute: cdwUpperLimit%3FB39CFA036B
      //	DESCRPTION:
      //	DAC upper limit (12Bit value)
      //
      //
      //	UNIT:
      //	DAC counts
      static const DWORD GetcdwUpperLimit ();

      //## Attribute: cdwMaxOffsetCalibError%3FBDD364033C
      //	DESCRPTION:
      //	max. offset error
      //
      //
      //	UNIT:
      //	DAC counts
      static const DWORD GetcdwMaxOffsetCalibError ();

    // Additional Public Declarations
      //## begin CHITDACMAX5712%3FAB9F6A01B5.public preserve=yes
      //## end CHITDACMAX5712%3FAB9F6A01B5.public

  protected:
    // Additional Protected Declarations
      //## begin CHITDACMAX5712%3FAB9F6A01B5.protected preserve=yes
      //## end CHITDACMAX5712%3FAB9F6A01B5.protected

  private:
    // Data Members for Class Attributes

      //## begin CHITDACMAX5712::cdwWakeUpValue%3FABA043001F.attr preserve=no  public: static DWORD {UC} 0xF000
      static const DWORD  m_cdwWakeUpValue;
      //## end CHITDACMAX5712::cdwWakeUpValue%3FABA043001F.attr

      //## begin CHITDACMAX5712::cdwWaitTimePwrEnable%3FABA0A30222.attr preserve=no  public: static DWORD {UC} 500000
      static const DWORD  m_cdwWaitTimePwrEnable;
      //## end CHITDACMAX5712::cdwWaitTimePwrEnable%3FABA0A30222.attr

      //## begin CHITDACMAX5712::cdwWaitTimeCalibration%3FABA0F50251.attr preserve=no  public: static DWORD {UC} 1000
      static const DWORD  m_cdwWaitTimeCalibration;
      //## end CHITDACMAX5712::cdwWaitTimeCalibration%3FABA0F50251.attr

      //## begin CHITDACMAX5712::cdwWaitTimeAutoCalibration%3FBCBAFE00AB.attr preserve=no  public: static DWORD {UC} 10
      static const DWORD  m_cdwWaitTimeAutoCalibration;
      //## end CHITDACMAX5712::cdwWaitTimeAutoCalibration%3FBCBAFE00AB.attr

      //## begin CHITDACMAX5712::cdwEmergencyStopDAC%3FABB98D0251.attr preserve=no  public: static DWORD {UC} 0x97000000
      static const DWORD  m_cdwEmergencyStopDAC;
      //## end CHITDACMAX5712::cdwEmergencyStopDAC%3FABB98D0251.attr

      //## begin CHITDACMAX5712::cdwDefaultOffsetValue%3FB1F2B80280.attr preserve=no  public: static DWORD {UC} 2416
      static const DWORD  m_cdwDefaultOffsetValue;
      //## end CHITDACMAX5712::cdwDefaultOffsetValue%3FB1F2B80280.attr

      //## begin CHITDACMAX5712::cdwLowerLimit%3FB39C96007D.attr preserve=no  public: static DWORD {UC} 511
      static const DWORD  m_cdwLowerLimit;
      //## end CHITDACMAX5712::cdwLowerLimit%3FB39C96007D.attr

      //## begin CHITDACMAX5712::cdwUpperLimit%3FB39CFA036B.attr preserve=no  public: static DWORD {UC} 0xFFF
      static const DWORD  m_cdwUpperLimit;
      //## end CHITDACMAX5712::cdwUpperLimit%3FB39CFA036B.attr

      //## begin CHITDACMAX5712::cdwMaxOffsetCalibError%3FBDD364033C.attr preserve=no  public: static DWORD {UC} 260
      static const DWORD  m_cdwMaxOffsetCalibError;
      //## end CHITDACMAX5712::cdwMaxOffsetCalibError%3FBDD364033C.attr

    // Additional Private Declarations
      //## begin CHITDACMAX5712%3FAB9F6A01B5.private preserve=yes
      //## end CHITDACMAX5712%3FAB9F6A01B5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHITDACMAX5712%3FAB9F6A01B5.implementation preserve=yes
      //## end CHITDACMAX5712%3FAB9F6A01B5.implementation

};

//## begin CHITDACMAX5712%3FAB9F6A01B5.postscript preserve=yes
//## end CHITDACMAX5712%3FAB9F6A01B5.postscript

//## begin CHIIOCEventMasks%3FC1D67501C5.preface preserve=yes
//## end CHIIOCEventMasks%3FC1D67501C5.preface

//## Class: CHIIOCEventMasks%3FC1D67501C5
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FC357B202DE;CHITReservedSharedMemory { -> }

struct CHIIOCEventMasks 
{
  //## begin CHIIOCEventMasks%3FC1D67501C5.initialDeclarations preserve=yes
  //## end CHIIOCEventMasks%3FC1D67501C5.initialDeclarations

    // Data Members for Associations

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3FC1D96C038A
      //## Role: CHIIOCEventMasks::dwWCEventMask%3FC1D96D01B6
      //## begin CHIIOCEventMasks::dwWCEventMask%3FC1D96D01B6.role preserve=no  public: DWORD { -> VFHN}
      DWORD m_dwWCEventMask[EBHIT_NUMBER_OF_WC_EVENT_REG];
      //## end CHIIOCEventMasks::dwWCEventMask%3FC1D96D01B6.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3FC1D9ED03D8
      //## Role: CHIIOCEventMasks::dwHWEventMask%3FC1D9EE0233
      //## begin CHIIOCEventMasks::dwHWEventMask%3FC1D9EE0233.role preserve=no  public: DWORD { -> VFHN}
      DWORD m_dwHWEventMask[EBHIT_NUMBER_OF_HW_EVENT_REG];
      //## end CHIIOCEventMasks::dwHWEventMask%3FC1D9EE0233.role

  public:
    // Additional Public Declarations
      //## begin CHIIOCEventMasks%3FC1D67501C5.public preserve=yes
      //## end CHIIOCEventMasks%3FC1D67501C5.public

  protected:
    // Additional Protected Declarations
      //## begin CHIIOCEventMasks%3FC1D67501C5.protected preserve=yes
      //## end CHIIOCEventMasks%3FC1D67501C5.protected

  private:
    // Additional Private Declarations
      //## begin CHIIOCEventMasks%3FC1D67501C5.private preserve=yes
      //## end CHIIOCEventMasks%3FC1D67501C5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIIOCEventMasks%3FC1D67501C5.implementation preserve=yes
      //## end CHIIOCEventMasks%3FC1D67501C5.implementation

};

//## begin CHIIOCEventMasks%3FC1D67501C5.postscript preserve=yes
//## end CHIIOCEventMasks%3FC1D67501C5.postscript

//## begin CHITADCMAX1281%4003C3DC02CE.preface preserve=yes
//## end CHITADCMAX1281%4003C3DC02CE.preface

//## Class: CHITADCMAX1281%4003C3DC02CE
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHITADCMAX1281 
{
  //## begin CHITADCMAX1281%4003C3DC02CE.initialDeclarations preserve=yes
  //## end CHITADCMAX1281%4003C3DC02CE.initialDeclarations

  public:
    //## Constructors (generated)
      CHITADCMAX1281();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cdADCRefVoltage%4003C42002AF
      //	DESCRPTION:
      //	ADC reference voltage
      //
      //	UNIT:
      //	Volt
      static const double GetcdADCRefVoltage ();

      //## Attribute: cdwADCCurGainResistor%4003C45C0186
      //	DESCRPTION:
      //	current gain resistor
      //
      //	UNIT:
      //	Ohm
      static const DWORD GetcdwADCCurGainResistor ();

      //## Attribute: cdwADCRange%4003C4D600BB
      //	DESCRPTION:
      //	ADC range
      //
      //	UNIT:
      //	digit
      static const DWORD GetcdwADCRange ();

      //## Attribute: cdwADCLowerLimitDigit%4003CAC1037A
      //	DESCRPTION:
      //	ADC lower limit range
      //
      //	UNIT:
      //	digit
      static const DWORD GetcdwADCLowerLimitDigit ();

      //## Attribute: cdADCLowerLimitCur%4003CAFF001F
      //	DESCRPTION:
      //	ADC lower limit range
      //
      //	UNIT:
      //	A
      static const double GetcdADCLowerLimitCur ();

      //## Attribute: cdwShiftCountsCurLaserDet%4003F38601C5
      static const DWORD GetcdwShiftCountsCurLaserDet ();

      //## Attribute: cdwBitMaskCurLaserDet%4003EA96003E
      //	DESCRIPTION:
      //	bit mask for current laser detecion
      static const DWORD GetcdwBitMaskCurLaserDet ();

    // Additional Public Declarations
      //## begin CHITADCMAX1281%4003C3DC02CE.public preserve=yes
      //## end CHITADCMAX1281%4003C3DC02CE.public

  protected:
    // Additional Protected Declarations
      //## begin CHITADCMAX1281%4003C3DC02CE.protected preserve=yes
      //## end CHITADCMAX1281%4003C3DC02CE.protected

  private:
    // Data Members for Class Attributes

      //## begin CHITADCMAX1281::cdADCRefVoltage%4003C42002AF.attr preserve=no  public: static double {UC} 2.5
      static const double  m_cdADCRefVoltage;
      //## end CHITADCMAX1281::cdADCRefVoltage%4003C42002AF.attr

      //## begin CHITADCMAX1281::cdwADCCurGainResistor%4003C45C0186.attr preserve=no  public: static DWORD {UC} 130000
      static const DWORD  m_cdwADCCurGainResistor;
      //## end CHITADCMAX1281::cdwADCCurGainResistor%4003C45C0186.attr

      //## begin CHITADCMAX1281::cdwADCRange%4003C4D600BB.attr preserve=no  public: static DWORD {UC} 4096
      static const DWORD  m_cdwADCRange;
      //## end CHITADCMAX1281::cdwADCRange%4003C4D600BB.attr

      //## begin CHITADCMAX1281::cdwADCLowerLimitDigit%4003CAC1037A.attr preserve=no  public: static DWORD {UC} 300
      static const DWORD  m_cdwADCLowerLimitDigit;
      //## end CHITADCMAX1281::cdwADCLowerLimitDigit%4003CAC1037A.attr

      //## begin CHITADCMAX1281::cdADCLowerLimitCur%4003CAFF001F.attr preserve=no  public: static double {UC} 0.02
      static const double  m_cdADCLowerLimitCur;
      //## end CHITADCMAX1281::cdADCLowerLimitCur%4003CAFF001F.attr

      //## begin CHITADCMAX1281::cdwShiftCountsCurLaserDet%4003F38601C5.attr preserve=no  public: static DWORD {UC} 4
      static const DWORD  m_cdwShiftCountsCurLaserDet;
      //## end CHITADCMAX1281::cdwShiftCountsCurLaserDet%4003F38601C5.attr

      //## begin CHITADCMAX1281::cdwBitMaskCurLaserDet%4003EA96003E.attr preserve=no  public: static DWORD {UC} 0x0000FFF0
      static const DWORD  m_cdwBitMaskCurLaserDet;
      //## end CHITADCMAX1281::cdwBitMaskCurLaserDet%4003EA96003E.attr

    // Additional Private Declarations
      //## begin CHITADCMAX1281%4003C3DC02CE.private preserve=yes
      //## end CHITADCMAX1281%4003C3DC02CE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHITADCMAX1281%4003C3DC02CE.implementation preserve=yes
      //## end CHITADCMAX1281%4003C3DC02CE.implementation

};

//## begin CHITADCMAX1281%4003C3DC02CE.postscript preserve=yes
//## end CHITADCMAX1281%4003C3DC02CE.postscript

// Class CHIIOCWriteDWord 

// Class CHIIOCSetRSMAddress 

// Class CHITDefinitions 

// Class CHIIOCPCISettings 

// Class CHIIOCSetWCProfile 

// Class CHIIOCSetWCConfiguration 

// Class CHITDACMAX5712 

// Class CHIIOCEventMasks 

// Class CHITADCMAX1281 

//## begin module%3E26C6DC02DC.epilog preserve=yes
//## end module%3E26C6DC02DC.epilog


#endif
