#include "common.h"

void error(const string error_message)
{
	// throw an exception
	// which output error message and shut whole program down
	throw invalid_argument(error_message);
}

const string uuid()
{
	uuid_t id;
	uuid_generate(id);
	char *str = new char[100];
	uuid_unparse(id, str);
	string ret(str);
	delete[] str;
	return ret;
}
