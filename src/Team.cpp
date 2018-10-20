#include "Team.h"

// constructors
Team::Team(const string name)
	: connector(TABLE_NAME)
	, logger(CLASS_NAME)
{
	this->name = name;
	this->personset.clear();
	
	this->id = generate_sha1(this->get_name());
	this->insert();
}

// getters
const string Team::get_name() const
{
	return this->name;
}

const Person& Team::get_member(const unsigned int index) const
{
	return this->personset[index];
}

// other member function
void Team::add_member(const Person& member)
{
	
}

void Team::remove_member(const Person& member)
{
	
}

// protected
void Team::insert()
{
}

void Team::update(const string column_name, const string column_value)
{
}

// private
const string Team::TABLE_NAME = "teams";

const string Team::CLASS_NAME = "Team";
