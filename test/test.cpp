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

void test_dateetime()
{
}

void test_logger()
{
	Logger log("Test");
	log.trace("test message1");
	log.warning("warning message");
	log.trace("test message2");
	log.info("info message");
	log.fatal("fatal message");
}

void test_mysql()
{
}

void test_person()
{
	Person test1("test1", 21, Gender::male, "0987654321", ActiveStatus::active);
	Person test2("test2", 22, Gender::male, "0987654321", ActiveStatus::active);
	Person test3("test3", 23, Gender::male, "0987654321", ActiveStatus::active);
	Person test4("test4", 24, Gender::male, "0987654321", ActiveStatus::active);
	Person test5("test5", 25, Gender::male, "0987654321", ActiveStatus::active);
}

void test_team()
{
	Person test1("test1", 21, Gender::male, "0987654321", ActiveStatus::active);
	Person test2("test2", 22, Gender::male, "0987654321", ActiveStatus::active);
	Person test3("test3", 23, Gender::male, "0987654321", ActiveStatus::active);
	Person test4("test4", 24, Gender::male, "0987654321", ActiveStatus::active);
	Person test5("test5", 25, Gender::male, "0987654321", ActiveStatus::active);
	
	Team test_team("test_team");
	test_team.add_member(test1);
	test_team.add_member(test2);
	test_team.add_member(test3);
	test_team.add_member(test4);
	test_team.add_member(test5);
}

void test_time()
{
}

void test_main()
{
	test_common();
	test_datee();
	test_dateetime();
	test_mysql();
	test_person();
	test_team();
	test_time();
	test_logger();
}
