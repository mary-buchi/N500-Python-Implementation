//## begin module%3DA48FF50035.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA48FF50035.cm

//## begin module%3DA48FF50035.cp preserve=no
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
//## end module%3DA48FF50035.cp

//## Module: EBETmain%3DA48FF50035; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA48FF50035.additionalIncludes preserve=no
//## end module%3DA48FF50035.additionalIncludes

//## begin module%3DA48FF50035.includes preserve=yes
//## end module%3DA48FF50035.includes

// EBETmain
#include "EBETmain.h"
// EBETchan
#include "EBETchan.h"
// EBETsess
#include "EBETsess.h"
// EBETsmon
#include "EBETsmon.h"
// EBETflog
#include "EBETflog.h"
//## begin module%3DA48FF50035.declarations preserve=no
//## end module%3DA48FF50035.declarations

//## begin module%3DA48FF50035.additionalDeclarations preserve=yes

static void InitSocket()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
 
    wVersionRequested = MAKEWORD( 2, 2 );
 
    err = WSAStartup( wVersionRequested, &wsaData );
    ASSERT(err == 0);
}

extern "C" __declspec(dllexport) void InvokeDriver()
{
    InitSocket();

	// create system monitor
	CETSystemMonitor::Create();
	CETFileLogger::Create();

    // create channels
    CETChannelFactory::Create();
    CETChannelFactory::GetInstance()->CreateChannels();

	// create session manager
	CETSessionManager::Create();

	CO_TRACE(_T("SY"), _T("Ethernet Driver started"));
}

extern "C" __declspec(dllexport) void ShutdownDriver()
{
	CETChannelFactory::Delete();

	// delete system monitor
	CETSystemMonitor::Delete();
	CETFileLogger::Delete();

	CETSessionManager::Delete();

    int l_iErr = WSACleanup();
}
//## end module%3DA48FF50035.additionalDeclarations


//## begin module%3DA48FF50035.epilog preserve=yes
//## end module%3DA48FF50035.epilog
