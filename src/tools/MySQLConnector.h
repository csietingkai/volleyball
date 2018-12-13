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
			const T select();
			const bool insert();
			const int update();
			const int remove();
		
		private:
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
			
			ServerInfo info;
			std::string table_name;
			
			void print_sql_exception(const sql::SQLException e);
	};
	
	template class MySQLConnector<Person>;
}

#endif // MYSQL_CONNECTOR_H_
