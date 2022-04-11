/*****************************************************************************************************
** FILENAME       :    DeviceTestFunctions.cpp
**
** DESCRIPTION    :   Testing Program to test all the functions of Device class
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
#include "DeviceTestFunctions.h"
#include "utility.h"
#include "Device.h"
#include <cstring>

//global vars
Device * dev;


void 
DeviceTest::setUp()
{
}

void 
DeviceTest::tearDown()
{
}


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( DeviceTest );
 
/****************************************************************
FUNCTION NAME   : testConstructor
DESCRIPTION     : Method to test the constructor
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_D-01
RETURN          : void
****************************************************************/ 
void DeviceTest::testConstructor() {  // Note 5
	// create a Device object
	char d_id[] = "1EBH56";
	char m_no[] = "1234567898765432";
	
	dev = new Device(d_id, m_no);
	
	// check that the object is constructed correctly
	char *dev_id = dev->GetDeviceId();
	CPPUNIT_ASSERT(strcmp(d_id,dev_id)==0);
	
	char *magic_no = dev->GetMagicNo();
	CPPUNIT_ASSERT(strcmp(m_no, magic_no)==0);
	
	long int size = dev->GetSize();
	CPPUNIT_ASSERT(125829120 == size);
	
	CPPUNIT_ASSERT(26 == dev->GetHeaderLength());   //SetHeader() method is called inside constructor
		
}



