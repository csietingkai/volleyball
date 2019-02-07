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
	class Game : Logable, IModel
	{
		public:
			const static std::string CLASS_NAME;
			
			Game(const Team team1, const Team team2);
			Game(const Team team1, const Team team2, const Person judge);
			Game(const Team team1, const Team team2, const DateTime game_time);
			Game(const Team team1, const Team team2, const Person judge, const DateTime game_time);
			Game(const Game& other);
			
			void set_team1(const Team team1) { this->team1 = team1; };
			void set_team2(const Team team2) { this->team2 = team2; };
			void set_judge(const Person judge) { this->judge = judge; };
			void set_game_time(const DateTime game_time) { this->game_time = game_time; };
			
			const UUID get_id() const override { return IModel::get_id(); };
			const Team get_team1() const;
			const Team get_team2() const;
			const Person get_judge() const;
			const DateTime get_game_time() const;
			const std::string to_string() const;
			
			const Game& operator =(const Game& other);
			const bool operator ==(const Game& other);
			const bool operator !=(const Game& other) { return !this->operator==(other); };
			friend std::ostream& operator <<(std::ostream& strm, const Game& other) { strm << other.to_string(); return strm; };
			
			void update_id(const UUID id) override { this->id = id; };
			
		private:
			Team team1;
			Team team2;
			Person judge;
			DateTime game_time;
	};
}

#endif // GAME_H_
