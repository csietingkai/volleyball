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
		
		// check hour range in 0~23, check minute & second range 0~59
		void check_member_vars();
};

#endif //TIME_H_
