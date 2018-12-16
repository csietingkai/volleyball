#include "MySQLConnector.h"

template <class T>
const std::string voba::MySQLConnector<T>::CLASS_NAME = "MySQLConnector."+T::CLASS_NAME;

// constructor
template <class T>
voba::MySQLConnector<T>::MySQLConnector()
	: Logable(voba::MySQLConnector<T>::CLASS_NAME)
{
	this->table_name = info.get_table_name(T::CLASS_NAME);
	
	this->driver = get_driver_instance();
	this->connection = this->driver->connect(info.get_server(), info.get_account(), info.get_pwd());
	this->connection->setSchema(info.get_schema());

	this->statement = this->connection->createStatement();
}

template <class T>
voba::MySQLConnector<T>::~MySQLConnector()
{
	delete connection;
	delete statement;
}

// private function
template <class T>
void voba::MySQLConnector<T>::print_sql_exception(const sql::SQLException e)
{
	std::string error_msg = "# ERR: ";
	error_msg += e.what();
	error_msg += " (MySQL error code: ";
	error_msg += e.getErrorCode();
	error_msg += ", SQLState: ";
	error_msg += e.getSQLState();
	error_msg += " )";
	this->logger.error(error_msg);
}

// Game specialization
template<> sql::ResultSet* voba::MySQLConnector<voba::Game>::select(const std::string id)
{
	
}

template<> const bool voba::MySQLConnector<voba::Game>::insert(const voba::Game p)
{
	
}

template<> const int voba::MySQLConnector<voba::Game>::update(const voba::Game p)
{
	
}

template<> const int voba::MySQLConnector<voba::Game>::remove(const voba::Game p)
{
	
}

// Person specialization
template<> sql::ResultSet* voba::MySQLConnector<voba::Person>::select(const std::string id)
{
	sql::ResultSet *result_set;
	std::list<std::string> query_list = {};
	query_list.push_back("*");
	query_list.push_back(this->table_name);
	query_list.push_back("ID = '"+id+"'");
	std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::select, query_list);
	
	this->logger.debug(query);
	
	try
	{
		result_set = this->statement->executeQuery(query);
	}
	catch (sql::SQLException e)
	{
		this->logger.error("SQL Exception happened !!");
		this->print_sql_exception(e);
	}
	return result_set;
}

template<> const bool voba::MySQLConnector<voba::Person>::insert(const voba::Person p)
{
	bool ret;
	std::list<std::string> query_list = {};
	query_list.push_back(this->table_name);
	
	std::string values = "'"+p.get_id()+"',";
	values += "'"+p.get_name()+"',";
	values += "'"+std::to_string(p.get_age())+"',";
	values += "'"+std::to_string(static_cast<int>(p.get_gender()))+"',";
	values += "'"+p.get_phonenumber()+"',";
	values += "'"+std::to_string(static_cast<int>(p.get_active_status()))+"'";
	
	query_list.push_back(values);
	std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::insert, query_list);
	
	this->logger.debug(query);
	
	try
	{
		ret = this->statement->execute(query);
	}
	catch (sql::SQLException e)
	{
		this->logger.error("SQL Exception happened !!");
		this->print_sql_exception(e);
	}
	return ret;
}

template<> const int voba::MySQLConnector<voba::Person>::update(const voba::Person p)
{
	
}

template<> const int voba::MySQLConnector<voba::Person>::remove(const voba::Person p)
{
	
}

// Team specialization
template<> sql::ResultSet* voba::MySQLConnector<voba::Team>::select(const std::string id)
{
	
}

template<> const bool voba::MySQLConnector<voba::Team>::insert(const voba::Team p)
{
	
}

template<> const int voba::MySQLConnector<voba::Team>::update(const voba::Team p)
{
	
}

template<> const int voba::MySQLConnector<voba::Team>::remove(const voba::Team p)
{
	
}

