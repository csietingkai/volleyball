#include "auth.h"

const std::string voba::Auth::CLASS_NAME = "Auth";

voba::Auth::Auth(const std::string account, const std::string pwd, const voba::Role role)
{
	this->id = voba::Utils::generate_uuid();
	this->account = account;
	this->pwd = pwd;
	this->role = role;
}
		
const bool voba::Auth::create()
{
	std::string table_name = this->info.get_table_name(voba::Auth::CLASS_NAME);
	
	sql::Driver *driver = get_driver_instance();
	sql::Connection *connection = driver->connect(this->info.get_server(), this->info.get_account(), this->info.get_pwd());
	connection->setSchema(this->info.get_schema());

	sql::Statement *statement = connection->createStatement();
	
	std::list<std::string> strs;
	strs.push_back(table_name);
	std::string val = "'"+this->id+"',";
	val += "'"+this->account+"',";
	val += "'"+this->pwd+"',";
	val += std::to_string(static_cast<int>(this->role));
	strs.push_back(val);
	std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::insert, strs);
	std::cout << query << std::endl;
	int result = statement->execute(query);
	
	delete connection;
	delete statement;
	
	return (result == 1);
}

const bool voba::Auth::edit(const Role role)
{
	
}

const bool voba::Auth::verify()
{
	
}

