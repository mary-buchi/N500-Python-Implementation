//## begin module%3FB3834502D6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FB3834502D6.cm

//## begin module%3FB3834502D6.cp preserve=no
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
//## end module%3FB3834502D6.cp

//## Module: EBCOmark%3FB3834502D6; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOmark.h

#ifndef EBCOmark_h
#define EBCOmark_h 1

//## begin module%3FB3834502D6.additionalIncludes preserve=no
//## end module%3FB3834502D6.additionalIncludes

//## begin module%3FB3834502D6.includes preserve=yes
//## end module%3FB3834502D6.includes

//## begin module%3FB3834502D6.declarations preserve=no
//## end module%3FB3834502D6.declarations

//## begin module%3FB3834502D6.additionalDeclarations preserve=yes
//## end module%3FB3834502D6.additionalDeclarations


//## begin CCOMarkup%3FB3770D001D.preface preserve=yes
//## end CCOMarkup%3FB3770D001D.preface

//## Class: CCOMarkup%3FB3770D001D
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL CCOMarkup 
{
  //## begin CCOMarkup%3FB3770D001D.initialDeclarations preserve=yes
  //## end CCOMarkup%3FB3770D001D.initialDeclarations

  private: //## implementation
    //## begin CCOMarkup::ElemPos%3FB3770D01C8.preface preserve=yes
    //## end CCOMarkup::ElemPos%3FB3770D01C8.preface

    //## Class: ElemPos%3FB3770D01C8; implementation
    //## Category: EBCO (Core Classes)%3B86CD280273
    //## Subsystem: EBCO (Core Classes)%3B86CCF602D6
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class ElemPos 
    {
      //## begin CCOMarkup::ElemPos%3FB3770D01C8.initialDeclarations preserve=yes
      //## end CCOMarkup::ElemPos%3FB3770D01C8.initialDeclarations

      public:
        //## Constructors (generated)
          ElemPos();

          ElemPos(const ElemPos &right);

        //## Destructor (generated)
          virtual ~ElemPos();


        //## Other Operations (specified)
          //## Operation: IsEmptyElement%1068729239
          bool IsEmptyElement () const;

          //## Operation: Clear%1068729240
          void Clear ();

        // Data Members for Class Attributes

          //## Attribute: nStartL%3FB3770D01DE
          //## begin CCOMarkup::ElemPos::nStartL%3FB3770D01DE.attr preserve=no  public: int {U} 
          int m_nStartL;
          //## end CCOMarkup::ElemPos::nStartL%3FB3770D01DE.attr

          //## Attribute: nStartR%3FB3770D01DF
          //## begin CCOMarkup::ElemPos::nStartR%3FB3770D01DF.attr preserve=no  public: int {U} 
          int m_nStartR;
          //## end CCOMarkup::ElemPos::nStartR%3FB3770D01DF.attr

          //## Attribute: nEndL%3FB3770D01E6
          //## begin CCOMarkup::ElemPos::nEndL%3FB3770D01E6.attr preserve=no  public: int {U} 
          int m_nEndL;
          //## end CCOMarkup::ElemPos::nEndL%3FB3770D01E6.attr

          //## Attribute: nEndR%3FB3770D01E7
          //## begin CCOMarkup::ElemPos::nEndR%3FB3770D01E7.attr preserve=no  public: int {U} 
          int m_nEndR;
          //## end CCOMarkup::ElemPos::nEndR%3FB3770D01E7.attr

          //## Attribute: nNext%3FB3770D01E8
          //## begin CCOMarkup::ElemPos::nNext%3FB3770D01E8.attr preserve=no  public: int {U} 
          int m_nNext;
          //## end CCOMarkup::ElemPos::nNext%3FB3770D01E8.attr

          //## Attribute: iElemParent%3FB3770D01F0
          //## begin CCOMarkup::ElemPos::iElemParent%3FB3770D01F0.attr preserve=no  public: int {U} 
          int m_iElemParent;
          //## end CCOMarkup::ElemPos::iElemParent%3FB3770D01F0.attr

          //## Attribute: iElemChild%3FB3770D01F1
          //## begin CCOMarkup::ElemPos::iElemChild%3FB3770D01F1.attr preserve=no  public: int {U} 
          int m_iElemChild;
          //## end CCOMarkup::ElemPos::iElemChild%3FB3770D01F1.attr

          //## Attribute: iElemNext%3FB3770D01F2
          //## begin CCOMarkup::ElemPos::iElemNext%3FB3770D01F2.attr preserve=no  public: int {U} 
          int m_iElemNext;
          //## end CCOMarkup::ElemPos::iElemNext%3FB3770D01F2.attr

        // Additional Public Declarations
          //## begin CCOMarkup::ElemPos%3FB3770D01C8.public preserve=yes
          //## end CCOMarkup::ElemPos%3FB3770D01C8.public

      protected:
        // Additional Protected Declarations
          //## begin CCOMarkup::ElemPos%3FB3770D01C8.protected preserve=yes
          //## end CCOMarkup::ElemPos%3FB3770D01C8.protected

      private:
        //## Equality Operations (generated)
          bool operator==(const ElemPos &right) const;

          bool operator!=(const ElemPos &right) const;

        // Additional Private Declarations
          //## begin CCOMarkup::ElemPos%3FB3770D01C8.private preserve=yes
          //## end CCOMarkup::ElemPos%3FB3770D01C8.private

      private: //## implementation
        // Additional Implementation Declarations
          //## begin CCOMarkup::ElemPos%3FB3770D01C8.implementation preserve=yes
          //## end CCOMarkup::ElemPos%3FB3770D01C8.implementation

    };

    //## begin CCOMarkup::ElemPos%3FB3770D01C8.postscript preserve=yes
    //## end CCOMarkup::ElemPos%3FB3770D01C8.postscript

    //## begin CCOMarkup::TokenPos%3FB3770D0204.preface preserve=yes
    //## end CCOMarkup::TokenPos%3FB3770D0204.preface

    //## Class: TokenPos%3FB3770D0204; implementation
    //## Category: EBCO (Core Classes)%3B86CD280273
    //## Subsystem: EBCO (Core Classes)%3B86CCF602D6
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class TokenPos 
    {
      //## begin CCOMarkup::TokenPos%3FB3770D0204.initialDeclarations preserve=yes
      //## end CCOMarkup::TokenPos%3FB3770D0204.initialDeclarations

      public:
        //## Constructors (generated)
          TokenPos();

        //## Destructor (generated)
          virtual ~TokenPos();


        //## Other Operations (specified)
          //## Operation: IsValid%1068729242
          bool IsValid () const;

          //## Operation: Clear%1068729243
          void Clear ();

        // Data Members for Class Attributes

          //## Attribute: nL%3FB3770D021A
          //## begin CCOMarkup::TokenPos::nL%3FB3770D021A.attr preserve=no  public: int {U} 
          int m_nL;
          //## end CCOMarkup::TokenPos::nL%3FB3770D021A.attr

          //## Attribute: nR%3FB3770D0222
          //## begin CCOMarkup::TokenPos::nR%3FB3770D0222.attr preserve=no  public: int {U} 
          int m_nR;
          //## end CCOMarkup::TokenPos::nR%3FB3770D0222.attr

          //## Attribute: nNext%3FB3770D0223
          //## begin CCOMarkup::TokenPos::nNext%3FB3770D0223.attr preserve=no  public: int {U} 
          int m_nNext;
          //## end CCOMarkup::TokenPos::nNext%3FB3770D0223.attr

          //## Attribute: bIsString%3FB3770D0224
          //## begin CCOMarkup::TokenPos::bIsString%3FB3770D0224.attr preserve=no  public: bool {U} 
          bool m_bIsString;
          //## end CCOMarkup::TokenPos::bIsString%3FB3770D0224.attr

        // Additional Public Declarations
          //## begin CCOMarkup::TokenPos%3FB3770D0204.public preserve=yes
          //## end CCOMarkup::TokenPos%3FB3770D0204.public

      protected:
        // Additional Protected Declarations
          //## begin CCOMarkup::TokenPos%3FB3770D0204.protected preserve=yes
          //## end CCOMarkup::TokenPos%3FB3770D0204.protected

      private:
        //## Constructors (generated)
          TokenPos(const TokenPos &right);

        //## Assignment Operation (generated)
          const TokenPos & operator=(const TokenPos &right);

        //## Equality Operations (generated)
          bool operator==(const TokenPos &right) const;

          bool operator!=(const TokenPos &right) const;

        // Additional Private Declarations
          //## begin CCOMarkup::TokenPos%3FB3770D0204.private preserve=yes
          //## end CCOMarkup::TokenPos%3FB3770D0204.private

      private: //## implementation
        // Additional Implementation Declarations
          //## begin CCOMarkup::TokenPos%3FB3770D0204.implementation preserve=yes
          //## end CCOMarkup::TokenPos%3FB3770D0204.implementation

    };

    //## begin CCOMarkup::TokenPos%3FB3770D0204.postscript preserve=yes
    //## end CCOMarkup::TokenPos%3FB3770D0204.postscript

  public:
    //## Constructors (generated)
      CCOMarkup();

      CCOMarkup(const CCOMarkup &right);

    //## Constructors (specified)
      //## Operation: CCOMarkup%1068729245
      CCOMarkup (LPCTSTR szDoc);

    //## Destructor (generated)
      virtual ~CCOMarkup();

    //## Assignment Operation (generated)
      const CCOMarkup & operator=(const CCOMarkup &right);


    //## Other Operations (specified)
      //## Operation: SetDoc%1068729249
      //	 Navigate
      bool SetDoc (LPCTSTR szDoc);

      //## Operation: IsWellFormed%1068729250
      bool IsWellFormed ();

      //## Operation: FindElem%1068729251
      bool FindElem (LPCTSTR szName = NULL);

      //## Operation: FindChildElem%1068729252
      bool FindChildElem (LPCTSTR szName = NULL);

      //## Operation: IntoElem%1068729253
      bool IntoElem ();

      //## Operation: OutOfElem%1068729254
      bool OutOfElem ();

      //## Operation: ResetChildPos%1068729255
      void ResetChildPos ();

      //## Operation: ResetPos%1068729256
      void ResetPos ();

      //## Operation: GetTagName%1068729257
      CString GetTagName ();

      //## Operation: GetChildTagName%1068729258
      CString GetChildTagName ();

      //## Operation: GetData%1068729259
      CString GetData ();

      //## Operation: GetChildData%1068729260
      CString GetChildData ();

      //## Operation: GetAttrib%1068729261
      CString GetAttrib (LPCTSTR szAttrib);

      //## Operation: GetChildAttrib%1068729262
      CString GetChildAttrib (LPCTSTR szAttrib);

      //## Operation: GetOffsets%1068729263
      bool GetOffsets (int& nStart, int& nEnd);

      //## Operation: GetError%1068729264
      CString GetError ();

      //## Operation: GetDoc%1068729265
      //	 Create
      CString GetDoc ();

      //## Operation: AddElem%1068729266
      bool AddElem (LPCTSTR szName, LPCTSTR szValue = NULL);

      //## Operation: AddChildElem%1068729267
      bool AddChildElem (LPCTSTR szName, LPCTSTR szValue = NULL);

      //## Operation: AddAttrib%1068729268
      bool AddAttrib (LPCTSTR szAttrib, LPCTSTR szValue);

      //## Operation: AddChildAttrib%1068729269
      bool AddChildAttrib (LPCTSTR szAttrib, LPCTSTR szValue);

    // Additional Public Declarations
      //## begin CCOMarkup%3FB3770D001D.public preserve=yes
      //## end CCOMarkup%3FB3770D001D.public

  protected:

    //## Other Operations (specified)
      //## Operation: x_GetFreePos%1068729270
      int x_GetFreePos ();

      //## Operation: x_ReleasePos%1068729271
      int x_ReleasePos ();

      //## Operation: x_ParseElem%1068729272
      int x_ParseElem (int iPosParent);

      //## Operation: x_ParseError%1068729273
      int x_ParseError (LPCTSTR szError, LPCTSTR szTag = NULL);

      //## Operation: x_FindChar%1068729274
      bool x_FindChar (int& n, _TCHAR c);

      //## Operation: x_FindToken%1068729275
      bool x_FindToken (TokenPos& token);

      //## Operation: x_GetToken%1068729276
      CString x_GetToken (const TokenPos& token);

      //## Operation: x_GetTagName%1068729277
      CString x_GetTagName (int iPos);

      //## Operation: x_GetData%1068729278
      CString x_GetData (int iPos);

      //## Operation: x_GetAttrib%1068729279
      CString x_GetAttrib (int iPos, LPCTSTR szAttrib);

      //## Operation: x_Add%1068729280
      int x_Add (int iPosParent, int iPosBefore, LPCTSTR szName, LPCTSTR szValue);

      //## Operation: x_FindAttrib%1068729281
      bool x_FindAttrib (TokenPos& token, LPCTSTR szAttrib = NULL);

      //## Operation: x_AddAttrib%1068729282
      int x_AddAttrib (int iPos, LPCTSTR szAttrib, LPCTSTR szValue);

      //## Operation: x_SetAttrib%1068729283
      int x_SetAttrib (int iPos, LPCTSTR szAttrib, LPCTSTR szValue);

      //## Operation: x_SetData%1068729284
      bool x_SetData (int iPos, LPCTSTR szData, int nCDATA);

      //## Operation: x_DocChange%1068729285
      void x_DocChange (int nLeft, int nReplace, const CString& csInsert);

      //## Operation: x_PosInsert%1068729286
      void x_PosInsert (int iPos, int nInsertLength);

      //## Operation: x_Adjust%1068729287
      void x_Adjust (int iPos, int nShift);

      //## Operation: x_TextToDoc%1068729288
      CString x_TextToDoc (LPCTSTR szText, bool bAttrib = false);

      //## Operation: x_TextFromDoc%1068729289
      CString x_TextFromDoc (int nLeft, int nRight);

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3FB394850027
      //## Role: CCOMarkup::aPos%3FB394850325
      //## Constraints:
      //	ordered
      //## begin CCOMarkup::aPos%3FB394850325.role preserve=no  public: CCOMarkup::ElemPos {0 -> nVFHON}
      CArray< ElemPos, ElemPos& > m_aPos;
      //## end CCOMarkup::aPos%3FB394850325.role

    // Additional Protected Declarations
      //## begin CCOMarkup%3FB3770D001D.protected preserve=yes
      //## end CCOMarkup%3FB3770D001D.protected

  private:
    //## Equality Operations (generated)
      bool operator==(const CCOMarkup &right) const;

      bool operator!=(const CCOMarkup &right) const;

    // Data Members for Class Attributes

      //## Attribute: csDoc%3FB3770D00B3
      //## begin CCOMarkup::csDoc%3FB3770D00B3.attr preserve=no  protected: CString {U} 
      CString m_csDoc;
      //## end CCOMarkup::csDoc%3FB3770D00B3.attr

      //## Attribute: nLevel%3FB3770D00BA
      //## begin CCOMarkup::nLevel%3FB3770D00BA.attr preserve=no  protected: int {U} 
      int m_nLevel;
      //## end CCOMarkup::nLevel%3FB3770D00BA.attr

      //## Attribute: csError%3FB3770D00BB
      //## begin CCOMarkup::csError%3FB3770D00BB.attr preserve=no  protected: CString {U} 
      CString m_csError;
      //## end CCOMarkup::csError%3FB3770D00BB.attr

      //## Attribute: iPos%3FB3770D00CE
      //## begin CCOMarkup::iPos%3FB3770D00CE.attr preserve=no  protected: int {U} 
      int m_iPos;
      //## end CCOMarkup::iPos%3FB3770D00CE.attr

      //## Attribute: iPosChild%3FB3770D00CF
      //## begin CCOMarkup::iPosChild%3FB3770D00CF.attr preserve=no  protected: int {U} 
      int m_iPosChild;
      //## end CCOMarkup::iPosChild%3FB3770D00CF.attr

      //## Attribute: iPosFree%3FB3770D00D8
      //## begin CCOMarkup::iPosFree%3FB3770D00D8.attr preserve=no  protected: int {U} 
      int m_iPosFree;
      //## end CCOMarkup::iPosFree%3FB3770D00D8.attr

    // Additional Private Declarations
      //## begin CCOMarkup%3FB3770D001D.private preserve=yes
      //## end CCOMarkup%3FB3770D001D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOMarkup%3FB3770D001D.implementation preserve=yes
      //## end CCOMarkup%3FB3770D001D.implementation

};

//## begin CCOMarkup%3FB3770D001D.postscript preserve=yes
//## end CCOMarkup%3FB3770D001D.postscript

// Class CCOMarkup::ElemPos 

// Class CCOMarkup::TokenPos 

// Class CCOMarkup 

//## begin module%3FB3834502D6.epilog preserve=yes
//## end module%3FB3834502D6.epilog


#endif
