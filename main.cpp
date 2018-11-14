#include <iostream>

#include "src/common.h"
#include "src/Datee.h"
#include "src/DateTime.h"
#include "src/MainWindowView.h"
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
// test unit in test.cpp
// algorithm for scheduling games
// set team conditions					// tingkai doing
// find the way to test gui on travis and trigger close button after few seconds
// create data in database for testing

#define TEST_MODE true

int main(int argc, char* argv[])
{
	int ret = 0;
	
#if TEST_MODE
	Logger main_log("Main");
	main_log.trace("trace in main!");
	main_log.fatal("fatal in main!!!");
	test_main();
#else
	// TODO need to test manually
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
	
	MainWindowView window;
	
	ret = app->run(window);
#endif
	
	return ret;
}
