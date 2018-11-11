#include <iostream>

#include "src/common.h"
#include "src/Datee.h"
#include "src/DateTime.h"
#include "src/MainWindow.h"
#include "src/MySQLConnector.h"
#include "src/Person.h"
#include "src/Team.h"
#include "src/Time.h"
#include "src/Logger.h" 
#include "test/test.h"

using namespace std;

// TODO List
// frontend view
// Logger class							// RB doing
// DateTime to (Date, Time, DateTime)	// tingkai almost finish
// test unit in test.cpp
// algorithm for scheduling games
// add git .gitignore
// set team conditions

#define TEST_MODE true

int main(int argc, char* argv[])
{
#if TEST_MODE
	test_main();
#else
	/*RefPtr<Application> app = Application::create(argc, argv);
	
	View window;
	
	return app->run(window);*/
	
	return 0;
#endif
	
	
}
