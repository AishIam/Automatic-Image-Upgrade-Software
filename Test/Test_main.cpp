#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "utility.h"
#include "Device.h"
#include "DeviceTestFunctions.h"
#include "Header.h"
#include "HeaderTestFunctions.h"
#include "UpdaterTestFunctions.h"
#include "Updater.h"

int main()
{
	// Gets the top level suite from the registry
	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);
	bool wasSucessful = runner.run();
	
	if(wasSucessful){
		cout << "Passed!" << endl;
	}
	else{
		cout << "Failed!" << endl;
	}
}
