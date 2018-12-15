#include "PersonFactory.h"

voba::MySQLConnector<voba::Person> voba::PersonFactory::connector;

const voba::Person& voba::PersonFactory::create()
{
	sql::ResultSet* result_set = voba::PersonFactory::connector.select("353de133f85ff64454a58ff782c31f483854c8f5");
	sql::ResultSetMetaData *res_meta = result_set->getMetaData();
	int columns = res_meta->getColumnCount();
	while (result_set->next())
	{
		for (int i = 1; i <= columns; i++)
		{
			std::cout << result_set->getString(i) << "|" ;
		}
		std::cout << std::endl;
	}
	Person *p = new Person("test1", 21, voba::Gender::male, "0987654321", voba::ActiveStatus::active);
	return *p;
}
