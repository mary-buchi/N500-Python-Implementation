//## begin module%40C8045D022E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40C8045D022E.cm

//## begin module%40C8045D022E.cp preserve=no
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
//## end module%40C8045D022E.cp

//## Module: EBTCpid%40C8045D022E; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCpid.h

#ifndef EBTCpid_h
#define EBTCpid_h 1

//## begin module%40C8045D022E.additionalIncludes preserve=no
//## end module%40C8045D022E.additionalIncludes

//## begin module%40C8045D022E.includes preserve=yes
//## end module%40C8045D022E.includes

//## begin module%40C8045D022E.declarations preserve=no
//## end module%40C8045D022E.declarations

//## begin module%40C8045D022E.additionalDeclarations preserve=yes
//## end module%40C8045D022E.additionalDeclarations


//## begin CTCPid%40C879EC023F.preface preserve=yes
//## end CTCPid%40C879EC023F.preface

//## Class: CTCPid%40C879EC023F
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%40CDBDA70084;TC_IDENTIFIERS { -> }

class CTCPid 
{
  //## begin CTCPid%40C879EC023F.initialDeclarations preserve=yes
  //## end CTCPid%40C879EC023F.initialDeclarations

  public:
    //## Constructors (generated)
      CTCPid();

    //## Destructor (generated)
      virtual ~CTCPid();


    //## Other Operations (specified)
      //## Operation: Do%1086869809
      double Do (const double p_dact = 0);

      //## Operation: Reset%1086869810
      void Reset ();

      //## Operation: Set%1086869811
      void Set (const double p_dNomValue = 0, const double p_dKp = 0, const double p_dTi = 0, const double p_dTv = 0, const double p_dLLimit = 0, const double p_dULimit = 0, const double p_dTs = 0);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dLLimit%40C87BD70106
      double GetdLLimit ();

      //## Attribute: dULimit%40C87BD70107
      double GetdULimit ();

      //## Attribute: dTs%40C87BD70116
      double GetdTs ();

      //## Attribute: dNom%40CE9C2D0262
      double GetdNom ();

    // Additional Public Declarations
      //## begin CTCPid%40C879EC023F.public preserve=yes
      //## end CTCPid%40C879EC023F.public

  protected:
    // Additional Protected Declarations
      //## begin CTCPid%40C879EC023F.protected preserve=yes
      //## end CTCPid%40C879EC023F.protected

  private:
    //## Constructors (generated)
      CTCPid(const CTCPid &right);

    //## Assignment Operation (generated)
      const CTCPid & operator=(const CTCPid &right);

    //## Equality Operations (generated)
      bool operator==(const CTCPid &right) const;

      bool operator!=(const CTCPid &right) const;

    // Data Members for Class Attributes

      //## Attribute: ddelta%40C87BD700A8
      //## begin CTCPid::ddelta%40C87BD700A8.attr preserve=no  private: double {U} 0
      double m_ddelta;
      //## end CTCPid::ddelta%40C87BD700A8.attr

      //## Attribute: dI%40C87BD700A9
      //## begin CTCPid::dI%40C87BD700A9.attr preserve=no  private: double {U} 0
      double m_dI;
      //## end CTCPid::dI%40C87BD700A9.attr

      //## Attribute: dP%40C87BD700B8
      //## begin CTCPid::dP%40C87BD700B8.attr preserve=no  private: double {U} 0
      double m_dP;
      //## end CTCPid::dP%40C87BD700B8.attr

      //## Attribute: dD%40C87BD700C8
      //## begin CTCPid::dD%40C87BD700C8.attr preserve=no  private: double {U} 0
      double m_dD;
      //## end CTCPid::dD%40C87BD700C8.attr

      //## Attribute: dI1%40C87BD700C9
      //## begin CTCPid::dI1%40C87BD700C9.attr preserve=no  private: double {U} 0
      double m_dI1;
      //## end CTCPid::dI1%40C87BD700C9.attr

      //## Attribute: ddelta1%40C87BD700D7
      //## begin CTCPid::ddelta1%40C87BD700D7.attr preserve=no  private: double {U} 0
      double m_ddelta1;
      //## end CTCPid::ddelta1%40C87BD700D7.attr

      //## Attribute: dKp%40C87BD700E7
      //## begin CTCPid::dKp%40C87BD700E7.attr preserve=no  private: double {U} 0
      double m_dKp;
      //## end CTCPid::dKp%40C87BD700E7.attr

      //## Attribute: dKi%40C87BD700E8
      //## begin CTCPid::dKi%40C87BD700E8.attr preserve=no  private: double {U} 0
      double m_dKi;
      //## end CTCPid::dKi%40C87BD700E8.attr

      //## Attribute: dTv%40C87BD700F6
      //## begin CTCPid::dTv%40C87BD700F6.attr preserve=no  private: double {U} 0
      double m_dTv;
      //## end CTCPid::dTv%40C87BD700F6.attr

      //## begin CTCPid::dLLimit%40C87BD70106.attr preserve=no  public: double {U} 0
      double m_dLLimit;
      //## end CTCPid::dLLimit%40C87BD70106.attr

      //## begin CTCPid::dULimit%40C87BD70107.attr preserve=no  public: double {U} 0
      double m_dULimit;
      //## end CTCPid::dULimit%40C87BD70107.attr

      //## begin CTCPid::dTs%40C87BD70116.attr preserve=no  public: double {U} 0
      double m_dTs;
      //## end CTCPid::dTs%40C87BD70116.attr

      //## Attribute: dk%40C87BD70125
      //## begin CTCPid::dk%40C87BD70125.attr preserve=no  private: double {U} 0
      double m_dk;
      //## end CTCPid::dk%40C87BD70125.attr

      //## begin CTCPid::dNom%40CE9C2D0262.attr preserve=no  public: double {U} 0
      double m_dNom;
      //## end CTCPid::dNom%40CE9C2D0262.attr

      //## Attribute: bInitDone%40D05C9E0375
      //## begin CTCPid::bInitDone%40D05C9E0375.attr preserve=no  private: BOOL {U} false
      BOOL m_bInitDone;
      //## end CTCPid::bInitDone%40D05C9E0375.attr

    // Additional Private Declarations
      //## begin CTCPid%40C879EC023F.private preserve=yes
      //## end CTCPid%40C879EC023F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCPid%40C879EC023F.implementation preserve=yes
      //## end CTCPid%40C879EC023F.implementation

};

//## begin CTCPid%40C879EC023F.postscript preserve=yes
//## end CTCPid%40C879EC023F.postscript

// Class CTCPid 

//## begin module%40C8045D022E.epilog preserve=yes
//## end module%40C8045D022E.epilog


#endif
