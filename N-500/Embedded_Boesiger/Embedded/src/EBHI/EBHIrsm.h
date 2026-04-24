//## begin module%3E59DEFE036B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E59DEFE036B.cm

//## begin module%3E59DEFE036B.cp preserve=no
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
//## end module%3E59DEFE036B.cp

//## Module: EBHIrsm%3E59DEFE036B; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIrsm.h

#ifndef EBHIrsm_h
#define EBHIrsm_h 1

//## begin module%3E59DEFE036B.additionalIncludes preserve=no
//## end module%3E59DEFE036B.additionalIncludes

//## begin module%3E59DEFE036B.includes preserve=yes
//## end module%3E59DEFE036B.includes



//## begin module%3E59DEFE036B.declarations preserve=no
//## end module%3E59DEFE036B.declarations

//## begin module%3E59DEFE036B.additionalDeclarations preserve=yes
//## end module%3E59DEFE036B.additionalDeclarations


//## begin CHIReservedSharedMemory%3E59DEAC029F.preface preserve=yes
//## end CHIReservedSharedMemory%3E59DEAC029F.preface

//## Class: CHIReservedSharedMemory%3E59DEAC029F
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E59EA48000F;CHITDefinitions { -> }
//## Uses: <unnamed>%3E670DA703B9;CHIExceptionError { -> }
//## Uses: <unnamed>%3E6715B90138;HI_IDENTIFIERS { -> }
//## Uses: <unnamed>%3E67658C006D;CHITReservedSharedMemory { -> }

class CHIReservedSharedMemory 
{
  //## begin CHIReservedSharedMemory%3E59DEAC029F.initialDeclarations preserve=yes
  //## end CHIReservedSharedMemory%3E59DEAC029F.initialDeclarations

  public:
    //## Constructors (generated)
      CHIReservedSharedMemory();

    //## Destructor (generated)
      virtual ~CHIReservedSharedMemory();


    //## Other Operations (specified)
      //## Operation: AllocRSMProcessImage%1046077270
      static void AllocRSMProcessImage (DWORD p_dwMemorySize = 0);

      //## Operation: DeAllocRSMProcessImage%1046077271
      static void DeAllocRSMProcessImage ();

      //## Operation: AllocRSMStreamBuffer%1046077272
      static void AllocRSMStreamBuffer (DWORD p_dwMemorySize = 0);

      //## Operation: DeAllocRSMStreamBuffer%1046077273
      static void DeAllocRSMStreamBuffer ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E661B6E00CB
      //## Role: CHIReservedSharedMemory::pVAdrStreamBuffer%3E661B6E03BA
      static DWORD * GetpVAdrStreamBuffer ();

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E67211F03A9
      //## Role: CHIReservedSharedMemory::pVAdrProcessImage%3E67212002C0
      static DWORD * GetpVAdrProcessImage ();

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E661B6E00CB
      //## begin CHIReservedSharedMemory::pVAdrStreamBuffer%3E661B6E03BA.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
      static DWORD *m_pVAdrStreamBuffer;
      //## end CHIReservedSharedMemory::pVAdrStreamBuffer%3E661B6E03BA.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E67211F03A9
      //## begin CHIReservedSharedMemory::pVAdrProcessImage%3E67212002C0.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
      static DWORD *m_pVAdrProcessImage;
      //## end CHIReservedSharedMemory::pVAdrProcessImage%3E67212002C0.role

    // Additional Public Declarations
      //## begin CHIReservedSharedMemory%3E59DEAC029F.public preserve=yes
      //## end CHIReservedSharedMemory%3E59DEAC029F.public

  protected:
    // Additional Protected Declarations
      //## begin CHIReservedSharedMemory%3E59DEAC029F.protected preserve=yes
      //## end CHIReservedSharedMemory%3E59DEAC029F.protected

  private:
    //## Constructors (generated)
      CHIReservedSharedMemory(const CHIReservedSharedMemory &right);

    //## Assignment Operation (generated)
      const CHIReservedSharedMemory & operator=(const CHIReservedSharedMemory &right);

    //## Equality Operations (generated)
      bool operator==(const CHIReservedSharedMemory &right) const;

      bool operator!=(const CHIReservedSharedMemory &right) const;

    // Additional Private Declarations
      //## begin CHIReservedSharedMemory%3E59DEAC029F.private preserve=yes
      //## end CHIReservedSharedMemory%3E59DEAC029F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIReservedSharedMemory%3E59DEAC029F.implementation preserve=yes
      //## end CHIReservedSharedMemory%3E59DEAC029F.implementation

};

//## begin CHIReservedSharedMemory%3E59DEAC029F.postscript preserve=yes
//## end CHIReservedSharedMemory%3E59DEAC029F.postscript

// Class CHIReservedSharedMemory 

//## begin module%3E59DEFE036B.epilog preserve=yes
//## end module%3E59DEFE036B.epilog


#endif
