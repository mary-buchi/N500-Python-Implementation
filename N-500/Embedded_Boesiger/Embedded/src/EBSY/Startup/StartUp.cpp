// StartUp.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <string.h>
#include "Pm.h"

int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	if (wcscmp(lpCmdLine, _T("-Reboot")) == 0)
	{
		SetSystemPowerState(_T("Reboot"), POWER_STATE_BOOT, 0);
		return 0;
	}
	else
	{
		PROCESS_INFORMATION procInfo;
		CreateProcess(_T("\\Windows\\Cmd.exe"),
					  _T("/c \"\\Hard Disk\\NIRFlex\\Startup.cmd\""),
					  NULL, NULL, NULL, 
					  0,
					  NULL, NULL, NULL,
					  &procInfo);
		return 0;
	}
}
