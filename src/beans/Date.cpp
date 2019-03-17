#include "Date.h"

// ======= Enumeration Week ======= //

std::ostream& voba::operator <<(std::ostream& strm, const Week& week)
{
	switch (week)
	{
		case voba::Week::SUNDAY:
			strm << "Sunday";
			break;
		
		case voba::Week::MONDAY:
			strm << "Monday";
			break;
		
		case voba::Week::TUESDAY:
			strm << "Tuesdy";
			break;
		
		case voba::Week::WEDNESDAY:
			strm << "Wednesday";
			break;
		
		case voba::Week::THURSDAY:
			strm << "Thursday";
			break;
		
		case voba::Week::FRIDAY:
			strm << "Friday";
			break;
		
		case voba::Week::SATURDAY:
			strm << "Saturday";
			break;
		
		default:
			std::cerr << "invalid week" << std::endl;
			break;
	}
	
	return strm;
}

// ======= Class Date ======= //

const std::string voba::Date::CLASS_NAME = "Date";

// constructor
voba::Date::Date(const int year, const int month, const int day)
	: Logable(voba::Date::CLASS_NAME)
{
	// set parameters as member variables
	// check the member variables had set are legel
	// then calculate week value by year, month, and day
	this->year = year;
	this->month = month;
	this->day = day;
	this->check_member_vars();
	this->week = this->calculate_week();
}

voba::Date::Date(const std::string date_str)
	: Logable(voba::Date::CLASS_NAME)
{
	// handle a format date string to object
	static const boost::regex reg("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	if (boost::regex_match(date_str, reg))
	{
		std::vector<std::string> params = voba::Utils::split(date_str, voba::Date::DATE_STRING_SEPERATOR);
		this->year = std::stoi(params[0]);
		this->month = std::stoi(params[1]);
		this->day = std::stoi(params[2]);
		this->check_member_vars();
	}
	else
	{
		this->logger.warning("date string format is not correct");
		this->year = 1900;
		this->month = 1;
		this->day = 1;
		this->check_member_vars();
	}
}

voba::Date::Date(const voba::Date& other)
	: Logable(voba::Date::CLASS_NAME)
{
	// call assign operator for copy constructor
	this->operator=(other);
}

// getters & setters
void voba::Date::set_year(const int year) 
{ 
	// set year value
	// check year value is legel
	// then calculate week value by year, month, and day
	this->year = year;
	this->check_member_vars();
	this->week = this->calculate_week();
}

void voba::Date::set_month(const int month)
{
	// set month value
	// check month value is legel
	// then calculate week value by year, month, and day
	this->month = month;
	this->check_member_vars();
	this->week = this->calculate_week();
}

void voba::Date::set_day(const int day)
{
	// set day value
	// check day value is legel
	// then calculate week value by year, month, and day
	this->day = day;
	this->check_member_vars();
	this->week = this->calculate_week();
}

const int voba::Date::get_year() const
{
	// return year value
	return this->year;
}

const int voba::Date::get_month() const
{
	// return month value
	return this->month;
}

const int voba::Date::get_day() const
{
	// return day value
	return this->day;
}

const voba::Week voba::Date::get_week() const
{
	// return week value
	return this->week;
}

const std::string voba::Date::to_string() const
{
	// call show week type to_string
	return this->to_string(true);
}

const std::string voba::Date::to_string(const bool show_week) const
{
	// transform member variables data into string
	// format: yyyy-mm-dd, week
	std::string re = "";
	
	re += std::to_string(this->get_year());
	re += voba::Date::DATE_STRING_SEPERATOR;
	re += (this->get_month()<10?"0":"")+std::to_string(this->get_month());
	re += voba::Date::DATE_STRING_SEPERATOR;
	re += (this->get_day()<10?"0":"")+std::to_string(this->get_day());
	
	if (show_week)
	{
		re += ", ";
		re += DAY_OF_WEEK[static_cast<int>(get_week())];
	}
	
	return re;
}

// public functions
const voba::Date voba::Date::Now()
{
	// use starndard c library to generate current date
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
	// year plus one then return a new instance
	int year = this->get_year()+1;
	int month = this->get_month();
	int day = this->get_day();
	voba::Date ret(year, month, day);
	return ret;
}

const voba::Date voba::Date::previous_year() const
{
	// year minus one then return a new instance
	int year = this->get_year()-1;
	int month = this->get_month();
	int day = this->get_day();
	voba::Date ret(year, month, day);
	return ret;
}

const voba::Date voba::Date::next_month() const
{
	// month plus one, check if become next year, then return a new instance
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
	// month minus one, check if become previous year, then return a new instance
	bool carry = false;
	
	int year = this->get_year();
	int month = this->get_month()-1;
	int day = this->get_day();
	if (month < 1)
	{
		month += MONTHS_PER_YEAR;
		carry = true;
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
	// day plus one, check if become next month, then return a new instance
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
	// day minus one, check if become next month, then return a new instance
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

const bool voba::Date::operator !=(const voba::Date& other) const 
{
	return !this->operator==(other);
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

const bool voba::Date::operator >(const voba::Date& other) const
{
	return other.operator<(*this);
}

const bool voba::Date::operator <=(const voba::Date& other) const
{
	return !this->operator>(other);
}

const bool voba::Date::operator >=(const voba::Date& other) const
{
	return !this->operator<(other);
}

std::ostream& operator <<(std::ostream& strm, const voba::Date& other)
{
	strm << other.to_string();
	return strm;
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
	// check 
	// 1900 <= year <= 9999
	// 1 <= month <= 12
	// 1 <= day <= days_limit
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
	// if year % 400 = 0 or yaer % 4 = 0, is leap year
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
