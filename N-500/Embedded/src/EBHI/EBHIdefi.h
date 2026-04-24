//## begin module%3E68A3D300AB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E68A3D300AB.cm

//## begin module%3E68A3D300AB.cp preserve=no
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
//## end module%3E68A3D300AB.cp

//## Module: EBHIdefi%3E68A3D300AB; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIdefi.h

#ifndef EBHIdefi_h
#define EBHIdefi_h 1

//## begin module%3E68A3D300AB.additionalIncludes preserve=no
//## end module%3E68A3D300AB.additionalIncludes

//## begin module%3E68A3D300AB.includes preserve=yes
//## end module%3E68A3D300AB.includes

//## begin module%3E68A3D300AB.declarations preserve=no
//## end module%3E68A3D300AB.declarations

//## begin module%3E68A3D300AB.additionalDeclarations preserve=yes
//## end module%3E68A3D300AB.additionalDeclarations


//## begin CHIMCParameter%3E68A38000DA.preface preserve=yes
//## end CHIMCParameter%3E68A38000DA.preface

//## Class: CHIMCParameter%3E68A38000DA
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBHI_DLL_DECL CHIMCParameter 
{
  //## begin CHIMCParameter%3E68A38000DA.initialDeclarations preserve=yes
  //## end CHIMCParameter%3E68A38000DA.initialDeclarations

  public:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwMinTransferDataSize%3E68A30203A9
      //	DESCRIPTION:
      //	min data packgae size for ethernet transfer
      //
      //	UNIT:
      //	Byte
      static DWORD GetdwMinTransferDataSize ();
      static void SetdwMinTransferDataSize (DWORD value);

      //## Attribute: dwMaxTransferDataSize%3E6C40D501D4
      //	DESCRIPTION:
      //	min data packgae size for ethernet transfer
      //
      //	UNIT:
      //	Byte
      static DWORD GetdwMaxTransferDataSize ();
      static void SetdwMaxTransferDataSize (DWORD value);

      //## Attribute: dwCycleID%3E6DF77801A5
      //	DESCRIPTION:
      //	min data packgae size for ethernet transfer
      //
      //	UNIT:
      //	Byte
      static DWORD GetdwCycleID ();
      static void SetdwCycleID (DWORD value);

    // Additional Public Declarations
      //## begin CHIMCParameter%3E68A38000DA.public preserve=yes
      //## end CHIMCParameter%3E68A38000DA.public

  protected:
    // Additional Protected Declarations
      //## begin CHIMCParameter%3E68A38000DA.protected preserve=yes
      //## end CHIMCParameter%3E68A38000DA.protected

  private:
    //## Constructors (generated)
      CHIMCParameter();

      CHIMCParameter(const CHIMCParameter &right);

    //## Assignment Operation (generated)
      const CHIMCParameter & operator=(const CHIMCParameter &right);

    //## Equality Operations (generated)
      bool operator==(const CHIMCParameter &right) const;

      bool operator!=(const CHIMCParameter &right) const;

    // Data Members for Class Attributes

      //## begin CHIMCParameter::dwMinTransferDataSize%3E68A30203A9.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwMinTransferDataSize;
      //## end CHIMCParameter::dwMinTransferDataSize%3E68A30203A9.attr

      //## begin CHIMCParameter::dwMaxTransferDataSize%3E6C40D501D4.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwMaxTransferDataSize;
      //## end CHIMCParameter::dwMaxTransferDataSize%3E6C40D501D4.attr

      //## begin CHIMCParameter::dwCycleID%3E6DF77801A5.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwCycleID;
      //## end CHIMCParameter::dwCycleID%3E6DF77801A5.attr

    // Additional Private Declarations
      //## begin CHIMCParameter%3E68A38000DA.private preserve=yes
      //## end CHIMCParameter%3E68A38000DA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIMCParameter%3E68A38000DA.implementation preserve=yes
      //## end CHIMCParameter%3E68A38000DA.implementation

};

//## begin CHIMCParameter%3E68A38000DA.postscript preserve=yes
//## end CHIMCParameter%3E68A38000DA.postscript

//## begin CHIProcessImageParameter%3EBA10D00128.preface preserve=yes
//## end CHIProcessImageParameter%3EBA10D00128.preface

//## Class: CHIProcessImageParameter%3EBA10D00128
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBHI_DLL_DECL CHIProcessImageParameter 
{
  //## begin CHIProcessImageParameter%3EBA10D00128.initialDeclarations preserve=yes
  //## end CHIProcessImageParameter%3EBA10D00128.initialDeclarations

  public:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cdwMaskOffsetAdr%3EBA1117037A
      static const DWORD GetcdwMaskOffsetAdr ();

      //## Attribute: cdwMaskDataWidth%3EBA11580138
      static const DWORD GetcdwMaskDataWidth ();

      //## Attribute: cdwMaskBitPosition%3EBA11580399
      static const DWORD GetcdwMaskBitPosition ();

      //## Attribute: cdwMaskControlStates%3EBA11590222
      static const DWORD GetcdwMaskControlStates ();

      //## Attribute: cdwMaskWriteBit%3F54A1640232
      static const DWORD GetcdwMaskWriteBit ();

      //## Attribute: cdwMaskDeleteRegister%41B08309031C
      static const DWORD GetcdwMaskDeleteRegister ();

      //## Attribute: cdwShiftCountsOffsetAdr%3EBA143300AB
      static const DWORD GetcdwShiftCountsOffsetAdr ();

      //## Attribute: cdwShiftCountsDataWidth%3EBA1481038A
      static const DWORD GetcdwShiftCountsDataWidth ();

      //## Attribute: cdwShiftCountsBitPosition%3EBA14840000
      static const DWORD GetcdwShiftCountsBitPosition ();

      //## Attribute: cdwShiftCountsControlStates%3EBA1486001F
      static const DWORD GetcdwShiftCountsControlStates ();

      //## Attribute: cdwMaskI2CBusNumber%3F5C6CB3002E
      static const DWORD GetcdwMaskI2CBusNumber ();

      //## Attribute: cdwMaskI2CTransferSpeed%3F5C6CB3004E
      static const DWORD GetcdwMaskI2CTransferSpeed ();

      //## Attribute: cdwShiftCountsI2CBusNumber%3F5C6CEC03D8
      static const DWORD GetcdwShiftCountsI2CBusNumber ();

      //## Attribute: cdwShiftCountsI2CTransferSpeed%3F5C6CED0000
      static const DWORD GetcdwShiftCountsI2CTransferSpeed ();

    // Additional Public Declarations
      //## begin CHIProcessImageParameter%3EBA10D00128.public preserve=yes
      //## end CHIProcessImageParameter%3EBA10D00128.public

  protected:
    // Additional Protected Declarations
      //## begin CHIProcessImageParameter%3EBA10D00128.protected preserve=yes
      //## end CHIProcessImageParameter%3EBA10D00128.protected

  private:
    //## Constructors (generated)
      CHIProcessImageParameter();

      CHIProcessImageParameter(const CHIProcessImageParameter &right);

    //## Assignment Operation (generated)
      const CHIProcessImageParameter & operator=(const CHIProcessImageParameter &right);

    //## Equality Operations (generated)
      bool operator==(const CHIProcessImageParameter &right) const;

      bool operator!=(const CHIProcessImageParameter &right) const;

    // Data Members for Class Attributes

      //## begin CHIProcessImageParameter::cdwMaskOffsetAdr%3EBA1117037A.attr preserve=no  public: static DWORD {UC} 0x0FFFF000
      static const DWORD  m_cdwMaskOffsetAdr;
      //## end CHIProcessImageParameter::cdwMaskOffsetAdr%3EBA1117037A.attr

      //## begin CHIProcessImageParameter::cdwMaskDataWidth%3EBA11580138.attr preserve=no  public: static DWORD {UC} 0x00000FC0
      static const DWORD  m_cdwMaskDataWidth;
      //## end CHIProcessImageParameter::cdwMaskDataWidth%3EBA11580138.attr

      //## begin CHIProcessImageParameter::cdwMaskBitPosition%3EBA11580399.attr preserve=no  public: static DWORD {UC} 0x0000003F
      static const DWORD  m_cdwMaskBitPosition;
      //## end CHIProcessImageParameter::cdwMaskBitPosition%3EBA11580399.attr

      //## begin CHIProcessImageParameter::cdwMaskControlStates%3EBA11590222.attr preserve=no  public: static DWORD {UC} 0xF0000000
      static const DWORD  m_cdwMaskControlStates;
      //## end CHIProcessImageParameter::cdwMaskControlStates%3EBA11590222.attr

      //## begin CHIProcessImageParameter::cdwMaskWriteBit%3F54A1640232.attr preserve=no  public: static DWORD {UC} 0x80000000
      static const DWORD  m_cdwMaskWriteBit;
      //## end CHIProcessImageParameter::cdwMaskWriteBit%3F54A1640232.attr

      //## begin CHIProcessImageParameter::cdwMaskDeleteRegister%41B08309031C.attr preserve=no  public: static DWORD {UC} 0x20000000
      static const DWORD  m_cdwMaskDeleteRegister;
      //## end CHIProcessImageParameter::cdwMaskDeleteRegister%41B08309031C.attr

      //## begin CHIProcessImageParameter::cdwShiftCountsOffsetAdr%3EBA143300AB.attr preserve=no  public: static DWORD {UC} 12
      static const DWORD  m_cdwShiftCountsOffsetAdr;
      //## end CHIProcessImageParameter::cdwShiftCountsOffsetAdr%3EBA143300AB.attr

      //## begin CHIProcessImageParameter::cdwShiftCountsDataWidth%3EBA1481038A.attr preserve=no  public: static DWORD {UC} 6
      static const DWORD  m_cdwShiftCountsDataWidth;
      //## end CHIProcessImageParameter::cdwShiftCountsDataWidth%3EBA1481038A.attr

      //## begin CHIProcessImageParameter::cdwShiftCountsBitPosition%3EBA14840000.attr preserve=no  public: static DWORD {UC} 0
      static const DWORD  m_cdwShiftCountsBitPosition;
      //## end CHIProcessImageParameter::cdwShiftCountsBitPosition%3EBA14840000.attr

      //## begin CHIProcessImageParameter::cdwShiftCountsControlStates%3EBA1486001F.attr preserve=no  public: static DWORD {UC} 28
      static const DWORD  m_cdwShiftCountsControlStates;
      //## end CHIProcessImageParameter::cdwShiftCountsControlStates%3EBA1486001F.attr

      //## begin CHIProcessImageParameter::cdwMaskI2CBusNumber%3F5C6CB3002E.attr preserve=no  public: static DWORD {UC} 0x00000FC0
      static const DWORD  m_cdwMaskI2CBusNumber;
      //## end CHIProcessImageParameter::cdwMaskI2CBusNumber%3F5C6CB3002E.attr

      //## begin CHIProcessImageParameter::cdwMaskI2CTransferSpeed%3F5C6CB3004E.attr preserve=no  public: static DWORD {UC} 0x0000003F
      static const DWORD  m_cdwMaskI2CTransferSpeed;
      //## end CHIProcessImageParameter::cdwMaskI2CTransferSpeed%3F5C6CB3004E.attr

      //## begin CHIProcessImageParameter::cdwShiftCountsI2CBusNumber%3F5C6CEC03D8.attr preserve=no  public: static DWORD {UC} 6
      static const DWORD  m_cdwShiftCountsI2CBusNumber;
      //## end CHIProcessImageParameter::cdwShiftCountsI2CBusNumber%3F5C6CEC03D8.attr

      //## begin CHIProcessImageParameter::cdwShiftCountsI2CTransferSpeed%3F5C6CED0000.attr preserve=no  public: static DWORD {UC} 0
      static const DWORD  m_cdwShiftCountsI2CTransferSpeed;
      //## end CHIProcessImageParameter::cdwShiftCountsI2CTransferSpeed%3F5C6CED0000.attr

    // Additional Private Declarations
      //## begin CHIProcessImageParameter%3EBA10D00128.private preserve=yes
      //## end CHIProcessImageParameter%3EBA10D00128.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIProcessImageParameter%3EBA10D00128.implementation preserve=yes
      //## end CHIProcessImageParameter%3EBA10D00128.implementation

};

//## begin CHIProcessImageParameter%3EBA10D00128.postscript preserve=yes
//## end CHIProcessImageParameter%3EBA10D00128.postscript

//## begin CHII2CParameter%3FD9C47E033C.preface preserve=yes
//## end CHII2CParameter%3FD9C47E033C.preface

//## Class: CHII2CParameter%3FD9C47E033C
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBHI_DLL_DECL CHII2CParameter 
{
  //## begin CHII2CParameter%3FD9C47E033C.initialDeclarations preserve=yes
  //## end CHII2CParameter%3FD9C47E033C.initialDeclarations

  public:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cdwI2CEventID%3FD9C4F5035B
      static const DWORD GetcdwI2CEventID ();

      //## Attribute: cdwI2CLogID%3FD9D0720213
      static const DWORD GetcdwI2CLogID ();

      //## Attribute: cdwI2CMaxDataSize%3FD9D93702EE
      //	DESCRIPTION:
      //	64 * sizeof(DWORD)
      static const DWORD GetcdwI2CMaxDataSize ();

      //## Attribute: cdwI2CValidID%3FD9DBEF0000
      static const DWORD GetcdwI2CValidID ();

      //## Attribute: cdwI2CBusNumberID%3FFD5DE101D4
      static const DWORD GetcdwI2CBusNumberID ();

      //## Attribute: cdwI2CTransferSpeedID%3FFD5DE200AB
      static const DWORD GetcdwI2CTransferSpeedID ();

    // Additional Public Declarations
      //## begin CHII2CParameter%3FD9C47E033C.public preserve=yes
      //## end CHII2CParameter%3FD9C47E033C.public

  protected:
    // Additional Protected Declarations
      //## begin CHII2CParameter%3FD9C47E033C.protected preserve=yes
      //## end CHII2CParameter%3FD9C47E033C.protected

  private:
    //## Constructors (generated)
      CHII2CParameter();

      CHII2CParameter(const CHII2CParameter &right);

    //## Assignment Operation (generated)
      const CHII2CParameter & operator=(const CHII2CParameter &right);

    //## Equality Operations (generated)
      bool operator==(const CHII2CParameter &right) const;

      bool operator!=(const CHII2CParameter &right) const;

    // Data Members for Class Attributes

      //## begin CHII2CParameter::cdwI2CEventID%3FD9C4F5035B.attr preserve=no  public: static DWORD {UC} 5000
      static const DWORD  m_cdwI2CEventID;
      //## end CHII2CParameter::cdwI2CEventID%3FD9C4F5035B.attr

      //## begin CHII2CParameter::cdwI2CLogID%3FD9D0720213.attr preserve=no  public: static DWORD {UC} 0x00140040
      static const DWORD  m_cdwI2CLogID;
      //## end CHII2CParameter::cdwI2CLogID%3FD9D0720213.attr

      //## begin CHII2CParameter::cdwI2CMaxDataSize%3FD9D93702EE.attr preserve=no  public: static DWORD {UC} 256
      static const DWORD  m_cdwI2CMaxDataSize;
      //## end CHII2CParameter::cdwI2CMaxDataSize%3FD9D93702EE.attr

      //## begin CHII2CParameter::cdwI2CValidID%3FD9DBEF0000.attr preserve=no  public: static DWORD {UC} 5001
      static const DWORD  m_cdwI2CValidID;
      //## end CHII2CParameter::cdwI2CValidID%3FD9DBEF0000.attr

      //## begin CHII2CParameter::cdwI2CBusNumberID%3FFD5DE101D4.attr preserve=no  public: static DWORD {UC} 5007
      static const DWORD  m_cdwI2CBusNumberID;
      //## end CHII2CParameter::cdwI2CBusNumberID%3FFD5DE101D4.attr

      //## begin CHII2CParameter::cdwI2CTransferSpeedID%3FFD5DE200AB.attr preserve=no  public: static DWORD {UC} 5008
      static const DWORD  m_cdwI2CTransferSpeedID;
      //## end CHII2CParameter::cdwI2CTransferSpeedID%3FFD5DE200AB.attr

    // Additional Private Declarations
      //## begin CHII2CParameter%3FD9C47E033C.private preserve=yes
      //## end CHII2CParameter%3FD9C47E033C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHII2CParameter%3FD9C47E033C.implementation preserve=yes
      //## end CHII2CParameter%3FD9C47E033C.implementation

};

//## begin CHII2CParameter%3FD9C47E033C.postscript preserve=yes
//## end CHII2CParameter%3FD9C47E033C.postscript

// Class CHIMCParameter 

// Class CHIProcessImageParameter 

// Class CHII2CParameter 

//## begin module%3E68A3D300AB.epilog preserve=yes
//## end module%3E68A3D300AB.epilog


#endif
