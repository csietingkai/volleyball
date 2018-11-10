#include "Date.h"

// constructors
Date::Date(const int year, const int month, const int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->check_member_vars();
	this->week = this->calculate_week();
}

Date::Date(const Date& other)
{
	this->operator=(other);
}

// setters
void Date::set_year(const int year)
{
	this->year = year;
	this->check_member_vars();
	this->week = this->calculate_week();
}

void Date::set_month(const int month)
{
	this->month = month;
	this->check_member_vars();
	this->week = this->calculate_week();
}

void Date::set_day(const int day)
{
	this->day = day;
	this->check_member_vars();
	this->week = this->calculate_week();
}

// getters
const int Date::get_year() const
{
	return this->year;
}

const int Date::get_month() const
{
	return this->month;
}

const int Date::get_day() const
{
	return this->day;
}

const Week Date::get_week() const
{
	return this->week;
}

const string Date::to_string() const
{
	// format: yyyy-mm-dd, week
	string re = "";
	
	re += std::to_string(get_year())+"-";
	re += (this->get_month()<10?"0":"")+std::to_string(this->get_month())+"-";
	re += (this->get_day()<10?"0":"")+std::to_string(this->get_day())+", ";
	
	re += DAY_OF_WEEK[static_cast<int>(get_week())];
	
	return re;
}

// operators
const Date& Date::operator =(const Date& other)
{
	this->year = other.get_year();
	this->month = other.get_month();
	this->day = other.get_day();
	this->check_member_vars();
	this->week = this->calculate_week();
	return *this;
}

const bool Date::operator ==(const Date& other) const
{
	bool ret = true;
	ret = ret && (this->year == other.get_year());
	ret = ret && (this->month == other.get_month());
	ret = ret && (this->day == other.get_day());
	return ret;
}

const bool Date::operator !=(const Date& other) const
{
	return !this->operator==(other);
}

const bool Date::operator <(const Date& other) const
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

const bool Date::operator >(const Date& other) const
{
	return other.operator<(*this);
}

const bool Date::operator <=(const Date& other) const
{
	return !this->operator>(other);
}

const bool Date::operator >=(const Date& other) const
{
	return !this->operator<(other);
}

ostream& operator <<(ostream& strm, const Date& other)
{
	strm << other.to_string();
	return strm;
}

// static
const Date Date::Now()
{
	time_t t = time(0);
	tm* tt = localtime(&t);
	int year = tt->tm_year+1900;
	int month = tt->tm_mon+1;
	int day = tt->tm_mday;
	
	Date now(year, month, day);
	return now;
}

// private
void Date::check_member_vars()
{
	assert(this->year <= 9999 && this->year >= 1900);
	assert(this->month <= 12 && this->month >= 1);
	if(this->month == 2 && this->is_leap == true)	// if leap year and Feb
	{
		assert(this->day <= DAY_OF_MONTHS[this->month]+1 && this->day >= 1);
	}
	else
	{
		assert(this->day <= DAY_OF_MONTHS[this->month] && this->day >= 1);
	}
}

const bool Date::calculate_leap() const
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
}

const Week Date::calculate_week() const
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
    w = (w+1)%7;
	return static_cast<Week>(w);
}

