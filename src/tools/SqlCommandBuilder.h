#ifndef SQL_COMMAND_BUILDER_H_
#define SQL_COMMAND_BUILDER_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <list>
#include <map>
#include <random>
#include <iostream>

#include "../utils/Utils.h"

namespace voba
{
	enum class SqlCommand
	{
		select,
		insert,
		update,
		remove
	};
	
	class SqlCommandBuilder
	{
		public:
			const static std::string build(const SqlCommand command, const std::list<std::string> strs);
		
		protected:
			const static std::string SELECT_NODE;
			const static std::string INSERT_NODE;
			const static std::string UPDATE_NODE;
			const static std::string REMOVE_NODE;
			
			const static std::string TABLE_NAME_TAG;
			const static std::string CONDITIONS_TAG;
			const static std::string COLUMN_NAME_TAG;
			const static std::string COLUMN_VALUE_TAG;
			const static std::string VALUES_TAG;
			
			const static std::map<SqlCommand, std::string> COMMANDS;
			
			const static std::map<SqlCommand, std::string> init_map();
			
			const static std::string build_select(const std::list<std::string> strs);
			const static std::string build_insert(const std::list<std::string> strs);
			const static std::string build_update(const std::list<std::string> strs);
			const static std::string build_remove(const std::list<std::string> strs);
	};
}

#endif // SQL_COMMAND_BUILDER_H_
