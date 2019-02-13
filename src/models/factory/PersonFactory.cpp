#include "PersonFactory.h"

const std::string voba::PersonFactory::CLASS_NAME = "PersonFactory";
voba::MySQLConnector<voba::Person> voba::PersonFactory::p_connector;
voba::MySQLConnector<voba::Team> voba::PersonFactory::t_connector;
voba::Logger voba::PersonFactory::logger(voba::PersonFactory::CLASS_NAME);

const std::vector<voba::Person> voba::PersonFactory::select_all()
{
	voba::PersonFactory::logger.debug("selecting all person from database");
	
	std::vector<voba::Person> all;
	
	voba::UUID id;
	std::string name;
	int age;
	voba::Gender gender;
	std::string phonenumber;
	voba::ActiveStatus status;
	
	sql::ResultSet* result_set = voba::PersonFactory::p_connector.select();
	while (result_set->next())
	{
		// 1 -> id
		id = voba::UUID::from_string(result_set->getString(1));
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
		
		voba::Person p(name, age, gender, phonenumber, status);
		p.update_id(id);
		
		all.push_back(p);
	}
	
	return all;
}

const voba::Person& voba::PersonFactory::select_by_id(const voba::UUID id)
{
	voba::PersonFactory::logger.debug("selecting person from database with id:'" + id.to_string() + "'");
	
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
	
	voba::Person *p = new voba::Person(name, age, gender, phonenumber, status);
	p->update_id(id);
	return *p;
}

const voba::Person& voba::PersonFactory::create(std::string name, int age, voba::Gender gender, std::string phonenumber, voba::ActiveStatus status)
{
	voba::PersonFactory::logger.debug("creating person in database");
	
	voba::Person *p = new voba::Person(name, age, gender, phonenumber, status);
	p->update_id(voba::UUID::random_uuid());
	voba::PersonFactory::p_connector.insert(*p);
	return *p;
}

const bool voba::PersonFactory::update(voba::Person& new_person)
{
	voba::PersonFactory::logger.debug("updating person in database");
	
	int result = voba::PersonFactory::p_connector.update(new_person);
	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool voba::PersonFactory::remove(voba::Person& person)
{
	voba::PersonFactory::logger.debug("deleting person in database");
	
	int result = 0;
	result += voba::PersonFactory::p_connector.remove(person);
	
	voba::Column member_id("member_id", "uuid");
	member_id.set_value(person.get_id().to_string());
	result += voba::PersonFactory::t_connector.remove(member_id);
	
	if (result >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
