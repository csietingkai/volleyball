#include "DateTime.h"

// constructors
DateTime::DateTime(const Datee date, const Time time)
{
	this->date = date;
	this->time = time;
}

DateTime::DateTime(const DateTime& datetime)
{
	this->operator=(datetime);
}

// setters
void DateTime::set_date(const Datee date)
{
	this->date = date;
}

void DateTime::set_time(const Time time)
{
	this->time = time;
}

// getters
const Datee DateTime::get_date() const
{
	return this->date;
}

const Time DateTime::get_time() const
{
	return this->time;
}

const string DateTime::to_string() const
{
	return this->date.to_string()+" "+this->time.to_string();
}

// static
const DateTime DateTime::Now()
{
	Datee dnow = Datee::Now();
	Time tnow = Time::Now();
	DateTime dtnow(dnow, tnow);
	return dtnow;
}

// operators
const DateTime& DateTime::operator =(const DateTime& other)
{
	this->date = other.get_date();
	this->time = other.get_time();
	return *this;
}

const bool DateTime::operator ==(const DateTime& other) const
{
	bool ret = true;
	ret = ret && (this->get_date() == other.get_date());
	ret = ret && (this->get_time() == other.get_time());
	return ret;
}

const bool DateTime::operator !=(const DateTime& other) const
{
	return !this->operator==(other);
}

const bool DateTime::operator <(const DateTime& other) const
{
	bool ret = this->get_date() < other.get_date();
	if(this->get_date() == other.get_date())
	{
		ret = this->get_time() < other.get_time();
	}
	return ret;
}

const bool DateTime::operator >(const DateTime& other) const
{
	return other.operator<(*this);
}

const bool DateTime::operator <=(const DateTime& other) const
{
	return !this->operator>(other);
}

const bool DateTime::operator >=(const DateTime& other) const
{
	return !this->operator<(other);
}

ostream& operator <<(ostream& strm, const DateTime& other)
{
	strm << other.to_string();
	return strm;
}

// other functions
const DateTime DateTime::next_section()
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
	
	DateTime ret(date, time);
	return ret;
}

const DateTime DateTime::previous_section()
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
	
	DateTime ret(date, time);
	return ret;
}

// private
const Time DateTime::GAME_TIME_SECTIONS[] = 
{
	{19, 0, 0}, 
	{20, 30, 0}, 
	{22, 0, 0},
	{23, 0, 0}
};

