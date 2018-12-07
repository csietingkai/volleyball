#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>

#include "../tools/Logger.h"

namespace voba
{
	const std::string MONTHS[] = 
	{
		"December", 
		"Junary", "Feburary", "March", 
		"April", "May", "June", 
		"July", "August", "September", 
		"October", "November", "December"
	};

	const std::string DAY_OF_WEEK[] = 
	{
		"Sunday",
		"Monday",
		"Tuesdy",
		"Wednesday", 
		"Thursday", 
		"Friday", 
		"Saturday" 
	};

	enum class Week: int
	{
		SUNDAY = 0,
		MONDAY = 1,
		TUESDAY = 2,
		WEDNESDAY = 3,
		THURSDAY = 4,
		FRIDAY = 5,
		SATURDAY = 6
	};

	class Date
	{
		public:
			// constructors
			Date(const int year = 1900, const int month = 1, const int day = 1);
			Date(const Date& other);
			
			// setters
			void set_year(const int year) { this->year = year; this->check_member_vars(); this->week = this->calculate_week(); };
			void set_month(const int month) { this->month = month; this->check_member_vars(); this->week = this->calculate_week(); };
			void set_day(const int day) { this->day = day; this->check_member_vars(); this->week = this->calculate_week(); };
			
			// getters
			const int get_year() const { return this->year; };
			const int get_month() const { return this->month; };
			const int get_day() const { return this->day; };
			const Week get_week() const { return this->week; };
			const std::string to_string() const;	// format: yyyy-mm-dd, week
			
			// operators
			const Date& operator =(const Date& other);
			const bool operator ==(const Date& other) const;
			const bool operator !=(const Date& other) const { return !this->operator==(other); };
			const bool operator <(const Date& other) const;
			const bool operator >(const Date& other) const { return other.operator<(*this); };
			const bool operator <=(const Date& other) const { return !this->operator>(other); };
			const bool operator >=(const Date& other) const { return !this->operator<(other); };
			friend std::ostream& operator <<(std::ostream& strm, const Date& other);
			
			// static 
			const static Date Now();
			
			// other functions
			const Date next_year() const;
			const Date previous_year() const;
			const Date next_month() const;
			const Date previous_month() const;
			const Date next_day() const;
			const Date previous_day() const;
		
		private:
			int year;
			int month;
			int day;
			Week week;
			bool is_leap;
			
			Logger logger;
			const static std::string CLASS_NAME;
			
			const static int YEAR_UPPER_LIMIT = 9999;
			const static int YEAR_LOWER_LIMIT = 1900;
			const static int MONTHS_PER_YEAR = 12;
			const static int DAYS_PER_MONTH[];
			
			// check year range in 1900~9999, check month range 1~12, check day range 1~28/29/30/31
			void check_member_vars();
			
			const bool calculate_leap() const; // calculate is leap by year
			const Week calculate_week() const; // calculate week by year, month and day
	};
}

#endif // DATE_H_
