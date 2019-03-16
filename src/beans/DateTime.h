#ifndef DATETIME_H_
#define DATETIME_H_

#include <ctime>
#include <iostream>

#include "Date.h"
#include "Time.h"

namespace voba
{
	/**
	 * specific game time section
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.01.23
	 */
	class GAME_TIME
	{
		public:
			const static Time FIRST_SECTION;
			const static Time SECOND_SECTION;
			const static Time THIRD_SECTION;
			const static Time FORTH_SECTION;
	};
	
	/**
	 * the class combine Date and Time
	 * 
	 * @Implement Logable
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.01.23
	 */
	class DateTime : Logable
	{
		public:
			const static std::string CLASS_NAME;

			/**
			 * constructor of class DateTime <br/>
			 * need user set date and time
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			DateTime() : Logable(DateTime::CLASS_NAME) {};
			/**
			 * constructor of class DateTime <br/>
			 * it contains date, time
			 * 
			 * @param date(Date&)
			 * @param time(Time&)
			 * 
			 * @see Date::Date(Date&)
			 * @see Time::Time(Time&)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			DateTime(const Date date, const Time time);
			/**
			 * constructor of class DateTime <br/>
			 * it contains date, time
			 * 
			 * @param datetime_str(string): format: date format + " " + time format
			 * 
			 * @see Date::Date(Date&)
			 * @see Time::Time(Time&)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			DateTime(const std::string datetime_str);
			/**
			 * copy constructor of class {@link DateTime}
			 * 
			 * @param datetime(DateTime&)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			DateTime(const DateTime& datetime);
			
			/**
			 * set date value
			 * 
			 * @param date(Date)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_date(const Date date);
			/**
			 * set time value
			 * 
			 * @param time(Time)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_time(const Time time);
			
			/**
			 * get date value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Date get_date() const;
			/**
			 * get time value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Time get_time() const;
			/**
			 * return full info of Time
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const std::string to_string() const;
			/**
			 * return full info of Time
			 * 
			 * @param show_week(bool)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const std::string to_string(const bool show_week) const;
			
			/**
			 * return current datetime
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const static DateTime Now();
			
			/**
			 * get the next game time section <br/>
			 * 19:00 -&gt; 20:30 -&gt; 22:00 -&gt; 23:00 -&gt; 19:00(next day)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const DateTime next_section();
			/**
			 * get the previous game time section <br/>
			 * 19:00 &lt;- 20:30 &lt;- 22:00 &lt;- 23:00 &lt;- 19:00(next day)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const DateTime previous_section();
			
			// operators
			const DateTime& operator =(const DateTime& other);
			const bool operator ==(const DateTime& other) const;
			const bool operator !=(const DateTime& other) const;
			const bool operator <(const DateTime& other) const;
			const bool operator >(const DateTime& other) const;
			const bool operator <=(const DateTime& other) const;
			const bool operator >=(const DateTime& other) const;
			friend std::ostream& operator <<(std::ostream& strm, const DateTime& other);
		
		private:
			Date date;
			Time time;
	};
}

#endif // DATETIME_H_
