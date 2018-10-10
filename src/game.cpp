#include <algorithm>
#include <iostream>
#include "game.h"

#include "common.h"
#include "people.h"
#include "datetime.h"

using namespace std;

//=====================/ Game class section /=====================//

int Game::game_count = 0;

// constructors
Game::Game(const Team team1, const Team team2)
:team1(team1), team2(team2)
{
	game_count++;
	is_timeset = false;
}

// setters
void Game::set_datetime(const DateTime datetime)
{
	this->datetime = datetime;
	is_timeset = true;
}

// getters
const Team Game::get_team1() const
{
	return this->team1;
}

const Team Game::get_team2() const
{
	return this->team2;
}

const DateTime Game::get_datetime() const
{
	if(is_timeset == false)
	{
		error("must set date and time first before use function \'get_datetime()\'");
	}
	return this->datetime;
}

const string Game::to_string() const
{
	string re;
	
	re += get_team1().get_name();
	re += " v.s ";
	re += get_team2().get_name();
	if(is_timeset == true)
	{
		re += " ";
		re += datetime.to_string();
	}
	
	return re;
}

const int Game::hashcode() const
{
	return std::hash<string>()(to_string());
}

// static
const int Game::count()
{
	return Game::game_count;
}

// operators
const Game& Game::operator =(const Game& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	this->team1 = other.get_team1();
	this->team2 = other.get_team2();
	if(is_timeset == false)
	{
		error("must set date and time first before use function \'operator=\'");
	}
	this->datetime = other.get_datetime();
	
	return *this;
}

const bool Game::operator ==(const Game& other) const
{
	if(is_timeset == false)
	{
		error("must set date and time first before use function \'operator==\'");
	}
	
	bool re = false;
	
	if(to_string() == other.to_string() && 
	   get_datetime() == other.get_datetime())
	{
		re = true;
	}
	
	return re;
}

const bool Game::operator !=(const Game& other) const
{
	return !(*this == other);
}

const bool Game::operator <(const Game& other) const
{
	if(is_timeset == false)
	{
		error("must set date and time first before use function \'operator<\'");
	}
	
	return get_datetime() < other.get_datetime();
}

const bool Game::operator >(const Game& other) const
{
	return (other < *this);
}

const bool Game::operator <=(const Game& other) const
{
	return !(*this > other);
}

const bool Game::operator >=(const Game& other) const
{
	return !(*this < other);
}

ostream& operator <<(ostream& strm, const Game& other)
{
	strm << other.to_string();
	return strm;
}


//====================/ Schedule class section /=====================//

// constructors
Schedule::Schedule(const DateTime start, const DateTime finish, const bool enable_four_section)
{
	if(finish <= start)
	{
		error("finish time must be later than start time");
	}
	this->start = start;
	this->finish = finish;
	this->four_section = enable_four_section;	// default is false
}

// setters
void Schedule::modify_exclude_week(const Week week)
{
	// for example, now exculde Wednesday and Sunday
	// if 'week' if Monday, add Monday to excludes
	// if 'week' if Sunday, remove Sunday from excludes
	if(std::find(excludes.begin(), excludes.end(), week) != excludes.end())
	{
		//cout << "find" << endl;
		excludes.erase(std::remove(excludes.begin(), excludes.end(), week), excludes.end());
	}
	else
	{
		//cout << "no find" << endl;
		excludes.push_back(week);
		std::sort(excludes.begin(), excludes.end());	// sort it
	}
	
	/*for(vector<Week>::iterator it = excludes.begin(); it != excludes.end(); it++)
	{
		cout << DAY_OF_WEEK[static_cast<int>(*it)] << " ";
	}
	cout << endl;*/
}

void Schedule::modify_teams(const Team team)
{
	if(std::find(teams.begin(), teams.end(), team) != teams.end())
	{
		// find it in the container
		// so delete it
		//cout << "find" << endl;
		teams.erase(std::remove(teams.begin(), teams.end(), team), teams.end());
	}
	else
	{
		// find no team in container
		// so add it to vector
		//cout << "no find" << endl;
		teams.push_back(team);
		std::sort(teams.begin(), teams.end());	// sort it
	}
	
	/*for(vector<Team>::iterator it = teams.begin(); it != teams.end(); it++)
	{
		cout << it->get_name() << " ";
	}
	cout << endl;*/
}

// getters
const DateTime Schedule::get_start() const
{
	// return the start time
	return this->start;
}

const DateTime Schedule::get_finish() const
{
	// return the finish time
	return this->finish;
}

// other functions
void Schedule::output_file(const string filename)
{
}

void Schedule::start_scheduling()
{
	vector<DateTime> times;
	for(DateTime current = get_start(); current <= get_finish(); current = current.next_section())
	{
		if(std::find(excludes.begin(), excludes.end(), current.get_week()) == excludes.end())
		{
			if(!(!four_section && current.get_hour() >= 23))
			{
				cout << current << endl;
				times.push_back(current);
			}
		}
	}
}
