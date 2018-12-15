#include "MySQLConnector.h"

template <class T>
const std::string voba::MySQLConnector<T>::CLASS_NAME = "MySQLConnector."+T::CLASS_NAME;

// constructor
template <class T>
voba::MySQLConnector<T>::MySQLConnector()
	: Logable(voba::MySQLConnector<T>::CLASS_NAME)
{
	this->table_name = info.get_table_name(T::CLASS_NAME);
}

template <class T>
voba::MySQLConnector<T>::~MySQLConnector()
{
	
}

// public function
template <class T>
const T& voba::MySQLConnector<T>::select(const std::string id)
{
	T *t = new T(id);
	return *t;
}

template <class T>
const bool voba::MySQLConnector<T>::insert(const T t)
{
	return false;
}

template <class T>
const int voba::MySQLConnector<T>::update(const T t)
{
	return 0;
}

template <class T>
const int voba::MySQLConnector<T>::remove(const T t)
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

// Person specialization
const voba::Person& voba::MySQLConnector<voba::Person>::select(const std::string id)
{
	Person *p = new Person("test1", 21, voba::Gender::male, "0987654321", voba::ActiveStatus::active);
	return *p;
}

// Team specialization
const voba::Team& voba::MySQLConnector<voba::Team>::select(const std::string id)
{
	Team *t = new Team(id);
	return *t;
}
