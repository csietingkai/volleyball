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

namespace voba
{
	template <class T>
	class MySQLConnector : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			// constructors
			MySQLConnector();
			~MySQLConnector();
			
			// basic functions
			const T& select(const std::string id);
			const bool insert(const T t);
			const int update(const T t);
			const int remove(const T t);
		
		private:
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
			
			ServerInfo info;
			std::string table_name;
			
			void print_sql_exception(const sql::SQLException e);
	};
	
	template<> 
	class MySQLConnector<Game>
	{
		public:
			const Game& select(const std::string id);
			const bool insert(const Game p);
			const int update(const Game p);
			const int remove(const Game p);
	};
	
	template<> 
	class MySQLConnector<Person>
	{
		public:
			const Person& select(const std::string id);
			const bool insert(const Person p);
			const int update(const Person p);
			const int remove(const Person p);
	};
	
	template<> 
	class MySQLConnector<Team>
	{
		public:
			const Team& select(const std::string id);
			const bool insert(const Team p);
			const int update(const Team p);
			const int remove(const Team p);
	};
}

#endif // MYSQL_CONNECTOR_H_
