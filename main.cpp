#include <iostream>

#include "src/common.h"
#include "src/MySQLConnector.h"
#include "src/Person.h"
#include "src/Team.h"
#include "src/View.h"

using namespace std;
using namespace Gtk;
using namespace Glib;

void test_init()
{
	Person test1("test1", 21, Gender::male, "0987654321", ActiveStatus::active);
	Person test2("test2", 22, Gender::male, "0987654321", ActiveStatus::active);
	Person test3("test3", 23, Gender::male, "0987654321", ActiveStatus::active);
	Person test4("test4", 24, Gender::male, "0987654321", ActiveStatus::active);
	Person test5("test5", 25, Gender::male, "0987654321", ActiveStatus::active);
	
	Team test_team("test_team");
	test_team.add_member(test1);
	test_team.add_member(test2);
	test_team.add_member(test3);
	test_team.add_member(test4);
	test_team.add_member(test5);
}

void test_team()
{
	Team test_team("test_team");
	for(int i = 0; i < test_team.size(); i++)
	{
		cout << test_team.get_member(i) << endl;
	}
}

int main(int argc, char* argv[])
{
	/*RefPtr<Application> app = Application::create(argc, argv);
	
	View window;
	
	return app->run(window);*/
	
	//test_init();
	test_team();
	
	return 0;
}
