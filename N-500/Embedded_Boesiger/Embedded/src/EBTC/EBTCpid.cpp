//## begin module%40C804650328.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40C804650328.cm

//## begin module%40C804650328.cp preserve=no
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
//## end module%40C804650328.cp

//## Module: EBTCpid%40C804650328; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCpid.cpp

// stdafx
#include "stdafx.h"
//## begin module%40C804650328.additionalIncludes preserve=no
//## end module%40C804650328.additionalIncludes

//## begin module%40C804650328.includes preserve=yes
//## end module%40C804650328.includes

// EBTCpid
#include "EBTCpid.h"
// EBTCident
#include "EBTCident.h"
//## begin module%40C804650328.declarations preserve=no
//## end module%40C804650328.declarations

//## begin module%40C804650328.additionalDeclarations preserve=yes
//## end module%40C804650328.additionalDeclarations


// Class CTCPid 

















CTCPid::CTCPid()
  //## begin CTCPid::CTCPid%.hasinit preserve=no
      : m_ddelta(0), m_dI(0), m_dP(0), m_dD(0), m_dI1(0), m_ddelta1(0), m_dKp(0), m_dKi(0), m_dTv(0), m_dLLimit(0), m_dULimit(0), m_dTs(0), m_dk(0), m_dNom(0), m_bInitDone(false)
  //## end CTCPid::CTCPid%.hasinit
  //## begin CTCPid::CTCPid%.initialization preserve=yes
  //## end CTCPid::CTCPid%.initialization
{
  //## begin CTCPid::CTCPid%.body preserve=yes
  //## end CTCPid::CTCPid%.body
}


CTCPid::~CTCPid()
{
  //## begin CTCPid::~CTCPid%.body preserve=yes
  //## end CTCPid::~CTCPid%.body
}



//## Other Operations (implementation)
double CTCPid::Do (const double p_dact)
{
  //## begin CTCPid::Do%1086869809.body preserve=yes

	// deviation
	m_ddelta = m_dNom - p_dact;

	// P-control
	m_dP = m_dKp * m_ddelta;

	// Integrate
	m_dI = m_dI1 + (m_dKi * (m_ddelta + m_ddelta1));

	// D-control
	m_dD = m_dTv * (m_ddelta - m_ddelta1);

	// control signal
	m_dk = (m_dP + m_dI + m_dD);// [stellsignal 0..1] // ajust kp to tune this

	// upper limit control signal
	if (m_dk > m_dULimit)
	{ 
		// Wenn der Stellwert m_dk am oberen Anschlag ist wird er auf den Anschlagwert gesetzt.
		// In dieser Situation erfolgt ein Aufsummieren des Integralanteils nur dann, wenn der
		// Istwert über dem Sollwert liegt.
		m_dk = m_dULimit;
		if (m_ddelta < 0)
		{ 
			// yi(k-1) = y(k)
			m_dI1 = m_dI;
		}

	} 
	else if (m_dk < m_dLLimit) // lower limit control signal
	{ 
		// Wenn der Stellwert m_dk am unteren Anschlag ist wird er auf den Anschlagwert gesetzt.
		// In dieser Situation erfolgt ein Aufsummieren des Integralanteils nur dann, wenn der
		// Istwert unter dem Sollwert liegt.
		m_dk = m_dLLimit;
		if (m_ddelta > 0)
		{	
			// yi(k-1) = y(k)
			m_dI1 = m_dI;
		}
	}
	else
	{
		// yi(k-1) = y(k)
		m_dI1 = m_dI;
	}

	// delta(k-1) = delta(k)
	m_ddelta1 = m_ddelta;

	return m_dk;

  //## end CTCPid::Do%1086869809.body
}

void CTCPid::Reset ()
{
  //## begin CTCPid::Reset%1086869810.body preserve=yes
	m_bInitDone = false;
	m_ddelta = 0.0;
	m_ddelta1 = m_ddelta;
    m_dI = 0;
    m_dP = 0;
    m_dD = 0;
    m_dI1 = 0;
  //## end CTCPid::Reset%1086869810.body
}

void CTCPid::Set (const double p_dNomValue, const double p_dKp, const double p_dTi, const double p_dTv, const double p_dLLimit, const double p_dULimit, const double p_dTs)
{
  //## begin CTCPid::Set%1086869811.body preserve=yes

	if (p_dTi != 0 && p_dTs != 0)
	{
		// P- Anteil
		m_dKp = p_dKp;
		// I-Anteil
		m_dKi = (m_dKp * p_dTs) / (2 * p_dTi);
		// D-Anteil
		m_dTv = (m_dKp * p_dTv) / p_dTs;

		m_dLLimit = p_dLLimit;
		m_dULimit = p_dULimit;
		m_dTs = p_dTs;

		m_dNom = p_dNomValue;
	}

  //## end CTCPid::Set%1086869811.body
}

//## Get and Set Operations for Class Attributes (implementation)

double CTCPid::GetdLLimit ()
{
  //## begin CTCPid::GetdLLimit%40C87BD70106.get preserve=no
  return m_dLLimit;
  //## end CTCPid::GetdLLimit%40C87BD70106.get
}

double CTCPid::GetdULimit ()
{
  //## begin CTCPid::GetdULimit%40C87BD70107.get preserve=no
  return m_dULimit;
  //## end CTCPid::GetdULimit%40C87BD70107.get
}

double CTCPid::GetdTs ()
{
  //## begin CTCPid::GetdTs%40C87BD70116.get preserve=no
  return m_dTs;
  //## end CTCPid::GetdTs%40C87BD70116.get
}

double CTCPid::GetdNom ()
{
  //## begin CTCPid::GetdNom%40CE9C2D0262.get preserve=no
  return m_dNom;
  //## end CTCPid::GetdNom%40CE9C2D0262.get
}

// Additional Declarations
  //## begin CTCPid%40C879EC023F.declarations preserve=yes
  //## end CTCPid%40C879EC023F.declarations

//## begin module%40C804650328.epilog preserve=yes
//## end module%40C804650328.epilog
