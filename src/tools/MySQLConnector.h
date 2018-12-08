#ifndef MYSQL_CONNECTOR_H_
#define MYSQL_CONNECTOR_H_

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <type_traits>

#include "../utils/ServerInfo.h"
#include "../utils/Utils.h"
#include "Logger.h"

namespace voba
{
	class MySQLConnector
	{
		public:
			const static std::string CLASS_NAME;
			
			// constructors
			MySQLConnector(const std::string target_class_name);
			~MySQLConnector();
			
			// basic functions
			sql::ResultSet* select();
			const bool insert();
			const int update();
			const int remove();
		
		private:
			sql::Driver *driver;
			sql::Connection *connection;
			sql::Statement *statement;
			
			ServerInfo info;
			std::string table_name;
			
			Logger logger;
			
			const static std::string SERVER_INFO_FILE_PATH;
			
			void print_sql_exception(const sql::SQLException e);
	};
}

#endif // MYSQL_CONNECTOR_H_
