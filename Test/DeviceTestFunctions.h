/*****************************************************************************************************
** FILENAME       :    DeviceTestFunctions.h
**
** DESCRIPTION    :   Header file for DeviceTestFunctions.cpp containing all the test functions for Device class
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

#ifndef __DEVICETESTFUNCTIONS_H__
#define __DEVICETESTFUNCTIONS_H__

#include <cppunit/extensions/HelperMacros.h>

class DeviceTest : public CPPUNIT_NS::TestFixture 
{ 
	/*************Test suites ****************/
	CPPUNIT_TEST_SUITE( DeviceTest );  
	CPPUNIT_TEST( testConstructor );
	CPPUNIT_TEST( testSetPartition );
	CPPUNIT_TEST_SUITE_END();
	
	/**************Test Functions *************/
	public:
		void setUp();
		void tearDown();

		// method to test the constructor
		void testConstructor();

		// method to test the SetPartition method
		void testSetPartition();
};


#endif
