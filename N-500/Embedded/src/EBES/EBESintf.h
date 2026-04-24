//## begin module%3DE5EC6D012D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EC6D012D.cm

//## begin module%3DE5EC6D012D.cp preserve=no
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
//## end module%3DE5EC6D012D.cp

//## Module: EBESintf%3DE5EC6D012D; Package specification
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Source file: R:\Embedded\src\EBES\EBESintf.h

#ifndef EBESintf_h
#define EBESintf_h 1

//## begin module%3DE5EC6D012D.additionalIncludes preserve=no
//## end module%3DE5EC6D012D.additionalIncludes

//## begin module%3DE5EC6D012D.includes preserve=yes
//## end module%3DE5EC6D012D.includes

// EBCOsypr
#include "EBCOsypr.h"
// EBPIintf
#include "EBPIintf.h"

class EBCO_DLL_DECL CCOSyncObject;
class CESClient;

//## begin module%3DE5EC6D012D.declarations preserve=no
//## end module%3DE5EC6D012D.declarations

//## begin module%3DE5EC6D012D.additionalDeclarations preserve=yes
//## end module%3DE5EC6D012D.additionalDeclarations


//## begin CESEventSourceInterface%3DE713B402CD.preface preserve=yes
//## end CESEventSourceInterface%3DE713B402CD.preface

//## Class: CESEventSourceInterface%3DE713B402CD
//## Category: EBES (Event Source)%3DE5E6910350
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEB67BF017E;ES_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DF4B2CA01DF;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%3EF311E402FD;EHIOpenEventRegistration { -> }
//## Uses: <unnamed>%3EF318D80177;CHIInterface { -> }

class EBES_DLL_DECL CESEventSourceInterface : public IPIEventSourceInterface  //## Inherits: <unnamed>%3DE713C502FC
{
  //## begin CESEventSourceInterface%3DE713B402CD.initialDeclarations preserve=yes
  //## end CESEventSourceInterface%3DE713B402CD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CESEventSourceInterface%1038837056
      CESEventSourceInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CESEventSourceInterface();


    //## Other Operations (specified)
      //## Operation: GetuiID%1038837052
      virtual UINT GetuiID ();

      //## Operation: ConnectionEstablished%1055744816
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055744817
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: Startup%1056098156
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1056098157
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: RegisterForEvent%1056353484
      //	DESCRIPTION
      //	registers the given client to the event manager.
      //
      //	PARAMETERS
      //	type of event being interested in
      //	process image id of the input being interested in
      //
      //	RETURNS
      //	async array:
      //	[0]: async int, ID for later unregistering, command
      //	executed
      //	[1]: event occured
      virtual CCOSyncObjectArray* RegisterForEvent (UINT p_uiInputID, INT& p_iEventID);

      //## Operation: UnRegisterFromEvent%1056353485
      //	DESCRIPTION
      //	unregisters the given client from the event manager.
      //
      //	PARAMETERS
      //	client identification
      //	type of event being interested in
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* UnRegisterFromEvent (UINT p_uiClientID);

      //## Operation: Cleanup%1164898825
      virtual void Cleanup ();

    // Additional Public Declarations
      //## begin CESEventSourceInterface%3DE713B402CD.public preserve=yes
      //## end CESEventSourceInterface%3DE713B402CD.public

  protected:
    // Additional Protected Declarations
      //## begin CESEventSourceInterface%3DE713B402CD.protected preserve=yes
      //## end CESEventSourceInterface%3DE713B402CD.protected

  private:
    //## Constructors (generated)
      CESEventSourceInterface();

      CESEventSourceInterface(const CESEventSourceInterface &right);

    //## Assignment Operation (generated)
      const CESEventSourceInterface & operator=(const CESEventSourceInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CESEventSourceInterface &right) const;

      bool operator!=(const CESEventSourceInterface &right) const;

    // Data Members for Class Attributes

      //## Attribute: uiNextClientID%3EF320A40196
      //## begin CESEventSourceInterface::uiNextClientID%3EF320A40196.attr preserve=no  private: static UINT {U} 0
      static UINT m_uiNextClientID;
      //## end CESEventSourceInterface::uiNextClientID%3EF320A40196.attr

    // Data Members for Associations

      //## Association: EBES (Event Source)::<unnamed>%3DE713E00221
      //## Role: CESEventSourceInterface::uiID%3DE713E10212
      //## begin CESEventSourceInterface::uiID%3DE713E10212.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CESEventSourceInterface::uiID%3DE713E10212.role

      //## Association: EBES (Event Source)::<unnamed>%3EF31F730280
      //## Role: CESEventSourceInterface::Clients%3EF31F75004F
      //## Constraints:
      //	ordered
      //## Qualifier: uiID%3EF31FF101E4; UINT
      //## begin CESEventSourceInterface::Clients%3EF31F75004F.role preserve=no  public: CESClient {1 -> 1RFHON}
      CMap<UINT, UINT&, CESClient *, CESClient *&> m_Clients;
      //## end CESEventSourceInterface::Clients%3EF31F75004F.role

    // Additional Private Declarations
      //## begin CESEventSourceInterface%3DE713B402CD.private preserve=yes
      //## end CESEventSourceInterface%3DE713B402CD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CESEventSourceInterface%3DE713B402CD.implementation preserve=yes
      //## end CESEventSourceInterface%3DE713B402CD.implementation

};

//## begin CESEventSourceInterface%3DE713B402CD.postscript preserve=yes
//## end CESEventSourceInterface%3DE713B402CD.postscript

//## begin CESClient%3EF31EEE01E4.preface preserve=yes
//## end CESClient%3EF31EEE01E4.preface

//## Class: CESClient%3EF31EEE01E4
//## Category: EBES (Event Source)%3DE5E6910350
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CESClient 
{
  //## begin CESClient%3EF31EEE01E4.initialDeclarations preserve=yes
  //## end CESClient%3EF31EEE01E4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CESClient%1056098158
      CESClient (CCOSyncObject* p_pSyncObj, UINT p_uiInputID);

    //## Destructor (generated)
      virtual ~CESClient();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBES (Event Source)::<unnamed>%3EF31F32003E
      //## Role: CESClient::pSyncObj%3EF31F320252
      CCOSyncObject * GetpSyncObj ();

      //## Association: EBES (Event Source)::<unnamed>%3EF6AF1F0167
      //## Role: CESClient::uiInputID%3EF6AF20006E
      UINT GetuiInputID ();

    // Additional Public Declarations
      //## begin CESClient%3EF31EEE01E4.public preserve=yes
      //## end CESClient%3EF31EEE01E4.public

  protected:
    // Additional Protected Declarations
      //## begin CESClient%3EF31EEE01E4.protected preserve=yes
      //## end CESClient%3EF31EEE01E4.protected

  private:
    //## Constructors (generated)
      CESClient();

      CESClient(const CESClient &right);

    //## Assignment Operation (generated)
      const CESClient & operator=(const CESClient &right);

    //## Equality Operations (generated)
      bool operator==(const CESClient &right) const;

      bool operator!=(const CESClient &right) const;

    // Data Members for Associations

      //## Association: EBES (Event Source)::<unnamed>%3EF31F32003E
      //## begin CESClient::pSyncObj%3EF31F320252.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pSyncObj;
      //## end CESClient::pSyncObj%3EF31F320252.role

      //## Association: EBES (Event Source)::<unnamed>%3EF6AF1F0167
      //## begin CESClient::uiInputID%3EF6AF20006E.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiInputID;
      //## end CESClient::uiInputID%3EF6AF20006E.role

    // Additional Private Declarations
      //## begin CESClient%3EF31EEE01E4.private preserve=yes
      //## end CESClient%3EF31EEE01E4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CESClient%3EF31EEE01E4.implementation preserve=yes
      //## end CESClient%3EF31EEE01E4.implementation

};

//## begin CESClient%3EF31EEE01E4.postscript preserve=yes
//## end CESClient%3EF31EEE01E4.postscript

// Class CESEventSourceInterface 

// Class CESClient 

//## begin module%3DE5EC6D012D.epilog preserve=yes
//## end module%3DE5EC6D012D.epilog


#endif
