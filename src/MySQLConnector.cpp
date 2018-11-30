#include "MySQLConnector.h"

// constructor
MySQLConnector::MySQLConnector(const string table_name)
	: logger(MySQLConnector::CLASS_NAME)
{
	logger.trace("initializing MySQLConnector with table_name='"+table_name+"'");
	
	this->table_name = table_name;
	
	this->driver = get_driver_instance();
	this->connection = this->driver->connect(this->server, this->account, this->pwd);
	this->connection->setSchema(schema);

	this->statement = this->connection->createStatement();
}

MySQLConnector::~MySQLConnector()
{
	delete this->connection;
	delete this->statement;
}

// basic functions
ResultSet* MySQLConnector::select(const string column_name)
{
	return this->select(column_name, "ID IS NOT NULL");
}

ResultSet* MySQLConnector::select(const string column_name, const string conditions)
{
	ResultSet *result_set;
	
	string query = get_sql_command(SQL::select);
	replace(query, "[COLUMN_NAME]", column_name);
	replace(query, "[TABLE_NAME]", this->table_name);
	replace(query, "[CONDITIONS]", conditions);
	
	logger.debug("select query: " + query);
	
	try
	{
		result_set = this->statement->executeQuery(query);
	}
	catch (SQLException e)
	{
		logger.error("SQL Exception happened !!");
		print_sql_exception(e);
	}
	/*ResultSetMetaData *res_meta = result_set->getMetaData();
	int columns = res_meta->getColumnCount();
	while (result_set->next())
	{
		for (int i = 1; i <= columns; i++)
		{
			cout << result_set->getString(i) << "|" ;
		}
		cout << endl;
	}*/
	return result_set;
}

const bool MySQLConnector::insert(const string values)
{
	bool ret = true;
	
	string query = get_sql_command(SQL::insert);
	replace(query, "[TABLE_NAME]", this->table_name);
	if (!trim(values).empty())
	{
		replace(query, "[VALUES]", values);
	}
	else
	{
		logger.error("sql insert error: values can't be empty");
		ret = false;
		return ret;
	}
	
	logger.debug("insert query: " + query);
	
	try
	{
		ret = this->statement->execute(query);
	}
	catch (SQLException e)
	{
		logger.error("SQL Exception happened !!");
		print_sql_exception(e);
	}
	
	return ret;
}

const int MySQLConnector::update(const string column_name, const string column_value, const string conditions)
{
	int ret = 0;
	
	string query = get_sql_command(SQL::update);
	replace(query, "[TABLE_NAME]", this->table_name);
	replace(query, "[COLUMN_NAME]", column_name);
	replace(query, "[COLUMN_VALUE]", column_value);
	replace(query, "[CONDITIONS]", conditions);
	
	logger.debug("update query: " + query);
	
	try
	{
		ret = this->statement->execute(query);
	}
	catch (SQLException e)
	{
		logger.error("SQL Exception happened !!");
		print_sql_exception(e);
	}
	
	return ret;
}

const int MySQLConnector::remove(const string conditions)
{
	int ret = 0;
	
	string query = get_sql_command(SQL::remove);
	replace(query, "[TABLE_NAME]", this->table_name);
	replace(query, "[CONDITIONS]", conditions);
	
	logger.debug("delete query: " + query);
	
	try
	{
		ret = this->statement->execute(query);
	}
	catch (SQLException e)
	{
		logger.error("SQL Exception happened !!");
		print_sql_exception(e);
	}
	
	return ret;
}

const int MySQLConnector::removeAll()
{
	return this->remove("ID IS NOT NULL");
}

// private
const string MySQLConnector::CLASS_NAME = "MySQLConnector";

void MySQLConnector::print_sql_exception(const SQLException e)
{
	cout << "# ERR: SQLException in " << __FILE__;
	cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}
