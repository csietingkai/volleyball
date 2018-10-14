#include "people.h"

// constructors
Person::Person(const string name, const unsigned int age, const Gender is_male, const string phonenumber, const ActiveStatus active)
	: name(name)
	, active(active)
	, gender(is_male)
	, age(age)
	, phonenumber(phonenumber)
	, connector("htk103u_volleyball", "persons")
{
	this->id = generate_sha1(to_string());
	string values = "";
	values += "'";
	values += id;
	values += "'";
	values += ",";
	values += "'";
	values += name;
	values += "'";
	values += ",";
	values += std::to_string(age);
	values += ",";
	values += std::to_string(static_cast<int>(gender));
	values += ",";
	values += "'";
	values += phonenumber;
	values += "'";
	values += ",";
	values += std::to_string(static_cast<int>(active));
	connector.insert(values);
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

const string Person::to_string() const 
{
	// to_string() function
	// format: name, age, [male|female], phone number
	string re = get_name() + "," + std::to_string(get_age()) + "," + (get_gender() == Gender::male ? "male" : "female") + "," + get_phonenumber();
	return re;
}

const int Person::hashcode() const
{
	// according to 'to_string()' function
	// generate hashcode
	return std::hash<std::string>()(to_string());
}
