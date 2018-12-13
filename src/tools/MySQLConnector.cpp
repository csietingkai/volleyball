#include "MySQLConnector.h"

template <class T>
const std::string voba::MySQLConnector<T>::CLASS_NAME = "MySQLConnector";

// constructor
template <class T>
voba::MySQLConnector<T>::MySQLConnector()
	: Logable(voba::MySQLConnector<T>::CLASS_NAME)
{
	this->table_name = info.get_table_name(T::CLASS_NAME);
	if (std::is_same<T, voba::Person>::value)
	{
		std::cout << "is Person" << std::endl;
	}
}

template <class T>
voba::MySQLConnector<T>::~MySQLConnector()
{
	
}

// public function
template <class T>
const T voba::MySQLConnector<T>::select()
{
	
}

template <class T>
const bool voba::MySQLConnector<T>::insert()
{
	return 0;
}

template <class T>
const int voba::MySQLConnector<T>::update()
{
	return 0;
}

template <class T>
const int voba::MySQLConnector<T>::remove()
{
	return 0;
}

// private function
template <class T>
void voba::MySQLConnector<T>::print_sql_exception(const sql::SQLException e)
{
	std::cout << "# ERR: SQLException in " << __FILE__;
	std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
	std::cout << "# ERR: " << e.what();
	std::cout << " (MySQL error code: " << e.getErrorCode();
	std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
}
