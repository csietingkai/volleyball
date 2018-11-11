#include "Datee.h"

// constructors
Datee::Datee(const int year, const int month, const int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->check_member_vars();
	this->week = this->calculate_week();
}

Datee::Datee(const Datee& other)
{
	this->operator=(other);
}

// setters
void Datee::set_year(const int year)
{
	this->year = year;
	this->check_member_vars();
	this->week = this->calculate_week();
}

void Datee::set_month(const int month)
{
	this->month = month;
	this->check_member_vars();
	this->week = this->calculate_week();
}

void Datee::set_day(const int day)
{
	this->day = day;
	this->check_member_vars();
	this->week = this->calculate_week();
}

// getters
const int Datee::get_year() const
{
	return this->year;
}

const int Datee::get_month() const
{
	return this->month;
}

const int Datee::get_day() const
{
	return this->day;
}

const Week Datee::get_week() const
{
	return this->week;
}

const string Datee::to_string() const
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
const Datee& Datee::operator =(const Datee& other)
{
	this->year = other.get_year();
	this->month = other.get_month();
	this->day = other.get_day();
	this->check_member_vars();
	this->week = this->calculate_week();
	return *this;
}

const bool Datee::operator ==(const Datee& other) const
{
	bool ret = true;
	ret = ret && (this->get_year() == other.get_year());
	ret = ret && (this->get_month() == other.get_month());
	ret = ret && (this->get_day() == other.get_day());
	return ret;
}

const bool Datee::operator !=(const Datee& other) const
{
	return !this->operator==(other);
}

const bool Datee::operator <(const Datee& other) const
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

const bool Datee::operator >(const Datee& other) const
{
	return other.operator<(*this);
}

const bool Datee::operator <=(const Datee& other) const
{
	return !this->operator>(other);
}

const bool Datee::operator >=(const Datee& other) const
{
	return !this->operator<(other);
}

ostream& operator <<(ostream& strm, const Datee& other)
{
	strm << other.to_string();
	return strm;
}

// static
const Datee Datee::Now()
{
	time_t t = time(0);
	tm* tt = localtime(&t);
	int year = tt->tm_year+1900;
	int month = tt->tm_mon+1;
	int day = tt->tm_mday;
	
	Datee now(year, month, day);
	return now;
}

// other functions
const Datee Datee::next_year() const
{
	int year = this->get_year()+1;
	int month = this->get_month();
	int day = this->get_day();
	Datee ret(year, month, day);
	return ret;
}

const Datee Datee::previous_year() const
{
	int year = this->get_year()-1;
	int month = this->get_month();
	int day = this->get_day();
	Datee ret(year, month, day);
	return ret;
}

const Datee Datee::next_month() const
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
	Datee ret(year, month, day);
	if (carry)
	{
		ret = ret.next_year();
	}
	return ret;
}

const Datee Datee::previous_month() const
{
	bool carry = false;
	
	int year = this->get_year();
	int month = this->get_month()-1;
	int day = this->get_day();
	if (month < 1)
	{
		month += MONTHS_PER_YEAR;
	}
	Datee ret(year, month, day);
	if (carry)
	{
		ret = ret.previous_year();
	}
	return ret;
}

const Datee Datee::next_day() const
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
	Datee ret(year, month, day);
	if (carry)
	{
		ret = ret.next_month();
	}
	return ret;
}

const Datee Datee::previous_day() const
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
	Datee ret(year, month, day);
	if (carry)
	{
		ret = ret.previous_month();
	}
	return ret;
}

// private
const int Datee::DAYS_PER_MONTH[] = 
{
	31,				// Dec,
	31, 28, 31, 	// Jan, Feb, Mar
	30, 31, 30, 	// Apr, May, Jun
	31, 31, 30, 	// Jul, Aug, Sept
	31, 30, 31		// Oct, Nov, Dec
};

void Datee::check_member_vars()
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

const bool Datee::calculate_leap() const
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

const Week Datee::calculate_week() const
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

