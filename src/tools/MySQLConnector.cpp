#include "MySQLConnector.h"

template <class T>
const std::string voba::MySQLConnector<T>::CLASS_NAME = "MySQLConnector."+T::CLASS_NAME;

template <class T>
voba::MySQLConnector<T>::MySQLConnector()
	: Logable(voba::MySQLConnector<T>::CLASS_NAME)
{
	// get table by class name
	// the create connnection to mysql
	this->table = this->info.get_table(T::CLASS_NAME);
	
	this->driver = get_driver_instance();
	this->connection = this->driver->connect(info.get_server(), info.get_account(), info.get_pwd());
	this->connection->setSchema(info.get_schema());

	this->statement = this->connection->createStatement();
}

template <class T>
voba::MySQLConnector<T>::~MySQLConnector()
{
	// delete variable initialize at constructor
	delete connection;
	delete statement;
}

template <class T>
sql::ResultSet* voba::MySQLConnector<T>::select()
{
	// use SqlCommandBuilder generate query and execute
	sql::ResultSet *result_set;
	
	std::string query = this->builder.select().from(this->table).to_string();
	
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
	// use SqlCommandBuilder generate query and execute
	voba::Column cid("id", voba::ColumnType::UUID);
	cid.set_value(id.to_string());
	std::list<voba::Column> columns;
	columns.push_back(cid);
	return this->select(columns);
}

template <class T>
sql::ResultSet* voba::MySQLConnector<T>::select(const std::list<Column> where_conditions)
{
	// use SqlCommandBuilder generate query and execute
	sql::ResultSet *result_set;
	
	std::string query = this->builder.select().from(this->table).where(where_conditions).to_string();
	
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
	if (!this->validate(t))
	{
		this->logger.warning("Model with empty ID while removing");
		return -1;
	}
	
	// use SqlCommandBuilder generate query and execute
	Column tid("id", voba::ColumnType::UUID);
	tid.set_value(t.get_id().to_string());
	return this->remove(tid);
}

template <class T>
const int voba::MySQLConnector<T>::remove(const voba::Column where_condition)
{
	std::list<voba::Column> columns;
	columns.push_back(where_condition);
	return this->remove(columns);
}

template <class T>
const int voba::MySQLConnector<T>::remove(const std::list<voba::Column> where_conditions)
{
	// use SqlCommandBuilder generate query and execute
	int ret = 0;
	
	std::string query = this->builder.remove().from(this->table).where(where_conditions).to_string();
	
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

template <class T>
sql::ResultSet* voba::MySQLConnector<T>::execute_query(const std::string query)
{
	sql::ResultSet *result_set;
	
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
const int voba::MySQLConnector<T>::execute(const std::string query)
{
	// use SqlCommandBuilder generate query and execute
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

// private function
template <class T>
void voba::MySQLConnector<T>::print_sql_exception(const sql::SQLException e)
{
	// handle function when catch sql exception
	std::string error_msg = "# ERR: ";
	error_msg += e.what();
	error_msg += " (MySQL error code: ";
	error_msg += std::to_string(e.getErrorCode());
	error_msg += ", SQLState: ";
	error_msg += e.getSQLState();
	error_msg += " )";
	this->logger.error(error_msg);
}

template <class T>
const bool voba::MySQLConnector<T>::validate(const T t)
{
	bool is_empty = false;
	UUID emptyUUID;
	
	if (is_empty)
	{
		is_empty = true;
	}
	else if (emptyUUID == t.get_id())
	{
		is_empty = true;
	}
	
	return !is_empty;
}

// Game specialization
template<> const int voba::MySQLConnector<voba::Game>::insert(const voba::Game g)
{
	if (!this->validate(t))
	{
		this->logger.warning("Game with empty ID while inserting");
		return -1;
	}
	
	// use SqlCommandBuilder generate query and execute
	voba::Column id("id", voba::ColumnType::UUID, g.get_id().to_string());
	voba::Column team1_id("team_1_id", voba::ColumnType::UUID, g.get_team1().get_id().to_string());
	voba::Column team2_id("team_2_id", voba::ColumnType::UUID, g.get_team2().get_id().to_string());
	voba::Column judge_id("judge_id", voba::ColumnType::UUID, g.get_judge().get_id().to_string());
	voba::Column game_time("game_time", voba::ColumnType::DateTime, g.get_game_time().to_string(false));
	std::list<voba::Column> values = { id, team1_id, team2_id, judge_id, game_time };
		
	std::string query = this->builder.insert(this->table).values(values).to_string();
	
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

template<> const int voba::MySQLConnector<voba::Game>::update(const voba::Game g)
{
	if (!this->validate(t))
	{
		this->logger.warning("Game with empty ID while updating");
		return -1;
	}
	
	// use SqlCommandBuilder generate query and execute
	voba::Column team1_id("team_1_id", voba::ColumnType::UUID, g.get_team1().get_id().to_string());
	voba::Column team2_id("team_2_id", voba::ColumnType::UUID, g.get_team2().get_id().to_string());
	voba::Column judge_id("judge_id", voba::ColumnType::UUID, g.get_judge().get_id().to_string());
	voba::Column game_time("game_time", voba::ColumnType::DateTime, g.get_game_time().to_string(false));
	std::list<voba::Column> sets = { team1_id, team2_id, judge_id, game_time };
	
	voba::Column id("id", voba::ColumnType::UUID, g.get_id().to_string());
	std::list<voba::Column> where_conditions;
	where_conditions.push_back(id);
		
	std::string query = this->builder.update(this->table).set(sets).where(where_conditions).to_string();
	
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

// Person specialization
template<> const int voba::MySQLConnector<voba::Person>::insert(const voba::Person p)
{
	if (!this->validate(t))
	{
		this->logger.warning("Person with empty ID while inserting");
		return -1;
	}
	
	// use SqlCommandBuilder generate query and execute
	voba::Column id("id", voba::ColumnType::UUID, p.get_id().to_string());
	voba::Column name("name", voba::ColumnType::String, p.get_name());
	voba::Column age("age", voba::ColumnType::Integer, std::to_string(p.get_age()));
	voba::Column gender("gender", voba::ColumnType::Boolean, std::to_string(static_cast<bool>(p.get_gender())));
	voba::Column phonenumber("phone_number", voba::ColumnType::String, p.get_phonenumber());
	voba::Column status("is_active", voba::ColumnType::Boolean, std::to_string(static_cast<bool>(p.get_active_status())));
	
	std::list<voba::Column> values = { id, name, age, gender, phonenumber, status };
		
	std::string query = this->builder.insert(this->table).values(values).to_string();
	
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
	if (!this->validate(p))
	{
		this->logger.warning("Person with empty ID while updating");
		return -1;
	}
	
	// use SqlCommandBuilder generate query and execute
	voba::Column name("name", voba::ColumnType::String, p.get_name());
	voba::Column age("age", voba::ColumnType::Integer, std::to_string(p.get_age()));
	voba::Column gender("gender", voba::ColumnType::Boolean, std::to_string(static_cast<bool>(p.get_gender())));
	voba::Column phonenumber("phone_number", voba::ColumnType::String, p.get_phonenumber());
	voba::Column status("is_active", voba::ColumnType::Boolean, std::to_string(static_cast<bool>(p.get_active_status())));
	std::list<voba::Column> sets = { name, age, gender, phonenumber, status };
	
	voba::Column id("id", voba::ColumnType::UUID, p.get_id().to_string());
	std::list<voba::Column> where_conditions;
	where_conditions.push_back(id);
	
	std::string query = this->builder.update(this->table).set(sets).where(where_conditions).to_string();
	
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
	if (!this->validate(t))
	{
		this->logger.warning("Team with empty ID while inserting");
		return -1;
	}
	
	// use SqlCommandBuilder generate query and execute
	voba::Column id("id", voba::ColumnType::UUID, t.get_id().to_string());
	voba::Column name("name", voba::ColumnType::String, t.get_name());
	voba::Column prefer_week("prefer_week", voba::ColumnType::String, t.get_prefer_week());
	voba::Column prefer_time("prefer_time", voba::ColumnType::String, t.get_prefer_time());
		
	int ret = 0;
	for (unsigned int i = 0; i < t.size(); i++)
	{
		Column member_id("member_id", voba::ColumnType::UUID, t.get_member(i).get_id().to_string());
		std::list<voba::Column> values = { id, name, member_id, prefer_week, prefer_time };
		std::string query = this->builder.insert(this->table).values(values).to_string();
		try
		{
			ret += this->statement->execute(query);
		}
		catch (sql::SQLException e)
		{
			this->logger.error("SQL Exception happened !!");
			this->print_sql_exception(e);
		}
	}
	
	return ret;
}

template<> const int voba::MySQLConnector<voba::Team>::update(const voba::Team t)
{
	if (!this->validate(t))
	{
		this->logger.warning("Team with empty ID while updating");
		return -1;
	}
	
	// use SqlCommandBuilder generate query and execute
	voba::Column name("name", voba::ColumnType::String, t.get_name());
	voba::Column prefer_week("prefer_week", voba::ColumnType::String, t.get_prefer_week());
	voba::Column prefer_time("prefer_time", voba::ColumnType::String, t.get_prefer_time());
	std::list<voba::Column> sets = { name, prefer_week, prefer_time };
		
	voba::Column id("id", voba::ColumnType::UUID, t.get_id().to_string());
	std::list<voba::Column> where_conditions;
	where_conditions.push_back(id);
	
	std::string query = this->builder.update(this->table).set(sets).where(where_conditions).to_string();
	
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

