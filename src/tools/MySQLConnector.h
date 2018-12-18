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
			
			sql::ResultSet* select(const std::string id);
			const bool insert(const T t) { return false; }; // need specialization
			const int update(const T t, const std::string old_id) { return 0; }; // need specialization
			const int remove(const T t);
		
		private:
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
			
			ServerInfo info;
			std::string table_name;
			
			void print_sql_exception(const sql::SQLException e);
	};
	
	template<> const bool MySQLConnector<Game>::insert(const Game g);
	template<> const int MySQLConnector<Game>::update(const Game g, const std::string old_id);
	
	template<> const bool MySQLConnector<Person>::insert(const Person p);
	template<> const int MySQLConnector<Person>::update(const Person p, const std::string old_id);
	
	template<> const bool MySQLConnector<Team>::insert(const Team t);
	template<> const int MySQLConnector<Team>::update(const Team t, const std::string old_id);
	
	template class MySQLConnector<Game>;
	template class MySQLConnector<Person>;
	template class MySQLConnector<Team>;
}

#endif // MYSQL_CONNECTOR_H_
