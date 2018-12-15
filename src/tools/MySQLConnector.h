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
	template <class T>
	class MySQLConnector : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			// constructors
			MySQLConnector();
			~MySQLConnector();
			
			// basic functions, MUST specialization
			sql::ResultSet* select(const std::string id) { return NULL; };
			const bool insert(const T t) { return false; };
			const int update(const T t) { return 0; };
			const int remove(const T t) { return 0; };
		
		private:
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
			
			ServerInfo info;
			std::string table_name;
			
			void print_sql_exception(const sql::SQLException e);
	};
	
	template<> sql::ResultSet* MySQLConnector<Person>::select(const std::string id);
	template<> const bool MySQLConnector<Person>::insert(const Person p);
	template<> const int MySQLConnector<Person>::update(const Person p);
	template<> const int MySQLConnector<Person>::remove(const Person p);
	
	template class MySQLConnector<Person>;
}

#endif // MYSQL_CONNECTOR_H_
