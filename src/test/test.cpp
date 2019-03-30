#include "test.h"

void voba::test_main()
{
	voba::test_beans();
	voba::test_models();
	voba::test_tools();
	voba::test_utils();
}

void voba::test_beans()
{
	voba::test_date();
	voba::test_time();
	voba::test_datetime();
}

void voba::test_date()
{
	//voba::Date date("1996-08-22");
	//std::cout << date.to_string() << std::endl;
}

void voba::test_datetime()
{
	//voba::DateTime datetime("1996-08-22 02:23:41");
	//std::cout << datetime.to_string() << std::endl;
}

void voba::test_time()
{
	//voba::Time time("02:23:41");
	//std::cout << time.to_string() << std::endl;
}

void voba::test_models()
{
	voba::test_game();
	voba::test_person();
	voba::test_team();
}

void voba::test_game()
{
//	voba::Team t1 = voba::TeamFactory::select_by_id(voba::UUID::from_string("7c6dda5f-be96-49a0-90c4-49c0e8d708c7"));
//	voba::Team t2 = voba::TeamFactory::select_by_id(voba::UUID::from_string("80cd5799-a7f3-4040-94e9-d6c35321e322"));
//	voba::Person p = voba::PersonFactory::select_by_id(voba::UUID::from_string("cd487f02-44d0-484b-b967-4b68a21b8b60"));
//	voba::Game g = voba::GameFactory::create(t1, t2);
//	voba::GameFactory::remove(g);
	
//	std::vector<voba::Game> games = voba::GameFactory::select_all();
//	for (unsigned int i = 0; i < games.size(); i++)
//	{
//		std::cout << games[i].to_string() << std::endl;
//	}
//	voba::Game g = voba::GameFactory::select_by_id(voba::UUID::from_string("f77c36b5-2ccc-40e6-81c0-ae3879c53b11"));
//	std::cout << g.to_string() << std::endl;
}

void voba::test_person()
{
	//voba::Person p("a", 12, voba::Gender::male, "0987s54321", voba::ActiveStatus::active);
	//voba::Person p1 = voba::PersonFactory::create("a", 12, voba::Gender::male, "0987s54321", voba::ActiveStatus::active);
	//std::cout << voba::PersonFactory::update(p) << std::endl;
	//std::cout << p.to_string() << std::endl;
	//voba::PersonFactory::remove(p);
	
	/*std::vector<voba::Person> all = voba::PersonFactory::select_all();
	for (unsigned int i = 0; i < all.size(); i++)
	{
		std::cout << all[i] << std::endl;
	}*/
}

void voba::test_team()
{
//	voba::Person p1 = voba::PersonFactory::create(voba::Utils::random_string(6), 12, voba::Gender::male, "0987s54321", voba::ActiveStatus::active);
//	voba::Person p2 = voba::PersonFactory::create(voba::Utils::random_string(6), 12, voba::Gender::male, "0987s54321", voba::ActiveStatus::active);
//	voba::Person p3 = voba::PersonFactory::create(voba::Utils::random_string(6), 12, voba::Gender::male, "0987s54321", voba::ActiveStatus::active);
//	voba::Person p4 = voba::PersonFactory::create(voba::Utils::random_string(6), 12, voba::Gender::male, "0987s54321", voba::ActiveStatus::active);
//	
//	voba::Team t(voba::Utils::random_string(3));
//	t.add_member(p1);
//	t.add_member(p2);
//	t.add_member(p3);
//	t.add_member(p4);
//	voba::UUID new_id = voba::UUID::random_uuid();
//	t.update_id(new_id);
//	
//	voba::MySQLConnector<voba::Team> t_connector;
//	t_connector.insert(t);
//	voba::Team t = voba::TeamFactory::select_by_id(voba::UUID::from_string("7c6dda5f-be96-49a0-90c4-49c0e8d708c7"));
//	std::cout << t.to_string() << std::endl;
//	std::vector<voba::Team> team_list = voba::TeamFactory::select_all();
//	for (unsigned int i = 0; i < team_list.size(); i++)
//	{
//		std::cout << team_list[i].to_string() << std::endl;
//	}
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
}

void voba::test_serverinfo()
{
	
}

void voba::test_util()
{
	
}

