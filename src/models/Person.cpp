#include "Person.h"

const std::string voba::Person::CLASS_NAME = "Person";

// constructor
voba::Person::Person()
	: voba::Logable(voba::Person::CLASS_NAME)
{
	
}

voba::Person::Person(const std::string name, const unsigned int age, const Gender gender, const std::string phonenumber, const ActiveStatus status)
	: voba::Logable(voba::Person::CLASS_NAME)
{
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->phonenumber = phonenumber;
	this->status = status;
}

voba::Person::Person(const voba::Person& other)
	: voba::Logable(voba::Person::CLASS_NAME)
{
	this->operator=(other);
}

// public function
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
