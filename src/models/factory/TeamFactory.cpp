#include "TeamFactory.h"

const std::string voba::TeamFactory::CLASS_NAME = "TeamFactory";
voba::MySQLConnector<voba::Team> voba::TeamFactory::t_connector;
voba::MySQLConnector<voba::Game> voba::TeamFactory::g_connector;
voba::Logger voba::TeamFactory::logger(voba::TeamFactory::CLASS_NAME);

const std::vector<voba::Team> voba::TeamFactory::select_all()
{
	voba::TeamFactory::logger.debug("selecting all team from database");
	
	std::vector<voba::Team> all;
	
	voba::UUID id;
	std::string name;
	
	voba::SqlCommandBuilder builder;
	voba::Column distinct_id("distinct(id)");
	// TODO get table from MySQLConnector
	voba::ServerInfo info;
	voba::Table team_table = info.get_table(voba::Team::CLASS_NAME);
	std::string query = builder.select(distinct_id).from(team_table).to_string();
	sql::ResultSet* result_set = voba::TeamFactory::t_connector.execute_query(query);
	while (result_set->next())
	{
		all.push_back(voba::TeamFactory::select_by_id(voba::UUID::from_string(result_set->getString(1))));
	}
	
	return all;
}

const voba::Team& voba::TeamFactory::select_by_id(const voba::UUID id)
{
	voba::TeamFactory::logger.debug("selecting a team from database");
	
	voba::Team *t = nullptr;
	
	sql::ResultSet* result_set = voba::TeamFactory::t_connector.select(id);
	if (result_set->next())
	{
		// team name
		t = new Team(result_set->getString(2));
		t->update_id(id);
		
		// add member
		voba::UUID member_id = voba::UUID::from_string(result_set->getString(3));
		voba::Person member = voba::PersonFactory::select_by_id(member_id);
		t->add_member(member);
		
		// handle prefer week
		std::vector<std::string> weeks = voba::Utils::split(result_set->getString(4), voba::Team::PREFER_WEEK_SEPERATOR);
		for (unsigned int i = 0; i < weeks.size(); i++)
		{
			t->add_prefer_week(static_cast<voba::Week>(std::stoi(weeks[i])));
		}
		
		// handle prefer time
		std::vector<std::string> times = voba::Utils::split(result_set->getString(5), voba::Team::PREFER_WEEK_SEPERATOR);
	}
	while (result_set->next())
	{
		// add member
		voba::UUID member_id = voba::UUID::from_string(result_set->getString(3));
		voba::Person member = voba::PersonFactory::select_by_id(member_id);
		t->add_member(member);
	}
	
	return *t;
}

const voba::Team& voba::TeamFactory::create(const std::string name)
{
	voba::TeamFactory::logger.debug("Creating a team");
	
	voba::Team *t = new Team(name);
	return *t;
}

const voba::Team& voba::TeamFactory::insert_member(voba::Team& team, const voba::Person& member)
{
	team.add_member(member);
	
	return team;
}

const voba::Team& voba::TeamFactory::delete_member(voba::Team& team, const voba::Person& member)
{
	team.remove_member(member);
	
	voba::Column tid("id", voba::ColumnType::UUID, team.get_id().to_string());
	voba::Column mid("member_id", voba::ColumnType::UUID);
	std::list<voba::Column> where_conditions = { tid, mid };
	voba::TeamFactory::t_connector.remove(where_conditions);
	
	return team;
}

const bool voba::TeamFactory::update(voba::Team& new_team)
{
	// update team's attributes, like prefer times, team name, etc
	int result = 0;
	
	result += voba::TeamFactory::t_connector.update(new_team);
	
	return true;
}

const bool voba::TeamFactory::remove(voba::Team& team)
{
	// remove team from table 'Teams' and 'Games' 
	int result = 0;
	
	voba::Column team_1_id("team_1_id", voba::ColumnType::UUID, team.get_id().to_string());
	voba::Column team_2_id("team_2_id", voba::ColumnType::UUID, team.get_id().to_string());
	result += voba::TeamFactory::t_connector.remove(team);
	result += voba::TeamFactory::g_connector.remove(team_1_id);
	result += voba::TeamFactory::g_connector.remove(team_2_id);
	
	return true;
}

