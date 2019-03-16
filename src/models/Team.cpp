#include "Team.h"

const std::string voba::Team::CLASS_NAME = "Team";

// constructor
voba::Team::Team(const std::string name)
	: Logable(voba::Team::CLASS_NAME)
{
	// set name
	// clear team member set
	// initialize week and time as full ok
	this->name = name;
	this->personset.clear();
	this->init_prefer_week();
	this->init_prefer_time();
}

voba::Team::Team(const Team& other)
	: Logable(voba::Team::CLASS_NAME)
{
	// call assign operator for copy constructor
	this->operator=(other);
}

// getters & setters
void voba::Team::set_name(const std::string name)
{
	// set name value
	this->name = name;
}

const std::string voba::Team::get_name() const
{
	// get name value
	return this->name;
}

const voba::Person& voba::Team::get_member(const unsigned int index) const
{
	// get member by index
	return this->personset[index];
}

const std::string voba::Team::get_prefer_week() const
{
	// week to int to string
	std::string ret = "";
	
	for (std::set<voba::Week>::iterator it = this->prefer_week.begin(); it != this->prefer_week.end(); it++)
	{
		//std::cout << voba::DAY_OF_WEEK[static_cast<int>(*it)] << std::endl;
		ret += std::to_string(static_cast<int>(*it));
		ret += ";";
	}
	
	ret = ret.substr(0, ret.length()-1);
	
	return ret;
}

const std::string voba::Team::get_prefer_time() const
{
	// time to string
	std::string ret = "";
	
	for (std::set<voba::Time>::iterator it = this->prefer_time.begin(); it != this->prefer_time.end(); it++)
	{
		ret += it->to_string();
		ret += ";";
	}
	
	ret = ret.substr(0, ret.length()-1);
	
	return ret;
}

const unsigned int voba::Team::size() const
{
	// return size of person set
	return this->personset.size();
}

const std::string voba::Team::to_string() const
{
	// full info to string
	std::string ret = "name: " + this->get_name();
	ret += "\n";
	ret += "size: " + std::to_string(this->size());
	ret += "\n";
	ret += "members: ";
	for (unsigned int i = 0; i < this->size(); i++)
	{
		ret += this->personset[i].get_name() + ", ";
	}
	ret += "\n";
	ret += "prefer_week: " + this->get_prefer_week();
	ret += "\n";
	ret += "prefer_time: " + this->get_prefer_time();
	return ret;
}

void voba::Team::add_member(const voba::Person& member)
{
	// add member if not exist in member set
	//logger.debug("add member '"+member.get_name()+"' to team '"+this->get_name()+"'");
	
	auto it = find(this->personset.begin(), this->personset.end(), member);
	if(it == this->personset.end())
	{
		this->personset.push_back(member);
	}
	else 
	{
		//logger.debug("member '"+member.get_name()+"' has ALREADY in team '"+this->get_name()+"'");
	}
}

void voba::Team::remove_member(const voba::Person& member)
{
	// remove member if exist in member set
	//logger.debug("remove member '"+member.get_name()+"' from team '"+this->get_name()+"'");
	
	auto it = find(this->personset.begin(), this->personset.end(), member);
	if(it != this->personset.end())
	{
		this->personset.erase(it);
	}
	else 
	{
		//logger.debug("member '"+member.get_name()+"' is NOT in team '"+this->get_name()+"'");
	}
}

void voba::Team::add_prefer_week(const voba::Week week)
{
	// add week day into prefer week set
	this->prefer_week.insert(week);
}

void voba::Team::remove_prefer_week(const voba::Week week)
{
	// remove week day from prefer week set
	this->prefer_week.erase(week);
}

void voba::Team::add_prefer_time(const voba::Time time)
{
	// add time into prefer time 
	this->prefer_time.insert(time);
}

void voba::Team::remove_prefer_time(const voba::Time time)
{
	// remove time from prefer time 
	this->prefer_time.erase(time);
}

// operators
const voba::Team& voba::Team::operator =(const voba::Team& other)
{
	if (this == &other)
	{
		return *this;
	}
	
	this->name = other.get_name();
	this->personset.clear();
	for (unsigned int i = 0; i < other.size(); i++)
	{
		this->add_member(other.get_member(i));
	}
	
	std::string prefer_week = other.get_prefer_week();
	std::vector<std::string> weeks = voba::Utils::split(prefer_week, voba::Team::PREFER_WEEK_SEPERATOR);
	for (auto it = weeks.begin(); it != weeks.end(); it++)
	{
		this->add_prefer_week(static_cast<voba::Week>(std::stoi(*it)));
	}
	
	std::string prefer_time = other.get_prefer_time();
	std::vector<std::string> times = voba::Utils::split(prefer_time, voba::Team::PREFER_TIME_SEPERATOR);
	for (auto it = times.begin(); it != times.end(); it++)
	{
		std::vector<std::string> time_vars = voba::Utils::split(*it, voba::Time::TIME_STRING_SEPERATOR);
		int h = std::stoi(time_vars[0]);
		int m = std::stoi(time_vars[1]);
		int s = std::stoi(time_vars[2]);
		voba::Time time(h, m, s);
		this->add_prefer_time(static_cast<voba::Time>(time));
	}
	this->update_id(other.get_id());
	
	return *this;
}

const bool voba::Team::operator ==(const voba::Team& other)
{
	bool ret = true;
	
	ret = ret && (this->get_name().compare(other.get_name()) == 0);
	ret = ret && (this->size() == other.size());
	if (ret)
	{
		for (unsigned int i = 0; i < this->size(); i++)
		{
			ret = ret && (this->personset[i] == other.get_member(i));
		}
	}
	ret = ret && (this->get_prefer_week().compare(other.get_prefer_week()) == 0);
	ret = ret && (this->get_prefer_time().compare(other.get_prefer_time()) == 0);
	
	return ret;
}

const bool voba::Team::operator !=(const voba::Team& other)
{
	return !this->operator==(other);
}

const voba::Person& voba::Team::operator [](const unsigned int index)
{
	return this->get_member(index);
}

std::ostream& operator <<(std::ostream& strm, const voba::Team& other)
{
	strm << other.to_string();
	return strm;
}

// private
void voba::Team::init_prefer_week()
{
	// default is whole week available
	this->prefer_week.insert(Week::SUNDAY);
	this->prefer_week.insert(Week::MONDAY);
	this->prefer_week.insert(Week::TUESDAY);
	this->prefer_week.insert(Week::WEDNESDAY);
	this->prefer_week.insert(Week::THURSDAY);
	this->prefer_week.insert(Week::FRIDAY);
	this->prefer_week.insert(Week::SATURDAY);
}

void voba::Team::init_prefer_time()
{
	// default is whole night available
	this->prefer_time.insert(voba::GAME_TIME::FIRST_SECTION);
	this->prefer_time.insert(voba::GAME_TIME::SECOND_SECTION);
	this->prefer_time.insert(voba::GAME_TIME::THIRD_SECTION);
	this->prefer_time.insert(voba::GAME_TIME::FORTH_SECTION);
}
