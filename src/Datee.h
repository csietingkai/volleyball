#ifndef DATEE_H_
#define DATEE_H_

#include <iostream>
#include <ctime>

#include "common.h"

using namespace std;

// global variables
const string MONTHS[] = 
{
	"December", 
	"Junary", "Feburary", "March", 
	"April", "May", "June", 
	"July", "August", "September", 
	"October", "November", "December"
};

const string DAY_OF_WEEK[] = 
{
	"Sunday",
	"Monday",
	"Tuesdy",
	"Wednesday", 
	"Thursday", 
	"Friday", 
	"Saturday" 
};

enum class Week
{
	SUNDAY = 0,
	MONDAY = 1,
	TUESDAY = 2,
	WEDNESDAY = 3,
	THURSDAY = 4,
	FRIDAY = 5,
	SATURDAY = 6
};

// name Date as Datee to prevent ambugious in Glib::Date
class Datee
{
	public:
		// constructors
		Datee(const int year = 1900, const int month = 1, const int day = 1);
		Datee(const Datee& other);
		
		// setters
		void set_year(const int year);
		void set_month(const int month);
		void set_day(const int day);
		
		// getters
		const int get_year() const;
		const int get_month() const;
		const int get_day() const;
		const Week get_week() const;
		const string to_string() const;	// format: yyyy-mm-dd, week
		
		// operators
		const Datee& operator =(const Datee& other);
		const bool operator ==(const Datee& other) const;
		const bool operator !=(const Datee& other) const;
		const bool operator <(const Datee& other) const;
		const bool operator >(const Datee& other) const;
		const bool operator <=(const Datee& other) const;
		const bool operator >=(const Datee& other) const;
		friend ostream& operator <<(ostream& strm, const Datee& other);
		
		// static 
		const static Datee Now();
		
		// other functions
		const Datee next_year() const;
		const Datee previous_year() const;
		const Datee next_month() const;
		const Datee previous_month() const;
		const Datee next_day() const;
		const Datee previous_day() const;
	
	private:
		int year;
		int month;
		int day;
		Week week;
		bool is_leap;
		
		const static int YEAR_UPPER_LIMIT = 9999;
		const static int YEAR_LOWER_LIMIT = 1900;
		const static int MONTHS_PER_YEAR = 12;
		const static int DAYS_PER_MONTH[];
		
		// check year range in 1900~9999, check month range 1~12, check day range 1~28/29/30/31
		void check_member_vars();
		
		const bool calculate_leap() const; // calculate is leap by year
		const Week calculate_week() const; // calculate week by year, month and day
};

#endif // DATEE_H_
