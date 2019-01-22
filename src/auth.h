#ifndef AUTH_H_
#define AUTH_H_

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <iostream>

#include "tools/SqlCommandBuilder.h"
#include "utils/ServerInfo.h"
#include "utils/Utils.h"

namespace voba
{
	/**
	 * role for controll if this user can do this action or not
	 * 
	 * @auther tingkai
	 * @date 2019.01.23
	 */
	enum class Role : int
	{
		OWNER = 1,
		ADMIN = 2,
		CAPTAIN = 4,
		USER = 8,
		NONE = 16
	};
	
	/**
	 * correspond data structure in database 'Auth' table
	 *  
	 * @see auth.h: enum Role, type int
	 * 
	 * @auther tingkai
	 * @date 2019.01.23
	 */
	struct User
	{
		std::string id;
		std::string account;
		std::string pwd;
		Role role;
	};
	
	/**
	 * connect to mysql and see is this pair of account and password is exist in database
	 * if exist, return user with id and role
	 * if not, return user with role 'NONE'
	 * 
	 * @see auth.h: struct User(string, string, string, Role)
	 * 
	 * @auther tingkai
	 * @date 2019.01.23
	 */
	const User auth(const std::string account, const std::string pwd);
}

#endif // AUTH_H_
