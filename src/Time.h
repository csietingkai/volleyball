#ifndef TIME_H_
#define TIME_H_

#include <iostream>
#include <ctime>

#include "common.h"

using namespace std;

class Time
{
	public:
		// constructors
		Time(const int hour = 0, const int minute = 0, const int second = 0);
		Time(const Time& other);
		
		// setters
		void set_hour(const int hour);
		void set_minute(const int minute);
		void set_second(const int second);
		
		// getters
		const int get_hour() const;
		const int get_minute() const;
		const int get_second() const;
		const string to_string() const;	// format: hh:mm:ss
		
		// static
		const static Time Now();
		
		// other functions
		const Time next_hour() const;
		const Time previous_hour() const;
		const Time next_minute() const;
		const Time previous_minute() const;
		const Time next_second() const;
		const Time previous_second() const;
		
		// operators
		const Time& operator =(const Time& other);
		const bool operator ==(const Time& other) const;
		const bool operator !=(const Time& other) const;
		const bool operator <(const Time& other) const;
		const bool operator >(const Time& other) const;
		const bool operator <=(const Time& other) const;
		const bool operator >=(const Time& other) const;
		friend ostream& operator <<(ostream& strm, const Time& other);
	
	private:
		int hour;
		int minute;
		int second;
		
		const static int HOUR_PER_DAY = 24;
		const static int MINUTE_PER_HOUR = 60;
		const static int SECOND_PER_MINUTE = 60;
		
		// check hour range in 0~23, check minute & second range 0~59
		void check_member_vars();
};

// specific game time section
class GAME_TIME
{
	public:
		const static Time FIRST_SECTION;
		const static Time SECOND_SECTION;
		const static Time THIRD_SECTION;
		const static Time FORTH_SECTION;
};

#endif //TIME_H_
