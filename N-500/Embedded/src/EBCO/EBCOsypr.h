//## begin module%3B9B537402C9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9B537402C9.cm

//## begin module%3B9B537402C9.cp preserve=no
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
//## end module%3B9B537402C9.cp

//## Module: EBCOsypr%3B9B537402C9; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOsypr.h

#ifndef EBCOsypr_h
#define EBCOsypr_h 1

//## begin module%3B9B537402C9.additionalIncludes preserve=no
//## end module%3B9B537402C9.additionalIncludes

//## begin module%3B9B537402C9.includes preserve=yes
//## end module%3B9B537402C9.includes

// EBCOrefc
#include "EBCOrefc.h"
// EBCOsync
#include "EBCOsync.h"

class EBCO_DLL_DECL CCOIntegerArray;

//## begin module%3B9B537402C9.declarations preserve=no
//## end module%3B9B537402C9.declarations

//## begin module%3B9B537402C9.additionalDeclarations preserve=yes
//## end module%3B9B537402C9.additionalDeclarations


//## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.preface preserve=yes
//## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.preface

//## Class: CCOSyncObjectParameterizedByRef%3B9B4ED00361; Parameterized Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF84A3900F3;ICORefCounting { -> }

template <class TYPE>
class CCOSyncObjectParameterizedByRef : public CCOSyncObject  //## Inherits: <unnamed>%3B9B4EDF0019
{
  //## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.initialDeclarations preserve=yes
  //## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOSyncObjectParameterizedByRef%1000031191
      CCOSyncObjectParameterizedByRef (TYPE p_ContainerValue);

      //## Operation: CCOSyncObjectParameterizedByRef%1164192216
      CCOSyncObjectParameterizedByRef (const CString& p_sName, TYPE p_ContainerValue);

    //## Destructor (generated)
      virtual ~CCOSyncObjectParameterizedByRef();


    //## Other Operations (specified)
      //## Operation: SetValue%1000031189
      //	DESCRIPTION
      //	Sets the container value
      //
      //	PARAMETER
      //	New container value
      virtual void SetValue (TYPE p_Value);

      //## Operation: GetValue%1000031190
      //	DESCRIPTION
      //	Returns the contained value
      //
      //	RETURNS
      //	Container value
      virtual TYPE GetValue ();

      //## Operation: HasValue%1039678349
      virtual bool HasValue ();

    // Additional Public Declarations
      //## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.public preserve=yes
      //## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: ContainerValue%3B9B503B013C
      //## begin CCOSyncObjectParameterizedByRef::ContainerValue%3B9B503B013C.attr preserve=no  private: TYPE {U} p_ContainerValue
      TYPE m_ContainerValue;
      //## end CCOSyncObjectParameterizedByRef::ContainerValue%3B9B503B013C.attr

    // Additional Protected Declarations
      //## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.protected preserve=yes
      //## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.protected

  private:
    // Additional Private Declarations
      //## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.private preserve=yes
      //## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.implementation preserve=yes
      //## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.implementation

};

//## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.postscript preserve=yes
//## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.postscript

//## begin CCOSyncObjectIntArray%3DB510AF038C.preface preserve=yes
//## end CCOSyncObjectIntArray%3DB510AF038C.preface

//## Class: CCOSyncObjectIntArray%3DB510AF038C; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DB518F80225;CCOIntegerArray { -> F}

typedef CCOSyncObjectParameterizedByRef< CCOIntegerArray* > CCOSyncObjectIntArray;

//## begin CCOSyncObjectIntArray%3DB510AF038C.postscript preserve=yes
//## end CCOSyncObjectIntArray%3DB510AF038C.postscript

//## begin CCOSyncObjectParameterized%3DF842A003B2.preface preserve=yes
//## end CCOSyncObjectParameterized%3DF842A003B2.preface

//## Class: CCOSyncObjectParameterized%3DF842A003B2; Parameterized Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class TYPE>
class CCOSyncObjectParameterized : public CCOSyncObject  //## Inherits: <unnamed>%3DF8431A00E4
{
  //## begin CCOSyncObjectParameterized%3DF842A003B2.initialDeclarations preserve=yes
  //## end CCOSyncObjectParameterized%3DF842A003B2.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOSyncObjectParameterized%1039678346
      CCOSyncObjectParameterized (TYPE p_ContainerValue);

      //## Operation: CCOSyncObjectParameterized%1164192215
      CCOSyncObjectParameterized (const CString& p_sName, TYPE p_ContainerValue);

    //## Destructor (generated)
      virtual ~CCOSyncObjectParameterized();


    //## Other Operations (specified)
      //## Operation: SetValue%1039678347
      //	DESCRIPTION
      //	Sets the container value
      //
      //	PARAMETER
      //	New container value
      virtual void SetValue (TYPE p_Value);

      //## Operation: GetValue%1039678348
      //	DESCRIPTION
      //	Returns the contained value
      //
      //	RETURNS
      //	Container value
      virtual TYPE GetValue ();

    // Additional Public Declarations
      //## begin CCOSyncObjectParameterized%3DF842A003B2.public preserve=yes
      //## end CCOSyncObjectParameterized%3DF842A003B2.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: ContainerValue%3DF842DB0028
      //## begin CCOSyncObjectParameterized::ContainerValue%3DF842DB0028.attr preserve=no  private: TYPE {U} p_ContainerValue
      TYPE m_ContainerValue;
      //## end CCOSyncObjectParameterized::ContainerValue%3DF842DB0028.attr

    // Additional Protected Declarations
      //## begin CCOSyncObjectParameterized%3DF842A003B2.protected preserve=yes
      //## end CCOSyncObjectParameterized%3DF842A003B2.protected

  private:
    // Additional Private Declarations
      //## begin CCOSyncObjectParameterized%3DF842A003B2.private preserve=yes
      //## end CCOSyncObjectParameterized%3DF842A003B2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOSyncObjectParameterized%3DF842A003B2.implementation preserve=yes
      //## end CCOSyncObjectParameterized%3DF842A003B2.implementation

};

//## begin CCOSyncObjectParameterized%3DF842A003B2.postscript preserve=yes
//## end CCOSyncObjectParameterized%3DF842A003B2.postscript

//## begin CCOSyncObjectBool%3BA3BD08031A.preface preserve=yes
//## end CCOSyncObjectBool%3BA3BD08031A.preface

//## Class: CCOSyncObjectBool%3BA3BD08031A; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CCOSyncObjectParameterized< bool > CCOSyncObjectBool;

//## begin CCOSyncObjectBool%3BA3BD08031A.postscript preserve=yes
//## end CCOSyncObjectBool%3BA3BD08031A.postscript

//## begin CCOSyncObjectInt%3DAA644F0263.preface preserve=yes
//## end CCOSyncObjectInt%3DAA644F0263.preface

//## Class: CCOSyncObjectInt%3DAA644F0263; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CCOSyncObjectParameterized< INT > CCOSyncObjectInt;

//## begin CCOSyncObjectInt%3DAA644F0263.postscript preserve=yes
//## end CCOSyncObjectInt%3DAA644F0263.postscript

//## begin CCOSyncObjectCString%4028882B0242.preface preserve=yes
//## end CCOSyncObjectCString%4028882B0242.preface

//## Class: CCOSyncObjectCString%4028882B0242; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CCOSyncObjectParameterized< CString > CCOSyncObjectCString;

//## begin CCOSyncObjectCString%4028882B0242.postscript preserve=yes
//## end CCOSyncObjectCString%4028882B0242.postscript

// Parameterized Class CCOSyncObjectParameterizedByRef 

// Parameterized Class CCOSyncObjectParameterized 

template <class TYPE>
inline CCOSyncObjectParameterized<TYPE>::~CCOSyncObjectParameterized()
{
  //## begin CCOSyncObjectParameterized::~CCOSyncObjectParameterized%.body preserve=yes
  //## end CCOSyncObjectParameterized::~CCOSyncObjectParameterized%.body
}


// Parameterized Class CCOSyncObjectParameterizedByRef 


template <class TYPE>
CCOSyncObjectParameterizedByRef<TYPE>::CCOSyncObjectParameterizedByRef (TYPE p_ContainerValue)
  //## begin CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1000031191.hasinit preserve=no
      : m_ContainerValue(p_ContainerValue)
  //## end CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1000031191.hasinit
  //## begin CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1000031191.initialization preserve=yes
  //## end CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1000031191.initialization
{
  //## begin CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1000031191.body preserve=yes
  //## end CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1000031191.body
}

template <class TYPE>
CCOSyncObjectParameterizedByRef<TYPE>::CCOSyncObjectParameterizedByRef (const CString& p_sName, TYPE p_ContainerValue)
  //## begin CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1164192216.hasinit preserve=no
      : m_ContainerValue(p_ContainerValue)
  //## end CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1164192216.hasinit
  //## begin CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1164192216.initialization preserve=yes
	, CCOSyncObject(p_sName)
  //## end CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1164192216.initialization
{
  //## begin CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1164192216.body preserve=yes
  //## end CCOSyncObjectParameterizedByRef::CCOSyncObjectParameterizedByRef%1164192216.body
}


template <class TYPE>
CCOSyncObjectParameterizedByRef<TYPE>::~CCOSyncObjectParameterizedByRef()
{
  //## begin CCOSyncObjectParameterizedByRef::~CCOSyncObjectParameterizedByRef%.body preserve=yes
    if (m_ContainerValue)
    {
        ICORefCounting* l_pRefCntObj = (ICORefCounting*)m_ContainerValue;
        l_pRefCntObj->ReleaseRef();
    }
    m_ContainerValue = NULL;
  //## end CCOSyncObjectParameterizedByRef::~CCOSyncObjectParameterizedByRef%.body
}



//## Other Operations (implementation)
template <class TYPE>
void CCOSyncObjectParameterizedByRef<TYPE>::SetValue (TYPE p_Value)
{
  //## begin CCOSyncObjectParameterizedByRef::SetValue%1000031189.body preserve=yes
    m_ContainerValue = p_Value;
  //## end CCOSyncObjectParameterizedByRef::SetValue%1000031189.body
}

template <class TYPE>
TYPE CCOSyncObjectParameterizedByRef<TYPE>::GetValue ()
{
  //## begin CCOSyncObjectParameterizedByRef::GetValue%1000031190.body preserve=yes
    HasException();
    ASSERT(m_ContainerValue != NULL);

    ICORefCounting* l_pRefCntObj = (ICORefCounting*)m_ContainerValue;
    l_pRefCntObj->AddRef();

    return m_ContainerValue;
  //## end CCOSyncObjectParameterizedByRef::GetValue%1000031190.body
}

template <class TYPE>
bool CCOSyncObjectParameterizedByRef<TYPE>::HasValue ()
{
  //## begin CCOSyncObjectParameterizedByRef::HasValue%1039678349.body preserve=yes
    return m_ContainerValue != NULL;
  //## end CCOSyncObjectParameterizedByRef::HasValue%1039678349.body
}

// Additional Declarations
  //## begin CCOSyncObjectParameterizedByRef%3B9B4ED00361.declarations preserve=yes
  //## end CCOSyncObjectParameterizedByRef%3B9B4ED00361.declarations

//## begin CCOSyncObjectIntArray.instantiation preserve=no
template class CCOSyncObjectParameterizedByRef< CCOIntegerArray* >;
//## end CCOSyncObjectIntArray.instantiation
// Parameterized Class CCOSyncObjectParameterized 


template <class TYPE>
CCOSyncObjectParameterized<TYPE>::CCOSyncObjectParameterized (TYPE p_ContainerValue)
  //## begin CCOSyncObjectParameterized::CCOSyncObjectParameterized%1039678346.hasinit preserve=no
      : m_ContainerValue(p_ContainerValue)
  //## end CCOSyncObjectParameterized::CCOSyncObjectParameterized%1039678346.hasinit
  //## begin CCOSyncObjectParameterized::CCOSyncObjectParameterized%1039678346.initialization preserve=yes
  //## end CCOSyncObjectParameterized::CCOSyncObjectParameterized%1039678346.initialization
{
  //## begin CCOSyncObjectParameterized::CCOSyncObjectParameterized%1039678346.body preserve=yes
  //## end CCOSyncObjectParameterized::CCOSyncObjectParameterized%1039678346.body
}

template <class TYPE>
CCOSyncObjectParameterized<TYPE>::CCOSyncObjectParameterized (const CString& p_sName, TYPE p_ContainerValue)
  //## begin CCOSyncObjectParameterized::CCOSyncObjectParameterized%1164192215.hasinit preserve=no
      : m_ContainerValue(p_ContainerValue)
  //## end CCOSyncObjectParameterized::CCOSyncObjectParameterized%1164192215.hasinit
  //## begin CCOSyncObjectParameterized::CCOSyncObjectParameterized%1164192215.initialization preserve=yes
	, CCOSyncObject(p_sName)
  //## end CCOSyncObjectParameterized::CCOSyncObjectParameterized%1164192215.initialization
{
  //## begin CCOSyncObjectParameterized::CCOSyncObjectParameterized%1164192215.body preserve=yes
  //## end CCOSyncObjectParameterized::CCOSyncObjectParameterized%1164192215.body
}



//## Other Operations (implementation)
template <class TYPE>
void CCOSyncObjectParameterized<TYPE>::SetValue (TYPE p_Value)
{
  //## begin CCOSyncObjectParameterized::SetValue%1039678347.body preserve=yes
    m_ContainerValue = p_Value;
  //## end CCOSyncObjectParameterized::SetValue%1039678347.body
}

template <class TYPE>
TYPE CCOSyncObjectParameterized<TYPE>::GetValue ()
{
  //## begin CCOSyncObjectParameterized::GetValue%1039678348.body preserve=yes
    HasException();
    return m_ContainerValue;
  //## end CCOSyncObjectParameterized::GetValue%1039678348.body
}

// Additional Declarations
  //## begin CCOSyncObjectParameterized%3DF842A003B2.declarations preserve=yes
  //## end CCOSyncObjectParameterized%3DF842A003B2.declarations

//## begin CCOSyncObjectBool.instantiation preserve=no
template class CCOSyncObjectParameterized< bool >;
//## end CCOSyncObjectBool.instantiation
//## begin CCOSyncObjectInt.instantiation preserve=no
template class CCOSyncObjectParameterized< INT >;
//## end CCOSyncObjectInt.instantiation
//## begin CCOSyncObjectCString.instantiation preserve=no
template class CCOSyncObjectParameterized< CString >;
//## end CCOSyncObjectCString.instantiation
//## begin module%3B9B537402C9.epilog preserve=yes
//## end module%3B9B537402C9.epilog


#endif
