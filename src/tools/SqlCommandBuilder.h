#ifndef SQL_COMMAND_BUILDER_H_
#define SQL_COMMAND_BUILDER_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <list>
#include <map>
#include <random>
#include <iostream>

#include "../utils/ServerInfo.h"
#include "../utils/Utils.h"

namespace voba
{
	class SqlCommandBuilder
	{
		public:
			SqlCommandBuilder();
			
			SqlCommandBuilder& select();
			SqlCommandBuilder& select(const Column column);
			SqlCommandBuilder& select(const std::list<Column> columns);
			
			SqlCommandBuilder& insert(const Table table);
			
			SqlCommandBuilder& update(const Table table);
			
			SqlCommandBuilder& remove();
			
			SqlCommandBuilder& from(const Table table);
			
			SqlCommandBuilder& where(const Column column);
			SqlCommandBuilder& where(const std::list<Column> columns);
			
			SqlCommandBuilder& values(const std::list<Column> columns);
			
			SqlCommandBuilder& set(const Column column);
			SqlCommandBuilder& set(const std::list<Column> columns);
			
			const std::string to_string();
		
		private:
			const static std::string SELECT;
			const static std::string INSERT;
			const static std::string UPDATE;
			const static std::string REMOVE;
			const static std::string FROM;
			const static std::string WHERE;
			const static std::string VALUES;
			const static std::string SET;
			const static std::string SPACE;
			const static std::string COMMA;
			const static std::string EQUAL;
			const static std::string AND;
			const static std::string LEFT_PARENTHESIS;
			const static std::string RIGHT_PARENTHESIS;
			
			std::string store;
			
			const std::string handle_column(const Column column);
	};
}

#endif // SQL_COMMAND_BUILDER_H_
