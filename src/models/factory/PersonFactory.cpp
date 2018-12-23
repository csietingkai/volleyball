#include "PersonFactory.h"

voba::MySQLConnector<voba::Person> voba::PersonFactory::p_connector;
voba::MySQLConnector<voba::Team> voba::PersonFactory::t_connector;

const voba::Person& voba::PersonFactory::select_by_id(const std::string id)
{
	std::string name;
	int age;
	voba::Gender gender;
	std::string phonenumber;
	voba::ActiveStatus status;
	
	sql::ResultSet* result_set = voba::PersonFactory::p_connector.select(id);
	//sql::ResultSetMetaData *res_meta = result_set->getMetaData();
	//int columns = res_meta->getColumnCount();
	while (result_set->next())
	{
		// 1 -> id
		// 2 -> name
		name = result_set->getString(2);
		// 3 -> age
		age = std::stoi(result_set->getString(3));
		// 4 -> gender
		gender = static_cast<voba::Gender>((std::stoi(result_set->getString(4)) != 0));
		// 5 -> phonenumber
		phonenumber = result_set->getString(5);
		// 6 -> active status
		status = static_cast<voba::ActiveStatus>((std::stoi(result_set->getString(6)) != 0));
	}
	
	Person *p = new Person(name, age, gender, phonenumber, status);
	return *p;
}

const voba::Person& voba::PersonFactory::create(std::string name, int age, voba::Gender gender, std::string phonenumber, voba::ActiveStatus status)
{
	// maybe cause duplicate exception
	Person *p = new Person(name, age, gender, phonenumber, status);
	bool result = (voba::PersonFactory::p_connector.insert(*p) == 0);
	//std::cout << result << std::endl;
	return *p;
}

const bool voba::PersonFactory::update(Person& new_person)
{
	std::string old_id = new_person.get_id();
	new_person.update_id();
	
	int result = voba::PersonFactory::p_connector.update(new_person, old_id);
	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool voba::PersonFactory::remove(Person& person)
{
	person.update_id();
	
	int result = voba::PersonFactory::p_connector.remove(person);
	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
