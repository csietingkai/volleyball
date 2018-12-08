#include "MySQLConnector.h"

const std::string voba::MySQLConnector::CLASS_NAME = "MySQLConnector";

// constructor
voba::MySQLConnector::MySQLConnector(const std::string target_class_name)
	: info(voba::MySQLConnector::SERVER_INFO_FILE_PATH)
	, logger(voba::MySQLConnector::CLASS_NAME)
{
	
	this->table_name = info.get_table_name(target_class_name);
}

voba::MySQLConnector::~MySQLConnector()
{
	
}

// public function
const int voba::MySQLConnector::remove()
{
	
}

// private function
const std::string voba::MySQLConnector::SERVER_INFO_FILE_PATH = "resources/server_info.xml";

void voba::MySQLConnector::print_sql_exception(const sql::SQLException e)
{
	std::cout << "# ERR: SQLException in " << __FILE__;
	std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
	std::cout << "# ERR: " << e.what();
	std::cout << " (MySQL error code: " << e.getErrorCode();
	std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
}
