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
const std::map<voba::SqlCommand, std::string> voba::SqlCommandBuilder::COMMANDS = init_map();

const std::map<voba::SqlCommand, std::string> voba::SqlCommandBuilder::init_map()
{
	std::map<voba::SqlCommand, std::string> map;
	
	boost::property_tree::ptree tree;
    boost::property_tree::read_xml("resources/crud.xml", tree);
	
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::select, tree.get<std::string>("commands.select")));
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::insert, tree.get<std::string>("commands.insert")));
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::update, tree.get<std::string>("commands.update")));
	map.insert(std::pair<voba::SqlCommand, std::string>(voba::SqlCommand::remove, tree.get<std::string>("commands.delete")));
	
	return map;
}

const std::string voba::SqlCommandBuilder::build_select(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::select)->second;
	
	
	
	return ret;
}

const std::string voba::SqlCommandBuilder::build_insert(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::insert)->second;
	
	
	
	return ret;
}

const std::string voba::SqlCommandBuilder::build_update(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::update)->second;
	
	
	
	return ret;
}

const std::string voba::SqlCommandBuilder::build_remove(const std::list<std::string> strs)
{
	std::string ret = voba::SqlCommandBuilder::COMMANDS.find(voba::SqlCommand::remove)->second;
	
	
	
	return ret;
}
