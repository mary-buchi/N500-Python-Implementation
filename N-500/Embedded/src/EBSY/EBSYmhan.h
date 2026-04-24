//## begin module%3ED367D0025E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ED367D0025E.cm

//## begin module%3ED367D0025E.cp preserve=no
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
//## end module%3ED367D0025E.cp

//## Module: EBSYmhan%3ED367D0025E; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYmhan.h

#ifndef EBSYmhan_h
#define EBSYmhan_h 1

//## begin module%3ED367D0025E.additionalIncludes preserve=no
//## end module%3ED367D0025E.additionalIncludes

//## begin module%3ED367D0025E.includes preserve=yes
//## end module%3ED367D0025E.includes



//## begin module%3ED367D0025E.declarations preserve=no
//## end module%3ED367D0025E.declarations

//## begin module%3ED367D0025E.additionalDeclarations preserve=yes
#ifdef _WIN32_WCE
static CString sMainDLLLocation     = _T("\\Hard Disk\\NIRFlex\\");
//static CString sOldDLLLocation      = _T("\\Hard Disk\\NIRFlexOld\\");
//static CString sNewDLLLocation      = _T("\\Hard Disk\\NIRFlexNew\\");
static wchar_t sOldDLLLocation[]      = L"\\Hard Disk\\NIRFlexOld";
static wchar_t sNewDLLLocation[]      = L"\\Hard Disk\\NIRFlexNew";
static CString sRunDLLLocation      = _T("\\Windows\\");
static CString sFPGASrcLocation     = _T("\\Windows\\");
static CString sFPGADlToolLocation  = _T("\\Windows\\FPGAdl.exe");
static CString sWinCEImageLocation  = _T("\\Hard Disk");
static CString sMarkerFile          = _T("FTC.dmy");
static CString sTempDLLLocation  = _T("\\Hard Disk\\TempDownload");
#else
static CString sMainDLLLocation = _T("R:\\Embedded\\Bin\\Flash\\Debug\\");
static CString sOldDLLLocation  = _T("R:\\Embedded\\Bin\\Flash\\Debug\\Old");
static CString sNewDLLLocation  = _T("R:\\Embedded\\Bin\\Flash\\Debug\\New");
static CString sTempDLLLocation  = _T("R:\\Embedded\\Bin\\Flash\\TempDownload");
static CString sRunDLLLocation  = _T("R:\\Embedded\\Bin\\Debug\\");
static CString sWinCEImageLocation  = _T("R:\\Embedded\\Bin\\Flash");
static CString sMarkerFile      = _T("FTC.dmy");
#endif
//## end module%3ED367D0025E.additionalDeclarations


//## begin CSYModuleHandling%3ED32C79029C.preface preserve=yes
//## end CSYModuleHandling%3ED32C79029C.preface

//## Class: CSYModuleHandling%3ED32C79029C
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ED35CFB0339;SSYDLLDirectory { -> }
//## Uses: <unnamed>%3F7290DE020A;SY_IDENTIFIERS { -> }
//## Uses: <unnamed>%40979B4D029C;SY_IDENTIFIERS { -> }
//## Uses: <unnamed>%40979B6200E7;XCOExceptionCleanupInitialize { -> }

class CSYModuleHandling 
{
  //## begin CSYModuleHandling%3ED32C79029C.initialDeclarations preserve=yes
  //## end CSYModuleHandling%3ED32C79029C.initialDeclarations

  public:
    //## Constructors (generated)
      CSYModuleHandling();

    //## Destructor (generated)
      virtual ~CSYModuleHandling();


    //## Other Operations (specified)
      //## Operation: LoadAllDLLs%1054039295
      static bool LoadAllDLLs (bool p_bLoadAtStart);

      //## Operation: UnloadAllDLLs%1054039296
      static bool UnloadAllDLLs ();

      //## Operation: RegisterAllInterfaces%1054039297
      static bool RegisterAllInterfaces (bool p_bLoadAtStart);

      //## Operation: DeRegisterAllInterfaces%1054039298
      static bool DeRegisterAllInterfaces ();

      //## Operation: ReadAllDLLVersions%1056436737
      static bool ReadAllDLLVersions (CMapStringToString& p_rDLLVersionList);

      //## Operation: GetDLLVersion%1055830876
      static CString GetDLLVersion (const CString& p_sDLLName);

      //## Operation: LoadDLL%1055830870
      static HMODULE LoadDLL (const CString& p_sDLLName);

      //## Operation: UnLoadDLL%1055830871
      static bool UnLoadDLL (const CString& p_sDLLName);

      //## Operation: UnLoadDynamicDLLs%1159966958
      static void UnLoadDynamicDLLs ();

      //## Operation: RegisterInterface%1055830873
      static bool RegisterInterface (const CString& p_sDLLName);

      //## Operation: DeRegisterInterface%1055830874
      static bool DeRegisterInterface (const CString& p_sDLLName);

      //## Operation: GetFirstDLLName%1055830877
      static CString GetFirstDLLName (POSITION& p_pPosition);

      //## Operation: GetNextDLLName%1055830878
      static CString GetNextDLLName (POSITION& p_pPosition);

      //## Operation: GetDLLHandle%1055830872
      static HMODULE GetDLLHandle (const CString& p_sDLLName);

      //## Operation: SetDLLHandle%1055830875
      static void SetDLLHandle (const CString& p_sDLLName, const HMODULE p_hDLL);

      //## Operation: CleanupBackupDLLs%1057322344
      static void CleanupBackupDLLs ();

      //## Operation: LoadAtStart%1074156378
      static bool LoadAtStart (const CString& p_sDLLName);

    // Additional Public Declarations
      //## begin CSYModuleHandling%3ED32C79029C.public preserve=yes
      //## end CSYModuleHandling%3ED32C79029C.public

  protected:
    // Additional Protected Declarations
      //## begin CSYModuleHandling%3ED32C79029C.protected preserve=yes
      //## end CSYModuleHandling%3ED32C79029C.protected

  private:
    //## Constructors (generated)
      CSYModuleHandling(const CSYModuleHandling &right);

    //## Assignment Operation (generated)
      const CSYModuleHandling & operator=(const CSYModuleHandling &right);

    //## Equality Operations (generated)
      bool operator==(const CSYModuleHandling &right) const;

      bool operator!=(const CSYModuleHandling &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EEED3620140
      //## Role: CSYModuleHandling::aLoadedDLLs%3EEED3620315
      //## begin CSYModuleHandling::aLoadedDLLs%3EEED3620315.role preserve=no  public: static CMapStringToPtr { -> VFHN}
      static CMapStringToPtr m_aLoadedDLLs;
      //## end CSYModuleHandling::aLoadedDLLs%3EEED3620315.role

      //## Association: EBSY (System Control)::<unnamed>%4099084E0368
      //## Role: CSYModuleHandling::RegisteredDLLs%4099084F0154
      //## Qualifier: class%4099088D0200; HMODULE
      //## begin CSYModuleHandling::RegisteredDLLs%4099084F0154.role preserve=no  public: static bool { -> VFHN}
      static CMap<HMODULE, HMODULE&, bool, bool&> m_RegisteredDLLs;
      //## end CSYModuleHandling::RegisteredDLLs%4099084F0154.role

    // Additional Private Declarations
      //## begin CSYModuleHandling%3ED32C79029C.private preserve=yes
      //## end CSYModuleHandling%3ED32C79029C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYModuleHandling%3ED32C79029C.implementation preserve=yes
      //## end CSYModuleHandling%3ED32C79029C.implementation

};

//## begin CSYModuleHandling%3ED32C79029C.postscript preserve=yes
//## end CSYModuleHandling%3ED32C79029C.postscript

// Class CSYModuleHandling 

//## begin module%3ED367D0025E.epilog preserve=yes
//## end module%3ED367D0025E.epilog


#endif
