//## begin module%3B8D53AE006F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D53AE006F.cm

//## begin module%3B8D53AE006F.cp preserve=no
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
//## end module%3B8D53AE006F.cp

//## Module: EBCOsync%3B8D53AE006F; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOsync.h

#ifndef EBCOsync_h
#define EBCOsync_h 1

//## begin module%3B8D53AE006F.additionalIncludes preserve=no
//## end module%3B8D53AE006F.additionalIncludes

//## begin module%3B8D53AE006F.includes preserve=yes
//## end module%3B8D53AE006F.includes

// EBCOrefc
#include "EBCOrefc.h"
// EBCOtmpl
#include "EBCOtmpl.h"

class EBCO_DLL_DECL XCOException;

//## begin module%3B8D53AE006F.declarations preserve=no
//## end module%3B8D53AE006F.declarations

//## begin module%3B8D53AE006F.additionalDeclarations preserve=yes
//## end module%3B8D53AE006F.additionalDeclarations


//## begin CCOSyncObject%3B8D554D00B2.preface preserve=yes
//## end CCOSyncObject%3B8D554D00B2.preface

//## Class: CCOSyncObject%3B8D554D00B2
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%409B80ED0267;CO_IDENTIFIERS { -> }

class EBCO_DLL_DECL CCOSyncObject : public CEvent, //## Inherits: <unnamed>%3B8D556303A3
                            	public ICORefCounting  //## Inherits: <unnamed>%3B8D55A20295
{
  //## begin CCOSyncObject%3B8D554D00B2.initialDeclarations preserve=yes
  //## end CCOSyncObject%3B8D554D00B2.initialDeclarations

  public:
    //## Constructors (generated)
      CCOSyncObject();

    //## Constructors (specified)
      //## Operation: CCOSyncObject%1164093766
      CCOSyncObject (const CString& p_sName);


    //## Other Operations (specified)
      //## Operation: SignalCompletion%999108324
      //	DESCRIPTION
      //	Signals the event object.
      //
      //	RETURNS
      //	void
      virtual void SignalCompletion ();

      //## Operation: ResetCompletion%1040029833
      //	DESCRIPTION
      //	Resets the event object to 'non signalled'
      //
      //	RETURNS
      //	void
      virtual void ResetCompletion ();

      //## Operation: HasException%999280849
      //	DESCRIPTION
      //	Checks for pending exceptions.
      //
      //	RETURNS
      //	void
      virtual void HasException ();

      //## Operation: Synchronize%999291448
      //	DESCRIPTION
      //	Locks the caller until the event has been signalled.
      //
      //	RETURNS
      //	void
      virtual void Synchronize ();

      //## Operation: Synchronize%1083932479
      //	DESCRIPTION
      //	Locks the caller until the event has been signalled.
      //
      //	PARAMETER
      //	timeout in [ms]
      //
      //	RETURNS
      //	void
      virtual void Synchronize (const UINT p_uiTimeout);

      //## Operation: AttachException%1000031215
      //	DESCRIPTION
      //	Attaches an exception to the synchronization object and
      //	signals the object.
      //
      //	RETURNS
      //	void
      virtual void AttachException (XCOException* p_pException);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%409B80AB02E5
      //## Role: CCOSyncObject::bIsSignalled%409B80AC0142
      bool GetbIsSignalled ();

    // Additional Public Declarations
      //## begin CCOSyncObject%3B8D554D00B2.public preserve=yes
      //## end CCOSyncObject%3B8D554D00B2.public

  protected:
    //## Destructor (generated)
      virtual ~CCOSyncObject();

    // Additional Protected Declarations
      //## begin CCOSyncObject%3B8D554D00B2.protected preserve=yes
      //## end CCOSyncObject%3B8D554D00B2.protected

  private:
    //## Constructors (generated)
      CCOSyncObject(const CCOSyncObject &right);

    //## Assignment Operation (generated)
      const CCOSyncObject & operator=(const CCOSyncObject &right);

    //## Equality Operations (generated)
      bool operator==(const CCOSyncObject &right) const;

      bool operator!=(const CCOSyncObject &right) const;

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3B8D597F01A7
      //## Role: CCOSyncObject::pException%3B8D597F0356
      //## begin CCOSyncObject::pException%3B8D597F0356.role preserve=no  public: XCOException {1..1 -> 1..1RFHN}
      XCOException *m_pException;
      //## end CCOSyncObject::pException%3B8D597F0356.role

      //## Association: EBCO (Core Classes)::<unnamed>%409B80AB02E5
      //## begin CCOSyncObject::bIsSignalled%409B80AC0142.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bIsSignalled;
      //## end CCOSyncObject::bIsSignalled%409B80AC0142.role

    // Additional Private Declarations
      //## begin CCOSyncObject%3B8D554D00B2.private preserve=yes
      //## end CCOSyncObject%3B8D554D00B2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOSyncObject%3B8D554D00B2.implementation preserve=yes
      //## end CCOSyncObject%3B8D554D00B2.implementation

};

//## begin CCOSyncObject%3B8D554D00B2.postscript preserve=yes
//## end CCOSyncObject%3B8D554D00B2.postscript

//## begin CCOSyncObjectArrayInstantiated%3B8D5FEE03C2.preface preserve=yes
//## end CCOSyncObjectArrayInstantiated%3B8D5FEE03C2.preface

//## Class: CCOSyncObjectArrayInstantiated%3B8D5FEE03C2; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CTypedPtrArray< CPtrArray,CCOSyncObject* > CCOSyncObjectArrayInstantiated;

//## begin CCOSyncObjectArrayInstantiated%3B8D5FEE03C2.postscript preserve=yes
//## end CCOSyncObjectArrayInstantiated%3B8D5FEE03C2.postscript

//## begin CCOSyncObjectArray%3B8D5CD80267.preface preserve=yes
//## end CCOSyncObjectArray%3B8D5CD80267.preface

//## Class: CCOSyncObjectArray%3B8D5CD80267
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL CCOSyncObjectArray : public CCOSyncObjectArrayInstantiated, //## Inherits: <unnamed>%3B8D60360176
    	public ICORefCounting  //## Inherits: <unnamed>%3B8D6242007F
{
  //## begin CCOSyncObjectArray%3B8D5CD80267.initialDeclarations preserve=yes
  //## end CCOSyncObjectArray%3B8D5CD80267.initialDeclarations

  public:
    //## Constructors (generated)
      CCOSyncObjectArray();


    //## Other Operations (specified)
      //## Operation: Add%999119009
      //	DESCRIPTION
      //	Adds a new synchronization object at the end of the
      //	array.
      //
      //	PARAMETERS
      //	- Sync Object
      //	- true, if the array should increment the reference
      //	count on it
      //
      //	RETURNS
      //	void
      virtual void Add (CCOSyncObject* p_pSyncObj, const bool p_bKeepOwnReference = true);

      //## Operation: SignalCompletion%999280847
      //	DESCRIPTION
      //	Signals all currently contained sync objects in the array
      //
      //	RETURNS
      //	void
      virtual void SignalCompletion ();

      //## Operation: HasException%999280850
      //	DESCRIPTION
      //	Checks for pending exceptions.
      //
      //	RETURNS
      //	void
      virtual void HasException ();

      //## Operation: AttachException%1000031216
      //	DESCRIPTION
      //	Attaches an exception to all contained synchronization
      //	object and signals them.
      //
      //	RETURNS
      //	void
      virtual void AttachException (XCOException* p_pException);

      //## Operation: Synchronize%1090935982
      virtual void Synchronize (DWORD p_dwTimeout = INFINITE);

    // Additional Public Declarations
      //## begin CCOSyncObjectArray%3B8D5CD80267.public preserve=yes
      //## end CCOSyncObjectArray%3B8D5CD80267.public

  protected:
    //## Destructor (generated)
      virtual ~CCOSyncObjectArray();

    // Additional Protected Declarations
      //## begin CCOSyncObjectArray%3B8D5CD80267.protected preserve=yes
      //## end CCOSyncObjectArray%3B8D5CD80267.protected

  private:
    //## Constructors (generated)
      CCOSyncObjectArray(const CCOSyncObjectArray &right);

    //## Assignment Operation (generated)
      const CCOSyncObjectArray & operator=(const CCOSyncObjectArray &right);

    //## Equality Operations (generated)
      bool operator==(const CCOSyncObjectArray &right) const;

      bool operator!=(const CCOSyncObjectArray &right) const;

    // Additional Private Declarations
      //## begin CCOSyncObjectArray%3B8D5CD80267.private preserve=yes
      //## end CCOSyncObjectArray%3B8D5CD80267.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOSyncObjectArray%3B8D5CD80267.implementation preserve=yes
      //## end CCOSyncObjectArray%3B8D5CD80267.implementation

};

//## begin CCOSyncObjectArray%3B8D5CD80267.postscript preserve=yes
//## end CCOSyncObjectArray%3B8D5CD80267.postscript

//## begin CCOSyncObjectPtr%3B8EAC860097.preface preserve=yes
//## end CCOSyncObjectPtr%3B8EAC860097.preface

//## Class: CCOSyncObjectPtr%3B8EAC860097; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CCOSmartPtr< CCOSyncObject > CCOSyncObjectPtr;

//## begin CCOSyncObjectPtr%3B8EAC860097.postscript preserve=yes
//## end CCOSyncObjectPtr%3B8EAC860097.postscript

//## begin CCOSyncObjectArrayPtr%3B8FD0750033.preface preserve=yes
//## end CCOSyncObjectArrayPtr%3B8FD0750033.preface

//## Class: CCOSyncObjectArrayPtr%3B8FD0750033; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CCOSmartPtr< CCOSyncObjectArray > CCOSyncObjectArrayPtr;

//## begin CCOSyncObjectArrayPtr%3B8FD0750033.postscript preserve=yes
//## end CCOSyncObjectArrayPtr%3B8FD0750033.postscript

// Class CCOSyncObject 

// Class CCOSyncObjectArray 

//## begin CCOSyncObjectPtr.instantiation preserve=no
template class CCOSmartPtr< CCOSyncObject >;
//## end CCOSyncObjectPtr.instantiation
//## begin CCOSyncObjectArrayPtr.instantiation preserve=no
template class CCOSmartPtr< CCOSyncObjectArray >;
//## end CCOSyncObjectArrayPtr.instantiation
//## begin module%3B8D53AE006F.epilog preserve=yes
//## end module%3B8D53AE006F.epilog


#endif
