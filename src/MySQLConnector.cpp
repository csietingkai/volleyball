#include "MySQLConnector.h"

// constructor
MySQLConnector::MySQLConnector(const string schema, const string table_name)
{
	this->schema = schema;
	this->table_name = table_name;
	
	this->driver = get_driver_instance();
	this->connection = this->driver->connect(this->server, this->account, this->password);
	this->connection->setSchema(schema);

	this->statement = this->connection->createStatement();
	this->result_set = this->statement->executeQuery("SELECT * FROM "+this->table_name);
	trace_log("hah");
}

MySQLConnector::~MySQLConnector()
{
	delete this->connection;
	delete this->statement;
	delete this->result_set;
}

// basic functions
ResultSet* MySQLConnector::select(const string column_name)
{
	return this->select(column_name, "");
}

ResultSet* MySQLConnector::select(const string column_name, const string conditions)
{
	string query = parse_xml(SQL::select);
	replace(query, "[COLUMN_NAME]", column_name);
	replace(query, "[TABLE_NAME]", this->table_name);
	if (!trim(conditions).empty())
	{
		replace(query, "[CODITIONS]", conditions);
	}
	else
	{
		replace(query, "[CODITIONS]", "ID IS NOT NULL");
	}
	//cout << query << endl;
	this->result_set = this->statement->executeQuery(query);
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
	return this->result_set;
}

const bool MySQLConnector::insert(const string values)
{
	bool ret = true;
	
	string query = parse_xml(SQL::insert);
	replace(query, "[TABLE_NAME]", this->table_name);
	if (!trim(values).empty())
	{
		replace(query, "[VALUES]", values);
	}
	else
	{
		error("sql insert error: values can't be empty");
	}
	
	try
	{
		ret = this->statement->execute(query);
	}
	catch (SQLException e)
	{
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	
	return ret;
}

const int MySQLConnector::update(const string column_name, const string column_value)
{
	return 0;
}

const int MySQLConnector::remove(const string codition)
{
	return 0;
}

const int MySQLConnector::removeAll()
{
	return this->remove("ID IS NOT NULL");
}
