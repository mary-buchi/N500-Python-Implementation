//## begin module%48898FC80099.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%48898FC80099.cm

//## begin module%48898FC80099.cp preserve=no
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
//## end module%48898FC80099.cp

//## Module: EBTCpid2%48898FC80099; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCpid2.cpp

// stdafx
#include "stdafx.h"
//## begin module%48898FC80099.additionalIncludes preserve=no
//## end module%48898FC80099.additionalIncludes

//## begin module%48898FC80099.includes preserve=yes
//## end module%48898FC80099.includes

// EBTCpid2
#include "EBTCpid2.h"
// EBTCident
#include "EBTCident.h"
//## begin module%48898FC80099.declarations preserve=no
//## end module%48898FC80099.declarations

//## begin module%48898FC80099.additionalDeclarations preserve=yes
//## end module%48898FC80099.additionalDeclarations


// Class CTCPid2 





























CTCPid2::CTCPid2()
  //## begin CTCPid2::CTCPid2%.hasinit preserve=no
      : m_ddelta(0), m_dI(0), m_dP(0), m_dD(0), m_dI1(0), m_ddelta1(0), m_dKp(0), m_dKi(0), m_dTv(0), m_dLLimit(0), m_dULimit(0), m_dTs(0), m_dk(0), m_dNom(0), m_bInitDone(false), m_iDeltaBufSize(10), m_iDeltaBufPos(0), m_dDeltaBuf(NULL), m_dDeltaSum(0), m_dEstimatedI(0), m_dInnerPBand(0.3), m_dOuterPBand(1.3), m_dPBandWidth(m_dOuterPBand-m_dInnerPBand), m_dWeight(0), m_dDeltaAvg(0), m_bFirst(true), m_eCurrentPowerState(ePowerStateLow)
  //## end CTCPid2::CTCPid2%.hasinit
  //## begin CTCPid2::CTCPid2%.initialization preserve=yes
  //## end CTCPid2::CTCPid2%.initialization
{
  //## begin CTCPid2::CTCPid2%.body preserve=yes
	m_dDeltaBuf = new double [m_iDeltaBufSize];
	memset(m_dDeltaBuf, 0, m_iDeltaBufSize * sizeof(double));
  //## end CTCPid2::CTCPid2%.body
}


CTCPid2::~CTCPid2()
{
  //## begin CTCPid2::~CTCPid2%.body preserve=yes
	delete [] m_dDeltaBuf;
	m_dDeltaBuf=NULL;
  //## end CTCPid2::~CTCPid2%.body
}



//## Other Operations (implementation)
double CTCPid2::Do (const double p_dact)
{
  //## begin CTCPid2::Do%1216975779.body preserve=yes
	// deviation

	m_ddelta = m_dNom - p_dact;

	if (m_bFirst)
	{
		m_ddelta1=m_ddelta;
		m_bFirst = false;
	}

	// P-control
	m_dP = m_dKp * m_ddelta;

	// D-control	
	m_dDeltaSum -= m_dDeltaBuf[m_iDeltaBufPos];
	m_dDeltaBuf[m_iDeltaBufPos] = m_ddelta - m_ddelta1;
	m_dDeltaSum += m_dDeltaBuf[m_iDeltaBufPos];
	m_iDeltaBufPos = (++m_iDeltaBufPos)%m_iDeltaBufSize;
	m_dDeltaAvg = m_dDeltaSum/m_iDeltaBufSize;
	m_dD = m_dTv * (m_dDeltaAvg);

	if ((m_eCurrentPowerState == ePowerStateLow) && (m_dDeltaAvg < -0.04))
	{
		m_eCurrentPowerState = ePowerStateRegular;
		m_dEstimatedI = EstimatedI(m_dNom,m_eCurrentPowerState,m_dKp);
		CO_TRACE(TC_ID, _T("Regular Power Supply"));
	}

	if ((m_eCurrentPowerState == ePowerStateRegular) && (m_dDeltaAvg < -0.09))
	{
		m_eCurrentPowerState = ePowerStateHigh;
		m_dEstimatedI = EstimatedI(m_dNom,m_eCurrentPowerState,m_dKp);
		CO_TRACE(TC_ID, _T("High Power Supply"));
	}

	// I-control
	m_dI = m_dI1 + m_dKi * (m_ddelta + m_ddelta1);
	// In the inner P-band use the actual I-control,
	// in the outer P-band use mix the actual and the estimated I
	// else only use the estimated I.
	m_dWeight = (fabs(m_ddelta)-m_dInnerPBand)/m_dPBandWidth;
	if (m_dWeight<0) m_dWeight =0;
	else if (m_dWeight>1) m_dWeight =1;
	m_dI = (1-m_dWeight) * m_dI + m_dWeight * m_dEstimatedI;

	// control signal (0..1), adjust kp to tune this
	m_dk = (m_dP + m_dI + m_dD);  

	// upper limit control signal
	if (m_dk > m_dULimit)
	{ 
		m_dk = m_dULimit;
	} 
	else if (m_dk < m_dLLimit) // lower limit control signal
	{ 
		m_dk = m_dLLimit;
	}

	m_dI1 = m_dI;

	// delta(k-1) = delta(k)
	m_ddelta1 = m_ddelta;
	
#ifdef DEBUG
	CString l_sMsg;
	l_sMsg.Format(_T("PID (Ttarget,Tact,I1,P,I,D,k): %.6f, %.6f, %.6f, %.6f, %.6f, %.6f, %.6f"), m_dNom, p_dact,m_dI1,m_dP,m_dI,m_dD,m_dk);
	CO_TRACE(TC_ID, (LPCTSTR)l_sMsg);
#endif

	return m_dk;

  //## end CTCPid2::Do%1216975779.body
}

void CTCPid2::Reset ()
{
  //## begin CTCPid2::Reset%1216975780.body preserve=yes
	m_bInitDone = false;
	m_ddelta = 0.0;
	m_ddelta1 = m_ddelta;
    m_dI = 0;
    m_dP = 0;
    m_dD = 0;
    m_dI1 = 0;
	memset(m_dDeltaBuf, 0, m_iDeltaBufSize * sizeof(double));
	m_bFirst = true;
	m_iDeltaBufPos=0;
	m_dDeltaSum=0;
	m_dEstimatedI = 0;
  //## end CTCPid2::Reset%1216975780.body
}

void CTCPid2::Set (const double p_dNomValue, const double p_dKp, const double p_dTi, const double p_dTv, const double p_dLLimit, const double p_dULimit, const double p_dTs)
{
  //## begin CTCPid2::Set%1216975781.body preserve=yes
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
		m_dEstimatedI = EstimatedI(p_dNomValue,m_eCurrentPowerState, m_dKp);
	}
  //## end CTCPid2::Set%1216975781.body
}

double CTCPid2::EstimatedI (double p_dNomTemp, ETCPowerState p_ePowerState, double p_dKp)
{
  //## begin CTCPid2::EstimatedI%1219123866.body preserve=yes
	double l_dEstimatedI=0;
	if (p_dNomTemp>35)
	{
		switch (p_ePowerState)
		{
		case ePowerStateLow:
			l_dEstimatedI = 0.0002020 * p_dNomTemp * p_dNomTemp - 0.01210 * p_dNomTemp + 0.1718;
			break;
		case ePowerStateRegular:
			l_dEstimatedI = 0.0000047 * p_dNomTemp * p_dNomTemp + 0.00223 * p_dNomTemp - 0.0868;
			break;
		case ePowerStateHigh:
			l_dEstimatedI = 0.0000020 * p_dNomTemp * p_dNomTemp + 0.00180 * p_dNomTemp - 0.0675;
			break;
		}
	}
	return l_dEstimatedI/p_dKp;
  //## end CTCPid2::EstimatedI%1219123866.body
}

//## Get and Set Operations for Class Attributes (implementation)

double CTCPid2::GetdLLimit ()
{
  //## begin CTCPid2::GetdLLimit%488991230384.get preserve=no
  return m_dLLimit;
  //## end CTCPid2::GetdLLimit%488991230384.get
}

double CTCPid2::GetdULimit ()
{
  //## begin CTCPid2::GetdULimit%48899123038C.get preserve=no
  return m_dULimit;
  //## end CTCPid2::GetdULimit%48899123038C.get
}

double CTCPid2::GetdTs ()
{
  //## begin CTCPid2::GetdTs%488991230393.get preserve=no
  return m_dTs;
  //## end CTCPid2::GetdTs%488991230393.get
}

double CTCPid2::GetdNom ()
{
  //## begin CTCPid2::GetdNom%4889912303A4.get preserve=no
  return m_dNom;
  //## end CTCPid2::GetdNom%4889912303A4.get
}

// Additional Declarations
  //## begin CTCPid2%4889905D0080.declarations preserve=yes
  //## end CTCPid2%4889905D0080.declarations

//## begin module%48898FC80099.epilog preserve=yes
//## end module%48898FC80099.epilog
