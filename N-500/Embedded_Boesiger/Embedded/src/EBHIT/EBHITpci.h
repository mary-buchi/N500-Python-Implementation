//## begin module%3E8BE6A001D4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E8BE6A001D4.cm

//## begin module%3E8BE6A001D4.cp preserve=no
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
//## end module%3E8BE6A001D4.cp

//## Module: EBHITpci%3E8BE6A001D4; Package specification
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Source file: R:\Embedded\src\EBHIT\EBHITpci.h

#ifndef EBHITpci_h
#define EBHITpci_h 1

//## begin module%3E8BE6A001D4.additionalIncludes preserve=no
//## end module%3E8BE6A001D4.additionalIncludes

//## begin module%3E8BE6A001D4.includes preserve=yes
//## end module%3E8BE6A001D4.includes

//## begin module%3E8BE6A001D4.declarations preserve=no
//## end module%3E8BE6A001D4.declarations

//## begin module%3E8BE6A001D4.additionalDeclarations preserve=yes
//## end module%3E8BE6A001D4.additionalDeclarations


//## begin CHITPCIAccess%3E8BE636034B.preface preserve=yes
//## end CHITPCIAccess%3E8BE636034B.preface

//## Class: CHITPCIAccess%3E8BE636034B
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHITPCIAccess 
{
  //## begin CHITPCIAccess%3E8BE636034B.initialDeclarations preserve=yes
  //## end CHITPCIAccess%3E8BE636034B.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: ReadBlockRAM%1049356540
      static bool ReadBlockRAM (DWORD* p_pDest, DWORD* p_pPCIAdr, DWORD p_dwSize);

      //## Operation: WriteBlockRAM%1049356541
      static bool WriteBlockRAM (DWORD* p_pDest, DWORD* p_pPCIAdr, DWORD p_dwSize);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cdwSysStatus%3F30A21B0167
      static const DWORD GetcdwSysStatus ();

      //## Attribute: cdwSysCmd%3F30A33B0213
      static const DWORD GetcdwSysCmd ();

      //## Attribute: cdwSysMode%3F30A33C033C
      static const DWORD GetcdwSysMode ();

      //## Attribute: cdwSysMXmitHostAdr%3F30A33D004E
      static const DWORD GetcdwSysMXmitHostAdr ();

      //## Attribute: cdwIrqClearIrq%3F30A3FE0290
      static const DWORD GetcdwIrqClearIrq ();

      //## Attribute: cdwIrqEnableIrq%3F30A4470128
      static const DWORD GetcdwIrqEnableIrq ();

    // Additional Public Declarations
      //## begin CHITPCIAccess%3E8BE636034B.public preserve=yes
      //## end CHITPCIAccess%3E8BE636034B.public

  protected:
    // Additional Protected Declarations
      //## begin CHITPCIAccess%3E8BE636034B.protected preserve=yes
      //## end CHITPCIAccess%3E8BE636034B.protected

  private:
    //## Constructors (generated)
      CHITPCIAccess();

      CHITPCIAccess(const CHITPCIAccess &right);

    //## Assignment Operation (generated)
      const CHITPCIAccess & operator=(const CHITPCIAccess &right);

    //## Equality Operations (generated)
      bool operator==(const CHITPCIAccess &right) const;

      bool operator!=(const CHITPCIAccess &right) const;

    // Data Members for Class Attributes

      //## begin CHITPCIAccess::cdwSysStatus%3F30A21B0167.attr preserve=no  public: static DWORD {UC} 0x0
      static const DWORD  m_cdwSysStatus;
      //## end CHITPCIAccess::cdwSysStatus%3F30A21B0167.attr

      //## begin CHITPCIAccess::cdwSysCmd%3F30A33B0213.attr preserve=no  public: static DWORD {UC} 0x4
      static const DWORD  m_cdwSysCmd;
      //## end CHITPCIAccess::cdwSysCmd%3F30A33B0213.attr

      //## begin CHITPCIAccess::cdwSysMode%3F30A33C033C.attr preserve=no  public: static DWORD {UC} 0x8
      static const DWORD  m_cdwSysMode;
      //## end CHITPCIAccess::cdwSysMode%3F30A33C033C.attr

      //## begin CHITPCIAccess::cdwSysMXmitHostAdr%3F30A33D004E.attr preserve=no  public: static DWORD {UC} 0x10
      static const DWORD  m_cdwSysMXmitHostAdr;
      //## end CHITPCIAccess::cdwSysMXmitHostAdr%3F30A33D004E.attr

      //## begin CHITPCIAccess::cdwIrqClearIrq%3F30A3FE0290.attr preserve=no  public: static DWORD {UC} 0x20
      static const DWORD  m_cdwIrqClearIrq;
      //## end CHITPCIAccess::cdwIrqClearIrq%3F30A3FE0290.attr

      //## begin CHITPCIAccess::cdwIrqEnableIrq%3F30A4470128.attr preserve=no  public: static DWORD {UC} 0x24
      static const DWORD  m_cdwIrqEnableIrq;
      //## end CHITPCIAccess::cdwIrqEnableIrq%3F30A4470128.attr

    // Additional Private Declarations
      //## begin CHITPCIAccess%3E8BE636034B.private preserve=yes
      //## end CHITPCIAccess%3E8BE636034B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHITPCIAccess%3E8BE636034B.implementation preserve=yes
      //## end CHITPCIAccess%3E8BE636034B.implementation

};

//## begin CHITPCIAccess%3E8BE636034B.postscript preserve=yes
//## end CHITPCIAccess%3E8BE636034B.postscript

// Class CHITPCIAccess 

//## begin module%3E8BE6A001D4.epilog preserve=yes
//## end module%3E8BE6A001D4.epilog


#endif
