#ifndef TEAM_FACTORY_H_
#define TEAM_FACTORY_H_

#include <iostream>
#include <vector>

#include "../Game.h"
#include "../Team.h"
#include "../../tools/MySQLConnector.h"

namespace voba
{
	class TeamFactory
	{
		public:
			const static std::string CLASS_NAME;
			
			const static std::vector<Team> select_all();
			const static Team& select_by_id(const UUID id);
			const static Team& create(const std::string name);
			const static Team& insert_member(Team& team, const Person& member);
			const static Team& delete_member(Team& team, const Person& member);
			const static bool update(const Team new_team);
			const static bool remove(const Team team);
		
		private:
			static MySQLConnector<Team> t_connector;
			static MySQLConnector<Game> g_connector;
			static Logger logger;
	};
}

#endif // TEAM_FACTORY_H_
