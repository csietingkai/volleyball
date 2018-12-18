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
	std::cout << person.get_id() << " " << person << std::endl;
	person.set_name("haha");
	voba::PersonFactory::update(person);
	std::cout << person.get_id() << " " << person << std::endl;
	voba::PersonFactory::remove(person);
}

void voba::test_team()
{
	
}

void voba::test_tools()
{
	voba::test_logger();
	voba::test_connector();
	voba::test_sqlcommandbuilder();
}

void voba::test_logger()
{
	
}

void voba::test_connector()
{
	
}

void voba::test_sqlcommandbuilder()
{
	
}

void voba::test_utils()
{
	voba::test_serverinfo();
	voba::test_util();
	voba::test_uuid();
}

void voba::test_serverinfo()
{
	
}

void voba::test_util()
{
	
}

void voba::test_uuid()
{
	
}

