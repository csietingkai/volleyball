#include "DateTime.h"

//====================/ DateTime class section /====================//

// constructors
/*DateTime::DateTime(const int year, const int month, const int day, const int hour, const int minute, const int second)
{
	// the constructor, set into private variable 
	// and check the variable is correct
	this->year = year;
	check_year();
	this->is_leap = calculate_leap();
	this->month = month;
	check_month();
	this->day = day;
	check_day();
	this->week = calculate_week();
	this->hour = hour;
	check_hour();
	this->minute = minute;
	check_minute();
	this->second = second;
	check_second();
}

// getters
const int DateTime::get_year() const
{
	return this->year;
}

const int DateTime::get_month() const
{
	return this->month;
}

const int DateTime::get_day() const
{
	return this->day;
}

const Week DateTime::get_week() const
{
	return this->week;
}

const int DateTime::get_hour() const
{
	return this->hour;
}

const int DateTime::get_minute() const
{
	return this->minute;
}

const int DateTime::get_second() const
{
	return this->second;
}

const string DateTime::to_string() const
{
	// add private variable into string 
	// format: yyyy-mm-dd, week, hh:mm:ss
	// and return the string 
	string re = "";
	
	re += std::to_string(get_year())+"-";
	re += (get_month()<10?"0":"")+std::to_string(get_month())+"-";
	re += (get_day()<10?"0":"")+std::to_string(get_day())+", ";
	
	re += DAY_OF_WEEK[static_cast<int>(get_week())]+", ";
	
	re += (get_hour()<10?"0":"")+std::to_string(get_hour())+":";
	re += (get_minute()<10?"0":"")+std::to_string(get_minute())+":";
	re += (get_second()<10?"0":"")+std::to_string(get_second());
	
	return re;
}

const int DateTime::hashcode() const
{
	// same value of object has same hashcode
	// so I choose 'to_string()' function to generate hashcode
	return std::hash<std::string>()(to_string());
}

// operators
const DateTime& DateTime::operator =(const DateTime& other)
{
	// assign operator overloading
	// by public function, getters, to complete this operator
	if(*this == other)
		return *this;
	this->year = other.get_year();
	this->month = other.get_month();
	this->day = other.get_day();
	this->hour = other.get_hour();
	this->minute = other.get_minute();
	this->second = other.get_second();
	
	this->is_leap = calculate_leap();
	this->week = calculate_week();
	
	return *this;
}

const bool DateTime::operator ==(const DateTime& other) const
{
	// if value are the same
	// their format string will be the same
	// so use 'string.compare()' function complete this
	bool re = false;
	if(this->to_string().compare(other.to_string()) == 0)
	{
		re = true;
	}
	return re;
}

const bool DateTime::operator !=(const DateTime& other) const
{
	return !(*this == other);
}

const bool DateTime::operator <(const DateTime& other) const
{
	// less then operator overloading
	// if the class need to added to a set or some data structure
	// which need to compare or sort
	// so I decide to implement this
	if(get_year() == other.get_year())
	{
		if(get_month() == other.get_month())
		{
			if(get_day() == other.get_day())
			{
				if(get_hour() == other.get_hour())
				{
					if(get_minute() == other.get_minute())
					{
						return get_second() < other.get_second();
					}
					return get_minute() < other.get_minute();
				}
				return get_hour() < other.get_hour();
			}
			return get_day() < other.get_day();
		}
		return get_month() < other.get_month();
	}
	return get_year() < other.get_year();
}

const bool DateTime::operator >(const DateTime& other) const
{
	return (other < *this);
}

const bool DateTime::operator <=(const DateTime& other) const
{
	return !(*this > other);
}

const bool DateTime::operator >=(const DateTime& other) const
{
	return !(*this < other);
}

ostream& operator <<(ostream& strm, const DateTime& other)
{
	// output stream operator overloading
	// just see function 'to_string()'
	strm << other.to_string();
	return strm;
}

// other function
const DateTime DateTime::next_section()
{
	DateTime *ret;
	const int START_TIME = 19;
	const int HALF_HOUR = 30;
	
	if(get_hour() < START_TIME) // 00:00~18:59
	{
		// set to 19:00
		ret = new DateTime(get_year(), get_month(), get_day(), START_TIME);
	}
	else if(get_hour() == START_TIME || (get_hour() == START_TIME+1 && get_minute() < HALF_HOUR)) // 19:00~20:29
	{
		// set to 20:30
		ret = new DateTime(get_year(), get_month(), get_day(), START_TIME+1, HALF_HOUR);
	}
	else if((get_hour() == START_TIME+1 && get_minute() >= HALF_HOUR) || get_hour() == START_TIME+2) // 20:30~21:59
	{
		// set to 22:00
		ret = new DateTime(get_year(), get_month(), get_day(), START_TIME+3);
	}
	else if(get_hour() == START_TIME+3) // 22:00~22:59
	{
		// set to 23:00
		ret = new DateTime(get_year(), get_month(), get_day(), START_TIME+4);
	}
	else // 23:00~
	{
		// set to 19:00(next day)
		int year = get_year();
		int month = get_month();
		int day = get_day()+1;
		const int DAY_LIMIT = DAY_OF_MONTHS[get_month()]+((is_leap && month==2) ? 1 : 0);
		if(day > DAY_LIMIT)
		{
			day -= DAY_LIMIT;
			month++;
		}
		if(month > 12)
		{
			month -= 12;
			year++;
		}
		ret = new DateTime(year, month, day, START_TIME);
	}
	
	return *ret;
}

const DateTime DateTime::previous_section()
{
	DateTime *ret;
	const int FINISH_TIME = 23;
	const int HALF_HOUR = 30;
	
	if(get_hour() == FINISH_TIME && get_minute() != 0) // 23:01~23:59
	{
		// set to 23:00
		ret = new DateTime(get_year(), get_month(), get_day(), FINISH_TIME);
	}
	else if((get_hour() == FINISH_TIME-1 && get_minute() != 0) || get_hour() == FINISH_TIME) // 22:01~23:00
	{
		// set to 22:00
		ret = new DateTime(get_year(), get_month(), get_day(), FINISH_TIME-1);
	}
	else if((get_hour() == FINISH_TIME-3 && get_minute() > HALF_HOUR) || get_hour() == FINISH_TIME-2 || get_hour() == FINISH_TIME-1) // 20:31~22:00
	{
		// set to 20:30
		ret = new DateTime(get_year(), get_month(), get_day(), FINISH_TIME-3, HALF_HOUR);
	}
	else if((get_hour() == FINISH_TIME-4 && get_minute() != 0) || (get_hour() == FINISH_TIME-3 && get_minute() <= HALF_HOUR)) // 19:01~20:30
	{
		// set to 19:00
		ret = new DateTime(get_year(), get_month(), get_day(), FINISH_TIME-4);
	}
	else // 00:00~19:00
	{
		// set to 23:00(previous day)
		int year = get_year();
		int month = get_month();
		int day = get_day()-1;
		const int DAY_LIMIT = DAY_OF_MONTHS[get_month()-1]+((is_leap && month==3) ? 1 : 0);
		if(day < 1)
		{
			day += DAY_LIMIT;
			month--;
		}
		if(month < 1)
		{
			month += 12;
			year--;
		}
		ret = new DateTime(year, month, day, FINISH_TIME);
	}
	
	return *ret;
}

// static functions
const DateTime DateTime::Now()
{
	// get the current time
	// use tm structure in <ctime>
	// and return the value of now
	time_t t = time(0);
	tm* tt = localtime(&t);
	int year = tt->tm_year+1900;
	int month = tt->tm_mon+1;
	int day = tt->tm_mday;
	int hour = tt->tm_hour;
	int minute = tt->tm_min;
	int second = tt->tm_sec;
	
	DateTime now(year, month, day, hour, minute, second);
	return now;
}

// private functions
void DateTime::check_year()	// check the year between 1900~9999
{
	if(this->year > 9999 || this->year < 1900)
	{
		error("year range must in 1900~9999");
	}
}

void DateTime::check_month() // check the month between 1~12
{
	if((this->month) > 12 || (this->month) < 1)
	{
		error("month range must in 1~12");
	}
}

void DateTime::check_day()	// check the day is in (the amount of month)
{
	if(this->month == 2 && this->is_leap == true)	// if leap year and Feb
	{
		if(this->day > 29)
		{
			error("day range must in 1~"+std::to_string(DAY_OF_MONTHS[this->month]));
		}
	}
	if(this->day > DAY_OF_MONTHS[this->month] || this->day < 1)
	{
		error("day range must in 1~"+std::to_string(DAY_OF_MONTHS[this->month]));
	}
}

void DateTime::check_hour()	// check hour in 0~23
{
	if(this->hour > 23 || this->hour < 0)
	{
		error("hour range must in 0~23");
	}
}

void DateTime::check_minute() // check minute in 0~59
{
	if(this->minute > 59 || this->minute < 0)
	{
		error("minute range must in 0~59");
	}
}

void DateTime::check_second() // check second in 0~59
{
	if(this->second > 59 || this->second < 0)
	{
		error("second range must in 0~59");
	}
}

const Week DateTime::calculate_week() const
{
	// Kim larsson calculation formula
	// w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	int d = get_day();
	int m = get_month();
	int y = get_year();
	if(m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	int w = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;
	/*cout << w << endl;
    switch (w) {
    case 0: 
          printf("Monday\n"); break;
    case 1: 
          printf("Tuesday\n"); break;
    case 2: 
          printf("Wednesday\n"); break;
    case 3: 
          printf("Thursday\n"); break;
    case 4: 
          printf("Friday\n"); break;
    case 5: 
          printf("Saturday\n"); break;
    case 6: 
          printf("Sunday\n"); break;
    }*/
    /*w = (w+1)%7;
	return static_cast<Week>(w);
}

const bool DateTime::calculate_leap() const
{
	// return a boolean value of this year is leap year or not
	int year = get_year();
	if(year%400 == 0)
	{
		return true;
	}
	else if(year%100 == 0)
	{
		return false;
	}
	else if(year%4 == 0)
	{
		return true;
	}
	return false;
}*/
