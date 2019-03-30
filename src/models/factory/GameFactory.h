#ifndef GAME_FACTORY_H_
#define GAME_FACTORY_H_

#include <iostream>
#include <vector>

#include "../Game.h"
#include "../../tools/MySQLConnector.h"
#include "PersonFactory.h"
#include "TeamFactory.h"

namespace voba
{
	class GameFactory
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * select all game data from database
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static std::vector<Game> select_all();
			/**
			 * select a game data from database
			 * 
			 * @param id(UUID)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static Game& select_by_id(const UUID id);
			/**
			 * create a game data in database
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static Game& create(const Team team1, const Team team2);
			/**
			 * create a game data in database
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * @param judge(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static Game& create(const Team team1, const Team team2, const Person judge);
			/**
			 * create a game data in database
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * @param game_time(DateTime)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static Game& create(const Team team1, const Team team2, const DateTime game_time);
			/**
			 * create a game data in database
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * @param judge(Person)
			 * @param game_time(DateTime)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static Game& create(const Team team1, const Team team2, const Person judge, const DateTime game_time);
			/**
			 * update the person data in database
			 * 
			 * @param new_game(Game)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static bool update(Game& new_game);
			/**
			 * remove the person data from database
			 * 
			 * @param game(Game)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.17
			 */
			const static bool remove(Game& game);
		
		private:
			static MySQLConnector<Game> g_connector;
			static Logger logger;
	};
}

#endif // GAME_FACTORY_H_
