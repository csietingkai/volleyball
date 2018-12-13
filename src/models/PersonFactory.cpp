#include "PersonFactory.h"

voba::MySQLConnector<voba::Person> voba::PersonFactory::connector;

const voba::Person& voba::PersonFactory::create()
{
	voba::PersonFactory::connector.remove();
	Person *p = new Person("test1", 21, voba::Gender::male, "0987654321", voba::ActiveStatus::active);
	return *p;
}
