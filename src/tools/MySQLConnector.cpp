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
sql::ResultSet* voba::MySQLConnector<T>::select()
{
	sql::ResultSet *result_set;
	SqlCommandBuilder builder;
	
	std::string query = builder.select().from(this->table).to_string();
	
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
sql::ResultSet* voba::MySQLConnector<T>::select(const voba::UUID id)
{
	voba::Column cid("id", "uuid");
	cid.set_value(id.to_string());
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
	tid.set_value(t.get_id().to_string());
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
template<> const int voba::MySQLConnector<voba::Game>::insert(const voba::Game g)
{
	return 0;
}

template<> const int voba::MySQLConnector<voba::Game>::update(const voba::Game g)
{
	return 0;
}

// Person specialization
template<> const int voba::MySQLConnector<voba::Person>::insert(const voba::Person p)
{
	voba::Column id("id", "string");
	id.set_value(p.get_id().to_string());
	voba::Column name("name", "string");
	name.set_value(p.get_name());
	voba::Column age("age", "int");
	age.set_value(std::to_string(p.get_age()));
	voba::Column gender("gender", "bool");
	gender.set_value(std::to_string(static_cast<bool>(p.get_gender())));
	voba::Column phonenumber("phone_number", "string");
	phonenumber.set_value(p.get_phonenumber());
	voba::Column status("is_active", "bool");
	status.set_value(std::to_string(static_cast<bool>(p.get_active_status())));
	
	std::list<voba::Column> values = { id, name, age, gender, phonenumber, status };
		
	voba::SqlCommandBuilder builder;
	std::string query = builder.insert(this->table).values(values).to_string();
	
	int ret = 0;
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
	voba::Column name("name", "string");
	name.set_value(p.get_name());
	voba::Column age("age", "int");
	age.set_value(std::to_string(p.get_age()));
	voba::Column gender("gender", "bool");
	gender.set_value(std::to_string(static_cast<bool>(p.get_gender())));
	voba::Column phonenumber("phone_number", "string");
	phonenumber.set_value(p.get_phonenumber());
	voba::Column status("is_active", "bool");
	status.set_value(std::to_string(static_cast<bool>(p.get_active_status())));;
	std::list<voba::Column> sets = { name, age, gender, phonenumber, status };
	
	voba::Column id("id", "string");
	id.set_value(p.get_id().to_string());
	std::list<voba::Column> where_conditions;
	where_conditions.push_back(id);
	
	voba::SqlCommandBuilder builder;
	std::string query = builder.update(this->table).set(sets).where(where_conditions).to_string();
	
	std::cout << query << std::endl;
	
	int ret = 0;
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

// Team specialization
template<> const int voba::MySQLConnector<voba::Team>::insert(const voba::Team t)
{
	return 0;
}

template<> const int voba::MySQLConnector<voba::Team>::update(const voba::Team t)
{
	return 0;
}

