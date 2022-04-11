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
map<string, char*> partitions;
map<string, char*> test_partitions;

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
	char start_addr[] = "0x7f36d4560010";
	dev = new Device(d_id, m_no);
	
	// check that the object is constructed correctly
	char *dev_id = dev->GetDeviceId();
	CPPUNIT_ASSERT(strcmp(d_id,dev_id)==0);
	
	char *magic_no = dev->GetMagicNo();
	CPPUNIT_ASSERT(strcmp(m_no, magic_no)==0);
	
	long int size = dev->GetSize();
	CPPUNIT_ASSERT(125829120 == size);
	
	char *startAddress = dev->GetStartAddress();
	CPPUNIT_ASSERT(strcmp(start_addr,startAddress)==0);
	
	CPPUNIT_ASSERT(25 == dev->GetHeaderLength());   //SetHeader() method is called inside constructor
		
}

/****************************************************************
FUNCTION NAME   : testSetPartition
DESCRIPTION     : Method to test the constructor
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_D-02
RETURN          : void
****************************************************************/ 
void DeviceTest::testSetPartition() {
	
	unsigned long int p_size = 20971515;
	CPPUNIT_ASSERT(p_size == dev->GetPartitionSize());
	
//	test_partitions["boot image"] = 	
//	test_partitions["application"] = 
//	test_partitions["libraries"] = 
//	test_partitions["framework level"] = 	
//	test_partitions["file system"] = 
//	test_partitions["kernel module"] = 
//	
//	dev->SetPartition();
//	partitions = dev->GetPartitions();
//	
//	CPPUNIT_ASSERT(test_partitions, partitions);
			
}

//void DeviceTest::testSetMemory(){
//	
//	unsigned long long int p_size = 20971515;
//	
//	memset(test_partitions["boot image"], '\0', p_size);
//	memset(test_partitions["application"], '\0', p_size); 
//	memset(test_partitions["libraries"], '\0', p_size);
//	memset(test_partitions["framework level"], '\0', p_size);
//	memset(test_partitions["file system"], '\0', p_size);
//	memset(test_partitions["kernel module"], '\0', p_size);
//	
//	dev->SetMemory();
//}


