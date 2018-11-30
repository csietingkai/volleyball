#include "Team.h"

// constructors
Team::Team(const string name)
	: Connectable(get_table_name(Team::CLASS_NAME))
	, logger(Team::CLASS_NAME)
{
	logger.trace("initializing "+Team::CLASS_NAME+" by normal constructor");
	
	this->name = name;
	this->personset.clear();
	this->id = generate_sha1(this->get_name());
	this->select();
}

Team::Team(const Team& other)
	: Connectable(get_table_name(Team::CLASS_NAME))
	, logger(Team::CLASS_NAME)
{
	logger.trace("initializing "+Team::CLASS_NAME+" by copy constructor");
	
	this->operator=(other);
}

// setters
void Team::set_name(const string name)
{
	this->name = name;
	this->update("name", "'"+this->get_name()+"'");
	this->personset.clear();
	this->select();
}

// getters
const string Team::get_id() const
{
	return this->id;
}

const string Team::get_name() const
{
	return this->name;
}

const Person& Team::get_member(const unsigned int index) const
{
	if (index >= this->size())
	{
		// throw error
	}
	return this->personset[index];
}

const string Team::get_prefer_week() const
{
	string ret = "";
	
	for (int i = 0; i < 7; i++)
	{
		if (prefer_week[i] == true) 
		{
			ret += "true";
		}
		else
		{
			ret += "false";
		}
		ret += ";";
	}
	
	// remove last ';'
	ret = ret.substr(0, ret.size()-1);
	
	return ret;
}

const string Team::get_prefer_time() const
{
	string ret = "";
	
	if (prefer_time[0] == true)
	{
		ret += GAME_TIME::FIRST_SECTION.to_string();
	}
	ret += ";";
	if (prefer_time[1] == true)
	{
		ret += GAME_TIME::SECOND_SECTION.to_string();
	}
	ret += ";";
	if (prefer_time[2] == true)
	{
		ret += GAME_TIME::THIRD_SECTION.to_string();
	}
	ret += ";";
	if (prefer_time[3] == true)
	{
		ret += GAME_TIME::FORTH_SECTION.to_string();
	}
	
	return ret;
}

const unsigned int Team::size() const
{
	return this->personset.size();
}

// other member function
void Team::add_member(const Person& member)
{
	logger.debug("add member '"+member.get_name()+"' to team '"+this->get_name()+"'");
	
	auto it = find(personset.begin(), personset.end(), member);
	if(it == personset.end())
	{
		personset.push_back(member);
		this->insert();
	}
	else 
	{
		logger.debug("member '"+member.get_name()+"' has ALREADY in team '"+this->get_name()+"'");
	}
}

void Team::remove_member(const Person& member)
{
	logger.debug("remove member '"+member.get_name()+"' from team '"+this->get_name()+"'");
	
	auto it = find(personset.begin(), personset.end(), member);
	if(it != personset.end())
	{
		this->remove(it->get_id());
		personset.erase(it);
	}
	else 
	{
		logger.debug("member '"+member.get_name()+"' is NOT in team '"+this->get_name()+"'");
	}
}

void Team::add_prefer_week(const Week week)
{
	prefer_week[static_cast<int>(week)] = false;
}

void Team::remove_prefer_week(const Week week)
{
	prefer_week[static_cast<int>(week)] = true;
}

void Team::add_prefer_time(const Time time)
{
	if (GAME_TIME::FIRST_SECTION == time)
	{
		prefer_time[0] = true;
	}
	else if (GAME_TIME::SECOND_SECTION == time)
	{
		prefer_time[1] = true;
	}
	else if (GAME_TIME::THIRD_SECTION == time)
	{
		prefer_time[2] = true;
	}
	else if (GAME_TIME::FORTH_SECTION == time)
	{
		prefer_time[3] = true;
	}
	else
	{
		logger.error("time '"+time.to_string()+"' is NOT CORRECT; use 'GAME_TIME'");
	}
}

void Team::remove_prefer_time(const Time time)
{
	if (GAME_TIME::FIRST_SECTION == time)
	{
		prefer_time[0] = false;
	}
	else if (GAME_TIME::SECOND_SECTION == time)
	{
		prefer_time[1] = false;
	}
	else if (GAME_TIME::THIRD_SECTION == time)
	{
		prefer_time[2] = false;
	}
	else if (GAME_TIME::FORTH_SECTION == time)
	{
		prefer_time[3] = false;
	}
	else
	{
		logger.error("time '"+time.to_string()+"' is NOT CORRECT; use 'GAME_TIME'");
	}
}

// operators
const Team& Team::operator =(const Team& other)
{
	this->name = other.get_name();
	this->personset.clear();
	this->id = generate_sha1(this->get_name());
	this->select();
	return *this;
}

const bool Team::operator ==(const Team& other) const
{
	return this->get_name() == other.get_name();
}

const bool Team::operator !=(const Team& other) const
{
	return !this->operator==(other);
}

const Person& Team:: operator [](const unsigned int index) const
{
	return this->get_member(index);
}

// protected
void Team::select()
{
	logger.debug("select in '"+Team::CLASS_NAME+"'");
	
	string column_name = "*";
	string conditions = "ID = '"+this->get_id()+"'";
	ResultSet* result_set = connector.select(column_name, conditions);
	ResultSetMetaData *res_meta = result_set->getMetaData();
	int columns = res_meta->getColumnCount();
	while (columns > 0 && result_set->next())
	{
		// id -> 1
		// team name -> 2
		// member id -> 3
		Person p(result_set->getString(3));
		personset.push_back(p);
		// prefer week -> 4
		// prefer time -> 5
	}
}

void Team::insert()
{
	logger.debug("insert in '"+Team::CLASS_NAME+"'");
	
	Person p = personset[this->size()-1];
	string values = "'"+this->get_id()+"',";
	values += "'"+this->get_name()+"',";
	values += "'"+p.get_id()+"',";
	values += "'"+this->get_prefer_week()+"',";
	values += "'"+this->get_prefer_time()+"'";
	connector.insert(values);
}

void Team::update(const string column_name, const string column_value)
{
	logger.debug("update in '"+Team::CLASS_NAME+"'");
	
	const string ori_id = this->id;
	this->id = generate_sha1(this->get_name());
	const string conditions = "ID = '"+ori_id+"'";
	const string new_id = "'"+this->id+"'";
	connector.update(column_name, column_value, conditions);
	connector.update("ID", new_id, conditions);
}

void Team::remove(const string member_id)
{
	logger.debug("delete in '"+Team::CLASS_NAME+"'");
	
	const string conditions = "MEMBER_ID = '"+member_id+"'";
	connector.remove(conditions);
}

// private
const string Team::CLASS_NAME = "Team";
