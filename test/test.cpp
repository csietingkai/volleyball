#include "test.h"
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;

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

void test_datee()
{
	Datee date;
}

void test_datetime()
{
}

void test_logger()
{
	Logger log("test");
	log.trace("test message");
	log.fatal("fatal message");
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
	test_datee();
	test_datetime();
	test_mysql();
	test_person();
	test_team();
	test_time();
	test_logger();
}
