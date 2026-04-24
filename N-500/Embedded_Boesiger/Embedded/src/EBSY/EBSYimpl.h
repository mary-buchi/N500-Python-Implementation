//## begin module%3EDC5B3C01D6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01D6.cm

//## begin module%3EDC5B3C01D6.cp preserve=no
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
//## end module%3EDC5B3C01D6.cp

//## Module: EBSYimpl%3EDC5B3C01D6; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYimpl.h

#ifndef EBSYimpl_h
#define EBSYimpl_h 1

//## begin module%3EDC5B3C01D6.additionalIncludes preserve=no
//## end module%3EDC5B3C01D6.additionalIncludes

//## begin module%3EDC5B3C01D6.includes preserve=yes
//## end module%3EDC5B3C01D6.includes

// EBPItype
#include "EBPItype.h"
// EBCOimpl
#include "EBCOimpl.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBSY_DLL_DECL CSYSystemInterface;

//## begin module%3EDC5B3C01D6.declarations preserve=no
//## end module%3EDC5B3C01D6.declarations

//## begin module%3EDC5B3C01D6.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01D6.additionalDeclarations


//## begin CSYSystemImplementation%3EDC5B9C009A.preface preserve=yes
//## end CSYSystemImplementation%3EDC5B9C009A.preface

//## Class: CSYSystemImplementation%3EDC5B9C009A
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EDC5B9C009F;CSYSystemInterface { -> F}
//## Uses: <unnamed>%3EDC5B9C00A2;CSYStateMachineEngine { -> }
//## Uses: <unnamed>%3EF83A650344;EPIDeviceState { -> }
//## Uses: <unnamed>%40225D8901FB;XCOExceptionError { -> }
//## Uses: <unnamed>%4023401A0221;SY_IDENTIFIERS { -> }
//## Uses: <unnamed>%403473DD0197;CSYSystem { -> }
//## Uses: <unnamed>%403474DE00ED;CCOCommandCleanupInitialize { -> }
//## Uses: <unnamed>%415D8EDD01EE;XSYExceptionErrorDeviceBusy { -> }
//## Uses: <unnamed>%4213110302AF;IHIInterface { -> }

class CSYSystemImplementation : public ICOAsyncImplementation  //## Inherits: <unnamed>%3EDC5B9C009C
{
  //## begin CSYSystemImplementation%3EDC5B9C009A.initialDeclarations preserve=yes
  //## end CSYSystemImplementation%3EDC5B9C009A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSYSystemImplementation%1038899316
      CSYSystemImplementation (CSYSystemInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~CSYSystemImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%1038899317
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: GetDeviceState%1056436743
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: RegisterClient%1096648856
      void RegisterClient (const CString& p_sClient);

      //## Operation: ResetClient%1096648861
      void ResetClient ();

      //## Operation: GetSoftwareVersion%1096656418
      CString GetSoftwareVersion ();

      //## Operation: GetOsVersion%1108540800
      CString GetOsVersion ();

      //## Operation: GetFpgaVersion%1108540801
      CString GetFpgaVersion ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiWarmupTimeout%4098868E0065
      UINT GetuiWarmupTimeout ();
      void SetuiWarmupTimeout (UINT value);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBSY (System Control)::<unnamed>%4111F8B402D7
      //## Role: CSYSystemImplementation::pSetInterfaceCfgSyncObj%4111F8B50150
      CCOSyncObject * GetpSetInterfaceCfgSyncObj ();
      void SetpSetInterfaceCfgSyncObj (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CSYSystemImplementation%3EDC5B9C009A.public preserve=yes
      //## end CSYSystemImplementation%3EDC5B9C009A.public

  protected:

    //## Other Operations (specified)
      //## Operation: HandleErrorException%1096648863
      //	returns true, if the given exception should be thrown
      //	out of the subsystem interface
      virtual bool HandleErrorException (XCOExceptionError* p_pException);

    // Additional Protected Declarations
      //## begin CSYSystemImplementation%3EDC5B9C009A.protected preserve=yes
      //## end CSYSystemImplementation%3EDC5B9C009A.protected

  private:
    //## Constructors (generated)
      CSYSystemImplementation();

      CSYSystemImplementation(const CSYSystemImplementation &right);

    //## Assignment Operation (generated)
      const CSYSystemImplementation & operator=(const CSYSystemImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CSYSystemImplementation &right) const;

      bool operator!=(const CSYSystemImplementation &right) const;

    // Data Members for Class Attributes

      //## begin CSYSystemImplementation::uiWarmupTimeout%4098868E0065.attr preserve=no  public: UINT {U} 30*60000
      UINT m_uiWarmupTimeout;
      //## end CSYSystemImplementation::uiWarmupTimeout%4098868E0065.attr

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%4111F8B402D7
      //## begin CSYSystemImplementation::pSetInterfaceCfgSyncObj%4111F8B50150.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pSetInterfaceCfgSyncObj;
      //## end CSYSystemImplementation::pSetInterfaceCfgSyncObj%4111F8B50150.role

      //## Association: EBSY (System Control)::<unnamed>%415D886502B5
      //## Role: CSYSystemImplementation::sCurrentClient%415D88660202
      //## begin CSYSystemImplementation::sCurrentClient%415D88660202.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sCurrentClient;
      //## end CSYSystemImplementation::sCurrentClient%415D88660202.role

    // Additional Private Declarations
      //## begin CSYSystemImplementation%3EDC5B9C009A.private preserve=yes
      //## end CSYSystemImplementation%3EDC5B9C009A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYSystemImplementation%3EDC5B9C009A.implementation preserve=yes
      //## end CSYSystemImplementation%3EDC5B9C009A.implementation

};

//## begin CSYSystemImplementation%3EDC5B9C009A.postscript preserve=yes
//## end CSYSystemImplementation%3EDC5B9C009A.postscript

// Class CSYSystemImplementation 

//## begin module%3EDC5B3C01D6.epilog preserve=yes
//## end module%3EDC5B3C01D6.epilog


#endif
