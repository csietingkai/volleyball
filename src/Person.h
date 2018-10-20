#ifndef PERSON_H_
#define PERSON_H_

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

class Person : Connectable
{
	public:
		typedef Connectable super;
		
		// constructors
		Person(const string name, const unsigned int age, const Gender gender, const string phonenumber, const ActiveStatus status);
		
		// setters
		void set_name(const string name);
		void set_age(const unsigned int age);
		void set_gender(const Gender gender);
		void set_phonenumber(const string phonenumber);
		void set_active_status(const ActiveStatus status);
		
		// getters
		const string get_name() const;
		const int get_age() const;
		const Gender get_gender() const;
		const string get_phonenumber() const;
		const ActiveStatus get_active_status() const;
		const string to_string() const;
			
		// operators
		const Person& operator =(const Person& other);
		const bool operator ==(const Person& other) const;
		const bool operator !=(const Person& other) const;
		friend ostream& operator <<(ostream& strm, const Person& other);
	
	protected:
		void init() override;
		void update(const string column_name, const string column_value) override;
		
	private:
		string id;
		string name;
		unsigned int age;
		Gender gender; // true <= male, false <= female
		string phonenumber;
		ActiveStatus status; // true <= active, false <= inactive
		
		const static string TABLE_NAME;
		MySQLConnector connector;
		const static string CLASS_NAME;
		Logger logger;
};

#endif //PERSON_H_
