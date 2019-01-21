#include "MySQLConnector.h"

template <class T>
const std::string voba::MySQLConnector<T>::CLASS_NAME = "MySQLConnector."+T::CLASS_NAME;

// constructor
template <class T>
voba::MySQLConnector<T>::MySQLConnector()
	: Logable(voba::MySQLConnector<T>::CLASS_NAME)
{
	this->table = this->info.get_table(T::CLASS_NAME);
	
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

template <class T>
sql::ResultSet* voba::MySQLConnector<T>::select(const std::string id)
{
	voba::Column cid("id");
	cid.set_value(id);
	std::list<voba::Column> columns;
	columns.push_back(cid);
	return this->select(columns);
}

template <class T>
sql::ResultSet* voba::MySQLConnector<T>::select(const std::list<Column> where_conditions)
{
	sql::ResultSet *result_set;
	SqlCommandBuilder builder;
	
	std::string query = builder.select().from(this->table).where(where_conditions).to_string();
	
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

template <class T>
const int voba::MySQLConnector<T>::remove(const T t)
{
	Column tid("id");
	tid.set_value(t.get_id());
	std::list<voba::Column> columns;
	columns.push_back(tid);
	return this->remove(columns);
}

template <class T>
const int voba::MySQLConnector<T>::remove(const std::list<Column> where_conditions)
{
	int ret = 0;
	
	SqlCommandBuilder builder;
	std::string query = builder.remove().from(this->table).where(where_conditions).to_string();
	
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

// private function
template <class T>
void voba::MySQLConnector<T>::print_sql_exception(const sql::SQLException e)
{
	std::string error_msg = "# ERR: ";
	error_msg += e.what();
	error_msg += " (MySQL error code: ";
	error_msg += std::to_string(e.getErrorCode());
	error_msg += ", SQLState: ";
	error_msg += e.getSQLState();
	error_msg += " )";
	this->logger.error(error_msg);
}

// Game specialization
template<> const bool voba::MySQLConnector<voba::Game>::insert(const voba::Game g)
{
	return 0;
}

template<> const int voba::MySQLConnector<voba::Game>::update(const voba::Game g, const std::string old_id)
{
	return 0;
}

// Person specialization
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

template<> const int voba::MySQLConnector<voba::Person>::update(const voba::Person p, const std::string old_id)
{
	int ret = 0;
	std::vector<std::string> columns
	{
		"name", "'"+p.get_name()+"'",
		"age", std::to_string(p.get_age()),
		"gender", std::to_string(static_cast<bool>(p.get_gender())),
		"phone_number", "'"+p.get_phonenumber()+"'",
		"is_active", std::to_string(static_cast<bool>(p.get_active_status())),
		"id", "'"+p.get_id()+"'"
	};
	
	for (unsigned int i = 0; i < columns.size(); i+=2)
	{
		std::list<std::string> query_list = {};
		query_list.push_back(this->table_name);
		query_list.push_back(columns[i]);
		query_list.push_back(columns[i+1]);
		query_list.push_back("ID='"+old_id+"'");
		
		std::string query = voba::SqlCommandBuilder::build(voba::SqlCommand::update, query_list);
		
		this->logger.debug(query);
		
		try
		{
			ret = this->statement->executeUpdate(query);
		}
		catch (sql::SQLException e)
		{
			this->logger.error("SQL Exception happened !!");
			this->print_sql_exception(e);
		}
	}
	return ret;
}

// Team specialization
template<> const bool voba::MySQLConnector<voba::Team>::insert(const voba::Team t)
{
	return 0;
}

template<> const int voba::MySQLConnector<voba::Team>::update(const voba::Team t, const std::string old_id)
{
	return 0;
}

