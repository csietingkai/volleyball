#ifndef TIME_H_
#define TIME_H_

#include <ctime>
#include <iostream>

#include "../tools/Logger.h"

namespace voba
{
	class Time : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			// constructors
			Time(const int hour = 0, const int minute = 0, const int second = 0);
			Time(const Time& other);
			
			// setters
			void set_hour(const int hour) { this->hour = hour; this->check_member_vars(); };
			void set_minute(const int minute) { this->minute = minute; this->check_member_vars(); };
			void set_second(const int second) { this->second = second; this->check_member_vars(); };
			
			// getters
			const int get_hour() const { return this->hour; };
			const int get_minute() const { return this->minute; };
			const int get_second() const { return this->second; };
			const std::string to_string() const;	// format: hh:mm:ss
			
			// static
			const static Time Now();
			
			// other functions
			const Time next_hour() const;
			const Time previous_hour() const;
			const Time next_minute() const;
			const Time previous_minute() const;
			const Time next_second() const;
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
			
			// check hour range in 0~23, check minute & second range 0~59
			void check_member_vars();
	};
}

#endif // TIME_H_
