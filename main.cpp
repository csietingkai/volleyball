#include <iostream>

#include "src/beans/DateTime.h"
#include "src/test/test.h"
#include "src/tools/SqlCommandBuilder.h"
#include "src/utils/ServerInfo.h"
#include "src/utils/Utils.h"
#include "src/views/MainWindow.h"
#include "src/auth.h"

int main(int argc, char* argv[])
{
	std::cout << "account: ";
	std::string account;
	std::cin >> account;
	std::cout << "password: ";
	std::string pwd;
	std::cin >> pwd;
	
	voba::User user = voba::auth(account, pwd);
	if (user.role <= voba::Role::USER)
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

			voba::MainWindow window;
			
			return app->run(window);
		}
	}
	else
	{
		std::cout << "Auth Failed" << std::endl;
	}
	
	return 1;
}
