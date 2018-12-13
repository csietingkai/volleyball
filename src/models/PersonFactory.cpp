#include "PersonFactory.h"

const voba::Person& voba::PersonFactory::create()
{
	Person *p = new Person("test1", 21, voba::Gender::male, "0987654321", voba::ActiveStatus::active);
	return *p;
}
