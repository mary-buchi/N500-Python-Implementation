//## begin module%3F9E1DB902A6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F9E1DB902A6.cm

//## begin module%3F9E1DB902A6.cp preserve=no
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
//## end module%3F9E1DB902A6.cp

//## Module: EBPOcounter%3F9E1DB902A6; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcounter.h

#ifndef EBPOcounter_h
#define EBPOcounter_h 1

//## begin module%3F9E1DB902A6.additionalIncludes preserve=no
//## end module%3F9E1DB902A6.additionalIncludes

//## begin module%3F9E1DB902A6.includes preserve=yes
//## end module%3F9E1DB902A6.includes

// EBPItype
#include "EBPItype.h"

class CPOPersistentObjImplementation;
class CPOLifeTimeCounter;

//## begin module%3F9E1DB902A6.declarations preserve=no
//## end module%3F9E1DB902A6.declarations

//## begin module%3F9E1DB902A6.additionalDeclarations preserve=yes
//## end module%3F9E1DB902A6.additionalDeclarations


//## begin CPOLifeTimeCounterHandler%3F9D409F0358.preface preserve=yes
//## end CPOLifeTimeCounterHandler%3F9D409F0358.preface

//## Class: CPOLifeTimeCounterHandler%3F9D409F0358
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FA8D4410071;CPOLogic { -> }
//## Uses: <unnamed>%3FFE99000140;CHIInterface { -> }

class CPOLifeTimeCounterHandler 
{
  //## begin CPOLifeTimeCounterHandler%3F9D409F0358.initialDeclarations preserve=yes
  //## end CPOLifeTimeCounterHandler%3F9D409F0358.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOLifeTimeCounterHandler%1067267864
      CPOLifeTimeCounterHandler (CPOPersistentObjImplementation* p_pImpl);

    //## Destructor (generated)
      virtual ~CPOLifeTimeCounterHandler();


    //## Other Operations (specified)
      //## Operation: StartMonitoring%1067324997
      void StartMonitoring (EPILifeTimeCounter p_eDevice, const UINT p_uiStartUpValue = 0);

      //## Operation: StopMonitoring%1067324998
      void StopMonitoring (const EPILifeTimeCounter &p_eDevice);

      //## Operation: FindCounter%1067325002
      CPOLifeTimeCounter* FindCounter (const EPILifeTimeCounter p_eCounter);

      //## Operation: AddDeltaValues%1067325004
      void AddDeltaValues (const UINT p_uiDeltaValue);

      //## Operation: NumberOfActivatedCounter%1067325005
      UINT NumberOfActivatedCounter ();

      //## Operation: ResetDeltaValue%1067498934
      void ResetDeltaValue ();

      //## Operation: RemoveNotActivatedCounter%1067498935
      void RemoveNotActivatedCounter ();

      //## Operation: IncElapsedAutoSaveTime%1067498936
      void IncElapsedAutoSaveTime ();

      //## Operation: UpdateEpromValues%1068021105
      void UpdateEpromValues ();

      //## Operation: DeleteCounterList%1080142972
      void DeleteCounterList ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwElapsedAutoSaveTime%3FA0E0BC008C
      DWORD GetdwElapsedAutoSaveTime ();
      void SetdwElapsedAutoSaveTime (DWORD value);

      //## Attribute: dwTicksAtConnLost%405AB4BB02E8
      DWORD GetdwTicksAtConnLost ();
      void SetdwTicksAtConnLost (DWORD value);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9D412E0192
      //## Role: CPOLifeTimeCounterHandler::pImpl%3F9D412F0230
      CPOPersistentObjImplementation * GetpImpl ();

    // Additional Public Declarations
      //## begin CPOLifeTimeCounterHandler%3F9D409F0358.public preserve=yes
      //## end CPOLifeTimeCounterHandler%3F9D409F0358.public

  protected:
    // Additional Protected Declarations
      //## begin CPOLifeTimeCounterHandler%3F9D409F0358.protected preserve=yes
      //## end CPOLifeTimeCounterHandler%3F9D409F0358.protected

  private:
    //## Constructors (generated)
      CPOLifeTimeCounterHandler();

      CPOLifeTimeCounterHandler(const CPOLifeTimeCounterHandler &right);

    //## Assignment Operation (generated)
      const CPOLifeTimeCounterHandler & operator=(const CPOLifeTimeCounterHandler &right);

    //## Equality Operations (generated)
      bool operator==(const CPOLifeTimeCounterHandler &right) const;

      bool operator!=(const CPOLifeTimeCounterHandler &right) const;

    // Data Members for Class Attributes

      //## begin CPOLifeTimeCounterHandler::dwElapsedAutoSaveTime%3FA0E0BC008C.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwElapsedAutoSaveTime;
      //## end CPOLifeTimeCounterHandler::dwElapsedAutoSaveTime%3FA0E0BC008C.attr

      //## begin CPOLifeTimeCounterHandler::dwTicksAtConnLost%405AB4BB02E8.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwTicksAtConnLost;
      //## end CPOLifeTimeCounterHandler::dwTicksAtConnLost%405AB4BB02E8.attr

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9D412E0192
      //## begin CPOLifeTimeCounterHandler::pImpl%3F9D412F0230.role preserve=no  public: CPOPersistentObjImplementation {1..1 -> 1..1RFHN}
      CPOPersistentObjImplementation *m_pImpl;
      //## end CPOLifeTimeCounterHandler::pImpl%3F9D412F0230.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9E1BDE0239
      //## Role: CPOLifeTimeCounterHandler::Counters%3F9E1BDF0027
      //## begin CPOLifeTimeCounterHandler::Counters%3F9E1BDF0027.role preserve=no  public: CPOLifeTimeCounter {0..1 -> *RFHN}
      CTypedPtrList<CPtrList, CPOLifeTimeCounter*> m_Counters;
      //## end CPOLifeTimeCounterHandler::Counters%3F9E1BDF0027.role

      //## Association: EBPO (Persistent Object)::<unnamed>%461395580128
      //## Role: CPOLifeTimeCounterHandler::CounterLock%46139558039A
      //## begin CPOLifeTimeCounterHandler::CounterLock%46139558039A.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_CounterLock;
      //## end CPOLifeTimeCounterHandler::CounterLock%46139558039A.role

    // Additional Private Declarations
      //## begin CPOLifeTimeCounterHandler%3F9D409F0358.private preserve=yes
      //## end CPOLifeTimeCounterHandler%3F9D409F0358.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOLifeTimeCounterHandler%3F9D409F0358.implementation preserve=yes
      //## end CPOLifeTimeCounterHandler%3F9D409F0358.implementation

};

//## begin CPOLifeTimeCounterHandler%3F9D409F0358.postscript preserve=yes
//## end CPOLifeTimeCounterHandler%3F9D409F0358.postscript

//## begin CPOLifeTimeCounter%3F9E1B52015E.preface preserve=yes
//## end CPOLifeTimeCounter%3F9E1B52015E.preface

//## Class: CPOLifeTimeCounter%3F9E1B52015E
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FAA00AC0298;PO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FAA6343022A;PI_CONST { -> }

class CPOLifeTimeCounter : public CPIPersistentLifeTimeCounter  //## Inherits: <unnamed>%3FABBAAF008C
{
  //## begin CPOLifeTimeCounter%3F9E1B52015E.initialDeclarations preserve=yes
  //## end CPOLifeTimeCounter%3F9E1B52015E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOLifeTimeCounter%1067325001
      CPOLifeTimeCounter (const CString& p_sItem);

      //## Operation: CPOLifeTimeCounter%1068448313
      CPOLifeTimeCounter (EPILifeTimeCounter p_eDevice, const UINT p_uiValue = 0, const UINT p_uiDeltaValue = 0);

    //## Destructor (generated)
      virtual ~CPOLifeTimeCounter();


    //## Other Operations (specified)
      //## Operation: IncCounterValue%1073631915
      void IncCounterValue (const UINT p_uiDeltaValue);

      //## Operation: IncDeltaValue%1074066584
      void IncDeltaValue (const UINT p_uiDeltaValue);

      //## Operation: ResetValues%1074066585
      void ResetValues ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9E21FB016E
      //## Role: CPOLifeTimeCounter::uiDeltaValue%3F9E21FB03A1
      UINT GetuiDeltaValue ();
      void SetuiDeltaValue (UINT value);

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9E2A420093
      //## Role: CPOLifeTimeCounter::bMonitoringStarted%3F9E2A4201BC
      bool GetbMonitoringStarted ();
      void SetbMonitoringStarted (bool value);

    // Additional Public Declarations
      //## begin CPOLifeTimeCounter%3F9E1B52015E.public preserve=yes
      //## end CPOLifeTimeCounter%3F9E1B52015E.public

  protected:
    // Additional Protected Declarations
      //## begin CPOLifeTimeCounter%3F9E1B52015E.protected preserve=yes
      //## end CPOLifeTimeCounter%3F9E1B52015E.protected

  private:
    //## Constructors (generated)
      CPOLifeTimeCounter(const CPOLifeTimeCounter &right);

    //## Assignment Operation (generated)
      const CPOLifeTimeCounter & operator=(const CPOLifeTimeCounter &right);

    //## Equality Operations (generated)
      bool operator==(const CPOLifeTimeCounter &right) const;

      bool operator!=(const CPOLifeTimeCounter &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9E21FB016E
      //## begin CPOLifeTimeCounter::uiDeltaValue%3F9E21FB03A1.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiDeltaValue;
      //## end CPOLifeTimeCounter::uiDeltaValue%3F9E21FB03A1.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9E2A420093
      //## begin CPOLifeTimeCounter::bMonitoringStarted%3F9E2A4201BC.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bMonitoringStarted;
      //## end CPOLifeTimeCounter::bMonitoringStarted%3F9E2A4201BC.role

    // Additional Private Declarations
      //## begin CPOLifeTimeCounter%3F9E1B52015E.private preserve=yes
      //## end CPOLifeTimeCounter%3F9E1B52015E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOLifeTimeCounter%3F9E1B52015E.implementation preserve=yes
      //## end CPOLifeTimeCounter%3F9E1B52015E.implementation

};

//## begin CPOLifeTimeCounter%3F9E1B52015E.postscript preserve=yes
//## end CPOLifeTimeCounter%3F9E1B52015E.postscript

// Class CPOLifeTimeCounterHandler 

// Class CPOLifeTimeCounter 

//## begin module%3F9E1DB902A6.epilog preserve=yes
//## end module%3F9E1DB902A6.epilog


#endif
