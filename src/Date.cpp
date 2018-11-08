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
	this->year = other.get_year();
	this->month = other.get_month();
	this->day = other.get_day();
	this->check_member_vars();
	this->week = this->calculate_week();
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

// operators
// static
// private
void Date::check_member_vars()
{
	assert(this->year > 9999 || this->year < 1900);
	assert(this->month > 12 || this->month < 1);
	if(this->month == 2 && this->is_leap == true)	// if leap year and Feb
	{
		assert(this->day > DAY_OF_MONTHS[this->month]+1 || this->day < 1);
	}
	else
	{
		assert(this->day > DAY_OF_MONTHS[this->month] || this->day < 1);
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

