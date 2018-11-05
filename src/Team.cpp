#include "Team.h"

// constructors
Team::Team(const string name)
	: Connectable(get_table_name(Team::CLASS_NAME))
	, logger(Team::CLASS_NAME)
{
	this->name = name;
	this->personset.clear();
	this->id = generate_sha1(this->get_name());
	this->select();
}

Team::Team(const Team& other)
	: Connectable(get_table_name(Team::CLASS_NAME))
	, logger(Team::CLASS_NAME)
{
	this->name = other.get_name();
	this->personset.clear();
	this->id = generate_sha1(this->get_name());
	this->select();
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

// operators
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
	string column_name = "member_id";
	string conditions = "ID = '"+this->get_id()+"'";
	ResultSet* result_set = connector.select(column_name, conditions);
	ResultSetMetaData *res_meta = result_set->getMetaData();
	int columns = res_meta->getColumnCount();
	while (columns > 0 && result_set->next())
	{
		Person p(result_set->getString(1));
		personset.push_back(p);
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
	const string ori_id = this->id;
	this->id = generate_sha1(this->get_name());
	const string conditions = "ID = '"+ori_id+"'";
	const string new_id = "'"+this->id+"'";
	connector.update(column_name, column_value, conditions);
	connector.update("ID", new_id, conditions);
}

void Team::remove(const string member_id)
{
	const string conditions = "MEMBER_ID = '"+member_id+"'";
	connector.remove(conditions);
}

// private
const string Team::CLASS_NAME = "Team";
