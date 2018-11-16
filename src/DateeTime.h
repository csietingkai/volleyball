#ifndef DATEETIME_H_
#define DATEETIME_H_

#include <iostream>
#include <ctime>

#include "common.h"
#include "Datee.h"
#include "Time.h"

using namespace std;

class DateeTime
{
	public:
		// constructors
		DateeTime(){};
		DateeTime(const Datee date, const Time time);
		DateeTime(const DateeTime& datetime);
		
		// setters
		void set_date(const Datee date);
		void set_time(const Time time);
		
		// getters
		const Datee get_date() const;
		const Time get_time() const;
		const string to_string() const;
		
		// static
		const static DateeTime Now();
		
		// operators
		const DateeTime& operator =(const DateeTime& other);
		const bool operator ==(const DateeTime& other) const;
		const bool operator !=(const DateeTime& other) const;
		const bool operator <(const DateeTime& other) const;
		const bool operator >(const DateeTime& other) const;
		const bool operator <=(const DateeTime& other) const;
		const bool operator >=(const DateeTime& other) const;
		friend ostream& operator <<(ostream& strm, const DateeTime& other);
		
		// other functions
		// each schedule has four sections can place a game in
		// which means on day can have four games at maximum
		const DateeTime next_section();
		const DateeTime previous_section();
	
	private:
		Datee date;
		Time time;
};

const static Time GAME_TIME_SECTIONS[4] = 
{
	{19, 0, 0}, 
	{20, 30, 0}, 
	{22, 0, 0},
	{23, 0, 0}
};

#endif // DATEETIME_H_
