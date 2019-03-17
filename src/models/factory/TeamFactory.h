#ifndef TEAM_FACTORY_H_
#define TEAM_FACTORY_H_

#include <iostream>
#include <vector>

#include "../Game.h"
#include "../Team.h"
#include "../../tools/MySQLConnector.h"
#include "PersonFactory.h"

namespace voba
{
	class TeamFactory
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * select all team data from database
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.01
			 */
			const static std::vector<Team> select_all();
			/**
			 * select team data from database
			 * 
			 * @param id(UUID)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.01
			 */
			const static Team& select_by_id(const UUID id);
			/**
			 * create a team
			 * 
			 * @param name(string)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.01
			 */
			const static Team& create(const std::string name);
			/**
			 * add member into team and update database
			 * 
			 * @param team(Team)
			 * @param member(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.01
			 */
			const static Team& insert_member(Team& team, const Person& member);
			/**
			 * remove member from team and update database
			 * 
			 * @param team(Team)
			 * @param member(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.01
			 */
			const static Team& delete_member(Team& team, const Person& member);
			/**
			 * update team's attributes
			 * 
			 * @param team(Team)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.01
			 */
			const static bool update(Team& new_team);
			/**
			 * remove a team from database
			 * 
			 * @param team(Team)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.01
			 */
			const static bool remove(Team& team);
		
		private:
			static MySQLConnector<Team> t_connector;
			static MySQLConnector<Game> g_connector;
			static Logger logger;
	};
}

#endif // TEAM_FACTORY_H_
