#ifndef PEOPLE_H
#define PEOPLE_H

#include <vector>

using namespace std;

//=====================/ Person class section /=====================//

enum class Gender
{
	male = true,
	female = false
};

class Person
{
	public:
		// constructors
		Person(const string name, const int age, const Gender is_male, const string phonenumber);
				
		// getters
		const string get_name() const; // get the name
		const int get_age() const; // get the age
		const Gender get_gender() const; // get the gender
		const string get_phonenumber() const; // get the phone number
		const string to_string() const; // print out person's full information
		const int hashcode() const; // generate hashcode with full info
		
		// static funtions
		static const int count(); // return how many people has construct
		
		// operators
		const Person& operator =(const Person& other);
		const bool operator ==(const Person& other) const;
		const bool operator !=(const Person& other) const;
		const bool operator <(const Person& other) const; // sort by full information
		const bool operator >(const Person& other) const;
		const bool operator <=(const Person& other) const;
		const bool operator >=(const Person& other) const;
		friend ostream& operator <<(ostream& strm, const Person& other);
		
	private:
		string name;
		int age;
		Gender gender; // true <= male, false <= female
		string phonenumber;
		
		static int person_count;
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
		void load_file(const string filename); // load from file: (teamname.csv)
		void save_file(const string filename); // save to file: (teamname.csv)
		
		// static
		static const int count(); // how many team has construct
		
		// operators
		const Team& operator =(const Team& other);
		const bool operator ==(const Team& other) const;
		const bool operator !=(const Team& other) const;
		const bool operator <(const Team& other) const; // sort by name
		const bool operator >(const Team& other) const;
		const bool operator <=(const Team& other) const;
		const bool operator >=(const Team& other) const;
		
	private:
		string name;
		vector<Person> personset;
		
		static int team_count;
};

#endif //PEOPLE_H
