//## begin module%3EE73AF7033C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE73AF7033C.cm

//## begin module%3EE73AF7033C.cp preserve=no
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
//## end module%3EE73AF7033C.cp

//## Module: EBI2CSTDLIBconv%3EE73AF7033C; Package specification
//## Subsystem: EBI2CSTDLIB (I2C Standard Library)%3EE73A490138
//## Source file: R:\Embedded\src\EBI2CSTDLIB\EBI2CSTDLIBconv.h

#ifndef EBI2CSTDLIBconv_h
#define EBI2CSTDLIBconv_h 1

//## begin module%3EE73AF7033C.additionalIncludes preserve=no
//## end module%3EE73AF7033C.additionalIncludes

//## begin module%3EE73AF7033C.includes preserve=yes
//## end module%3EE73AF7033C.includes

//## begin module%3EE73AF7033C.declarations preserve=no
//## end module%3EE73AF7033C.declarations

//## begin module%3EE73AF7033C.additionalDeclarations preserve=yes
//## end module%3EE73AF7033C.additionalDeclarations


//## begin CI2CSTDLIBConvert%3EE5975C0138.preface preserve=yes
//## end CI2CSTDLIBConvert%3EE5975C0138.preface

//## Class: CI2CSTDLIBConvert%3EE5975C0138
//## Category: EBI2CSTDLIB (I2C Standard Library)%3EE73A9A009C
//## Subsystem: EBI2CSTDLIB (I2C Standard Library)%3EE73A490138
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CI2CSTDLIBConvert 
{
  //## begin CI2CSTDLIBConvert%3EE5975C0138.initialDeclarations preserve=yes
  //## end CI2CSTDLIBConvert%3EE5975C0138.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: ByteToI2CString%1055234430
      //	DESCRIPTION:
      //	Converts a byte value to a I2C string.
      //	I2C String:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 91h => 11 00 00 11 00 00 00 11 (String)
      //
      //	PARAMETER:
      //	byte value to convert
      //
      //	RETURN:
      //	I2C string
      static CString ByteToI2CString (BYTE p_cValue);

      //## Operation: I2CStringToByteStream%1055234431
      //	DESCRIPTION:
      //	Converts a I2C string byte stream.
      //	I2C String:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 11 00 00 11 00 00 00 11 (I2C String) => 91h
      //
      //	PARAMETER:
      //	- string to convert
      //	- byte pointer that receives the data stream
      //	- pointer to the number of bytes convert
      //
      //	RETURN:
      //	-
      static void I2CStringToByteStream (CString p_strI2CStream, BYTE* p_pcI2CStream, int p_nI2CDataStreamLength);

      //## Operation: I2CStringToByte%1055310786
      //	DESCRIPTION:
      //	Converts a I2C string byte stream (16 characters!).
      //	I2C String:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 11 00 00 11 00 00 00 11 (I2C String) => 91h
      //
      //	PARAMETER:
      //	- string to convert
      //	- byte pointer that receives the data
      //
      //	RETURN:
      //	onzero if the operation is successful otherwise, it is 0.
      static bool I2CStringToByte (CString p_strI2CStream, BYTE& p_cI2CStream);

      //## Operation: ByteStreamToI2CString%1055234432
      //	DESCRIPTION:
      //	Converts a byte stream to a I2C string stream.
      //	I2C String:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 91h => 11 00 00 11 00 00 00 11 (I2C String)
      //
      //	PARAMETER:
      //	- byte pointer data stream
      //	- pointer to the number of bytes convert
      //
      //	RETURN:
      //	-
      static CString ByteStreamToI2CString (BYTE* p_pcI2CStream, int p_nI2CDataStreamLength);

      //## Operation: ByteToString%1055310784
      //	DESCRIPTION:
      //	Converts a byte value to a string.
      //
      //	PARAMETER:
      //	byte value to convert
      //
      //	RETURN:
      //	string
      static CString ByteToString (BYTE p_cValue);

      //## Operation: CheckACK%1072166712
      //	DESCRIPTION:
      //	checks the ACK from a char stream
      //
      //	PARAMETER:
      //	char stream
      //
      //	RETURN:
      //	true: ACK ok
      //	false: ACK failed
      static bool CheckACK (char* p_cStream, int p_Position);

      //## Operation: CheckNACK%1073545771
      //	DESCRIPTION:
      //	checks the NACK from a char stream
      //
      //	PARAMETER:
      //	char stream
      //
      //	RETURN:
      //	true: NACK ok
      //	false: NACK failed
      static bool CheckNACK (char* p_cStream, int p_Position);

      //## Operation: ByteToI2CCharStream%1072166708
      //	DESCRIPTION:
      //	Converts a byte value to a char stream
      //	I2C char stream:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 91h => 11 00 00 11 00 00 00 11 (char stream)
      //
      //	PARAMETER:
      //	byte value to convert
      //
      //	RETURN:
      //	I2C string
      static void ByteToI2CCharStream (BYTE p_cValue, char* p_cI2CStream);

      //## Operation: CharStreamToByteStream%1072166709
      //	DESCRIPTION:
      //	Converts a char stream to a byte stream.
      //	char stream:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 11 00 00 11 00 00 00 11 (I2C String) => 91h
      //
      //	PARAMETER:
      //	- char stream
      //	- byte pointer that receives the data stream
      //	- pointer to the number of bytes convert
      //
      //	RETURN:
      //	-
      static void CharStreamToByteStream (char* p_cI2CStream, BYTE* p_pcI2CStream, int p_nI2CDataStreamLength);

      //## Operation: ByteStreamToCharStream%1072166710
      //	DESCRIPTION:
      //	Converts a byte stream to a char stream.
      //	char stream:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 91h => 11 00 00 11 00 00 00 11 (I2C stream)
      //
      //	PARAMETER:
      //	- byte pointer data stream
      //	- pointer to the number of bytes convert
      //	- char stream
      //	RETURN:
      //	-
      static void ByteStreamToCharStream (BYTE* p_pcI2CStream, int p_nI2CDataStreamLength, char* p_cI2CStream);

      //## Operation: ByteToCharStream%1072166711
      //	DESCRIPTION:
      //	Converts a byte value to a char stream
      //
      //	PARAMETER:
      //	byte value to convert
      //	char stream
      static void ByteToCharStream (BYTE p_cValue, char* p_cDataStream);

      //## Operation: I2CCharStreamToByte%1072166713
      //	DESCRIPTION:
      //	Converts a I2C char stream to byte stream (16
      //	characters!).
      //	I2C char stream:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 11 00 00 11 00 00 00 11 (I2C String) => 91h
      //
      //	PARAMETER:
      //	- string to convert
      //	- byte pointer that receives the data
      //
      //	RETURN:
      //	onzero if the operation is successful otherwise, it is 0.
      static bool I2CCharStreamToByte (char* p_cI2CStream, BYTE& p_cI2CData);

      //## Operation: CharStreamToDWordStream%1078405492
      //	DESCRIPTION:
      //	Converts a char stream to a DWORD stream.
      //	char stream:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 11 00 00 11 00 00 00 11 (I2C String) => 91h
      //
      //	PARAMETER:
      //	- char stream
      //	- DWORD pointer that receives the data stream
      //	- pointer to the number of DWORD convert
      //
      //	RETURN:
      //	-
      static void CharStreamToDWordStream (char* p_cI2CStream, DWORD* p_pdwI2CStream, int p_nI2CDataStreamLength);

      //## Operation: DWordStreamToCharStream%1078405494
      //	DESCRIPTION:
      //	Converts a DWORD stream to a char stream.
      //	char stream:
      //	11: HIGH Byte
      //	00: LOW Byte
      //
      //	e.g. 91h => 11 00 00 11 00 00 00 11 (I2C stream)
      //
      //	PARAMETER:
      //	- DWORD pointer data stream
      //	- pointer to the number of DWORD convert
      //	- char stream
      //	RETURN:
      //	-
      static void DWordStreamToCharStream (DWORD* p_pdwI2CStream, int p_nI2CDataStreamLength, char* p_cI2CStream);

      //## Operation: DWordToCharStream%1078405495
      //	DESCRIPTION:
      //	Converts a DWORD value to a char stream
      //
      //	PARAMETER:
      //	DWORD value to convert
      //	char stream
      static void DWordToCharStream (DWORD p_dwValue, char* p_cDataStream);

    // Additional Public Declarations
      //## begin CI2CSTDLIBConvert%3EE5975C0138.public preserve=yes
      //## end CI2CSTDLIBConvert%3EE5975C0138.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CSTDLIBConvert%3EE5975C0138.protected preserve=yes
      //## end CI2CSTDLIBConvert%3EE5975C0138.protected

  private:
    //## Constructors (generated)
      CI2CSTDLIBConvert();

      CI2CSTDLIBConvert(const CI2CSTDLIBConvert &right);

    //## Assignment Operation (generated)
      const CI2CSTDLIBConvert & operator=(const CI2CSTDLIBConvert &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CSTDLIBConvert &right) const;

      bool operator!=(const CI2CSTDLIBConvert &right) const;

    // Additional Private Declarations
      //## begin CI2CSTDLIBConvert%3EE5975C0138.private preserve=yes
      //## end CI2CSTDLIBConvert%3EE5975C0138.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CSTDLIBConvert%3EE5975C0138.implementation preserve=yes
      //## end CI2CSTDLIBConvert%3EE5975C0138.implementation

};

//## begin CI2CSTDLIBConvert%3EE5975C0138.postscript preserve=yes
//## end CI2CSTDLIBConvert%3EE5975C0138.postscript

// Class CI2CSTDLIBConvert 

//## begin module%3EE73AF7033C.epilog preserve=yes
//## end module%3EE73AF7033C.epilog


#endif
