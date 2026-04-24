//## begin module%3E75E7800246.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E75E7800246.cm

//## begin module%3E75E7800246.cp preserve=no
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
//## end module%3E75E7800246.cp

//## Module: EBSTdebug%3E75E7800246; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTdebug.h

#ifndef EBSTdebug_h
#define EBSTdebug_h 1

//## begin module%3E75E7800246.additionalIncludes preserve=no
//## end module%3E75E7800246.additionalIncludes

//## begin module%3E75E7800246.includes preserve=yes
//## end module%3E75E7800246.includes


class EBST_DLL_DECL CSTStepperMotorImplementation;

//## begin module%3E75E7800246.declarations preserve=no
//## end module%3E75E7800246.declarations

//## begin module%3E75E7800246.additionalDeclarations preserve=yes
//## end module%3E75E7800246.additionalDeclarations


//## begin CSTDebug%3E75E4E80081.preface preserve=yes
//## end CSTDebug%3E75E4E80081.preface

//## Class: CSTDebug%3E75E4E80081
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTDebug 
{
  //## begin CSTDebug%3E75E4E80081.initialDeclarations preserve=yes
  //## end CSTDebug%3E75E4E80081.initialDeclarations

  public:
    //## Constructors (generated)
      CSTDebug();

    //## Constructors (specified)
      //## Operation: CSTDebug%1048150004
      CSTDebug (CSTStepperMotorImplementation* p_pContext);

    //## Destructor (generated)
      virtual ~CSTDebug();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75E50E038E
      //## Role: CSTDebug::pContext%3E75E5100005
      CSTStepperMotorImplementation * GetpContext ();

    // Additional Public Declarations
      //## begin CSTDebug%3E75E4E80081.public preserve=yes
      //## end CSTDebug%3E75E4E80081.public

  protected:
    // Additional Protected Declarations
      //## begin CSTDebug%3E75E4E80081.protected preserve=yes
      //## end CSTDebug%3E75E4E80081.protected

  private:
    //## Constructors (generated)
      CSTDebug(const CSTDebug &right);

    //## Assignment Operation (generated)
      const CSTDebug & operator=(const CSTDebug &right);

    //## Equality Operations (generated)
      bool operator==(const CSTDebug &right) const;

      bool operator!=(const CSTDebug &right) const;

    // Data Members for Class Attributes

      //## Attribute: bRotationDirection%3E7840DA02F7
      //## begin CSTDebug::bRotationDirection%3E7840DA02F7.attr preserve=no  public: BOOL {U} false
      BOOL m_bRotationDirection;
      //## end CSTDebug::bRotationDirection%3E7840DA02F7.attr

      //## Attribute: uiStepsToGo%3E78413E029A
      //## begin CSTDebug::uiStepsToGo%3E78413E029A.attr preserve=no  public: UINT {U} 0
      UINT m_uiStepsToGo;
      //## end CSTDebug::uiStepsToGo%3E78413E029A.attr

      //## Attribute: uiSpeed%3E78416900C5
      //## begin CSTDebug::uiSpeed%3E78416900C5.attr preserve=no  public: UINT {U} 0
      UINT m_uiSpeed;
      //## end CSTDebug::uiSpeed%3E78416900C5.attr

      //## Attribute: bEnable%3E7868940096
      //## begin CSTDebug::bEnable%3E7868940096.attr preserve=no  public: BOOL {U} false
      BOOL m_bEnable;
      //## end CSTDebug::bEnable%3E7868940096.attr

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75E50E038E
      //## begin CSTDebug::pContext%3E75E5100005.role preserve=no  public: CSTStepperMotorImplementation {1..1 -> 1..1RFHN}
      CSTStepperMotorImplementation *m_pContext;
      //## end CSTDebug::pContext%3E75E5100005.role

    // Additional Private Declarations
      //## begin CSTDebug%3E75E4E80081.private preserve=yes
      //## end CSTDebug%3E75E4E80081.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTDebug%3E75E4E80081.implementation preserve=yes
      //## end CSTDebug%3E75E4E80081.implementation

};

//## begin CSTDebug%3E75E4E80081.postscript preserve=yes
//## end CSTDebug%3E75E4E80081.postscript

// Class CSTDebug 

//## begin module%3E75E7800246.epilog preserve=yes
//## end module%3E75E7800246.epilog


#endif
