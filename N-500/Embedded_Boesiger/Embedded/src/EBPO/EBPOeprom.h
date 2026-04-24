//## begin module%3FA1183A0399.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA1183A0399.cm

//## begin module%3FA1183A0399.cp preserve=no
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
//## end module%3FA1183A0399.cp

//## Module: EBPOeprom%3FA1183A0399; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOeprom.h

#ifndef EBPOeprom_h
#define EBPOeprom_h 1

//## begin module%3FA1183A0399.additionalIncludes preserve=no
//## end module%3FA1183A0399.additionalIncludes

//## begin module%3FA1183A0399.includes preserve=yes
//## end module%3FA1183A0399.includes

// EBPIenum
#include "EBPIenum.h"
// EBPOenum
#include "EBPOenum.h"

class EBPI_DLL_DECL IPII2CEprom24LC515;
class EBPI_DLL_DECL CPIPersistentItem;
class EBPI_DLL_DECL CPIPersistentIdent;
class EBPI_DLL_DECL CPIPersistentLifeTimeCounter;
class EBPI_DLL_DECL CPIPersistentPara;
class CPOPersistentObjImplementation;
class EBPO_DLL_DECL CPOEpromSimulation;
class CPOLifeTimeCounter;

//## begin module%3FA1183A0399.declarations preserve=no
//## end module%3FA1183A0399.declarations

//## begin module%3FA1183A0399.additionalDeclarations preserve=yes
//## end module%3FA1183A0399.additionalDeclarations


//## begin CPOEpromManager%3FA119170177.preface preserve=yes
//## end CPOEpromManager%3FA119170177.preface

//## Class: CPOEpromManager%3FA119170177
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FA67A2F034B;CPOEpromSimulation { -> }
//## Uses: <unnamed>%3FA8C22400A0;CPIPersistentIdent { -> F}
//## Uses: <unnamed>%3FA8C2260061;CPIPersistentLifeTimeCounter { -> F}
//## Uses: <unnamed>%3FA8C228011D;CPIPersistentPara { -> F}
//## Uses: <unnamed>%3FA8EC3303DC;CPOLifeTimeCounter { -> F}
//## Uses: <unnamed>%3FAA65DC0065;PI_CONST { -> }
//## Uses: <unnamed>%3FF173E1010F;EPIEpromSection { -> }
//## Uses: <unnamed>%3FFD53280322;EPOListType { -> }
//## Uses: <unnamed>%400267C8029D;XPOExceptionHeader { -> }
//## Uses: <unnamed>%4010E163025D;PO_IDENTIFIERS { -> }
//## Uses: <unnamed>%4010EF4E0044;CPIObjectFactory { -> }
//## Uses: <unnamed>%4010EF50029F;CPIComponentsState { -> }

class CPOEpromManager 
{
  //## begin CPOEpromManager%3FA119170177.initialDeclarations preserve=yes
  //## end CPOEpromManager%3FA119170177.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOEpromManager%1067522287
      CPOEpromManager (const DWORD p_dwEpromID, CPOPersistentObjImplementation* p_pImpl);

    //## Destructor (generated)
      virtual ~CPOEpromManager();


    //## Other Operations (specified)
      //## Operation: CreateHeader%1067522279
      CString CreateHeader ();

      //## Operation: EpromCapacity%1072775571
      void EpromCapacity ();

      //## Operation: WritePageBlocks%1068021102
      void WritePageBlocks (const int p_iStartAdr, const CString& p_sContent);

      //## Operation: GetHeaderLength%1068021107
      int GetHeaderLength ();

      //## Operation: CalcNoOfPages%1068021111
      int CalcNoOfPages (const int p_iLength);

      //## Operation: ReadStartAddress%1068021115
      int ReadStartAddress (EPIEpromSection p_eSection);

      //## Operation: CalcStartAddress%1068104009
      int CalcStartAddress (EPIEpromSection p_eSection);

      //## Operation: ReadSectionLength%1068104010
      int ReadSectionLength (EPIEpromSection p_eSection);

      //## Operation: Write%1068104008
      void Write (EPIEpromSection p_eSection);

      //## Operation: CreateSectionString%1068104012
      CString CreateSectionString (EPIEpromSection p_eSection);

      //## Operation: SectionLength%1068104014
      int SectionLength (EPIEpromSection p_eSection);

      //## Operation: Save%1068194979
      void Save ();

      //## Operation: CreateItemList%1068194980
      void CreateItemList (EPIEpromSection p_eSection, CString& p_sSectionString);

      //## Operation: WriteParameter%1068448308
      void WriteParameter (CPIPersistentPara* p_pPara);

      //## Operation: WriteLifeTimeCounter%1068448309
      void WriteLifeTimeCounter (CPOLifeTimeCounter* p_pLifeTime);

      //## Operation: WriteIdentification%1068448310
      void WriteIdentification (CPIPersistentIdent* p_pIdentification);

      //## Operation: Merge%1068458449
      void Merge ();

      //## Operation: UpdateLifeTimeCounter%1068458450
      void UpdateLifeTimeCounter (CPOLifeTimeCounter* p_pLifeTimeCounter);

      //## Operation: ResetMergedList%1068534762
      void ResetMergedList (EPIEpromSection p_eSection);

      //## Operation: ResetNewLists%1068534763
      void ResetNewLists ();

      //## Operation: Reset%1073378944
      void Reset (EPIEpromSection p_eSection);

      //## Operation: FindIdent%1073378945
      bool FindIdent (CPIPersistentIdent* p_pIdent, EPOListType p_eListType);

      //## Operation: FindPara%1073460966
      bool FindPara (CPIPersistentPara* p_pPara, EPOListType p_eListType);

      //## Operation: FindLifeTime%1073460967
      CPOLifeTimeCounter* FindLifeTime (CPOLifeTimeCounter* p_pLifeTime, EPOListType p_eListType);

      //## Operation: ReadSection%1073460968
      CString ReadSection (EPIEpromSection p_eSection);

      //## Operation: ReadAll%1073460969
      void ReadAll ();

      //## Operation: ResetExistingList%1073460970
      void ResetExistingList (EPIEpromSection p_eSection);

      //## Operation: WriteAll%1073556131
      void WriteAll ();

      //## Operation: SaveLifeTime%1073565438
      void SaveLifeTime ();

      //## Operation: ResetUpdatedLifeTimeList%1073631917
      void ResetUpdatedLifeTimeList ();

      //## Operation: RemovePara%1074183149
      //	Removes all parameter from the "new list" with the same
      //	name of paraWanted.
      void RemovePara (CPIPersistentPara* p_pWanted);

      //## Operation: RemoveIdent%1074183150
      void RemoveIdent (CPIPersistentIdent* p_pWanted);

      //## Operation: RemoveLifeTime%1074183151
      void RemoveLifeTime (CPOLifeTimeCounter* p_pWanted);

      //## Operation: ParseHeader%1074239267
      bool ParseHeader (LPCTSTR p_sHeader);

      //## Operation: ReadHeader%1074505551
      CString ReadHeader (bool p_bWithLength);

      //## Operation: ResetExistingLists%1107176860
      void ResetExistingLists ();

      //## Operation: GetEpromHalf%1107176861
      void GetEpromHalf ();

      //## Operation: SetEpromHalf%1107176862
      void SetEpromHalf ();

      //## Operation: UpgradeEpromVersion%1107246382
      void UpgradeEpromVersion ();

      //## Operation: ResetHeader%1108565315
      void ResetHeader ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF3F6D00AB
      //## Role: CPOEpromManager::ParaExistingList%3FAF3F6E01E4
      CTypedPtrList<CPtrList, CPIPersistentItem*>& GetParaExistingList ();

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF40540399
      //## Role: CPOEpromManager::LifeTimeExistingList%3FAF405501D5
      CTypedPtrList<CPtrList, CPIPersistentItem*>& GetLifeTimeExistingList ();

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF405B007D
      //## Role: CPOEpromManager::IdentExistingList%3FAF405C006E
      CTypedPtrList<CPtrList, CPIPersistentItem*>& GetIdentExistingList ();

      //## Association: EBPO (Persistent Object)::<unnamed>%400BA68F0268
      //## Role: CPOEpromManager::bHeaderInfoUpToDate%400BA6900026
      bool GetbHeaderInfoUpToDate ();
      void SetbHeaderInfoUpToDate (bool value);

      //## Association: EBPO (Persistent Object)::<unnamed>%400BA6CD0239
      //## Role: CPOEpromManager::iIdentLength%400BA6CD03DF
      INT GetiIdentLength ();

    // Additional Public Declarations
      //## begin CPOEpromManager%3FA119170177.public preserve=yes
      //## end CPOEpromManager%3FA119170177.public

  protected:
    // Additional Protected Declarations
      //## begin CPOEpromManager%3FA119170177.protected preserve=yes
      //## end CPOEpromManager%3FA119170177.protected

  private:
    //## Constructors (generated)
      CPOEpromManager();

      CPOEpromManager(const CPOEpromManager &right);

    //## Assignment Operation (generated)
      const CPOEpromManager & operator=(const CPOEpromManager &right);

    //## Equality Operations (generated)
      bool operator==(const CPOEpromManager &right) const;

      bool operator!=(const CPOEpromManager &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA1327C034B
      //## Role: CPOEpromManager::bHardwarePresent%3FA1327D01F5
      //## begin CPOEpromManager::bHardwarePresent%3FA1327D01F5.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHardwarePresent;
      //## end CPOEpromManager::bHardwarePresent%3FA1327D01F5.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA65A1F0138
      //## Role: CPOEpromManager::pEpromSimulation%3FA65A1F02DF
      //## begin CPOEpromManager::pEpromSimulation%3FA65A1F02DF.role preserve=no  public: CPOEpromSimulation {1..1 -> 1..1RFHN}
      CPOEpromSimulation *m_pEpromSimulation;
      //## end CPOEpromManager::pEpromSimulation%3FA65A1F02DF.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA8BB4C0013
      //## Role: CPOEpromManager::LifeTimeNewList%3FA8BB4C013D
      //## begin CPOEpromManager::LifeTimeNewList%3FA8BB4C013D.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_LifeTimeNewList;
      //## end CPOEpromManager::LifeTimeNewList%3FA8BB4C013D.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA8BB4D0311
      //## Role: CPOEpromManager::ParaNewList%3FA8BB4E0072
      //## begin CPOEpromManager::ParaNewList%3FA8BB4E0072.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_ParaNewList;
      //## end CPOEpromManager::ParaNewList%3FA8BB4E0072.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA8BFDF0330
      //## Role: CPOEpromManager::IdentNewList%3FA8BFE000DE
      //## begin CPOEpromManager::IdentNewList%3FA8BFE000DE.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_IdentNewList;
      //## end CPOEpromManager::IdentNewList%3FA8BFE000DE.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF3E5F0399
      //## Role: CPOEpromManager::ParaMergedList%3FAF3E60011A
      //## begin CPOEpromManager::ParaMergedList%3FAF3E60011A.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_ParaMergedList;
      //## end CPOEpromManager::ParaMergedList%3FAF3E60011A.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF3F6D00AB
      //## begin CPOEpromManager::ParaExistingList%3FAF3F6E01E4.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_ParaExistingList;
      //## end CPOEpromManager::ParaExistingList%3FAF3F6E01E4.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF40540399
      //## begin CPOEpromManager::LifeTimeExistingList%3FAF405501D5.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_LifeTimeExistingList;
      //## end CPOEpromManager::LifeTimeExistingList%3FAF405501D5.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF405B007D
      //## begin CPOEpromManager::IdentExistingList%3FAF405C006E.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_IdentExistingList;
      //## end CPOEpromManager::IdentExistingList%3FAF405C006E.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF929502FD
      //## Role: CPOEpromManager::LifeTimeMergedList%3FAF929700CC
      //## begin CPOEpromManager::LifeTimeMergedList%3FAF929700CC.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_LifeTimeMergedList;
      //## end CPOEpromManager::LifeTimeMergedList%3FAF929700CC.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FAF929C0148
      //## Role: CPOEpromManager::IdentMergedList%3FAF929D00DA
      //## begin CPOEpromManager::IdentMergedList%3FAF929D00DA.role preserve=no  public: CPIPersistentItem {0..1 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_IdentMergedList;
      //## end CPOEpromManager::IdentMergedList%3FAF929D00DA.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FFD6C710228
      //## Role: CPOEpromManager::UpdateLifeTimeCounterList%3FFD6C720034
      //## begin CPOEpromManager::UpdateLifeTimeCounterList%3FFD6C720034.role preserve=no  public: CPIPersistentItem {0..0 -> 0..nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_UpdateLifeTimeCounterList;
      //## end CPOEpromManager::UpdateLifeTimeCounterList%3FFD6C720034.role

      //## Association: EBPO (Persistent Object)::<unnamed>%40050481038A
      //## Role: CPOEpromManager::pImpl%4005048300DA
      //## begin CPOEpromManager::pImpl%4005048300DA.role preserve=no  public: CPOPersistentObjImplementation {1..1 -> 1..1RFHN}
      CPOPersistentObjImplementation *m_pImpl;
      //## end CPOEpromManager::pImpl%4005048300DA.role

      //## Association: EBPO (Persistent Object)::<unnamed>%400BA68F0268
      //## begin CPOEpromManager::bHeaderInfoUpToDate%400BA6900026.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHeaderInfoUpToDate;
      //## end CPOEpromManager::bHeaderInfoUpToDate%400BA6900026.role

      //## Association: EBPO (Persistent Object)::<unnamed>%400BA6CD0239
      //## begin CPOEpromManager::iIdentLength%400BA6CD03DF.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iIdentLength;
      //## end CPOEpromManager::iIdentLength%400BA6CD03DF.role

      //## Association: EBPO (Persistent Object)::<unnamed>%400BA71002C6
      //## Role: CPOEpromManager::iParaLegth%400BA7110056
      //## begin CPOEpromManager::iParaLegth%400BA7110056.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iParaLegth;
      //## end CPOEpromManager::iParaLegth%400BA7110056.role

      //## Association: EBPO (Persistent Object)::<unnamed>%400BA72F018D
      //## Role: CPOEpromManager::iLifeTimeLegth%400BA72F02F5
      //## begin CPOEpromManager::iLifeTimeLegth%400BA72F02F5.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iLifeTimeLegth;
      //## end CPOEpromManager::iLifeTimeLegth%400BA72F02F5.role

      //## Association: EBPO (Persistent Object)::<unnamed>%400BA8AB0362
      //## Role: CPOEpromManager::iPageSize%400BA8AC014F
      //## begin CPOEpromManager::iPageSize%400BA8AC014F.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iPageSize;
      //## end CPOEpromManager::iPageSize%400BA8AC014F.role

      //## Association: EBPO (Persistent Object)::<unnamed>%400BAA8B0258
      //## Role: CPOEpromManager::iHeaderLength%400BAA8B0343
      //## begin CPOEpromManager::iHeaderLength%400BAA8B0343.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iHeaderLength;
      //## end CPOEpromManager::iHeaderLength%400BAA8B0343.role

      //## Association: EBPO (Persistent Object)::<unnamed>%400CF1D002A7
      //## Role: CPOEpromManager::iEpromSizeInByte%400CF1D10111
      //## begin CPOEpromManager::iEpromSizeInByte%400CF1D10111.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iEpromSizeInByte;
      //## end CPOEpromManager::iEpromSizeInByte%400CF1D10111.role

      //## Association: EBPO (Persistent Object)::<unnamed>%4010D5D000C2
      //## Role: CPOEpromManager::pEprom%4010D5D0020C
      //## begin CPOEpromManager::pEprom%4010D5D0020C.role preserve=no  public: IPII2CEprom24LC515 {1..1 -> 1..1RFHN}
      IPII2CEprom24LC515 *m_pEprom;
      //## end CPOEpromManager::pEprom%4010D5D0020C.role

      //## Association: EBPO (Persistent Object)::<unnamed>%41FE5990023F
      //## Role: CPOEpromManager::iActiveEpromHalf%41FE59910175
      //## begin CPOEpromManager::iActiveEpromHalf%41FE59910175.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iActiveEpromHalf;
      //## end CPOEpromManager::iActiveEpromHalf%41FE59910175.role

      //## Association: EBPO (Persistent Object)::<unnamed>%41FF42B701B8
      //## Role: CPOEpromManager::iHeaderVersion%41FF42B8008F
      //## begin CPOEpromManager::iHeaderVersion%41FF42B8008F.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iHeaderVersion;
      //## end CPOEpromManager::iHeaderVersion%41FF42B8008F.role

    // Additional Private Declarations
      //## begin CPOEpromManager%3FA119170177.private preserve=yes
      //## end CPOEpromManager%3FA119170177.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOEpromManager%3FA119170177.implementation preserve=yes
      //## end CPOEpromManager%3FA119170177.implementation

};

//## begin CPOEpromManager%3FA119170177.postscript preserve=yes
//## end CPOEpromManager%3FA119170177.postscript

// Class CPOEpromManager 

//## begin module%3FA1183A0399.epilog preserve=yes
//## end module%3FA1183A0399.epilog


#endif
