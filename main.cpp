#include <iostream>

#include "src/beans/DateTime.h"
#include "src/tools/SqlCommandBuilder.h"
#include "src/utils/ServerInfo.h"
#include "src/utils/Utils.h"
#include "src/views/MainWindowView.h"
#include "src/auth.h"
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
		Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

		voba::MainWindowView window;

		return app->run(window);
	}
}
