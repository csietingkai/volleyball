#ifndef SERVER_INFO_H_
#define SERVER_INFO_H_

#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>
#include <iostream>
#include <vector>

#include "Utils.h"

namespace pt = boost::property_tree;

namespace voba
{
	/**
	 * mysql column type
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.12.05
	 */
	enum class ColumnType : int
	{
		UUID,
		String,
		Integer, 
		Boolean,
		DateTime,
		Unknown
	};
	
	/**
	 * convert string to ColumnType
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.12.05
	 */
	const ColumnType string_to_column_type(const std::string str);
	std::ostream& operator <<(std::ostream& strm, const ColumnType& role);
	
	/**
	 * the class represent a column in a table in database
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.12.05
	 */
	class Column
	{
		public:
			Column() {};
			Column(const std::string name): name(name), type(ColumnType::String), value(""), nullable(false) {};
			Column(const std::string name, const ColumnType type): name(name), type(type), value(""), nullable(false) {};
			Column(const std::string name, const ColumnType type, const std::string value): name(name), type(type), value(value), nullable(false) {};
			Column(const std::string name, const ColumnType type, const bool nullable): name(name), type(type), value(""), nullable(nullable) {};
			Column(const std::string name, const ColumnType type, const std::string value, const bool nullable): name(name), type(type), value(value), nullable(nullable) {};
			
			void set_name(const std::string name) { this->name = name; };
			void set_type(const ColumnType type) { this->type = type; };
			void set_value(const std::string value) { this->value = value; };
			void set_nullable(const bool nullable) { this->nullable = nullable; };
			
			const std::string get_name() const { return this->name; };
			const ColumnType get_type() const { return this->type; };
			const std::string get_value() const { return this->value; };
			const bool get_nullable() const { return this->nullable; };
			
			const Column& operator =(const Column& other);
		
		private:
			std::string name;
			ColumnType type;
			std::string value;
			bool nullable;
	};
	
	/**
	 * the class represent a table in database
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.12.05
	 */
	class Table
	{
		public:
			Table() {};
			Table(const std::string name, const std::string class_name): name(name), class_name(class_name) {};
			Table(const Table& other) { this->operator=(other); }
			
			void set_name(std::string name) { this->name = name; };
			void set_class_name(std::string class_name) { this->class_name = class_name; };
			void push_back(Column column) { this->columns.push_back(column); };
			void pop_back() { this->columns.pop_back(); };
			const unsigned int size() const { return this->columns.size(); };
			const Column get_column(unsigned int index) const { return this->columns[index]; };
			
			const std::string get_name() const { return this->name; };
			const std::string get_class_name() const { return this->class_name; };
			
			const Table& operator =(const Table& other);
		
		private:
			std::string name;
			std::string class_name;
			std::vector<voba::Column> columns;
	};
	
	/**
	 * get the configuration of MySQL database
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.12.05
	 */
	class ServerInfo
	{
		public:
			ServerInfo();
			ServerInfo(const std::string xml_path);
			
			const std::string get_server() const { return this->server; };
			const std::string get_account() const { return this->account; };
			const std::string get_pwd() const { return this->pwd; };
			const std::string get_schema() const { return this->schema; };
			const std::string get_table_name(const std::string class_name) const;
			const Table get_table(const std::string class_name) const;
			
		private:
			std::string server;
			std::string account;
			std::string pwd;
			std::string schema;
			std::vector<voba::Table> tables;
			
			const static std::string ROOT_NAME;
			const static std::string SERVER_NODE_NAME;
			const static std::string ACCOUNT_NODE_NAME;
			const static std::string PWD_NODE_NAME;
			const static std::string SCHEMA_NODE_NAME;
			const static std::string TABLES_NODE_NAME;
			const static std::string TABLE_NODE_NAME;
			const static std::string COLUMN_NODE_NAME;
			const static std::string ATTR_NAME;
			const static std::string ATTR_CLASS_NAME;
			const static std::string ATTR_TYPE;
			const static std::string ATTR_NULLABLE;
			
			/**
			 * read the 'server_info.xml' as server configuration <br/>
			 * &lt;table&gt; &lt;--&gt; class Table
			 * &lt;column&gt; &lt;--&gt; class Column
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			void init(const std::string xml_path);
	};
}

#endif // SERVER_INFO_H_
