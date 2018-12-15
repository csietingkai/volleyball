#include "PersonFactory.h"

voba::MySQLConnector<voba::Person> voba::PersonFactory::connector;

const voba::Person& voba::PersonFactory::create()
{
	return voba::PersonFactory::connector.select("id");
}
