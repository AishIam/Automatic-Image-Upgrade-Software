/*****************************************************************************************************
** FILENAME       :    HeaderTestFunctions.h
**
** DESCRIPTION    :   Testing Program to test all the functions of Header class
**
** Revision History   :    V_0.1
**
** DATE
** ------------------------------------------------------------------------------------------------
** 08 APR 2022               
** 
** 
** Copyright © 2022 Capgemini Group All Rights Reserved
**
*****************************************************************************************************/


#include <cppunit/config/SourcePrefix.h>
#include "HeaderTestFunctions.h"
#include "utility.h"
#include "Header.h"
#include <cstring>

//global vars
Header *header;

void 
HeaderTest::setUp()
{
}

void 
HeaderTest::tearDown()
{
}


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( HeaderTest );
 
/****************************************************************
FUNCTION NAME   : testParseDetails
DESCRIPTION     : Method to test the function ParseDetails which 
**				   parses the file and set values of the instance variables
				   
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_H-01
RETURN          : void
****************************************************************/  
void HeaderTest::testParseDetails() { 
	// create a Header object
	
	header = new Header();
	
	header->ParseDetails("file.BAK");
	
	char dev_id[] = "1EBH56";
	char mag_no[] = "1234567898765432";
	char dev_name[] = "Filesystem_Image";
	char checksum[] = "00001000";
	char address[] = "0x11011110";
	char BIAddr[] = "0x3F00";
	char BISize[] = "64";
	char BIVersion[] = "10.5.16299.15";
	
	CPPUNIT_ASSERT(strcmp(dev_id, header->GetDeviceID())==0);
	
	CPPUNIT_ASSERT(strcmp(mag_no, header->GetMagicNo())==0);
	
	CPPUNIT_ASSERT(strcmp(dev_name, header->GetDeviceName())==0);
	
	CPPUNIT_ASSERT(strcmp(checksum, header->GetChecksum())==0);
	
	CPPUNIT_ASSERT(strcmp(address, header->GetBaseAddress())==0);
	
	CPPUNIT_ASSERT(strcmp(BIAddr, header->GetBIAddress())==0);
	
	CPPUNIT_ASSERT(strcmp(BISize, header->GetBISize())==0);
	
	CPPUNIT_ASSERT(strcmp(BIVersion, header->GetBIVersion())==0);
		
}

/****************************************************************
FUNCTION NAME   : testGetFileType
DESCRIPTION     : Method to test the function GetFileType which 
**				   returns the file type after checking its extension
				   
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_H-02
RETURN          : void
****************************************************************/  
void HeaderTest::testGetFileType() {
	
	string type = header->GetFileType("file.BAK");
	CPPUNIT_ASSERT("file system" == type);
	
	type = header->GetFileType("file.boot");
	CPPUNIT_ASSERT("boot image" == type);
}


