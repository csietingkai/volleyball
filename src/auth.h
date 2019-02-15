#ifndef AUTH_H_
#define AUTH_H_

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <iostream>

#include "beans/UUID.h"
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
		ROOT = 64,
		ADMIN = 32,
		LEADER = 16,
		USER = 8,
		NONE = 4
	};
	
	const Role int_to_role(const int value);
	
	std::ostream& operator <<(std::ostream& strm, const Role& role);
	
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
	 * @param account(string) : username value
	 * @param pwd(string) : password value
	 * 
	 * @return user(User) : user object
	 * 
	 * @see auth.h: struct User(string, string, string, Role)
	 * 
	 * @auther tingkai
	 * @date 2019.01.23
	 */
	const User auth(const std::string account, const std::string pwd);
	
	/**
	 * the situation of making auth
	 * 
	 * @auther tingkai
	 * @date 2019.02.05
	 */
	enum class AuthState : int
	{
		SUCCESS = 0,
		DUPLICATE_ACCOUNT_NAME = 1,
		AUTH_NOT_ENOUGH = 2,
		FAIL = 32
	};
	
	std::ostream& operator <<(std::ostream& strm, const AuthState& state);
	
	/**
	 * connect to mysql and insert a new user to database, 
	 * but 'new_user' role must under 'current_user'
	 * 
	 * @param current_user(User) : the user create other user
	 * @param new_user(User) : the other user create by other one
	 * 
	 * @return success(bool) : create new user or not
	 * 
	 * @see auth.h: struct User(string, string, string, Role)
	 * 
	 * @auther tingkai
	 * @date 2019.02.04
	 */
	const AuthState create_auth(const User current_user, const User new_user);
}

#endif // AUTH_H_
