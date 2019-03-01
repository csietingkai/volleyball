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
			
			/**
			 * select all person data from database
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.10
			 */
			const static std::vector<Person> select_all();
			/**
			 * select a person data from database
			 * 
			 * @param id(UUID)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.10
			 */
			const static Person& select_by_id(const UUID id);
			/**
			 * create a person data in database <br/>
			 * and create a person object at the same time
			 * 
			 * @param name(string)
			 * @param age(int)
			 * @param gender(Gender)
			 * @param phonenumber(string)
			 * @param status(ActiveStatus)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.10
			 */
			const static Person& create(std::string name, int age, Gender gender, std::string phonenumber, ActiveStatus status);
			/**
			 * update the person data in database
			 * 
			 * @param new_person(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.10
			 */
			const static bool update(Person& new_person);
			/**
			 * remove the person data from database
			 * 
			 * @param person(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.10
			 */
			const static bool remove(Person& person);
		
		private:
			static MySQLConnector<Person> p_connector;
			static MySQLConnector<Team> t_connector;
			static Logger logger;
	};
}

#endif // PERSON_FACTORY_H_
