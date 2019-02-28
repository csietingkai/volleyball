#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>

#include "../tools/Logger.h"

namespace voba
{
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
	 * @CreatedBy tingkai
	 * @Date 2019.01.23
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
	
	std::ostream& operator <<(std::ostream& strm, const Week& weel);

	/**
	 * the class to record the date
	 * 
	 * @Implement Logable
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.01.23
	 */
	class Date : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * constructor of class Date <br>
			 * it contains year, month, day
			 * 
			 * @param year(int): date of year, 1900~9999
			 * @param month(int): date of month, 1~31
			 * @param day(int): date of day, 1~28/29/30/31
			 * 
			 * @see Date #check_member_vars
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			Date(const int year = 1900, const int month = 1, const int day = 1);
			/**
			 * copy constructor of class Date
			 * 
			 * @param other(Date&): the other Date reference object 
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			Date(const Date& other);
			
			/**
			 * set year value
			 * 
			 * @param year(int): year value
			 * 
			 * @see Date #check_member_vars
			 * @see Date #calculate_week
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_year(const int year);
			/**
			 * set month value
			 * 
			 * @param month(int): month value
			 * 
			 * @see Date #check_member_vars
			 * @see Date #calculate_week
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_month(const int month);
			/**
			 * set day value
			 * 
			 * @param day(int): day value
			 * 
			 * @see Date #check_member_vars
			 * @see Date #calculate_week
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_day(const int day);
			
			/**
			 * return year value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const int get_year() const;
			/**
			 * return month value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const int get_month() const;
			/**
			 * return day value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const int get_day() const;
			/**
			 * return week value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Week get_week() const;
			/**
			 * return full info of Date
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const std::string to_string() const;
			/**
			 * return full info of Date
			 * 
			 * @param show_week(bool)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const std::string to_string(const bool show_week) const;
			
			/**
			 * return current Date
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const static Date Now();
			
			/**
			 * get next year
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Date next_year() const;
			/**
			 * get previous year
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Date previous_year() const;
			/**
			 * get next month
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Date next_month() const;
			/**
			 * get previous month
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Date previous_month() const;
			/**
			 * get next day
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Date next_day() const;
			/**
			 * get previous day
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Date previous_day() const;
			
			const Date& operator =(const Date& other);
			const bool operator ==(const Date& other) const;
			const bool operator !=(const Date& other) const;
			const bool operator <(const Date& other) const;
			const bool operator >(const Date& other) const;
			const bool operator <=(const Date& other) const;
			const bool operator >=(const Date& other) const;
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
			 * check year, month, day's value are legel
			 * 
			 * @assert: values are legal
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void check_member_vars();
			
			/**
			 * calculate is leap by year
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const bool calculate_leap() const;
			/**
			 * calculate week by year, month and day <br/>
			 * use Kim larsson calculation formula
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Week calculate_week() const;
	};
}

#endif // DATE_H_
