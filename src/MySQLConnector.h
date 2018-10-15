#ifndef MYSQL_CONNECTOR_H_
#define MYSQL_CONNECTOR_H_

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include "common.h"

using namespace std;
using namespace sql;

class MySQLConnector
{
	public:
		// constructors
		MySQLConnector(const string schema, const string table_name);
		~MySQLConnector();
		
		// basic functions
		ResultSet* select(const string column_name);
		ResultSet* select(const string column_name, const string condition);
		const bool insert(const string values);
		const int update(const string column_name, const string column_value);
		const int remove(const string codition); // use remove rather than delete
		const int removeAll();
	
	private:
		Driver *driver;
		Connection *connection;
		Statement *statement;
		ResultSet *result_set;
		
		string schema;
		string table_name;
		
		const string server = "mysql.cs.ccu.edu.tw";
		const string account = "htk103u";
		const string password = "htkkoeoh";
};

#endif
