#include "test.h"

void voba::test_main()
{
	voba::test_tools();
}

void voba::test_tools()
{
	voba::test_connector();
}

void voba::test_connector()
{
	voba::MySQLConnector<voba::Person> connector;
}
