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
	
	struct User
	{
		std::string id;
		std::string account;
		std::string pwd;
		Role role;
	};
	
	const User auth(const std::string account, const std::string pwd);
}

#endif // AUTH_H_
