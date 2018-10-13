#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "src/common.h"
#include "src/people.h"
#include "src/MySQLConnector.h"

using namespace std;
 
const string schema = "htk103u_volleyball";
const string table_name = "persons";
 
int main()
{
	MySQLConnector connector(schema, table_name);
	parse_xml("resources/crud.xml");
	
	return 0;
}
