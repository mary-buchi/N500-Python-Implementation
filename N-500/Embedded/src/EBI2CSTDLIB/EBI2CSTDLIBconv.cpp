//## begin module%3EE73AEB0290.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE73AEB0290.cm

//## begin module%3EE73AEB0290.cp preserve=no
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
//## end module%3EE73AEB0290.cp

//## Module: EBI2CSTDLIBconv%3EE73AEB0290; Package body
//## Subsystem: EBI2CSTDLIB (I2C Standard Library)%3EE73A490138
//## Source file: R:\Embedded\src\EBI2CSTDLIB\EBI2CSTDLIBconv.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE73AEB0290.additionalIncludes preserve=no
//## end module%3EE73AEB0290.additionalIncludes

//## begin module%3EE73AEB0290.includes preserve=yes
//## end module%3EE73AEB0290.includes

// EBI2CSTDLIBconv
#include "EBI2CSTDLIBconv.h"
//## begin module%3EE73AEB0290.declarations preserve=no
//## end module%3EE73AEB0290.declarations

//## begin module%3EE73AEB0290.additionalDeclarations preserve=yes
//## end module%3EE73AEB0290.additionalDeclarations


// Class CI2CSTDLIBConvert 


//## Other Operations (implementation)
CString CI2CSTDLIBConvert::ByteToI2CString (BYTE p_cValue)
{
  //## begin CI2CSTDLIBConvert::ByteToI2CString%1055234430.body preserve=yes
  BYTE l_cMask = 0x80;
  CString l_strI2C = _T("");
  for (int ii = 0; ii < 8; ii++)
  {
    if (p_cValue & l_cMask)
    {
      // HIGH byte
      l_strI2C+= _T("11");
    }
    else
    {
      // LOW byte
      l_strI2C+= _T("00");
    }

    l_cMask = l_cMask >> 1;
  }
  
  return l_strI2C;
  //## end CI2CSTDLIBConvert::ByteToI2CString%1055234430.body
}

void CI2CSTDLIBConvert::I2CStringToByteStream (CString p_strI2CStream, BYTE* p_pcI2CStream, int p_nI2CDataStreamLength)
{
  //## begin CI2CSTDLIBConvert::I2CStringToByteStream%1055234431.body preserve=yes
  int l_nStreamLength = p_strI2CStream.GetLength();
  int l_nStringCounter = 0;

  for (int ii = 0; ii < p_nI2CDataStreamLength; ii++)
  { 
    p_pcI2CStream[ii] = 0;
    for (int jj = 0; jj < 8; jj++)
    {
      if (l_nStringCounter < l_nStreamLength) 
      {
        CString strTmp = p_strI2CStream.GetAt(jj + (ii * 8));
        BYTE l_qq = ((BYTE)_wtoi((LPCTSTR)strTmp) << (7 - jj));
        p_pcI2CStream[ii] = p_pcI2CStream[ii] | l_qq;
      }
      else
      {
        BYTE l_qq = 0x1 << (7 - jj);
        p_pcI2CStream[ii] = p_pcI2CStream[ii] | l_qq;
      }
      l_nStringCounter++;
    }
  }
  //## end CI2CSTDLIBConvert::I2CStringToByteStream%1055234431.body
}

bool CI2CSTDLIBConvert::I2CStringToByte (CString p_strI2CStream, BYTE& p_cI2CStream)
{
  //## begin CI2CSTDLIBConvert::I2CStringToByte%1055310786.body preserve=yes
  int l_nStreamLength = p_strI2CStream.GetLength();
  if (l_nStreamLength != 16)
    return false;

  CString l_strValue;
  int l_nStringCounter = 0;
  int l_nByteShiftRightCounter = 7;

  p_cI2CStream = 0;
  do
  {
    l_strValue = p_strI2CStream.Mid(l_nStringCounter,2);
    l_nStringCounter+= 2;
    
    if (l_strValue == _T("11"))
    {
      p_cI2CStream|= (0x1 << l_nByteShiftRightCounter);
    }
    else if (!(l_strValue == _T("00")))
    {
      return false;
    }

    l_nByteShiftRightCounter--;
  }
  while (l_nStringCounter < l_nStreamLength);
  return true;
  //## end CI2CSTDLIBConvert::I2CStringToByte%1055310786.body
}

CString CI2CSTDLIBConvert::ByteStreamToI2CString (BYTE* p_pcI2CStream, int p_nI2CDataStreamLength)
{
  //## begin CI2CSTDLIBConvert::ByteStreamToI2CString%1055234432.body preserve=yes
  CString l_strI2C;
  for (int ii = 0; ii < p_nI2CDataStreamLength; ii++)
  {
    l_strI2C+= ByteToString(p_pcI2CStream[ii]);
  }
  
  return l_strI2C;
  //## end CI2CSTDLIBConvert::ByteStreamToI2CString%1055234432.body
}

CString CI2CSTDLIBConvert::ByteToString (BYTE p_cValue)
{
  //## begin CI2CSTDLIBConvert::ByteToString%1055310784.body preserve=yes
  BYTE l_cMask = 0x80;
  CString l_strI2C = _T("");
  for (int ii = 0; ii < 8; ii++)
  {
    if (p_cValue & l_cMask)
    {
      // HIGH byte
      l_strI2C+= _T("1");
    }
    else
    {
      // LOW byte
      l_strI2C+= _T("0");
    }

    l_cMask = l_cMask >> 1;
  }
  
  return l_strI2C;
  //## end CI2CSTDLIBConvert::ByteToString%1055310784.body
}

bool CI2CSTDLIBConvert::CheckACK (char* p_cStream, int p_Position)
{
  //## begin CI2CSTDLIBConvert::CheckACK%1072166712.body preserve=yes
  char l_cCheck;//(char)"";
  for (int ii = 0; ii < 2; ii++)
  {
    l_cCheck = p_cStream[p_Position + ii];
    if (l_cCheck == '0')
      return false;
  }
  
  return true;
  //## end CI2CSTDLIBConvert::CheckACK%1072166712.body
}

bool CI2CSTDLIBConvert::CheckNACK (char* p_cStream, int p_Position)
{
  //## begin CI2CSTDLIBConvert::CheckNACK%1073545771.body preserve=yes
  char l_cCheck;//(char)"";
  for (int ii = 0; ii < 2; ii++)
  {
    l_cCheck = p_cStream[p_Position + ii];
    if (l_cCheck == '1')
      return false;
  }
  
  return true;
  //## end CI2CSTDLIBConvert::CheckNACK%1073545771.body
}

void CI2CSTDLIBConvert::ByteToI2CCharStream (BYTE p_cValue, char* p_cI2CStream)
{
  //## begin CI2CSTDLIBConvert::ByteToI2CCharStream%1072166708.body preserve=yes
  BYTE l_cMask = 0x80;
  strcpy(p_cI2CStream,"");

  for (int ii = 0; ii < 8; ii++)
  {
    if (p_cValue & l_cMask)
    {
      // HIGH byte
      strcat((char*)p_cI2CStream,"11");
    }
    else
    {
      // LOW byte
      strcat((char*)p_cI2CStream,"00");
    }

    l_cMask = l_cMask >> 1;
  }
  //## end CI2CSTDLIBConvert::ByteToI2CCharStream%1072166708.body
}

void CI2CSTDLIBConvert::CharStreamToByteStream (char* p_cI2CStream, BYTE* p_pcI2CStream, int p_nI2CDataStreamLength)
{
  //## begin CI2CSTDLIBConvert::CharStreamToByteStream%1072166709.body preserve=yes
  int l_nStreamLength = strlen(p_cI2CStream);
  int l_nStrCounter = 0;

  for (int ii = 0; ii < p_nI2CDataStreamLength; ii++)
  { 
    p_pcI2CStream[ii] = 0;
    for (int jj = 0; jj < 8; jj++)
    {
      if (l_nStrCounter < l_nStreamLength) 
      {
        if (p_cI2CStream[jj + (ii * 8)] == '1')
        {
          p_pcI2CStream[ii]|= (0x1 << (7 - jj));
        }
      }
      else
      {
          p_pcI2CStream[ii]|= (0x1 << (7 - jj));
      }
      l_nStrCounter++;
    }
  }

  //## end CI2CSTDLIBConvert::CharStreamToByteStream%1072166709.body
}

void CI2CSTDLIBConvert::ByteStreamToCharStream (BYTE* p_pcI2CStream, int p_nI2CDataStreamLength, char* p_cI2CStream)
{
  //## begin CI2CSTDLIBConvert::ByteStreamToCharStream%1072166710.body preserve=yes
  for (int ii = 0; ii < p_nI2CDataStreamLength; ii++)
  {
    ByteToCharStream(p_pcI2CStream[ii],p_cI2CStream);
  }
  //## end CI2CSTDLIBConvert::ByteStreamToCharStream%1072166710.body
}

void CI2CSTDLIBConvert::ByteToCharStream (BYTE p_cValue, char* p_cDataStream)
{
  //## begin CI2CSTDLIBConvert::ByteToCharStream%1072166711.body preserve=yes
  BYTE l_cMask = 0x80;
  for (int ii = 0; ii < 8; ii++)
  {
    if (p_cValue & l_cMask)
    {
      // HIGH byte
      strcat((char*)p_cDataStream,"1");
    }
    else
    {
      // LOW byte
      strcat((char*)p_cDataStream,"0");
    }

    l_cMask = l_cMask >> 1;
  }
  //## end CI2CSTDLIBConvert::ByteToCharStream%1072166711.body
}

bool CI2CSTDLIBConvert::I2CCharStreamToByte (char* p_cI2CStream, BYTE& p_cI2CData)
{
  //## begin CI2CSTDLIBConvert::I2CCharStreamToByte%1072166713.body preserve=yes
  int l_nStreamLength = strlen(p_cI2CStream);
  if (l_nStreamLength != 16)
    return false;

  char l_cValue[64];
  strcpy(l_cValue, "");
  char l_cHigh[] = "11";
  char l_cLow[] = "00";
  int l_nStringCounter = 0;
  int l_nByteShiftRightCounter = 7;

  p_cI2CData = 0;
  do
  {
    strcpy(l_cValue, "");
    strncat(l_cValue, p_cI2CStream + l_nStringCounter, 2);
    l_nStringCounter+= 2;
    
    if (strcmp(l_cValue, l_cHigh) == 0)
    {
      p_cI2CData|= (0x1 << l_nByteShiftRightCounter);
    }
    else if (!(strcmp(l_cValue, l_cLow) == 0))
    {
      return false;
    }

    l_nByteShiftRightCounter--;
  }
  while (l_nStringCounter < l_nStreamLength);
  return true;
  //## end CI2CSTDLIBConvert::I2CCharStreamToByte%1072166713.body
}

void CI2CSTDLIBConvert::CharStreamToDWordStream (char* p_cI2CStream, DWORD* p_pdwI2CStream, int p_nI2CDataStreamLength)
{
  //## begin CI2CSTDLIBConvert::CharStreamToDWordStream%1078405492.body preserve=yes
  int l_nStreamLength = strlen(p_cI2CStream);
  int l_nStrCounter = 0;
  
  l_nStrCounter = 0;
  for (int jj = 0; jj < p_nI2CDataStreamLength; jj++)
  {
    p_pdwI2CStream[jj] = 0;
    for (int ii = 0; ii < 32; ii++)
    {
      if (l_nStrCounter < l_nStreamLength) 
      {
        if (p_cI2CStream[ii + (jj * 32)] == '1')
        {
          p_pdwI2CStream[jj]|= (0x1 << (31 - ii));
        }
      }
      else
      {
          p_pdwI2CStream[jj]|= (0x1 << (31 - ii));
      }
      l_nStrCounter++;
    }
  }
  //## end CI2CSTDLIBConvert::CharStreamToDWordStream%1078405492.body
}

void CI2CSTDLIBConvert::DWordStreamToCharStream (DWORD* p_pdwI2CStream, int p_nI2CDataStreamLength, char* p_cI2CStream)
{
  //## begin CI2CSTDLIBConvert::DWordStreamToCharStream%1078405494.body preserve=yes
  for (int ii = 0; ii < p_nI2CDataStreamLength; ii++)
  {
    DWordToCharStream(p_pdwI2CStream[ii],p_cI2CStream);
  }
  //## end CI2CSTDLIBConvert::DWordStreamToCharStream%1078405494.body
}

void CI2CSTDLIBConvert::DWordToCharStream (DWORD p_dwValue, char* p_cDataStream)
{
  //## begin CI2CSTDLIBConvert::DWordToCharStream%1078405495.body preserve=yes
  DWORD l_dwMask = 0x80000000;
  for (int ii = 0; ii < 32; ii++)
  {
    if (p_dwValue & l_dwMask)
    {
      // HIGH byte
      strcat((char*)p_cDataStream,"1");
    }
    else
    {
      // LOW byte
      strcat((char*)p_cDataStream,"0");
    }

    l_dwMask = l_dwMask >> 1;
  }
  //## end CI2CSTDLIBConvert::DWordToCharStream%1078405495.body
}

// Additional Declarations
  //## begin CI2CSTDLIBConvert%3EE5975C0138.declarations preserve=yes
  //## end CI2CSTDLIBConvert%3EE5975C0138.declarations

//## begin module%3EE73AEB0290.epilog preserve=yes
//## end module%3EE73AEB0290.epilog
