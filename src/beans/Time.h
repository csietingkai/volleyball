#ifndef TIME_H_
#define TIME_H_

#include <ctime>
#include <iostream>

#include "../tools/Logger.h"

namespace voba
{
	/**
	 * class Time
	 * extend {@link src/tools/Logger.h: Logable}
	 * 
	 * @auther tingkai
	 * @date 2019.01.23
	 */
	class Time : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * constructor of class {@link Time} <br>
			 * it contains hour, time, second
			 * 
			 * @param hour(int): time of hour, 0~23
			 * @param minute(int): time of minute, 0~59
			 * @param second(int): time of second, 0~59
			 * 
			 * @see Time.h #check_member_vars
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			Time(const int hour = 0, const int minute = 0, const int second = 0);
			/**
			 * copy constructor of class {@link Time}
			 * 
			 * @param other(Time&): the other Time reference object 
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			Time(const Time& other);
			
			/**
			 * set hour value
			 * 
			 * @param hour(int): hour value
			 * 
			 * @see Time.h #check_member_vars
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_hour(const int hour) { this->hour = hour; this->check_member_vars(); };
			/**
			 * set minute value
			 * 
			 * @param minute(int): minute value
			 * 
			 * @see Time.h #check_member_vars
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_minute(const int minute) { this->minute = minute; this->check_member_vars(); };
			/**
			 * set second value
			 * 
			 * @param second(int): second value
			 * 
			 * @see Time.h #check_member_vars
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void set_second(const int second) { this->second = second; this->check_member_vars(); };
			
			/**
			 * return hour value
			 * 
			 * @return hour(int): hour value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const int get_hour() const { return this->hour; };
			/**
			 * return minute value
			 * 
			 * @return minute(int): minute value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const int get_minute() const { return this->minute; };
			/**
			 * return second value
			 * 
			 * @return second(int): second value
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const int get_second() const { return this->second; };
			/**
			 * return full info of Time
			 * 
			 * @return re(string): hh:mm:ss
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const std::string to_string() const;
			
			/**
			 * return current time
			 * 
			 * @return now(Time): current time
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const static Time Now();
			
			/**
			 * get next hour
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Time next_hour() const;
			/**
			 * get previous hour
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Time previous_hour() const;
			/**
			 * get next minute
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Time next_minute() const;
			/**
			 * get previous minute
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Time previous_minute() const;
			/**
			 * get next second
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Time next_second() const;
			/**
			 * get previous second
			 * 
			 * @return ret(Time)
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			const Time previous_second() const;
			
			// operators
			const Time& operator =(const Time& other);
			const bool operator ==(const Time& other) const;
			const bool operator !=(const Time& other) const { return !this->operator==(other); };
			const bool operator <(const Time& other) const;
			const bool operator >(const Time& other) const { return other.operator<(*this); };
			const bool operator <=(const Time& other) const { return !this->operator>(other); };
			const bool operator >=(const Time& other) const { return !this->operator<(other); };
			friend std::ostream& operator <<(std::ostream& strm, const Time& other) { strm << other.to_string(); return strm; };
		
		private:
			int hour;
			int minute;
			int second;
			
			const static int HOUR_PER_DAY = 24;
			const static int MINUTE_PER_HOUR = 60;
			const static int SECOND_PER_MINUTE = 60;
			
			/**
			 * check hour range in 0~23, check minute & second range 0~59
			 * 
			 * @throw assert
			 * 
			 * @auther tingkai
			 * @date 2019.01.23
			 */
			void check_member_vars();
	};
}

#endif // TIME_H_
