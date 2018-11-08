#include "test.h"

void test_common()
{
	string uuid1 = generate_uuid();
	string uuid2 = generate_uuid();
	// two uuids above must be equal
	assert(uuid1.compare(uuid2) != 0);
	
	string before_replace = "the string before replace";
	string after_replace = "the string after replace";
	replace(before_replace, "before", "after");
	assert(after_replace.compare(before_replace) == 0);
	
	string before_trim = "     test trim       ";
	string after_trim = "test trim";
	before_trim = trim(before_trim);
	assert(after_trim.compare(before_trim) == 0);
}

void test_date()
{
	Date date;
}

void test_datetime()
{
}

void test_logger()
{
}

void test_mysql()
{
}

void test_person()
{
}

void test_team()
{
}

void test_time()
{
}

void test_main()
{
	test_common();
	test_date();
	test_datetime();
	test_mysql();
	test_person();
	test_team();
	test_time();
}
