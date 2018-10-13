#ifndef PEOPLE_H
#define PEOPLE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
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
		Person(const string name, const ActiveStatus active, const Gender is_male, const int age, const string phonenumber);
				
		// getters
		const string get_name() const;
		const ActiveStatus get_active_status() const;
		const Gender get_gender() const;
		const int get_age() const;
		const string get_phonenumber() const;
		const string to_string() const;
		const int hashcode() const; // generate hashcode with full info
			
		// operators
		const Person& operator =(const Person& other);
		const bool operator ==(const Person& other) const;
		const bool operator !=(const Person& other) const;
		friend ostream& operator <<(ostream& strm, const Person& other);
		
	private:
		string uuid;
		string name;
		ActiveStatus active; // true <= active, false <= inactive
		Gender gender; // true <= male, false <= female
		int age;
		string phonenumber;
};

// hash function for Person
namespace std
{
	template<>
	struct hash<Person>
	{
		size_t operator ()(const Person& obj) const
		{
			return obj.hashcode();
		}
	};
}

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
