#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "common.h"
#include "DateTime.h"
#include "Team.h"

class Game : Connectable
{
	public:
		// constructors
		Game(const Team team1, const Team team2);
		//Game(const Game& other);
		
		// setters
		void set_team1(const Team team1);
		void set_team2(const Team team2);
		void set_datetime(const DateTime datetime);
		
		// getters
		const Team get_team1() const;
		const Team get_team2() const;
		const DateTime get_datetime() const;
		const string to_string() const;
		
		// operators
		const Game& operator =(const Game& other);
		const bool operator ==(const Game& other) const;
		const bool operator !=(const Game& other) const;
		const bool operator <(const Game& other) const; // sort by datetime
		const bool operator >(const Game& other) const;
		const bool operator <=(const Game& other) const;
		const bool operator >=(const Game& other) const;
		friend ostream& operator <<(ostream& strm, const Game& other);
		
	protected:
		void select() override;
		void insert() override;
		void update(const string column_name, const string column_value) override;
		
	private:
		string id;
		DateTime datetime;
		Team team1;
		Team team2;
		bool is_timeset;	// this variable used to record 'set_datetime' function is called or not
		
		const static string CLASS_NAME;
		Logger logger;
};

#endif // GAME_H_
