//## begin module%3E5E0B790251.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E5E0B790251.cm

//## begin module%3E5E0B790251.cp preserve=no
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
//## end module%3E5E0B790251.cp

//## Module: EBWCacti%3E5E0B790251; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCacti.h

#ifndef EBWCacti_h
#define EBWCacti_h 1

//## begin module%3E5E0B790251.additionalIncludes preserve=no
//## end module%3E5E0B790251.additionalIncludes

//## begin module%3E5E0B790251.includes preserve=yes
//## end module%3E5E0B790251.includes

// EBCOactn
#include "EBCOactn.h"
// EBHIenum
#include "EBHIenum.h"


//## begin module%3E5E0B790251.declarations preserve=no
//## end module%3E5E0B790251.declarations

//## begin module%3E5E0B790251.additionalDeclarations preserve=yes
//## end module%3E5E0B790251.additionalDeclarations


//## begin CWCActionInitialize%3E5E0B3000EA.preface preserve=yes
//## end CWCActionInitialize%3E5E0B3000EA.preface

//## Class: CWCActionInitialize%3E5E0B3000EA
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E5E0E1402AF;IHIInterface { -> }
//## Uses: <unnamed>%3F9D114D02FD;CWCWedgeControlImplementation { -> }

class CWCActionInitialize : public CCOAction  //## Inherits: <unnamed>%3E5E0B5C0128
{
  //## begin CWCActionInitialize%3E5E0B3000EA.initialDeclarations preserve=yes
  //## end CWCActionInitialize%3E5E0B3000EA.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCActionInitialize%1046351112
      CWCActionInitialize (const UINT p_uiID, ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCActionInitialize();


    //## Other Operations (specified)
      //## Operation: Done%1052827018
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

      //## Operation: Cancel%1164967778
      //	DESCRIPTION
      //	Cancels an action. Resets the current references to
      //	client and server sync objects.
      //
      //	RETURNS
      //	void
      virtual void Cancel ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB781900FA
      //## Role: CWCActionInitialize::dwInitializedEvent%3FBB7819032C
      static DWORD GetdwInitializedEvent ();
      static void SetdwInitializedEvent (DWORD value);

    // Additional Public Declarations
      //## begin CWCActionInitialize%3E5E0B3000EA.public preserve=yes
      //## end CWCActionInitialize%3E5E0B3000EA.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1046351113
      virtual CCOSyncObject* ExecuteAction ();

    // Additional Protected Declarations
      //## begin CWCActionInitialize%3E5E0B3000EA.protected preserve=yes
      //## end CWCActionInitialize%3E5E0B3000EA.protected

  private:
    //## Constructors (generated)
      CWCActionInitialize();

      CWCActionInitialize(const CWCActionInitialize &right);

    //## Assignment Operation (generated)
      const CWCActionInitialize & operator=(const CWCActionInitialize &right);

    //## Equality Operations (generated)
      bool operator==(const CWCActionInitialize &right) const;

      bool operator!=(const CWCActionInitialize &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB781900FA
      //## begin CWCActionInitialize::dwInitializedEvent%3FBB7819032C.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwInitializedEvent;
      //## end CWCActionInitialize::dwInitializedEvent%3FBB7819032C.role

    // Additional Private Declarations
      //## begin CWCActionInitialize%3E5E0B3000EA.private preserve=yes
      //## end CWCActionInitialize%3E5E0B3000EA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCActionInitialize%3E5E0B3000EA.implementation preserve=yes
      //## end CWCActionInitialize%3E5E0B3000EA.implementation

};

//## begin CWCActionInitialize%3E5E0B3000EA.postscript preserve=yes
//## end CWCActionInitialize%3E5E0B3000EA.postscript

//## begin CWCActionReferencing%3EC252CD003E.preface preserve=yes
//## end CWCActionReferencing%3EC252CD003E.preface

//## Class: CWCActionReferencing%3EC252CD003E
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EC2544C01F4;IHIInterface { -> }

class CWCActionReferencing : public CCOAction  //## Inherits: <unnamed>%3EC252E201B5
{
  //## begin CWCActionReferencing%3EC252CD003E.initialDeclarations preserve=yes
  //## end CWCActionReferencing%3EC252CD003E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCActionReferencing%1052922967
      CWCActionReferencing (const UINT p_uiID, ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCActionReferencing();


    //## Other Operations (specified)
      //## Operation: Done%1052922968
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

      //## Operation: Cancel%1164967779
      //	DESCRIPTION
      //	Cancels an action. Resets the current references to
      //	client and server sync objects.
      //
      //	RETURNS
      //	void
      virtual void Cancel ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB788100CB
      //## Role: CWCActionReferencing::dwReferencedEvent%3FBB788102B0
      static DWORD GetdwReferencedEvent ();
      static void SetdwReferencedEvent (DWORD value);

    // Additional Public Declarations
      //## begin CWCActionReferencing%3EC252CD003E.public preserve=yes
      //## end CWCActionReferencing%3EC252CD003E.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1052922969
      virtual CCOSyncObject* ExecuteAction ();

    // Additional Protected Declarations
      //## begin CWCActionReferencing%3EC252CD003E.protected preserve=yes
      //## end CWCActionReferencing%3EC252CD003E.protected

  private:
    //## Constructors (generated)
      CWCActionReferencing();

      CWCActionReferencing(const CWCActionReferencing &right);

    //## Assignment Operation (generated)
      const CWCActionReferencing & operator=(const CWCActionReferencing &right);

    //## Equality Operations (generated)
      bool operator==(const CWCActionReferencing &right) const;

      bool operator!=(const CWCActionReferencing &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB788100CB
      //## begin CWCActionReferencing::dwReferencedEvent%3FBB788102B0.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwReferencedEvent;
      //## end CWCActionReferencing::dwReferencedEvent%3FBB788102B0.role

    // Additional Private Declarations
      //## begin CWCActionReferencing%3EC252CD003E.private preserve=yes
      //## end CWCActionReferencing%3EC252CD003E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCActionReferencing%3EC252CD003E.implementation preserve=yes
      //## end CWCActionReferencing%3EC252CD003E.implementation

};

//## begin CWCActionReferencing%3EC252CD003E.postscript preserve=yes
//## end CWCActionReferencing%3EC252CD003E.postscript

//## begin CWCActionStopMeasuring%3EC480C1032C.preface preserve=yes
//## end CWCActionStopMeasuring%3EC480C1032C.preface

//## Class: CWCActionStopMeasuring%3EC480C1032C
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCActionStopMeasuring : public CCOAction  //## Inherits: <unnamed>%3EC4810B03D8
{
  //## begin CWCActionStopMeasuring%3EC480C1032C.initialDeclarations preserve=yes
  //## end CWCActionStopMeasuring%3EC480C1032C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCActionStopMeasuring%1053065365
      CWCActionStopMeasuring (const UINT p_uiID, ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCActionStopMeasuring();


    //## Other Operations (specified)
      //## Operation: Done%1053065366
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

      //## Operation: Cancel%1164967780
      //	DESCRIPTION
      //	Cancels an action. Resets the current references to
      //	client and server sync objects.
      //
      //	RETURNS
      //	void
      virtual void Cancel ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB78A8003E
      //## Role: CWCActionStopMeasuring::dwStoppedEvent%3FBB78A80290
      static DWORD GetdwStoppedEvent ();
      static void SetdwStoppedEvent (DWORD value);

    // Additional Public Declarations
      //## begin CWCActionStopMeasuring%3EC480C1032C.public preserve=yes
      //## end CWCActionStopMeasuring%3EC480C1032C.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1053065367
      virtual CCOSyncObject* ExecuteAction ();

    // Additional Protected Declarations
      //## begin CWCActionStopMeasuring%3EC480C1032C.protected preserve=yes
      //## end CWCActionStopMeasuring%3EC480C1032C.protected

  private:
    //## Constructors (generated)
      CWCActionStopMeasuring();

      CWCActionStopMeasuring(const CWCActionStopMeasuring &right);

    //## Assignment Operation (generated)
      const CWCActionStopMeasuring & operator=(const CWCActionStopMeasuring &right);

    //## Equality Operations (generated)
      bool operator==(const CWCActionStopMeasuring &right) const;

      bool operator!=(const CWCActionStopMeasuring &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBB78A8003E
      //## begin CWCActionStopMeasuring::dwStoppedEvent%3FBB78A80290.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwStoppedEvent;
      //## end CWCActionStopMeasuring::dwStoppedEvent%3FBB78A80290.role

    // Additional Private Declarations
      //## begin CWCActionStopMeasuring%3EC480C1032C.private preserve=yes
      //## end CWCActionStopMeasuring%3EC480C1032C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCActionStopMeasuring%3EC480C1032C.implementation preserve=yes
      //## end CWCActionStopMeasuring%3EC480C1032C.implementation

};

//## begin CWCActionStopMeasuring%3EC480C1032C.postscript preserve=yes
//## end CWCActionStopMeasuring%3EC480C1032C.postscript

//## begin CWCActionCurrDir%3FBC84DB0280.preface preserve=yes
//## end CWCActionCurrDir%3FBC84DB0280.preface

//## Class: CWCActionCurrDir%3FBC84DB0280
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FBC9AD903B9;EHIOpenEventRegistration { -> }

class CWCActionCurrDir : public CCOAction  //## Inherits: <unnamed>%3FBC855203C8
{
  //## begin CWCActionCurrDir%3FBC84DB0280.initialDeclarations preserve=yes
  //## end CWCActionCurrDir%3FBC84DB0280.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCActionCurrDir%1069318245
      CWCActionCurrDir (const UINT p_uiID, ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCActionCurrDir();


    //## Other Operations (specified)
      //## Operation: Done%1069318246
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

      //## Operation: Cancel%1164967781
      //	DESCRIPTION
      //	Cancels an action. Resets the current references to
      //	client and server sync objects.
      //
      //	RETURNS
      //	void
      virtual void Cancel ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBC855F00BB
      //## Role: CWCActionCurrDir::dwCurrDirEvent%3FBC855F02C0
      static DWORD GetdwCurrDirEvent ();
      static void SetdwCurrDirEvent (DWORD value);

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBC991F03B9
      //## Role: CWCActionCurrDir::eEventRegistration%3FBC992002A0
      static EHIOpenEventRegistration GeteEventRegistration ();
      static void SeteEventRegistration (EHIOpenEventRegistration value);

    // Additional Public Declarations
      //## begin CWCActionCurrDir%3FBC84DB0280.public preserve=yes
      //## end CWCActionCurrDir%3FBC84DB0280.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1069318247
      virtual CCOSyncObject* ExecuteAction ();

    // Additional Protected Declarations
      //## begin CWCActionCurrDir%3FBC84DB0280.protected preserve=yes
      //## end CWCActionCurrDir%3FBC84DB0280.protected

  private:
    //## Constructors (generated)
      CWCActionCurrDir();

      CWCActionCurrDir(const CWCActionCurrDir &right);

    //## Assignment Operation (generated)
      const CWCActionCurrDir & operator=(const CWCActionCurrDir &right);

    //## Equality Operations (generated)
      bool operator==(const CWCActionCurrDir &right) const;

      bool operator!=(const CWCActionCurrDir &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBC855F00BB
      //## begin CWCActionCurrDir::dwCurrDirEvent%3FBC855F02C0.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwCurrDirEvent;
      //## end CWCActionCurrDir::dwCurrDirEvent%3FBC855F02C0.role

      //## Association: EBWC (Wedge Control)::<unnamed>%3FBC991F03B9
      //## begin CWCActionCurrDir::eEventRegistration%3FBC992002A0.role preserve=no  public: static EHIOpenEventRegistration {1..1 -> 1..1VFHN}
      static EHIOpenEventRegistration m_eEventRegistration;
      //## end CWCActionCurrDir::eEventRegistration%3FBC992002A0.role

    // Additional Private Declarations
      //## begin CWCActionCurrDir%3FBC84DB0280.private preserve=yes
      //## end CWCActionCurrDir%3FBC84DB0280.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCActionCurrDir%3FBC84DB0280.implementation preserve=yes
      //## end CWCActionCurrDir%3FBC84DB0280.implementation

};

//## begin CWCActionCurrDir%3FBC84DB0280.postscript preserve=yes
//## end CWCActionCurrDir%3FBC84DB0280.postscript

//## begin CWCActionMeasuring%400B88AC00AB.preface preserve=yes
//## end CWCActionMeasuring%400B88AC00AB.preface

//## Class: CWCActionMeasuring%400B88AC00AB
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWCActionMeasuring : public CCOAction  //## Inherits: <unnamed>%400B893300EA
{
  //## begin CWCActionMeasuring%400B88AC00AB.initialDeclarations preserve=yes
  //## end CWCActionMeasuring%400B88AC00AB.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCActionMeasuring%1074497961
      CWCActionMeasuring (const UINT p_uiID, ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCActionMeasuring();


    //## Other Operations (specified)
      //## Operation: Done%1074497962
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

      //## Operation: Cancel%1164967777
      //	DESCRIPTION
      //	Cancels an action. Resets the current references to
      //	client and server sync objects.
      //
      //	RETURNS
      //	void
      virtual void Cancel ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBWC (Wedge Control)::<unnamed>%400B894000AB
      //## Role: CWCActionMeasuring::dwMeasuringExcEvent%400B89400272
      static DWORD GetdwMeasuringExcEvent ();
      static void SetdwMeasuringExcEvent (DWORD value);

    // Additional Public Declarations
      //## begin CWCActionMeasuring%400B88AC00AB.public preserve=yes
      //## end CWCActionMeasuring%400B88AC00AB.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1074497963
      virtual CCOSyncObject* ExecuteAction ();

    // Additional Protected Declarations
      //## begin CWCActionMeasuring%400B88AC00AB.protected preserve=yes
      //## end CWCActionMeasuring%400B88AC00AB.protected

  private:
    //## Constructors (generated)
      CWCActionMeasuring();

      CWCActionMeasuring(const CWCActionMeasuring &right);

    //## Assignment Operation (generated)
      const CWCActionMeasuring & operator=(const CWCActionMeasuring &right);

    //## Equality Operations (generated)
      bool operator==(const CWCActionMeasuring &right) const;

      bool operator!=(const CWCActionMeasuring &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%400B894000AB
      //## begin CWCActionMeasuring::dwMeasuringExcEvent%400B89400272.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
      static DWORD m_dwMeasuringExcEvent;
      //## end CWCActionMeasuring::dwMeasuringExcEvent%400B89400272.role

    // Additional Private Declarations
      //## begin CWCActionMeasuring%400B88AC00AB.private preserve=yes
      //## end CWCActionMeasuring%400B88AC00AB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCActionMeasuring%400B88AC00AB.implementation preserve=yes
      //## end CWCActionMeasuring%400B88AC00AB.implementation

};

//## begin CWCActionMeasuring%400B88AC00AB.postscript preserve=yes
//## end CWCActionMeasuring%400B88AC00AB.postscript

// Class CWCActionInitialize 

// Class CWCActionReferencing 

// Class CWCActionStopMeasuring 

// Class CWCActionCurrDir 

// Class CWCActionMeasuring 

//## begin module%3E5E0B790251.epilog preserve=yes
//## end module%3E5E0B790251.epilog


#endif
