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
// frontend view						// tingkai doing
// Logger class							// RB doing
// test unit in test.cpp
// algorithm for scheduling games
// add git .gitignore
// set team conditions

#define TEST_MODE true

int main(int argc, char* argv[])
{
#if TEST_MODE
	test_main();
#endif
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
	
	MainWindowView window;
	
	return app->run(window);
}
