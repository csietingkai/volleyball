#ifndef TEST_H_
#define TEST_H_

#include <assert.h>
#include <iostream>

#include "../src/beans/DateTime.h"

namespace voba
{
	void test_main();
	
	void test_beans();
	void test_date();
	void test_datetime();
	void test_time();
	
	void test_models();
	void test_game();
	void test_person();
	void test_team();
	
	void test_tools();
	void test_logger();
	void test_connector();
	void test_sqlcommandbuilder();
	
	void test_utils();
	void test_serverinfo();
	void test_util();
}

#endif // TEST_H_
