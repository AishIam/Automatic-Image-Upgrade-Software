/*****************************************************************************************************
** FILENAME       :    UpdaterTestFunctions.h
**
** DESCRIPTION    :   Header file for UpdaterTestFunctions.cpp containing all the test functions for Updater class
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

#ifndef __UPDATERTESTFUNCTIONS_H__
#define __UPDATERTESTFUNCTIONS_H__

#include <cppunit/extensions/HelperMacros.h>

class UpdaterTest : public CPPUNIT_NS::TestFixture 
{ 

/*************Test suites ****************/
	CPPUNIT_TEST_SUITE( UpdaterTest );  
	CPPUNIT_TEST( testConstructor );    //AIU/UT_U-01
	CPPUNIT_TEST( testValidate );       //AIU/UT_U-02
	CPPUNIT_TEST( testInstallDownload );  //AIU/UT_U-03
	CPPUNIT_TEST( testIsComplete );     //AIU/UT_U-04
	CPPUNIT_TEST( testRevert );       //AIU/UT_U-05
	
	CPPUNIT_TEST_SUITE_END();

/**************Test Functions *************/
	public:
		void setUp();
		void tearDown();

		// method to test the Constructor
		void testConstructor();  //AIU/UT_U-01

		// method to test the Validate method
		void testValidate();   //AIU/UT_U-02
		
		// method to test the InstallDownload method
		void testInstallDownload();   //AIU/UT_U-03
		
		// method to test the IsComplete method
		void testIsComplete();   //AIU/UT_U-05
		
		// method to test the Revert method
		void testRevert();    //AIU/UT_U-06
};


#endif
