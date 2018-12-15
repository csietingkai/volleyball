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
			const static Person& create();
			const static bool update(const Person new_person);
			const static bool remove(const Person preson);
		
		private:
			static MySQLConnector<Person> connector;
	};
}

#endif // PERSON_FACTORY_H_
