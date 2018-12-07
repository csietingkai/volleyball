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
#include "src/beans/DateTime.h"
#include "src/tools/SqlCommandBuilder.h"
#include "src/utils/ServerInfo.h"
#include "src/utils/Utils.h"
#include "test/test.h"

int main(int argc, char* argv[])
{
	if (argc > 1 && strcmp(argv[1], "test") == 0)
	{
		voba::test_main();
		return 0;
	}
	else
	{
		// TODO need to test manually
		/*Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

		MainWindowView window;

		return app->run(window);*/
		return 0;
	}
}
