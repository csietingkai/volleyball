#include <iostream>

#include "src/common.h"
#include "src/Datee.h"
#include "src/DateeTime.h"
#include "src/MainWindowView.h"
#include "src/MySQLConnector.h"
#include "src/Person.h"
#include "src/Schedule.h"
#include "src/Team.h"
#include "src/Time.h"
#include "src/Logger.h" 
#include "test/test.h"

using namespace std;

#define TEST_MODE false

int main(int argc, char* argv[])
{
	int ret = 0;
	
#if TEST_MODE
	test_main();
#else
	// TODO need to test manually
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
	
	MainWindowView window;
	
	ret = app->run(window);
#endif
	
	return ret;
}
