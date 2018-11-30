#ifndef TEST_H_
#define TEST_H_

#include <assert.h>
#include <iostream>

#include "../src/common.h"
#include "../src/Datee.h"
#include "../src/DateeTime.h"
#include "../src/MySQLConnector.h"
#include "../src/Person.h"
#include "../src/Team.h"
#include "../src/Time.h"
#include "../src/Logger.h"

using namespace std;

void test_common();
void test_datee();
void test_dateetime();
void test_logger();
void test_mysql();
void test_person();
void test_team();
void test_time();
void test_main();

#endif // TEST_H_
