#include "MySQLConnector.h"

// constructor
template <typename T>
voba::MySQLConnector<T>::MySQLConnector()
	: info(voba::MySQLConnector<T>::SERVER_INFO_FILE_PATH)
	, logger(voba::MySQLConnector<T>::CLASS_NAME)
{
	if (std::is_same<T, voba::Person>::value)
	{
		std::cout << "Person" << std::endl;
	}
}

template <typename T>
voba::MySQLConnector<T>::~MySQLConnector()
{
	
}

// public function
/*sql::ResultSet* voba::MySQLConnector::select(const std::string column_name);
sql::ResultSet* voba::MySQLConnector::select(const std::string column_name, const std::string condition);
const bool voba::MySQLConnector::insert(const std::string values);
const int voba::MySQLConnector::update(const std::string column_name, const std::string column_value, const std::string conditions);
const int voba::MySQLConnector::remove(const std::string codition);
const int voba::MySQLConnector::removeAll();*/

// private function
template <typename T>
const std::string voba::MySQLConnector<T>::CLASS_NAME = "MySQLConnector";
template <typename T>
const std::string voba::MySQLConnector<T>::SERVER_INFO_FILE_PATH = "resources/server_info.xml";

template <typename T>
void voba::MySQLConnector<T>::print_sql_exception(const sql::SQLException e)
{
	
}
