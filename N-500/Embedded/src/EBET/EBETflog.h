//## begin module%468BA97C0221.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%468BA97C0221.cm

//## begin module%468BA97C0221.cp preserve=no
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
//## end module%468BA97C0221.cp

//## Module: EBETflog%468BA97C0221; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETflog.h

#ifndef EBETflog_h
#define EBETflog_h 1

//## begin module%468BA97C0221.additionalIncludes preserve=no
//## end module%468BA97C0221.additionalIncludes

//## begin module%468BA97C0221.includes preserve=yes
//## end module%468BA97C0221.includes



//## begin module%468BA97C0221.declarations preserve=no
//## end module%468BA97C0221.declarations

//## begin module%468BA97C0221.additionalDeclarations preserve=yes
//## end module%468BA97C0221.additionalDeclarations


//## begin CETFileLogger%468BA9A6033A.preface preserve=yes
//## end CETFileLogger%468BA9A6033A.preface

//## Class: CETFileLogger%468BA9A6033A
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class  EBET_DLL_DECL CETFileLogger 
{
  //## begin CETFileLogger%468BA9A6033A.initialDeclarations preserve=yes
  //## end CETFileLogger%468BA9A6033A.initialDeclarations

  public:
    //## Destructor (generated)
      virtual ~CETFileLogger();


    //## Other Operations (specified)
      //## Operation: Create%1183536497
      static void Create ();

      //## Operation: Delete%1183536498
      static void Delete ();

      //## Operation: GetInstance%1183536499
      static CETFileLogger* GetInstance ();

      //## Operation: AddMessage%1183536500
      void AddMessage (const WCHAR* p_sMsg);

      //## Operation: AddMessage%1183536501
      void AddMessage (const WCHAR* p_sMsg, const WCHAR* p_sPar);

      //## Operation: AddMessage%1183536502
      void AddMessage (const WCHAR* p_sMsg, int p_iPar);

      //## Operation: AddMessage%1183615547
      void AddMessage (const WCHAR* p_sMsg, int p_iPar1, int p_iPar2);

    // Additional Public Declarations
      //## begin CETFileLogger%468BA9A6033A.public preserve=yes
      //## end CETFileLogger%468BA9A6033A.public

  protected:
    // Additional Protected Declarations
      //## begin CETFileLogger%468BA9A6033A.protected preserve=yes
      //## end CETFileLogger%468BA9A6033A.protected

  private:
    //## Constructors (generated)
      CETFileLogger();

      CETFileLogger(const CETFileLogger &right);

    //## Assignment Operation (generated)
      const CETFileLogger & operator=(const CETFileLogger &right);

    //## Equality Operations (generated)
      bool operator==(const CETFileLogger &right) const;

      bool operator!=(const CETFileLogger &right) const;

    // Data Members for Class Attributes

      //## Attribute: iStartTick%468BAB0602E6
      //## begin CETFileLogger::iStartTick%468BAB0602E6.attr preserve=no  private: int {U} 0
      int m_iStartTick;
      //## end CETFileLogger::iStartTick%468BAB0602E6.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%468BA9E4023F
      //## Role: CETFileLogger::pInstance%468BA9E50350
      //## begin CETFileLogger::pInstance%468BA9E50350.role preserve=no  public: static CETFileLogger {1..1 -> 1..1RFHN}
      static CETFileLogger *m_pInstance;
      //## end CETFileLogger::pInstance%468BA9E50350.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468BAACE0263
      //## Role: CETFileLogger::AccessLock%468BAACF0099
      //## begin CETFileLogger::AccessLock%468BAACF0099.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CETFileLogger::AccessLock%468BAACF0099.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468BAAEA01EC
      //## Role: CETFileLogger::pFile%468BAAEB008F
      //## begin CETFileLogger::pFile%468BAAEB008F.role preserve=no  public: CFile {1..1 -> 1..1RFHN}
      CFile *m_pFile;
      //## end CETFileLogger::pFile%468BAAEB008F.role

    // Additional Private Declarations
      //## begin CETFileLogger%468BA9A6033A.private preserve=yes
      //## end CETFileLogger%468BA9A6033A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETFileLogger%468BA9A6033A.implementation preserve=yes
      //## end CETFileLogger%468BA9A6033A.implementation

};

//## begin CETFileLogger%468BA9A6033A.postscript preserve=yes
//## end CETFileLogger%468BA9A6033A.postscript

// Class CETFileLogger 

//## begin module%468BA97C0221.epilog preserve=yes
//## end module%468BA97C0221.epilog


#endif
