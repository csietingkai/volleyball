#ifndef TIME_H_
#define TIME_H_

#include <boost/regex.hpp>
#include <ctime>
#include <iostream>
#include <vector>

#include "../tools/Logger.h"
#include "../utils/Utils.h"

namespace voba
{
	/**
	 * the class to record the time
	 * 
	 * @Implement Logable
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.01.23
	 */
	class Time : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * constructor of class Time<br>
			 * it contains hour, time, second
			 * 
			 * @param hour(int): time of hour, 0~23
			 * @param minute(int): time of minute, 0~59
			 * @param second(int): time of second, 0~59
			 * 
			 * @see Time #check_member_vars
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			Time(const int hour = 0, const int minute = 0, const int second = 0);
			/**
			 * constructor of class Time<br>
			 * it contains hour, time, second
			 * 
			 * @param time_str(string): format: [0-9]{2}:[0-9]{2}:[0-9]{2}
			 * 
			 * @see Time #check_member_vars
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.16
			 */
			Time(const std::string time_str);
			/**
			 * copy constructor of class {@link Time}
			 * 
			 * @param other(Time&): the other Time reference object 
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			Time(const Time& other);
			
			/**
			 * set hour value
			 * 
			 * @param hour(int): hour value
			 * 
			 * @see Time #check_member_vars
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_hour(const int hour);
			/**
			 * set minute value
			 * 
			 * @param minute(int): minute value
			 * 
			 * @see Time #check_member_vars
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_minute(const int minute);
			/**
			 * set second value
			 * 
			 * @param second(int): second value
			 * 
			 * @see Time #check_member_vars
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void set_second(const int second);
			
			/**
			 * return hour value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const int get_hour() const;
			/**
			 * return minute value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const int get_minute() const;
			/**
			 * return second value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const int get_second() const;
			/**
			 * return full info of Time
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const std::string to_string() const;
			
			/**
			 * return current time
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const static Time Now();
			
			/**
			 * get next hour
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Time next_hour() const;
			/**
			 * get previous hour
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Time previous_hour() const;
			/**
			 * get next minute
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Time next_minute() const;
			/**
			 * get previous minute
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Time previous_minute() const;
			/**
			 * get next second
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Time next_second() const;
			/**
			 * get previous second
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			const Time previous_second() const;
			
			// operators
			const Time& operator =(const Time& other);
			const bool operator ==(const Time& other) const;
			const bool operator !=(const Time& other) const;
			const bool operator <(const Time& other) const;
			const bool operator >(const Time& other) const;
			const bool operator <=(const Time& other) const;
			const bool operator >=(const Time& other) const;
			friend std::ostream& operator <<(std::ostream& strm, const Time& other);
		
		private:
			int hour;
			int minute;
			int second;
			
			const static int HOUR_PER_DAY = 24;
			const static int MINUTE_PER_HOUR = 60;
			const static int SECOND_PER_MINUTE = 60;
			
			/**
			 * check hour, minute, second's values are legal
			 * 
			 * @assert 
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.23
			 */
			void check_member_vars();
	};
}

#endif // TIME_H_
