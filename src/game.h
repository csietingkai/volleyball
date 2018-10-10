#ifndef GAME_H_
#define GAME_H_

#include "people.h"
#include "datetime.h"

//=====================/ Game class section /=====================//

class Game
{
	public:
		// constructor
		Game(const Team team1, const Team team2);
		
		// setters
		void set_datetime(const DateTime datetime);		// set time game time
		
		// getters
		const Team get_team1() const;			// get team1 value
		const Team get_team2() const;			// get team2 value
		const DateTime get_datetime() const;	// get the game time
		const string to_string() const;			// return a string repersent the information of the game
		const int hashcode() const;				// use 'to_string()' to generate hashcode
		
		// static
		static const int count();				// return how many games now
		
		// operators
		const Game& operator =(const Game& other);
		const bool operator ==(const Game& other) const;
		const bool operator !=(const Game& other) const;
		const bool operator <(const Game& other) const; // sort by datetime
		const bool operator >(const Game& other) const;
		const bool operator <=(const Game& other) const;
		const bool operator >=(const Game& other) const;
		friend ostream& operator <<(ostream& strm, const Game& other);
	
	private:
		DateTime datetime;
		Team team1;
		Team team2;
		bool is_timeset;	// this variable used to record 'set_datetime' function is called or not 
		
		static int game_count;
};

namespace std
{
	template<>
	struct hash<Game>
	{
		size_t operator ()(const Game& obj) const
		{
			return obj.hashcode();
		}
	};
}

//=====================/ Schedule class section /=====================//

class Schedule
{
	public:
		// constructors
		Schedule(const DateTime start, const DateTime finish, const bool enable_four_section = false);
		
		// setters
		void modify_exclude_week(const Week week);	// if contain the
		void modify_teams(const Team team);		// variable, delete it, if not, add it
		 
		// getters
		const DateTime get_start() const;
		const DateTime get_finish() const;
		
		// other functions
		void output_file(const string filename);
		void start_scheduling();
		
	private:
		DateTime start;
		DateTime finish;
		vector<Week> excludes;
		vector<Game> games;
		vector<Team> teams;
		bool four_section;	// the variable is set one day can have three or four games, false mean three, true mean four
};

#endif //GAME_H_
