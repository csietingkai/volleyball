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
	template <typename T>
	class MySQLConnector
	{
		public:
			// constructors
			MySQLConnector<T>();
			~MySQLConnector<T>();
			
			// basic functions
			/*sql::ResultSet* select(const std::string column_name);
			sql::ResultSet* select(const std::string column_name, const std::string condition);
			const bool insert(const std::string values);
			const int update(const std::string column_name, const std::string column_value, const std::string conditions);
			const int remove(const std::string codition);*/
			const int removeAll();
		
		private:
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
			
			ServerInfo info;
			
			Logger logger;
			const static std::string CLASS_NAME;
			
			const static std::string SERVER_INFO_FILE_PATH;
			
			void print_sql_exception(const sql::SQLException e);
	};
	
	template class MySQLConnector<Person>;
}

#endif // MYSQL_CONNECTOR_H_
