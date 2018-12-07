#ifndef TEST_H_
#define TEST_H_

#include <assert.h>
#include <iostream>

#include "../src/beans/DateTime.h"
#include "../src/models/Person.h"
#include "../src/tools/MySQLConnector.h"

namespace voba
{
	void test_main();
	
	void test_tools();
	void test_connector();
}

#endif // TEST_H_
