#ifndef TEAM_FACTORY_H_
#define TEAM_FACTORY_H_

#include <iostream>
#include <vector>

#include "../Team.h"
#include "../../tools/MySQLConnector.h"

namespace voba
{
	class TeamFactory
	{
		public:
			const static Team& create();
			const static Team& insert_member(Team& team, const Person& member);
			const static Team& delete_member(Team& team, const Person& member);
			const static bool update(const Team new_team);
			const static bool remove(const Team team);
		
		private:
			static MySQLConnector<Team> connector;
	};
}

#endif // TEAM_FACTORY_H_
