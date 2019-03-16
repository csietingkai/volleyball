#include "Time.h"

// ======= Class Time ======= //

const std::string voba::Time::CLASS_NAME = "Time";

// constructor
voba::Time::Time(const int hour, const int minute, const int second)
	: Logable(voba::Time::CLASS_NAME)
{
	// set parameters as member variables
	// check the member variables had set are legel
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	this->check_member_vars();
}

voba::Time::Time(const std::string time_str)
	: Logable(voba::Time::CLASS_NAME)
{
	// handle a format time string to object
	static const boost::regex reg("[0-9]{2}:[0-9]{2}:[0-9]{2}");
	if (boost::regex_match(time_str, reg))
	{
		std::vector<std::string> params = voba::Utils::split(time_str, voba::Time::TIME_STRING_SEPERATOR);
		this->hour = std::stoi(params[0]);
		this->minute = std::stoi(params[1]);
		this->second = std::stoi(params[2]);
		this->check_member_vars();
	}
	else
	{
		this->logger.warning("time string format is not correct");
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
		this->check_member_vars();
	}
}

voba::Time::Time(const Time& other)
	: Logable(voba::Time::CLASS_NAME)
{
	// call assign operator for copy constructor
	this->operator=(other);
}

// getters & setters
void voba::Time::set_hour(const int hour)
{ 
	// set hour value
	// check hour value is legel
	this->hour = hour;
	this->check_member_vars();
}

void voba::Time::set_minute(const int minute)
{
	// set minute value
	// check minute value is legel
	this->minute = minute;
	this->check_member_vars();
}

void voba::Time::set_second(const int second)
{
	// set second value
	// check second value is legel
	this->second = second;
	this->check_member_vars();
}

const int voba::Time::get_hour() const
{
	// return hour value
	return this->hour;
}

const int voba::Time::get_minute() const
{
	// return minute value
	return this->minute;
}

const int voba::Time::get_second() const
{ 
	// return second value
	return this->second;
}

const std::string voba::Time::to_string() const
{
	// transform member variables data into string
	// format: hh:mm:ss
	std::string re = "";
	
	re += (this->get_hour()<10?"0":"")+std::to_string(this->get_hour());
	re += voba::Time::TIME_STRING_SEPERATOR;
	re += (this->get_minute()<10?"0":"")+std::to_string(this->get_minute());
	re += voba::Time::TIME_STRING_SEPERATOR;
	re += (this->get_second()<10?"0":"")+std::to_string(this->get_second());
	
	return re;
}
	
// public function	
const voba::Time voba::Time::Now()
{
	// use starndard c library to generate current time
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
	// hour plus one then return a new instance
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
	// hour minus one then return a new instance
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
	// minute plus one then return a new instance
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
	// minute minus one then return a new instance
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
	// second plus one then return a new instance
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
	// second minus one then return a new instance
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

const voba::Time& voba::Time::operator =(const voba::Time& other)
{
	this->hour = other.get_hour();
	this->minute = other.get_minute();
	this->second = other.get_second();
	this->check_member_vars();
	return *this;
}

const bool voba::Time::operator ==(const voba::Time& other) const
{
	bool ret = true;
	ret = ret && (this->hour == other.get_hour());
	ret = ret && (this->minute == other.get_minute());
	ret = ret && (this->second == other.get_second());
	return ret;
}

const bool voba::Time::operator !=(const voba::Time& other) const
{
	return !this->operator==(other);
}

const bool voba::Time::operator <(const voba::Time& other) const
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

const bool voba::Time::operator >(const voba::Time& other) const
{
	return other.operator<(*this);
}

const bool voba::Time::operator <=(const voba::Time& other) const
{
	return !this->operator>(other);
}

const bool voba::Time::operator >=(const voba::Time& other) const
{
	return !this->operator<(other);
}

// private function
void voba::Time::check_member_vars()
{
	// TODO use 'logger.error' or 'assert' or both?
	// check 
	// 0 <= hour < 24
	// 0 <= minute < 60
	// 0 <= second < 60
	assert(this->hour < HOUR_PER_DAY && this->hour >= 0);
	assert(this->minute < MINUTE_PER_HOUR && this->minute >= 0);
	assert(this->second < SECOND_PER_MINUTE && this->second >= 0);
}
