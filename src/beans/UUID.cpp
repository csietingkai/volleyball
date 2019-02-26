#include "UUID.h"

voba::UUID::UUID()
{
	this->id = "00000000-0000-0000-0000-000000000000";
}

voba::UUID::UUID(const std::string str)
{
	if (this->is_valid(str))
	{
		this->id = str;
	}
	else
	{
		this->id = "00000000-0000-0000-0000-000000000000";
	}
}

const voba::UUID& voba::UUID::random_uuid()
{
	UUID *uuid = new UUID();
	boost::uuids::random_generator generator;
	boost::uuids::uuid buuid = generator();
	uuid->id = boost::uuids::to_string(buuid);
	return *uuid;
}

const voba::UUID& voba::UUID::from_string(const std::string str)
{
	UUID *uuid = new UUID(str);
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
};
