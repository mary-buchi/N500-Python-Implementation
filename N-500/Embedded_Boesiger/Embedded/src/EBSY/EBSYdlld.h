//## begin module%3ED304860171.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ED304860171.cm

//## begin module%3ED304860171.cp preserve=no
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
//## end module%3ED304860171.cp

//## Module: EBSYdlld%3ED304860171; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYdlld.h

#ifndef EBSYdlld_h
#define EBSYdlld_h 1

//## begin module%3ED304860171.additionalIncludes preserve=no
//## end module%3ED304860171.additionalIncludes

//## begin module%3ED304860171.includes preserve=yes
//## end module%3ED304860171.includes

//## begin module%3ED304860171.declarations preserve=no
//## end module%3ED304860171.declarations

//## begin module%3ED304860171.additionalDeclarations preserve=yes
//## end module%3ED304860171.additionalDeclarations


//## begin SSYDLLDirectory%3ED35BE20348.preface preserve=yes
//## end SSYDLLDirectory%3ED35BE20348.preface

//## Class: SSYDLLDirectory%3ED35BE20348
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SSYDLLDirectory 
{
  //## begin SSYDLLDirectory%3ED35BE20348.initialDeclarations preserve=yes
  //## end SSYDLLDirectory%3ED35BE20348.initialDeclarations

  public:
    // Data Members for Class Attributes

      //## Attribute: sDllName%3ED35C91027D
      //## begin SSYDLLDirectory::sDllName%3ED35C91027D.attr preserve=no  public: WCHAR* {U} 
      WCHAR* m_sDllName;
      //## end SSYDLLDirectory::sDllName%3ED35C91027D.attr

      //## Attribute: sCompId%3F433758031C
      //## begin SSYDLLDirectory::sCompId%3F433758031C.attr preserve=no  public: WCHAR* {U} 
      WCHAR* m_sCompId;
      //## end SSYDLLDirectory::sCompId%3F433758031C.attr

      //## Attribute: bLoadAtStart%3ED35CC9006A
      //## begin SSYDLLDirectory::bLoadAtStart%3ED35CC9006A.attr preserve=no  public: bool {U} 
      bool m_bLoadAtStart;
      //## end SSYDLLDirectory::bLoadAtStart%3ED35CC9006A.attr

    // Additional Public Declarations
      //## begin SSYDLLDirectory%3ED35BE20348.public preserve=yes
      //## end SSYDLLDirectory%3ED35BE20348.public

  protected:
    // Additional Protected Declarations
      //## begin SSYDLLDirectory%3ED35BE20348.protected preserve=yes
      //## end SSYDLLDirectory%3ED35BE20348.protected

  private:
    // Additional Private Declarations
      //## begin SSYDLLDirectory%3ED35BE20348.private preserve=yes
      //## end SSYDLLDirectory%3ED35BE20348.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SSYDLLDirectory%3ED35BE20348.implementation preserve=yes
      //## end SSYDLLDirectory%3ED35BE20348.implementation

};

//## begin SSYDLLDirectory%3ED35BE20348.postscript preserve=yes
//## end SSYDLLDirectory%3ED35BE20348.postscript

// Class SSYDLLDirectory 

// Class SSYDLLDirectory 




// Additional Declarations
  //## begin SSYDLLDirectory%3ED35BE20348.declarations preserve=yes

SSYDLLDirectory asCoreDLLDirectory[] =
{
    {_T("EBCO.dll"),        _T("CO"), 0},
    {_T("EBET.dll"),        _T("ET"), 0},
    {_T("EBHI.dll"),        _T("HI"), 0},
    {_T("EBISR.dll"),       _T("ISR"), 0},
    {_T("NIRFlex.exe"),     _T("NF"), 0},
    {_T("EBPCI.dll"),       _T("PCI"), 0},
    {_T("EBPI.dll"),        _T("PI"), 0},
    {_T("EBSY.dll"),        _T("SY"), 0},
	{_T("msvcr90.dll"),		_T("MSVCRT"),0},
    {NULL,                  NULL,     0}
};

SSYDLLDirectory asDLLToLoadDirectory[] =
{
    {_T("EBPO.dll"),        _T("PO"),       1},
    {_T("EBDI.dll"),        _T("DI"),       0},
    {_T("EBES.dll"),        _T("ES"),       0},
    {_T("EBEPROM.dll"),     _T("I2CEPROM"), 1},
    {_T("EBADC.dll"),       _T("I2CADC"),   0},
    {_T("EBDP.dll"),        _T("I2CDP"),    0},
    {_T("EBTEMP.dll"),      _T("I2CTEMP"),  0},
    {_T("EBIO.dll"),        _T("IO"),       0},
    {_T("EBMC.dll"),        _T("MC"),       0},
    {_T("EBPC.dll"),        _T("PC"),       0},
    {_T("EBST.dll"),        _T("ST"),       0},
    {_T("EBTC.dll"),        _T("TC"),       0},
    {_T("EBWC.dll"),        _T("WC"),       0},
    {NULL          ,        NULL,           0}
};

  //## end SSYDLLDirectory%3ED35BE20348.declarations
//## begin module%3ED304860171.epilog preserve=yes
//## end module%3ED304860171.epilog


#endif
