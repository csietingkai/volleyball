#include "auth.h"

const voba::User voba::auth(const std::string account, const std::string pwd)
{
	const static int ID_AT = 1;
	const static int ACCOUNT_AT = 2;
	const static int PWD_AT = 3;
	const static int ROLE_AT = 4;
	
	voba::User user;
	user.id = "";
	user.account = account;
	user.pwd = pwd;
	user.role = voba::Role::NONE;
	
	voba::ServerInfo info;
	voba::Table table = info.get_table("Auth");
	sql::Driver *driver = get_driver_instance();
	sql::Connection *connection = driver->connect(info.get_server(), info.get_account(), info.get_pwd());
	connection->setSchema(info.get_schema());
	sql::Statement *statement = connection->createStatement();
	
	voba::SqlCommandBuilder builder;
	std::string query = builder.select().from(table).to_string();
	sql::ResultSet *result_set = statement->executeQuery(query);
	
	while (result_set->next()) {
		if (result_set->getString(ACCOUNT_AT).compare(user.account) != 0)
		{
			continue;
		}
		else
		{
			if (result_set->getString(PWD_AT).compare(user.pwd) != 0)
			{
				break;
			}
			else
			{
				user.id = result_set->getString(ID_AT);
				user.role = static_cast<voba::Role>(std::stoi(result_set->getString(ROLE_AT)));
			}
		}
	}

	return user;
}

