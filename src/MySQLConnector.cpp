#include "MySQLConnector.h"

// constructor
MySQLConnector::MySQLConnector(const string schema, const string table_name)
{
	this->driver = get_driver_instance();
	this->connection = this->driver->connect(this->server, this->account, this->password);
	this->connection->setSchema(schema);

	this->statement = this->connection->createStatement();
	this->result_set = this->statement->executeQuery("SELECT NAME FROM "+table_name);
	
	while (this->result_set->next()) {
		cout << "MySQL replies: ";
		cout << this->result_set->getString(1) << endl;
	}
}

MySQLConnector::~MySQLConnector()
{
	delete this->connection;
	delete this->statement;
	delete this->result_set;
}
