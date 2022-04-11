/*****************************************************************************************************
** FILENAME       :    HeaderTestFunctions.h
**
** DESCRIPTION    :   Header file for HeaderTestFunctions.cpp containing all the test functions for Header class
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

#ifndef __HEADERTESTFUNCTIONS_H__
#define __HEADERTESTFUNCTIONS_H__

#include <cppunit/extensions/HelperMacros.h>

class HeaderTest : public CPPUNIT_NS::TestFixture 
{ 
/*************Test suites ****************/
	CPPUNIT_TEST_SUITE( HeaderTest );  
	CPPUNIT_TEST( testParseDetails );
	CPPUNIT_TEST( testGetFileType );
	CPPUNIT_TEST_SUITE_END();
	
/**************Test Functions *************/
	public:
		void setUp();
		void tearDown();

		// method to test the method ParseDetails
		void testParseDetails();

		// method to test the GetFileType method
		void testGetFileType();
};


#endif
