//## begin module%3B86D6DD0172.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B86D6DD0172.cm

//## begin module%3B86D6DD0172.cp preserve=no
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
//## end module%3B86D6DD0172.cp

//## Module: EBCOintf%3B86D6DD0172; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOintf.h

#ifndef EBCOintf_h
#define EBCOintf_h 1

//## begin module%3B86D6DD0172.additionalIncludes preserve=no
//## end module%3B86D6DD0172.additionalIncludes

//## begin module%3B86D6DD0172.includes preserve=yes
//## end module%3B86D6DD0172.includes

// EBCOenum
#include "EBCOenum.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBCO_DLL_DECL CCOCommand;
class EBCO_DLL_DECL ICOAsyncImplementation;

//## begin module%3B86D6DD0172.declarations preserve=no
//## end module%3B86D6DD0172.declarations

//## begin module%3B86D6DD0172.additionalDeclarations preserve=yes
//## end module%3B86D6DD0172.additionalDeclarations


//## begin ICOObjectInterface%3DA5E00F0046.preface preserve=yes
//## end ICOObjectInterface%3DA5E00F0046.preface

//## Class: ICOObjectInterface%3DA5E00F0046
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL ICOObjectInterface 
{
  //## begin ICOObjectInterface%3DA5E00F0046.initialDeclarations preserve=yes
  //## end ICOObjectInterface%3DA5E00F0046.initialDeclarations

  public:
    //## Constructors (generated)
      ICOObjectInterface();

    //## Destructor (generated)
      virtual ~ICOObjectInterface();


    //## Other Operations (specified)
      //## Operation: GetuiID%1034272547
      virtual UINT GetuiID () = 0;

      //## Operation: Startup%1055313953
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup () = 0;

      //## Operation: Shutdown%1055313954
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown () = 0;

      //## Operation: ConnectionEstablished%1055313955
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished () = 0;

      //## Operation: ConnectionLost%1055313956
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost () = 0;

    // Additional Public Declarations
      //## begin ICOObjectInterface%3DA5E00F0046.public preserve=yes
      //## end ICOObjectInterface%3DA5E00F0046.public

  protected:
    // Additional Protected Declarations
      //## begin ICOObjectInterface%3DA5E00F0046.protected preserve=yes
      //## end ICOObjectInterface%3DA5E00F0046.protected

  private:
    //## Constructors (generated)
      ICOObjectInterface(const ICOObjectInterface &right);

    //## Assignment Operation (generated)
      const ICOObjectInterface & operator=(const ICOObjectInterface &right);

    //## Equality Operations (generated)
      bool operator==(const ICOObjectInterface &right) const;

      bool operator!=(const ICOObjectInterface &right) const;

    // Additional Private Declarations
      //## begin ICOObjectInterface%3DA5E00F0046.private preserve=yes
      //## end ICOObjectInterface%3DA5E00F0046.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOObjectInterface%3DA5E00F0046.implementation preserve=yes
      //## end ICOObjectInterface%3DA5E00F0046.implementation

};

//## begin ICOObjectInterface%3DA5E00F0046.postscript preserve=yes
typedef CCOSyncObject* (ICOObjectInterface::*COAsyncCommandPtr)();
//## end ICOObjectInterface%3DA5E00F0046.postscript

//## begin ICOAsyncInterface%3B86D700001E.preface preserve=yes
//## end ICOAsyncInterface%3B86D700001E.preface

//## Class: ICOAsyncInterface%3B86D700001E
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B8FE39C03E0;CCOSyncObject { -> F}
//## Uses: <unnamed>%3B8FE3B1030E;CCOCommand { -> F}
//## Uses: <unnamed>%3B8FE420020A;ECOAsyncCallQueue { -> }

class EBCO_DLL_DECL ICOAsyncInterface : public ICOObjectInterface  //## Inherits: <unnamed>%3EE6D9BD0306
{
  //## begin ICOAsyncInterface%3B86D700001E.initialDeclarations preserve=yes
  //## end ICOAsyncInterface%3B86D700001E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: ICOAsyncInterface%999280839
      ICOAsyncInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~ICOAsyncInterface();


    //## Other Operations (specified)
      //## Operation: InitInstance%999280837
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: ExitInstance%999280840
      //	DESCRIPTION
      //	stops the implementation's worker thread and prepares
      //	for the final cleanup
      //
      //	RETURNS
      //	void
      virtual void ExitInstance ();

      //## Operation: GetsCurrentState%1000031199
      //	DESCRIPTION
      //	Returns the current state of the unit in text.
      //
      //	RETURNS
      //	State name
      virtual CString GetsCurrentState ();

      //## Operation: Startup%999280842
      //	DESCRIPTION
      //	Brings the subsystem into 'ConfigProcessModelSetup' and
      //	processes all model dependent and fixed parameters
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%999369758
      //	DESCRIPTION
      //	Brings the subsystem down to the entry state 'created'
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1055313951
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055313952
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sSubsystemID%3B8FD8D301B0
      virtual const CString GetsSubsystemID () const;

    // Additional Public Declarations
      //## begin ICOAsyncInterface%3B86D700001E.public preserve=yes
      //## end ICOAsyncInterface%3B86D700001E.public

  protected:

    //## Other Operations (specified)
      //## Operation: Execute%999280843
      //	DESCRIPTION
      //	Passes the current command to the implementation context.
      //
      //	RETURNS
      //	CCOSyncObject*
      virtual CCOSyncObject* Execute (CCOCommand* p_pCommand, const ECOAsyncCallQueue p_ePriority = eCOQueueNormal);

    // Data Members for Class Attributes

      //## begin ICOAsyncInterface::sSubsystemID%3B8FD8D301B0.attr preserve=no  public: CString {UC} p_sSubsystemID
      const CString  m_sSubsystemID;
      //## end ICOAsyncInterface::sSubsystemID%3B8FD8D301B0.attr

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69D220099
      //## Role: ICOAsyncInterface::pImplementation%3DA69D2202FC
      //## begin ICOAsyncInterface::pImplementation%3DA69D2202FC.role preserve=no  public: ICOAsyncImplementation {1..1 -> 1..1RFHN}
      ICOAsyncImplementation *m_pImplementation;
      //## end ICOAsyncInterface::pImplementation%3DA69D2202FC.role

    // Additional Protected Declarations
      //## begin ICOAsyncInterface%3B86D700001E.protected preserve=yes
      //## end ICOAsyncInterface%3B86D700001E.protected

  private:
    //## Constructors (generated)
      ICOAsyncInterface();

      ICOAsyncInterface(const ICOAsyncInterface &right);

    //## Assignment Operation (generated)
      const ICOAsyncInterface & operator=(const ICOAsyncInterface &right);

    //## Equality Operations (generated)
      bool operator==(const ICOAsyncInterface &right) const;

      bool operator!=(const ICOAsyncInterface &right) const;

    // Additional Private Declarations
      //## begin ICOAsyncInterface%3B86D700001E.private preserve=yes
      //## end ICOAsyncInterface%3B86D700001E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOAsyncInterface%3B86D700001E.implementation preserve=yes
      //## end ICOAsyncInterface%3B86D700001E.implementation

};

//## begin ICOAsyncInterface%3B86D700001E.postscript preserve=yes
//## end ICOAsyncInterface%3B86D700001E.postscript

//## begin ICOSyncInterface%3DB92ED80037.preface preserve=yes
//## end ICOSyncInterface%3DB92ED80037.preface

//## Class: ICOSyncInterface%3DB92ED80037
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL ICOSyncInterface : public ICOObjectInterface  //## Inherits: <unnamed>%3EE6D9E20344
{
  //## begin ICOSyncInterface%3DB92ED80037.initialDeclarations preserve=yes
  //## end ICOSyncInterface%3DB92ED80037.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: ICOSyncInterface%1039527157
      ICOSyncInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~ICOSyncInterface();

    // Additional Public Declarations
      //## begin ICOSyncInterface%3DB92ED80037.public preserve=yes
      //## end ICOSyncInterface%3DB92ED80037.public

  protected:
    // Additional Protected Declarations
      //## begin ICOSyncInterface%3DB92ED80037.protected preserve=yes
      //## end ICOSyncInterface%3DB92ED80037.protected

  private:
    //## Constructors (generated)
      ICOSyncInterface();

      ICOSyncInterface(const ICOSyncInterface &right);

    //## Assignment Operation (generated)
      const ICOSyncInterface & operator=(const ICOSyncInterface &right);

    //## Equality Operations (generated)
      bool operator==(const ICOSyncInterface &right) const;

      bool operator!=(const ICOSyncInterface &right) const;

    // Additional Private Declarations
      //## begin ICOSyncInterface%3DB92ED80037.private preserve=yes
      //## end ICOSyncInterface%3DB92ED80037.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOSyncInterface%3DB92ED80037.implementation preserve=yes
      //## end ICOSyncInterface%3DB92ED80037.implementation

};

//## begin ICOSyncInterface%3DB92ED80037.postscript preserve=yes
//## end ICOSyncInterface%3DB92ED80037.postscript

// Class ICOObjectInterface 

// Class ICOAsyncInterface 

// Class ICOSyncInterface 

//## begin module%3B86D6DD0172.epilog preserve=yes
//## end module%3B86D6DD0172.epilog


#endif
