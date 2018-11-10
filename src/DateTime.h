#ifndef DATETIME_H_
#define DATETIME_H_

#include <iostream>
#include <ctime>

#include "common.h"
#include "Datee.h"
#include "Time.h"

using namespace std;

class DateTime
{
	public:
		// constructors
		DateTime(const Datee date, const Time time);
		DateTime(const DateTime& datetime);
		
		// setters
		void set_date(const Datee date);
		void set_time(const Time time);
		
		// getters
		const Datee get_date() const;
		const Time get_time() const;
		const string to_string() const;
		
		// static
		const static DateTime Now();
		
		// operators
		const DateTime& operator =(const DateTime& other);
		const bool operator ==(const DateTime& other) const;
		const bool operator !=(const DateTime& other) const;
		const bool operator <(const DateTime& other) const;
		const bool operator >(const DateTime& other) const;
		const bool operator <=(const DateTime& other) const;
		const bool operator >=(const DateTime& other) const;
		friend ostream& operator <<(ostream& strm, const DateTime& other);
		
		// other functions
		const DateTime next_section();
		const DateTime previous_section();
	
	private:
		Datee date;
		Time time;
		
		const static Time GAME_TIME_SECTIONS[];
		
};
#endif //DATETIME_H_
