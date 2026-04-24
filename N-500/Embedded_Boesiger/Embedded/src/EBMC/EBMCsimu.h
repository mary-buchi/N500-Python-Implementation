//## begin module%3F97883303CC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F97883303CC.cm

//## begin module%3F97883303CC.cp preserve=no
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
//## end module%3F97883303CC.cp

//## Module: EBMCsimu%3F97883303CC; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCsimu.h

#ifndef EBMCsimu_h
#define EBMCsimu_h 1

//## begin module%3F97883303CC.additionalIncludes preserve=no
//## end module%3F97883303CC.additionalIncludes

//## begin module%3F97883303CC.includes preserve=yes
//## end module%3F97883303CC.includes


class EBPI_DLL_DECL CPIMeasurementChannelDataPackage;

//## begin module%3F97883303CC.declarations preserve=no
//## end module%3F97883303CC.declarations

//## begin module%3F97883303CC.additionalDeclarations preserve=yes
//## end module%3F97883303CC.additionalDeclarations


//## begin CMCCtrlSimulation%3F97881D036E.preface preserve=yes
//## end CMCCtrlSimulation%3F97881D036E.preface

//## Class: CMCCtrlSimulation%3F97881D036E
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F979C7E0320;CPIMeasurementChannelDataPackage { -> F}
//## Uses: <unnamed>%3F97A1950311;CHIMCParameter { -> }

class CMCCtrlSimulation 
{
  //## begin CMCCtrlSimulation%3F97881D036E.initialDeclarations preserve=yes
  //## end CMCCtrlSimulation%3F97881D036E.initialDeclarations

  public:
    //## Constructors (generated)
      CMCCtrlSimulation();

    //## Destructor (generated)
      virtual ~CMCCtrlSimulation();


    //## Other Operations (specified)
      //## Operation: Initialize%1066894467
      void Initialize ();

      //## Operation: Start%1067518841
      void Start ();

      //## Operation: GetDataPackage%1066894473
      CPIMeasurementChannelDataPackage* GetDataPackage ();

    // Additional Public Declarations
      //## begin CMCCtrlSimulation%3F97881D036E.public preserve=yes
      //## end CMCCtrlSimulation%3F97881D036E.public

  protected:
    // Additional Protected Declarations
      //## begin CMCCtrlSimulation%3F97881D036E.protected preserve=yes
      //## end CMCCtrlSimulation%3F97881D036E.protected

  private:
    //## Constructors (generated)
      CMCCtrlSimulation(const CMCCtrlSimulation &right);

    //## Assignment Operation (generated)
      const CMCCtrlSimulation & operator=(const CMCCtrlSimulation &right);

    //## Equality Operations (generated)
      bool operator==(const CMCCtrlSimulation &right) const;

      bool operator!=(const CMCCtrlSimulation &right) const;

    // Data Members for Class Attributes

      //## Attribute: sFileName%3F978D1002B2
      //## begin CMCCtrlSimulation::sFileName%3F978D1002B2.attr preserve=no  private: static CString {U} _T("R:\\Bin\\Data\\Stream.bin")
      static CString m_sFileName;
      //## end CMCCtrlSimulation::sFileName%3F978D1002B2.attr

      //## Attribute: pbyDetectorChannel%3F978DFF0013
      //## begin CMCCtrlSimulation::pbyDetectorChannel%3F978DFF0013.attr preserve=no  private: BYTE* {U} NULL
      BYTE* m_pbyDetectorChannel;
      //## end CMCCtrlSimulation::pbyDetectorChannel%3F978DFF0013.attr

      //## Attribute: pbyLaserChannel%3F978E1700CE
      //## begin CMCCtrlSimulation::pbyLaserChannel%3F978E1700CE.attr preserve=no  private: BYTE* {U} NULL
      BYTE* m_pbyLaserChannel;
      //## end CMCCtrlSimulation::pbyLaserChannel%3F978E1700CE.attr

      //## Attribute: iStreamLength%3F97930B0255
      //## begin CMCCtrlSimulation::iStreamLength%3F97930B0255.attr preserve=no  private: INT {U} 0
      INT m_iStreamLength;
      //## end CMCCtrlSimulation::iStreamLength%3F97930B0255.attr

      //## Attribute: dwReadPosition%3F97A09301F7
      //## begin CMCCtrlSimulation::dwReadPosition%3F97A09301F7.attr preserve=no  private: DWORD {U} 0
      DWORD m_dwReadPosition;
      //## end CMCCtrlSimulation::dwReadPosition%3F97A09301F7.attr

    // Additional Private Declarations
      //## begin CMCCtrlSimulation%3F97881D036E.private preserve=yes
      //## end CMCCtrlSimulation%3F97881D036E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCCtrlSimulation%3F97881D036E.implementation preserve=yes
      //## end CMCCtrlSimulation%3F97881D036E.implementation

};

//## begin CMCCtrlSimulation%3F97881D036E.postscript preserve=yes
//## end CMCCtrlSimulation%3F97881D036E.postscript

// Class CMCCtrlSimulation 

//## begin module%3F97883303CC.epilog preserve=yes
//## end module%3F97883303CC.epilog


#endif
