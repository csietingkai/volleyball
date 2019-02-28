#ifndef TEAM_H_
#define TEAM_H_

#include <iostream>
#include <set>

#include "../beans/DateTime.h"
#include "IModel.h"
#include "Person.h"

namespace voba
{
	/**
	 * a team model
	 * 
	 * @Implement Logable
	 * @Implement IModel
	 * 
	 * @CreatedBy tingkai
	 * @Date 2018.12.18
	 */
	class Team : Logable, public IModel
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * constructor of Team class
			 * 
			 * @param name(string)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Team(const std::string name);
			/**
			 * copy constructor of Team class
			 * 
			 * @param other(Team)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Team(const Team& other);
			
			/**
			 * set team name
			 * 
			 * @param name(string)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_name(const std::string name);
			/**
			 * get team name
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string get_name() const;
			/**
			 * get team member
			 * 
			 * @param index(int)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const Person& get_member(const unsigned int index) const;
			/**
			 * get team prefer week as string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string get_prefer_week() const;
			/**
			 * get team prefer game time as string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string get_prefer_time() const;
			/**
			 * get how many member in a team
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const unsigned int size() const;
			/**
			 * return full info of Team
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string to_string() const;
			
			/**
			 * add member into team
			 * 
			 * @param member(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void add_member(const Person& member);
			/**
			 * remove member from team
			 * 
			 * @param member(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void remove_member(const Person& member);
			/**
			 * make a week day available
			 * 
			 * @param week(Week)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void add_prefer_week(const Week week);
			/**
			 * make a week day unavailable
			 * 
			 * @param week(Week)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void remove_prefer_week(const Week week);
			/**
			 * make a game section available
			 * 
			 * @param time(Time)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void add_prefer_time(const Time time);
			/**
			 * make a game sectino unavailable
			 * 
			 * @param time(Time)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void remove_prefer_time(const Time time);
			
			// operators
			const Team& operator =(const Team& other);
			const bool operator ==(const Team& other);
			const bool operator !=(const Team& other);
			const Person& operator [](const unsigned int index);
			friend std::ostream& operator <<(std::ostream& strm, const Team& other);
		
		private:
			std::string name;
			std::vector<Person> personset;
			std::set<Week> prefer_week;
			std::set<Time> prefer_time;
			
			/**
			 * setting default prefer week days
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void init_prefer_week();
			/**
			 * setting default prefer game time
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void init_prefer_time();
	};
}

#endif // TEAM_H_
