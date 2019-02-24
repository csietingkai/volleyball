#include "auth.h"

const voba::Role voba::int_to_role(const int value)
{
	voba::Role r = voba::Role::NONE;
	switch (value)
	{
		case 64:
			r = voba::Role::ROOT;
			break;
		
		case 32:
			r = voba::Role::ADMIN;
			break;
		
		case 16:
			r = voba::Role::LEADER;
			break;
		
		case 8:
			r = voba::Role::USER;
			break;
		
		case 4:
			r = voba::Role::NONE;
			break;
		
		default:
			std::cerr << "invalid value to role" << std::endl;
			break;
	}
	
	return r;
}

std::ostream& voba::operator <<(std::ostream& strm, const voba::Role& role)
{
	switch (role)
	{
		case voba::Role::ROOT:
			strm << "root";
			break;
		
		case voba::Role::ADMIN:
			strm << "admin";
			break;
		
		case voba::Role::LEADER:
			strm << "leader";
			break;
		
		case voba::Role::USER:
			strm << "user";
			break;
		
		case voba::Role::NONE:
			strm << "none";
			break;
		
		default:
			std::cerr << "invalid role" << std::endl;
			break;
	}
	
	return strm;
}

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
	voba::Column where_condition("account", voba::ColumnType::String);
	where_condition.set_value(account);
	std::string query = builder.select().from(table).where(where_condition).to_string();
	sql::ResultSet *result_set = statement->executeQuery(query);
	
	while (result_set->next())
	{
		if (result_set->getString(PWD_AT).compare(user.pwd) == 0)
		{
			user.id = result_set->getString(ID_AT);
			user.role = voba::int_to_role(std::stoi(result_set->getString(ROLE_AT)));
			break;
		}
	}

	return user;
}

std::ostream& voba::operator <<(std::ostream& strm, const voba::AuthState& state)
{
	switch (state)
	{
		case voba::AuthState::SUCCESS:
			strm << "success";
			break;
		
		case voba::AuthState::DUPLICATE_ACCOUNT_NAME:
			strm << "duplicate account name";
			break;
		
		case voba::AuthState::AUTH_NOT_ENOUGH:
			strm << "auth level not enough";
			break;
		
		case voba::AuthState::FAIL:
			strm << "unknown fail";
			break;
		
		default:
			std::cerr << "invalid state" << std::endl;
			break;
	}
	
	return strm;
}

const voba::AuthState voba::create_auth(const voba::User current_user, const voba::User new_user)
{
	voba::AuthState result = voba::AuthState::FAIL;
	if (current_user.role > new_user.role)
	{
		voba::ServerInfo info;
		voba::Table table = info.get_table("Auth");
		sql::Driver *driver = get_driver_instance();
		sql::Connection *connection = driver->connect(info.get_server(), info.get_account(), info.get_pwd());
		connection->setSchema(info.get_schema());
		sql::Statement *statement = connection->createStatement();
		
		voba::Column id("id", voba::ColumnType::UUID);
		
		id.set_value(voba::UUID::random_uuid().to_string());
		voba::Column account("account", voba::ColumnType::String);
		account.set_value(new_user.account);
		voba::Column pwd("pwd", voba::ColumnType::String);
		pwd.set_value(new_user.pwd);
		voba::Column role("role", voba::ColumnType::Integer);
		role.set_value(std::to_string(static_cast<int>(new_user.role)));
		std::list<voba::Column> values = { id, account, pwd, role };
		
		voba::SqlCommandBuilder builder;
		std::string query = builder.insert(table).values(values).to_string();
		try
		{
			statement->execute(query);
			result = voba::AuthState::SUCCESS;
		}
		catch (sql::SQLException e)
		{
			std::string error_msg = "# ERR: ";
			error_msg += e.what();
			error_msg += " (MySQL error code: ";
			error_msg += std::to_string(e.getErrorCode());
			error_msg += ", SQLState: ";
			error_msg += e.getSQLState();
			error_msg += " )";
			std::cout << error_msg << std::endl;
			if (e.getErrorCode() == 1062)
			{
				result = voba::AuthState::DUPLICATE_ACCOUNT_NAME;
			}
		}
	}
	else 
	{
		result = voba::AuthState::AUTH_NOT_ENOUGH;
	}
	
	return result;
}
