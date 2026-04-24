//## begin module%3F4239AB03DD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4239AB03DD.cm

//## begin module%3F4239AB03DD.cp preserve=no
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
//## end module%3F4239AB03DD.cp

//## Module: EBPIcpst%3F4239AB03DD; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIcpst.h

#ifndef EBPIcpst_h
#define EBPIcpst_h 1

//## begin module%3F4239AB03DD.additionalIncludes preserve=no
//## end module%3F4239AB03DD.additionalIncludes

//## begin module%3F4239AB03DD.includes preserve=yes
//## end module%3F4239AB03DD.includes

//## begin module%3F4239AB03DD.declarations preserve=no
//## end module%3F4239AB03DD.declarations

//## begin module%3F4239AB03DD.additionalDeclarations preserve=yes
//## end module%3F4239AB03DD.additionalDeclarations


//## begin CPIComponentsState%3F4235EA0005.preface preserve=yes
//## end CPIComponentsState%3F4235EA0005.preface

//## Class: CPIComponentsState%3F4235EA0005
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIComponentsState 
{
  //## begin CPIComponentsState%3F4235EA0005.initialDeclarations preserve=yes
  //## end CPIComponentsState%3F4235EA0005.initialDeclarations

  public:
    //## Constructors (generated)
      CPIComponentsState();

    //## Destructor (generated)
      virtual ~CPIComponentsState();


    //## Other Operations (specified)
      //## Operation: Create%1061301417
      static void Create ();

      //## Operation: Delete%1061301418
      static void Delete ();

      //## Operation: GetInstance%1061301419
      static CPIComponentsState* GetInstance ();

      //## Operation: GetComponentState%1061301420
      bool GetComponentState (const CString& p_sComponentId);

      //## Operation: SetComponentState%1061301421
      void SetComponentState (const CString& p_sComponentId, const bool p_bActive);

    // Additional Public Declarations
      //## begin CPIComponentsState%3F4235EA0005.public preserve=yes
      //## end CPIComponentsState%3F4235EA0005.public

  protected:
    // Additional Protected Declarations
      //## begin CPIComponentsState%3F4235EA0005.protected preserve=yes
      //## end CPIComponentsState%3F4235EA0005.protected

  private:
    //## Constructors (generated)
      CPIComponentsState(const CPIComponentsState &right);

    //## Assignment Operation (generated)
      const CPIComponentsState & operator=(const CPIComponentsState &right);

    //## Equality Operations (generated)
      bool operator==(const CPIComponentsState &right) const;

      bool operator!=(const CPIComponentsState &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3F4235EA0012
      //## Role: CPIComponentsState::pInstance%3F4235EA0014
      //## begin CPIComponentsState::pInstance%3F4235EA0014.role preserve=no  public: static CPIComponentsState {1..1 -> 1..1RFHN}
      static CPIComponentsState *s_pInstance;
      //## end CPIComponentsState::pInstance%3F4235EA0014.role

    // Additional Private Declarations
      //## begin CPIComponentsState%3F4235EA0005.private preserve=yes
      //## end CPIComponentsState%3F4235EA0005.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIComponentsState%3F4235EA0005.implementation preserve=yes
      //## end CPIComponentsState%3F4235EA0005.implementation

};

//## begin CPIComponentsState%3F4235EA0005.postscript preserve=yes
//## end CPIComponentsState%3F4235EA0005.postscript

// Class CPIComponentsState 

//## begin module%3F4239AB03DD.epilog preserve=yes
//## end module%3F4239AB03DD.epilog


#endif
