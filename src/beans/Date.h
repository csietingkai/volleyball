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

	/**
	 * enum Week, from Sunday to Saturday
	 * 
	 * @auther tingkai
	 * @date 2019.01.23
	 */
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

	/**
	 * class Date
	 * extend {@link src/tools/Logger.h: Logable}
	 * 
	 * @auther tingkai
	 * @date 2019.01.23
	 */
	class Date : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * constructor of class {@link Date} <br>
			 * it contains year, month, day
			 * 
			 * @param year(int): date of year, 1900~9999
			 * @param month(int): date of month, 1~31
			 * @param day(int): date of day, 1~28/29/30/31
			 * 
			 * @see Date.h #check_member_vars
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			Date(const int year = 1900, const int month = 1, const int day = 1);
			/**
			 * copy constructor of class {@link Date}
			 * 
			 * @param other(Date&): the other Date reference object 
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			Date(const Date& other);
			
			/**
			 * set year value
			 * 
			 * @param year(int): year value
			 * 
			 * @see Date.h #check_member_vars
			 * @see Date.h #calculate_week
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_year(const int year) { this->year = year; this->check_member_vars(); this->week = this->calculate_week(); };
			/**
			 * set month value
			 * 
			 * @param month(int): month value
			 * 
			 * @see Date.h #check_member_vars
			 * @see Date.h #calculate_week
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_month(const int month) { this->month = month; this->check_member_vars(); this->week = this->calculate_week(); };
			/**
			 * set day value
			 * 
			 * @param day(int): day value
			 * 
			 * @see Date.h #check_member_vars
			 * @see Date.h #calculate_week
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_day(const int day) { this->day = day; this->check_member_vars(); this->week = this->calculate_week(); };
			
			/**
			 * return year value
			 * 
			 * @return year(int): year value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const int get_year() const { return this->year; };
			/**
			 * return month value
			 * 
			 * @return month(int): month value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const int get_month() const { return this->month; };
			/**
			 * return day value
			 * 
			 * @return day(int): day value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const int get_day() const { return this->day; };
			/**
			 * return week value
			 * 
			 * @return week(int): week value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Week get_week() const { return this->week; };
			/**
			 * return full info of Date
			 * 
			 * @return re(string): yyyy-mm-dd, week
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const std::string to_string() const;
			
			/**
			 * return current Date
			 * 
			 * @return now(Date): current date
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const static Date Now();
			
			/**
			 * get next year
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Date next_year() const;
			/**
			 * get previous year
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Date previous_year() const;
			/**
			 * get next month
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Date next_month() const;
			/**
			 * get previous month
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Date previous_month() const;
			/**
			 * get next day
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Date next_day() const;
			/**
			 * get previous day
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Date previous_day() const;
			
			const Date& operator =(const Date& other);
			const bool operator ==(const Date& other) const;
			const bool operator !=(const Date& other) const { return !this->operator==(other); };
			const bool operator <(const Date& other) const;
			const bool operator >(const Date& other) const { return other.operator<(*this); };
			const bool operator <=(const Date& other) const { return !this->operator>(other); };
			const bool operator >=(const Date& other) const { return !this->operator<(other); };
			friend std::ostream& operator <<(std::ostream& strm, const Date& other);
			
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
			
			/**
			 * check year range in 1900~9999, check month range 1~12, check day range 1~28/29/30/31
			 * 
			 * @throw assert
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void check_member_vars();
			
			/**
			 * calculate is leap by year
			 * 
			 * @return ret(bool)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const bool calculate_leap() const;
			/**
			 * calculate week by year, month and day <br/>
			 * use Kim larsson calculation formula <br/>
			 * w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7
			 * 
			 * @return w({@link Date.h enum class Week})
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Week calculate_week() const;
	};
}

#endif // DATE_H_
