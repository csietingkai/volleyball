#include "Time.h"

const std::string voba::Time::CLASS_NAME = "Time";

// constructor
voba::Time::Time(const int hour, const int minute, const int second)
	: Logable(voba::Time::CLASS_NAME)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	this->check_member_vars();
}

voba::Time::Time(const Time& other)
	: Logable(voba::Time::CLASS_NAME)
{
	this->operator=(other);
}

// public function
const std::string voba::Time::to_string() const
{
	std::string re = "";
	
	re += (this->get_hour()<10?"0":"")+std::to_string(this->get_hour())+":";
	re += (this->get_minute()<10?"0":"")+std::to_string(this->get_minute())+":";
	re += (this->get_second()<10?"0":"")+std::to_string(this->get_second());
	
	return re;
}
		
const voba::Time voba::Time::Now()
{
	time_t t = time(0);
	tm* tt = localtime(&t);
	int hour = tt->tm_hour;
	int minute = tt->tm_min;
	int second = tt->tm_sec;
	
	voba::Time now(hour, minute, second);
	return now;
}

const voba::Time voba::Time::next_hour() const
{
	int hour = this->get_hour()+1;
	int minute = this->get_minute();
	int second = this->get_second();
	if (hour >= HOUR_PER_DAY)
	{
		hour -= HOUR_PER_DAY;
	}
	voba::Time ret(hour, minute, second);
	return ret;
}

const voba::Time voba::Time::previous_hour() const
{
	int hour = this->get_hour()-1;
	int minute = this->get_minute();
	int second = this->get_second();
	if (hour < 0)
	{
		hour += HOUR_PER_DAY;
	}
	voba::Time ret(hour, minute, second);
	return ret;
}

const voba::Time voba::Time::next_minute() const
{
	bool carry = false;
	
	int hour = this->get_hour();
	int minute = this->get_minute()+1;
	int second = this->get_second();
	if (minute >= MINUTE_PER_HOUR)
	{
		minute -= MINUTE_PER_HOUR;
		carry = true;
	}
	voba::Time ret(hour, minute, second);
	if (carry)
	{
		ret = ret.next_hour();
	}
	return ret;
}

const voba::Time voba::Time::previous_minute() const
{
	bool carry = false;
	
	int hour = this->get_hour();
	int minute = this->get_minute()-1;
	int second = this->get_second();
	if (minute < 0)
	{
		minute += MINUTE_PER_HOUR;
		carry = true;
	}
	voba::Time ret(hour, minute, second);
	if (carry)
	{
		ret = ret.previous_hour();
	}
	return ret;
}

const voba::Time voba::Time::next_second() const
{
	bool carry = false;
	
	int hour = this->get_hour();
	int minute = this->get_minute();
	int second = this->get_second()+1;
	if (second >= SECOND_PER_MINUTE)
	{
		second -= SECOND_PER_MINUTE;
		carry = true;
	}
	voba::Time ret(hour, minute, second);
	if (carry)
	{
		ret = ret.next_minute();
	}
	return ret;
}

const voba::Time voba::Time::previous_second() const
{
	bool carry = false;
	
	int hour = this->get_hour();
	int minute = this->get_minute();
	int second = this->get_second()-1;
	if (second < 0)
	{
		second += SECOND_PER_MINUTE;
		carry = true;
	}
	voba::Time ret(hour, minute, second);
	if (carry)
	{
		ret = ret.previous_minute();
	}
	return ret;
}

const voba::Time& voba::Time::operator =(const Time& other)
{
	this->hour = other.get_hour();
	this->minute = other.get_minute();
	this->second = other.get_second();
	this->check_member_vars();
	return *this;
}

const bool voba::Time::operator ==(const Time& other) const
{
	bool ret = true;
	ret = ret && (this->hour == other.get_hour());
	ret = ret && (this->minute == other.get_minute());
	ret = ret && (this->second == other.get_second());
	return ret;
}

const bool voba::Time::operator <(const Time& other) const
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

// private function
void voba::Time::check_member_vars()
{
	// TODO use 'logger.error' or 'assert' or both?
	assert(this->hour < HOUR_PER_DAY && this->hour >= 0);
	assert(this->minute < MINUTE_PER_HOUR && this->minute >= 0);
	assert(this->second < SECOND_PER_MINUTE && this->second >= 0);
}
