#ifndef TEAM_H_
#define TEAM_H_

#include <algorithm>
#include <iostream>
#include <string>
#include "common.h"
#include "MySQLConnector.h"
#include "Person.h"

using namespace std;

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
		
		// operators
		const Team& operator =(const Team& other);
		const bool operator ==(const Team& other) const;
		const bool operator !=(const Team& other) const;
		
	private:
		string id;
		string name;
		vector<Person> personset;
		
		static int team_count;
};

#endif //TEAM_H_
