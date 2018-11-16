#include "DateeTime.h"

// constructors
DateeTime::DateeTime(const Datee date, const Time time)
	: date(date)
	, time(time)
{
}

DateeTime::DateeTime(const DateeTime& DateeTime)
{
	this->operator=(DateeTime);
}

// setters
void DateeTime::set_date(const Datee date)
{
	this->date = date;
}

void DateeTime::set_time(const Time time)
{
	this->time = time;
}

// getters
const Datee DateeTime::get_date() const
{
	return this->date;
}

const Time DateeTime::get_time() const
{
	return this->time;
}

const string DateeTime::to_string() const
{
	return this->date.to_string()+" "+this->time.to_string();
}

// static
const DateeTime DateeTime::Now()
{
	Datee dnow = Datee::Now();
	Time tnow = Time::Now();
	DateeTime dtnow(dnow, tnow);
	return dtnow;
}

// operators
const DateeTime& DateeTime::operator =(const DateeTime& other)
{
	this->date = other.get_date();
	this->time = other.get_time();
	return *this;
}

const bool DateeTime::operator ==(const DateeTime& other) const
{
	bool ret = true;
	ret = ret && (this->get_date() == other.get_date());
	ret = ret && (this->get_time() == other.get_time());
	return ret;
}

const bool DateeTime::operator !=(const DateeTime& other) const
{
	return !this->operator==(other);
}

const bool DateeTime::operator <(const DateeTime& other) const
{
	bool ret = this->get_date() < other.get_date();
	if(this->get_date() == other.get_date())
	{
		ret = this->get_time() < other.get_time();
	}
	return ret;
}

const bool DateeTime::operator >(const DateeTime& other) const
{
	return other.operator<(*this);
}

const bool DateeTime::operator <=(const DateeTime& other) const
{
	return !this->operator>(other);
}

const bool DateeTime::operator >=(const DateeTime& other) const
{
	return !this->operator<(other);
}

ostream& operator <<(ostream& strm, const DateeTime& other)
{
	strm << other.to_string();
	return strm;
}

// other functions
const DateeTime DateeTime::next_section()
{
	Datee date = this->date;
	Time time = this->time;
	
	// 00:00~18:59
	if (time < GAME_TIME_SECTIONS[0])
	{
		time = GAME_TIME_SECTIONS[0];
	}
	// 19:00~20:29
	else if (time >= GAME_TIME_SECTIONS[0] && time < GAME_TIME_SECTIONS[1])
	{
		time = GAME_TIME_SECTIONS[1];
	}
	// 20:30~21:59
	else if (time >= GAME_TIME_SECTIONS[1] && time < GAME_TIME_SECTIONS[2])
	{
		time = GAME_TIME_SECTIONS[2];
	}
	// 22:00~22:59
	else if (time >= GAME_TIME_SECTIONS[2] && time < GAME_TIME_SECTIONS[3])
	{
		time = GAME_TIME_SECTIONS[3];
	}
	// 23:00~23:59
	else
	{
		time = GAME_TIME_SECTIONS[0];
		date = date.next_day();
	}
	
	DateeTime ret(date, time);
	return ret;
}

const DateeTime DateeTime::previous_section()
{
	Datee date = this->date;
	Time time = this->time;
	
	// 00:00~19:00
	if (time <= GAME_TIME_SECTIONS[0])
	{
		time = GAME_TIME_SECTIONS[3];
		date = date.previous_day();
	}
	// 19:01~20:30
	else if (time > GAME_TIME_SECTIONS[0] && time <= GAME_TIME_SECTIONS[1])
	{
		time = GAME_TIME_SECTIONS[0];
	}
	// 20:31~22:00
	else if (time > GAME_TIME_SECTIONS[1] && time <= GAME_TIME_SECTIONS[2])
	{
		time = GAME_TIME_SECTIONS[1];
	}
	// 22:01~23:00
	else if (time > GAME_TIME_SECTIONS[2] && time <= GAME_TIME_SECTIONS[3])
	{
		time = GAME_TIME_SECTIONS[2];
	}
	// 23:00~23:59
	else
	{
		time = GAME_TIME_SECTIONS[3];
	}
	
	DateeTime ret(date, time);
	return ret;
}
