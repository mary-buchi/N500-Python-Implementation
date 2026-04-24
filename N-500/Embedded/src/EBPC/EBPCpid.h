//## begin module%4033A00C015F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%4033A00C015F.cm

//## begin module%4033A00C015F.cp preserve=no
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
//## end module%4033A00C015F.cp

//## Module: EBPCpid%4033A00C015F; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCpid.h

#ifndef EBPCpid_h
#define EBPCpid_h 1

//## begin module%4033A00C015F.additionalIncludes preserve=no
//## end module%4033A00C015F.additionalIncludes

//## begin module%4033A00C015F.includes preserve=yes
//## end module%4033A00C015F.includes

//## begin module%4033A00C015F.declarations preserve=no
//## end module%4033A00C015F.declarations

//## begin module%4033A00C015F.additionalDeclarations preserve=yes
//## end module%4033A00C015F.additionalDeclarations


//## begin CPCPid%403398C701DC.preface preserve=yes
//## end CPCPid%403398C701DC.preface

//## Class: CPCPid%403398C701DC
//	x_nom      -> Regler Sollwert
//	x_act      -> aktueller Istwert
//	Kp         -> P-Verstärkungsfaktor
//	Ti         -> Nachstellzeit (I-Anteil)
//	Tv         -> Vorstellzeit (D-Anteil)
//	LimitUp    -> oberes Limit - Stellwert Begrenzung
//	LimitDown  -> unteres Limit - Stellwert Begrenzung
//	Ts         -> Reglertakt
//	y_k        -> Stellsignal begrenzt
//
//	x_d = 0;	// Regelabweichung zum Zeitpunkt k
//	y_I = 0;      // I-Anteil(k)
//	y_P = 0;      // P-Anteil(k)
//	y_D = 0;      // D-Anteil(k)
//	y_I1 = 0;	    // I-Anteil(k-1)
//	x_d1 = 0;     // Regelabweichung zum Zeitpunkt k-1
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCPid 
{
  //## begin CPCPid%403398C701DC.initialDeclarations preserve=yes
  //## end CPCPid%403398C701DC.initialDeclarations

  public:
    //## Constructors (generated)
      CPCPid();

    //## Destructor (generated)
      virtual ~CPCPid();


    //## Other Operations (specified)
      //## Operation: Do%1077125104
      double Do (const double p_dnom = 0, const double p_dact = 0);

      //## Operation: Reset%1077125105
      void Reset ();

      //## Operation: Set%1077174615
      void Set (const double p_dKp = 0, const double p_dTi = 0, const double p_dTv = 0, const double p_dLLimit = 0, const double p_dULimit = 0, const double p_dTs = 0, const double p_dDACGain = 0, const double p_dDACOffset = 0);

      //## Operation: PresetI1%1077198848
      void PresetI1 (const double p_dPresetValue);

    // Additional Public Declarations
      //## begin CPCPid%403398C701DC.public preserve=yes
      //## end CPCPid%403398C701DC.public

  protected:
    // Additional Protected Declarations
      //## begin CPCPid%403398C701DC.protected preserve=yes
      //## end CPCPid%403398C701DC.protected

  private:
    //## Constructors (generated)
      CPCPid(const CPCPid &right);

    //## Assignment Operation (generated)
      const CPCPid & operator=(const CPCPid &right);

    //## Equality Operations (generated)
      bool operator==(const CPCPid &right) const;

      bool operator!=(const CPCPid &right) const;

    // Data Members for Class Attributes

      //## Attribute: ddelta%4033A09E0249
      //## begin CPCPid::ddelta%4033A09E0249.attr preserve=no  private: double {U} 0
      double m_ddelta;
      //## end CPCPid::ddelta%4033A09E0249.attr

      //## Attribute: dI%4033A10201EC
      //## begin CPCPid::dI%4033A10201EC.attr preserve=no  private: double {U} 0
      double m_dI;
      //## end CPCPid::dI%4033A10201EC.attr

      //## Attribute: dP%4033A1430065
      //## begin CPCPid::dP%4033A1430065.attr preserve=no  private: double {U} 0
      double m_dP;
      //## end CPCPid::dP%4033A1430065.attr

      //## Attribute: dD%4033A1610036
      //## begin CPCPid::dD%4033A1610036.attr preserve=no  private: double {U} 0
      double m_dD;
      //## end CPCPid::dD%4033A1610036.attr

      //## Attribute: dI1%4033A1620046
      //## begin CPCPid::dI1%4033A1620046.attr preserve=no  private: double {U} 0
      double m_dI1;
      //## end CPCPid::dI1%4033A1620046.attr

      //## Attribute: ddelta1%4033A163021B
      //## begin CPCPid::ddelta1%4033A163021B.attr preserve=no  private: double {U} 0
      double m_ddelta1;
      //## end CPCPid::ddelta1%4033A163021B.attr

      //## Attribute: dKp%4033A3B301FB
      //## begin CPCPid::dKp%4033A3B301FB.attr preserve=no  private: double {U} 0
      double m_dKp;
      //## end CPCPid::dKp%4033A3B301FB.attr

      //## Attribute: dKi%4033A3E80130
      //## begin CPCPid::dKi%4033A3E80130.attr preserve=no  private: double {U} 0
      double m_dKi;
      //## end CPCPid::dKi%4033A3E80130.attr

      //## Attribute: dTv%4033A3EA00E2
      //## begin CPCPid::dTv%4033A3EA00E2.attr preserve=no  private: double {U} 0
      double m_dTv;
      //## end CPCPid::dTv%4033A3EA00E2.attr

      //## Attribute: dLLimit%4033A4890343
      //## begin CPCPid::dLLimit%4033A4890343.attr preserve=no  private: double {U} 0
      double m_dLLimit;
      //## end CPCPid::dLLimit%4033A4890343.attr

      //## Attribute: dULimit%4033A48B0372
      //## begin CPCPid::dULimit%4033A48B0372.attr preserve=no  private: double {U} 0
      double m_dULimit;
      //## end CPCPid::dULimit%4033A48B0372.attr

      //## Attribute: dTs%4033A4B90324
      //## begin CPCPid::dTs%4033A4B90324.attr preserve=no  private: double {U} 0
      double m_dTs;
      //## end CPCPid::dTs%4033A4B90324.attr

      //## Attribute: dy%4034612D0084
      //## begin CPCPid::dy%4034612D0084.attr preserve=no  private: double {U} 0
      double m_dy;
      //## end CPCPid::dy%4034612D0084.attr

      //## Attribute: dDACGain%40FD2A0202E3
      //## begin CPCPid::dDACGain%40FD2A0202E3.attr preserve=no  private: double {U} 0
      double m_dDACGain;
      //## end CPCPid::dDACGain%40FD2A0202E3.attr

      //## Attribute: dDACOffset%40FD2A110004
      //## begin CPCPid::dDACOffset%40FD2A110004.attr preserve=no  private: double {U} 0
      double m_dDACOffset;
      //## end CPCPid::dDACOffset%40FD2A110004.attr

      //## Attribute: dk%40FE10F2037D
      //## begin CPCPid::dk%40FE10F2037D.attr preserve=no  private: double {U} 0
      double m_dk;
      //## end CPCPid::dk%40FE10F2037D.attr

    // Additional Private Declarations
      //## begin CPCPid%403398C701DC.private preserve=yes
      //## end CPCPid%403398C701DC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCPid%403398C701DC.implementation preserve=yes
      //## end CPCPid%403398C701DC.implementation

};

//## begin CPCPid%403398C701DC.postscript preserve=yes
//## end CPCPid%403398C701DC.postscript

// Class CPCPid 

//## begin module%4033A00C015F.epilog preserve=yes
//## end module%4033A00C015F.epilog


#endif
