#include "auth.h"

const std::string voba::Auth::CLASS_NAME = "Auth";

voba::Auth::Auth(const std::string account, const std::string pwd)
{
	this->id = voba::Utils::generate_uuid();
	this->account = account;
	this->pwd = pwd;
	
	this->driver = get_driver_instance();
	this->connection = this->driver->connect(info.get_server(), info.get_account(), info.get_pwd());
	this->connection->setSchema(info.get_schema());

	this->statement = this->connection->createStatement();
}

voba::Auth::~Auth()
{
	delete connection;
	delete statement;
}

const bool voba::Auth::create()
{
	return this->create(Role::USER);
}
		
const bool voba::Auth::create(const Role role)
{
	this->role = role;
	std::string table_name = this->info.get_table_name(voba::Auth::CLASS_NAME);
	
	std::list<std::string> strs;
	strs.push_back(table_name);
	std::string val = "'"+this->id+"',";
	val += "'"+this->account+"',";
	val += "'"+this->pwd+"',";
	val += std::to_string(static_cast<int>(role));
	strs.push_back(val);
	
	std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::insert, strs);
	
	return this->statement->execute(query);
}

const bool voba::Auth::edit(const Role role)
{
	if (this->verify() == false)
	{
		return false;
	}
	
	this->role = role;
	std::string table_name = this->info.get_table_name(voba::Auth::CLASS_NAME);
	
	std::list<std::string> strs;
	strs.push_back(table_name);
	strs.push_back("ROLE");
	strs.push_back(std::to_string(static_cast<int>(this->role)));
	strs.push_back("ACCOUNT='"+this->account+"'");
	
	std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::update, strs);
	
	return (this->statement->executeUpdate(query) == 1);
}

const bool voba::Auth::verify()
{
	std::string table_name = this->info.get_table_name(voba::Auth::CLASS_NAME);
	
	std::list<std::string> strs;
	strs.push_back("PWD");
	strs.push_back(table_name);
	strs.push_back("ACCOUNT='"+this->account+"'");
	
	std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::select, strs);
	
	sql::ResultSet* result_set = this->statement->executeQuery(query);
	if (result_set->next())
	{
		//std::cout << result_set->getString(1) << std::endl;
		
		if (this->pwd.compare(result_set->getString(1)) == 0)
		{
			return true;
		}
	}
	
	return false;
}

const voba::Role voba::Auth::get_role()
{
	if (this->verify() == false)
	{
		return Role::NONE;
	}
	
	std::string table_name = this->info.get_table_name(voba::Auth::CLASS_NAME);
	
	std::list<std::string> strs;
	strs.push_back("ROLE");
	strs.push_back(table_name);
	strs.push_back("ACCOUNT='"+this->account+"'");
	
	std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::select, strs);
	
	sql::ResultSet* result_set = this->statement->executeQuery(query);
	if (result_set->next())
	{
		return static_cast<voba::Role>(std::stoi(result_set->getString(1)));
	}
	
	return Role::NONE;
}

