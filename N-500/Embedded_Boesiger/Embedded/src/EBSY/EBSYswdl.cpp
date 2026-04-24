//## begin module%3EE086FE0094.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE086FE0094.cm

//## begin module%3EE086FE0094.cp preserve=no
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
//## end module%3EE086FE0094.cp

//## Module: EBSYswdl%3EE086FE0094; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYswdl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE086FE0094.additionalIncludes preserve=no
//## end module%3EE086FE0094.additionalIncludes

//## begin module%3EE086FE0094.includes preserve=yes
#include "Iphlpapi.h"
//## end module%3EE086FE0094.includes

// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBSYswdl
#include "EBSYswdl.h"
// EBSYmhan
#include "EBSYmhan.h"
// EBSYshdn
#include "EBSYshdn.h"
// EBSYidnt
#include "EBSYidnt.h"
// EBSYcntd
#include "EBSYcntd.h"


//## begin module%3EE086FE0094.declarations preserve=no
//## end module%3EE086FE0094.declarations

//## begin module%3EE086FE0094.additionalDeclarations preserve=yes
//## end module%3EE086FE0094.additionalDeclarations


// Class CSYStateConstitutionDownloadSoftwareComponents 


//## begin CSYStateConstitutionDownloadSoftwareComponents::pInstance%3EE07FAE01B4.role preserve=no  public: static CSYStateConstitutionDownloadSoftwareComponents {1..1 -> RFHN}
CSYStateConstitutionDownloadSoftwareComponents *CSYStateConstitutionDownloadSoftwareComponents::m_pInstance = NULL;
//## end CSYStateConstitutionDownloadSoftwareComponents::pInstance%3EE07FAE01B4.role




CSYStateConstitutionDownloadSoftwareComponents::CSYStateConstitutionDownloadSoftwareComponents()
  //## begin CSYStateConstitutionDownloadSoftwareComponents::CSYStateConstitutionDownloadSoftwareComponents%.hasinit preserve=no
      : m_iWinCEPackageCounter(0), m_pSoftwareComponentList(NULL), m_pClientSyncObj(NULL)
  //## end CSYStateConstitutionDownloadSoftwareComponents::CSYStateConstitutionDownloadSoftwareComponents%.hasinit
  //## begin CSYStateConstitutionDownloadSoftwareComponents::CSYStateConstitutionDownloadSoftwareComponents%.initialization preserve=yes
  //## end CSYStateConstitutionDownloadSoftwareComponents::CSYStateConstitutionDownloadSoftwareComponents%.initialization
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::CSYStateConstitutionDownloadSoftwareComponents%.body preserve=yes
  //## end CSYStateConstitutionDownloadSoftwareComponents::CSYStateConstitutionDownloadSoftwareComponents%.body
}


CSYStateConstitutionDownloadSoftwareComponents::~CSYStateConstitutionDownloadSoftwareComponents()
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::~CSYStateConstitutionDownloadSoftwareComponents%.body preserve=yes
  //## end CSYStateConstitutionDownloadSoftwareComponents::~CSYStateConstitutionDownloadSoftwareComponents%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionDownloadSoftwareComponents::Create ()
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::Create%1054888632.body preserve=yes

	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionDownloadSoftwareComponents();

  //## end CSYStateConstitutionDownloadSoftwareComponents::Create%1054888632.body
}

void CSYStateConstitutionDownloadSoftwareComponents::Delete ()
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::Delete%1054888634.body preserve=yes

    if (m_pInstance)
    {
        delete m_pInstance;
    }

    m_pInstance = NULL;

  //## end CSYStateConstitutionDownloadSoftwareComponents::Delete%1054888634.body
}

CSYStateConstitutionDownloadSoftwareComponents* CSYStateConstitutionDownloadSoftwareComponents::GetInstance ()
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::GetInstance%1054888633.body preserve=yes

    ASSERT(m_pInstance != NULL);
    return m_pInstance;

  //## end CSYStateConstitutionDownloadSoftwareComponents::GetInstance%1054888633.body
}

EPIDeviceState CSYStateConstitutionDownloadSoftwareComponents::GetDeviceState ()
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::GetDeviceState%1056436749.body preserve=yes
    return eRunning;
  //## end CSYStateConstitutionDownloadSoftwareComponents::GetDeviceState%1056436749.body
}

void CSYStateConstitutionDownloadSoftwareComponents::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::Do%1055753505.body preserve=yes

    try
    {
        CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*>& pComponentList = 
            m_pSoftwareComponentList->GetComponents();

        POSITION pos = pComponentList.GetHeadPosition();

        // Create a file to the newdll location to indicate, that new files are to copy next time

        CString sFileLocation         = sMainDLLLocation + _T("\\");
	      bool    bReboot               = false;
        bool    bFirstRebootFile      = false;
        bool    bReAssembleWinCEImage = false;
        const int ciNumberOfWinCEPackage = 10;
        while (pos)
        {
            
            CPIPersistentSoftwareComponent* pComponent = pComponentList.GetNext(pos);
            byte* pImage = pComponent->GetpImage();
            int lFileLength = pComponent->GetiImageSize();
   
            if (pComponent->GetbIsFPGASource())
            {
#ifdef _WIN32_WCE
              // FPGA Source Update File
              bReboot = true;
              sFileLocation = sFPGASrcLocation;
              // write file to run directory
              CString sFilePath = sFPGASrcLocation + pComponent->GetsName();
              CFile cFileRun(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

              // Write file to disk
              cFileRun.Write(pImage, lFileLength);
              cFileRun.Close();

              // run FPGA download
              SHELLEXECUTEINFO oSi;
              memset(&oSi, 0, sizeof(oSi));
              oSi.cbSize        = sizeof(oSi);
              oSi.fMask         = SEE_MASK_NOCLOSEPROCESS;
              oSi.hwnd          = 0;
              oSi.lpFile        = sFPGADlToolLocation;
              oSi.lpParameters  = sFilePath;

              // Start FPGA Download Tool
              if (!ShellExecuteEx(&oSi))
              {
                throw new XCOExceptionCleanupInitialize(SY_ID, IDE_FPGA_EXECUTION_ERROR, __FILE__, __LINE__);;
              }
                  
              // wait until process is terminated
              if (::WaitForSingleObject(oSi.hProcess,INFINITE) == WAIT_TIMEOUT)
              {
                // timeout exception - process could not 
                throw new XCOExceptionCleanupInitialize(SY_ID, IDE_FPGA_DOWNLOAD_TIMEOUT, __FILE__, __LINE__);;
              }
#endif
            }
            else if (pComponent->GetbIsWinCEImage())
            {
                try
                {
                  CString sWinCEFilePath;

                  CreateDirectory(sNewDLLLocation, NULL);

                  sWinCEFilePath = sWinCEImageLocation + _T("\\") + pComponent->GetsName();
                  CFile cFileRun(sWinCEFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

                  // Write file to disk
                  cFileRun.Write(pImage, lFileLength);
                  cFileRun.Close();

                  CString sTmp = pComponent->GetsName();
                  int iIndex = sTmp.ReverseFind('.');
                  int iLenght = sTmp.GetLength() - 1;
                  m_iWinCEPackageCounter = _wtoi(sTmp.Right(iLenght - iIndex));

                  if (m_iWinCEPackageCounter == (ciNumberOfWinCEPackage - 1))
                  {
                    // reassemble WinCE Image package -> WinCE Image nk.bin
                    m_iWinCEPackageCounter = 0;
                  
                    // get WinCE Image File name -> from WinCE package file
                    sTmp = pComponent->GetsName();
                    int iIndex = sTmp.ReverseFind('.');
                    CString sWinCEImageName = sTmp.Left(iIndex);
                    sWinCEFilePath = sWinCEImageLocation + _T("\\") + sWinCEImageName;                  
                  
                    // create new WinCE Image File
                    CFile cWinCEImage(sWinCEFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

                    for (int ii = 0; ii < ciNumberOfWinCEPackage; ii++)
                    {                    
                      // reassemble all package file to one WinCE Image file
                      CString sWinCEPackageFilePath;
                      sWinCEPackageFilePath.Format((sWinCEFilePath + _T(".%d")), ii);
                    
                      CFile cWinCEPackageFile(sWinCEPackageFilePath, CFile::modeRead|CFile::typeBinary);
                      int iLength = (int)cWinCEPackageFile.GetLength();
                      BYTE* pData = new BYTE[iLength];
                      cWinCEPackageFile.Read(pData, iLength);
                    
                      cWinCEImage.Write(pData, iLength);
                      cWinCEPackageFile.Close();

                      // now delete WinCE image package file
                      CO_TRACE1(SY_ID, _T("Delete WinCE Image Package File %s"), sWinCEPackageFilePath);
                      DeleteFile(sWinCEPackageFilePath);
                 
                      if (pData)
                      {
                        delete [] pData;
                        pData = NULL;
                      }
                    }
                    bReboot = true;

                    CO_TRACE1(SY_ID, _T("WinCE Image File %s download comleted."), cWinCEImage.GetFileName());                    
                    cWinCEImage.Close();

                    RemoveDirectory(sNewDLLLocation);
                  }
                }
                catch(CFileException* p_pException)
                {
                  p_pException->Delete();
                  throw new XCOExceptionCleanupInitialize(SY_ID, IDE_WINCE_DOWNLOAD_ERROR, __FILE__, __LINE__);
                }
            }
            else
            {
              
              try
              {
                // NIRWare Embedded File
                if (pComponent->GetbRequiresReboot())
                {
                  bReboot = true;
                  CString sDLLLocation = sNewDLLLocation;

                  if (!bFirstRebootFile)
                  {
                      CreateDirectory(sNewDLLLocation, NULL);

                      CString sFilePath = sDLLLocation + _T("\\") + sMarkerFile;
                      CFile cFile(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);
                      cFile.Close();

                      bFirstRebootFile = true;
                  }

                  // Assemble filename and open it for writing
                  CString sFilePath = sDLLLocation + _T("\\") + pComponent->GetsName();
                  MakeWritable(sFilePath);
				  CFile cFile(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

				  // remove read only flag in the main location as well
                  CString sMainFilePath = sMainDLLLocation + _T("\\") + pComponent->GetsName();
                  MakeWritable(sMainFilePath);

                  // Write file to disk
                  cFile.Write(pImage, lFileLength);
                  cFile.Close();
                }
                else
                {

                  // Assemble filename and open it for writing
                  CString sFilePath = sMainDLLLocation + pComponent->GetsName();
                  MakeWritable(sFilePath);
                  CFile cFileFlash(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

                  // Write file to flash
                  cFileFlash.Write(pImage, lFileLength);
                  cFileFlash.Close();

  #ifdef _WIN32_WCE
                  // write file to run directory
                  sFilePath = sRunDLLLocation + pComponent->GetsName();
                  CFile cFileRun(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);
                  // Write file to disk
                  cFileRun.Write(pImage, lFileLength);
                  cFileRun.Close();
  #endif
                }

                bReboot = bReboot || pComponent->GetbRequiresReboot();
              }
              catch(CFileException* p_pException)
              {
                p_pException->Delete();
                throw new XCOExceptionCleanupInitialize(SY_ID, IDE_EB_FILE_DOWNLOAD_ERROR, __FILE__, __LINE__);
              }
            }
        } // while

#ifdef _WIN32_WCE
        if (bReboot)
        {
            // attach exception to current command, so that the PC notices that we are going to reboot
            m_pClientSyncObj->AttachException(new XCOExceptionCleanupInitialize(SY_ID,IDE_SYSTEM_REBOOT,__FILE__,__LINE__));

            // give PC driver some time to pass the exception to the PC
            Sleep(4000);

            CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	        p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
        }
        else
#endif
          {
			      p_pContext->ChangeState(CSYStateConstitutionConnected::GetInstance());
          }
    }
    catch (CFileException* p_pException)
    {
        p_pException->Delete();
        throw new XCOExceptionCleanupInitialize(SY_ID, IDE_UPDATE_COMPONENT, __FILE__, __LINE__);
    }

  //## end CSYStateConstitutionDownloadSoftwareComponents::Do%1055753505.body
}

void CSYStateConstitutionDownloadSoftwareComponents::MakeWritable (const CString& p_sFile)
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::MakeWritable%1083574991.body preserve=yes
	//example for CFile::GetStatus
	CFileStatus l_FileStatus;
	if ( CFile::GetStatus( (LPCTSTR) p_sFile, l_FileStatus ) )
	{
		// file exists
		// remove readOnly attribute
		l_FileStatus.m_attribute = 0;
		CFile::SetStatus( (LPCTSTR) p_sFile, l_FileStatus );
	}
  //## end CSYStateConstitutionDownloadSoftwareComponents::MakeWritable%1083574991.body
}

//## Get and Set Operations for Associations (implementation)

void CSYStateConstitutionDownloadSoftwareComponents::SetpSoftwareComponentList (CPIPersistentSoftwareComponentList * value)
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::SetpSoftwareComponentList%409802820046.set preserve=no
  m_pSoftwareComponentList = value;
  //## end CSYStateConstitutionDownloadSoftwareComponents::SetpSoftwareComponentList%409802820046.set
}

void CSYStateConstitutionDownloadSoftwareComponents::SetpClientSyncObj (CCOSyncObject * value)
{
  //## begin CSYStateConstitutionDownloadSoftwareComponents::SetpClientSyncObj%4098E06802FA.set preserve=no
  m_pClientSyncObj = value;
  //## end CSYStateConstitutionDownloadSoftwareComponents::SetpClientSyncObj%4098E06802FA.set
}

// Additional Declarations
  //## begin CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.declarations preserve=yes
  //## end CSYStateConstitutionDownloadSoftwareComponents%3EE07FAE01AD.declarations

// Class CSYStateConstitutionDownloadStarted 





//## begin CSYStateConstitutionDownloadStarted::pInstance%47833E6200A3.role preserve=no  public: static CSYStateConstitutionDownloadStarted {1..1 -> 1..1RFHN}
CSYStateConstitutionDownloadStarted *CSYStateConstitutionDownloadStarted::m_pInstance = NULL;
//## end CSYStateConstitutionDownloadStarted::pInstance%47833E6200A3.role


CSYStateConstitutionDownloadStarted::CSYStateConstitutionDownloadStarted()
  //## begin CSYStateConstitutionDownloadStarted::CSYStateConstitutionDownloadStarted%.hasinit preserve=no
      : m_bReboot(false), m_iCEPackageCnt(0), m_bFPGA(false)
  //## end CSYStateConstitutionDownloadStarted::CSYStateConstitutionDownloadStarted%.hasinit
  //## begin CSYStateConstitutionDownloadStarted::CSYStateConstitutionDownloadStarted%.initialization preserve=yes
  //## end CSYStateConstitutionDownloadStarted::CSYStateConstitutionDownloadStarted%.initialization
{
  //## begin CSYStateConstitutionDownloadStarted::CSYStateConstitutionDownloadStarted%.body preserve=yes
  //## end CSYStateConstitutionDownloadStarted::CSYStateConstitutionDownloadStarted%.body
}


CSYStateConstitutionDownloadStarted::~CSYStateConstitutionDownloadStarted()
{
  //## begin CSYStateConstitutionDownloadStarted::~CSYStateConstitutionDownloadStarted%.body preserve=yes
  //## end CSYStateConstitutionDownloadStarted::~CSYStateConstitutionDownloadStarted%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionDownloadStarted::Create ()
{
  //## begin CSYStateConstitutionDownloadStarted::Create%1199783730.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionDownloadStarted();
  //## end CSYStateConstitutionDownloadStarted::Create%1199783730.body
}

void CSYStateConstitutionDownloadStarted::Delete ()
{
  //## begin CSYStateConstitutionDownloadStarted::Delete%1199783731.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CSYStateConstitutionDownloadStarted::Delete%1199783731.body
}

CSYStateConstitutionDownloadStarted* CSYStateConstitutionDownloadStarted::GetInstance ()
{
  //## begin CSYStateConstitutionDownloadStarted::GetInstance%1199783732.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSYStateConstitutionDownloadStarted::GetInstance%1199783732.body
}

void CSYStateConstitutionDownloadStarted::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionDownloadStarted::Enter%1200053480.body preserve=yes
    m_bReboot = false;
	m_bFPGA = false;
    m_iCEPackageCnt = 0;

	// create temporary download directories
	::CreateDirectory(sTempDLLLocation + _T("\\"), NULL);
	::CreateDirectory(sTempDLLLocation + _T("\\CE\\"), NULL);
	::CreateDirectory(sTempDLLLocation + _T("\\Reboot\\"), NULL);
	::CreateDirectory(sTempDLLLocation + _T("\\NoReboot\\"), NULL);
	::CreateDirectory(sNewDLLLocation, NULL);
  //## end CSYStateConstitutionDownloadStarted::Enter%1200053480.body
}

void CSYStateConstitutionDownloadStarted::DownloadSoftwareComponent (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponent* p_pComponent)
{
  //## begin CSYStateConstitutionDownloadStarted::DownloadSoftwareComponent%1199783733.body preserve=yes
#ifdef _WIN32_WCE
    try
    {
        // Create a file to the newdll location to indicate, that new files are to copy next time
        CString sFileLocation         = sMainDLLLocation + _T("\\");
        bool    bReAssembleWinCEImage = false;
        const int ciNumberOfWinCEPackage = 10;

        byte* pImage = p_pComponent->GetpImage();
        int lFileLength = p_pComponent->GetiImageSize();

        if (p_pComponent->GetbIsFPGASource())
        {
            // FPGA Source Update File
            m_bReboot = true;
			m_bFPGA = true;
			m_sFPGAImageName = p_pComponent->GetsName();
            // write file to run directory
            CString sFilePath = sFPGASrcLocation + p_pComponent->GetsName();
            CFile cFileRun(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

            // Write file to disk
            cFileRun.Write(pImage, lFileLength);
            cFileRun.Close();
        }
        else if (p_pComponent->GetbIsWinCEImage())
        {
            m_bReboot = true;
            CString sWinCELocation = sTempDLLLocation + _T("\\CE");

            sWinCELocation = sWinCELocation + _T("\\") + p_pComponent->GetsName();
            CFile cFileRun(sWinCELocation, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

            // Write file to disk
            cFileRun.Write(pImage, lFileLength);
            cFileRun.Close();

            m_iCEPackageCnt++;
        }
        else
        {
            // NIRWare Embedded File
            CString sDLLLocation = sTempDLLLocation;
            if (p_pComponent->GetbRequiresReboot())
            {
				sDLLLocation += _T("\\Reboot");
				if (!m_bReboot)
				{
					// create FTC.dmy file in new sll location, required by startup.cmd to recognize updated core dll's
					CString sFilePath = sDLLLocation + _T("\\") + sMarkerFile;
					MakeWritable(sFilePath);
					CFile cFile(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);
					cFile.Close();
				}
                m_bReboot = true;
			}
			else
			{
				sDLLLocation += _T("\\NoReboot");
			}

            // Assemble filename and open it for writing
            CString sFilePath = sDLLLocation + _T("\\") + p_pComponent->GetsName();
            MakeWritable(sFilePath);
            CFile cFile(sFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

            // Write file to disk
            cFile.Write(pImage, lFileLength);
            cFile.Close();
        }
    }
    catch (CFileException* p_pException)
    {
        p_pException->Delete();
        throw new XCOExceptionCleanupInitialize(SY_ID, IDE_UPDATE_COMPONENT, __FILE__, __LINE__);
    }
#endif
  //## end CSYStateConstitutionDownloadStarted::DownloadSoftwareComponent%1199783733.body
}

void CSYStateConstitutionDownloadStarted::EndDownload (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateConstitutionDownloadStarted::EndDownload%1200222479.body preserve=yes
	try
	{
		CopyFolder(sTempDLLLocation + _T("\\Reboot"), sNewDLLLocation);
		CopyFolder(sTempDLLLocation + _T("\\NoReboot"), sRunDLLLocation);
		CopyFolder(sTempDLLLocation + _T("\\NoReboot"), sMainDLLLocation);

		if (m_iCEPackageCnt > 0)
		{
            // create new WinCE Image File
			CString sWinCEFilePath = sTempDLLLocation + _T("\\CE\\NK.bin");
            CFile cWinCEImage(sWinCEFilePath, CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);

            for (int l_iCnt = 0; l_iCnt < m_iCEPackageCnt; l_iCnt++)
            {                    
                // reassemble all package file to one WinCE Image file
                CString sWinCEPackageFilePath;
                sWinCEPackageFilePath.Format((sTempDLLLocation + _T("\\CE\\NK.bin.%d")), l_iCnt);

                CFile cWinCEPackageFile(sWinCEPackageFilePath, CFile::modeRead|CFile::typeBinary);
                int iLength = (int)cWinCEPackageFile.GetLength();
                BYTE* pData = new BYTE[iLength];
                cWinCEPackageFile.Read(pData, iLength);

                cWinCEImage.Write(pData, iLength);
                cWinCEPackageFile.Close();

                delete [] pData;
                pData = NULL;
            }

            cWinCEImage.Close();
			CString sCEImageDestination = sWinCEImageLocation + _T("\\NK.bin");
            MakeWritable(sCEImageDestination);
			;;CopyFile(sWinCEFilePath, sCEImageDestination, false);

            // save IP config
            SaveIPConfig();
		}

		if (m_bFPGA)
		{
#ifdef _WIN32_WCE
			CString sFPGAFilePath = sFPGASrcLocation + m_sFPGAImageName;

            // run FPGA download
            SHELLEXECUTEINFO oSi;
            memset(&oSi, 0, sizeof(oSi));
            oSi.cbSize        = sizeof(oSi);
            oSi.fMask         = SEE_MASK_NOCLOSEPROCESS;
            oSi.hwnd          = 0;
            oSi.lpFile        = sFPGADlToolLocation;
            oSi.lpParameters  = sFPGAFilePath;

            // Start FPGA Download Tool
            if (!ShellExecuteEx(&oSi))
            {
                throw new XCOExceptionCleanupInitialize(SY_ID, IDE_FPGA_EXECUTION_ERROR, __FILE__, __LINE__);;
            }

            // wait until process is terminated
            if (::WaitForSingleObject(oSi.hProcess,INFINITE) == WAIT_TIMEOUT)
            {
                // timeout exception - process could not 
                throw new XCOExceptionCleanupInitialize(SY_ID, IDE_FPGA_DOWNLOAD_TIMEOUT, __FILE__, __LINE__);;
            }
#endif
		}

		CleanupTempFolder(sTempDLLLocation + _T("\\CE"));
		CleanupTempFolder(sTempDLLLocation + _T("\\Reboot"));
		CleanupTempFolder(sTempDLLLocation + _T("\\NoReboot"));

        if (m_bReboot)
        {
            // attach exception to current command, so that the PC notices that we are going to reboot
            p_pClientSyncObj->AttachException(new XCOExceptionCleanupInitialize(SY_ID,IDE_SYSTEM_REBOOT,__FILE__,__LINE__));

            // give PC driver some time to pass the exception to the PC
            Sleep(4000);

            CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
            p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
        }
        else
        {
            p_pContext->ChangeState(CSYStateConstitutionConnected::GetInstance());
        }
	}
    catch (CFileException* p_pException)
    {
        p_pException->Delete();
        throw new XCOExceptionCleanupInitialize(SY_ID, IDE_UPDATE_COMPONENT, __FILE__, __LINE__);
    }
  //## end CSYStateConstitutionDownloadStarted::EndDownload%1200222479.body
}

bool CSYStateConstitutionDownloadStarted::SaveIPConfig ()
{
  //## begin CSYStateConstitutionDownloadStarted::SaveIPConfig%1200320793.body preserve=yes
    bool l_bDHCPEnabled;
    CString l_sAddress;
    CString l_sSubnetMask;
    DetermineIPConfig(l_bDHCPEnabled, l_sAddress, l_sSubnetMask);

    CString l_sFileName = sWinCEImageLocation + _T("\\IPconfig.txt");

    try
    {
        CFile l_File;
        if (l_File.Open((LPCTSTR)l_sFileName, CFile::modeCreate | CFile::modeWrite))
        {
            CString l_sLine;
            l_sLine.Format(_T("DHCPenabled=%d;IPAddress=%s;SubnetMask=%s;\r\n"), l_bDHCPEnabled, (LPCTSTR)l_sAddress, (LPCTSTR)l_sSubnetMask);
            l_File.Write((const void*)(LPCTSTR)l_sLine, l_sLine.GetLength()*2);
            l_File.Close();
            return true;
        }

        return false;
    }
    catch(CFileException *l_pException)
    {
        l_pException->Delete();
        return false;
    }
  //## end CSYStateConstitutionDownloadStarted::SaveIPConfig%1200320793.body
}

void CSYStateConstitutionDownloadStarted::DetermineIPConfig (bool& p_bDHCPEnabled, CString& p_sAddress, CString& p_sSubnetMask)
{
  //## begin CSYStateConstitutionDownloadStarted::DetermineIPConfig%1200320794.body preserve=yes
    p_bDHCPEnabled = false;
    p_sAddress = _T("????");
    p_sSubnetMask = _T("????");

    BYTE* l_pAdapterAddressesBuffer = NULL;
    ULONG l_ulBufferSize = 0;
    PIP_ADAPTER_ADDRESSES l_pAdapterAddresses = NULL;

    ::GetAdaptersAddresses(AF_INET, 0, NULL, l_pAdapterAddresses, &l_ulBufferSize);
    l_pAdapterAddressesBuffer = new BYTE[l_ulBufferSize];
    l_pAdapterAddresses = (PIP_ADAPTER_ADDRESSES)l_pAdapterAddressesBuffer;
    if (GetAdaptersAddresses(AF_INET, 0, NULL, l_pAdapterAddresses, &l_ulBufferSize) != ERROR_SUCCESS)
    {
        delete [] l_pAdapterAddressesBuffer;
        return;
    }

	PIP_ADAPTER_ADDRESSES l_pAdapterAddr = NULL;
	PIP_ADAPTER_ADDRESSES l_pLocalPtr = l_pAdapterAddresses;
	CString l_sFriendlyName = _T("Local Area Connection");
	do
	{
		if (l_sFriendlyName == l_pLocalPtr->FriendlyName)
		{
			l_pAdapterAddr = l_pLocalPtr;
			break;
		}
		l_pLocalPtr = l_pLocalPtr->Next;
	} while (l_pLocalPtr != NULL);

	if (l_pAdapterAddr == NULL)
		l_pAdapterAddr = l_pAdapterAddresses;

	if (l_pAdapterAddr == NULL || l_pAdapterAddr->FirstUnicastAddress == NULL)
    {
        delete [] l_pAdapterAddressesBuffer;
        return;
    }

    DWORD l_dwAdapterIndex = l_pAdapterAddr->IfIndex;
	sockaddr_in* l_pAddress = (sockaddr_in*)l_pAdapterAddr->FirstUnicastAddress->Address.lpSockaddr;
    p_sAddress = inet_ntoa(l_pAddress->sin_addr);
    ULONG l_ulAddress = l_pAddress->sin_addr.S_un.S_addr;
    delete [] l_pAdapterAddressesBuffer;

    BYTE* l_pAddressTableBuffer = NULL;
    PMIB_IPADDRTABLE l_pAddressTable = NULL;
    ULONG l_ulAddressTableSize = 0;
    GetIpAddrTable(l_pAddressTable,&l_ulAddressTableSize,false);
    l_pAddressTableBuffer = new BYTE[l_ulAddressTableSize];
    l_pAddressTable = (PMIB_IPADDRTABLE)l_pAddressTableBuffer;
    if (GetIpAddrTable(l_pAddressTable,&l_ulAddressTableSize,false) != ERROR_SUCCESS)
    {
        delete [] l_pAddressTableBuffer;
        return;
    }

    // find matching entry
    DWORD l_dwMask = 0;
    for(DWORD l_dwCnt=0; l_dwCnt<l_pAddressTable->dwNumEntries; l_dwCnt++)
    {
        if (l_ulAddress == l_pAddressTable->table[l_dwCnt].dwAddr)
        {
            l_dwMask = l_pAddressTable->table[l_dwCnt].dwMask;
            in_addr l_Mask;
            l_Mask.S_un.S_addr = l_pAddressTable->table[l_dwCnt].dwMask;
            p_sSubnetMask = inet_ntoa(l_Mask);
            break;
        }
    }
    delete [] l_pAddressTableBuffer;

    BYTE* l_pAdapterInfoBuffer = NULL;
    PIP_ADAPTER_INFO l_pAdapterInfo = NULL;
    ULONG l_ulAdapterInfoSize = 0;
    GetAdaptersInfo(l_pAdapterInfo, &l_ulAdapterInfoSize);
    l_pAdapterInfoBuffer = new BYTE[l_ulAdapterInfoSize];
    l_pAdapterInfo = (PIP_ADAPTER_INFO)l_pAdapterInfoBuffer;
    if (GetAdaptersInfo(l_pAdapterInfo, &l_ulAdapterInfoSize) != ERROR_SUCCESS)
    {
        delete [] l_pAdapterInfoBuffer;
        return;
    }

    PIP_ADAPTER_INFO l_pLocalAdapterInfo = l_pAdapterInfo;
    PIP_ADAPTER_INFO l_pAdpInfo = NULL;
    while(l_pLocalAdapterInfo)
    {
        if (l_pLocalAdapterInfo->Index == l_dwAdapterIndex)
        {
            l_pAdpInfo = l_pLocalAdapterInfo;
            l_pLocalAdapterInfo = NULL;
        }
        else
        {
            l_pLocalAdapterInfo = l_pLocalAdapterInfo->Next;
        }
    }

    if (l_pAdpInfo)
    {
        p_bDHCPEnabled = l_pAdpInfo->DhcpEnabled != 0;
    }
    delete [] l_pAdapterInfoBuffer;
  //## end CSYStateConstitutionDownloadStarted::DetermineIPConfig%1200320794.body
}

// Additional Declarations
  //## begin CSYStateConstitutionDownloadStarted%47833E1F0237.declarations preserve=yes
  //## end CSYStateConstitutionDownloadStarted%47833E1F0237.declarations

// Class CSYStateConstitutionDownload 

CSYStateConstitutionDownload::CSYStateConstitutionDownload()
  //## begin CSYStateConstitutionDownload::CSYStateConstitutionDownload%.hasinit preserve=no
  //## end CSYStateConstitutionDownload::CSYStateConstitutionDownload%.hasinit
  //## begin CSYStateConstitutionDownload::CSYStateConstitutionDownload%.initialization preserve=yes
  //## end CSYStateConstitutionDownload::CSYStateConstitutionDownload%.initialization
{
  //## begin CSYStateConstitutionDownload::CSYStateConstitutionDownload%.body preserve=yes
  //## end CSYStateConstitutionDownload::CSYStateConstitutionDownload%.body
}


CSYStateConstitutionDownload::~CSYStateConstitutionDownload()
{
  //## begin CSYStateConstitutionDownload::~CSYStateConstitutionDownload%.body preserve=yes
  //## end CSYStateConstitutionDownload::~CSYStateConstitutionDownload%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionDownload::MakeWritable (const CString& p_sFile)
{
  //## begin CSYStateConstitutionDownload::MakeWritable%1200053479.body preserve=yes
	//example for CFile::GetStatus
	CFileStatus l_FileStatus;
	if ( CFile::GetStatus( (LPCTSTR) p_sFile, l_FileStatus ) )
	{
		// file exists
		// remove readOnly attribute
		l_FileStatus.m_attribute = 0;
		CFile::SetStatus( (LPCTSTR) p_sFile, l_FileStatus );
	}
  //## end CSYStateConstitutionDownload::MakeWritable%1200053479.body
}

void CSYStateConstitutionDownload::CleanupTempFolder (const CString& p_sFolder)
{
  //## begin CSYStateConstitutionDownload::CleanupTempFolder%1200165527.body preserve=yes
    try
    {
        BOOL                        bSuccess = TRUE;
        CString                     sDLLName = _T("");
        CString                     sDLLPath = _T("");
        HANDLE                      hFile;                    
        WIN32_FIND_DATA             fileData;
        
        hFile = FindFirstFile(p_sFolder+_T("\\*.*"), &fileData);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            BOOL bWorking = TRUE;
            while (bWorking)
            {
                if (!(fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                {
                    sDLLName = fileData.cFileName;
                    sDLLPath = p_sFolder + _T("\\") + sDLLName;

	                // remove read only attribute
	                CFileStatus l_FileStatus;
	                if ( CFile::GetStatus( (LPCTSTR) sDLLPath, l_FileStatus ) )
	                {
		                // file exists
		                // remove readOnly attribute
		                l_FileStatus.m_attribute = 0;
		                CFile::SetStatus( (LPCTSTR) sDLLPath, l_FileStatus );
	                }

                    DeleteFile(sDLLPath);
                }
                bWorking = FindNextFile(hFile, &fileData);
            }
            FindClose(hFile);
        }
    }
    catch(CFileException* p_pException)
    {
        p_pException->Delete();
    }
  //## end CSYStateConstitutionDownload::CleanupTempFolder%1200165527.body
}

void CSYStateConstitutionDownload::CopyFolder (const CString& p_sSrcFolder, const CString& p_sDestFolder)
{
  //## begin CSYStateConstitutionDownload::CopyFolder%1200222480.body preserve=yes
    BOOL                        bSuccess = TRUE;
    CString                     sDLLName = _T("");
    CString                     sSrcPath = _T("");
    CString                     sDestPath = _T("");
    HANDLE                      hFile;                    
    WIN32_FIND_DATA             fileData;
    
    hFile = FindFirstFile(p_sSrcFolder+_T("\\*.*"), &fileData);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        BOOL bWorking = TRUE;
        while (bWorking)
        {
            if (!(fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                sDLLName = fileData.cFileName;
                sSrcPath = p_sSrcFolder + _T("\\") + sDLLName;
				sDestPath = p_sDestFolder + _T("\\") + sDLLName;

	            // remove read only attribute
	            CFileStatus l_FileStatus;
	            if ( CFile::GetStatus( (LPCTSTR) sDestPath, l_FileStatus ) )
	            {
		            // file exists
		            // remove readOnly attribute
		            l_FileStatus.m_attribute = 0;
		            CFile::SetStatus( (LPCTSTR) sDestPath, l_FileStatus );
	            }

				::CopyFile(sSrcPath, sDestPath, false);
            }
            bWorking = FindNextFile(hFile, &fileData);
        }
        FindClose(hFile);
    }
  //## end CSYStateConstitutionDownload::CopyFolder%1200222480.body
}

void CSYStateConstitutionDownload::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionDownload::ConnectionLost%1200165525.body preserve=yes
	CleanupTempFolder(sTempDLLLocation + _T("\\CE"));
	CleanupTempFolder(sTempDLLLocation + _T("\\Reboot"));
	CleanupTempFolder(sTempDLLLocation + _T("\\NoReboot"));

    p_pContext->ChangeState(CSYStateConstitutionStandByWarmingUp::GetInstance());
  //## end CSYStateConstitutionDownload::ConnectionLost%1200165525.body
}

// Additional Declarations
  //## begin CSYStateConstitutionDownload%47875C020199.declarations preserve=yes
  //## end CSYStateConstitutionDownload%47875C020199.declarations

//## begin module%3EE086FE0094.epilog preserve=yes
//## end module%3EE086FE0094.epilog
