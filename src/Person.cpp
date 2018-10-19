#include "Person.h"

// constructors
Person::Person(const string name, const unsigned int age, const Gender is_male, const string phonenumber, const ActiveStatus active)
	: connector(table_name)
{
	this->id = generate_sha1(to_string());
	this->name = name;
	this->active = active;
	this->gender = gender;
	this->age = age;
	this->phonenumber = phonenumber;
	this->init();
	//this->connector.update("age", "22", "");
}

// getters
const string Person::get_name() const
{
	return this->name;
}

const int Person::get_age() const
{
	return this->age;
}

const Gender Person::get_gender() const 
{
	return this->gender;
}

const string Person::get_phonenumber() const
{
	return this->phonenumber;
}

const ActiveStatus Person::get_active_status() const
{
	return this->active;
}

const string Person::to_string() const 
{
	// to_string() function
	// format: name, age, [male|female], phone number
	string re = get_name() + ",";
	re += std::to_string(get_age()) + ",";
	re += get_gender() == Gender::male ? "male" : "female";
	re += ",";
	re += get_phonenumber() + ",";
	re += get_active_status() == ActiveStatus::active ? "active" : "inactive";
	return re;
}

const string Person::hashcode() const
{
	// generate hashcode with full info
	return this->id;
}

void Person::init()
{
	sql::ResultSet *result_set = connector.select("ID", "ID = '" + id + "'");
	if (0 == result_set->rowsCount())
	{
		string values = "'";
		values += id;
		values += "','";
		values += name + "',";
		values += std::to_string(age) + ",";
		values += std::to_string(static_cast<int>(gender)) + ",'";
		values += phonenumber + "',";
		values += std::to_string(static_cast<int>(active));
		connector.insert(values);
	}
}
