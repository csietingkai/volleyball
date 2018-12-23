#ifndef AUTH_H_
#define AUTH_H_

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <list>
#include <mysql_connection.h>
#include <iostream>

#include "tools/SqlCommandBuilder.h"
#include "utils/ServerInfo.h"
#include "utils/Utils.h"

namespace voba
{
	enum class Role : int
	{
		OWNER = 1,
		ADMIN = 2,
		CAPTAIN = 4,
		USER = 8,
		NONE = 16
	};
	
	class Auth
	{
		public:
			const static std::string CLASS_NAME;
			
			Auth(const std::string account, const std::string pwd);
			~Auth();
			
			const bool create();
			const bool create(const Role role);
			const bool edit(const Role role);
			const bool verify();
			const Role get_role();
			
		private:
			std::string id;
			std::string account;
			std::string pwd;
			Role role;
			
			ServerInfo info;
			
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
	};
}

#endif // AUTH_H_
