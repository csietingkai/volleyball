#include "SqlCommandBuilder.h"

// public function
voba::SqlCommandBuilder::SqlCommandBuilder()
{
	this->store = "";
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::select()
{
	voba::Column all("*");
	return this->select(all);
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::select(const voba::Column column)
{
	this->store += voba::SqlCommandBuilder::SELECT;
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += column.get_name();
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::select(const std::list<voba::Column> columns)
{
	this->store += voba::SqlCommandBuilder::SELECT;
	this->store += voba::SqlCommandBuilder::SPACE;
	for (auto it = columns.begin(); it != columns.end(); it++)
	{
		this->store += it->get_name();
		this->store += voba::SqlCommandBuilder::COMMA;
	}
	this->store = this->store.substr(0, this->store.length()-1);
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::insert(const voba::Table table)
{
	this->store += voba::SqlCommandBuilder::INSERT;
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += table.get_name();
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::update(const Table table)
{
	this->store += voba::SqlCommandBuilder::UPDATE;
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += table.get_name();
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::remove()
{
	this->store += voba::SqlCommandBuilder::REMOVE;
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::from(const Table table)
{
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += voba::SqlCommandBuilder::FROM;
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += table.get_name();
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::where(const Column column)
{
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += voba::SqlCommandBuilder::WHERE;
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += this->handle_column(column);
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::where(const std::list<Column> columns)
{
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += voba::SqlCommandBuilder::WHERE;
	this->store += voba::SqlCommandBuilder::SPACE;
	for (auto it = columns.begin(); it != columns.end(); it++)
	{
		this->store += this->handle_column(*it);
		this->store += voba::SqlCommandBuilder::SPACE;
		this->store += voba::SqlCommandBuilder::AND;
		this->store += voba::SqlCommandBuilder::SPACE;
	}
	this->store = this->store.substr(0, this->store.length()-5);
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::values(const std::list<Column> columns)
{
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += voba::SqlCommandBuilder::VALUES;
	this->store += voba::SqlCommandBuilder::LEFT_PARENTHESIS;
	for (auto it = columns.begin(); it != columns.end(); it++)
	{
		bool is_string = (it->get_type() != voba::ColumnType::Boolean && it->get_type() != voba::ColumnType::Integer);
	
		if (is_string)
		{
			this->store += "'";
			this->store += it->get_value();
			this->store += "'";
		}
		else
		{
			this->store += it->get_value();
		}
		this->store += voba::SqlCommandBuilder::COMMA;
	}
	this->store = this->store.substr(0, this->store.length()-1);
	this->store += voba::SqlCommandBuilder::RIGHT_PARENTHESIS;
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::set(const Column column)
{
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += voba::SqlCommandBuilder::SET;
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += this->handle_column(column);
	return *this;
}

voba::SqlCommandBuilder& voba::SqlCommandBuilder::set(const std::list<Column> columns)
{
	this->store += voba::SqlCommandBuilder::SPACE;
	this->store += voba::SqlCommandBuilder::SET;
	this->store += voba::SqlCommandBuilder::SPACE;
	for (auto it = columns.begin(); it != columns.end(); it++)
	{
		this->store += this->handle_column(*it);
		this->store += voba::SqlCommandBuilder::COMMA;
	}
	this->store = this->store.substr(0, this->store.length()-1);
	return *this;
}

const std::string voba::SqlCommandBuilder::to_string()
{
	std::string ret = this->store;
	this->store = "";
	return ret;
}

// protected
const std::string voba::SqlCommandBuilder::SELECT = "SELECT";
const std::string voba::SqlCommandBuilder::INSERT = "INSERT INTO";
const std::string voba::SqlCommandBuilder::UPDATE = "UPDATE";
const std::string voba::SqlCommandBuilder::REMOVE = "DELETE";
const std::string voba::SqlCommandBuilder::FROM = "FROM";
const std::string voba::SqlCommandBuilder::WHERE = "WHERE";
const std::string voba::SqlCommandBuilder::VALUES = "VALUES";
const std::string voba::SqlCommandBuilder::SET = "SET";
const std::string voba::SqlCommandBuilder::SPACE = " ";
const std::string voba::SqlCommandBuilder::COMMA = ",";
const std::string voba::SqlCommandBuilder::EQUAL = "=";
const std::string voba::SqlCommandBuilder::AND = "AND";
const std::string voba::SqlCommandBuilder::LEFT_PARENTHESIS = "(";
const std::string voba::SqlCommandBuilder::RIGHT_PARENTHESIS = ")";

const std::string voba::SqlCommandBuilder::handle_column(const voba::Column column)
{
	bool is_string = (column.get_type() != voba::ColumnType::Boolean && column.get_type() != voba::ColumnType::Integer);
	
	std::string ret = "";
	ret += column.get_name();
	ret += voba::SqlCommandBuilder::EQUAL;
	if (is_string)
	{
		ret += "'";
		ret += column.get_value();
		ret += "'";
	}
	else
	{
		ret += column.get_value();
	}
	
	return ret;
}
