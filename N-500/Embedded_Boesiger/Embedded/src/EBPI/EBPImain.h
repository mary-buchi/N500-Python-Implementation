//## begin module%3DA48877004B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA48877004B.cm

//## begin module%3DA48877004B.cp preserve=no
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
//## end module%3DA48877004B.cp

//## Module: EBPImain%3DA48877004B; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPImain.h

#ifndef EBPImain_h
#define EBPImain_h 1

//## begin module%3DA48877004B.additionalIncludes preserve=no
//## end module%3DA48877004B.additionalIncludes

//## begin module%3DA48877004B.includes preserve=yes
//## end module%3DA48877004B.includes


class CPIDriverEntry;

//## begin module%3DA48877004B.declarations preserve=no
//## end module%3DA48877004B.declarations

//## begin module%3DA48877004B.additionalDeclarations preserve=yes
//## end module%3DA48877004B.additionalDeclarations


//## begin CPIDriverFactory%3DA48A7A00F6.preface preserve=yes
//## end CPIDriverFactory%3DA48A7A00F6.preface

//## Class: CPIDriverFactory%3DA48A7A00F6
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPIDriverFactory 
{
  //## begin CPIDriverFactory%3DA48A7A00F6.initialDeclarations preserve=yes
  //## end CPIDriverFactory%3DA48A7A00F6.initialDeclarations

  public:
    //## Constructors (generated)
      CPIDriverFactory();

    //## Destructor (generated)
      virtual ~CPIDriverFactory();


    //## Other Operations (specified)
      //## Operation: Create%1034190395
      static void Create ();

      //## Operation: Delete%1034190396
      static void Delete ();

      //## Operation: GetInstance%1034190397
      static CPIDriverFactory* GetInstance ();

      //## Operation: LoadDrivers%1034190398
      void LoadDrivers ();

      //## Operation: Start%1034190400
      void Start ();

      //## Operation: Stop%1056354243
      void Stop ();

    // Additional Public Declarations
      //## begin CPIDriverFactory%3DA48A7A00F6.public preserve=yes
      //## end CPIDriverFactory%3DA48A7A00F6.public

  protected:
    // Additional Protected Declarations
      //## begin CPIDriverFactory%3DA48A7A00F6.protected preserve=yes
      //## end CPIDriverFactory%3DA48A7A00F6.protected

  private:
    //## Constructors (generated)
      CPIDriverFactory(const CPIDriverFactory &right);

    //## Assignment Operation (generated)
      const CPIDriverFactory & operator=(const CPIDriverFactory &right);

    //## Equality Operations (generated)
      bool operator==(const CPIDriverFactory &right) const;

      bool operator!=(const CPIDriverFactory &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3DA48A910121
      //## Role: CPIDriverFactory::pInstance%3DA48A9203C2
      //## begin CPIDriverFactory::pInstance%3DA48A9203C2.role preserve=no  public: static CPIDriverFactory {1..1 -> 1..1RFHN}
      static CPIDriverFactory *m_pInstance;
      //## end CPIDriverFactory::pInstance%3DA48A9203C2.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DA48C15011F
      //## Role: CPIDriverFactory::pTcpDriver%3DA48C1503AB
      //## begin CPIDriverFactory::pTcpDriver%3DA48C1503AB.role preserve=no  public: CPIDriverEntry {1..1 -> 1..1RFHN}
      CPIDriverEntry *m_pTcpDriver;
      //## end CPIDriverFactory::pTcpDriver%3DA48C1503AB.role

    // Additional Private Declarations
      //## begin CPIDriverFactory%3DA48A7A00F6.private preserve=yes
      //## end CPIDriverFactory%3DA48A7A00F6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIDriverFactory%3DA48A7A00F6.implementation preserve=yes
      //## end CPIDriverFactory%3DA48A7A00F6.implementation

};

//## begin CPIDriverFactory%3DA48A7A00F6.postscript preserve=yes
//## end CPIDriverFactory%3DA48A7A00F6.postscript

//## begin CPISystem%3DA4895803CA.preface preserve=yes
//## end CPISystem%3DA4895803CA.preface

//## Class: CPISystem%3DA4895803CA
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA5459F0326;CPIDriverFactory { -> }
//## Uses: <unnamed>%3DA545A90336;CPIObjectFactory { -> }
//## Uses: <unnamed>%3F4328480370;CPIComponentsState { -> }
//## Uses: <unnamed>%3FA10B75030D;PI_IDENTIFIERS { -> }

class EBPI_DLL_DECL CPISystem 
{
  //## begin CPISystem%3DA4895803CA.initialDeclarations preserve=yes
  //## end CPISystem%3DA4895803CA.initialDeclarations

  public:
    //## Constructors (generated)
      CPISystem();

    //## Destructor (generated)
      virtual ~CPISystem();


    //## Other Operations (specified)
      //## Operation: Create%1034190393
      static void Create ();

      //## Operation: Start%1055492123
      static void Start ();

      //## Operation: Stop%1056354244
      static void Stop ();

      //## Operation: Delete%1034190394
      static void Delete ();

    // Additional Public Declarations
      //## begin CPISystem%3DA4895803CA.public preserve=yes
      //## end CPISystem%3DA4895803CA.public

  protected:
    // Additional Protected Declarations
      //## begin CPISystem%3DA4895803CA.protected preserve=yes
      //## end CPISystem%3DA4895803CA.protected

  private:
    //## Constructors (generated)
      CPISystem(const CPISystem &right);

    //## Assignment Operation (generated)
      const CPISystem & operator=(const CPISystem &right);

    //## Equality Operations (generated)
      bool operator==(const CPISystem &right) const;

      bool operator!=(const CPISystem &right) const;

    // Additional Private Declarations
      //## begin CPISystem%3DA4895803CA.private preserve=yes
      //## end CPISystem%3DA4895803CA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPISystem%3DA4895803CA.implementation preserve=yes
      //## end CPISystem%3DA4895803CA.implementation

};

//## begin CPISystem%3DA4895803CA.postscript preserve=yes
//## end CPISystem%3DA4895803CA.postscript

//## begin TINVOKE_DRIVER_PROC%3DA48D3B03AD.preface preserve=yes
//## end TINVOKE_DRIVER_PROC%3DA48D3B03AD.preface

//## Class: TINVOKE_DRIVER_PROC%3DA48D3B03AD
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef void (*TINVOKE_DRIVER_PROC)();

//## begin TINVOKE_DRIVER_PROC%3DA48D3B03AD.postscript preserve=yes
//## end TINVOKE_DRIVER_PROC%3DA48D3B03AD.postscript

//## begin CPIDriverEntry%3DA48BB70124.preface preserve=yes
//## end CPIDriverEntry%3DA48BB70124.preface

//## Class: CPIDriverEntry%3DA48BB70124
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPIDriverEntry 
{
  //## begin CPIDriverEntry%3DA48BB70124.initialDeclarations preserve=yes
  //## end CPIDriverEntry%3DA48BB70124.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIDriverEntry%1034190399
      CPIDriverEntry (HMODULE p_hLibrary, TINVOKE_DRIVER_PROC p_fnInvokeMethod, TINVOKE_DRIVER_PROC p_fnShutdownMethod);

    //## Destructor (generated)
      virtual ~CPIDriverEntry();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3DA48D7F029C
      //## Role: CPIDriverEntry::pInvokeMethod%3DA48D800104
      TINVOKE_DRIVER_PROC GetpInvokeMethod ();

      //## Association: EBPI (PC Interface)::<unnamed>%3DA48E6E010F
      //## Role: CPIDriverEntry::hLibrary%3DA48E6E03E1
      HMODULE GethLibrary ();

      //## Association: EBPI (PC Interface)::<unnamed>%3DA491650373
      //## Role: CPIDriverEntry::pShutdownMethod%3DA491660217
      TINVOKE_DRIVER_PROC GetpShutdownMethod ();

    // Additional Public Declarations
      //## begin CPIDriverEntry%3DA48BB70124.public preserve=yes
      //## end CPIDriverEntry%3DA48BB70124.public

  protected:
    // Additional Protected Declarations
      //## begin CPIDriverEntry%3DA48BB70124.protected preserve=yes
      //## end CPIDriverEntry%3DA48BB70124.protected

  private:
    //## Constructors (generated)
      CPIDriverEntry();

      CPIDriverEntry(const CPIDriverEntry &right);

    //## Assignment Operation (generated)
      const CPIDriverEntry & operator=(const CPIDriverEntry &right);

    //## Equality Operations (generated)
      bool operator==(const CPIDriverEntry &right) const;

      bool operator!=(const CPIDriverEntry &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3DA48D7F029C
      //## begin CPIDriverEntry::pInvokeMethod%3DA48D800104.role preserve=no  public: TINVOKE_DRIVER_PROC {1..1 -> 1..1VHN}
      TINVOKE_DRIVER_PROC m_pInvokeMethod;
      //## end CPIDriverEntry::pInvokeMethod%3DA48D800104.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DA48E6E010F
      //## begin CPIDriverEntry::hLibrary%3DA48E6E03E1.role preserve=no  public: HMODULE {1..1 -> 1..1VFHN}
      HMODULE m_hLibrary;
      //## end CPIDriverEntry::hLibrary%3DA48E6E03E1.role

      //## Association: EBPI (PC Interface)::<unnamed>%3DA491650373
      //## begin CPIDriverEntry::pShutdownMethod%3DA491660217.role preserve=no  public: TINVOKE_DRIVER_PROC {1..1 -> 1..1VFHN}
      TINVOKE_DRIVER_PROC m_pShutdownMethod;
      //## end CPIDriverEntry::pShutdownMethod%3DA491660217.role

    // Additional Private Declarations
      //## begin CPIDriverEntry%3DA48BB70124.private preserve=yes
      //## end CPIDriverEntry%3DA48BB70124.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIDriverEntry%3DA48BB70124.implementation preserve=yes
      //## end CPIDriverEntry%3DA48BB70124.implementation

};

//## begin CPIDriverEntry%3DA48BB70124.postscript preserve=yes
//## end CPIDriverEntry%3DA48BB70124.postscript

// Class CPIDriverFactory 

// Class CPISystem 

// Class CPIDriverEntry 

//## begin module%3DA48877004B.epilog preserve=yes
//## end module%3DA48877004B.epilog


#endif
