#ifndef MYSQL_CONNECTOR_H_
#define MYSQL_CONNECTOR_H_

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <type_traits>

#include "../models/Game.h"
#include "../models/Person.h"
#include "../models/Team.h"
#include "../utils/ServerInfo.h"
#include "../utils/Utils.h"
#include "Logger.h"
#include "SqlCommandBuilder.h"

namespace voba
{
	/**
	 * @CreatedBy tingkai
	 * @Date 2019.12.07
	 */
	template <class T>
	class MySQLConnector : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * constructor of MySQLConnector <br/>
			 * initialize connection
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.12.07
			 */
			MySQLConnector();
			/**
			 * destructor of MySQLConnector <br/>
			 * close connection
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.12.07
			 */
			~MySQLConnector();
			
			/**
			 * select all rows
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.12.07
			 */
			sql::ResultSet* select();
			sql::ResultSet* select(const UUID id);
			sql::ResultSet* select(const std::list<Column> where_conditions);
			const int insert(const T t) { return 0; }; // need specialization
			const int update(const T t) { return 0; }; // need specialization
			const int remove(const T t);
			const int remove(const Column where_conditions);
			const int remove(const std::list<Column> where_conditions);
			
			const int execute(const std::string query);
		
		private:
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
			
			ServerInfo info;
			Table table;
			SqlCommandBuilder builder;
			
			void print_sql_exception(const sql::SQLException e);
	};
	
	template<> const int MySQLConnector<Game>::insert(const Game g);
	template<> const int MySQLConnector<Game>::update(const Game g);
	
	template<> const int MySQLConnector<Person>::insert(const Person p);
	template<> const int MySQLConnector<Person>::update(const Person p);
	
	template<> const int MySQLConnector<Team>::insert(const Team t);
	template<> const int MySQLConnector<Team>::update(const Team t);
	
	template class MySQLConnector<Game>;
	template class MySQLConnector<Person>;
	template class MySQLConnector<Team>;
}

#endif // MYSQL_CONNECTOR_H_
