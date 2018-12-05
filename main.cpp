#include <iostream>

/*#include "src/common.h"
#include "src/Datee.h"
#include "src/DateeTime.h"
#include "src/MainWindowView.h"
#include "src/MySQLConnector.h"
#include "src/Person.h"
#include "src/Schedule.h"
#include "src/Team.h"
#include "src/Time.h"
#include "src/Logger.h" 
#include "test/test.h"*/
#include "src/beans/SqlCommandBuilder.h"
#include "src/utils/ServerInfo.h"
#include "src/utils/Utils.h"

int main(int argc, char* argv[])
{
	/*if (argc > 1 && strcmp(argv[1], "test") == 0)
	{
		test_main();
		return 0;
	}
	else
	{
		// TODO need to test manually
		Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

		MainWindowView window;

		return app->run(window);
	}*/
	std::cout << voba::SqlCommandBuilder::build(voba::SqlCommand::select, {"A", "b", "c"}) << std::endl;
	return 0;
}
