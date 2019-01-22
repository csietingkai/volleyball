#include "auth.h"

const voba::User voba::auth(const std::string account, const std::string pwd)
{
	// constant for each column and its index
	const static int ID_AT = 1;
	const static int PWD_AT = 3;
	const static int ROLE_AT = 4;
	
	// create an empty user
	voba::User user;
	user.id = "";
	user.account = account;
	user.pwd = pwd;
	user.role = voba::Role::NONE;
	
	// connect to mysql to get full information
	voba::ServerInfo info;
	voba::Table table = info.get_table("Auth");
	sql::Driver *driver = get_driver_instance();
	sql::Connection *connection = driver->connect(info.get_server(), info.get_account(), info.get_pwd());
	connection->setSchema(info.get_schema());
	sql::Statement *statement = connection->createStatement();
	
	voba::SqlCommandBuilder builder;
	Column where_condition("account", "string");
	where_condition.set_value(account);
	std::string query = builder.select().from(table).where(where_condition).to_string();
	sql::ResultSet *result_set = statement->executeQuery(query);
	
	while (result_set->next()) {
		if (result_set->getString(PWD_AT).compare(user.pwd) == 0)
		{
			user.id = result_set->getString(ID_AT);
			user.role = static_cast<voba::Role>(std::stoi(result_set->getString(ROLE_AT)));
			break;
		}
	}

	return user;
}

