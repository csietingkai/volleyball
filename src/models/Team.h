#ifndef TEAM_H_
#define TEAM_H_

#include <iostream>
#include <set>

#include "../beans/DateTime.h"
#include "IModel.h"
#include "Person.h"

namespace voba
{
	class Team : Logable, IModel
	{
		public:
			const static std::string CLASS_NAME;
			
			// constructors
			Team(const std::string name);
			Team(const Team& other);
			
			// setters
			void set_name(const std::string name) { this->name = name; };
			
			// getters
			const std::string get_id() const override { return IModel::get_id(); };
			const std::string get_name() const { return this->name; };
			const Person& get_member(const unsigned int index) const;
			const std::string get_prefer_week() const;
			const std::string get_prefer_time() const;
			const unsigned int size() const { return this->personset.size(); };
			const std::string to_string() const;
			
			// other member function
			void add_member(const Person& member);
			void remove_member(const Person& member);
			void add_prefer_week(const Week week) { this->prefer_week.insert(week); };
			void remove_prefer_week(const Week week) { this->prefer_week.erase(week); };
			void add_prefer_time(const Time time) { this->prefer_time.insert(time); };
			void remove_prefer_time(const Time time) { this->prefer_time.erase(time); };
			
			// operators
			const Team& operator =(const Team& other);
			const bool operator ==(const Team& other);
			const bool operator !=(const Team& other) { return !this->operator==(other); };
			const Person& operator [](const unsigned int index) { return this->get_member(index); };
			friend std::ostream& operator <<(std::ostream& strm, const Team& other) { strm << other.to_string(); return strm; };
			
			void update_id(const std::string id) override { this->id = id; };
		
		private:
			std::string name;
			std::vector<Person> personset;
			std::set<Week> prefer_week;
			std::set<Time> prefer_time;
			
			void init_prefer_week();
			void init_prefer_time();
			void check_range(const unsigned int index) const;
	};
}

#endif // TEAM_H_
