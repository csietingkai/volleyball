#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <unordered_set>
#include "people.h"

#include "common.h"

using namespace std;

//=====================/ Person class section /=====================//

int Person::person_count = 0;

Person::Person(const string name, const int age, const Gender is_male, const string phonenumber)
{
	// the constructor
	// set parameter into private variable
	// and check parameter is correct
	this->name = name;
	if(age <= 0)
	{
		error("negative number");
	}
	this->age = age;
	this->gender = is_male;
	this->phonenumber = phonenumber;
	
	Person::person_count += 1;	// every time object construct, count+1
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

// static functions
const int Person::count()
{
	// return how many person has created
	return Person::person_count;
}

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

const bool Person::operator <(const Person& other) const
{
	return this->to_string().compare(other.to_string());
}

const bool Person::operator >(const Person& other) const
{
	return (other < (*this));
}

const bool Person::operator <=(const Person& other) const
{
	return !(other > (*this));
}

const bool Person::operator >=(const Person& other) const
{
	return !(other < (*this));
}

ostream& operator <<(ostream& strm, const Person& other)
{
	strm << other.to_string();
	return strm;
}

//=====================/ Team class section /=====================//

int Team::team_count = 0;

// constructors
Team::Team(const string name)
{
	this->name = name;
	this->personset.clear();
	
	Team::team_count += 1;
}

// getters
const string Team::get_name() const
{
	return this->name;
}

const Person& Team::get_member(const int index) const
{
	if(index >= this->size())
	{
		error("get member index too large");
	}
	return personset[index];
}

// other member function
void Team::add_member(const Person& member)
{
	// make all element into a set(no duplicate data structure)
	// then back into vector
	personset.push_back(member);
	unordered_set<Person> s(personset.begin(), personset.end());
	personset.assign(s.begin(), s.end());
	sort(personset.begin(), personset.end());
}

void Team::remove_member(const Person& member)
{
	auto it = find(personset.begin(), personset.end(), member);
	if(it != personset.end())
	{
		personset.erase(it);
	}
	
	//for(int i = 0; i < personset.size(); i++)
	//	cout << personset[i] << endl;
}

const int Team::size() const
{
	return personset.size();
}

void Team::load_file(const string filename)
{
	// load data from file
	ifstream fin("resources/"+filename+".csv");
	
	if(fin.is_open() == false)
	{
		error("can not open input file");
	}
	
	// get lines and then split by ','
	string strin;
	while(getline(fin, strin)){
		//cout << strin << endl;
		istringstream iss(strin);
		string token[4];
		for(int i = 0; i < 4; i++)
		{
			getline(iss, token[i], ',');
			//cout << token[i] << endl;
		}
		
		string name = token[0];
		int age = stoi(token[1]);
		//cout << token[2] << endl;
		Gender gender = (token[2].compare("male") == 0 ? Gender::male : Gender::female);
		string phonenumber = token[3];
		
		add_member(Person(name, age, gender, phonenumber));
	}
	
	//for(Person p : personset)
	//	cout << p << endl;
	
	fin.close();
}

void Team::save_file(const string filename)
{
	// save current data to file
	ofstream fout("resources/"+filename+".csv");
	
	if(fout.is_open() == false)
	{
		error("can not open output file");
	}
	
	for(Person p : personset)
	{
		fout << p << endl;
	}
	
	//for(Person p : personset)
	//	cout << p << endl;
	
	fout.close();
}

// static
const int Team::count()
{
	return Team::team_count;
}

// operators
const Team& Team::operator =(const Team& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	this->name = other.get_name();
	this->personset.clear();
	for(int i = 0; i < other.size(); i++)
	{
		add_member(other.get_member(i));
	}
	
	//for(int i = 0; i < personset.size(); i++)
	//	cout << personset[i] << endl;
	
	return *this;
}

const bool Team::operator ==(const Team& other) const
{
	if((this->get_name() != other.get_name())||
	   (this->size() != other.size()))
	{
		//cout << "name size false" << endl;
		return false;
	}
	for(int i = 0; i < this->size(); i++)
	{
		//cout << this->get_member(i) << endl;
		//cout << other.get_member(i) << endl;
		if(this->get_member(i) != other.get_member(i))
		{
			//cout << "member " << i << " false" << endl;
			return false;
		}
	}
	return true;
}

const bool Team::operator !=(const Team& other) const
{
	return !(operator==(other));
}

const bool Team::operator <(const Team& other) const
{
	return this->get_name().compare(other.get_name());
}

const bool Team::operator >(const Team& other) const
{
	return (other < (*this));
}

const bool Team::operator <=(const Team& other) const
{
	return !(other > (*this));
}

const bool Team::operator >=(const Team& other) const
{
	return !(other < (*this));
}
