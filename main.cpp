#include <iostream>

#include "src/common.h"
#include "src/MySQLConnector.h"
#include "src/Person.h"
#include "src/Team.h"
#include "src/View.h"

using namespace std;
using namespace Gtk;
using namespace Glib;

int main(int argc, char* argv[])
{
	RefPtr<Application> app = Application::create(argc, argv);
	
	View window;
	
	return app->run(window);
}
