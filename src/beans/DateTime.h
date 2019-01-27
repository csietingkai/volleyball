#ifndef DATETIME_H_
#define DATETIME_H_

#include <ctime>
#include <iostream>

#include "Date.h"
#include "Time.h"

namespace voba
{
	// specific game time section
	class GAME_TIME
	{
		public:
			const static Time FIRST_SECTION;
			const static Time SECOND_SECTION;
			const static Time THIRD_SECTION;
			const static Time FORTH_SECTION;
	};
	
	class DateTime : Logable
	{
		public:
			const static std::string CLASS_NAME;

			/**
			 * constructor of class {@link DateTime} <br/>
			 * need user set date and time
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			DateTime() : Logable(DateTime::CLASS_NAME) {};
			/**
			 * constructor of class {@link DateTime} <br/>
			 * it contains date, time
			 * 
			 * @param date({@link Date})
			 * @param time({@link Time})
			 * 
			 * @see Date.h #Date(Date&)
			 * @see Time.h #Time(Time&)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			DateTime(const Date date, const Time time);
			/**
			 * copy constructor of class {@link DateTime}
			 * 
			 * @param other(Time&): the other DateTime reference object 
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			DateTime(const DateTime& datetime);
			
			/**
			 * set date value
			 * 
			 * @param date(Date): date value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_date(const Date date) { this->date = date; };
			/**
			 * set time value
			 * 
			 * @param time(Time): time value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_time(const Time time) { this->time = time; };
			
			/**
			 * get date value
			 * 
			 * @return date(Date): date value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Date get_date() const { return this->date; };
			/**
			 * get time value
			 * 
			 * @return time(Time): time value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Time get_time() const { return this->time; };
			/**
			 * return full info of Time
			 * 
			 * @return re(string): yyyy-mm-dd, week hh:mm:ss
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const std::string to_string() const { return this->date.to_string()+" "+this->time.to_string(); };
			
			/**
			 * return current datetime
			 * 
			 * @return now(DateTime): current datetime
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const static DateTime Now();
			
			/**
			 * get the next game time section <br/>
			 * 19:00 -&gt; 20:30 -&gt; 22:00 -&gt; 23:00 -&gt; 19:00(next day)
			 * 
			 * @return ret(DateTime): next game time
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const DateTime next_section();
			/**
			 * get the previous game time section <br/>
			 * 19:00 &lt;- 20:30 &lt;- 22:00 &lt;- 23:00 &lt;- 19:00(next day)
			 * 
			 * @return ret(DateTime): next game time
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const DateTime previous_section();
			
			// operators
			const DateTime& operator =(const DateTime& other);
			const bool operator ==(const DateTime& other) const;
			const bool operator !=(const DateTime& other) const { return !this->operator==(other); };
			const bool operator <(const DateTime& other) const;
			const bool operator >(const DateTime& other) const { return other.operator<(*this); };
			const bool operator <=(const DateTime& other) const { return !this->operator>(other); };
			const bool operator >=(const DateTime& other) const { return !this->operator<(other); };
			friend std::ostream& operator <<(std::ostream& strm, const DateTime& other);
		
		private:
			Date date;
			Time time;
	};
}

#endif // DATETIME_H_
