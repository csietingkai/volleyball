#ifndef TEAM_H_
#define TEAM_H_

#include <algorithm>
#include <iostream>
#include <string>
#include "common.h"
#include "MySQLConnector.h"
#include "Person.h"

using namespace std;

class Team : Connectable
{
	public:
		// constructors
		Team(const string name);
		
		// getters
		const string get_name() const;
		const Person& get_member(const unsigned int index) const;
		
		// other member function
		void add_member(const Person& member); // add member to set
		void remove_member(const Person& member); // remove member from set
		const int size() const;
		
		// operators
		const Team& operator =(const Team& other);
		const bool operator ==(const Team& other) const;
		const bool operator !=(const Team& other) const;
		
	protected:
		void insert() override;
		void update(const string column_name, const string column_value) override;
		
	private:
		string id;
		string name;
		vector<Person> personset;
		
		const static string TABLE_NAME;
		MySQLConnector connector;
		const static string CLASS_NAME;
		Logger logger;
};

#endif //TEAM_H_
