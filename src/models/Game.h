#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "IModel.h"
#include "Team.h"
#include "../beans/DateTime.h"
#include "../tools/Logger.h"
#include "../utils/Utils.h"

namespace voba
{
	/**
	 * a game model
	 * 
	 * @Implement Logable
	 * @Implement IModel
	 * 
	 * @CreatedBy tingkai
	 * @Date 2018.12.18
	 */
	class Game : Logable, public IModel
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * constructor of Game class
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Game(const Team team1, const Team team2);
			/**
			 * constructor of Game class
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * @param judge(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Game(const Team team1, const Team team2, const Person judge);
			/**
			 * constructor of Game class
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * @param game_time(DateTime)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Game(const Team team1, const Team team2, const DateTime game_time);
			/**
			 * constructor of Game class
			 * 
			 * @param team1(Team)
			 * @param team2(Team)
			 * @param judge(Person)
			 * @param game_time(DateTime)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Game(const Team team1, const Team team2, const Person judge, const DateTime game_time);
			/**
			 * constructor of Game class
			 * 
			 * @param other(Game)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Game(const Game& other);
			
			/**
			 * set team1 value
			 * 
			 * @param team1(Team)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_team1(const Team team1);
			/**
			 * set team2 value
			 * 
			 * @param team2(Team)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_team2(const Team team2);
			/**
			 * set judge value
			 * 
			 * @param judge(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_judge(const Person judge);
			/**
			 * set game time value
			 * 
			 * @param game_time(DateTime)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_game_time(const DateTime game_time);
			/**
			 * get team1 value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const Team get_team1() const;
			/**
			 * get team1 value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const Team get_team2() const;
			/**
			 * get team1 value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const Person get_judge() const;
			/**
			 * get team1 value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const DateTime get_game_time() const;
			/**
			 * get team1 value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string to_string() const;
			
			// operators
			const Game& operator =(const Game& other);
			const bool operator ==(const Game& other);
			const bool operator !=(const Game& other);
			friend std::ostream& operator <<(std::ostream& strm, const Game& other);
			
		private:
			Team team1;
			Team team2;
			Person judge;
			DateTime game_time;
	};
}

#endif // GAME_H_
