//## begin module%3B8EA7B90040.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8EA7B90040.cm

//## begin module%3B8EA7B90040.cp preserve=no
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
//## end module%3B8EA7B90040.cp

//## Module: EBCOtmpl%3B8EA7B90040; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOtmpl.h

#ifndef EBCOtmpl_h
#define EBCOtmpl_h 1

//## begin module%3B8EA7B90040.additionalIncludes preserve=no
//## end module%3B8EA7B90040.additionalIncludes

//## begin module%3B8EA7B90040.includes preserve=yes
//## end module%3B8EA7B90040.includes

//## begin module%3B8EA7B90040.declarations preserve=no
//## end module%3B8EA7B90040.declarations

//## begin module%3B8EA7B90040.additionalDeclarations preserve=yes
//## end module%3B8EA7B90040.additionalDeclarations


//## begin CCOSmartPtr%3B8EA7C5020A.preface preserve=yes
//## end CCOSmartPtr%3B8EA7C5020A.preface

//## Class: CCOSmartPtr%3B8EA7C5020A; Parameterized Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class TYPE>
class CCOSmartPtr 
{
  //## begin CCOSmartPtr%3B8EA7C5020A.initialDeclarations preserve=yes
  //## end CCOSmartPtr%3B8EA7C5020A.initialDeclarations

  public:
    //## Constructors (generated)
      CCOSmartPtr();

    //## Constructors (specified)
      //## Operation: CCOSmartPtr%999204135
      CCOSmartPtr (TYPE* p_pRight);

    //## Destructor (generated)
      virtual ~CCOSmartPtr();


    //## Other Operations (specified)
      //## Operation: operator TYPE*%999204136
      operator TYPE* ();

      //## Operation: operator*%999204137
      TYPE& operator * ();

      //## Operation: operator->%999204138
      TYPE* operator -> ();

      //## Operation: operator=%999204139
      CCOSmartPtr<TYPE>& operator = (CCOSmartPtr<TYPE>& p_pRight);

      //## Operation: operator=%999204140
      CCOSmartPtr<TYPE>& operator = (TYPE* p_pRight);

    // Additional Public Declarations
      //## begin CCOSmartPtr%3B8EA7C5020A.public preserve=yes
      //## end CCOSmartPtr%3B8EA7C5020A.public

  protected:
    // Additional Protected Declarations
      //## begin CCOSmartPtr%3B8EA7C5020A.protected preserve=yes
      //## end CCOSmartPtr%3B8EA7C5020A.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: ptr%3B8EA8460396
      //## begin CCOSmartPtr::ptr%3B8EA8460396.attr preserve=no  private: TYPE* {U} 
      TYPE* m_ptr;
      //## end CCOSmartPtr::ptr%3B8EA8460396.attr

    // Additional Private Declarations
      //## begin CCOSmartPtr%3B8EA7C5020A.private preserve=yes
      //## end CCOSmartPtr%3B8EA7C5020A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOSmartPtr%3B8EA7C5020A.implementation preserve=yes
      //## end CCOSmartPtr%3B8EA7C5020A.implementation

};

//## begin CCOSmartPtr%3B8EA7C5020A.postscript preserve=yes
//## end CCOSmartPtr%3B8EA7C5020A.postscript

//## begin ICOSingleton%3B9144BA010A.preface preserve=yes
//## end ICOSingleton%3B9144BA010A.preface

//## Class: ICOSingleton%3B9144BA010A; Parameterized Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class TYPE>
class ICOSingleton 
{
  //## begin ICOSingleton%3B9144BA010A.initialDeclarations preserve=yes
  //## end ICOSingleton%3B9144BA010A.initialDeclarations

  public:
    //## Constructors (generated)
      ICOSingleton();

    //## Destructor (generated)
      virtual ~ICOSingleton();


    //## Other Operations (specified)
      //## Operation: Create%999369759
      //	DESCRIPTION
      //	Creates the one and only instance of the class
      //
      //	RETURNS
      //	void
      static void Create ();

      //## Operation: Delete%999369760
      //	DESCRIPTION
      //	Deletes the one and only instance of the class
      //
      //	RETURNS
      //	void
      static void Delete ();

      //## Operation: GetInstance%999369761
      //	DESCRIPTION
      //	Gives access to the one and only instance of the class
      //
      //	RETURNS
      //	Pointer to instance
      static TYPE* GetInstance ();

    // Additional Public Declarations
      //## begin ICOSingleton%3B9144BA010A.public preserve=yes
      //## end ICOSingleton%3B9144BA010A.public

  protected:
    // Additional Protected Declarations
      //## begin ICOSingleton%3B9144BA010A.protected preserve=yes
      //## end ICOSingleton%3B9144BA010A.protected

  private:
    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3B9144E10264
      //## Role: ICOSingleton::pInstance%3B9144E400B1
      //## begin ICOSingleton::pInstance%3B9144E400B1.role preserve=no  public: static ICOSingleton {1..1 -> 1..1RFHN}
      static TYPE* s_pInstance;
      //## end ICOSingleton::pInstance%3B9144E400B1.role

    // Additional Private Declarations
      //## begin ICOSingleton%3B9144BA010A.private preserve=yes
      //## end ICOSingleton%3B9144BA010A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOSingleton%3B9144BA010A.implementation preserve=yes
      //## end ICOSingleton%3B9144BA010A.implementation

};

//## begin ICOSingleton%3B9144BA010A.postscript preserve=yes
//## end ICOSingleton%3B9144BA010A.postscript

// Parameterized Class CCOSmartPtr 

// Parameterized Class ICOSingleton 

// Parameterized Class CCOSmartPtr 


template <class TYPE>
CCOSmartPtr<TYPE>::CCOSmartPtr()
  //## begin CCOSmartPtr::CCOSmartPtr%.hasinit preserve=no
  //## end CCOSmartPtr::CCOSmartPtr%.hasinit
  //## begin CCOSmartPtr::CCOSmartPtr%.initialization preserve=yes
      : m_ptr(NULL)
  //## end CCOSmartPtr::CCOSmartPtr%.initialization
{
  //## begin CCOSmartPtr::CCOSmartPtr%.body preserve=yes
  //## end CCOSmartPtr::CCOSmartPtr%.body
}

template <class TYPE>
CCOSmartPtr<TYPE>::CCOSmartPtr (TYPE* p_pRight)
  //## begin CCOSmartPtr::CCOSmartPtr%999204135.hasinit preserve=no
  //## end CCOSmartPtr::CCOSmartPtr%999204135.hasinit
  //## begin CCOSmartPtr::CCOSmartPtr%999204135.initialization preserve=yes
	: m_ptr(p_pRight)
  //## end CCOSmartPtr::CCOSmartPtr%999204135.initialization
{
  //## begin CCOSmartPtr::CCOSmartPtr%999204135.body preserve=yes
  //## end CCOSmartPtr::CCOSmartPtr%999204135.body
}


template <class TYPE>
CCOSmartPtr<TYPE>::~CCOSmartPtr()
{
  //## begin CCOSmartPtr::~CCOSmartPtr%.body preserve=yes
	if (m_ptr)
		m_ptr->ReleaseRef();
  //## end CCOSmartPtr::~CCOSmartPtr%.body
}



//## Other Operations (implementation)
template <class TYPE>
CCOSmartPtr<TYPE>::operator TYPE* ()
{
  //## begin CCOSmartPtr::operator TYPE*%999204136.body preserve=yes
	return m_ptr;
  //## end CCOSmartPtr::operator TYPE*%999204136.body
}

template <class TYPE>
TYPE& CCOSmartPtr<TYPE>::operator * ()
{
  //## begin CCOSmartPtr::operator*%999204137.body preserve=yes
	return *m_ptr;
  //## end CCOSmartPtr::operator*%999204137.body
}

template <class TYPE>
TYPE* CCOSmartPtr<TYPE>::operator -> ()
{
  //## begin CCOSmartPtr::operator->%999204138.body preserve=yes
	return m_ptr;
  //## end CCOSmartPtr::operator->%999204138.body
}

template <class TYPE>
CCOSmartPtr<TYPE>& CCOSmartPtr<TYPE>::operator = (CCOSmartPtr<TYPE>& p_pRight)
{
  //## begin CCOSmartPtr::operator=%999204139.body preserve=yes
	if (m_ptr)
		m_ptr->ReleaseRef();
	m_ptr = p_pRight;

	if (m_ptr)
		m_ptr->AddRef();
	
	return *this;
  //## end CCOSmartPtr::operator=%999204139.body
}

template <class TYPE>
CCOSmartPtr<TYPE>& CCOSmartPtr<TYPE>::operator = (TYPE* p_pRight)
{
  //## begin CCOSmartPtr::operator=%999204140.body preserve=yes
	if (m_ptr)
		m_ptr->ReleaseRef();
	m_ptr = p_pRight;

	return *this;
  //## end CCOSmartPtr::operator=%999204140.body
}

// Additional Declarations
  //## begin CCOSmartPtr%3B8EA7C5020A.declarations preserve=yes
  //## end CCOSmartPtr%3B8EA7C5020A.declarations

// Parameterized Class ICOSingleton 

//## begin ICOSingleton::pInstance%3B9144E400B1.role preserve=no  public: static ICOSingleton {1..1 -> 1..1RFHN}
template <class TYPE>
TYPE* ICOSingleton<TYPE>::s_pInstance = NULL;
//## end ICOSingleton::pInstance%3B9144E400B1.role


template <class TYPE>
ICOSingleton<TYPE>::ICOSingleton()
  //## begin ICOSingleton::ICOSingleton%.hasinit preserve=no
  //## end ICOSingleton::ICOSingleton%.hasinit
  //## begin ICOSingleton::ICOSingleton%.initialization preserve=yes
  //## end ICOSingleton::ICOSingleton%.initialization
{
  //## begin ICOSingleton::ICOSingleton%.body preserve=yes
  //## end ICOSingleton::ICOSingleton%.body
}


template <class TYPE>
ICOSingleton<TYPE>::~ICOSingleton()
{
  //## begin ICOSingleton::~ICOSingleton%.body preserve=yes
  //## end ICOSingleton::~ICOSingleton%.body
}



//## Other Operations (implementation)
template <class TYPE>
void ICOSingleton<TYPE>::Create ()
{
  //## begin ICOSingleton::Create%999369759.body preserve=yes
    ASSERT(s_pInstance == NULL);
    s_pInstance = new TYPE;
  //## end ICOSingleton::Create%999369759.body
}

template <class TYPE>
void ICOSingleton<TYPE>::Delete ()
{
  //## begin ICOSingleton::Delete%999369760.body preserve=yes
    delete s_pInstance;
    s_pInstance = NULL;
  //## end ICOSingleton::Delete%999369760.body
}

template <class TYPE>
TYPE* ICOSingleton<TYPE>::GetInstance ()
{
  //## begin ICOSingleton::GetInstance%999369761.body preserve=yes
    ASSERT(s_pInstance != NULL);
    return s_pInstance;
  //## end ICOSingleton::GetInstance%999369761.body
}

// Additional Declarations
  //## begin ICOSingleton%3B9144BA010A.declarations preserve=yes
  //## end ICOSingleton%3B9144BA010A.declarations

//## begin module%3B8EA7B90040.epilog preserve=yes
//## end module%3B8EA7B90040.epilog


#endif
