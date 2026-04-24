//## begin module%3B8D539703DD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D539703DD.cm

//## begin module%3B8D539703DD.cp preserve=no
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
//## end module%3B8D539703DD.cp

//## Module: EBCOrefc%3B8D539703DD; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOrefc.h

#ifndef EBCOrefc_h
#define EBCOrefc_h 1

//## begin module%3B8D539703DD.additionalIncludes preserve=no
//## end module%3B8D539703DD.additionalIncludes

//## begin module%3B8D539703DD.includes preserve=yes
//## end module%3B8D539703DD.includes



//## begin module%3B8D539703DD.declarations preserve=no
//## end module%3B8D539703DD.declarations

//## begin module%3B8D539703DD.additionalDeclarations preserve=yes
//## end module%3B8D539703DD.additionalDeclarations


//## begin ICORefCounting%3B8D53C70238.preface preserve=yes
//## end ICORefCounting%3B8D53C70238.preface

//## Class: ICORefCounting%3B8D53C70238
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL ICORefCounting 
{
  //## begin ICORefCounting%3B8D53C70238.initialDeclarations preserve=yes
  //## end ICORefCounting%3B8D53C70238.initialDeclarations

  public:
    //## Constructors (generated)
      ICORefCounting();

    //## Constructors (specified)
      //## Operation: ICORefCounting%1164298708
      ICORefCounting (const CString& p_sName);


    //## Other Operations (specified)
      //## Operation: AddRef%999108322
      virtual void AddRef ();

      //## Operation: ReleaseRef%999108323
      virtual void ReleaseRef ();

      //## Operation: TraceLivingObjects%1164298707
      static int TraceLivingObjects ();

      //## Operation: GetLivingObjectInfo%1174997739
      static CString GetLivingObjectInfo ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sName%4565CAE100CA
      void SetsName (CString value);

    // Additional Public Declarations
      //## begin ICORefCounting%3B8D53C70238.public preserve=yes
      //## end ICORefCounting%3B8D53C70238.public

  protected:
    //## Destructor (generated)
      virtual ~ICORefCounting();

    // Data Members for Class Attributes

      //## Attribute: uiRefCount%3B8D53F603E4
      //## begin ICORefCounting::uiRefCount%3B8D53F603E4.attr preserve=no  private: UINT {U} 1
      UINT m_uiRefCount;
      //## end ICORefCounting::uiRefCount%3B8D53F603E4.attr

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3B8D54A10173
      //## Role: ICORefCounting::AccessLock%3B8D54A10341
      //## begin ICORefCounting::AccessLock%3B8D54A10341.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end ICORefCounting::AccessLock%3B8D54A10341.role

    // Additional Protected Declarations
      //## begin ICORefCounting%3B8D53C70238.protected preserve=yes
      //## end ICORefCounting%3B8D53C70238.protected

  private:
    //## Constructors (generated)
      ICORefCounting(const ICORefCounting &right);

    // Data Members for Class Attributes

      //## begin ICORefCounting::sName%4565CAE100CA.attr preserve=no  public: CString {U} 
      CString m_sName;
      //## end ICORefCounting::sName%4565CAE100CA.attr

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%4565C96D0057
      //## Role: ICORefCounting::LivingObjects%4565C96E03D4
      //## begin ICORefCounting::LivingObjects%4565C96E03D4.role preserve=no  public: static ICORefCounting {0..0 -> 1..nRFHN}
      static CTypedPtrList<CPtrList, ICORefCounting*> m_LivingObjects;
      //## end ICORefCounting::LivingObjects%4565C96E03D4.role

      //## Association: EBCO (Core Classes)::<unnamed>%4565C99A021E
      //## Role: ICORefCounting::LivingObjectsLock%4565C99B031A
      //## begin ICORefCounting::LivingObjectsLock%4565C99B031A.role preserve=no  public: static CCriticalSection {1..1 -> 1..1VFHN}
      static CCriticalSection m_LivingObjectsLock;
      //## end ICORefCounting::LivingObjectsLock%4565C99B031A.role

    // Additional Private Declarations
      //## begin ICORefCounting%3B8D53C70238.private preserve=yes
      //## end ICORefCounting%3B8D53C70238.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICORefCounting%3B8D53C70238.implementation preserve=yes
      //## end ICORefCounting%3B8D53C70238.implementation

};

//## begin ICORefCounting%3B8D53C70238.postscript preserve=yes
//## end ICORefCounting%3B8D53C70238.postscript

// Class ICORefCounting 

//## begin module%3B8D539703DD.epilog preserve=yes
//## end module%3B8D539703DD.epilog


#endif
