//## begin module%3EE891890000.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE891890000.cm

//## begin module%3EE891890000.cp preserve=no
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
//## end module%3EE891890000.cp

//## Module: EBI2CSTDLIBcomd%3EE891890000; Package specification
//## Subsystem: EBI2CSTDLIB (I2C Standard Library)%3EE73A490138
//## Source file: R:\Embedded\src\EBI2CSTDLIB\EBI2CSTDLIBcomd.h

#ifndef EBI2CSTDLIBcomd_h
#define EBI2CSTDLIBcomd_h 1

//## begin module%3EE891890000.additionalIncludes preserve=no
//## end module%3EE891890000.additionalIncludes

//## begin module%3EE891890000.includes preserve=yes
//## end module%3EE891890000.includes

//## begin module%3EE891890000.declarations preserve=no
//## end module%3EE891890000.declarations

//## begin module%3EE891890000.additionalDeclarations preserve=yes
//## end module%3EE891890000.additionalDeclarations


//## begin CI2CSTDLIBCmd%3EE891A00157.preface preserve=yes
//## end CI2CSTDLIBCmd%3EE891A00157.preface

//## Class: CI2CSTDLIBCmd%3EE891A00157
//## Category: EBI2CSTDLIB (I2C Standard Library)%3EE73A9A009C
//## Subsystem: EBI2CSTDLIB (I2C Standard Library)%3EE73A490138
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CI2CSTDLIBCmd 
{
  //## begin CI2CSTDLIBCmd%3EE891A00157.initialDeclarations preserve=yes
  //## end CI2CSTDLIBCmd%3EE891A00157.initialDeclarations

  public:
    // Data Members for Class Attributes

      //## Attribute: strI2CStart%3EE891D90119
      //## begin CI2CSTDLIBCmd::strI2CStart%3EE891D90119.attr preserve=no  public: static CString {U} _T("10")
      static CString m_strI2CStart;
      //## end CI2CSTDLIBCmd::strI2CStart%3EE891D90119.attr

      //## Attribute: strI2CStop%3EE891D90128
      //## begin CI2CSTDLIBCmd::strI2CStop%3EE891D90128.attr preserve=no  public: static CString {U} _T("01")
      static CString m_strI2CStop;
      //## end CI2CSTDLIBCmd::strI2CStop%3EE891D90128.attr

      //## Attribute: strI2CAck%3EE891D90138
      //## begin CI2CSTDLIBCmd::strI2CAck%3EE891D90138.attr preserve=no  public: static CString {U} _T("11")
      static CString m_strI2CAck;
      //## end CI2CSTDLIBCmd::strI2CAck%3EE891D90138.attr

      //## Attribute: strI2CNack%3EE891D90139
      //## begin CI2CSTDLIBCmd::strI2CNack%3EE891D90139.attr preserve=no  public: static CString {U} _T("11")
      static CString m_strI2CNack;
      //## end CI2CSTDLIBCmd::strI2CNack%3EE891D90139.attr

      //## Attribute: strI2CHigh%3EE891D90148
      //## begin CI2CSTDLIBCmd::strI2CHigh%3EE891D90148.attr preserve=no  public: static CString {U} _T("11")
      static CString m_strI2CHigh;
      //## end CI2CSTDLIBCmd::strI2CHigh%3EE891D90148.attr

      //## Attribute: strI2CLow%3EE891D90157
      //## begin CI2CSTDLIBCmd::strI2CLow%3EE891D90157.attr preserve=no  public: static CString {U} _T("00")
      static CString m_strI2CLow;
      //## end CI2CSTDLIBCmd::strI2CLow%3EE891D90157.attr

      //## Attribute: cI2CStart%3FE7F5A80280
      //## begin CI2CSTDLIBCmd::cI2CStart%3FE7F5A80280.attr preserve=no  public: static char[] {U} "10"
      static char m_cI2CStart[];
      //## end CI2CSTDLIBCmd::cI2CStart%3FE7F5A80280.attr

      //## Attribute: cI2CStop%3FE7F6AF03C8
      //## begin CI2CSTDLIBCmd::cI2CStop%3FE7F6AF03C8.attr preserve=no  public: static char[] {U} "01"
      static char m_cI2CStop[];
      //## end CI2CSTDLIBCmd::cI2CStop%3FE7F6AF03C8.attr

      //## Attribute: cI2CAck%3FE7F6B00000
      //## begin CI2CSTDLIBCmd::cI2CAck%3FE7F6B00000.attr preserve=no  public: static char[] {U} "11"
      static char m_cI2CAck[];
      //## end CI2CSTDLIBCmd::cI2CAck%3FE7F6B00000.attr

      //## Attribute: cI2CNack%3FE7F6B0000F
      //## begin CI2CSTDLIBCmd::cI2CNack%3FE7F6B0000F.attr preserve=no  public: static char[] {U} "00"
      static char m_cI2CNack[];
      //## end CI2CSTDLIBCmd::cI2CNack%3FE7F6B0000F.attr

      //## Attribute: cI2CHigh%3FE7F6B0002E
      //## begin CI2CSTDLIBCmd::cI2CHigh%3FE7F6B0002E.attr preserve=no  public: static char[] {U} "11"
      static char m_cI2CHigh[];
      //## end CI2CSTDLIBCmd::cI2CHigh%3FE7F6B0002E.attr

      //## Attribute: cI2CLow%3FE7F6B0003E
      //## begin CI2CSTDLIBCmd::cI2CLow%3FE7F6B0003E.attr preserve=no  public: static char[] {U} "00"
      static char m_cI2CLow[];
      //## end CI2CSTDLIBCmd::cI2CLow%3FE7F6B0003E.attr

    // Additional Public Declarations
      //## begin CI2CSTDLIBCmd%3EE891A00157.public preserve=yes
      //## end CI2CSTDLIBCmd%3EE891A00157.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CSTDLIBCmd%3EE891A00157.protected preserve=yes
      //## end CI2CSTDLIBCmd%3EE891A00157.protected

  private:
    //## Constructors (generated)
      CI2CSTDLIBCmd();

      CI2CSTDLIBCmd(const CI2CSTDLIBCmd &right);

    //## Assignment Operation (generated)
      const CI2CSTDLIBCmd & operator=(const CI2CSTDLIBCmd &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CSTDLIBCmd &right) const;

      bool operator!=(const CI2CSTDLIBCmd &right) const;

    // Additional Private Declarations
      //## begin CI2CSTDLIBCmd%3EE891A00157.private preserve=yes
      //## end CI2CSTDLIBCmd%3EE891A00157.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CSTDLIBCmd%3EE891A00157.implementation preserve=yes
      //## end CI2CSTDLIBCmd%3EE891A00157.implementation

};

//## begin CI2CSTDLIBCmd%3EE891A00157.postscript preserve=yes
//## end CI2CSTDLIBCmd%3EE891A00157.postscript

// Class CI2CSTDLIBCmd 

// Class CI2CSTDLIBCmd 

//## begin CI2CSTDLIBCmd::strI2CStart%3EE891D90119.attr preserve=no  public: static CString {U} _T("10")
CString CI2CSTDLIBCmd::m_strI2CStart = _T("10");
//## end CI2CSTDLIBCmd::strI2CStart%3EE891D90119.attr

//## begin CI2CSTDLIBCmd::strI2CStop%3EE891D90128.attr preserve=no  public: static CString {U} _T("01")
CString CI2CSTDLIBCmd::m_strI2CStop = _T("01");
//## end CI2CSTDLIBCmd::strI2CStop%3EE891D90128.attr

//## begin CI2CSTDLIBCmd::strI2CAck%3EE891D90138.attr preserve=no  public: static CString {U} _T("11")
CString CI2CSTDLIBCmd::m_strI2CAck = _T("11");
//## end CI2CSTDLIBCmd::strI2CAck%3EE891D90138.attr

//## begin CI2CSTDLIBCmd::strI2CNack%3EE891D90139.attr preserve=no  public: static CString {U} _T("11")
CString CI2CSTDLIBCmd::m_strI2CNack = _T("11");
//## end CI2CSTDLIBCmd::strI2CNack%3EE891D90139.attr

//## begin CI2CSTDLIBCmd::strI2CHigh%3EE891D90148.attr preserve=no  public: static CString {U} _T("11")
CString CI2CSTDLIBCmd::m_strI2CHigh = _T("11");
//## end CI2CSTDLIBCmd::strI2CHigh%3EE891D90148.attr

//## begin CI2CSTDLIBCmd::strI2CLow%3EE891D90157.attr preserve=no  public: static CString {U} _T("00")
CString CI2CSTDLIBCmd::m_strI2CLow = _T("00");
//## end CI2CSTDLIBCmd::strI2CLow%3EE891D90157.attr

//## begin CI2CSTDLIBCmd::cI2CStart%3FE7F5A80280.attr preserve=no  public: static char[] {U} "10"
char CI2CSTDLIBCmd::m_cI2CStart[] = "10";
//## end CI2CSTDLIBCmd::cI2CStart%3FE7F5A80280.attr

//## begin CI2CSTDLIBCmd::cI2CStop%3FE7F6AF03C8.attr preserve=no  public: static char[] {U} "01"
char CI2CSTDLIBCmd::m_cI2CStop[] = "01";
//## end CI2CSTDLIBCmd::cI2CStop%3FE7F6AF03C8.attr

//## begin CI2CSTDLIBCmd::cI2CAck%3FE7F6B00000.attr preserve=no  public: static char[] {U} "11"
char CI2CSTDLIBCmd::m_cI2CAck[] = "11";
//## end CI2CSTDLIBCmd::cI2CAck%3FE7F6B00000.attr

//## begin CI2CSTDLIBCmd::cI2CNack%3FE7F6B0000F.attr preserve=no  public: static char[] {U} "00"
char CI2CSTDLIBCmd::m_cI2CNack[] = "00";
//## end CI2CSTDLIBCmd::cI2CNack%3FE7F6B0000F.attr

//## begin CI2CSTDLIBCmd::cI2CHigh%3FE7F6B0002E.attr preserve=no  public: static char[] {U} "11"
char CI2CSTDLIBCmd::m_cI2CHigh[] = "11";
//## end CI2CSTDLIBCmd::cI2CHigh%3FE7F6B0002E.attr

//## begin CI2CSTDLIBCmd::cI2CLow%3FE7F6B0003E.attr preserve=no  public: static char[] {U} "00"
char CI2CSTDLIBCmd::m_cI2CLow[] = "00";
//## end CI2CSTDLIBCmd::cI2CLow%3FE7F6B0003E.attr

// Additional Declarations
  //## begin CI2CSTDLIBCmd%3EE891A00157.declarations preserve=yes
  //## end CI2CSTDLIBCmd%3EE891A00157.declarations

//## begin module%3EE891890000.epilog preserve=yes
//## end module%3EE891890000.epilog


#endif
