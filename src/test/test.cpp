#include "test.h"

void voba::test_main()
{
	voba::test_beans();
	voba::test_models();
	voba::test_tools();
	voba::test_utils();
}

void voba::test_beans()
{
	voba::test_date();
	voba::test_datetime();
	voba::test_time();
}

void voba::test_date()
{
	
}

void voba::test_datetime()
{
	
}

void voba::test_time()
{
	
}

void voba::test_models()
{
	voba::test_game();
	voba::test_person();
	voba::test_team();
}

void voba::test_game()
{
	
}

void voba::test_person()
{
	
}

void voba::test_team()
{
	
}

void voba::test_tools()
{
	voba::test_logger();
	voba::test_connector();
	voba::test_sqlcommandbuilder();
}

void voba::test_logger()
{
	
}

void voba::test_connector()
{
	voba::MySQLConnector<voba::Person> p_connector;
	sql::ResultSet* res = p_connector.select("353de133f85ff64454a58ff782c31f483854c8f5");
	sql::ResultSetMetaData *res_meta = res -> getMetaData();
	int columns = res_meta -> getColumnCount();
	while (res->next())
	{
		for (int i = 1; i <= columns; i++)
		{
			std::cout << res->getString(i) << "|" ;
		}
		std::cout << std::endl;
	}
}

void voba::test_sqlcommandbuilder()
{
	
}

void voba::test_utils()
{
	voba::test_serverinfo();
	voba::test_util();
}

void voba::test_serverinfo()
{
	
}

void voba::test_util()
{
	
}

