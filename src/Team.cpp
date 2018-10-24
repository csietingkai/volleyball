#include "Team.h"

// constructors
Team::Team(const string name)
	: connector(TABLE_NAME)
	, logger(CLASS_NAME)
{
	this->name = name;
	this->personset.clear();
	this->id = generate_sha1(this->get_name());
	this->select();
}

// setters
void Team::set_name(const string name)
{
	this->name = name;
	this->update("name", "'"+this->get_name()+"'");
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

const unsigned int Team::size() const
{
	return this->personset.size();
}

// other member function
void Team::add_member(const Person& member)
{
	auto it = find(personset.begin(), personset.end(), member);
	if(it == personset.end())
	{
		//cout << "no find" << endl;
		personset.push_back(member);
		this->insert();
	}
	else 
	{
		//cout << "find" << endl;
	}
}

void Team::remove_member(const Person& member)
{
	auto it = find(personset.begin(), personset.end(), member);
	if(it != personset.end())
	{
		//cout << "find" << endl;
		this->remove(it->get_id());
		personset.erase(it);
	}
	else 
	{
		//cout << "no find" << endl;
	}
}

// protected
void Team::select()
{
	string column_name = "member_id";
	string conditions = "ID = '"+this->get_id()+"'";
	ResultSet* result_set = connector.select(column_name, conditions);
	ResultSetMetaData *res_meta = result_set->getMetaData();
	int columns = res_meta->getColumnCount();
	while (columns > 0 && result_set->next())
	{
		Person p(result_set->getString(1));
		this->add_member(p);
	}
}

void Team::insert()
{
	Person p = personset[this->size()-1];
	string values = "'"+this->get_id()+"',";
	values += "'"+this->get_name()+"',";
	values += "'"+p.get_id()+"'";
	connector.insert(values);
}

void Team::update(const string column_name, const string column_value)
{
}

void Team::remove(const string member_id)
{
	
}

// private
const string Team::TABLE_NAME = "teams";

const string Team::CLASS_NAME = "Team";
