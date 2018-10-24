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

#define interface class

interface Connectable
{
	protected:
		virtual void select() = 0;
		virtual void insert() = 0;
		virtual void update(const string column_name, const string column_value) = 0;
		virtual void remove(const string id) {};
};

class MySQLConnector
{
	public:
		// constructors
		MySQLConnector(const string table_name);
		~MySQLConnector();
		
		// basic functions
		ResultSet* select(const string column_name);
		ResultSet* select(const string column_name, const string condition);
		const bool insert(const string values);
		const int update(const string column_name, const string column_value, const string conditions);
		const int remove(const string codition); // use remove rather than delete
		const int removeAll();
	
	private:
		Driver *driver;
		Connection *connection;
		Statement *statement;
		ResultSet *result_set;
		
		string table_name;
		const static string CLASS_NAME;
		Logger logger;
		
		const string server = get_connect_info(Connect_info::server);
		const string account = get_connect_info(Connect_info::account);
		const string pwd = get_connect_info(Connect_info::pwd);
		const string schema = get_connect_info(Connect_info::schema);
		
		void print_sql_exception(const SQLException e);
};

#endif
