#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "src/common.h"
#include "src/MySQLConnector.h"
#include "src/people.h"

using namespace std;
 
const string schema = "htk103u_volleyball";
const string table_name = "persons";
 
int main()
{
	Person p("aaa", 21, Gender::female, "0938282394", ActiveStatus::inactive);
	
	return 0;
}
