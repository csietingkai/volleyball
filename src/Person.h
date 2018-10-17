#ifndef PEOPLE_H
#define PEOPLE_H

#include <algorithm>
#include <iostream>
#include <string>
#include "common.h"
#include "MySQLConnector.h"

using namespace std;

//=====================/ Person class section /=====================//

enum class Gender
{
	male = true,
	female = false
};

enum class ActiveStatus
{
	active = true,
	inactive = false
};

class Person
{
	public:
		// constructors
		Person(const string name, const unsigned int age, const Gender is_male, const string phonenumber, const ActiveStatus active);
		
		// getters
		const string get_name() const;
		const int get_age() const;
		const Gender get_gender() const;
		const string get_phonenumber() const;
		const ActiveStatus get_active_status() const;
		const string to_string() const;
		const string hashcode() const; 
			
		// operators
		const Person& operator =(const Person& other);
		const bool operator ==(const Person& other) const;
		const bool operator !=(const Person& other) const;
		friend ostream& operator <<(ostream& strm, const Person& other);
		
	private:
		string id;
		string name;
		unsigned int age;
		Gender gender; // true <= male, false <= female
		string phonenumber;
		ActiveStatus active; // true <= active, false <= inactive
		
		const string table_name = "persons";
		MySQLConnector connector;
		
		void init();
};

//=====================/ Team class section /=====================//

class Team
{
	public:
		// constructors
		Team(const string name);
		
		// getters
		const string get_name() const;
		const Person& get_member(const int index) const; // get meber by index
		
		// other member function
		void add_member(const Person& member); // add member to set
		void remove_member(const Person& member); // remove member from set
		const int size() const;
		
		// static
		static const int count(); // how many team has construct
		
		// operators
		const Team& operator =(const Team& other);
		const bool operator ==(const Team& other) const;
		const bool operator !=(const Team& other) const;
		
	private:
		string uuid;
		string name;
		vector<Person> personset;
		
		static int team_count;
};

#endif //PEOPLE_H
