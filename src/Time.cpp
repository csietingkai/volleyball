#include "Time.h"

// constructors
Time::Time(const int hour, const int minute, const int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	this->check_member_vars();
}

Time::Time(const Time& other)
{
	this->operator=(other);
}

// setters
void Time::set_hour(const int hour)
{
	this->hour = hour;
	this->check_member_vars();
}

void Time::set_minute(const int minute)
{
	this->minute = minute;
	this->check_member_vars();
}

void Time::set_second(const int second)
{
	this->second = second;
	this->check_member_vars();
}

// getters
const int Time::get_hour() const
{
	return this->hour;
}

const int Time::get_minute() const
{
	return this->minute;
}

const int Time::get_second() const
{
	return this->second;
}

const string Time::to_string() const
{
	string re = "";
	
	re += (get_hour()<10?"0":"")+std::to_string(get_hour())+":";
	re += (get_minute()<10?"0":"")+std::to_string(get_minute())+":";
	re += (get_second()<10?"0":"")+std::to_string(get_second());
	
	return re;
}

// static
const Time Time::Now()
{
	time_t t = time(0);
	tm* tt = localtime(&t);
	int hour = tt->tm_hour;
	int minute = tt->tm_min;
	int second = tt->tm_sec;
	
	Time now(hour, minute, second);
	return now;
}


// operators
const Time& Time::operator =(const Time& other)
{
	this->hour = other.get_hour();
	this->minute = other.get_minute();
	this->second = other.get_second();
	this->check_member_vars();
	return *this;
}

const bool Time::operator ==(const Time& other) const
{
	bool ret = true;
	ret = ret && (this->hour == other.get_hour());
	ret = ret && (this->minute == other.get_minute());
	ret = ret && (this->second == other.get_second());
	return ret;
}

const bool Time::operator !=(const Time& other) const
{
	return !this->operator==(other);
}

const bool Time::operator <(const Time& other) const
{
	bool ret = this->get_hour() < other.get_hour();
	if(this->get_hour() == other.get_hour())
	{
		ret = this->get_minute() < other.get_minute();
		if(this->get_minute() == other.get_minute())
		{
			ret = this->get_second() < other.get_second();
		}
	}
	return ret;
}

const bool Time::operator >(const Time& other) const
{return other.operator<(*this);
}

const bool Time::operator <=(const Time& other) const
{
	return !this->operator>(other);
}

const bool Time::operator >=(const Time& other) const
{
	return !this->operator<(other);
}

ostream& operator <<(ostream& strm, const Time& other)
{
	strm << other.to_string();
	return strm;
}

// private
void Time::check_member_vars()
{
	// TODO use 'logger.error' or 'assert' or both?
	assert(this->hour <= 23 && this->hour >= 0);
	assert(this->minute <= 60 && this->minute >= 0);
	assert(this->second <= 60 && this->second >= 0);
}
