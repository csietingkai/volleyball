#include "DateTime.h"

// ======= Class GAME_TIME ======= //

const voba::Time voba::GAME_TIME::FIRST_SECTION(19, 0, 0);
const voba::Time voba::GAME_TIME::SECOND_SECTION(20, 30, 0);
const voba::Time voba::GAME_TIME::THIRD_SECTION(22, 0, 0);
const voba::Time voba::GAME_TIME::FORTH_SECTION(23, 0, 0);

// ======= Class DateTime ======= //
const std::string voba::DateTime::CLASS_NAME = "DateTime";

// constructors
voba::DateTime::DateTime(const voba::Date date, const voba::Time time)
	: Logable(voba::DateTime::CLASS_NAME)
{
	// set parameters as member variables
	this->date = date;
	this->time = time;
}

voba::DateTime::DateTime(const voba::DateTime& datetime)
	: Logable(voba::DateTime::CLASS_NAME)
{
	// call assign operator for copy constructor
	this->operator=(datetime);
}

// getters & setters
void voba::DateTime::set_date(const voba::Date date)
{
	// set date value
	this->date = date;
}

void voba::DateTime::set_time(const voba::Time time)
{
	// set time value
	this->time = time;
}

const voba::Date voba::DateTime::get_date() const
{
	// return date value
	return this->date;
}

const voba::Time voba::DateTime::get_time() const
{
	// return time value
	return this->time;
}

const std::string voba::DateTime::to_string() const
{
	// transform member variables data into string
	// format: yyyy-mm-dd, week hh:mm:ss
	return this->date.to_string()+" "+this->time.to_string();
}

// public function
const voba::DateTime voba::DateTime::Now()
{
	// call date's now and time's now and combine
	voba::Date dnow = voba::Date::Now();
	voba::Time tnow = voba::Time::Now();
	voba::DateTime dtnow(dnow, tnow);
	return dtnow;
}

const voba::DateTime voba::DateTime::next_section()
{
	// find the next range in the list of GAME_TIME
	voba::Date date = this->date;
	voba::Time time = this->time;
	
	// 00:00~18:59
	if (time < voba::GAME_TIME::FIRST_SECTION)
	{
		time = voba::GAME_TIME::FIRST_SECTION;
	}
	// 19:00~20:29
	else if (time >= voba::GAME_TIME::FIRST_SECTION && time < voba::GAME_TIME::SECOND_SECTION)
	{
		time = voba::GAME_TIME::SECOND_SECTION;
	}
	// 20:30~21:59
	else if (time >= voba::GAME_TIME::SECOND_SECTION && time < voba::GAME_TIME::THIRD_SECTION)
	{
		time = voba::GAME_TIME::THIRD_SECTION;
	}
	// 22:00~22:59
	else if (time >= voba::GAME_TIME::THIRD_SECTION && time < voba::GAME_TIME::FORTH_SECTION)
	{
		time = voba::GAME_TIME::FORTH_SECTION;
	}
	// 23:00~23:59
	else
	{
		time = voba::GAME_TIME::FIRST_SECTION;
		date = date.next_day();
	}
	
	voba::DateTime ret(date, time);
	return ret;
}

const voba::DateTime voba::DateTime::previous_section()
{
	// find the previous range in the list of GAME_TIME
	voba::Date date = this->date;
	voba::Time time = this->time;
	
	// 00:00~19:00
	if (time <= voba::GAME_TIME::FIRST_SECTION)
	{
		time = voba::GAME_TIME::FORTH_SECTION;
		date = date.previous_day();
	}
	// 19:01~20:30
	else if (time > voba::GAME_TIME::FIRST_SECTION && time <= voba::GAME_TIME::SECOND_SECTION)
	{
		time = voba::GAME_TIME::FIRST_SECTION;
	}
	// 20:31~22:00
	else if (time > voba::GAME_TIME::SECOND_SECTION && time <= voba::GAME_TIME::THIRD_SECTION)
	{
		time = voba::GAME_TIME::SECOND_SECTION;
	}
	// 22:01~23:00
	else if (time > voba::GAME_TIME::THIRD_SECTION && time <= voba::GAME_TIME::FORTH_SECTION)
	{
		time = voba::GAME_TIME::THIRD_SECTION;
	}
	// 23:00~23:59
	else
	{
		time = voba::GAME_TIME::FORTH_SECTION;
	}
	
	voba::DateTime ret(date, time);
	return ret;
}

const voba::DateTime& voba::DateTime::operator =(const voba::DateTime& other)
{
	this->date = other.get_date();
	this->time = other.get_time();
	return *this;
}

const bool voba::DateTime::operator ==(const voba::DateTime& other) const
{
	bool ret = true;
	ret = ret && (this->get_date() == other.get_date());
	ret = ret && (this->get_time() == other.get_time());
	return ret;
}

const bool voba::DateTime::operator !=(const voba::DateTime& other) const
{
	return !this->operator==(other);
}

const bool voba::DateTime::operator <(const voba::DateTime& other) const
{
	bool ret = this->get_date() < other.get_date();
	if(this->get_date() == other.get_date())
	{
		ret = this->get_time() < other.get_time();
	}
	return ret;
}

const bool voba::DateTime::operator >(const voba::DateTime& other) const
{
	return other.operator<(*this);
}

const bool voba::DateTime::operator <=(const voba::DateTime& other) const
{
	return !this->operator>(other);
}

const bool voba::DateTime::operator >=(const voba::DateTime& other) const
{
	return !this->operator<(other);
}

std::ostream& operator <<(std::ostream& strm, const voba::DateTime& other)
{
	strm << other.to_string();
	return strm;
}
