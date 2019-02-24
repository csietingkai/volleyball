#include "ServerInfo.h"

const voba::ColumnType voba::string_to_column_type(const std::string str)
{
	voba::ColumnType type = voba::ColumnType::Unknown;
	
	if (str.compare(voba::Utils::to_lower_case("uuid")) == 0)
	{
		type = voba::ColumnType::UUID;
	}
	else if (str.compare(voba::Utils::to_lower_case("string")) == 0)
	{
		type = voba::ColumnType::String;
	}
	else if (str.compare(voba::Utils::to_lower_case("integer")) == 0)
	{
		type = voba::ColumnType::Integer;
	}
	else if (str.compare(voba::Utils::to_lower_case("boolean")) == 0)
	{
		type = voba::ColumnType::Boolean;
	}
	else if (str.compare(voba::Utils::to_lower_case("datetime")) == 0)
	{
		type = voba::ColumnType::DateTime;
	}
	else
	{
		std::cerr << "Unknown Column Type" << std::endl;
	}
	
	return type;
}

std::ostream& voba::operator <<(std::ostream& strm, const voba::ColumnType& role)
{
	switch (role)
	{
		case voba::ColumnType::UUID:
			strm << "UUID";
			break;
		
		case voba::ColumnType::String:
			strm << "String";
			break;
		
		case voba::ColumnType::Integer:
			strm << "Integer";
			break;
		
		case voba::ColumnType::Boolean:
			strm << "Boolean";
			break;
		
		case voba::ColumnType::DateTime:
			strm << "DateTime";
			break;
		
		default:
			std::cerr << "invalid column type" << std::endl;
			break;
	}
	
	return strm;
}

const voba::Column& voba::Column::operator =(const voba::Column& other)
{
	if (this == &other)
	{
		return *this;
	}
	
	this->set_name(other.get_name());
	this->set_type(other.get_type());
	this->set_value(other.get_value());
	this->set_nullable(other.get_nullable());
	
	return *this;
}

const voba::Table& voba::Table::operator =(const voba::Table& other)
{
	if (this == &other)
	{
		return *this;
	}
	
	this->set_name(other.get_name());
	this->set_class_name(other.get_class_name());
	
	for (unsigned int i = 0; i < other.size(); i++)
	{
		this->push_back(other.get_column(i));
	}
	
	return *this;
}

// constructor
voba::ServerInfo::ServerInfo()
{
	this->init("resources/server_info.xml");
}

voba::ServerInfo::ServerInfo(const std::string xml_path)
{
	this->init(xml_path);
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

const voba::Table voba::ServerInfo::get_table(const std::string class_name) const
{
	voba::Table ret;
	for (Table table : this->tables)
	{
		if (class_name == table.get_class_name())
		{
			ret = table;
			break;
		}
	}
	return ret;
}

// private 
void voba::ServerInfo::init(const std::string xml_path)
{
	const std::string ROOT_NAME = "connection";
	const std::string SERVER_NODE_NAME = ROOT_NAME+".server.<xmlattr>.value";
	const std::string ACCOUNT_NODE_NAME = ROOT_NAME+".account.<xmlattr>.value";
	const std::string PWD_NODE_NAME = ROOT_NAME+".pwd.<xmlattr>.value";
	const std::string SCHEMA_NODE_NAME = ROOT_NAME+".schema.<xmlattr>.value";
	const std::string TABLES_NODE_NAME = ROOT_NAME+".tables";
	const std::string TABLE_NODE_NAME = "table";
	const std::string COLUMN_NODE_NAME = "column";
	const std::string ATTR_NAME = "<xmlattr>.name";
	const std::string ATTR_CLASS_NAME = "<xmlattr>.class_name";
	const std::string ATTR_TYPE = "<xmlattr>.type";
	const std::string ATTR_NULLABLE = "<xmlattr>.nullable";
	
	pt::ptree ptree;
    pt::read_xml(xml_path, ptree);
    
    this->server = ptree.get<std::string>(SERVER_NODE_NAME);
    this->account = ptree.get<std::string>(ACCOUNT_NODE_NAME);
    this->pwd = ptree.get<std::string>(PWD_NODE_NAME);
    this->schema = ptree.get<std::string>(SCHEMA_NODE_NAME);
 
	BOOST_FOREACH(pt::ptree::value_type const& table, ptree.get_child(TABLES_NODE_NAME)) 
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
				voba::ColumnType column_type = voba::string_to_column_type(column.second.get<std::string>("<xmlattr>.type"));
				bool nullable = column.second.get<bool>("<xmlattr>.nullable", false);
				Column c(column_name, column_type, nullable);
				t.push_back(c);
			}
		}
		this->tables.push_back(t);
	}
}
