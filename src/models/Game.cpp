#include "Game.h"

const std::string voba::Game::CLASS_NAME = "Game";

// constructor
voba::Game::Game(const voba::Team team1, const voba::Team team2)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
{
	// do nothing
}

voba::Game::Game(const voba::Team team1, const voba::Team team2, const voba::Person judge)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
	, judge(judge)
{
	// do nothing
}

voba::Game::Game(const voba::Team team1, const voba::Team team2, const voba::DateTime game_time)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
	, game_time(game_time)
{
	// do nothing
}

voba::Game::Game(const voba::Team team1, const voba::Team team2, const voba::Person judge, const voba::DateTime game_time)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
	, judge(judge)
	, game_time(game_time)
{
	// do nothing
}

voba::Game::Game(const voba::Game& other)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(other.get_team1())
	, team2(other.get_team2())
{
	// do nothing
}

// getters & setters
void voba::Game::set_team1(const voba::Team team1)
{
	// set team1 value
	this->team1 = team1;
}

void voba::Game::set_team2(const voba::Team team2)
{
	// set team2 value
	this->team2 = team2;
}

void voba::Game::set_judge(const voba::Person judge)
{
	// set judge value
	this->judge = judge;
}

void voba::Game::set_game_time(const voba::DateTime game_time)
{
	// set game time value
	this->game_time = game_time;
}

const voba::Team voba::Game::get_team1() const
{
	// return team1 value
	return this->team1;
}

const voba::Team voba::Game::get_team2() const 
{
	// return team2 value
	return this->team2;
}

const voba::Person voba::Game::get_judge() const
{
	// return judge value
	return this->judge;
}

const voba::DateTime voba::Game::get_game_time() const
{
	// return game time value
	return this->game_time;
}

const std::string voba::Game::to_string() const
{
	// full info to string
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
	this->update_id(other.get_id());
	
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

const bool voba::Game::operator !=(const voba::Game& other)
{
	return !this->operator==(other);
}

std::ostream& operator <<(std::ostream& strm, const voba::Game& other)
{
	strm << other.to_string();
	return strm;
}
