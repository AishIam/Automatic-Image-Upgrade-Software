#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "utility.h"
#include "Device.h"
#include "DeviceTestFunctions.h"
#include "Header.h"
#include "HeaderTestFunctions.h"

int main()
{
	// Gets the top level suite from the registry
	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);
	bool wasSucessful = runner.run();
	
	return wasSucessful ? 0 : 1;
}
