//## begin module%3F9D14DA00E7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F9D14DA00E7.cm

//## begin module%3F9D14DA00E7.cp preserve=no
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
//## end module%3F9D14DA00E7.cp

//## Module: EBPOlogic%3F9D14DA00E7; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOlogic.h

#ifndef EBPOlogic_h
#define EBPOlogic_h 1

//## begin module%3F9D14DA00E7.additionalIncludes preserve=no
//## end module%3F9D14DA00E7.additionalIncludes

//## begin module%3F9D14DA00E7.includes preserve=yes
//## end module%3F9D14DA00E7.includes

// EBPIenum
#include "EBPIenum.h"

class EBPI_DLL_DECL CPIPersistentItem;
class EBPI_DLL_DECL CPIPersistentIdent;
class EBPI_DLL_DECL CPIPersistentPara;
class CPOPersistentObjImplementation;
class CPOEpromManager;
class CPOLifeTimeCounter;

//## begin module%3F9D14DA00E7.declarations preserve=no
//## end module%3F9D14DA00E7.declarations

//## begin module%3F9D14DA00E7.additionalDeclarations preserve=yes
//## end module%3F9D14DA00E7.additionalDeclarations


//## begin CPOLogic%3F9D1517006A.preface preserve=yes
//## end CPOLogic%3F9D1517006A.preface

//## Class: CPOLogic%3F9D1517006A
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FA8D4B10003;CPOLifeTimeCounter { -> F}
//## Uses: <unnamed>%3FAFAB7901F4;CPIPersistentPara { -> F}
//## Uses: <unnamed>%3FAFAB9E00AB;CPIPersistentIdent { -> F}
//## Uses: <unnamed>%3FF985CC03C0;CPIPersistentItem { -> F}
//## Uses: <unnamed>%403F127D0232;EPILifeTimeCounter { -> }

class CPOLogic 
{
  //## begin CPOLogic%3F9D1517006A.initialDeclarations preserve=yes
  //## end CPOLogic%3F9D1517006A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOLogic%1067262117
      CPOLogic (CPOPersistentObjImplementation* p_pImpl);

    //## Destructor (generated)
      virtual ~CPOLogic();


    //## Other Operations (specified)
      //## Operation: WriteParameter%1068021101
      void WriteParameter (CPIPersistentPara* p_pPara);

      //## Operation: WriteLifeTimeCounter%1068021103
      void WriteLifeTimeCounter (const EPILifeTimeCounter p_eDevice, const UINT p_uiValue);

      //## Operation: UpdateLifeTimeCounter%1068021104
      void UpdateLifeTimeCounter (CPOLifeTimeCounter *p_pCounter);

      //## Operation: WriteIdent%1068448311
      void WriteIdent (CPIPersistentIdent* p_pIdent);

      //## Operation: Save%1068458451
      void Save ();

      //## Operation: Reset%1073378942
      void Reset (EPIEpromSection p_eSection);

      //## Operation: ReadIdentifications%1073292443
      void ReadIdentifications (CTypedPtrList<CPtrList, CPIPersistentItem*> &p_List);

      //## Operation: ReadParameter%1073460971
      void ReadParameter (CTypedPtrList<CPtrList, CPIPersistentItem*> &p_List);

      //## Operation: ReadLifeTimeCounter%1073460972
      int ReadLifeTimeCounter (EPILifeTimeCounter p_eDevice);

      //## Operation: SaveLifeTime%1073631916
      void SaveLifeTime ();

      //## Operation: SetConfig%1079509389
      void SetConfig ();

      //## Operation: MCUndock%1107449341
      void MCUndock ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA8B49F0255
      //## Role: CPOLogic::pEprom%3FA8B4A0012D
      CPOEpromManager * GetpEprom ();

    // Additional Public Declarations
      //## begin CPOLogic%3F9D1517006A.public preserve=yes
      //## end CPOLogic%3F9D1517006A.public

  protected:
    // Additional Protected Declarations
      //## begin CPOLogic%3F9D1517006A.protected preserve=yes
      //## end CPOLogic%3F9D1517006A.protected

  private:
    //## Constructors (generated)
      CPOLogic(const CPOLogic &right);

    //## Assignment Operation (generated)
      const CPOLogic & operator=(const CPOLogic &right);

    //## Equality Operations (generated)
      bool operator==(const CPOLogic &right) const;

      bool operator!=(const CPOLogic &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9D155002CB
      //## Role: CPOLogic::pImpl%3F9D155201D2
      //## begin CPOLogic::pImpl%3F9D155201D2.role preserve=no  public: CPOPersistentObjImplementation {1..1 -> 1..1RFHN}
      CPOPersistentObjImplementation *m_pImpl;
      //## end CPOLogic::pImpl%3F9D155201D2.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA8B49F0255
      //## begin CPOLogic::pEprom%3FA8B4A0012D.role preserve=no  public: CPOEpromManager {1..1 -> 1..1RFHN}
      CPOEpromManager *m_pEprom;
      //## end CPOLogic::pEprom%3FA8B4A0012D.role

    // Additional Private Declarations
      //## begin CPOLogic%3F9D1517006A.private preserve=yes
      //## end CPOLogic%3F9D1517006A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOLogic%3F9D1517006A.implementation preserve=yes
      //## end CPOLogic%3F9D1517006A.implementation

};

//## begin CPOLogic%3F9D1517006A.postscript preserve=yes
//## end CPOLogic%3F9D1517006A.postscript

// Class CPOLogic 

//## begin module%3F9D14DA00E7.epilog preserve=yes
//## end module%3F9D14DA00E7.epilog


#endif
