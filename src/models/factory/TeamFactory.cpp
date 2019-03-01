#include "TeamFactory.h"

const std::string voba::TeamFactory::CLASS_NAME = "TeamFactory";
voba::MySQLConnector<voba::Team> voba::TeamFactory::t_connector;
voba::MySQLConnector<voba::Game> voba::TeamFactory::g_connector;
voba::Logger voba::TeamFactory::logger(voba::TeamFactory::CLASS_NAME);

const std::vector<voba::Team> voba::TeamFactory::select_all()
{
	/*voba::TeamFactory::logger.debug("selecting all team from database");
	
	std::vector<voba::Team> all;
	
	voba::UUID id;
	std::string name;
	
	sql::ResultSet* result_set = voba::TeamFactory::t_connector.select();
	while (result_set->next())
	{
		std::cout << result_set->getString(1) << std::endl;
		std::cout << result_set->getString(2) << std::endl;
		std::cout << result_set->getString(3) << std::endl;
		std::cout << result_set->getString(4) << std::endl;
		std::cout << result_set->getString(5) << std::endl << std::endl;
	}
	
	return all;*/
}

const voba::Team& voba::TeamFactory::select_by_id(const voba::UUID id)
{
	/*voba::TeamFactory::logger.debug("selecting a team from database");
	
	voba::Team *t;
	
	voba::UUID id;
	std::string name;
	
	sql::ResultSet* result_set = voba::TeamFactory::t_connector.select();
	while (result_set->next())
	{
		std::cout << result_set->getString(1) << std::endl;
		std::cout << result_set->getString(2) << std::endl;
		std::cout << result_set->getString(3) << std::endl;
		std::cout << result_set->getString(4) << std::endl;
		std::cout << result_set->getString(5) << std::endl << std::endl;
	}
	
	return *t;*/
}

const voba::Team& voba::TeamFactory::create(const std::string name)
{
	voba::TeamFactory::logger.debug("Creating a team");
	
	voba::Team *t = new Team(name);
	return *t;
}

const voba::Team& voba::TeamFactory::insert_member(voba::Team& team, const voba::Person& member)
{
	
}

const voba::Team& voba::TeamFactory::delete_member(voba::Team& team, const voba::Person& member)
{
	voba::Column tid("id", voba::ColumnType::UUID);
	tid.set_value(team.get_id().to_string());
	voba::Column mid("member_id", voba::ColumnType::UUID);
}

const bool voba::TeamFactory::update(const voba::Team new_team)
{
	int result = 0;
	
	result += voba::TeamFactory::t_connector.update(new_team);
	
	return true;
}

const bool voba::TeamFactory::remove(const voba::Team team)
{
	int result = 0;
	
	voba::UUID id = team.get_id();
	voba::Column team_1_id("team_1_id", voba::ColumnType::UUID);
	team_1_id.set_value(id.to_string());
	voba::Column team_2_id("team_2_id", voba::ColumnType::UUID);
	team_2_id.set_value(id.to_string());
	result += voba::TeamFactory::t_connector.remove(team);
	result += voba::TeamFactory::g_connector.remove(team_1_id);
	result += voba::TeamFactory::g_connector.remove(team_2_id);
	
	return true;
}

