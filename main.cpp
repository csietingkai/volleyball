#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "src/common.h"
#include "src/MySQLConnector.h"
#include "src/Person.h"

using namespace std;
 
int main()
{
	Person p("sdfojkaaa", 2224, Gender::female, "0938282394", ActiveStatus::active);
	p.set_name("aaa");
	
	return 0;
}
