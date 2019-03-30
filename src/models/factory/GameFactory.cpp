#include "GameFactory.h"

const std::string voba::GameFactory::CLASS_NAME = "GameFactory";
voba::MySQLConnector<voba::Game> voba::GameFactory::g_connector;
voba::Logger voba::GameFactory::logger(voba::GameFactory::CLASS_NAME);

const std::vector<voba::Game> voba::GameFactory::select_all()
{
	std::vector<voba::Game> all;
	
	voba::UUID id;
	voba::UUID team1_id;
	voba::UUID team2_id;
	voba::UUID judge_id;
	voba::UUID empty_UUID;
	voba::DateTime game_time;
	voba::DateTime empty_datetime;
	
	sql::ResultSet* result_set = voba::GameFactory::g_connector.select();
	while (result_set->next())
	{
		// 1 -> id
		id = voba::UUID::from_string(result_set->getString(1));
		// 2 -> team1_id
		team1_id = voba::UUID::from_string(result_set->getString(2));
		// 3 -> team2_id
		team2_id = voba::UUID::from_string(result_set->getString(3));
		// 4 -> judge_id
		judge_id = voba::UUID::from_string(result_set->getString(4));
		// 5 -> game_time
		game_time = *(new voba::DateTime(result_set->getString(5)));
		
		voba::Team t1 = voba::TeamFactory::select_by_id(team1_id);
		voba::Team t2 = voba::TeamFactory::select_by_id(team2_id);
		voba::Game g(t1, t2);
		g.update_id(id);
		if (empty_UUID != judge_id) 
		{
			voba::Person p = voba::PersonFactory::select_by_id(judge_id);
			g.set_judge(p);
		}
		
		if (empty_datetime != game_time) 
		{
			g.set_game_time(game_time);
		}
		
		all.push_back(g);
	}
	
	return all;
}

const voba::Game& voba::GameFactory::select_by_id(const voba::UUID id)
{
	voba::UUID team1_id;
	voba::UUID team2_id;
	voba::UUID judge_id;
	voba::UUID empty_UUID;
	voba::DateTime game_time;
	voba::DateTime empty_datetime;
	
	sql::ResultSet* result_set = voba::GameFactory::g_connector.select(id);
	while (result_set->next())
	{
		// 2 -> team1_id
		team1_id = voba::UUID::from_string(result_set->getString(2));
		// 3 -> team2_id
		team2_id = voba::UUID::from_string(result_set->getString(3));
		// 4 -> judge_id
		judge_id = voba::UUID::from_string(result_set->getString(4));
		// 5 -> game_time
		game_time = *(new voba::DateTime(result_set->getString(5)));
	}
	
	voba::Team t1 = voba::TeamFactory::select_by_id(team1_id);
	voba::Team t2 = voba::TeamFactory::select_by_id(team2_id);
	voba::Game *g = new voba::Game(t1, t2);
	g->update_id(id);
	if (empty_UUID != judge_id) 
	{
		voba::Person p = voba::PersonFactory::select_by_id(judge_id);
		g->set_judge(p);
	}
	
	if (empty_datetime != game_time) 
	{
		g->set_game_time(game_time);
	}
	
	return *g;
}

const voba::Game& voba::GameFactory::create(const voba::Team team1, const voba::Team team2)
{
	voba::Game *g = new voba::Game(team1, team2);
	g->update_id(voba::UUID::random_uuid());
	voba::GameFactory::g_connector.insert(*g);
	return *g;
}

const voba::Game& voba::GameFactory::create(const voba::Team team1, const voba::Team team2, const voba::Person judge)
{
	voba::Game *g = new voba::Game(team1, team2, judge);
	g->update_id(voba::UUID::random_uuid());
	voba::GameFactory::g_connector.insert(*g);
	return *g;
}

const voba::Game& voba::GameFactory::create(const voba::Team team1, const voba::Team team2, const voba::DateTime game_time)
{
	voba::Game *g = new voba::Game(team1, team2, game_time);
	g->update_id(voba::UUID::random_uuid());
	voba::GameFactory::g_connector.insert(*g);
	return *g;
}

const voba::Game& voba::GameFactory::create(const voba::Team team1, const voba::Team team2, const voba::Person judge, const voba::DateTime game_time)
{
	voba::Game *g = new voba::Game(team1, team2, judge, game_time);
	g->update_id(voba::UUID::random_uuid());
	voba::GameFactory::g_connector.insert(*g);
	return *g;
}

const bool voba::GameFactory::update(voba::Game& new_game)
{
	int result = voba::GameFactory::g_connector.update(new_game);
	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool voba::GameFactory::remove(voba::Game& game)
{
	int result = 0;
	result += voba::GameFactory::g_connector.remove(game);
	
	if (result >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
