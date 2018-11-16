#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include <algorithm>
#include <iostream>

#include "common.h"
#include "DateeTime.h"
#include "Game.h"
#include "Team.h"

using namespace std;

class Schedule
{
	public:
		// constructors
		Schedule(const DateeTime start, const DateeTime finish, const bool enable_four_section = false);
		
		// setters
		 
		// getters
		const DateeTime get_start() const;
		const DateeTime get_finish() const;
		const bool is_enable_four_section() const;
		
		// other functions
		void start_scheduling();
		
	private:
		DateeTime start;
		DateeTime finish;
		vector<Week> excludes;
		vector<Game> games;
		vector<Team> teams;
		bool four_section;	// the variable is set one day can have three or four games, false mean three, true mean four
};

#endif // SCHEDULE_H_
