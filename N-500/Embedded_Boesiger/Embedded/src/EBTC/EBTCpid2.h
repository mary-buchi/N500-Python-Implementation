//## begin module%48898FCD01E8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%48898FCD01E8.cm

//## begin module%48898FCD01E8.cp preserve=no
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
//## end module%48898FCD01E8.cp

//## Module: EBTCpid2%48898FCD01E8; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCpid2.h

#ifndef EBTCpid2_h
#define EBTCpid2_h 1

//## begin module%48898FCD01E8.additionalIncludes preserve=no
//## end module%48898FCD01E8.additionalIncludes

//## begin module%48898FCD01E8.includes preserve=yes
//## end module%48898FCD01E8.includes

//## begin module%48898FCD01E8.declarations preserve=no
//## end module%48898FCD01E8.declarations

//## begin module%48898FCD01E8.additionalDeclarations preserve=yes
//## end module%48898FCD01E8.additionalDeclarations


//## begin ETCPowerState%48AA5E250110.preface preserve=yes
//## end ETCPowerState%48AA5E250110.preface

//## Class: ETCPowerState%48AA5E250110
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {ePowerStateLow, ePowerStateRegular, ePowerStateHigh} ETCPowerState;

//## begin ETCPowerState%48AA5E250110.postscript preserve=yes
//## end ETCPowerState%48AA5E250110.postscript

//## begin CTCPid2%4889905D0080.preface preserve=yes
//## end CTCPid2%4889905D0080.preface

//## Class: CTCPid2%4889905D0080
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4889977D01A8;TC_IDENTIFIERS { -> }
//## Uses: <unnamed>%48AA62BF023F;ETCPowerState { -> }

class CTCPid2 
{
  //## begin CTCPid2%4889905D0080.initialDeclarations preserve=yes
  //## end CTCPid2%4889905D0080.initialDeclarations

  public:
    //## Constructors (generated)
      CTCPid2();

    //## Destructor (generated)
      virtual ~CTCPid2();


    //## Other Operations (specified)
      //## Operation: Do%1216975779
      double Do (const double p_dact = 0);

      //## Operation: Reset%1216975780
      void Reset ();

      //## Operation: Set%1216975781
      void Set (const double p_dNomValue = 0, const double p_dKp = 0, const double p_dTi = 0, const double p_dTv = 0, const double p_dLLimit = 0, const double p_dULimit = 0, const double p_dTs = 0);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dLLimit%488991230384
      double GetdLLimit ();

      //## Attribute: dULimit%48899123038C
      double GetdULimit ();

      //## Attribute: dTs%488991230393
      double GetdTs ();

      //## Attribute: dNom%4889912303A4
      double GetdNom ();

    // Additional Public Declarations
      //## begin CTCPid2%4889905D0080.public preserve=yes
      //## end CTCPid2%4889905D0080.public

  protected:
    // Additional Protected Declarations
      //## begin CTCPid2%4889905D0080.protected preserve=yes
      //## end CTCPid2%4889905D0080.protected

  private:
    //## Constructors (generated)
      CTCPid2(const CTCPid2 &right);

    //## Assignment Operation (generated)
      const CTCPid2 & operator=(const CTCPid2 &right);

    //## Equality Operations (generated)
      bool operator==(const CTCPid2 &right) const;

      bool operator!=(const CTCPid2 &right) const;


    //## Other Operations (specified)
      //## Operation: EstimatedI%1219123866
      double EstimatedI (double p_dNomTemp, ETCPowerState p_ePowerState, double p_dKp);

    // Data Members for Class Attributes

      //## Attribute: ddelta%488991230346
      //## begin CTCPid2::ddelta%488991230346.attr preserve=no  private: double {U} 0
      double m_ddelta;
      //## end CTCPid2::ddelta%488991230346.attr

      //## Attribute: dI%48899123034D
      //## begin CTCPid2::dI%48899123034D.attr preserve=no  private: double {U} 0
      double m_dI;
      //## end CTCPid2::dI%48899123034D.attr

      //## Attribute: dP%488991230353
      //## begin CTCPid2::dP%488991230353.attr preserve=no  private: double {U} 0
      double m_dP;
      //## end CTCPid2::dP%488991230353.attr

      //## Attribute: dD%48899123035A
      //## begin CTCPid2::dD%48899123035A.attr preserve=no  private: double {U} 0
      double m_dD;
      //## end CTCPid2::dD%48899123035A.attr

      //## Attribute: dI1%488991230360
      //## begin CTCPid2::dI1%488991230360.attr preserve=no  private: double {U} 0
      double m_dI1;
      //## end CTCPid2::dI1%488991230360.attr

      //## Attribute: ddelta1%488991230367
      //## begin CTCPid2::ddelta1%488991230367.attr preserve=no  private: double {U} 0
      double m_ddelta1;
      //## end CTCPid2::ddelta1%488991230367.attr

      //## Attribute: dKp%48899123036E
      //## begin CTCPid2::dKp%48899123036E.attr preserve=no  private: double {U} 0
      double m_dKp;
      //## end CTCPid2::dKp%48899123036E.attr

      //## Attribute: dKi%488991230375
      //## begin CTCPid2::dKi%488991230375.attr preserve=no  private: double {U} 0
      double m_dKi;
      //## end CTCPid2::dKi%488991230375.attr

      //## Attribute: dTv%48899123037C
      //## begin CTCPid2::dTv%48899123037C.attr preserve=no  private: double {U} 0
      double m_dTv;
      //## end CTCPid2::dTv%48899123037C.attr

      //## begin CTCPid2::dLLimit%488991230384.attr preserve=no  public: double {U} 0
      double m_dLLimit;
      //## end CTCPid2::dLLimit%488991230384.attr

      //## begin CTCPid2::dULimit%48899123038C.attr preserve=no  public: double {U} 0
      double m_dULimit;
      //## end CTCPid2::dULimit%48899123038C.attr

      //## begin CTCPid2::dTs%488991230393.attr preserve=no  public: double {U} 0
      double m_dTs;
      //## end CTCPid2::dTs%488991230393.attr

      //## Attribute: dk%48899123039C
      //## begin CTCPid2::dk%48899123039C.attr preserve=no  private: double {U} 0
      double m_dk;
      //## end CTCPid2::dk%48899123039C.attr

      //## begin CTCPid2::dNom%4889912303A4.attr preserve=no  public: double {U} 0
      double m_dNom;
      //## end CTCPid2::dNom%4889912303A4.attr

      //## Attribute: bInitDone%4889912303AC
      //## begin CTCPid2::bInitDone%4889912303AC.attr preserve=no  private: BOOL {U} false
      BOOL m_bInitDone;
      //## end CTCPid2::bInitDone%4889912303AC.attr

      //## Attribute: iDeltaBufSize%488991410134
      //## begin CTCPid2::iDeltaBufSize%488991410134.attr preserve=no  private: int {UC} 10
      const int  m_iDeltaBufSize;
      //## end CTCPid2::iDeltaBufSize%488991410134.attr

      //## Attribute: iDeltaBufPos%4889920501D1
      //## begin CTCPid2::iDeltaBufPos%4889920501D1.attr preserve=no  private: int {U} 0
      int m_iDeltaBufPos;
      //## end CTCPid2::iDeltaBufPos%4889920501D1.attr

      //## Attribute: dDeltaBuf%4889922500FF
      //## begin CTCPid2::dDeltaBuf%4889922500FF.attr preserve=no  private: double* {U} NULL
      double* m_dDeltaBuf;
      //## end CTCPid2::dDeltaBuf%4889922500FF.attr

      //## Attribute: dDeltaSum%48899304017B
      //## begin CTCPid2::dDeltaSum%48899304017B.attr preserve=no  private: double {U} 0
      double m_dDeltaSum;
      //## end CTCPid2::dDeltaSum%48899304017B.attr

      //## Attribute: dEstimatedI%48AA5906037D
      //## begin CTCPid2::dEstimatedI%48AA5906037D.attr preserve=no  private: double {U} 0
      double m_dEstimatedI;
      //## end CTCPid2::dEstimatedI%48AA5906037D.attr

      //## Attribute: dInnerPBand%48AA5941013B
      //## begin CTCPid2::dInnerPBand%48AA5941013B.attr preserve=no  private: double {U} 0.3
      double m_dInnerPBand;
      //## end CTCPid2::dInnerPBand%48AA5941013B.attr

      //## Attribute: dOuterPBand%48AA597100B1
      //## begin CTCPid2::dOuterPBand%48AA597100B1.attr preserve=no  private: double {U} 1.3
      double m_dOuterPBand;
      //## end CTCPid2::dOuterPBand%48AA597100B1.attr

      //## Attribute: dPBandWidth%48AA59A202D1
      //## begin CTCPid2::dPBandWidth%48AA59A202D1.attr preserve=no  private: double {U} m_dOuterPBand-m_dInnerPBand
      double m_dPBandWidth;
      //## end CTCPid2::dPBandWidth%48AA59A202D1.attr

      //## Attribute: dWeight%48AA5A13038E
      //## begin CTCPid2::dWeight%48AA5A13038E.attr preserve=no  private: double {U} 0
      double m_dWeight;
      //## end CTCPid2::dWeight%48AA5A13038E.attr

      //## Attribute: dDeltaAvg%48AA5A350096
      //## begin CTCPid2::dDeltaAvg%48AA5A350096.attr preserve=no  private: double {U} 0
      double m_dDeltaAvg;
      //## end CTCPid2::dDeltaAvg%48AA5A350096.attr

      //## Attribute: bFirst%48AA5A5401E5
      //## begin CTCPid2::bFirst%48AA5A5401E5.attr preserve=no  private: bool {U} true
      bool m_bFirst;
      //## end CTCPid2::bFirst%48AA5A5401E5.attr

      //## Attribute: eCurrentPowerState%48AA627701EC
      //## begin CTCPid2::eCurrentPowerState%48AA627701EC.attr preserve=no  private: ETCPowerState {U} ePowerStateLow
      ETCPowerState m_eCurrentPowerState;
      //## end CTCPid2::eCurrentPowerState%48AA627701EC.attr

    // Additional Private Declarations
      //## begin CTCPid2%4889905D0080.private preserve=yes
      //## end CTCPid2%4889905D0080.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCPid2%4889905D0080.implementation preserve=yes
      //## end CTCPid2%4889905D0080.implementation

};

//## begin CTCPid2%4889905D0080.postscript preserve=yes
//## end CTCPid2%4889905D0080.postscript

// Class CTCPid2 

//## begin module%48898FCD01E8.epilog preserve=yes
//## end module%48898FCD01E8.epilog


#endif
