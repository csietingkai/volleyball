#ifndef TEAM_H_
#define TEAM_H_

#include <iostream>

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
			void set_name(const std::string name);
			
			// getters
			const std::string get_id() const override { return IModel::get_id(); };
			const std::string get_name() const;
			const Person& get_member(const unsigned int index) const;
			const std::string get_prefer_week() const;
			const std::string get_prefer_time() const;
			const unsigned int size() const;
			const std::string to_string() const { return ""; };
			
			// other member function
			void add_member(const Person& member);
			void remove_member(const Person& member);
			void add_prefer_week(const Week week);
			void remove_prefer_week(const Week week);
			void add_prefer_time(const Time time);
			void remove_prefer_time(const Time time);
			
			// operators
			const Team& operator =(const Team& other);
			const bool operator ==(const Team& other) const;
			const bool operator !=(const Team& other) const;
			const Person& operator [](const unsigned int index) const;
			
			void update_id() override { this->id = Utils::generate_sha1(this->to_string()); };
		
		private:
			std::string name;
			std::vector<Person> personset;
			bool prefer_week[7] = { true, true, true, true, true, true, true };
			bool prefer_time[4] = { true, true, true, true };
	};
}

#endif // TEAM_H_
