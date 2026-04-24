//## begin module%3DE5EB2C0072.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB2C0072.cm

//## begin module%3DE5EB2C0072.cp preserve=no
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
//## end module%3DE5EB2C0072.cp

//## Module: EBPOimpl%3DE5EB2C0072; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOimpl.h

#ifndef EBPOimpl_h
#define EBPOimpl_h 1

//## begin module%3DE5EB2C0072.additionalIncludes preserve=no
//## end module%3DE5EB2C0072.additionalIncludes

//## begin module%3DE5EB2C0072.includes preserve=yes
//## end module%3DE5EB2C0072.includes

// EBCOimpl
#include "EBCOimpl.h"

class EBPI_DLL_DECL CPIPersistentConfig;
class EBPO_DLL_DECL CPOPersistentObjInterface;
class CPOLifeTimeCounterHandler;
class CPOLogic;

//## begin module%3DE5EB2C0072.declarations preserve=no
//## end module%3DE5EB2C0072.declarations

//## begin module%3DE5EB2C0072.additionalDeclarations preserve=yes
//## end module%3DE5EB2C0072.additionalDeclarations


//## begin CPOPersistentObjImplementation%3DE633A00247.preface preserve=yes
//## end CPOPersistentObjImplementation%3DE633A00247.preface

//## Class: CPOPersistentObjImplementation%3DE633A00247
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE6351003CD;CPOPersistentObjInterface { -> F}
//## Uses: <unnamed>%3DE641A30237;CPOStateMachineEngine { -> }

class CPOPersistentObjImplementation : public ICOAsyncImplementation  //## Inherits: <unnamed>%3DE633BC0350
{
  //## begin CPOPersistentObjImplementation%3DE633A00247.initialDeclarations preserve=yes
  //## end CPOPersistentObjImplementation%3DE633A00247.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOPersistentObjImplementation%1038495055
      CPOPersistentObjImplementation (CPOPersistentObjInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~CPOPersistentObjImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%1038495056
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9D154D021F
      //## Role: CPOPersistentObjImplementation::pLogic%3F9D154E03E4
      CPOLogic * GetpLogic ();

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9D4131006A
      //## Role: CPOPersistentObjImplementation::pLifeTimeCounterHandler%3F9D41310378
      CPOLifeTimeCounterHandler * GetpLifeTimeCounterHandler ();

      //## Association: EBPO (Persistent Object)::<unnamed>%403F138303A9
      //## Role: CPOPersistentObjImplementation::pConfig%403F13840187
      CPIPersistentConfig * GetpConfig ();
      void SetpConfig (CPIPersistentConfig * value);

      //## Association: EBPO (Persistent Object)::<unnamed>%4057FC0D01FF
      //## Role: CPOPersistentObjImplementation::uiID%4057FC0E004B
      UINT GetuiID ();

    // Additional Public Declarations
      //## begin CPOPersistentObjImplementation%3DE633A00247.public preserve=yes
      //## end CPOPersistentObjImplementation%3DE633A00247.public

  protected:
    // Additional Protected Declarations
      //## begin CPOPersistentObjImplementation%3DE633A00247.protected preserve=yes
      //## end CPOPersistentObjImplementation%3DE633A00247.protected

  private:
    //## Constructors (generated)
      CPOPersistentObjImplementation();

      CPOPersistentObjImplementation(const CPOPersistentObjImplementation &right);

    //## Assignment Operation (generated)
      const CPOPersistentObjImplementation & operator=(const CPOPersistentObjImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CPOPersistentObjImplementation &right) const;

      bool operator!=(const CPOPersistentObjImplementation &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9D154D021F
      //## begin CPOPersistentObjImplementation::pLogic%3F9D154E03E4.role preserve=no  public: CPOLogic {1..1 -> 1..1RFHN}
      CPOLogic *m_pLogic;
      //## end CPOPersistentObjImplementation::pLogic%3F9D154E03E4.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9D4131006A
      //## begin CPOPersistentObjImplementation::pLifeTimeCounterHandler%3F9D41310378.role preserve=no  public: CPOLifeTimeCounterHandler {1..1 -> 1..1RFHN}
      CPOLifeTimeCounterHandler *m_pLifeTimeCounterHandler;
      //## end CPOPersistentObjImplementation::pLifeTimeCounterHandler%3F9D41310378.role

      //## Association: EBPO (Persistent Object)::<unnamed>%403F138303A9
      //## begin CPOPersistentObjImplementation::pConfig%403F13840187.role preserve=no  public: CPIPersistentConfig {1..1 -> 1..1RFHN}
      CPIPersistentConfig *m_pConfig;
      //## end CPOPersistentObjImplementation::pConfig%403F13840187.role

      //## Association: EBPO (Persistent Object)::<unnamed>%4057FC0D01FF
      //## begin CPOPersistentObjImplementation::uiID%4057FC0E004B.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CPOPersistentObjImplementation::uiID%4057FC0E004B.role

    // Additional Private Declarations
      //## begin CPOPersistentObjImplementation%3DE633A00247.private preserve=yes
      //## end CPOPersistentObjImplementation%3DE633A00247.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOPersistentObjImplementation%3DE633A00247.implementation preserve=yes
      //## end CPOPersistentObjImplementation%3DE633A00247.implementation

};

//## begin CPOPersistentObjImplementation%3DE633A00247.postscript preserve=yes
//## end CPOPersistentObjImplementation%3DE633A00247.postscript

// Class CPOPersistentObjImplementation 

//## begin module%3DE5EB2C0072.epilog preserve=yes
//## end module%3DE5EB2C0072.epilog


#endif
