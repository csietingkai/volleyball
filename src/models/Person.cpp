#include "Person.h"

const std::string voba::Person::CLASS_NAME = "Person";

voba::Person::Person()
	: voba::Logable(voba::Person::CLASS_NAME)
{
	// do nothing
}

voba::Person::Person(const std::string name, const unsigned int age, const Gender gender, const std::string phonenumber, const ActiveStatus status)
	: voba::Logable(voba::Person::CLASS_NAME)
{
	// set parameters as member variables
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->phonenumber = phonenumber;
	this->status = status;
}

voba::Person::Person(const voba::Person& other)
	: voba::Logable(voba::Person::CLASS_NAME)
{
	// call assign operator for copy constructor
	this->operator=(other);
}

// getters & setters
void voba::Person::set_name(const std::string name)
{
	// set name value
	this->name = name;
}

void voba::Person::set_age(const unsigned int age)
{
	// set age value
	this->age = age;
}

void voba::Person::set_gender(const Gender gender)
{
	// set gender value
	this->gender = gender;
}

void voba::Person::set_phonenumber(const std::string phonenumber)
{
	// set phonenumber value
	this->phonenumber = phonenumber;
}

void voba::Person::set_active_status(const voba::ActiveStatus status)
{
	// set active status value
	this->status = status;
}

const std::string voba::Person::get_name() const
{
	// return name value
	return this->name;
}

const int voba::Person::get_age() const
{
	// return age value
	return this->age;
}

const voba::Gender voba::Person::get_gender() const
{
	// return gender value
	return this->gender;
}

const std::string voba::Person::get_phonenumber() const
{
	// return phonenumber value
	return this->phonenumber;
}

const voba::ActiveStatus voba::Person::get_active_status() const
{
	// return active status value
	return this->status;
}

const std::string voba::Person::to_string() const
{
	// format: name, age, [male|female], phone number
	std::string re = this->get_name() + ",";
	re += std::to_string(this->get_age()) + ",";
	re += this->get_gender() == Gender::male ? "male" : "female";
	re += ",";
	re += this->get_phonenumber() + ",";
	re += this->get_active_status() == ActiveStatus::active ? "active" : "inactive";
	return re;
}
	
// operators
const voba::Person& voba::Person::operator =(const voba::Person& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	this->name = other.get_name();
	this->age = other.get_age();
	this->gender = other.get_gender();
	this->phonenumber = other.get_phonenumber();
	this->status = other.get_active_status();
	this->update_id(other.get_id());
	
	return *this;
}

const bool voba::Person::operator ==(const voba::Person& other)
{
	bool re = true;
	re = re && (this->get_name().compare(other.get_name()) == 0);
	re = re && (this->get_age() == other.get_age());
	re = re && (this->get_gender() == other.get_gender());
	re = re && (this->get_phonenumber().compare(other.get_phonenumber()) == 0);
	re = re && (this->get_active_status() == other.get_active_status());
	return re;
}

const bool voba::Person::operator !=(const voba::Person& other)
{
	return !this->operator==(other);
}

std::ostream& operator <<(std::ostream& strm, const voba::Person& other)
{
	strm << other.to_string(); 
	return strm;
};
