#ifndef SERVER_INFO_H_
#define SERVER_INFO_H_

#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>
#include <iostream>
#include <vector>

namespace pt = boost::property_tree;

namespace voba
{
	class Column
	{
		public:
			Column() {};
			Column(std::string name, std::string type): name(name), type(type), nullable(false) {};
			Column(std::string name, std::string type, bool nullable): name(name), type(type), nullable(nullable) {};
			
			void set_name(std::string name) { this->name = name; };
			void set_type(std::string type) { this->type = type; };
			void set_value(std::string value) { this->value = value; };
			void set_nullable(bool nullable) { this->nullable = nullable; };
			
			const std::string get_name() const { return this->name; };
			const std::string get_type() const { return this->type; };
			const std::string get_value() const { return this->value; };
			const bool get_nullable() const { return this->nullable; };
		
		private:
			std::string name;
			std::string type;
			std::string value;
			bool nullable;
	};
	
	class Table
	{
		public:
			Table() {};
			Table(std::string name, std::string class_name): name(name), class_name(class_name) {};
			
			void set_name(std::string name) { this->name = name; };
			void set_class_name(std::string class_name) { this->class_name = class_name; };
			void push_back(Column column) { columns.push_back(column); };
			void pop_back() { columns.pop_back(); };
			
			const std::string get_name() const { return this->name; };
			const std::string get_class_name() const { return this->class_name; };
		
		private:
			std::string name;
			std::string class_name;
			std::vector<voba::Column> columns;
	};
	
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
			
			void init(const std::string xml_path);
	};
}

#endif // SERVER_INFO_H_
