#include "UUID.h"

voba::UUID::UUID()
{
	boost::uuids::random_generator generator;
	boost::uuids::uuid uuid = generator();
	this->id = boost::uuids::to_string(uuid);
}

voba::UUID::UUID(const std::string str)
{
	if (this->is_valid(str))
	{
		this->id = str;
	}
}

const voba::UUID& voba::UUID::random_uuid()
{
	UUID *uuid = new UUID();
	return *uuid;
}

const voba::UUID& voba::UUID::operator =(const voba::UUID& other) 
{ 
	this->id = other.to_string();
	return *this;
}

const bool voba::UUID::is_valid(std::string str)
{
	static const boost::regex reg("[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12}");
	return boost::regex_match(str, reg);
}
