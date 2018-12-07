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
	
	class DateTime
	{
		public:
			// constructors
			DateTime() : logger(DateTime::CLASS_NAME) {};
			DateTime(const Date date, const Time time);
			DateTime(const DateTime& datetime);
			
			// setters
			void set_date(const Date date) { this->date = date; };
			void set_time(const Time time) { this->time = time; };
			
			// getters
			const Date get_date() const { return this->date; };
			const Time get_time() const { return this->time; };
			const std::string to_string() const { return this->date.to_string()+" "+this->time.to_string(); };
			
			// static
			const static DateTime Now();
			
			// other functions
			// each schedule has four sections can place a game in
			// which means on day can have four games at maximum
			const DateTime next_section();
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
			
			Logger logger;
			const static std::string CLASS_NAME;
	};
}

#endif // DATETIME_H_
