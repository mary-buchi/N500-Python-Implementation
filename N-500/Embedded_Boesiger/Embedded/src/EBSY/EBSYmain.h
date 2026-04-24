//## begin module%3EDC5B3C01D2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01D2.cm

//## begin module%3EDC5B3C01D2.cp preserve=no
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
//## end module%3EDC5B3C01D2.cp

//## Module: EBSYmain%3EDC5B3C01D2; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYmain.h

#ifndef EBSYmain_h
#define EBSYmain_h 1

//## begin module%3EDC5B3C01D2.additionalIncludes preserve=no
//## end module%3EDC5B3C01D2.additionalIncludes

//## begin module%3EDC5B3C01D2.includes preserve=yes
//## end module%3EDC5B3C01D2.includes


class EBCO_DLL_DECL XCOException;
class EBSY_DLL_DECL CSYSystemInterface;

//## begin module%3EDC5B3C01D2.declarations preserve=no
//## end module%3EDC5B3C01D2.declarations

//## begin module%3EDC5B3C01D2.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01D2.additionalDeclarations


//## begin CSYSystem%3EE886FE0308.preface preserve=yes
//## end CSYSystem%3EE886FE0308.preface

//## Class: CSYSystem%3EE886FE0308
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE888870133;IPISystemInterface { -> }
//## Uses: <unnamed>%3EE9913402C0;CPIObjectFactory { -> }
//## Uses: <unnamed>%3EE9939200BC;CSYStateMachineEngine { -> }
//## Uses: <unnamed>%3EEF1D5A0150;CSYModuleHandling { -> }
//## Uses: <unnamed>%3EEF22180008;CPISystem { -> }
//## Uses: <unnamed>%3EF7076900FC;CHIInterface { -> }
//## Uses: <unnamed>%402CA1440119;XCOExceptionError { -> }
//## Uses: <unnamed>%403475B901BA;XCOException { -> F}

class EBSY_DLL_DECL CSYSystem 
{
  //## begin CSYSystem%3EE886FE0308.initialDeclarations preserve=yes
  //## end CSYSystem%3EE886FE0308.initialDeclarations

  public:
    //## Constructors (generated)
      CSYSystem();

    //## Destructor (generated)
      virtual ~CSYSystem();


    //## Other Operations (specified)
      //## Operation: Create%1055493755
      //	returns true if the creation was successful
      static bool Create ();

      //## Operation: Delete%1055493756
      static void Delete ();

      //## Operation: ShowException%1077175167
      static void ShowException (XCOException* p_pException);

    // Additional Public Declarations
      //## begin CSYSystem%3EE886FE0308.public preserve=yes
      //## end CSYSystem%3EE886FE0308.public

  protected:
    // Additional Protected Declarations
      //## begin CSYSystem%3EE886FE0308.protected preserve=yes
      //## end CSYSystem%3EE886FE0308.protected

  private:
    //## Constructors (generated)
      CSYSystem(const CSYSystem &right);

    //## Assignment Operation (generated)
      const CSYSystem & operator=(const CSYSystem &right);

    //## Equality Operations (generated)
      bool operator==(const CSYSystem &right) const;

      bool operator!=(const CSYSystem &right) const;


    //## Other Operations (specified)
      //## Operation: WriteLogFile%1077175166
      static void WriteLogFile (XCOException* p_pException);

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EE9943C00FB
      //## Role: CSYSystem::pSystemInterface%3EE9943C02E0
      //## begin CSYSystem::pSystemInterface%3EE9943C02E0.role preserve=no  public: static CSYSystemInterface { -> RFHN}
      static CSYSystemInterface *m_pSystemInterface;
      //## end CSYSystem::pSystemInterface%3EE9943C02E0.role

    // Additional Private Declarations
      //## begin CSYSystem%3EE886FE0308.private preserve=yes
      //## end CSYSystem%3EE886FE0308.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYSystem%3EE886FE0308.implementation preserve=yes
      //## end CSYSystem%3EE886FE0308.implementation

};

//## begin CSYSystem%3EE886FE0308.postscript preserve=yes
//## end CSYSystem%3EE886FE0308.postscript

// Class CSYSystem 

//## begin module%3EDC5B3C01D2.epilog preserve=yes
//## end module%3EDC5B3C01D2.epilog


#endif
