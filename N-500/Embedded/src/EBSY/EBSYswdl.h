//## begin module%3EE0870703B1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE0870703B1.cm

//## begin module%3EE0870703B1.cp preserve=no
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
//## end module%3EE0870703B1.cp

//## Module: EBSYswdl%3EE0870703B1; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYswdl.h

#ifndef EBSYswdl_h
#define EBSYswdl_h 1

//## begin module%3EE0870703B1.additionalIncludes preserve=no
//## end module%3EE0870703B1.additionalIncludes

//## begin module%3EE0870703B1.includes preserve=yes
//## end module%3EE0870703B1.includes

// EBSYcons
#include "EBSYcons.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBPI_DLL_DECL CPIPersistentSoftwareComponentList;

//## begin module%3EE0870703B1.declarations preserve=no
//## end module%3EE0870703B1.declarations

//## begin module%3EE0870703B1.additionalDeclarations preserve=yes
//## end module%3EE0870703B1.additionalDeclarations


//## begin CSYStateConstitutionDownload%47875C020199.preface preserve=yes
//## end CSYStateConstitutionDownload%47875C020199.preface

//## Class: CSYStateConstitutionDownload%47875C020199
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYStateConstitutionDownload : public CSYStateConstitution  //## Inherits: <unnamed>%47875C390288
{
  //## begin CSYStateConstitutionDownload%47875C020199.initialDeclarations preserve=yes
  //## end CSYStateConstitutionDownload%47875C020199.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionDownload();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionDownload();


    //## Other Operations (specified)
      //## Operation: CopyFolder%1200222480
      void CopyFolder (const CString& p_sSrcFolder, const CString& p_sDestFolder);

      //## Operation: ConnectionLost%1200165525
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSYStateConstitutionDownload%47875C020199.public preserve=yes
      //## end CSYStateConstitutionDownload%47875C020199.public

  protected:

    //## Other Operations (specified)
      //## Operation: MakeWritable%1200053479
      void MakeWritable (const CString& p_sFile);

      //## Operation: CleanupTempFolder%1200165527
      void CleanupTempFolder (const CString& p_sFolder);

    // Additional Protected Declarations
      //## begin CSYStateConstitutionDownload%47875C020199.protected preserve=yes
      //## end CSYStateConstitutionDownload%47875C020199.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionDownload(const CSYStateConstitutionDownload &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionDownload & operator=(const CSYStateConstitutionDownload &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionDownload &right) const;

      bool operator!=(const CSYStateConstitutionDownload &right) const;

    // Additional Private Declarations
      //## begin CSYStateConstitutionDownload%47875C020199.private preserve=yes
      //## end CSYStateConstitutionDownload%47875C020199.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionDownload%47875C020199.implementation preserve=yes
      //## end CSYStateConstitutionDownload%47875C020199.implementation

};

//## begin CSYStateConstitutionDownload%47875C020199.postscript preserve=yes
//## end CSYStateConstitutionDownload%47875C020199.postscript

//## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.preface preserve=yes
//## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.preface

//## Class: CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF9536E0054;CSYStateConstitutionConnected { -> }
//## Uses: <unnamed>%3EF953BD0380;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%3F335B6D007D;CSYModuleHandling { -> }
//## Uses: <unnamed>%409629DD00AC;SY_IDENTIFIERS { -> }

class CSYStateConstitutionDownloadSoftwareComponents : public CSYStateConstitutionDownload  //## Inherits: <unnamed>%47875C5D00B3
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.initialDeclarations preserve=yes
  //## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionDownloadSoftwareComponents();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionDownloadSoftwareComponents();


    //## Other Operations (specified)
      //## Operation: Create%1054888632
      static void Create ();

      //## Operation: Delete%1054888634
      static void Delete ();

      //## Operation: GetInstance%1054888633
      static CSYStateConstitutionDownloadSoftwareComponents* GetInstance ();

      //## Operation: GetDeviceState%1056436749
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: Do%1055753505
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBSY (System Control)::<unnamed>%409802810292
      //## Role: CSYStateConstitutionDownloadSoftwareComponents::pSoftwareComponentList%409802820046
      void SetpSoftwareComponentList (CPIPersistentSoftwareComponentList * value);

      //## Association: EBSY (System Control)::<unnamed>%4098E068006A
      //## Role: CSYStateConstitutionDownloadSoftwareComponents::pClientSyncObj%4098E06802FA
      void SetpClientSyncObj (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.public preserve=yes
      //## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.protected preserve=yes
      //## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionDownloadSoftwareComponents(const CSYStateConstitutionDownloadSoftwareComponents &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionDownloadSoftwareComponents & operator=(const CSYStateConstitutionDownloadSoftwareComponents &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionDownloadSoftwareComponents &right) const;

      bool operator!=(const CSYStateConstitutionDownloadSoftwareComponents &right) const;


    //## Other Operations (specified)
      //## Operation: MakeWritable%1083574991
      void MakeWritable (const CString& p_sFile);

    // Data Members for Class Attributes

      //## Attribute: iWinCEPackageCounter%42032B400000
      //## begin CSYStateConstitutionDownloadSoftwareComponents::iWinCEPackageCounter%42032B400000.attr preserve=no  private: int {U} 0
      int m_iWinCEPackageCounter;
      //## end CSYStateConstitutionDownloadSoftwareComponents::iWinCEPackageCounter%42032B400000.attr

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EE07FAE01B2
      //## Role: CSYStateConstitutionDownloadSoftwareComponents::pInstance%3EE07FAE01B4
      //## begin CSYStateConstitutionDownloadSoftwareComponents::pInstance%3EE07FAE01B4.role preserve=no  public: static CSYStateConstitutionDownloadSoftwareComponents {1..1 -> RFHN}
      static CSYStateConstitutionDownloadSoftwareComponents *m_pInstance;
      //## end CSYStateConstitutionDownloadSoftwareComponents::pInstance%3EE07FAE01B4.role

      //## Association: EBSY (System Control)::<unnamed>%409802810292
      //## begin CSYStateConstitutionDownloadSoftwareComponents::pSoftwareComponentList%409802820046.role preserve=no  public: CPIPersistentSoftwareComponentList {1..1 -> 1..1RFHN}
      CPIPersistentSoftwareComponentList *m_pSoftwareComponentList;
      //## end CSYStateConstitutionDownloadSoftwareComponents::pSoftwareComponentList%409802820046.role

      //## Association: EBSY (System Control)::<unnamed>%4098E068006A
      //## begin CSYStateConstitutionDownloadSoftwareComponents::pClientSyncObj%4098E06802FA.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pClientSyncObj;
      //## end CSYStateConstitutionDownloadSoftwareComponents::pClientSyncObj%4098E06802FA.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.private preserve=yes
      //## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.implementation preserve=yes
      //## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.implementation

};

//## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.postscript preserve=yes
//## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.postscript

//## begin CSYStateConstitutionDownloadStarted%47833E1F0237.preface preserve=yes
//## end CSYStateConstitutionDownloadStarted%47833E1F0237.preface

//## Class: CSYStateConstitutionDownloadStarted%47833E1F0237
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYStateConstitutionDownloadStarted : public CSYStateConstitutionDownload  //## Inherits: <unnamed>%47875C330366
{
  //## begin CSYStateConstitutionDownloadStarted%47833E1F0237.initialDeclarations preserve=yes
  //## end CSYStateConstitutionDownloadStarted%47833E1F0237.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionDownloadStarted();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionDownloadStarted();


    //## Other Operations (specified)
      //## Operation: Create%1199783730
      static void Create ();

      //## Operation: Delete%1199783731
      static void Delete ();

      //## Operation: GetInstance%1199783732
      static CSYStateConstitutionDownloadStarted* GetInstance ();

      //## Operation: Enter%1200053480
      //	DESCRIPTION
      //	Enters into a state. Place to set some flags or init
      //	vars.
      //	Actions should be placed in the Do method.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Enter (ICOStateMachineContext* p_pContext);

      //## Operation: DownloadSoftwareComponent%1199783733
      //	DESCRIPTION
      //	Downloads the software components
      //
      //	PARAMETER
      //	- Context
      //	- Component to download
      //
      //	RETURNS
      //	void
      virtual void DownloadSoftwareComponent (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponent* p_pComponent);

      //## Operation: EndDownload%1200222479
      //	DESCRIPTION
      //	Ends and completes a download process
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void EndDownload (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CSYStateConstitutionDownloadStarted%47833E1F0237.public preserve=yes
      //## end CSYStateConstitutionDownloadStarted%47833E1F0237.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionDownloadStarted%47833E1F0237.protected preserve=yes
      //## end CSYStateConstitutionDownloadStarted%47833E1F0237.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionDownloadStarted(const CSYStateConstitutionDownloadStarted &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionDownloadStarted & operator=(const CSYStateConstitutionDownloadStarted &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionDownloadStarted &right) const;

      bool operator!=(const CSYStateConstitutionDownloadStarted &right) const;


    //## Other Operations (specified)
      //## Operation: SaveIPConfig%1200320793
      bool SaveIPConfig ();

      //## Operation: DetermineIPConfig%1200320794
      void DetermineIPConfig (bool& p_bDHCPEnabled, CString& p_sAddress, CString& p_sSubnetMask);

    // Data Members for Class Attributes

      //## Attribute: bReboot%478761A30173
      //## begin CSYStateConstitutionDownloadStarted::bReboot%478761A30173.attr preserve=no  private: bool {U} false
      bool m_bReboot;
      //## end CSYStateConstitutionDownloadStarted::bReboot%478761A30173.attr

      //## Attribute: iCEPackageCnt%4787628C0100
      //## begin CSYStateConstitutionDownloadStarted::iCEPackageCnt%4787628C0100.attr preserve=no  private: int {U} 0
      int m_iCEPackageCnt;
      //## end CSYStateConstitutionDownloadStarted::iCEPackageCnt%4787628C0100.attr

      //## Attribute: bFPGA%47891E990309
      //## begin CSYStateConstitutionDownloadStarted::bFPGA%47891E990309.attr preserve=no  private: bool {U} false
      bool m_bFPGA;
      //## end CSYStateConstitutionDownloadStarted::bFPGA%47891E990309.attr

      //## Attribute: sFPGAImageName%4789F7B90028
      //## begin CSYStateConstitutionDownloadStarted::sFPGAImageName%4789F7B90028.attr preserve=no  private: CString {U} 
      CString m_sFPGAImageName;
      //## end CSYStateConstitutionDownloadStarted::sFPGAImageName%4789F7B90028.attr

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%47833E600370
      //## Role: CSYStateConstitutionDownloadStarted::pInstance%47833E6200A3
      //## begin CSYStateConstitutionDownloadStarted::pInstance%47833E6200A3.role preserve=no  public: static CSYStateConstitutionDownloadStarted {1..1 -> 1..1RFHN}
      static CSYStateConstitutionDownloadStarted *m_pInstance;
      //## end CSYStateConstitutionDownloadStarted::pInstance%47833E6200A3.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionDownloadStarted%47833E1F0237.private preserve=yes
      //## end CSYStateConstitutionDownloadStarted%47833E1F0237.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionDownloadStarted%47833E1F0237.implementation preserve=yes
      //## end CSYStateConstitutionDownloadStarted%47833E1F0237.implementation

};

//## begin CSYStateConstitutionDownloadStarted%47833E1F0237.postscript preserve=yes
//## end CSYStateConstitutionDownloadStarted%47833E1F0237.postscript

// Class CSYStateConstitutionDownload 

// Class CSYStateConstitutionDownloadSoftwareComponents 

// Class CSYStateConstitutionDownloadStarted 

//## begin module%3EE0870703B1.epilog preserve=yes
//## end module%3EE0870703B1.epilog


#endif
