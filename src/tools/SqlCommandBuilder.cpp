#include "SqlCommandBuilder.h"

// public function
const std::string voba::SqlCommandBuilder::build(const voba::SqlCommand command, const std::list<std::string> strs)
{
	std::string ret = "";
	
	switch(command)
	{
		case voba::SqlCommand::select:
			ret = voba::SqlCommandBuilder::build_select(strs);
			break;
			
		case voba::SqlCommand::insert:
			ret = voba::SqlCommandBuilder::build_insert(strs);
			break;
			
		case voba::SqlCommand::update:
			ret = voba::SqlCommandBuilder::build_update(strs);
			break;
			
		case voba::SqlCommand::remove:
			ret = voba::SqlCommandBuilder::build_remove(strs);
			break;
	}
	
	return ret;
}

// private function
const std::string voba::SqlCommandBuilder::SELECT_NODE = "commands.select";
const std::string voba::SqlCommandBuilder::INSERT_NODE = "commands.insert";
const std::string voba::SqlCommandBuilder::UPDATE_NODE = "commands.update";
const std::string voba::SqlCommandBuilder::REMOVE_NODE = "commands.delete";

const std::string voba::SqlCommandBuilder::TABLE_NAME_TAG = "[TABLE_NAME]";
const std::string voba::SqlCommandBuilder::CONDITIONS_TAG = "[CONDITIONS]";
const std::string voba::SqlCommandBuilder::COLUMN_NAME_TAG = "[COLUMN_NAME]";
const std::string voba::SqlCommandBuilder::COLUMN_VALUE_TAG = "[COLUMN_VALUE]";
const std::string voba::SqlCommandBuilder::VALUES_TAG = "[VALUES]";

const std::map<voba::SqlCommand, std::string> voba::SqlCommandBuilder::COMMANDS = init_map();

const std::map<voba::SqlCommand, std::string> voba::SqlCommandBuilder::init_map()
{
	std::map<voba::SqlCommand, std::string> map;
	
	boost::property_tree::ptree tree;
    boost::property_tree::read_xml("resources/crud.xml", tree);
	
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::select, tree.get<std::string>(voba::SqlCommandBuilder::SELECT_NODE)));
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::insert, tree.get<std::string>(voba::SqlCommandBuilder::INSERT_NODE)));
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::update, tree.get<std::string>(voba::SqlCommandBuilder::UPDATE_NODE)));
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::remove, tree.get<std::string>(voba::SqlCommandBuilder::REMOVE_NODE)));
	
	return map;
}

const std::string voba::SqlCommandBuilder::build_select(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::select)->second; 
	ret = voba::Utils::trim(ret);
	
	if (strs.size() != 3)
	{
		return ret;
	}
	
	std::list<std::string>::const_iterator it = strs.begin();
	
	std::string column_name = *it;
	it++;
	std::string table_name = *it;
	it++;
	std::string conditions = *it;
	
	voba::Utils::replace(ret, voba::SqlCommandBuilder::COLUMN_NAME_TAG, column_name);
	voba::Utils::replace(ret, voba::SqlCommandBuilder::TABLE_NAME_TAG, table_name);
	voba::Utils::replace(ret, voba::SqlCommandBuilder::CONDITIONS_TAG, conditions);
	
	return ret;
}

const std::string voba::SqlCommandBuilder::build_insert(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::insert)->second; 
	ret = voba::Utils::trim(ret);
	
	if (strs.size() != 2)
	{
		return ret;
	}
	
	std::list<std::string>::const_iterator it = strs.begin();
	
	std::string table_name = *it;
	it++;
	std::string values = *it;
	
	voba::Utils::replace(ret, voba::SqlCommandBuilder::TABLE_NAME_TAG, table_name);
	voba::Utils::replace(ret, voba::SqlCommandBuilder::VALUES_TAG, values);
	
	return ret;
}

const std::string voba::SqlCommandBuilder::build_update(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::update)->second; 
	ret = voba::Utils::trim(ret);
	
	if (strs.size() != 4)
	{
		return ret;
	}
	
	std::list<std::string>::const_iterator it = strs.begin();
	
	std::string table_name = *it;
	it++;
	std::string column_name = *it;
	it++;
	std::string column_value = *it;
	it++;
	std::string conditions = *it;
	
	voba::Utils::replace(ret, voba::SqlCommandBuilder::TABLE_NAME_TAG, table_name);
	voba::Utils::replace(ret, voba::SqlCommandBuilder::COLUMN_NAME_TAG, column_name);
	voba::Utils::replace(ret, voba::SqlCommandBuilder::COLUMN_VALUE_TAG, column_value);
	voba::Utils::replace(ret, voba::SqlCommandBuilder::CONDITIONS_TAG, conditions);
	
	return ret;
}

const std::string voba::SqlCommandBuilder::build_remove(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::remove)->second; 
	ret = voba::Utils::trim(ret);
	
	if (strs.size() != 2)
	{
		return ret;
	}
	
	std::list<std::string>::const_iterator it = strs.begin();
	
	std::string table_name = *it;
	it++;
	std::string conditions = *it;
	
	voba::Utils::replace(ret, voba::SqlCommandBuilder::TABLE_NAME_TAG, table_name);
	voba::Utils::replace(ret, voba::SqlCommandBuilder::CONDITIONS_TAG, conditions);
	
	return ret;
}
