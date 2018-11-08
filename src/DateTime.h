#ifndef DATETIME_H_
#define DATETIME_H_

#include <iostream>
#include <ctime>

#include "common.h"
#include "Date.h"
#include "Time.h"

using namespace std;

//====================/ DateTime class section /====================//

class DateTime
{
	/*public:
		// constructors
		DateTime(const int year =  1900, const int month = 1, const int day = 1, const int hour = 0, const int minute = 0, const int second = 0);
		
		// getters
		const int get_year() const;		// return the year
		const int get_month() const;	// return the month
		const int get_day() const;		// return the day
		const Week get_week() const;	// return what day is it
		const int get_hour() const;		// return the hour
		const int get_minute() const;	// return the minute
		const int get_second() const;	// return the minute
		const string to_string() const;	// format: yyyy-mm-dd, week, hh:mm:ss
		const int hashcode() const;
		
		// operators
		const DateTime& operator =(const DateTime& other);
		const bool operator ==(const DateTime& other) const;
		const bool operator !=(const DateTime& other) const;
		const bool operator <(const DateTime& other) const;
		const bool operator >(const DateTime& other) const;
		const bool operator <=(const DateTime& other) const;
		const bool operator >=(const DateTime& other) const;
		friend ostream& operator <<(ostream& strm, const DateTime& other);
		// other function
		const DateTime next_section();
		const DateTime previous_section();
		
		// static functions
		const static DateTime Now();
		
	private:
		int year;
		int month; // store -1, range 0~11
		int day;
		Week week;
		int hour;
		int minute;
		int second;
		
		bool is_leap; // 閏年
		
		void check_year();		// check year range in 1900~9999
		void check_month();		// check month range 1~12
		void check_day(); 		// check day range 1~28/29/30/31
		void check_hour(); 		// check hour range 0~23
		void check_minute(); 	// check minute range 0~59
		void check_second(); 	// check second range 0~59
		
		const bool calculate_leap() const; // calculate is leap by year
		const Week calculate_week() const; // calculate week by year, month and day*/
};

#endif //DATETIME_H_
