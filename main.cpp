#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include "src/common.h"
#include "src/people.h"
#include "src/datetime.h"
#include "src/game.h"
#include "src/gui.h"

using namespace std;

int main(int argc, char *argv[])
{
	/*Team csie("csie");
	csie.load_file(csie.get_name());
	Team test("test");
	test.load_file(test.get_name());
	
	Game g(csie, test);
	g.set_datetime(DateTime::Now());
	
	Game g2(test, csie);
	DateTime dt;
	g2.set_datetime(dt);
	
	DateTime start(2018, 1, 1);
	DateTime finish(2018, 3, 1);
	Schedule s(start, finish, true);
	s.modify_exclude_week(Week::SUNDAY);
	s.modify_exclude_week(Week::WEDNESDAY);
	s.modify_teams(csie);
	s.modify_teams(test);
	s.start_scheduling();*/
	cout << uuid() << endl;
	
	return 0;
}
