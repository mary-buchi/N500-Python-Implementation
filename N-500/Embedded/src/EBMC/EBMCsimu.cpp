//## begin module%3F97883D0003.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F97883D0003.cm

//## begin module%3F97883D0003.cp preserve=no
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
//## end module%3F97883D0003.cp

//## Module: EBMCsimu%3F97883D0003; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCsimu.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F97883D0003.additionalIncludes preserve=no
//## end module%3F97883D0003.additionalIncludes

//## begin module%3F97883D0003.includes preserve=yes
//## end module%3F97883D0003.includes

// EBPItype
#include "EBPItype.h"
// EBMCsimu
#include "EBMCsimu.h"
// EBHIdefi
#include "EBHIdefi.h"


//## begin module%3F97883D0003.declarations preserve=no
//## end module%3F97883D0003.declarations

//## begin module%3F97883D0003.additionalDeclarations preserve=yes
//## end module%3F97883D0003.additionalDeclarations


// Class CMCCtrlSimulation 

//## begin CMCCtrlSimulation::sFileName%3F978D1002B2.attr preserve=no  private: static CString {U} _T("R:\\Bin\\Data\\Stream.bin")
CString CMCCtrlSimulation::m_sFileName = _T("R:\\Bin\\Data\\Stream.bin");
//## end CMCCtrlSimulation::sFileName%3F978D1002B2.attr






CMCCtrlSimulation::CMCCtrlSimulation()
  //## begin CMCCtrlSimulation::CMCCtrlSimulation%.hasinit preserve=no
      : m_pbyDetectorChannel(NULL), m_pbyLaserChannel(NULL), m_iStreamLength(0), m_dwReadPosition(0)
  //## end CMCCtrlSimulation::CMCCtrlSimulation%.hasinit
  //## begin CMCCtrlSimulation::CMCCtrlSimulation%.initialization preserve=yes
  //## end CMCCtrlSimulation::CMCCtrlSimulation%.initialization
{
  //## begin CMCCtrlSimulation::CMCCtrlSimulation%.body preserve=yes
  //## end CMCCtrlSimulation::CMCCtrlSimulation%.body
}


CMCCtrlSimulation::~CMCCtrlSimulation()
{
  //## begin CMCCtrlSimulation::~CMCCtrlSimulation%.body preserve=yes
    delete [] m_pbyDetectorChannel;
    m_pbyDetectorChannel = NULL;
    delete [] m_pbyLaserChannel;
    m_pbyLaserChannel = NULL;
  //## end CMCCtrlSimulation::~CMCCtrlSimulation%.body
}



//## Other Operations (implementation)
void CMCCtrlSimulation::Initialize ()
{
  //## begin CMCCtrlSimulation::Initialize%1066894467.body preserve=yes
    delete [] m_pbyDetectorChannel;
    m_pbyDetectorChannel = NULL;
    delete [] m_pbyLaserChannel;
    m_pbyLaserChannel = NULL;

    CFile l_File;
    m_iStreamLength = 0;

#ifdef _WIN32_WCE
    m_sFileName = "\\Hard Disk\\NIRFlex\\Stream.bin";
#endif

    if (l_File.Open(m_sFileName, CFile::modeRead))
    {
        // size of streams
        INT l_iStreamLength = (int)l_File.GetLength();

        // read file into memory
        BYTE* l_pbyMemoryFile = new BYTE[l_iStreamLength];
        l_File.Read(l_pbyMemoryFile, l_iStreamLength);

        m_pbyDetectorChannel = new BYTE[l_iStreamLength/2];
        m_pbyLaserChannel    = new BYTE[l_iStreamLength/2];

        INT l_iMemReadCnt = 0;
        for (int l_iCnt=0; l_iCnt<l_iStreamLength/8; l_iCnt++)
        {
            memcpy(m_pbyLaserChannel+l_iCnt*4, l_pbyMemoryFile+l_iMemReadCnt, 4);
            l_iMemReadCnt += 4;
            memcpy(m_pbyDetectorChannel+l_iCnt*4, l_pbyMemoryFile+l_iMemReadCnt, 4);
            l_iMemReadCnt += 4;
        }
        delete [] l_pbyMemoryFile;
        l_File.Close();

        m_iStreamLength = l_iStreamLength/2;
    }

    m_dwReadPosition = 0;
  //## end CMCCtrlSimulation::Initialize%1066894467.body
}

void CMCCtrlSimulation::Start ()
{
  //## begin CMCCtrlSimulation::Start%1067518841.body preserve=yes
    m_dwReadPosition = 0;
  //## end CMCCtrlSimulation::Start%1067518841.body
}

CPIMeasurementChannelDataPackage* CMCCtrlSimulation::GetDataPackage ()
{
  //## begin CMCCtrlSimulation::GetDataPackage%1066894473.body preserve=yes
    DWORD l_dwDataSize = CHIMCParameter::GetdwMaxTransferDataSize();
    l_dwDataSize = min(l_dwDataSize, m_iStreamLength-m_dwReadPosition);
    if (l_dwDataSize == 0)
        return NULL;

    BYTE* l_pDetectorData = new BYTE[l_dwDataSize];
    BYTE* l_pLaserData = new BYTE[l_dwDataSize];
    memcpy(l_pDetectorData, m_pbyDetectorChannel+m_dwReadPosition, l_dwDataSize);
    memcpy(l_pLaserData, m_pbyLaserChannel+m_dwReadPosition, l_dwDataSize);
    m_dwReadPosition += l_dwDataSize;

    CPIMeasurementChannelDataPackage* l_pDataPackage = new CPIMeasurementChannelDataPackage(
        CHIMCParameter::GetdwCycleID(),
        l_dwDataSize,
        l_pLaserData,
        l_pDetectorData);


    return l_pDataPackage;
  //## end CMCCtrlSimulation::GetDataPackage%1066894473.body
}

// Additional Declarations
  //## begin CMCCtrlSimulation%3F97881D036E.declarations preserve=yes
  //## end CMCCtrlSimulation%3F97881D036E.declarations

//## begin module%3F97883D0003.epilog preserve=yes
//## end module%3F97883D0003.epilog
