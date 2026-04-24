//## begin module%3F4B4E8502CE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4E8502CE.cm

//## begin module%3F4B4E8502CE.cp preserve=no
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
//## end module%3F4B4E8502CE.cp

//## Module: EBI2CDPintf%3F4B4E8502CE; Package specification
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPintf.h

#ifndef EBI2CDPintf_h
#define EBI2CDPintf_h 1

//## begin module%3F4B4E8502CE.additionalIncludes preserve=no
//## end module%3F4B4E8502CE.additionalIncludes

//## begin module%3F4B4E8502CE.includes preserve=yes
//## end module%3F4B4E8502CE.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3F4B4E8502CE.declarations preserve=no
//## end module%3F4B4E8502CE.declarations

//## begin module%3F4B4E8502CE.additionalDeclarations preserve=yes
//## end module%3F4B4E8502CE.additionalDeclarations


//## begin CI2CDigitalPotiAD5245%3F4B6249005D.preface preserve=yes
//## end CI2CDigitalPotiAD5245%3F4B6249005D.preface

//## Class: CI2CDigitalPotiAD5245%3F4B6249005D
//## Category: EBI2CDP (I2C Digital Potentiometer)%3F4B4CE20177
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4B636F02BF;I2CDP_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F4B6371029F;CI2CSTDLIBConvert { -> }
//## Uses: <unnamed>%3F4B63730290;CI2CSTDLIBCmd { -> }
//## Uses: <unnamed>%3F5D79930213;CHIProcessImageParameter { -> }
//## Uses: <unnamed>%3FFBC8C00242;CPIComponentsState { -> }
//## Uses: <unnamed>%3FFBC90701F4;CPISyncObjI2CDataStream { -> }
//## Uses: <unnamed>%3FFBC90A00EA;CHII2CWorkerThread { -> }
//## Uses: <unnamed>%3FFBC90D0167;IHIInterface { -> }
//## Uses: <unnamed>%3FFBC933007D;XI2CDigitalPotiExceptionError { -> }
//## Uses: <unnamed>%3FFBD81700EA;CI2CDigitalPotiAD5245Command { -> }

class EBI2CDP_DLL_DECL CI2CDigitalPotiAD5245 : public IPII2CDigitalPotiAD5245  //## Inherits: <unnamed>%3F4B6275032C
{
  //## begin CI2CDigitalPotiAD5245%3F4B6249005D.initialDeclarations preserve=yes
  //## end CI2CDigitalPotiAD5245%3F4B6249005D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CDigitalPotiAD5245%1061902077
      CI2CDigitalPotiAD5245 (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CI2CDigitalPotiAD5245();


    //## Other Operations (specified)
      //## Operation: GetuiID%1061902078
      virtual UINT GetuiID ();

      //## Operation: Startup%1061902079
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1061902080
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1061902081
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1061902082
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: WriteValue%1061902083
      //	DESCRIPTION
      //	writes the value to the digital potentiometer
      //
      //	INPUT:
      //	- data byte
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteValue (BYTE p_cValue);

      //## Operation: ReadValue%1061902084
      //	DESCRIPTION
      //	gets the digital potentiometer value
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* ReadValue ();

    // Additional Public Declarations
      //## begin CI2CDigitalPotiAD5245%3F4B6249005D.public preserve=yes
      //## end CI2CDigitalPotiAD5245%3F4B6249005D.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CDigitalPotiAD5245%3F4B6249005D.protected preserve=yes
      //## end CI2CDigitalPotiAD5245%3F4B6249005D.protected

  private:
    //## Constructors (generated)
      CI2CDigitalPotiAD5245();

      CI2CDigitalPotiAD5245(const CI2CDigitalPotiAD5245 &right);

    //## Assignment Operation (generated)
      const CI2CDigitalPotiAD5245 & operator=(const CI2CDigitalPotiAD5245 &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CDigitalPotiAD5245 &right) const;

      bool operator!=(const CI2CDigitalPotiAD5245 &right) const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwI2CBaseAdr%3FFBD7D2000F
      const DWORD GetdwI2CBaseAdr () const;

      //## Attribute: cI2CDeviceAdr%3F5D78C1007D
      const BYTE GetcI2CDeviceAdr () const;

      //## Attribute: cI2CBusNumber%3F5D78C1009C
      const BYTE GetcI2CBusNumber () const;

      //## Attribute: cI2CTransferSpeed%3F5D78C100AB
      const BYTE GetcI2CTransferSpeed () const;

      //## Attribute: cI2CDevice%3F5D78C100BB
      const BYTE GetcI2CDevice () const;

      //## Attribute: cInstruction%3FFBD32801F4
      const BYTE GetcInstruction () const;

    // Data Members for Class Attributes

      //## begin CI2CDigitalPotiAD5245::dwI2CBaseAdr%3FFBD7D2000F.attr preserve=no  private: DWORD {U} 
      DWORD m_dwI2CBaseAdr;
      //## end CI2CDigitalPotiAD5245::dwI2CBaseAdr%3FFBD7D2000F.attr

      //## begin CI2CDigitalPotiAD5245::cI2CDeviceAdr%3F5D78C1007D.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDeviceAdr;
      //## end CI2CDigitalPotiAD5245::cI2CDeviceAdr%3F5D78C1007D.attr

      //## begin CI2CDigitalPotiAD5245::cI2CBusNumber%3F5D78C1009C.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CBusNumber;
      //## end CI2CDigitalPotiAD5245::cI2CBusNumber%3F5D78C1009C.attr

      //## begin CI2CDigitalPotiAD5245::cI2CTransferSpeed%3F5D78C100AB.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CTransferSpeed;
      //## end CI2CDigitalPotiAD5245::cI2CTransferSpeed%3F5D78C100AB.attr

      //## begin CI2CDigitalPotiAD5245::cI2CDevice%3F5D78C100BB.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDevice;
      //## end CI2CDigitalPotiAD5245::cI2CDevice%3F5D78C100BB.attr

      //## begin CI2CDigitalPotiAD5245::cInstruction%3FFBD32801F4.attr preserve=no  private: BYTE {U} 0x00
      BYTE m_cInstruction;
      //## end CI2CDigitalPotiAD5245::cInstruction%3FFBD32801F4.attr

      //## Attribute: cMaskDPAD5245%3FFBD4D30138
      //## begin CI2CDigitalPotiAD5245::cMaskDPAD5245%3FFBD4D30138.attr preserve=no  private: BYTE {U} 0x1
      BYTE m_cMaskDPAD5245;
      //## end CI2CDigitalPotiAD5245::cMaskDPAD5245%3FFBD4D30138.attr

      //## Attribute: cMaskWriteAccess%3FFBD5BD0196
      //## begin CI2CDigitalPotiAD5245::cMaskWriteAccess%3FFBD5BD0196.attr preserve=no  private: BYTE {U} 0xFE
      BYTE m_cMaskWriteAccess;
      //## end CI2CDigitalPotiAD5245::cMaskWriteAccess%3FFBD5BD0196.attr

      //## Attribute: cMaskReadAccess%3FFBF4D9035B
      //## begin CI2CDigitalPotiAD5245::cMaskReadAccess%3FFBF4D9035B.attr preserve=no  private: BYTE {U} 0x01
      BYTE m_cMaskReadAccess;
      //## end CI2CDigitalPotiAD5245::cMaskReadAccess%3FFBF4D9035B.attr

    // Data Members for Associations

      //## Association: EBI2CDP (I2C Digital Potentiometer)::<unnamed>%3F4B630902AF
      //## Role: CI2CDigitalPotiAD5245::uiID%3F4B630A005E
      //## begin CI2CDigitalPotiAD5245::uiID%3F4B630A005E.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CI2CDigitalPotiAD5245::uiID%3F4B630A005E.role

      //## Association: EBI2CDP (I2C Digital Potentiometer)::<unnamed>%3FFBC86F005D
      //## Role: CI2CDigitalPotiAD5245::bHWPresent%3FFBC86F02C0
      //## begin CI2CDigitalPotiAD5245::bHWPresent%3FFBC86F02C0.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHWPresent;
      //## end CI2CDigitalPotiAD5245::bHWPresent%3FFBC86F02C0.role

    // Additional Private Declarations
      //## begin CI2CDigitalPotiAD5245%3F4B6249005D.private preserve=yes
      //## end CI2CDigitalPotiAD5245%3F4B6249005D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CDigitalPotiAD5245%3F4B6249005D.implementation preserve=yes
      //## end CI2CDigitalPotiAD5245%3F4B6249005D.implementation

};

//## begin CI2CDigitalPotiAD5245%3F4B6249005D.postscript preserve=yes
//## end CI2CDigitalPotiAD5245%3F4B6249005D.postscript

// Class CI2CDigitalPotiAD5245 

//## begin module%3F4B4E8502CE.epilog preserve=yes
//## end module%3F4B4E8502CE.epilog


#endif
