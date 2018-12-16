#include "test.h"

void voba::test_main()
{
	voba::test_beans();
	voba::test_models();
	voba::test_tools();
}

void voba::test_beans()
{
	voba::test_date();
	voba::test_datetime();
	voba::test_time();
}

void voba::test_date()
{
	
}

void voba::test_datetime()
{
	
}

void voba::test_time()
{
	
}

void voba::test_models()
{
	voba::test_game();
	voba::test_person();
	voba::test_team();
}

void voba::test_game()
{
	
}

void voba::test_person()
{
	voba::Person person = voba::PersonFactory::create("aaa", 11, voba::Gender::female, "0912345678", voba::ActiveStatus::inactive);
	std::cout << person << std::endl;
}

void voba::test_team()
{
	
}

void voba::test_tools()
{
	voba::test_connector();
}

void voba::test_connector()
{
	
}
