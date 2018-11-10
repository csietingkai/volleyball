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
}

const DateTime DateTime::previous_section()
{
}

