#include "Date.h"

const std::string voba::Date::CLASS_NAME = "Date";

// constructor
voba::Date::Date(const int year, const int month, const int day)
	: logger(voba::Date::CLASS_NAME)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->check_member_vars();
	this->week = this->calculate_week();
}

voba::Date::Date(const voba::Date& other)
	: logger(voba::Date::CLASS_NAME)
{
	this->operator=(other);
}

// public function
const std::string voba::Date::to_string() const
{
	// format: yyyy-mm-dd, week
	std::string re = "";
	
	re += std::to_string(this->get_year())+"-";
	re += (this->get_month()<10?"0":"")+std::to_string(this->get_month())+"-";
	re += (this->get_day()<10?"0":"")+std::to_string(this->get_day())+", ";
	
	re += DAY_OF_WEEK[static_cast<int>(get_week())];
	
	return re;
}

const voba::Date& voba::Date::operator =(const voba::Date& other)
{
	this->year = other.get_year();
	this->month = other.get_month();
	this->day = other.get_day();
	this->check_member_vars();
	this->week = this->calculate_week();
	return *this;
}

const bool voba::Date::operator ==(const voba::Date& other) const
{
	bool ret = true;
	ret = ret && (this->get_year() == other.get_year());
	ret = ret && (this->get_month() == other.get_month());
	ret = ret && (this->get_day() == other.get_day());
	return ret;
}

const bool voba::Date::operator <(const voba::Date& other) const
{
	bool ret = this->get_year() < other.get_year();
	if(this->get_year() == other.get_year())
	{
		ret = this->get_month() < other.get_month();
		if(this->get_month() == other.get_month())
		{
			ret = this->get_day() < other.get_day();
		}
	}
	return ret;
}

std::ostream& operator <<(std::ostream& strm, const voba::Date& other)
{
	strm << other.to_string();
	return strm;
}

const voba::Date voba::Date::Now()
{
	time_t t = time(0);
	tm* tt = localtime(&t);
	int year = tt->tm_year+1900;
	int month = tt->tm_mon+1;
	int day = tt->tm_mday;
	
	voba::Date now(year, month, day);
	return now;
}

const voba::Date voba::Date::next_year() const
{
	int year = this->get_year()+1;
	int month = this->get_month();
	int day = this->get_day();
	voba::Date ret(year, month, day);
	return ret;
}

const voba::Date voba::Date::previous_year() const
{
	int year = this->get_year()-1;
	int month = this->get_month();
	int day = this->get_day();
	voba::Date ret(year, month, day);
	return ret;
}

const voba::Date voba::Date::next_month() const
{
	bool carry = false;
	int year = this->get_year();
	int month = this->get_month()+1;
	int day = this->get_day();
	if (month >= MONTHS_PER_YEAR)
	{
		month -= MONTHS_PER_YEAR;
		carry = true;
	}
	voba::Date ret(year, month, day);
	if (carry)
	{
		ret = ret.next_year();
	}
	return ret;
}

const voba::Date voba::Date::previous_month() const
{
	bool carry = false;
	
	int year = this->get_year();
	int month = this->get_month()-1;
	int day = this->get_day();
	if (month < 1)
	{
		month += MONTHS_PER_YEAR;
	}
	voba::Date ret(year, month, day);
	if (carry)
	{
		ret = ret.previous_year();
	}
	return ret;
}

const voba::Date voba::Date::next_day() const
{
	bool carry = false;
	
	int year = this->get_year();
	int month = this->get_month();
	int day = this->get_day()+1;
	int days_limit = DAYS_PER_MONTH[month]+((this->is_leap && month == 2) ? 1 : 0);
	if (day > days_limit)
	{
		day -= days_limit;
		carry = true;
	}
	voba::Date ret(year, month, day);
	if (carry)
	{
		ret = ret.next_month();
	}
	return ret;
}

const voba::Date voba::Date::previous_day() const
{
	bool carry = false;
	
	int year = this->get_year();
	int month = this->get_month();
	int day = this->get_day()-1;
	int days_limit = DAYS_PER_MONTH[month]+((this->is_leap && month == 3) ? 1 : 0);
	if (day < 1)
	{
		day += days_limit;
		carry = true;
	}
	voba::Date ret(year, month, day);
	if (carry)
	{
		ret = ret.previous_month();
	}
	return ret;
}

// private function
const int voba::Date::DAYS_PER_MONTH[] = 
{
	31,				// Dec,
	31, 28, 31, 	// Jan, Feb, Mar
	30, 31, 30, 	// Apr, May, Jun
	31, 31, 30, 	// Jul, Aug, Sept
	31, 30, 31		// Oct, Nov, Dec
};

void voba::Date::check_member_vars()
{
	// TODO use 'logger.error' or 'assert' or both?
	assert(this->get_year() <= YEAR_UPPER_LIMIT && this->get_year() >= YEAR_LOWER_LIMIT);
	assert(this->get_month() <= MONTHS_PER_YEAR && this->get_month() >= 1);
	if(this->get_month() == 2 && this->is_leap == true)	// if leap year and Feb
	{
		assert(this->get_day() <= DAYS_PER_MONTH[this->get_month()]+1 && this->get_day() >= 1);
	}
	else
	{
		assert(this->get_day() <= DAYS_PER_MONTH[this->get_month()] && this->get_day() >= 1);
	}
}

const bool voba::Date::calculate_leap() const
{
	// return a boolean value of this year is leap year or not
	int year = this->get_year();
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
}

const voba::Week voba::Date::calculate_week() const
{
	// Kim larsson calculation formula
	// w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	int d = this->get_day();
	int m = this->get_month();
	int y = this->get_year();
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
    w = (w+1)%7;
	return static_cast<voba::Week>(w);
}
