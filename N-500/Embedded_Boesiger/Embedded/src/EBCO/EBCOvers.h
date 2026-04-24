//## begin module%406C1D8201C7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%406C1D8201C7.cm

//## begin module%406C1D8201C7.cp preserve=no
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
//## end module%406C1D8201C7.cp

//## Module: EBCOvers%406C1D8201C7; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOvers.h

#ifndef EBCOvers_h
#define EBCOvers_h 1

//## begin module%406C1D8201C7.additionalIncludes preserve=no
//## end module%406C1D8201C7.additionalIncludes

//## begin module%406C1D8201C7.includes preserve=yes
//## end module%406C1D8201C7.includes

//## begin module%406C1D8201C7.declarations preserve=no
//## end module%406C1D8201C7.declarations

//## begin module%406C1D8201C7.additionalDeclarations preserve=yes
//## end module%406C1D8201C7.additionalDeclarations


//## begin CCOVersion%406C1D6601C6.preface preserve=yes
//## end CCOVersion%406C1D6601C6.preface

//## Class: CCOVersion%406C1D6601C6
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL CCOVersion 
{
  //## begin CCOVersion%406C1D6601C6.initialDeclarations preserve=yes
  //## end CCOVersion%406C1D6601C6.initialDeclarations

  public:
    //## Constructors (generated)
      CCOVersion();

      CCOVersion(const CCOVersion &right);

    //## Constructors (specified)
      //## Operation: CCOVersion%1080827389
      CCOVersion (const CString& p_sVersion);

    //## Destructor (generated)
      virtual ~CCOVersion();

    //## Equality Operations (generated)
      bool operator==(const CCOVersion &right) const;

      bool operator!=(const CCOVersion &right) const;

    //## Relational Operations (generated)
      bool operator<(const CCOVersion &right) const;

      bool operator>(const CCOVersion &right) const;

      bool operator<=(const CCOVersion &right) const;

      bool operator>=(const CCOVersion &right) const;


    //## Other Operations (specified)
      //## Operation: operator()%1080827392
      CString operator () (CString );

    // Additional Public Declarations
      //## begin CCOVersion%406C1D6601C6.public preserve=yes
      //## end CCOVersion%406C1D6601C6.public

  protected:
    // Additional Protected Declarations
      //## begin CCOVersion%406C1D6601C6.protected preserve=yes
      //## end CCOVersion%406C1D6601C6.protected

  private:
    //## Assignment Operation (generated)
      const CCOVersion & operator=(const CCOVersion &right);


    //## Other Operations (specified)
      //## Operation: CompareMajor%1080827390
      int CompareMajor (const CCOVersion& p_Right) const;

      //## Operation: CompareMinor%1080827391
      int CompareMinor (const CCOVersion& p_Right) const;

    // Data Members for Class Attributes

      //## Attribute: sMajor%406C1E240011
      //## begin CCOVersion::sMajor%406C1E240011.attr preserve=no  private: CString {U} 
      CString m_sMajor;
      //## end CCOVersion::sMajor%406C1E240011.attr

      //## Attribute: sMinor%406C1E2F01C5
      //## begin CCOVersion::sMinor%406C1E2F01C5.attr preserve=no  private: CString {U} 
      CString m_sMinor;
      //## end CCOVersion::sMinor%406C1E2F01C5.attr

    // Additional Private Declarations
      //## begin CCOVersion%406C1D6601C6.private preserve=yes
      //## end CCOVersion%406C1D6601C6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOVersion%406C1D6601C6.implementation preserve=yes
      //## end CCOVersion%406C1D6601C6.implementation

};

//## begin CCOVersion%406C1D6601C6.postscript preserve=yes
//## end CCOVersion%406C1D6601C6.postscript

// Class CCOVersion 

//## begin module%406C1D8201C7.epilog preserve=yes
//## end module%406C1D8201C7.epilog


#endif
