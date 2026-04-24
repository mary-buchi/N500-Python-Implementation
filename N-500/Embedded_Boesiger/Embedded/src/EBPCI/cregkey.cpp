//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************


Module Name:

	cregkey.cpp

Abstract:

    Wrapper class for registry keys


*****************************************************************************/
//////////////////////////////////////////////////////////////////////////////


#include <windows.h>
#include <devload.h>
#include "cregkey.h"
//#include "debug.h"

CRegKey::CRegKey (LPCTSTR lpActiveRegPath)
    : m_hKey(NULL)
{ 
	m_hKey = OpenDeviceKey(lpActiveRegPath);
	if(m_hKey == NULL) {
		//DEBUGMSG(ZONE_ERROR, (_T("CRegKey - couldn't get device key from '%s'\r\n"), lpActiveRegPath));
	}
}

CRegKey::~CRegKey()
{
    if (m_hKey != NULL) {
        RegCloseKey (m_hKey);
    }
}

BOOL CRegKey::QueryDword (LPWSTR lpSubKeyName, DWORD & dwValue)
{ DWORD dwSize, dwType;
  LONG rc;
  BOOL result = TRUE;

    if (m_hKey == NULL) {
        return FALSE;
    }

    dwSize = sizeof(dwValue);
    rc = RegQueryValueEx(m_hKey, lpSubKeyName, NULL, &dwType, (LPBYTE) &dwValue, &dwSize);
	if (rc != ERROR_SUCCESS || dwType != REG_DWORD) {
        result = FALSE;
    }
    return result;
}

BOOL CRegKey::QuerySzW (LPWSTR lpSubKeyName, DWORD & dwLength, LPWSTR pszValue)
{ DWORD dwType;
  LONG rc;
  BOOL result = TRUE;

    if (m_hKey == NULL) {
        return FALSE;
    }

    rc = RegQueryValueEx(m_hKey, lpSubKeyName, NULL, &dwType, (LPBYTE) pszValue, &dwLength);
	if (rc != ERROR_SUCCESS || dwType != REG_SZ) {
        result = FALSE;
    }

    return result;
}
