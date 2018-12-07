#include "ServerInfo.h"

// constructor
voba::ServerInfo::ServerInfo(std::string xml_path)
{
	pt::ptree ptree;
    pt::read_xml(xml_path, ptree);
    
    this->server = ptree.get<std::string>(voba::ServerInfo::SERVER_NODE_NAME);
    this->account = ptree.get<std::string>(voba::ServerInfo::ACCOUNT_NODE_NAME);
    this->pwd = ptree.get<std::string>(voba::ServerInfo::PWD_NODE_NAME);
    this->schema = ptree.get<std::string>(voba::ServerInfo::SCHEMA_NODE_NAME);
 
    BOOST_FOREACH(pt::ptree::value_type const& table, ptree.get_child(voba::ServerInfo::TABLES_NODE_NAME)) 
    {
    	//std::cout << table.first << "\t" << table.second.get<std::string>("<xmlattr>.name") << " " << table.second.get<std::string>("<xmlattr>.class_name") << std::endl;
    	std::string table_name = table.second.get<std::string>("<xmlattr>.name");
    	std::string class_name = table.second.get<std::string>("<xmlattr>.class_name");
    	Table t(table_name, class_name);
    	BOOST_FOREACH(pt::ptree::value_type const& column, table.second.get_child(""))
    	{
    		if (column.first != "<xmlattr>")
    		{
    			//std::cout << "\t" << column.first << "\t" << column.second.get<std::string>("<xmlattr>.name") << " " << column.second.get<std::string>("<xmlattr>.type") << " " << column.second.get<bool>("<xmlattr>.nullable", false) << std::endl;
				std::string column_name = column.second.get<std::string>("<xmlattr>.name");
				std::string column_type = column.second.get<std::string>("<xmlattr>.type");
				bool nullable = column.second.get<bool>("<xmlattr>.nullable", false);
				Column c(column_name, column_type, nullable);
				t.insert_back(c);
    		}
    	}
    	this->tables.push_back(t);
    }
}

// public
const std::string voba::ServerInfo::get_table_name(const std::string class_name) const
{
	std::string ret = "";
	for (Table table : this->tables)
	{
		if (class_name == table.get_class_name())
		{
			ret = table.get_name();
			break;
		}
	}
	return ret;
}

// private 
const std::string voba::ServerInfo::ROOT_NAME = "connection";
const std::string voba::ServerInfo::SERVER_NODE_NAME = voba::ServerInfo::ROOT_NAME+".server";
const std::string voba::ServerInfo::ACCOUNT_NODE_NAME = voba::ServerInfo::ROOT_NAME+".account";
const std::string voba::ServerInfo::PWD_NODE_NAME = voba::ServerInfo::ROOT_NAME+".pwd";
const std::string voba::ServerInfo::SCHEMA_NODE_NAME = voba::ServerInfo::ROOT_NAME+".schema";
const std::string voba::ServerInfo::TABLES_NODE_NAME = voba::ServerInfo::ROOT_NAME+".tables";
const std::string voba::ServerInfo::TABLE_NODE_NAME = "table";
const std::string voba::ServerInfo::COLUMN_NODE_NAME = "column";
const std::string voba::ServerInfo::ATTR_NAME = "<xmlattr>.name";
const std::string voba::ServerInfo::ATTR_CLASS_NAME = "<xmlattr>.class_name";
const std::string voba::ServerInfo::ATTR_TYPE = "<xmlattr>.type";
const std::string voba::ServerInfo::ATTR_NULLABLE = "<xmlattr>.nullable";
