#ifndef PERSON_FACTORY_H_
#define PERSON_FACTORY_H_

#include <iostream>
#include <vector>

#include "../Person.h"
#include "../../tools/MySQLConnector.h"

namespace voba
{
	class PersonFactory
	{
		public:
			const static std::string CLASS_NAME;
			
			const static std::vector<Person> select_all();
			const static Person& select_by_id(const UUID id);
			const static Person& create(std::string name, int age, Gender gender, std::string phonenumber, ActiveStatus status);
			const static bool update(Person& new_person);
			const static bool remove(Person& person);
		
		private:
			static MySQLConnector<Person> p_connector;
			static MySQLConnector<Team> t_connector;
			static Logger logger;
	};
}

#endif // PERSON_FACTORY_H_
