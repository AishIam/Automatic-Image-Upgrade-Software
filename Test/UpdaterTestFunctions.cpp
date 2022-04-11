/*****************************************************************************************************
** FILENAME       :    UpdaterTestFunctions.cpp
**
** DESCRIPTION    :   Testing Program to test all the functions of Updater class
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
#include "UpdaterTestFunctions.h"
#include "utility.h"
#include "Updater.h"
#include <cstring>

//global vars
Updater *updater;

void 
UpdaterTest::setUp()
{
}

void 
UpdaterTest::tearDown()
{
}


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( UpdaterTest );

/****************************************************************
FUNCTION NAME   : testConstructor
DESCRIPTION     : Method to test the constructor of Updater class
				   
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_U-01
RETURN          : void
****************************************************************/ 

void UpdaterTest::testConstructor() {  
	// create a Updater object
	
	char d_id[] = "1EBH56";
	char m_no[] = "1234567898765432";
	Device *dev = new Device(d_id, m_no);
	Header *header = new Header();
	
	updater= new Updater(dev, header, "file.BAK");
	
	
}

/****************************************************************
FUNCTION NAME   : testValidate
DESCRIPTION     : Method to test the Validate function which validates all
**					the details present in the input files
				   
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_U-02
RETURN          : void
****************************************************************/ 

void UpdaterTest::testValidate() {
	
	
}

/****************************************************************
FUNCTION NAME   : testInstallDownload
DESCRIPTION     : Method to test the function InstallDownload
				   
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_U-03
RETURN          : void
****************************************************************/ 
void UpdaterTest::testInstallDownload() {
	
	
}

/****************************************************************
FUNCTION NAME   : testIsComplete
DESCRIPTION     : Method to test the function IsComplete
				   
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_U-04
RETURN          : void
****************************************************************/ 
void UpdaterTest::testIsComplete() {
	
	
}

/****************************************************************
FUNCTION NAME   : testRevert
DESCRIPTION     : Method to test the function Revert
				   
PARAMETERS      : nil
FUNCTION TAG    : AIU/UT_U-05
RETURN          : void
****************************************************************/ 
void UpdaterTest::testRevert() {
	
	
}


