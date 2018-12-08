#include "Person.h"

const std::string voba::Person::CLASS_NAME = "Person";

// constructor
voba::Person::Person()
	: connector(voba::Person::CLASS_NAME)
	, logger(voba::Person::CLASS_NAME)
{
	
}


