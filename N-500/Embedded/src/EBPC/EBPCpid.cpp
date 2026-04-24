//## begin module%4033A00A0065.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%4033A00A0065.cm

//## begin module%4033A00A0065.cp preserve=no
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
//## end module%4033A00A0065.cp

//## Module: EBPCpid%4033A00A0065; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCpid.cpp

// stdafx
#include "stdafx.h"
//## begin module%4033A00A0065.additionalIncludes preserve=no
//## end module%4033A00A0065.additionalIncludes

//## begin module%4033A00A0065.includes preserve=yes
//## end module%4033A00A0065.includes

// EBPCpid
#include "EBPCpid.h"
//## begin module%4033A00A0065.declarations preserve=no
//## end module%4033A00A0065.declarations

//## begin module%4033A00A0065.additionalDeclarations preserve=yes
//## end module%4033A00A0065.additionalDeclarations


// Class CPCPid 


















CPCPid::CPCPid()
  //## begin CPCPid::CPCPid%.hasinit preserve=no
      : m_ddelta(0), m_dI(0), m_dP(0), m_dD(0), m_dI1(0), m_ddelta1(0), m_dKp(0), m_dKi(0), m_dTv(0), m_dLLimit(0), m_dULimit(0), m_dTs(0), m_dy(0), m_dDACGain(0), m_dDACOffset(0), m_dk(0)
  //## end CPCPid::CPCPid%.hasinit
  //## begin CPCPid::CPCPid%.initialization preserve=yes
  //## end CPCPid::CPCPid%.initialization
{
  //## begin CPCPid::CPCPid%.body preserve=yes
  //## end CPCPid::CPCPid%.body
}


CPCPid::~CPCPid()
{
  //## begin CPCPid::~CPCPid%.body preserve=yes
  //## end CPCPid::~CPCPid%.body
}



//## Other Operations (implementation)
double CPCPid::Do (const double p_dnom, const double p_dact)
{
  //## begin CPCPid::Do%1077125104.body preserve=yes

	// deviation
	m_ddelta = p_dnom - p_dact;

	// P-control
	m_dP = m_dKp * m_ddelta;

	// Integrate
	m_dI = m_dI1 + (m_dKi * (m_ddelta + m_ddelta1));

	// D-control
	m_dD = m_dTv * (m_ddelta - m_ddelta1);

	// control signal
	m_dy = (m_dP + m_dI + m_dD);// [V]

	// volt zu digits
	m_dk = m_dDACGain * m_dy + m_dDACOffset;

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
  //## end CPCPid::Do%1077125104.body
}

void CPCPid::Reset ()
{
  //## begin CPCPid::Reset%1077125105.body preserve=yes
	m_ddelta = 0;
    m_dI = 0;
    m_dP = 0;
    m_dD = 0;
    m_dI1 = 0;
    m_ddelta1 = 0;
  //## end CPCPid::Reset%1077125105.body
}

void CPCPid::Set (const double p_dKp, const double p_dTi, const double p_dTv, const double p_dLLimit, const double p_dULimit, const double p_dTs, const double p_dDACGain, const double p_dDACOffset)
{
  //## begin CPCPid::Set%1077174615.body preserve=yes

  if (p_dTi != 0 && p_dTs != 0)
  {
      // P- Anteil
      m_dKp = p_dKp;// * p_dDACGain;
      // I-Anteil
      m_dKi = (m_dKp * p_dTs) / (2 * p_dTi);
      // D-Anteil
      m_dTv = (m_dKp * p_dTv) / p_dTs;
   
      m_dLLimit = p_dLLimit;
      m_dULimit = p_dULimit;
      m_dTs = p_dTs;

      m_dDACOffset = p_dDACOffset;
	  m_dDACGain = p_dDACGain;
  }
  else
  {
    // EXCEPTION !!!
    // TODO
  }

  //## end CPCPid::Set%1077174615.body
}

void CPCPid::PresetI1 (const double p_dPresetValue)
{
  //## begin CPCPid::PresetI1%1077198848.body preserve=yes
	m_dI1 = p_dPresetValue;
  //## end CPCPid::PresetI1%1077198848.body
}

// Additional Declarations
  //## begin CPCPid%403398C701DC.declarations preserve=yes
  //## end CPCPid%403398C701DC.declarations

//## begin module%4033A00A0065.epilog preserve=yes
//## end module%4033A00A0065.epilog
