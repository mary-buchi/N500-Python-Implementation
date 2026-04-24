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

	cregkey.h

Abstract:

	Declaration file for the CRegKey class


Revision History:


*****************************************************************************/
//////////////////////////////////////////////////////////////////////////////
#ifndef __CREGKEY_H_
#define __CREGKEY_H_


class CRegKey
{
public:
    CRegKey (LPCTSTR lpActiveRegPath);
    ~CRegKey ();
    BOOL QueryDword     (LPWSTR lpSubKeyName, DWORD & dwValue);
    BOOL QueryBinary    (LPWSTR lpSubKeyName, DWORD & dwSize, PUCHAR * pucData);
    BOOL QuerySzA       (LPWSTR lpSubKeyName, DWORD & dwSize, LPSTR lpStr);
    BOOL QuerySzW       (LPWSTR lpSubKeyName, DWORD & dwSize, LPWSTR lpStr);
    HKEY Key(void) { return m_hKey; };
private:
    HKEY    m_hKey;
};


#endif // __CREGKEY_H_
