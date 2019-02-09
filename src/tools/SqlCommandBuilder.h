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
			/**
			 * constructor of SqlCommandBuilder <br/>
			 * initialize storage string
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder();
			
			/**
			 * select *
			 * 
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& select();
			/**
			 * select [column].name
			 * 
			 * @param column(Column) : column with name
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @see SqlCommandBuilder #select(list<Column>)
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& select(const Column column);
			/**
			 * select [column1].name, [column2].name, ...
			 * 
			 * @param columns(list<Column>) : column list with name
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& select(const std::list<Column> columns);
			
			/**
			 * insert into [table].name
			 * 
			 * @param table(Table) : table with name
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& insert(const Table table);
			
			/**
			 * update [table].name
			 * 
			 * @param table(Table) : table with name
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& update(const Table table);
			
			/**
			 * delete
			 * 
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& remove();
			
			/**
			 * from [table].name
			 * 
			 * @param table(Table) : table with name
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& from(const Table table);
			
			/**
			 * where [column].name = [column].value
			 * 
			 * @param column(Column) : column with name and value
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @see SqlCommandBuilder #where(list<Column>)
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& where(const Column column);
			/**
			 * where [column1].name = [column1].value AND [column2].name = [column2].value AND ...
			 * 
			 * @param column(Column) : list of column with name and value
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& where(const std::list<Column> columns);
			
			/**
			 * values([column1].value, [column2].value, ...)
			 * 
			 * @param column(Column) : list of column with name and value
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& values(const std::list<Column> columns);
			
			/**
			 * set [column].name = [column].value
			 * 
			 * @param column(Column) : column with name and value
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @see SqlCommandBuilder #set(list<Column>)
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& set(const Column column);
			/**
			 * set [column1].name = [column1].value AND [column2].name = [column2].value AND ...
			 * 
			 * @param column(Column) : list column with name and value
			 * @return SqlCommandBuilder& : current builder reference
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
			SqlCommandBuilder& set(const std::list<Column> columns);
			
			/**
			 * return the current storage string and then clear it
			 * 
			 * @return store : the sql command
			 * 
			 * @auther tingkai
			 * @date 2019.02.09
			 */
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
