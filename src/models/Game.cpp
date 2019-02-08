#include "Game.h"

const std::string voba::Game::CLASS_NAME = "Game";

// constructor
voba::Game::Game(const voba::Team team1, const voba::Team team2)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
{
	
}

voba::Game::Game(const voba::Team team1, const voba::Team team2, const voba::Person judge)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
	, judge(judge)
{
	
}

voba::Game::Game(const voba::Team team1, const voba::Team team2, const voba::DateTime game_time)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
	, game_time(game_time)
{
	
}

voba::Game::Game(const voba::Team team1, const voba::Team team2, const voba::Person judge, const voba::DateTime game_time)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
	, judge(judge)
	, game_time(game_time)
{
	
}

voba::Game::Game(const voba::Game& other)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(other.get_team1())
	, team2(other.get_team2())
{
	
}

const std::string voba::Game::to_string() const
{
	std::string ret = "";
	
	ret += this->team1.get_name();
	ret += " vs ";
	ret += this->team2.get_name();
	ret += ", judge by: ";
	ret += this->judge.get_name();
	ret += ", game time: ";
	ret += this->game_time.to_string();
	
	return ret;
}

const voba::Game& voba::Game::operator =(const voba::Game& other)
{
	if (this == &other)
	{
		return *this;
	}
	
	this->team1 = other.get_team1();
	this->team2 = other.get_team2();
	this->judge = other.get_judge();
	this->game_time = other.get_game_time();
	
	return *this;
}

const bool voba::Game::operator ==(const voba::Game& other)
{
	bool ret = true;
	
	ret = ret && (this->team1 == other.get_team1());
	ret = ret && (this->team2 == other.get_team2());
	ret = ret && (this->judge == other.get_judge());
	ret = ret && (this->game_time == other.get_game_time());
	
	return ret;
}

