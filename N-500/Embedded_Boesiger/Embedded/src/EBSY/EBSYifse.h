//## begin module%3EF98D1001D3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF98D1001D3.cm

//## begin module%3EF98D1001D3.cp preserve=no
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
//## end module%3EF98D1001D3.cp

//## Module: EBSYifse%3EF98D1001D3; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYifse.h

#ifndef EBSYifse_h
#define EBSYifse_h 1

//## begin module%3EF98D1001D3.additionalIncludes preserve=no
//## end module%3EF98D1001D3.additionalIncludes

//## begin module%3EF98D1001D3.includes preserve=yes
//## end module%3EF98D1001D3.includes

//## begin module%3EF98D1001D3.declarations preserve=no
//## end module%3EF98D1001D3.declarations

//## begin module%3EF98D1001D3.additionalDeclarations preserve=yes
//## end module%3EF98D1001D3.additionalDeclarations


//## begin CSYInterfaceSettings%3EF98D7302DC.preface preserve=yes
//## end CSYInterfaceSettings%3EF98D7302DC.preface

//## Class: CSYInterfaceSettings%3EF98D7302DC
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF998D800AA;CPIInterfaceConfig { -> }

class CSYInterfaceSettings 
{
  //## begin CSYInterfaceSettings%3EF98D7302DC.initialDeclarations preserve=yes
  //## end CSYInterfaceSettings%3EF98D7302DC.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: ReadValue%1056542787
      static CString ReadValue (const CString& p_sKeyName, const CString& p_sValueName);

      //## Operation: WriteValue%1056542788
      static bool WriteValue (const CString& p_sKeyName, const CString& p_sValueName, const CString& p_sValue);

      //## Operation: WriteValue%1091609204
      static bool WriteValue (const CString& p_sKeyName, const CString& p_sValueName, const DWORD& p_dwValue);

      //## Operation: SetIPAddress%1056543512
      static bool SetIPAddress (CPIInterfaceConfig* p_pInterfaceConfig);

    // Additional Public Declarations
      //## begin CSYInterfaceSettings%3EF98D7302DC.public preserve=yes
      //## end CSYInterfaceSettings%3EF98D7302DC.public

  protected:
    // Additional Protected Declarations
      //## begin CSYInterfaceSettings%3EF98D7302DC.protected preserve=yes
      //## end CSYInterfaceSettings%3EF98D7302DC.protected

  private:
    //## Constructors (generated)
      CSYInterfaceSettings(const CSYInterfaceSettings &right);

    //## Assignment Operation (generated)
      const CSYInterfaceSettings & operator=(const CSYInterfaceSettings &right);

    //## Equality Operations (generated)
      bool operator==(const CSYInterfaceSettings &right) const;

      bool operator!=(const CSYInterfaceSettings &right) const;

    // Additional Private Declarations
      //## begin CSYInterfaceSettings%3EF98D7302DC.private preserve=yes
      //## end CSYInterfaceSettings%3EF98D7302DC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYInterfaceSettings%3EF98D7302DC.implementation preserve=yes
      //## end CSYInterfaceSettings%3EF98D7302DC.implementation

};

//## begin CSYInterfaceSettings%3EF98D7302DC.postscript preserve=yes
//## end CSYInterfaceSettings%3EF98D7302DC.postscript

// Class CSYInterfaceSettings 

//## begin module%3EF98D1001D3.epilog preserve=yes
//## end module%3EF98D1001D3.epilog


#endif
