#include "Person.h"

const string Person::CLASS_NAME = "Person";

// constructors
Person::Person(const string name, const unsigned int age, const Gender gender, const string phonenumber, const ActiveStatus status)
	: connector(TABLE_NAME)
	, logger(Person::CLASS_NAME)
{
	this->name = name;
	this->status = status;
	this->gender = gender;
	this->age = age;
	this->phonenumber = phonenumber;
	this->id = generate_sha1(to_string());
	this->init();
}

// setters
void Person::set_name(const string name)
{
	this->name = name;
	this->update("name", "'"+this->get_name()+"'");
}

void Person::set_age(const unsigned int age)
{
	this->age = age;
	this->update("age", std::to_string(this->get_age()));
}

void Person::set_gender(const Gender gender)
{
	this->gender = gender;
	this->update("gender", std::to_string(static_cast<int>(gender)));
}

void Person::set_phonenumber(const string phonenumber)
{
	this->phonenumber = phonenumber;
	this->update("phonenumber", "'"+this->get_phonenumber()+"'");
}

void Person::set_active_status(const ActiveStatus status)
{
	this->status = status;
	this->update("is_active", std::to_string(static_cast<int>(status)));
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
	return this->status;
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

// operators
// operators
const Person& Person::operator =(const Person& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	this->name = other.get_name();
	this->age = other.get_age();
	this->gender = other.get_gender();
	this->phonenumber = other.get_phonenumber();
	
	return *this;
}

const bool Person::operator ==(const Person& other) const
{
	bool re = false;
	if(this->to_string().compare(other.to_string()) == 0)
	{
		re = true;
	}
	return re;
}

const bool Person::operator !=(const Person& other) const
{
	return !(operator==(other));
}

ostream& operator <<(ostream& strm, const Person& other)
{
	strm << other.to_string();
	return strm;
}

// private
const string Person::TABLE_NAME = "persons";

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
		values += std::to_string(static_cast<int>(status));
		connector.insert(values);
	}
}

void Person::update(const string column_name, const string column_value)
{
	const string ori_id = this->id;
	this->id = generate_sha1(to_string());
	const string conditions = "ID = '"+ori_id+"'";
	const string new_id = "'"+this->id+"'";
	connector.update(column_name, column_value, conditions);
	connector.update("ID", this->id, conditions);
}
