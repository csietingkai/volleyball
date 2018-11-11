#ifndef TEST_H_
#define TEST_H_

#include <assert.h>
#include <iostream>

#include "common.h"
#include "Datee.h"
#include "DateTime.h"
#include "MySQLConnector.h"
#include "Person.h"
#include "Team.h"
#include "Time.h"

using namespace std;

void test_common();
void test_datee();
void test_datetime();
void test_logger();
void test_mysql();
void test_person();
void test_team();
void test_time();
void test_main();

#endif // TEST_H_
